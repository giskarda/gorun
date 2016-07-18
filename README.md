# gorun
sbt ~action implementation in go

## Whats that:

`~`$action in an sbt world (but I presume it might have stolen or used by other project) is a way to tell the tool (most probably the compiler part not the repl part in this case) to reload itself when files on disk (usually CWD and below). $action is the command to run after.

## Implemented

Only the OS X backend has been partially written. It lacks of the reload feature but it's following FS changes from the kernel event queue.

## Notes:

this is a toy to play with the C integration in GO. The only reason to exists its because it might help others to see how to include C code in Go project and maybe in how to use the FSEvent stream api of OSX.
