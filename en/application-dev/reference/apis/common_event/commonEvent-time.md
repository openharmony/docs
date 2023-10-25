# Common Events of the Time and Time Zone Subsystem
This document lists the common system events provided by the time and time zone subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_TIME_CHANGED
Indicates that the system time has been set.

- Value: usual.event.TIME_CHANGED
- Required subscriber permissions: none

When the system time is set, the event notification service is triggered to publish this event.

## COMMON_EVENT_TIME_TICK
Indicates that the system time has changed.

- Value: usual.event.TIME_TICK
- Required subscriber permissions: none

On devices where the unit of time is minutes, when the system time changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_TIMEZONE_CHANGED
Indicates that the system time zone has changed.

- Value: usual.event.TIMEZONE_CHANGED
- Required subscriber permissions: none

When the system time zone changes, the event notification service is triggered to publish this event.
