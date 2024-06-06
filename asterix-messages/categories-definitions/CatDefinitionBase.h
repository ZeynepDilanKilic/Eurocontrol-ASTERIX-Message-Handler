#pragma once

#include "../../lib/json.hpp"

using json = nlohmann::json;

class CatDefinitionBase
{
protected:
  static void get(json &cat_def_json, const std::string &cat_def_str)
  {
    cat_def_json = json::parse(cat_def_str);
  }
};