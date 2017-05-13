#ifndef MAIN_H_
#define MAIN_H_

#include "logger.h"
#include <unistd.h>
#include <ApplicationServices/ApplicationServices.h>

void tapKeyDownEvent();
CGEventRef onCapture(CGEventTapProxy, CGEventType, CGEventRef, void*);

#endif // MAIN_H_
