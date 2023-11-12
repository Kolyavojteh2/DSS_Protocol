#include "AliveNodeResponsePacket.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

AliveNodeResponsePacket_t::AliveNodeResponsePacket_t() {}
AliveNodeResponsePacket_t::AliveNodeResponsePacket_t(const std::vector<uint8_t> &bin)
{
    if (AliveNodeResponsePacket_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

AliveNodeResponsePacket_t::~AliveNodeResponsePacket_t() {}

int AliveNodeResponsePacket_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    // parent MAC
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, MAC_ADDRESS_LENGTH, parentMAC))
        return -1;
    // no needing
    // currentIndex += MAC_ADDRESS_LENGTH;

    return 0;
}

int AliveNodeResponsePacket_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addVariableDataToBin(bin, parentMAC);

    return 0;
}

int AliveNodeResponsePacket_t::getPacketSize()
{
    return parentMAC.size();
}