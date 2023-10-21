#include "GetConfigPacketRequest.h"
#include "../utils/ConvertPacket.h"

#include <iostream>

GetConfigPacketRequest_t::GetConfigPacketRequest_t() {}
GetConfigPacketRequest_t::GetConfigPacketRequest_t(const std::vector<uint8_t> &bin)
{
    if (GetConfigPacketRequest_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

GetConfigPacketRequest_t::~GetConfigPacketRequest_t() {}

int GetConfigPacketRequest_t::fromBin(const std::vector<uint8_t> &bin)
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
    // no needing
    // currentIndex += configName.size();

    return 0;
}

int GetConfigPacketRequest_t::toBin(std::vector<uint8_t> &bin) const
{
    ConvertPacket::addToBin(bin, (uint8_t)ns.size());
    ConvertPacket::addVariableDataToBin(bin, ns);

    ConvertPacket::addToBin(bin, (uint8_t)configName.size());
    ConvertPacket::addVariableDataToBin(bin, configName);

    return 0;
}
