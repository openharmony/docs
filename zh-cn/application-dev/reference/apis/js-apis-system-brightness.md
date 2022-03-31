# 屏幕亮度

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API Version 7 开始，该接口不再维护，推荐使用新接口[`@ohos.brightness`](js-apis-brightness.md)。
> 
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import brightness from '@system.brightness';
```


## brightness.getValue

getValue(Object): void

获得设备当前的屏幕亮度值。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| value | number | 屏幕亮度，取值为1-255之间的整数。 |

**示例：**

  ```
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

设置设备当前的屏幕亮度值。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 屏幕亮度，值为1-255之间的整数。<br/>-&nbsp;如果值小于等于0，系统按1处理。<br/>-&nbsp;如果值大于255，系统按255处理。<br/>-&nbsp;如果值为小数，系统将处理为整数。例如设置为8.1，系统按8处理。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

**示例：**

  ```
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

获得当前屏幕亮度模式。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

  success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| mode | number | 值为0或1：<br/>-&nbsp;0为手动调节屏幕亮度模式<br/>-&nbsp;1为自动调节屏幕亮度模式 |

**示例：**

  ```
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

设置设备当前的屏幕亮度模式。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mode | number | 是 | 值为0或1<br/>-&nbsp;0为手动调节屏幕亮度<br/>-&nbsp;1为自动调节屏幕亮度 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

**示例：**

  ```
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

设置屏幕是否保持常亮状态，开启常亮模式推荐在onShow()阶段调用。

**系统能力：** SystemCapability.PowerManager.DisplayPowerManager

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| keepScreenOn | boolean | 是 | 是否保持屏幕常亮。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

**示例：**

  ```
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
