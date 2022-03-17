# 应用上下文

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 从API Version 7 开始，该接口不再维护，推荐使用新接口。具体新接口在接口描述中说明。
> 
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import app from '@system.app';
```


## app.getInfo

getInfo(): &lt;AppResponse&gt;

获取当前应用配置文件中声明的信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**返回值：**
**表1** AppResponse

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| appID<sup>6+</sup> | string | 表示应用的包名，用于标识应用的唯一性。 |
| appName | string | 表示应用的名称。 |
| versionName | string | 表示应用的版本名称。 |
| versionCode | number | 表示应用的版本号。 |

**示例：**

  ```
  export default {    
    getInfo(){        
      var info = app.getInfo();        
        console.log(JSON.stringify(info));    
    } 
  }
  ```

## app.screenOnVisible

screenOnVisible(Object): void

应用申请息屏不返回主表盘，再次亮屏依旧显示应用界面。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| visible | boolean | 否 | 是否启动保活，默认值false。 |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

**示例：**

  ```
  export default {    
    screenOnVisible(){        
      app.screenOnVisible({            
        visible: true,            
          success() {                
            console.log('call app.keepVisible success');            
          },            
          fail(data, code) {                
            console.log('call app.keepVisible fail');            
          },
      });    
    }
  }
  ```


## app.terminate

terminate(): void

退出当前Ability。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**示例：**

  ```
  export default {    
    terminate(){        
      app.terminate();    
    }}
  ```

## app.requestFullWindow

requestFullWindow(duration: number): void

请求应用以全窗口运行，FA在某些场景下（如半模态FA）会以非全窗口运行，调用该接口会从非全窗口切换为全窗口运行，如果已经以全窗口运行则该接口调用无效。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| duration | number | 否 | 请求全屏时，设定非全屏到全屏的过渡时间，单位为毫秒，默认时间与非全屏到全屏的距离成正比。 |

**示例：**

  ```
  export default {    
    requestFullWindow(){        
      app.requestFullWindow({            
        duration: 200});    
    }
  }
  ```
