#pragma once

#include "CatDefinitionBase.h"

namespace AsterixMessageCategories
{
    class Cat34 : public CatDefinitionBase
    {
        // NOT: Hangi json yazımının kullanılacağına daha sonra karar verilecek.
        // private:
        // inline static std::string cat34_str = R"({"field_specification":{"data_type":"bitfield","name":"FSPEC","reverse_bits":true,"type":"extendable_bits"},"items":[{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":1,"name":"Message Type","type":"fixed_bytes"}],"name":"Message Type","number":"000","type":"item"},{"comment":"","data_fields":[{"comment":"System Area Code","data_type":"uint","length":1,"name":"SAC","type":"fixed_bytes"},{"comment":"System Identification Code","data_type":"uint","length":1,"name":"SIC","type":"fixed_bytes"}],"name":"Data Source Identifier","number":"010","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":1,"lsb":1.40625,"name":"Sector Number","type":"fixed_bytes"}],"name":"Sector Number","number":"020","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":3,"lsb":0.0078125,"name":"Time of Day","type":"fixed_bytes"}],"name":"Time of Day","number":"030","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":2,"lsb":0.0078125,"name":"Antenna Rotation Speed","type":"fixed_bytes"}],"name":"Antenna Rotation Speed","number":"041","type":"item"},{"comment":"","data_fields":[{"field_specification":{"data_type":"bitfield","name":"available","reverse_bits":true,"type":"extendable_bits"},"items":[{"data_fields":[{"items":[{"bit_length":1,"comment":"","name":"NOGO","start_bit":7,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"RDPC","start_bit":6,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"RDPR","start_bit":5,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL RDP","start_bit":4,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL XMT","start_bit":3,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"MSC","start_bit":2,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"TSV","start_bit":1,"type":"fixed_bits"}],"length":1,"name":"COM","type":"fixed_bitfield"}],"name":"COM","optional_bitfield_index":0,"optional_bitfield_name":"available","type":"optional_item"},{"data_fields":[{"items":[{"bit_length":1,"comment":"","name":"ANT","start_bit":7,"type":"fixed_bits"},{"bit_length":2,"comment":"","name":"CH-A/B","start_bit":5,"type":"fixed_bits"},{"bit_length":1,"comment":"Overload condition\n0 No overload\n1 Overload","name":"OVL","start_bit":4,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"MSC","start_bit":3,"type":"fixed_bits"}],"length":1,"name":"PSR","type":"fixed_bitfield"}],"name":"PSR","optional_bitfield_index":3,"optional_bitfield_name":"available","type":"optional_item"},{"data_fields":[{"items":[{"bit_length":1,"comment":"","name":"ANT","start_bit":7,"type":"fixed_bits"},{"bit_length":2,"comment":"","name":"CH-A/B","start_bit":5,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL","start_bit":4,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"MSC","start_bit":4,"type":"fixed_bits"}],"length":1,"name":"SSR","type":"fixed_bitfield"}],"name":"SSR","optional_bitfield_index":4,"optional_bitfield_name":"available","type":"optional_item"},{"data_fields":[{"items":[{"bit_length":1,"comment":"","name":"ANT","start_bit":15,"type":"fixed_bits"},{"bit_length":2,"comment":"","name":"CH-A/B","start_bit":13,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL SUR","start_bit":12,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"MSC","start_bit":11,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"SCF","start_bit":10,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"DLF","start_bit":9,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL SCF","start_bit":8,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"OVL DLF","start_bit":7,"type":"fixed_bits"}],"length":2,"name":"MDS","type":"fixed_bitfield"}],"name":"MDS","optional_bitfield_index":5,"optional_bitfield_name":"available","type":"optional_item"}],"name":"050","type":"compound"}],"name":"System Configuration and Status","number":"050","type":"item"},{"comment":"","data_fields":[{"field_specification":{"data_type":"bitfield","name":"available","reverse_bits":true,"type":"extendable_bits"},"items":[{"comment":"","data_fields":[{"items":[{"bit_length":3,"comment":"","name":"RED-RDP","start_bit":4,"type":"fixed_bits"},{"bit_length":3,"comment":"","name":"RED-XMT","start_bit":1,"type":"fixed_bits"}],"length":1,"name":"COM","type":"fixed_bitfield"}],"name":"COM","optional_bitfield_index":0,"optional_bitfield_name":"available","type":"optional_item"},{"comment":"","data_fields":[{"items":[{"bit_length":1,"comment":"","name":"POL","start_bit":7,"type":"fixed_bits"},{"bit_length":3,"comment":"","name":"RED-RAD","start_bit":4,"type":"fixed_bits"},{"bit_length":2,"comment":"","name":"STC","start_bit":2,"type":"fixed_bits"}],"length":1,"name":"PSR","type":"fixed_bitfield"}],"name":"PSR","optional_bitfield_index":3,"optional_bitfield_name":"available","type":"optional_item"},{"comment":"","data_fields":[{"items":[{"bit_length":3,"comment":"","name":"RED-RAD","start_bit":5,"type":"fixed_bits"}],"length":1,"name":"SSR","type":"fixed_bitfield"}],"name":"SSR","optional_bitfield_index":4,"optional_bitfield_name":"available","type":"optional_item"},{"comment":"","data_fields":[{"items":[{"bit_length":3,"comment":"","name":"RED-RAD","start_bit":5,"type":"fixed_bits"},{"bit_length":1,"comment":"","name":"CLU","start_bit":4,"type":"fixed_bits"}],"length":1,"name":"MDS","type":"fixed_bitfield"}],"name":"MDS","optional_bitfield_index":5,"optional_bitfield_name":"available","type":"optional_item"}],"name":"060","type":"compound"}],"name":"System Processing Mode","number":"060","type":"item"},{"comment":"","data_fields":[{"items":[{"items":[{"bit_length":5,"comment":"","name":"TYP","start_bit":11,"type":"fixed_bits"},{"bit_length":11,"comment":"","name":"COUNTER","start_bit":0,"type":"fixed_bits"}],"length":2,"name":"plot_count_values","type":"fixed_bitfield"}],"name":"plot_count_values","repetition_item":{"data_type":"uint","length":1,"name":"REP","type":"fixed_bytes"},"type":"repetitive"}],"name":"Message Count Values","number":"070","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"int","length":1,"lsb":0.0078125,"name":"RANGE ERROR","type":"fixed_bytes"},{"comment":"","data_type":"int","length":1,"lsb":0.02197265625,"name":"AZIMUTH ERROR","type":"fixed_bytes"}],"name":"Collimation Error","number":"090","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":2,"lsb":0.00390625,"name":"RHO-START","type":"fixed_bytes"},{"comment":"","data_type":"uint","length":2,"lsb":0.00390625,"name":"RHO-END","type":"fixed_bytes"},{"comment":"","data_type":"uint","length":2,"lsb":0.00549316406,"name":"THETA-START","type":"fixed_bytes"},{"comment":"","data_type":"uint","length":2,"lsb":0.00549316406,"name":"THETA-END","type":"fixed_bytes"}],"name":"Generic Polar Window","number":"100","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"uint","length":1,"name":"TYP","type":"fixed_bytes"}],"name":"Data Filter","number":"110","type":"item"},{"comment":"","data_fields":[{"comment":"","data_type":"int","length":2,"lsb":1.0,"name":"Height of Data Source","type":"fixed_bytes"},{"comment":"","data_type":"int","length":3,"lsb":2.145767e-05,"name":"Latitude","type":"fixed_bytes"},{"comment":"","data_type":"int","length":3,"lsb":2.145767e-05,"name":"Longitude","type":"fixed_bytes"}],"name":"3D-Position Of Data Source","number":"120","type":"item"}],"name":"cat034_1.26_record","type":"record","uap":["010","000","030","020","041","050","060","FX","070","100","110","120","090","RE","SP","FX"]})";

