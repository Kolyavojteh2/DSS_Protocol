#include "GetSensorDataPacketResponse.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

GetSensorDataPacketResponse_t::GetSensorDataPacketResponse_t() {}
GetSensorDataPacketResponse_t::GetSensorDataPacketResponse_t(const std::vector<uint8_t> &bin)
{
    if (GetSensorDataPacketResponse_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

GetSensorDataPacketResponse_t::~GetSensorDataPacketResponse_t() {}

int GetSensorDataPacketResponse_t::fromBin(const std::vector<uint8_t> &bin)
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

    // sizeof(time_t)
    if (ConvertPacket::getFromBin(bin, currentIndex, sizeTime))
        return -1;
    currentIndex += sizeof(sizeTime);

    // sizeof(data)
    if (ConvertPacket::getFromBin(bin, currentIndex, sizeData))
        return -1;
    currentIndex += sizeof(sizeData);

    // data count
    uint8_t count;
    if (ConvertPacket::getFromBin(bin, currentIndex, count))
        return -1;
    currentIndex += sizeof(count);

    // DataTime
    for (uint8_t i = 0; i < count; ++i)
    {
        time_t itTime;
        if (ConvertPacket::getFromBin(bin, currentIndex, itTime))
            return -1;
        currentIndex += sizeof(itTime);

        dataTime.push_back(itTime);
    }

    // DataValue
    for (uint8_t i = 0; i < count; ++i)
    {
        for (uint8_t byte = 0; byte < sizeData; byte++)
        {
            uint8_t value;
            if (ConvertPacket::getFromBin(bin, currentIndex, value))
                return -1;
            currentIndex += sizeof(value);

            dataValue.push_back(value);
        }
    }

    return 0;
}

int GetSensorDataPacketResponse_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, (uint8_t)sensorName.size());
    ConvertPacket::addVariableDataToBin(bin, sensorName);

    ConvertPacket::addToBin(bin, (uint8_t)dataName.size());
    ConvertPacket::addVariableDataToBin(bin, dataName);

    ConvertPacket::addToBin(bin, sizeTime);
    ConvertPacket::addToBin(bin, sizeData);

    uint8_t count = dataTime.size() > 255 ? 255 : dataTime.size();
    ConvertPacket::addToBin(bin, count);

    uint8_t countTime = dataTime.size() > 255 ? 255 : dataTime.size();
    for (uint8_t i = 0; i < countTime; ++i)
        ConvertPacket::addToBin(bin, dataTime[i]);

    uint8_t countData = dataValue.size() > 255 ? 255 : dataValue.size();
    for (uint8_t i = 0; i < countData; ++i)
        ConvertPacket::addToBin(bin, dataValue[i]);

    return 0;
}

int GetSensorDataPacketResponse_t::getPacketSize()
{
    uint8_t count = dataTime.size() > 255 ? 255 : dataTime.size();
    uint8_t countTime = dataTime.size() > 255 ? 255 : dataTime.size();
    uint8_t countData = dataValue.size() > 255 ? 255 : dataValue.size();

    return sizeof(uint8_t) + sensorName.size() + sizeof(uint8_t) + dataName.size() + sizeof(sizeTime) + sizeof(sizeData) +
           sizeof(count) + countTime + countData;
}