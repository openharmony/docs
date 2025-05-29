# ArkData Changelog

## cl.ArkData.1 Asset Property Type Change

**Access Level**

Public API

**Reason for Change**

In OpenHarmony 5.0 Beta1, the **undefined** type is added for **Asset** properties, which undermines the universality of **Asset**.

**Change Impact**

This change is a non-compatible change. The **Asset** properties no longer support the **undefined** type.

If the **undefined** type has been used in your code, the code compilation will fail due to type mismatch.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.31

**Key API/Component Changes**

Asset/Data Common Type (**commonType**)

**Adaptation Guide**

For application projects that use the **undefined** type in **Asset** properties, the properties of the **undefined** type must be changed to an empty string.

For other application projects that use the **Asset** properties, set the properties to an empty string to solve the data overwriting problem.

## cl.ArkData.2 setSessionId() Behavior Change

**Access Level**

Public API

**Reason for Change**

When data is synced via distributed data objects, the system attempts to set up connections with all the devices on the network with the same account and sync data. However, data sync is not necessary for the devices without distributed data objects. Therefore, unnecessary data sync causes waste of system resources.

**Change Impact**

This change is a non-compatible change. After the change, data sync via distributed data objects is allowed only between devices in [cross-device migration](../../../application-dev/application-models/hop-cross-device-migration.md) or [multi-device collaboration](../../../application-dev/application-models/hop-multi-device-collaboration.md). For the applications that do not support cross-device migration or multi-device collaboration, data will not be automatically synced if distributed data objects are used.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.31

**Key API/Component Changes**

setSessionId/Distributed data object (**data_object**)

**Adaptation Guide**

For details, see the sample code in [Using Distributed Data Objects in Cross-Device Migration](../../../application-dev/database/data-sync-of-distributed-data-object.md#using-distributed-data-objects-in-cross-device-migration) and [Using Distributed Data Objects in Multi-Device Collaboration](../../../application-dev/database/data-sync-of-distributed-data-object.md#using-distributed-data-objects-in-multi-device-collaboration).
