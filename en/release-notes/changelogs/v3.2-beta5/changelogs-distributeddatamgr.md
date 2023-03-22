# Distributed Data Management Subsystem JS API Changelog

## cl.distributeddatamgr.1 API Change
Changed the APIs in **kv_store** of the distributed data management subsystem:

Changed the **createKVManager()** implementation from asynchronous mode to synchronous mode because the execution duration is fixed and short. 

Before change:<br>**createKVManager(config: KVManagerConfig): Promise\<KVManager\>;**<br>**createKVManager(config: KVManagerConfig, callback: AsyncCallback<KVManager>): void;**<br>After change:<br>**createKVManager(config: KVManagerConfig): KVManager;**

You need to adapt your application.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): Promise\<KVManager\>; | Deleted    |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): KVManager; | Changed    |


**Adaptation Guide**

The following illustrates how to call **createKVManager** to create a **KVManager** object.

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

## cl.distributeddatamgr.2 Move of getRdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
Moved **getRdbStoreV9()** from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts, and renamed it **getRdbStore()**.

**Change Impact**
The change must be made for all the applications that use these APIs. Otherwise, the compilation in the SDK of the new version cannot be successful.

**Key API/Component Changes**
APIs:

```ts
function getRdbStoreV9(context: Context, config: StoreConfigV9, version: number, callback: AsyncCallback<RdbStoreV9>): void;
function getRdbStoreV9(context: Context, config: StoreConfigV9, version: number): Promise<RdbStoreV9>;
```
Moved the above APIs from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**.
```
function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback<RdbStore>): void;
function getRdbStore(context: Context, config: StoreConfig): Promise<RdbStore>;
```

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the names of the **getRdbStore()** APIs.

## cl.distributeddatamgr.3 Move of deleteRdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts

Moved **deleteRdbStoreV9()** from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts, and renamed it **deleteRdbStore()**.

**Change Impact**
The change must be made for all the applications that use these APIs. Otherwise, the compilation in the SDK of the new version cannot be successful.

**Key API/Component Changes**
APIs:
```ts
function deleteRdbStoreV9(context: Context, name: string, callback: AsyncCallback<void>): void;
function deleteRdbStoreV9(context: Context, name: string): Promise<void>;
```
Moved the above APIs from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**.
```
function deleteRdbStore(context: Context, name: string, callback: AsyncCallback<void>): void;
function deleteRdbStore(context: Context, name: string): Promise<void>;
```

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the names of the **deleteRdbStoreV9()** APIs.

## cl.distributeddatamgr.4 Move of StoreConfigV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The change must be made for all the applications that use these APIs. Otherwise, the compilation in the SDK of the new version cannot be successful.

**Key API/Component Changes**
Moved **StoreConfigV9** from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and renamed it **StoreConfig**.

**Adaptation Guide**

 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change the **StoreConfigV9** in APIs.

## cl.distributeddatamgr.5 Move of enum SecurityLevel from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The change must be made for all the applications that use these APIs. Otherwise, the compilation in the SDK of the new version cannot be successful.

**Key API/Component Changes**
Moved **enum SecurityLevel** from **ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**.

**Adaptation Guide**

Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.

## cl.distributeddatamgr.6 Mover of RdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The change must be made for all the applications that use these APIs. Otherwise, the compilation in the SDK of the new version cannot be successful.

**Key API/Component Changes**
Moved **RdbStoreV9** from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and renamed it **RdbStore**.

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change **RdbStoreV9** in relevant APIs.

## cl.distributeddatamgr.7 Move of class RdbPredicatesV9 from ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The change must be made for all the applications that use these APIs. Otherwise, the compilation in the SDK of the new version cannot be successful.

**Key API/Component Changes**
Moved the class **RdbPredicatesV9** from **ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and renamed it **RdbPredicates**.

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Change **RdbPredicatesV9** in the relevant APIs.

## cl.distributeddatamgr.8 Move of ResultSetV9 from api/@ohos.data.relationalStore.d.ts to @ohos.data.relationalStore.d.ts
**Change Impact**
The change must be made for all the applications that use these APIs. Otherwise, the compilation in the SDK of the new version cannot be successful.

**Key API/Component Changes**
Moved **ResultSetV9** from **api/data/rdb/resultSet.d.ts** to **@ohos.data.relationalStore.d.ts** and renamed it **ResultSet**.

**Adaptation Guide**
 * Change **import rdb from "@ohos.data.rdb"** to **import rdb from "@ohos.data.relationalStore"**.
 * Obtain the **ResultSetV9** instance only by using **getRdbStoreV9**. After modifications are made according to cl.distributeddatamgr.2, the code can automatically adapt to **ResultSet**.

