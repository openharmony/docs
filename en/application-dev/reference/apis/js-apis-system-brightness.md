# Screen Brightness

> **NOTE**
> - The APIs of this module are no longer maintained since API version 7. You are advised to use [`@ohos.brightness`](js-apis-brightness.md).
> 
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import brightness from '@system.brightness';
```


## brightness.getValue

getValue(Object): void

Obtains the current screen brightness.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | (data: [BrightnessResponse](#brightnessresponse)) => void | No| Called when API call is successful.|
| fail | (data: string, code: number) => void | No| Called when API call has failed.|
| complete | () => void | No| Called when API call is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| value | number | Screen brightness. The value is an integer ranging from **1** to **255**.|


**Example**

  ```js
  export default {    
    getValue() {        
      brightness.getValue({            
        success: function(data){                
          console.log('success get brightness value:' + data.value);            
        },            
        fail: function(data, code) {                
          console.log('get brightness fail, code: ' + code + ', data: ' + data);            
        },
      });    
    },
  }
  ```


## brightness.setValue

setValue(Object): void

Sets the screen brightness.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Screen brightness. The value is an integer ranging from **1** to **255**.<br>- If the value is less than or equal to **0**, value **1** will be used.<br>- If the value is greater than **255**, value **255** will be used.<br>- If the value contains decimals, the integral part of the value will be used. For example, if value **8.1** is set, value **8** will be used.|
| success | () => void | No| Called when API call is successful.|
| fail | (data: string, code: number) => void | No| Called when API call has failed.|
| complete | () => void | No| Called when API call is complete.|

**Example**

  ```js
  export default {    
    setValue() {        
      brightness.setValue({            
        value: 100,            
        success: function(){                
          console.log('handling set brightness success.');            
        },            
        fail: function(data, code){                
          console.log('handling set brightness value fail, code:' + code + ', data: ' + data);            
        },        
      });    
    },
  }
  ```


## brightness.getMode

getMode(Object): void

Obtains the screen brightness adjustment mode.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | (data: [BrightnessModeResponse](#brightnessmoderesponse)) => void | No| Called when API call is successful.|
| fail | (data: string, code: number) => void | No| Called when API call has failed.|
| complete | () => void | No| Called when API call is complete.|

**Return value of success()**

| Name| Type| Description|
| -------- | -------- | -------- |
| mode | number | The value can be **0** or **1**.<br>- **0**: manual adjustment<br>- **1**: automatic adjustment|

**Example**

  ```js
  export default {    
    getMode() {        
      brightness.getMode({            
        success: function(data){                
          console.log('success get mode:' + data.mode);            
        },            
        fail: function(data, code){                
          console.log('handling get mode fail, code:' + code + ', data: ' + data);            
        },
      });    
    },
  }
  ```


## brightness.setMode

setMode(Object): void

Sets the screen brightness adjustment mode.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mode | number | Yes| The value can be **0** or **1**.<br>- **0**: manual adjustment<br>- **1**: automatic adjustment|
| success | () => void | No| Called when API call is successful.|
| fail | (data: string, code: number) => void | No| Called when API call has failed.|
| complete | () => void | No| Called when API call is complete.|

**Example**

  ```js
  export default {    
    setMode() {        
      brightness.setMode({            
        mode: 1,            
        success: function(){                
        console.log('handling set mode success.');            
      },            
       fail: function(data, code){                
         console.log('handling set mode fail, code:' + code + ', data: ' + data);            
       },
      });    
    },
  }
  ```


## brightness.setKeepScreenOn

setKeepScreenOn(Object): void

Sets whether to always keep the screen on. Call this API in **onShow()**.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| keepScreenOn | boolean | Yes| Whether to keep the screen on.|
| success | () => void | No| Called when API call is successful.|
| fail | (data: string, code: number) => void | No| Called when API call has failed.|
| complete | () => void | No| Called when API call is complete.|

**Example**

  ```js
  export default {    
    setKeepScreenOn() {        
      brightness.setKeepScreenOn({            
        keepScreenOn: true,            
        success: function () {                
          console.log('handling set keep screen on success.')            
        },            
        fail: function (data, code) {                
          console.log('handling set keep screen on fail, code:' + code + ', data: ' + data);            
        },        
      });    
    },
  }
  ```
## 

## BrightnessResponse

| Name| Type | Description|
| -------- | -------- | -------- |
| value | number | Screen brightness. The value is an integer ranging from **1** to **255**.|

## BrightnessModeResponse

| Name| Type | Description|
| -------- | -------- | -------- |
| mode | number | The value can be **0** or **1**.<br> - **0**: manual adjustment<br>- **0**: manual adjustment|
