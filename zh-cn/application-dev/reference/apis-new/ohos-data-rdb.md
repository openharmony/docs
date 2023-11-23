# @ohos.data.rdb    
关系型数据库（Relational Database，RDB）是一种基于关系模型来管理数据的数据库。关系型数据库基于SQLite组件提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复杂的场景需要。不支持Worker线程。  
该模块提供以下关系型数据库相关的常用功能：  
- [RdbPredicates](#rdbpredicates)： 数据库中用来代表数据实体的性质、特征或者数据实体之间关系的词项，主要用来定义数据库的操作条件。- [RdbStore](#rdbstore)：提供管理关系数据库(RDB)方法的接口。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import rdb from '@ohos.data.rdb'    
```  
    
## getRdbStore<sup>(deprecated)</sup>    
获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，使用callback异步回调。  
 **调用形式：**     
- getRdbStore(context: Context, config: StoreConfig, version: number, callback: AsyncCallback\<RdbStore>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.getRdbStore。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context<sup>(deprecated)</sup> | Context | true | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-app-context.md)。 |  
| config<sup>(deprecated)</sup> | StoreConfig | true | 与此RDB存储相关的数据库配置。 |  
| version<sup>(deprecated)</sup> | number | true | 数据库版本。<br>目前暂不支持通过version自动识别数据库升级降级操作，只能由开发者自行维护。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<RdbStore> | true | 指定callback回调函数，返回RdbStore对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
import relationalStore from '@ohos.data.relationalStore';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
data_rdb.getRdbStore(this.context, "RdbTest.db", 1, (err, rdbStore) => {  
  if (err) {  
    console.info("Get RdbStore failed, err: " + err)  
    return  
  }  
  console.log("Get RdbStore successfully.")  
})  
    
```    
  
    
## getRdbStore<sup>(deprecated)</sup>    
获得一个相关的RdbStore，操作关系型数据库，用户可以根据自己的需求配置RdbStore的参数，然后通过RdbStore调用相关接口可以执行相关的数据操作，使用Promise异步回调。  
 **调用形式：**     
- getRdbStore(context: Context, config: StoreConfig, version: number): Promise\<RdbStore>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.getRdbStore。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context<sup>(deprecated)</sup> | Context | true | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-app-context.md)。 |  
| config<sup>(deprecated)</sup> | StoreConfig | true | 与此RDB存储相关的数据库配置。 |  
| version<sup>(deprecated)</sup> | number | true | 数据库版本。<br>目前暂不支持通过version自动识别数据库升级降级操作，只能由开发者自行维护。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<RdbStore> | Promise对象。返回RdbStore对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let promise = data_rdb.getRdbStore(this.context, "RdbTest.db", 1);  
promise.then(async (rdbStore) => {  
  console.log("Get RdbStore successfully.")  
}).catch((err: BusinessError) => {  
  console.log("Get RdbStore failed, err: " + err)  
})    
```    
  
    
## deleteRdbStore<sup>(deprecated)</sup>    
删除数据库，使用callback异步回调。  
 **调用形式：**     
- deleteRdbStore(context: Context, name: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.deleteRdbStore。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context<sup>(deprecated)</sup> | Context | true | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-app-context.md)。 |  
| name<sup>(deprecated)</sup> | string | true | 数据库名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 指定callback回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
data_rdb.deleteRdbStore(this.context, "RdbTest.db", (err) => {  
  if (err) {  
    console.info("Delete RdbStore failed, err: " + err)  
    return  
  }  
  console.log("Delete RdbStore successfully.")  
})    
```    
  
    
## deleteRdbStore<sup>(deprecated)</sup>    
使用指定的数据库文件配置删除数据库，使用Promise异步回调。  
 **调用形式：**     
