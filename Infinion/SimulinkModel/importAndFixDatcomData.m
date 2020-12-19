function aero = importAndFixDatcomData()

    % it sucks that this file has to exist, but fact is that datcom isn't all that consistant. Sometimes it produces data, sometimes not.
    % in the case it doesent, this file just fills in the missing values with those of their closest neighbours.
    % So for example, if the yaw coefficient for altitude of 100 m was present but the one for 120m wasn't, we would fill in that value with the one for 100m.

    aero=datcomimport("../datcomFiles/datcom.out")

    aerotab = {'cnb', 'cyb'};
    for k = 1:length(aerotab)
        for m = 1:aero{1}.nmach
            for h = 1:aero{1}.nalt
                aero{1}.(aerotab{k})(:,m,h) = aero{1}.(aerotab{k})(1,m,h);
            end
        end
    end

    for h = 1:aero{1}.nalt
        for m = 1:aero{1}.nmach
            for k = 1:(aero{1}.nalpha - 1)
                if(isnan(aero{1}.cm(k+1,m,h)))
                    aero{1}.cm(k+1,m,h) = aero{1}.cm(k,m,h)
                end
            end
        end
    end

    for h = 1:aero{1}.nalt
        for m = 1:aero{1}.nmach
            for k = 1:(aero{1}.nalpha - 1)
                if(isnan(aero{1}.xcp(k+1,m,h)))
                    aero{1}.xcp(k+1,m,h) = aero{1}.xcp(k,m,h)
                end
            end
        end
    end

    for h = 1:aero{1}.nalt
        for m = 1:aero{1}.nmach
            for k = 1:(aero{1}.nalpha - 1)
                if(isnan(aero{1}.cma(k+1,m,h)))
                    aero{1}.cma(k+1,m,h) = aero{1}.cma(k,m,h)
                end
            end
        end
    end



    % correct the coefficients of yaw (which datcom thinks are coefficients of pitch)
    for k = 1:(aero{3}.ndelta)
        if(isnan(aero{3}.dcm_sym(k,3,1)))
            aero{3}.dcm_sym(k,3,1) = aero{3}.dcm_sym(k,2,1)
        end
    end
    aero{3}.dcm_sym(:,:,2) = aero{3}.dcm_sym(:,:,1)
    aero{3}.dcm_sym(:,:,3) = aero{3}.dcm_sym(:,:,1)


end
