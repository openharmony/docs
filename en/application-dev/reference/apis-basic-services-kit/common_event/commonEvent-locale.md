# Common Events of the Language Subsystem
 This document lists the common system events provided by the language subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_LOCALE_CHANGED<sup>11+</sup>
Indicates that the device locale has been set.

- Value: usual.event.LOCALE_CHANGED
- Required subscriber permissions: none

When the device locale is set, the event notification service is triggered to publish this event.
