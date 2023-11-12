#include "DSS_Protocol.h"
#include "utils/ConvertPacket.h"

#include "packets/BootstrapPacket.h"

#include "packets/AliveNodeRequestPacket.h"
#include "packets/AliveNodeResponsePacket.h"

#include "packets/ChronoUpdateRequestPacket.h"
#include "packets/ChronoUpdateResponsePacket.h"

#include "packets/GetConfigPacketRequest.h"
#include "packets/GetConfigPacketResponse.h"
#include "packets/SetConfigPacket.h"

#include "packets/GetSensorsPacketRequest.h"
#include "packets/GetSensorsPacketResponse.h"
#include "packets/GetSensorDataPacketRequest.h"
#include "packets/GetSensorDataPacketResponse.h"
#include "packets/GetSensorHeaderPacketRequest.h"
#include "packets/GetSensorHeaderPacketResponse.h"
#include "packets/ClearSensorDataRequest.h"
#include "packets/SetSensorReadingModeRequest.h"

#include <iostream>

#ifndef DSS_PROTOCOL_TYPE_NUMBER
#define DSS_PROTOCOL_TYPE_NUMBER 12
#endif // DSS_PROTOCOL_TYPE_NUMBER

DSS_Protocol_t::DSS_Protocol_t() : packet(nullptr){};

DSS_Protocol_t DSS_Protocol_t::makeHeaderDataOnly(const std::vector<uint8_t> &bin)
{
    DSS_Protocol_t result;

    uint32_t currentIndex = 0;

    // source MAC
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, MAC_ADDRESS_LENGTH, result.sourceMAC))
        return DSS_Protocol_t();
    currentIndex += MAC_ADDRESS_LENGTH;

    // destination MAC
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, MAC_ADDRESS_LENGTH, result.destinationMAC))
        return DSS_Protocol_t();
    currentIndex += MAC_ADDRESS_LENGTH;

    // type
    if (ConvertPacket::getFromBin(bin, currentIndex, result.type))
        return DSS_Protocol_t();
    // no needing
    // currentIndex += sizeof(type);

    return result;
}

DSS_Protocol_t::DSS_Protocol_t(const PacketType_t packetType) : packet(nullptr)
{
    type = (uint8_t)packetType;

    packet = makePacket(packetType);
    if (packet == nullptr)
    {
        std::cerr << "An error occured during an ExchangeProtocol object construction" << std::endl;
        return;
    }
}

DSS_Protocol_t::DSS_Protocol_t(const std::vector<uint8_t> &bin)
{
    if (bin.empty())
        return;

    if (DSS_Protocol_t::fromBin(bin))
    {
        std::cerr << "An error occured during an ExchangeProtocol object construction" << std::endl;
        return;
    }
}

DSS_Protocol_t::~DSS_Protocol_t()
{
    if (packet)
        delete packet;
}

BasePacket_t *DSS_Protocol_t::makePacket(const PacketType_t packetType)
{
    BasePacket_t *ptrRet = nullptr;

    switch (packetType)
    {
    case BootstrapPacket:
        ptrRet = new BootstrapPacket_t;
        break;

    case AliveNodeRequestPacket:
        ptrRet = new AliveNodeRequestPacket_t;
        break;

    case AliveNodeResponsePacket:
        ptrRet = new AliveNodeResponsePacket_t;
        break;

    case ChronoUpdateRequestPacket:
        ptrRet = new ChronoUpdateRequestPacket_t;
        break;

    case ChronoUpdateResponsePacket:
        ptrRet = new ChronoUpdateResponsePacket_t;
        break;

    case GetConfigPacketRequest:
        ptrRet = new GetConfigPacketRequest_t;
        break;

    case GetConfigPacketResponse:
        ptrRet = new GetConfigPacketResponse_t;
        break;

    case SetConfigPacket:
        ptrRet = new SetConfigPacket_t;
        break;

    case GetSensorsPacketRequest:
        ptrRet = new GetSensorsPacketRequest_t;
        break;

    case GetSensorsPacketResponse:
        ptrRet = new GetSensorsPacketResponse_t;
        break;

    case GetSensorDataPacketRequest:
        ptrRet = new GetSensorDataPacketRequest_t;
        break;

    case GetSensorDataPacketResponse:
        ptrRet = new GetSensorDataPacketResponse_t;
        break;

    case GetSensorHeaderPacketRequest:
        ptrRet = new GetSensorHeaderPacketRequest_t;
        break;

    case GetSensorHeaderPacketResponse:
        ptrRet = new GetSensorHeaderPacketResponse_t;
        break;

    case ClearSensorDataRequest:
        ptrRet = new ClearSensorDataRequest_t;
        break;

    case SetSensorReadingModeRequest:
        ptrRet = new SetSensorReadingModeRequest_t;
        break;

    default:
        break;
    }

    return ptrRet;
}

