%% HL-20 Project with Optional FlightGear Interface
% This project shows how to model NASA's HL-20 lifting body with Simulink(R), 
% Stateflow(R) and Aerospace Blockset(TM) software. The vehicle model includes the aerodynamics, 
% control logic, fault management systems (FDIR), and engine controls (FADEC). It 
% also includes effects of the environment, such as wind profiles for the landing 
% phase. The entire model simulates approach and landing flight phases using an 
% auto-landing controller. To analyze the effects of actuator failures and wind gust variation
% on the stability of the vehicle, use the  "Run Failure Analysis in Parallel" project shortcut.
% If Parallel Computing Toolbox(TM) is installed, the analysis is run in parallel.
% If Parallel Computing Toolbox(TM) is not installed, the analysis is run in serial.
% Visualization for this model is done via an interface to FlightGear, an open source flight
% simulator package. If the FlightGear interface is unavailable, you can simulate the model
% by closing the loop using the alternative data sources provided in the Variant block. In
% this block, you can choose a previously saved data file, a Signal Editor
% block, or a set of constant values. This example requires Control System Toolbox(TM).
                        
% Copyright 2007-2018 The MathWorks, Inc.
                        
%% FlightGear Interface
% For more information on the FlightGear interface, read these documentation topics:
%
% * <matlab:helpview([docroot,'/toolbox/aeroblks/aeroblks.map'],'flight_gear_install') Installing the Flight Simulator>
% * <matlab:helpview([docroot,'/toolbox/aeroblks/aeroblks.map'],'flight_gear_simulate') Working with the Flight Simulator Interface>
% * <matlab:helpview([docroot,'/toolbox/aeroblks/aeroblks.map'],'hl20_flight_gear_help') Modeling the HL20 with the Flight Simulator>
%
% For a more detailed description of this model components, view a recorded 
% navigation through the model using this link:
%
% * <matlab:web('https://www.mathworks.com/videos/spacecraft-automated-landing-system-68869.html') NASA HL-20 WebEx Recording>

%% NASA HL-20 Background
% The HL-20, also known as personnel launch system (PLS), is a lifting body re-entry 
% vehicle that was designed to complement the Space Shuttle orbiter. Designed to 
% carry up to ten people and very little cargo[1], the HL-20 lifting body was to 
% be placed in orbit either launched vertically via booster rockets or 
% transported in the payload bay of the Space Shuttle orbiter. HL-20 lifting body 
% was designed to have a powered deorbiting accomplished with an onboard 
% propulsion system while its reentry was to be nose-first, horizontal and 
% unpowered.
%
% The HL-20 lifting body was developed as a low cost solution for getting to and 
% from low Earth orbit. The proposed benefits of the HL-20 were reduced operating 
% costs due to rapid turnaround between landing and launch, improved flight 
% safety, and ability to land conventionally on runways. Potential scenarios for 
% the HL-20 were orbital rescue of stranded astronauts, International Space 
% Station crew exchange if the Space Shuttle orbiter was not available, 
% observation missions, and satellite servicing missions.

%% Opening HL-20 Project
%
% Run the following command to create and open a working copy of the project 
% files for this example.
%
% <matlab:asbhl20 |asbhl20|>
%
% <<asbhl20landing.png>>
%
% For more information on using Simulink Projects and HL-20, see:
%
% * <matlab:web('https://www.mathworks.com/content/dam/mathworks/tag-team/Objects/a/73194-integrated-project-management-tool-final.pdf') Tamayo S., Gage S., Walker G., "Integrated Project Management Tool for Modeling Simulation of Complex Systems" AIAA Modeling and Simulation  Technologies Conference (August 2012)>

%% Additional Information About NASA HL-20
%
% [1] Jackson E. B., Cruz C. L., "Preliminary Subsonic Aerodynamic Model for 
% Simulation Studies of the HL-20 Lifting Body," NASA TM4302 (August 1992)


displayEndOfDemoMessage(mfilename)
