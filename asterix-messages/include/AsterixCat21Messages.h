#pragma once

#include "../categories-definitions/Cat21.h"
#include "../categories-types/Cat21Types.h"
#include "AsterixCatMessageBase.h"

using namespace AsterixMessageCategories;
class AsterixCat21Messages : public AsterixCatMessageBase
{
public:
   AsterixCat21Messages();
  virtual ~AsterixCat21Messages() override;
  bool decodeData(const char *data, json& cat21_json_data);



private:
  std::vector<std::string> cat21_uap_order{""};
  std::map<std::string, int> cat21_items_order{};
};