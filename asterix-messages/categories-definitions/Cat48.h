#pragma once

#include "CatDefinitionBase.h"
#include <fstream>
#include <iostream>
namespace AsterixMessageCategories
{
  class Cat48 : public CatDefinitionBase
  {

    // NOT: Hangi json yazımının kullanılacağına daha sonra karar verilecek.
    // private:
    // inline static std::string cat48_str = R"({"field_specification":{"data_type":"bitfield","name":"FSPEC","reverse_bits":true,"type":"extendable_bits"},"items":[{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":1,"name":"Message Type","type":"fixed_bytes"}],"name":"Message Type","number":"000","type":"item"},{"comment":"","data_fields":[{"comment":"System Area Code","data_type":"uint","length":1,"name":"SAC","type":"fixed_bytes"},{"comment":"System Identification Code","data_type":"uint","length":1,"name":"SIC","type":"fixed_bytes"}],"name":"Data Source Identifier","number":"010","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":1,"lsb":1.40625,"name":"Sector Number","type":"fixed_bytes"}],"name":"Sector Number","number":"020","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":3,"lsb":0.0078125,"name":"Time of Day","type":"fixed_bytes"}],"name":"Time of Day","number":"030","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":2,"lsb":0.0078125,"name":"Antenna Rotation Speed","type":"fixed_bytes"}],"name":"Antenna Rotation Speed","number":"041","type":"item"},{"comment":"","data_fields":[{"field_specification":{"data_type":"bitfield","name":"available","reverse_bits":true,"type":"extendable_bits"},"items":[{"data_fields":[{"items":[{"bit_length":1,"comment":"","name":"NOGO","start_bit":7,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"RDPC","start_bit":6,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"RDPR","start_bit":5,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL RDP","start_bit":4,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL XMT","start_bit":3,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"MSC","start_bit":2,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"TSV","start_bit":1,"type":"fixed_bits"}],"length":1,"name":"COM","type":"fixed_bitfield"}],"name":"COM","optional_bitfield_index":0,"optional_bitfield_name":"available","type":"optional_item"},{"data_fields":[{"items":[{"bit_length":1,"comment":"","name":"ANT","start_bit":7,"type":"fixed_bits"},{"bit_length":2,"comment":"","name":"CH-A/B","start_bit":5,"type":"fixed_bits"},{"bit_length":1,"comment":"Overload condition\n0 No overload\n1 Overload","name":"OVL","start_bit":4,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"MSC","start_bit":3,"type":"fixed_bits"}],"length":1,"name":"PSR","type":"fixed_bitfield"}],"name":"PSR","optional_bitfield_index":3,"optional_bitfield_name":"available","type":"optional_item"},{"data_fields":[{"items":[{"bit_length":1,"comment":"","name":"ANT","start_bit":7,"type":"fixed_bits"},{"bit_length":2,"comment":"","name":"CH-A/B","start_bit":5,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL","start_bit":4,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"MSC","start_bit":4,"type":"fixed_bits"}],"length":1,"name":"SSR","type":"fixed_bitfield"}],"name":"SSR","optional_bitfield_index":4,"optional_bitfield_name":"available","type":"optional_item"},{"data_fields":[{"items":[{"bit_length":1,"comment":"","name":"ANT","start_bit":15,"type":"fixed_bits"},{"bit_length":2,"comment":"","name":"CH-A/B","start_bit":13,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL SUR","start_bit":12,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"MSC","start_bit":11,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"SCF","start_bit":10,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"DLF","start_bit":9,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL SCF","start_bit":8,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL DLF","start_bit":7,"type":"fixed_bits"}],"length":2,"name":"MDS","type":"fixed_bitfield"}],"name":"MDS","optional_bitfield_index":5,"optional_bitfield_name":"available","type":"optional_item"}],"name":"050","type":"compound"}],"name":"System Configuration and Status","number":"050","type":"item"},{"comment":"","data_fields":[{"field_specification":{"data_type":"bitfield","name":"available","reverse_bits":true,"type":"extendable_bits"},"items":[{"comment":"","data_fields":[{"items":[{"bit_length":3,"comment":"","name":"RED-RDP","start_bit":4,"type":"fixed_bits"},{"bit_length":3,"comment":"","name":"RED-XMT","start_bit":1,"type":"fixed_bits"}],"length":1,"name":"COM","type":"fixed_bitfield"}],"name":"COM","optional_bitfield_index":0,"optional_bitfield_name":"available","type":"optional_item"},{"comment":"","data_fields":[{"items":[{"bit_length":1,"comment":"","name":"POL","start_bit":7,"type":"fixed_bits"},{"bit_length":3,"comment":"","name":"RED-RAD","start_bit":4,"type":"fixed_bits"},{"bit_length":2,"comment":"","name":"STC","start_bit":2,"type":"fixed_bits"}],"length":1,"name":"PSR","type":"fixed_bitfield"}],"name":"PSR","optional_bitfield_index":3,"optional_bitfield_name":"available","type":"optional_item"},{"comment":"","data_fields":[{"items":[{"bit_length":3,"comment":"","name":"RED-RAD","start_bit":5,"type":"fixed_bits"}],"length":1,"name":"SSR","type":"fixed_bitfield"}],"name":"SSR","optional_bitfield_index":4,"optional_bitfield_name":"available","type":"optional_item"},{"comment":"","data_fields":[{"items":[{"bit_length":3,"comment":"","name":"RED-RAD","start_bit":5,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"CLU","start_bit":4,"type":"fixed_bits"}],"length":1,"name":"MDS","type":"fixed_bitfield"}],"name":"MDS","optional_bitfield_index":5,"optional_bitfield_name":"available","type":"optional_item"}],"name":"060","type":"compound"}],"name":"System Processing Mode","number":"060","type":"item"},{"comment":"","data_fields":[{"items":[{"items":[{"bit_length":5,"comment":"","name":"TYP","start_bit":11,"type":"fixed_bits"},{"bit_length":11,"comment":"","name":"COUNTER","start_bit":0,"type":"fixed_bits"}],"length":2,"name":"plot_count_values","type":"fixed_bitfield"}],"name":"plot_count_values","repetition_item":{"data_type":"uint","length":1,"name":"REP","type":"fixed_bytes"},"type":"repetitive"}],"name":"Message Count Values","number":"070","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"int","length":1,"lsb":0.0078125,"name":"RANGE ERROR","type":"fixed_bytes"},{"comment":"","data_type":"int","length":1,"lsb":0.02197265625,"name":"AZIMUTH ERROR","type":"fixed_bytes"}],"name":"Collimation Error","number":"090","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":2,"lsb":0.00390625,"name":"RHO-START","type":"fixed_bytes"},{"comment":"","data_type":"uint","length":2,"lsb":0.00390625,"name":"RHO-END","type":"fixed_bytes"},{"comment":"","data_type":"uint","length":2,"lsb":0.00549316406,"name":"THETA-START","type":"fixed_bytes"},{"comment":"","data_type":"uint","length":2,"lsb":0.00549316406,"name":"THETA-END","type":"fixed_bytes"}],"name":"Generic Polar Window","number":"100","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":1,"name":"TYP","type":"fixed_bytes"}],"name":"Data Filter","number":"110","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"int","length":2,"lsb":1.0,"name":"Height of Data Source","type":"fixed_bytes"},{"comment":"","data_type":"int","length":3,"lsb":2.145767e-05,"name":"Latitude","type":"fixed_bytes"},{"comment":"","data_type":"int","length":3,"lsb":2.145767e-05,"name":"Longitude","type":"fixed_bytes"}],"name":"3D-Position Of Data Source","number":"120","type":"item"}],"name":"cat034_1.26_record","type":"record","uap":["010","000","030","020","041","050","060","FX","070","100","110","120","090","RE","SP","FX"]})";

