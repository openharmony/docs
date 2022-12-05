# 关系型数据库

关系型数据库（Relational Database，RDB）是一种基于关系模型来管理数据的数据库。关系型数据库基于SQLite组件提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复杂的场景需要。

该模块提供以下关系型数据库相关的常用功能：

- [RdbPredicatesV9](#rdbpredicatesv99)： 数据库中用来代表数据实体的性质、特征或者数据实体之间关系的词项，主要用来定义数据库的操作条件。
- [RdbStoreV9](#rdbstorev99)：提供管理关系数据库(RDB)方法的接口。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import data_rdb from '@ohos.data.rdb';
```

## data_rdb.getRdbStoreV9<sup>9+</sup>

getRdbStoreV9(context: Context, config: StoreConfigV9, version: number, callback: AsyncCallback&lt;RdbStoreV9&gt;): void

获得一个相关的RdbStoreV9，操作关系型数据库，用户可以根据自己的需求配置RdbStoreV9的参数，然后通过RdbStoreV9调用相关接口可以执行相关的数据操作，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                                         |
| -------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                        | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| config   | [StoreConfigV9](#storeconfigv99)               | 是   | 与此RDB存储相关的数据库配置。                                |
| version  | number                                         | 是   | 数据库版本。<br>目前暂不支持通过version自动识别数据库升级降级操作，只能由开发者自行维护。                                                 |
| callback | AsyncCallback&lt;[RdbStoreV9](#rdbstorev9)&gt; | 是   | 指定callback回调函数，返回RdbStoreV9对象。                   |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 14800010     | Invalid database  name. |
| 14800011     | Database corrupted.     |

**示例：**

FA模型示例：

```js
// 获取context
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// 获取context后调用getRdbStoreV9
const STORE_CONFIGV9 = { name: "RdbTest.db",
                     securityLevel: data_rdb.SecurityLevel.S1}
data_rdb.getRdbStoreV9(context, STORE_CONFIGV9, 1, function (err, rdbStoreV9) {
    if (err) {
        console.info("Get RdbStoreV9 failed, err: " + err)
        return
    }
    console.log("Get RdbStoreV9 successfully.")
})
```

Stage模型示例：

```ts
// 获取context
import Ability from '@ohos.application.Ability'
let context
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// 获取context后调用getRdbStoreV9
const STORE_CONFIGV9 = { name: "RdbTest.db",
                     securityLevel: data_rdb.SecurityLevel.S1}
data_rdb.getRdbStoreV9(context, STORE_CONFIGV9, 1, function (err, rdbStoreV9) {
    if (err) {
        console.info("Get RdbStoreV9 failed, err: " + err)
        return
    }
    console.log("Get RdbStoreV9 successfully.")
})
```

## data_rdb.getRdbStoreV9<sup>9+</sup>

getRdbStoreV9(context: Context, config: StoreConfigV9, version: number): Promise&lt;RdbStoreV9&gt;

获得一个相关的RdbStoreV9，操作关系型数据库，用户可以根据自己的需求配置RdbStoreV9的参数，然后通过RdbStoreV9调用相关接口可以执行相关的数据操作，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名  | 类型                             | 必填 | 说明                                                         |
| ------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                          | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| config  | [StoreConfigV9](#storeconfigv99) | 是   | 与此RDB存储相关的数据库配置。                                |
| version | number                           | 是   | 数据库版本。<br>目前暂不支持通过version自动识别数据库升级降级操作，只能由开发者自行维护。                                                 |

**返回值**：

| 类型                                      | 说明                              |
| ----------------------------------------- | --------------------------------- |
| Promise&lt;[RdbStoreV9](#rdbstorev99)&gt; | Promise对象。返回RdbStoreV9对象。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 14800010     | Invalid database  name. |
| 14800011     | Database corrupted.     |

**示例：**

FA模型示例：

```js
// 获取context
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// 获取context后调用getRdbStoreV9
const STORE_CONFIGV9 = { name: "RdbTest.db",
                     securityLevel: data_rdb.SecurityLevel.S1}
let promise = data_rdb.getRdbStoreV9(context, STORE_CONFIGV9, 1);
promise.then(async (rdbStoreV9) => {
    console.log("Get RdbStoreV9 successfully.")
}).catch((err) => {
    console.log("Get RdbStoreV9 failed, err: " + err)
})
```

Stage模型示例：

```ts
// 获取context
import Ability from '@ohos.application.Ability'
let context
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// 获取context后调用getRdbStoreV9
const STORE_CONFIGV9 = { name: "RdbTest.db",
                     securityLevel: data_rdb.SecurityLevel.S1}
let promise = data_rdb.getRdbStoreV9(context, STORE_CONFIGV9, 1);
promise.then(async (rdbStoreV9) => {
    console.log("Get RdbStoreV9 successfully.")
}).catch((err) => {
    console.log("Get RdbStoreV9 failed, err: " + err)
})
```

## data_rdb.deleteRdbStoreV9<sup>9+</sup>

deleteRdbStoreV9(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

删除数据库，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| name     | string                    | 是   | 数据库名称。                                                 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。                                       |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 14800010     | Invalid database  name. |

**示例：**

FA模型示例：

```js
// 获取context
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// 获取context后调用deleteRdbStoreV9
data_rdb.deleteRdbStoreV9(context, "RdbTest.db", function (err) {
    if (err) {
        console.info("Delete RdbStorev9 failed, err: " + err)
        return
    }
    console.log("Delete RdbStorev9 successfully.")
})
```

Stage模型示例：

```ts
// 获取context
import Ability from '@ohos.application.Ability'
let context
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// 获取context后调用deleteRdbStoreV9
data_rdb.deleteRdbStoreV9(context, "RdbTest.db", function (err) {
    if (err) {
        console.info("Delete RdbStoreV9 failed, err: " + err)
        return
    }
    console.log("Delete RdbStoreV9 successfully.")
})
```

## data_rdb.deleteRdbStoreV9<sup>9+</sup>

deleteRdbStoreV9(context: Context, name: string): Promise&lt;void&gt;

使用指定的数据库文件配置删除数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| name    | string  | 是   | 数据库名称。                                                 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[关系型数据库错误码](../errorcodes/errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**            |
| ------------ | ----------------------- |
| 14800010     | Invalid database  name. |

**示例：**

FA模型示例：

```js
// 获取context
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// 获取context后调用deleteRdbStoreV9
let promise = data_rdb.deleteRdbStoreV9(context, "RdbTest.db")
promise.then(()=>{
    console.log("Delete RdbStoreV9 successfully.")
}).catch((err) => {
    console.info("Delete RdbStoreV9 failed, err: " + err)
})
```

Stage模型示例：

```ts
// 获取context
import Ability from '@ohos.application.Ability'
let context
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// 获取context后调用deleteRdbStoreV9
let promise = data_rdb.deleteRdbStoreV9(context, "RdbTest.db")
promise.then(()=>{
    console.log("Delete RdbStoreV9 successfully.")
}).catch((err) => {
    console.info("Delete RdbStoreV9 failed, err: " + err)
})
```

## data_rdb.getRdbStore<sup>(deprecated)</sup>

getRdbStore(context: Context, config: StoreConfig, version: number, callback: AsyncCallback&lt;RdbStore&gt;): void

获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，使用callback异步回调。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[data_rdb.getRdbStoreV9](#data_rdbgetrdbstorev99)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                         |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| context  | Context                                    | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| config   | [StoreConfig](#storeconfig)                | 是   | 与此RDB存储相关的数据库配置。                                |
| version  | number                                     | 是   | 数据库版本。<br>目前暂不支持通过version自动识别数据库升级降级操作，只能由开发者自行维护。                                                 |
| callback | AsyncCallback&lt;[RdbStore](#rdbstore)&gt; | 是   | 指定callback回调函数，返回RdbStore对象。                     |

**示例：**

FA模型示例：

```js
// 获取context
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// 获取context后调用getRdbStore
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, function (err, rdbStore) {
    if (err) {
        console.info("Get RdbStore failed, err: " + err)
        return
    }
    console.log("Get RdbStore successfully.")
})
```

Stage模型示例：

```ts
// 获取context
import Ability from '@ohos.application.Ability'
let context
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// 获取context后调用getRdbStore
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, function (err, rdbStore) {
    if (err) {
        console.info("Get RdbStore failed, err: " + err)
        return
    }
    console.log("Get RdbStore successfully.")
})
```

## data_rdb.getRdbStore<sup>(deprecated)</sup>

getRdbStore(context: Context, config: StoreConfig, version: number): Promise&lt;RdbStore&gt;

获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，使用Promise异步回调。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[data_rdb.getRdbStoreV9](#data_rdbgetrdbstorev99-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名  | 类型                        | 必填 | 说明                                                         |
| ------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                     | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| config  | [StoreConfig](#storeconfig) | 是   | 与此RDB存储相关的数据库配置。                                |
| version | number                      | 是   | 数据库版本。<br>目前暂不支持通过version自动识别数据库升级降级操作，只能由开发者自行维护。                                                 |

**返回值**：

| 类型                                 | 说明                            |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[RdbStore](#rdbstore)&gt; | Promise对象。返回RdbStore对象。 |

**示例：**

FA模型示例：

```js
// 获取context
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// 获取context后调用getRdbStore
const STORE_CONFIG = { name: "RdbTest.db" }
let promise = data_rdb.getRdbStore(context, STORE_CONFIG, 1);
promise.then(async (rdbStore) => {
    console.log("Get RdbStore successfully.")
}).catch((err) => {
    console.log("Get RdbStore failed, err: " + err)
})
```

Stage模型示例：

```ts
// 获取context
import Ability from '@ohos.application.Ability'
let context
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// 获取context后调用getRdbStore
const STORE_CONFIG = { name: "RdbTest.db" }
let promise = data_rdb.getRdbStore(context, STORE_CONFIG, 1);
promise.then(async (rdbStore) => {
    console.log("Get RdbStore successfully.")
}).catch((err) => {
    console.log("Get RdbStore failed, err: " + err)
})
```

## data_rdb.deleteRdbStore<sup>(deprecated)</sup>

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

删除数据库，使用callback异步回调。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[data_rdb.deleteRdbStoreV9](#data_rdbdeleterdbstorev99)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| name     | string                    | 是   | 数据库名称。                                                 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。                                       |

**示例：**

FA模型示例：

```js
// 获取context
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// 获取context后调用deleteRdbStore
data_rdb.deleteRdbStore(context, "RdbTest.db", function (err) {
    if (err) {
        console.info("Delete RdbStore failed, err: " + err)
        return
    }
    console.log("Delete RdbStore successfully.")
})
```

Stage模型示例：

```ts
// 获取context
import Ability from '@ohos.application.Ability'
let context
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// 获取context后调用deleteRdbStore
data_rdb.deleteRdbStore(context, "RdbTest.db", function (err) {
    if (err) {
        console.info("Delete RdbStore failed, err: " + err)
        return
    }
    console.log("Delete RdbStore successfully.")
})
```

## data_rdb.deleteRdbStore<sup>(deprecated)</sup>

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

使用指定的数据库文件配置删除数据库，使用Promise异步回调。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[data_rdb.deleteRdbStoreV9](#data_rdbdeleterdbstorev99-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数**

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| name    | string  | 是   | 数据库名称。                                                 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

FA模型示例：

```js
// 获取context
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// 获取context后调用deleteRdbStore
let promise = data_rdb.deleteRdbStore(context, "RdbTest.db")
promise.then(() => {
    console.log("Delete RdbStore successfully.")
}).catch((err) => {
    console.info("Delete RdbStore failed, err: " + err)
})
```

Stage模型示例：

```ts
// 获取context
import Ability from '@ohos.application.Ability'
let context
class MainAbility extends Ability{
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// 获取context后调用deleteRdbStore
let promise = data_rdb.deleteRdbStore(context, "RdbTest.db")
promise.then(()=>{
    console.log("Delete RdbStore successfully.")
}).catch((err) => {
    console.info("Delete RdbStore failed, err: " + err)
})
```

## RdbPredicatesV9<sup>9+</sup>

表示关系型数据库（RDB）的谓词。该类确定RDB中条件表达式的值是true还是false。


### constructor<sup>9+</sup>

constructor(name: string)


构造函数。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| name   | string | 是   | 数据库表名。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
```

### inDevices<sup>9+</sup>

inDevices(devices: Array&lt;string&gt;): RdbPredicatesV9


同步分布式数据库时连接到组网内指定的远程设备。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名  | 类型                | 必填 | 说明                       |
| ------- | ------------------- | ---- | -------------------------- |
| devices | Array&lt;string&gt; | 是   | 指定的组网内的远程设备ID。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.inDevices(['12345678abcde'])
```

### inAllDevices<sup>9+</sup>

inAllDevices(): RdbPredicatesV9


同步分布式数据库时连接到组网内所有的远程设备。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesv9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.inAllDevices()
```

### equalTo<sup>9+</sup>

equalTo(field: string, value: ValueType): RdbPredicatesV9


配置谓词以匹配数据字段为ValueType且值等于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "lisi")
```


### notEqualTo<sup>9+</sup>

notEqualTo(field: string, value: ValueType): RdbPredicatesV9


配置谓词以匹配数据字段为ValueType且值不等于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.notEqualTo("NAME", "lisi")
```


