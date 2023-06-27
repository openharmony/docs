# 分布式数据管理子系统JS API变更Changelog

## cl.distributeddatamgr.1 接口变更
distributeddatamgr子系统kv_store组件接口存在变更：

由于执行时间固定且耗时短，不需要异步等待执行结果，createKVManager方法需要改为同步接口。因此旧的接口function createKVManager(config: KVManagerConfig): Promise\<KVManager\>; 与 function createKVManager(config: KVManagerConfig, callback: AsyncCallback<KVManager>): void; 改为 function createKVManager(config: KVManagerConfig): KVManager;

开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): Promise\<KVManager\>; | 删除     |
| @ohos.distributedKVStore        | distributedKVStore        | function createKVManager(config: KVManagerConfig): KVManager; | 变更     |


**适配指导**

应用中调用createKVManager创建KVManager对象实例可参考下列代码

Stage模型下的示例：

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

FA模型下的示例：

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

## cl.distributeddatamgr.2 function getRdbStoreV9 从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts
**变更影响**
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
如下接口：
```ts
function getRdbStoreV9(context: Context, config: StoreConfigV9, version: number, callback: AsyncCallback<RdbStoreV9>): void;
function getRdbStoreV9(context: Context, config: StoreConfigV9, version: number): Promise<RdbStoreV9>;
```
从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts:
```
function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback<RdbStore>): void;
function getRdbStore(context: Context, config: StoreConfig): Promise<RdbStore>;
```

**适配指导**
 * `import rdb from "@ohos.data.rdb"` 改为 `import rdb from "@ohos.data.relationalStore"`；
 * 按上述接口变更对齐修改所调用的方法名称即可。

## cl.distributeddatamgr.3 function deleteRdbStoreV9 从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts
**变更影响**
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
如下接口：
```ts
function deleteRdbStoreV9(context: Context, name: string, callback: AsyncCallback<void>): void;
function deleteRdbStoreV9(context: Context, name: string): Promise<void>;
```
从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts:
```
function deleteRdbStoreV9(context: Context, name: string, callback: AsyncCallback<void>): void;
function deleteRdbStoreV9(context: Context, name: string): Promise<void>;
```

**适配指导**
 * `import rdb from "@ohos.data.rdb"` 改为 `import rdb from "@ohos.data.relationalStore"`；
 * 按上述接口变更对齐修改所调用的方法名称即可。

## cl.distributeddatamgr.4 interface StoreConfigV9 从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts
**变更影响**
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface StoreConfigV9 从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts 改名为interface StoreConfig。

**适配指导**
 * `import rdb from "@ohos.data.rdb"` 改为 `import rdb from "@ohos.data.relationalStore"`；
 * 按上述接口变更对齐修改所调用的接口名称即可。

## cl.distributeddatamgr.5 enum SecurityLevel 从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts
**变更影响**
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
enum SecurityLevel 从ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts。

**适配指导**
 * `import rdb from "@ohos.data.rdb"` 改为 `import rdb from "@ohos.data.relationalStore"`；
 * 按上述接口变更对齐修改所调用的接口名称即可。

## cl.distributeddatamgr.6 interface RdbStoreV9 从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts
**变更影响**
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更** 
interface RdbStoreV9 从@ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts 改名为interface RdbStore。

**适配指导**
 * `import rdb from "@ohos.data.rdb"` 改为 `import rdb from "@ohos.data.relationalStore"`；
 * 按上述接口变更对齐修改所调用的接口名称即可。

## cl.distributeddatamgr.7 class RdbPredicatesV9 从ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts
**变更影响**
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
class RdbPredicatesV9 从ohos.data.rdb.d.ts 迁移至@ohos.data.relationalStore.d.ts 改名为interface RdbPredicates。

**适配指导**
 * `import rdb from "@ohos.data.rdb"` 改为 `import rdb from "@ohos.data.relationalStore"`；
 * 按上述接口变更对齐修改所调用的接口名称即可。

## cl.distributeddatamgr.8 interface ResultSetV9 从api/@ohos.data.relationalStore.d.ts 迁移至@ohos.data.relationalStore.d.ts
**变更影响**
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**
interface ResultSetV9 从api/data/rdb/resultSet.d.ts 迁移至@ohos.data.relationalStore.d.ts 改名为interface ResultSet。

**适配指导**
 * `import rdb from "@ohos.data.rdb"` 改为 `import rdb from "@ohos.data.relationalStore"`；
 * ResultSetV9实例仅通过getRdbStoreV9方法获取，参考cl.distributeddatamgr.2变更后，代码可自动适配ResultSet。