- deleteRdbStore(context: Context, name: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.deleteRdbStore。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context<sup>(deprecated)</sup> | Context | true | 应用的上下文。 <br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-app-context.md)。 |  
| name<sup>(deprecated)</sup> | string | true | 数据库名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let promise = data_rdb.deleteRdbStore(this.context, "RdbTest.db")  
promise.then(() => {  
  console.log("Delete RdbStore successfully.")  
}).catch((err: BusinessError) => {  
  console.info("Delete RdbStore failed, err: " + err)  
})    
```    
  
    
## SyncMode<sup>(deprecated)</sup>    
指数据库同步模式。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.SyncMode替代。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SYNC_MODE_PUSH<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.SyncMode.SYNC_MODE_PUSH替代。<br>表示数据从本地设备推送到远程设备。 |  
| SYNC_MODE_PULL<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.SyncMode.SYNC_MODE_PULL替代。<br>表示数据从远程设备拉至本地设备。 |  
    
## SubscribeType<sup>(deprecated)</sup>    
描述订阅类型。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.SubscribeType替代。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUBSCRIBE_TYPE_REMOTE<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE替代。<br>订阅远程数据更改。 |  
    
## RdbStore<sup>(deprecated)</sup>    
提供管理关系数据库(RDB)方法的接口。在使用以下相关接口前，请使用[executeSql](#executesql8)接口初始化数据库表结构和相关数据。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.RdbStore替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### insert<sup>(deprecated)</sup>    
向目标表中插入一行数据，使用callback异步回调。  
 **调用形式：**     
- insert(table: string, values: ValuesBucket, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.insert。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table<sup>(deprecated)</sup> | string | true | 指定的目标表名。 |  
| values<sup>(deprecated)</sup> | ValuesBucket | true | 表示要插入到表中的数据行。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 指定callback回调函数。如果操作成功，返回行ID；否则返回-1。 |  
    
 **示例代码：**   
示例：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisi";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
  
rdbStore.insert("EMPLOYEE", valueBucket, (status: number, rowId: number) => {  
  if (status) {  
    console.log("Insert is failed");  
    return;  
  }  
  console.log("Insert is successful, rowId = " + rowId);  
})  
    
```    
  
    
### insert<sup>(deprecated)</sup>    
向目标表中插入一行数据，使用Promise异步回调。  
 **调用形式：**     
- insert(table: string, values: ValuesBucket): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.insert。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table<sup>(deprecated)</sup> | string | true | 指定的目标表名。 |  
| values<sup>(deprecated)</sup> | ValuesBucket | true | 表示要插入到表中的数据行。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象。如果操作成功，返回行ID；否则返回-1。 |  
    
 **示例代码：**   
示例：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisi";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
  
let promise: void = rdbStore.insert("EMPLOYEE", valueBucket)  
promise.then((rowId: BusinessError) => {  
  console.log("Insert is successful, rowId = " + rowId);  
}).catch((status: number) => {  
  console.log("Insert is failed");  
})  
    
```    
  
    
### batchInsert<sup>(deprecated)</sup>    
向目标表中插入一组数据，使用callback异步回调。  
 **调用形式：**     
- batchInsert(table: string, values: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.batchInsert。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table<sup>(deprecated)</sup> | string | true | 指定的目标表名。 |  
| values<sup>(deprecated)</sup> | Array<ValuesBucket> | true | 表示要插入到表中的一组数据。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 指定callback回调函数。如果操作成功，返回插入的数据个数，否则返回-1。 |  
    
 **示例代码：**   
示例：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
let value5 = "Jack";  
let value6 = 19;  
let value7 = 101.5;  
let value8 = new Uint8Array([6, 7, 8, 9, 10]);  
let value9 = "Tom";  
let value10 = 20;  
let value11 = 102.5;  
let value12 = new Uint8Array([11, 12, 13, 14, 15]);  
const valueBucket1: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
const valueBucket2: ValuesBucket = {  
  key1: value5,  
  key2: value6,  
  key3: value7,  
  key4: value8,  
};  
const valueBucket3: ValuesBucket = {  
  key1: value9,  
  key2: value10,  
  key3: value11,  
  key4: value12,  
};  
  
let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);  
rdbStore.batchInsert("EMPLOYEE", valueBuckets, (status: number, insertNum: number) => {  
  if (status) {  
    console.log("batchInsert is failed, status = " + status);  
    return;  
  }  
  console.log("batchInsert is successful, the number of values that were inserted = " + insertNum);  
})  
    
```    
  
    
### batchInsert<sup>(deprecated)</sup>    
向目标表中插入一组数据，使用Promise异步回调。  
 **调用形式：**     
- batchInsert(table: string, values: Array\<ValuesBucket>): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.batchInsert。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table<sup>(deprecated)</sup> | string | true | 指定的目标表名。 |  
| values<sup>(deprecated)</sup> | Array<ValuesBucket> | true | 表示要插入到表中的一组数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象。如果操作成功，返回插入的数据个数，否则返回-1。 |  
    
 **示例代码：**   
示例：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
let value5 = "Jack";  
let value6 = 19;  
let value7 = 101.5;  
let value8 = new Uint8Array([6, 7, 8, 9, 10]);  
let value9 = "Tom";  
let value10 = 20;  
let value11 = 102.5;  
let value12 = new Uint8Array([11, 12, 13, 14, 15]);  
const valueBucket1: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
const valueBucket2: ValuesBucket = {  
  key1: value5,  
  key2: value6,  
  key3: value7,  
  key4: value8,  
};  
const valueBucket3: ValuesBucket = {  
  key1: value9,  
  key2: value10,  
  key3: value11,  
  key4: value12,  
};  
  
