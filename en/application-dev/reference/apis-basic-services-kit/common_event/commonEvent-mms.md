# Common Events of the SMS Application
This document lists the common system events provided by the SMS application to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_SMS_RECEIVE_COMPLETED

Indicates that a new SMS message has been received.

- Value: usual.event.SMS_RECEIVE_COMPLETED
- Required subscriber permissions: none

When the device receives a new SMS message, the event notification service is triggered to publish this event.
