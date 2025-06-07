# ArkData Changelog

## cl.arkdata.1 Added Error Code 14800020 to getRdbStore() in @ohos.data.relationalStore.d.ts
**Access Level**

Public API

**Reason for Change**

No error code is reported when the root key does not match the working key. The error code 14800020 is added to trigger the database restore and rebuild on the service side.

**Change Impact**

This change is a non-compatible change.

Before the change, no error code is reported when the root key does not match the working key. As a result, the database cannot be restored on the service side.

After the change, error code 14800020 is reported when the root key does not match the working key. This error code will trigger the restore and rebuild of the database on the service side.

**Start API Level**

API 9

**Change Since**

OpenHarmony 5.0.1.1

**Key API/Component Changes**

The following APIs in [@ohos.data.relationalStore.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.data.relationalStore.d.ts):

1. function getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<RdbStore\>): void;

2. function getRdbStore(context: Context, config: StoreConfig): Promise\<RdbStore\>;

**Adaptation Guide**

If the error code 14800020 is thrown after **getRdbStore** is called, the database root key does not match the working key. In this case, the database needs to be rebuilt.
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
    // If err.code is 14800020, the database needs to be restored on the service side.
    return;
  }
  console.info('Get RdbStore successfully.');
})
```
