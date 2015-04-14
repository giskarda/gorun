#include "stdio.h"
#include "fsevent_darwin.h"


CFStringRef SetMonitoredPath(char *path) {
  CFStringRef mypath =  CFStringCreateWithCStringNoCopy(NULL, path,
                                                        kCFStringEncodingUTF8, NULL);
  return mypath;
}


FSEventStreamRef CreateStream(CFStringRef mypath) {
  CFArrayRef pathsToWatch = CFArrayCreate(NULL, (const void **)&mypath, 1, NULL);
  void *callbackInfo = NULL;
  FSEventStreamRef stream;
  CFAbsoluteTime latency = 2.0;

  /* Create the stream, passing in a callback */
  stream = FSEventStreamCreate(NULL,
                               &mycallback,
                               callbackInfo,
                               pathsToWatch,
                               kFSEventStreamEventIdSinceNow, /* Or a previous event ID */
                               latency,
                               kFSEventStreamCreateFlagNone /* Flags explained in reference */
                               );

  return stream;
}

void mycallback(
                ConstFSEventStreamRef streamRef,
                void *clientCallBackInfo,
                size_t numEvents,
                void *eventPaths,
                const FSEventStreamEventFlags eventFlags[],
                const FSEventStreamEventId eventIds[])
{
  int i;
  char **paths = eventPaths;

  // printf("Callback called\n");
  for (i=0; i<numEvents; i++) {
    /* flags are unsigned long, IDs are uint64_t */
    printf("Change %llu in %s, flags %lu\n", eventIds[i], paths[i], eventFlags[i]);
  }
}

void Init(FSEventStreamRef stream){
  FSEventStreamScheduleWithRunLoop(stream, CFRunLoopGetCurrent(),         kCFRunLoopDefaultMode);
  FSEventStreamStart(stream);
  CFRunLoopRun();
}
