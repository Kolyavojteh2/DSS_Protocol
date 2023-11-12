#ifndef GET_SENSORS_PACKET_RESPONSE_H
#define GET_SENSORS_PACKET_RESPONSE_H

#include "BasePacket.h"
#include <string>

struct GetSensorsPacketResponse_t : public BasePacket_t
{
    GetSensorsPacketResponse_t();
    GetSensorsPacketResponse_t(const std::vector<uint8_t> &bin);
    ~GetSensorsPacketResponse_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;

    std::vector<std::string> sensors;
};

#endif // GET_SENSORS_PACKET_RESPONSE_H
