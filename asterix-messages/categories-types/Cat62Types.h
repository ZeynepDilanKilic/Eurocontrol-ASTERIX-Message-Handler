#pragma once

#include <vector>
#include <string>
#pragma pack(push, 1) // Hizalamayı 1 byte'a ayarla
struct Cat62_010_DataSourceIndentifier
{
  unsigned int sac;
  unsigned int sic;
};

struct Cat62_015_ServiceIdentification
{
  unsigned int serviceIdentification;
};

struct Cat62_040_TrackNumber
{
  unsigned int trackNumber;
};

struct Cat61_060_TrackMode3ACode
{
  struct mode3A
  {
    unsigned int v;
    unsigned int g;
    unsigned int ch;
    unsigned int mode3AReply;
  } Mode3A;
};

struct Cat62_070_TimeOfTrackInformation
{
  unsigned int timeOfTrackInformation;
};

struct Cat062_080_TrackStatus
{
  struct trackStatus
  {
    unsigned int mon;
    unsigned int spi;
    unsigned int mrh;
    unsigned int src;
    unsigned int cnf;
    unsigned int fx;
  } TrackStatus;

  struct trackStatusFirstExtent
  {
    unsigned int sim;
    unsigned int tse;
    unsigned int tsb;
    unsigned int fpc;
    unsigned int aff;
    unsigned int stp;
    unsigned int kos;
    unsigned int fx2;
  } TrackStatusFirstExtent;

  struct trackStatusSecondExtent
  {
    unsigned int ama;
    unsigned int md4;
    unsigned int me;
    unsigned int mi;
    unsigned int md5;
    unsigned int fx3;
  } TrackStatusSecondExtent;

  struct trackStatusThirdExtent
  {
    unsigned int cst;
    unsigned int psr;
    unsigned int ssr;
    unsigned int mds;
    unsigned int ads;
    unsigned int suc;
    unsigned int aac;
    unsigned int fx4;
  } TrackStatusThirdExtent;

  struct trackStatusForthExtent
  {
    unsigned int sds;
    unsigned int ems;
    unsigned int pft;
    unsigned int fplt;
    unsigned int fx5;
  } TrackStatusForthExtent;

  struct trackStatusFifthExtent
  {
    unsigned int dupt;
    unsigned int dupf;
    unsigned int dupm;
    unsigned int sfc;
    unsigned int idd;
    unsigned int iec;
    unsigned int fx6;
  } TrackStatusFifthExtent;
};

struct Cat62_100_TrackStatus
{
  struct calculatedTrackPosition_Cartesian
  {
    double x;
    double y;
  }CalculatedTrackPosition_Cartesian;
};

struct Cat62_105_CalculatedPositionInWGS_84Co_ordinates
{
  double latitude;
  double longitude;
};

struct Cat62_110_Mode5DataReportsAndExtendedMore1Code
{
  struct sum
  {
    unsigned int m5;
    unsigned int id;
    unsigned int da;
    unsigned int m1;
    unsigned int m2;
    unsigned int m3;
    unsigned int x;
  } Sum;

  struct pmn
  {
    int pin;
    int nat;
    int mis;
  } Pum;

  struct pos
  {
    double latitude;
    double longitude;
  } Pos;

  struct ga
  {
    unsigned int res;
    unsigned int ga;
  } Ga;

  struct em1
  {
    int extendedMode1Code;
  } Em1;

  struct tos
  {
    double tos;
  } Tos;

  struct xp
  {
    unsigned int x5;
    unsigned int xc;
    unsigned int x3;
    unsigned int x2;
    unsigned int x1;
  } Xp;
};

struct Cat62_120_TrackMode2Code
{
  unsigned int mode2code;
};

struct Cat62_130_CalculatedTrackGeometricAltitude
{
  double altitude;
};

struct Cat62_135_CalculatedTrackBarometricAltitude
{
  unsigned int qnh;
  double calculatedTrackBarometricAltitude;
};

struct Cat62_136_MeasuredFlightLevel
{
  double measurementFlightLevel;
};

struct Cat62_185_CalculatedTrackVelocity_Cartesian
{
  double vx;
  double vy;
};

struct Cat62_200_ModeOfMovement
{
  unsigned int trans;
  unsigned int _long;
  unsigned int vert;
  unsigned int adf;
};