let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);  
let promise: void = rdbStore.batchInsert("EMPLOYEE", valueBuckets);  
promise.then((insertNum: number) => {  
  console.log("batchInsert is successful, the number of values that were inserted = " + insertNum);  
}).catch((status: number) => {  
  console.log("batchInsert is failed, status = " + status);  
})  
    
```    
  
    
### update<sup>(deprecated)</sup>    
根据RdbPredicates的指定实例对象更新数据库中的数据，使用callback异步回调。  
 **调用形式：**     
- update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.update。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| values<sup>(deprecated)</sup> | ValuesBucket | true | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |  
| predicates<sup>(deprecated)</sup> | RdbPredicates | true | RdbPredicates的实例对象指定的更新条件。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 指定的callback回调方法。返回受影响的行数。 |  
    
 **示例代码：**   
示例：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Lisa")  
rdbStore.update(valueBucket, predicates, (err: BusinessError, rows: number) => {  
  if (err) {  
    console.info("Updated failed, err: " + err)  
    return  
  }  
  console.log("Updated row count: " + rows)  
})  
    
```    
  
    
### update<sup>(deprecated)</sup>    
根据RdbPredicates的指定实例对象更新数据库中的数据，使用Promise异步回调。  
 **调用形式：**     
- update(values: ValuesBucket, predicates: RdbPredicates): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.update。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| values<sup>(deprecated)</sup> | ValuesBucket | true | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。<br/> |  
| predicates<sup>(deprecated)</sup> | RdbPredicates | true | RdbPredicates的实例对象指定的更新条件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 指定的Promise回调方法。返回受影响的行数。 |  
    
 **示例代码：**   
示例：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Lisa")  
let promise: void = rdbStore.update(valueBucket, predicates)  
promise.then(async (rows: number) => {  
  console.log("Updated row count: " + rows)  
}).catch((err: BusinessError) => {  
  console.info("Updated failed, err: " + err)  
})  
    
```    
  
    
### delete<sup>(deprecated)</sup>    
根据RdbPredicates的指定实例对象从数据库中删除数据，使用callback异步回调。  
 **调用形式：**     
- delete(predicates: RdbPredicates, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.delete。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates<sup>(deprecated)</sup> | RdbPredicates | true | RdbPredicates的实例对象指定的删除条件。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 指定callback回调函数。返回受影响的行数。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Lisa")  
rdbStore.delete(predicates, (err: BusinessError, rows: number) => {  
  if (err) {  
    console.info("Delete failed, err: " + err)  
    return  
  }  
  console.log("Delete rows: " + rows)  
})    
```    
  
    
### delete<sup>(deprecated)</sup>    
根据RdbPredicates的指定实例对象从数据库中删除数据，使用Promise异步回调。  
 **调用形式：**     
- delete(predicates: RdbPredicates): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.delete。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates<sup>(deprecated)</sup> | RdbPredicates | true | RdbPredicates的实例对象指定的删除条件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象。返回受影响的行数。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Lisa")  
let promise: void = rdbStore.delete(predicates)  
promise.then((rows: number) => {  
  console.log("Delete rows: " + rows)  
}).catch((err: BusinessError) => {  
  console.info("Delete failed, err: " + err)  
})    
```    
  
    
### query<sup>(deprecated)</sup>    
根据指定条件查询数据库中的数据，使用callback异步回调。  
 **调用形式：**     
- query(predicates: RdbPredicates, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.query。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates<sup>(deprecated)</sup> | RdbPredicates | true | RdbPredicates的实例对象指定的查询条件。 |  
| columns<sup>(deprecated)</sup> | Array<string> | true | 表示要查询的列。如果值为空，则查询应用于所有列。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ResultSet> | true | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Rose")  
rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], (err: BusinessError, resultSet: void) => {  
  if (err) {  
    console.info("Query failed, err: " + err)  
    return  
  }  
  console.log("ResultSet column names: " + resultSet.columnNames)  
  console.log("ResultSet column count: " + resultSet.columnCount)  
})    
```    
  
    
### query<sup>(deprecated)</sup>    
根据指定条件查询数据库中的数据，使用Promise异步回调。  
 **调用形式：**     
