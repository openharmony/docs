# Screen Brightness

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> - The APIs of this module are no longer maintained since API version 7. It is recommended that you use [`@ohos.brightness`](js-apis-brightness.md) instead.
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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

The following values will be returned when the operation is successful.

| Name | Type | Description |
| -------- | -------- | -------- |
| value | number | Screen&nbsp;brightness,&nbsp;which&nbsp;ranges&nbsp;from&nbsp;1&nbsp;to&nbsp;255. |

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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| value | number | Yes | Screen&nbsp;brightness.&nbsp;The&nbsp;value&nbsp;is&nbsp;an&nbsp;integer&nbsp;ranging&nbsp;from&nbsp;1&nbsp;to&nbsp;255.<br/>-&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;**0**,&nbsp;value&nbsp;**1**&nbsp;will&nbsp;be&nbsp;used.<br/>-&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;greater&nbsp;than&nbsp;**255**,&nbsp;value&nbsp;**255**&nbsp;will&nbsp;be&nbsp;used.<br/>-&nbsp;If&nbsp;the&nbsp;value&nbsp;contains&nbsp;decimals,&nbsp;the&nbsp;integral&nbsp;part&nbsp;of&nbsp;the&nbsp;value&nbsp;will&nbsp;be&nbsp;used.&nbsp;For&nbsp;example,&nbsp;if&nbsp;value&nbsp;**8.1**&nbsp;is&nbsp;set,&nbsp;value&nbsp;**8**&nbsp;will&nbsp;be&nbsp;used. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete |

The following values will be returned when the operation is successful.

| Name | Type | Description |
| -------- | -------- | -------- |
| mode | number | The&nbsp;value&nbsp;can&nbsp;be&nbsp;**0**&nbsp;or&nbsp;**1**.<br/>-&nbsp;**0**:&nbsp;The&nbsp;screen&nbsp;brightness&nbsp;is&nbsp;manually&nbsp;adjusted.<br/>-&nbsp;**1**:&nbsp;The&nbsp;screen&nbsp;brightness&nbsp;is&nbsp;automatically&nbsp;adjusted. |

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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| mode | number | Yes | The&nbsp;value&nbsp;can&nbsp;be&nbsp;**0**&nbsp;or&nbsp;**1**.<br/>-&nbsp;**0**:&nbsp;The&nbsp;screen&nbsp;brightness&nbsp;is&nbsp;manually&nbsp;adjusted.<br/>-&nbsp;**1**:&nbsp;The&nbsp;screen&nbsp;brightness&nbsp;is&nbsp;automatically&nbsp;adjusted. |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| keepScreenOn | boolean | Yes | Whether&nbsp;to&nbsp;always&nbsp;keep&nbsp;the&nbsp;screen&nbsp;on |
| success | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;successful. |
| fail | Function | No | Called&nbsp;when&nbsp;the&nbsp;operation&nbsp;fails. |
| complete | Function | No | Called&nbsp;when&nbsp;the&nbsp;execution&nbsp;is&nbsp;complete. |

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