#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif


#include <stdint.h>
#include <sstream>
#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "net.h"

int main ( int argc, char** argv )
{
    std::ostringstream oSS;
    oSS << (uint16_t)PACKET_PING;
    oSS << "HELLO";

    NetPacket test = Net::Parse(oSS.str());
    std::cout << test.ucData;

    return 0;
}
