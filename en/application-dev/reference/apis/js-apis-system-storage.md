# Data storage

> ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**<br/>
>
> - The APIs of this module are no longer maintained since API Version 6. You are advised to use [`@ohos.data.storage`](js-apis-data-storage.md). From API Version 9, you are advised to use [`@ohos.data.preferences`](js-apis-data-preferences.md).
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import storage from '@system.storage';
```


## storage.get

get(Object): void

Obtains the stored data.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Index of the data to obtain.|
| default | string | No| Default value returned when the **key** does not exist.|
| success | Function | No| Called when the stored data is successfully obtained.|
| fail | Function | No| Called when the stored data failed to be obtained.|
| complete | Function | No| Called when the execution is complete.|

**Example**

```
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


## storage.set

set(Object): void

Modifies the stored data.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Index of the data to modify.|
| value | string | No| New value to set. The maximum length is 128 bytes.|
| success | Function | No| Called when the data is successfully modified.|
| fail | Function | No| Called when the data failed to be modified.|
| complete | Function | No| Called when the execution is complete.|

**Example**

```
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


## storage.clear

clear(Object): void

Clears the stored data.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when the data is successfully cleared.|
| fail | Function | No| Called when the data failed to be cleared.|
| complete | Function | No| Called when the execution is complete.|

**Example**

```
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


## storage.delete

delete(Object): void

Deletes the stored data.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Index of the data to delete.|
| success | Function | No| Called when the data is deleted.|
| fail | Function | No| Called when the data failed to be deleted.|
| complete | Function | No| Called when the execution is complete.|

**Example**

```
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
