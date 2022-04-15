# Data Storage

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> - The APIs of this module are no longer maintained since API version 6. It is recommended that you use [`@ohos.data.storage`](js-apis-data-storage.md) instead.
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import storage from '@system.storage';
```


## storage.get

get(Object): void

Reads the stored content.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | string | Yes | Content&nbsp;index. |
| default | string | No | Default&nbsp;value&nbsp;returned&nbsp;when&nbsp;the&nbsp;**key**&nbsp;does&nbsp;not&nbsp;exist. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;stored&nbsp;content&nbsp;is&nbsp;successfully&nbsp;read. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;stored&nbsp;content&nbsp;fails&nbsp;to&nbsp;be&nbsp;read. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

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

Modifies the stored content.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | string | Yes | Index&nbsp;of&nbsp;the&nbsp;stored&nbsp;content&nbsp;to&nbsp;be&nbsp;modified. |
| value | string | No | Target&nbsp;storage&nbsp;content.&nbsp;The&nbsp;maximum&nbsp;number&nbsp;of&nbsp;characters&nbsp;allowed&nbsp;is&nbsp;128. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;stored&nbsp;content&nbsp;is&nbsp;modified&nbsp;successfully. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;stored&nbsp;content&nbsp;fails&nbsp;to&nbsp;be&nbsp;modified. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

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

Clears the stored content.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;stored&nbsp;content&nbsp;is&nbsp;cleared&nbsp;successfully |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;stored&nbsp;content&nbsp;fails&nbsp;to&nbsp;be&nbsp;cleared |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

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

Deletes the stored content.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| key | string | Yes | Content&nbsp;index. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;stored&nbsp;content&nbsp;is&nbsp;deleted&nbsp;successfully. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;stored&nbsp;content&nbsp;fails&nbsp;to&nbsp;be&nbsp;deleted. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

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