BasePacket_t *DSS_Protocol_t::makePacketFromBin(const PacketType_t packetType, const std::vector<uint8_t> &bin)
{
    BasePacket_t *ptrRet = nullptr;

    std::vector<uint8_t> packetBin(bin.begin() + MAC_ADDRESS_LENGTH + MAC_ADDRESS_LENGTH + sizeof(type), bin.end());
    switch (packetType)
    {
    case BootstrapPacket:
        ptrRet = new BootstrapPacket_t(packetBin);
        break;

    case AliveNodeRequestPacket:
        ptrRet = new AliveNodeRequestPacket_t(packetBin);
        break;

    case AliveNodeResponsePacket:
        ptrRet = new AliveNodeResponsePacket_t(packetBin);
        break;

    case ChronoUpdateRequestPacket:
        ptrRet = new ChronoUpdateRequestPacket_t(packetBin);
        break;

    case ChronoUpdateResponsePacket:
        ptrRet = new ChronoUpdateResponsePacket_t(packetBin);
        break;

    case GetConfigPacketRequest:
        ptrRet = new GetConfigPacketRequest_t(packetBin);
        break;

    case GetConfigPacketResponse:
        ptrRet = new GetConfigPacketResponse_t(packetBin);
        break;

    case SetConfigPacket:
        ptrRet = new SetConfigPacket_t(packetBin);
        break;

    case GetSensorsPacketRequest:
        ptrRet = new GetSensorsPacketRequest_t(packetBin);
        break;

    case GetSensorsPacketResponse:
        ptrRet = new GetSensorsPacketResponse_t(packetBin);
        break;

    case GetSensorDataPacketRequest:
        ptrRet = new GetSensorDataPacketRequest_t(packetBin);
        break;

    case GetSensorDataPacketResponse:
        ptrRet = new GetSensorDataPacketResponse_t(packetBin);
        break;

    case GetSensorHeaderPacketRequest:
        ptrRet = new GetSensorHeaderPacketRequest_t(packetBin);
        break;

    case GetSensorHeaderPacketResponse:
        ptrRet = new GetSensorHeaderPacketResponse_t(packetBin);
        break;

    case ClearSensorDataRequest:
        ptrRet = new ClearSensorDataRequest_t(packetBin);
        break;

    case SetSensorReadingModeRequest:
        ptrRet = new SetSensorReadingModeRequest_t(packetBin);
        break;

    default:
        break;
    }

    return ptrRet;
}

int DSS_Protocol_t::getPacketSize()
{
    return sourceMAC.size() + destinationMAC.size() + sizeof(type) + packet->getPacketSize();
}

int DSS_Protocol_t::fromBin(const std::vector<uint8_t> &bin)
{
    uint32_t currentIndex = 0;

    // source MAC
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, MAC_ADDRESS_LENGTH, sourceMAC))
        return -1;
    currentIndex += MAC_ADDRESS_LENGTH;

    // destination MAC
    if (ConvertPacket::getVariableDataFromBin(bin, currentIndex, MAC_ADDRESS_LENGTH, destinationMAC))
        return -1;
    currentIndex += MAC_ADDRESS_LENGTH;

    // type
    if (ConvertPacket::getFromBin(bin, currentIndex, type))
        return -1;
    currentIndex += sizeof(type);

    // packet
    if (packet)
    {
        delete packet;
        packet = nullptr;
    }

    std::vector<uint8_t> bin_packet;
    std::move(bin.begin() + currentIndex, bin.end(), std::back_inserter(bin_packet));
    packet = makePacketFromBin((PacketType_t)type, bin);
    // no needing
    // currentIndex += MAC_ADDRESS_LENGTH;

    if (packet == nullptr)
        return -1;

    return 0;
}

int DSS_Protocol_t::toBin(std::vector<uint8_t> &bin) const
{
    bin.clear();

    ConvertPacket::addVariableDataToBin(bin, sourceMAC);
    ConvertPacket::addVariableDataToBin(bin, destinationMAC);
    ConvertPacket::addToBin(bin, type);

    packet->toBin(bin);

    return 0;
}
