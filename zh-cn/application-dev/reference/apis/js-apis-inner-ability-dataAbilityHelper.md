# DataAbilityHelper模块(JS端SDK接口)

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在FA模型下使用。

## 使用说明

使用前根据具体情况引入如下模块
```ts
import ohos_data_ability from '@ohos.data.dataAbility'
import ohos_data_rdb from '@ohos.data.rdb'
```

## DataAbilityHelper.openFile

openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void

在指定的远程路径中打开文件（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                   | 必填 | 说明                               |
| -------- | ---------------------- | ---- | ---------------------------------- |
| uri      | string                 | 是   | 指示要打开的文件的路径。           |
| mode     | string                 | 是   | 指示文件打开模式‘rwt’。            |
| callback | AsyncCallback\<number> | 是   | 被指定的回调方法，返回文件说明符。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var mode = "rwt";
DAHelper.openFile(
    "dataability:///com.example.DataAbility",
    mode,
    (err) => {
		console.info("==========================>Called=======================>");
});
```

## DataAbilityHelper.openFile

openFile(uri: string, mode: string): Promise\<number>

在指定的远程路径中打开文件（promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要打开的文件的路径。 |
| mode | string | 是   | 指示文件打开模式‘rwt’。  |

**返回值：**

| 类型             | 说明             |
| ---------------- | ---------------- |
| Promise\<number> | 返回文件说明符。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var mode = "rwt";
DAHelper.openFile(
    "dataability:///com.example.DataAbility",
    mode).then((data) => {
		console.info("==========================>openFileCallback=======================>");
});
```

## DataAbilityHelper.on

on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void

注册观察者以观察给定uri指定的数据callback通知。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 数据更改。               |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback\<void> | 是   | 指示数据更改时的回调。   |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var helper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
function onChangeNotify() {
    console.info("==========================>onChangeNotify=======================>");
};
helper.on(
    "dataChange",
    "dataability:///com.example.DataAbility",
    onChangeNotify
)
```

## DataAbilityHelper.off

off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void

注消观察者以停止观察给定uri指定的数据callback通知。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | 是   | 数据更改。               |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback\<void> | 否   | 指示已注册的回调。       |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var helper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
function onChangeNotify() {
    console.info("==========================>onChangeNotify=======================>");
};
helper.off(
    "dataChange",
    "dataability:///com.example.DataAbility",
)
helper.off(
    "dataChange",
    "dataability:///com.example.DataAbility",
    onChangeNotify
)
```

## DataAbilityHelper.getType

getType(uri: string, callback: AsyncCallback\<string>): void

