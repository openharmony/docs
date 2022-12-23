# resultSet (结果集)

结果集是指用户调用关系型数据库查询接口之后返回的结果集合，提供了多种灵活的数据访问方式，以便用户获取各项数据。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ResultSetV9<sup>9+</sup>

提供通过查询数据库生成的数据库结果集的访问方法。

### 使用说明

需要通过[RdbStoreV9.query()](js-apis-data-rdb.md#query)获取resultSetV9对象。

```js
import dataRdb from '@ohos.data.rdb';
let predicatesV9 = new dataRdb.RdbPredicatesV9("EMPLOYEE");
predicatesV9.equalTo("AGE", 18);
let promise = rdbStoreV9.query(predicatesV9, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSetV9) => {
    console.log(TAG + "resultSet columnNames:" + resultSetV9.columnNames);
    console.log(TAG + "resultSet columnCount:" + resultSetV9.columnCount);
});
```

### 属性<sup>9+</sup>

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称         | 类型            | 必填 | 说明                             |
| ------------ | ------------------- | ---- | -------------------------------- |
| columnNames  | Array&lt;string&gt; | 是   | 获取结果集中所有列的名称。       |
| columnCount  | number              | 是   | 获取结果集中的列数。             |
| rowCount     | number              | 是   | 获取结果集中的行数。             |
| rowIndex     | number              | 是   | 获取结果集当前行的索引。         |
| isAtFirstRow | boolean             | 是   | 检查结果集是否位于第一行。       |
| isAtLastRow  | boolean             | 是   | 检查结果集是否位于最后一行。     |
| isEnded      | boolean             | 是   | 检查结果集是否位于最后一行之后。 |
| isStarted    | boolean             | 是   | 检查指针是否移动过。             |
| isClosed     | boolean             | 是   | 检查当前结果集是否关闭。         |

### getColumnIndex<sup>9+</sup>

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

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is  null or the column type is incompatible. |

**示例：**

  ```js
resultSetV9.goToFirstRow();
const id = resultSetV9.getLong(resultSetV9.getColumnIndex("ID"));
const name = resultSetV9.getString(resultSetV9.getColumnIndex("NAME"));
const age = resultSetV9.getLong(resultSetV9.getColumnIndex("AGE"));
const salary = resultSetV9.getDouble(resultSetV9.getColumnIndex("SALARY"));
  ```

### getColumnName<sup>9+</sup>

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

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is  null or the column type is incompatible. |

**示例：**

  ```js
const id = resultSetV9.getColumnName(0);
const name = resultSetV9.getColumnName(1);
const age = resultSetV9.getColumnName(2);
  ```

### goTo<sup>9+</sup>

goTo(offset:number): boolean

向前或向后转至结果集的指定行，相对于其当前位置偏移。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| offset | number | 是   | 表示相对于当前位置的偏移量。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is  empty or the specified location is invalid. |

**示例：**

  ```js
let predicatesV9goto = new dataRdb.RdbPredicatesV9("EMPLOYEE");
let promisequerygoto = rdbStoreV9.query(predicatesV9goto, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoto.then((resultSetV9) => {
    resultSetV9.goTo(1);
    resultSetV9.close();
}).catch((err) => {
    console.log('query failed');
});
  ```

### goToRow<sup>9+</sup>

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

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is  empty or the specified location is invalid. |

**示例：**

  ```js
let predicatesV9gotorow = new dataRdb.RdbPredicatesV9("EMPLOYEE");
let promisequerygotorow = rdbStoreV9.query(predicatesV9gotorow, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygotorow.then((resultSetV9) => {
    resultSetV9.goToRow(5);
    resultSetV9.close();
}).catch((err) => {
    console.log('query failed');
});
  ```

### goToFirstRow<sup>9+</sup>

goToFirstRow(): boolean


转到结果集的第一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is  empty or the specified location is invalid. |

**示例：**

  ```js
let predicatesV9goFirst = new dataRdb.RdbPredicatesV9("EMPLOYEE");
let promisequerygoFirst = rdbStoreV9.query(predicatesV9goFirst, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoFirst.then((resultSetV9) => {
    resultSetV9.goToFirstRow();
    resultSetV9.close();
}).catch((err) => {
    console.log('query failed');
});
  ```

### goToLastRow<sup>9+</sup>

goToLastRow(): boolean

转到结果集的最后一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is  empty or the specified location is invalid. |

**示例：**

  ```js
let predicatesV9goLast = new dataRdb.RdbPredicatesV9("EMPLOYEE");
let promisequerygoLast = rdbStoreV9.query(predicatesV9goLast, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoLast.then((resultSetV9) => {
    resultSetV9.goToLastRow();
    resultSetV9.close();
}).catch((err) => {
    console.log('query failed');
});
  ```

### goToNextRow<sup>9+</sup>

goToNextRow(): boolean

转到结果集的下一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is  empty or the specified location is invalid. |

**示例：**

  ```js
let predicatesV9goNext = new dataRdb.RdbPredicatesV9("EMPLOYEE");
let promisequerygoNext = rdbStoreV9.query(predicatesV9goNext, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoNext.then((resultSetV9) => {
    resultSetV9.goToNextRow();
    resultSetV9.close();
}).catch((err) => {
    console.log('query failed');
});
  ```

### goToPreviousRow<sup>9+</sup>

goToPreviousRow(): boolean

转到结果集的上一行。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is  empty or the specified location is invalid. |

**示例：**

  ```js
let predicatesV9goPrev = new dataRdb.RdbPredicatesV9("EMPLOYEE");
let promisequerygoPrev = rdbStoreV9.query(predicatesV9goPrev, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promisequerygoPrev.then((resultSetV9) => {
    resultSetV9.goToPreviousRow();
    resultSetV9.close();
}).catch((err) => {
    console.log('query failed');
});
  ```

### getBlob<sup>9+</sup>

getBlob(columnIndex: number): Uint8Array

以字节数组的形式获取当前行中指定列的值。

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

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is  null or the column type is incompatible. |

**示例：**

  ```js
const codes = resultSetV9.getBlob(resultSetV9.getColumnIndex("CODES"));
  ```

### getString<sup>9+</sup>

getString(columnIndex: number): string

以字符串形式获取当前行中指定列的值。

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

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is  null or the column type is incompatible. |

**示例：**

  ```js
const name = resultSetV9.getString(resultSetV9.getColumnIndex("NAME"));
  ```

### getLong<sup>9+</sup>

getLong(columnIndex: number): number

以Long形式获取当前行中指定列的值。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                    |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | 是   | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 以Long形式返回指定列的值。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is  null or the column type is incompatible. |

**示例：**

  ```js
const age = resultSetV9.getLong(resultSetV9.getColumnIndex("AGE"));
  ```

### getDouble<sup>9+</sup>

getDouble(columnIndex: number): number

以double形式获取当前行中指定列的值。

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

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is  null or the column type is incompatible. |

**示例：**

  ```js
const salary = resultSetV9.getDouble(resultSetV9.getColumnIndex("SALARY"));
  ```

### isColumnNull<sup>9+</sup>

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

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is  null or the column type is incompatible. |

**示例：**

  ```js
const isColumnNull = resultSetV9.isColumnNull(resultSetV9.getColumnIndex("CODES"));
  ```

### close<sup>9+</sup>

close(): void

关闭结果集。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

  ```js
let predicatesV9Close = new dataRdb.RdbPredicatesV9("EMPLOYEE");
let promiseClose = rdbStoreV9.query(predicatesV9Close, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promiseClose.then((resultSetV9) => {
    resultSetV9.close();
}).catch((err) => {
    console.log('resultset close failed');
});
  ```

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is  empty or the specified location is invalid. |

## ResultSet<sup>(deprecated)</sup>

提供通过查询数据库生成的数据库结果集的访问方法。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[ResultSetV9](#resultsetv99)替代。

### 使用说明

需要通过[RdbStore.query()](js-apis-data-rdb.md#query)获取resultSet对象。

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

### 属性<sup>(deprecated)</sup>

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[属性](#属性9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| columnNames | Array&lt;string&gt; | 是 | 获取结果集中所有列的名称。 |
| columnCount | number | 是 | 获取结果集中的列数。 |
| rowCount | number | 是 | 获取结果集中的行数。 |
| rowIndex | number | 是 | 获取结果集当前行的索引。 |
| isAtFirstRow | boolean | 是 | 检查结果集是否位于第一行。 |
| isAtLastRow | boolean | 是 | 检查结果集是否位于最后一行。 |
| isEnded | boolean | 是 | 检查结果集是否位于最后一行之后。 |
| isStarted | boolean | 是 | 检查指针是否移动过。 |
| isClosed | boolean | 是 | 检查当前结果集是否关闭。 |

### getColumnIndex<sup>(deprecated)</sup>

getColumnIndex(columnName: string): number

根据指定的列名获取列索引。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[getColumnIndex](#getcolumnindex9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnName | string | 是 | 表示结果集中指定列的名称。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回指定列的索引。 |

**示例：**

  ```js
  resultSet.goToFirstRow();
  const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
  const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
  const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
  const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
  ```

### getColumnName<sup>(deprecated)</sup>

getColumnName(columnIndex: number): string

根据指定的列索引获取列名。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[getColumnName](#getcolumnname9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 表示结果集中指定列的索引。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回指定列的名称。 |

**示例：**

  ```js
  const id = resultSet.getColumnName(0);
  const name = resultSet.getColumnName(1);
  const age = resultSet.getColumnName(2);
  ```

### goTo<sup>(deprecated)</sup>

goTo(offset:number): boolean

向前或向后转至结果集的指定行，相对于其当前位置偏移。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[goTo](#goto9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | offset | number | 是 | 表示相对于当前位置的偏移量。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

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

### goToRow<sup>(deprecated)</sup>

goToRow(position: number): boolean

转到结果集的指定行。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[goToRow](#gotorow9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | position | number | 是 | 表示要移动到的指定位置。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

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

### goToFirstRow<sup>(deprecated)</sup>

goToFirstRow(): boolean

转到结果集的第一行。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[goToFirstRow](#gotofirstrow9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

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

### goToLastRow<sup>(deprecated)</sup>

goToLastRow(): boolean

转到结果集的最后一行。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[goToLastRow](#gotolastrow9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

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

### goToNextRow<sup>(deprecated)</sup>

goToNextRow(): boolean

转到结果集的下一行。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[goToNextRow](#gotonextrow9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

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

### goToPreviousRow<sup>(deprecated)</sup>

goToPreviousRow(): boolean

转到结果集的上一行。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[goToPreviousRow](#gotopreviousrow9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

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

### getBlob<sup>(deprecated)</sup>

getBlob(columnIndex: number): Uint8Array

以字节数组的形式获取当前行中指定列的值。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[getBlob](#getblob9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Uint8Array | 以字节数组的形式返回指定列的值。 |

**示例：**

  ```js
  const codes = resultSet.getBlob(resultSet.getColumnIndex("CODES"));
  ```

### getString<sup>(deprecated)</sup>

getString(columnIndex: number): string

以字符串形式获取当前行中指定列的值。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[getString](#getstring9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | string | 以字符串形式返回指定列的值。 |

**示例：**

  ```js
  const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
  ```

### getLong<sup>(deprecated)</sup>

getLong(columnIndex: number): number

以Long形式获取当前行中指定列的值。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[getLong](#getlong9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 以Long形式返回指定列的值。 |

**示例：**

  ```js
  const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
  ```

### getDouble<sup>(deprecated)</sup>

getDouble(columnIndex: number): number

以double形式获取当前行中指定列的值。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[getDouble](#getdouble9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 以double形式返回指定列的值。 |

**示例：**

  ```js
  const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
  ```

### isColumnNull<sup>(deprecated)</sup>

isColumnNull(columnIndex: number): boolean

检查当前行中指定列的值是否为null。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[isColumnNull](#iscolumnnull9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | columnIndex | number | 是 | 指定的列索引，从0开始。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果当前行中指定列的值为null，则返回true，否则返回false。 |

**示例：**

  ```js
  const isColumnNull = resultSet.isColumnNull(resultSet.getColumnIndex("CODES"));
  ```

### close<sup>(deprecated)</sup>

close(): void

关闭结果集。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[close](#close9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

  ```js
  let predicatesClose = new dataRdb.RdbPredicates("EMPLOYEE");
  let promiseClose = rdbStore.query(predicatesClose, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
  promiseClose.then((resultSet) => {
      resultSet.close();
  }).catch((err) => {
      console.log('resultset close failed');
  });
  ```

