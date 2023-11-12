#ifndef GET_SENSOR_DATA_PACKET_RESPONSE_H
#define GET_SENSOR_DATA_PACKET_RESPONSE_H

#include "BasePacket.h"
#include <string>
#include <vector>

struct GetSensorDataPacketResponse_t : public BasePacket_t
{
    GetSensorDataPacketResponse_t();
    GetSensorDataPacketResponse_t(const std::vector<uint8_t> &bin);
    ~GetSensorDataPacketResponse_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;

    std::string sensorName;
    std::string dataName;

    uint8_t sizeTime;
    uint8_t sizeData;

    std::vector<time_t> dataTime;
    std::vector<uint8_t> dataValue;
};

#endif // GET_SENSOR_DATA_PACKET_RESPONSE_H