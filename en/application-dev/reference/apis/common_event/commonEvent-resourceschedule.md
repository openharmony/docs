# Common Events of the Resource Scheduler Subsystem
This document lists the common system events provided by the resource scheduler subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED
Indicates that the system idle mode has changed.

- Constant value: "usual.event.DEVICE_IDLE_MODE_CHANGED"
- Required subscriber permissions: none

When the user does not use the device for the specified period of time and the screen is turned off, the system delays the CPU and network access by background applications, and the event notification service is triggered to publish this event.

APIs related to this event: **deviceStandby**.

## COMMON_EVENT_DEVICE_IDLE_EXEMPTION_LIST_UPDATED
Indicates that the exemption list for resource usage restrictions has been updated in idle mode.

- Constant value: "usual.event.DEVICE_IDLE_EXEMPTION_LIST_UPDATED"
- Required subscriber permissions: none

When the exemption list for resource usage restrictions is updated, the event notification service is triggered to publish this event.
Resources include application network access, Timer usage, and WorkScheduler task usage.
System applications can call JavaScript APIs to apply for removing resource usage restrictions.

APIs related to this event: **deviceStandby**.
