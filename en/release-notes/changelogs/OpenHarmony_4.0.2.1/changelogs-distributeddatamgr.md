# Distributed Data Management Subsystem JS API Changelog

## cl.distributeddatamgr.1 API Change
Changed the **relationalStore** APIs of the distributed data management (distributeddatamgr) subsystem.

Before change:
After **getRdbStore()** is called, the application determines whether the RDB store is newly created based on the **openStatus** attribute (openStatus == ON_CREATE) of the returned **rdbStore** object.
After change:
After **getRdbStore()** is called, the application determines whether the RDB store is newly created based on the **version** attribute (version == 0) of the returned **rdbStore** object.

You need to adapt your application.

 **Change Impact**

The JS APIs of API version 10 are affected and need to be changed accordingly. Otherwise, certain functions cannot be properly implemented in the SDK of the new version.

**Key API/Component Changes**

| Module                            | Class            | Method/Attribute/Enum/Constant| Change Type|
| ------------------------------    | --------------- | ---------------- | ------- |
| @ohos.data.relationalStore        | RdbStore        | **openStatus: number;** is changed to **version: number;**.|  Changed  |


**Adaptation Guide**

Refer to the following code to set or obtain the RDB store version for an application:

```ts
const STORE_CONFIG = {
    name: "rdbstore.db",
    securityLevel: data_rdb.SecurityLevel.S1
}
data_rdb.getRdbStore(this.context, STORE_CONFIG, function (err, rdbStore) {
    // Before:
    // if (rdbStore.openStatus == ON_CREATE) {
    //     rdbStore.executeSql("CREATE TABLE IF NOT EXISTS student (id INTEGER PRIMARY KEY AUTOINCREMENT, score REAL);", null) // create table xxx
    // }
    
    // Now:
    if (rdbStore.version == 0) {
        rdbStore.executeSql("CREATE TABLE IF NOT EXISTS student (id INTEGER PRIMARY KEY AUTOINCREMENT, score REAL);", null) // create table xxx
        // Set the RDB store version, which is a positive integer greater than 0.
        rdbStore.version == 3
    }
    // Obtain the RDB store version.
    console.info("Get RdbStore version is " + rdbStore.version)
})
```
