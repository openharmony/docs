# @system.storage (Data Storage)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @yanhuii-->
<!--Designer: @houpengtao1-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

>  **NOTE**
>
>  - The APIs of this module are no longer maintained since API version 6, and you are advised to use [`@ohos.data.storage`](js-apis-data-storage.md). From API version 9, you are advised to use [`@ohos.data.preferences`](js-apis-data-preferences.md).
>
>  - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  
>  - The APIs of this module can be used only in the FA model.

## Modules to Import

```js
import storage from '@system.storage';
```

## storage.get

get(options: GetStorageOptions): void

Reads the value stored in the cache based on the specified key.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core.Lite

**Parameters**

| Name | Type                   | Mandatory| Description      |
| ------- | -------------------- | ---- | ---------- |
| options | [GetStorageOptions](#getstorageoptions) | Yes  | API configuration.|

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

set(options: SetStorageOptions): void

Sets the value in the cache based on the specified key.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core.Lite

**Parameters**

| Name | Type                  | Mandatory| Description      |
| ------- | ------------------- | ---- | ---------- |
| options | [SetStorageOptions](#setstorageoptions) | Yes  | API configuration.|

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

clear(options?: ClearStorageOptions): void

Clears the key-value pairs from the cache.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core.Lite

**Parameters**

| Name | Type                                       | Mandatory| Description          |
| ------- | ------------------------------------------- | ---- | -------------- |
| options | [ClearStorageOptions](#clearstorageoptions) | No  | API configuration.|

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

delete(options: DeleteStorageOptions): void

Deletes the key-value pair based on the specified key.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core.Lite

**Parameters**

| Name | Type                                         | Mandatory| Description          |
| ------- | --------------------------------------------- | ---- | -------------- |
| options | [DeleteStorageOptions](#deletestorageoptions) | Yes  | API configuration.|

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

## GetStorageOptions

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core.Lite

| Name    | Type         | Mandatory| Description                    |
| -------- | ---------------- | ---- | ------------------- |
| key      | string                               | Yes  | Key of the data to obtain.                                            |
| default  | string                               | No  | Default value returned when the specified key does not exist.                             |
| success  | (data: any) => void                  | No  | Called to return the value obtained when **storage.get()** is successfully called.    |
| fail     | (data: string, code: number) => void | No  | Called to return the result when **storage.get()** fails to be called. **data** indicates the error information, and **code** indicates the error code.|
| complete | () => void                           | No  | Called when **storage.get()** is complete.                              |


## SetStorageOptions

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core.Lite

| Name    | Type               | Mandatory| Description                  |
| -------- | ------------------- | ---- | -------------------- |
| key      | string                               | Yes  | Key of the data to set.                                |
| value    | string                               | Yes  | New value to set. The length must be less than 128 bytes.                             |
| success  | () => void                           | No  | Called when **storage.set()** is successfully called.                              |
| fail     | (data: string, code: number) => void | No  | Called to return the result when **storage.set()** fails to be called. **data** indicates the error information, and **code** indicates the error code.|
| complete | () => void                           | No  | Called when **storage.set()** is complete.                              |


## ClearStorageOptions

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core.Lite

| Name    | Type            | Mandatory| Description                        |
| -------- | --------------------- | ---- | -------------------- |
| success  | () => void                           | No  | Called when **storage.clear()** is successfully called.                              |
| fail     | (data: string, code: number) => void | No  | Called to return the result when **storage.clear()** fails to be called. **data** indicates the error information, and **code** indicates the error code.|
| complete | () => void                           | No  | Called when **storage.clear()** is complete.                              |


## DeleteStorageOptions

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core.Lite

| Name    | Type                | Mandatory| Description                 |
| -------- | -------------------- | ---- | ------------------ |
| key      | string                               | Yes  | Key of the data to delete.                                            |
| success  | () => void                           | No  | Called when **storage.delete()** is successfully called.                              |
| fail     | (data: string, code: number) => void | No  | Called to return the result when **storage.delete()** fails to be called. **data** indicates the error information, and **code** indicates the error code.|
| complete | () => void                           | No  | Called when **storage.delete()** is complete.                              |