### beginWrap<sup>9+</sup>

beginWrap(): RdbPredicatesV9


向谓词添加左括号。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回带有左括号的Rdb谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

### endWrap<sup>9+</sup>

endWrap(): RdbPredicatesV9

向谓词添加右括号。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回带有右括号的Rdb谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

### or<sup>9+</sup>

or(): RdbPredicatesV9

将或条件添加到谓词中。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回带有或条件的Rdb谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Lisa")
    .or()
    .equalTo("NAME", "Rose")
```

### and<sup>9+</sup>

and(): RdbPredicatesV9

向谓词添加和条件。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                      |
| ------------------------------------ | ------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回带有和条件的Rdb谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Lisa")
    .and()
    .equalTo("SALARY", 200.5)
```

### contains<sup>9+</sup>

contains(field: string, value: string): RdbPredicatesV9

配置谓词以匹配数据字段为string且value包含指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.contains("NAME", "os")
```

### beginsWith<sup>9+</sup>

beginsWith(field: string, value: string): RdbPredicatesV9

配置谓词以匹配数据字段为string且值以指定字符串开头的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.beginsWith("NAME", "os")
```

### endsWith<sup>9+</sup>

endsWith(field: string, value: string): RdbPredicatesV9

配置谓词以匹配数据字段为string且值以指定字符串结尾的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.endsWith("NAME", "se")
```

### isNull<sup>9+</sup>

isNull(field: string): RdbPredicatesV9

配置谓词以匹配值为null的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例**：

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.isNull("NAME")
```

### isNotNull<sup>9+</sup>

isNotNull(field: string): RdbPredicatesV9

配置谓词以匹配值不为null的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.isNotNull("NAME")
```

### like<sup>9+</sup>

like(field: string, value: string): RdbPredicatesV9

配置谓词以匹配数据字段为string且值类似于指定字符串的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| field  | string | 是   | 数据库表中的列名。     |
| value  | string | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.like("NAME", "%os%")
```

### glob<sup>9+</sup>

glob(field: string, value: string): RdbPredicatesV9

配置RdbPredicatesV9匹配数据字段为string的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| field  | string | 是   | 数据库表中的列名。                                           |
| value  | string | 是   | 指示要与谓词匹配的值。<br>支持通配符，*表示0个、1个或多个数字或字符，?表示1个数字或字符。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.glob("NAME", "?h*g")
```

### between<sup>9+</sup>

between(field: string, low: ValueType, high: ValueType): RdbPredicatesV9

将谓词配置为匹配数据字段为ValueType且value在给定范围内的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                       |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | 是   | 数据库表中的列名。         |
| low    | [ValueType](#valuetype) | 是   | 指示与谓词匹配的最小值。   |
| high   | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的最大值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.between("AGE", 10, 50)
```

### notBetween<sup>9+</sup>

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicatesV9

