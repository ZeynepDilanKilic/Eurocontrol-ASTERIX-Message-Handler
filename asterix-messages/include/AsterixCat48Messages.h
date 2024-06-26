#pragma once

#include "../categories-definitions/Cat48.h"
#include "../categories-types/Cat48Types.h"
#include "AsterixCatMessageBase.h"

using namespace AsterixMessageCategories;
class AsterixCat48Messages : public AsterixCatMessageBase
{
public:
  AsterixCat48Messages();
  virtual ~AsterixCat48Messages() override;
  // Decode Data Network(TCP/IP & UDP)
  bool decodeData(const char *data, json &cat48_json_data);

  void to_json(json &j);
  void from_json(AsterixMessage_Cat48 &);

private:
  json cat48_definition;
  std::vector<std::string> cat48_uap_order{"010", "140", "020", "040", "070", "090", "130", "FX", "220", "240", "250", "161", "042", "200", "170", "FX", "210", "030", "080", "100", "110", "120", "230", "FX", "260", "055", "050", "065", "060", "SP", "RE", "FX"};
  std::map<std::string, int> cat48_items_order{{"010", 0}, {"020", 1}, {"030", 2}, {"040", 3}, {"042", 4}, {"050", 5}, {"055", 6}, {"060", 7}, {"065", 8}, {"070", 9}, {"080", 10}, {"090", 11}, {"100", 12}, {"110", 13}, {"120", 14}, {"130", 15}, {"140", 16}, {"161", 17}, {"170", 18}, {"200", 19}, {"210", 20}, {"220", 21}, {"230", 22}, {"240", 23}, {"250", 24}, {"260", 25}};
};