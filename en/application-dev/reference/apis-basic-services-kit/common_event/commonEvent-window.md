# Common Events of the Window Management Subsystem
This document lists the common system events provided by the window management subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_SPLIT_SCREEN<sup>10+</sup>
Indicates a screen splitting action.

- Value: usual.event.SPLIT_SCREEN
- Required subscriber permissions: none

When any of the following actions is performed, the event notification service is triggered to publish this event: accessing the recent tasks screen, creating a split-screen bar, and destroying a split-screen bar.
