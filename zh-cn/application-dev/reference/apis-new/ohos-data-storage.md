# @ohos.data.storage    
轻量级存储为应用提供key-value键值型的文件数据处理能力，支持应用对数据进行轻量级存储及查询。数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括数字型、字符型、布尔型。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import storage from '@ohos.data.storage'    
```  
    
## 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| MAX_KEY_LENGTH | number | true | true | key的最大长度限制为80字节。     。 |  
| MAX_VALUE_LENGTH | number | true | true | value的最大长度限制为8192字节。 。 |  
    
## getStorageSync<sup>(deprecated)</sup>    
读取指定文件，将数据加载到Storage实例，用于数据操作。  
 **调用形式：**     
- getStorageSync(path: string): Storage  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.getPreferences。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 应用程序内部数据存储路径。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Storage | 获取到要操作的Storage实例，用于进行数据存储操作。 |  
    
 **示例代码：**   
示例：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
  path = filePath;  
  console.info("======================>getFilesDirPromise====================>");  
  
  let storage = data_storage.getStorageSync(path + '/mystore');  
  storage.putSync('startup', 'auto');  
  storage.flushSync();  
});    
```    
  
    
## getStorage    
读取指定文件，将数据加载到Storage实例，用于数据操作  
 **调用形式：**     
    
- getStorage(path: string, callback: AsyncCallback\<Storage>): void    
起始版本： 6    
- getStorage(path: string): Promise\<Storage>    
起始版本： 6  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 应用程序内部数据存储路径。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<Storage> | Promise实例，用于异步获取结果。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
  path = filePath;  
  console.info("======================>getFilesDirPromise====================>");  
  
  data_storage.getStorage(path + '/mystore', function (err, storage) {  
    if (err) {  
      console.info("Failed to get the storage. path: " + path + '/mystore');  
      return;  
    }  
    storage.putSync('startup', 'auto');  
    storage.flushSync();  
  })  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
  path = filePath;  
  console.info("======================>getFilesDirPromise====================>");  
  
  let getPromise = data_storage.getStorage(path + '/mystore');  
  getPromise.then((storage) => {  
    storage.putSync('startup', 'auto');  
    storage.flushSync();  
  }).catch((err) => {  
    console.info("Failed to get the storage. path: " + path + '/mystore');  
  })  
});    
```    
  
    
## deleteStorageSync<sup>(deprecated)</sup>    
从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。  
 **调用形式：**     
- deleteStorageSync(path: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.deletePreferences。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 应用程序内部数据存储路径。  |  
    
 **示例代码：**   
示例：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
    path = filePath;  
    console.info("======================>getFilesDirPromise====================>");  
  
    data_storage.deleteStorageSync(path + '/mystore');  
});    
```    
  
    
## deleteStorage    
从内存中移除指定文件对应的Storage单实例，并删除指定文件及其备份文件、损坏文件。删除指定文件时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题  
 **调用形式：**     
    
- deleteStorage(path: string, callback: AsyncCallback\<void>): void    
起始版本： 6    
- deleteStorage(path: string): Promise\<void>    
起始版本： 6  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 应用程序内部数据存储路径。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise实例，用于异步获取结果。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
  path = filePath;  
  console.info("======================>getFilesDirPromise====================>");  
  
  data_storage.deleteStorage(path + '/mystore', function (err) {  
    if (err) {  
      console.info("Failed to delete the storage with err: " + err);  
      return;  
    }  
    console.info("Succeeded in deleting the storage.");  
  })  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
  path = filePath;  
  console.info("======================>getFilesDirPromise====================>");  
  
  let promisedelSt = data_storage.deleteStorage(path + '/mystore');  
  promisedelSt.then(() => {  
    console.info("Succeeded in deleting the storage.");  
  }).catch((err) => {  
    console.info("Failed to delete the storage with err: " + err);  
  })  
});    
```    
  
    
## removeStorageFromCacheSync<sup>(deprecated)</sup>    
从内存中移除指定文件对应的Storage单实例。移除Storage单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。  
 **调用形式：**     
- removeStorageFromCacheSync(path: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.removePreferencesFromCache。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | 应用程序内部数据存储路径。  |  
    
 **示例代码：**   
示例：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
    path = filePath;  
    console.info("======================>getFilesDirPromise====================>");  
  
    data_storage.removeStorageFromCacheSync(path + '/mystore');  
});    
```    
  
    
## removeStorageFromCache    
从内存中移除指定文件对应的Storage单实例。移除Storage单实例时，应用不允许再使用该实例进行数据操作，否则会出现数据一致性问题。  
 **调用形式：**     
    
