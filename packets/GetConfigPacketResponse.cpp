#include "GetConfigPacketResponse.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

GetConfigPacketResponse_t::GetConfigPacketResponse_t() {}
GetConfigPacketResponse_t::GetConfigPacketResponse_t(const std::vector<uint8_t> &bin)
{
    if (GetConfigPacketResponse_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

GetConfigPacketResponse_t::~GetConfigPacketResponse_t() {}

int GetConfigPacketResponse_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    // ns length
    uint8_t nsLength;
    if (ConvertPacket::getFromBin(bin, currentIndex, nsLength))
        return -1;
    currentIndex += sizeof(nsLength);

    // namespace
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, nsLength, ns))
        return -1;
    currentIndex += ns.size();

    // configName length
    uint8_t configNameLength;
    if (ConvertPacket::getFromBin(bin, currentIndex, configNameLength))
        return -1;
    currentIndex += sizeof(configNameLength);

    // configName
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, configNameLength, configName))
        return -1;
    currentIndex += configName.size();

    // configValue length
    uint8_t configValueLength;
    if (ConvertPacket::getFromBin(bin, currentIndex, configValueLength))
        return -1;
    currentIndex += sizeof(configValueLength);

    // configValue
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, configValueLength, configValue))
        return -1;
    // no needing
    // currentIndex += configValue.size();

    return 0;
}

int GetConfigPacketResponse_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, (uint8_t)ns.size());
    ConvertPacket::addVariableDataToBin(bin, ns);

    ConvertPacket::addToBin(bin, (uint8_t)configName.size());
    ConvertPacket::addVariableDataToBin(bin, configName);

    ConvertPacket::addToBin(bin, (uint8_t)configValue.size());
    ConvertPacket::addVariableDataToBin(bin, configValue);

    return 0;
}

int GetConfigPacketResponse_t::getPacketSize()
{
    return sizeof(uint8_t) + ns.size() + sizeof(uint8_t) + configName.size() + sizeof(uint8_t) + configValue.size();
}
