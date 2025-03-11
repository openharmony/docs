# ArkData子系统Changelog

## cl.distributeddatamgr.1 关系型数据管理@ohos.data.relationalStore.d.ts中deleteRdbStore接口行为变更

**访问级别**

公开接口

**变更原因**

删除关系型数据库后，仍能通过句柄执行插入、删除、更新操作，且不返回错误码，导致无法感知关系型数据库已被删除。

**变更影响**

此变更不涉及应用适配。

变更前：在关系型数据库被删除后，通过现有的句柄仍然可以执行插入、删除和更新操作，且这些操作不会返回错误码。

变更后：在关系型数据库被删除后，通过现有的句柄执行插入、删除和更新操作，会返回14800014错误码。

**起始 API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.1.0.56开始。

**变更的接口/组件**

deleteRdbStore/关系型数据管理（relational_store）

**示例代码**

在调用deleteRdbStore删除关系型数据库之后，若继续使用此数据库进行插入、删除和更新操作，则将返回14800014错误码。请在删除数据库之后重新建库以确保正常使用。

```ts
import { relationalStore } from '@kit.ArkData';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let store: relationalStore.RdbStore | undefined = undefined;

const CREATE_TABLE_TEST = "CREATE TABLE IF NOT EXISTS test (" + "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
    "name TEXT NOT NULL, " + "age INTEGER, " + "salary REAL, " + "blobType BLOB)";
const STORE_CONFIG: relationalStore.StoreConfig = {
    name: "rdbstore.db",
    securityLevel: relationalStore.SecurityLevel.S3,
}

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {

    relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
      store = rdbStore;
      console.info('Get RdbStore successfully.')
    }).catch((err: BusinessError) => {
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    })

    if(store != undefined) {
      (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE).then(() => {
        console.info('Delete table done.');
      }).catch((err: BusinessError) => {
        console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
      })
    }

    relationalStore.deleteRdbStore(this.context, "rdbstore.db").then(()=>{
      store = undefined;
      console.info('Delete RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    })

    const valueBucket: relationalStore.ValuesBucket = {
      'NAME': "Lisa",
      'AGE': 18,
      'SALARY': 100.5,
      'BLOB': new Uint8Array([1, 2, 3, 4, 5]);
    };
    if(store != undefined) {
      (store as relationalStore.RdbStore).insert("test", valueBucket).then((rowId: number) => {
        console.info(`Insert is successful, rowId = ${rowId}`);
      }).catch((err: BusinessError) => {
        console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
      })
    }
  }
}
```