cmake_minimum_required(VERSION 3.2.0)
project(Testing C CXX ASM)


include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/extern/include
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/rtw/c/src
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/rtw/c/src/ext_mode/common
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/simulink/include

)

# Collect all our source files
set(C_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/ZeroPilotSwHooks/main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/Spike.c
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/Spike_data.c
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rt_nonfinite.c
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rtGetNaN.c
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rtGetInf.c
)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(attempt ${C_SOURCES})

target_link_libraries(attempt m)
