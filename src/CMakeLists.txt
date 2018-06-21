
add_library(system.net
    http/HttpListener.cpp
    ../include/system.net/HttpListener.h
    http/HttpListenerContext.cpp
    ../include/system.net/HttpListenerContext.h
    http/HttpListenerResponse.cpp
    ../include/system.net/HttpListenerResponse.h
    http/HttpListenerRequest.cpp
    ../include/system.net/HttpListenerRequest.h
    http/HttpListenerException.cpp
    ../include/system.net/HttpListenerException.h
    )

target_compile_features(system.net
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    PRIVATE cxx_thread_local
    )

target_include_directories(system.net
    PUBLIC
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ../include
    )

install(
    TARGETS
        system.net
    EXPORT
        system.net
    DESTINATION
        "lib"
    )

install(
    FILES
        ${system.net_SOURCE_DIR}/include/system.net/HttpListener.h
        ${system.net_SOURCE_DIR}/include/system.net/HttpListenerContext.h
        ${system.net_SOURCE_DIR}/include/system.net/HttpListenerException.h
        ${system.net_SOURCE_DIR}/include/system.net/HttpListenerRequest.h
        ${system.net_SOURCE_DIR}/include/system.net/HttpListenerResponse.h
    DESTINATION
        "include/system.net"
    )

install(
    EXPORT
        system.net
    FILE
        system.net-config.cmake
    DESTINATION
        "cmake"
    )
