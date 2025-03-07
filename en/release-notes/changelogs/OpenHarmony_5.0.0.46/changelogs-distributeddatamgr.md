# Distributed Data Management Changelog

## cl.relationalStore.1 Change in the Return Value of getRow or getValue for an Empty Uint8Array

**Access Level**

Public API

**Reason for Change**

When an empty (zero-length) Uint8Array is inserted into a column of the BLOB type, **null** will be written to the database. When **getRow()** or **getValue()** is called, the value obtained does not match the value inserted.

**Change Impact**

This change is a non-compatible change.

Before the change:<br>If an empty Uint8Array is inserted into a column of the BLOB type, calling **getRow**/**getValue** will return **null**.

After the change:<br>If an empty Uint8Array is inserted into a column of the BLOB type, calling **getRow**/**getValue** will return an empty Uint8Array.

**Start API Level**

| API| Start API Level|
| -------- | -------------- |
| getRow   | API 11         |
| getValue | API 12         |

**Change Since**

OpenHarmony SDK 5.0.0.46

**Key API/Component Changes**

**getRow** in @ohos.data.relationalStore.d.ts.
**getValue** in @ohos.data.relationalStore.d.ts.

**Adaptation Guide**

After the change, the interface invoking mode remains unchanged. The value returned by **getRow()** or **getValue()** changes.
```ts
import { relationalStore } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
};
const CREATE_TABLE_TEST =
  "CREATE TABLE IF NOT EXISTS EMPLOYEE (id INTEGER PRIMARY KEY AUTOINCREMENT,name TEXT NOT NULL, age INTEGER, salary REAL, blobType BLOB)";

let store: relationalStore.RdbStore | undefined = undefined;
relationalStore.getRdbStore(this.context, STORE_CONFIG, (err: BusinessError, rdbStore: relationalStore.RdbStore) => {
  store = rdbStore;
  store.executeSql(CREATE_TABLE_TEST);
  if (err) {
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info('Get RdbStore successfully.');
})
// Insert a Uint8Array whose length is 0 into ValuesBucket of the blob type, and obtain the data.
let resultSet: relationalStore.ResultSet | undefined = undefined;
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
if (store != undefined) {
  (store as relationalStore.RdbStore).query(predicates).then((result: relationalStore.ResultSet) => {
    resultSet = result;
  });
}
if (resultSet != undefined) {
  // blobType is the name of the column whose data type is blob.
  const codes = (resultSet as relationalStore.ResultSet).getValue((resultSet as relationalStore.ResultSet).getColumnIndex("blobType"));
}
// Before the change, the value of codes is null.
// After the change, the value of codes is an empty Uint8Array.

if (resultSet != undefined) {
  const row = (resultSet as relationalStore.ResultSet).getRow();
}
// Before the change, row.blobType is null.
// After the change, row.blobType is an empty Uint8Array.
```
