# Data Storage

>  **NOTE**<br/>
>
> - The APIs of this module are no longer maintained since API Version 6, and you are advised to use [`@ohos.data.storage`](js-apis-data-storage.md). From API Version 9, you are advised to use [`@ohos.data.preferences`](js-apis-data-preferences.md).
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import storage from '@system.storage';
```


## storage.get

get(Object): void

Reads the value stored in the cache based on the specified key.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the data to read.|
| default | string | No| Default value returned when the **key** does not exist.|
| success | Function | No| Called to return the value obtained when **storage.get()** is successful.|
| fail | Function | No| Called when **storage.get()** fails. In the callback, **data** indicates the error information, and **code** indicates the error code.|
| complete | Function | No| Called when **storage.get()** is complete.|

**Example**

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


## storage.set

set(Object): void

Sets the value in the cache based on the specified key.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the data to set.|
| value | string | Yes| New value to set. The maximum length is 128 bytes.|
| success | Function | No| Called when **storage.set()** is successful.|
| fail | Function | No| Called when **storage.set()** fails. In the callback, **data** indicates the error information, and **code** indicates the error code.|
| complete | Function | No| Called when **storage.set()** is complete.|

**Example**

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


## storage.clear

clear(Object): void

Clears the key-value pairs from the cache.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when **storage.clear()** is successful.|
| fail | Function | No| Called when **storage.clear()** fails. In the callback, **data** indicates the error information, and **code** indicates the error code.|
| complete | Function | No| Called when **storage.clear()** is complete.|

**Example**

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


## storage.delete

delete(Object): void

Deletes the key-value pair based on the specified key.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the data to delete.|
| success | Function | No| Called when **storage.delete()** is successful.|
| fail | Function | No| Called when **storage.delete()** fails. In the callback, **data** indicates the error information, and **code** indicates the error code.|
| complete | Function | No| Called when **storage.delete()** is complete.|

**Example**

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
