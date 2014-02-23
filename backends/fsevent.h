#include <CoreServices/CoreServices.h>

CFStringRef SetMonitoredPath(char *path);
FSEventStreamRef CreateStream(CFStringRef mypath);
void Init(FSEventStreamRef stream);

void mycallback(
                ConstFSEventStreamRef streamRef,
                void *clientCallBackInfo,
                size_t numEvents,
                void *eventPaths,
                const FSEventStreamEventFlags eventFlags[],
                const FSEventStreamEventId eventIds[]
                );
