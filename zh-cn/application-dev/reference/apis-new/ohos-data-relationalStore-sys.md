# @ohos.data.relationalStore    
关系型数据库（Relational Database，RDB）是一种基于关系模型来管理数据的数据库。关系型数据库基于SQLite组件提供了一套完整的对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复场景需要。不支持Worker线程。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import relationalStore from '@ohos.data.relationalStore'    
```  
    
## RdbStore    
提供管理关系数据库(RDB)方法的接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
### update    
根据DataSharePredicates的指定实例对象更新数据库中的数据，使用callback异步回调。  
 **调用形式：**     
    
- update(       table: string,       values: ValuesBucket,       predicates: dataSharePredicates.DataSharePredicates,       callback: AsyncCallback\<number>     ): void    
起始版本： 9    
- update(       table: string,       values: ValuesBucket,       predicates: dataSharePredicates.DataSharePredicates,       callback: AsyncCallback\<number>     ): void    
起始版本： 10    
- update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>    
起始版本： 9    
- update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table | string | true | 指定的目标表名。 |  
| values | ValuesBucket | true | values指示数据库中要更新的数据行。键值对与数据库表的列名相关联。 |  
| predicates | dataSharePredicates.DataSharePredicates | true | DataSharePredicates的实例对象指定的更新条件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定的callback回调方法。返回受影响的行数。 |  
| Promise<number> | 指定的Promise回调方法。返回受影响的行数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 202 |  |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates'  
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Rose";  
let value2 = 22;  
let value3 = 200.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Lisa");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket, predicates, (err, rows) => {  
    if (err) {  
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`Updated row count: ${rows}`);  
  })  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { ValuesBucket } from '@ohos.data.ValuesBucket';  
import { BusinessError } from "@ohos.base";  
  
let key1 = "NAME";  
let key2 = "AGE";  
let key3 = "SALARY";  
let key4 = "CODES";  
let value1 = "Rose";  
let value2 = 22;  
let value3 = 200.5;  
let value4 = new Uint8Array([1, 2, 3, 4, 5]);  
const valueBucket: ValuesBucket = {  
  key1: value1,  
  key2: value2,  
  key3: value3,  
  key4: value4,  
};  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Lisa");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket, predicates).then(async (rows: Number) => {  
    console.info(`Updated row count: ${rows}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### delete    
根据DataSharePredicates的指定实例对象从数据库中删除数据，使用callback异步回调。  
 **调用形式：**     
    
- delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void    
起始版本： 9    
- delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void    
起始版本： 10    
- delete(table: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>    
起始版本： 9    
- delete(table: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<number>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table | string | true | 指定的目标表名。 |  
| predicates | dataSharePredicates.DataSharePredicates | true | DataSharePredicates的实例对象指定的删除条件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。返回受影响的行数。 |  
| Promise<number> | Promise对象。返回受影响的行数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 202 |  |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Lisa");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).delete("EMPLOYEE", predicates, (err, rows) => {  
    if (err) {  
      console.error(`Delete failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`Delete rows: ${rows}`);  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from "@ohos.base";  
  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Lisa");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).delete("EMPLOYEE", predicates).then((rows: Number) => {  
    console.info(`Delete rows: ${rows}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
### query<sup>(10+)</sup>    
根据指定条件查询数据库中的数据，使用callback异步回调。  
 **调用形式：**     
    
- query(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<ResultSet>): void    
起始版本： 10    
- query(       table: string,       predicates: dataSharePredicates.DataSharePredicates,       columns: Array\<string>,       callback: AsyncCallback\<ResultSet>     ): void    
起始版本： 9    
- query(       table: string,       predicates: dataSharePredicates.DataSharePredicates,       columns?: Array\<string>     ): Promise\<ResultSet>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.RelationalStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| table | string | true | 指定的目标表名。 |  
| predicates | dataSharePredicates.DataSharePredicates | true | DataSharePredicates的实例对象指定的查询条件。 |  
| columns<sup>(9+)</sup> | Array<string> | true | 表示要查询的列。如果值为空，则查询应用于所有列。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定callback回调函数。如果操作成功，则返回ResultSet对象。 |  
| Promise<ResultSet> | Promise对象。如果操作成功，则返回ResultSet对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14800000 | Inner error. |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Rose");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], (err, resultSet) => {  
    if (err) {  
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);  
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。  
    while (resultSet.goToNextRow()) {  
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));  
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);  
    }  
    // 释放数据集的内存  
    resultSet.close();  
  })  
}    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from "@ohos.base";  
  
let predicates = new dataSharePredicates.DataSharePredicates();  
predicates.equalTo("NAME", "Rose");  
if(store != undefined) {  
  (store as relationalStore.RdbStore).query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {  
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);  
    // resultSet是一个数据集合的游标，默认指向第-1个记录，有效的数据从0开始。  
    while (resultSet.goToNextRow()) {  
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));  
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));  
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));  
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));  
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);  
    }  
    // 释放数据集的内存  
    resultSet.close();  
  }).catch((err: BusinessError) => {  
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);  
  })  
}  
    
```    
  
    
 **示例代码：**   
```ts    
// 设置数据库版本  
if(store != undefined) {  
  (store as relationalStore.RdbStore).version = 3;  
  // 获取数据库版本  
  console.info(`RdbStore version is ${store.version}`);  
}    
```    
  