配置RdbPredicatesV9以匹配数据字段为ValueType且value超出给定范围的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                       |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | 是   | 数据库表中的列名。         |
| low    | [ValueType](#valuetype) | 是   | 指示与谓词匹配的最小值。   |
| high   | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的最大值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.notBetween("AGE", 10, 50)
```

### greaterThan<sup>9+</sup>

greaterThan(field: string, value: ValueType): RdbPredicatesV9

配置谓词以匹配数据字段为ValueType且值大于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.greaterThan("AGE", 18)
```

### lessThan<sup>9+</sup>

lessThan(field: string, value: ValueType): RdbPredicatesV9

配置谓词以匹配数据字段为valueType且value小于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.lessThan("AGE", 20)
```

### greaterThanOrEqualTo<sup>9+</sup>

greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicatesV9

配置谓词以匹配数据字段为ValueType且value大于或等于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.greaterThanOrEqualTo("AGE", 18)
```

### lessThanOrEqualTo<sup>9+</sup>

lessThanOrEqualTo(field: string, value: ValueType): RdbPredicatesV9

配置谓词以匹配数据字段为ValueType且value小于或等于指定值的字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                   |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | 是   | 数据库表中的列名。     |
| value  | [ValueType](#valuetype) | 是   | 指示要与谓词匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.lessThanOrEqualTo("AGE", 20)
```

### orderByAsc<sup>9+</sup>

orderByAsc(field: string): RdbPredicatesV9

配置谓词以匹配其值按升序排序的列。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.orderByAsc("NAME")
```

### orderByDesc<sup>9+</sup>

orderByDesc(field: string): RdbPredicatesV9

配置谓词以匹配其值按降序排序的列。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| field  | string | 是   | 数据库表中的列名。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.orderByDesc("AGE")
```

### distinct<sup>9+</sup>

distinct(): RdbPredicatesV9

配置谓词以过滤重复记录并仅保留其中一个。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型                                 | 说明                           |
| ------------------------------------ | ------------------------------ |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回可用于过滤重复记录的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Rose").distinct()
```

### limitAs<sup>9+</sup>

limitAs(value: number): RdbPredicatesV9

设置最大数据记录数的谓词。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| value  | number | 是   | 最大数据记录数。 |

**返回值**：

| 类型                                 | 说明                                 |
| ------------------------------------ | ------------------------------------ |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回可用于设置最大数据记录数的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Rose").limitAs(3)
```

### offsetAs<sup>9+</sup>

offsetAs(rowOffset: number): RdbPredicatesV9

配置RdbPredicatesV9以指定返回结果的起始位置。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                               |
| --------- | ------ | ---- | ---------------------------------- |
| rowOffset | number | 是   | 返回结果的起始位置，取值为正整数。 |

**返回值**：

| 类型                                 | 说明                                 |
| ------------------------------------ | ------------------------------------ |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回具有指定返回结果起始位置的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Rose").offsetAs(3)
```

### groupBy<sup>9+</sup>

groupBy(fields: Array&lt;string&gt;): RdbPredicatesV9

配置RdbPredicatesV9按指定列分组查询结果。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                | 必填 | 说明                 |
| ------ | ------------------- | ---- | -------------------- |
| fields | Array&lt;string&gt; | 是   | 指定分组依赖的列名。 |

**返回值**：

| 类型                                 | 说明                   |
| ------------------------------------ | ---------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回分组查询列的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.groupBy(["AGE", "NAME"])
```

### indexedBy<sup>9+</sup>

indexedBy(field: string): RdbPredicatesV9

配置RdbPredicatesV9以指定索引列。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| field  | string | 是   | 索引列的名称。 |

**返回值**：


| 类型                                 | 说明                                  |
| ------------------------------------ | ------------------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回具有指定索引列的RdbPredicatesV9。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.indexedBy("SALARY_INDEX")
```

### in<sup>9+</sup>

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicatesV9

配置RdbPredicatesV9以匹配数据字段为ValueType数组且值在给定范围内的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                 | 必填 | 说明                                    |
| ------ | ------------------------------------ | ---- | --------------------------------------- |
| field  | string                               | 是   | 数据库表中的列名。                      |
| value  | Array&lt;[ValueType](#valuetype)&gt; | 是   | 以ValueType型数组形式指定的要匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.in("AGE", [18, 20])
```

### notIn<sup>9+</sup>

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicatesV9

将RdbPredicatesV9配置为匹配数据字段为ValueType且值超出给定范围的指定字段。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                 | 必填 | 说明                                  |
| ------ | ------------------------------------ | ---- | ------------------------------------- |
| field  | string                               | 是   | 数据库表中的列名。                    |
| value  | Array&lt;[ValueType](#valuetype)&gt; | 是   | 以ValueType数组形式指定的要匹配的值。 |

**返回值**：

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [RdbPredicatesV9](#rdbpredicatesv99) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.notIn("NAME", ["Lisa", "Rose"])
```

## RdbStoreV9<sup>9+</sup>

提供管理关系数据库(RDB)方法的接口。

在使用以下相关接口前，请使用[executeSql](#executesql)接口初始化数据库表结构和相关数据，具体可见[关系型数据库开发指导](../../database/database-relational-guidelines.md)。

### insert<sup>9+</sup>

insert(table: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

向目标表中插入一行数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                       |
| -------- | ----------------------------- | ---- | ---------------------------------------------------------- |
| table    | string                        | 是   | 指定的目标表名。                                           |
| values   | [ValuesBucket](#valuesbucket) | 是   | 表示要插入到表中的数据行。                                 |
| callback | AsyncCallback&lt;number&gt;   | 是   | 指定callback回调函数。如果操作成功，返回行ID；否则返回-1。 |

**示例：**

```js
const valueBucket = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
rdbStoreV9.insert("EMPLOYEE", valueBucket, function (status, rowId) {
    if (status) {
        console.log("Insert is failed");
        return;
    }
    console.log("Insert is successful, rowId = " + rowId);
})
```

### insert<sup>9+</sup>

insert(table: string, values: ValuesBucket):Promise&lt;number&gt;

向目标表中插入一行数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                          | 必填 | 说明                       |
| ------ | ----------------------------- | ---- | -------------------------- |
| table  | string                        | 是   | 指定的目标表名。           |
| values | [ValuesBucket](#valuesbucket) | 是   | 表示要插入到表中的数据行。 |

**返回值**：

| 类型                  | 说明                                              |
| --------------------- | ------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回行ID；否则返回-1。 |

**示例：**

```js
const valueBucket = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let promise = rdbStoreV9.insert("EMPLOYEE", valueBucket)
promise.then((rowId) => {
    console.log("Insert is successful, rowId = " + rowId);
}).catch((status) => {
    console.log("Insert is failed");
})
```

### batchInsert<sup>9+</sup>

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;):void

向目标表中插入一组数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                         |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| table    | string                                     | 是   | 指定的目标表名。                                             |
| values   | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。                                 |
| callback | AsyncCallback&lt;number&gt;                | 是   | 指定callback回调函数。如果操作成功，返回插入的数据个数，否则返回-1。 |

**示例：**

```js
const valueBucket1 = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5])
}
const valueBucket2 = {
    "NAME": "Jack",
    "AGE": 19,
    "SALARY": 101.5,
    "CODES": new Uint8Array([6, 7, 8, 9, 10])
}
const valueBucket3 = {
    "NAME": "Tom",
    "AGE": 20,
    "SALARY": 102.5,
    "CODES": new Uint8Array([11, 12, 13, 14, 15])
}

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
rdbStoreV9.batchInsert("EMPLOYEE", valueBuckets, function(status, insertNum) {
    if (status) {
        console.log("batchInsert is failed, status = " + status);
        return;
    }
    console.log("batchInsert is successful, the number of values that were inserted = " + insertNum);
})
```

### batchInsert<sup>9+</sup>

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;):Promise&lt;number&gt;

向目标表中插入一组数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                       | 必填 | 说明                         |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | 是   | 指定的目标表名。             |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是   | 表示要插入到表中的一组数据。 |

**返回值**：

| 类型                  | 说明                                                        |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回插入的数据个数，否则返回-1。 |

**示例：**

```js
const valueBucket1 = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5])
}
const valueBucket2 = {
    "NAME": "Jack",
    "AGE": 19,
    "SALARY": 101.5,
    "CODES": new Uint8Array([6, 7, 8, 9, 10])
}
const valueBucket3 = {
    "NAME": "Tom",
    "AGE": 20,
    "SALARY": 102.5,
    "CODES": new Uint8Array([11, 12, 13, 14, 15])
}

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
let promise = rdbStoreV9.batchInsert("EMPLOYEE", valueBuckets);
promise.then((insertNum) => {
    console.log("batchInsert is successful, the number of values that were inserted = " + insertNum);
}).catch((status) => {
    console.log("batchInsert is failed, status = " + status);
})
```

### update<sup>9+</sup>

update(values: ValuesBucket, predicates: RdbPredicatesV9, callback: AsyncCallback&lt;number&gt;):void

根据RdbPredicatesV9的指定实例对象更新数据库中的数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                                         |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)        | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99) | 是   | RdbPredicatesV9的实例对象指定的更新条件。                    |
| callback   | AsyncCallback&lt;number&gt;          | 是   | 指定的callback回调方法。返回受影响的行数。                   |

**示例：**

```js
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Lisa")
rdbStoreV9.update(valueBucket, predicatesV9, function (err, ret) {
    if (err) {
        console.info("Updated failed, err: " + err)
        return
    }
    console.log("Updated row count: " + ret)
})
```

### update<sup>9+</sup>

update(values: ValuesBucket, predicates: RdbPredicatesV9):Promise&lt;number&gt;

根据RdbPredicatesV9的指定实例对象更新数据库中的数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型                                 | 必填 | 说明                                                         |
| ------------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| values       | [ValuesBucket](#valuesbucket)        | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicatesV9 | [RdbPredicatesV9](#rdbpredicatesv99) | 是   | RdbPredicatesV9的实例对象指定的更新条件。                    |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回受影响的行数。 |

**示例：**

```js
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Lisa")
let promise = rdbStoreV9.update(valueBucket, predicatesV9)
promise.then(async (ret) => {
    console.log("Updated row count: " + ret)
}).catch((err) => {
    console.info("Updated failed, err: " + err)
})
```

### update<sup>9+</sup>

update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;):void

根据DataSharePredicates的指定实例对象更新数据库中的数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| table      | string                                                       | 是   | 指定的目标表名。                                             |
| values     | [ValuesBucket](#valuesbucket)                                | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | DataSharePredicates的实例对象指定的更新条件。                |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 指定的callback回调方法。返回受影响的行数。                   |

**示例：**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Lisa")
rdbStoreV9.update("EMPLOYEE", valueBucket, predicates, function (err, ret) {
    if (err) {
        console.info("Updated failed, err: " + err)
        return
    }
    console.log("Updated row count: " + ret)
})
```

### update<sup>9+</sup>

update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates):Promise&lt;number&gt;

根据DataSharePredicates的指定实例对象更新数据库中的数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| table      | string                                                       | 是   | 指定的目标表名。                                             |
| values     | [ValuesBucket](#valuesbucket)                                | 是   | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | DataSharePredicates的实例对象指定的更新条件。                |

**返回值**：

| 类型                  | 说明                                      |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回受影响的行数。 |

**示例：**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Lisa")
let promise = rdbStoreV9.update("EMPLOYEE", valueBucket, predicates)
promise.then(async (ret) => {
    console.log("Updated row count: " + ret)
}).catch((err) => {
    console.info("Updated failed, err: " + err)
})
```

### delete<sup>9+</sup>

delete(predicates: RdbPredicatesV9, callback: AsyncCallback&lt;number&gt;):void

根据RdbPredicatesV9的指定实例对象从数据库中删除数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                      |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99) | 是   | RdbPredicatesV9的实例对象指定的删除条件。 |
| callback   | AsyncCallback&lt;number&gt;          | 是   | 指定callback回调函数。返回受影响的行数。  |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Lisa")
rdbStoreV9.delete(predicatesV9, function (err, rows) {
    if (err) {
        console.info("Delete failed, err: " + err)
        return
    }
    console.log("Delete rows: " + rows)
})
```

### delete<sup>9+</sup>

delete(predicates: RdbPredicatesV9):Promise&lt;number&gt;

根据RdbPredicatesV9的指定实例对象从数据库中删除数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                      |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99) | 是   | RdbPredicatesV9的实例对象指定的删除条件。 |

**返回值**：

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回受影响的行数。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Lisa")
let promise = rdbStoreV9.delete(predicatesV9)
promise.then((rows) => {
    console.log("Delete rows: " + rows)
}).catch((err) => {
    console.info("Delete failed, err: " + err)
})
```

### delete<sup>9+</sup>

delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;):void

根据DataSharePredicates的指定实例对象从数据库中删除数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                          |
| ---------- | ------------------------------------------------------------ | ---- | --------------------------------------------- |
| table      | string                                                       | 是   | 指定的目标表名。                              |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | DataSharePredicates的实例对象指定的删除条件。 |
| callback   | AsyncCallback&lt;number&gt;                                  | 是   | 指定callback回调函数。返回受影响的行数。      |

**示例：**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Lisa")
rdbStoreV9.delete("EMPLOYEE", predicates, function (err, rows) {
    if (err) {
        console.info("Delete failed, err: " + err)
        return
    }
    console.log("Delete rows: " + rows)
})
```

### delete<sup>9+</sup>

delete(table: string, predicates: dataSharePredicates.DataSharePredicates):Promise&lt;number&gt;

根据DataSharePredicates的指定实例对象从数据库中删除数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                          |
| ---------- | ------------------------------------------------------------ | ---- | --------------------------------------------- |
| table      | string                                                       | 是   | 指定的目标表名。                              |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | DataSharePredicates的实例对象指定的删除条件。 |

**返回值**：

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回受影响的行数。 |

**示例：**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Lisa")
let promise = rdbStoreV9.delete("EMPLOYEE", predicates)
promise.then((rows) => {
    console.log("Delete rows: " + rows)
}).catch((err) => {
    console.info("Delete failed, err: " + err)
})
```

### query<sup>9+</sup>

query(predicates: RdbPredicatesV9, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSetV9&gt;):void

根据指定条件查询数据库中的数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99)                         | 是   | RdbPredicatesV9的实例对象指定的查询条件。                   |
| columns    | Array&lt;string&gt;                                          | 是   | 表示要查询的列。如果值为空，则查询应用于所有列。            |
| callback   | AsyncCallback&lt;[ResultSetV9](js-apis-data-resultset.md)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSetV9对象。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Rose")
rdbStoreV9.query(predicatesV9, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSetV9) {
    if (err) {
        console.info("Query failed, err: " + err)
        return
    }
    console.log("ResultSet column names: " + resultSetV9.columnNames)
    console.log("ResultSet column count: " + resultSetV9.columnCount)
})
```

### query<sup>9+</sup>

query(predicates: RdbPredicatesV9, columns?: Array&lt;string&gt;):Promise&lt;ResultSetV9&gt;

根据指定条件查询数据库中的数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                             |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99) | 是   | RdbPredicatesV9的实例对象指定的查询条件。        |
| columns    | Array&lt;string&gt;                  | 否   | 表示要查询的列。如果值为空，则查询应用于所有列。 |

**返回值**：

| 类型                                                    | 说明                                               |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSetV9](js-apis-data-resultset.md)&gt; | Promise对象。如果操作成功，则返回ResultSetV9对象。 |

**示例：**

  ```js
