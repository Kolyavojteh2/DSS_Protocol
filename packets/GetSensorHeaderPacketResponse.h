#ifndef GET_SENSOR_HEADER_PACKET_RESPONSE_H
#define GET_SENSOR_HEADER_PACKET_RESPONSE_H

#include "BasePacket.h"
#include <string>

struct GetSensorHeaderPacketResponse_t : public BasePacket_t
{
    GetSensorHeaderPacketResponse_t();
    GetSensorHeaderPacketResponse_t(const std::vector<uint8_t> &bin);
    ~GetSensorHeaderPacketResponse_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    std::string sensorName;
    std::vector<std::string> sensorDataNames;
};

#endif // GET_SENSOR_HEADER_PACKET_RESPONSE_H