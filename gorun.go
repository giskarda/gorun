package main

import (
	"flag"
	"log"
	"runtime"

	"github.com/giskarda/gorun/backends"
)

var (
	verbose = flag.Bool("verbose", false, "Run gorun in verbose mode")

	path    = flag.String("path", "/tmp", "Monitored path")
	cmd     = flag.String("cmd", "go build", "Perform command on any file change")
)


func main() {
	flag.Parse()

	gorunconfig := backends.GorunConfig{}
	gorunconfig.MonitoredPath = path
	gorunconfig.Cmd = cmd

	log.Println("Starting gorun")
	switch goos := runtime.GOOS; {
	case "darwin" == goos:
		log.Println("OS: Darwin")
		backends.RunDarwin(gorunconfig)
	default:
		log.Fatal("Couldn't identify OperatingSystem via runtime.GOOS")
	}
}