struct Cat62_220_CalculatedRateOfClimb_Descent
{
  double rateOfClimbDescent;
};

struct Cat62_245_TargetIdentification
{
  unsigned int sti;
  unsigned int targetIndetifcation; //// Çıkışına göre bakılacak icoa_characters
};

struct Cat62_270_TargetSizeAndOrientation
{
  double length;
  unsigned int fx;

  struct targetSizeAndOrientationFirstExtent
  {
    double orientation;
    unsigned int fx2;
  } TargetSizeAndOrientationFirstExtent;
};

struct Cat62_290_SystemTrackUpdateAges
{
  struct trk
  {
    double age;
  } Trk;

  struct psr
  {
    double age;
  } Psr;

  struct ssr
  {
    double age;
  } Ssr;

  struct mds
  {
    double age;
  } Mds;

  struct ads
  {
    double age;
  } Ads;

  struct es
  {
    double age;
  } Es;

  struct vdl
  {
    double age;
  } Vdl;

  struct uat
  {
    double age;
  } Uat;

  struct lop
  {
    double age;
  } Lop;

  struct mlt
  {
    double age;
  } Mlt;
};

struct Cat62_295_TrackDataAges
{
  struct available
  {
    double age;

    struct md1
    {
      double age;
    } Md1;

    struct md2
    {
      double age;
    } Md2;

    struct mda
    {
      double age;
    } Mda;

    struct md4
    {
      double age;
    } Md4;

    struct md5
    {
      double age;
    } Md5;

    struct mhg
    {
      double age;
    } Mhg;

    struct ias
    {
      double age;
    } Ias;

    struct sal
    {
      double age;
    } Sal;

    struct fss
    {
      double age;
    } Fss;

    struct tid
    {
      double age;
    } Tid;

    struct com
    {
      double age;
    } Com;

    struct acs
    {
      double age;
    } Acs;

    struct bvr
    {
      double age;
    } Bvr;

    struct gvr
    {
      double age;
    } Gvr;

    struct ran
    {
      double age;
    } Ran;

    struct tar
    {
      double age;
    } Tar;

    struct tan
    {
      double age;
    } Tan;

    struct gsp
    {
      double age;
    } Gsp;

    struct vun
    {
      double age;
    } Vun;

    struct met
    {
      double age;
    } Met;

    struct emc
    {
      double age;
    } Emc;

    struct pos
    {
      double age;
    } Pos;

    struct gal
    {
      double age;
    } Gal;

    struct pun
    {
      double age;
    } Pun;

    struct mb
    {
      double age;
    } Mb;

    struct iar
    {
      double age;
    } Iar;

    struct mac
    {
      double age;
    } Mac;

    struct bps
    {
      double age;
    } Bps;

  } Available;
};

struct Cat62_300_VehileFleetIdentification
{
  unsigned int vfi;
};

struct Cat62_340_MeasuredInformation
{
  struct sid
  {
    unsigned int sac;
    unsigned int sic;
  } Sid;

  struct pos
  {
    double rho;
    double theta;
  } Pos;

  struct hei
  {
    double height;
  } Hei;

  struct mdc
  {
    unsigned int v;
    unsigned int g;
    double lastMeasuredModeCCode;
  } Mdc;

  struct mda
  {
    unsigned int v;
    unsigned int g;
    unsigned int l;
    unsigned int mode3AReply;
  } Mda;

  struct typ
  {
    unsigned int typ;
    unsigned int sim;
    unsigned int rab;
    unsigned int tst;
  } Typ;
};

struct Cat62_380_AircraftDerivedData
{
  unsigned int adr;
  struct id
  {
    unsigned int targetIdentification; // icao_characters bakılacak tam neye karşılık geldiği bilinmiyor.
  } Id;

  struct mhg
  {
    double magneticHeading;
  } Mhg;

  struct ais
  {
    unsigned int im;
    unsigned int airSpeed;
  } Ais;

  struct tas
  {
    double trueAirspeed;
  } Tas;

  struct sal
  {
    struct selectedAltitude
    {
      unsigned int sas;
      unsigned int source;
      unsigned int altitude;
    } SelectedAltitude;
  } Sal;

