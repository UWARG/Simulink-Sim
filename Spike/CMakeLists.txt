cmake_minimum_required(VERSION 3.2.0)
project(Testing C CXX ASM)

set(CMAKE_CXX_STANDARD 11)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/ZeroPilotSwHooks/
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/extern/include
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/rtw/c/src
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/rtw/c/src/ext_mode/common
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/R2018b/simulink/include
  ${CMAKE_CURRENT_SOURCE_DIR}/../../ZeroPilot-SW/Autopilot/AttitudeManager
  ${CMAKE_CURRENT_SOURCE_DIR}/../../ZeroPilot-SW/Autopilot/Inc

)

# Collect all our source files
set(CXX_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/ZeroPilotSwHooks/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ZeroPilotSwHooks/SendToSafetyIntercept.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ZeroPilotSwHooks/AirspeedSensorIntercept.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/Spike.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rt_nonfinite.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rtGetNaN.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCCode/SimulinkModel/Spike_grt_rtw/rtGetInf.cpp
)

###### THESE FOLDERS SHOULD BE CREATED INSIDE THE DIRECTORY WHERE THE FINAL EXE IS RUN FROM
add_custom_target(make-results-dir ALL
  COMMAND ${CMAKE_COMMAND} -E make_directory "SimulationResults")
add_custom_target(make-ActuatorCommand-dir ALL
  COMMAND ${CMAKE_COMMAND} -E make_directory "SimulationResults/ActuatorCommands")
add_custom_target(make-SensorOutput-dir ALL
  COMMAND ${CMAKE_COMMAND} -E make_directory "SimulationResults/SensorOutputs")

add_executable(attempt ${CXX_SOURCES})

target_link_libraries(attempt m)



#### INSTRUCTIONS!!!!

# create a build folder in the same folder as this file.
# cd into that build folder
# run "cmake .."
# run "make"
# copy the executable "attempt" into Spike/SimulationResults
# run it with ./attempt


# you can see the results of various positions of the aircraft as time goes by in the various files in Spike/SimulationResults/SensorOutputs
# To change the elevator/aileron/throttle inputs, change the input array in Spike/ZeroPilotSwHooks/main.cpp


# for the person integrating this into our ZeroPilot software, get rid of main.cpp and all the .hpp files in the ZeroPilotSwHooks directory.
# uncomment the code in airspeedIntercept.cpp

# you'l have to rig another Cmake job triggered by the build script in Autopilot (maybe add a -s option for simulate).
#add this derived class interface to the SendToSafety.hpp file:

##ifdef SIMULATION
#// This derived class hooks into the Simulink simulation rather than hardware
#class SimulatedIMU : public IMU
#{
#    public :
#        void Init();
#        void Begin_Measuring();
#        void GetResult(IMUData_t *Data);
#    private:
#        float getNewestDataPoint(const char * fileName);
#};
##endif



# Maybe with a define or something defined globally (the SIMULATION define perhaps), the code callingthe Send to safety module will need to "hook into" this derived class rather than the real one.

#For the imu and airspeed sensor files, you'l just need to link in the intercept files I've provided here instead of the real implementations.
