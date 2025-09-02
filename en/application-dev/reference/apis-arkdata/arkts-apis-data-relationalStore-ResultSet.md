# Interface (ResultSet)

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Provides APIs to access the result set obtained by querying the RDB store. returned by **query()**.

For the following APIs, you should use either [query](arkts-apis-data-relationalStore-RdbStore.md#query), [querySql](arkts-apis-data-relationalStore-RdbStore.md#querysql), [remoteQuery](arkts-apis-data-relationalStore-RdbStore.md#remotequery-1), or [queryLockedRow](arkts-apis-data-relationalStore-RdbStore.md#querylockedrow12) to obtain the **ResultSet** instance first, and then use this instance to call the corresponding method.

## Module to Import

```ts
import { relationalStore } from '@kit.ArkData';
```

## Property

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name        | Type           | Mandatory| Description                            |
| ------------ | ------------------- | ---- | -------------------------------- |
| columnNames  | Array&lt;string&gt; | Yes  | Names of all columns in the result set.      |
| columnCount  | number              | Yes  | Number of columns in the result set.            |
| rowCount     | number              | Yes  | Number of rows in the result set.            |
| rowIndex     | number              | Yes  | Index of the current row in the result set.<br>Default value: **-1**. The index position starts from **0**.|
| isAtFirstRow | boolean             | Yes  | Whether the result set pointer is in the first row (the row index is **0**). The value **true** means the result set pointer is in the first row.|
| isAtLastRow  | boolean             | Yes  | Whether the result set pointer is in the last row. The value **true** means the pointer is in the last row.|
| isEnded      | boolean             | Yes  | Whether the result set pointer is after the last row. The value **true** means the pointer is after the last row.|
| isStarted    | boolean             | Yes  | Whether the result set pointer is moved. The value **true** means the pointer is moved.            |
| isClosed     | boolean             | Yes  | Whether the result set is closed. The value **true** means the result set is closed.        |

## getColumnIndex

getColumnIndex(columnName: string): number

Obtains the column index based on the column name.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| columnName | string | Yes  | Column name.|

**Returns**:

| Type  | Description              |
| ------ | ------------------ |
| number | Column index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("ID"));
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
```

## getColumnName

getColumnName(columnIndex: number): string

Obtains the column name based on the column index.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | -------------------------- |
| columnIndex | number | Yes  | Column index.|

**Returns**:

| Type  | Description              |
| ------ | ------------------ |
| string | Column name obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getColumnName(0);
  const name = (resultSet as relationalStore.ResultSet).getColumnName(1);
  const age = (resultSet as relationalStore.ResultSet).getColumnName(2);
}
```

## getColumnType<sup>18+</sup>

getColumnType(columnIdentifier: number | string): Promise\<ColumnType>

Obtains the column data type based on the specified column index or column name. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name          | Type            | Mandatory| Description                                                        |
| ---------------- | ---------------- | ---- | ------------------------------------------------------------ |
| columnIdentifier | number \| string | Yes  | Index or name of column in a result set. The index must be a non-negative integer and cannot exceed the length of **columnNames**. The column name must be a name in **columnNames**.|

**Returns**:

