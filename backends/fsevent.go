package backends

import (
	"log"
)
/*
#cgo CFLAGS: -Wno-format
#cgo LDFLAGS: -framework CoreServices
#include "stdio.h"
#include "fsevent.h"
*/
import "C"

func RunDarwin(gorunconfig GorunConfig) {

	path := C.CString(*gorunconfig.MonitoredPath)
	mypath := C.SetMonitoredPath(path)
	mystream := C.CreateStream(mypath)

	log.Println("Init FSEvent loop")
	C.Init(mystream)
}
