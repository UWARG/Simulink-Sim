
function C = lastStr2double(str)

s = deblank(str);

w = isspace(s);            

indexOfLastNum = find(w == 1, 1, 'last');

lastNum = extractAfter(s, indexOfLastNum);

C = real(str2double(lastNum));
