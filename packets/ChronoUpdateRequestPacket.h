#ifndef CHRONO_UPDATE_REQUEST_PACKET_H
#define CHRONO_UPDATE_REQUEST_PACKET_H

#include "BasePacket.h"

struct ChronoUpdateRequestPacket_t : public BasePacket_t
{
    ChronoUpdateRequestPacket_t();
    ChronoUpdateRequestPacket_t(const std::vector<uint8_t> &bin);
    ~ChronoUpdateRequestPacket_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;

    uint64_t oldTime;
};

#endif // CHRONO_UPDATE_REQUEST_PACKET_H
