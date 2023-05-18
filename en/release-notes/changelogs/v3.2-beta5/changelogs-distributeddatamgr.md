# Distributed Data Management Subsystem Changelog

## cl.distributeddatamgr.1 API Change
Changed the APIs in **kv_store** of the distributed data management subsystem:

Changed **createKVManager()** from an asynchronous API to a synchronous API, because the execution duration is fixed and short.<br>Before change:<br>**createKVManager(config: KVManagerConfig): Promise\<KVManager\>;**<br>**createKVManager(config: KVManagerConfig, callback: AsyncCallback<KVManager>): void;**<br>After change:<br>**createKVManager(config: KVManagerConfig): KVManager;**

You need to adapt your application based on the following information.

 **Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): Promise\<KVManager\>; | Deleted    |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): KVManager; | Changed    |


**Adaptation Guide**

The following sample code shows how to call **createKVManager** to create a **KVManager** object.

Stage model:

```ts
import AbilityStage from '@ohos.application.Ability'
let kvManager;
export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
        let context = this.context
        const kvManagerConfig = {
            context: context,
            bundleName: 'com.example.datamanagertest',
        }
        try {
            kvManager = distributedKVStore.createKVManager(kvManagerConfig);          
        } catch (e) {
            console.error(`Failed to create KVManager.code is ${e.code},message is ${e.message}`);
        }
    }
}
```

FA model:

```ts
import featureAbility from '@ohos.ability.featureAbility'
let kvManager;
let context = featureAbility.getContext()
const kvManagerConfig = {
    context: context,
    bundleName: 'com.example.datamanagertest',
}
try {
    kvManager = distributedKVStore.createKVManager(kvManagerConfig);
} catch (e) {
    console.error(`Failed to create KVManager.code is ${e.code},message is ${e.message}`);
}
```

## cl.distributeddatamgr.2 Moved function getRdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

Moved the following APIs from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**:

Before change:

```ts
function getRdbStoreV9(context: Context, config: StoreConfigV9, version: number, callback: AsyncCallback<RdbStoreV9>): void;
function getRdbStoreV9(context: Context, config: StoreConfigV9, version: number): Promise<RdbStoreV9>;
```
After change:
```
function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback<RdbStore>): void;
function getRdbStore(context: Context, config: StoreConfig): Promise<RdbStore>;
```

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the names of related APIs accordingly.

## cl.distributeddatamgr.3 Moved function deleteRdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
APIs:
```ts
function deleteRdbStoreV9(context: Context, name: string, callback: AsyncCallback<void>): void;
function deleteRdbStoreV9(context: Context, name: string): Promise<void>;
```
The APIs are moved from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**.
```
function deleteRdbStoreV9(context: Context, name: string, callback: AsyncCallback<void>): void;
function deleteRdbStoreV9(context: Context, name: string): Promise<void>;
```

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the names of related APIs accordingly.

## cl.distributeddatamgr.4 Moved interface StoreConfigV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **StoreConfigV9** from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and renamed it **StoreConfig**.

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the names of related APIs accordingly.

## cl.distributeddatamgr.5 Moved enum SecurityLevel from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved enum **SecurityLevel** from **ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**.

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the names of related APIs accordingly.

## cl.distributeddatamgr.6 Moved interface RdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **RdbStoreV9** from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and renamed it **RdbStore**.

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the names of related APIs accordingly.

## cl.distributeddatamgr.7 Moved class RdbPredicatesV9 from ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved the class **RdbPredicatesV9** from **ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and renamed it **RdbPredicates**.

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the names of related APIs accordingly.

## cl.distributeddatamgr.8 Moved interface ResultSetV9 from api/@ohos.data.relationalStore.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**
Moved **ResultSetV9** from **api/data/rdb/resultSet.d.ts** to **@ohos.data.relationalStore.d.ts** and renamed it **ResultSet**.

**Adaptation Guide**

 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Obtain the **ResultSetV9** instance only by using **getRdbStoreV9**. After modifications are made according to cl.distributeddatamgr.2, the code can automatically adapt to **ResultSet**.
