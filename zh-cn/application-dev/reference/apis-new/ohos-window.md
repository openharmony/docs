# @ohos.window    
窗口提供管理窗口的一些基础能力，包括对当前窗口的创建、销毁、各属性设置，以及对各窗口间的管理调度。该模块提供以下窗口相关的常用功能：- [Window](#window)：当前窗口实例，窗口管理器管理的基本单元。- [WindowStage](#windowstage9)：窗口管理器。管理各个基本窗口单元。  
> **说明**   
>本模块首批接口从API version -1开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import window from '@ohos.window'    
```  
    
## WindowType<sup>(7+)</sup>    
窗口类型枚举。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_APP | 0 | 模型约束：本模块接口仅可在FA模型下使用。<br>表示应用子窗口。<br>**模型约束：** 此接口仅可在FA模型下使用。 |  
| TYPE_SYSTEM_ALERT | 1 | 表示系统告警窗口。 |  
| TYPE_FLOAT<sup>(9+)</sup> | 8 | 模型约束：本模块接口仅可在Stage模型下使用。<br>表示悬浮窗。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**需要权限：** ohos.permission.SYSTEM_FLOAT_WINDOW |  
| TYPE_DIALOG<sup>(10+)</sup> | 16 | 模型约束：本模块接口仅可在Stage模型下使用。<br>表示模态窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |  
    
## AvoidAreaType<sup>(7+)</sup>    
窗口内容需要规避区域的类型枚举。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_SYSTEM | 0 | 表示系统默认区域。一般包括状态栏、导航栏，各设备系统定义可能不同。 |  
| TYPE_CUTOUT | 1 | 表示刘海屏区域。 |  
| TYPE_SYSTEM_GESTURE<sup>(9+)</sup> | 2 | 表示手势区域。 |  
| TYPE_KEYBOARD<sup>(9+)</sup> | 3 | 表示软键盘区域。 |  
    
## SystemBarProperties<sup>(6+)</sup>    
状态栏、导航栏的属性。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| statusBarColor<sup>(6+)</sup> | string | false | false | 状态栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。默认值：`#0x66000000`。 |  
| isStatusBarLightIcon<sup>(7+)</sup> | boolean | false | false | 状态栏图标是否为高亮状态。true表示高亮；false表示不高亮。默认值：false。 |  
| statusBarContentColor<sup>(8+)</sup> | string | false | false | 状态栏文字颜色。当设置此属性后， `isStatusBarLightIcon`属性设置无效。默认值：`0xE5FFFFFF。` |  
| navigationBarColor<sup>(6+)</sup> | string | false | false | 导航栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。默认值：`#0x66000000。` |  
| isNavigationBarLightIcon<sup>(7+)</sup> | boolean | false | false | 导航栏图标是否为高亮状态。true表示高亮；false表示不高亮。默认值：false。 |  
| navigationBarContentColor<sup>(8+)</sup> | string | false | false | 导航栏文字颜色。当设置此属性后， `isNavigationBarLightIcon`属性设置无效。默认值：`#0xE5FFFFFF。` |  
    
## Rect<sup>(7+)</sup>    
窗口矩形区域。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left<sup>(7+)</sup> | number | false | true | 矩形区域的左边界，单位为px，该参数为整数。 |  
| left<sup>(10+)</sup> | number | false | true |  |  
| top<sup>(7+)</sup> | number | false | true | 矩形区域的上边界，单位为px，该参数应为整数。 |  
| top<sup>(10+)</sup> | number | false | true |  |  
| width<sup>(7+)</sup> | number | false | true | 矩形区域的宽度，单位为px，该参数应为整数。 |  
| width<sup>(10+)</sup> | number | false | true | 矩形区域的高度，单位为px，该参数应为整数。 |  
| height<sup>(7+)</sup> | number | false | true |  |  
| height<sup>(10+)</sup> | number | false | true |  |  
    
## Rect<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left<sup>(10+)</sup> | number | false | true |  |  
| top<sup>(10+)</sup> | number | false | true |  |  
| width<sup>(10+)</sup> | number | false | true |  |  
| height<sup>(10+)</sup> | number | false | true |  |  
    
## AvoidArea<sup>(7+)</sup>    
窗口内容规避区域。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| visible<sup>(9+)</sup> | boolean | false | true | 规避区域是否可见。true表示可见；false表示不可见。 |  
| leftRect<sup>(7+)</sup> | Rect | false | true | 屏幕左侧的矩形区。 |  
| topRect<sup>(7+)</sup> | Rect | false | true | 屏幕顶部的矩形区。 |  
| rightRect<sup>(7+)</sup> | Rect | false | true | 屏幕右侧的矩形区。 |  
| bottomRect<sup>(7+)</sup> | Rect | false | true | 屏幕底部的矩形区。 |  
    
## Size<sup>(7+)</sup>    
窗口大小。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width<sup>(7+)</sup> | number | false | true | 窗口宽度，单位为px，该参数应为整数。 |  
| width<sup>(10+)</sup> | number | false | true |  |  
| height<sup>(7+)</sup> | number | false | true | 窗口高度，单位为px，该参数应为整数。 |  
| height<sup>(10+)</sup> | number | false | true |  |  
    
## Size<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width<sup>(10+)</sup> | number | false | true |  |  
| height<sup>(10+)</sup> | number | false | true |  |  
    
## WindowProperties<sup>(6+)</sup>    
获取当前窗口的属性，返回WindowProperties。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| windowRect<sup>(7+)</sup> | Rect | false | true | 窗口尺寸。 |  
| windowRect<sup>(10+)</sup> | Rect | false | true |  |  
| type<sup>(7+)</sup> | WindowType | false | true | 窗口类型。 |  
| isFullScreen<sup>(6+)</sup> | boolean | false | true | 是否全屏，默认为false。true表示全屏；false表示非全屏。 |  
| isLayoutFullScreen<sup>(7+)</sup> | boolean | false | true | 窗口是否为沉浸式，默认为false。true表示沉浸式；false表示非沉浸式。 |  
| focusable<sup>(7+)</sup> | boolean | false | true | 窗口是否可聚焦，默认为true。true表示可聚焦；false表示不可聚焦。 |  
| touchable<sup>(7+)</sup> | boolean | false | true | 窗口是否可触摸，默认为true。true表示可触摸；false表示不可触摸。 |  
| brightness<sup>(6+)</sup> | number | false | true | 屏幕亮度。该参数为浮点数，可设置的亮度范围为[0.0, 1.0]，其取1.0时表示最大亮度值。如果窗口没有设置亮度值，表示亮度跟随系统，此时获取到的亮度值为-1。 |  
| brightness<sup>(10+)</sup> | number | false | true |  |  
| dimBehindValue<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>靠后窗口的暗度值。该参数为浮点数，取值范围为[0.0, 1.0]，其取1.0表示最暗。<br>- **说明：** 从API version 9开始废弃。<br>- 从 API version 7开始支持。 |  
| isKeepScreenOn<sup>(6+)</sup> | boolean | false | true | 屏幕是否常亮，默认为false。true表示常亮；false表示不常亮。 |  
| isKeepScreenOn<sup>(10+)</sup> | boolean | false | true |  |  
| isPrivacyMode<sup>(7+)</sup> | boolean | false | true | 隐私模式，默认为false。true表示模式开启；false表示模式关闭。 |  
| isRoundCorner<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>窗口是否为圆角。默认为false。true表示圆角；false表示非圆角。<br>- **说明：** 从API version 9开始废弃。<br/>- 从 API version 7开始支持。 |  
| isTransparent<sup>(7+)</sup> | boolean | false | true | 窗口是否透明。默认为false。true表示透明；false表示不透明。 |  
| id<sup>(9+)</sup> | number | false | true | 窗口ID，默认值为0，该参数应为整数。 |  
    
## WindowProperties<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| windowRect<sup>(10+)</sup> | Rect | false | true |  |  
| brightness<sup>(10+)</sup> | number | false | true |  |  
| isKeepScreenOn<sup>(10+)</sup> | boolean | false | true |  |  
    
## ColorSpace<sup>(8+)</sup>    
色域模式。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT | 0 | 默认SRGB色域模式。 |  
| WIDE_GAMUT | 1 | 广色域模式。 |  
    
## Configuration<sup>(9+)</sup>    
创建子窗口或系统窗口时的参数。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(9+)</sup> | string | false | true | 窗口名字。 |  
| windowType<sup>(9+)</sup> | WindowType | false | true | 窗口类型。 |  
| ctx<sup>(9+)</sup> | BaseContext | false | false | 当前应用上下文信息。不设置，则默认为空。<br>FA模型下不需要使用该参数，即可创建子窗口。<br>Stage模型下需要使用该参数，用于创建系统窗口。 |  
| displayId<sup>(9+)</sup> | number | false | false | 当前物理屏幕id。不设置，则默认为-1，该参数应为整数。 |  
| parentId<sup>(9+)</sup> | number | false | false | 父窗口id。不设置，则默认为-1，该参数应为整数。 |  
    
## createWindow<sup>(9+)</sup>    
创建子窗口或者系统窗口，使用callback异步回调。  
 **调用形式：**     
    
- createWindow(config: Configuration, callback: AsyncCallback\<Window>): void    
起始版本： 9    
- createWindow(config: Configuration): Promise\<Window>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | Configuration | true | 创建窗口时的参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前创建的窗口对象。 |  
| Promise<Window> | Promise对象。返回当前创建的窗口对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 1300001 | Repeated operation. |  
| 1300006 | This window context is abnormal. |  
| 1300008 | The operation is on invalid display. |  
| 1300009 | The parent window is invalid. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
let config: window.Configuration = {  
  name: "alertWindow",  
  windowType: window.WindowType.TYPE_SYSTEM_ALERT  
};  
try {  
  window.createWindow(config, (err: BusinessError, data) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to create the window. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    windowClass = data;  
    console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));  
    windowClass.resetSize(500, 1000);  
  });  
} catch (exception) {  
  console.error('Failed to create the window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
let config: window.Configuration = {  
  name: "alertWindow",  
  windowType: window.WindowType.TYPE_SYSTEM_ALERT  
};  
try {  
  let promise = window.createWindow(config);  
  promise.then((data) => {  
    windowClass = data;  
    console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error('Failed to create the Window. Cause:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to create the window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## create<sup>(deprecated)</sup>    
创建子窗口，使用callback异步回调。  
 **调用形式：**     
- create(id: string, type: WindowType, callback: AsyncCallback\<Window>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#createWindow。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | string | true | 窗口id。 |  
| type<sup>(deprecated)</sup> | WindowType | true | 窗口类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Window> | true | 回调函数。返回当前创建的子窗口对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
window.create('first', window.WindowType.TYPE_APP, (err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  windowClass = data;  
  console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
## create<sup>(deprecated)</sup>    
创建子窗口，使用Promise异步回调。  
 **调用形式：**     
- create(id: string, type: WindowType): Promise\<Window>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#createWindow。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | string | true | 窗口id。 |  
| type<sup>(deprecated)</sup> | WindowType | true | 窗口类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Window> | Promise对象。返回当前创建的子窗口对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
let promise = window.create('first', window.WindowType.TYPE_APP);  
promise.then((data) => {  
  windowClass = data;  
  console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
## create<sup>(deprecated)</sup>    
创建系统窗口，使用callback异步回调。  
 **调用形式：**     
- create(ctx: BaseContext, id: string, type: WindowType): Promise\<Window>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#createWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ctx<sup>(deprecated)</sup> | BaseContext | true | 当前应用上下文信息。 |  
| id<sup>(deprecated)</sup> | string | true | 窗口id。 |  
| type<sup>(deprecated)</sup> | WindowType | true | 窗口类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Window> | Promise对象。返回当前创建的子窗口对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
let promise = window.create('alertWindow', window.WindowType.TYPE_SYSTEM_ALERT);  
promise.then((data) => {  
  windowClass = data;  
  console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to create the Window. Cause:' + JSON.stringify(err));  
});  
    
```    
  
    
## create<sup>(deprecated)</sup>    
创建系统窗口，使用callback异步回调。  
 **调用形式：**     
- create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback\<Window>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#createWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ctx<sup>(deprecated)</sup> | BaseContext | true | 当前应用上下文信息。 |  
| id<sup>(deprecated)</sup> | string | true | 窗口id。 |  
| type<sup>(deprecated)</sup> | WindowType | true | 窗口类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Window> | true | 回调函数。返回当前创建的子窗口对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
window.create('alertWindow', window.WindowType.TYPE_SYSTEM_ALERT, (err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to create the window. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  windowClass = data;  
  console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));  
  windowClass.resetSize(500, 1000);  
});  
    
```    
  
    
## find<sup>(deprecated)</sup>    
查找id所对应的窗口，使用callback异步回调。  
 **调用形式：**     
- find(id: string, callback: AsyncCallback\<Window>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#findWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | string | true | 窗口id。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Window> | true | 回调函数。返回当前查找到的窗口对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
window.find('alertWindow', (err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  windowClass = data;  
  console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
## find<sup>(deprecated)</sup>    
查找id所对应的窗口，使用Promise异步回调。  
 **调用形式：**     
- find(id: string): Promise\<Window>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#findWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | string | true | 窗口id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Window> | Promise对象。返回当前查找的窗口对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
let promise = window.find('alertWindow');  
promise.then((data) => {  
  windowClass = data;  
  console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
## findWindow<sup>(9+)</sup>    
查找name所对应的窗口。  
 **调用形式：**     
- findWindow(name: string): Window  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 窗口id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Window | 当前查找的窗口对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window | undefined = undefined;  
try {  
  windowClass = window.findWindow('alertWindow');  
} catch (exception) {  
  console.error('Failed to find the Window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## findWindow<sup>(10+)</sup>  
 **调用形式：**     
- findWindow(name: string): Window  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Window |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 |  |  
    
## getTopWindow<sup>(deprecated)</sup>    
获取当前应用内最后显示的窗口，使用callback异步回调。  
 **调用形式：**     
- getTopWindow(callback: AsyncCallback\<Window>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#getLastWindow。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Window> | true | 回调函数。返回当前应用内最后显示的窗口对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
window.getTopWindow((err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  windowClass = data;  
  console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
## getTopWindow<sup>(deprecated)</sup>    
获取当前应用内最后显示的窗口，使用Promise异步回调。  
 **调用形式：**     
- getTopWindow(): Promise\<Window>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#getLastWindow。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Window> | Promise对象。返回当前应用内最后显示的窗口对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
let promise = window.getTopWindow();  
promise.then((data)=> {  
    windowClass = data;  
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError)=>{  
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
## getTopWindow<sup>(deprecated)</sup>    
获取当前应用内最后显示的窗口，使用Promise异步回调。  
 **调用形式：**     
- getTopWindow(ctx: BaseContext): Promise\<Window>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#getLastWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ctx<sup>(deprecated)</sup> | BaseContext | true | 当前应用上下文信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Window> | Promise对象。返回当前应用内最后显示的窗口对象。 |  
    
 **示例代码：**   
```ts    
```ts  
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
let promise = window.getTopWindow();  
promise.then((data) => {  
  windowClass = data;  
  console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
## getTopWindow<sup>(deprecated)</sup>    
获取当前应用内最后显示的窗口，使用callback异步回调。  
 **调用形式：**     
- getTopWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window#getLastWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ctx<sup>(deprecated)</sup> | BaseContext | true | 当前应用上下文信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Window> | true | 回调函数。返回当前应用内最后显示的窗口对象。 |  
    
 **示例代码：**   
```ts    
mport { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
let promise = window.getTopWindow();  
promise.then((data) => {  
  windowClass = data;  
  console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
## getLastWindow<sup>(9+)</sup>    
获取当前应用内最后显示的窗口  
 **调用形式：**     
    
- getLastWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void    
起始版本： 9    
- getLastWindow(ctx: BaseContext, callback: AsyncCallback\<Window>): void    
起始版本： 10    
- getLastWindow(ctx: BaseContext): Promise\<Window>    
起始版本： 9    
- getLastWindow(ctx: BaseContext): Promise\<Window>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ctx | BaseContext | true | 当前应用上下文信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前应用内最后显示的窗口对象。 |  
| Promise<Window> | Promise对象。返回当前应用内最后显示的窗口对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300006 | This window context is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
try {  
  class BaseContext {  
      stageMode: boolean = false;  
    }  
    let context: BaseContext = { stageMode: false };  
  window.getLastWindow(context, (err: BusinessError, data) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    windowClass = data;  
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window | undefined = undefined;  
class BaseContext {  
  stageMode: boolean = false;  
}  
let context: BaseContext = { stageMode: false };  
try {  
  let promise = window.getLastWindow(context);  
  promise.then((data) => {  
    windowClass = data;  
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## Orientation<sup>(9+)</sup>    
窗口显示方向类型枚举。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSPECIFIED | 0 | 表示未定义方向模式，由系统判定。 |  
| UNSPECIFIED<sup>(10+)</sup> | 0 |  |  
| PORTRAIT | 1 | 表示竖屏显示模式。 |  
| PORTRAIT<sup>(10+)</sup> | 1 |  |  
| LANDSCAPE | 2 | 表示横屏显示模式。 |  
| LANDSCAPE<sup>(10+)</sup> | 2 |  |  
| PORTRAIT_INVERTED | 3 | 表示反向竖屏显示模式。 |  
| PORTRAIT_INVERTED<sup>(10+)</sup> | 3 |  |  
| LANDSCAPE_INVERTED | 4 | 表示反向横屏显示模式。 |  
| LANDSCAPE_INVERTED<sup>(10+)</sup> | 4 |  |  
| AUTO_ROTATION | 5 | 表示传感器自动旋转模式。 |  
| AUTO_ROTATION_PORTRAIT | 6 |  |  
| AUTO_ROTATION_LANDSCAPE | 7 | 表示传感器自动竖向旋转模式。 |  
| AUTO_ROTATION_RESTRICTED | 8 | 表示受开关控制的自动旋转模式。 |  
| AUTO_ROTATION_PORTRAIT_RESTRICTED | 9 | 表示受开关控制的自动竖向旋转模式。 |  
| AUTO_ROTATION_LANDSCAPE_RESTRICTED | 10 | 表述受开关控制的自动横向旋转模式。 |  
| LOCKED | 11 | 表示锁定模式。 |  
    
## Orientation<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSPECIFIED | 0 |  |  
| PORTRAIT | 1 |  |  
| LANDSCAPE | 2 |  |  
| PORTRAIT_INVERTED | 3 |  |  
| LANDSCAPE_INVERTED | 4 |  |  
    
## WindowEventType<sup>(10+)</sup>    
窗口生命周期。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WINDOW_SHOWN | 1 | 切到前台。 |  
| WINDOW_ACTIVE | 2 | 获焦状态。 |  
| WINDOW_INACTIVE | 3 | 失焦状态。 |  
| WINDOW_HIDDEN | 4 | 切到后台。 |  
    
## Window    
当前窗口实例，窗口管理器管理的基本单元。下列API示例中都需先使用[getLastWindow()](#windowgetlastwindow9)、[createWindow()](#windowcreatewindow9)、[findWindow()](#windowfindwindow9)中的任一方法获取到Window实例，再通过此实例调用对应方法。    
### show<sup>(deprecated)</sup>    
显示当前窗口。<span style="letter-spacing: 0px;">显示当前窗口，使用callback异步回调。</span>  
 **调用形式：**     
- show(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#showWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.show((err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to show the window. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in showing the window.');  
});  
    
```    
  
    
### show<sup>(deprecated)</sup>    
显示当前窗口，使用Promise异步回调。  
 **调用形式：**     
- show(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#showWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.show();  
promise.then(() => {  
  console.info('Succeeded in showing the window.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to show the window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### showWindow<sup>(9+)</sup>    
显示当前窗口。  
 **调用形式：**     
    
- showWindow(callback: AsyncCallback\<void>): void    
起始版本： 9    
- showWindow(callback: AsyncCallback\<void>): void    
起始版本： 10    
- showWindow(): Promise\<void>    
起始版本： 9    
- showWindow(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.showWindow((err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to show the window. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in showing the window.');  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.showWindow();  
promise.then(() => {  
  console.info('Succeeded in showing the window.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to show the window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### destroy<sup>(deprecated)</sup>    
销毁当前窗口，使用callback异步回调。  
 **调用形式：**     
- destroy(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#destroyWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
### destroy<sup>(deprecated)</sup>    
销毁当前窗口，使用Promise异步回调。  
 **调用形式：**     
- destroy(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#destroyWindow。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
### destroyWindow<sup>(9+)</sup>    
销毁当前窗口。  
 **调用形式：**     
    
- destroyWindow(callback: AsyncCallback\<void>): void    
起始版本： 9    
- destroyWindow(callback: AsyncCallback\<void>): void    
起始版本： 10    
- destroyWindow(): Promise\<void>    
起始版本： 9    
- destroyWindow(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.destroyWindow((err) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in destroying the window.');  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.destroyWindow();  
promise.then(() => {  
  console.info('Succeeded in destroying the window.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### moveTo<sup>(deprecated)</sup>    
移动窗口位置，使用Promise异步回调。  
 **调用形式：**     
- moveTo(x: number, y: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#moveWindowTo。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x<sup>(deprecated)</sup> | number | true | 窗口在x轴方向移动的值，值为正表示右移，单位为px，该参数仅支持整数输入。 |  
| y<sup>(deprecated)</sup> | number | true | 窗口在y轴方向移动的值，值为正表示下移，单位为px，该参数仅支持整数输入。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.moveTo(300, 300);  
promise.then(() => {  
  console.info('Succeeded in moving the window.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to move the window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### moveTo<sup>(deprecated)</sup>    
移动窗口位置，使用callback异步回调。  
 **调用形式：**     
- moveTo(x: number, y: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#moveWindowTo。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x<sup>(deprecated)</sup> | number | true | 窗口在x轴方向移动的值，值为正表示右移，单位为px，该参数仅支持整数输入。 |  
| y<sup>(deprecated)</sup> | number | true | 窗口在y轴方向移动的值，值为正表示下移，单位为px，该参数仅支持整数输入。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.moveTo(300, 300, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to move the window. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in moving the window.');  
});  
    
```    
  
    
### moveWindowTo<sup>(9+)</sup>    
移动窗口位置。  
 **调用形式：**     
    
- moveWindowTo(x: number, y: number): Promise\<void>    
起始版本： 9    
- moveWindowTo(x: number, y: number): Promise\<void>    
起始版本： 10    
- moveWindowTo(x: number, y: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- moveWindowTo(x: number, y: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number | true | 窗口在x轴方向移动的值，值为正表示右移，单位为px，该参数仅支持整数输入。 |  
| y | number | true | 窗口在y轴方向移动的值，值为正表示下移，单位为px，该参数仅支持整数输入。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.moveWindowTo(300, 300, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to move the window. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in moving the window.');  
  });  
} catch (exception) {  
  console.error('Failed to move the window. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.moveWindowTo(300, 300);  
  promise.then(() => {  
    console.info('Succeeded in moving the window.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to move the window. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to move the window. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### resetSize<sup>(deprecated)</sup>    
改变当前窗口大小，使用Promise异步回调。  
 **调用形式：**     
- resetSize(width: number, height: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#resize。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| width<sup>(deprecated)</sup> | number | true | 目标窗口的宽度，单位为px，该参数仅支持整数输入。 |  
| height<sup>(deprecated)</sup> | number | true | 目标窗口的高度，单位为px，该参数仅支持整数输入。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.resetSize(500, 1000);  
promise.then(() => {  
  console.info('Succeeded in changing the window size.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to change the window size. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### resetSize<sup>(deprecated)</sup>    
改变当前窗口大小，使用callback异步回调。  
 **调用形式：**     
- resetSize(width: number, height: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#resize。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| width<sup>(deprecated)</sup> | number | true | 目标窗口的宽度，单位为px，该参数仅支持整数输入。 |  
| height<sup>(deprecated)</sup> | number | true | 目标窗口的高度，单位为px，该参数仅支持整数输入。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.resetSize(500, 1000, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to change the window size. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in changing the window size.');  
});  
    
```    
  
    
### resize<sup>(9+)</sup>    
改变当前窗口大小。  
 **调用形式：**     
    
- resize(width: number, height: number): Promise\<void>    
起始版本： 9    
- resize(width: number, height: number): Promise\<void>    
起始版本： 10    
- resize(width: number, height: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- resize(width: number, height: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| width | number | true | 目标窗口的宽度，单位为px，该参数仅支持整数输入。 |  
| height | number | true | 目标窗口的高度，单位为px，该参数仅支持整数输入。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.resize(500, 1000, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to change the window size. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in changing the window size.');  
  });  
} catch (exception) {  
  console.error('Failed to change the window size. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.resize(500, 1000);  
  promise.then(() => {  
    console.info('Succeeded in changing the window size.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to change the window size. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to change the window size. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### getProperties<sup>(deprecated)</sup>    
获取当前窗口的属性，使用callback异步回调，返回WindowProperties。  
 **调用形式：**     
- getProperties(callback: AsyncCallback\<WindowProperties>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#getWindowProperties。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<WindowProperties> | true | 回调函数。返回当前窗口属性。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.getProperties((err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
### getProperties<sup>(deprecated)</sup>    
获取当前窗口的属性，使用Promise异步回调，返回WindowProperties。  
 **调用形式：**     
- getProperties(): Promise\<WindowProperties>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#getWindowProperties。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<WindowProperties> | Promise对象。返回当前窗口属性。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.getProperties();  
promise.then((data) => {  
  console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getWindowProperties<sup>(9+)</sup>    
获取当前窗口的属性，返回WindowProperties。  
 **调用形式：**     
- getWindowProperties(): WindowProperties  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| WindowProperties | 当前窗口属性。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let properties = windowClass.getWindowProperties();  
} catch (exception) {  
  console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### getWindowProperties<sup>(10+)</sup>  
 **调用形式：**     
- getWindowProperties(): WindowProperties  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| WindowProperties |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 |  |  
    
### getAvoidArea<sup>(deprecated)</sup>    
获取窗口内容规避的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与窗口内容重叠时，需要窗口内容避让的区域。  
 **调用形式：**     
- getAvoidArea(type: AvoidAreaType, callback: AsyncCallback\<AvoidArea>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#getWindowAvoidArea。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | AvoidAreaType | true | 表示规避区类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<AvoidArea> | true | 回调函数。返回窗口内容规避区域。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let type = window.AvoidAreaType.TYPE_SYSTEM;  
windowClass.getAvoidArea(type, (err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));  
});  
    
```    
  
    
### getAvoidArea<sup>(deprecated)</sup>    
获取窗口内容规避的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与窗口内容重叠时，需要窗口内容避让的区域。  
 **调用形式：**     
- getAvoidArea(type: AvoidAreaType): Promise\<AvoidArea>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#getWindowAvoidArea。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | AvoidAreaType | true | 表示规避区类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<AvoidArea> | Promise对象。返回窗口内容规避区域。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let type = window.AvoidAreaType.TYPE_SYSTEM;  
let promise = windowClass.getAvoidArea(type);  
promise.then((data) => {  
  console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));  
});  
    
```    
  
    
### getWindowAvoidArea<sup>(9+)</sup>    
获取窗口内容规避的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与窗口内容重叠时，需要窗口内容避让的区域。  
 **调用形式：**     
- getWindowAvoidArea(type: AvoidAreaType): AvoidArea  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | AvoidAreaType | true | 表示规避区类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AvoidArea | 窗口内容规避区域。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
let type = window.AvoidAreaType.TYPE_SYSTEM;  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let avoidArea = windowClass.getWindowAvoidArea(type);  
} catch (exception) {  
  console.error('Failed to obtain the area. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### setFullScreen<sup>(deprecated)</sup>    
设置窗口的布局是否为全屏布局，使用callback异步回调。全屏布局是指窗口大小为全屏幕，状态栏与导航栏不显示。非全屏布局是指状态栏与导航栏显示，窗口大小避让状态栏与导航栏位置。  
 **调用形式：**     
- setFullScreen(isFullScreen: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowSystemBarEnable。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isFullScreen<sup>(deprecated)</sup> | boolean | true | 是否设为全屏布局（该全屏布局影响状态栏导航栏显示）。true表示全屏；false表示非全屏。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isFullScreen: boolean = true;  
windowClass.setFullScreen(isFullScreen, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in enabling the full-screen mode.');  
});  
    
```    
  
    
### setFullScreen<sup>(deprecated)</sup>    
设置窗口的布局是否为全屏布局，使用Promise异步回调。全屏布局是指窗口大小为全屏幕，状态栏与导航栏不显示。非全屏布局是指状态栏与导航栏显示，窗口大小避让状态栏与导航栏位置。  
 **调用形式：**     
- setFullScreen(isFullScreen: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowSystemBarEnable。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isFullScreen<sup>(deprecated)</sup> | boolean | true | 是否设为全屏布局（该全屏布局影响状态栏导航栏显示）。true表示全屏；false表示非全屏。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isFullScreen: boolean = true;  
let promise = windowClass.setFullScreen(isFullScreen);  
promise.then(() => {  
  console.info('Succeeded in enabling the full-screen mode.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setLayoutFullScreen<sup>(deprecated)</sup>    
设置窗口的布局是否为沉浸式布局，使用callback异步回调。沉浸式布局是指布局不避让状态栏与导航栏，组件可能产生与其重叠的情况。非沉浸式布局是指布局避让状态栏与导航栏，组件不会与其重叠。  
 **调用形式：**     
- setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowLayoutFullScreen。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isLayoutFullScreen<sup>(deprecated)</sup> | boolean | true | 窗口的布局是否为沉浸式布局（该沉浸式布局不影响状态栏、导航栏显示）。true表示沉浸式布局；false表示非沉浸式布局。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isLayoutFullScreen: boolean = true;  
windowClass.setLayoutFullScreen(isLayoutFullScreen, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the window layout to full-screen mode.');  
});  
    
```    
  
    
### setLayoutFullScreen<sup>(deprecated)</sup>    
设置窗口的布局是否为沉浸式布局，使用Promise异步回调。沉浸式布局是指布局不避让状态栏与导航栏，组件可能产生与其重叠的情况。非沉浸式布局是指布局避让状态栏与导航栏，组件不会与其重叠。  
 **调用形式：**     
- setLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowLayoutFullScreen。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isLayoutFullScreen<sup>(deprecated)</sup> | boolean | true | 窗口的布局是否为沉浸式布局（该沉浸式布局不影响状态栏、导航栏显示）。true表示沉浸式布局；false表示非沉浸式布局。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isLayoutFullScreen: boolean = true;  
let promise = windowClass.setLayoutFullScreen(isLayoutFullScreen);  
promise.then(() => {  
  console.info('Succeeded in setting the window layout to full-screen mode.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));  
});  
    
```    
  
    
### setWindowLayoutFullScreen<sup>(9+)</sup>    
设置窗口的布局是否为沉浸式布局。  
 **调用形式：**     
    
- setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isLayoutFullScreen | boolean | true | 窗口的布局是否为沉浸式布局（该沉浸式布局状态栏、导航栏仍然显示）。true表示沉浸式布局；false表示非沉浸式布局。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isLayoutFullScreen = true;  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.setWindowLayoutFullScreen(isLayoutFullScreen, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the window layout to full-screen mode.');  
  });  
} catch (exception) {  
  console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isLayoutFullScreen = true;  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.setWindowLayoutFullScreen(isLayoutFullScreen);  
  promise.then(() => {  
    console.info('Succeeded in setting the window layout to full-screen mode.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### setSystemBarEnable<sup>(deprecated)</sup>    
设置窗口全屏模式时导航栏、状态栏的可见模式，使用callback异步回调。  
 **调用形式：**     
- setSystemBarEnable(names: Array\<'status' | 'navigation'>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowSystemBarEnable。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| names<sup>(deprecated)</sup> | Array<'status' \| 'navigation'> | true | 设置窗口全屏模式时状态栏和导航栏是否显示。<br>例如，需全部显示，该参数设置为['status','navigation']；不设置，则默认不显示。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let names: Array<'status' | 'navigation'> = [];  
windowClass.setSystemBarEnable(names, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the system bar to be invisible.');  
});  
    
```    
  
    
### setSystemBarEnable<sup>(deprecated)</sup>    
设置窗口全屏模式时导航栏、状态栏的可见模式，使用Promise异步回调。  
 **调用形式：**     
- setSystemBarEnable(names: Array\<'status' | 'navigation'>): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowSystemBarEnable。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| names<sup>(deprecated)</sup> | Array<'status' \| 'navigation'> | true | 设置窗口全屏模式时状态栏和导航栏是否显示。<br>例如，需全部显示，该参数设置为['status','navigation']；不设置，则默认不显示。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
// 此处以不显示导航栏、状态栏为例  
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let names: Array<'status' | 'navigation'> = [];  
let promise = windowClass.setSystemBarEnable(names);  
promise.then(() => {  
  console.info('Succeeded in setting the system bar to be invisible.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));  
});  
    
```    
  
    
### setWindowSystemBarEnable<sup>(9+)</sup>    
设置窗口全屏模式时导航栏、状态栏的可见模式。  
 **调用形式：**     
    
- setWindowSystemBarEnable(names: Array\<'status' | 'navigation'>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setWindowSystemBarEnable(names: Array\<'status' | 'navigation'>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setWindowSystemBarEnable(names: Array\<'status' | 'navigation'>): Promise\<void>    
起始版本： 9    
- setWindowSystemBarEnable(names: Array\<'status' | 'navigation'>): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| names | Array<'status' \| 'navigation'> | true | 设置窗口全屏模式时状态栏和导航栏是否显示。<br>例如，需全部显示，该参数设置为['status','navigation']；不设置，则默认不显示。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
// 此处以不显示导航栏、状态栏为例  
import { BusinessError } from '@ohos.base';  
  
let names: Array<'status' | 'navigation'> = [];  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.setWindowSystemBarEnable(names, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the system bar to be invisible.');  
  });  
} catch (exception) {  
  console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
// 此处以不显示导航栏、状态栏为例  
import { BusinessError } from '@ohos.base';  
  
let names: Array<'status' | 'navigation'> = [];  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.setWindowSystemBarEnable(names);  
  promise.then(() => {  
    console.info('Succeeded in setting the system bar to be invisible.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### setSystemBarProperties<sup>(deprecated)</sup>    
设置窗口全屏模式时窗口内导航栏、状态栏的属性，使用callback异步回调。  
 **调用形式：**     
- setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowSystemBarProperties。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| systemBarProperties<sup>(deprecated)</sup> | SystemBarProperties | true | 导航栏、状态栏的属性。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let SystemBarProperties: window.SystemBarProperties = {  
  statusBarColor: '#ff00ff',  
  navigationBarColor: '#00ff00',  
  //以下两个属性从API Version8开始支持  
  statusBarContentColor: '#ffffff',  
  navigationBarContentColor: '#00ffff'  
};  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.setWindowSystemBarProperties(SystemBarProperties, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the system bar properties.');  
  });  
} catch (exception) {  
  console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setSystemBarProperties<sup>(deprecated)</sup>    
设置窗口全屏模式时窗口内导航栏、状态栏的属性，使用Promise异步回调。  
 **调用形式：**     
- setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowSystemBarProperties。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| systemBarProperties<sup>(deprecated)</sup> | SystemBarProperties | true | 导航栏、状态栏的属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let SystemBarProperties: window.SystemBarProperties = {  
  statusBarColor: '#ff00ff',  
  navigationBarColor: '#00ff00',  
  //以下两个属性从API Version8开始支持  
  statusBarContentColor: '#ffffff',  
  navigationBarContentColor: '#00ffff'  
};  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.setWindowSystemBarProperties(SystemBarProperties);  
  promise.then(() => {  
    console.info('Succeeded in setting the system bar properties.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setWindowSystemBarProperties<sup>(9+)</sup>    
设置窗口全屏模式时窗口内导航栏、状态栏的属性。  
 **调用形式：**     
    
- setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| systemBarProperties | SystemBarProperties | true | 导航栏、状态栏的属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let SystemBarProperties: window.SystemBarProperties = {  
  statusBarColor: '#ff00ff',  
  navigationBarColor: '#00ff00',  
  //以下两个属性从API Version8开始支持  
  statusBarContentColor: '#ffffff',  
  navigationBarContentColor: '#00ffff'  
};  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.setWindowSystemBarProperties(SystemBarProperties, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the system bar properties.');  
  });  
} catch (exception) {  
  console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let SystemBarProperties: window.SystemBarProperties = {  
  statusBarColor: '#ff00ff',  
  navigationBarColor: '#00ff00',  
  //以下两个属性从API Version8开始支持  
  statusBarContentColor: '#ffffff',  
  navigationBarContentColor: '#00ffff'  
};  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.setWindowSystemBarProperties(SystemBarProperties);  
  promise.then(() => {  
    console.info('Succeeded in setting the system bar properties.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setPreferredOrientation<sup>(9+)</sup>    
设置窗口的显示方向属性。  
 **调用形式：**     
    
- setPreferredOrientation(orientation: Orientation): Promise\<void>    
起始版本： 9    
- setPreferredOrientation(orientation: Orientation): Promise\<void>    
起始版本： 10    
- setPreferredOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setPreferredOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| orientation | Orientation | true | 窗口显示方向的属性。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let orientation = window.Orientation.AUTO_ROTATION;  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.setPreferredOrientation(orientation, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set window orientation. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting window orientation.');  
  });  
} catch (exception) {  
  console.error('Failed to set window orientation. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let orientation = window.Orientation.AUTO_ROTATION;  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.setPreferredOrientation(orientation);  
  promise.then(() => {  
    console.info('Succeeded in setting the window orientation.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the window orientation. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set window orientation. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### loadContent<sup>(9+)</sup>    
为当前窗口加载与LocalStorage相关联的具体页面内容。  
 **调用形式：**     
    
- loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 9    
- loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 10    
- loadContent(path: string, storage: LocalStorage): Promise\<void>    
起始版本： 9    
- loadContent(path: string, storage: LocalStorage): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 设置加载页面的路径。 |  
| storage | LocalStorage | true | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window = window.findWindow("test");  
    let storage: LocalStorage = new LocalStorage();  
    storage.setOrCreate('storageSimpleProp', 121);  
    try {  
      if (!windowClass) {  
        console.info('Failed to load the content. Cause: windowClass is null');  
      }  
      else {  
        (windowClass as window.Window).loadContent('pages/page2', storage, (err: BusinessError) => {  
          const errCode: number = err.code;  
          if (errCode) {  
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
            return;  
          }  
          console.info('Succeeded in loading the content.');  
        });  
      }  
    } catch (exception) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window = window.findWindow("test");  
    let storage: LocalStorage = new LocalStorage();  
    storage.setOrCreate('storageSimpleProp', 121);  
    try {  
      if (!windowClass) {  
        console.info('Failed to load the content. Cause: windowClass is null');  
      }  
      else {  
        let promise = (windowClass as window.Window).loadContent('pages/page2', storage);  
        promise.then(() => {  
          console.info('Succeeded in loading the content.');  
        }).catch((err: BusinessError) => {  
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
        });  
      }  
    } catch (exception) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
    
### loadContent<sup>(deprecated)</sup>  
 **调用形式：**     
- loadContent(path: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setUIContent。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  |  
    
### loadContent<sup>(deprecated)</sup>  
 **调用形式：**     
- loadContent(path: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setUIContent。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path<sup>(deprecated)</sup> | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
### getUIContext<sup>(10+)</sup>    
获取UIContext实例。  
 **调用形式：**     
- getUIContext() : UIContext  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| UIContext | 返回UIContext实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
import { UIContext } from '@ohos.arkui.UIContext';  
  
export default class EntryAbility extends UIAbility {  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    // 为主窗口加载对应的目标页面。  
    windowStage.loadContent("pages/page2", (err: BusinessError) => {  
      let errCode: number = err.code;  
      if (errCode) {  
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
        return;  
      }  
      console.info('Succeeded in loading the content.');  
      // 获取应用主窗口。  
      let windowClass: window.Window = window.findWindow("test");  
      windowStage.getMainWindow((err: BusinessError, data) => {  
        let errCode: number = err.code;  
        if (errCode) {  
          console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
          return;  
        }  
        windowClass = data;  
        console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
        // 获取UIContext实例。  
        let uiContext: UIContext | null = null;  
        uiContext = windowClass.getUIContext();  
      })  
    });  
  }  
};  
    
```    
  
    
### setUIContent<sup>(9+)</sup>    
为当前窗口加载具体页面内容。  
 **调用形式：**     
    
- setUIContent(path: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setUIContent(path: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setUIContent(path: string): Promise\<void>    
起始版本： 9    
- setUIContent(path: string): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 设置加载页面的路径。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.setUIContent('pages/page2/page2', (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in loading the content.');  
  });  
} catch (exception) {  
  console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.setUIContent('pages/page2/page2');  
  promise.then(() => {  
    console.info('Succeeded in loading the content.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to load the content. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to load the content. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### loadContentByName<sup>(11+)</sup>    
为当前窗口加载与LocalStorage相关联的[命名路由](../../ui/arkts-routing.md#命名路由)页面。  
 **调用形式：**     
    
- loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 11    
- loadContentByName(name: string, callback: AsyncCallback\<void>): void    
起始版本： 11    
- loadContentByName(name: string, storage?: LocalStorage): Promise\<void>    
起始版本： 11  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 命名路由页面的名称。 |  
| storage | LocalStorage | true | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
// ets/entryability/EntryAbility.ets  
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
import * as Index from '../pages/Index'; // 导入命名路由页面  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口  
    let storage: LocalStorage = new LocalStorage();  
    storage.setOrCreate('storageSimpleProp', 121);  
    try {  
      if (!windowClass) {  
        console.info('Failed to load the content. Cause: windowClass is null');  
      } else {  
        (windowClass as window.Window).loadContentByName(Index.entryName, storage, (err: BusinessError) => {  
          const errCode: number = err.code;  
          if (errCode) {  
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
            return;  
          }  
          console.info('Succeeded in loading the content.');  
        });  
      }  
    } catch (exception) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
    }  
  }  
};  
  
// ets/pages/Index.ets  
export const entryName : string = 'Index';  
@Entry({routeName: entryName, storage : LocalStorage.getShared()})  
@Component  
export struct Index {  
  @State message: string = 'Hello World'  
  build() {  
    Row() {  
      Column() {  
        Text(this.message)  
          .fontSize(50)  
          .fontWeight(FontWeight.Bold)  
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
// ets/entryability/EntryAbility.ets  
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
import * as Index from '../pages/Index'; // 导入命名路由页面  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口  
    try {  
      if (!windowClass) {  
        console.info('Failed to load the content. Cause: windowClass is null');  
      } else {  
        (windowClass as window.Window).loadContentByName(Index.entryName, (err: BusinessError) => {  
          const errCode: number = err.code;  
          if (errCode) {  
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
            return;  
          }  
          console.info('Succeeded in loading the content.');  
        });  
      }  
    } catch (exception) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
    }  
  }  
};  
  
// ets/pages/Index.ets  
export const entryName : string = 'Index';  
@Entry({routeName: entryName})  
@Component  
export struct Index {  
  @State message: string = 'Hello World'  
  build() {  
    Row() {  
      Column() {  
        Text(this.message)  
          .fontSize(50)  
          .fontWeight(FontWeight.Bold)  
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
    
```    
  
    
### isShowing<sup>(deprecated)</sup>    
判断当前窗口是否已显示，使用callback异步回调。  
 **调用形式：**     
- isShowing(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#isWindowShowing。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示当前窗口已显示，返回false表示当前窗口未显示。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.isShowing((err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to check whether the window is showing. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
### isShowing<sup>(deprecated)</sup>    
判断当前窗口是否已显示，使用Promise异步回调。  
 **调用形式：**     
- isShowing(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#isWindowShowing。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示当前窗口已显示，返回false表示当前窗口未显示。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.isShowing();  
promise.then((data) => {  
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to check whether the window is showing. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### isWindowShowing<sup>(9+)</sup>    
判断当前窗口是否已显示。  
 **调用形式：**     
- isWindowShowing(): boolean  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 当前窗口是否已显示。true表示当前窗口已显示，false则表示当前窗口未显示。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let data = windowClass.isWindowShowing();  
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));  
} catch (exception) {  
  console.error('Failed to check whether the window is showing. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### isWindowShowing<sup>(10+)</sup>  
 **调用形式：**     
- isWindowShowing(): boolean  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.on('windowSizeChange', (data) => {  
    console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to enable the listener for window size changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### on('windowSizeChange')<sup>(7+)</sup>    
开启窗口尺寸变化的监听。  
 **调用形式：**     
    
- on(type: 'windowSizeChange', callback: Callback\<Size>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'windowSizeChange'，即窗口尺寸变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的窗口尺寸。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.on('windowSizeChange', (data) => {  
    console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to enable the listener for window size changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### off('windowSizeChange')<sup>(7+)</sup>    
关闭窗口尺寸变化的监听。  
 **调用形式：**     
    
- off(type: 'windowSizeChange', callback?: Callback\<Size>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'windowSizeChange'，即窗口尺寸变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的窗口尺寸。如果传入参数，则关闭该监听。如果未传入参数，则关闭窗口尺寸变化的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.off('windowSizeChange');  
} catch (exception) {  
  console.error('Failed to disable the listener for window size changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### on('systemAvoidAreaChange')<sup>(deprecated)</sup>    
开启系统规避区变化的监听。  
 **调用形式：**     
- on(type: 'systemAvoidAreaChange', callback: Callback\<AvoidArea>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#on_avoidAreaChange。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 监听事件，固定为'systemAvoidAreaChange'，即系统规避区变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<AvoidArea> | true | 回调函数。返回当前规避区。 |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");windowClass.on('systemAvoidAreaChange', (data) => {  console.info('Succeeded in enabling the listener for system avoid area changes. Data: ' + JSON.stringify(data));});    
```    
  
    
### off('systemAvoidAreaChange')<sup>(deprecated)</sup>    
关闭系统规避区变化的监听。  
 **调用形式：**     
- off(type: 'systemAvoidAreaChange', callback?: Callback\<AvoidArea>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#off_avoidAreaChange。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 监听事件，固定为'systemAvoidAreaChange'，即系统规避区变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<AvoidArea> | false | 回调函数。返回当前规避区。若传入参数，则关闭该监听。若未传入参数，则关闭所有系统规避区变化的监听。 |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");windowClass.off('systemAvoidAreaChange');    
```    
  
    
### on('avoidAreaChange')<sup>(9+)</sup>    
开启系统规避区变化的监听。  
 **调用形式：**     
    
- on(type: 'avoidAreaChange', callback: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'avoidAreaChange'，即系统规避区变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前规避区以及规避区类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.on('avoidAreaChange', (data) => {  
    console.info('Succeeded in enabling the listener for system avoid area changes. type:' +  
    JSON.stringify(data.type) + ', area: ' + JSON.stringify(data.area));  
  });  
} catch (exception) {  
  console.error('Failed to enable the listener for system avoid area changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### off('avoidAreaChange')<sup>(9+)</sup>    
关闭系统规避区变化的监听。  
 **调用形式：**     
    
- off(type: 'avoidAreaChange', callback?: Callback\<{ type: AvoidAreaType, area: AvoidArea }>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'avoidAreaChange'，即系统规避区变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前规避区以及规避区类型。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有系统规避区变化的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.off('avoidAreaChange');  
} catch (exception) {  
  console.error('Failed to disable the listener for system avoid area changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### on('keyboardHeightChange')<sup>(7+)</sup>    
开启固定态输入法窗口软键盘高度变化的监听。从API version 10开始，改变输入法窗口为固定态或者悬浮态方法详细介绍请参见[输入法服务](js-apis-inputmethodengine.md#changeflag10)。  
 **调用形式：**     
    
- on(type: 'keyboardHeightChange', callback: Callback\<number>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'keyboardHeightChange'，即键盘高度变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的键盘高度，返回值为整数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.on('keyboardHeightChange', (data) => {  
    console.info('Succeeded in enabling the listener for keyboard height changes. Data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to enable the listener for keyboard height changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### off('keyboardHeightChange')<sup>(7+)</sup>    
关闭固定态输入法窗口软键盘高度变化的监听。从API version 10开始，改变输入法窗口为固定态或者悬浮态方法详细介绍请参见[输入法服务](js-apis-inputmethodengine.md#changeflag10)。  
 **调用形式：**     
    
- off(type: 'keyboardHeightChange', callback?: Callback\<number>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'keyboardHeightChange'，即键盘高度变化事件 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的键盘高度，返回值为整数。若传入参数，则关闭该监听。如果未传入参数，则关闭所有固定态输入法窗口软键盘高度变化的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.off('keyboardHeightChange');  
} catch (exception) {  
  console.error('Failed to disable the listener for keyboard height changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### on('touchOutside')<sup>(11+)</sup>    
开启本窗口区域范围外的点击事件的监听。  
 **调用形式：**     
    
- on(type: 'touchOutside', callback: Callback\<void>): void    
起始版本： 11  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'touchOutside'，即本窗口范围外的点击事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当点击事件发生在本窗口范围之外的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.on('touchOutside', () => {  
    console.info('touch outside');  
  });  
} catch (exception) {  
  console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### off('touchOutside')<sup>(11+)</sup>    
关闭本窗口区域范围外的点击事件的监听。  
 **调用形式：**     
    
- off(type: 'touchOutside', callback?: Callback\<void>): void    
起始版本： 11  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'touchOutside'，即本窗口范围外的点击事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当点击事件发生在本窗口范围之外的回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口区域范围外的点击事件的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.off('touchOutside');  
} catch (exception) {  
  console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### on('screenshot')<sup>(9+)</sup>    
开启截屏事件的监听。  
 **调用形式：**     
    
- on(type: 'screenshot', callback: Callback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'screenshot'，即截屏事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。发生截屏事件时的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.on('screenshot', () => {  
    console.info('screenshot happened');  
  });  
} catch (exception) {  
  console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### off('screenshot')<sup>(9+)</sup>    
关闭截屏事件的监听。  
 **调用形式：**     
    
- off(type: 'screenshot', callback?: Callback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'screenshot'，即截屏事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。发生截屏事件时的回调。若传入参数，则关闭该监听。若未传入参数，则关闭所有截屏事件的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
let callback = () => {  
  console.info('screenshot happened');  
};  
try {  
  windowClass.on('screenshot', callback);  
} catch (exception) {  
  console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));  
}  
try {  
  windowClass.off('screenshot', callback);  
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：  
  windowClass.off('screenshot');  
} catch (exception) {  
  console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### on('dialogTargetTouch')<sup>(10+)</sup>    
开启模态窗口目标窗口的点击事件的监听。  
 **调用形式：**     
    
- on(type: 'dialogTargetTouch', callback: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'dialogTargetTouch'，即模态窗口目标窗口的点击事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当点击事件发生在模态窗口目标窗口的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.on('dialogTargetTouch', () => {  
    console.info('touch dialog target');  
  });  
} catch (exception) {  
  console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### off('dialogTargetTouch')<sup>(10+)</sup>    
关闭模态窗口目标窗口的点击事件的监听。  
 **调用形式：**     
    
- off(type: 'dialogTargetTouch', callback?: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'dialogTargetTouch'，即模态窗口目标窗口的点击事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当点击事件发生在模态窗口目标窗口的回调。若传入参数，则关闭该监听。若未传入参数，则关闭所有模态窗口目标窗口的点击事件的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
et windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.off('dialogTargetTouch');  
} catch (exception) {  
  console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### on('windowEvent')<sup>(10+)</sup>    
开启窗口生命周期变化的监听。  
 **调用形式：**     
    
- on(type: 'windowEvent', callback: Callback\<WindowEventType>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'windowEvent'，即窗口生命周期变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的窗口生命周期状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.on('windowEvent', (data) => {  
    console.info('Window event happened. Event:' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### off('windowEvent')<sup>(10+)</sup>    
关闭窗口生命周期变化的监听。  
 **调用形式：**     
    
- off(type: 'windowEvent', callback?: Callback\<WindowEventType>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'windowEvent'，即窗口生命周期变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的窗口生命周期状态。若传入参数，则关闭该监听。若未传入参数，则关闭所有窗口生命周期变化的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.off('windowEvent');  
} catch (exception) {  
  console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### isSupportWideGamut<sup>(deprecated)</sup>    
判断当前窗口是否支持广色域模式，使用Promise异步回调。  
 **调用形式：**     
- isSupportWideGamut(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#isWindowSupportWideGamut。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示当前窗口支持广色域模式，返回false表示当前窗口不支持广色域模式。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.isSupportWideGamut();  
promise.then((data) => {  
  console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to check whether the window support WideGamut. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### isSupportWideGamut<sup>(deprecated)</sup>    
判断当前窗口是否支持广色域模式，使用callback异步回调。  
 **调用形式：**     
- isSupportWideGamut(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#isWindowSupportWideGamut。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示当前窗口支持广色域模式，返回false表示当前窗口不支持广色域模式。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.isSupportWideGamut((err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to check whether the window support WideGamut. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in checking whether the window support WideGamut Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
### isWindowSupportWideGamut<sup>(9+)</sup>    
判断当前窗口是否支持广色域模式。  
 **调用形式：**     
    
- isWindowSupportWideGamut(): Promise\<boolean>    
起始版本： 9    
- isWindowSupportWideGamut(callback: AsyncCallback\<boolean>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示当前窗口支持广色域模式，返回false表示当前窗口不支持广色域模式。 |  
| Promise<boolean> | Promise对象。返回true表示当前窗口支持广色域模式，返回false表示当前窗口不支持广色域模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.isWindowSupportWideGamut((err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to check whether the window support WideGamut. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in checking whether the window support WideGamut Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.isWindowSupportWideGamut();  
promise.then((data) => {  
  console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to check whether the window support WideGamut. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setColorSpace<sup>(deprecated)</sup>    
设置当前窗口为广色域模式或默认色域模式，使用Promise异步回调。  
 **调用形式：**     
- setColorSpace(colorSpace: ColorSpace): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowColorSpace。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| colorSpace<sup>(deprecated)</sup> | ColorSpace | true | 设置色域模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT);  
promise.then(() => {  
  console.info('Succeeded in setting window colorspace.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set window colorspace. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setColorSpace<sup>(deprecated)</sup>    
设置当前窗口为广色域模式或默认色域模式，使用callback异步回调。  
 **调用形式：**     
- setColorSpace(colorSpace: ColorSpace, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowColorSpace。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| colorSpace<sup>(deprecated)</sup> | ColorSpace | true | 设置色域模式。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set window colorspace. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting window colorspace.');  
});  
    
```    
  
    
### setWindowColorSpace<sup>(9+)</sup>    
设置当前窗口为广色域模式或默认色域模式。  
 **调用形式：**     
    
- setWindowColorSpace(colorSpace: ColorSpace): Promise\<void>    
起始版本： 9    
- setWindowColorSpace(colorSpace: ColorSpace, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| colorSpace | ColorSpace | true | 设置色域模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWindowColorSpace(window.ColorSpace.WIDE_GAMUT, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set window colorspace. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting window colorspace.');  
  });  
} catch (exception) {  
  console.error('Failed to set window colorspace. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let promise = windowClass.setWindowColorSpace(window.ColorSpace.WIDE_GAMUT);  
  promise.then(() => {  
    console.info('Succeeded in setting window colorspace.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set window colorspace. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set window colorspace. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### getColorSpace<sup>(deprecated)</sup>    
获取当前窗口色域模式，使用Promise异步回调。  
 **调用形式：**     
- getColorSpace(): Promise\<ColorSpace>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#getWindowColorSpace。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<ColorSpace> | Promise对象。返回当前色域模式。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.getColorSpace();  
promise.then((data) => {  
  console.info('Succeeded in getting window color space. Cause:' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.error('Failed to get window colorspace. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getColorSpace<sup>(deprecated)</sup>    
获取当前窗口色域模式，使用callback异步回调。  
 **调用形式：**     
- getColorSpace(callback: AsyncCallback\<ColorSpace>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#getWindowColorSpace。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<ColorSpace> | true | 回调函数。当获取成功，err为undefined，data为当前色域模式。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.getColorSpace((err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to get window colorspace. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in getting window colorspace. Cause:' + JSON.stringify(data));  
});  
    
```    
  
    
### getWindowColorSpace<sup>(9+)</sup>    
获取当前窗口色域模式。  
 **调用形式：**     
- getWindowColorSpace(): ColorSpace  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ColorSpace | 当前色域模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
let color: string = '#00ff33';  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWindowBackgroundColor(color);  
} catch (exception) {  
  console.error('Failed to set the background color. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setBackgroundColor<sup>(deprecated)</sup>    
设置窗口的背景色，使用Promise异步回调。Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。  
 **调用形式：**     
- setBackgroundColor(color: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowBackgroundColor。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| color<sup>(deprecated)</sup> | string | true | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let color: string = '#00ff33';  
let promise = windowClass.setBackgroundColor(color);  
promise.then(() => {  
  console.info('Succeeded in setting the background color.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setBackgroundColor<sup>(deprecated)</sup>    
设置窗口的背景色，使用callback异步回调。Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。  
 **调用形式：**     
- setBackgroundColor(color: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowBackgroundColor。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| color<sup>(deprecated)</sup> | string | true | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let color: string = '#00ff33';  
windowClass.setBackgroundColor(color, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the background color.');  
});  
    
```    
  
    
### setWindowBackgroundColor<sup>(9+)</sup>    
设置窗口的背景色。Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。  
 **调用形式：**     
- setWindowBackgroundColor(color: string): void  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| color | string | true | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
let color: string = '#00ff33';  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWindowBackgroundColor(color);  
} catch (exception) {  
  console.error('Failed to set the background color. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setWindowBackgroundColor<sup>(10+)</sup>  
 **调用形式：**     
- setWindowBackgroundColor(color: string): void  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| color | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 |  |  
    
### setBrightness<sup>(deprecated)</sup>    
设置屏幕亮度值，使用Promise异步回调。  
 **调用形式：**     
- setBrightness(brightness: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowBrightness。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| brightness<sup>(deprecated)</sup> | number | true | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let brightness: number = 1;  
let promise = windowClass.setBrightness(brightness);  
promise.then(() => {  
  console.info('Succeeded in setting the brightness.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setBrightness<sup>(deprecated)</sup>    
设置屏幕亮度值，使用callback异步回调。  
 **调用形式：**     
- setBrightness(brightness: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowBrightness。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| brightness<sup>(deprecated)</sup> | number | true | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let brightness: number = 1;  
windowClass.setBrightness(brightness, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the brightness.');  
});  
    
```    
  
    
### setWindowBrightness<sup>(9+)</sup>    
设置屏幕亮度值。  
 **调用形式：**     
    
- setWindowBrightness(brightness: number): Promise\<void>    
起始版本： 9    
- setWindowBrightness(brightness: number): Promise\<void>    
起始版本： 10    
- setWindowBrightness(brightness: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setWindowBrightness(brightness: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| brightness | number | true | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let brightness: number = 1;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWindowBrightness(brightness, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the brightness.');  
  });  
} catch (exception) {  
  console.error('Failed to set the brightness. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let brightness: number = 1;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let promise = windowClass.setWindowBrightness(brightness);  
  promise.then(() => {  
    console.info('Succeeded in setting the brightness.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the brightness. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setDimBehind<sup>(deprecated)</sup>    
窗口叠加时，设备有子窗口的情况下设置靠后的窗口的暗度值，使用callback异步回调。  
 **调用形式：**     
- setDimBehind(dimBehindValue: number, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dimBehindValue<sup>(deprecated)</sup> | number | true | 表示靠后的窗口的暗度值，取值范围为[0.0, 1.0]，取1.0时表示最暗。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.setDimBehind(0.5, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the dimness.');  
});  
    
```    
  
    
### setDimBehind<sup>(deprecated)</sup>    
窗口叠加时，设备有子窗口的情况下设置靠后的窗口的暗度值，使用Promise异步回调。  
 **调用形式：**     
- setDimBehind(dimBehindValue: number): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dimBehindValue<sup>(deprecated)</sup> | number | true | 表示靠后的窗口的暗度值，取值范围为[0.0, 1.0]，取1.0时表示最暗。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.setDimBehind(0.5);  
promise.then(() => {  
  console.info('Succeeded in setting the dimness.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setFocusable<sup>(deprecated)</sup>    
设置点击时是否支持切换焦点窗口，使用Promise异步回调。  
 **调用形式：**     
- setFocusable(isFocusable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowFocusable。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isFocusable<sup>(deprecated)</sup> | boolean | true | 点击时是否支持切换焦点窗口。true表示支持；false表示不支持。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isFocusable: boolean = true;  
let promise = windowClass.setFocusable(isFocusable);  
promise.then(() => {  
  console.info('Succeeded in setting the window to be focusable.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the window to be focusable. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setFocusable<sup>(deprecated)</sup>    
设置点击时是否支持切换焦点窗口，使用callback异步回调。  
 **调用形式：**     
- setFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowFocusable。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isFocusable<sup>(deprecated)</sup> | boolean | true | 点击时是否支持切换焦点窗口。true表示支持；false表示不支持。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
<span style="font-size: 14px; letter-spacing: 0px;">import { BusinessError } from '@ohos.base';</span>  
  
let windowClass: window.Window = window.findWindow("test");  
let isFocusable: boolean = true;  
windowClass.setFocusable(isFocusable, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the window to be focusable.');  
});    
```    
  
    
### setWindowFocusable<sup>(9+)</sup>    
设置点击时是否支持切换焦点窗口。  
 **调用形式：**     
    
- setWindowFocusable(isFocusable: boolean): Promise\<void>    
起始版本： 9    
- setWindowFocusable(isFocusable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isFocusable | boolean | true | 点击时是否支持切换焦点窗口。true表示支持；false表示不支持。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isFocusable: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWindowFocusable(isFocusable, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the window to be focusable.');  
  });  
} catch (exception) {  
  console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isFocusable: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let promise = windowClass.setWindowFocusable(isFocusable);  
  promise.then(() => {  
    console.info('Succeeded in setting the window to be focusable.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the window to be focusable. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### setKeepScreenOn<sup>(deprecated)</sup>    
设置屏幕是否为常亮状态，使用Promise异步回调。  
 **调用形式：**     
- setKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowKeepScreenOn。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isKeepScreenOn<sup>(deprecated)</sup> | boolean | true | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isKeepScreenOn: boolean = true;  
let promise = windowClass.setKeepScreenOn(isKeepScreenOn);  
promise.then(() => {  
  console.info('Succeeded in setting the screen to be always on.');  
}).catch((err: BusinessError) => {  
  console.info('Failed to set the screen to be always on. Cause:  ' + JSON.stringify(err));  
});  
    
```    
  
    
### setKeepScreenOn<sup>(deprecated)</sup>    
设置屏幕是否为常亮状态，使用callback异步回调。  
 **调用形式：**     
- setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowKeepScreenOn。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isKeepScreenOn<sup>(deprecated)</sup> | boolean | true | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isKeepScreenOn: boolean = true;  
windowClass.setKeepScreenOn(isKeepScreenOn, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the screen to be always on.');  
});  
    
```    
  
    
### setWindowKeepScreenOn<sup>(9+)</sup>    
设置屏幕是否为常亮状态。  
 **调用形式：**     
    
- setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>    
起始版本： 9    
- setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>    
起始版本： 10    
- setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isKeepScreenOn | boolean | true | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isKeepScreenOn: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWindowKeepScreenOn(isKeepScreenOn, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the screen to be always on.');  
  });  
} catch (exception) {  
  console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isKeepScreenOn: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let promise = windowClass.setWindowKeepScreenOn(isKeepScreenOn);  
  promise.then(() => {  
    console.info('Succeeded in setting the screen to be always on.');  
  }).catch((err: BusinessError) => {  
    console.info('Failed to set the screen to be always on. Cause:  ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setOutsideTouchable<sup>(deprecated)</sup>    
设置是否允许可点击子窗口之外的区域，使用Promise异步回调。。  
 **调用形式：**     
- setOutsideTouchable(touchable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| touchable<sup>(deprecated)</sup> | boolean | true | 设置是否可点击。true表示可点击；false表示不可点击。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (!windowClass) {  
  console.info('Failed to load the content. Cause: windowClass is null');  
}  
else {  
  (windowClass as window.Window).setOutsideTouchable(true, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the area to be touchable.');  
  });  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
if (!windowClass) {  
  console.info('Failed to load the content. Cause: windowClass is null');  
}  
else {  
let promise = (windowClass as window.Window).setOutsideTouchable(true);  
promise.then(() => {  
  console.info('Succeeded in setting the area to be touchable.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));  
});  
}  
    
```    
  
    
### setOutsideTouchable<sup>(deprecated)</sup>    
设置是否允许可点击子窗口之外的区域，使用callback异步回调。  
 **调用形式：**     
- setOutsideTouchable(touchable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| touchable<sup>(deprecated)</sup> | boolean | true | 设置是否可点击。true表示可点击；false表示不可点击。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
### setPrivacyMode<sup>(deprecated)</sup>    
设置窗口是否为隐私模式，使用Promise异步回调。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。此接口可用于禁止截屏/录屏的场景。  
 **调用形式：**     
- setPrivacyMode(isPrivacyMode: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowPrivacyMode。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isPrivacyMode<sup>(deprecated)</sup> | boolean | true | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isPrivacyMode: boolean = true;  
windowClass.setPrivacyMode(isPrivacyMode, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the window to privacy mode.');  
});  
    
```    
  
    
### setPrivacyMode<sup>(deprecated)</sup>    
。  
 **调用形式：**     
- setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowPrivacyMode。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isPrivacyMode<sup>(deprecated)</sup> | boolean | true | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let isPrivacyMode: boolean = true;  
let promise = windowClass.setPrivacyMode(isPrivacyMode);  
promise.then(() => {  
  console.info('Succeeded in setting the window to privacy mode.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the window to privacy mode. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setWindowPrivacyMode<sup>(9+)</sup>    
设置窗口是否为隐私模式。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。此接口可用于禁止截屏/录屏的场景。  
 **调用形式：**     
    
- setWindowPrivacyMode(isPrivacyMode: boolean): Promise\<void>    
起始版本： 9    
- setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core  
 **需要权限：** ohos.permission.PRIVACY_WINDOW    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isPrivacyMode | boolean | true | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isPrivacyMode: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWindowPrivacyMode(isPrivacyMode, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the window to privacy mode.');  
  });  
} catch (exception) {  
  console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isPrivacyMode: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let promise = windowClass.setWindowPrivacyMode(isPrivacyMode);  
  promise.then(() => {  
    console.info('Succeeded in setting the window to privacy mode.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the window to privacy mode. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### setTouchable<sup>(deprecated)</sup>    
设置窗口是否为可触状态，使用Promise异步回调。  
 **调用形式：**     
- setTouchable(isTouchable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowTouchable。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isTouchable<sup>(deprecated)</sup> | boolean | true | 窗口是否为可触状态。true表示可触；false表示不可触。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
例(callback):  
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isTouchable = true;  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.setTouchable(isTouchable);  
promise.then(() => {  
  console.info('Succeeded in setting the window to be touchable.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the window to be touchable. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setTouchable<sup>(deprecated)</sup>    
设置窗口是否为可触状态，使用callback异步回调。  
 **调用形式：**     
- setTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window.Window#setWindowTouchable。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isTouchable<sup>(deprecated)</sup> | boolean | true | 窗口是否为可触状态。true表示可触；false表示不可触。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let isTouchable = true;  
if (!windowClass) {  
  console.info('Failed to load the content. Cause: windowClass is null');  
}  
else {  
  (windowClass as window.Window).setTouchable(isTouchable, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the window to be touchable.');  
  });  
}  
    
```    
  
    
### setWindowTouchable<sup>(9+)</sup>    
设置窗口是否为可触状态。  
 **调用形式：**     
    
- setWindowTouchable(isTouchable: boolean): Promise\<void>    
起始版本： 9    
- setWindowTouchable(isTouchable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isTouchable | boolean | true | 窗口是否为可触状态。true表示可触；false表示不可触。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isTouchable = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWindowTouchable(isTouchable, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the window to be touchable.');  
  });  
} catch (exception) {  
  console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isTouchable: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let promise = windowClass.setWindowTouchable(isTouchable);  
  promise.then(() => {  
    console.info('Succeeded in setting the window to be touchable.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the window to be touchable. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### snapshot<sup>(9+)</sup>    
获取窗口截图。  
 **调用形式：**     
    
- snapshot(callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 9    
- snapshot(): Promise\<image.PixelMap>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<image.PixelMap> | Promise对象。返回当前窗口截图。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.snapshot((err: BusinessError, pixelMap: image.PixelMap) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to snapshot window. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());  
  pixelMap.release(); // PixelMap使用完后及时释放内存  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
import image from '@ohos.multimedia.image';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.snapshot();  
promise.then((pixelMap: image.PixelMap) => {  
  console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());  
  pixelMap.release(); // PixelMap使用完后及时释放内存  
}).catch((err: BusinessError) => {  
  console.error('Failed to snapshot window. Cause:' + JSON.stringify(err));  
});  
    
```    
  
    
### setAspectRatio<sup>(10+)</sup>    
设置窗口内容布局的比例。  
 **调用形式：**     
    
- setAspectRatio(ratio: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setAspectRatio(ratio: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ratio | number | true | 除边框装饰之外的窗口内容布局的宽高比。该参数为浮点数，取值范围为(0.0, +∞)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let ratio = 1.0;  
  let promise = windowClass.setAspectRatio(ratio);  
  promise.then(() => {  
    console.info('Succeeded in setting aspect ratio of window.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the aspect ratio of window. Cause:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the aspect ratio of window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let ratio = 1.0;  
  windowClass.setAspectRatio(ratio, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the aspect ratio of window. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the aspect ratio of window.');  
  });  
} catch (exception) {  
  console.error('Failed to set the aspect ratio of window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### resetAspectRatio<sup>(10+)</sup>    
取消设置窗口内容布局的比例。  
 **调用形式：**     
    
- resetAspectRatio(callback: AsyncCallback\<void>): void    
起始版本： 10    
- resetAspectRatio(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let promise = windowClass.resetAspectRatio();  
  promise.then(() => {  
    console.info('Succeeded in resetting aspect ratio of window.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to reset the aspect ratio of window. Cause:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to reset the aspect ratio of window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
try {  
    windowClass.resetAspectRatio((err: BusinessError) => {  
        const errCode: number = err.code;  
        if (errCode) {  
            console.error('Failed to reset the aspect ratio of window. Cause:' + JSON.stringify(err));  
            return;  
        }  
        console.info('Succeeded in resetting aspect ratio of window.');  
    });  
} catch (exception) {  
    console.error('Failed to reset the aspect ratio of window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## WindowStageEventType<sup>(9+)</sup>    
WindowStage生命周期。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SHOWN | 1 | 切到前台。 |  
| SHOWN<sup>(10+)</sup> | 1 |  |  
| ACTIVE | 2 | 获焦状态。 |  
| ACTIVE<sup>(10+)</sup> | 2 |  |  
| INACTIVE | 3 | 失焦状态。 |  
| INACTIVE<sup>(10+)</sup> | 3 |  |  
| HIDDEN | 4 | 切到后台。 |  
| HIDDEN<sup>(10+)</sup> | 4 |  |  
| RESUMED<sup>(11+)</sup> | 5 | 前台可交互状态。前台应用进入多任务为不可交互状态，继续返回前台时恢复可交互状态。 |  
| PAUSED<sup>(11+)</sup> | 6 | 前台不可交互状态。前台应用进入多任务为不可交互状态，继续返回前台时恢复可交互状态。 |  
    
## WindowStageEventType<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SHOWN | 1 |  |  
| ACTIVE | 2 |  |  
| INACTIVE | 3 |  |  
| HIDDEN | 4 |  |  
| RESUMED<sup>(11+)</sup> | 5 |  |  
| PAUSED<sup>(11+)</sup> | 6 |  |  
    
## WindowStage<sup>(9+)</sup>    
窗口管理器。管理各个基本窗口单元，即[Window](#window)实例。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### getMainWindow<sup>(9+)</sup>    
获取该WindowStage实例下的主窗口。  
 **调用形式：**     
    
- getMainWindow(): Promise\<Window>    
起始版本： 9    
- getMainWindow(): Promise\<Window>    
起始版本： 10    
- getMainWindow(callback: AsyncCallback\<Window>): void    
起始版本： 9    
- getMainWindow(callback: AsyncCallback\<Window>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前WindowStage下的主窗口对象。 |  
| Promise<Window> | Promise对象。返回当前WindowStage下的主窗口对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
| 1300005 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window | undefined = undefined;  
    windowStage.getMainWindow((err: BusinessError, data) => {  
      const errCode: number = err.code;  
      if (errCode) {  
        console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
        return;  
      }  
      windowClass = data;  
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
    });  
  }  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window | undefined = undefined;  
    let promise = windowStage.getMainWindow();  
    promise.then((data) => {  
      windowClass = data;  
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
      console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
    });  
  }  
};  
    
```    
  
    
### getMainWindowSync<sup>(9+)</sup>    
获取该WindowStage实例下的主窗口。  
 **调用形式：**     
- getMainWindowSync(): Window  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Window | 返回当前WindowStage下的主窗口对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
| 1300005 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    try {  
      let windowClass = windowStage.getMainWindowSync();  
    } catch (exception) {  
      console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
    
### getMainWindowSync<sup>(10+)</sup>  
 **调用形式：**     
- getMainWindowSync(): Window  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Window |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 |  |  
| 1300005 |  |  
    
### createSubWindow<sup>(9+)</sup>    
创建该WindowStage实例下的子窗口。  
 **调用形式：**     
    
- createSubWindow(name: string): Promise\<Window>    
起始版本： 9    
- createSubWindow(name: string): Promise\<Window>    
起始版本： 10    
- createSubWindow(name: string, callback: AsyncCallback\<Window>): void    
起始版本： 9    
- createSubWindow(name: string, callback: AsyncCallback\<Window>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 子窗口的名字。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前WindowStage下的子窗口对象。 |  
| Promise<Window> | Promise对象。返回当前WindowStage下的子窗口对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300005 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window | undefined = undefined;  
    try {  
      windowStage.createSubWindow('mySubWindow', (err: BusinessError, data) => {  
        const errCode: number = err.code;  
        if (errCode) {  
          console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));  
          return;  
        }  
        windowClass = data;  
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));  
        if (!windowClass) {  
          console.info('Failed to load the content. Cause: windowClass is null');  
        }  
        else {  
          (windowClass as window.Window).resetSize(500, 1000);  
        }  
      });  
  
    } catch (exception) {  
      console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window | undefined = undefined;  
    try {  
      let promise = windowStage.createSubWindow('mySubWindow');  
      promise.then((data) => {  
        windowClass = data;  
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));  
      }).catch((err: BusinessError) => {  
        console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));  
      });  
    } catch (exception) {  
      console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
    
### getSubWindow<sup>(9+)</sup>    
获取该WindowStage实例下的所有子窗口。  
 **调用形式：**     
    
- getSubWindow(): Promise\<Array\<Window>>    
起始版本： 9    
- getSubWindow(): Promise\<Array\<Window>>    
起始版本： 10    
- getSubWindow(callback: AsyncCallback\<Array\<Window>>): void    
起始版本： 9    
- getSubWindow(callback: AsyncCallback\<Array\<Window>>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前WindowStage下的所有子窗口对象。 |  
| Promise<Array<Window>> | Promise对象。返回当前WindowStage下的所有子窗口对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300005 | This window stage is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window[] = [];  
    windowStage.getSubWindow((err: BusinessError, data) => {  
      const errCode: number = err.code;  
      if (errCode) {  
        console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));  
        return;  
      }  
      windowClass = data;  
      console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));  
    });  
  }  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    let windowClass: window.Window[] = [];  
    let promise = windowStage.getSubWindow();  
    promise.then((data) => {  
      windowClass = data;  
      console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));  
    }).catch((err: BusinessError) => {  
      console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));  
    })  
  }  
};  
    
```    
  
    
### loadContent<sup>(9+)</sup>    
为当前WindowStage的主窗口加载与LocalStorage相关联的具体页面内容。  
 **调用形式：**     
    
- loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 9    
- loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 10    
- loadContent(path: string, storage?: LocalStorage): Promise\<void>    
起始版本： 9    
- loadContent(path: string, storage?: LocalStorage): Promise\<void>    
起始版本： 10    
- loadContent(path: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- loadContent(path: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 设置加载页面的路径。 |  
| storage | LocalStorage | true | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300005 | This window state is abnormal. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  storage: LocalStorage = new LocalStorage();  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    this.storage.setOrCreate('storageSimpleProp', 121);  
    console.log('onWindowStageCreate');  
    try {  
      windowStage.loadContent('pages/page2', this.storage, (err: BusinessError) => {  
        const errCode: number = err.code;  
        if (errCode) {  
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
          return;  
        }  
        console.info('Succeeded in loading the content.');  
      });  
    } catch (exception) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  storage: LocalStorage = new LocalStorage();  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    this.storage.setOrCreate('storageSimpleProp', 121);  
    console.log('onWindowStageCreate');  
    try {  
      let promise = windowStage.loadContent('pages/page2', this.storage);  
      promise.then(() => {  
        console.info('Succeeded in loading the content.');  
      }).catch((err: BusinessError) => {  
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
      });  
    } catch (exception) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
    }  
    ;  
  }  
};  
    
```    
  
    
### loadContentByName<sup>(11+)</sup>    
为当前WindowStage加载与LocalStorage相关联的[命名路由](../../ui/arkts-routing.md#命名路由)页面。  
 **调用形式：**     
    
- loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 11    
- loadContentByName(name: string, callback: AsyncCallback\<void>): void    
起始版本： 11    
- loadContentByName(name: string, storage?: LocalStorage): Promise\<void>    
起始版本： 11  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 命名路由页面的名称。 |  
| storage | LocalStorage | true | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
// ets/entryability/EntryAbility.ets  
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
import * as Index from '../pages/Index'; // 导入命名路由页面  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  storage: LocalStorage = new LocalStorage();  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    this.storage.setOrCreate('storageSimpleProp', 121);  
    try {  
      windowStage.loadContentByName(Index.entryName, this.storage, (err: BusinessError) => {  
        const errCode: number = err.code;  
        if (errCode) {  
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
          return;  
        }  
        console.info('Succeeded in loading the content.');  
      });  
    } catch (exception) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
    }  
  }  
};  
  
// ets/pages/Index.ets  
export const entryName : string = 'Index';  
@Entry({routeName: entryName, storage : LocalStorage.getShared()})  
@Component  
export struct Index {  
  @State message: string = 'Hello World'  
  build() {  
    Row() {  
      Column() {  
        Text(this.message)  
          .fontSize(50)  
          .fontWeight(FontWeight.Bold)  
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
// ets/entryability/EntryAbility.ets  
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
import { BusinessError } from '@ohos.base';  
import * as Index from '../pages/Index'; // 导入命名路由页面  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    try {  
      windowStage.loadContentByName(Index.entryName, (err: BusinessError) => {  
        const errCode: number = err.code;  
        if (errCode) {  
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
          return;  
        }  
        console.info('Succeeded in loading the content.');  
      });  
    } catch (exception) {  
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));  
    }  
  }  
};  
  
// ets/pages/Index.ets  
export const entryName : string = 'Index';  
@Entry({routeName: entryName})  
@Component  
export struct Index {  
  @State message: string = 'Hello World'  
  build() {  
    Row() {  
      Column() {  
        Text(this.message)  
          .fontSize(50)  
          .fontWeight(FontWeight.Bold)  
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
    
```    
  
    
### on('windowStageEvent')<sup>(9+)</sup>    
开启WindowStage生命周期变化的监听。  
 **调用形式：**     
    
- on(eventType: 'windowStageEvent', callback: Callback\<WindowStageEventType>): void    
起始版本： 9    
- on(eventType: 'windowStageEvent', callback: Callback\<WindowStageEventType>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventType | string | true | 监听事件，固定为'windowStageEvent'，即WindowStage生命周期变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的WindowStage生命周期状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300005 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    try {  
      windowStage.on('windowStageEvent', (data) => {  
        console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +  
        JSON.stringify(data));  
      });  
    } catch (exception) {  
      console.error('Failed to enable the listener for window stage event changes. Cause:' +  
      JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
    
### off('windowStageEvent')<sup>(9+)</sup>    
关闭WindowStage生命周期变化的监听。  
 **调用形式：**     
    
- off(eventType: 'windowStageEvent', callback?: Callback\<WindowStageEventType>): void    
起始版本： 9    
- off(eventType: 'windowStageEvent', callback?: Callback\<WindowStageEventType>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventType | string | true | 监听事件，固定为'windowStageEvent'，即WindowStage生命周期变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的WindowStage生命周期状态。若传入参数，则关闭该监听。若未传入参数，则关闭所有WindowStage生命周期变化的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300005 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
  
export default class EntryAbility extends UIAbility {  
  // ...  
  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    console.log('onWindowStageCreate');  
    try {  
      windowStage.off('windowStageEvent');  
    } catch (exception) {  
      console.error('Failed to disable the listener for window stage event changes. Cause:' +  
      JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
    
## WindowStage<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### getMainWindow<sup>(10+)</sup>  
 **调用形式：**     
    
- getMainWindow(): Promise\<Window>    
起始版本： 10    
- getMainWindow(callback: AsyncCallback\<Window>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Window> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 |  |  
| 1300005 |  |  
    
### getMainWindowSync<sup>(10+)</sup>  
 **调用形式：**     
- getMainWindowSync(): Window  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Window |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 |  |  
| 1300005 |  |  
    
### createSubWindow<sup>(10+)</sup>  
 **调用形式：**     
    
- createSubWindow(name: string): Promise\<Window>    
起始版本： 10    
- createSubWindow(name: string, callback: AsyncCallback\<Window>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Window> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 |  |  
| 1300005 |  |  
    
### getSubWindow<sup>(10+)</sup>  
 **调用形式：**     
    
- getSubWindow(): Promise\<Array\<Window>>    
起始版本： 10    
- getSubWindow(callback: AsyncCallback\<Array\<Window>>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<Window>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300005 |  |  
    
### loadContent<sup>(10+)</sup>  
 **调用形式：**     
    
- loadContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 10    
- loadContent(path: string, storage?: LocalStorage): Promise\<void>    
起始版本： 10    
- loadContent(path: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true |  |  
| storage | LocalStorage | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 |  |  
| 1300005 |  |  
    
### loadContentByName<sup>(11+)</sup>  
 **调用形式：**     
    
- loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 11    
- loadContentByName(name: string, callback: AsyncCallback\<void>): void    
起始版本： 11    
- loadContentByName(name: string, storage?: LocalStorage): Promise\<void>    
起始版本： 11  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true |  |  
| storage | LocalStorage | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 |  |  
| 1300003 |  |  
    
### on('windowStageEvent')<sup>(10+)</sup>  
 **调用形式：**     
    
- on(eventType: 'windowStageEvent', callback: Callback\<WindowStageEventType>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventType | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 |  |  
| 1300005 |  |  
    
### off('windowStageEvent')<sup>(10+)</sup>  
 **调用形式：**     
    
- off(eventType: 'windowStageEvent', callback?: Callback\<WindowStageEventType>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventType | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 |  |  
| 1300005 |  |  
