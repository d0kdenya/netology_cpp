file(GLOB SRC
        src/*.cpp
        src/transport/*.cpp)

add_library(racecore SHARED ${SRC})

target_include_directories(racecore PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(racecore PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY         ${CMAKE_BINARY_DIR}/bin
        ARCHIVE_OUTPUT_DIRECTORY         ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)  # <—

set_target_properties(racecore PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON)
