cmake_minimum_required(VERSION 3.2.0)
project(Testing C CXX ASM)

set(CMAKE_CXX_STANDARD 11)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/extern/include
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/rtw/c/src
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/rtw/c/src/ext_mode/common
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/simulink/include

)

# Collect all our source files
set(CXX_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/ZeroPilotSwHooks/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ZeroPilotSwHooks/AirspeedSensorIntercept.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/Spike.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rt_nonfinite.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rtGetNaN.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rtGetInf.cpp
)

add_custom_target(make-results-dir ALL
  COMMAND ${CMAKE_COMMAND} -E make_directory "SimulationResults")
add_custom_target(make-ActuatorCommand-dir ALL
  COMMAND ${CMAKE_COMMAND} -E make_directory "SimulationResults/ActuatorCommands")
add_custom_target(make-SensorOutput-dir ALL
  COMMAND ${CMAKE_COMMAND} -E make_directory "SimulationResults/SensorOutputs")

# Link runTests with what we want to test and the GTest and pthread library
add_executable(attempt ${CXX_SOURCES})

target_link_libraries(attempt m)