| Type                                | Description                               |
| ------------------------------------ | ----------------------------------- |
| Promise<[ColumnType](arkts-apis-data-relationalStore-e.md#columntype18)> | Promise used to return the column type obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                 |
| 14800011     | Failed to open the database because it is corrupted. |
| 14800012     | ResultSet is empty or pointer index is out of bounds.                                           |
| 14800013     | Resultset is empty or column index is out of bounds.                                        |
| 14800014     | The RdbStore or ResultSet is already closed.                                              |
| 14800019     | The SQL must be a query statement.                           |
| 14800021     | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.                                     |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |

**Example**:

```ts
if (resultSet != undefined) {
  let idType = await (resultSet as relationalStore.ResultSet).getColumnType("ID") as relationalStore.ColumnType;
  let nameType = await (resultSet as relationalStore.ResultSet).getColumnType("NAME") as relationalStore.ColumnType;
  let ageType = await (resultSet as relationalStore.ResultSet).getColumnType("AGE") as relationalStore.ColumnType;
  let salaryType = await (resultSet as relationalStore.ResultSet).getColumnType("SALARY") as relationalStore.ColumnType;
  let codesType = await (resultSet as relationalStore.ResultSet).getColumnType("CODES") as relationalStore.ColumnType;
  let identityType = await (resultSet as relationalStore.ResultSet).getColumnType(5) as relationalStore.ColumnType;
  let assetDataType = await (resultSet as relationalStore.ResultSet).getColumnType(6) as relationalStore.ColumnType;
  let assetsDataType = await (resultSet as relationalStore.ResultSet).getColumnType(7) as relationalStore.ColumnType;
  let floatArrayType = await (resultSet as relationalStore.ResultSet).getColumnType(8) as relationalStore.ColumnType;
}
```

## getColumnTypeSync<sup>18+</sup>

getColumnTypeSync(columnIdentifier: number | string): ColumnType

Obtains the column data type based on the specified column index or column name. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name          | Type            | Mandatory| Description                                                        |
| ---------------- | ---------------- | ---- | ------------------------------------------------------------ |
| columnIdentifier | number \| string | Yes  | Index or name of column in a result set. The index must be a non-negative integer and cannot exceed the length of **columnNames**. The column name must be a name in **columnNames**.|

**Returns**:

| Type                       | Description                  |
| --------------------------- | ---------------------- |
| [ColumnType](arkts-apis-data-relationalStore-e.md#columntype18) | Column type obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                 |
| 14800011     | Failed to open the database because it is corrupted. |
| 14800012     | ResultSet is empty or pointer index is out of bounds.                                           |
| 14800013     | Resultset is empty or column index is out of bounds.                                        |
| 14800014     | The RdbStore or ResultSet is already closed.                                              |
| 14800019     | The SQL must be a query statement.                           |
| 14800021     | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.                                     |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |

**Example**:

```ts
if (resultSet != undefined) {
  let idType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("ID") as relationalStore.ColumnType;
  let nameType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("NAME") as relationalStore.ColumnType;
  let ageType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("AGE") as relationalStore.ColumnType;
  let salaryType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("SALARY") as relationalStore.ColumnType;
  let codesType = (resultSet as relationalStore.ResultSet).getColumnTypeSync("CODES") as relationalStore.ColumnType;
  let identityType = (resultSet as relationalStore.ResultSet).getColumnTypeSync(5) as relationalStore.ColumnType;
  let assetDataType = (resultSet as relationalStore.ResultSet).getColumnTypeSync(6) as relationalStore.ColumnType;
  let assetsDataType = (resultSet as relationalStore.ResultSet).getColumnTypeSync(7) as relationalStore.ColumnType;
  let floatArrayType = (resultSet as relationalStore.ResultSet).getColumnTypeSync(8) as relationalStore.ColumnType;
}
```

## goTo

goTo(offset:number): boolean

Moves the result set pointer based on the offset specified.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                        |
| ------ | ------ | ---- | ---------------------------- |
| offset | number | Yes  | Offset relative to the position of the current result set pointer. A positive value means to move the pointer backward, and a negative value means to move the pointer forward.|

**Returns**:

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goTo(1);
}
```

## goToRow

goToRow(position: number): boolean

Moves to the specified row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type  | Mandatory| Description                    |
| -------- | ------ | ---- | ------------------------ |
| position | number | Yes  | Destination position to move to.|

**Returns**:

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToRow(5);
}
```

## goToFirstRow

goToFirstRow(): boolean


Moves to the first row of the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Returns**:

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToFirstRow();
}
```

## goToLastRow

goToLastRow(): boolean

Moves to the last row of the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Returns**:

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToLastRow();
}
```

## goToNextRow

goToNextRow(): boolean

Moves to the next row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Returns**:

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToNextRow();
}
```

## goToPreviousRow

goToPreviousRow(): boolean

Moves to the previous row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Returns**:

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToPreviousRow();
}
```

## getValue<sup>12+</sup>

getValue(columnIndex: number): ValueType

