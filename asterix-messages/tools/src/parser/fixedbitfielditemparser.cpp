/*
 * This file is part of ATSDB.
 *
 * ATSDB is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ATSDB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with ATSDB.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../include/parser/fixedbitfielditemparser.h"
#include "../../include/parser/fixedbitsitemparser.h"

using namespace std;
using namespace nlohmann;

FixedBitFieldItemParser::FixedBitFieldItemParser(const nlohmann::json &item_definition)
    : ItemParserBase(item_definition)
{
    assert(type_ == "fixed_bitfield");

    optional_ = item_definition.contains("optional") && item_definition.at("optional") == true;

    if (optional_)
    {
        if (!item_definition.contains("optional_variable_name"))
            throw runtime_error("parsing fixed bitfield item '" + name_ +
                                "' optional but no variable given");

        optional_variable_name_ = item_definition.at("optional_variable_name");
        optional_variable_name_parts_ = split(optional_variable_name_, '.');

        if (!item_definition.contains("optional_variable_value"))
            throw runtime_error("parsing fixed bitfield item '" + name_ +
                                "' optional but no variable value given");

        optional_variable_value_ = item_definition.at("optional_variable_value");
    }

    if (!item_definition.contains("length"))
        throw runtime_error("parsing fixed bitfield item '" + name_ + "' without length");

    length_ = item_definition.at("length");

    if (length_ > 8)
        throw runtime_error("parsing fixed bitfield item '" + name_ + "' with too big length");

    if (!item_definition.contains("items"))
        throw runtime_error("parsing fixed bitfield item '" + name_ + "' without sub-items");

    const json &items = item_definition.at("items");

    if (!items.is_array())
        throw runtime_error("parsing fixed bitfield item '" + name_ +
                            "' sub-items specification is not an array");

    std::string item_name;
    FixedBitsItemParser *item{nullptr};

    for (const json &data_item_it : items)
    {
        item_name = data_item_it.at("name");
        item = new FixedBitsItemParser(data_item_it, length_); // leave out own name
        assert(item);
        items_.push_back(std::unique_ptr<ItemParserBase>{item});
    }
}

size_t FixedBitFieldItemParser::parseItem(const char *data, size_t index, size_t size,
                                          size_t current_parsed_bytes, nlohmann::json &target,
                                          bool debug)
{

    if (optional_ &&
        !variableHasValue(target, optional_variable_name_parts_, optional_variable_value_))
    {
        return 0; // no parse
    }
    bitfield.clear();

    for (auto &sub_item_it : items_)
    {
        sub_item_it->parseItem(data, index, size, current_parsed_bytes, target, debug);

        auto data_type = sub_item_it.get()->item_definition_["data_type"];

        bitfield.push_back(static_cast<FixedBitsItemParser *>(sub_item_it.get())->parsedChar);
    }

    return length_;
}
