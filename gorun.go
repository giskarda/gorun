package main

import (
	"flag"
	"log"

	"github.com/giskarda/gorun/backends"
)

var (
	verbose = flag.Bool("verbose", false, "Run gorun in verbose mode")

	path = flag.String("path", "/tmp", "Monitored path")
	cmd  = flag.String("cmd", "go build", "Perform command on any file change")
)

func main() {
	flag.Parse()

	gorunconfig := backends.GorunConfig{}
	gorunconfig.MonitoredPath = path
	gorunconfig.Cmd = cmd

	log.Println("Starting gorun")
	backends.Run(gorunconfig)
}
