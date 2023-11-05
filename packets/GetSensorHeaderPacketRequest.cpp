#include "GetSensorHeaderPacketRequest.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

GetSensorHeaderPacketRequest_t::GetSensorHeaderPacketRequest_t() {}
GetSensorHeaderPacketRequest_t::GetSensorHeaderPacketRequest_t(const std::vector<uint8_t> &bin)
{
    if (GetSensorHeaderPacketRequest_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

GetSensorHeaderPacketRequest_t::~GetSensorHeaderPacketRequest_t() {}

int GetSensorHeaderPacketRequest_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    // sensor name length
    uint8_t sensorLength;
    if (ConvertPacket::getFromBin(bin, currentIndex, sensorLength))
        return -1;
    currentIndex += sizeof(sensorLength);

    // sensor name
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, sensorLength, sensorName))
        return -1;
    currentIndex += sensorLength;

    return 0;
}

int GetSensorHeaderPacketRequest_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, (uint8_t)sensorName.size());
    ConvertPacket::addVariableDataToBin(bin, sensorName);

    return 0;
}
