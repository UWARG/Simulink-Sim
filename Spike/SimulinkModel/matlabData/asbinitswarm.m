function out = asbinitswarm(str,num_ac)
% OUT = ASBINITSWARM(STR,NUM_AC)
%
% ASBINITSWARM will initialize a given input parameter that is
% defined by STR.  NUM_AC represents the number of aircraft
% in a particular formation

%   Copyright 2000-2016 The MathWorks, Inc.

global tau_t tau_b tau_n minimum_ac_dist minimum_obs_dist desired_vel
global target_cone vel_ic state_ic
global rho S Cd0 k W


strlist = {'tau','minimum_ac_dist','minimum_obs_dist', 'desired_vel',...
           'targetcone_limit','state_ic','gam_ic','V_ic','chi_ic',...
           'x_ic','y_ic','h_ic'};

if nargin ~= 2
    error(message('aeroblks:asbinitswarm:numargs'));
elseif ~ischar(str) && ~isstring(str)
    error(message('aeroblks:asbinitswarm:notchar'))
elseif ~ismember(str,strlist)
    error(message('aeroblks:asbinitswarm:noinitialization'))
end

switch str
case 'tau' % will initialize time constant array
           % [tau_t tau_b tau_n] x number of aircraft
    out = ones(num_ac,1)*[tau_t tau_b tau_n];
case 'minimum_ac_dist'
    out = ones(num_ac,1)*minimum_ac_dist;
case 'minimum_obs_dist'
    out = ones(num_ac,1)*minimum_obs_dist;
case 'desired_vel'
    out = ones(num_ac,1)*desired_vel;
case 'targetcone_limit'
    out = ones(num_ac,1)*target_cone;
case 'state_ic'
    % initial thrust will offset drag for each aircraft
    Cl = 2*W/(rho*vel_ic^2*S);
    Cd = Cd0+k*Cl^2;
    thrust_ic = 0.5*rho*vel_ic^2*S*Cd;
    % state vector [thrust mu loadfactor]
    out = [thrust_ic; 0; 1]*ones(1,num_ac);
case 'gam_ic'
    % state vector [gam]
    out = zeros(1,num_ac);
case 'V_ic'
    % state vector [V]
    out = vel_ic*ones(1,num_ac);
case 'chi_ic'
    % state vector [chi]
    out = zeros(1,num_ac);
case 'x_ic'
    state = [0 -state_ic.deltax_ic -state_ic.deltax_ic];
    bias = [0 0 0];
    % state vector [x]
    out = fillarray(num_ac,state,bias);
case 'y_ic'
    state = [0               -state_ic.deltay_ic state_ic.deltay_ic];
    bias = [state_ic.biasy_ic state_ic.biasy_ic  state_ic.biasy_ic];
    % state vector [y]
    out = fillarray(num_ac,state,bias);
case 'h_ic'
    state = [0 -state_ic.deltah_ic -state_ic.deltah_ic];
    bias = [state_ic.h_ic state_ic.h_ic state_ic.h_ic];
    % state vector [h]
    out = fillarray(num_ac,state,bias);
otherwise
    disp('Not initializing anything, outputting empty matrix');
    out=[];
end

end
%--------------------------------------------------------
function out = fillarray(num_ac,state,bias)
    out = zeros(1,num_ac);
    % lead aircraft index
    lead_index = ceil(num_ac/2);
    % lead aircraft
    out(:,lead_index) = state(1)+bias(1);
    % to the left of lead
    for i=1:lead_index-1
        out(:,lead_index-i) = i*state(2)+bias(2);
    end
    % to the right of lead
    for i=1:num_ac-lead_index
        out(:,lead_index+i) = i*state(3)+bias(3);
    end    
end
    
