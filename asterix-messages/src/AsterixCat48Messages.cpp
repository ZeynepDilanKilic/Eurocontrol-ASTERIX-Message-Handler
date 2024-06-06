// #include "../include/AsterixCat34Messages.h"
#include "../include/AsterixCat48Messages.h"
AsterixCat48Messages::AsterixCat48Messages()
{
  Cat48::get(cat48_definition);
};

AsterixCat48Messages::~AsterixCat48Messages(){

};

bool AsterixCat48Messages::decodeData(const char *data, json &cat48_json_data)
{

  AsterixCatMessageBase::baseDecodeData(data, cat48_definition, cat48_items_order, cat48_uap_order, cat48_json_data);
  return true;
}