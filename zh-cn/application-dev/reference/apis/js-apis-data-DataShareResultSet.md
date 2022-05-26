# DataShare结果集

**DataShare结果集（DataShareResultSet）** 

提供通过查询数据库生成的数据库结果集的访问方法。

>**说明：** 
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import DataShareResultSet from './@ohos.data.DataShareResultSet';
```

## 使用说明

需要通过dataShare.query()获取DataShareResultSet对象。

```js
import dataShare from '@ohos.data.dataShare';
import DataSharePredicates from './@ohos.data.DataSharePredicates';

query()
```

## 属性

| 名称        | 参数类型        | 必填 | 说明                       |
| ----------- | --------------- | ---- | -------------------------- |
| columnNames | Array<*string*> | 是   | 获取结果集中所有列的名称。 |
| columnCount | *number*        | 是   | 获取结果集中的列数。       |
| rowCount    | *number*        | 是   | 获取结果集中的行数。       |
| isClosed    | *boolean*       | 是   | 检查当前结果集是否关闭。   |

## goToFirstRow

goToFirstRow(): *boolean*;

转到结果集的第一行。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型      | 说明                                          |
| :-------- | --------------------------------------------- |
| *boolean* | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```js
let isGoTOFirstRow = resultSet.goToFirstRow();
console.info('resultSet.goToFirstRow: ' + isGoTOFirstRow);
```

## goToLastRow

goToLastRow(): *boolean*;

转到结果集的最后一行。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| *boolean* | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```js
let isGoToLastRow = resultSet.goToLastRow();
console.info('resultSet.goToLastRow: ' + isGoToLastRow);
```

## goToNextRow

goToNextRow(): *boolean*;

转到结果集的下一行。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型      | 说明                                          |
| --------- | --------------------------------------------- |
| *boolean* | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```js
let isGoToNextRow = resultSet.goToNextRow();
console.info('resultSet.goToNextRow: ' + isGoToNextRow);
```

## goToPreviousRow

goToPreviousRow(): boolean;

转到结果集的上一行。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**返回值：**

| 类型      | 说明                                          |
| --------- | --------------------------------------------- |
| *boolean* | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```js
let isGoToPreviousRow = resultSet.goToPreviousRow();
console.info('resultSet.goToPreviousRow: ' + isGoToPreviousRow);
```

## goTo

goTo(offset:number): boolean;

向前或向后转至结果集的指定行，相对于其当前位置偏移。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名** | **类型** | **必填** | 说明                         |
| ---------- | -------- | -------- | ---------------------------- |
| *offset*   | number   | 是       | 表示相对于当前位置的偏移量。 |

**返回值：**

| 类型      | 说明                                          |
| --------- | --------------------------------------------- |
| *boolean* | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```js
let goToNum = 1;
let isGoTo = resultSet.goTo(goToNum);
console.info('resultSet.goTo: ' + isGoTo);
```

## goToRow

goToRow(position: number): boolean;

转到结果集的指定行。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名** | **类型** | **必填** | 说明                     |
| ---------- | -------- | -------- | ------------------------ |
| *position* | number   | 是       | 表示要移动到的指定位置。 |

**返回值：**

| 类型      | 说明                                          |
| --------- | --------------------------------------------- |
| *boolean* | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```js
let goToRowNum = 2
let isGoToRow = resultSet.goToRow(goToRowNum);
console.info('resultSet.goToRow: ' + isGoToRow);
```

## getBlob

getBlob(*columnIndex*: *number*): Uint8Array;

以字节数组的形式获取当前行中指定列的值。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名**    | **类型** | **必填** | 说明                    |
| ------------- | -------- | -------- | ----------------------- |
| *columnIndex* | number   | 是       | 指定的列索引，从0开始。 |

**返回值：**

| 类型         | 说明                             |
| ------------ | -------------------------------- |
| *Uint8Array* | 以字节数组的形式返回指定列的值。 |

**示例：**

```js
let columnIndex = 1
let goToFirstRow = resultSet.goToFirstRow();
let getBlob = resultSet.getBlob(columnIndex);
console.info('resultSet.getBlob: ' + getBlob);
```

## getString

getString(*columnIndex*: *number*): *string*;

以字符串形式获取当前行中指定列的值。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名**    | **类型** | **必填** | 说明                    |
| ------------- | -------- | -------- | ----------------------- |
| *columnIndex* | number   | 是       | 指定的列索引，从0开始。 |

**返回值：**

| 类型     | 说明                         |
| -------- | ---------------------------- |
| *string* | 以字符串形式返回指定列的值。 |

**示例：**

```js
let columnIndex = 1
let goToFirstRow = resultSet.goToFirstRow();
let getString = resultSet.getString(columnIndex);
console.info('resultSet.getString: ' + getString);
```

## getLong

getLong(*columnIndex*: *number*): *number*;

以Long形式获取当前行中指定列的值。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名**    | **类型** | **必填** | 说明                    |
| ------------- | -------- | -------- | ----------------------- |
| *columnIndex* | number   | 是       | 指定的列索引，从0开始。 |

**返回值：**

| 类型     | 说明                       |
| -------- | -------------------------- |
| *number* | 以Long形式返回指定列的值。 |

**示例：**

```js
let columnIndex = 1
let goToFirstRow = resultSet.goToFirstRow();
let getLong = resultSet.getLong(columnIndex);
console.info('resultSet.getLong: ' + getLong);
```

## getDouble

getDouble(*columnIndex*: *number*): *number*;

以double形式获取当前行中指定列的值。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名**    | **类型** | **必填** | 说明                    |
| ------------- | -------- | -------- | ----------------------- |
| *columnIndex* | number   | 是       | 指定的列索引，从0开始。 |

**返回值：**

| 类型     | 说明                         |
| -------- | ---------------------------- |
| *number* | 以double形式返回指定列的值。 |

**示例：**

```js
let columnIndex = 1
let goToFirstRow = resultSet.goToFirstRow();
let getDouble = resultSet.getDouble(columnIndex);
console.info('resultSet.getDouble: ' + getDouble);
```

## close

close(): *void*;

关闭结果集。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**示例：**

```js
resultSet.close();
```

## getColumnIndex

getColumnIndex(*columnName*: *string*): *number*;

根据指定的列名获取列索引。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名**   | **类型** | **必填** | 说明                       |
| ------------ | -------- | -------- | -------------------------- |
| *columnName* | string   | 是       | 表示结果集中指定列的名称。 |

**返回值：**

| 类型     | 说明               |
| -------- | ------------------ |
| *number* | 返回指定列的索引。 |

**示例：**

```js
let ColumnName = "name"
let getColumnIndex = resultSet.getColumnIndex(ColumnName)
console.info('resultSet.getColumnIndex: ' + getColumnIndex);
```

## getColumnName

getColumnName(*columnIndex*: *number*): *string*;

根据指定的列索引获取列名。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名**    | **类型** | **必填** | 说明                       |
| ------------- | -------- | -------- | -------------------------- |
| *columnIndex* | number   | 是       | 表示结果集中指定列的索引。 |

**返回值：**

| 类型     | 说明               |
| -------- | ------------------ |
| *string* | 返回指定列的名称。 |

**示例：**

```js
let columnIndex = 1
let getColumnName = resultSet.getColumnName(columnIndex)
console.info('resultSet.getColumnName: ' + getColumnName);
```

## getDataType

getDataType(*columnIndex*: *number*): DataType;

获取指定列的数据类型。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

**参数：**

| **参数名**    | **类型** | **必填** | 说明                       |
| ------------- | -------- | -------- | -------------------------- |
| *columnIndex* | number   | 是       | 表示结果集中指定列的索引。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| *DataType* | 返回指定列的类型。 |

**示例：**

```js
let columnIndex = 1;
let getDataType = resultSet.getDataType(columnIndex);
console.info('resultSet.getDataType: ' + getDataType);
```

## DataType

用于表示数据类型。

只能被内部应用使用。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core。

| 名称        | 默认值 | 说明                 |
| ----------- | ------ | -------------------- |
| TYPE_NULL   | 0      | 表示值类型为空。     |
| TYPE_LONG   | 1      | 表示值类型为Long。   |
| TYPE_DOUBLE | 2      | 表示值类型为Double。 |
| TYPE_STRING | 3      | 表示值类型为String。 |
| TYPE_BLOB   | 4      | 表示值类型为Blob。   |
