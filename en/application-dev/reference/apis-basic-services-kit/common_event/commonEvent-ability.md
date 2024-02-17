# Common Events of the Ability Subsystem
This document lists the common system events provided by the Ability subsystem to applications.

## COMMON_EVENT_BOOT_COMPLETED

Indicates that the user has finished the boot process.

- Constant value: "usual.event.BOOT_COMPLETED"
- Required subscriber permissions: ohos.permission.RECEIVER_STARTUP_COMPLETED

When the specified user finishes the boot process on the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_PACKAGE_RESTARTED

Indicates that the user has restarted the application package and killed all its processes.

- Constant value: "usual.event.PACKAGE_RESTARTED"
- Required subscriber permissions: none

When the specified user restarts the application and kills all its processes, the event notification service is triggered to publish this event.

## COMMON_EVENT_PACKAGE_DATA_CLEARED

Indicates that the user cleared the application package data.

- Constant value: "usual.event.PACKAGE_DATA_CLEARED"
- Required subscriber permissions: none

When the specified user clears the application package data on the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_QUICK_FIX_APPLY_RESULT<sup>9+</sup>

Indicates the result of applying a quick fix to the application.

- Constant value: "usual.event.QUICK_FIX_APPLY_RESULT"
- Required subscriber permissions: none

When the specified user applies a quick fix to the application on the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_QUICK_FIX_REVOKE_RESULT<sup>10+</sup>

Indicates the result of revoking a quick fix to the application.

- Constant value: "usual.event.QUICK_FIX_REVOKE_RESULT"
- Required subscriber permissions: none

When a quick fix to the application is revoked on the device, the event notification service is triggered to publish this event.
