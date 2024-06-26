#include "../include/AsterixCatMessageBase.h"
#include <algorithm>

AsterixCatMessageBase::AsterixCatMessageBase()
{
}

AsterixCatMessageBase::~AsterixCatMessageBase()
{
}

int count = 1;
bool AsterixCatMessageBase::baseDecodeData(const char *data, const json &cat_definition, const std::map<std::string, int> &cat_items_orders, const std::vector<std::string> &uap_list, json &cat_data_return)
{
  m_data = "";
  parsedBytes = 0;
  header_info.uap_list.clear();
  header_info.message_len = 0;
  header_info.cat_type = 0;
  m_data = data;
  m_uap_list = uap_list;
  cat_data_return.clear();
  decodeHeader();

  for (auto decodeBytes : header_info.uap_list)
  {
    if (decodeBytes == "FX")
    {
      //"FX" (Field Extension Indicator)
      std::cout << "FX" << std::endl;
      continue;
    }
    else if (decodeBytes == "RE")
    {
      //"RE" (Reserved Expansion Field)
      std::cout << "RE" << std::endl;
      continue;
    }
    else if (decodeBytes == "SP")
    {
      //"SP" (Special Purpose Field)
      std::cout << "SP" << std::endl;
      // Not: special alan byte değeri alınacak. burada parsedBytes'a eklenerek devam edileceks
      continue;
    }
    else if (decodeBytes == "-")
    {
      //"-" (Empyt Line - Data Not Related With Radar)
      std::cout << "-" << std::endl;
      parsedBytes += 1;
      continue;
    }
    else
    {
      ItemParser itemParser(cat_definition["items"][cat_items_orders.at(decodeBytes)]);
      parsedBytes += itemParser.parseItem(m_data, parsedBytes, 0, 0, cat_data_return, 0);
      // std::cout << cat_data_return[decodeBytes].dump(4) << std::endl;
    }
  }
  std::cout << count << std::endl;
  count++;
  //std::cout << cat_data_return.dump(4) << std::endl;
  //std::vector<char> a;

  /*baseEncodeData(cat_data_return, cat_definition, cat_items_orders, uap_list, a);

  encodeHeader(0x22, a);
  char *ret = reinterpret_cast<char *>(&a[0]);

  for (auto t : a)
  {
    std::cout << std::hex << static_cast<int>(static_cast<unsigned char>(t)) << " ";
  }
  std::cout << std::endl;*/

  // baseDecodeData(ret, cat_definition, cat_items_orders, uap_list, cat_data_return);

  return 0;
}

size_t AsterixCatMessageBase::decodeHeader()
{
  header_info.cat_type = static_cast<int>(static_cast<unsigned char>(m_data[0]));
  header_info.message_len = (static_cast<unsigned char>(m_data[1]) << 8) | static_cast<unsigned char>(m_data[2]);

  std::vector<bool> binaryRepresentation;
  size_t byteIndex = 3;

  bool moreBytes;
  do
  {
    std::bitset<8> fspecBits(m_data[byteIndex]);
    moreBytes = fspecBits[0]; // En sağdaki bit, daha fazla FSPEC byte'ı olup olmadığını belirtir

    for (int bitIndex = 7; bitIndex >= 0; --bitIndex)
    {
      binaryRepresentation.push_back(fspecBits[bitIndex]); // FSPEC'in geri kalan bitlerini oku
    }

    ++byteIndex;
  } while (moreBytes);

  // UAP list ile karşılaştır, fspec alanını, octet dizilimi ters olduğu için reverse yaptım.

  for (auto val = 0; val < binaryRepresentation.size(); val++)
  {
    if (binaryRepresentation[val] == true)
    {

      header_info.uap_list.push_back(m_uap_list[val]);
    }
  }
  parsedBytes += byteIndex;
  return 0;
}

bool AsterixCatMessageBase::baseEncodeData(json jData, const json &cat_definition, const std::map<std::string, int> &cat_items_ordes, const std::vector<std::string> &uap_list, std::vector<char> &data_return)
{
  std::vector<char> data;
  std::vector<bool> fspec(uap_list.size(), 0);
  size_t count = 0;
  for (auto uap : uap_list) // 000, 010
  {
    if (jData.contains(uap))
    {
      ItemSerializer itemSerializer(cat_definition["items"][cat_items_ordes.at(uap)]);
      itemSerializer.serializeItem(jData[uap], 0, 0, 0, data, 0);
      fspec[uap_list.size() - count - 1] = 1;
    }
    count++;
  }

  std::reverse(fspec.begin(), fspec.end());

  auto it = std::find(fspec.rbegin(), fspec.rend(), true);
  auto index = std::distance(it, fspec.rend() - 1);
  auto block = index / 8;
  for (int i = 0; i < block; i++)
  {
    fspec[i * 8 + 7] = true;
  }

  std::vector<char> fspec_ch;
  for (size_t i = 0; i < fspec.size() / 8; ++i)
  {
    char byte{};
    for (size_t bit{i * 8}; bit < (i + 1) * 8; bit++)
    {
      if (fspec[bit])
      {
        byte |= 1 << (7 + (i * 8) - bit);
      }
    }
    fspec_ch.push_back(byte);
    if (fspec[i * 8 + 7] == 0)
    {
      break;
    }
  }

  for (size_t i = 0; i < data.size(); i++)
  {
    data_return.push_back(data[i]);
  }
  for (size_t i = fspec_ch.size() - 1; i < -1; i--)
  {

    data_return.insert(data_return.begin(), fspec_ch[i]);
  }

  return 0;
}

void AsterixCatMessageBase::encodeHeader(char cat, std::vector<char> &data)
{

  uint16_t length = data.size() + 3;

  std::vector<uint8_t> lengthByteArray;
  lengthByteArray.push_back(length & 0xFF);
  lengthByteArray.push_back((length >> 8) & 0XFF);

  for (uint8_t byte : lengthByteArray)
  {
    char sz = static_cast<char>(byte);
    data.insert(data.begin(), sz);
  }

  data.insert(data.begin(), cat);
}