  struct fss
  {
    struct finalStateSelectedAltitude
    {
      unsigned int mv;
      unsigned int ah;
      unsigned int am;
      unsigned int altitude;
    } FinalStateSelectedAltitude;
  } Fss;

  struct tis
  {
    unsigned int nav;
    unsigned int nvb;
  } Tis;

  struct tid
  {
    struct trajectoryIntentData
    {
      struct tid1
      {
        unsigned int tca;
        unsigned int nc;
        unsigned int tcpNumber;
      } Tid1;

      double altitude;
      double longitude;
      double latitude;

      struct tid2
      {
        unsigned int pointType;
        unsigned int td;
        unsigned int tra;
        unsigned int toa;
      } Tid2;

      double tov;
      double ttr;

    } TrajectoryIntentData;
  } Tid;

  struct com
  {
    struct communicaitons_Acas_CapabilityAndFlightStatusReportedByModeS
    {
      unsigned int com;
      unsigned int stat;
      unsigned int ssc;
      unsigned int aic;
      unsigned int b1a;
      unsigned int b1b;
    } Communicaitons_Acas_CapabilityAndFlightStatusReportedByModeS;
  } Com;

  struct sab
  {
    struct status_reported_by_ads_B
    {
      unsigned int ac;
      unsigned int mn;
      unsigned int dc;
      unsigned int gbs;
      unsigned int stat;
    } StatusReportedByADS_B;
  } Sab;

  struct acs
  {
    unsigned int mbData;
  } Acs;

  struct bvr
  {
    double barometricVerticalRate;
  } Bvr;

  struct gvr
  {
    double geometricVerticalRate;
  } Gvr;

  struct ran
  {
    double rollAngle;
  } Ran;

  struct tar
  {
    struct track_angle_rate
    {
      unsigned int ti;
      double rateOfTurn;
    } TrackAngleRate;
  } Tar;

  struct tan
  {
    double trackAngle;
  } Tan;

  struct gsp
  {
    double groundSpeed;
  } Gsp;

  struct met
  {
    struct ws
    {
      double windSpeed;
    } Ws;

    struct wd
    {
      double windDirection;
    } Wd;

    struct tmp
    {
      double temperature;
    } Tmp;

    struct trb
    {
      unsigned int turbulence;
    } Trb;
  } Met;

  struct emc
  {
    unsigned int ecat;
  } Emc;

  struct pos
  {
    double latitude;
    double longitude;
  } Pos;

  struct gal
  {
    double geometricAltitude;
  } Gal;

  struct pun
  {
    unsigned int positionUncertainty;
  } Pun;

  struct mb
  {
    struct mode_s_mb_data
    {
      unsigned int mbData;
      struct address
      {
        unsigned int bds1;
        unsigned int bds2;
      } Address;

    } ModeSMBData;
  } Mb;

  struct iar
  {
    double indicatedAirSpeed;
  };

  struct mac
  {
    double machNumber;
  } Mac;

  struct bps
  {
    double barometricPressureSetting;
  } Bps;
};

struct Cat62_390_FlightPlanRelatedData
{

  struct tag
  {
    unsigned int sac;
    unsigned int sic;
  } Tag;

  struct csn
  {
    char callsign[7];
  } Csn;

  struct ifi
  {
    struct ifps_flight_id
    {
      unsigned int typ;
      unsigned int nbr;
    };

  } Ifi;

  struct fct
  {
    struct flight_category
    {
      unsigned int gat_oat;
      unsigned int fr1_fr2;
      unsigned int rvsm;
      unsigned int hpr;
    } FlightCategory;
  } FCT;

  struct tac
  {
    char typeOfAircraft[4];
  } Tac;

  struct wtc
  {
    char wakeTurbulenceCategory[1];
  } Wtc;

  struct dep
  {
    char departureAirport[4];
  } Dep;

  struct dst
  {
    char destrinationAirport[4];
  } Dst;

  struct rds
  {
    unsigned int nu1;
    unsigned int nu2;
    unsigned int ltr;
  } Rds;

  double cfl;

  struct ctl
  {
    unsigned int centre;
    unsigned int position;
  } Ctl;

  struct tod
  {
    struct time_of_departure_arrival
    {
      struct tod1
      {
        unsigned int type;
        unsigned int day;
        unsigned int hor;
        unsigned int min;
        unsigned int avs;
        unsigned int sec;
      } Tod1;
    } TimeOfDeperatureArrival;
  } Tod;

