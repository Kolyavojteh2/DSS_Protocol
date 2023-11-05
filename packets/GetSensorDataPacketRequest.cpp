#include "GetSensorDataPacketRequest.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

GetSensorDataPacketRequest_t::GetSensorDataPacketRequest_t() {}
GetSensorDataPacketRequest_t::GetSensorDataPacketRequest_t(const std::vector<uint8_t> &bin)
{
    if (GetSensorDataPacketRequest_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

GetSensorDataPacketRequest_t::~GetSensorDataPacketRequest_t() {}

int GetSensorDataPacketRequest_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    // sensorName length
    uint8_t sensorNameLength;
    if (ConvertPacket::getFromBin(bin, currentIndex, sensorNameLength))
        return -1;
    currentIndex += sizeof(sensorNameLength);

    // sensorName
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, sensorNameLength, sensorName))
        return -1;
    currentIndex += sensorNameLength;

    // dataName length
    uint8_t dataNameLength;
    if (ConvertPacket::getFromBin(bin, currentIndex, dataNameLength))
        return -1;
    currentIndex += sizeof(dataNameLength);

    // dataName
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, dataNameLength, dataName))
        return -1;
    currentIndex += dataNameLength;

    // timeFrom length
    if (ConvertPacket::getFromBin(bin, currentIndex, timeFrom))
        return -1;
    currentIndex += sizeof(timeFrom);

    // timeTo length
    if (ConvertPacket::getFromBin(bin, currentIndex, timeTo))
        return -1;
    // no needing
    currentIndex += sizeof(timeTo);

    return 0;
}

int GetSensorDataPacketRequest_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, (uint8_t)sensorName.size());
    ConvertPacket::addVariableDataToBin(bin, sensorName);

    ConvertPacket::addToBin(bin, (uint8_t)dataName.size());
    ConvertPacket::addVariableDataToBin(bin, dataName);

    ConvertPacket::addToBin(bin, timeFrom);
    ConvertPacket::addToBin(bin, timeTo);

    return 0;
}
