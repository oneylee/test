#pragma

#define ROW_MEMBER(table, row) static const char* row;
#define DECL_ROW(table, row) const char* table::row = #row;

#define DECL_TABLE(table)               \
struct table                            \
{                                       \
    static const char* TABLE_NAME;      \
    table ## _MAP(ROW_MEMBER);          \
};
    
#define DECL_MEMBER(table)              \
const char* TABLE_NAME = #table;        \
table ## _MAP(DECL_ROW);

#define WEATHER_MAP(XX) \
XX(WEATHER, CITY)       \
XX(WEATHER, TEMP_LO)    \
XX(WEATHER, TEMP_HI)    \
XX(WEATHER, PRCP)       \
XX(WEATHER, DATE)       

DECL_TABLE(WEATHER)

    