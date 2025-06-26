# Interface (ResultSet)

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { relationalStore } from '@kit.ArkData';
```

## ResultSet

提供通过查询数据库生成的数据库结果集的访问方法。结果集是指用户调用关系型数据库查询接口之后返回的结果集合，提供了多种灵活的数据访问方式，以便用户获取各项数据。

下列API示例中，都需先使用[query](arkts-apis-data-relationalStore-RdbStore.md#query)、[querySql](arkts-apis-data-relationalStore-RdbStore.md#querysql)、[remoteQuery](arkts-apis-data-relationalStore-RdbStore.md#remotequery-1)、[queryLockedRow](arkts-apis-data-relationalStore-RdbStore.md#querylockedrow12)等query类方法中任一方法获取到ResultSet实例，再通过此实例调用对应方法。

### 属性

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称         | 类型            | 必填 | 说明                             |
| ------------ | ------------------- | ---- | -------------------------------- |
| columnNames  | Array&lt;string&gt; | 是   | 获取结果集中所有列的名称。       |
| columnCount  | number              | 是   | 获取结果集中列的数量。             |
| rowCount     | number              | 是   | 获取结果集中行的数量。             |
| rowIndex     | number              | 是   | 获取结果集当前行的索引位置，默认值为-1。索引位置下标从0开始。 |
| isAtFirstRow | boolean             | 是   | 检查结果集指针是否位于第一行（行索引为0），true表示位于第一行，false表示不位于第一行。 |
| isAtLastRow  | boolean             | 是   | 检查结果集指针是否位于最后一行，true表示位于最后一行，false表示不位于最后一行。 |
| isEnded      | boolean             | 是   | 检查结果集指针是否位于最后一行之后，true表示位于最后一行之后，false表示不位于最后一行之后。 |
| isStarted    | boolean             | 是   | 检查指针是否移动过，true表示指针已移动过，false表示指针未移动过。             |
| isClosed     | boolean             | 是   | 检查当前结果集是否关闭，true表示结果集已关闭，false表示结果集未关闭。         |

### getColumnIndex

getColumnIndex(columnName: string): number

根据指定的列名获取列索引。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| columnName | string | 是   | 表示结果集中指定列的名称。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回指定列的索引。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("ID"));
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
```

### getColumnName

getColumnName(columnIndex: number): string

根据指定的列索引获取列名。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | -------------------------- |
| columnIndex | number | 是   | 表示结果集中指定列的索引。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 返回指定列的名称。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getColumnName(0);
  const name = (resultSet as relationalStore.ResultSet).getColumnName(1);
  const age = (resultSet as relationalStore.ResultSet).getColumnName(2);
}
```

### getColumnType<sup>18+</sup>

getColumnType(columnIdentifier: number | string): Promise\<ColumnType>

根据指定的列索引或列名称获取列数据类型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名           | 类型             | 必填 | 说明                                                         |
| ---------------- | ---------------- | ---- | ------------------------------------------------------------ |
| columnIdentifier | number \| string | 是   | 表示结果集中指定列的索引或名称。索引必须是非负整数，最大不能超过属性columnNames的长度。列名必须是属性columnNames内的名称。 |

**返回值：**

| 类型                                 | 说明                                |
| ------------------------------------ | ----------------------------------- |
| Promise<[ColumnType](arkts-apis-data-relationalStore-e.md#columntype18)> | Promise对象。返回指定列的数据类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

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

### getColumnTypeSync<sup>18+</sup>

getColumnTypeSync(columnIdentifier: number | string): ColumnType

根据指定的列索引或列名称获取列数据类型。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core 

**参数：**

| 参数名           | 类型             | 必填 | 说明                                                         |
| ---------------- | ---------------- | ---- | ------------------------------------------------------------ |
| columnIdentifier | number \| string | 是   | 表示结果集中指定列的索引或名称。索引必须是非负整数，最大不能超过属性columnNames的长度。列名必须是属性columnNames内的名称。 |

**返回值：**

| 类型                        | 说明                   |
| --------------------------- | ---------------------- |
| [ColumnType](arkts-apis-data-relationalStore-e.md#columntype18) | 返回指定列的数据类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

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

### goTo

goTo(offset:number): boolean

指定相对当前结果集指针位置的偏移量，以移动结果集的指针位置。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| offset | number | 是   | 表示相对当前结果集指针位置的偏移量，正值表示向后移动，负值表示向前移动。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goTo(1);
}
```

