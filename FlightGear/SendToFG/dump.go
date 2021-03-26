package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"net"
	"strconv"
	"strings"
	"time"
)

const ( //defaults
	DEF_HOST                 string = "127.0.0.1"
	DEF_PORT                 int    = 5500
	DEF_LOCATION             string = "SimulationBuild/SensorOutputs/"
	DEF_TIME_BETWEEN_PACKETS int    = 20
	DEF_DEBUG                bool   = false
)

var (
	debug              bool
	host               string
	port               int
	loc                string
	timeBetweenPackets int
	packets            []string
)

func main() {

	log.Println("parsing flags")
	setFlags()
	log.Println("getting data")
	getData()
	log.Println("sending data")
	sendData()
	log.Println("data sent")
}

func setFlags() {

	flag.StringVar(&host, "hostname", DEF_HOST, "should be local machine for our purposes")
	flag.IntVar(&port, "port", DEF_PORT, "port on destination to send data to")
	flag.BoolVar(&debug, "debug", DEF_DEBUG, "prints out data in debug mode")
	flag.StringVar(&loc, "location", DEF_LOCATION, "location from local position where the sim data is")
	flag.IntVar(&timeBetweenPackets, "time", DEF_TIME_BETWEEN_PACKETS, "time between packets in ms")

	flag.Parse()
	if debug {
		log.Println("debug", debug)
		log.Println("location", loc)
		log.Println("time between packets", timeBetweenPackets)
		log.Println("host", host)
		log.Println("port", port)
	}
}

func getData() {

	data, err := ioutil.ReadFile(loc + "roll.txt")
	check(err)
	rollData := strings.Split(string(data), "\n")

	data, err = ioutil.ReadFile(loc + "pitch.txt")
	check(err)
	pitchData := strings.Split(string(data), "\n")

	data, err = ioutil.ReadFile(loc + "yaw.txt")
	check(err)
	yawData := strings.Split(string(data), "\n")

	data, err = ioutil.ReadFile(loc + "latitude.txt")
	check(err)
	latData := strings.Split(string(data), "\n")

	data, err = ioutil.ReadFile(loc + "longitude.txt")
	check(err)
	longData := strings.Split(string(data), "\n")

	data, err = ioutil.ReadFile(loc + "altitude.txt")
	check(err)
	altData := strings.Split(string(data), "\n")

	for i := 0; i < len(rollData)-1; i++ {

		var roll float64
		roll, err = strconv.ParseFloat(rollData[i], 32)
		check(err)

		var pitch float64
		pitch, err = strconv.ParseFloat(pitchData[i], 32)
		check(err)

		var yaw float64
		yaw, err = strconv.ParseFloat(yawData[i], 32)
		check(err)

		var lat float64
		lat, err = strconv.ParseFloat(latData[i], 32)
		check(err)

		var long float64
		long, err = strconv.ParseFloat(longData[i], 32)
		check(err)

		var alt float64
		alt, err = strconv.ParseFloat(altData[i], 32)
		check(err)

		packets = append(packets, fmt.Sprintf("%.2f,%.6f,%.6f,%.2f,%.2f,%.2f,\n", alt, lat, long, roll, pitch, yaw))

		if debug {
			log.Println("read ", packets[len(packets)-1])
		}
	}
}

func sendData() {
	sPort := fmt.Sprintf("%d", port)
	dest, _ := net.ResolveUDPAddr("udp", host+":"+sPort)
	conn, err := net.DialUDP("udp", nil, dest)
	check(err)
	defer conn.Close()

	for _, msg := range packets {
		_, err = conn.Write([]byte(msg))
		check(err)
		time.Sleep(time.Duration(timeBetweenPackets) * time.Millisecond)

		if debug {
			log.Println("sent ", msg, "to ", host, ":", port)
		}
	}

}

func check(err error) {
	if err != nil {
		panic(err)
	}
}
