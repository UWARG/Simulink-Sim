function asbhl20()
% This function creates a local working copy of the HL-20 project example

% Copyright 2014-2015 The MathWorks, Inc.

[projectFolder, ~] = matlab.internal.project.example.projectDemoSetUp( ...
       fullfile(matlabroot,'toolbox','aeroblks','aerodemos','asbhl20.zip'),...
            [], []);
        
% Depending on whether or not Stateflow is installed and a license is
% available, the corresponding Fault Detection variant is selected.
origpath = pwd;
cd(fullfile(projectFolder, 'controller'));
sfDictionaryObj = Simulink.data.dictionary.open('asbhl20_FDIRAppData.sldd');
sfDataSectObj = getSection(sfDictionaryObj,'Design Data');
installedProducts = ver;
stateflowFlag = false;
for k=1:length(installedProducts)
    if strcmp(installedProducts(k).Name,'Stateflow')
        testLicense = builtin('license','test','Stateflow');
        if testLicense
            stateflowFlag = true;
        end
    end
end

if stateflowFlag
    evalin(sfDataSectObj,'VSS_MODELLOGIC = 1;');       % 0 - No FDIRApp logic
                                                       % 1 - Model Reference
else
    evalin(sfDataSectObj,'VSS_MODELLOGIC = 0;');       % 0 - No FDIRApp logic
                                                       % 1 - Model Reference
end
saveChanges(sfDictionaryObj);
close(sfDictionaryObj);
cd(origpath);
                                       
simulinkproject(projectFolder);

end