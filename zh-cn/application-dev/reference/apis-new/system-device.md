# @system.device    
本模块提供当前设备的信息。  
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import device from '@system.device';  
    
```  
    
## DeviceResponse    
设备信息。  
 **系统能力:**  SystemCapability.Startup.SystemInfo.Lite    
### 属性    
 **系统能力:**  SystemCapability.Startup.SystemInfo.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| brand | string | false | true | 品牌。 |  
| manufacturer | string | false | true | 生产商。 |  
| model | string | false | true | 型号。 |  
| product | string | false | true | 代号。 |  
| language<sup>(4+)</sup> | string | false | true | 系统语言。 |  
| region<sup>(4+)</sup> | string | false | true | 系统地区。 |  
| windowWidth | number | false | true | 可使用的窗口宽度。 |  
| windowHeight | number | false | true | 可使用的窗口高度。 |  
| screenDensity<sup>(4+)</sup> | number | false | true | 屏幕密度。 |  
| screenShape<sup>(4+)</sup> | 'rect' \| 'circle' | false | true | 屏幕形状。可取值：<br/>-rect：方形屏；<br/>-circle：圆形屏。 |  
| apiVersion<sup>(4+)</sup> | number | false | true | 系统API版本号。 |  
| deviceType<sup>(4+)</sup> | string | false | true | 设备类型。 |  
    
 **示例代码：**   
```ts    
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
  
    
## GetDeviceOptions    
定义设备信息获取的参数选项。    
### 属性    
 **系统能力:**  SystemCapability.Startup.SystemInfo.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success | (data: DeviceResponse) => void | false | false | 接口调用成功的回调函数。 data为成功返回的设备信息，具体参考[DeviceResponse](#deviceresponse)。 |  
| fail | (data: any, code: number) => void | false | false | 接口调用失败的回调函数。 code为失败返回的错误码。<br>code:200，表示返回结果中存在无法获得的信息。 |  
| complete | () => void | false | false | 接口调用结束的回调函数。 |  
    
## Device  
 **系统能力:**  SystemCapability.Startup.SystemInfo.Lite    
### getInfo<sup>(deprecated)</sup>    
获取当前设备的信息。  
 **调用形式：**     
- static getInfo(options?: GetDeviceOptions): void  
  
 **废弃说明：** 从API version 6 开始废弃。  
 **系统能力:**  SystemCapability.Startup.SystemInfo.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | GetDeviceOptions | false | 定义设备信息获取的参数选项。 |  
    
 **示例代码：**   
```js    
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
  
