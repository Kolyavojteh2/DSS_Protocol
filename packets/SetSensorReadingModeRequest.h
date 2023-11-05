#ifndef SET_SENSOR_READING_MODE_REQUEST_H
#define SET_SENSOR_READING_MODE_REQUEST_H

#include "BasePacket.h"

#include <string>
#include <vector>

struct SetSensorReadingModeRequest_t : public BasePacket_t
{
    SetSensorReadingModeRequest_t();
    SetSensorReadingModeRequest_t(const std::vector<uint8_t> &bin);
    ~SetSensorReadingModeRequest_t() override;

    int fromBin(const std::vector<uint8_t> &bin) override;
    int toBin(std::vector<uint8_t> &bin) const override;

    uint8_t isCyclic;
    time_t period;
};

#endif // SET_SENSOR_READING_MODE_REQUEST_H
