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

getInfo(): AppResponse

获取当前应用配置文件中声明的信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Lite

**返回值：**

| 参数类型 | 说明 |
| -------- | -------- |
| [AppResponse](#appresponse) | 定义AppResponse信息。 |

**示例：**

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

requestFullWindow(options?: RequestFullWindowOptions): void

请求应用以全窗口运行，FA在某些场景下（如半模态FA）会以非全窗口运行，调用该接口会从非全窗口切换为全窗口运行，如果已经以全窗口运行则该接口调用无效。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options | [RequestFullWindowOptions](#requestfullwindowoptions) | 否 | 请求全屏时，设定非全屏到全屏的过渡时间，单位为毫秒，默认时间与非全屏到全屏的距离成正比。 |

**示例：**

  ```
  export default {    
    requestFullWindow(){        
      app.requestFullWindow({            
        duration: 200});    
    }
  }
 ```

## app.setImageCacheCount

setImageCacheCount(value: number): void

设置解码图像计数的图像缓存容量。如果未设置，应用程序将不会缓存任何解码图像。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 否 | 解码图像计数的值容量。 |

## app.setImageRawDataCacheSize

setImageRawDataCacheSize(value: number): void

在解码前设置原始图像数据大小的图像缓存容量（以字节为单位）。如果未设置，应用程序将不会缓存任何原始图像数据。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 否 | 原始图像数据大小的值容量（以字节为单位）。 |


## app.setImageFileCacheSize

setImageFileCacheSize(value: number): void

在解码前设置磁盘上的图像文件缓存大小（以字节为单位）。如果未设置，应用程序将在磁盘上缓存100MB图像文件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | number | 否 | 原始图像数据大小的值容量（以字节为单位）。 |

## AppResponse

定义AppResponse信息。

**系统能力：**  以下各项对应的系统能力有所不同，详见下表。

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- |-------- |
| appID<sup>6+</sup> | string | 是 | 表示应用的包名，用于标识应用的唯一性。 <br> **系统能力：** SystemCapability.ArkUI.ArkUI.Full|
| appName | string | 是 | 表示应用的名称。 <br> **系统能力：** SystemCapability.ArkUI.ArkUI.Lite|
| versionName | string | 是 | 表示应用的版本名称。 <br> **系统能力：** SystemCapability.ArkUI.ArkUI.Lite|
| versionCode | number | 是 | 表示应用的版本号。 <br> **系统能力：** SystemCapability.ArkUI.ArkUI.Lite|

## ScreenOnVisibleOptions

定义屏幕上可见接口的选项。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| visible | boolean | 否 | 是否启动保活，默认值false。 |
| success | () => void | 否 | 接口调用成功的回调函数。 |
| fail | (data: string, code: number) => void | 否 | 接口调用失败的回调函数。 |
| complete | () => void | 否 | 接口调用结束的回调函数。 |

# RequestFullWindowOptions

定义RequestFullWindow接口的选项。

**系统能力：**  以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| duration | number | 是 | 定义动画选项的数量。 |

