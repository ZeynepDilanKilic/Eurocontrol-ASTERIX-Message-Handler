#include "../include/AsterixCat21Messages.h"


AsterixCat21Messages::AsterixCat21Messages()
{

}

AsterixCat21Messages::~AsterixCat21Messages()
{

}

bool AsterixCat21Messages::decodeData(const char *data, json& cat21_json_data)
{
  json cat21_definition;
  Cat21::get(cat21_definition);
  AsterixCatMessageBase::baseDecodeData(data, cat21_definition, cat21_items_order, cat21_uap_order, cat21_json_data);
  return true;
}

