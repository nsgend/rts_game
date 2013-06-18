#ifndef NET_H_INCLUDED
#define NET_H_INCLUDED

#include <iostream>
#include <stdint.h>

#ifdef __WIN32__
    #include <winsock2.h>
#endif

enum {
    PACKET_PING,
    PACKET_PING_REPLY
};

typedef struct {
    uint16_t iPacketType;
    unsigned char ucData[24];
} NetPacket;

class Net {
public:
    static NetPacket Parse(std::string Packet);
};

#endif // NET_H_INCLUDED
