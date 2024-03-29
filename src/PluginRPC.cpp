#include "PluginRPC.h"
#include <string>
#include <sampapi/CInput.h>

namespace samp = sampapi::v037r1;

template <typename T>
std::string readWithSize(RakNet::BitStream& bs) {
    T size;
    if (!bs.Read(size) || size <= 0)
        return {};
    std::string str(size, '\0');
    bs.Read(str.data(), size);
    return str;
}

template <typename T>
void writeWithSize(RakNet::BitStream& bs, std::string_view str) {
    T size = static_cast<T>(str.size());
    bs.Write(size);
    bs.Write(str.data(), size);
}

bool PluginRPC::onServerMessage(unsigned char& id, RakNet::BitStream* bs) {
    if (id != 93) // RPC_ClientMessage
        return true;

    unsigned long color;
    std::string msg;

    bs->Read(color);
    msg = readWithSize<unsigned int>(*bs);

    if (msg.find("Para escuchar alguna emisora de radio de San Andreas, usa {DBED15}/emisoras") != std::string::npos) {
        samp::RefInputBox()->Send("/arrancar");
    }

    return true;
}
