function aero = importAndFixDatcomData()

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


end
