# @ohos.data.distributedKVStore    
分布式键值数据库为应用程序提供不同设备间数据库的分布式协同能力。通过调用分布式键值数据库各个接口，应用程序可将数据保存到分布式键值数据库中，并可对分布式键值数据库中的数据进行增加、删除、修改、查询、同步等操作。  
  
该模块提供以下分布式键值数据库相关的常用功能：  
  
- [KVManager](#kvmanager)：分布式键值数据库管理实例，用于获取数据库的相关信息。  
- [KVStoreResultSet](#kvstoreresultset)：提供获取数据库结果集的相关方法，包括查询和移动数据读取位置等。  
- [Query](#query)：使用谓词表示数据库查询，提供创建Query实例、查询数据库中的数据和添加谓词的方法。  
- [SingleKVStore](#singlekvstore)：单版本分布式键值数据库，不对数据所属设备进行区分，提供查询数据和同步数据的方法。  
- [DeviceKVStore](#devicekvstore)：设备协同数据库，继承自[SingleKVStore](#singlekvstore)，以设备维度对数据进行区分，提供查询数据和同步数据的方法。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedKVStore from '@ohos.data.distributedKVStore'    
```  
    
## SingleKVStore    
SingleKVStore数据库实例，提供增加数据、删除数据和订阅数据变更、订阅数据同步完成的方法。在调用SingleKVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个SingleKVStore实例。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
### putBatch    
将valuesbucket类型的值写入SingleKVStore数据库，使用Promise异步回调。  
 **调用形式：**     
    
- putBatch(value: Array\<ValuesBucket>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- putBatch(value: Array\<ValuesBucket>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- putBatch(value: Array\<ValuesBucket>): Promise\<void>    
起始版本： 9    
- putBatch(value: Array\<ValuesBucket>): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Array<ValuesBucket> | true | 表示要插入的数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let v8Arr: distributedKVStore.Entry[] = [];  
  let arr = new Uint8Array([4, 5, 6, 7]);  
  let vb1: distributedKVStore.Entry = { key: "name_1", value: 32 }  
  let vb2: distributedKVStore.Entry = { key: "name_2", value: arr };  
  let vb3: distributedKVStore.Entry = { key: "name_3", value: "lisi" };  
  
  v8Arr.push(vb1);  
  v8Arr.push(vb2);  
  v8Arr.push(vb3);  
  kvStore.putBatch(v8Arr, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting batch');  
  })  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to put batch.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let v8Arr: distributedKVStore.Entry[] = [];  
  let arr = new Uint8Array([4, 5, 6, 7]);  
  let vb1: distributedKVStore.Entry = { key: "name_1", value: 32 }  
  let vb2: distributedKVStore.Entry = { key: "name_2", value: arr };  
  let vb3: distributedKVStore.Entry = { key: "name_3", value: "lisi" };  
  
  v8Arr.push(vb1);  
  v8Arr.push(vb2);  
  v8Arr.push(vb3);  
  kvStore.putBatch(v8Arr).then(async () => {  
    console.info(`Succeeded in putting patch`);  
  }).catch((err: BusinessError) => {  
    console.error(`putBatch fail.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`putBatch fail.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### delete    
从数据库中删除符合predicates条件的键值对，使用Promise异步回调。  
 **调用形式：**     
    
- delete(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<void>)    
起始版本： 9    
- delete(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<void>)    
起始版本： 10    
- delete(predicates: dataSharePredicates.DataSharePredicates): Promise\<void>    
起始版本： 9    
- delete(predicates: dataSharePredicates.DataSharePredicates): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates | dataSharePredicates.DataSharePredicates | true | 指示筛选条件,当此参数为null时，应定义处理逻辑。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 15100003 | Database corrupted. |  
| 15100005 | Database or result set already closed. |  
| 14800047 | The WAL file size exceeds the default limit. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let predicates = new dataSharePredicates.DataSharePredicates();  
  let arr = ["name"];  
  predicates.inKeys(arr);  
  kvStore.put("name", "bob", (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info("Succeeded in putting");  
    kvStore.delete(predicates, (err) => {  
      if (err == undefined) {  
        console.info('Succeeded in deleting');  
      } else {  
        console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);  
      }  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let predicates = new dataSharePredicates.DataSharePredicates();  
  let arr = ["name"];  
  predicates.inKeys(arr);  
  kvStore.put("name", "bob").then(() => {  
    console.info(`Succeeded in putting data`);  
    kvStore.delete(predicates).then(() => {  
      console.info('Succeeded in deleting');  
    }).catch((err: BusinessError) => {  
      console.error(`Failed to delete.code is ${err.code},message is ${err.message}`);  
    });  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
### getResultSet    
获取与指定Predicate对象匹配的KVStoreResultSet对象，使用Promise异步回调。  
 **调用形式：**     
    
- getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 9    
- getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 10    
- getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates | dataSharePredicates.DataSharePredicates | true | 指示筛选条件,当此参数为null时，应定义处理逻辑。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取与指定Predicates对象匹配的KVStoreResultSet对象。 |  
| Promise<KVStoreResultSet> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 15100003 | Over max  limits. |  
| 15100005 | Database corrupted. |  
| 15100001 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting batch');  
    const query = new distributedKVStore.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSet(query, async (err, result) => {  
      if (err != undefined) {  
        console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in getting result set');  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries).then(async () => {  
    console.info('Succeeded in putting batch');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
  });  
  const query = new distributedKVStore.Query();  
  query.prefixKey("batch_test");  
  kvStore.getResultSet(query).then((result) => {  
    console.info('Succeeded in getting result set');  
    resultSet = result;  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);  
}  
    
```    
  
    
## DeviceKVStore    
设备协同数据库，继承自SingleKVStore，提供查询数据和同步数据的方法。  
设备协同数据库，以设备维度对数据进行区分，每台设备仅能写入和修改本设备的数据，其它设备的数据对其是只读的，无法修改其它设备的数据。  
比如，可以使用设备协同数据库实现设备间的图片分享，可以查看其他设备的图片，但无法修改和删除其他设备的图片。在调用DeviceKVStore的方法前，需要先通过[getKVStore](#getkvstore)构建一个DeviceKVStore实例。  
 **系统能力:**  SystemCapability.DistributedDataManager.KVStore.DistributedKVStore    
### getResultSet    
获取与本设备指定Predicate对象匹配的KVStoreResultSet对象，使用Promise异步回调。  
 **调用形式：**     
    
- getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 9    
- getResultSet(predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<KVStoreResultSet>): void    
起始版本： 10    
- getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>    
起始版本： 10    
- getResultSet(       deviceId: string,       predicates: dataSharePredicates.DataSharePredicates,       callback: AsyncCallback\<KVStoreResultSet>     ): void    
起始版本： 9    
- getResultSet(       deviceId: string,       predicates: dataSharePredicates.DataSharePredicates,       callback: AsyncCallback\<KVStoreResultSet>     ): void    
起始版本： 10    
- getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>    
起始版本： 9    
- getResultSet(deviceId: string, predicates: dataSharePredicates.DataSharePredicates): Promise\<KVStoreResultSet>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedDataManager.DataShare.Provider    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| predicates | dataSharePredicates.DataSharePredicates | true | 指示筛选条件,当此参数为null时，应定义处理逻辑。 |  
| deviceId | string | true | 标识要查询其数据的设备。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取与指定Predicates对象匹配的KVStoreResultSet对象。 |  
| Promise<KVStoreResultSet> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 15100003 | Over max  limits. |  
| 15100005 | Database corrupted. |  
| 15100001 | Database or result set already closed. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let entries: distributedKVStore.Entry[] = [];  
  for (let i = 0; i < 10; i++) {  
    let key = 'batch_test_string_key';  
    let entry: distributedKVStore.Entry = {  
      key: key + i,  
      value: {  
        type: distributedKVStore.ValueType.STRING,  
        value: 'batch_test_string_value'  
      }  
    }  
    entries.push(entry);  
  }  
  kvStore.putBatch(entries, async (err) => {  
    if (err != undefined) {  
      console.error(`Failed to put batch.code is ${err.code},message is ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in putting batch');  
    const query = new distributedKVStore.Query();  
    query.prefixKey("batch_test");  
    kvStore.getResultSet(query, async (err, result) => {  
      if (err != undefined) {  
        console.error(`Failed to get resultSet.code is ${err.code},message is ${err.message}`);  
        return;  
      }  
      console.info('Succeeded in getting resultSet');  
      resultSet = result;  
      kvStore.closeResultSet(resultSet, (err) => {  
        if (err != undefined) {  
          console.error(`Failed to close resultSet.code is ${err.code},message is ${err.message}`);  
          return;  
        }  
        console.info('Succeeded in closing resultSet');  
      })  
    });  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`Failed to get resultSet.code is ${error.code},message is ${error.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import dataSharePredicates from '@ohos.data.dataSharePredicates';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let resultSet: distributedKVStore.KVStoreResultSet;  
  let predicates = new dataSharePredicates.DataSharePredicates();  
  predicates.prefixKey("batch_test_string_key");  
  kvStore.getResultSet('localDeviceId', predicates).then((result) => {  
    console.info('Succeeded in getting result set');  
    resultSet = result;  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to get resultset.code is ${err.code},message is ${err.message}`);  
  });  
  kvStore.closeResultSet(resultSet).then(() => {  
    console.info('Succeeded in closing result set');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to close resultset.code is ${err.code},message is ${err.message}`);  
  });  
} catch (e) {  
  let error = e as BusinessError;  
  console.error(`An unexpected error occurred.code is ${error.code},message is ${error.code}`);  
}  
    
```    
  
