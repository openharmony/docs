# ArkData子系统Changelog

## cl.arkdata.1 关系型数据管理@ohos.data.relationalStore.d.ts中getRdbStore接口新增错误码14800020，用于业务侧进行恢复重建数据库。
**访问级别**

公开接口

**变更原因**

根密钥和工作密钥不匹配时返回的错误码不正确，新增14800020错误码，此错误码用于业务侧进行恢复重建数据库。

**变更影响**

该变更为不兼容变更。

变更之前，在根密钥和工作密钥不匹配场景下，不会抛出错误码。业务侧无法恢复数据库。

变更之后，在根密钥和工作密钥不匹配场景下，会抛出14800020错误码，此错误码可用于业务侧进行恢复重建数据库。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.0.1.1 版本开始。

**变更的接口/组件**

[@ohos.data.relationalStore.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.data.relationalStore.d.ts)中如下接口：

1. function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore\>): void;

2. function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore\>;

**适配指导**

异常处理：在调用getRdbStore方法后，检查返回的错误码。如果错误码为14800020，表示数据库根密钥与工作密钥不匹配，需要进行重新建库。
```ts
import { relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3,
  encrypt: true
};
const CREATE_TABLE_TEST =
  "CREATE TABLE IF NOT EXISTS EMPLOYEE (id INTEGER PRIMARY KEY AUTOINCREMENT,name TEXT NOT NULL, age INTEGER, salary REAL, blobType BLOB)";

let store: relationalStore.RdbStore | undefined = undefined;
relationalStore.getRdbStore(this.context, STORE_CONFIG, (err: BusinessError, rdbStore: relationalStore.RdbStore) => {
  store = rdbStore;
  store.executeSql(CREATE_TABLE_TEST);
  if (err) {
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    //err.code为14800020业务侧需要进行数据库恢复。
    return;
  }
  console.info('Get RdbStore successfully.');
})
```