let predicatesV9 = new data_rdb.RdbPredicatesV9("EMPLOYEE")
predicatesV9.equalTo("NAME", "Rose")
let promise = rdbStoreV9.query(predicatesV9, ["ID", "NAME", "AGE", "SALARY", "CODES"])
promise.then((resultSetV9) => {
    console.log("ResultSet column names: " + resultSetV9.columnNames)
    console.log("ResultSet column count: " + resultSetV9.columnCount)
}).catch((err) => {
    console.info("Query failed, err: " + err)
})
  ```

### query<sup>9+</sup>

query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSetV9&gt;):void

根据指定条件查询数据库中的数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| table      | string                                                       | 是   | 指定的目标表名。                                            |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | DataSharePredicates的实例对象指定的查询条件。               |
| columns    | Array&lt;string&gt;                                          | 是   | 表示要查询的列。如果值为空，则查询应用于所有列。            |
| callback   | AsyncCallback&lt;[ResultSetV9](js-apis-data-resultset.md)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSetV9对象。 |

**示例：**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose")
rdbStoreV9.query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSetV9) {
    if (err) {
        console.info("Query failed, err: " + err)
        return
    }
    console.log("ResultSet column names: " + resultSetV9.columnNames)
    console.log("ResultSet column count: " + resultSetV9.columnCount)
})
```

### query<sup>9+</sup>

query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSetV9&gt;

根据指定条件查询数据库中的数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                             |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| table      | string                                                       | 是   | 指定的目标表名。                                 |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | 是   | DataSharePredicates的实例对象指定的查询条件。    |
| columns    | Array&lt;string&gt;                                          | 否   | 表示要查询的列。如果值为空，则查询应用于所有列。 |

**返回值**：

| 类型                                                    | 说明                                               |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSetV9](js-apis-data-resultset.md)&gt; | Promise对象。如果操作成功，则返回ResultSetV9对象。 |

**示例：**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
let predicates = new dataSharePredicates.DataSharePredicates()
predicates.equalTo("NAME", "Rose")
let promise = rdbStoreV9.query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
promise.then((resultSetV9) => {
    console.log("ResultSet column names: " + resultSetV9.columnNames)
    console.log("ResultSet column count: " + resultSetV9.columnCount)
}).catch((err) => {
    console.info("Query failed, err: " + err)
})
```

### remoteQuery<sup>9+</sup>

remoteQuery(device: string, table: string, predicates: RdbPredicatesV9, columns: Array&lt;string&gt; , callback: AsyncCallback&lt;ResultSetV9&gt;): void

根据指定条件查询远程设备数据库中的数据。使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| device     | string                                                       | 是   | 指定的远程设备的networkId。                                 |
| table      | string                                                       | 是   | 指定的目标表名。                                            |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99)                         | 是   | RdbPredicatesV9的实例对象，指定查询的条件。                 |
| columns    | Array&lt;string&gt;                                          | 是   | 表示要查询的列。如果值为空，则查询应用于所有列。            |
| callback   | AsyncCallback&lt;[ResultSetV9](js-apis-data-resultset.md#resultset)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSetV9对象。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9('EMPLOYEE')
predicatesV9.greaterThan("id", 0)
rdbStoreV9.remoteQuery("deviceId", "EMPLOYEE", predicatesV9, ["ID", "NAME", "AGE", "SALARY", "CODES"],
    function(err, resultSetV9){
    if (err) {
        console.info("Failed to remoteQuery, err: " + err)
        return
    }
    console.info("ResultSet column names: " + resultSetV9.columnNames)
    console.info("ResultSet column count: " + resultSetV9.columnCount)
})
```

### remoteQuery<sup>9+</sup>

remoteQuery(device: string, table: string, predicates: RdbPredicatesV9, columns: Array&lt;string&gt;): Promise&lt;ResultSetV9&gt;

根据指定条件查询远程设备数据库中的数据。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                                             |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| device     | string                               | 是   | 指定的远程设备的networkId。                      |
| table      | string                               | 是   | 指定的目标表名。                                 |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99) | 是   | RdbPredicatesV9的实例对象，指定查询的条件。      |
| columns    | Array&lt;string&gt;                  | 是   | 表示要查询的列。如果值为空，则查询应用于所有列。 |

**返回值**：

| 类型                                                         | 说明                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| Promise&lt;[ResultSetV9](js-apis-data-resultset.md#resultset)&gt; | Promise对象。如果操作成功，则返回ResultSetV9对象。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9('EMPLOYEE')
predicatesV9.greaterThan("id", 0)
let promise = rdbStoreV9.remoteQuery("deviceId", "EMPLOYEE", predicatesV9, ["ID", "NAME", "AGE", "SALARY", "CODES"])
promise.then((resultSetV9) => {
    console.info("ResultSet column names: " + resultSetV9.columnNames)
    console.info("ResultSet column count: " + resultSetV9.columnCount)
}).catch((err) => {
    console.info("Failed to remoteQuery , err: " + err)
})
```

### querySql<sup>9+</sup>

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSetV9&gt;):void

根据指定SQL语句查询数据库中的数据，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                        |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| sql      | string                                                       | 是   | 指定要执行的SQL语句。                                       |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt;                         | 是   | SQL语句中参数的值。                                         |
| callback | AsyncCallback&lt;[ResultSetV9](js-apis-data-resultset.md)&gt; | 是   | 指定callback回调函数。如果操作成功，则返回ResultSetV9对象。 |

**示例：**

```js
rdbStoreV9.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], function (err, resultSetV9) {
    if (err) {
        console.info("Query failed, err: " + err)
        return
    }
    console.log("ResultSet column names: " + resultSetV9.columnNames)
    console.log("ResultSet column count: " + resultSetV9.columnCount)
})
```

### querySql<sup>9+</sup>

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSetV9&gt;

根据指定SQL语句查询数据库中的数据，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                  |
| -------- | ------------------------------------ | ---- | --------------------- |
| sql      | string                               | 是   | 指定要执行的SQL语句。 |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。   |

**返回值**：

| 类型                                                    | 说明                                               |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSetV9](js-apis-data-resultset.md)&gt; | Promise对象。如果操作成功，则返回ResultSetV9对象。 |

**示例：**

```js
let promise = rdbStoreV9.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'])
promise.then((resultSetV9) => {
    console.log("ResultSet column names: " + resultSetV9.columnNames)
    console.log("ResultSet column count: " + resultSetV9.columnCount)
}).catch((err) => {
    console.info("Query failed, err: " + err)
})
```

### executeSql<sup>9+</sup>

executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void

执行包含指定参数但不返回值的SQL语句，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                   |
| -------- | ------------------------------------ | ---- | ---------------------- |
| sql      | string                               | 是   | 指定要执行的SQL语句。  |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 是   | SQL语句中参数的值。    |
| callback | AsyncCallback&lt;void&gt;            | 是   | 指定callback回调函数。 |

**示例：**

```js
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
rdbStoreV9.executeSql(SQL_CREATE_TABLE, null, function(err) {
    if (err) {
        console.info("ExecuteSql failed, err: " + err)
        return
    }
    console.info('Create table done.')
})
```

### executeSql<sup>9+</sup>

executeSql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;void&gt;

执行包含指定参数但不返回值的SQL语句，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                  |
| -------- | ------------------------------------ | ---- | --------------------- |
| sql      | string                               | 是   | 指定要执行的SQL语句。 |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 否   | SQL语句中参数的值。   |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
let promise = rdbStoreV9.executeSql(SQL_CREATE_TABLE)
promise.then(() => {
    console.info('Create table done.')
}).catch((err) => {
    console.info("ExecuteSql failed, err: " + err)
})
```

