#include "GetSensorsPacketResponse.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

GetSensorsPacketResponse_t::GetSensorsPacketResponse_t() {}
GetSensorsPacketResponse_t::GetSensorsPacketResponse_t(const std::vector<uint8_t> &bin)
{
    if (GetSensorsPacketResponse_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

GetSensorsPacketResponse_t::~GetSensorsPacketResponse_t() {}

int GetSensorsPacketResponse_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    // Sensors count
    uint8_t count;
    if (ConvertPacket::getFromBin(bin, currentIndex, count))
        return -1;
    currentIndex += sizeof(count);

    // each sensor
    for (uint8_t sensorNumber = 0; sensorNumber < count; ++sensorNumber)
    {
        // sensor name length
        uint8_t sensorLength;
        if (ConvertPacket::getFromBin(bin, currentIndex, sensorLength))
            return -1;
        currentIndex += sizeof(sensorLength);

        // sensor name
        std::string sensor;
        if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, sensorLength, sensor))
            return -1;
        currentIndex += sensorLength;

        sensors.push_back(sensor);
    }

    return 0;
}

int GetSensorsPacketResponse_t::toBin(std::vector<uint8_t> &bin) const
{
    // Sensors count
    ConvertPacket::addToBin(bin, (uint8_t)sensors.size());

    // each sensor
    for (const std::string &sensor : sensors)
    {
        ConvertPacket::addToBin(bin, (uint8_t)sensor.size());
        ConvertPacket::addVariableDataToBin(bin, sensor);
    }

    return 0;
}

int GetSensorsPacketResponse_t::getPacketSize()
{
    int m_size = sizeof(uint8_t);
    for (auto &it : sensors)
        m_size += sizeof(uint8_t) + it.size();

    return m_size;
}