
if (HTTP_EXAMPLE)
    add_executable(system.net.example1
        example1.cpp
        )

    target_compile_features(system.net.example1
        PRIVATE cxx_auto_type
        PRIVATE cxx_nullptr
        PRIVATE cxx_range_for
        PRIVATE cxx_thread_local
        )

    target_include_directories(system.net.example1
        PUBLIC
            ../include
        )

    target_link_libraries(system.net.example1
        system.net ws2_32
        )
endif()
