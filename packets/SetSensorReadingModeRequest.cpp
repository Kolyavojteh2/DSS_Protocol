#include "SetSensorReadingModeRequest.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

SetSensorReadingModeRequest_t::SetSensorReadingModeRequest_t() {}
SetSensorReadingModeRequest_t::SetSensorReadingModeRequest_t(const std::vector<uint8_t> &bin)
{
    if (SetSensorReadingModeRequest_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

SetSensorReadingModeRequest_t::~SetSensorReadingModeRequest_t() {}

int SetSensorReadingModeRequest_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    if (ConvertPacket::getFromBin(bin, currentIndex, isCyclic))
        return -1;
    currentIndex += sizeof(isCyclic);

    if (ConvertPacket::getFromBin(bin, currentIndex, period))
        return -1;
    currentIndex += sizeof(period);

    return 0;
}

int SetSensorReadingModeRequest_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, isCyclic);
    ConvertPacket::addToBin(bin, period);

    return 0;
}

int SetSensorReadingModeRequest_t::getPacketSize()
{
    return sizeof(isCyclic) + sizeof(period);
}
