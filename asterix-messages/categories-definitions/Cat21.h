#pragma once
#include "CatDefinitionBase.h"
#include <fstream>
#include <iostream>
namespace AsterixMessageCategories
{
  class Cat21 : public CatDefinitionBase
  {
  public:
    static void get(json &cat_definition)
    {
      CatDefinitionBase::get(cat_definition, cat21_str);
    }

  private:
    inline static std::string cat21_str = R"({
    "name":"cat021_2.4_record",
    "type":"record",
    "field_specification":{
        "name":"FSPEC",
        "type":"extendable_bits",
        "reverse_bits":true,
        "data_type":"bitfield"
    },
    "uap":[
        "010",
        "040",
        "161",
        "015",
        "071",
        "130",
        "131",
        "FX",
        "072",
        "150",
        "151",
        "080",
        "073",
        "074",
        "075",
        "FX",
        "076",
        "140",
        "090",
        "210",
        "070",
        "230",
        "145",
        "FX",
        "152",
        "200",
        "155",
        "157",
        "160",
        "165",
        "077",
        "FX",
        "170",
        "020",
        "220",
        "146",
        "148",
        "110",
        "016",
        "FX",
        "008",
        "271",
        "132",
        "250",
        "260",
        "400",
        "295",
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
            "number":"008",
            "name":"Aircraft Operational Status",
            "comment":"Identification of the operational services available in the aircraft while airborne.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Aircraft Operational Status",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"RA",
                            "comment":"TCAS Resolution Advisory active\n0 TCAS II or ACAS RA not active\n1 TCAS RA active",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"TC",
                            "comment":"Target Trajectory Change Report Capability\n0 no capability for Trajectory Change Reports\n1 support for TC+0 reports only\n2 support for multiple TC reports\n3 reserved",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":2
                        },
                        {
                            "name":"TS",
                            "comment":"Target State Report Capability\n0 no capability to support Target State Reports\n1 capable of supporting target State Reports",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"ARV",
                            "comment":"Air-Referenced Velocity Report Capability\n0 no capability to generate ARV-reports\n1 capable of generate ARV-reports",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"CDTI/A",
                            "comment":"Cockpit Display of Traffic Information airborne\n0 CDTI not operational\n1 CDTI operational",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"Not TCAS",
                            "comment":"TCAS System Status\n0 TCAS operational\n1 TCAS not operational",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":1
                        },
                        {
                            "name":"SA",
                            "comment":"Single Antenna\n0 Antenna Diversity\n1 Single Antenna only",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                }
            ]
        },
        {
            "number":"010",
            "name":"Data Source Identification",
            "comment":"Identification of the ADS-B station providing information.",
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
            "number":"016",
            "name":"Service Management",
            "comment":"Identification of services offered by a ground station (identified by a SIC code).",
            "type":"item",
            "data_fields":[
                {
                    "name":"RP",
                    "comment":"Report Period",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint",
                    "lsb":0.5
                }
            ]
        },
        {
            "number":"020",
            "name":"Emitter Category",
            "comment":"Characteristics of the originating ADS-B unit.",
            "type":"item",
            "data_fields":[
                {
                    "name":"ECAT",
                    "comment":"0 No ADS-B Emitter Category Information\n1 light aircraft <= 15500 lbs\n2 15500 lbs < small aircraft <75000 lbs\n3 75000 lbs < medium a/c < 300000 lbs\n4 High Vortex Large\n5 300000 lbs <= heavy aircraft\n6 highly manoeuvrable (5g acceleration capability) and high speed (>400 knots cruise)\n7 to 9 reserved\n10 rotocraft\n11 glider / sailplane\n12 lighter-than-air\n13 unmanned aerial vehicle\n14 space / transatmospheric vehicle\n15 ultralight / handglider / paraglider\n16 parachutist / skydiver\n17 to 19 reserved\n20 surface emergency vehicle\n21 surface service vehicle\n22 fixed ground or tethered obstruction\n23 cluster obstacle\n24 line obstacle",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"040",
            "name":"Target Report Descriptor",
            "comment":"Type and characteristics of the data as transmitted by a system.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Target Report Descriptor",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"ATP",
                            "comment":"Address Type\n0 24-Bit ICAO address\n1 Duplicate address\n2 Surface vehicle address\n3 Anonymous address\n4-7 Reserved for future use",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":3
                        },
                        {
                            "name":"ARC",
                            "comment":"Altitude Reporting Capability\n0 25 ft\n1 100 ft\n2 Unknown\n3 Invalid",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":2
                        },
                        {
                            "name":"RC",
                            "comment":"Range Check\n0 Default\n1 Range Check passed,CPR Validation pending",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"RAB",
                            "comment":"Report Type\n0 Report from target transponder\n1 Report from field monitor[fixed transponder]",
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
                    "name":"Target Report Descriptor First Extension",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"DCR",
                            "comment":"Differential Correction\n0 No differential correction (ADS-B)\n1 Differential correction [ADS-B]",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"GBS",
                            "comment":"Ground Bit Setting\n0 Ground Bit not set\n1 Ground Bit set",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"SIM",
                            "comment":"Simulated Target\n0 Actual target report\n1 Simulated target report",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"TST",
                            "comment":"Test Target\n0 Default\n1 Test Target",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"SAA",
                            "comment":"Selected Altitude Available\n0 Equipment capable to provide Selected\n1 Altitude Equipment not capable to provide Selected Altitude",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"CL",
                            "comment":"Confidence Level\n0 Report valid\n1 Report suspect\n2 No information\n3 Reserved for future use",
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
                },
                {
                    "name":"Target Report Descriptor Second Extension : Error Conditions",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX2",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"LLC",
                            "comment":"List Lookup Check\n0 default\n1 List Lookup failed",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },                    
                        {
                            "name":"IPC",
                            "comment":"Independent Position Check\n0 default\n1 Independent Position Check failed",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"NOGO",
                            "comment":"No-go Bit Status\n0 NOGO-bit not set\n1 NOGO-bit set",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"CPR",
                            "comment":"Compact Position Reporting\n0 CPR Validation correct\n1 CPR Validation failed",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"LDPJ",
                            "comment":"Local Decoding Position Jump\n0 LDPJ not detected\n1 LDPJ detected",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"RCF",
                            "comment":"Range Check\n0 default\n1 Range Check failed",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":1
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
            "number":"070",
            "name":"Mode 3/A Code in Octal Representation",
            "comment":"Mode-3/A code converted into octal representation.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Mode 3/A Code in Octal Representation",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"Mode-3/A",
                            "comment":"Mode-3/A reply in octal representation",
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
            "number":"071",
            "name":"Time of Applicability for Position",
            "comment":"Time of applicability of the reported position, in the form of elapsed time since last midnight, expressed as UTC.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time of Applicability for Position",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"072",
            "name":"Time of Applicability for Velocity",
            "comment":"Time of applicability (measurement) of the reported velocity, in the form of elapsed time since last midnight, expressed as UTC.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time of Applicability for Velocity",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"073",
            "name":"Time of Message Reception for Position",
            "comment":"Time of reception of the latest position squitter in the Ground Station, in the form of elapsed time since last midnight, expressed as UTC.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time of Message Reception for Position",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"074",
            "name":"Time of Message Reception of Position-High Precision",
            "comment":"Time at which the latest ADS-B position information was received by the ground station, expressed as fraction of the second of the UTC Time.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time of Message Reception of Position-High Precision",
                    "type":"fixed_bitfield",
                    "length":4,
                    "items":[
                        {
                            "name":"FSI",
                            "comment":"Full Second Indication\n3 Reserved\n2 TOMRp whole seconds = (I021/073) Whole seconds – 1\n1 TOMRp whole seconds = (I021/073) Whole seconds + 1\n0 TOMRp whole seconds = (I021/073) Whole seconds",
                            "type":"fixed_bits",
                            "start_bit":30,
                            "bit_length":2
                        },
                        {
                            "name":"Time of Message Reception of Position - high precision",
                            "comment":"Fractional part of the time of message reception for position in the ground station.",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":30,
                            "lsb":9.31322574615478515625E-10
                        }
                    ]
                }
            ]
        },
        {
            "number":"075",
            "name":"Time of Message Reception for Velocity",
            "comment":"Time of reception of the latest velocity squitter in the Ground Station, in the form of elapsed time since last midnight, expressed as UTC.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time of Message Reception of Velocity",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint",
                    "lsb":0.0078125
                }
            ]
        },
        {
            "number":"076",
            "name":"Time of Message Reception of Velocity-High Precision",
            "comment":"Time at which the latest ADS-B velocity information was received by the ground station, expressed as fraction of the second of the UTC Time.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time of Message Reception of Velocity-High Precision",
                    "type":"fixed_bitfield",
                    "length":4,
                    "items":[
                        {
                            "name":"FSI",
                            "comment":"Full Second Indication\n3 Reserved\n2 TOMRv whole seconds = (I021/075) Whole seconds – 1\n1 TOMRv whole seconds = (I021/075) Whole seconds + 1\n0 TOMRv whole seconds = (I021/075) Whole seconds",
                            "type":"fixed_bits",
                            "start_bit":30,
                            "bit_length":2
                        },
                        {
                            "name":"Time of Message Reception of Velocity - high precision",
                            "comment":"Fractional part of the time of message reception for velocity in the ground station.",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":30,
                            "lsb":9.31322574615478515625E-10
                        }
                    ]
                }
            ]
        },
        {
            "number":"077",
            "name":"Time of ASTERIX Report Transmission",
            "comment":"Time of the transmission of the ASTERIX category 021 report in the form of elapsed time since last midnight, expressed as UTC.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Time Of ASTERIX Report Transmission",
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
            "name":"Target Address",
            "comment":"Target address (emitter identifier) assigned uniquely to each target.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Target Address",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"uint"
                }
            ]
        },
        {
            "number":"090",
            "name":"Quality Indicators",
            "comment":"ADS-B quality indicators transmitted by a/c according to MOPS version.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Quality Indicators",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"NUCr or NACv",
                            "comment":"\"Navigation Uncertainty Category for velocity\" NUCr or the \"Navigation Accuracy Category for Velocity\" NACv",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":3
                        },
                        {
                            "name":"NUCp or NIC",
                            "comment":"\"Navigation Uncertainty Category for Position\" NUCp or \"Navigation Integrity Category \"NIC\"",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":4
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
                    "name":"Quality Indicators First Extension : Navigation Accuracy Category for Position",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"NICbaro",
                            "comment":"Navigation Integrity Category for Barometric Altitude",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"SIL",
                            "comment":"Surveillance (version 1) or Source (version 2) Integrity Level",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":2
                        },
                        {
                            "name":"NACp",
                            "comment":"Navigation Accuracy Category for Position",
                            "type":"fixed_bits",
                            "start_bit":1,
                            "bit_length":4
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
                    "name":"Quality Indicators Second Extension : Position Quality Indicators",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX2",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"SIL-Supplement",
                            "comment":"SIL-Supplement\n0 measured per flight-hour\n1 measured per sample",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"SDA",
                            "comment":"Horizontal Position System Design Assurance Level [as defined in version 2]",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":2
                        },
                        {
                            "name":"GVA",
                            "comment":"Geometric Altitude Accuracy",
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
                    "name":"Quality Indicators Third Extension : Position Quality Indicators",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX3",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"PIC",
                            "comment":"Position Integrity Category",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":4
                        },
                        {
                            "name":"FX4",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":1
                        }
                    ]
                }
            ]
        },
        {
            "number":"110",
            "name":"Trajectory Intent",
            "comment":"",
            "type":"item",
            "data_fields":[
                {
                    "name":"Trajectory Intent",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"TIS",
                            "comment":"",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
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
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"rep",
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
                                            "comment":"Altitude in two’s complement form\n-1500 ft <= altitude <= 150000 ft",
                                            "type":"fixed_bytes",
                                            "length":2,
                                            "data_type":"int",
                                            "lsb":10.0
                                        },
                                        {
                                            "name":"Latitude",
                                            "comment":"In WGS.84 in two’s complement.\n-90 <= latitude <= 90 deg.",
                                            "type":"fixed_bytes",
                                            "length":3,
                                            "data_type":"int",
                                            "lsb":2.1457672119140625E-5
                                        },
                                        {
                                            "name":"Longitude",
                                            "comment":"In WGS.84 in two’s complement.\n-180 <= longitude < 180",
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
                                                    "comment":"0 Unknown\n1 Fly by waypoint (LT)\n2 Fly over waypoint (LT)\n3 Hold pattern (LT)\n4 Procedure hold (LT)\n5 Procedure turn (LT)\n6 RF leg (LT)\n7 Top of climb (VT)\n8 Top of descent (VT)\n9 Start of level (VT)\n10 Cross-over altitude (VT)\n11 Transition altitude [VT]",
                                                    "type":"fixed_bits",
                                                    "start_bit":4,
                                                    "bit_length":4
                                                },
                                                {
                                                    "name":"TD",
                                                    "comment":"0 N/A\n1 Turn right\n2 Turn left\n3 No turn",
                                                    "type":"fixed_bits",
                                                    "start_bit":2,
                                                    "bit_length":2
                                                },
                                                {
                                                    "name":"TRA",
                                                    "comment":"Turn Radius Availabilty\n0 TTR not available\n1 TTR available",
                                                    "type":"fixed_bits",
                                                    "start_bit":1,
                                                    "bit_length":1
                                                },
                                                {
                                                    "name":"TOA",
                                                    "comment":"0 TOV available\n1 TOV not available",
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
                        }
                    ]
                }
            ]
        },
        {
            "number":"130",
            "name":"Position in WGS-84 Co-ordinates",
            "comment":"Position in WGS-84 Co-ordinates.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Latitude",
                    "comment":"In WGS.84 in two’s complement.\nRange -90 <= latitude <= 90 deg.",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"int",
                    "lsb":2.1457672119140625e-5
                },
                {
                    "name":"Longitude",
                    "comment":"In WGS.84 in two’s complement.\nRange -180 <= longitude < 180 deg.",
                    "type":"fixed_bytes",
                    "length":3,
                    "data_type":"int",
                    "lsb":2.1457672119140625e-5
                }
            ]
        },
        {
            "number":"131",
            "name":"High-Resolution Position in WGS-84 Co-ordinates",
            "comment":"Position in WGS-84 Co-ordinates in high resolution.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Latitude",
                    "comment":"In WGS.84 in two’s complement.\nRange -90 <= latitude <= 90 deg.",
                    "type":"fixed_bytes",
                    "length":4,
                    "data_type":"int",
                    "lsb":1.676380634307861328125E-7
                },
                {
                    "name":"Longitude",
                    "comment":"In WGS.84 in two’s complement.\nRange -180 <= longitude < 180 deg.",
                    "type":"fixed_bytes",
                    "length":4,
                    "data_type":"int",
                    "lsb":1.676380634307861328125E-7
                }
            ]
        },
        {
            "number":"132",
            "name":"Message Amplitude",
            "comment":"Amplitude, in dBm, of ADS-B messages received by the ground station, coded in two’s complement.",
            "type":"item",
            "data_fields":[
                {
                    "name":"MAM",
                    "comment":"Message Amplitude",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"int",
                    "lsb":1.0
                }
            ]
        },
        {
            "number":"140",
            "name":"Geometric Height",
            "comment":"Minimum height from a plane tangent to the earth’s ellipsoid, defined by WGS-84, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Geometric Height",
                    "comment":"-1500 ft <= Geometric Height <= 150000 ft",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":6.25
                }
            ]
        },
        {
            "number":"145",
            "name":"Flight Level",
            "comment":"Flight Level from barometric measurements, not QNH corrected, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Flight Level",
                    "comment":"-15 FL <= Flight Level <= 1500 FL",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.25
                }
            ]
        },
        {
            "number":"146",
            "name":"Selected Altitude",
            "comment":"The Selected Altitude as provided by the avionics and corresponding either to the MCP/FCU Selected Altitude (the ATC cleared altitude entered by the flight crew into the avionics) or to the FMS Selected Altitude.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Selected Altitude",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"SAS",
                            "comment":"Source Availability\n0 No source information provided\n1 Source Information provided",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"Source",
                            "comment":"0 Unknown\n1 Aircraft Altitude (Holding Altitude)\n2 MCP/FCU Selected Altitude\n3 FMS Selected Altitude",
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
                            "data_type":"int",
                            "lsb":25.0
                        }
                    ]
                }
            ]
        },
        {
            "number":"148",
            "name":"Final State Selected Altitude",
            "comment":"The vertical intent value that corresponds with the ATC cleared altitude, as derived from the Altitude Control Panel (MCP/FCU).",
            "type":"item",
            "data_fields":[
                {
                    "name":"Final State Selected Altitude",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"MV",
                            "comment":"Manage Vertical Mode\n0 Not active or unknown\n1 Active",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"AH",
                            "comment":"Altitude Hold Mode\n0 Not active or unknown\n1 Active",
                            "type":"fixed_bits",
                            "start_bit":14,
                            "bit_length":1
                        },
                        {
                            "name":"AM",
                            "comment":"Approach Mode\n0 Not active or unknown\n1 Active",
                            "type":"fixed_bits",
                            "start_bit":13,
                            "bit_length":1
                        },
                        {
                            "name":"Altitude",
                            "comment":"Altitude in in two’s complement form\n-1300ft <= Altitude <= 100000ft",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":13,
                            "data_type":"int",
                            "lsb":25.0
                        }
                    ]
                }
            ]
        },
        {
            "number":"150",
            "name":"Air Speed",
            "comment":"Calculated Air Speed (Element of Air Vector).",
            "type":"item",
            "data_fields":[
                {
                    "name":"Air Speed",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"IM",
                            "comment":"0 Air Speed = IAS\n1 Air Speed = Mach",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"Air Speed",
                            "comment":"Air Speed (IAS or Mach)\nif IAS, LSB = 2^-14 NM/s\nif Mach, LSB = 0.001",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":15
                        }
                    ]
                }
            ]
        },
        {
            "number":"151",
            "name":"True Airspeed",
            "comment":"",
            "type":"item",
            "data_fields":[
                {
                    "name":"True Airspeed",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"RE",
                            "comment":"\"Range Exceeded\" Indicator\n0 Value in defined range\n1 Value exceeds defined range",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"True Air Speed",
                            "comment":"",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":15,
                            "lsb":1.0
                        }
                    ]
                }
            ]
        },
        {
            "number":"152",
            "name":"Magnetic Heading",
            "comment":"Magnetic Heading (Element of Air Vector).",
            "type":"item",
            "data_fields":[
                {
                    "name":"Magnetic Heading",
                    "comment":"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.0054931640625
                }
            ]
        },
        {
            "number":"155",
            "name":"Barometric Vertical Rate",
            "comment":"Barometric Vertical Rate, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Barometric Vertical Rate",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"RE",
                            "comment":"\"Range Exceeded\" Indicator\n0 Value in defined range\n1 Value exceeds defined range",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"Barometric Vertical Rate",
                            "comment":"",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":15,
                            "data_type":"int",
                            "lsb":6.25
                        }
                    ]
                }
            ]
        },
        {
            "number":"157",
            "name":"Geometric Vertical Rate",
            "comment":"Geometric Vertical Rate, in two’s complement form, with reference to WGS-84.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Geometric Vertical Rate",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"RE",
                            "comment":"\"Range Exceeded\" Indicator\n0 Value in defined range\n1 Value exceeds defined range",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"Geometric Vertical Rate",
                            "comment":"",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":15,
                            "data_type":"int",
                            "lsb":6.25
                        }
                    ]
                }
            ]
        },
        {
            "number":"160",
            "name":"Airborne Ground Vector",
            "comment":"Ground Speed and Track Angle elements of Airborne Ground Vector.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Ground Speed",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"RE",
                            "comment":"\"Range Exceeded\" Indicator\n0 Value in defined range\n1 Value exceeds defined range",
                            "type":"fixed_bits",
                            "start_bit":15,
                            "bit_length":1
                        },
                        {
                            "name":"Ground Speed",
                            "comment":"Ground Speed referenced to WGS-84\n0 ≤ Ground Speed < 2 NM/s",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":15,
                            "lsb":6.103515625E-5
                        }
                    ]
                },
                {
                    "name":"Track Angle",
                    "comment":"Track Angle clockwise reference to \"True North\"",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"uint",
                    "lsb":0.0054931640625
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
                    "name":"Track Number",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"Track Number",
                            "comment":"TRACK NUMBER[0...4095]",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":12,
                            "data_type":"uint"
                        }
                    ]
                }
            ]
        },
        {
            "number":"165",
            "name":"Track Angle Rate",
            "comment":"Rate of Turn, in two’s complement form.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Track Angle Rate",
                    "type":"fixed_bitfield",
                    "length":2,
                    "items":[
                        {
                            "name":"TAR",
                            "comment":"Track Angle Rate\nMaximum value = 16 °/s",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":10,
                            "data_type":"int",
                            "lsb":0.03125
                        }
                    ]
                }
            ]
        },
        {
            "number":"170",
            "name":"Target Identification",
            "comment":"Target (aircraft or vehicle) identification in 8 characters, as reported by the target.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Target Identification",
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
            "number":"200",
            "name":"Target Status",
            "comment":"Status of the target",
            "type":"item",
            "data_fields":[
                {
                    "name":"Target Status",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"ICF",
                            "comment":"Intent Change Flag\n0 No intent change active\n1 Intent change flag raised",
                            "type":"fixed_bits",
                            "start_bit":7,
                            "bit_length":1
                        },
                        {
                            "name":"LNAV",
                            "comment":"LNAV Mode\n0 LNAV Mode engaged\n1 LNAV Mode not engaged",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"ME",
                            "comment":"0 No military emergency\n1 Military emergency",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"PS",
                            "comment":"Priority Status\n0 No emergency / not reported\n1 General emergency\n2 Lifeguard / medical emergency\n3 Minimum fuel\n4 No communications\n5 Unlawful interference\n6 \"Downed\" Aircraft",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":3
                        },
                        {
                            "name":"SS",
                            "comment":"Surveillance Status\n0 No condition reported\n1 Permanent Alert (Emergency condition)\n2 Temporary Alert (change in Mode 3/A Code other than emergency)\n3 SPI set",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":2
                        }
                    ]
                }
            ]
        },
        {
            "number":"210",
            "name":"MOPS Version",
            "comment":"Identification of the MOPS version used by a/c to supply ADS-B information.",
            "type":"item",
            "data_fields":[
                {
                    "name":"MOPS Version",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"VNS",
                            "comment":"Version Not Supported\n0 The MOPS Version is supported by the GS\n1 The MOPS Version is not supported by the GS",
                            "type":"fixed_bits",
                            "start_bit":6,
                            "bit_length":1
                        },
                        {
                            "name":"VN",
                            "comment":"Version Number\nThis sub-field shall contain a value describing the MOPS used by each aircraft.\nCurrently defined for 1090 ES (LTT=2):\n0 ED102/DO-260 [Ref. 8]\n1 DO-260A [Ref. 9]\n2 ED102A/DO-260B [Ref. 11]",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":3
                        },
                        {
                            "name":"LTT",
                            "comment":"Link Technology Type\n0 Other\n1 UAT\n2 1090 ES\n3 VDL 4\n4-7 Not assigned",
                            "type":"fixed_bits",
                            "start_bit":0,
                            "bit_length":3
                        }
                    ]
                }
            ]
        },
        {
            "number":"220",
            "name":"Met Information",
            "comment":"Meteorological information.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Met Information",
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
                                    "comment":"-100 °C <= Temperature <= 100 °C",
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
            "number":"230",
            "name":"Roll Angle",
            "comment":"The roll angle, in two’s complement form, of an aircraft executing a turn.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Roll Angle",
                    "comment":"-180 <= Roll Angle <= 180",
                    "type":"fixed_bytes",
                    "length":2,
                    "data_type":"int",
                    "lsb":0.01
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
        },
        {
            "number":"271",
            "name":"Surface Capabilities and Characteristics",
            "comment":"Operational capabilities of the aircraft while on the ground.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Surface Capabilities and Characteristics",
                    "type":"fixed_bitfield",
                    "length":1,
                    "items":[
                        {
                            "name":"POA",
                            "comment":"Position Offset Applied\n0 Position transmitted is not ADS-B position reference point\n1 Position transmitted is the ADS-B position reference point",
                            "type":"fixed_bits",
                            "start_bit":5,
                            "bit_length":1
                        },
                        {
                            "name":"CDTI/S",
                            "comment":"Cockpit Display of Traffic Information Surface\n0 CDTI not operational\n1 CDTI operational",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":1
                        },
                        {
                            "name":"B2 low",
                            "comment":"Class B2 transmit power less than 70 Watts\n0 >= 70 Watts\n1 < 70 Watts",
                            "type":"fixed_bits",
                            "start_bit":3,
                            "bit_length":1
                        },
                        {
                            "name":"RAS",
                            "comment":"Receiving ATC Services\n0 Aircraft not receiving ATC-services\n1 Aircraft receiving ATC services",
                            "type":"fixed_bits",
                            "start_bit":2,
                            "bit_length":1
                        },
                        {
                            "name":"IDENT",
                            "comment":"Setting of \"IDENT\"-switch\n0 IDENT switch not active\n1 IDENT switch active",
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
                    "name":"Surface Capabilities and Characteristics First Extension : Length / Width of Aircraft",
                    "type":"fixed_bitfield",
                    "length":1,
                    "optional":true,
                    "optional_variable_name":"FX",
                    "optional_variable_value":1,
                    "items":[
                        {
                            "name":"L+W",
                            "comment":"Length and width of the aircraft",
                            "type":"fixed_bits",
                            "start_bit":4,
                            "bit_length":4
                        }
                    ]
                }
            ]
        },
        {
            "number":"295",
            "name":"Data Ages",
            "comment":"Ages of the data provided.",
            "type":"item",
            "data_fields":[
                {
                    "name":"Data Ages",
                    "type":"compound",
                    "field_specification":{
                        "name":"available",
                        "type":"extendable_bits",
                        "data_type":"bitfield",
                        "reverse_bits":true
                    },
                    "items":[
                        {
                            "name":"Aircraft Operational Status",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":0,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the latest received information transmitted in item I021/008.",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Target Report Descriptor",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":1,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last update of the Target Report Descriptor, item I021/040",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Mode 3/A",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":2,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last update of the Mode 3/A Code, item I021/070",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Quality Indicators",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":3,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the latest information received to update the Quality Indicators, item I021/090",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Trajectory Intent",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":4,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the last update of the Trajectory Intent information updating item I021/110",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Message Amplitude",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":5,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the latest measurement of the message amplitude, item I021/132",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Geometric Height",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":6,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the information contained in item 021/140",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Flight Level",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":8,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Flight Level information in item I021/145",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Intermediate State Selected Altitude",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":9,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Intermediate State Selected Altitude in item I021/146",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Final State Selected Altitude",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":10,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Final State Selected Altitude in item I021/148",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Air Speed",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":11,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Air Speed contained in item I021/150",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"True Air Speed",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":12,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the value for the True Air Speed in item I021/151",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Magnetic Heading",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":13,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the value for the Magnetic Heading in item I021/152",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Barometric Vertical Rate",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":14,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Barometric Vertical Rate contained in I021/155",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Geometric Vertical Rate",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":16,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Geometric Vertical Rate in item I021/157",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Ground Vector",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":17,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Ground Vector in item I021/160",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Track Angle Rate",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":18,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of item I021/165 Track Angle Rate",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Target Identification",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":19,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Target Identification in item I021/170",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Target Status",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":20,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Target Status as contained in item I021/200",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Met Information",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":21,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Meteorological data contained in I021/220",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Roll Angle",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":22,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the Roll Angle value as in item I021/230",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"ACAS Resolution Advisory",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":24,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the latest update of an active ACAS Resolution Advisory",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        },
                        {
                            "name":"Surface Capabilities and Characteristics",
                            "type":"optional_item",
                            "optional_bitfield_name":"available",
                            "optional_bitfield_index":25,
                            "data_fields":[
                                {
                                    "name":"Age",
                                    "comment":"Age of the latest information received on the surface capabilities and characteristics of the respective target",
                                    "type":"fixed_bytes",
                                    "data_type":"uint",
                                    "length":1,
                                    "lsb":0.1
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "number":"400",
            "name":"Receiver ID",
            "type":"item",
            "data_fields":[
                {
                    "name":"RID",
                    "comment":"Designator of Ground Station in Distributed System.",
                    "type":"fixed_bytes",
                    "length":1,
                    "data_type":"uint"
                }
            ]
        }
    ]
}
)";
  };
};
