%% Airframe Trim and Linearize with Control System Toolbox(TM)
% This example shows how to trim and linearize an airframe in the 
% Simulink(R) environment using the Control System Toolbox(TM) software
%
% Designing an autopilot with classical design techniques requires linear 
% models of the airframe pitch dynamics for several trimmed flight 
% conditions. The MATLAB(R) technical computing environment can determine 
% the trim conditions and derive linear state-space models directly from the 
% nonlinear Simulink and Aerospace Blockset(TM) model. This step saves time 
% and helps to validate the model. The Control System Toolbox functions allow 
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

%% Find Names and Ordering of States from Simulink(R) Model
%

[sizes,x0,names]=aeroblk_guidance_airframe([],[],[],'sizes');

state_names = cell(1,numel(names));
for i = 1:numel(names)
  n = max(strfind(names{i},'/'));
  state_names{i}=names{i}(n+1:end);
end

%% Specify Which States to Trim and Which States Remain Fixed 
%

fixed_states            = [{'U,w'} {'Theta'} {'Position'}];
fixed_derivatives       = [{'U,w'} {'q'}];        % w and q
fixed_outputs           = [];                     % Velocity
fixed_inputs            = [];

n_states=[];n_deriv=[];
for i = 1:length(fixed_states)
  n_states=[n_states find(strcmp(fixed_states{i},state_names))]; %#ok<AGROW>
end
for i = 1:length(fixed_derivatives)
  n_deriv=[n_deriv find(strcmp(fixed_derivatives{i},state_names))]; %#ok<AGROW>
end
n_deriv=n_deriv(2:end);                          % Ignore U

%% Trim Model
%

[X_trim,U_trim,Y_trim,DX]=trim('aeroblk_guidance_airframe',x0,0,[0 0 v_ini]', ...
                               n_states,fixed_inputs,fixed_outputs, ...
                               [],n_deriv)  %#ok<NOPTS>

%% Derive Linear Model and View Frequency Response
%

[A,B,C,D]=linmod('aeroblk_guidance_airframe',X_trim,U_trim);
if exist('control','dir')
  airframe = ss(A(n_deriv,n_deriv),B(n_deriv,:),C([2 1],n_deriv),D([2 1],:));
  set(airframe,'StateName',state_names(n_deriv), ...
               'InputName',{'Elevator'}, ...
               'OutputName',[{'az'} {'q'}]);
  
  zpk(airframe)
  ltiview('bode',airframe)    
end

displayEndOfDemoMessage(mfilename)
