#include "db_define.h"
#include <unordered_map>

DECL_MEMBER(WEATHER)

#define GET_MAPPED_VAL(map, str)    \
auto iter = map.find(str);          \
if (iter == map.end())              \
    return Type::UNKNOWN;           \
return iter->second;

const char* Protocol::kHttp = "HTTP";
const char* Protocol::kTcp = "TCP";
const char* Protocol::kUdp = "UDP";

const std::string Protocol::g_ProtocolStr[] = {
    Protocol::kHttp, Protocol::kTcp, Protocol::kUdp
};

Protocol::Type Protocol::Mapped(const std::string& ss) {
    static const std::unordered_map<std::string, Protocol::Type> map = {
        {Protocol::kHttp,   Protocol::Type::HTTP},
        {Protocol::kUdp,    Protocol::Type::UDP},
        {Protocol::kTcp,    Protocol::Type::TCP}
    };

    GET_MAPPED_VAL(map, ss);
}