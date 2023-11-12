#ifndef GET_SENSOR_HEADER_PACKET_REQUEST_H
#define GET_SENSOR_HEADER_PACKET_REQUEST_H

#include "BasePacket.h"
#include <string>

struct GetSensorHeaderPacketRequest_t : public BasePacket_t
{
    GetSensorHeaderPacketRequest_t();
    GetSensorHeaderPacketRequest_t(const std::vector<uint8_t> &bin);
    ~GetSensorHeaderPacketRequest_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;

    std::string sensorName;
};

#endif // GET_SENSOR_HEADER_PACKET_REQUEST_H