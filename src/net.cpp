
#include "net.h"

#include <iostream>
#include <sstream>
#include <istream>

std::istream& operator >>(std::istream &is, NetPacket& np) {
    is >> np.iPacketType;
    is >> np.ucData;

    return is;
}

NetPacket Net::Parse(std::string Packet) {
    NetPacket outPacket;
    std::istringstream iSS(Packet, std::ios_base::binary | std::ios_base::in);

    iSS >> outPacket;

    return outPacket;
}
