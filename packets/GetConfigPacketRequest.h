#ifndef GET_CONFIG_PACKET_REQUEST_H
#define GET_CONFIG_PACKET_REQUEST_H

#include "BasePacket.h"
#include <string>
#include <vector>

struct GetConfigPacketRequest_t : public BasePacket_t
{
    GetConfigPacketRequest_t();
    GetConfigPacketRequest_t(const std::vector<uint8_t> &bin);
    ~GetConfigPacketRequest_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;

    std::string ns;
    std::string configName;
};

#endif // GET_CONFIG_PACKET_REQUEST_H
