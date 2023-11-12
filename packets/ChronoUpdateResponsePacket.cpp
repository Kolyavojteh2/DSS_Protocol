#include "ChronoUpdateResponsePacket.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

ChronoUpdateResponsePacket_t::ChronoUpdateResponsePacket_t() : newTime(0) {}
ChronoUpdateResponsePacket_t::ChronoUpdateResponsePacket_t(const std::vector<uint8_t> &bin) : newTime(0)
{
    if (ChronoUpdateResponsePacket_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

ChronoUpdateResponsePacket_t::~ChronoUpdateResponsePacket_t() {}

int ChronoUpdateResponsePacket_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    // newTime
    if (ConvertPacket::getFromBin(bin, currentIndex, newTime))
        return -1;
    // no needing
    // currentIndex += sizeof(oldTime);

    return 0;
}

int ChronoUpdateResponsePacket_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, newTime);

    return 0;
}

int ChronoUpdateResponsePacket_t::getPacketSize()
{
    return sizeof(newTime);
}