- removeStorageFromCache(path: string, callback: AsyncCallback\<void>): void    
起始版本： 6    
- removeStorageFromCache(path: string): Promise\<void>    
起始版本： 6  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 应用程序内部数据存储路径。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise实例，用于异步获取结果。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
  path = filePath;  
  console.info("======================>getFilesDirPromise====================>");  
  
  data_storage.removeStorageFromCache(path + '/mystore', function (err) {  
    if (err) {  
      console.info("Failed to remove storage from cache with err: " + err);  
      return;  
    }  
    console.info("Succeeded in removing storage from cache.");  
  })  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
  
let path;  
let context = featureAbility.getContext();  
context.getFilesDir().then((filePath) => {  
  path = filePath;  
  console.info("======================>getFilesDirPromise====================>");  
  
  let promiserevSt = data_storage.removeStorageFromCache(path + '/mystore')  
  promiserevSt.then(() => {  
    console.info("Succeeded in removing storage from cache.");  
  }).catch((err) => {  
    console.info("Failed to remove storage from cache with err: " + err);  
  })  
});    
```    
  
    
## Storage<sup>(deprecated)</sup>    
提供获取和修改存储数据的接口。  
  
下列接口都需先使用[data_storage.getStorage](#data_storagegetstorage)或[data_storage.getStorageSync](#data_storagegetstoragesync)获取到Storage实例，再通过此实例调用对应接口。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.preferences.preferences替代。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core    
### getSync<sup>(deprecated)</sup>    
获取键对应的值，如果值为null或者非默认值类型，返回默认数据defValue。  
 **调用形式：**     
- getSync(key: string, defValue: ValueType): ValueType  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.get。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 要获取的存储key名称，不能为空。                               |  
| defValue<sup>(deprecated)</sup> | ValueType | true | 给定key的存储不存在，则要返回的默认值。支持number、string、boolean。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ValueType | 键对应的值，如果值为null或者非默认值类型，返回默认数据。 |  
    
 **示例代码：**   
示例：  
```ts    
let value = storage.getSync('startup', 'default');  
console.info("The value of startup is " + value);    
```    
  
    
### get    
获取键对应的值，如果值为null或者非默认值类型，返回默认数据defValue。  
 **调用形式：**     
    
- get(key: string, defValue: ValueType, callback: AsyncCallback\<ValueType>): void    
起始版本： 6    
- get(key: string, defValue: ValueType): Promise\<ValueType>    
起始版本： 6  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要获取的存储key名称，不能为空。            |  
| defValue | ValueType | true | 默认返回值。支持number、string、boolean。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<ValueType> | Promise实例，用于异步获取结果。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
storage.get('startup', 'default', function(err, value) {  
    if (err) {  
        console.info("Failed to get the value of startup with err: " + err);  
        return;  
      }  
    console.info("The value of startup is " + value);  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let promiseget = storage.get('startup', 'default');  
promiseget.then((value) => {  
    console.info("The value of startup is " + value)  
}).catch((err) => {  
    console.info("Failed to get the value of startup with err: " + err);  
})    
```    
  
    
### hasSync<sup>(deprecated)</sup>    
检查存储对象是否包含名为给定key的存储。  
 **调用形式：**     