- query(predicates: RdbPredicates, columns?: Array\<string>): Promise\<ResultSet>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.query。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates<sup>(deprecated)</sup> | RdbPredicates | true | RdbPredicates的实例对象指定的查询条件。 |  
| columns<sup>(deprecated)</sup> | Array<string> | false | 表示要查询的列。如果值为空，则查询应用于所有列。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<ResultSet> | Promise对象。如果操作成功，则返回ResultSet对象。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Rose")  
let promise: void = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])  
promise.then((resultSet: void) => {  
  console.log("ResultSet column names: " + resultSet.columnNames)  
  console.log("ResultSet column count: " + resultSet.columnCount)  
}).catch((err: BusinessError) => {  
  console.info("Query failed, err: " + err)  
})    
```    
  
    
### querySql<sup>(deprecated)</sup>    
根据指定SQL语句查询数据库中的数据，使用callback异步回调。  
 **调用形式：**     
- querySql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<ResultSet>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.querySql。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sql<sup>(deprecated)</sup> | string | true | 指定要执行的SQL语句。 |  
| bindArgs<sup>(deprecated)</sup> | Array<ValueType> | true | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数需为空数组。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<ResultSet> | true | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |  
    
 **示例代码：**   
示例：  
```ts    
rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], (err: BusinessError, resultSet: void) => {  
  if (err) {  
    console.info("Query failed, err: " + err)  
    return  
  }  
  console.log("ResultSet column names: " + resultSet.columnNames)  
  console.log("ResultSet column count: " + resultSet.columnCount)  
})    
```    
  
    
### querySql<sup>(deprecated)</sup>    
根据指定SQL语句查询数据库中的数据，使用Promise异步回调。  
 **调用形式：**     
- querySql(sql: string, bindArgs?: Array\<ValueType>): Promise\<ResultSet>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.querySql。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sql<sup>(deprecated)</sup> | string | true | 指定要执行的SQL语句。 |  
| bindArgs<sup>(deprecated)</sup> | Array<ValueType> | false | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<ResultSet> | Promise对象。如果操作成功，则返回ResultSet对象。 |  
    
 **示例代码：**   
示例：  
```ts    
let promise: void = rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'")  
promise.then((resultSet: void) => {  
  console.log("ResultSet column names: " + resultSet.columnNames)  
  console.log("ResultSet column count: " + resultSet.columnCount)  
}).catch((err: BusinessError) => {  
  console.info("Query failed, err: " + err)  
})    
```    
  
    
### executeSql<sup>(deprecated)</sup>    
执行包含指定参数但不返回值的SQL语句，使用callback异步回调。  
 **调用形式：**     
- executeSql(sql: string, bindArgs: Array\<ValueType>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.executeSql。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sql<sup>(deprecated)</sup> | string | true | 指定要执行的SQL语句。 |  
| bindArgs<sup>(deprecated)</sup> | Array<ValueType> | true | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数需为空数组。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 指定callback回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = ?"  
rdbStore.executeSql(SQL_DELETE_TABLE, ['zhangsan'], (err: BusinessError) => {  
  if (err) {  
    console.info("ExecuteSql failed, err: " + err)  
    return  
  }  
  console.info('Delete table done.')  
})    
```    
  
    
### executeSql<sup>(deprecated)</sup>    
执行包含指定参数但不返回值的SQL语句，使用Promise异步回调。  
 **调用形式：**     
- executeSql(sql: string, bindArgs?: Array\<ValueType>): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.executeSql。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sql<sup>(deprecated)</sup> | string | true | 指定要执行的SQL语句。 |  
| bindArgs<sup>(deprecated)</sup> | Array<ValueType> | false | SQL语句中参数的值。该值与sql参数语句中的占位符相对应。当sql参数语句完整时，该参数不填。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例：  
```ts    
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'"  
let promise: void = rdbStore.executeSql(SQL_DELETE_TABLE)  
promise.then(() => {  
  console.info('Delete table done.')  
}).catch((err: BusinessError) => {  
  console.info("ExecuteSql failed, err: " + err)  
})    
```    
  
    
### beginTransaction<sup>(deprecated)</sup>    
在开始执行SQL语句之前，开始事务。  
 **调用形式：**     
- beginTransaction(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.beginTransaction。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **示例代码：**   
示例：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "blobType";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3]);  
  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
  
data_rdb.getRdbStore(this.context, "RdbTest.db", 1, async (err: BusinessError, rdbStore) => {  
  rdbStore.beginTransaction()  
  await rdbStore.insert("test", valueBucket)  
  rdbStore.commit()  
})  
    
```    
  
    
### commit<sup>(deprecated)</sup>    
提交已执行的SQL语句。  
 **调用形式：**     
- commit(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.commit。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **示例代码：**   
示例：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "blobType";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3]);  
  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
  
data_rdb.getRdbStore(this.context, "RdbTest.db", 1, async (err: BusinessError, rdbStore) => {  
  rdbStore.beginTransaction()  
  await rdbStore.insert("test", valueBucket)  
  rdbStore.commit()  
})  
    
```    
  
    
### rollBack<sup>(deprecated)</sup>    
回滚已经执行的SQL语句。  
 **调用形式：**     
