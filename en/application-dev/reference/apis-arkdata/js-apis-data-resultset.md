# resultSet

A result set is a set of results returned after the relational database (RDB) query APIs are called. You can use the **resultset** APIs to obtain required data.

> **NOTE**<br/>
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are no longer maintained since API version 9. You are advised to use [@ohos.data.relationalStore#ResultSet](arkts-apis-data-relationalStore-ResultSet.md) instead.

## ResultSet

Provides methods to access the result set, which is obtained by querying the RDB store.

### Usage

You need to obtain a **resultSet** object by using [RdbStore.query()](js-apis-data-rdb.md#query).

```js
import dataRdb from '@ohos.data.rdb';
let predicates = new dataRdb.RdbPredicates("EMPLOYEE");
predicates.equalTo("AGE", 18);
let promise = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  console.log(TAG + "resultSet columnNames:" + resultSet.columnNames);
  console.log(TAG + "resultSet columnCount:" + resultSet.columnCount);
});
```

### Attributes

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| columnNames | Array&lt;string&gt; | Yes| Names of all columns in the result set.|
| columnCount | number | Yes| Number of columns in the result set.|
| rowCount | number | Yes| Number of rows in the result set.|
| rowIndex | number | Yes| Index of the current row in the result set.|
| isAtFirstRow | boolean | Yes| Whether the cursor is in the first row of the result set.|
| isAtLastRow | boolean | Yes| Whether the cursor is in the last row of the result set.|
| isEnded | boolean | Yes| Whether the cursor is after the last row of the result set.|
| isStarted | boolean | Yes| Whether the cursor has been moved.|
| isClosed | boolean | Yes| Whether the result set is closed.|

### getColumnIndex

getColumnIndex(columnName: string): number

Obtains the column index based on the column name.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | columnName | string | Yes| Column name specified.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Index of the column obtained.|

**Example**

```js
const success = resultSet.goToFirstRow();
if (success) {
  const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
  const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
  const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
  const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
}
```

### getColumnName

getColumnName(columnIndex: number): string

Obtains the column name based on the column index.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | Yes| Column index specified.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Column name obtained.|

**Example**

```js
const id = resultSet.getColumnName(0);
const name = resultSet.getColumnName(1);
const age = resultSet.getColumnName(2);
```

### goTo

goTo(offset:number): boolean

Moves the cursor to the row based on the specified offset.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | offset | number | Yes| Offset relative to the current position.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let predicatesgoto = new dataRdb.RdbPredicates("EMPLOYEE");
let promisequerygoto = rdbStore.query(predicatesgoto, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoto.then((resultSet) => {
  resultSet.goTo(1);
  resultSet.close();
}).catch((err) => {
  console.log('query failed');
});
```

### goToRow

goToRow(position: number): boolean

Moves the cursor to the specified row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | position | number | Yes| Position to which the cursor is to be moved.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let predicatesgotorow = new dataRdb.RdbPredicates("EMPLOYEE");
let promisequerygotorow = rdbStore.query(predicatesgotorow, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygotorow.then((resultSet) => {
  resultSet.goToRow(5);
  resultSet.close();
}).catch((err) => {
  console.log('query failed');
});
```

### goToFirstRow

goToFirstRow(): boolean

Moves the cursor to the first row of the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let predicatesgoFirst = new dataRdb.RdbPredicates("EMPLOYEE");
let promisequerygoFirst = rdbStore.query(predicatesgoFirst, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoFirst.then((resultSet) => {
  resultSet.goToFirstRow();
  resultSet.close();
}).catch((err) => {
  console.log('query failed');
});
```

### goToLastRow

goToLastRow(): boolean

Moves the cursor to the last row of the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let predicatesgoLast = new dataRdb.RdbPredicates("EMPLOYEE");
let promisequerygoLast = rdbStore.query(predicatesgoLast, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoLast.then((resultSet) => {
  resultSet.goToLastRow();
  resultSet.close();
}).catch((err) => {
  console.log('query failed');
});
```

### goToNextRow

goToNextRow(): boolean

Moves the cursor to the next row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let predicatesgoNext = new dataRdb.RdbPredicates("EMPLOYEE");
let promisequerygoNext = rdbStore.query(predicatesgoNext, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoNext.then((resultSet) => {
  resultSet.goToNextRow();
  resultSet.close();
}).catch((err) => {
  console.log('query failed');
});
```

### goToPreviousRow

goToPreviousRow(): boolean

Moves the cursor to the previous row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let predicatesgoPrev = new dataRdb.RdbPredicates("EMPLOYEE");
let promisequerygoPrev = rdbStore.query(predicatesgoPrev, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoPrev.then((resultSet) => {
  resultSet.goToPreviousRow();
  resultSet.close();
}).catch((err) => {
  console.log('query failed');
});
```

### getBlob

getBlob(columnIndex: number): Uint8Array

Obtains the value in the specified column in the current row as a byte array.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | Yes| Index of the specified column, starting from 0.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Uint8Array | Value in the specified column as a byte array.|

**Example**

```js
const codes = resultSet.getBlob(resultSet.getColumnIndex("CODES"));
```

### getString

getString(columnIndex: number): string

Obtains the value in the specified column in the current row as a string.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | Yes| Index of the specified column, starting from 0.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Value in the specified column as a string.|

**Example**

```js
const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
```

### getLong

getLong(columnIndex: number): number

Obtains the value in the specified column in the current row as a Long.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | Yes| Index of the specified column, starting from 0.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Value in the specified column as a Long.<br>The value range supported by this API is **Number.MIN_SAFE_INTEGER** to **Number.MAX_SAFE_INTEGER**. If the value is out of this range, use [getDouble](#getdouble).|

**Example**

```js
const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
```

### getDouble

getDouble(columnIndex: number): number

Obtains the value in the specified column in the current row as a double.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | Yes| Index of the specified column, starting from 0.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Value in the specified column as a double.|

**Example**

```js
const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
```

### isColumnNull

isColumnNull(columnIndex: number): boolean

Checks whether the value in the specified column of the current row is null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | Yes| Index of the specified column, starting from 0.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the value is null; returns **false** otherwise.|

**Example**

```js
const isColumnNull = resultSet.isColumnNull(resultSet.getColumnIndex("CODES"));
```

### close

close(): void

Closes this result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```js
let predicatesClose = new dataRdb.RdbPredicates("EMPLOYEE");
let promiseClose = rdbStore.query(predicatesClose, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promiseClose.then((resultSet) => {
  resultSet.close();
}).catch((err) => {
  console.log('resultset close failed');
});
```
