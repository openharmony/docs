# ArkData Changelog

## cl.kv_store.1 Scenario Change for Cross-Device Automatic Sync of the KV Store

**Access Level**

Public API

**Reason for Change**

The change is made to eliminate invalid data sync across devices.

**Change Impact**

This change is a non-compatible change.

Before the change: 

When data is added, deleted, or modified in a KV store with **autoSync** set to **true**, data will be automatically synced to the devices in the same network.

After the change: 

When data is added, deleted, or modified in a KV store with **autoSync** set to **true**, data will be automatically synced to the devices in [multi-device collaboration](../../../application-dev/application-models/hop-multi-device-collaboration.md) in the same network.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.37

**Key API/Component Changes**

autoSync/distributedKVStore

**Adaptation Guide**

The cross-device automatic sync of KV stores applies only to multi-device collaboration. For details, see [Cross-Device Sync of KV Stores](../../../application-dev/database/data-sync-of-kv-store.md).
In other cases, set **autoSync** to **false**. Even if **autoSync** is set to **true**, the automatic data sync does not take effect.