- rollBack(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.rollBack。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **示例代码：**   
示例：  
```ts    
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
import featureAbility from '@ohos.ability.featureAbility';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "blobType";  
let value1 = "Lisa";  
let value2 = 18;  
let value3 = 100.5;  
let value4 = new Uint8Array([1, 2, 3]);  
  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
  
const STORE_CONFIG = { name: "RdbTest.db"}  
data_rdb.getRdbStore(this,context, "RdbTest.db", 1, async (err: BusinessError, rdbStore) => {  
    try {  
		rdbStore.beginTransaction()  
		await rdbStore.insert("test", valueBucket)  
		rdbStore.commit()  
	} catch (e) {  
		rdbStore.rollBack()  
	}  
})  
    
```    
  
    
### setDistributedTables<sup>(deprecated)</sup>    
设置分布式列表，使用callback异步回调。  
 **调用形式：**     
- setDistributedTables(tables: Array\<string>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.setDistributedTables。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tables<sup>(deprecated)</sup> | Array<string> | true | 要设置的分布式列表表名 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 指定callback回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
rdbStore.setDistributedTables(["EMPLOYEE"], (err: BusinessError) => {  
  if (err) {  
    console.info('SetDistributedTables failed, err: ' + err)  
    return  
  }  
  console.info('SetDistributedTables successfully.')  
})    
```    
  
    
### setDistributedTables<sup>(deprecated)</sup>    
设置分布式列表，使用Promise异步回调。  
 **调用形式：**     
- setDistributedTables(tables: Array\<string>): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.setDistributedTables。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tables<sup>(deprecated)</sup> | Array<string> | true | 要设置的分布式列表表名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例：  
```ts    
let promise: void = rdbStore.setDistributedTables(["EMPLOYEE"])  
promise.then(() => {  
  console.info("SetDistributedTables successfully.")  
}).catch((err: BusinessError) => {  
  console.info("SetDistributedTables failed, err: " + err)  
})    
```    
  
    
### obtainDistributedTableName<sup>(deprecated)</sup>    
根据远程设备的本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名, 使用callback异步回调。  
 **调用形式：**     
- obtainDistributedTableName(device: string, table: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.obtainDistributedTableName。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远程设备ID 。 |  
| table<sup>(deprecated)</sup> | string | true | 远程设备的本地表名 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 指定的callback回调函数。如果操作成功，返回远程设备的分布式表名。 |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let dmInstance: Array<string>;  
  
deviceManager.createDeviceManager("com.example.appdatamgrverify", (err: BusinessError, manager: void) => {  
  if (err) {  
    console.log("create device manager failed, err=" + err);  
    return;  
  }  
  dmInstance = manager;  
  let devices: Array<string> = dmInstance.getTrustedDeviceListSync();  
  let deviceId: Array<string> = devices[0].deviceId;  
})  
  
rdbStore.obtainDistributedTableName(deviceId, "EMPLOYEE", (err: BusinessError, tableName: String) {  
  if (err) {  
    console.info('ObtainDistributedTableName failed, err: ' + err)  
    return  
  }  
  console.info('ObtainDistributedTableName successfully, tableName=.' + tableName)  
})    
```    
  
    
### obtainDistributedTableName<sup>(deprecated)</sup>    
根据远程设备的本地表名获取指定远程设备的分布式表名。在查询远程设备数据库时，需要使用分布式表名，使用Promise异步回调。  
 **调用形式：**     
- obtainDistributedTableName(device: string, table: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.obtainDistributedTableName。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远程设备ID。 |  
| table<sup>(deprecated)</sup> | string | true | 远程设备的本地表名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象。如果操作成功，返回远程设备的分布式表名。 |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let dmInstance: Array<string>;  
  
deviceManager.createDeviceManager("com.example.appdatamgrverify", (err: BusinessError, manager: void) => {  
  if (err) {  
    console.log("create device manager failed, err=" + err);  
    return;  
  }  
  dmInstance = manager;  
  let devices: Array<string> = dmInstance.getTrustedDeviceListSync();  
  let deviceId: Array<string> = devices[0].deviceId;  
})  
  
let promise: void = rdbStore.obtainDistributedTableName(deviceId, "EMPLOYEE")  
promise.then((tableName: String) => {  
  console.info('ObtainDistributedTableName successfully, tableName= ' + tableName)  
}).catch((err: BusinessError) => {  
  console.info('ObtainDistributedTableName failed, err: ' + err)  
})    
```    
  
    
### sync<sup>(deprecated)</sup>    
在设备之间同步数据, 使用callback异步回调。  
 **调用形式：**     
- sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback\<Array\<[string, number]>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.sync。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | SyncMode | true | 指同步模式。该值可以是推、拉。 |  
| predicates<sup>(deprecated)</sup> | RdbPredicates | true | 约束同步数据和设备。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<[string, number]>> | true | 指定的callback回调函数，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let dmInstance: Array<string>;  
  
deviceManager.createDeviceManager("com.example.appdatamgrverify", (err: BusinessError, manager: void) => {  
  if (err) {  
    console.log("create device manager failed, err=" + err);  
    return;  
  }  
  dmInstance = manager;  
  let devices: Array<string> = dmInstance.getTrustedDeviceListSync();  
  for (let i = 0; i < devices.length; i++) {  
    let deviceIds: Array<string> = devices[i].deviceId;  
  }  
})  
  
let predicates = new data_rdb.RdbPredicates('EMPLOYEE')  
predicates.inDevices(deviceIds)  
rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicates, (err: BusinessError, result: void) {  
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
在设备之间同步数据，使用Promise异步回调。  
 **调用形式：**     
- sync(mode: SyncMode, predicates: RdbPredicates): Promise\<Array\<[string, number]>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.sync。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | SyncMode | true | 指同步模式。该值可以是推、拉。 |  
| predicates<sup>(deprecated)</sup> | RdbPredicates | true | 约束同步数据和设备。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<[string, number]>> | Promise对象，用于向调用者发送同步结果。string：设备ID；number：每个设备同步状态，0表示成功，其他值表示失败。 |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let dmInstance: Array<string>;  
  
deviceManager.createDeviceManager("com.example.appdatamgrverify", (err: BusinessError, manager: void) => {  
  if (err) {  
    console.log("create device manager failed, err=" + err);  
    return;  
  }  
  dmInstance = manager;  
  let devices: Array<string> = dmInstance.getTrustedDeviceListSync();  
  for (let i = 0; i < devices.length; i++) {  
    let deviceIds: Array<string> = devices[i].deviceId;  
  }  
})  
  
let predicates = new data_rdb.RdbPredicates('EMPLOYEE')  
predicates.inDevices(deviceIds)  
let promise: void = rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicates)  
promise.then((result: void) =>{  
  console.log('Sync done.')  
  for (let i = 0; i < result.length; i++) {  
    console.log('device=' + result[i][0] + ' status=' + result[i][1])  
  }  
}).catch((err: BusinessError) => {  
  console.log('Sync failed')  
})    
```    
  
    
### on('dataChange')<sup>(deprecated)</sup>    
注册数据库的观察者。当分布式数据库中的数据发生更改时，将调用回调。  
 **调用形式：**     
- on(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.on。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取值为'dataChange'，表示数据更改。 |  
| type<sup>(deprecated)</sup> | SubscribeType | true | 订阅类型。 |  
| observer<sup>(deprecated)</sup> | Callback<Array<string>> | true | 指分布式数据库中数据更改事件的观察者。Arraylt;string>为数据库中的数据发生改变的对端设备ID。 |  
    
 **示例代码：**   
示例：  
```ts    
let devices: Array<string>;  
  
try {  
  rdbStore.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver: Array<string>) => {  
    for (let i = 0; i < devices.length; i++) {  
      console.log('device=' + devices[i] + ' data changed')  
    }  
  })  
} catch (err) {  
  console.log('Register observer failed')  
}  
    
```    
  
    
### off('dataChange')<sup>(deprecated)</sup>    
从数据库中删除指定类型的指定观察者, 使用callback异步回调。  
 **调用形式：**     
- off(event: 'dataChange', type: SubscribeType, observer: Callback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbStore.off。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | string | true | 取值为'dataChange'，表示数据更改。 |  
| type<sup>(deprecated)</sup> | SubscribeType | true | 订阅类型。 |  
| observer<sup>(deprecated)</sup> | Callback<Array<string>> | true | 指已注册的数据更改观察者。Arraylt;string>为数据库中的数据发生改变的对端设备ID。 |  
    
 **示例代码：**   
示例：  
```ts    
let devices: Array<string>;  
  
try {  
  rdbStore.off('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver: Array<string>) => {  
    for (let i = 0; i < devices.length; i++) {  
      console.log('device=' + devices[i] + ' data changed')  
    }  
  })  
} catch (err) {  
  console.log('Unregister observer failed')  
}  
    
```    
  
    
## ValueType<sup>(deprecated)</sup>    
用于表示允许的数据字段类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ValueType替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
    
| 取值范围 | 说明 |  
| --------| --------|  
| number | 表示值类型为数字。 |  
| string | 表示值类型为字符。 |  
| boolean | 表示值类型为布尔值。 |  
    
## ValuesBucket<sup>(deprecated)</sup>    
用于存储键值对的类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.ValuesBucket替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
## StoreConfig<sup>(deprecated)</sup>    
管理关系数据库配置。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.StoreConfig替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 数据库文件名。 |  
    
## RdbPredicates<sup>(deprecated)</sup>    
表示关系型数据库（RDB）的谓词。该类确定RDB中条件表达式的值是true还是false。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.data.relationalStore.RdbPredicates替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### inDevices<sup>(deprecated)</sup>    
同步分布式数据库时连接到组网内指定的远程设备。  
 **调用形式：**     
- inDevices(devices: Array\<string>): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.inDevices。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| devices<sup>(deprecated)</sup> | Array<string> | true | 指定的组网内的远程设备ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  
let dmInstance: deviceManager.DeviceManager;  
let deviceIds: Array<string> = [];  
let devices: Array<string> = [];  
  
deviceManager.createDeviceManager("com.example.appdatamgrverify", (err: BusinessError, manager: void) => {  
  if (err) {  
    console.log("create device manager failed, err=" + err);  
    return;  
  }  
  dmInstance = manager;  
  devices = dmInstance.getTrustedDeviceListSync();  
  for (let i = 0; i < devices.length; i++) {  
    deviceIds[i] = devices[i].deviceId;  
  }  
})  
  
let predicates = new data_rdb.RdbPredicates("EMPLOYEE");  
predicates.inDevices(deviceIds);  
                                    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE");  
predicates.inDevices(deviceIds);    
```    
  
    
### inAllDevices<sup>(deprecated)</sup>    
同步分布式数据库时连接到组网内所有的远程设备。  
 **调用形式：**     
- inAllDevices(): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.inAllDevices。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.inAllDevices()    
```    
  
    
### equalTo<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为ValueType且值等于指定值的字段。  
 **调用形式：**     
- equalTo(field: string, value: ValueType): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.equalTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "lisi")    
```    
  
    
### notEqualTo<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为ValueType且值不等于指定值的字段。  
 **调用形式：**     
- notEqualTo(field: string, value: ValueType): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.notEqualTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.notEqualTo("NAME", "lisi")    
```    
  
    
### beginWrap<sup>(deprecated)</sup>    
向谓词添加左括号。  
 **调用形式：**     
- beginWrap(): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.beginWrap。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回带有左括号的Rdb谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "lisi")  
    .beginWrap()  
    .equalTo("AGE", 18)  
    .or()  
    .equalTo("SALARY", 200.5)  
    .endWrap()    
```    
  
    
### endWrap<sup>(deprecated)</sup>    
向谓词添加右括号。  
 **调用形式：**     
- endWrap(): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.endWrap。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回带有右括号的Rdb谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "lisi")  
    .beginWrap()  
    .equalTo("AGE", 18)  
    .or()  
    .equalTo("SALARY", 200.5)  
    .endWrap()    
```    
  
    
### or<sup>(deprecated)</sup>    
将或条件添加到谓词中。  
 **调用形式：**     
- or(): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.or。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回带有或条件的Rdb谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Lisa")  
    .or()  
    .equalTo("NAME", "Rose")    
```    
  
    
### and<sup>(deprecated)</sup>    
向谓词添加和条件。  
 **调用形式：**     
- and(): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.and。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回带有和条件的Rdb谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Lisa")  
    .and()  
    .equalTo("SALARY", 200.5)    
```    
  
    
### contains<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为string且value包含指定值的字段。  
 **调用形式：**     
- contains(field: string, value: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.contains。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | string | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.contains("NAME", "os")    
```    
  
    
### beginsWith<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为string且值以指定字符串开头的字段。  
 **调用形式：**     
- beginsWith(field: string, value: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.beginsWith。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | string | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.beginsWith("NAME", "os")    
```    
  
    
### endsWith<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为string且值以指定字符串结尾的字段。  
 **调用形式：**     
- endsWith(field: string, value: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.endsWith。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | string | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.endsWith("NAME", "se")    
```    
  
    
### isNull<sup>(deprecated)</sup>    
配置谓词以匹配值为null的字段。  
 **调用形式：**     
- isNull(field: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.isNull。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.isNull("NAME")    
```    
  
    
### isNotNull<sup>(deprecated)</sup>    
配置谓词以匹配值不为null的指定字段。  
 **调用形式：**     
- isNotNull(field: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.isNotNull。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.isNotNull("NAME")    
```    
  
    
### like<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为string且值类似于指定字符串的字段。  
 **调用形式：**     
- like(field: string, value: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.like。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | string | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.like("NAME", "%os%")    
```    
  
    
### glob<sup>(deprecated)</sup>    
配置RdbPredicates匹配数据字段为string的指定字段。  
 **调用形式：**     
- glob(field: string, value: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.glob。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | string | true | 指示要与谓词匹配的值。<br>支持通配符，*表示0个、1个或多个数字或字符，?表示1个数字或字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.glob("NAME", "?h*g")    
```    
  
    
### between<sup>(deprecated)</sup>    
将谓词配置为匹配数据字段为ValueType且value在给定范围内的指定字段。  
 **调用形式：**     
- between(field: string, low: ValueType, high: ValueType): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.between。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| low<sup>(deprecated)</sup> | ValueType | true | 指示与谓词匹配的最小值。 |  
| high<sup>(deprecated)</sup> | ValueType | true | 指示要与谓词匹配的最大值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.between("AGE", 10, 50)    
```    
  
    
### notBetween<sup>(deprecated)</sup>    
配置RdbPredicates以匹配数据字段为ValueType且value超出给定范围的指定字段。  
 **调用形式：**     
- notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.notBetween。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| low<sup>(deprecated)</sup> | ValueType | true | 指示与谓词匹配的最小值。 |  
| high<sup>(deprecated)</sup> | ValueType | true | 指示要与谓词匹配的最大值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.notBetween("AGE", 10, 50)    
```    
  
    
### greaterThan<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为ValueType且值大于指定值的字段。  
 **调用形式：**     
- greaterThan(field: string, value: ValueType): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.greaterThan。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.greaterThan("AGE", 18)    
```    
  
    
### lessThan<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为valueType且value小于指定值的字段。  
 **调用形式：**     
- lessThan(field: string, value: ValueType): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.lessThan。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.lessThan("AGE", 20)    
```    
  
    
### greaterThanOrEqualTo<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为ValueType且value大于或等于指定值的字段。  
 **调用形式：**     
- greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.greaterThanOrEqualTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.greaterThanOrEqualTo("AGE", 18)    
```    
  
    
### lessThanOrEqualTo<sup>(deprecated)</sup>    
配置谓词以匹配数据字段为ValueType且value小于或等于指定值的字段。  
 **调用形式：**     
- lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.lessThanOrEqualTo。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | ValueType | true | 指示要与谓词匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.lessThanOrEqualTo("AGE", 20)    
```    
  
    
### orderByAsc<sup>(deprecated)</sup>    
配置谓词以匹配其值按升序排序的列。  
 **调用形式：**     
- orderByAsc(field: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.orderByAsc。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.orderByAsc("NAME")    
```    
  
    
### orderByDesc<sup>(deprecated)</sup>    
配置谓词以匹配其值按降序排序的列。  
 **调用形式：**     
- orderByDesc(field: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.orderByDesc。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.orderByDesc("AGE")    
```    
  
    
### distinct<sup>(deprecated)</sup>    
配置谓词以过滤重复记录并仅保留其中一个。  
 **调用形式：**     
- distinct(): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.distinct。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回可用于过滤重复记录的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Rose").distinct()    
```    
  
    
### limitAs<sup>(deprecated)</sup>    
设置最大数据记录数的谓词。  
 **调用形式：**     
- limitAs(value: number): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.limitAs。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(deprecated)</sup> | number | true | 最大数据记录数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回可用于设置最大数据记录数的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Rose").limitAs(3)    
```    
  
    
### offsetAs<sup>(deprecated)</sup>    
配置RdbPredicates以指定返回结果的起始位置。  
 **调用形式：**     
- offsetAs(rowOffset: number): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.offsetAs。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rowOffset<sup>(deprecated)</sup> | number | true | 返回结果的起始位置，取值为正整数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回具有指定返回结果起始位置的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.equalTo("NAME", "Rose").offsetAs(3)    
```    
  
    
### groupBy<sup>(deprecated)</sup>    
配置RdbPredicates按指定列分组查询结果。  
 **调用形式：**     
- groupBy(fields: Array\<string>): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.groupBy。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fields<sup>(deprecated)</sup> | Array<string> | true | 指定分组依赖的列名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回分组查询列的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.groupBy(["AGE", "NAME"])    
```    
  
    
### indexedBy<sup>(deprecated)</sup>    
配置RdbPredicates以指定索引列。  
 **调用形式：**     
- indexedBy(field: string): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.indexedBy。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 索引列的名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回具有指定索引列的RdbPredicates。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.indexedBy("SALARY_INDEX")    
```    
  
    
### in<sup>(deprecated)</sup>    
配置RdbPredicates以匹配数据字段为ValueType数组且值在给定范围内的指定字段。  
 **调用形式：**     
- in(field: string, value: Array\<ValueType>): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.in。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | Array<ValueType> | true | 以ValueType型数组形式指定的要匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.in("AGE", [18, 20])    
```    
  
    
### notIn<sup>(deprecated)</sup>    
将RdbPredicates配置为匹配数据字段为ValueType且值超出给定范围的指定字段。  
 **调用形式：**     
- notIn(field: string, value: Array\<ValueType>): RdbPredicates  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.data.relationalStore.RdbPredicates.notIn。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| field<sup>(deprecated)</sup> | string | true | 数据库表中的列名。 |  
| value<sup>(deprecated)</sup> | Array<ValueType> | true | 以ValueType数组形式指定的要匹配的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RdbPredicates | 返回与指定字段匹配的谓词。 |  
    
 **示例代码：**   
示例：  
```ts    
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")  
predicates.notIn("NAME", ["Lisa", "Rose"])    
```    
  
