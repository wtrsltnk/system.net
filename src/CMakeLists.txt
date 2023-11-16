
add_library(system.net
    http/HttpListener.cpp
    http/HttpListenerContext.cpp
    http/HttpListenerResponse.cpp
    http/HttpListenerRequest.cpp
    http/HttpListenerException.cpp
    ../include/system.net/system.net.http.httplistener.h
    ../include/system.net/system.net.http.httplistenercontext.h
    ../include/system.net/system.net.http.httplistenerexception.h
    ../include/system.net/system.net.http.httplistenerrequest.h
    ../include/system.net/system.net.http.httplistenerresponse.h
    )

target_compile_features(system.net
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    PRIVATE cxx_thread_local
    )

target_include_directories(system.net
    PUBLIC
        $<BUILD_LOCAL_INTERFACE:${CMAKE_SOURCE_DIR}/include>
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
        ${system.net_SOURCE_DIR}/include/system.net/system.net.http.httplistener.h
        ${system.net_SOURCE_DIR}/include/system.net/system.net.http.httplistenercontext.h
        ${system.net_SOURCE_DIR}/include/system.net/system.net.http.httplistenerexception.h
        ${system.net_SOURCE_DIR}/include/system.net/system.net.http.httplistenerrequest.h
        ${system.net_SOURCE_DIR}/include/system.net/system.net.http.httplistenerresponse.h
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