获取给定URI指定数据的MIME类型（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                   | 必填 | 说明                                          |
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | 是   | 指示要操作的数据的路径。                      |
| callback | AsyncCallback\<string> | 是   | 回调方法，返回与uri指定的数据匹配的MIME类型。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getType(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataAbilityHelper.getType

getType(uri: string): Promise\<string>

获取给定URI指定数据的MIME类型（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要操作的数据的路径。 |

**返回值：**

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise\<string> | 返回与uri指定的数据匹配的MIME类型。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getType(
    "dataability:///com.example.DataAbility"
	).then((data) => {
		console.info("==========================>getTypeCallback=======================>");
});
```

## DataAbilityHelper.getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>): void

获取支持的文件的MIME类型（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名           | 类型                           | 必填 | 说明                               |
| -------------- | ------------------------------ | ---- | ---------------------------------- |
| uri            | string                         | 是   | 指示要获取的文件的路径。           |
| mimeTypeFilter | string                         | 是   | 指示要获取的文件的MIME类型。       |
| callback       | AsyncCallback\<Array\<string>> | 是   | 回调方法，返回匹配的MIME类型数组。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getFileTypes(
    "dataability:///com.example.DataAbility",
    "image/*",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```



## DataAbilityHelper.getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string): Promise\<Array\<string>>

获取支持的文件的MIME类型（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名           | 类型   | 必填 | 说明                         |
| -------------- | ------ | ---- | ---------------------------- |
| uri            | string | 是   | 指示要获取的文件的路径。     |
| mimeTypeFilter | string | 是   | 指示要获取的文件的MIME类型。 |

**返回值：**

| 类型                     | 说明                     |
| ------------------------ | ------------------------ |
| Promise\<Array\<string>> | 返回匹配的MIME类型数组。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getFileTypes(
    "dataability:///com.example.DataAbility",
    "image/*"
	).then((data) => {
		console.info("==========================>getFileTypesCallback=======================>");
});
```

## DataAbilityHelper.normalizeUri

normalizeUri(uri: string, callback: AsyncCallback\<string>): void

将引用数据功能的给定uri转换为规范化uri（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                 | 是   | 指示要规范化的uri对象。                                      |
| callback | AsyncCallback\<string> | 是   | 回调方法。如果数据功能支持uri规范化，则返回规范化uri对象；否则返回null。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.normalizeUri(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataAbilityHelper.normalizeUri

normalizeUri(uri: string): Promise\<string>

将引用数据功能的给定uri转换为规范化uri（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | 是   | 指示要规范化的uri对象。 |

**返回值：**

| 类型             | 说明                                                   |
| ---------------- | ------------------------------------------------------ |
| Promise\<string> | 如果数据功能支持uri规范化，则返回规范化uri对象；否则返回null。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.normalizeUri(
    "dataability:///com.example.DataAbility",
	).then((data) => {
		console.info("==========================>normalizeUriCallback=======================>");
});
```

## DataAbilityHelper.denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback\<string>): void

将由normalizeUri（uri）生成的给定规范化uri转换为非规范化uri（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                   | 必填 | 说明                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | 是   | 指示要规范化的uri对象。                             |
| callback | AsyncCallback\<string> | 是   | 回调方法。如果反规范化成功，则返回反规范化uri对象。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.denormalizeUri(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```



## DataAbilityHelper.denormalizeUri

denormalizeUri(uri: string): Promise\<string>

将由normalizeUri（uri）生成的给定规范化uri转换为非规范化uri（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | 是   | 指示要规范化的uri对象。 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<string> | 如果反规范化成功，则返回反规范化uri对象。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.denormalizeUri(
    "dataability:///com.example.DataAbility",
	).then((data) => {
		console.info("==========================>denormalizeUriCallback=======================>");
});
```

## DataAbilityHelper.notifyChange

notifyChange(uri: string, callback: AsyncCallback\<void>): void

通知已注册的观察者uri指定的数据资源的更改（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | 是   | 指示要操作的数据的路径。 |
| callback | AsyncCallback\<void> | 是   | 回调方法。               |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var helper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
helper.notifyChange(
    "dataability:///com.example.DataAbility",
    (err) => {
		console.info("==========================>Called=======================>");
});
```

## DataAbilityHelper.notifyChange

notifyChange(uri: string): Promise\<void>

通知已注册的观察者uri指定的数据资源的更改（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | 是   | 指示要操作的数据的路径。 |

**返回值：**

| 类型           | 说明                  |
| -------------- | --------------------- |
| Promise\<void> | 返回值为Promise对象。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.notifyChange(
    "dataability:///com.example.DataAbility",
	).then(() => {
		console.info("==========================>notifyChangeCallback=======================>");
});
```

## DataAbilityHelper.insert

insert(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void

将单个数据记录插入数据库（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型                   | 必填 | 说明                                                   |
| ------------ | ---------------------- | ---- | ------------------------------------------------------ |
| uri          | string                 | 是   | 指示要插入的数据的路径。                               |
| valuesBucket | rdb.ValuesBucket       | 是   | 指示要插入的数据记录。如果此参数为空，将插入一个空行。 |
| callback     | AsyncCallback\<number> | 是   | 回调方法，返回插入数据记录的索引。                     |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
    "blobType": "u8",
}
DAHelper.insert(
    "dataability:///com.example.DataAbility",
    valueBucket,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataAbilityHelper.insert

insert(uri: string, valuesBucket: rdb.ValuesBucket): Promise\<number>

将单个数据记录插入数据库（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型             | 必填 | 说明                                                   |
| ------------ | ---------------- | ---- | ------------------------------------------------------ |
| uri          | string           | 是   | 指示要插入的数据的路径。                               |
| valuesBucket | rdb.ValuesBucket | 是   | 指示要插入的数据记录。如果此参数为空，将插入一个空行。 |

**返回值：**

| 类型             | 说明                     |
| ---------------- | ------------------------ |
| Promise\<number> | 返回插入数据记录的索引。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const valueBucket = {
    "name": "rose1",
    "age": 221,
    "salary": 20.5,
    "blobType": "u8",
}
DAHelper.insert(
    "dataability:///com.example.DataAbility",
    valueBucket
	).then((data) => {
		console.info("==========================>insertCallback=======================>");
});
```

## DataAbilityHelper.batchInsert

batchInsert(uri: string, valuesBuckets: Array\<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void

插入数据库（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型                    | 必填 | 说明                             |
| ------------ | ----------------------- | ---- | -------------------------------- |
| uri          | string                  | 是   | 指示要插入的数据的路径。         |
| valuesBucket | Array\<rdb.ValuesBucket> | 是   | 指示要插入的数据记录。           |
| callback     | AsyncCallback\<number>  | 是   | 回调方法。返回插入的数据记录数。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": "u8",},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": "u8",},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": "u8",})
DAHelper.batchInsert(
    "dataability:///com.example.DataAbility",
    cars,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataAbilityHelper.batchInsert

batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>): Promise\<number>

将多个数据记录插入数据库（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型                    | 必填 | 说明                     |
| ------------ | ----------------------- | ---- | ------------------------ |
| uri          | string                  | 是   | 指示要插入的数据的路径。 |
| valuesBucket | Array<rdb.ValuesBucket> | 是   | 指示要插入的数据记录。   |

**返回值：**

| 类型             | 说明                   |
| ---------------- | ---------------------- |
| Promise\<number> | 返回插入的数据记录数。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": "u8",},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": "u8",},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": "u8",})
DAHelper.batchInsert(
    "dataability:///com.example.DataAbility",
    cars
	).then((data) => {
		console.info("==========================>batchInsertCallback=======================>");
});
```

## DataAbilityHelper.delete

delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

从数据库中删除一个或多个数据记录（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型                              | 必填 | 说明                                             |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | 是   | 指示要删除的数据的路径。                         |
| predicates | dataAbility.DataAbilityPredicates | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| callback     | AsyncCallback\<number>            | 是   | 回调方法。返回已删除的数据记录数。               |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.delete(
    "dataability:///com.example.DataAbility",
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataAbilityHelper.delete

delete(uri: string, predicates?: dataAbility.DataAbilityPredicates): Promise\<number>;

从数据库中删除一个或多个数据记录（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型                              | 必填 | 说明                                             |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | 是   | 指示要删除的数据的路径。                         |
| predicates | dataAbility.DataAbilityPredicates | 否   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型             | 说明                     |
| ---------------- | ------------------------ |
| Promise\<number> | 返回已删除的数据记录数。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.delete(
    "dataability:///com.example.DataAbility",
    da
	).then((data) => {
		console.info("==========================>deleteCallback=======================>");
});
```

## DataAbilityHelper.update

update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

更新数据库中的数据记录（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型                              | 必填 | 说明                                             |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | 是   | 指示要更新的数据的路径。                         |
| valuesBucket | rdb.ValuesBucket                  | 是   | 指示要更新的数据。                               |
| predicates   | dataAbility.DataAbilityPredicates | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| callback     | AsyncCallback\<number>            | 是   | 回调方法，返回更新的数据记录数。                 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": "u8",
}
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.update(
    "dataability:///com.example.DataAbility",
    va,
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataAbilityHelper.update

update(uri: string, valuesBucket: rdb.ValuesBucket, predicates?: dataAbility.DataAbilityPredicates): Promise\<number>;

更新数据库中的数据记录（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名         | 类型                              | 必填 | 说明                                             |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | 是   | 指示要更新的数据的路径。                         |
| valuesBucket | rdb.ValuesBucket                  | 是   | 指示要更新的数据。                               |
| predicates   | dataAbility.DataAbilityPredicates | 否   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型             | 说明                                         |
| ---------------- | -------------------------------------------- |
| Promise\<number> | Promise中包含更新的数据记录数。 。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": "u8",
}
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.update(
    "dataability:///com.example.DataAbility",
    va,
    da
	).then((data) => {
		console.info("==========================>updateCallback=======================>");
});
```

## DataAbilityHelper.query

query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void

查询数据库中的数据（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名       | 类型                              | 必填 | 说明                                             |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | 是   | 指示要查询的数据的路径。                         |
| columns    | Array\<string>                | 是   | 指示要查询的列。如果此参数为空，则查询所有列。   |
| predicates | dataAbility.DataAbilityPredicates | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| callback   | AsyncCallback\<ResultSet>         | 是   | 回调方法，返回查询结果。                         |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars=new Array("value1", "value2", "value3", "value4");
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.query(
    "dataability:///com.example.DataAbility",
    cars,
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```



## DataAbilityHelper.query

query(uri: string, columns?: Array\<string>, predicates?: dataAbility.DataAbilityPredicates): Promise\<ResultSet>;

查询数据库中的数据（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名       | 类型                              | 必填 | 说明                                             |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | 是   | 指示要查询的数据的路径。                         |
| columns    | Array\<string>               | 否   | 指示要查询的列。如果此参数为空，则查询所有列。   |
| predicates | dataAbility.DataAbilityPredicates | 否   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |

**返回值：**

| 类型                | 说明           |
| ------------------- | -------------- |
| Promise\<ResultSet> | 返回查询结果。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars=new Array("value1", "value2", "value3", "value4");
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.query(
    "dataability:///com.example.DataAbility",
    cars,
    da
	).then((data) => {
		console.info("==========================>queryCallback=======================>");
});
```

## DataAbilityHelper.call

call(uri: string, method: string, arg: string, extras: PacMap): Promise\<PacMap>

调用DataAbility的扩展接口，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名       | 类型                              | 必填 | 说明                                             |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                 | 是   | 指定待处理的DataAbility。例："dataability:///com.example.xxx.xxxx"           |
| method    | string                  | 是   | 被调用的方法名。   |
| arg      | string                   | 是   |需传入的参数。      |
| extras   | [PacMap](#pacmap)        | 是   | 键值对参数。       |

**返回值：**

| 类型 | 说明 |
|------ | ------- |
|Promise\<[PacMap](#pacmap)> | 调用的返回值。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';

let dataAbilityHelper = featureAbility.acquireDataAbilityHelper("dataability:///com.example.jsapidemo.UserDataAbility");
dataAbilityHelper.call("dataability:///com.example.jsapidemo.UserDataAbility", "method", "arg", {"key1":"value1"}).then((data) => {
    console.info('Operation succeeded: ' + data);
}).catch((error) => {
    console.error('Operation failed. Cause: ' + error);
});
```

## DataAbilityHelper.call

call(uri: string, method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void

调用DataAbility的扩展接口，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名       | 类型                              | 必填 | 说明                                             |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                 | 是   | 指定待处理的DataAbility。例："dataability:///com.example.xxx.xxxx"           |
| method    | string                  | 是   | 被调用的方法名。   |
| arg      | string                   | 是   |需传入的参数。      |
| extras   | [PacMap](#pacmap)        | 是   | 键值对参数。       |
| callback | AsyncCallback\<[PacMap](#pacmap)> | 是 | 返回值。     |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';

let dataAbilityHelper = featureAbility.acquireDataAbilityHelper("dataability:///com.example.jsapidemo.UserDataAbility");
dataAbilityHelper.call("dataability:///com.example.jsapidemo.UserDataAbility", "method", "arg", {"key1":"value1"}, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + err);
        return;
    }
    console.info('Operation succeeded: ' + data);
});
```

## DataAbilityHelper.executeBatch

executeBatch(uri: string, operations: Array\<DataAbilityOperation>, callback: AsyncCallback\<Array\<DataAbilityResult>>): void;

查询数据库中的数据。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名            | 类型                                         | 必填 | 说明                                             |
| ----------    | ---------------------------------             | ---- | ------------------------------------------------ |
| uri           | string                                        | 是   | 指定待处理的DataAbility。例："dataability:///com.example.xxx.xxxx"。|
| operations    |  Array\<[DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)>               | 是   | 指示数据操作列表，其中可以包含对数据库的多个操作。   |
| callback      |  AsyncCallback\<Array\<[DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)>>    | 是   |在数组 DataAbilityResult中返回每个操作的结果。      |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';

// 根据DataAbilityOperation列表选择要对数据库做的操作
let op=new Array();
let dataAbilityHelper = featureAbility.acquireDataAbilityHelper("dataability:///com.example.jsapidemo.UserDataAbility");
dataAbilityHelper.executeBatch("dataability:///com.example.jsapidemo.UserDataAbility", op, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + err);
        return;
    }
    console.info('Operation succeeded: ' + data);
});
```

## DataAbilityHelper.executeBatch

executeBatch(uri: string, operations: Array\<DataAbilityOperation>): Promise\<Array\<DataAbilityResult>>;

查询数据库中的数据。

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

**参数：**

| 参数名          | 类型                            | 必填 | 说明                                             |
| ----------    | -------------------------------| ---- | ------------------------------------------------ |
| uri           | string                         | 是   | 指定待处理的DataAbility。例："dataability:///com.example.xxx.xxxx"。|
| operations    |  Array\<[DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)>  | 是   | 指示数据操作列表，其中可以包含对数据库的多个操作。   |

**返回值：**

| 类型 | 说明 |
|------ | ------- |
|Promise\<Array\<[DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)>> | 在数组 DataAbilityResult中返回每个操作的结果。 |

**示例：**

```ts
import featureAbility from '@ohos.ability.featureAbility';

// 根据DataAbilityOperation列表选择要对数据库做的操作
let op=new Array();
let dataAbilityHelper = featureAbility.acquireDataAbilityHelper("dataability:///com.example.jsapidemo.UserDataAbility");
dataAbilityHelper.executeBatch("dataability:///com.example.jsapidemo.UserDataAbility",op ).then((data) => {
    console.info('Operation succeeded: ' + data);
}).catch((error) => {
    console.error('Operation failed. Cause: ' + error);
});

```

## PacMap

[key: string]: number | string | boolean | Array\<string | number | boolean> | null;

**系统能力**：SystemCapability.Ability.AbilityRuntime.FAModel

| 参数名 | 参数类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| [key: string] | number \| string \| boolean \| Array\<string \| number \| boolean\> \| null | Yes| 数据存储在键值对中。|