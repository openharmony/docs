# Application Management


> **NOTE**
>
> The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import pkg from '@system.package';
```


## package.hasInstalled

hasInstalled(Object): void

Checks whether an application exists, or whether a native application has been installed.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes | Application bundle name. |
| success | Function | No | Called when the check result is obtained. |
| fail | Function | No | Called when the check result fails to be obtained. |
| complete | Function | No | Called when the execution is complete. |

The following value will be returned when the check result is obtained.

| Name | Type | Description |
| -------- | -------- | -------- |
| result | boolean | The value **true** means that the application exists or the native application has been installed, and **false** means the opposite. |

**Example**

```
export default {    
  hasInstalled() {        
    pkg.hasInstalled({            
      bundleName: 'com.example.bundlename',            
      success: function(data) {                
        console.log('package has installed: ' + data);            
      },            
      fail: function(data, code) {               
        console.log('query package fail, code: ' + code + ', data: ' + data);            
      },        
    });    
  },
}
```