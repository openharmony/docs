# @system.storage    
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import storage from '@system.storage';  
    
```  
    
## GetStorageOptions<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 6 开始废弃。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 6 开始废弃。<br>内容索引。 |  
| default<sup>(deprecated)</sup> | string | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>key不存在则返回的默认值。 |  
| success<sup>(deprecated)</sup> | (data: any) => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用成功的回调函数，data为返回key对应的value。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用失败的回调函数，data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用结束的回调函数。 |  
    
## SetStorageOptions<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 6 开始废弃。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 6 开始废弃。<br>要修改的存储值的索引。 |  
| value<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 6 开始废弃。<br>新值。长度需小于128字节。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用失败的回调函数，data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用结束的回调函数。 |  
    
## ClearStorageOptions<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 6 开始废弃。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用失败的回调函数，data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用结束的回调函数。 |  
    
## DeleteStorageOptions<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 6 开始废弃。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| key<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 6 开始废弃。<br>内容索引。 |  
| success<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用失败的回调函数，data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用结束的回调函数。 |  
    
## Storage<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 6 开始废弃。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
### get<sup>(deprecated)</sup>    
通过索引读取缓存中存储的值。  
 **调用形式：**     
- static get(options: GetStorageOptions): void  
  
 **废弃说明：** 从API version 6 开始废弃。替代接口: ohos.preferences.preferences.get。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | GetStorageOptions | true | 接口配置信息。 |  
    
 **示例代码：**   
```js    
export default {      
  storageGet() {          
    storage.get({              
      key: 'storage_key',              
      success: function(data) {                  
        console.log('call storage.get success: ' + data);              
      },              
      fail: function(data, code) {                  
        console.log('call storage.get fail, code: ' + code + ', data: ' + data);              
      },              
      complete: function() {                  
        console.log('call complete');              
      },  
    });      
  }  
}  
    
```    
  
    
### set<sup>(deprecated)</sup>    
修改缓存中索引对应的值。  
 **调用形式：**     
- static set(options: SetStorageOptions): void  
  
 **废弃说明：** 从API version 6 开始废弃。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | SetStorageOptions | true | 接口配置信息。 |  
    
 **示例代码：**   
```js    
export default {      
  storageSet() {          
    storage.set({              
      key: 'storage_key',              
      value: 'storage value',              
      success: function() {                  
        console.log('call storage.set success.');              
      },              
      fail: function(data, code) {                  
        console.log('call storage.set fail, code: ' + code + ', data: ' + data);              
      },          
    });      
  }  
}  
    
```    
  
    
### clear<sup>(deprecated)</sup>    
清空缓存中存储的键值对。  
 **调用形式：**     
- static clear(options?: ClearStorageOptions): void  
  
 **废弃说明：** 从API version 6 开始废弃。替代接口: ohos.preferences.preferences.clear。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | ClearStorageOptions | false | 接口配置信息。 |  
    
 **示例代码：**   
```js    
export default {      
  storageClear() {          
    storage.clear({              
      success: function() {                  
        console.log('call storage.clear success.');              
      },              
      fail: function(data, code) {                  
        console.log('call storage.clear fail, code: ' + code + ', data: ' + data);              
      },          
    });      
  }  
}  
    
```    
  
    
### delete<sup>(deprecated)</sup>    
删除缓存中索引对应的键值对。  
 **调用形式：**     
- static delete(options: DeleteStorageOptions): void  
  
 **废弃说明：** 从API version 6 开始废弃。替代接口: ohos.preferences.preferences.delete。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.DistributedDataManager.Preferences.Core.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | DeleteStorageOptions | true | 接口配置信息。 |  
    
 **示例代码：**   
```js    
export default {      
  storageDelete() {          
    storage.delete({              
      key: 'Storage1',              
      success: function() {                  
        console.log('call storage.delete success.');              
      },              
      fail: function(data, code) {                  
        console.log('call storage.delete fail, code: ' + code + ', data: ' + data);              
      },          
    });      
  }  
}  
    
```    
  
