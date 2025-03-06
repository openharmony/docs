# ArkData Changelog

## cl.kv_store.1 Change in the Error Code Returned by getKVStore()

**Access Level**

Public API

**Reason for the Change**

The error code returned is changed from **15100003** to **15100006** when the database file cannot be accessed due to the device being locked.

**Change Impact**

This change is a non-compatible change.

Before the change:<br>The attempt to access files in the **/el2**, **/el3**, or **/el4** directory when the device is not unlocked will trigger error 15100003 Database corrupted.

After the change:<br>The attempt to access files in the **/el2**, **/el3**, or **/el4** directory when the device is not unlocked will trigger error 15100006 Unable to open the database file.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.51

**Key API/Component Changes**

**getKVStore()** of distributedKVStore

**Adaptation Guide**

Files in the **/el2**, **/el3**, or **/el4** directory cannot be accessed when the device is locked. Calling **getKVStore()** will return error 15100006 Unable to open the database file when the device is locked. This error code does not affect applications. You can determine whether to capture this error code. If this error code is captured, the service can access the database file at appropriate time, for example, when the device is unlocked.

## cl.kv_store.2 Change in the Error Code Returned by backup() and restore()

**Access Level**

Public API

**Reason for the Change**

Due to an implementation bug, calling **backup()** will trigger a successful backup operation even when the database file is corrupted, generating a backup of the corrupted file.

Due to an implementation bug, calling **restore()** will trigger a successful restore operation even when the database file is corrupted, resulting in a corrupted file.

**Change Impact**

This change is a non-compatible change.

Before the change:<br>Calling **backup()** will trigger a successful backup operation even when the database file is corrupted, generating a backup of the corrupted file. Calling **restore()** will trigger a successful restore operation even when the database file is corrupted, resulting in a corrupted file.

Before the change:<br>If the database file is corrupted, calling **backup()** or **restore()** will return error 15100003 Database corrupted.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.51

**Key API/Component Changes**

**backup()** and **restore()** of distributedKVStore

**Adaptation Guide**

If the database file is corrupted, calling **backup()** will return error 15100003 Database corrupted. The backup operation fails, and the service should proceed based on the error code.

If the database file is corrupted, calling **restore()** will return error 15100003 Database corrupted. The restore operation fails, and the service should regenerate data and write the data to the database file.
