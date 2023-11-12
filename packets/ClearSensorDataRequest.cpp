#include "ClearSensorDataRequest.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

ClearSensorDataRequest_t::ClearSensorDataRequest_t() {}
ClearSensorDataRequest_t::ClearSensorDataRequest_t(const std::vector<uint8_t> &bin)
{
    if (ClearSensorDataRequest_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

ClearSensorDataRequest_t::~ClearSensorDataRequest_t() {}

int ClearSensorDataRequest_t::fromBin(const std::vector<uint8_t> &bin)
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

int ClearSensorDataRequest_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, (uint8_t)sensorName.size());
    ConvertPacket::addVariableDataToBin(bin, sensorName);

    ConvertPacket::addToBin(bin, (uint8_t)dataName.size());
    ConvertPacket::addVariableDataToBin(bin, dataName);

    ConvertPacket::addToBin(bin, timeFrom);
    ConvertPacket::addToBin(bin, timeTo);

    return 0;
}

int ClearSensorDataRequest_t::getPacketSize()
{
    return sizeof(uint8_t) + sensorName.size() + sizeof(uint8_t) + dataName.size() + sizeof(timeFrom) + sizeof(timeTo);
}