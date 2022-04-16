# Application Management


> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
>
> - The APIs of this module are no longer maintained since API version 7. It is recommended that you use [`@ohos.bundle`](js-apis-Bundle.md) instead.
>
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import pkg from '@system.package';
```


## package.hasInstalled

hasInstalled(Object): void

Checks whether an application exists, or whether a native application has been installed.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework

**Parameter**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes | Application&nbsp;bundle&nbsp;name |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;check&nbsp;result&nbsp;is&nbsp;obtained |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;check&nbsp;result&nbsp;fails&nbsp;to&nbsp;be&nbsp;obtained |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

The following value will be returned when the check result is obtained.

| Name | Type | Description |
| -------- | -------- | -------- |
| result | boolean | Whether&nbsp;the&nbsp;application&nbsp;exists,&nbsp;or&nbsp;whether&nbsp;the&nbsp;native&nbsp;application&nbsp;has&nbsp;been&nbsp;installed |

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