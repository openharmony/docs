# @ohos.data.dataShareResultSet (数据共享结果集)(系统接口)

**结果集(DataShareResultSet)** 可提供访问由查询数据库生成的结果集的相关方法，根据提供的行数，查询相应的值，也可查询指定数据类型的值。

> **说明：** 
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 数据共享结果集在全系统最多同时存在32个，使用完及时释放。

## 导入模块

```ts
import { DataShareResultSet } from '@kit.ArkData';
```

## 使用说明

需要通过调用[query](js-apis-data-dataShare-sys.md#query)接口获取DataShareResultSet对象。

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
提供通过查询数据库生成的结果集的相关访问方法。

列或键名称作为字符串数组返回，其中字符串的顺序与结果集中的列或键的顺序相同。

### 属性

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

| 名称        | 类型      | 必填 | 说明                     |
| ----------- | ------------- | ---- | ------------------------ |
| columnNames | Array&lt;string&gt; | 是   | 结果集中所有列的名称。   |
| columnCount | number        | 是   | 结果集中的列数。         |
| rowCount    | number        | 是   | 结果集中的行数。         |
| isClosed    | boolean       | 是   | 标识当前结果集是否关闭。如果结果集已关闭，则为true；否则为false。 |

### goToFirstRow

goToFirstRow(): boolean

转到结果集的第一行。

**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型    | 说明                                          |
| :------ | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```ts
// resultSet需依照本页的使用说明进行创建。
if (resultSet != undefined) {
  let isGoToFirstRow = (resultSet as DataShareResultSet).goToFirstRow();
  console.info('resultSet.goToFirstRow: ' + isGoToFirstRow);
}
```

### goToLastRow

goToLastRow(): boolean

转到结果集的最后一行。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```ts
if (resultSet != undefined) {
  let isGoToLastRow = (resultSet as DataShareResultSet).goToLastRow();
  console.info('resultSet.goToLastRow: ' + isGoToLastRow);
}
```

### goToNextRow

goToNextRow(): boolean

转到结果集的下一行。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```ts
if (resultSet != undefined) {
  let isGoToNextRow = (resultSet as DataShareResultSet).goToNextRow();
  console.info('resultSet.goToNextRow: ' + isGoToNextRow);
}
```

### goToPreviousRow

goToPreviousRow(): boolean

转到结果集的上一行。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```ts
if (resultSet != undefined) {
  let isGoToPreviousRow = (resultSet as DataShareResultSet).goToPreviousRow();
  console.info('resultSet.goToPreviousRow: ' + isGoToPreviousRow);
}
```

### goTo

goTo(offset: number): boolean

相对于当前位置向前或向后移动指定行数。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名** | **类型** | **必填** | 说明                                                         |
| ---------- | -------- | -------- | ------------------------------------------------------------ |
| offset     | number   | 是       | 表示相对于当前位置的偏移量。offset为负值表示向前偏移，正值则表示向后偏移。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```ts
let goToNum = 1;
if (resultSet != undefined) {
  let isGoTo = (resultSet as DataShareResultSet).goTo(goToNum);
  console.info('resultSet.goTo: ' + isGoTo);
}
```

### goToRow

goToRow(position: number): boolean

转到结果集的指定行。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名** | **类型** | **必填** | 说明                                    |
| ---------- | -------- | -------- | --------------------------------------- |
| position   | number   | 是       | 表示要移动到的指定位置，从 0 开始。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果成功移动结果集，则为true；否则返回false。 |

**示例：**

```ts
let goToRowNum = 2;
if (resultSet != undefined) {
  let isGoToRow = (resultSet as DataShareResultSet).goToRow(goToRowNum);
  console.info('resultSet.goToRow: ' + isGoToRow);
}
```

### getBlob

getBlob(columnIndex: number): Uint8Array

以字节数组的形式获取当前行中指定列的值。

如果当前行中指定的列或键的值为空，或者指定的列或键不是Blob类型，则使用方需要确定是否抛出此异常。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名**  | **类型** | **必填** | 说明                    |
| ----------- | -------- | -------- | ----------------------- |
| columnIndex | number   | 是       | 指定的列索引，从0开始。 |

**返回值：**

| 类型       | 说明                             |
| ---------- | -------------------------------- |
| Uint8Array | 以字节数组的形式返回指定列的值。 |

**示例：**

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

以字符串形式获取当前行中指定列的值。

如果当前行中指定的列或键的值为空，或者指定的列或键不是string类型，则使用方需要确定是否抛出此异常。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名**  | **类型** | **必填** | 说明                    |
| ----------- | -------- | -------- | ----------------------- |
| columnIndex | number   | 是       | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| string | 以字符串形式返回指定列的值。 |

**示例：**

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

以长整数值形式获取当前行中指定列的值。

如果当前行中指定的列或键的值为空，或者指定的列或键不是long类型，则使用方需要确定是否抛出此异常。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名**  | **类型** | **必填** | 说明                    |
| ----------- | -------- | -------- | ----------------------- |
| columnIndex | number   | 是       | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 以长整数值形式返回指定列的值。 |

**示例：**

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

以值类型为双浮点数形式获取当前行中指定列的值。

如果当前行中指定的列或键的值为空，或者指定的列或键不是double类型，则使用方需要确定是否抛出此异常。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名**  | **类型** | **必填** | 说明                    |
| ----------- | -------- | -------- | ----------------------- |
| columnIndex | number   | 是       | 指定的列索引，从0开始。 |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| number | 值类型为双浮点数形式返回指定列的值。 |

**示例：**

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

关闭结果集。

对结果集调用此方法将释放其所有资源并使其无效。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**示例：**

```ts
if (resultSet != undefined) {
  (resultSet as DataShareResultSet).close();
}
```

### getColumnIndex

getColumnIndex(columnName: string): number

根据指定的列名获取列索引。

列名作为输入参数传递。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名** | **类型** | **必填** | 说明                       |
| ---------- | -------- | -------- | -------------------------- |
| columnName | string   | 是       | 表示结果集中指定列的名称。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回指定列的索引。 |

**示例：**

```ts
let ColumnName = "name";
if (resultSet != undefined) {
  let getColumnIndex = (resultSet as DataShareResultSet).getColumnIndex(ColumnName);
  console.info('resultSet.getColumnIndex: ' + getColumnIndex);
}
```

### getColumnName

getColumnName(columnIndex: number): string

根据指定的列索引获取列名。

列索引作为输入参数传递。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名**  | **类型** | **必填** | 说明                       |
| ----------- | -------- | -------- | -------------------------- |
| columnIndex | number   | 是       | 表示结果集中指定列的索引。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 返回指定列的名称。 |

**示例：**

```ts
let columnIndex = 1;
if (resultSet != undefined) {
  let getColumnName = (resultSet as DataShareResultSet).getColumnName(columnIndex);
  console.info('resultSet.getColumnName: ' + getColumnName);
}
```

### getDataType

getDataType(columnIndex: number): DataType

指定列索引获取该列的数据类型。

如果当前行中指定的列或键的值为空，或者指定的列或键不是DataType类型，则使用方需要确定是否抛出此异常。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

**参数：**

| **参数名**  | **类型** | **必填** | 说明                       |
| ----------- | -------- | -------- | -------------------------- |
| columnIndex | number   | 是       | 表示结果集中指定列的索引。 |

**返回值：**

| 类型                  | 说明               |
| --------------------- | ------------------ |
| [DataType](#datatype) | 返回指定列的类型。 |

**示例：**

```ts
let columnIndex = 1;
if (resultSet != undefined) {
  let getDataType = (resultSet as DataShareResultSet).getDataType(columnIndex);
  console.info('resultSet.getDataType: ' + getDataType);
}
```

## DataType

数据类型枚举。

**系统能力：**  SystemCapability.DistributedDataManager.DataShare.Core

| 名称        | 值 | 说明                 |
| ----------- | ------ | -------------------- |
| TYPE_NULL   | 0      | 表示值类型为空。     |
| TYPE_LONG   | 1      | 表示值类型为长整数值。   |
| TYPE_DOUBLE | 2      | 表示值类型为双浮点数。 |
| TYPE_STRING | 3      | 表示值类型为字符串。 |
| TYPE_BLOB   | 4      | 表示值类型为字节数组。 |