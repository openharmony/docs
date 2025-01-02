# @ohos.data.dataShareResultSet (DataShare Result Set) (System API)

The **DataShareResultSet** module provides APIs for accessing the result set obtained from the database. You can access the values in the specified rows or the value of the specified data type.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.
>
> - The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import { DataShareResultSet } from '@kit.ArkData';
```

## Usage

You can use [query](js-apis-data-dataShare-sys.md#query) to obtain a **DataShareResultSet** object.

```ts
import { DataShareResultSet, dataShare, dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit'
import { UIAbility } from '@kit.AbilityKit';

let dataShareHelper: dataShare.DataShareHelper | undefined = undefined;
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let context = getContext(UIAbility);
dataShare.createDataShareHelper(context, uri, (err:BusinessError, data:dataShare.DataShareHelper) => {
  if (err != undefined) {
    console.error("createDataShareHelper fail, error message : " + err);
  } else {
    console.info("createDataShareHelper end, data : " + data);
    dataShareHelper = data;
  }
});

let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
let resultSet: DataShareResultSet | undefined = undefined;
da.equalTo("name", "ZhangSan");
if (dataShareHelper != undefined) {
  (dataShareHelper as dataShare.DataShareHelper).query(uri, da, columns).then((data: DataShareResultSet) => {
    console.info("query end, data : " + data);
    resultSet = data;
  }).catch((err: BusinessError) => {
    console.error("query fail, error message : " + err);
  });
}
```

## DataShareResultSet
Provides APIs for accessing the result sets returned.

The column or key names are returned as a string array, in which the strings are in the same order as the columns or keys in the result set.

### Properties

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Name       | Type     | Mandatory| Description                    |
| ----------- | ------------- | ---- | ------------------------ |
| columnNames | Array&lt;string&gt; | Yes  | Names of all columns in the result set.  |
| columnCount | number        | Yes  | Number of columns in the result set.        |
| rowCount    | number        | Yes  | Number of rows in the result set.        |
| isClosed    | boolean       | Yes  | Whether the result set is closed.|

### goToFirstRow

goToFirstRow(): boolean

Moves to the first row of the result set.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type   | Description                                         |
| :------ | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```ts
// Create a resultSet object. For details, see Usage in this topic.
if (resultSet != undefined) {
  let isGoToFirstRow = (resultSet as DataShareResultSet).goToFirstRow();
  console.info('resultSet.goToFirstRow: ' + isGoToFirstRow);
}
```

### goToLastRow

goToLastRow(): boolean

Moves to the last row of the result set.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```ts
if (resultSet != undefined) {
  let isGoToLastRow = (resultSet as DataShareResultSet).goToLastRow();
  console.info('resultSet.goToLastRow: ' + isGoToLastRow);
}
```

### goToNextRow

goToNextRow(): boolean

Moves to the next row in the result set.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```ts
if (resultSet != undefined) {
  let isGoToNextRow = (resultSet as DataShareResultSet).goToNextRow();
  console.info('resultSet.goToNextRow: ' + isGoToNextRow);
}
```

### goToPreviousRow

goToPreviousRow(): boolean

Moves to the previous row in the result set.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```ts
if (resultSet != undefined) {
  let isGoToPreviousRow = (resultSet as DataShareResultSet).goToPreviousRow();
  console.info('resultSet.goToPreviousRow: ' + isGoToPreviousRow);
}
```

### goTo

goTo(offset: number): boolean

Moves based on the specified offset.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| Description                                                        |
| ---------- | -------- | -------- | ------------------------------------------------------------ |
| offset     | number   | Yes      | Offset relative to the current position. A negative value means to move backward, and a positive value means to move forward.|

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```ts
let goToNum = 1;
if (resultSet != undefined) {
  let isGoTo = (resultSet as DataShareResultSet).goTo(goToNum);
  console.info('resultSet.goTo: ' + isGoTo);
}
```

### goToRow

goToRow(position: number): boolean

Moves to the specified row in the result set.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| Description                                   |
| ---------- | -------- | -------- | --------------------------------------- |
| position   | number   | Yes      | Position to move to, starting from 0.|

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```ts
let goToRowNum = 2;
if (resultSet != undefined) {
  let isGoToRow = (resultSet as DataShareResultSet).goToRow(goToRowNum);
  console.info('resultSet.goToRow: ' + isGoToRow);
}
```

### getBlob

getBlob(columnIndex: number): Uint8Array

Obtains the value in the form of a byte array based on the specified column and the current row.

If the specified column or key is empty or the value is not of the Blob type, you need to determine whether to throw an exception.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name** | **Type**| **Mandatory**| Description                   |
| ----------- | -------- | -------- | ----------------------- |
| columnIndex | number   | Yes      | Index of the target column, starting from 0.|

**Return value**

| Type      | Description                            |
| ---------- | -------------------------------- |
| Uint8Array | Value obtained.|

**Example**

```ts
let columnIndex = 1;
if (resultSet != undefined) {
  let goToFirstRow = (resultSet as DataShareResultSet).goToFirstRow();
  let getBlob = (resultSet as DataShareResultSet).getBlob(columnIndex);
  console.info('resultSet.getBlob: ' + getBlob);
}
```

### getString

getString(columnIndex: number): string

Obtains the value in the form of a string based on the specified column and the current row.

If the specified column or key is empty or the value is not of the string type, you need to determine whether to throw an exception.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name** | **Type**| **Mandatory**| Description                   |
| ----------- | -------- | -------- | ----------------------- |
| columnIndex | number   | Yes      | Index of the target column, starting from 0.|

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| string | Value obtained.|

**Example**

```ts
let columnIndex = 1;
if (resultSet != undefined) {
  let goToFirstRow = (resultSet as DataShareResultSet).goToFirstRow();
  let getString = (resultSet as DataShareResultSet).getString(columnIndex);
  console.info('resultSet.getString: ' + getString);
}
```

### getLong

getLong(columnIndex: number): number

Obtains the value in the form of a long integer based on the specified column and the current row.

If the specified column or key is empty or the value is not of the long type, you need to determine whether to throw an exception.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name** | **Type**| **Mandatory**| Description                   |
| ----------- | -------- | -------- | ----------------------- |
| columnIndex | number   | Yes      | Index of the target column, starting from 0.|

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Value obtained.|

**Example**

```ts
let columnIndex = 1;
if (resultSet != undefined) {
  let goToFirstRow = (resultSet as DataShareResultSet).goToFirstRow();
  let getLong = (resultSet as DataShareResultSet).getLong(columnIndex);
  console.info('resultSet.getLong: ' + getLong);
}
```

### getDouble

getDouble(columnIndex: number): number

Obtains the value in the form of a double-precision floating-point number based on the specified column and the current row.

If the specified column or key is empty or the value is not of the double type, you need to determine whether to throw an exception.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name** | **Type**| **Mandatory**| Description                   |
| ----------- | -------- | -------- | ----------------------- |
| columnIndex | number   | Yes      | Index of the target column, starting from 0.|

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| number | Value obtained.|

**Example**

```ts
let columnIndex = 1;
if (resultSet != undefined) {
  let goToFirstRow = (resultSet as DataShareResultSet).goToFirstRow();
  let getDouble = (resultSet as DataShareResultSet).getDouble(columnIndex);
  console.info('resultSet.getDouble: ' + getDouble);
}
```

### close

close(): void

Closes this result set.

Calling this API will invalidate the result set and release all its resources.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Example**

```ts
if (resultSet != undefined) {
  (resultSet as DataShareResultSet).close();
}
```

### getColumnIndex

getColumnIndex(columnName: string): number

Obtains the column index based on a column name.

The column name is passed in as an input parameter.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| Description                      |
| ---------- | -------- | -------- | -------------------------- |
| columnName | string   | Yes      | Column name.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Column index obtained.|

**Example**

```ts
let ColumnName = "name";
if (resultSet != undefined) {
  let getColumnIndex = (resultSet as DataShareResultSet).getColumnIndex(ColumnName);
  console.info('resultSet.getColumnIndex: ' + getColumnIndex);
}
```

### getColumnName

getColumnName(columnIndex: number): string

Obtains the column name based on a column index.

The column index is passed in as an input parameter.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name** | **Type**| **Mandatory**| Description                      |
| ----------- | -------- | -------- | -------------------------- |
| columnIndex | number   | Yes      | Column index.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| string | Column name obtained.|

**Example**

```ts
let columnIndex = 1;
if (resultSet != undefined) {
  let getColumnName = (resultSet as DataShareResultSet).getColumnName(columnIndex);
  console.info('resultSet.getColumnName: ' + getColumnName);
}
```

### getDataType

getDataType(columnIndex: number): DataType

Obtains the data type based on the specified column index.

If the specified column or key is empty or the value is not of the DataType type, you need to determine whether to throw an exception.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

**Parameters**

| **Name** | **Type**| **Mandatory**| Description                      |
| ----------- | -------- | -------- | -------------------------- |
| columnIndex | number   | Yes      | Column index.|

**Return value**

| Type                 | Description              |
| --------------------- | ------------------ |
| [DataType](#datatype) | Data type obtained.|

**Example**

```ts
let columnIndex = 1;
if (resultSet != undefined) {
  let getDataType = (resultSet as DataShareResultSet).getDataType(columnIndex);
  console.info('resultSet.getDataType: ' + getDataType);
}
```

## DataType

Enumerates the data types.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Core

| Name       | Value| Description                |
| ----------- | ------ | -------------------- |
| TYPE_NULL   | 0      | Null.    |
| TYPE_LONG   | 1      | Long integer.  |
| TYPE_DOUBLE | 2      | Double-precision floating-point number.|
| TYPE_STRING | 3      | String.|
| TYPE_BLOB   | 4      | Byte array.|
