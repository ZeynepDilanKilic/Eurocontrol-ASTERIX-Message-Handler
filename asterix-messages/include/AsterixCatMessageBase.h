#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <functional>

#include "../tools/include/string_conv.h"
#include "../tools/include/parser/itemparser.h"
#include "../tools/include/parser/extendablebitsitemparser.h"
#include "../tools/include/parser/compounditemparser.h"
#include "../tools/include/parser/fixedbitfielditemparser.h"
#include "../tools/include/parser/fixedbytesitemparser.h"
#include "../tools/include/parser/fixedbitsitemparser.h"
#include "../tools/include/parser/optionalitemparser.h"

#include "../tools/include/serializer/itemserializer.h"

#include "../../lib/json.hpp"

using json = nlohmann::json;

class AsterixCatMessageBase
{
protected:
    AsterixCatMessageBase();
    virtual ~AsterixCatMessageBase();

    // Decode Data Network(TCP/IP & UDP)
    bool baseDecodeData(const char *data, const json &cat_definition, const std::map<std::string, int> &cat_items_orders, const std::vector<std::string> &uap_list, json &cat_data_return);
    bool baseEncodeData(json jData, const json &cat_definition, const std::map<std::string, int> &cat_items_ordes, const std::vector<std::string> &uap_list, std::vector<char> &data_return);

private:
    // Decode First 4 Bytes (FSPEC)
    size_t decodeHeader();
    void encodeHeader(char cat, std::vector<char> &data);

    struct MessageHeader
    {
        int cat_type;
        int message_len;
        std::vector<std::string> uap_list;
    };

    const char *m_data;
    json m_cat_definition{""};
    json mapping;
    MessageHeader header_info;
    size_t parsedBytes;
    std::vector<std::string> m_uap_list;
};