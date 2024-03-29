#pragma once

#include <RakHook/rakhook.hpp>
#include <RakNet/BitStream.h>

class PluginRPC {
public:
    bool onServerMessage(unsigned char& id, RakNet::BitStream* bs);
};

