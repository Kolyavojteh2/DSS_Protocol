cmake_minimum_required(VERSION 3.5)

project(DSS_Protocol LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DSS_Protocol
    main.cpp

    DSS_Protocol.h
    DSS_Protocol.cpp

    packets/BasePacket.h

    utils/ConvertPacket.cpp
    utils/ConvertPacket.h

    packets/BootstrapPacket.cpp
    packets/BootstrapPacket.h

    packets/AliveNodeRequestPacket.cpp
    packets/AliveNodeRequestPacket.h

    packets/AliveNodeResponsePacket.cpp
    packets/AliveNodeResponsePacket.h
)

target_include_directories(DSS_Protocol PUBLIC
    ${CMAKE_SOURCE_DIR}/
)

install(TARGETS DSS_Protocol
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
