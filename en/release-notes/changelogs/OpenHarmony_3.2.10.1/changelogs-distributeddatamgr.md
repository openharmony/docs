# ChangeLog of JS API Changes of the Distributed Data Management Subsystem

Compared with OpenHarmony 3.2 Beta4, OpenHarmony 3.2.10.1(Mr) has the following API changes in the distributed data management subsystem:

## cl.distributeddatamgr.1 API Change
APIs in the **kv_store** component of the distributed data management subsystem are changed:

**createKVManager** is changed from asynchronous to synchronous, because the execution duration is fixed and short and there is no need to asynchronously wait for the execution result. Therefore, the original APIs **function createKVManager(config: KVManagerConfig): Promise\<KVManager\>;** and **function createKVManager(config: KVManagerConfig, callback: AsyncCallback<KVManager>): void;** are changed to **function createKVManager(config: KVManagerConfig): KVManager;**.

You need to adapt your applications based on the following information:

**Change Impacts**

JS APIs in API version 9 are affected. The application needs to adapt these APIs so that it can properly implement functions in the SDK environment of the new version.

**Key API/Component Changes**

| Module                  | Class              | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ------------------------ | ------------------ | ------------------------------------------------------------ | -------- |
| @ohos.distributedKVStore | distributedKVStore | function createKVManager(config: KVManagerConfig): Promise\<KVManager\>; | Deleted    |
| @ohos.distributedKVStore | distributedKVStore | function createKVManager(config: KVManagerConfig): KVManager; | Changed    |


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

## cl.distributeddatamgr.2 Migration of function getRdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts.
**Change Impacts**

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

APIs:

```ts
function getRdbStoreV9(context: Context, config: StoreConfigV9, version: number, callback: AsyncCallback<RdbStoreV9>): void;
function getRdbStoreV9(context: Context, config: StoreConfigV9, version: number): Promise<RdbStoreV9>;
```
The APIs are migrated from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**.
```
function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback<RdbStore>): void;
function getRdbStore(context: Context, config: StoreConfig): Promise<RdbStore>;
```

**Adaptation Guide**

 * `import rdb from "@ohos.data.rdb"` is changed to `import rdb from "@ohos.data.relationalStore"`.
 * The names of relevant methods should be changed according to the preceding changes.

## cl.distributeddatamgr.3 Migration of function deleteRdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impacts**

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

APIs:

```ts
function deleteRdbStoreV9(context: Context, name: string, callback: AsyncCallback<void>): void;
function deleteRdbStoreV9(context: Context, name: string): Promise<void>;
```
The APIs are migrated from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**.
```
function deleteRdbStoreV9(context: Context, name: string, callback: AsyncCallback<void>): void;
function deleteRdbStoreV9(context: Context, name: string): Promise<void>;
```

**Adaptation Guide**
 * `import rdb from "@ohos.data.rdb"` is changed to `import rdb from "@ohos.data.relationalStore"`.
 * The names of relevant methods should be changed according to the preceding changes.

## cl.distributeddatamgr.4 Migration of interface StoreConfigV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impacts**

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

**interface StoreConfigV9** is migrated from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and is renamed as **interface StoreConfig**.

**Adaptation Guide**
 * `import rdb from "@ohos.data.rdb"` is changed to `import rdb from "@ohos.data.relationalStore"`.
 * The names of relevant APIs should be changed according to the preceding changes.

## cl.distributeddatamgr.5 Migration of enum SecurityLevel from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impacts**

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

**enum SecurityLevel** is migrated from **ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts**.

**Adaptation Guide**
 * `import rdb from "@ohos.data.rdb"` is changed to `import rdb from "@ohos.data.relationalStore"`.
 * The names of relevant APIs should be changed according to the preceding changes.

## cl.distributeddatamgr.6 Migration of interface RdbStoreV9 from @ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impacts**

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

**interface RdbStoreV9** is migrated from **@ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and is renamed as **interface RdbStore**.

**Adaptation Guide**
 * `import rdb from "@ohos.data.rdb"` is changed to `import rdb from "@ohos.data.relationalStore"`.
 * The names of relevant APIs should be changed according to the preceding changes.

## cl.distributeddatamgr.7 Migration of class RdbPredicatesV9 from ohos.data.rdb.d.ts to @ohos.data.relationalStore.d.ts
**Change Impacts**

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

**class RdbPredicatesV9** is migrated from **ohos.data.rdb.d.ts** to **@ohos.data.relationalStore.d.ts** and is renamed as **interface RdbPredicates**.

**Adaptation Guide**
 * `import rdb from "@ohos.data.rdb"` is changed to `import rdb from "@ohos.data.relationalStore"`.
 * The names of relevant APIs should be changed according to the preceding changes.

## cl.distributeddatamgr.8 Migration of interface ResultSetV9 from api/@ohos.data.relationalStore.d.ts to @ohos.data.relationalStore.d.ts
**Change Impacts**

The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

**interface ResultSetV9** is migrated from **api/data/rdb/resultSet.d.ts** to **@ohos.data.relationalStore.d.ts** and is renamed as **interface ResultSet**.

**Adaptation Guide**

 * `import rdb from "@ohos.data.rdb"` is changed to `import rdb from "@ohos.data.relationalStore"`.
 * The **ResultSetV9** instance is obtained only via **getRdbStoreV9**. After modifications are made according to cl.distributeddatamgr.2, the code can automatically adapt to **ResultSet**.