  public:
    static void get(json &cat_definition)
    {
      CatDefinitionBase::get(cat_definition, cat48_str);
    }

  private:
    inline static std::string cat48_str = R"({
    "name":"cat048_1.23_record",
    "type":"record",
    "field_specification":{
        "name":"FSPEC",
        "type":"extendable_bits",
        "reverse_bits":true,
        "data_type":"bitfield"
    },
    "uap":[
        "010",
        "140",
        "020",
        "040",
        "070",
        "090",
        "130",
        "FX",
        "220",
        "240",
        "250",
        "161",
        "042",
        "200",
        "170",
        "FX",
        "210",
        "030",
        "080",
        "100",
        "110",
        "120",
        "230",
        "FX",
        "260",
        "055",
        "050",
        "065",
        "060",
        "SP",
        "RE",
        "FX"
    ],
    "items":[
        {
            "number":"010",
            "name":"Data Source Identifier",
            "comment":"Identification of the radar station from which the data are received.",
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
            "number":"020",
            "name":"Target Report Descriptor",
            "comment":"Type and properties of the target report.",
            "type":"item",
            "data_fields":[
                {
                    "name":"target_report_descriptor",
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
                            "name":"RDP",
                            "comment":"0 Report from RDP Chain 1\n1 Report from RDP Chain 2",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"SPI",
                            "comment":"0 Absence of SPI\n1 Special Position Identification",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"RAB",
                            "comment":"0 Report from aircraft transponder\n1 Report from field monitor",
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
                    "name":"target_report_descriptor_first_extend",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"TST",
                            "comment":"0 Real target report\n1 Test target report",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"ERR",
                            "comment":"0 No Extended Range\n1 Extended Range present",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"XPP",
                            "comment":"0 No X-Pulse present\n1 X-Pulse present",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"ME",
                            "comment":"0 No military emergency\n1 Military emergency",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"MI",
                            "comment":"0 No military identification\n1 Military identification",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"FOE/FRI",
                            "comment":"00 No Mode 4 interrogation\n01 Friendly target\n10 Unknown target\n11 No reply",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":2
                        },
                        {
                            "name":"FX2",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                }
            ]
        },
        {
            "number":"030",
            "name":"Warning/Error Conditions",
            "comment":"Warning/error conditions detected by a radar station for the target report involved.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Warning/Error Conditions",
                    "type":"extendable",
                    "items":[
                        {
                            "name":"warning/error_condition",
                            "type":"fixed_bitfield",
                            "length":1,
                            "items":[
                                {
                                    "name":"W/E Value",
                                    "comment":"0 Not defined; never used.\n1 Multipath Reply (Reflection)\n2 Reply due to sidelobe interrogation/reception\n3 Split plot\n4 Second time around reply\n5 Angel\n6 Slow moving target correlated with road infrastructure (terrestrial vehicle)\n7 Fixed PSR plot\n8 Slow PSR target\n9 Low quality PSR plot\n10 Phantom SSR plot\n11 Non-Matching Mode-3/A Code\n12 Mode C code / Mode S altitude code abnormal value compared to the track\n13 Target in Clutter Area\n14 Maximum Doppler Response in Zero Filter\n15 Transponder anomaly detected\n16 Duplicated or Illegal Mode S Aircraft Address\n17 Mode S error correction applied\n18 Undecodable Mode C code / Mode S altitude code\n19 Birds\n20 Flock of Birds\n21 Mode 1 was present in original reply\n22 Mode 2 was present in original reply\n23 Plot potentially caused by Wind Turbine",
                                    "type":"fixed_bits",
                                    "start_bit":1,
                                    "bit_length":7
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
        },
        {
            "number":"040",
            "name":"Measured Position in Polar Co-ordinates",
            "comment":"Measured position of an aircraft in local polar co-ordinates",
            "type":"item",
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
            "number":"042",
            "name":"Calculated Position in Cartesian Co-ordinates",
            "comment":"Calculated position of an aircraft in Cartesian co-ordinates.",
            "type":"item",
            "data_fields":[
                {
                    "name":"X-Component",
                    "comment":"Max. range = +/-256 NM",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.0078125
                },
                {
                    "name":"Y-Component",
                    "comment":"Max. range = +/-256 NM",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"050",
            "name":"Mode-2 Code in Octal Representation",
            "comment":"Reply to Mode-2 interrogation.",
            "type":"item",
            "data_fields":[
                {
                    "name":"mode_2",
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
                            "comment":"0 Mode-2 code as derived from the reply of the transponder\n1 Smoothed Mode-2 code as provided by a local tracker",
                            "type":"fixed_bits",
                            "start_bit":13,
                            "bit_length":1
                        },
                        {
                            "name":"Mode-2 code",
                            "comment":"",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":12
                        }
                    ]
                }
            ]
        },
        {
            "number":"055",
            "name":"Mode-1 Code in Octal Representation",
            "comment":"Reply to Mode-1 interrogation",
            "type":"item",
            "data_fields":[
                {
                    "name":"mode_1",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"V",
                            "comment":"0 Code validated\n1 Code not validated",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"G",
                            "comment":"0 Default\n1 Garbled Code",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"L",
                            "comment":"0 Mode-1 code as derived from the reply of the transponder.\n1 Smoothed Mode-1 code as provided by a local tracker.",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"Mode-1 code",
                            "comment":"",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":5
                        }
                    ]
                }
            ]
        },
        {
            "number":"060",
            "name":"Mode-2 Code Confidence Indicator",
            "comment":"Confidence level for each bit of a Mode-2 reply as provided by a monopulse SSR station.",
            "type":"item",
            "data_fields":[
                {
                    "name":"QXi",
                    "comment":"0 High quality pulse Xi\n1 Low quality pulse Xi",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"065",
            "name":"Mode-1 Code Confidence Indicator",
            "comment":"Confidence level for each bit of a Mode-1 reply as provided by a monopulse SSR station.",
            "type":"item",
            "data_fields":[
                {
                    "name":"QXi",
                    "comment":"0 High quality pulse Xi\n1 Low quality pulse Xi",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"070",
            "name":"Mode-3/A Code in Octal Representation",
            "comment":"Mode-3/A code converted into octal representation.",
            "type":"item",
            "data_fields":[
                {
                    "name":"mode-3/a",
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
            "number":"080",
            "comment":"Confidence level for each bit of a Mode-3/A reply as provided by a monopulse SSR station.",
            "name":"Mode-3/A Code Confidence Indicator",
            "type":"item",
            "data_fields":[
                {
                    "name":"QXi",
                    "comment":"0 High quality pulse Xi\n1 Low quality pulse Xi",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"090",
            "name":"Flight Level in Binary Representation",
            "comment":"Flight Level converted into binary representation.",
            "type":"item",
            "data_fields":[
                {
                    "name":"flight_level",
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
                            "name":"Flight Level",
                            "comment":"",
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
            "number":"100",
            "name":"Mode-C Code and Code Confidence Indicator",
            "comment":"Mode-C height in Gray notation as received from the transponder together with the confidence level for each reply bit as provided by a MSSR/Mode S station.",
            "type":"item",
            "data_fields":[
                {
                    "name":"mode_c_code",
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
                            "name":"Mode-C reply",
                            "comment":"Mode-C reply in Gray notation",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":12
                        }
                    ]
                },
                {
                    "name":"QXi",
                    "comment":"0 High quality pulse Xi\n1 Low quality pulse Xi",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"110",
            "name":"Height Measured by a 3D Radar",
            "comment":"Height of a target as measured by a 3D radar. The height shall use mean sea level as the zero reference level.",
            "type":"item",
            "data_fields":[
                {
                    "name":"3D-Height",
                    "comment":"3D height, in binary notation. Negative values are expressed in two’s complement",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":25.0
                }
            ]
        },
        {
            "number":"120",
            "name":"Radial Doppler Speed",
            "comment":"Information on the Doppler Speed of the target report.",
            "type":"item",
            "data_fields":[
                {
                    "name":"120",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"CAL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"Calculated Doppler Speed",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"D",
                                            "comment":"0 Doppler speed is valid\n1 Doppler speed is doubtful",
                                            "type":"fixed_bits",
                                            "start_bit":15,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"CAL",
                                            "comment":"Calculated Doppler Speed, coded in two’s complement",
                                            "type":"fixed_bits",
                                            "start_bit":0,
                                            "bit_length":10,
                                            "data_type":"int"
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"RDS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"Raw Doppler Speed",
                                    "type":"repetitive",
                                    "repetition_item":{
                                        "name":"REP",
                                        "type":"fixed_bytes",
                                        "length":1,
                                        "data_type":"uint"
                                    },
                                    "items":[
                                        {
                                            "name":"DOP",
                                            "comment":"Doppler Speed",
                                            "type":"fixed_bytes",
                                            "length":2,
                                            "data_type":"uint"
                                        },
                                        {
                                            "name":"AMB",
                                            "comment":"Ambiguity Range",
                                            "type":"fixed_bytes",
                                            "length":2,
                                            "data_type":"uint"
                                        },
                                        {
                                            "name":"FRQ",
                                            "comment":"Transmitter Frequency",
                                            "type":"fixed_bytes",
                                            "length":2,
                                            "data_type":"uint"
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
            "number":"130",
            "name":"Radar Plot Characteristics",
            "comment":"",
            "type":"item",
            "data_fields":[
                {
                    "name":"130",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"SRL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"value",
                                    "comment":"SSR plot runlength, expressed as a positive binary value.",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.0439453125
                                }
                            ]
                        },
                        {
                            "name":"SRR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"value",
                                    "comment":"Number of received replies for (M)SSR",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint"
                                }
                            ]
                        },
                        {
                            "name":"SAM",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"value",
                                    "comment":"Amplitude of (M)SSR reply",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"int"
                                }
                            ]
                        },
                        {
                            "name":"PRL",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"value",
                                    "comment":"Primary Plot Runlength, expressed as positive binary value",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"uint",
                                    "lsb":0.0439453125
                                }
                            ]
                        },
                        {
                            "name":"PAM",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"value",
                                    "comment":"Amplitude of Primary Plot",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"int"
                                }
                            ]
                        },
                        {
                            "name":"RPD",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"value",
                                    "comment":"Range [PSR-SSR]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"int",
                                    "lsb":0.00390625
                                }
                            ]
                        },
                        {
                            "name":"APD",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":6,
                            "data_fields":[
                                {
                                    "name":"value",
                                    "comment":"Azimuth [PSR-SSR]",
                                    "type":"fixed_bytes",
                                    "length":1,
                                    "data_type":"int",
                                    "lsb":0.02197265625
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"140",
            "name":"Time of Day",
            "comment":"Absolute time stamping expressed as Co-ordinated Universal Time (UTC).",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time-of-Day",
                    "comment":"Acceptable Range of values: 0<= Time-of-Day<=24 hrs",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"161",
            "name":"Track Number",
            "comment":"An integer value representing a unique reference to a track record within a particular track file.",
            "type":"item",
            "data_fields":[
                {
                    "name":"TRACK NUMBER",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"170",
            "name":"Track Status",
            "comment":"Status of monoradar track (PSR and/or SSR updated).",
            "type":"item",
            "data_fields":[
                {
                    "name":"track_status",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"CNF",
                            "comment":"Confirmed vs. Tentative Track\n0 Confirmed Track\n1 Tentative Track",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"RAD",
                            "comment":"Type of Sensor(s) maintaining Track\n00 Combined Track\n01 PSR Track\n10 SSR/Mode S Track\n11 Invalid",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":2
                        },
                        {
                            "name":"DOU",
                            "comment":"Signals level of confidence in plot to track association process\n0 Normal confidence\n1 Low confidence in plot to track association.",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"MAH",
                            "comment":"Manoeuvre detection in Horizontal Sense\n0 No horizontal man.sensed\n1 Horizontal man. sensed",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"CDM",
                            "comment":"Climbing / Descending Mode\n00 Maintaining\n01 Climbing\n10 Descending\n11 Unknown",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":2
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
                    "name":"track_status_first_extend",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"TRE",
                            "comment":"Signal for End_of_Track\n0 Track still alive\n1 End of track lifetime[last report for this track]",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"GHO",
                            "comment":"Ghost vs. true target\n0 True target track.\n1 Ghost target track.",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"SUP",
                            "comment":"Track maintained with track information from neighbouring Node B on the cluster, or network\n0 no\n1 yes",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"TCC",
                            "comment":"Type of plot coordinate transformation mechanism: 0 Tracking performed in so-called 'Radar Plane', i.e. neither slant range correction nor stereographical projection was applied.\n1 Slant range correction and a suitable projection technique are used to track in a 2D.reference plane, tangential to the earth model at the Radar Site co-ordinates.",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        }
                    ]
                }
            ]
        },
        {
            "number":"200",
            "name":"Calculated Track Velocity in Polar Co-ordinates",
            "comment":"Calculated track velocity expressed in polar co-ordinates.",
            "type":"item",
            "data_fields":[
                {
                    "name":"CALCULATED GROUNDSPEED",
                    "comment":"[max. 2 NM/s]",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.2197265625
                },
                {
                    "name":"CALCULATED HEADING",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint",
                    "lsb":0.0054931640625
                }
            ]
        },
        {
            "number":"210",
            "name":"Track Quality",
            "comment":"Track quality in the form of a vector of standard deviations.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Sigma [X]",
                    "comment":"Standard Deviation on the horizontal axis of the local grid system\n0<= Sigma(X)<2 NM",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint",
                    "lsb":0.0078125
                },
                {
                    "name":"Sigma [Y]",
                    "comment":"Standard Deviation on the vertical axis of the local grid system\n0<= Sigma(Y)<2 NM",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint",
                    "lsb":0.0078125
                },
                {
                    "name":"Sigma [V]",
                    "comment":"Standard Deviation on the groundspeed within the local grid system\n0<=Sigma (V)<56.25 Kt",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint",
                    "lsb":0.2197265625
                },
                {
                    "name":"Sigma [H]",
                    "comment":"Standard Deviation on the heading within the local grid system\n0 <= sigma(H) < 22.5 degrees",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint",
                    "lsb":0.087890625
                }
            ]
        },
        {
            "number":"220",
            "name":"Aircraft Address",
            "comment":"Aircraft address (24-bits Mode S address) assigned uniquely to each aircraft.",
            "type":"item",
            "data_fields":[
                {
                    "name":"AIRCRAFT ADDRESS",
                    "comment":"24-bits Mode S address",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"230",
            "name":"Communications/ACAS Capability and Flight Status",
            "comment":"Communications capability of the transponder, capability of the on-board ACAS equipment and flight status.",
            "type":"item",
            "data_fields":[
                {
                    "name":"communication/acas_capability_and_flight_status",
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
                            "comment":"Flight Status\n0 No alert, no SPI, aircraft airborne\n1 No alert, no SPI, aircraft on ground\n2 Alert, no SPI, aircraft airborne\n3 Alert, no SPI, aircraft on ground\n4 Alert, SPI, aircraft airborne or on ground\n5 No alert, SPI, aircraft airborne or on ground\n6 Not assigned\n7 Unknown",
                            "type":"fixed_bits",
                            "start_bit":10,
                            "bit_length":3
                        },
                        {
                            "name":"SI",
                            "comment":"SI/II Transponder Capability\n0 No\n1 Yes",
                            "type":"fixed_bits",
                            "start_bit":9,
                            "bit_length":1
                        },
                        {
                            "name":"MSSC",
                            "comment":"Mode-S Specific Service Capability\n0 No\n1 Yes",
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
            "number":"240",
            "name":"Aircraft Identification",
            "comment":"Aircraft identification (in 8 characters) obtained from an aircraft equipped with a Mode S transponder.",
            "type":"item",
            "data_fields":[
                {
                    "name":"aircraft_identification",
                    "type":"fixed_bitfield",
                    "length":6,
                    "items":[
                        {
                            "name":"Aircraft Identification",
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
            "number":"250",
            "name":"Mode S MB Data",
            "comment":"Mode S Comm B data as extracted from the aircraft transponder.",
            "type":"item",
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
            "number":"260",
            "name":"ACAS Resolution Advisory Report",
            "comment":"Currently active Resolution Advisory (RA), if any, generated by the ACAS associated with the transponder transmitting the report and threat identity data.",
            "type":"item",
            "data_fields":[
                {
                    "name":"MB DATA",
                    "comment":"56-bit message conveying Mode S Comm B message data of BDS Register 3,0.",
                    "type":"fixed_bytes",
                    "length":7,
                    "data_type":"bin"
                }
            ]
        }
    ]
}
)";
  };
};