  struct ast
  {
    char aircraftStand[6];
  } Ast;

  struct sts
  {
    unsigned int emp;
    unsigned int avl;
  } Sts;

  struct std
  {
    char standardInstrumentDeparture[7];
  } Std;

  struct sta
  {
    char standartInstrumentArrival[7];
  } Sta;

  struct pem
  {
    struct pre_emergency_mode_3a
    {
      unsigned int va;
      unsigned int mode_3a_reply;
    } PreEmergencyMode3A;
  } Pem;

  struct pec
  {
    char pre_emergency_callsign[7];
  } Pec;
};

struct Cat62_500_EstimatedAccuracies
{
  struct apc
  {
    double apc_x_component;
    double apc_y_component;
  } Apc;

  struct cov
  {
    double cov_xy_covariance_component;
  } Cov;

  struct apw
  {
    double apw_latitude_component;
    double apw_longitude_component;
  } Apw;

  double aga;
  double aba;
  struct atv
  {
    double atv_x_component;
    double atv_y_component;
  } Atv;

  struct aa
  {
    double aa_x_component;
    double aa_y_component;
  } Aa;

  struct arc
  {
    double arc;
  } Arc;
};

struct Cat62_510_Composed_Track_Number
{
  struct composed_track_number
  {
    unsigned int systemUnitIdentification;
    unsigned int systemTrackNumber;
    unsigned int extend;
  } ComposedTrackNumber;
};



struct AsterixMessage_Cat62
{
  Cat62_010_DataSourceIndentifier cat62_010_DataSourceIndentifier{0};
  Cat62_015_ServiceIdentification cat62_015_ServiceIdentification{0};
  Cat62_040_TrackNumber cat62_040_TrackNumber{0};
  Cat61_060_TrackMode3ACode cat61_060_TrackMode3ACode{0};
  Cat62_070_TimeOfTrackInformation cat62_070_TimeOfTrackInformation{0};
  Cat062_080_TrackStatus cat062_080_TrackStatus{0};
  Cat62_100_TrackStatus cat62_100_TrackStatus{0};
  Cat62_105_CalculatedPositionInWGS_84Co_ordinates cat62_105_CalculatedPositionInWGS_84Co_ordinates{0};
  Cat62_110_Mode5DataReportsAndExtendedMore1Code cat62_110_Mode5DataReportsAndExtendedMore1Code{0};
  Cat62_120_TrackMode2Code cat62_120_TrackMode2Code{0};
  Cat62_130_CalculatedTrackGeometricAltitude cat62_130_CalculatedTrackGeometricAltitude{0};
  Cat62_135_CalculatedTrackBarometricAltitude cat62_135_CalculatedTrackBarometricAltitude{0};
  Cat62_136_MeasuredFlightLevel cat62_136_MeasuredFlightLevel{0};
  Cat62_185_CalculatedTrackVelocity_Cartesian cat62_185_CalculatedTrackVelocity_Cartesian{0};
  Cat62_200_ModeOfMovement cat62_200_ModeOfMovement{0};
  Cat62_220_CalculatedRateOfClimb_Descent cat62_220_CalculatedRateOfClimb_Descent{0};
  Cat62_245_TargetIdentification cat62_245_TargetIdentification{0};
  Cat62_270_TargetSizeAndOrientation cat62_270_TargetSizeAndOrientation{0};
  Cat62_290_SystemTrackUpdateAges cat62_290_SystemTrackUpdateAges{0};
  Cat62_295_TrackDataAges cat62_295_TrackDataAges{0};
  Cat62_300_VehileFleetIdentification cat62_300_VehileFleetIdentification{0};
  Cat62_340_MeasuredInformation cat62_340_MeasuredInformation{0};
  Cat62_380_AircraftDerivedData cat62_380_AircraftDerivedData{0};
  Cat62_390_FlightPlanRelatedData cat62_390_FlightPlanRelatedData{0};
  Cat62_500_EstimatedAccuracies cat62_500_EstimatedAccuracies{0};

  AsterixMessage_Cat62(){};
};

#pragma pack(pop) // Önceki hizalama ayarını geri yükleas