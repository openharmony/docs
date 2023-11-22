# @ohos.resourceManager    
资源管理模块，根据当前configuration：语言、区域、横竖屏、Mcc（移动国家码）和Mnc（移动网络码）、Device capability（设备类型）、Density（分辨率）提供获取应用资源信息读取接口。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import resourceManager from '@ohos.resourceManager'    
```  
    
## Direction    
用于表示设备屏幕方向。    
    
 **系统能力:**  SystemCapability.Global.ResourceManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DIRECTION_VERTICAL | 0 | 竖屏  |  
| DIRECTION_HORIZONTAL | 1 | 横屏 |  
    
## DeviceType    
    
 **系统能力:**  SystemCapability.Global.ResourceManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEVICE_TYPE_PHONE | 0x00 |  |  
| DEVICE_TYPE_TABLET | 0x01 | 平板 |  
| DEVICE_TYPE_CAR | 0x02 | 汽车 |  
| DEVICE_TYPE_PC | 0x03 |  |  
| DEVICE_TYPE_TV | 0x04 | 电视 |  
| DEVICE_TYPE_WEARABLE | 0x06 | 穿戴  |  
| DEVICE_TYPE_2IN1<sup>(11+)</sup> | 0x07 |  |  
    
## ScreenDensity    
    
 **系统能力:**  SystemCapability.Global.ResourceManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCREEN_SDPI | 120 | 小规模的屏幕密度  |  
| SCREEN_MDPI | 160 | 中规模的屏幕密度 |  
| SCREEN_LDPI | 240 | 大规模的屏幕密度 |  
| SCREEN_XLDPI | 320 |  特大规模的屏幕密度   |  
| SCREEN_XXLDPI | 480 | 超大规模的屏幕密度 |  
| SCREEN_XXXLDPI | 640 | 超特大规模的屏幕密度 |  
    
## Configuration    
表示当前设备的状态。    
### 属性    
 **系统能力:**  SystemCapability.Global.ResourceManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| direction | Direction | false | true | 当前设备屏幕方向 |  
| locale | string | false | true | 当前系统语言  |  
    
## DeviceCapability    
表示设备支持的能力。    
### 属性    
 **系统能力:**  SystemCapability.Global.ResourceManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| screenDensity | ScreenDensity | false | true | 当前设备屏幕密度 |  
| deviceType | DeviceType | false | true | 当前设备类型 |  
    
## AsyncCallback<sup>(deprecated)</sup>    
从API version 6 开始支持，从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
### null  
 **调用形式：**     
- (err: Error, data: T): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| err | Error | true |  |  
| data | T | true |  |  
    
## getResourceManager    
获取指定应用的资源管理对象，返回ResourceManager对象。  
 **调用形式：**     
    
- getResourceManager(callback: AsyncCallback\<ResourceManager>): void    
起始版本： 6    
- getResourceManager(bundleName: string, callback: AsyncCallback\<ResourceManager>): void    
起始版本： 6    
- getResourceManager(): Promise\<ResourceManager>    
起始版本： 6    
- getResourceManager(bundleName: string): Promise\<ResourceManager>    
起始版本： 6  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指定应用的Bundle名称  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback方式返回ResourceManager对象 |  
| Promise<ResourceManager> | Promise方式返回资源管理对象 |  
    
 **示例代码1：**   
示例（callback）  
```ts    
resourceManager.getResourceManager("com.example.myapplication", (error, mgr) => {  
});    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
resourceManager.getResourceManager().then((mgr: resourceManager.ResourceManager) => {  
  mgr.getStringValue(0x1000000, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let str = value;  
    }  
  });  
}).catch((error: BusinessError) => {  
  console.log("error is " + error);  
});  
    
```    
  
    
## getSystemResourceManager<sup>(10+)</sup>    
获取系统资源管理对象，返回系统资源的ResourceManager对象。  
 **调用形式：**     
- getSystemResourceManager(): ResourceManager  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ResourceManager | 返回系统资源的管理对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9001009 | If application can't access system resource. |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let systemResourceManager = resourceManager.getSystemResourceManager();  
  systemResourceManager.getStringValue($r('sys.string.ohos_lab_vibrate').id).then((value: string) => {  
    let str = value;  
  }).catch((error: BusinessError) => {  
    console.log("systemResourceManager getStringValue promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`systemResourceManager getStringValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
## ResourceManager  
 **系统能力:**  SystemCapability.Global.ResourceManager    
### getString<sup>(deprecated)</sup>    
用户获取指定资源ID对应的字符串，使用callback形式返回字符串。  
 **调用形式：**     
- getString(resId: number, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getStringValue。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 异步回调，用于返回获取的字符串  |  
    
 **示例代码：**   
```ts    
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getString($r('app.string.test').id, (error, value) => {  
        if (error != null) {  
            console.log("error is " + error);  
        } else {  
            let str = value;  
        }  
    });  
});  
    
```    
  
    
### getString<sup>(deprecated)</sup>    
用户获取指定资源ID对应的字符串，使用Promise形式返回字符串。  
 **调用形式：**     
- getString(resId: number): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getStringValue。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true |  资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 资源ID值对应的字符串 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getString($r('app.string.test').id).then((value: string) => {  
        let str = value;  
    }).catch((error: BusinessError) => {  
        console.log("getstring promise error is " + error);  
    });  
});  
    
