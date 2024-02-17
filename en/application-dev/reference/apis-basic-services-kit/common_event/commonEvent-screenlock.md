# Common Events of the Theme Framework - Lock Screen
This document lists the common system events provided by the theme framework - lock screen to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_SCREEN_LOCKED
Indicates that the screen has been locked.

- Value: usual.event.SCREEN_LOCKED
- Required subscriber permissions: none

When the screen is locked, the event notification service is triggered to publish this event.

## COMMON_EVENT_SCREEN_UNLOCKED
Indicates that the screen has been unlocked.

- Value: usual.event.SCREEN_UNLOCKED
- Required subscriber permissions: none

When the screen is unlocked, the event notification service is triggered to publish this event.
