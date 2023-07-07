# Common Events of the File Management Subsystem
This document lists the common system events provided by the file management subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>
Indicates that an external storage device was removed.
- Value: usual.event.data.VOLUME_REMOVED
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

When an external storage device is removed, the event notification service is triggered to publish this event.

## COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>
Indicates that an external storage device was unmounted.
- Value: usual.event.data.VOLUME_UNMOUNTED
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

When an external storage device is successfully unmounted by calling [unmount](../js-apis-file-volumemanager.md) or by removing the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>
Indicates that an external storage device was mounted.
- Value: usual.event.data.VOLUME_MOUNTED
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

When an external storage device is mounted by calling [mount](../js-apis-file-volumemanager.md) or by inserting the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>
Indicates that an external storage device was removed without being unmounted.
- Value: usual.event.data.VOLUME_BAD_REMOVAL
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

When an external storage device is directly removed without being umounted, the event notification service is triggered to publish this event.

## COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>
Indicates that an external storage device is about to be ejected.
- Value: usual.event.data.VOLUME_EJECT
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

When the user calls [unmount](../js-apis-file-volumemanager.md) on a mounted external storage device or removes the device, the event notification service is triggered to publish this event.
