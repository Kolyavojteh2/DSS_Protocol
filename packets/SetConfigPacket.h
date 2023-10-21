#ifndef SET_CONFIG_PACKET_H
#define SET_CONFIG_PACKET_H

#include "BasePacket.h"

#include <string>
#include <vector>

struct SetConfigPacket_t : public BasePacket_t
{
    SetConfigPacket_t();
    SetConfigPacket_t(const std::vector<uint8_t> &bin);
    ~SetConfigPacket_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    std::string ns;
    std::string configName;
    std::string configValue;
};

#endif // SET_CONFIG_PACKET_H
