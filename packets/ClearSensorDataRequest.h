#ifndef CLEAR_SENSOR_DATA_REQUEST_H
#define CLEAR_SENSOR_DATA_REQUEST_H

#include "BasePacket.h"

#include <string>
#include <vector>

struct ClearSensorDataRequest_t : public BasePacket_t
{
    ClearSensorDataRequest_t();
    ClearSensorDataRequest_t(const std::vector<uint8_t> &bin);
    ~ClearSensorDataRequest_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    int getPacketSize() override;

    std::string sensorName;
    std::string dataName;

    time_t timeFrom;
    time_t timeTo;
};

#endif // CLEAR_SENSOR_DATA_REQUEST_H
