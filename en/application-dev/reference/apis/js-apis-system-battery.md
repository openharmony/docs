# Battery Level

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> - The APIs of this module are no longer maintained since API version 7. It is recommended that you use [`@ohos.batteryInfo`](js-apis-battery-info.md) instead.
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import battery from '@system.battery';
```


## battery.getStatus

getStatus(Object): void

Obtains the current charging state and battery level.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Parameter**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;check&nbsp;result&nbsp;is&nbsp;obtained |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;check&nbsp;result&nbsp;fails&nbsp;to&nbsp;be&nbsp;obtained |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

The following value will be returned when the check result is obtained.

| Name | Type | Description |
| -------- | -------- | -------- |
| charging | boolean | Whether&nbsp;the&nbsp;battery&nbsp;is&nbsp;being&nbsp;charged |
| level | number | Current&nbsp;battery&nbsp;level,&nbsp;which&nbsp;ranges&nbsp;from&nbsp;0.00&nbsp;to&nbsp;1.00. |

**Example**

```js
export default {    
  getStatus() {       
    battery.getStatus({           
      success: function(data) {               
        console.log('success get battery level:' + data.level);           
      },            
      fail: function(data, code) {                
        console.log('fail to get battery level code:' + code + ', data: ' + data);            
      },        
    });    
  },
}
```