- hasSync(key: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.has。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 要获取的存储key名称，不能为空。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true表示存在，false表示不存在。 |  
    
 **示例代码：**   
示例：  
```ts    
let isExist = storage.hasSync('startup');  
if (isExist) {  
    console.info("The key of startup is contained.");  
}    
```    
  
    
### has    
检查存储对象是否包含名为给定key的存储。  
 **调用形式：**     
    
- has(key: string, callback: AsyncCallback\<boolean>): boolean    
起始版本： 6    
- has(key: string): Promise\<boolean>    
起始版本： 6  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要获取的存储key名称，不能为空。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| boolean | true表示存在，false表示不存在。 |  
| Promise<boolean> | Promise实例，用于异步处理。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
storage.has('startup', function (err, isExist) {  
    if (err) {  
        console.info("Failed to check the key of startup with err: " + err);  
        return;  
    }  
    if (isExist) {  
        console.info("The key of startup is contained.");  
    }  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let promisehas = storage.has('startup')  
promisehas.then((isExist) => {  
    if (isExist) {  
        console.info("The key of startup is contained.");  
    }  
}).catch((err) => {  
    console.info("Failed to check the key of startup with err: " + err);  
})    
```    
  
    
### putSync<sup>(deprecated)</sup>    
首先获取指定文件对应的Storage实例，然后借助Storage API将数据写入Storage实例，通过flush或者flushSync将Storage实例持久化。  
 **调用形式：**     
- putSync(key: string, value: ValueType): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.put。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 要修改的存储的key，不能为空。              |  
| value<sup>(deprecated)</sup> | ValueType | true | 存储的新值。支持number、string、boolean。  |  
    
 **示例代码：**   
示例：  
```ts    
storage.putSync('startup', 'auto');    
```    
  
    
### put    
首先获取指定文件对应的Storage实例，然后借助Storage API将数据写入Storage实例，通过flush或者flushSync将Storage实例持久化。  
 **调用形式：**     
    
- put(key: string, value: ValueType, callback: AsyncCallback\<void>): void    
起始版本： 6    
- put(key: string, value: ValueType): Promise\<void>    
起始版本： 6  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要修改的存储的key，不能为空。              |  
| value | ValueType | true | 存储的新值。支持number、string、boolean。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise实例，用于异步处理。 |  
    
 **示例代码1：**   
示例（callback<span style="letter-spacing: 0px;">）：</span>  
```ts    
storage.put('startup', 'auto', function (err) {  
    if (err) {  
        console.info("Failed to put the value of startup with err: " + err);  
        return;  
    }  
    console.info("Succeeded in putting the value of startup.");  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let promiseput = storage.put('startup', 'auto');  
promiseput.then(() => {  
    console.info("Succeeded in putting the value of startup.");  
}).catch((err) => {  
    console.info("Failed to put the value of startup with err: " + err);  
})    
```    
  
    
### deleteSync<sup>(deprecated)</sup>    
从存储对象中删除名为给定key的存储。  
 **调用形式：**     
- deleteSync(key: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.delete。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | true | 要获取的存储key名称。它不能为空。  |  
    
 **示例代码：**   
示例：  
```ts    
 storage.deleteSync('startup');    
```    
  
    
### delete    
从存储对象中删除名为给定key的存储。  
 **调用形式：**     
    
- delete(key: string, callback: AsyncCallback\<void>): void    
起始版本： 6    
- delete(key: string): Promise\<void>    
起始版本： 6  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | string | true | 要获取的存储key名称，不能为空。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 要获取的存储key名称，不能为空。 |  
| Promise<void> | Promise实例，用于异步处理。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
storage.delete('startup', function (err) {  
    if (err) {  
        console.info("Failed to delete startup key failed err: " + err);  
        return;  
    }  
    console.info("Succeeded in deleting startup key.");  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let promisedel = storage.delete('startup')  
promisedel.then(() => {  
    console.info("Succeeded in deleting startup key.");  
}).catch((err) => {  
    console.info("Failed to delete startup key failed err: " + err);  
})    
```    
  
    
### clearSync<sup>(deprecated)</sup>    
将当前storage对象中的修改保存到当前的storage，并同步存储到文件中。  
 **调用形式：**     
- clearSync(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.clear。    
 **示例代码：**   
示例：  
```ts    
storage.clearSync();    
```    
  
    
### clear    
清除此存储对象中的所有存储。  
 **调用形式：**     
    
- clear(callback: AsyncCallback\<void>): void    
起始版本： 6    
- clear(): Promise\<void>    
起始版本： 6  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise实例，用于异步处理。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
storage.clear(function (err) {  
    if (err) {  
        console.info("Failed to clear the storage with err: " + err);  
        return;  
    }  
    console.info("Succeeded in clearing the storage.");  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let promiseclear = storage.clear();  
promiseclear.then(() => {  
    console.info("Succeeded in clearing the storage.");  
}).catch((err) => {  
    console.info("Failed to clear the storage with err: " + err);  
})    
```    
  
    
### flushSync<sup>(deprecated)</sup>    
将当前storage对象中的修改保存到当前的storage，并同步存储到文件中。  
 **调用形式：**     
- flushSync(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.flush。    
 **示例代码：**   
示例  
```ts    
storage.flushSync();    
```    
  
    
### flush    
将当前storage对象中的修改保存到当前的storage，并异步存储到文件中。  
 **调用形式：**     
    
- flush(callback: AsyncCallback\<void>): void    
起始版本： 6    
- flush(): Promise\<void>    
起始版本： 6  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise实例，用于异步处理。 |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
storage.flush(function (err) {  
    if (err) {  
        console.info("Failed to flush to file with err: " + err);  
        return;  
    }  
    console.info("Succeeded in flushing to file.");  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let promiseflush = storage.flush();  
promiseflush.then(() => {  
    console.info("Succeeded in flushing to file.");  
}).catch((err) => {  
    console.info("Failed to flush to file with err: " + err);  
})    
```    
  
    
### on('change')<sup>(deprecated)</sup>    
订阅数据变更者类需要实现StorageObserver接口，订阅的key的值发生变更后，在执行flush/flushSync方法后，callback方法会被回调。  
 **调用形式：**     
- on(type: 'change', callback: Callback\<StorageObserver>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.on。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 事件类型，固定值'change'，表示数据变更。  |  
| callback<sup>(deprecated)</sup> | Callback<StorageObserver> | true | 回调对象实例。                            |  
    
 **示例代码：**   
示例：  
```ts    
let observer = function (key) {  
    console.info("The key of " + key + " changed.");  
}  
storage.on('change', observer);  
storage.putSync('startup', 'auto');  
storage.flushSync();  // observer will be called.    
```    
  
    
### off('change')<sup>(deprecated)</sup>    
当不再进行订阅数据变更时，使用此接口取消订阅。  
 **调用形式：**     
- off(type: 'change', callback: Callback\<StorageObserver>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.preferences.preferences.off。    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 事件类型，固定值'change'，表示数据变更。  |  
| callback<sup>(deprecated)</sup> | Callback<StorageObserver> | true | 需要取消的回调对象实例。                  |  
    
 **示例代码：**   
示例：  
```ts    
let observer = function (key) {  
    console.info("The key of " + key + " changed.");  
}  
storage.off('change', observer);    
```    
  
    
## ValueType    
用于表示允许的数据字段类型。    
    
| 取值范围 | 说明 |  
| --------| --------|  
| number | 表示值类型为数字。 |  
| string | 表示值类型为字符。 |  
| boolean | 表示值类型为布尔值。 |  
    
## StorageObserver<sup>(deprecated)</sup>    
从API version 6 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| key | string | false | true | 变更的数据内容。  |  
