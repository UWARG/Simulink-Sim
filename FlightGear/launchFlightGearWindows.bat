C:
cd C:\Program Files\FlightGear 2018.3.6

SET FG_ROOT=C:\Program Files\FlightGear 2018.3.6\data
.\\bin\fgfs --generic=socket,in,30,,5500,udp,WargFGPacketStructure --fdm=null --timeofday=noon --disable-real-weather-fetch --wind=0@0 --altitude=80 --lat=21.322 --lon=-157.924
