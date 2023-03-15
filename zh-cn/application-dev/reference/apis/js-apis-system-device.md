# @system.device (设备信息)

本模块提供当前设备的信息。

> **说明：**
>
> - 从API Version 6开始，该接口不再维护，推荐使用新接口[`@ohos.deviceInfo`](js-apis-device-info.md)进行设备信息查询。
>
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```typescript
import device from '@system.device';
```

## device.getInfo

getInfo(Object): void

获取当前设备的信息。

> **说明：**
> 在首页的onShow生命周期之前不建议调用device.getInfo接口。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| success | Function | 否 | 接口调用成功的回调函数。 |
| fail | Function | 否 | 接口调用失败的回调函数。 |
| complete | Function | 否 | 接口调用结束的回调函数。 |

success返回值：

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| brand | string | 品牌。 |
| manufacturer | string | 生产商。 |
| model | string | 型号。 |
| product | string | 代号。 |
| language<sup>4+</sup> | string | 系统语言。 |
| region<sup>4+</sup> | string | 系统地区。 |
| windowWidth | number | 可使用的窗口宽度。 |
| windowHeight | number | 可使用的窗口高度。 |
| screenDensity<sup>4+</sup> | number | 屏幕密度。 |
| screenShape<sup>4+</sup> | string | 屏幕形状。可取值：<br/>-&nbsp;rect：方形屏；<br/>-&nbsp;circle：圆形屏。 |
| apiVersion<sup>4+</sup> | number | 系统API版本号。 |
| releaseType<sup>4+</sup> | string | 版本发布类型，值为类型+版本号，如Beta1。<br/>类型可能值有：<br/>-&nbsp;Canary：同一apiVersion下，canary版本之间保持API兼容，beta版本不对canary版本兼容。<br/>-&nbsp;Beta：同一apiVersion下，beta版本之间保持API兼容，release版本不对beta版本兼容。<br/>-&nbsp;Release：release版本会保持5个API版本兼容。 |
| deviceType<sup>4+</sup> | string | 设备类型。 |

fail返回错误代码：

| 错误码 | 说明 |
| -------- | -------- |
| 200 | 返回结果中存在无法获得的信息。 |

**示例：**

```typescript
export default {    
  getInfo() {        
    device.getInfo({            
      success: function(data) {                
        console.log('Device information obtained successfully. Device brand:' + data.brand);            
      },            
      fail: function(data, code) {                
        console.log('Failed to obtain device information. Error code:'+ code + '; Error information: ' + data);            
      },        
    });    
  },
}
```