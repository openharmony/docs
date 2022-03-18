# 应用上下文


## 导入模块

```
import app from '@system.app';
```

## 权限列表

无


## app.getInfo

getInfo(): &lt;AppResponse&gt;

获取当前应用配置文件中声明的信息。

- 返回值
  **表1** AppResponse
  
  | | | |
  | -------- | -------- | -------- |
  | 参数名 | 类型 | 说明 |
  | appID<sup>6+</sup> | string | 表示应用的包名，用于标识应用的唯一性。 |
  | appName | string | 表示应用的名称。 |
  | versionName | string | 表示应用的版本名称。 |
  | versionCode | number | 表示应用的版本号。 |

- 示例
  ```
  export default {    
    getInfo(){        
      var info = app.getInfo();        
        console.log(JSON.stringify(info));    
    } 
  }
  ```


## app.terminate

terminate(): void

退出当前Ability

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7 开始，推荐使用新接口['@ohos.ability.featureAbility'](js-apis-featureAbility.md)。

- 示例
  ```
  export default {    
    terminate(){        
      app.terminate();    
    }}
  ```

## app.requestFullWindow

requestFullWindow(duration: number): void

请求应用以全窗口运行，FA在某些场景下（如半模态FA）会以非全窗口运行，调用该接口会从非全窗口切换为全窗口运行，如果已经以全窗口运行则该接口调用无效。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | duration | number | 否 | 请求全屏时，设定非全屏到全屏的过渡时间，单位为毫秒，默认时间与非全屏到全屏的距离成正比。 |

- 示例
  ```
  export default {    
    requestFullWindow(){        
      app.requestFullWindow({            
        duration: 200});    
    }
  }
  ```
