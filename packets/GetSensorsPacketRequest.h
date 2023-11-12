#ifndef GET_SENSORS_PACKET_REQUEST_H
#define GET_SENSORS_PACKET_REQUEST_H

#include "BasePacket.h"

struct GetSensorsPacketRequest_t : public BasePacket_t
{
    GetSensorsPacketRequest_t();
    GetSensorsPacketRequest_t(const std::vector<uint8_t> &bin);
    ~GetSensorsPacketRequest_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;
};

#endif // GET_SENSORS_PACKET_REQUEST_H