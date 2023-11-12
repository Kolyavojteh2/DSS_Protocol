#ifndef GET_SENSOR_DATA_PACKET_REQUEST_H
#define GET_SENSOR_DATA_PACKET_REQUEST_H

#include "BasePacket.h"
#include <string>
#include <vector>

struct GetSensorDataPacketRequest_t : public BasePacket_t
{
    GetSensorDataPacketRequest_t();
    GetSensorDataPacketRequest_t(const std::vector<uint8_t> &bin);
    ~GetSensorDataPacketRequest_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;

    std::string sensorName;
    std::string dataName;

    time_t timeFrom;
    time_t timeTo;
};

#endif // GET_SENSOR_DATA_PACKET_REQUEST_H