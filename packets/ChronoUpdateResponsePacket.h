#ifndef CHRONO_UPDATE_RESPONSE_PACKET_H
#define CHRONO_UPDATE_RESPONSE_PACKET_H

#include "BasePacket.h"

struct ChronoUpdateResponsePacket_t : public BasePacket_t
{
    ChronoUpdateResponsePacket_t();
    ChronoUpdateResponsePacket_t(const std::vector<uint8_t> &bin);
    ~ChronoUpdateResponsePacket_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    uint64_t newTime;
};

#endif // CHRONO_UPDATE_RESPONSE_PACKET_H
