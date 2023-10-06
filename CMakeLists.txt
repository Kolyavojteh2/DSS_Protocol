idf_component_register(
    SRCS
    "DSS_Protocol.cpp"

    "utils/ConvertPacket.cpp"

    "packets/BootstrapPacket.cpp"
    "packets/AliveNodeRequestPacket.cpp"
    "packets/AliveNodeResponsePacket.cpp"

    INCLUDE_DIRS
    "."
)
