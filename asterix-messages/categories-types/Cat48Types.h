#pragma once

#include <vector>
#include <string>

#pragma pack(push, 1) // Hizalamayı 1 byte'a ayarla

// CAT_definitionda bitfield alanlar unsigned int olarak tanımlanmıştır.
struct Cat48_010_DataSourceIdentifier
{
    unsigned int sac;
    unsigned int sic;
};

struct Cat48_020_TargetReportDescriptor
{
    struct target_report_descriptor
    {
        unsigned int typ;
        unsigned int sim;
        unsigned int rdp;
        unsigned int spi;
        unsigned int rab;
        unsigned int fx;
    } Targetreportdescriptor;

    struct target_report_descriptor_first_extend
    {
        unsigned int tst;
        unsigned int err;
        unsigned int xpp;
        unsigned int me;
        unsigned int mi;
        unsigned int foe_fri;
        unsigned int fx2;
    } Targetreportdescriptorfirstextend;
};

struct Cat48_030_WarningErrorConditions
{
    struct warning_error_condition
    {
        unsigned int w_e_value;
        unsigned int extend;
    } Warningerrorcondition;

    // EXTENDABLE VERİSİ KONTROL VE TESTİ YAPILACAK
};

struct Cat48_040_MeasuredPositioninPolarCoordinates
{
    double rho;
    double theta;
};

struct Cat48_042_CalculatedPositioninCartesianCoordinates
{
    double x_component;
    double y_component;
};

struct Cat48_050_Mode2CodeinOctalRepresentation
{
    struct mode_2
    {
        unsigned int v;
        unsigned int g;
        unsigned int l;
        unsigned int mode2_code;
    } Mode2;
};

struct Cat48_055_Mode1CodeinOctalRepresentation
{
    struct mode_1
    {
        unsigned int v;
        unsigned int g;
        unsigned int l;
        unsigned int mode1_code;
    } Mode1;
};

struct Cat48_060_Mode2CodeConfidenceIndicator
{
    unsigned int qxi;
};

struct Cat48_065_Mode1CodeConfidenceIndicator
{
    unsigned int qxi;
};

struct Cat48_070_Mode3ACodeinOctalRepresentation
{
    struct mode3_a
    {
        unsigned int v;
        unsigned int g;
        unsigned int l;
        unsigned int mode3a_reply; // Nasıl tutulması gerek kontrol edilecek.
        /*
            "name":"Mode-3/A reply",
            "comment":"",
            "type":"fixed_bits",
            "data_type":"digits",
            "start_bit":0,
            "bit_length":12,
            "num_digits":4,
            "digit_bit_length":3
        */
    } Mode3a;
};

struct Cat48_080_Mode3ACodeConfidenceIndicator
{
    unsigned int qxi;
};

struct Cat48_090_FlightLevelinBinaryRepresentation
{
    struct flight_level
    {
        unsigned int v;
        unsigned int g;
        double flight_level;
    } Flightlevel;
};

struct Cat48_100_ModeCCodeandCodeConfidenceIndicator
{
    struct mode_c_code
    {
        unsigned int v;
        unsigned int g;
        unsigned int modec_reply;
    } Modeccode;

    unsigned int qxi;
};

struct Cat48_110_HeightMeasuredbya3DRadar
{
    double height_3D;
};

struct Cat48_120_RadialDopplerSpeed
{
    struct CAL
    {
        unsigned int d;
        int cal;
    } CalculatedDopplerSpeed;

    struct RDS
    {
        unsigned int dop;
        unsigned int amb;
        unsigned int frq;
    } RawDopplerSpeed;
    std::vector<RDS> countValues;

    struct Available
    {
        unsigned int cal_available;
        unsigned int rds_available;
    } available_map;
};

struct Cat48_130_RadarPlotCharacteristics
{
    double srl;
    unsigned int srr;
    unsigned int sam;
    double prl;
    unsigned int pam;
    double rpd;
    double apd;

    struct Available
    {
        unsigned int srl_available;
        unsigned int srr_available;
        unsigned int sam_available;
        unsigned int prl_available;
        unsigned int pam_available;
        unsigned int rdp_available;
        unsigned int apd_available;
    } available_map;
};

struct Cat48_140_TimeOfDay
{
    double timeOfDay;
};

struct Cat48_161_TrackNumber
{
    unsigned int track_number;
};

