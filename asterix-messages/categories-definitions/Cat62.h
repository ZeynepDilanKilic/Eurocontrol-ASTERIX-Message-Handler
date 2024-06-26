#pragma once
#include "CatDefinitionBase.h"

namespace AsterixMessageCategories
{
  class Cat62 : public CatDefinitionBase
  {
  public:
    static void get(json &cat_definition)
    {
      CatDefinitionBase::get(cat_definition, cat62_str);
    }

  private:
    inline static std::string cat62_str = R"({
    "name":"cat062_1.18_record",
    "type":"record",
    "field_specification":{
        "name":"FSPEC",
        "type":"extendable_bits",
        "reverse_bits":true,
        "data_type":"bitfield"
    },
    "uap":[
        "010",
        "-",
        "015",
        "070",
        "105",
        "100",
        "185",
        "FX",
        "210",
        "060",
        "245",
        "380",
        "040",
        "080",
        "290",
        "FX",
        "200",
        "295",
        "136",
        "130",
        "135",
        "220",
        "390",
        "FX",
        "270",
        "300",
        "110",
        "120",
        "510",
        "500",
        "340",
        "FX",
        "-",
        "-",
        "-",
        "-",
        "-",
        "RE",
        "SP",
        "FX"
    ],
    "items":[
        {
            "number":"010",
            "name":"Data Source Identifier",
            "comment":"Identification of the system sending the data",
            "type":"item",
            "data_fields":[
                {
                    "name":"SAC",
                    "comment":"System Area Code",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                },
                {
                    "name":"SIC",
                    "comment":"System Identification Code",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"015",
            "name":"Service Identification",
            "comment":"Identification of the service provided to one or more users.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Service Identification",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"040",
            "name":"Track Number",
            "comment":"Identification of a track",
            "type":"item",
            "data_fields":[
                {
                    "name":"Track Number",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"060",
            "name":"Track Mode 3/A Code",
            "comment":"Mode-3/A code converted into octal representation.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Mode 3/A",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"V",
                            "comment":"0 Code validated\n1 Code not validated",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"G",
                            "comment":"0 Default\n1 Garbled Code",
                            "type":"fixed_bits",
                            "start_bit":14,
                            "bit_length":1
                        },
                        {
                            "name":"CH",
                            "comment":"Change in Mode 3/A\n0 No Change\n1 Mode 3/A has changed",
                            "type":"fixed_bits",
                            "start_bit":13,
                            "bit_length":1
                        },
                        {
                            "name":"Mode-3/A reply",
                            "comment":"",
                            "type":"fixed_bits",
                            "data_type":"digits",
                            "start_bit":0,
                            "bit_length":12,
                            "num_digits":4,
                            "digit_bit_length":3
                        }
                    ]
                }
            ]
        },
        {
            "number":"070",
            "name":"Time Of Track Information",
            "comment":"Absolute time stamping of the information provided in the track message, in the form of elapsed time since last midnight, expressed as UTC.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time Of Track Information",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"080",
            "name":"Track Status",
            "comment":"Status of a track.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Track Status",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"MON",
                            "comment":"0 Multisensor track\n1 Monosensor track",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"SPI",
                            "comment":"0 default value\n1 SPI present in the last report received from a sensor capable of decoding this data",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"MRH",
                            "comment":"Most Reliable Height\n0 Barometric altitude (Mode C) more reliable\n1 Geometric altitude more reliable",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"SRC",
                            "comment":"Source of calculated track altitude for I062/130\n0 no source\n1 GNSS\n2 3D radar\n3 triangulation\n4 height from coverage\n5 speed look-up table\n6 default height\n7 multilateration",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":3
                        },
                        {
                            "name":"CNF",
                            "comment":"0 Confirmed track\n1 Tentative track",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":1
                        },
                        {
                            "name":"FX",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                },
                {
                    "name":"Track Status First Extent",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"SIM",
                            "comment":"0 Actual track\n1 Simulated track",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"TSE",
                            "comment":"0 default value\n1 last message transmitted to the user for the track",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"TSB",
                            "comment":"0 default value\n1 first message transmitted to the user for the track",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"FPC",
                            "comment":"0 Not flight-plan correlated\n1 Flight plan correlated",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"AFF",
                            "comment":"0 default value\n1 ADS-B data inconsistent with other surveillance information",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"STP",
                            "comment":"0 default value\n1 Slave Track Promotion",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"KOS",
                            "comment":"0 Complementary service used\n1 Background service used",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":1
                        },
                        {
                            "name":"FX2",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                },
                {
                    "name":"Track Status Second Extent",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX2",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"AMA",
                            "comment":"0 track not resulting from amalgamation process\n1 track resulting from amalgamation process",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"MD4",
                            "comment":"0 No Mode 4 interrogation\n1 Friendly target\n2 Unknown target\n3 No reply",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"ME",
                            "comment":"0 default value\n1 Military Emergency present in the last report received from a sensor capable of decoding this data",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"MI",
                            "comment":"0 default value\n1 Military Identification present in the last report received from a sensor capable of decoding this data",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"MD5",
                            "comment":"0 No Mode 5 interrogation\n1 Friendly target\n2 Unknown target\n3 No reply",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":2
                        },
                        {
                            "name":"FX3",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                },
                {
                    "name":"Track Status Third Extent",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX3",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"CST",
                            "comment":"0 Default value\n1 Age of the last received track update is higher than system dependent threshold [coasting]",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"PSR",
                            "comment":"0 Default value\n1 Age of the last received PSR track update is higher than system dependent threshold",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"SSR",
                            "comment":"0 Default value\n1 Age of the last received SSR track update is higher than system dependent threshold",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"MDS",
                            "comment":"0 Default value\n1 Age of the last received Mode S track update is higher than system dependent threshold",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"ADS",
                            "comment":"0 Default value\n1 Age of the last received ADS-B track update is higher than system dependent threshold",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"SUC",
                            "comment":"0 Default value\n1 Special Used Code [Mode A codes to be defined in the system to mark a track with special interest]",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"AAC",
                            "comment":"0 Default value\n1 Assigned Mode A Code Conflict [same discrete Mode A Code assigned to another track]",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":1
                        },
                        {
                            "name":"FX4",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                }
                ,
                {
                    "name":"Track Status Fourth Extent",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX4",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"SDS",
                            "comment":"Surveillance Data Status\n0 Combined\n1 Co-operative only\n2 Non-Cooperative only\n3 Not defined",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":2
                        },
                        {
                            "name":"EMS",
                            "comment":"Emergency Status Indication\n0 No emergency\n1 General emergency\n2 Lifeguard / medical\n3 Minimum fuel\n4 No communications\n5 Unlawful interference\n6 'Downed' Aircraft\n7 Undefined",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":3
                        },
                        {
                            "name":"PFT",
                            "comment":"0 No indication\n1 Potential False Track Indication",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"FPLT",
                            "comment":"0 Default value\n1 Track created / updated with FPL data",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":1
                        },
                        {
                            "name":"FX5",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                },
                {
                    "name":"Track Status Fifth Extent",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX5",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"DUPT",
                            "comment":"0 Default value\n1 Duplicate Mode 3/A Code",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"DUPF",
                            "comment":"0 Default value\n1 Duplicate Flight Plan",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"DUPM",
                            "comment":"0 Default value\n1 Duplicate Flight Plan due to manual correlation",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"SFC",
                            "comment":"0 Default value\n1 Surface target",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"IDD",
                            "comment":"0 No indication\n1 Duplicate Flight-ID",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"IEC",
                            "comment":"0 Default value\n1 Inconsistent Emergency Code",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"FX6",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                }
            ]
        },
        {
            "number":"100",
            "name":"Calculated Track Position. [Cartesian]",
            "comment":"Calculated position in Cartesian co-ordinates with a resolution of 0.5m, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"X",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"int",
                    "lsb":0.5
                },
                {
                    "name":"Y",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"int",
                    "lsb":0.5
                }
            ]
        },
        {
            "number":"105",
            "name":"Calculated Position In WGS-84 Co-ordinates",
            "comment":"Calculated Position in WGS-84 Co-ordinates with a resolution of 180/2^25. degrees",
            "type":"item",
            "data_fields":[
                {
                    "name":"Latitude",
                    "comment":"In WGS.84 in two’s complement. Range -90 <= latitude <= 90 deg.",
                    "type":"fixed_bytes",
                    "length":4,
                    "data_type":"int",
                    "lsb":5.36441802978515625E-6
                },
                {
                    "name":"Longitude",
                    "comment":"In WGS.84 in two’s complement. Range -180 <= longitude < 180 deg.",
                    "type":"fixed_bytes",
                    "length":4,
                    "data_type":"int",
                    "lsb":5.36441802978515625E-6
                }
            ]
        },
        {
            "number":"110",
            "name":"Mode 5 Data reports & Extended Mode 1 Code",
            "comment":"Mode 5 Data reports & Extended Mode 1 Code",
            "type":"item",
            "data_fields":[
                {
                    "name":"110",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"SUM",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"SUM",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"M5",
                                            "comment":"0 No Mode 5 interrogation\n1 Mode 5 interrogation",
                                            "type":"fixed_bits",
                                            "start_bit":7,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"ID",
                                            "comment":"0 No authenticated Mode 5 ID reply\n1 Authenticated Mode 5 ID reply",
                                            "type":"fixed_bits",
                                            "start_bit":6,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"DA",
                                            "comment":"0 No authenticated Mode 5 Data reply or Report\n 1 Authenticated Mode 5 Data reply or Report [i.e any valid Mode 5 reply type other than ID]",
                                            "type":"fixed_bits",
                                            "start_bit":5,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"M1",
                                            "comment":"0 Mode 1 code not present or not from Mode 5 reply\n 1 Mode 1 code from Mode 5 reply.",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"M2",
                                            "comment":"0 Mode 2 code not present or not from Mode 5 reply\n 1 Mode 2 code from Mode 5 reply.",
                                            "type":"fixed_bits",
                                            "start_bit":3,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"M3",
                                            "comment":"0 Mode 3 code not present or not from Mode 5 reply\n 1 Mode 3 code from Mode 5 reply.",
                                            "type":"fixed_bits",
                                            "start_bit":2,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"MC",
                                            "comment":"0 Mode C altitude not present or not from Mode 5 reply\n1 Mode C altitude from Mode 5 reply",
                                            "type":"fixed_bits",
                                            "start_bit":1,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"X",
                                            "comment":"X-pulse from Mode 5 Data reply or Report.\n0 X-pulse set to zero or no authenticated Data reply or Report received.\n1 X-pulse set to one.",
                                            "type":"fixed_bits",
                                            "start_bit":1,
                                            "bit_length":1
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"PMN",
                            "comment":"Mode 5 PIN /National Origin/ Mission Code",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"PIN",
                                    "comment":"PIN Code",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int"
                                },
                                {
                                    "name":"NAT",
                                    "comment":"National Origin",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"int"
                                },
                                {
                                    "name":"MIS",
                                    "comment":"Mission Code",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"int"
                                }
                            ]
                        },
                        {
                            "name":"POS",
                            "comment":"Mode 5 Reported Position",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"Latitude",
                                    "comment":"In WGS.84 in two’s complement. Range -90 <= latitude <= 90 deg.",
                                    "type":"fixed_bytes",
                                    "length":3,
                                    "data_type":"int",
                                    "lsb":2.1457672119140625E-5
                                },
                                {
                                    "name":"Longitude",
                                    "comment":"In WGS.84 in two’s complement. Range -180 <= longitude < 180 deg.",
                                    "type":"fixed_bytes",
                                    "length":3,
                                    "data_type":"int",
                                    "lsb":2.1457672119140625E-5
                                }
                            ]
                        },
                        {
                            "name":"GA",
                            "comment":"Mode 5 GNSS-derived Altitude",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"GA",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"RES",
                                            "comment":"Resolution with which the GNSS-derived Altitude (GA) is reported.\n0 GA reported in 100 ft increments,\n1 GA reported in 25 ft increments.",
                                            "type":"fixed_bits",
                                            "start_bit":14,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"GA",
                                            "comment":"GNSS-derived Altitude of target, expressed as height above WGS 84 ellipsoid.",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":14
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"EM1",
                            "comment":"Extended Mode 1 Code in Octal Representation",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"Extended Mode 1 Code",
                                    "comment":"Extended Mode 1 Code in octal representation",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int"
                                }
                            ]
                        },
                        {
                            "name":"TOS",
                            "comment":"Time Offset for POS and GA",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"TOS",
                                    "comment":"Time Offset coded as a twos complement number with an LSB of 1/128 s. The time at which the Mode 5 Reported Position (Subfield #3) and Mode 5 GNSS- derived Altitude (Subfield #4) are valid is given by Time of Day (I048/140) plus Time Offset.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"int",
                                    "lsb":0.0078125
                                }
                            ]
                        },
                        {
                            "name":"XP",
                            "comment":"X Pulse Presence",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":6,
                            "data_fields":[
                                {
                                    "name":"XP",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"X5",
                                            "comment":"X-pulse from Mode 5 Data reply or Report.\n0 X-pulse set to zero or no authenticated Data reply or Report received.\n1 X-pulse set to one[present].",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"XC",
                                            "comment":"X-pulse from Mode C reply\n0 X-pulse set to zero or no Mode C reply\n1 X-pulse set to one [present]",
                                            "type":"fixed_bits",
                                            "start_bit":3,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"X3",
                                            "comment":"X-pulse from Mode 3/A reply\n0 X-pulse set to zero or no Mode 3/A reply\n1 X-pulse set to one [present]",
                                            "type":"fixed_bits",
                                            "start_bit":2,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"X2",
                                            "comment":"X-pulse from Mode 2 reply\n0 X-pulse set to zero or no Mode 2 reply\n1 X-pulse set to one [present]",
                                            "type":"fixed_bits",
                                            "start_bit":1,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"X1",
                                            "comment":"X-pulse from Mode 1 reply\n0 X-pulse set to zero or no Mode 1 reply\n1 X-pulse set to one [present]",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":1
                                        }
                                    ]
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"120",
            "name":"Track Mode 2 Code",
            "comment":"Mode 2 code associated to the track",
            "type":"item",
            "data_fields":[
                {
                    "name":"Mode-2 code",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"130",
            "name":"Calculated Track Geometric Altitude",
            "comment":"Vertical distance between the target and the projection of its position on the earth’s ellipsoid, as defined by WGS84, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Altitude",
                    "comment":"Vmin = -1500 ft\nVmax = 150000 ft",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":6.25
                }
            ]
        },
        {
            "number":"135",
            "name":"Calculated Track Barometric Altitude",
            "comment":"Calculated Barometric Altitude of the track, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Calculated Track Barometric Altitude",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"QNH",
                            "comment":"0 No QNH correction applied\n1 QNH correction applied",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"Calculated Track Barometric Altitude",
                            "comment":"Vmin = -15 FL\nVmax = 1500 FL",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":15,
                            "data_type":"int",
                            "lsb":25.0
                        }
                    ]
                }
            ]
        },
        {
            "number":"136",
            "name":"Measured Flight Level",
            "comment":"Last valid and credible flight level used to update the track, in two’s complement form,.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Measured Flight Level",
                    "comment":"Vmin = -15 FL\nVmax = 1500 FL",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.25
                }
            ]
        },
        {
            "number":"185",
            "name":"Calculated Track Velocity [Cartesian]",
            "comment":"Calculated track velocity expressed in Cartesian co-ordinates, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Vx",
                    "comment":"-8192m/s <= Vx <= 8191.75m/s",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.25
                },
                {
                    "name":"Vy",
                    "comment":"-8192m/s <= Vx <= 8191.75m/s",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.25
                }
            ]
        },
        {
            "number":"200",
            "name":"Mode of Movement",
            "comment":"Calculated Mode of Movement of a target.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Mode of Movement",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"TRANS",
                            "comment":"Transversal Acceleration :\n0 Constant Course\n1 Right Turn\n2 Left Turn\n3 Undetermined",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":2
                        },
                        {
                            "name":"LONG",
                            "comment":"Longitudinal Acceleration :\n0 Constant Groundspeed\n1 Increasing Groundspeed\n2 Decreasing Groundspeed\n3 Undetermined",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":2
                        },
                        {
                            "name":"VERT",
                            "comment":"Vertical Rate :\n0 Level\n1 Climb\n2 Descent\n3 Undetermined",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":2
                        },
                        {
                            "name":"ADF",
                            "comment":"Altitude Discrepancy Flag\n0 No altitude discrepancy\n1 Altitude discrepancy",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":1
                        }
                    ]
                }
            ]
        },
        {
            "number":"210",
            "name":"Calculated Acceleration [Cartesian]",
            "comment":"Calculated Acceleration of the target expressed in Cartesian co-ordinates, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Ax",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"int",
                    "lsb":0.25
                },
                {
                    "name":"Ay",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"int",
                    "lsb":0.25
                }
            ]
        },
        {
            "number":"220",
            "name":"Calculated Rate Of Climb/Descent",
            "comment":"Calculated rate of Climb/Descent of an aircraft in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Rate of Climb/Descent",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":6.25
                }
            ]
        },
        {
            "number":"245",
            "name":"Target Identification",
            "comment":"Target [aircraft or vehicle] identification in 8 characters.",
            "type":"item",
            "data_fields":[
                {
                    "name":"STI",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"STI",
                            "comment":"0 Callsign or registration downlinked from target\n1 Callsign not downlinked from target\n2 Registration not downlinked from target\n3 Invalid",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":2
                        }
                    ]
                },
                {
                    "name":"TI",
                    "type":"fixed_bitfield",
                    "length":6,
                    "items":[
                        {
                            "name":"Target Identification",
                            "comment":"",
                            "type":"fixed_bits",
                            "data_type":"icao_characters",
                            "start_bit":0,
                            "bit_length":48,
                            "num_characters":8,
                            "character_bit_length":6
                        }
                    ]
                }
            ]
        },
        {
            "number":"270",
            "name":"Target Size & Orientation",
            "comment":"Target size defined as length and width of the detected target, and orientation.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Target Size & Orientation",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"LENGTH",
                            "comment":"When the length only is sent, the largest dimension is provided.",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":7,
                            "lsb":1.0
                        },
                        {
                            "name":"FX",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                },
                {
                    "name":"Target Size & Orientation First Extent",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"ORIENTATION",
                            "comment":"The orientation gives the direction which the target nose is pointing to, relative to the Geographical North.",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":7,
                            "lsb":2.8125
                        },
                        {
                            "name":"FX2",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                },
                {
                    "name":"Target Size & Orientation Second Extent",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX2",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"WIDTH",
                            "comment":"",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":7,
                            "lsb":1.0
                        },
                        {
                            "name":"FX3",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                }
            ]
        },
        {
            "number":"290",
            "name":"System Track Update Ages",
            "comment":"Ages of the last plot/local track/target report update for each sensor type.",
            "type":"item",
            "data_fields":[
                {
                    "name":"290",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"TRK",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Actual track age since occurence",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"PSR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last primary detection used to update the track",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"SSR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last secondary detection used to update the track",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MDS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last Mode S detection used to update the track",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"ADS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last ADS-C report used to update the track",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"ES",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last 1090 Extended Squitter ADS-B report used to update the track",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"VDL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":6,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last VDL Mode 4 ADS-B report used to update the track",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"UAT",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":8,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last UAT ADS-B report used to update the track",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"LOP",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":9,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last magnetic loop detection",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MLT",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":10,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last MLT detection",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"295",
            "name":"Track Data Ages",
            "comment":"Ages of the data provided.",
            "type":"item",
            "data_fields":[
                {
                    "name":"295",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"MFL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last valid and credible Mode C code or barometric altitude from ADS-B used to update the track [I062/136]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MD1",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last valid and credible Mode 1 code used to update the track [I062/110]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MD2",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last valid and credible Mode 2 code used to update the track [I062/120]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MDA",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last valid and credible Mode 3/A code used to update the track [I062/060]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MD4",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last valid and credible Mode 4 code used to update the track",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MD5",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last valid and credible Mode 5 code used to update the track [I062/110]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MHG",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":6,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Magnetic Heading' in item 062/380 [Subfield #3]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"IAS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":8,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Indicated Airspeed/ Mach Number' in item 062/380 [Subfield #4]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"TAS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":9,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'True Airspeed' in item 062/380 [Subfield #5]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"SAL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":10,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Selected Altitude' in item 062/380 [Subfield #6]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"FSS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":11,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Final State Selected Altitude' in item 062/380 [Subfield #7]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"TID",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":12,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Trajectory Intent' in item 062/380 [Subfield #8]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"COM",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":13,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Communication/ACAS Capability and Flight Status' in item 062/380 [Subfield #10]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"SAB",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":14,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Status Reported by ADS-B' in item 062/380 [Subfield #11]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"ACS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":16,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'ACAS Resolution Advisory Report' in item 062/380 [Subfield #12]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"BVR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":17,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Barometric Vertical Rate' in item 062/380 [Subfield #13]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"GVR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":18,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Geometrical Vertical Rate' in item 062/380 [Subfield #14]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"RAN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":19,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Roll Angle' in item 062/380 [Subfield #15]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"TAR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":20,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Track Angle Rate' in item 062/380 [Subfield #16]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"TAN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":21,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Track Angle' in item 062/380 [Subfield #17]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"GSP",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":22,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Ground Speed' in item 062/380 [Subfield #18]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"VUN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":24,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Velocity Uncertainty' in item 062/380 [Subfield #19]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MET",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":25,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Meteorological Data' in item 062/380 [Subfield #20]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"EMC",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":26,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Emitter Category' in item 062/380 [Subfield #21]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"POS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":27,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Position' in item 062/380 [Subfield #23]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"GAL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":28,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Geometric Altitude' in item 062/380 [Subfield #24]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"PUN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":29,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Position Uncertainty' in item 062/380 [Subfield #25]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MB",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":30,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Mode S MB Data' in item 062/380 [Subfield #22]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"IAR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":32,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Indicated Airspeed' in item 062/380 [Subfield #26]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"MAC",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":33,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Mach Number' in item 062/380 [Subfield #27]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"BPS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":34,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the DAP 'Barometric Pressure Setting' in item 062/380 [Subfield #28]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"300",
            "name":"Vehicle Fleet Identification",
            "comment":"Vehicle fleet identification number.",
            "type":"item",
            "data_fields":[
                {
                    "name":"VFI",
                    "comment":"0 Unknown\n1 ATC equipment maintenance\n2 Airport maintenance\n3 Fire\n4 Bird scarer\n5 Snow plough\n6 Runway sweeper\n7 Emergency\n8 Police\n9 Bus\n10 Tug (push/tow)\n11 Grass cutter\n12 Fuel\n13 Baggage\n14 Catering\n15 Aircraft maintenance\n16 Flyco [follow me]",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"340",
            "name":"Measured Information",
            "comment":"All measured data related to the last report used to update the track. These data are not used for ADS-B.",
            "type":"item",
            "data_fields":[
                {
                    "name":"340",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"SID",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"SAC",
                                    "comment":"System Area Code",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                },
                                {
                                    "name":"SIC",
                                    "comment":"System Identification Code",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"POS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"RHO",
                                    "comment":"Max. range = 256 NM",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.00390625
                                },
                                {
                                    "name":"THETA",
                                    "comment":"",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.0054931640625
                                }
                            ]
                        },
                        {
                            "name":"HEI",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"HEIGHT",
                                    "comment":"Measured 3-D Height",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int",
                                    "lsb":25.0
                                }
                            ]
                        },
                        {
                            "name":"MDC",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"MDC",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"V",
                                            "comment":"0 Code validated\n1 Code not validated",
                                            "type":"fixed_bits",
                                            "start_bit":15,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"G",
                                            "comment":"0 Default\n1 Garbled code",
                                            "type":"fixed_bits",
                                            "start_bit":14,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"Last Measured Mode C Code",
                                            "comment":"Last Measured Mode C Code, in two's complement form\nVmin = -12 FL\nVmax = 1270 FL",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":14,
                                            "data_type":"int",
                                            "lsb":0.25
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"MDA",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"MDA",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"V",
                                            "comment":"0 Code validated\n1 Code not validated",
                                            "type":"fixed_bits",
                                            "start_bit":15,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"G",
                                            "comment":"0 Default\n1 Garbled code",
                                            "type":"fixed_bits",
                                            "start_bit":14,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"L",
                                            "comment":"0 Mode-3/A code derived from the reply of the transponder\n1 Mode-3/A code not extracted during the last scan",
                                            "type":"fixed_bits",
                                            "start_bit":13,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"Mode-3/A reply",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"digits",
                                            "start_bit":0,
                                            "bit_length":12,
                                            "num_digits":4,
                                            "digit_bit_length":3
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"TYP",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"TYP",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"TYP",
                                            "comment":"000 No detection\n001 Single PSR detection\n010 Single SSR detection\n011 SSR + PSR detection\n100 Single ModeS All-Call\n101 Single ModeS Roll-Call\n110 ModeS All-Call + PSR\n111 ModeS Roll-Call +PSR",
                                            "type":"fixed_bits",
                                            "start_bit":5,
                                            "bit_length":3
                                        },
                                        {
                                            "name":"SIM",
                                            "comment":"0  Actual target report\n1 Simulated target report",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"RAB",
                                            "comment":"0 Report from aircraft transponder\n1 Report from field monitor[fixed transponder]",
                                            "type":"fixed_bits",
                                            "start_bit":3,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"TST",
                                            "comment":"0 Real target report\n 1 Test target report",
                                            "type":"fixed_bits",
                                            "start_bit":2,
                                            "bit_length":1
                                        }
                                    ]
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"380",
            "name":"Aircraft Derived Data",
            "comment":"Data derived directly by the aircraft.",
            "type":"item",
            "data_fields":[
                {
                    "name":"380",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"ADR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"Target Address",
                                    "comment":"24 bits Target Address",
                                    "type":"fixed_bytes",
                                    "length":3,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"ID",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"ID",
                                    "type":"fixed_bitfield",
                                    "length":6,
                                    "items":[
                                        {
                                            "name":"Target Identification",
                                            "comment":"Characters 1-8 (coded on 6 bits each) defining a target identification when flight plan is available or the registration marking when no flight plan is available.",
                                            "type":"fixed_bits",
                                            "data_type":"icao_characters",
                                            "start_bit":0,
                                            "bit_length":48,
                                            "num_characters":8,
                                            "character_bit_length":6
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"MHG",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"Magnetic Heading",
                                    "comment":"",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.0054931640625
                                }
                            ]
                        },
                        {
                            "name":"AIS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"Indicated Airspeed / Mach No",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"IM",
                                            "comment":"0 Air Speed = IAS, LSB (Bit-1) = 2^-14 NM/s\n1 Air Speed = Mach, LSB (Bit-1) = 0.001",
                                            "type":"fixed_bits",
                                            "start_bit":15,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"Air Speed",
                                            "comment":"Air Speed [IAS or Mach]",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":15
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"TAS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"True Airspeed",
                                    "comment":"0 <= True Air Speed <= 2046 knots",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":1.0
                                }
                            ]
                        },
                        {
                            "name":"SAL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"Selected Altitude",
                                    "comment":"The short-term vertical intent as described by either the FMS selected altitude, the Altitude Control Panel Selected Altitude (FCU/MCP), or the current aircraft altitude according to the aircraft's mode of flight.",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"SAS",
                                            "comment":"0 No source information provided\n1 Source Information provided",
                                            "type":"fixed_bits",
                                            "start_bit":15,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"Source",
                                            "comment":"0 Unknown\n01 Aircraft Altitude\n2 FCU/MCP Selected Altitude\n3 FMS Selected Altitude",
                                            "type":"fixed_bits",
                                            "start_bit":13,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"Altitude",
                                            "comment":"Altitude in two’s complement form\n-1300ft <= Altitude <= 100000ft",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":13,
                                            "lsb":25.0
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"FSS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":6,
                            "data_fields":[
                                {
                                    "name":"Final State Selected Altitude",
                                    "comment":"The vertical intent value that corresponds with the ATC cleared altitude, as derived from the Altitude Control Panel (FCU/MCP).",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"MV",
                                            "comment":"Manage Vertical Mode\n0 Not active\n1 Active",
                                            "type":"fixed_bits",
                                            "start_bit":15,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"AH",
                                            "comment":"Altitude Hold\n0 Not active\n1 Active",
                                            "type":"fixed_bits",
                                            "start_bit":14,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"AM",
                                            "comment":"Approach Mode\n0 Not active\n1 Active",
                                            "type":"fixed_bits",
                                            "start_bit":13,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"Altitude",
                                            "comment":"Altitude in two’s complement form\n-1300ft <= Altitude <= 100000ft",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":13,
                                            "lsb":25.0
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"TIS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":8,
                            "data_fields":[
                                {
                                    "name":"Trajectory Intent Status",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"NAV",
                                            "comment":"0 Trajectory Intent Data is available for this aircraft\n1 Trajectory Intent Data is not available for this aircraft",
                                            "type":"fixed_bits",
                                            "start_bit":7,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"NVB",
                                            "comment":"0 Trajectory Intent Data is valid\n1 Trajectory Intent Data is not valid",
                                            "type":"fixed_bits",
                                            "start_bit":6,
                                            "bit_length":1
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"TID",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":9,
                            "data_fields":[
                                {
                                    "name":"Trajectory Intent Data",
                                    "type":"repetitive",
                                    "repetition_item":{
                                        "name":"REP",
                                        "type":"fixed_bytes",
                                        "length":1,
                                        "data_type":"uint"
                                    },
                                    "items":[
                                        {
                                            "name":"TID1",
                                            "type":"fixed_bitfield",
                                            "length":1,
                                            "items":[
                                                {
                                                    "name":"TCA",
                                                    "comment":"0 TCP number available\n1 TCP number not available",
                                                    "type":"fixed_bits",
                                                    "start_bit":7,
                                                    "bit_length":1
                                                },
                                                {
                                                    "name":"NC",
                                                    "comment":"0 TCP compliance\n1 TCP non-compliance",
                                                    "type":"fixed_bits",
                                                    "start_bit":6,
                                                    "bit_length":1
                                                },
                                                {
                                                    "name":"TCP number",
                                                    "comment":"Trajectory Change Point number",
                                                    "type":"fixed_bits",
                                                    "start_bit":0,
                                                    "bit_length":6
                                                }
                                            ]
                                        },
                                        {
                                            "name":"Altitude",
                                            "comment":"-1500 ft <= altitude <= 150000 ft",
                                            "type":"fixed_bytes",
                                            "length":2,
                                            "data_type":"int",
                                            "lsb":10.0
                                        },
                                        {
                                            "name":"Latitude",
                                            "comment":"In WGS.84 in two's complement.\n-90 <= latitude <= 90 deg.",
                                            "type":"fixed_bytes",
                                            "length":3,
                                            "data_type":"int",
                                            "lsb":2.1457672119140625E-5
                                        },
                                        {
                                            "name":"Longitude",
                                            "comment":"In WGS.84 in two's complement.\n-180 <= latitude < 180",
                                            "type":"fixed_bytes",
                                            "length":3,
                                            "data_type":"int",
                                            "lsb":2.1457672119140625E-5
                                        },
                                        {
                                            "name":"TID2",
                                            "type":"fixed_bitfield",
                                            "length":1,
                                            "items":[
                                                {
                                                    "name":"Point Type",
                                                    "comment":"0 Unknown\n1 Fly by waypoint (LT)\n2 Fly over waypoint (LT)\n3 Hold = 4 Procedure hold (LT)\n5 Procedure turn (LT)\n6 RF leg (LT)\n7 Top of climb (VT)\n8 Top of descent (VT)\n9 Start of level (VT)\n10 Cross-over altitude (VT)\n11 Transition altitude [VT]",
                                                    "type":"fixed_bits",
                                                    "start_bit":4,
                                                    "bit_length":4
                                                },
                                                {
                                                    "name":"TD",
                                                    "comment":"0 N/A\n 1 Turn right\n2 Turn left\n3 No turn",
                                                    "type":"fixed_bits",
                                                    "start_bit":2,
                                                    "bit_length":2
                                                },
                                                {
                                                    "name":"TRA",
                                                    "comment":"Turn Radius Availability\n0 TTR not available\n1 TTR available",
                                                    "type":"fixed_bits",
                                                    "start_bit":1,
                                                    "bit_length":1
                                                },
                                                {
                                                    "name":"TOA",
                                                    "comment":"0 TOV avilable\n1 TOV not available",
                                                    "type":"fixed_bits",
                                                    "start_bit":0,
                                                    "bit_length":1
                                                }
                                            ]
                                        },
                                        {
                                            "name":"TOV",
                                            "comment":"Time Over Point",
                                            "type":"fixed_bytes",
                                            "length":3,
                                            "data_type":"uint",
                                            "lsb":1.0
                                        },
                                        {
                                            "name":"TTR",
                                            "comment":"TCP Turn radius\n0 <= TTR <= 655.35 Nm",
                                            "type":"fixed_bytes",
                                            "length":2,
                                            "data_type":"uint",
                                            "lsb":0.01
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"COM",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":10,
                            "data_fields":[
                                {
                                    "name":"Communications/ACAS Capability and Flight Status reported by Mode-S",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"COM",
                                            "comment":"Communications capability of the transponder\n0 No communications capability (surveillance only)\n1 Comm. A and Comm. B capability\n2 Comm. A, Comm. B and Uplink ELM\n3 Comm. A, Comm. B, Uplink ELM and Downlink ELM\n4 Level 5 Transponder capability\n5 to 7 Not assigned",
                                            "type":"fixed_bits",
                                            "start_bit":13,
                                            "bit_length":3
                                        },
                                        {
                                            "name":"STAT",
                                            "comment":"Flight Status\n0 No alert, no SPI, aircraft airborne\n1 No alert, no SPI, aircraft on ground\n2 Alert, no SPI, aircraft airborne\n3 Alert, no SPI, aircraft on ground\n4 Alert, SPI, aircraft airborne or on ground\n5 No alert, SPI, aircraft airborne or on ground\n6 Not defined\n7 Unknown or not yet extracted",
                                            "type":"fixed_bits",
                                            "start_bit":10,
                                            "bit_length":3
                                        },
                                        {
                                            "name":"SSC",
                                            "comment":"Specific Service Capability\n0 No\n1 Yes",
                                            "type":"fixed_bits",
                                            "start_bit":7,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"ARC",
                                            "comment":"Altitude reporting capability\n0 100 ft resolution\n1 25 ft resolution",
                                            "type":"fixed_bits",
                                            "start_bit":6,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"AIC",
                                            "comment":"Aircraft identification capability\n0 No\n1 Yes",
                                            "type":"fixed_bits",
                                            "start_bit":5,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"B1A",
                                            "comment":"BDS 1,0 bit 16",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"B1B",
                                            "comment":"BDS 1,0 bits 37/40",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":4
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"SAB",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":11,
                            "data_fields":[
                                {
                                    "name":"Status reported by ADS-B",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"AC",
                                            "comment":"0 unknown\n1 ACAS not operational\n2 ACAS operational\n3 invalid",
                                            "type":"fixed_bits",
                                            "start_bit":14,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"MN",
                                            "comment":"0 unknown\n1 Multiple navigational aids not operating\n2 Multiple navigational aids operating\n3 invalid",
                                            "type":"fixed_bits",
                                            "start_bit":12,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"DC",
                                            "comment":"0 unknown\n1 Differential correction\n2 No differential correction\n3 invalid",
                                            "type":"fixed_bits",
                                            "start_bit":10,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"GBS",
                                            "comment":"0 Transponder Ground Bit not set or unknown\n1 Transponder Ground Bit set",
                                            "type":"fixed_bits",
                                            "start_bit":9,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"STAT",
                                            "comment":"Flight Status\n0 No emergency\n1 General emergency\n2 Lifeguard / medical\n3 Minimum fuel\n4 No communications\n5 Unlawful interference\n6 'Downed' Aircraft\n7 Unknown",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":3
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"ACS",
                            "comment":"Currently active Resolution Advisory (RA), if any, generated by the ACAS associated with the transponder transmitting the report and threat identity data.",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":12,
                            "data_fields":[
                                {
                                    "name":"MB Data",
                                    "comment":"56-bit message conveying Mode S Comm B message data of BDS Register 3,0",
                                    "type":"fixed_bytes",
                                    "length":7,
                                    "data_type":"bin"
                                }
                            ]
                        },
                        {
                            "name":"BVR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":13,
                            "data_fields":[
                                {
                                    "name":"Barometric Vertical Rate",
                                    "comment":"",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int",
                                    "lsb":6.25
                                }
                            ]
                        },
                        {
                            "name":"GVR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":14,
                            "data_fields":[
                                {
                                    "name":"Geometric Vertical Rate",
                                    "comment":"",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int",
                                    "lsb":6.25
                                }
                            ]
                        },
                        {
                            "name":"RAN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":16,
                            "data_fields":[
                                {
                                    "name":"Roll Angle",
                                    "comment":"Roll Angle in two’s complement form, -180 <= Roll Angle <= 180",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int",
                                    "lsb":0.01
                                }
                            ]
                        },
                        {
                            "name":"TAR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":17,
                            "data_fields":[
                                {
                                    "name":"Track Angle Rate",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"TI",
                                            "comment":"Turn Indicator\n0 Not available\n1 Left\n2 Right\n3 Straight",
                                            "type":"fixed_bits",
                                            "start_bit":14,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"Rate of Turn",
                                            "comment":"Rate of Turn in two’s complement form\n-15 °/s <= Rate of Turn <= 15 °/s",
                                            "type":"fixed_bits",
                                            "start_bit":1,
                                            "bit_length":7,
                                            "data_type":"int",
                                            "lsb":0.25
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"TAN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":18,
                            "data_fields":[
                                {
                                    "name":"Track Angle",
                                    "comment":"",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.00549316406
                                }
                            ]
                        },
                        {
                            "name":"GSP",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":19,
                            "data_fields":[
                                {
                                    "name":"Ground Speed",
                                    "comment":"Ground Speed in two's complement form referenced to WGS84\n-2 NM/s <= Ground Speed < 2 NM/s",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int",
                                    "lsb":6.103515625E-5
                                }
                            ]
                        },
                        {
                            "name":"VUN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":20,
                            "data_fields":[
                                {
                                    "name":"Velocity Uncertainty Category",
                                    "comment":"",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"MET",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":21,
                            "data_fields":[
                                {
                                    "name":"MET",
                                    "type":"compound",
                                    "field_specification":{
                                        "name":"available",
                                        "type":"extendable_bits",
                                        "data_type":"bitfield",
                                        "reverse_bits":true
                                    },
                                    "items":[
                                        {
                                            "name":"WS",
                                            "type":"optional_item",
                                            "optional_bitfield_name":"available",
                                            "optional_bitfield_index":0,
                                            "data_fields":[
                                                {
                                                    "name":"Wind Speed",
                                                    "comment":"0 <= Wind Speed <= 300",
                                                    "type":"fixed_bytes",
                                                    "length":2,
                                                    "data_type":"uint",
                                                    "lsb":1.0
                                                }
                                            ]
                                        },
                                        {
                                            "name":"WD",
                                            "type":"optional_item",
                                            "optional_bitfield_name":"available",
                                            "optional_bitfield_index":1,
                                            "data_fields":[
                                                {
                                                    "name":"Wind Direction",
                                                    "comment":"1 <= Wind Direction <= 360",
                                                    "type":"fixed_bytes",
                                                    "length":2,
                                                    "data_type":"uint",
                                                    "lsb":1.0
                                                }
                                            ]
                                        },
                                        {
                                            "name":"TMP",
                                            "type":"optional_item",
                                            "optional_bitfield_name":"available",
                                            "optional_bitfield_index":2,
                                            "data_fields":[
                                                {
                                                    "name":"Temperature",
                                                    "comment":"Temperature in degrees celsius\n-100 °C <= Temperature <= 100 °C",
                                                    "type":"fixed_bytes",
                                                    "length":2,
                                                    "data_type":"int",
                                                    "lsb":0.25
                                                }
                                            ]
                                        },
                                        {
                                            "name":"TRB",
                                            "type":"optional_item",
                                            "optional_bitfield_name":"available",
                                            "optional_bitfield_index":3,
                                            "data_fields":[
                                                {
                                                    "name":"Turbulence",
                                                    "comment":"Integer between 0 and 15 inclusive",
                                                    "type":"fixed_bytes",
                                                    "length":1,
                                                    "data_type":"uint"
                                                }
                                            ]
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"EMC",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":22,
                            "data_fields":[
                                {
                                    "name":"ECAT",
                                    "comment":"1 light aircraft ≤ 7000 kg\n2 reserved\n3 7000 kg < medium aircraft < 136000 kg\n4 reserved\n5 136000 kg ≤ heavy aircraft\n6 highly manoeuvrable (5g acceleration capability) and high speed (>400 knots cruise)\n7 to 9 reserved\n10 rotocraft\n11 glider / sailplane\n12 lighter-than-air\n13 unmanned aerial vehicle\n14 space / transatmospheric vehicle\n15 ultralight / handglider / paraglider\n16 parachutist / skydiver\n17 to 19 reserved\n20 surface emergency vehicle\n21 surface service vehicle\n22 fixed ground or tethered obstruction\n23 to 24 reserved",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"POS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":24,
                            "data_fields":[
                                {
                                    "name":"Latitude",
                                    "comment":"In WGS.84 in two’s complement form.\nRange -90 <= latitude <= 90 deg.",
                                    "type":"fixed_bytes",
                                    "length":3,
                                    "data_type":"int",
                                    "lsb":2.1457672119140625E-5
                                },
                                {
                                    "name":"Longitude",
                                    "comment":"In WGS.84 in two’s complement form.\nRange -180 <= longitude < 180 deg.",
                                    "type":"fixed_bytes",
                                    "length":3,
                                    "data_type":"int",
                                    "lsb":2.1457672119140625E-5
                                }
                            ]
                        },
                        {
                            "name":"GAL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":25,
                            "data_fields":[
                                {
                                    "name":"Geometric Altitude",
                                    "comment":"Altitude in two's complement form\n-1500 ft <= Altitude <= 150000 ft",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int",
                                    "lsb":6.25
                                }
                            ]
                        },
                        {
                            "name":"PUN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":26,
                            "data_fields":[
                                {
                                    "name":"Position Uncertainty",
                                    "comment":"",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"int"
                                }
                            ]
                        },
                        {
                            "name":"MB",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":27,
                            "data_fields":[
                                {
                                    "name":"Mode S MB Data",
                                    "type":"repetitive",
                                    "repetition_item":{
                                        "name":"REP",
                                        "type":"fixed_bytes",
                                        "length":1,
                                        "data_type":"uint"
                                    },
                                    "items":[
                                        {
                                            "name":"MB Data",
                                            "comment":"56-bit message conveying Mode S Comm B message data",
                                            "type":"fixed_bytes",
                                            "length":7,
                                            "data_type":"bin"
                                        },
                                        {
                                            "name":"address",
                                            "type":"fixed_bitfield",
                                            "length":1,
                                            "items":[
                                                {
                                                    "name":"BDS1",
                                                    "comment":"Comm B Data Buffer Store 1 Address",
                                                    "type":"fixed_bits",
                                                    "start_bit":4,
                                                    "bit_length":4
                                                },
                                                {
                                                    "name":"BDS2",
                                                    "comment":"Comm B Data Buffer Store 2 Address",
                                                    "type":"fixed_bits",
                                                    "start_bit":0,
                                                    "bit_length":4
                                                }
                                            ]
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"IAR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":28,
                            "data_fields":[
                                {
                                    "name":"Indicated Air Speed",
                                    "comment":"0 Kt <= Indicated Airspeed <= 1100 Kt",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":1.0
                                }
                            ]
                        },
                        {
                            "name":"MAC",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":29,
                            "data_fields":[
                                {
                                    "name":"Mach Number",
                                    "comment":"0 <= Mach Number <= 4.096",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.008
                                }
                            ]
                        },
                        {
                            "name":"BPS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":30,
                            "data_fields":[
                                {
                                    "name":"Barometric Pressure Setting",
                                    "comment":"BPS is the barometric pressure setting of the aircraft minus 800 mb.",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.1
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"390",
            "name":"Flight Plan Related Data",
            "comment":"All flight plan related information, provided by ground-based systems.",
            "type":"item",
            "data_fields":[
                {
                    "name":"390",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"TAG",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"SAC",
                                    "comment":"System Area Code",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                },
                                {
                                    "name":"SIC",
                                    "comment":"System Identity Code",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"CSN",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"CSN",
                                    "type":"fixed_bitfield",
                                    "length":7,
                                    "items":[
                                        {
                                            "name":"Callsign",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":56,
                                            "num_characters":7,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"IFI",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"IFPS_FLIGHT_ID",
                                    "type":"fixed_bitfield",
                                    "length":4,
                                    "items":[
                                        {
                                            "name":"TYP",
                                            "comment":"0 Plan Number\n1 Unit 1 internal flight number\n2 Unit 2 internal flight number\n3 Unit 3 internal flight number",
                                            "type":"fixed_bits",
                                            "start_bit":30,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"NBR",
                                            "comment":"Number from 0 to 99 999 999",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":27
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"FCT",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"Flight Category",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"GAT/OAT",
                                            "comment":"0 Unknown\n1 General Air Traffic\n2 Operational Air Traffic\n3 Not applicable",
                                            "type":"fixed_bits",
                                            "start_bit":6,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"FR1/FR2",
                                            "comment":"0 Instrument Flight Rules\n1 Visual Flight Rules\n2 Not applicable\n3 Controlled Visual Flight Rules",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"RVSM",
                                            "comment":"0 Unknown\n1 Approved\n2 Exempt\n3 Not Approved",
                                            "type":"fixed_bits",
                                            "start_bit":2,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"HPR",
                                            "comment":"0 Normal Priority Flight\n1 High Priority Flight",
                                            "type":"fixed_bits",
                                            "start_bit":1,
                                            "bit_length":1
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"TAC",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"TAC",
                                    "type":"fixed_bitfield",
                                    "length":4,
                                    "items":[
                                        {
                                            "name":"Type of Aircraft",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":32,
                                            "num_characters":4,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"WTC",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"WTC",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"Wake Turbulence Category",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":8,
                                            "num_characters":1,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"DEP",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":6,
                            "data_fields":[
                                {
                                    "name":"DEP",
                                    "type":"fixed_bitfield",
                                    "length":4,
                                    "items":[
                                        {
                                            "name":"Departure Airport",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":32,
                                            "num_characters":4,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"DST",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":8,
                            "data_fields":[
                                {
                                    "name":"DST",
                                    "type":"fixed_bitfield",
                                    "length":4,
                                    "items":[
                                        {
                                            "name":"Destination Airport",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":32,
                                            "num_characters":4,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"RDS",
                            "comment":"Runway Designation",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":9,
                            "data_fields":[
                                {
                                    "name":"NU1",
                                    "comment":"First number",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                },
                                {
                                    "name":"NU2",
                                    "comment":"Second number",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                },
                                {
                                    "name":"LTR",
                                    "comment":"Letter",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"CFL",
                            "comment":"Current Cleared Flight Level",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":10,
                            "data_fields":[
                                {
                                    "name":"CFL",
                                    "comment":"",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"CTL",
                            "comment":"Current Control Position",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":11,
                            "data_fields":[
                                {
                                    "name":"Centre",
                                    "comment":"8-bit group Identification code",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                },
                                {
                                    "name":"Position",
                                    "comment":"8-bit Control Position identification code",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"TOD",
                            "comment":"Time of Departure / Arrival",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":12,
                            "data_fields":[
                                {
                                    "name":"Time of Departure / Arrival",
                                    "type":"repetitive",
                                    "repetition_item":{
                                        "name":"REP",
                                        "type":"fixed_bytes",
                                        "length":1,
                                        "data_type":"uint"
                                    },
                                    "items":[
                                        {
                                            "name":"TOD1",
                                            "type":"fixed_bitfield",
                                            "length":4,
                                            "items":[
                                                {
                                                    "name":"TYP",
                                                    "comment":"0 Scheduled off-block time\n1 Estimated off-block time\n2 Estimated take-off time\n3 Actual off-block time\n4 Predicted time at runway hold\n5 Actual time at runway hold\n6 Actual line-up time\n7 Actual take-off time\n8 Estimated time of arrival\n9 Predicted landing time\n10 Actual landing time\n11 Actual time off runway\n12 Predicted time to gate\n13 Actual on-block time",
                                                    "type":"fixed_bits",
                                                    "start_bit":27,
                                                    "bit_length":5
                                                },
                                                {
                                                    "name":"DAY",
                                                    "comment":"0 Today\n1 Yesterday\n2 Tomorrow\n3 Invalid",
                                                    "type":"fixed_bits",
                                                    "start_bit":25,
                                                    "bit_length":2
                                                },
                                                {
                                                    "name":"HOR",
                                                    "comment":"Hours, from 0 to 23",
                                                    "type":"fixed_bits",
                                                    "start_bit":16,
                                                    "bit_length":5
                                                },
                                                {
                                                    "name":"MIN",
                                                    "comment":"Minutes, from 0 to 59",
                                                    "type":"fixed_bits",
                                                    "start_bit":8,
                                                    "bit_length":6
                                                },
                                                {
                                                    "name":"AVS",
                                                    "comment":"0 Seconds available\n1 Seconds not available",
                                                    "type":"fixed_bits",
                                                    "start_bit":7,
                                                    "bit_length":1
                                                },
                                                {
                                                    "name":"SEC",
                                                    "comment":"Seconds, from 0 to 59",
                                                    "type":"fixed_bits",
                                                    "start_bit":0,
                                                    "bit_length":6
                                                }
                                            ]
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"AST",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":13,
                            "data_fields":[
                                {
                                    "name":"AST",
                                    "type":"fixed_bitfield",
                                    "length":6,
                                    "items":[
                                        {
                                            "name":"Aircraft Stand",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":48,
                                            "num_characters":6,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"STS",
                            "comment":"Stand Status",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":14,
                            "data_fields":[
                                {
                                    "name":"STS",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"EMP",
                                            "comment":"0 Empty\n1 Occupied\n2 Unknown\n3 Invalid",
                                            "type":"fixed_bits",
                                            "start_bit":6,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"AVL",
                                            "comment":"0 Available\n1 Not available\n2 Unknown\n3 Invalid",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":2
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"STD",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":16,
                            "data_fields":[
                                {
                                    "name":"STD",
                                    "type":"fixed_bitfield",
                                    "length":7,
                                    "items":[
                                        {
                                            "name":"Standard Instrument Departure",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":56,
                                            "num_characters":7,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"STA",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":17,
                            "data_fields":[
                                {
                                    "name":"STA",
                                    "type":"fixed_bitfield",
                                    "length":7,
                                    "items":[
                                        {
                                            "name":"Standard Instrument Arrival",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":56,
                                            "num_characters":7,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"PEM",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":18,
                            "data_fields":[
                                {
                                    "name":"Pre-Emergency Mode 3/A",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"VA",
                                            "comment":"Validity\n0 No valid Mode 3/A available\n1 Valid Mode 3/A available",
                                            "type":"fixed_bits",
                                            "start_bit":12,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"Mode-3/A reply",
                                            "comment":"In octal representation",
                                            "type":"fixed_bits",
                                            "data_type":"digits",
                                            "start_bit":0,
                                            "bit_length":12,
                                            "num_digits":4,
                                            "digit_bit_length":3
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"PEC",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":19,
                            "data_fields":[
                                {
                                    "name":"PEC",
                                    "type":"fixed_bitfield",
                                    "length":7,
                                    "items":[
                                        {
                                            "name":"Pre-Emergency Callsign",
                                            "comment":"",
                                            "type":"fixed_bits",
                                            "data_type":"ascii_characters",
                                            "start_bit":0,
                                            "bit_length":56,
                                            "num_characters":7,
                                            "character_bit_length":8
                                        }
                                    ]
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"500",
            "name":"Estimated Accuracies",
            "comment":"Overview of all important accuracies",
            "type":"item",
            "data_fields":[
                {
                    "name":"500",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"APC",
                            "comment":"Estimated Accuracy Of Track Position [Cartesian]",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"APC [X-Component]",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated position of a target expressed in Cartesian co-ordinates.",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.5
                                },
                                {
                                    "name":"APC [Y-Component]",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated position of a target expressed in Cartesian co-ordinates.",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":0.5
                                }
                            ]
                        },
                        {
                            "name":"COV",
                            "comment":"XY covariance component",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"COV [XY Covariance Component]",
                                    "comment":"XY Covariance Component in two’s complement form",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"int",
                                    "lsb":0.5
                                }
                            ]
                        },
                        {
                            "name":"APW",
                            "comment":"Estimated Accuracy Of Track Position [WGS-84]",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"APW [Latitude Component]",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated position of a target expressed in WGS-84.",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":5.36441802978515625E-6
                                },
                                {
                                    "name":"APW [Longitude Component]",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated position of a target expressed in WGS-84.",
                                    "type":"fixed_bytes",
                                    "length":2,
                                    "data_type":"uint",
                                    "lsb":5.36441802978515625E-6
                                }
                            ]
                        },
                        {
                            "name":"AGA",
                            "comment":"Estimated Accuracy Of Calculated Track Geometric Altitude",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"AGA",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated geometric altitude of a target.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":6.25
                                }
                            ]
                        },
                        {
                            "name":"ABA",
                            "comment":"Estimated Accuracy Of Calculated Track Barometric Altitude",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"ABA",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated barometric altitude of the track.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"ATV",
                            "comment":"Estimated Accuracy Of Track Velocity [Cartesian]",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"ATV [X-Component]",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated track velocity in Cartesian co-ordinates.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                },
                                {
                                    "name":"ATV [Y-Component]",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated track velocity in Cartesian co-ordinates.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"AA",
                            "comment":"Estimated Accuracy Of Acceleration [Cartesian]",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":6,
                            "data_fields":[
                                {
                                    "name":"AA [X-Component]",
                                    "comment":"Estimated accuracy [i.e. standard deviation] of the calculated acceleration in Cartesian co-ordinates.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                },
                                {
                                    "name":"AA [Y-Component]",
                                    "comment":"Estimated accuracy [i.e. standard deviation] of the calculated acceleration in Cartesian co-ordinates.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.25
                                }
                            ]
                        },
                        {
                            "name":"ARC",
                            "comment":"Estimated Accuracy Of Rate Of Climb/Descent",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":8,
                            "data_fields":[
                                {
                                    "name":"ARC",
                                    "comment":"Estimated accuracy (i.e. standard deviation) of the calculated rate of Climb/Descent of an aircraft.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":6.25
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"510",
            "name":"Composed Track Number",
            "comment":"Identification of a system track",
            "type":"item",
            "data_fields":[
                {
                    "name":"Composed Track Number",
                    "type":"extendable",
                    "items":[
                        {
                            "name":"Composed Track Number",
                            "type":"fixed_bitfield",
                            "length":3,
                            "items":[
                                {
                                    "name":"SYSTEM UNIT IDENTIFICATION",
                                    "comment":"",
                                    "type":"fixed_bits",
                                    "start_bit":16,
                                    "bit_length":8
                                },
                                {
                                    "name":"SYSTEM TRACK NUMBER",
                                    "comment":"",
                                    "type":"fixed_bits",
                                    "start_bit":1,
                                    "bit_length":15
                                },
                                {
                                    "name":"extend",
                                    "type":"fixed_bits",
                                    "start_bit":0,
                                    "bit_length":1
                                }
                            ]
                        }
                    ]
                }
            ]
        }
    ]
}
)";
  };
};
