// #include "../include/AsterixCat34Messages.h"
#include "../include/AsterixCat34Messages.h"
AsterixCat34Messages::AsterixCat34Messages()
{
  Cat34::get(cat34_definition);
};

AsterixCat34Messages::~AsterixCat34Messages(){

};

bool AsterixCat34Messages::decodeData(const char *data, json &cat34_json_data)
{

  AsterixCatMessageBase::baseDecodeData(data, cat34_definition, cat34_items_order, cat34_uap_order, cat34_json_data);

  return true;
}
