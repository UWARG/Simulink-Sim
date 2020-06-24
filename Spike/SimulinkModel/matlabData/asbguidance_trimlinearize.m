%% Airframe Trim and Linearize with Simulink(R) Control Design(TM)
% This example shows how to trim and linearize an airframe using 
% Simulink(R) Control Design(TM) software
%
% Designing an autopilot with classical design techniques requires linear 
% models of the airframe pitch dynamics for several trimmed flight 
% conditions. The MATLAB(R) technical computing environment can determine 
% the trim conditions and derive linear state-space models directly from the 
% nonlinear Simulink(R) and Aerospace Blockset(TM) model. This step saves time 
% and helps to validate the model. The Simulink Control Design functions allow 
% you to visualize the motion of the airframe in terms of open-loop frequency 
% or time responses.

% Copyright 1990-2016 The MathWorks, Inc.

%% Initialize Guidance Model
%
% The first problem is to find the elevator deflection, and the
% resulting trimmed body rate (q), which will generate a given
% incidence value when the missile is traveling at a set speed.
% Once the trim condition is found, a linear model can be derived
% for the dynamics of the perturbations in the states around 
% the trim condition. 

open_system('aeroblk_guidance_airframe');

%% Define State Values
%

h_ini     = 10000/m2ft;      % Trim Height [m]
M_ini     = 3;               % Trim Mach Number
alpha_ini = -10*d2r;         % Trim Incidence [rad]
theta_ini = 0*d2r;           % Trim Flightpath Angle [rad]
v_ini = M_ini*(340+(295-340)*h_ini/11000); 	% Total Velocity [m/s]

q_ini = 0;               % Initial pitch Body Rate [rad/sec]

%% Set Operating Point and State Specifications
%
% The first state specifications are Position states. The second state 
% specification is Theta. Both are known, but not at steady state. The 
% third state specifications are body axis angular rates, of which the 
% variable w is at steady state.
%

opspec = operspec('aeroblk_guidance_airframe');
opspec.State(1).Known = [1;1];
opspec.State(1).SteadyState = [0;0];
opspec.State(2).Known = 1;
opspec.State(2).SteadyState = 0;
opspec.State(3).Known = [1 1];
opspec.State(3).SteadyState = [0 1];

%% Search for Operating Point, Set I/O, Then Linearize
%

op = findop('aeroblk_guidance_airframe',opspec);

io(1) = linio('aeroblk_guidance_airframe/Fin Deflection',1,'input');
io(2) = linio('aeroblk_guidance_airframe/Selector',1,'output');
io(3) = linio(sprintf(['aeroblk_guidance_airframe/Aerodynamics &\n', ...
                    'Equations of Motion']),3,'output');

sys = linearize('aeroblk_guidance_airframe',op,io);

%% Select Trimmed States, Create LTI Object, and Plot Bode Response
%

% find index of desired states in the state vector
names = sys.StateName;
q_idx = find(strcmp('q',names));
az_idx = find(strcmp('U,w(2)',names));

airframe = ss(sys.A([az_idx q_idx],[az_idx q_idx]),sys.B([az_idx q_idx],:),sys.C(:,[az_idx q_idx]),sys.D);

set(airframe,'inputname',{'Elevator'}, ...
             'outputname',[{'az'} {'q'}]);

ltiview('bode',airframe);

displayEndOfDemoMessage(mfilename)
