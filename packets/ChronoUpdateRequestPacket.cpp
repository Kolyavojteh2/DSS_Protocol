#include "ChronoUpdateRequestPacket.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

ChronoUpdateRequestPacket_t::ChronoUpdateRequestPacket_t() : oldTime(0) {}
ChronoUpdateRequestPacket_t::ChronoUpdateRequestPacket_t(const std::vector<uint8_t> &bin) : oldTime(0)
{
    if (ChronoUpdateRequestPacket_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

ChronoUpdateRequestPacket_t::~ChronoUpdateRequestPacket_t() {}

int ChronoUpdateRequestPacket_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    // oldTime
    if (ConvertPacket::getFromBin(bin, currentIndex, oldTime))
        return -1;
    // no needing
    // currentIndex += sizeof(oldTime);

    return 0;
}

int ChronoUpdateRequestPacket_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, oldTime);

    return 0;
}
