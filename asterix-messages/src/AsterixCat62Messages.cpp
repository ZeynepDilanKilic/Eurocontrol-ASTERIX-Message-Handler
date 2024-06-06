#include "../include/AsterixCat62Messages.h"


AsterixCat62Messages::AsterixCat62Messages()
{

}

AsterixCat62Messages::~AsterixCat62Messages()
{

}

bool AsterixCat62Messages::decodeData(const char *data, json& cat62_json_data)
{
  json cat62_definition;
  Cat62::get(cat62_definition);
  AsterixCatMessageBase::baseDecodeData(data, cat62_definition, cat62_items_order, cat62_uap_order, cat62_json_data);
  return true;
}

bool AsterixCat62Messages::encodeData(json &cat62_json_data, const char *data)
{
  json cat62_definition;
  Cat62::get(cat62_definition);
  //AsterixCatMessageBase::b
  return false;
}