# Distributed Data Object Changelog

## c1.data_object.1 setSessionId Behavior Change

**Access Level**

Public API

**Reason for Change**

The change is made to solve invalid data synchronization.

**Change Impact**

This change is a non-compatible change. In cross-device migration, after **setSessionId** is called for the distributed data object of the source device, data will not be automatically synchronized to the target device.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.21

**Key API/Component Changes**

setSessionId/**data_object**

**Adaptation Guide**

In cross-device migration development, after **setSessionId()** is called for a distributed data object on the source device, call **save()** to save data to the target device.

```ts
let dataObject = distributedDataObject.create(context, source);
dataObject.setSessionId(sessionId);
dataObject.save (wantParam.targetDevice as string); // Call save() to save data to the target device.
```

For details, see [Using Distributed Data Objects in Cross-Device Migration](../../../application-dev/database/data-sync-of-distributed-data-object.md#using-distributed-data-objects-in-cross-device-migration).