struct Cat48_170_TrackStatus
{
    struct track_status
    {
        unsigned int cnf;
        unsigned int rad;
        unsigned int dou;
        unsigned int mah;
        unsigned int cdm;
        unsigned int fx;
    } Trackstatus;

    struct track_status_first_extend
    {
        unsigned int tre;
        unsigned int gho;
        unsigned int sup;
        unsigned int tcc;
    } Trackstatusfirstextend;
};

struct Cat48_200_CalculatedTrackVelocityinPolarCoordinates
{
    double calculateed_groundspeed;
    double calculated_heading;
};

struct Cat48_210_TrackQuality
{
    double sigma_x;
    double sigma_y;
    double sigma_v;
    double sigma_h;
};

struct Cat48_220_AircraftAddress
{
    unsigned int aircraft_address;
};

struct Cat48_230_CommunicationsACASCapabilityandFlightStatus
{
    struct communication_acas_capability_and_flight_status
    {
        unsigned int com;
        unsigned int stat;
        unsigned int si;
        unsigned int mssc;
        unsigned int arc;
        unsigned int aic;
        unsigned int b1a;
        unsigned int b1b;
    } Communicationacascapabilityandflightstatus;
};

struct Cat48_240_AircraftIdentification
{
    unsigned int aircraft_Identification; // Icao characters parse kontrolü yapılacak.
    /*
        "name":"Aircraft Identification",
        "comment":"",
        "type":"fixed_bits",
        "data_type":"icao_characters",
        "start_bit":0,
        "bit_length":48,
        "num_characters":8,
        "character_bit_length":6
    */
};

struct Cat48_250_ModeSMBData
{
    struct Mode_S_MB_Data
    {
        unsigned int mb_data;

        struct Adress
        {
            unsigned int bds1;
            unsigned int bds2;
        }address;

    } ModeSMBData;
    std::vector<Mode_S_MB_Data> countValues;
};

struct Cat48_260_ACASResolutionAdvisoryReport
{
    unsigned int mb_data; //data_type : bin
};

#pragma pack(pop) // Önceki hizalama ayarını geri yükle

struct AsterixMessage_Cat48
{
    Cat48_010_DataSourceIdentifier datasourceidentifier{0};
    Cat48_020_TargetReportDescriptor targetreportdescriptor{0};
    Cat48_030_WarningErrorConditions warningerrorconditions{0};
    Cat48_040_MeasuredPositioninPolarCoordinates measuredpositioninpolarcoordinates{0};
    Cat48_042_CalculatedPositioninCartesianCoordinates calculatedpositionincartesiancoordinates{0};
    Cat48_050_Mode2CodeinOctalRepresentation mode2codeinoctalrepresentation{0};
    Cat48_055_Mode1CodeinOctalRepresentation mode1codeinoctalrepresentation{0};
    Cat48_060_Mode2CodeConfidenceIndicator mode2codeconfidenceindicator;
    Cat48_065_Mode1CodeConfidenceIndicator mode1codeconfidenceindicator{0};
    Cat48_070_Mode3ACodeinOctalRepresentation mode3acodeinoctalrepresentation{0};
    Cat48_080_Mode3ACodeConfidenceIndicator mode3acodeconfidenceindicator{0};
    Cat48_090_FlightLevelinBinaryRepresentation flightlevelinbinaryrepresentation{0};
    Cat48_100_ModeCCodeandCodeConfidenceIndicator modeccodeandcodeconfidenceindicator{0};
    Cat48_110_HeightMeasuredbya3DRadar heightmeasuredbya3dradar{0};
    Cat48_120_RadialDopplerSpeed radialdopplerspeed{0};
    Cat48_130_RadarPlotCharacteristics radarplotcharacteristics{0};
    Cat48_140_TimeOfDay timeofday{0};
    Cat48_161_TrackNumber tracknumber{0};
    Cat48_170_TrackStatus trackstatus{0};
    Cat48_200_CalculatedTrackVelocityinPolarCoordinates calculatedtrackvelocityinpolarcoordinates;
    Cat48_210_TrackQuality trackquality{0};
    Cat48_220_AircraftAddress aircraftaddress{0};
    Cat48_230_CommunicationsACASCapabilityandFlightStatus communicationsacascapabilityandflightstatus{0};
    Cat48_240_AircraftIdentification aircraftidentification{0};
    Cat48_250_ModeSMBData modesmbdata{0};
    Cat48_260_ACASResolutionAdvisoryReport acasresolutionadvisoryreport{0};
    AsterixMessage_Cat48() {}
};