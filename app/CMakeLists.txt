add_executable(race_cli main.cpp)
target_link_libraries(race_cli PRIVATE racecore)

set_target_properties(race_cli PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
