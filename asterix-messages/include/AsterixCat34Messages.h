#pragma once

#include "../categories-definitions/Cat34.h"
#include "../categories-types/Cat34Types.h"
#include "AsterixCatMessageBase.h"

using namespace AsterixMessageCategories;
class AsterixCat34Messages : public AsterixCatMessageBase
{
public:
  AsterixCat34Messages();
  virtual ~AsterixCat34Messages() override;
  // Decode Data Network(TCP/IP & UDP)
  bool decodeData(const char *data, json &cat34_json_data);

  void to_json(const AsterixMessage_Cat34 &catstr, json &jData);
  void from_json(json jData, AsterixMessage_Cat34 &cat_data);

private:
  json cat34_definition;
  std::vector<std::string> cat34_uap_order{"010", "000", "030", "020", "041", "050", "060", "FX", "070", "100", "110", "120", "090", "RE", "SP", "FX"};
  std::map<std::string, int> cat34_items_order{{"000", 0}, {"010", 1}, {"020", 2}, {"030", 3}, {"041", 4}, {"050", 5}, {"060", 6}, {"070", 7}, {"090", 8}, {"100", 9}, {"110", 10}, {"120", 11}};
};