Obtains the value from the specified column and current row. If the value type is any of **ValueType**, the value of the corresponding type will be returned. Otherwise, **14800000** will be returned.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type      | Description                            |
| ---------- | -------------------------------- |
| [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Allowed data field types.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**    |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error.      |
| 14800011  | Failed to open the database because it is corrupted.        |
| 14800012  | ResultSet is empty or pointer index is out of bounds.       |
| 14800013  | Resultset is empty or column index is out of bounds.   |
| 14800014  | The RdbStore or ResultSet is already closed.       |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.    |
| 14800022  | SQLite: Callback routine requested an abort.     |
| 14800023  | SQLite: Access permission denied.    |
| 14800024  | SQLite: The database file is locked.    |
| 14800025  | SQLite: A table in the database is locked.  |
| 14800026  | SQLite: The database is out of memory.    |
| 14800027  | SQLite: Attempt to write a readonly database.    |
| 14800028  | SQLite: Some kind of disk I/O error occurred.    |
| 14800029  | SQLite: The database is full.   |
| 14800030  | SQLite: Unable to open the database file.    |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.    |
| 14800032  | SQLite: Abort due to constraint violation.   |
| 14800033  | SQLite: Data type mismatch.      |
| 14800034  | SQLite: Library used incorrectly.    |

**Example**:

```ts
if (resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getValue((resultSet as relationalStore.ResultSet).getColumnIndex("BIGINT_COLUMN"));
}
```

## getBlob

getBlob(columnIndex: number): Uint8Array


Obtains the value from the specified column and current row, and returns it in a byte array.<br>If the type of the value in the specified column is INTEGER, DOUBLE, TEXT, or BLOB, the value will be converted into a byte array and returned. If the column is empty, an empty byte array will be returned. If the value is of any other type, **14800000** will be returned.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type      | Description                            |
| ---------- | -------------------------------- |
| Uint8Array | Value obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getBlob((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

## getString

getString(columnIndex: number): string

Obtains the value from the specified column and current row, and returns it in the form of a string.<br>If the type of the value in the specified column is INTEGER, DOUBLE, TEXT, or BLOB, a string will be returned. If the value type is INTEGER and the column is empty, an empty string will be returned. If the value is of any other type, **14800000** will be returned. If the value in the current column is of the DOUBLE type, the precision may be lost. You are advised to use [getDouble](#getdouble) to obtain the value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type  | Description                        |
| ------ | ---------------------------- |
| string | Value obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
}
```

## getLong

getLong(columnIndex: number): number

Obtains the value from the specified column and current row, and returns a value of Long type.<br>If the type of the value in the specified column is INTEGER, DOUBLE, TEXT, or BLOB, a value of Long type will be returned. If the column is empty, **0** will be returned. If the value is of any other type, **14800000** will be returned.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Value obtained.<br>The value range supported by this API is **Number.MIN_SAFE_INTEGER** to **Number.MAX_SAFE_INTEGER**. If the value is out of this range, use [getDouble](#getdouble).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
}
```

## getDouble

getDouble(columnIndex: number): number

Obtains the value from the specified column and current row, and returns a value of double type.<br>If the type of the value in the specified column is INTEGER, DOUBLE, TEXT, or BLOB, a value of double type will be returned. If the column is empty, **0.0** will be returned. If the value is of any other type, **14800000** will be returned.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type  | Description                        |
| ------ | ---------------------------- |
| number | Value obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
```

## getAsset<sup>10+</sup>

getAsset(columnIndex: number): Asset

Obtains the value from the specified column and current row, and returns the value in the [Asset](arkts-apis-data-relationalStore-i.md#asset10) format. If the type of the value in the column is **Asset**, the value of the Asset type is returned. If the value in the column is null, **null** is returned. If the value in the column is of other types, **14800000** is returned.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name        | Type    | Mandatory | Description          |
| ----------- | ------ | --- | ------------ |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type             | Description                        |
| --------------- | -------------------------- |
| [Asset](arkts-apis-data-relationalStore-i.md#asset10) | Value obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const doc = (resultSet as relationalStore.ResultSet).getAsset((resultSet as relationalStore.ResultSet).getColumnIndex("DOC"));
}
```

## getAssets<sup>10+</sup>

getAssets(columnIndex: number): Assets

Obtains the value from the specified column and current row, and returns the value in the [Assets](arkts-apis-data-relationalStore-t.md#assets10) format. If the type of the value in the column is **Assets**, the value of the Assets type is returned. If the value in the column is null, **null** is returned. If the value in the column is of other types, **14800000** is returned.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name        | Type    | Mandatory | Description          |
| ----------- | ------ | --- | ------------ |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type             | Description                          |
| ---------------- | ---------------------------- |
| [Assets](arkts-apis-data-relationalStore-t.md#assets10)| Value obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const docs = (resultSet as relationalStore.ResultSet).getAssets((resultSet as relationalStore.ResultSet).getColumnIndex("DOCS"));
}
```

## getRow<sup>11+</sup>

getRow(): ValuesBucket

Obtains the current row.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Returns**:

| Type             | Description                          |
| ---------------- | ---------------------------- |
| [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket) | Value of the specified row.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const row = (resultSet as relationalStore.ResultSet).getRow();
}
```

## getRows<sup>18+</sup>

getRows(maxCount: number, position?: number): Promise<Array\<ValuesBucket>>

Obtains a specified amount of data from the result set. This API uses a promise to return the result. Do not call this API concurrently with other APIs of [ResultSet](arkts-apis-data-relationalStore-ResultSet.md). Otherwise, unexpected data may be obtained.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| maxCount | number | Yes  | Number of rows to obtain. The value is a positive integer. If the value is not a positive integer, error 401 will be thrown.|
| position | number | No  | Start position for obtaining data from the result set. The value is a non-negative integer. If this parameter is not specified, data is obtained from the current row of the result set (by default, it is the first row of the result set when data is obtained for the first time). If it is not a non-negative integer, error code 401 will be thrown.|


**Returns**:

| Type             | Description                          |
| ---------------- | ---------------------------- |
| Promise<Array<[ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)>> | Promise used to return **maxCount** rows of data obtained. If the number of remaining records is less than **maxCount**, the remaining records are returned. Returning an empty array indicates that the end of the result set is reached.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |

**Example**:

```ts
// Obtain 100 rows of data.
async function proccessRows(resultSet: relationalStore.ResultSet) {
  // Example 1: Specify only maxCount.
  if (resultSet != undefined) {
    let rows: Array<relationalStore.ValuesBucket>;
    let maxCount: number = 50;
    // Obtain data from the current row of the result set. By default, the first fetch starts from the first row of the current result set. Subsequent fetches start from the row following the last row retrieved.
    // getRows automatically moves the current row of the result set to the row following the last row retrieved by the previous getRows call. You do not need to use APIs such as goToFirstRow and goToNextRow.
    while ((rows = await (resultSet as relationalStore.ResultSet).getRows(maxCount)).length != 0) {
      console.info(JSON.stringify(rows[0]));
    }
  }

  // Example 2: Specify maxCount and position.
  if (resultSet != undefined) {
    let rows: Array<relationalStore.ValuesBucket>;
    let maxCount: number = 50;
    let position: number = 50;
    while ((rows = await (resultSet as relationalStore.ResultSet).getRows(maxCount, position)).length != 0) {
      console.info(JSON.stringify(rows[0]));
      position += rows.length;
    }
  }
}
```

## getSendableRow<sup>12+</sup>

getSendableRow(): sendableRelationalStore.ValuesBucket

Obtains the sendable data from the current row. The sendable data can be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Returns**:

| Type                                                                                          | Description                                        |
| ---------------------------------------------------------------------------------------------- | -------------------------------------------- |
| [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket) | Sendable data obtained for cross-thread transfer.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                 |
| ------------ | --------------------------------------------- |
| 14800000     | Inner error.                                  |
| 14800011     | Failed to open the database because it is corrupted.                           |
| 14800012     | ResultSet is empty or pointer index is out of bounds.                            |
| 14800013     | Resultset is empty or column index is out of bounds.                         |
| 14800014     | The RdbStore or ResultSet is already closed.                               |
| 14800021     | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.                        |
| 14800022     | SQLite: Callback routine requested an abort.  |
| 14800023     | SQLite: Access permission denied.             |
| 14800024     | SQLite: The database file is locked.          |
| 14800025     | SQLite: A table in the database is locked.    |
| 14800026     | SQLite: The database is out of memory.        |
| 14800027     | SQLite: Attempt to write a readonly database. |
| 14800028     | SQLite: Some kind of disk I/O error occurred. |
| 14800029     | SQLite: The database is full.                 |
| 14800030     | SQLite: Unable to open the database file.     |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.      |
| 14800032     | SQLite: Abort due to constraint violation.    |
| 14800033     | SQLite: Data type mismatch.                   |
| 14800034     | SQLite: Library used incorrectly.             |

**Example**:

<!--code_no_check-->
```ts
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { relationalStore } from '@kit.ArkData';
import { taskpool } from '@kit.ArkTS';
import type ctx from '@ohos.app.ability.common';
import { sendableRelationalStore } from '@kit.ArkData';

@Concurrent
async function getDataByName(name: string, context: ctx.UIAbilityContext) {
  const STORE_CONFIG: relationalStore.StoreConfig = {
    name: "RdbTest.db",
    securityLevel: relationalStore.SecurityLevel.S3
  };
  const store = await relationalStore.getRdbStore(context, STORE_CONFIG);
  const predicates = new relationalStore.RdbPredicates("EMPLOYEE");
  predicates.equalTo("NAME", name);
  const resultSet = store.querySync(predicates);

  if (resultSet.rowCount > 0) {
    resultSet.goToFirstRow();
    const sendableValuesBucket = resultSet.getSendableRow();
    return sendableValuesBucket;
  } else {
    return null;
  }
}

export default class EntryAbility extends UIAbility {
  async onWindowStageCreate(windowStage: window.WindowStage) {
    const task = new taskpool.Task(getDataByName, 'Lisa', this.context);
    const sendableValuesBucket = await taskpool.execute(task) as sendableRelationalStore.ValuesBucket;

    if (sendableValuesBucket) {
      const columnCount = sendableValuesBucket.size;
      const age = sendableValuesBucket.get('age');
      const name = sendableValuesBucket.get('name');
      console.info(`Query data in taskpool succeeded, name is "${name}", age is "${age}"`);
    }
  }
}
```

## isColumnNull

isColumnNull(columnIndex: number): boolean

Checks whether the value in the specified column is null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type   | Description                                                     |
| ------- | --------------------------------------------------------- |
| boolean | Returns **true** if the value is null; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------- |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800013  | Resultset is empty or column index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**:

```ts
if (resultSet != undefined) {
  const isColumnNull = (resultSet as relationalStore.ResultSet).isColumnNull((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

## getValueForFlutter<sup>20+</sup>

getValueForFlutter(columnIndex: number): ValueType

Obtains the value from the specified column and current row. If the value is a number and exceeds the value range of **number**, the value is returned as a string.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Returns**:

| Type      | Description                            |
| ---------- | -------------------------------- |
| [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | Value obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**    |
|-----------|---------|
| 14800011  | Failed to open the database because it is corrupted.        |
| 14800012  | ResultSet is empty or pointer index is out of bounds.       |
| 14800013  | Resultset is empty or column index is out of bounds.   |
| 14800014  | The RdbStore or ResultSet is already closed.       |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.    |
| 14800023  | SQLite: Access permission denied.    |
| 14800024  | SQLite: The database file is locked.    |
| 14800025  | SQLite: A table in the database is locked.  |
| 14800028  | SQLite: Some kind of disk I/O error occurred.    |
| 14800030  | SQLite: Unable to open the database file.    |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.    |

**Example**:

```ts
if (resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getValueForFlutter((resultSet as relationalStore.ResultSet).getColumnIndex("BIGINT_COLUMN"));
}
```

## getRowForFlutter<sup>20+</sup>

getRowForFlutter(): ValuesBucket

Obtains the value from the specified column and all rows. If the value is a number and exceeds the value range of **number**, the value is returned as a string.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Returns**:

| Type             | Description                          |
| ---------------- | ---------------------------- |
| [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket) | Value obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |

**Example**:

```ts
if (resultSet != undefined) {
  const row = (resultSet as relationalStore.ResultSet).getRowForFlutter();
}
```

## close

close(): void

Closes this **resultSet** to release memory. If the **resultSet** is not closed, FD or memory leaks may occur.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**:

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).close();
}
```

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |
