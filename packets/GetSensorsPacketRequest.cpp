#include "GetSensorsPacketRequest.h"

#include <iostream>

GetSensorsPacketRequest_t::GetSensorsPacketRequest_t() {}
GetSensorsPacketRequest_t::GetSensorsPacketRequest_t(const std::vector<uint8_t> &bin)
{
    if (GetSensorsPacketRequest_t::fromBin(bin))
    {
        std::cerr << "An error occured during an object construction" << std::endl;
        return;
    }
}

GetSensorsPacketRequest_t::~GetSensorsPacketRequest_t() {}

int GetSensorsPacketRequest_t::fromBin(const std::vector<uint8_t> &bin)
{
    // Unused
    (void)bin;

    return 0;
}

int GetSensorsPacketRequest_t::toBin(std::vector<uint8_t> &bin) const
{
    // Unused
    (void)bin;

    return 0;
}
