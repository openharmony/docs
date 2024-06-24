# Common Events of the File Management Subsystem
This document lists the common system events provided by the file management subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>
Indicates that an external storage device was removed.
- Value: usual.event.data.VOLUME_REMOVED
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER (for system apps only)

This common event is triggered when an external storage device is removed.

## COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>
Indicates that an external storage device was unmounted.
- Value: usual.event.data.VOLUME_UNMOUNTED
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER (for system apps only)

This common event is triggered when an external storage device is successfully unmounted by calling the **unmount** API or by removing the device.

## COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>
Indicates that an external storage device was mounted.
- Value: usual.event.data.VOLUME_MOUNTED
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER (for system apps only)

This common event is triggered when an external storage device is successfully mounted by calling the **mount** API or by inserting the device.

## COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>
Indicates that an external storage device was removed without being unmounted.
- Value: usual.event.data.VOLUME_BAD_REMOVAL
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER (for system apps only)

This common event is triggered when an external storage device is directly removed without being unmounted.

## COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>
Indicates that an external storage device is about to be ejected.
- Value: usual.event.data.VOLUME_EJECT
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER (for system apps only)

This common event is triggered when the user calls the **unmount** API on a mounted external storage device or removes the device.
