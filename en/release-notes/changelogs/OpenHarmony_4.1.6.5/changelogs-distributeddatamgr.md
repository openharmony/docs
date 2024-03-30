# Distributed Data Management Subsystem Changelog

## cl.distributeddatamgr.1 OH_Rdb_CloudSync Parameter Change

**Access Level**

Public

**Reason for Change**

After the change, the callback also returns the context.

**Change Impact**

This change is a non-compatible change. You need to modify the parameters in **OH_Rdb_CloudSync**.

**API level**

11

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

Before the change:
    
```c
int OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count,
    Rdb_SyncCallback *callback);
```
After the change:
    
```c
int OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count,
    const Rdb_ProgressObserver *observer);
```

**Adaptation Guide**

You need to add a parameter of the Rdb_ProgressObserver type. The newly added parameter includes the original **callback** field and a **context** field.

```c
// Define the callback.
void CloudSyncObserverCallback(void *context, Rdb_ProgressDetails *progressDetails)
{
// Do something.
}
const Rdb_ProgressObserver observer = { .context = nullptr, .callback = CloudSyncObserverCallback };
OH_Rdb_CloudSync(storeTestRdbStore_, Rdb_SyncMode::SYNC_MODE_TIME_FIRST, table, TABLE_COUNT, &observer);
```