### beginTransaction<sup>9+</sup>

beginTransaction():void

在开始执行SQL语句之前，开始事务。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db",
                     securityLevel: data_rdb.SecurityLevel.S1}
data_rdb.getRdbStoreV9(context, STORE_CONFIG, 1, async function (err, rdbStoreV9) {
    rdbStoreV9.beginTransaction()
	const valueBucket = {
		"name": "lisi",
		"age": 18,
		"salary": 100.5,
		"blobType": new Uint8Array([1, 2, 3]),
	}
	await rdbStoreV9.insert("test", valueBucket)
	rdbStoreV9.commit()
})
```

### commit<sup>9+</sup>

commit():void

提交已执行的SQL语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db",
                     securityLevel: data_rdb.SecurityLevel.S1}
data_rdb.getRdbStoreV9(context, STORE_CONFIG, 1, async function (err, rdbStoreV9) {
    rdbStoreV9.beginTransaction()
	const valueBucket = {
		"name": "lisi",
		"age": 18,
		"salary": 100.5,
		"blobType": new Uint8Array([1, 2, 3]),
	}
	await rdbStoreV9.insert("test", valueBucket)
	rdbStoreV9.commit()
})
```

### rollBack<sup>9+</sup>

rollBack():void

回滚已经执行的SQL语句。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db",
                     securityLevel: data_rdb.SecurityLevel.S1}
data_rdb.getRdbStoreV9(context, STORE_CONFIG, 1, async function (err, rdbStoreV9) {
    try {
		rdbStoreV9.beginTransaction()
		const valueBucket = {
			"id": 1,
			"name": "lisi",
			"age": 18,
			"salary": 100.5,
			"blobType": new Uint8Array([1, 2, 3]),
		}
		await rdbStoreV9.insert("test", valueBucket)
		rdbStoreV9.commit()
	} catch (e) {
		rdbStoreV9.rollBack()
	}
})
```

### backup<sup>9+</sup>

backup(destName:string, callback: AsyncCallback&lt;void&gt;):void

以指定名称备份数据库，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| destName | string                    | 是   | 指定数据库的备份文件名。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。   |

**示例：**

```js
rdbStoreV9.backup("dbBackup.db", function(err) {
    if (err) {
        console.info('Backup failed, err: ' + err)
        return
    }
    console.info('Backup success.')
})
```

### backup<sup>9+</sup>

backup(destName:string): Promise&lt;void&gt;

以指定名称备份数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明                     |
| -------- | ------ | ---- | ------------------------ |
| destName | string | 是   | 指定数据库的备份文件名。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promiseBackup = rdbStoreV9.backup("dbBackup.db")
promiseBackup.then(()=>{
    console.info('Backup success.')
}).catch((err)=>{
    console.info('Backup failed, err: ' + err)
})
```

### restore<sup>9+</sup>

restore(srcName:string, callback: AsyncCallback&lt;void&gt;):void

从指定的数据库备份文件恢复数据库，使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| srcName  | string                    | 是   | 指定数据库的备份文件名。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。   |

**示例：**

```js
rdbStoreV9.restore("dbBackup.db", function(err) {
    if (err) {
        console.info('Restore failed, err: ' + err)
        return
    }
    console.info('Restore success.')
})
```

### restore<sup>9+</sup>

restore(srcName:string): Promise&lt;void&gt;

从指定的数据库备份文件恢复数据库，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                     |
| ------- | ------ | ---- | ------------------------ |
| srcName | string | 是   | 指定数据库的备份文件名。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promiseRestore = rdbStoreV9.restore("dbBackup.db")
promiseRestore.then(()=>{
    console.info('Restore success.')
}).catch((err)=>{
    console.info('Restore failed, err: ' + err)
})
```

### setDistributedTables<sup>9+</sup>

setDistributedTables(tables: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

设置分布式列表，使用callback异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| tables   | Array&lt;string&gt;       | 是   | 要设置的分布式列表表名 |
| callback | AsyncCallback&lt;void&gt; | 是   | 指定callback回调函数。 |

**示例：**

```js
rdbStoreV9.setDistributedTables(["EMPLOYEE"], function (err) {
    if (err) {
        console.info('SetDistributedTables failed, err: ' + err)
        return
    }
    console.info('SetDistributedTables successfully.')
})
```

### setDistributedTables<sup>9+</sup>

 setDistributedTables(tables: Array&lt;string&gt;): Promise&lt;void&gt;

设置分布式列表，使用Promise异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                | 必填 | 说明                     |
| ------ | ------------------- | ---- | ------------------------ |
| tables | Array&lt;string&gt; | 是   | 要设置的分布式列表表名。 |

**返回值**：

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = rdbStoreV9.setDistributedTables(["EMPLOYEE"])
promise.then(() => {
    console.info("SetDistributedTables successfully.")
}).catch((err) => {
    console.info("SetDistributedTables failed, err: " + err)
})
```

### obtainDistributedTableName<sup>9+</sup>

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void

根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名, 使用callback异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| device   | string                      | 是   | 远程设备 。                                                  |
| table    | string                      | 是   | 本地表名。                                                   |
| callback | AsyncCallback&lt;string&gt; | 是   | 指定的callback回调函数。如果操作成功，返回远程设备的分布式表名。 |

**示例：**

```js
rdbStoreV9.obtainDistributedTableName("12345678abcde", "EMPLOYEE", function (err, tableName) {
    if (err) {
        console.info('ObtainDistributedTableName failed, err: ' + err)
        return
    }
    console.info('ObtainDistributedTableName successfully, tableName=.' + tableName)
})
```

### obtainDistributedTableName<sup>9+</sup>

 obtainDistributedTableName(device: string, table: string): Promise&lt;string&gt;

根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名，使用Promise异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| device | string | 是   | 远程设备。 |
| table  | string | 是   | 本地表名。 |

**返回值**：

| 类型                  | 说明                                                  |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;string&gt; | Promise对象。如果操作成功，返回远程设备的分布式表名。 |

**示例：**

```js
let promise = rdbStoreV9.obtainDistributedTableName("12345678abcde", "EMPLOYEE")
promise.then((tableName) => {
    console.info('ObtainDistributedTableName successfully, tableName= ' + tableName)
}).catch((err) => {
    console.info('ObtainDistributedTableName failed, err: ' + err)
})
```

### sync<sup>9+</sup>

