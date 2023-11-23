# @ohos.application.DataShareExtensionAbility    
基于ExtensionAbility框架，提供支持数据共享业务的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## DataShareExtensionAbility  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context<sup>(10+)</sup> | ExtensionContext | false | true |  |  
    
### onCreate    
表示数据共享扩展能力上下文。  
 **调用形式：**     
    
- onCreate?(want: Want, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | Want类型信息，包括Ability名称、Bundle名称等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。无返回值。 |  
    
 **示例代码：**   
```ts    
import relationalStore from '@ohos.data.relationalStore'  
import Want from '@ohos.app.ability.Want'  
  
let DB_NAME = 'DB00.db';  
let TBL_NAME = 'TBL00';  
let DDL_TBL_CREATE = 'CREATE TABLE IF NOT EXISTS '  
  + TBL_NAME  
  + ' (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)';  
let rdbStore: relationalStore.RdbStore;  
  
export default class DataShareExtAbility extends DataShareExtensionAbility {  
  onCreate(want: Want, callback: Function) {  
    relationalStore.getRdbStore(this.context, {  
      name: DB_NAME,  
      securityLevel: relationalStore.SecurityLevel.S1  
    }, (err, data) => {  
      console.info(`getRdbStore done, data : ${data}`);  
      rdbStore = data;  
      rdbStore.executeSql(DDL_TBL_CREATE, [], (err) => {  
        console.error(`executeSql done, error message : ${err}`);  
      });  
      if (callback) {  
        callback();  
      }  
    });  
  }  
};  
    
```    
  
    
### insert    
在数据库插入时回调此接口，该方法可以选择性重写。  
 **调用形式：**     
    
- insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指示要插入的数据的路径。 |  
| valueBucket | ValuesBucket | true | 指示要插入的数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回插入数据记录的索引。 |  
    
 **示例代码：**   
```ts    
import relationalStore from '@ohos.data.relationalStore'  
import { ValuesBucket } from '@ohos.data.ValuesBucket'  
  
let TBL_NAME = 'TBL00';  
let rdbStore: relationalStore.RdbStore;  
  
export default class DataShareExtAbility extends DataShareExtensionAbility {  
  insert(uri: string, valueBucket: ValuesBucket, callback: Function) {  
    if (valueBucket === null) {  
      console.error('invalid valueBuckets');  
      return;  
    }  
    rdbStore.insert(TBL_NAME, valueBucket, (err, ret) => {  
      console.info(`callback ret: ${ret}`);  
      if (callback !== undefined) {  
        callback(err, ret);  
      }  
    });  
  }  
};  
    
```    
  
    
### update    
在数据库更新时服务端回调此接口，该方法可以选择性重写。  
 **调用形式：**     
    
- update?(     uri: string,     predicates: dataSharePredicates.DataSharePredicates,     valueBucket: ValuesBucket,     callback: AsyncCallback\<number>   ): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指示要更新的数据的路径。 |  
| predicates | dataSharePredicates.DataSharePredicates | true | 指示筛选条件。 |  
| valueBucket | ValuesBucket | true | 指示要更新的数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回更新的数据记录数。 |  
    
 **示例代码：**   
```ts    
import relationalStore from '@ohos.data.relationalStore';  
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { ValuesBucket } from '@ohos.data.ValuesBucket'  
  
let TBL_NAME = 'TBL00';  
let rdbStore: relationalStore.RdbStore;  
  
export default class DataShareExtAbility extends DataShareExtensionAbility {  
  update(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket, callback: Function) {  
    if (predicates === null || predicates === undefined) {  
      return;  
    }  
    rdbStore.update(TBL_NAME, valueBucket, predicates, (err, ret) => {  
      if (callback !== undefined) {  
        callback(err, ret);  
      }  
    });  
  }  
};  
    
```    
  
    
### delete    
在删除数据库记录时服务端回调此接口，该方法可以选择性重写。  
 **调用形式：**     
    
- delete?(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指示要删除的数据的路径。 |  
| predicates | dataSharePredicates.DataSharePredicates | true | 指示筛选条件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回已删除的数据记录数。 |  
    
 **示例代码：**   
```ts    
import relationalStore from '@ohos.data.relationalStore';  
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
let TBL_NAME = 'TBL00';  
let rdbStore: relationalStore.RdbStore;  
  
export default class DataShareExtAbility extends DataShareExtensionAbility {  
  delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: Function) {  
    if (predicates === null || predicates === undefined) {  
      return;  
    }  
    rdbStore.delete(TBL_NAME, predicates, (err, ret) => {  
      if (callback !== undefined) {  
        callback(err, ret);  
      }  
    });  
  }  
};  
    
```    
  
    
### query    
在查询数据库时服务端回调此接口，该方法可以选择性重写。  
 **调用形式：**     
    
- query?(     uri: string,     predicates: dataSharePredicates.DataSharePredicates,     columns: Array\<string>,     callback: AsyncCallback\<Object>   ): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指示要查询的数据的路径。 |  
| predicates | dataSharePredicates.DataSharePredicates | true | 指示筛选条件。 |  
| columns | Array<string> | true | 指示要查询的列。如果此参数为空，则查询所有列。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回查询到的结果集。 |  
    
 **示例代码：**   
```ts    
import relationalStore from '@ohos.data.relationalStore';  
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
  
let TBL_NAME = 'TBL00';  
let rdbStore: relationalStore.RdbStore;  
  
export default class DataShareExtAbility extends DataShareExtensionAbility {  
  query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array<string>, callback: Function) {  
    if (predicates === null || predicates === undefined) {  
      return;  
    }  
    rdbStore.query(TBL_NAME, predicates, columns, (err, resultSet) => {  
      if (resultSet !== undefined) {  
        console.info(`resultSet.rowCount: ${resultSet.rowCount}`);  
      }  
      if (callback !== undefined) {  
        callback(err, resultSet);  
      }  
    });  
  }  
};  
    
```    
  
    
### batchInsert    
在数据库批量插入时服务端回调此接口，该方法可以选择性重写。  
 **调用形式：**     
    
- batchInsert?(uri: string, valueBuckets: Array\<ValuesBucket>, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指示要批量插入的数据的路径。 |  
| valueBuckets | Array<ValuesBucket> | true | 指示要批量插入的数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回插入的数据记录数。 |  
    
 **示例代码：**   
```ts    
import relationalStore from '@ohos.data.relationalStore';  
import { ValuesBucket } from '@ohos.data.ValuesBucket'  
  
let TBL_NAME = 'TBL00';  
let rdbStore: relationalStore.RdbStore;  
  
export default class DataShareExtAbility extends DataShareExtensionAbility {  
  batchInsert(uri: string, valueBuckets: Array<ValuesBucket>, callback: Function) {  
    if (valueBuckets === null || valueBuckets.length === undefined) {  
      console.error('invalid valueBuckets');  
      return;  
    }  
    rdbStore.batchInsert(TBL_NAME, valueBuckets, (err, ret) => {  
      if (callback !== undefined) {  
        callback(err, ret);  
      }  
    });  
  };  
};  
    
```    
  
    
### normalizeUri    
用户给定的URI转换为服务端使用的URI时回调此接口，该方法可以选择性重写。  
 **调用形式：**     
    
- normalizeUri?(uri: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指示用户传入的[URI](js-apis-uri.md#uri)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果支持URI规范化，则返回规范化URI，否则返回空。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
export default class DataShareExtAbility extends DataShareExtensionAbility {  
  normalizeUri(uri: string, callback: Function) {  
    let key = 'code';  
    let value = 0;  
    let err: BusinessError = {  
      code: value,  
      name: key,  
      message: key  
    };  
    let ret: string = `normalize: ${uri}`;  
    callback(err, ret);  
  }  
};  
    
```    
  
    
### denormalizeUri    
服务端使用的URI转换为用户传入的初始URI时服务端回调此接口，该方法可以选择性重写。  
 **调用形式：**     
    
- denormalizeUri?(uri: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 指示服务端使用的[URI](js-apis-uri.md#uri)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果反规范化成功，则返回反规范化的URI；如果无需进行反规范化，则返回原始URI；若不支持则返回空。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
export default class DataShareExtAbility extends DataShareExtensionAbility {  
  denormalizeUri(uri: string, callback: Function) {  
    let key = 'code';  
    let value = 0;  
    let err: BusinessError = {  
      code: value,  
      name: key,  
      message: key  
    };  
      let ret = `denormalize ${uri}`;  
      callback(err, ret);  
  }  
};  
    
```    
  