    public:
        static void get(json &cat_definition)
        {
            CatDefinitionBase::get(cat_definition, cat34_str);
        }

    private:
        inline static std::string cat34_str = R"({
    "name":"cat034_1.26_record",
    "type":"record",
    "field_specification":{
        "name":"FSPEC",
        "type":"extendable_bits",
        "reverse_bits":true,
        "data_type":"bitfield"
    },
    "uap":[
        "010",
        "000",
        "030",
        "020",
        "041",
        "050",
        "060",
        "FX",
        "070",
        "100",
        "110",
        "120",
        "090",
        "RE",
        "SP",
        "FX"
    ],
    "items":[
        {
            "number":"000",
            "name":"Message Type",
            "comment":"This Data Item allows for a more convenient handling of the messages at the receiver side by further defining the type of transaction.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Message Type",
                    "comment":"1 North Marker message\n2 Sector crossing message\n3 Geographical filtering message\n4 Jamming Strobe message",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                }
            ]
        },
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
            "name":"Sector Number",
            "comment":"Eight most significant bits of the antenna azimuth defining a particular azimuth sector.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Sector Number",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint",
                    "lsb":1.40625
                }
            ]
        },
        {
            "number":"030",
            "name":"Time of Day",
            "comment":"Absolute time stamping expressed as UTC time.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time of Day",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"041",
            "name":"Antenna Rotation Speed",
            "comment":"Antenna rotation period as measured between two consecutive North crossings or as averaged during a period of time.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Antenna Rotation Speed",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"050",
            "name":"System Configuration and Status",
            "comment":"Information concerning the configuration and status of a System.",
            "type":"item",
            "data_fields":[
                {
                    "name":"050",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits", 
                        "data_type":"bitfield",
                        "reverse_bits":true                       
                    },
                    "items":[
                        {
                            "name":"COM",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"COM",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"NOGO",
                                            "comment":"Operational Release Status of the System\n0 System is released for operational use\n1 Operational use of System is inhibited, i.e. the data shall be discarded by an operational SDPS",
                                            "type":"fixed_bits",
                                            "start_bit":7,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"RDPC",
                                            "comment":"Radar Data Processor Chain Selection Status\n0 RDPC-1 selected\n1 RDPC-2 selected",
                                            "type":"fixed_bits",
                                            "start_bit":6,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"RDPR",
                                            "comment":"Event to signal a reset/restart of the selected Radar Data Processor Chain, i.e. expect a new assignment of track numbers\n0 Default situation\n1 Reset of RDPC",
                                            "type":"fixed_bits",
                                            "start_bit":5,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"OVL RDP",
                                            "comment":"Radar Data Processor Overload Indicator\n0 Default, no overload\n1 Overload in RDP",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"OVL XMT",
                                            "comment":"Transmission Subsystem Overload Status\n0 Default, no overload\n1 Overload in transmission subsystem",
                                            "type":"fixed_bits",
                                            "start_bit":3,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"MSC",
                                            "comment":"Monitoring System Connected Status\n0 Monitoring system connected\n1 Monitoring system disconnected",
                                            "type":"fixed_bits",
                                            "start_bit":2,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"TSV",
                                            "comment":"Time Source Validity\n0 valid\n1 invalid",
                                            "type":"fixed_bits",
                                            "start_bit":1,
                                            "bit_length":1
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"PSR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"PSR",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"ANT",
                                            "comment":"Selected antenna\n0 antenna 1\n1 antenna 2",
                                            "type":"fixed_bits",
                                            "start_bit":7,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"CH-A/B",
                                            "comment":"Channel A/B selection status\n0 No channel selected\n1 Channel A only selected\n2 Channel B only selected\n3 Diversity mode;Channel A and B selected",
                                            "type":"fixed_bits",
                                            "start_bit":5,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"OVL",
                                            "comment":"Overload condition\n0 No overload\n1 Overload",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"MSC",
                                            "comment":"Monitoring System Connected Status:\n0 Monitoring system connected\n1 Monitoring system disconnected",
                                            "type":"fixed_bits",
                                            "start_bit":3,
                                            "bit_length":1
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"SSR",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"SSR",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"ANT",
                                            "comment":"Selected antenna\n0 antenna 1\n1 antenna 2",
                                            "type":"fixed_bits",
                                            "start_bit":7,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"CH-A/B",
                                            "comment":"Channel A/B selection status\n0 No channel selected\n1 Channel A only selected\n2 Channel B only selected\n3 Diversity mode;Channel A and B selected",
                                            "type":"fixed_bits",
                                            "start_bit":5,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"OVL",
                                            "comment":"Overload condition\n0 No overload\n1 Overload",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"MSC",
                                            "comment":"Monitoring System Connected Status:\n0 Monitoring system connected\n1 Monitoring system disconnected",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":1
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"MDS",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"MDS",
                                    "type":"fixed_bitfield",
                                    "length":2,
                                    "items":[
                                        {
                                            "name":"ANT",
                                            "comment":"Selected antenna\n0 antenna 1\n1 antenna 2",
                                            "type":"fixed_bits",
                                            "start_bit":15,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"CH-A/B",
                                            "comment":"Channel A/B selection status for surveillance\n0 No channel selected\n1 Channel A only selected\n2 Channel B only selected\n3 Illegal combination",
                                            "type":"fixed_bits",
                                            "start_bit":13,
                                            "bit_length":2
                                        },
                                        {
                                            "name":"OVL SUR",
                                            "comment":"Overload condition\n0 No overload\n1 Overload",
                                            "type":"fixed_bits",
                                            "start_bit":12,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"MSC",
                                            "comment":"Monitoring System Connected Status:\n0 Monitoring system connected\n1 Monitoring system disconnected",
                                            "type":"fixed_bits",
                                            "start_bit":11,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"SCF",
                                            "comment":"Channel A/B selection status for Surveillance Co-ordination Function\n0 Channel A in use\n1 Channel B in use",
                                            "type":"fixed_bits",
                                            "start_bit":10,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"DLF",
                                            "comment":"Channel A/B selection status for Data Link Function\n0 Channel A in use\n1 Channel B in use",
                                            "type":"fixed_bits",
                                            "start_bit":9,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"OVL SCF",
                                            "comment":"Overload in Surveillance Co-ordination Function\n0 No overload\n1 Overload",
                                            "type":"fixed_bits",
                                            "start_bit":8,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"OVL DLF",
                                            "comment":"Overload in Data Link Function\n0 No overload\n1 Overload",
                                            "type":"fixed_bits",
                                            "start_bit":7,
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
            "number":"060",
            "name":"System Processing Mode",
            "comment":"Status concerning the processing options, in use during the last antenna revolution, for the various Sensors, composing the System.",
            "type":"item",
            "data_fields":[
                {
                    "name":"060",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true  
                    },
                    "items":[
                        {
                            "name":"COM",
                            "comment":"The first Secondary Subfield (COM) defines the processing modes of the common elements of a System.",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"COM",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"RED-RDP",
                                            "comment":"Reduction Steps in use for an overload of the RDP\n0 No reduction active\n1 Reduction step 1 active\n2 Reduction step 2 active\n3 Reduction step 3 active\n4 Reduction step 4 active\n5 Reduction step 5 active\n6 Reduction step 6 active\n7 Reduction step 7 active",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":3
                                        },
                                        {
                                            "name":"RED-XMT",
                                            "comment":"Reduction Steps in use for an overload of the Transmission subsystemn0 No reduction active\n1 Reduction step 1 active\n2 Reduction step 2 active\n3 Reduction step 3 active\n4 Reduction step 4 active\n5 Reduction step 5 active\n6 Reduction step 6 active\n7 Reduction step 7 active",
                                            "type":"fixed_bits",
                                            "start_bit":1,
                                            "bit_length":3
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"PSR",
                            "comment":"Specific Processing Mode information for a PSR sensor",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"PSR",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"POL",
                                            "comment":"Polarization in use by PSR\n0 Linear polarization\n1 Circular polarization",
                                            "type":"fixed_bits",
                                            "start_bit":7,
                                            "bit_length":1
                                        },
                                        {
                                            "name":"RED-RAD",
                                            "comment":"Reduction Steps in use as result of an overload within the PSR subsystem\n0 No reduction active\n1 Reduction step 1 active\n2 Reduction step 2 active\n3 Reduction step 3 active\n4 Reduction step 4 active\n5 Reduction step 5 active\n6 Reduction step 6 active\n7 Reduction step 7 active",
                                            "type":"fixed_bits",
                                            "start_bit":4,
                                            "bit_length":3
                                        },
                                        {
                                            "name":"STC",
                                            "comment":"Sensitivity Time Control Map in use\n0 STC Map-1\n1 STC Map-2\n2 STC Map-3\n3 STC Map-4",
                                            "type":"fixed_bits",
                                            "start_bit":2,
                                            "bit_length":2
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"SSR",
                            "comment":"Specific Processing Mode information for a SSR sensor",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"SSR",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"RED-RAD",
                                            "comment":"Reduction Steps in use as result of an overload within the SSR subsystem\n0 No reduction active\n1 Reduction step 1 active\n2 Reduction step 2 active\n3 Reduction step 3 active\n4 Reduction step 4 active\n5 Reduction step 5 active\n6 Reduction step 6 active\n7 Reduction step 7 active",
                                            "type":"fixed_bits",
                                            "start_bit":5,
                                            "bit_length":3
                                        }
                                    ]
                                }
                            ]
                        },
                        {
                            "name":"MDS",
                            "comment":"Specific Processing Mode information for a Mode S Sensor",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"MDS",
                                    "type":"fixed_bitfield",
                                    "length":1,
                                    "items":[
                                        {
                                            "name":"RED-RAD",
                                            "comment":"Reduction Steps in use as result of an overload within the Mode S subsystem\n0 No reduction active\n1 Reduction step 1 active\n2 Reduction step 2 active\n3 Reduction step 3 active\n4 Reduction step 4 active\n5 Reduction step 5 active\n6 Reduction step 6 active\n7 Reduction step 7 active",
                                            "type":"fixed_bits",
                                            "start_bit":5,
                                            "bit_length":3
                                        },
                                        {
                                            "name":"CLU",
                                            "comment":"Cluster State\n0 Autonomous\n1 Not autonomous",
                                            "type":"fixed_bits",
                                            "start_bit":4,
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
            "number":"070",
            "name":"Message Count Values",
            "comment":"Message Count values, according the various types of messages, for the last completed antenna revolution, counted between two North crossings",
            "type":"item",
            "data_fields":[
                {
                    "name":"plot_count_values",
                    "type":"repetitive",
                    "repetition_item":{
                        "name":"REP",
                        "type":"fixed_bytes",
                        "length":1,
                        "data_type":"uint"
                    },
                    "items":[
                        {
                            "name":"plot_count_values",
                            "type":"fixed_bitfield",
                            "length":2,
                            "items":[
                                {
                                    "name":"TYP",
                                    "comment":"Type of message counter, encoded as follows\n0 No detection (number of misses)\n1 Single PSR target reports\n2 Single SSR target reports (Non-Mode S)\n3 SSR+PSR target reports (Non-Mode S)\n4 Single All-Call target reports (Mode S)\n5 Single Roll-Call target reports (Mode S)\n6 All-Call + PSR (Mode S) target reports\n7 Roll-Call + PSR (Mode S) target reports\n8 Filter for Weather data\n9 Filter for Jamming Strobe\n10 Filter for PSR data\n11 Filter for SSR/Mode S data\n12 Filter for SSR/Mode S+PSR data\n13 Filter for Enhanced Surveillance data\n14 Filter for PSR+Enhanced Surveillance\n15 Filter for PSR+Enhanced Surveillance + SSR/Mode S data not in Area of Prime Interest\n16 Filter for PSR+Enhanced Surveillance + all SSR/Mode S data",
                                    "type":"fixed_bits",
                                    "start_bit":11,
                                    "bit_length":5
                                },
                                {
                                    "name":"COUNTER",
                                    "comment":"11-bit counter value",
                                    "type":"fixed_bits",
                                    "start_bit":0,
                                    "bit_length":11
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"090",
            "name":"Collimation Error",
            "comment":"Averaged difference in range and in azimuth for the primary target position with respect to the SSR target position as calculated by the radar station.",
            "type":"item",
            "data_fields":[
                {
                    "name":"RANGE ERROR",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"int",
                    "lsb":0.0078125
                },
                {
                    "name":"AZIMUTH ERROR",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"int",
                    "lsb":0.02197265625
                }
            ]
        },
        {
            "number":"100",
            "name":"Generic Polar Window",
            "comment":"Geographical window defined in polar co-ordinates.",
            "type":"item",
            "data_fields":[
                {
                    "name":"RHO-START",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint",
                    "lsb":0.00390625
                },
                {
                    "name":"RHO-END",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint",
                    "lsb":0.00390625
                },
                {
                    "name":"THETA-START",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint",
                    "lsb":0.00549316406
                },
                {
                    "name":"THETA-END",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint",
                    "lsb":0.00549316406
                }
            ]
        },
        {
            "number":"110",
            "name":"Data Filter",
            "comment":"Data Filter, which allows suppression of individual data types.",
            "type":"item",
            "data_fields":[
                {
                    "name":"TYP",
                    "comment":"0 invalid value\n1 Filter for Weather data\n2 Filter for Jamming Strobe\n3 Filter for PSR data\n4 Filter for SSR/Mode S data\n5 Filter for SSR/Mode S + PSR data\n6 Enhanced Surveillance data\n7 Filter for PSR+Enhanced Surveillance data\n8 Filter for PSR+Enhanced Surveillance + SSR/Mode S data not in Area of Prime Interest\n9 Filter for PSR+Enhanced Surveillance + all SSR/Mode S data",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"120",
            "name":"3D-Position Of Data Source",
            "comment":"3D-Position of Data Source in WGS 84 Co-ordinates.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Height of Data Source",
                    "comment":"Signed Height of the Data Source, expressed in meters above WGS 84 reference ellipsoid.",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":1.0
                },
                {
                    "name":"Latitude",
                    "comment":"Latitude in WGS 84 expressed in two’s complement\nRange: -90<= latitude<= 90degrees",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"int",
                    "lsb":0.00002145767
                },
                {
                    "name":"Longitude",
                    "comment":"Longitude in WGS 84 expressed in two’s complement\nRange: -180 < = longitude<180 degrees",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"int",
                    "lsb":0.00002145767
                }
            ]
        }
    ]
}
)";

    }; // end of class
};     // end of namespace