```    
  
    
### getStringValue<sup>(9+)</sup>    
用户获取指定resource对象对应的字符串。  
 **调用形式：**     
    
- getStringValue(resource: Resource, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getStringValue(resource: Resource): Promise\<string>    
起始版本： 9    
- getStringValue(resId: number, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getStringValue(resId: number): Promise\<string>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息 |  
| resId | number | true | 资源ID值    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的字符串 |  
| Promise<string> | 资源ID值对应的字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the module resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringValue($r('app.string.test').id, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let str = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getStringValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringValue($r('app.string.test').id).then((value: string) => {  
    let str = value;  
  }).catch((error: BusinessError) => {  
    console.log("getStringValue promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getStringValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringArray<sup>(deprecated)</sup>    
用户获取指定资源ID对应的字符串数组，使用callback形式返回字符串数组。  
 **调用形式：**     
- getStringArray(resId: number, callback: AsyncCallback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getStringArrayValue。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<string>> | true | 异步回调，用于返回获取的字符串数组 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let strArray = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getStringArrayValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringArray<sup>(deprecated)</sup>    
用户获取指定资源ID对应的字符串数组，使用Promise形式返回字符串数组。  
 **调用形式：**     
- getStringArray(resId: number): Promise\<Array\<string>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getStringArrayValue。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<string>> | 资源ID值对应的字符串数组 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id).then((value: Array<string>) => {  
    let strArray = value;  
  }).catch((error: BusinessError) => {  
    console.log("getStringArrayValue promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getStringArrayValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringArrayValue<sup>(9+)</sup>    
用户获取指定资源ID对应的字符串数组  
 **调用形式：**     
    
- getStringArrayValue(resource: Resource, callback: _AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- getStringArrayValue(resource: Resource): Promise\<Array\<string>>    
起始版本： 9    
- getStringArrayValue(resId: number, callback: _AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- getStringArrayValue(resId: number): Promise\<Array\<string>>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息  |  
| resId | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的字符串数组 |  
| Promise<Array<string>> | 资源ID值对应的字符串数组 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let strArray = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getStringArrayValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringArrayValue($r('app.strarray.test').id).then((value: Array<string>) => {  
    let strArray = value;  
  }).catch((error: BusinessError) => {  
    console.log("getStringArrayValue promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getStringArrayValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMedia<sup>(deprecated)</sup>    
用户获取指定资源ID对应的媒体文件内容。  
 **调用形式：**     
- getMedia(resId: number, callback: AsyncCallback\<Uint8Array>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getMediaContent。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Uint8Array> | true | 异步回调，用于返回获取的媒体文件内容 |  
    
 **示例代码：**   
```ts    
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getMedia($r('app.media.test').id, (error, value) => {  
        if (error != null) {  
            console.log("error is " + error);  
        } else {  
            let media = value;  
        }  
    });  
});  
    
```    
  
    
### getMedia<sup>(deprecated)</sup>    
用户获取指定资源ID对应的媒体文件内容，使用Promise形式返回字节数组。  
 **调用形式：**     
- getMedia(resId: number): Promise\<Uint8Array>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getMediaContent。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Uint8Array> | 资源ID值对应的媒体文件内容 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getMedia($r('app.media.test').id).then((value: Uint8Array) => {  
        let media = value;  
    }).catch((error: BusinessError) => {  
        console.log("getMedia promise error is " + error);  
    });  
});  
    
```    
  
    
### getMediaContent<sup>(9+)</sup>    
用户获取指定资源ID对应的媒体文件内容  
 **调用形式：**     
    