### goToRow

goToRow(position: number): boolean

转到结果集的指定行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明                     |
| -------- | ------ | ---- | ------------------------ |
| position | number | 是   | 表示要移动到的指定位置。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToRow(5);
}
```

### goToFirstRow

goToFirstRow(): boolean


转到结果集的第一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
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

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToFirstRow();
}
```

### goToLastRow

goToLastRow(): boolean

转到结果集的最后一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
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

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToLastRow();
}
```

### goToNextRow

goToNextRow(): boolean

转到结果集的下一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
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

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToNextRow();
}
```

### goToPreviousRow

goToPreviousRow(): boolean

转到结果集的上一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
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

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToPreviousRow();
}
```

### getValue<sup>12+</sup>

getValue(columnIndex: number): ValueType

获取当前行中指定列的值，如果值类型是ValueType中指定的任意类型，返回指定类型的值，否则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型       | 说明                             |
| ---------- | -------------------------------- |
| [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | 表示允许的数据字段类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**     |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getValue((resultSet as relationalStore.ResultSet).getColumnIndex("BIGINT_COLUMN"));
}
```

### getBlob

getBlob(columnIndex: number): Uint8Array


以字节数组的形式获取当前行中指定列的值，如果当前列的数据类型为INTEGER、DOUBLE、TEXT、BLOB类型，会转成字节数组类型返回指定值，如果该列内容为空时，会返回空字节数组，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型       | 说明                             |
| ---------- | -------------------------------- |
| Uint8Array | 以字节数组的形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getBlob((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

### getString

getString(columnIndex: number): string

以字符串形式获取当前行中指定列的值，如果当前列中的值为INTEGER、DOUBLE、TEXT、BLOB类型，会以字符串形式返回指定值，如果是当前列中的值为INTEGER，并且为空，则会返回空字符串""，其他类型则返回14800000。如果当前列中的值为DOUBLE类型，可能存在精度的丢失，建议使用[getDouble](#getdouble)接口获取。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| string | 以字符串形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
}
```

### getLong

getLong(columnIndex: number): number

以Long形式获取当前行中指定列的值，如果当前列的数据类型为INTEGER、DOUBLE、TEXT、BLOB类型，会转成Long类型返回指定值，如果该列内容为空时，会返回0，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 以Long形式返回指定列的值。<br>该接口支持的数据范围是：Number.MIN_SAFE_INTEGER ~ Number.MAX_SAFE_INTEGER，若超出该范围，建议使用[getDouble](#getdouble)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
}
```

### getDouble

getDouble(columnIndex: number): number

以double形式获取当前行中指定列的值，如果当前列的数据类型为INTEGER、DOUBLE、TEXT、BLOB类型，会转成double类型返回指定值，如果该列内容为空时，会返回0.0，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| number | 以double形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
```

### getAsset<sup>10+</sup>

getAsset(columnIndex: number): Asset

以[Asset](arkts-apis-data-relationalStore-i.md#asset10)形式获取当前行中指定列的值，如果当前列的数据类型为Asset类型，会以Asset类型返回指定值，如果当前列中的值为null时，会返回null，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名         | 类型     | 必填  | 说明           |
| ----------- | ------ | --- | ------------ |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型              | 说明                         |
| --------------- | -------------------------- |
| [Asset](arkts-apis-data-relationalStore-i.md#asset10) | 以Asset形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const doc = (resultSet as relationalStore.ResultSet).getAsset((resultSet as relationalStore.ResultSet).getColumnIndex("DOC"));
}
```

### getAssets<sup>10+</sup>

getAssets(columnIndex: number): Assets

以[Assets](arkts-apis-data-relationalStore-t.md#assets10)形式获取当前行中指定列的值，如果当前列的数据类型为Assets类型，会以Assets类型返回指定值，如果当前列中的值为null时，会返回null，其他类型则返回14800000。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名         | 类型     | 必填  | 说明           |
| ----------- | ------ | --- | ------------ |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
| [Assets](arkts-apis-data-relationalStore-t.md#assets10)| 以Assets形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const docs = (resultSet as relationalStore.ResultSet).getAssets((resultSet as relationalStore.ResultSet).getColumnIndex("DOCS"));
}
```

### getRow<sup>11+</sup>

getRow(): ValuesBucket

获取当前行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
| [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket) | 返回指定行的值。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
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

**示例：**

```ts
if (resultSet != undefined) {
  const row = (resultSet as relationalStore.ResultSet).getRow();
}
```

### getRows<sup>18+</sup>

getRows(maxCount: number, position?: number): Promise<Array\<ValuesBucket>>

从结果集中获取指定数量的数据，使用Promise异步回调。禁止与[ResultSet](arkts-apis-data-relationalStore-ResultSet.md#resultset)的其他接口并发调用，否则获取的数据可能非预期。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| maxCount | number | 是   | 正整数，指定要从结果集中获取数据的条数。不为正整数则参数非法，抛出错误码401。 |
| position | number | 否   | 非负整数，指定从结果集中获取数据的起始位置，不填则从结果集的当前行（默认首次获取数据时为当前结果集的第一行）开始获取数据。不为非负整数则参数非法，抛出错误码401。 |


**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
| Promise<Array<[ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)>> | 返回maxCount条数据，剩余数据不足maxCount条则返回剩余数据，返回空数组时代表已经遍历到结果集的末尾。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
// 以查到100条数据为例
async function proccessRows(resultSet: relationalStore.ResultSet) {
  // 示例1：仅指定maxCount
  if (resultSet != undefined) {
    let rows: Array<relationalStore.ValuesBucket>;
    let maxCount: number = 50;
    // 从结果集的当前行（默认首次获取数据时为当前结果集的第一行，后续为上次获取数据结束位置的下一行）开始获取数据
    // getRows会自动移动结果集当前行到上次getRows获取结束位置的下一行，无需使用goToFirstRow、goToNextRow等接口移动
    while ((rows = await (resultSet as relationalStore.ResultSet).getRows(maxCount)).length != 0) {
      console.info(JSON.stringify(rows[0]));
    }
  }

  // 示例2：指定maxCount和起始的position
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

### getSendableRow<sup>12+</sup>

getSendableRow(): sendableRelationalStore.ValuesBucket

获取当前行数据的sendable形式，用于跨线程传递。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型                                                                                           | 说明                                         |
| ---------------------------------------------------------------------------------------------- | -------------------------------------------- |
| [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket) | 当前行数据的sendable形式，用于跨线程传递。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                  |
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

**示例：**

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

### isColumnNull

isColumnNull(columnIndex: number): boolean

检查当前行中指定列的值是否为null。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型    | 说明                                                      |
| ------- | --------------------------------------------------------- |
| boolean | 如果当前行中指定列的值为null，则返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------- |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
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

**示例：**

```ts
if (resultSet != undefined) {
  const isColumnNull = (resultSet as relationalStore.ResultSet).isColumnNull((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

### getValueForFlutter<sup>20+</sup>

getValueForFlutter(columnIndex: number): ValueType

获取当前行中指定列的值，如果当前行中指定列的值是数字且超出number的取值范围，将转换为字符串类型返回。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始的整数。 |

**返回值：**

| 类型       | 说明                             |
| ---------- | -------------------------------- |
| [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | 返回当前行中指定列对应数据字段类型的值。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**     |
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

**示例：**

```ts
if (resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getValueForFlutter((resultSet as relationalStore.ResultSet).getColumnIndex("BIGINT_COLUMN"));
}
```

### getRowForFlutter<sup>20+</sup>

getRowForFlutter(): ValuesBucket

获取指定行中所有列的值，如果当前行中指定列的值是数字且超出number的取值范围，将转换为字符串类型返回。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型              | 说明                           |
| ---------------- | ---------------------------- |
| [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket) | 返回指定行中所有列的值。|

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。其中，14800011错误码处理可参考[数据库备份与恢复](../../database/data-backup-and-restore.md)。

| **错误码ID** | **错误信息**                                                 |
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

**示例：**

```ts
if (resultSet != undefined) {
  const row = (resultSet as relationalStore.ResultSet).getRowForFlutter();
}
```

### close

close(): void

关闭结果集，若不关闭可能会引起fd泄露和内存泄露。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).close();
}
```

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800012  | ResultSet is empty or pointer index is out of bounds. |