sync(mode: SyncMode, predicates: RdbPredicatesV9, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void

在设备之间同步数据, 使用callback异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                               | 必填 | 说明                                                         |
| ---------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| mode       | [SyncMode](#syncmode8)                             | 是   | 指同步模式。该值可以是推、拉。                               |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99)               | 是   | 约束同步数据和设备。                                         |
| callback   | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | 是   | 指定的callback回调函数，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9('EMPLOYEE')
predicatesV9.inDevices(['12345678abcde'])
rdbStoreV9.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicatesV9, function (err, result) {
    if (err) {
        console.log('Sync failed, err: ' + err)
        return
    }
    console.log('Sync done.')
    for (let i = 0; i < result.length; i++) {
        console.log('device=' + result[i][0] + ' status=' + result[i][1])
    }
})
```

### sync<sup>9+</sup>

 sync(mode: SyncMode, predicates: RdbPredicatesV9): Promise&lt;Array&lt;[string, number]&gt;&gt;

在设备之间同步数据，使用Promise异步回调。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名     | 类型                                 | 必填 | 说明                           |
| ---------- | ------------------------------------ | ---- | ------------------------------ |
| mode       | [SyncMode](#syncmode8)               | 是   | 指同步模式。该值可以是推、拉。 |
| predicates | [RdbPredicatesV9](#rdbpredicatesv99) | 是   | 约束同步数据和设备。           |

**返回值**：

| 类型                                         | 说明                                                         |
| -------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise对象，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |

**示例：**

```js
let predicatesV9 = new data_rdb.RdbPredicatesV9('EMPLOYEE')
predicatesV9.inDevices(['12345678abcde'])
let promise = rdbStoreV9.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicatesV9)
promise.then((resultSetV9) =>{
    console.log('Sync done.')
    for (let i = 0; i < resultSetV9.length; i++) {
        console.log('device=' + resultSetV9[i][0] + ' status=' + resultSetV9[i][1])
    }
}).catch((err) => {
    console.log('Sync failed')
})
```

### on('dataChange')<sup>9+</sup>

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

注册数据库的观察者。当分布式数据库中的数据发生更改时，将调用回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------- |
| event    | string                              | 是   | 取值为'dataChange'，表示数据更改。          |
| type     | [SubscribeType](#subscribetype8)    | 是   | 指在{@code SubscribeType}中定义的订阅类型。 |
| observer | Callback&lt;Array&lt;string&gt;&gt; | 是   | 指分布式数据库中数据更改事件的观察者。      |

**示例：**

```js
function storeObserver(devices) {
    for (let i = 0; i < devices.length; i++) {
        console.log('device=' + devices[i] + ' data changed')
    }
}
try {
    rdbStoreV9.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
} catch (err) {
    console.log('Register observer failed')
}
```

### off('dataChange')<sup>9+</sup>

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

从数据库中删除指定类型的指定观察者, 使用callback异步回调。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------- |
| event    | string                              | 是   | 取值为'dataChange'，表示数据更改。          |
| type     | [SubscribeType](#subscribetype8)    | 是   | 指在{@code SubscribeType}中定义的订阅类型。 |
| observer | Callback&lt;Array&lt;string&gt;&gt; | 是   | 指已注册的数据更改观察者。                  |

**示例：**

```js
function storeObserver(devices) {
    for (let i = 0; i < devices.length; i++) {
        console.log('device=' + devices[i] + ' data changed')
    }
}
try {
    rdbStoreV9.off('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
} catch (err) {
    console.log('Unregister observer failed')
}
```

## StoreConfigV9<sup>9+</sup>

管理关系数据库配置。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称        | 类型          | 必填 | 说明                                                      |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | 是   | 数据库文件名。                                            |
| securityLevel | SecurityLevel | 是   | 设置数据库安全级别                                        |
| encrypt       | boolean       | 否   | 指定数据库是否加密。<br/> true:加密。<br/> false:非加密。 |

## SecurityLevel<sup>9+</sup>

数据库的安全级别枚举。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称 | 值   | 说明                                                         |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | 表示数据库的安全级别为低级别，当数据泄露时会产生较低影响。例如，包含壁纸等系统数据的数据库。 |
| S2   | 2    | 表示数据库的安全级别为中级别，当数据泄露时会产生较大影响。例如，包含录音、视频等用户生成数据或通话记录等信息的数据库。 |
| S3   | 3    | 表示数据库的安全级别为高级别，当数据泄露时会产生重大影响。例如，包含用户运动、健康、位置等信息的数据库。 |
| S4   | 4    | 表示数据库的安全级别为关键级别，当数据泄露时会产生严重影响。例如，包含认证凭据、财务数据等信息的数据库。 |

## ValueType

用于表示允许的数据字段类型。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型    | 说明                 |
| ------- | -------------------- |
| number  | 表示值类型为数字。   |
| string  | 表示值类型为字符。   |
| boolean | 表示值类型为布尔值。 |


## ValuesBucket

用于存储键值对的类型。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 键类型 | 值类型                                                      |
| ------ | ----------------------------------------------------------- |
| string | [ValueType](#valuetype)\|&nbsp;Uint8Array&nbsp;\|&nbsp;null |

## SyncMode<sup>8+</sup>

指数据库同步模式。

**系统能力：**SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称           | 值   | 说明                               |
| -------------- | ---- | ---------------------------------- |
| SYNC_MODE_PUSH | 0    | 表示数据从本地设备推送到远程设备。 |
| SYNC_MODE_PULL | 1    | 表示数据从远程设备拉至本地设备。   |

## SubscribeType<sup>8+</sup>

描述订阅类型。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称                  | 值   | 说明               |
| --------------------- | ---- | ------------------ |
| SUBSCRIBE_TYPE_REMOTE | 0    | 订阅远程数据更改。 |

## RdbPredicates<sup>(deprecated)</sup>

表示关系型数据库（RDB）的谓词。该类确定RDB中条件表达式的值是true还是false。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[RdbPredicatesV9](#rdbpredicatesv99)替代。


### constructor<sup>(deprecated)</sup>

constructor(name: string)

构造函数。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[constructor](#constructor9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 数据库表名。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
```

### inDevices<sup>(deprecated)</sup>

inDevices(devices: Array&lt;string&gt;): RdbPredicates

同步分布式数据库时连接到组网内指定的远程设备。

> **说明：**
>
> 从 API Version 8 开始支持，从 API Version 9 开始废弃，建议使用[inDevices](#indevices9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| devices | Array&lt;string&gt; | 是 | 指定的组网内的远程设备ID。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.inDevices(['12345678abcde'])
```

### inAllDevices<sup>(deprecated)</sup>

inAllDevices(): RdbPredicates

同步分布式数据库时连接到组网内所有的远程设备。

> **说明：**
>
> 从 API Version 8 开始支持，从 API Version 9 开始废弃，建议使用[inAllDevices](#inalldevices9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.inAllDevices()
```

### equalTo<sup>(deprecated)</sup>

equalTo(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据字段为ValueType且值等于指定值的字段。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[equalTo](#equalto9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
```


### notEqualTo<sup>(deprecated)</sup>

notEqualTo(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据字段为ValueType且值不等于指定值的字段。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[notEqualTo](#notequalto9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notEqualTo("NAME", "lisi")
```


### beginWrap<sup>(deprecated)</sup>

beginWrap(): RdbPredicates

向谓词添加左括号。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[beginWrap](#beginwrap9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回带有左括号的Rdb谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

### endWrap<sup>(deprecated)</sup>

endWrap(): RdbPredicates

向谓词添加右括号。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[endWrap](#endwrap9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回带有右括号的Rdb谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

### or<sup>(deprecated)</sup>

or(): RdbPredicates

将或条件添加到谓词中。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[or](#or9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回带有或条件的Rdb谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
    .or()
    .equalTo("NAME", "Rose")
```

### and<sup>(deprecated)</sup>

and(): RdbPredicates

向谓词添加和条件。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[and](#and9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回带有和条件的Rdb谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
    .and()
    .equalTo("SALARY", 200.5)
```

### contains<sup>(deprecated)</sup>

contains(field: string, value: string): RdbPredicates

配置谓词以匹配数据字段为string且value包含指定值的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[contains](#contains9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.contains("NAME", "os")
```

### beginsWith<sup>(deprecated)</sup>

beginsWith(field: string, value: string): RdbPredicates

配置谓词以匹配数据字段为string且值以指定字符串开头的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[beginsWith](#beginswith9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.beginsWith("NAME", "os")
```

### endsWith<sup>(deprecated)</sup>

endsWith(field: string, value: string): RdbPredicates

配置谓词以匹配数据字段为string且值以指定字符串结尾的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[endsWith](#endswith9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.endsWith("NAME", "se")
```

### isNull<sup>(deprecated)</sup>

isNull(field: string): RdbPredicates

配置谓词以匹配值为null的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[isNull](#isnull9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例**：
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.isNull("NAME")
```

### isNotNull<sup>(deprecated)</sup>

isNotNull(field: string): RdbPredicates

配置谓词以匹配值不为null的指定字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[isNotNull](#isnotnull9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.isNotNull("NAME")
```

### like<sup>(deprecated)</sup>

like(field: string, value: string): RdbPredicates

配置谓词以匹配数据字段为string且值类似于指定字符串的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[like](#like9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.like("NAME", "%os%")
```

### glob<sup>(deprecated)</sup>

glob(field: string, value: string): RdbPredicates

配置RdbPredicates匹配数据字段为string的指定字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[glob](#glob9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | string | 是 | 指示要与谓词匹配的值。<br>支持通配符，*表示0个、1个或多个数字或字符，?表示1个数字或字符。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.glob("NAME", "?h*g")
```

### between<sup>(deprecated)</sup>

between(field: string, low: ValueType, high: ValueType): RdbPredicates

将谓词配置为匹配数据字段为ValueType且value在给定范围内的指定字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[between](#between9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| low | [ValueType](#valuetype) | 是 | 指示与谓词匹配的最小值。 |
| high | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的最大值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.between("AGE", 10, 50)
```

### notBetween<sup>(deprecated)</sup>

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates

配置RdbPredicates以匹配数据字段为ValueType且value超出给定范围的指定字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[notBetween](#notbetween9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| low | [ValueType](#valuetype) | 是 | 指示与谓词匹配的最小值。 |
| high | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的最大值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notBetween("AGE", 10, 50)
```

### greaterThan<sup>(deprecated)</sup>

greaterThan(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据字段为ValueType且值大于指定值的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[greaterThan](#greaterthan9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.greaterThan("AGE", 18)
```

### lessThan<sup>(deprecated)</sup>

lessThan(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据字段为valueType且value小于指定值的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[lessThan](#lessthan9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.lessThan("AGE", 20)
```

### greaterThanOrEqualTo<sup>(deprecated)</sup>

greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据字段为ValueType且value大于或等于指定值的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[greaterThanOrEqualTo](#greaterthanorequalto9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.greaterThanOrEqualTo("AGE", 18)
```

### lessThanOrEqualTo<sup>(deprecated)</sup>

lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates

配置谓词以匹配数据字段为ValueType且value小于或等于指定值的字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[lessThanOrEqualTo](#lessthanorequalto9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | [ValueType](#valuetype) | 是 | 指示要与谓词匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.lessThanOrEqualTo("AGE", 20)
```

### orderByAsc<sup>(deprecated)</sup>

orderByAsc(field: string): RdbPredicates

配置谓词以匹配其值按升序排序的列。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[orderByAsc](#orderbyasc9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.orderByAsc("NAME")
```

### orderByDesc<sup>(deprecated)</sup>

orderByDesc(field: string): RdbPredicates

配置谓词以匹配其值按降序排序的列。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[orderByDesc](#orderbydesc9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.orderByDesc("AGE")
```

### distinct<sup>(deprecated)</sup>

distinct(): RdbPredicates

配置谓词以过滤重复记录并仅保留其中一个。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[distinct](#distinct9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回可用于过滤重复记录的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").distinct()
```

### limitAs<sup>(deprecated)</sup>

limitAs(value: number): RdbPredicates

设置最大数据记录数的谓词。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[limitAs](#limitas9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 最大数据记录数。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回可用于设置最大数据记录数的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").limitAs(3)
```

### offsetAs<sup>(deprecated)</sup>

offsetAs(rowOffset: number): RdbPredicates

配置RdbPredicates以指定返回结果的起始位置。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[offsetAs](#offsetas9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| rowOffset | number | 是 | 返回结果的起始位置，取值为正整数。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回具有指定返回结果起始位置的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").offsetAs(3)
```

### groupBy<sup>(deprecated)</sup>

groupBy(fields: Array&lt;string&gt;): RdbPredicates

配置RdbPredicates按指定列分组查询结果。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[groupBy](#groupby9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fields | Array&lt;string&gt; | 是 | 指定分组依赖的列名。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回分组查询列的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.groupBy(["AGE", "NAME"])
```

### indexedBy<sup>(deprecated)</sup>

indexedBy(field: string): RdbPredicates

配置RdbPredicates以指定索引列。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[indexedBy](#indexedby9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 索引列的名称。 |

**返回值**：


| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回具有指定索引列的RdbPredicates。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.indexedBy("SALARY_INDEX")
```

### in<sup>(deprecated)</sup>

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

配置RdbPredicates以匹配数据字段为ValueType数组且值在给定范围内的指定字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[in](#in9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | Array&lt;[ValueType](#valuetype)&gt; | 是 | 以ValueType型数组形式指定的要匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.in("AGE", [18, 20])
```

### notIn<sup>(deprecated)</sup>

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

将RdbPredicates配置为匹配数据字段为ValueType且值超出给定范围的指定字段。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[notIn](#notin9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| field | string | 是 | 数据库表中的列名。 |
| value | Array&lt;[ValueType](#valuetype)&gt; | 是 | 以ValueType数组形式指定的要匹配的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | 返回与指定字段匹配的谓词。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notIn("NAME", ["Lisa", "Rose"])
```

## RdbStore<sup>(deprecated)</sup>

提供管理关系数据库(RDB)方法的接口。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[RdbStoreV9](#rdbstorev99)替代。

在使用以下相关接口前，请使用[executeSql](#executesql)接口初始化数据库表结构和相关数据，具体可见[关系型数据库开发指导](../../database/database-relational-guidelines.md)。

### insert<sup>(deprecated)</sup>

insert(table: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

向目标表中插入一行数据，使用callback异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[insert](#insert9-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| table | string | 是 | 指定的目标表名。 |
| values | [ValuesBucket](#valuesbucket) | 是 | 表示要插入到表中的数据行。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 指定callback回调函数。如果操作成功，返回行ID；否则返回-1。 |

**示例：**

```js
const valueBucket = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
rdbStore.insert("EMPLOYEE", valueBucket, function (status, rowId) {
    if (status) {
        console.log("Insert is failed");
        return;
    }
    console.log("Insert is successful, rowId = " + rowId);
})
```

### insert<sup>(deprecated)</sup>

insert(table: string, values: ValuesBucket):Promise&lt;number&gt;

向目标表中插入一行数据，使用Promise异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[insert](#insert9-2)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| table | string | 是 | 指定的目标表名。 |
| values | [ValuesBucket](#valuesbucket) | 是 | 表示要插入到表中的数据行。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回行ID；否则返回-1。 |

**示例：**

```js
const valueBucket = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let promise = rdbStore.insert("EMPLOYEE", valueBucket)
promise.then((rowId) => {
    console.log("Insert is successful, rowId = " + rowId);
}).catch((status) => {
    console.log("Insert is failed");
})
```

### batchInsert<sup>(deprecated)</sup>

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;):void

向目标表中插入一组数据，使用callback异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[batchInsert](#batchinsert9-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| table | string | 是 | 指定的目标表名。 |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是 | 表示要插入到表中的一组数据。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 指定callback回调函数。如果操作成功，返回插入的数据个数，否则返回-1。 |

**示例：**

```js
const valueBucket1 = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5])
}
const valueBucket2 = {
    "NAME": "Jack",
    "AGE": 19,
    "SALARY": 101.5,
    "CODES": new Uint8Array([6, 7, 8, 9, 10])
}
const valueBucket3 = {
    "NAME": "Tom",
    "AGE": 20,
    "SALARY": 102.5,
    "CODES": new Uint8Array([11, 12, 13, 14, 15])
}

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
rdbStore.batchInsert("EMPLOYEE", valueBuckets, function(status, insertNum) {
    if (status) {
        console.log("batchInsert is failed, status = " + status);
        return;
    }
    console.log("batchInsert is successful, the number of values that were inserted = " + insertNum);
})
```

### batchInsert<sup>(deprecated)</sup>

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;):Promise&lt;number&gt;

向目标表中插入一组数据，使用Promise异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[batchInsert](#batchinsert9-2)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| table | string | 是 | 指定的目标表名。 |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | 是 | 表示要插入到表中的一组数据。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象。如果操作成功，返回插入的数据个数，否则返回-1。 |

**示例：**

```js
const valueBucket1 = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5])
}
const valueBucket2 = {
    "NAME": "Jack",
    "AGE": 19,
    "SALARY": 101.5,
    "CODES": new Uint8Array([6, 7, 8, 9, 10])
}
const valueBucket3 = {
    "NAME": "Tom",
    "AGE": 20,
    "SALARY": 102.5,
    "CODES": new Uint8Array([11, 12, 13, 14, 15])
}

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
let promise = rdbStore.batchInsert("EMPLOYEE", valueBuckets);
promise.then((insertNum) => {
    console.log("batchInsert is successful, the number of values that were inserted = " + insertNum);
}).catch((status) => {
    console.log("batchInsert is failed, status = " + status);
})
```

### update<sup>(deprecated)</sup>

update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

根据RdbPredicates的指定实例对象更新数据库中的数据，使用callback异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[update](#update9-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| values | [ValuesBucket](#valuesbucket) | 是 | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates) | 是 | RdbPredicates的实例对象指定的更新条件。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 指定的callback回调方法。返回受影响的行数。 |

**示例：**

```js
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
rdbStore.update(valueBucket, predicates, function (err, ret) {
    if (err) {
        console.info("Updated failed, err: " + err)
        return
    }
    console.log("Updated row count: " + ret)
})
```

### update<sup>(deprecated)</sup>

update(values: ValuesBucket, predicates: RdbPredicates):Promise&lt;number&gt;

根据RdbPredicates的指定实例对象更新数据库中的数据，使用Promise异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[update](#update9-2)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| values | [ValuesBucket](#valuesbucket) | 是 | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |
| predicates | [RdbPredicates](#rdbpredicates) | 是 | RdbPredicates的实例对象指定的更新条件。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回受影响的行数。 |

**示例：**

```js
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
let promise = rdbStore.update(valueBucket, predicates)
promise.then(async (ret) => {
    console.log("Updated row count: " + ret)
}).catch((err) => {
    console.info("Updated failed, err: " + err)
})
```

### delete<sup>(deprecated)</sup>

delete(predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

根据RdbPredicates的指定实例对象从数据库中删除数据，使用callback异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[delete](#delete9-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是 | RdbPredicates的实例对象指定的删除条件。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 指定callback回调函数。返回受影响的行数。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
rdbStore.delete(predicates, function (err, rows) {
    if (err) {
        console.info("Delete failed, err: " + err)
        return
    }
    console.log("Delete rows: " + rows)
})
```

### delete<sup>(deprecated)</sup>

delete(predicates: RdbPredicates):Promise&lt;number&gt;

根据RdbPredicates的指定实例对象从数据库中删除数据，使用Promise异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[delete](#delete9-2)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是 | RdbPredicates的实例对象指定的删除条件。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise对象。返回受影响的行数。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
let promise = rdbStore.delete(predicates)
promise.then((rows) => {
    console.log("Delete rows: " + rows)
}).catch((err) => {
    console.info("Delete failed, err: " + err)
})
```

### query<sup>(deprecated)</sup>

query(predicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

根据指定条件查询数据库中的数据，使用callback异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[query](#query9-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是 | RdbPredicates的实例对象指定的查询条件。 |
| columns | Array&lt;string&gt; | 是 | 表示要查询的列。如果值为空，则查询应用于所有列。 |
| callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | 是 | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose")
rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSet) {
    if (err) {
        console.info("Query failed, err: " + err)
        return
    }
    console.log("ResultSet column names: " + resultSet.columnNames)
    console.log("ResultSet column count: " + resultSet.columnCount)
})
```

### query<sup>(deprecated)</sup>

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

根据指定条件查询数据库中的数据，使用Promise异步回调。

> **说明：**
>
> 从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[query](#query9-2)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| predicates | [RdbPredicates](#rdbpredicates) | 是 | RdbPredicates的实例对象指定的查询条件。 |
| columns | Array&lt;string&gt; | 否 | 表示要查询的列。如果值为空，则查询应用于所有列。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Promise对象。如果操作成功，则返回ResultSet对象。 |

**示例：**

  ```js
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose")
  let promise = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
  promise.then((resultSet) => {
      console.log("ResultSet column names: " + resultSet.columnNames)
      console.log("ResultSet column count: " + resultSet.columnCount)
  }).catch((err) => {
      console.info("Query failed, err: " + err)
  })
  ```

### querySql<sup>(deprecated)</sup>

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

根据指定SQL语句查询数据库中的数据，使用callback异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[querySql](#querysql9-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| sql | string | 是 | 指定要执行的SQL语句。 |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 是 | SQL语句中参数的值。 |
| callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | 是 | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |

**示例：**

```js
rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], function (err, resultSet) {
    if (err) {
        console.info("Query failed, err: " + err)
        return
    }
    console.log("ResultSet column names: " + resultSet.columnNames)
    console.log("ResultSet column count: " + resultSet.columnCount)
})
```

### querySql<sup>(deprecated)</sup>

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;

根据指定SQL语句查询数据库中的数据，使用Promise异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[querySql](#querysql9-2)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| sql | string | 是 | 指定要执行的SQL语句。 |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 否 | SQL语句中参数的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Promise对象。如果操作成功，则返回ResultSet对象。 |

**示例：**

```js
let promise = rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'])
promise.then((resultSet) => {
    console.log("ResultSet column names: " + resultSet.columnNames)
    console.log("ResultSet column count: " + resultSet.columnCount)
}).catch((err) => {
    console.info("Query failed, err: " + err)
})
```

### executeSql<sup>(deprecated)</sup>

executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void

执行包含指定参数但不返回值的SQL语句，使用callback异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[executeSql](#executesql9-1)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| sql | string | 是 | 指定要执行的SQL语句。 |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 是 | SQL语句中参数的值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 指定callback回调函数。 |

**示例：**

```js
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
rdbStore.executeSql(SQL_CREATE_TABLE, null, function(err) {
    if (err) {
        console.info("ExecuteSql failed, err: " + err)
        return
    }
    console.info('Create table done.')
})
```

### executeSql<sup>(deprecated)</sup>

executeSql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;void&gt;

执行包含指定参数但不返回值的SQL语句，使用Promise异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[executeSql](#executesql9-2)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| sql | string | 是 | 指定要执行的SQL语句。 |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | 否 | SQL语句中参数的值。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
let promise = rdbStore.executeSql(SQL_CREATE_TABLE)
promise.then(() => {
    console.info('Create table done.')
}).catch((err) => {
    console.info("ExecuteSql failed, err: " + err)
})
```

### beginTransaction<sup>(deprecated)</sup>

beginTransaction():void

在开始执行SQL语句之前，开始事务。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[beginTransaction](#begintransaction9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, async function (err, rdbStore) {
    rdbStore.beginTransaction()
	const valueBucket = {
		"name": "lisi",
		"age": 18,
		"salary": 100.5,
		"blobType": new Uint8Array([1, 2, 3]),
	}
	await rdbStore.insert("test", valueBucket)
	rdbStore.commit()
})
```

### commit<sup>(deprecated)</sup>

commit():void

提交已执行的SQL语句。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[commit](#commit9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, async function (err, rdbStore) {
    rdbStore.beginTransaction()
	const valueBucket = {
		"name": "lisi",
		"age": 18,
		"salary": 100.5,
		"blobType": new Uint8Array([1, 2, 3]),
	}
	await rdbStore.insert("test", valueBucket)
	rdbStore.commit()
})
```

### rollBack<sup>(deprecated)</sup>

rollBack():void

回滚已经执行的SQL语句。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[rollBack](#rollback9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, async function (err, rdbStore) {
    try {
		rdbStore.beginTransaction()
		const valueBucket = {
			"id": 1,
			"name": "lisi",
			"age": 18,
			"salary": 100.5,
			"blobType": new Uint8Array([1, 2, 3]),
		}
		await rdbStore.insert("test", valueBucket)
		rdbStore.commit()
	} catch (e) {
		rdbStore.rollBack()
	}
})
```

### setDistributedTables<sup>(deprecated)</sup>

setDistributedTables(tables: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

设置分布式列表，使用callback异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[setDistributedTables](#setdistributedtables9-1)替代。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| tables | Array&lt;string&gt; | 是 | 要设置的分布式列表表名 |
| callback | AsyncCallback&lt;void&gt; | 是 | 指定callback回调函数。 |

**示例：**

```js
rdbStore.setDistributedTables(["EMPLOYEE"], function (err) {
    if (err) {
        console.info('SetDistributedTables failed, err: ' + err)
        return
    }
    console.info('SetDistributedTables successfully.')
})
```

### setDistributedTables<sup>(deprecated)</sup>

 setDistributedTables(tables: Array&lt;string&gt;): Promise&lt;void&gt;

设置分布式列表，使用Promise异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[setDistributedTables](#setdistributedtables9-2)替代。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| tables | Array&lt;string&gt; | 是 | 要设置的分布式列表表名。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = rdbStore.setDistributedTables(["EMPLOYEE"])
promise.then(() => {
    console.info("SetDistributedTables successfully.")
}).catch((err) => {
    console.info("SetDistributedTables failed, err: " + err)
})
```

### obtainDistributedTableName<sup>(deprecated)</sup>

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void

根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名, 使用callback异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[obtainDistributedTableName](#obtaindistributedtablename9-1)替代。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| device | string | 是 | 远程设备 。|
| table | string | 是 | 本地表名。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 指定的callback回调函数。如果操作成功，返回远程设备的分布式表名。 |

**示例：**

```js
rdbStore.obtainDistributedTableName("12345678abcde", "EMPLOYEE", function (err, tableName) {
    if (err) {
        console.info('ObtainDistributedTableName failed, err: ' + err)
        return
    }
    console.info('ObtainDistributedTableName successfully, tableName=.' + tableName)
})
```

### obtainDistributedTableName<sup>(deprecated)</sup>

 obtainDistributedTableName(device: string, table: string): Promise&lt;string&gt;

根据本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名，使用Promise异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[obtainDistributedTableName](#obtaindistributedtablename9-2)替代。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| device | string | 是 | 远程设备。 |
| table | string | 是 | 本地表名。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise对象。如果操作成功，返回远程设备的分布式表名。 |

**示例：**

```js
let promise = rdbStore.obtainDistributedTableName("12345678abcde", "EMPLOYEE")
promise.then((tableName) => {
    console.info('ObtainDistributedTableName successfully, tableName= ' + tableName)
}).catch((err) => {
    console.info('ObtainDistributedTableName failed, err: ' + err)
})
```

### sync<sup>(deprecated)</sup>

sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void

在设备之间同步数据, 使用callback异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[sync](#sync9-1)替代。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mode | [SyncMode](#syncmode8) | 是 | 指同步模式。该值可以是推、拉。 |
| predicates | [RdbPredicates](#rdbpredicates) | 是 | 约束同步数据和设备。 |
| callback | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | 是 | 指定的callback回调函数，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。|

**示例：**

```js
let predicates = new data_rdb.RdbPredicates('EMPLOYEE')
predicates.inDevices(['12345678abcde'])
rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicates, function (err, result) {
    if (err) {
        console.log('Sync failed, err: ' + err)
        return
    }
    console.log('Sync done.')
    for (let i = 0; i < result.length; i++) {
        console.log('device=' + result[i][0] + ' status=' + result[i][1])
    }
})
```

### sync<sup>(deprecated)</sup>

 sync(mode: SyncMode, predicates: RdbPredicates): Promise&lt;Array&lt;[string, number]&gt;&gt;

在设备之间同步数据，使用Promise异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[sync](#sync9-2)替代。

**需要权限：** ohos.permission.DISTRIBUTED_DATASYNC

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mode | [SyncMode](#syncmode8) | 是 | 指同步模式。该值可以是推、拉。 |
| predicates | [RdbPredicates](#rdbpredicates) | 是 | 约束同步数据和设备。 |

**返回值**：

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise对象，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |

**示例：**

```js
let predicates = new data_rdb.RdbPredicates('EMPLOYEE')
predicates.inDevices(['12345678abcde'])
let promise = rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicates)
promise.then((result) =>{
    console.log('Sync done.')
    for (let i = 0; i < result.length; i++) {
        console.log('device=' + result[i][0] + ' status=' + result[i][1])
    }
}).catch((err) => {
    console.log('Sync failed')
})
```

### on('dataChange')<sup>(deprecated)</sup>

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

注册数据库的观察者。当分布式数据库中的数据发生更改时，将调用回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[on](#ondatachange9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 取值为'dataChange'，表示数据更改。 |
| type | [SubscribeType](#subscribetype8) | 是 | 指在{@code SubscribeType}中定义的订阅类型。 |
| observer | Callback&lt;Array&lt;string&gt;&gt; | 是 | 指分布式数据库中数据更改事件的观察者。 |

**示例：**

```js
function storeObserver(devices) {
    for (let i = 0; i < devices.length; i++) {
        console.log('device=' + devices[i] + ' data changed')
    }
}
try {
    rdbStore.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
} catch (err) {
    console.log('Register observer failed')
}
```

### off('dataChange')<sup>(deprecated)</sup>

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

从数据库中删除指定类型的指定观察者, 使用callback异步回调。

> **说明：**
>
> 从 API Version 8开始支持，从 API Version 9 开始废弃，建议使用[off](#offdatachange9)替代。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 取值为'dataChange'，表示数据更改。 |
| type | [SubscribeType](#subscribetype8)    | 是 | 指在{@code SubscribeType}中定义的订阅类型。 |
| observer | Callback&lt;Array&lt;string&gt;&gt; | 是 | 指已注册的数据更改观察者。|

**示例：**

```js
function storeObserver(devices) {
    for (let i = 0; i < devices.length; i++) {
        console.log('device=' + devices[i] + ' data changed')
    }
}
try {
    rdbStore.off('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
} catch (err) {
    console.log('Unregister observer failed')
}
```

## StoreConfig<sup>(deprecated)</sup>

管理关系数据库配置。

**说明：**

从 API Version 7开始支持，从 API Version 9 开始废弃，建议使用[StoreConfigV9](#storeconfigv99)替代。

**系统能力：**SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 数据库文件名。 |