- getMediaContent(resource: Resource, callback: _AsyncCallback\<Uint8Array>): void    
起始版本： 9    
- getMediaContent(resource: Resource, density: number, callback: _AsyncCallback\<Uint8Array>): void    
起始版本： 10    
- getMediaContent(resource: Resource): Promise\<Uint8Array>    
起始版本： 9    
- getMediaContent(resource: Resource, density: number): Promise\<Uint8Array>    
起始版本： 10    
- getMediaContent(resId: number, callback: _AsyncCallback\<Uint8Array>): void    
起始版本： 9    
- getMediaContent(resId: number, density: number, callback: _AsyncCallback\<Uint8Array>): void    
起始版本： 10    
- getMediaContent(resId: number): Promise\<Uint8Array>    
起始版本： 9    
- getMediaContent(resId: number, density: number): Promise\<Uint8Array>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息  |  
| density<sup>(10+)</sup> | number | true | 资源获取需要的屏幕密度，0表示默认屏幕密度 |  
| resId | number | true | 资源ID值  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的媒体文件内容 |  
| Promise<Uint8Array> | resource对象对应的媒体文件内容 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaContent($r('app.media.test').id, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let media = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getMediaContent failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaContent($r('app.media.test').id).then((value: Uint8Array) => {  
    let media = value;  
  }).catch((error: BusinessError) => {  
    console.log("getMediaContent promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getMediaContent failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaBase64<sup>(deprecated)</sup>    
用户获取指定资源ID对应的图片资源Base64编码，使用callback形式返回字符串。  
 **调用形式：**     
- getMediaBase64(resId: number, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getMediaContentBase64。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值  。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 异步回调，用于返回获取的图片资源Base64编码 |  
    
 **示例代码：**   
```ts    
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getMediaBase64($r('app.media.test').id, (error, value) => {  
        if (error != null) {  
            console.log("error is " + error);  
        } else {  
            let media = value;  
        }  
    });  
});  
    
```    
  
    
### getMediaBase64<sup>(deprecated)</sup>    
用户获取指定资源ID对应的图片资源Base64编码，使用Promise形式返回字符串。  
 **调用形式：**     
- getMediaBase64(resId: number): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getMediaContentBase64。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值  。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 资源ID值对应的图片资源Base64编码 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getMediaBase64($r('app.media.test').id).then((value: string) => {  
        let media = value;  
    }).catch((error: BusinessError) => {  
        console.log("getMediaBase64 promise error is " + error);  
    });  
});  
    
```    
  
    
### getMediaContentBase64<sup>(9+)</sup>    
用户获取指定资源ID对应的图片资源Base64编码  
 **调用形式：**     
    
- getMediaContentBase64(resource: Resource, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getMediaContentBase64(resource: Resource, density: number, callback: _AsyncCallback\<string>): void    
起始版本： 10    
- getMediaContentBase64(resource: Resource): Promise\<string>    
起始版本： 9    
- getMediaContentBase64(resource: Resource, density: number): Promise\<string>    
起始版本： 10    
- getMediaContentBase64(resId: number, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getMediaContentBase64(resId: number, density: number, callback: _AsyncCallback\<string>): void    
起始版本： 10    
- getMediaContentBase64(resId: number): Promise\<string>    
起始版本： 9    
- getMediaContentBase64(resId: number, density: number): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息  |  
| density<sup>(10+)</sup> | number | true | 资源获取需要的屏幕密度，0表示默认屏幕密度 |  
| resId | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的图片资源Base64编码 |  
| Promise<string> | resource对象对应的图片资源Base64编码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaContentBase64($r('app.media.test').id, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let media = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaContentBase64($r('app.media.test').id, 120, (error, value) => {  
    if (error != null) {  
      console.error(`callback getMediaContentBase64 failed, error code: ${error.code}, message: ${error.message}.`);  
    } else {  
      let media = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getMediaContentBase64 failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getDeviceCapability    
用户获取设备的DeviceCapability。  
 **调用形式：**     
    
- getDeviceCapability(callback: _AsyncCallback\<DeviceCapability>): void    
起始版本： 6    
- getDeviceCapability(): Promise\<DeviceCapability>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回设备的DeviceCapability |  
| Promise<DeviceCapability> | 设备的DeviceCapability |  
    
 **示例代码1：**   
示例（callback）  
```ts    
try {  
  this.context.resourceManager.getDeviceCapability((error, value) => {  
    if (error != null) {  
      console.error("getDeviceCapability callback error is " + error);  
    } else {  
      let screenDensity = value.screenDensity;  
      let deviceType = value.deviceType;  
    }  
  });  
} catch (error) {  
  console.error("getDeviceCapability callback error is " + error);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getDeviceCapability().then((value: resourceManager.DeviceCapability) => {  
    let screenDensity = value.screenDensity;  
    let deviceType = value.deviceType;  
  }).catch((error: BusinessError) => {  
    console.error("getDeviceCapability promise error is " + error);  
  });  
} catch (error) {  
  console.error("getDeviceCapability promise error is " + error);  
}  
    
```    
  
    
### getConfiguration    
用户获取设备的Configuration  
 **调用形式：**     
    
- getConfiguration(callback: _AsyncCallback\<Configuration>): void    
起始版本： 6    
- getConfiguration(): Promise\<Configuration>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回设备的Configuration |  
| Promise<Configuration> | 设备的Configuration |  
    
 **示例代码1：**   
示例（callback）  
```ts    
try {  
  this.context.resourceManager.getConfiguration((error, value) => {  
    if (error != null) {  
      console.error("getConfiguration callback error is " + error);  
    } else {  
      let direction = value.direction;  
      let locale = value.locale;  
    }  
  });  
} catch (error) {  
  console.error("getConfiguration callback error is " + error);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getConfiguration().then((value: resourceManager.Configuration) => {  
    let direction = value.direction;  
    let locale = value.locale;  
  }).catch((error: BusinessError) => {  
    console.error("getConfiguration promise error is " + error);  
  });  
} catch (error) {  
  console.error("getConfiguration promise error is " + error);  
}  
    
```    
  
    
### getPluralString<sup>(deprecated)</sup>    
根据指定数量获取指定ID字符串表示的单复数字符串，使用callback形式返回字符串。  
 **调用形式：**     
- getPluralString(resId: number, num: number, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getPluralStringValue。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值 |  
| num<sup>(deprecated)</sup> | number | true | 数量值    |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 异步回调，返回根据指定数量获取指定ID字符串表示的单复数字符串 |  
    
 **示例代码：**   
```ts    
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getPluralString($r("app.plural.test").id, 1, (error, value) => {  
        if (error != null) {  
            console.log("error is " + error);  
        } else {  
            let str = value;  
        }  
    });  
});  
    
```    
  
    
### getPluralString<sup>(deprecated)</sup>    
根据指定数量获取对指定ID字符串表示的单复数字符串，使用Promise形式返回字符串。  
 **调用形式：**     
- getPluralString(resId: number, num: number): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getPluralStringValue。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId<sup>(deprecated)</sup> | number | true | 资源ID值  |  
| num<sup>(deprecated)</sup> | number | true | 数量值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 根据提供的数量获取对应ID字符串表示的单复数字符串 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getPluralString($r("app.plural.test").id, 1).then((value: string) => {  
        let str = value;  
    }).catch((error: BusinessError) => {  
        console.log("getPluralString promise error is " + error);  
    });  
});  
    
```    
  
    
### getPluralStringValue<sup>(9+)</sup>    
根据指定数量获取指定ID字符串表示的单复数字符串  
 **调用形式：**     
    
- getPluralStringValue(resource: Resource, num: number, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getPluralStringValue(resource: Resource, num: number): Promise\<string>    
起始版本： 9    
- getPluralStringValue(resId: number, num: number, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getPluralStringValue(resId: number, num: number): Promise\<string>    
起始版本： 9  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息  |  
| num | number | true | 数量值    |  
| resId | number | true | 资源ID值  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，返回根据指定数量获取指定ID字符串表示的单复数字符串 |  
| Promise<string> | 根据提供的数量获取对应resource对象表示的单复数字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let str = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getPluralStringValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getPluralStringValue($r("app.plural.test").id, 1).then((value: string) => {  
    let str = value;  
  }).catch((error: BusinessError) => {  
    console.log("getPluralStringValue promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getPluralStringValue failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getRawFile<sup>(deprecated)</sup>    
用户获取resources/rawfile目录下对应的rawfile文件内容，使用callback形式返回字节数组。  
 **调用形式：**     
- getRawFile(path: string, callback: AsyncCallback\<Uint8Array>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getRawFileContent。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | rawfile文件路径      |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Uint8Array> | true | 异步回调，用于返回获取的rawfile文件内容 |  
    
 **示例代码：**   
```ts    
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getRawFile("test.txt", (error, value) => {  
        if (error != null) {  
            console.log("error is " + error);  
        } else {  
            let rawFile = value;  
        }  
    });  
});  
    
```    
  
    
### getRawFile<sup>(deprecated)</sup>    
用户获取resources/rawfile目录下对应的rawfile文件内容，使用Promise形式返回字节数组。  
 **调用形式：**     
- getRawFile(path: string): Promise\<Uint8Array>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getRawFileContent。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | rawfile文件路径  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Uint8Array> | rawfile文件内容 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getRawFile("test.txt").then((value: Uint8Array) => {  
        let rawFile = value;  
    }).catch((error: BusinessError) => {  
        console.log("getRawFile promise error is " + error);  
    });  
});  
    
```    
  
    
### getRawFileDescriptor<sup>(deprecated)</sup>    
用户获取resources/rawfile目录下对应rawfile文件的descriptor，使用callback形式返回。  
 **调用形式：**     
- getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getRawFd。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | rawfile文件路径 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<RawFileDescriptor> | true | 异步回调，用于返回获取的rawfile文件的descriptor |  
    
 **示例代码：**   
```ts    
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getRawFileDescriptor("test.txt", (error, value) => {  
        if (error != null) {  
            console.log("error is " + error);  
        } else {  
            let fd = value.fd;  
            let offset = value.offset;  
            let length = value.length;  
        }  
    });  
});  
    
```    
  
    
### getRawFileDescriptor<sup>(deprecated)</sup>    
用户获取resources/rawfile目录下对应rawfile文件的descriptor，使用Promise形式返回。  
 **调用形式：**     
- getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.getRawFd。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true |  rawfile文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<RawFileDescriptor> | rawfile文件descriptor |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
resourceManager.getResourceManager((error, mgr) => {  
    mgr.getRawFileDescriptor("test.txt").then((value: resourceManager.RawFileDescriptor) => {  
        let fd = value.fd;  
        let offset = value.offset;  
        let length = value.length;  
    }).catch((error: BusinessError) => {  
        console.log("getRawFileDescriptor promise error is " + error);  
    });  
});  
    
```    
  
    
### closeRawFileDescriptor<sup>(deprecated)</sup>    
用户关闭resources/rawfile目录下rawfile文件的descriptor，使用callback形式返回。  
 **调用形式：**     
- closeRawFileDescriptor(path: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.closeRawFd。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true |  rawfile文件路径 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  异步回调 |  
    
 **示例代码：**   
```ts    
resourceManager.getResourceManager((error, mgr) => {  
    mgr.closeRawFileDescriptor("test.txt", (error, value) => {  
        if (error != null) {  
            console.log("error is " + error);  
        }  
    });  
});    
```    
  
    
### closeRawFileDescriptor<sup>(deprecated)</sup>    
用户关闭resources/rawfile目录下rawfile文件的descriptor，使用Promise形式返回。  
 **调用形式：**     
- closeRawFileDescriptor(path: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.resourceManager.closeRawFd。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true | rawfile文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回值 |  
    
 **示例代码：**   
```ts    
resourceManager.getResourceManager((error, mgr) => {  
    mgr.closeRawFileDescriptor("test.txt");  
});    
```    
  
    
### getStringByName<sup>(9+)</sup>    
用户获取指定资源名称对应的字符串  
 **调用形式：**     
    
- getStringByName(resName: string, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getStringByName(resName: string): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的字符串 |  
| Promise<string> | 资源名称对应的字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringByName("test", (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let str = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getStringByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringByName("test").then((value: string) => {  
    let str = value;  
  }).catch((error: BusinessError) => {  
    console.log("getStringByName promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getStringByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringArrayByName<sup>(9+)</sup>    
用户获取指定资源名称对应的字符串数组  
 **调用形式：**     
    
- getStringArrayByName(resName: string, callback: _AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- getStringArrayByName(resName: string): Promise\<Array\<string>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true |  资源名称   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的字符串数组 |  
| Promise<Array<string>> | 资源名称对应的字符串数组 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringArrayByName("test", (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let strArray = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getStringArrayByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringArrayByName("test").then((value: Array<string>) => {  
    let strArray = value;  
  }).catch((error: BusinessError) => {  
    console.log("getStringArrayByName promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getStringArrayByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaByName<sup>(9+)</sup>    
用户获取指定资源ID对应的媒体文件内容  
 **调用形式：**     
    
- getMediaByName(resName: string, callback: _AsyncCallback\<Uint8Array>): void    
起始版本： 9    
- getMediaByName(resName: string, density: number, callback: _AsyncCallback\<Uint8Array>): void    
起始版本： 10    
- getMediaByName(resName: string): Promise\<Uint8Array>    
起始版本： 9    
- getMediaByName(resName: string, density: number): Promise\<Uint8Array>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称  |  
| density<sup>(10+)</sup> | number | true | 资源获取需要的屏幕密度，0表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的媒体文件内容 |  
| Promise<Uint8Array> | 资源名称对应的媒体文件内容 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaByName("test", (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let media = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getMediaByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
参数：<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md#screendensity" style="background-color: rgb(255, 255, 255); font-size: 14px; letter-spacing: 0px;">density</a>  
```null    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaByName("test", 120, (error, value) => {  
    if (error != null) {  
      console.error(`callback getMediaByName failed, error code: ${error.code}, message: ${error.message}.`);  
    } else {  
      let media = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getMediaByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码3：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaByName("test").then((value: Uint8Array) => {  
    let media = value;  
  }).catch((error: BusinessError) => {  
    console.log("getMediaByName promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getMediaByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaBase64ByName<sup>(9+)</sup>    
用户获取指定资源名称对应的图片资源Base64编码  
 **调用形式：**     
    
- getMediaBase64ByName(resName: string, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getMediaBase64ByName(resName: string, density: number, callback: _AsyncCallback\<string>): void    
起始版本： 10    
- getMediaBase64ByName(resName: string): Promise\<string>    
起始版本： 9    
- getMediaBase64ByName(resName: string, density: number): Promise\<string>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称  |  
| density<sup>(10+)</sup> | number | true |  资源获取需要的屏幕密度，0表示默认屏幕密度  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的图片资源Base64编码 |  
| Promise<string> | 资源名称对应的图片资源Base64编码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaBase64ByName("test", (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let media = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getMediaBase64ByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
参数：<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md#screendensity" style="background-color: rgb(255, 255, 255); font-size: 14px; letter-spacing: 0px;">density</a>  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaBase64ByName("test", 120, (error, value) => {  
    if (error != null) {  
      console.error(`callback getMediaBase64ByName failed, error code: ${error.code}, message: ${error.message}.`);  
    } else {  
      let media = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getMediaBase64ByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码3：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaBase64ByName("test").then((value: string) => {  
    let media = value;  
  }).catch((error: BusinessError) => {  
    console.log("getMediaBase64ByName promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getMediaBase64ByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getPluralStringByName<sup>(9+)</sup>    
根据传入的数量值，获取资源名称对应的字符串资源  
 **调用形式：**     
    
- getPluralStringByName(resName: string, num: number, callback: _AsyncCallback\<string>): void    
起始版本： 9    
- getPluralStringByName(resName: string, num: number): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称  |  
| num | number | true | 数量值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，返回根据传入的数量值获取资源名称对应的字符串资源 |  
| Promise<string> | 根据传入的数量值获取资源名称对应的字符串资源 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getPluralStringByName("test", 1, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let str = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getPluralStringByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getPluralStringByName("test", 1).then((value: string) => {  
    let str = value;  
  }).catch((error: BusinessError) => {  
    console.log("getPluralStringByName promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getPluralStringByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringSync<sup>(9+)</sup>    
用户获取指定资源ID对应的字符串，使用同步方式返回字符串。  
 **调用形式：**     
- getStringSync(resId: number): string  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 资源ID值对应的字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringSync($r('app.string.test').id);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringSync<sup>(10+)</sup>    
用户获取指定资源ID对应的字符串，根据args参数进行格式化，使用同步方式返回相应字符串。  
 **调用形式：**     
- getStringSync(resId: number, ...args: Array\<string | number>): string  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值。 |  
| args | Array<string \| number> | true | 格式化字符串资源参数 <br> 支持参数类型：<br> %d、%f、%s、%% <br> 说明：%%转译符，转译%<br>举例：%%d格式化后为%d字符串 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 资源ID值对应的格式化字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
| 9001007 | If the resource obtained by resId formatting error. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringSync($r('app.string.test').id, "format string", 10, 98.78);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringSync<sup>(9+)</sup>    
用户获取指定resource对象对应的字符串，使用同步方式返回字符串。  
 **调用形式：**     
- getStringSync(resource: Resource): string  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | resource对象对应的字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
let resource: resourceManager.Resource = {  
  bundleName: "com.example.myapplication",  
  moduleName: "entry",  
  id: $r('app.string.test').id  
};  
try {  
  this.context.resourceManager.getStringSync(resource);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringSync<sup>(10+)</sup>    
用户获取指定resource对象对应的字符串，根据args参数进行格式化，使用同步方式返回相应字符串。  
 **调用形式：**     
- getStringSync(resource: Resource, ...args: Array\<string | number>): string  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true |  资源信息  |  
| args | Array<string \| number> | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | resource对象对应的格式化字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
| 9001007 | If the resource obtained by resId formatting error. |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
let resource: resourceManager.Resource = {  
  bundleName: "com.example.myapplication",  
  moduleName: "entry",  
  id: $r('app.string.test').id  
};  
try {  
  this.context.resourceManager.getStringSync(resource, "format string", 10, 98.78);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringByNameSync<sup>(9+)</sup>    
用户获取指定资源名称对应的字符串，使用同步方式返回字符串。  
 **调用形式：**     
- getStringByNameSync(resName: string): string  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 资源名称对应的字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringByNameSync("test");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringByNameSync<sup>(10+)</sup>    
用户获取指定资源名称对应的字符串，根据args参数进行格式化，使用同步方式返回相应字符串。  
。  
 **调用形式：**     
- getStringByNameSync(resName: string, ...args: Array\<string | number>): string  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称 |  
| args | Array<string \| number> | true | 格式化字符串资源参数 <br> 支持参数类型：<br /> %d、%f、%s、%% <br> 说明：%%转译符，转译%<br>举例：%%d格式化后为%d字符串 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 资源名称对应的格式化字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
| 9001008 | If the resource obtained by resName formatting error. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringByNameSync("test");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getBoolean<sup>(9+)</sup>    
使用同步方式，返回获取指定资源ID对应的布尔结果。  
 **调用形式：**     
- getBoolean(resId: number): boolean  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 资源ID值对应的布尔结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getBoolean($r('app.boolean.boolean_test').id);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getBoolean<sup>(9+)</sup>    
使用同步方式，返回获取指定resource对象对应的布尔结果。  
 **调用形式：**     
- getBoolean(resource: Resource): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | resource对象对应的布尔结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
let resource: resourceManager.Resource = {  
  bundleName: "com.example.myapplication",  
  moduleName: "entry",  
  id: $r('app.boolean.boolean_test').id  
};  
try {  
  this.context.resourceManager.getBoolean(resource);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getBoolean failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getBooleanByName<sup>(9+)</sup>    
使用同步方式，返回获取指定资源名称对应的布尔结果  
  
 **调用形式：**     
- getBooleanByName(resName: string): boolean  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 资源名称对应的布尔结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 |  |  
| 9001004 |  |  
| 9001006 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getBooleanByName("boolean_test");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getBooleanByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getNumber<sup>(9+)</sup>    
用户获取指定资源ID对应的integer数值或者float数值，使用同步方式返回资源对应的数值。  
 **调用形式：**     
- getNumber(resId: number): number  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 资源ID值对应的数值。Integer对应的是原数值，float对应的是真实像素点值，具体参考示例代码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getNumber($r('app.integer.integer_test').id); // integer对应返回的是原数值  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getNumber failed, error code: ${code}, message: ${message}.`);  
}  
  
try {  
  this.context.resourceManager.getNumber($r('app.float.float_test').id); // float对应返回的是真实像素点值  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getNumber failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getNumber<sup>(9+)</sup>    
用户获取指定resource对象对应的integer数值或者float数值，使用同步方式返回资源对应的数值。  
 **调用形式：**     
- getNumber(resource: Resource): number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true |  资源信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | resource对象对应的数值。Integer对应的是原数值，float对应的是真实像素点值, 具体参考示例代码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
let resource: resourceManager.Resource = {  
  bundleName: "com.example.myapplication",  
  moduleName: "entry",  
  id: $r('app.integer.integer_test').id  
};  
try {  
  this.context.resourceManager.getNumber(resource);// integer对应返回的是原数值, float对应返回的是真实像素点值  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getNumber failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getNumberByName<sup>(9+)</sup>    
用户获取指定资源名称对应的integer数值或者float数值，使用同步方式资源对应的数值。  
 **调用形式：**     
- getNumberByName(resName: string): number  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true |  资源名称 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 资源名称对应的数值 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getNumberByName("integer_test");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getNumberByName failed, error code: ${code}, message: ${message}.`);  
}  
  
try {  
  this.context.resourceManager.getNumberByName("float_test");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getNumberByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### release<sup>(7+)</sup>    
用户释放创建的resourceManager, 此接口暂不支持。  
 **调用形式：**     
- release()  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **示例代码：**   
```ts    
try {  
  this.context.resourceManager.release();  
} catch (error) {  
  console.error("release error is " + error);  
}  
    
```    
  
    
### getRawFileContent<sup>(9+)</sup>    
用户获取resources/rawfile目录下对应的rawfile文件内容。  
 **调用形式：**     
    
- getRawFileContent(path: string, callback: _AsyncCallback\<Uint8Array>): void    
起始版本： 9    
- getRawFileContent(path: string): Promise\<Uint8Array>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | rawfile文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的rawfile文件内容 |  
| Promise<Uint8Array> | rawfile文件内容 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001005 | If the resource not found by path. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getRawFileContent("test.txt", (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let rawFile = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getRawFileContent failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getRawFileContent("test.txt").then((value: Uint8Array) => {  
    let rawFile = value;  
  }).catch((error: BusinessError) => {  
    console.log("getRawFileContent promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getRawFileContent failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getRawFd<sup>(9+)</sup>    
用户获取resources/rawfile目录下对应rawfile文件的descriptor  
 **调用形式：**     
    
- getRawFd(path: string, callback: _AsyncCallback\<RawFileDescriptor>): void    
起始版本： 9    
- getRawFd(path: string): Promise\<RawFileDescriptor>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | rawfile文件路径  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的rawfile文件的descriptor |  
| Promise<RawFileDescriptor> | rawfile文件descriptor |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001005 | If the resource not found by path. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getRawFd("test.txt", (error, value) => {  
    if (error != null) {  
      console.log(`callback getRawFd failed error code: ${error.code}, message: ${error.message}.`);  
    } else {  
      let fd = value.fd;  
      let offset = value.offset;  
      let length = value.length;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getRawFd failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getRawFd("test.txt").then((value: resourceManager.RawFileDescriptor) => {  
    let fd = value.fd;  
    let offset = value.offset;  
    let length = value.length;  
  }).catch((error: BusinessError) => {  
    console.log(`promise getRawFd error error code: ${error.code}, message: ${error.message}.`);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getRawFd failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### closeRawFd<sup>(9+)</sup>    
用户关闭resources/rawfile目录下rawfile文件的descriptor  
 **调用形式：**     
    
- closeRawFd(path: string, callback: _AsyncCallback\<void>): void    
起始版本： 9    
- closeRawFd(path: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | rawfile文件路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调 |  
| Promise<void> | 无返回值 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001005 | The resource not found by path. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.closeRawFd("test.txt", (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback closeRawFd failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.closeRawFd("test.txt");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise closeRawFd failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getDrawableDescriptor<sup>(10+)</sup>    
用户获取指定资源ID对应的DrawableDescriptor对象，使用同步方式返回资源对应的DrawableDescriptor，用于图标的显示。  
 **调用形式：**     
- getDrawableDescriptor(resId: number, density?: number): DrawableDescriptor  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
| density | number | false | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DrawableDescriptor | 资源ID值对应的DrawableDescriptor对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);  
}  
try {  
  this.context.resourceManager.getDrawableDescriptor($r('app.media.icon').id, 120);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getDrawableDescriptorByName<sup>(10+)</sup>    
用户获取指定资源名称对应的DrawableDescriptor对象，使用同步方式返回资源对应的DrawableDescriptor，用于图标的显示。  
 **调用形式：**     
- getDrawableDescriptorByName(resName: string, density?: number): DrawableDescriptor  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称 |  
| density | number | false | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DrawableDescriptor | 资源ID值对应的DrawableDescriptor对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getDrawableDescriptorByName('icon');  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);  
}  
try {  
  this.context.resourceManager.getDrawableDescriptorByName('icon', 120);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getDrawableDescriptorByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getDrawableDescriptor<sup>(10+)</sup>    
用户获取指定resource对应的DrawableDescriptor对象，使用同步方式返回资源对应的DrawableDescriptor，用于图标的显示。  
 **调用形式：**     
- getDrawableDescriptor(resource: Resource, density?: number): DrawableDescriptor  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息 |  
| density | number | false | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DrawableDescriptor | 资源ID值对应的DrawableDescriptor对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
let resource: resourceManager.Resource = {  
bundleName: "com.example.myapplication",  
moduleName: "entry",  
id: $r('app.media.icon').id  
};  
try {  
this.context.resourceManager.getDrawableDescriptor(resource);  
} catch (error) {  
let code = (error as BusinessError).code;  
let message = (error as BusinessError).message;  
console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);  
}  
try {  
this.context.resourceManager.getDrawableDescriptor(resource, 120);  
} catch (error) {  
let code = (error as BusinessError).code;  
let message = (error as BusinessError).message;  
console.error(`getDrawableDescriptor failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getRawFileList<sup>(10+)</sup>    
用户获取resources/rawfile目录下文件夹及文件列表。  
 **调用形式：**     
    
- getRawFileList(path: string, callback: _AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getRawFileList(path: string): Promise\<Array\<string>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | rawfile文件夹路径  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取rawfile文件目录下的文件列表 |  
| Promise<Array<string>> | rawfile文件目录下的文件列表 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001005 | f the resource not found by path. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try { // 传入""表示获取rawfile根目录下的文件列表  
  this.context.resourceManager.getRawFileList("", (error, value) => {  
    if (error != null) {  
      console.error(`callback getRawFileList failed, error code: ${error.code}, message: ${error.message}.`);  
    } else {  
      let rawFile = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getRawFileList failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try { // 传入""表示获取rawfile根目录下的文件列表  
  this.context.resourceManager.getRawFileList("").then((value: Array<string>) => {  
    let rawFile = value;  
  }).catch((error: BusinessError) => {  
    console.error(`promise getRawFileList failed, error code: ${error.code}, message: ${error.message}.`);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getRawFileList failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getColor<sup>(10+)</sup>    
用户获取指定资源ID对应的颜色值。  
 **调用形式：**     
    
- getColor(resId: number, callback: _AsyncCallback\<number>): void    
起始版本： 10    
- getColor(resId: number): Promise\<number>    
起始版本： 10    
- getColor(resource: Resource, callback: _AsyncCallback\<number>): void    
起始版本： 10    
- getColor(resource: Resource): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值     |  
| resource | Resource | true | 资源信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的颜色值（十进制） |  
| Promise<number> | resource对象对应的颜色值（十进制） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getColor($r('app.color.test').id, (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let str = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getColor failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getColor($r('app.color.test').id).then((value: number) => {  
    let str = value;  
  }).catch((error: BusinessError) => {  
    console.log("getColor promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getColor failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getColorByName<sup>(10+)</sup>    
用户获取指定资源名称对应的颜色值。  
 **调用形式：**     
    
- getColorByName(resName: string, callback: _AsyncCallback\<number>): void    
起始版本： 10    
- getColorByName(resName: string): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 异步回调，用于返回获取的颜色值（十进制） |  
| Promise<number> | 资源名称对应的颜色值（十进制） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getColorByName("test", (error, value) => {  
    if (error != null) {  
      console.log("error is " + error);  
    } else {  
      let string = value;  
    }  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`callback getColorByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getColorByName("test").then((value: number) => {  
    let string = value;  
  }).catch((error: BusinessError) => {  
    console.log("getColorByName promise error is " + error);  
  });  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`promise getColorByName failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getColorSync<sup>(10+)</sup>    
用户获取指定资源ID对应的颜色值，使用同步方式返回其对应的颜色值。  
 **调用形式：**     
- getColorSync(resId: number) : number  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 资源ID值对应的颜色值（十进制） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getColorSync($r('app.color.test').id);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getColorSync<sup>(10+)</sup>    
用户获取指定resource对象对应的颜色值，使用同步方式返回其对应的颜色值。  
 **调用形式：**     
- getColorSync(resource: Resource) : number  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | resource对象对应的颜色值（十进制） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
let resource: resourceManager.Resource = {  
  bundleName: "com.example.myapplication",  
  moduleName: "entry",  
  id: $r('app.color.test').id  
};  
try {  
  this.context.resourceManager.getColorSync(resource);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getColorSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getColorByNameSync<sup>(10+)</sup>    
用户获取指定资源名称对应的颜色值，使用同步方式返回其对应的颜色值。  
 **调用形式：**     
- getColorByNameSync(resName: string) : number  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 资源名称对应的颜色值（十进制） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getColorByNameSync("test");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getColorByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### addResource<sup>(10+)</sup>    
应用运行时，加载指定的资源路径，实现资源覆盖。  
 **调用形式：**     
- addResource(path: string) : void  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 资源路径 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001010 | If the overlay path is invalid. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let path = getContext().bundleCodeDir + "/library1-default-signed.hsp";  
try {  
  this.context.resourceManager.addResource(path);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`addResource failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### removeResource<sup>(10+)</sup>    
用户运行时，移除指定的资源路径，还原被覆盖前的资源。  
 **调用形式：**     
- removeResource(path: string) : void  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 资源路径 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001010 | If the overlay path is invalid. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let path = getContext().bundleCodeDir + "/library1-default-signed.hsp";  
try {  
  this.context.resourceManager.removeResource(path);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`removeResource failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getRawFdSync<sup>(10+)</sup>    
用户获取resources/rawfile目录下对应rawfile文件的descriptor。  
 **调用形式：**     
- getRawFdSync(path: string): RawFileDescriptor  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | rawfile文件路径   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| RawFileDescriptor | rawfile文件的descriptor |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001005 | If the resource not found by path. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getRawFdSync("test.txt");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getRawFdSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### closeRawFdSync<sup>(10+)</sup>    
用户关闭resources/rawfile目录下rawfile文件的descriptor。  
 **调用形式：**     
- closeRawFdSync(path: string): void  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true |  rawfile文件路径 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001005 | The resource not found by path. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.closeRawFdSync("test.txt");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`closeRawFd failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getRawFileListSync<sup>(10+)</sup>    
用户获取resources/rawfile目录下文件夹及文件列表，使用同步形式返回文件列表的字符串数组。  
 **调用形式：**     
- getRawFileListSync(path: string): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | rawfile文件夹路径 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | rawfile文件夹下的列表（包含子文件夹和文件） |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001005 | If the resource not found by path. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try { // 传入""表示获取rawfile根目录下的文件列表  
  this.context.resourceManager.getRawFileListSync("")  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getRawFileListSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getRawFileContentSync<sup>(10+)</sup>    
用户获取resources/rawfile目录下对应的rawfile文件内容，使用同步形式返回字节数组。  
 **调用形式：**     
- getRawFileContentSync(path: string): Uint8Array  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | rawfile文件路径       |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 返回获取的rawfile文件内容 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001005 | If the resource not found by path. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getRawFileContentSync("test.txt");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getRawFileContentSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaContentSync<sup>(10+)</sup>    
用户获取指定资源ID对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回字节数组。  
 **调用形式：**     
- getMediaContentSync(resId: number, density?: number): Uint8Array  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
| density | number | false |  资源获取需要的屏幕密度，0或缺省表示默认屏幕密度  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 资源ID对应的媒体文件内容 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaContentSync($r('app.media.test').id); // 默认屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);  
}  
  
try {  
  this.context.resourceManager.getMediaContentSync($r('app.media.test').id, 120); // 指定屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaContentSync<sup>(10+)</sup>    
用户获取指定resource对象对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回字节数组。  
 **调用形式：**     
- getMediaContentSync(resource: Resource, density?: number): Uint8Array  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息 <br/> |  
| density | number | false | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | resource对象对应的媒体文件内容 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaContentSync($r('app.media.test').id); // 默认屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);  
}  
  
try {  
  this.context.resourceManager.getMediaContentSync($r('app.media.test').id, 120); // 指定屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaContentSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaContentBase64Sync<sup>(10+)</sup>    
用户获取指定资源ID对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回字符串。  
 **调用形式：**     
- getMediaContentBase64Sync(resId: number, density?: number): string  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
| density | number | false | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 资源ID对应的图片资源Base64编码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id); // 默认屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);  
}  
  
try {  
  this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id, 120); // 指定屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaContentBase64Sync<sup>(10+)</sup>    
  
  
用户获取指定resource对象对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回字符串。  
 **调用形式：**     
- getMediaContentBase64Sync(resource: Resource, density?: number): string  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息 |  
| density | number | false |  资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | resource对象对应的图片资源Base64编码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id); // 默认屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);  
}  
  
try {  
  this.context.resourceManager.getMediaContentBase64Sync($r('app.media.test').id, 120); // 指定屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaContentBase64Sync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getPluralStringValueSync<sup>(10+)</sup>    
根据指定数量获取指定ID字符串表示的单复数字符串，使用同步方式返回字符串。  
 **调用形式：**     
- getPluralStringValueSync(resId: number, num: number): string  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
| num | number | true | 数量值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 根据指定数量获取指定ID字符串表示的单复数字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getPluralStringValueSync($r('app.plural.test').id, 1);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getPluralStringValueSync<sup>(10+)</sup>    
根据指定数量获取指定resource对象表示的单复数字符串，使用同步方式返回字符串。  
 **调用形式：**     
- getPluralStringValueSync(resource: Resource, num: number): string  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true | 资源信息 |  
| num | number | true | 数量值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 根据指定数量获取指定resource对象表示的单复数字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getPluralStringValueSync($r('app.plural.test').id, 1);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getPluralStringValueSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringArrayValueSync<sup>(10+)</sup>    
用户获取指定资源ID对应的字符串数组，使用同步方式返回字符串数组。  
 **调用形式：**     
- getStringArrayValueSync(resId: number): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resId | number | true | 资源ID值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 资源ID值对应的字符串数组 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getStringArrayValueSync($r('app.strarray.test').id);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringArrayValueSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringArrayValueSync<sup>(10+)</sup>    
用户获取指定resource对象对应的字符串数组，使用同步方式返回字符串数组。  
 **调用形式：**     
- getStringArrayValueSync(resource: Resource): Array\<string>  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resource | Resource | true |  资源信息 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | resource对象对应的字符串数组 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001001 | If the resId invalid. |  
| 9001002 | If the resource not found by resId. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager';  
import { BusinessError } from '@ohos.base';  
  
let resource: resourceManager.Resource = {  
  bundleName: "com.example.myapplication",  
  moduleName: "entry",  
  id: $r('app.strarray.test').id  
};  
try {  
  this.context.resourceManager.getStringArrayValueSync(resource);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringArrayValueSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getPluralStringByNameSync<sup>(10+)</sup>    
根据指定数量获取指定资源名称表示的单复数字符串，使用同步方式返回字符串。  
 **调用形式：**     
- getPluralStringByNameSync(resName: string, num: number): string  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称 |  
| num | number | true | 数量值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 根据指定数量获取指定资源名称表示的单复数字符串 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getPluralStringByNameSync("test", 1);  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getPluralStringByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaByNameSync<sup>(10+)</sup>    
用户获取指定资源名称对应的默认或指定的屏幕密度媒体文件内容，使用同步方式返回字节数组。  
 **调用形式：**     
- getMediaByNameSync(resName: string, density?: number): Uint8Array  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true |  资源名称 |  
| density | number | false | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 对应资源名称的媒体文件内容 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaByNameSync("test"); // 默认屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
  
try {  
  this.context.resourceManager.getMediaByNameSync("test", 120); // 指定屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getMediaBase64ByNameSync<sup>(10+)</sup>    
用户获取指定资源名称对应的默认或指定的屏幕密度图片资源Base64编码，使用同步方式返回字符串。  
 **调用形式：**     
- getMediaBase64ByNameSync(resName: string, density?: number): string  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称 |  
| density | number | false | 资源获取需要的屏幕密度，0或缺省表示默认屏幕密度 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 资源名称对应的图片资源Base64编码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  this.context.resourceManager.getMediaBase64ByNameSync("test"); // 默认屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaBase64ByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
  
try {  
  this.context.resourceManager.getMediaBase64ByNameSync("test", 120); // 指定屏幕密度  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getMediaBase64ByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getStringArrayByNameSync<sup>(10+)</sup>    
用户获取指定资源名称对应的字符串数组，使用同步方式返回字符串数组。  
 **调用形式：**     
- getStringArrayByNameSync(resName: string): Array\<string>  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resName | string | true | 资源名称 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 对应资源名称的字符串数组 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 9001003 | If the resName invalid. |  
| 9001004 | If the resource not found by resName. |  
| 9001006 | If the resource re-ref too much. |  
    
 **示例代码：**   
```ts    
try {  
  this.context.resourceManager.getStringArrayByNameSync("test");  
} catch (error) {  
  let code = (error as BusinessError).code;  
  let message = (error as BusinessError).message;  
  console.error(`getStringArrayByNameSync failed, error code: ${code}, message: ${message}.`);  
}  
    
```    
  
    
### getConfigurationSync<sup>(10+)</sup>    
用户获取设备的Configuration，使用同步形式返回Configuration对象。  
 **调用形式：**     
- getConfigurationSync(): Configuration  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Configuration | 设备的Configuration |  
    
 **示例代码：**   
```ts    
try {  
  let value = this.context.resourceManager.getConfigurationSync();  
  let direction = value.direction;  
  let locale = value.locale;  
} catch (error) {  
  console.error("getConfigurationSync error is " + error);  
}  
    
```    
  
    
### getDeviceCapabilitySync<sup>(10+)</sup>    
用户获取设备的DeviceCapability，使用同步形式返回DeviceCapability对象。  
 **调用形式：**     
- getDeviceCapabilitySync(): DeviceCapability  
  
 **系统能力:**  SystemCapability.Global.ResourceManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DeviceCapability | 设备的DeviceCapability |  
    
 **示例代码：**   
```ts    
try {  
  let value = this.context.resourceManager.getDeviceCapabilitySync();  
  let screenDensity = value.screenDensity;  
  let deviceType = value.deviceType;  
} catch (error) {  
  console.error("getDeviceCapabilitySync error is " + error);  
}  
    
```    
  
