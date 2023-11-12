#include "GetSensorHeaderPacketResponse.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

GetSensorHeaderPacketResponse_t::GetSensorHeaderPacketResponse_t() {}
GetSensorHeaderPacketResponse_t::GetSensorHeaderPacketResponse_t(const std::vector<uint8_t> &bin)
{
    if (GetSensorHeaderPacketResponse_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

GetSensorHeaderPacketResponse_t::~GetSensorHeaderPacketResponse_t() {}

int GetSensorHeaderPacketResponse_t::fromBin(const std::vector<uint8_t> &bin)
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

    // count
    uint8_t count;
    if (ConvertPacket::getFromBin(bin, currentIndex, count))
        return -1;
    currentIndex += sizeof(count);

    // each dataName
    for (uint8_t i = 0; i < count; ++i)
    {
        // data name length
        uint8_t dataNameLength;
        if (ConvertPacket::getFromBin(bin, currentIndex, dataNameLength))
            return -1;
        currentIndex += sizeof(dataNameLength);

        // data name
        std::string dataName;
        if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, dataNameLength, dataName))
            return -1;
        currentIndex += dataNameLength;

        sensorDataNames.push_back(dataName);
    }

    return 0;
}

int GetSensorHeaderPacketResponse_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, (uint8_t)sensorName.size());
    ConvertPacket::addVariableDataToBin(bin, sensorName);

    ConvertPacket::addToBin(bin, (uint8_t)sensorDataNames.size());
    for (uint8_t i = 0; i < sensorDataNames.size(); ++i)
    {
        ConvertPacket::addToBin(bin, (uint8_t)sensorDataNames[i].size());
        ConvertPacket::addVariableDataToBin(bin, sensorDataNames[i]);
    }

    return 0;
}

int GetSensorHeaderPacketResponse_t::getPacketSize()
{
    int m_size = sizeof(uint8_t) + sensorName.size() + sizeof(uint8_t);
    for (auto &it : sensorDataNames)
        m_size += sizeof(uint8_t) + it.size();

    return m_size;
}