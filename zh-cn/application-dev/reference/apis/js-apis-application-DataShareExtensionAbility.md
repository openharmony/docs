# DataShareExtensionAbility

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 
> 本模块首批接口从API version 9开始支持。API 9当前为Canary版本，仅供使用，不保证接口可稳定调用。


类的数据共享扩展能力。


## 导入模块

  
```
import DataShareExtensionAbility from '@ohos.application.DataShareExtensionAbility';
```

## 属性

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

| 名称 | 可读 | 可写 | 参数类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- | -------- | -------- |
| context | 是 | 否 | ExtensionContext | 否 | 指示数据共享扩展能力上下文。| 


## DataShareExtensionAbility.onCreate

onCreate?(want: Want): void;

在启动数据共享扩展功能进行初始化时回调。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | Want | 是 | want表示有关数据共享扩展功能的连接信息。|

**示例：**
    
  ```js
  class myAbility extends DataShareExtensionAbility {
      onCreate(want) {
          console.log('onCreate, want:' + want.abilityName);
      }
  }
  ```

## DataShareExtensionAbility.getFileTypes

getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>): void

获取支持的文件的MIME类型（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称           | 类型                           | 必填 | 描述                               |
| -------------- | ------------------------------ | ---- | ---------------------------------- |
| uri            | string                         | 是   | 指示要获取的文件的路径。           |
| mimeTypeFilter | string                         | 是   | 指示要获取的文件的MIME类型。       |
| callback       | AsyncCallback\<Array\<string>> | 是   | 回调方法，返回匹配的MIME类型数组。 |

**示例：**

```js
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

## DataShareExtensionAbility.insert

insert?(uri: string, valueBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void

将单个数据记录插入数据库（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称         | 类型                   | 必填 | 描述                                                   |
| ------------ | ---------------------- | ---- | ------------------------------------------------------ |
| uri          | string                 | 是   | 指示要插入的数据的路径。                               |
| valuesBucket | rdb.ValuesBucket       | 是   | 指示要插入的数据记录。如果此参数为空，将插入一个空行。 |
| callback     | AsyncCallback\<number> | 是   | 回调方法，返回插入数据记录的索引。                     |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
    "blobType": u8,
}
DAHelper.insert(
    "dataability:///com.example.DataAbility",
    valueBucket,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.update

update?(uri: string, valueBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

更新数据库中的数据记录（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称         | 类型                              | 必填 | 描述                                             |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | 是   | 指示要更新的数据的路径。                         |
| valuesBucket | rdb.ValuesBucket                  | 是   | 指示要更新的数据。                               |
| predicates   | dataAbility.DataAbilityPredicates | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| callback     | AsyncCallback\<number>            | 是   | 回调方法，返回更新的数据记录数。                 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": u8,
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

## DataShareExtensionAbility.delete

delete?(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

从数据库中删除一个或多个数据记录（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称         | 类型                              | 必填 | 描述                                             |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | 是   | 指示要删除的数据的路径。                         |
| valuesBucket | dataAbility.DataAbilityPredicates | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| callback     | AsyncCallback\<number>            | 是   | 回调方法。返回已删除的数据记录数。               |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
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

## DataShareExtensionAbility.query

query?(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void

查询数据库中的数据（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称       | 类型                              | 必填 | 描述                                             |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | 是   | 指示要查询的数据的路径。                         |
| columns    | rdb.ValuesBucket                  | 是   | 指示要查询的列。如果此参数为空，则查询所有列。   |
| predicates | dataAbility.DataAbilityPredicates | 是   | 指示筛选条件。当此参数为null时，应定义处理逻辑。 |
| callback   | AsyncCallback\<ResultSet>         | 是   | 回调方法，返回查询结果。                         |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
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

## DataShareExtensionAbility.getType

getType?(uri: string, callback: AsyncCallback\<string>): void

获取给定URI指定数据的MIME类型（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称     | 类型                   | 必填 | 描述                                          |
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | 是   | 指示要操作的数据的路径。                      |
| callback | AsyncCallback\<string> | 是   | 回调方法，返回与uri指定的数据匹配的MIME类型。 |

**示例：**

```js
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

## DataShareExtensionAbility.batchInsert

batchInsert?(uri: string, valueBuckets: Array<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void

插入数据库（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称         | 类型                    | 必填 | 描述                             |
| ------------ | ----------------------- | ---- | -------------------------------- |
| uri          | string                  | 是   | 指示要插入的数据的路径。         |
| valuesBucket | Array<rdb.ValuesBucket> | 是   | 指示要插入的数据记录。           |
| callback     | AsyncCallback\<number>  | 是   | 回调方法。返回插入的数据记录数。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": u8,})
DAHelper.batchInsert(
    "dataability:///com.example.DataAbility",
    cars,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback\<string>): void

将引用数据功能的给定uri转换为规范化uri（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                 | 是   | 指示要规范化的uri对象。                                      |
| callback | AsyncCallback\<string> | 是   | 回调方法。如果数据功能支持uri规范化，则返回规范化uri对象；否则返回null。 |

**示例：**

```js
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

## DataShareExtensionAbility.denormalizeUri

denormalizeUri?(uri: string, callback: AsyncCallback\<string>): void

将由normalizeUri（uri）生成的给定规范化uri转换为非规范化uri（callback形式）。

**系统能力**：SystemCapability.DistributedDataManager.DataShare.Provider

**参数：**

| 名称     | 类型                   | 必填 | 描述                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | 是   | 指示要规范化的uri对象。                             |
| callback | AsyncCallback\<string> | 是   | 回调方法。如果反规范化成功，则返回反规范化uri对象。 |

**示例：**

```js
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
