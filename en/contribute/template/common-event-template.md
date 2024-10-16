# System Common Events

## Writing Requirements

1. Public APIs and system APIs are separately maintained in two documents.

    - Public APIs: en/application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md
    - System APIs: en/application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions-sys.md

    > **NOTE**
    >
    > Currently, some system APIs are not added with the @systemapi tag in .d.ts files, with or without the following description. If you find any of them, you can submit a trouble ticket.
    > - This API can be called only by system applications. 
    > - This common event can be triggered only by system. 
    > - This is a protected common event that can only be sent by system. 

2. Use the kit name as the level-2 title and the event name as the level-3 title.




## Template: *Example* Kit

### EventName<sup>Version+</sup>

Describes the meaning and function of an event.

Describe event triggering scenarios and conditions.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: *xxx*

**Atomic service API**: This API can be used in atomic services since API version *xx*.

**Value**: *xxx*




## Example: Ability Kit

### COMMON_EVENT_BOOT_COMPLETED<sup>9+</sup>

Indicates that the boot is complete and the system is loaded.

When the specified user finishes the boot process on the device, the event notification service is triggered to publish this event.

**System API**: This is a system API.

**Required subscriber permissions**: ohos.permission.RECEIVER_STARTUP_COMPLETED (for system applications only)

**System capability**: SystemCapability.Notification.CommonEvent

**Value:** "usual.event.BOOT_COMPLETED"