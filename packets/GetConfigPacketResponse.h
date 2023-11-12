#ifndef GET_CONFIG_PACKET_RESPONSE_H
#define GET_CONFIG_PACKET_RESPONSE_H

#include "BasePacket.h"

#include <string>
#include <vector>

struct GetConfigPacketResponse_t : public BasePacket_t
{
    GetConfigPacketResponse_t();
    GetConfigPacketResponse_t(const std::vector<uint8_t> &bin);
    ~GetConfigPacketResponse_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;

    std::string ns;
    std::string configName;
    std::string configValue;
};

#endif // GET_CONFIG_PACKET_RESPONSE_H
