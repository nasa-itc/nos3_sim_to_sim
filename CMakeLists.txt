project(subsim_sim)

find_package(ITC_Common REQUIRED QUIET COMPONENTS itc_logger)
find_package(NOSENGINE REQUIRED QUIET COMPONENTS common transport client uart)

include_directories(inc
                    ${sim_common_SOURCE_DIR}/inc
                    ${ITC_Common_INCLUDE_DIRS}
                    ${NOSENGINE_INCLUDE_DIRS})

set(subsim_sim_src
    src/subsim_hardware_model.cpp
    src/subsim_42_data_provider.cpp
    src/subsim_data_provider.cpp
    src/subsim_data_point.cpp
)

# For Code::Blocks and other IDEs
file(GLOB subsim_sim_inc inc/*.hpp)

set(subsim_sim_libs
    sim_common
    ${ITC_Common_LIBRARIES}
    ${NOSENGINE_LIBRARIES}
)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:$ORIGIN/../lib") # Pick up .so in install directory

add_library(subsim_sim SHARED ${subsim_sim_src} ${subsim_sim_inc})
target_link_libraries(subsim_sim ${subsim_sim_libs})
install(TARGETS subsim_sim LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
