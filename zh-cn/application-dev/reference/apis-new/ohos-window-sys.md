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
 **系统接口：** 此接口为系统接口。    
    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_INPUT_METHOD<sup>(9+)</sup> | 2 | 表示输入法窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_STATUS_BAR<sup>(9+)</sup> | 3 | 表示状态栏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_PANEL<sup>(9+)</sup> | 4 | 表示通知栏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_KEYGUARD<sup>(9+)</sup> | 5 | 表示锁屏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_VOLUME_OVERLAY<sup>(9+)</sup> | 6 | 表示音量条。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_NAVIGATION_BAR<sup>(9+)</sup> | 7 | 表示导航栏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_WALLPAPER<sup>(9+)</sup> | 9 | 表示壁纸。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_DESKTOP<sup>(9+)</sup> | 10 | 表示桌面。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_LAUNCHER_RECENT<sup>(9+)</sup> | 11 | 表示多任务中心。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_LAUNCHER_DOCK<sup>(9+)</sup> | 12 | 表示桌面Dock栏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_VOICE_INTERACTION<sup>(9+)</sup> | 13 | 表示智慧语音。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_POINTER<sup>(9+)</sup> | 14 | 表示鼠标。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_FLOAT_CAMERA<sup>(9+)</sup> | 15 | 表示相机类型悬浮窗。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_SCREENSHOT<sup>(9+)</sup> | 17 | 表示截屏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
| TYPE_SYSTEM_TOAST<sup>(11+)</sup> | 18 | 表示顶层提示窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |  
    
## WindowMode<sup>(7+)</sup>    
窗口模式枚举。    
## WindowLayoutMode<sup>(9+)</sup>    
窗口布局模式枚举。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WINDOW_LAYOUT_MODE_CASCADE | 0 | 表示使用层叠布局模式。 |  
| WINDOW_LAYOUT_MODE_TILE | 1 | 表示使用平铺布局模式。 |  
    
## SystemBarRegionTint<sup>(8+)</sup>    
单个导航栏或状态栏回调信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(8+)</sup> | WindowType | false | true | 当前属性改变的系统栏类型，仅支持类型为导航栏、状态栏的系统栏。 |  
| isEnable<sup>(8+)</sup> | boolean | false | false | 当前系统栏是否显示。true表示显示；false表示不显示。 |  
| region<sup>(8+)</sup> | Rect | false | false | 当前系统栏的位置及大小。 |  
| backgroundColor<sup>(8+)</sup> | string | false | false | 系统栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |  
| contentColor<sup>(8+)</sup> | string | false | false | 系统栏文字颜色。 |  
    
## SystemBarTintState<sup>(8+)</sup>    
当前系统栏回调信息集合。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| displayId<sup>(8+)</sup> | number | false | true | 当前物理屏幕id，该参数应为整数。 |  
| regionTint<sup>(8+)</sup> | Array<SystemBarRegionTint> | false | true | 当前已改变的所有系统栏信息。 |  
    
## ScaleOptions<sup>(9+)</sup>    
缩放参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x<sup>(9+)</sup> | number | false | false | X轴的缩放参数。该参数为浮点数，默认值为1.0。 |  
| y<sup>(9+)</sup> | number | false | false | Y轴的缩放参数。该参数为浮点数，默认值为1.0。  |  
| pivotX<sup>(9+)</sup> | number | false | false | 缩放中心点X轴坐标。该参数为浮点数，默认值为0.5， 取值范围[0.0, 1.0]。 |  
| pivotY<sup>(9+)</sup> | number | false | false | 缩放中心点Y轴坐标。该参数为浮点数，默认值为0.5， 取值范围[0.0, 1.0]。 |  
    
## RotateOptions<sup>(9+)</sup>    
旋转参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x<sup>(9+)</sup> | number | false | false | 绕X轴的旋转角度。该参数为浮点数，默认值为0.0。 |  
| y<sup>(9+)</sup> | number | false | false | 绕Y轴的旋转角度。该参数为浮点数，默认值为0.0。 |  
| z<sup>(9+)</sup> | number | false | false | 绕Z轴的旋转角度。该参数为浮点数，默认值为0.0。 |  
| pivotX<sup>(9+)</sup> | number | false | false | 旋转中心点X轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。 |  
| pivotY<sup>(9+)</sup> | number | false | false | 旋转中心点Y轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。 |  
    
## TranslateOptions<sup>(9+)</sup>    
平移参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x<sup>(9+)</sup> | number | false | false | X轴的平移参数。该参数为浮点数，默认值为0.0。 |  
| y<sup>(9+)</sup> | number | false | false | Y轴的平移参数。该参数为浮点数，默认值为0.0 |  
| z<sup>(9+)</sup> | number | false | false | Z轴的平移参数。该参数为浮点数，默认值为0.0。 |  
    
## TransitionContext<sup>(9+)</sup>    
属性转换的上下文信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| toWindow<sup>(9+)</sup> | Window | false | true | 动画的目标窗口。 |  
    
### completeTransition<sup>(9+)</sup>    
设置属性转换的最终完成状态。该函数需要在动画函数[animateTo()](../arkui-ts/ts-explicit-animation.md)执行后设置。  
 **调用形式：**     
- completeTransition(isCompleted: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isCompleted | boolean | true | 窗口属性转换是否完成。true表示完成本次转换；false表示撤销本次转换。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window | undefined = undefined;  
(context: window.TransitionContext) => {  
  let toWindow: window.Window = context.toWindow;  
  animateTo({  
    duration: 1000, // 动画时长  
    tempo: 0.5, // 播放速率  
    curve: Curve.EaseInOut, // 动画曲线  
    delay: 0, // 动画延迟  
    iterations: 1, // 播放次数  
    playMode: PlayMode.Normal, // 动画模式  
  }, () => {  
    let obj: window.TranslateOptions = {  
      x: 100.0,  
      y: 0.0,  
      z: 0.0  
    };  
    toWindow.translate(obj);  
    console.info('toWindow translate end');  
  }  
  );  
  try {  
    context.completeTransition(true)  
  } catch (exception) {  
    console.info('toWindow translate fail. Cause: ' + JSON.stringify(exception));  
  }  
  console.info('complete transition end');  
};  
    
```    
  
    
## TransitionController<sup>(9+)</sup>    
属性转换控制器。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### animationForShown<sup>(9+)</sup>    
窗口显示时的自定义动画配置。  
 **调用形式：**     
- animationForShown(context: TransitionContext): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | TransitionContext | true | 属性转换时的上下文。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window | undefined = undefined;(context : window.TransitionContext) => {  let toWindow: window.Window = context.toWindow;  animateTo({    duration: 1000, // 动画时长    tempo: 0.5, // 播放速率    curve: Curve.EaseInOut, // 动画曲线    delay: 0, // 动画延迟    iterations: 1, // 播放次数    playMode: PlayMode.Normal, // 动画模式    onFinish: ()=> {      context.completeTransition(true)    }  }, () => {    let obj : window.TranslateOptions = {      x : 100.0,      y : 0.0,      z : 0.0    };    toWindow.translate(obj);    console.info('toWindow translate end');  }  );  console.info('complete transition end');};    
```    
  
    
### animationForHidden<sup>(9+)</sup>  
 **调用形式：**     
- animationForHidden(context: TransitionContext): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| context | TransitionContext | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window | undefined = undefined;(context: window.TransitionContext) => {  let toWindow: window.Window = context.toWindow;  animateTo({    duration: 1000, // 动画时长    tempo: 0.5, // 播放速率    curve: Curve.EaseInOut, // 动画曲线    delay: 0, // 动画延迟    iterations: 1, // 播放次数    playMode: PlayMode.Normal, // 动画模式    onFinish: () => {      context.completeTransition(true)    }  }, () => {    let obj: window.TranslateOptions = {      x: 100.0,      y: 0.0,      z: 0.0    };    toWindow.translate(obj);    console.info('toWindow translate end');  }  )  console.info('complete transition end');};    
```    
  
    
## minimizeAll<sup>(9+)</sup>    
最小化某显示设备下的所有窗口。  
 **调用形式：**     
    
- minimizeAll(id: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- minimizeAll(id: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | number | true | 显示设备[Display](js-apis-display.md#display)的ID号，该参数仅支持整数输入。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import display from '@ohos.display'  
import { BusinessError } from '@ohos.base';  
  
let displayClass: display.Display | null = null;  
try {  
  displayClass = display.getDefaultDisplaySync();  
  
  try {  
    window.minimizeAll(displayClass.id, (err: BusinessError) => {  
      const errCode: number = err.code;  
      if (errCode) {  
        console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('Succeeded in minimizing all windows.');  
    });  
  } catch (exception) {  
    console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(exception));  
  }  
} catch (exception) {  
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import display from '@ohos.display'  
import { BusinessError } from '@ohos.base';  
  
let displayClass: display.Display | null = null;  
try {  
  displayClass = display.getDefaultDisplaySync();  
  
  try {  
    let promise = window.minimizeAll(displayClass.id);  
    promise.then(() => {  
      console.info('Succeeded in minimizing all windows.');  
    }).catch((err: BusinessError) => {  
      console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(err));  
    });  
  } catch (exception) {  
    console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(exception));  
  }  
} catch (exception) {  
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## toggleShownStateForAllAppWindows<sup>(9+)</sup>    
多窗口快速切换时隐藏或者恢复应用窗口。  
 **调用形式：**     
    
- toggleShownStateForAllAppWindows(callback: AsyncCallback\<void>): void    
起始版本： 9    
- toggleShownStateForAllAppWindows(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
window.toggleShownStateForAllAppWindows((err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to toggle shown state for all app windows. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in toggling shown state for all app windows.');  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let promise = window.toggleShownStateForAllAppWindows();  
promise.then(() => {  
  console.info('Succeeded in toggling shown state for all app windows.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to toggle shown state for all app windows. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
## setWindowLayoutMode<sup>(9+)</sup>    
设置窗口布局模式。  
 **调用形式：**     
    
- setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setWindowLayoutMode(mode: WindowLayoutMode): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | WindowLayoutMode | true | 设置的窗口布局模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting window layout mode.');  
  });  
} catch (exception) {  
  console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let promise = window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE);  
  promise.then(() => {  
    console.info('Succeeded in setting window layout mode.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## setGestureNavigationEnabled<sup>(10+)</sup>    
设置手势导航启用状态  
 **调用形式：**     
    
- setGestureNavigationEnabled(enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setGestureNavigationEnabled(enable: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 设置手势导航启用状态。true表示启用手势导航；false表示禁用手势导航。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调信息。 |  
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
  window.setGestureNavigationEnabled(true, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set gesture navigation enabled. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting gesture navigation enabled.');  
  });  
} catch (exception) {  
  console.error('Failed to set gesture navigation enabled. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let promise = window.setGestureNavigationEnabled(true);  
  promise.then(() => {  
    console.info('Succeeded in setting gesture navigation enabled.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set gesture navigation enabled. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set gesture navigation enabled. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## setWaterMarkImage<sup>(10+)</sup>    
设置水印图片显示状态。使用异步回调。  
 **调用形式：**     
    
- setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean): Promise\<void>    
起始版本： 10    
- setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pixelMap | image.PixelMap | true | 水印图片。 |  
| enable | boolean | true | | enable   | boolean                  | 是   | 设置是否显示水印图片。true显示水印图片；false表示不显示水印图片。 | |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调信息。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import image from '@ohos.multimedia.image';  
import { BusinessError } from '@ohos.base';  
  
let enable: boolean = true;  
let color: ArrayBuffer = new ArrayBuffer(0);  
let initializationOptions: image.InitializationOptions = {  
  size: {  
    height: 100,  
    width: 100  
  }  
};  
image.createPixelMap(color, initializationOptions).then((pixelMap: image.PixelMap) => {  
  console.info('Succeeded in creating pixelmap.');  
  try {  
    window.setWaterMarkImage(pixelMap, enable, (err: BusinessError) => {  
      const errCode: number = err.code;  
      if (errCode) {  
        console.error('Failed to show watermark image. Cause: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('Succeeded in showing watermark image.');  
    });  
  } catch (exception) {  
    console.error('Failed to show watermark image. Cause: ' + JSON.stringify(exception));  
  }  
}).catch((err: BusinessError) => {  
  console.error('Failed to create PixelMap. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import image from '@ohos.multimedia.image';  
import { BusinessError } from '@ohos.base';  
  
let enable: boolean = true;  
let color: ArrayBuffer = new ArrayBuffer(0);  
let initializationOptions: image.InitializationOptions = {  
  size: {  
    height: 100,  
    width: 100  
  }  
};  
image.createPixelMap(color, initializationOptions).then((pixelMap: image.PixelMap) => {  
  console.info('Succeeded in creating pixelmap.');  
  try {  
    let promise = window.setWaterMarkImage(pixelMap, enable);  
    promise.then(() => {  
      console.info('Succeeded in showing watermark image.');  
    }).catch((err: BusinessError) => {  
      console.error('Failed to show watermark image. Cause: ' + JSON.stringify(err));  
    });  
  } catch (exception) {  
    console.error('Failed to show watermark image. Cause: ' + JSON.stringify(exception));  
  }  
}).catch((err: BusinessError) => {  
  console.error('Failed to create PixelMap. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
## on('systemBarTintChange')<sup>(8+)</sup>    
开启状态栏、导航栏属性变化的监听。  
 **调用形式：**     
    
- on(type: 'systemBarTintChange', callback: Callback\<SystemBarTintState>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'systemBarTintChange'，即导航栏、状态栏属性变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的状态栏、导航栏信息集合。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  window.on('systemBarTintChange', (data) => {  
    console.info('Succeeded in enabling the listener for systemBarTint changes. Data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to enable the listener for systemBarTint changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## off('systemBarTintChange')<sup>(8+)</sup>    
关闭状态栏、导航栏属性变化的监听。  
 **调用形式：**     
    
- off(type: 'systemBarTintChange', callback?: Callback\<SystemBarTintState>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'systemBarTintChange'，即导航栏、状态栏属性变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前的状态栏、导航栏信息集合。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有状态栏、导航栏属性变化的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  window.off('systemBarTintChange');  
} catch (exception) {  
  console.error('Failed to disable the listener for systemBarTint changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## on('gestureNavigationEnabledChange')<sup>(10+)</sup>    
添加手势导航启用状态变化的监听。  
 **调用形式：**     
    
- on(type: 'gestureNavigationEnabledChange', callback: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'gestureNavigationEnabledChange'，即手势导航启用状态变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前手势导航的启用状态。true表示手势导航状态变化为启用；false表示手势导航状态变化为禁用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码：**   
```ts    
try {  
  window.on('gestureNavigationEnabledChange', (data) => {  
    console.info('Succeeded in enabling the listener for gesture navigation status changes. Data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to enable the listener for gesture navigation status changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## off('gestureNavigationEnabledChange')<sup>(10+)</sup>    
移除手势导航启用状态变化的监听。  
 **调用形式：**     
    
- off(type: 'gestureNavigationEnabledChange', callback?: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'gestureNavigationEnabledChange'，即手势导航启用状态变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 已注册的回调函数。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有手势导航启用状态变化的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码：**   
```ts    
try {  
  window.off('gestureNavigationEnabledChange');  
} catch (exception) {  
  console.error('Failed to disable the listener for gesture navigation status changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## on('waterMarkFlagChange')<sup>(10+)</sup>    
添加水印启用状态变化的监听。  
 **调用形式：**     
    
- on(type: 'waterMarkFlagChange', callback: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'waterMarkFlagChange'，即水印启用状态变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前水印的启用状态。true表示当前已启用水印；false表示当前未启用水印。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码：**   
```ts    
try {  
  window.on('waterMarkFlagChange', (data) => {  
    console.info('Succeeded in enabling the listener for watermark flag changes. Data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to enable the listener for watermark flag changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## off('waterMarkFlagChange')<sup>(10+)</sup>    
移除水印启用状态变化的监听。  
 **调用形式：**     
    
- off(type: 'waterMarkFlagChange', callback?: Callback\<boolean>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听事件，固定为'waterMarkFlagChange'，即水印启用状态变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 已注册的回调函数。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有水印启用状态变化的监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码：**   
```ts    
try {  
  window.off('waterMarkFlagChange');  
} catch (exception) {  
  console.error('Failed to disable the listener for watermark flag changes. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
## BlurStyle<sup>(9+)</sup>    
窗口模糊类型枚举。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| OFF | 0 | 表示关闭模糊。 |  
| THIN | 1 | 表示较薄的模糊类型。 |  
| REGULAR | 2 | 表示适中的模糊类型。 |  
| THICK | 3 | 表示较厚的模糊类型。 |  
    
## Window    
当前窗口实例，窗口管理器管理的基本单元。下列API示例中都需先使用[getLastWindow()](#windowgetlastwindow9)、[createWindow()](#windowcreatewindow9)、[findWindow()](#windowfindwindow9)中的任一方法获取到Window实例，再通过此实例调用对应方法。    
### hide<sup>(7+)</sup>    
隐藏当前窗口。  
 **调用形式：**     
    
- hide(callback: AsyncCallback\<void>): void    
起始版本： 7    
- hide(): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
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
windowClass.hide((err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in hiding the window.');  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.hide();  
promise.then(() => {  
  console.info('Succeeded in hiding the window.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### hideWithAnimation<sup>(9+)</sup>    
隐藏当前窗口，过程中播放动画  
 **调用形式：**     
    
- hideWithAnimation(callback: AsyncCallback\<void>): void    
起始版本： 9    
- hideWithAnimation(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
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
| 1300004 | Unauthorized operation. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.hideWithAnimation((err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to hide the window with animation. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in hiding the window with animation.');  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.hideWithAnimation();  
promise.then(() => {  
  console.info('Succeeded in hiding the window with animation.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to hide the window with animation. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### showWithAnimation<sup>(9+)</sup>    
显示当前窗口，过程中播放动画。  
 **调用形式：**     
    
- showWithAnimation(callback: AsyncCallback\<void>): void    
起始版本： 9    
- showWithAnimation(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
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
| 1300004 | Unauthorized operation. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.showWithAnimation((err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in showing the window with animation.');  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.showWithAnimation();  
promise.then(() => {  
  console.info('Succeeded in showing the window with animation.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setWindowType<sup>(deprecated)</sup>    
设置窗口类型，使用Promise异步回调。  
 **调用形式：**     
- setWindowType(type: WindowType): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | WindowType | true | 窗口类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let type = window.WindowType.TYPE_APP;  
let promise = windowClass.setWindowType(type);  
promise.then(() => {  
  console.info('Succeeded in setting the window type.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setWindowType<sup>(deprecated)</sup>    
设置窗口类型，使用callback异步回调。  
 **调用形式：**     
- setWindowType(type: WindowType, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | WindowType | true | 窗口类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let type = window.WindowType.TYPE_APP;  
windowClass.setWindowType(type, (err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in setting the window type.');  
});  
    
```    
  
    
### setWindowMode<sup>(9+)</sup>    
设置窗口模式。  
 **调用形式：**     
    
- setWindowMode(mode: WindowMode): Promise\<void>    
起始版本： 9    
- setWindowMode(mode: WindowMode, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | WindowMode | true | 窗口模式。 |  
    
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
  
let mode = window.WindowMode.FULLSCREEN;  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  windowClass.setWindowMode(mode, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the window mode. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the window mode.');  
  });  
} catch (exception) {  
  console.error('Failed to set the window mode. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let mode = window.WindowMode.FULLSCREEN;  
try {  
  let windowClass: window.Window = window.findWindow("test");  
  let promise = windowClass.setWindowMode(mode);  
  promise.then(() => {  
    console.info('Succeeded in setting the window mode.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the window mode. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the window mode. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### bindDialogTarget<sup>(9+)</sup>    
绑定模态窗口与目标窗口并添加模态窗口销毁监听。  
 **调用形式：**     
    
- bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback\<void>): Promise\<void>    
起始版本： 9    
- bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback\<void>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback\<void>): Promise\<void>    
起始版本： 9    
- bindDialogTarget(       requestInfo: dialogRequest.RequestInfo,       deathCallback: Callback\<void>,       callback: AsyncCallback\<void>     ): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token | rpc.RemoteObject | true | 目标窗口token值。 |  
| deathCallback | Callback<void> | true | 模态窗口销毁监听。 |  
| requestInfo | dialogRequest.RequestInfo | true | 目标窗口RequestInfo值。 |  
    
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
import rpc from '@ohos.rpc';  
import { BusinessError } from '@ohos.base';  
  
class MyDeathRecipient {  
  onRemoteDied() {  
    console.log('server died');  
  }  
}  
  
class TestRemoteObject extends rpc.RemoteObject {  
  constructor(descriptor: string) {  
    super(descriptor);  
  }  
  
  addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {  
    return true;  
  }  
  
  removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {  
    return true;  
  }  
  
  isObjectDead(): boolean {  
    return false;  
  }  
}  
  
let token: TestRemoteObject = new TestRemoteObject('testObject');  
let windowClass: window.Window | undefined = undefined;  
let config: window.Configuration = { name: "dialogWindow", windowType: window.WindowType.TYPE_DIALOG };  
try {  
  window.createWindow(config, (err: BusinessError, data) => {  
    let errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to create the window. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    windowClass = data;  
  });  
  windowClass.bindDialogTarget(token, () => {  
    console.info('Dialog Window Need Destroy.');  
  }, (err: BusinessError) => {  
    let errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to bind dialog target. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in binding dialog target.');  
  });  
} catch (exception) {  
  console.error('Failed to bind dialog target. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import rpc from '@ohos.rpc';  
import { BusinessError } from '@ohos.base';  
  
class MyDeathRecipient {  
  onRemoteDied() {  
    console.log('server died');  
  }  
}  
  
class TestRemoteObject extends rpc.RemoteObject {  
  constructor(descriptor: string) {  
    super(descriptor);  
  }  
  
  addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {  
    return true;  
  }  
  
  removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {  
    return true;  
  }  
  
  isObjectDead(): boolean {  
    return false;  
  }  
}  
  
let token: TestRemoteObject = new TestRemoteObject('testObject');  
let windowClass: window.Window | undefined = undefined;  
let config: window.Configuration = {  
  name: "dialogWindow",  
  windowType: window.WindowType.TYPE_DIALOG  
};  
try {  
  window.createWindow(config, (err: BusinessError, data) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to create the window. Cause: ' + JSON.stringify(err));  
      return;  
    }  
    windowClass = data;  
  });  
  let promise = windowClass.bindDialogTarget(token, () => {  
    console.info('Dialog Window Need Destroy.');  
  });  
  promise.then(() => {  
    console.info('Succeeded in binding dialog target.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to bind dialog target. Cause:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to bind dialog target. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### setWakeUpScreen<sup>(9+)</sup>    
窗口唤醒屏幕。  
 **调用形式：**     
- setWakeUpScreen(wakeUp: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wakeUp | boolean | true | 是否设置唤醒屏幕。true表示唤醒；false表示不唤醒。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码：**   
```ts    
let wakeUp: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setWakeUpScreen(wakeUp);  
} catch (exception) {  
  console.error('Failed to wake up the screen. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setSnapshotSkip<sup>(9+)</sup>    
截屏录屏是否忽略当前窗口。此接口一般用于禁止截屏。  
 **调用形式：**     
- setSnapshotSkip(isSkip: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isSkip | boolean | true | 截屏录屏是否忽略当前窗口，默认为false。<br>true表示忽略当前窗口，false表示不忽略当前窗口。</br> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
let isSkip: boolean = true;  
try {  
  windowClass.setSnapshotSkip(isSkip);  
} catch (exception) {  
  console.error('Failed to Skip. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setForbidSplitMove<sup>(9+)</sup>    
设置窗口在分屏模式下是否被禁止移动。  
 **调用形式：**     
    
- setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setForbidSplitMove(isForbidSplitMove: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isForbidSplitMove | boolean | true | 窗口在分屏模式下是否被禁止移动。true表示禁止；false表示不禁止。 |  
    
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
  
let isForbidSplitMove: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setForbidSplitMove(isForbidSplitMove, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to forbid window moving in split screen mode. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in forbidding window moving in split screen mode.');  
  });  
} catch (exception) {  
  console.error('Failed to forbid window moving in split screen mode. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isForbidSplitMove: boolean = true;  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let promise = windowClass.setForbidSplitMove(isForbidSplitMove);  
  promise.then(() => {  
    console.info('Succeeded in forbidding window moving in split screen mode.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to forbid window moving in split screen mode. Cause: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to forbid window moving in split screen mode. Cause:' + JSON.stringify(exception));  
}  
    
```    
  
    
### opacity<sup>(9+)</sup>    
设置窗口不透明度。仅支持在[自定义系统窗口的显示与隐藏动画](../../windowmanager/system-window-stage.md#自定义系统窗口的显示与隐藏动画)中使用。  
 **调用形式：**     
- opacity(opacity: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| opacity | number | true | 不透明度。该参数为浮点数，取值范围为[0.0, 1.0]。0.0表示完全透明，1.0表示完全不透明。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.opacity(0.5);  
} catch (exception) {  
  console.error('Failed to opacity. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### scale<sup>(9+)</sup>    
设置窗口缩放参数。仅支持在[自定义系统窗口的显示与隐藏动画](../../windowmanager/system-window-stage.md#自定义系统窗口的显示与隐藏动画)中使用。  
 **调用形式：**     
- scale(scaleOptions: ScaleOptions): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| scaleOptions | ScaleOptions | true | 缩放参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
let obj: window.ScaleOptions = {  
  x: 2.0,  
  y: 1.0,  
  pivotX: 0.5,  
  pivotY: 0.5  
};  
try {  
  windowClass.scale(obj);  
} catch (exception) {  
  console.error('Failed to scale. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### rotate<sup>(9+)</sup>    
设置窗口旋转参数。仅支持在[自定义系统窗口的显示与隐藏动画](../../windowmanager/system-window-stage.md#自定义系统窗口的显示与隐藏动画)中使用。  
 **调用形式：**     
- rotate(rotateOptions: RotateOptions): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotateOptions | RotateOptions | true | 旋转参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | his window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
let obj: window.RotateOptions = {  
  x: 1.0,  
  y: 1.0,  
  z: 45.0,  
  pivotX: 0.5,  
  pivotY: 0.5  
};  
try {  
  windowClass.rotate(obj);  
} catch (exception) {  
  console.error('Failed to rotate. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### translate<sup>(9+)</sup>    
设置窗口平移参数。仅支持在[自定义系统窗口的显示与隐藏动画](../../windowmanager/system-window-stage.md#自定义系统窗口的显示与隐藏动画)中使用。  
 **调用形式：**     
- translate(translateOptions: TranslateOptions): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| translateOptions | TranslateOptions | true | 平移参数，单位为px。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
let obj: window.TranslateOptions = {  
  x: 100.0,  
  y: 0.0,  
  z: 0.0  
};  
try {  
  windowClass.translate(obj);  
} catch (exception) {  
  console.error('Failed to translate. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### getTransitionController<sup>(9+)</sup>    
获取窗口属性转换控制器。  
 **调用形式：**     
- getTransitionController(): TransitionController  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| TransitionController | 属性转换控制器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
mport { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
(context: window.TransitionContext) => {  
  let toWindow = context.toWindow;  
  animateTo({  
    duration: 1000, // 动画时长  
    tempo: 0.5, // 播放速率  
    curve: Curve.EaseInOut, // 动画曲线  
    delay: 0, // 动画延迟  
    iterations: 1, // 播放次数  
    playMode: PlayMode.Normal, // 动画模式  
    onFinish: () => {  
      context.completeTransition(true)  
    }  
  }, () => {  
    let obj: window.TranslateOptions = {  
      x: 100.0,  
      y: 0.0,  
      z: 0.0  
    };  
    toWindow.translate(obj); // 设置动画过程中的属性转换  
    console.info('toWindow translate end');  
  }  
  );  
  console.info('complete transition end');  
};  
windowClass.hideWithAnimation((err: BusinessError, data) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in showing the window with animation. Data: ' + JSON.stringify(data));  
});  
    
```    
  
    
### setBlur<sup>(9+)</sup>    
设置窗口模糊。  
 **调用形式：**     
- setBlur(radius: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| radius | number | true | 表示窗口模糊的半径值。该参数为浮点数，取值范围为[0, +∞)，取值为0.0时表示关闭窗口模糊。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setBlur(4.0);  
} catch (exception) {  
  console.error('Failed to set blur. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setBackdropBlur<sup>(9+)</sup>    
设置窗口背景模糊。  
 **调用形式：**     
- setBackdropBlur(radius: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| radius | number | true | 表示窗口背景模糊的半径值。该参数为浮点数，取值范围为[0.0, +∞)，取值为0.0表示关闭窗口背景模糊。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setBackdropBlur(4.0);  
} catch (exception) {  
  console.error('Failed to set backdrop blur. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setBackdropBlurStyle<sup>(9+)</sup>    
设置窗口背景模糊类型。  
 **调用形式：**     
- setBackdropBlurStyle(blurStyle: BlurStyle): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| blurStyle | BlurStyle | true | 表示窗口背景模糊类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setBackdropBlurStyle(window.BlurStyle.THIN);  
} catch (exception) {  
  console.error('Failed to set backdrop blur style. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setShadow<sup>(9+)</sup>    
设置窗口边缘阴影。  
 **调用形式：**     
- setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| radius | number | true | 表示窗口边缘阴影的模糊半径。该参数为浮点数，取值范围为[0.0, +∞)，取值为0.0时表示关闭窗口边缘阴影。 |  
| color | string | false | 示窗口边缘阴影的颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |  
| offsetX | number | false | 表示窗口边缘阴影的X轴的偏移量。该参数为浮点数，单位为px。 |  
| offsetY | number | false | 表示窗口边缘阴影的Y轴的偏移量。该参数为浮点数，单位为px。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setShadow(4.0, '#FF00FF00', 2, 3);  
} catch (exception) {  
  console.error('Failed to set shadow. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### setCornerRadius<sup>(9+)</sup>    
设置窗口圆角半径。  
 **调用形式：**     
- setCornerRadius(cornerRadius: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cornerRadius | number | true | 表示窗口圆角的半径值。该参数为浮点数，取值范围为[0.0, +∞)，取值为0.0时表示没有窗口圆角。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1300002 | This window state is abnormal. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码：**   
```ts    
let windowClass: window.Window = window.findWindow("test");  
try {  
  windowClass.setCornerRadius(4.0);  
} catch (exception) {  
  console.error('Failed to set corner radius. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### raiseToAppTop<sup>(10+)</sup>    
提升应用子窗口到应用顶层。  
 **调用形式：**     
    
- raiseToAppTop(callback: AsyncCallback\<void>): void    
起始版本： 10    
- raiseToAppTop(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
| 1300004 | Unauthorized operation. |  
| 1300009 | The parent window is invalid. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
windowClass.raiseToAppTop((err: BusinessError) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to raise the window to app top. Cause: ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in raising the window to app top.');  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
let promise = windowClass.raiseToAppTop();  
promise.then(() => {  
  console.info('Succeeded in raising the window to app top.');  
}).catch((err: BusinessError) => {  
  console.error('Failed to raise the window to app top. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setWaterMarkFlag<sup>(10+)</sup>    
为当前窗口添加或删除安全水印标志。  
 **调用形式：**     
    
- setWaterMarkFlag(enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setWaterMarkFlag(enable: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 是否对窗口添加标志位。true表示添加，false表示删除。 |  
    
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
| 1300008 | The operation is on invalid display. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let enable = true;  
  let promise = windowClass.setWaterMarkFlag(enable);  
  promise.then(() => {  
    console.info('Succeeded in setting water mark flag of window.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set water mark flag of window. Cause:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set water mark flag of window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import { BusinessError } from '@ohos.base';  
  
let windowClass: window.Window = window.findWindow("test");  
try {  
  let enable: boolean = true;  
  windowClass.setWaterMarkFlag(enable, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set water mark flag of window. Cause:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting water mark flag of window.');  
  });  
} catch (exception) {  
  console.error('Failed to set water mark flag of window. Cause: ' + JSON.stringify(exception));  
}  
    
```    
  
    
### raiseAboveTarget<sup>(10+)</sup>    
将同一个主窗口下的子窗口提升到目标子窗口之上。  
 **调用形式：**     
    
- raiseAboveTarget(windowId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- raiseAboveTarget(windowId: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| windowId | number | true | 目标子窗口的id，通过[getWindowProperties](#getwindowproperties9)接口获取到[properties](#windowproperties)后，再通过properties.id获取 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | | Promise<void> | 无返回结果的Promise对象。 | |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
| 1300004 | Unauthorized operation. |  
| 1300009 | The parent window is invalid. |  
    
 **示例代码1：**   
示例(callback):  
```js    
// 将windowClass调整到targetWindow之上let windowClass: window.Window | undefined = undefined;let targetWindow: window.Window = windowClass;let properties = targetWindow.getWindowProperties();let targetId = properties.id;windowClass.raiseAboveTarget(targetId, (err) => {    if (err.code) {        console.error('Failed to raise the subWindow to target subWindow top. Cause: ' + JSON.stringify(err));        return;    }    console.info('Succeeded in raising the subWindow to target subWindow top.');});    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```js    
// 将windowClass调整到targetWindow之上let windowClass: window.Window | undefined = undefined;let targetWindow: window.Window = windowClass;let properties = targetWindow.getWindowProperties();let targetId = properties.id;let promise = windowClass.raiseAboveTarget(targetId);promise.then(()=> {    console.info('Succeeded in raising the subWindow to target subWindow top.');}).catch((err)=>{    console.error('Failed to raise the subWindow to target subWindow top. Cause: ' + JSON.stringify(err));});    
```    
  
    
### setRaiseByClickEnabled<sup>(10+)</sup>    
禁止/使能子窗口点击抬升功能。  
 **调用形式：**     
    
- setRaiseByClickEnabled(enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setRaiseByClickEnabled(enable: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 设置子窗口点击抬升功能是否使能，true表示使能，false表示禁止。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
| 1300004 | Unauthorized operation. |  
| 1300009 | The parent window is invalid. |  
    
 **示例代码1：**   
示例(callback):  
```js    
let enabled = false;let windowClass: window.Window = window.findWindow("test");windowClass.setRaiseByClickEnabled(enabled, (err) => {    if (err.code) {        console.error('Failed to disable the raise-by-click function. Cause: ' + JSON.stringify(err));        return;    }    console.info('Succeeded in disabling the raise-by-click function.');});    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```js    
let enabled = false;let windowClass: window.Window = window.findWindow("test");let promise = windowClass.setRaiseByClickEnabled(enabled);promise.then(()=> {    console.info('Succeeded in disabling the raise-by-click function.');}).catch((err)=>{    console.error('Failed to disable the raise-by-click function. Cause: ' + JSON.stringify(err));});    
```    
  
    
### minimize<sup>(10+)</sup>    
最小化主窗口。  
 **调用形式：**     
    
- minimize(callback: AsyncCallback\<void>): void    
起始版本： 10    
- minimize(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 801 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
    
 **示例代码1：**   
示例(callback):  
```js    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class EntryAbility extends UIAbility {  
    onWindowStageCreate(windowStage) {  
        // 为主窗口加载对应的目标页面。  
        windowStage.loadContent("pages/page2", (err) => {  
            if (err.code) {  
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
                return;  
            }  
            console.info('Succeeded in loading the content.');  
        });  
        // 获取应用主窗口。  
        let mainWindow = null;  
          
        windowStage.getMainWindow((err, data) => {  
            if (err.code) {  
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
                return;  
            }  
            mainWindow = data;  
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
            // 调用minimize接口。  
            mainWindow.minimize((err) => {  
                if (err.code) {  
                    console.error('Failed to minimize the app main window. Cause: ' + JSON.stringify(err));  
                    return;  
                }  
                console.info('Successfully minimized app main window.');  
            });  
        })  
    }  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```js    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class EntryAbility extends UIAbility {  
    onWindowStageCreate(windowStage) {  
        // 为主窗口加载对应的目标页面。  
        windowStage.loadContent("pages/page2", (err) => {  
            if (err.code) {  
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
                return;  
            }  
            console.info('Succeeded in loading the content.');  
        });  
        // 获取应用主窗口。  
        let mainWindow = null;  
          
        windowStage.getMainWindow((err, data) => {  
            if (err.code) {  
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
                return;  
            }  
            mainWindow = data;  
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
            // 获取minimize接口的promise对象。  
            let promise = mainWindow.minimize();  
            promise.then(()=> {  
                console.info('Successfully minimized app main window.');  
            }).catch((err)=>{  
                console.error('Failed to minimize the app main window. Cause: ' + JSON.stringify(err));  
            });  
        })  
    }  
};  
    
```    
  
    
### setResizeByDragEnabled<sup>(10+)</sup>    
禁止/使能通过拖拽方式缩放主窗口的功能。  
 **调用形式：**     
    
- setResizeByDragEnabled(enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setResizeByDragEnabled(enable: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 设置窗口是否使能通过拖拽进行缩放，true表示使能，false表示禁止。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码1：**   
示例(callback):  
```js    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class EntryAbility extends UIAbility {  
    onWindowStageCreate(windowStage) {  
        // 为主窗口加载对应的目标页面。  
        windowStage.loadContent("pages/page2", (err) => {  
            if (err.code) {  
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
                return;  
            }  
            console.info('Succeeded in loading the content.');  
        });  
        // 获取应用主窗口。  
        let mainWindow = null;  
          
        windowStage.getMainWindow((err, data) => {  
            if (err.code) {  
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
                return;  
            }  
            mainWindow = data;  
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
  
            let enabled = false;  
            // 调用setResizeByDragEnabled接口。  
            mainWindow.setResizeByDragEnabled(enabled, (err) => {  
                if (err.code) {  
                    console.error('Failed to set the function of disabling the resize by dragg window. Cause: ' + JSON.stringify(err));  
                    return;  
                }  
                console.info('Succeeded in setting the function of disabling the resize by dragg window.');  
            });  
        })  
    }  
};  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```js    
import UIAbility from '@ohos.app.ability.UIAbility';  
  
export default class EntryAbility extends UIAbility {  
    onWindowStageCreate(windowStage) {  
        // 为主窗口加载对应的目标页面。  
        windowStage.loadContent("pages/page2", (err) => {  
            if (err.code) {  
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
                return;  
            }  
            console.info('Succeeded in loading the content.');  
        });  
        // 获取应用主窗口。  
        let mainWindow = null;  
          
        windowStage.getMainWindow((err, data) => {  
            if (err.code) {  
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
                return;  
            }  
            mainWindow = data;  
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
  
            let enabled = false;  
            // 获取setResizeByDragEnabled接口的promise对象  
            let promise = mainWindow.setResizeByDragEnabled(enabled);  
            promise.then(()=> {  
                console.info('Succeeded in setting the function of disabling the resize by dragg window.');  
            }).catch((err)=>{  
                console.error('Failed to set the function of disabling the resize by dragg window. Cause: ' + JSON.stringify(err));  
            });  
        })  
    }  
};  
    
```    
  
    
### hideNonSystemFloatingWindows<sup>(11+)</sup>    
设置是否隐藏非系统级悬浮窗口。  
 **调用形式：**     
    
- hideNonSystemFloatingWindows(shouldHide: boolean, callback: AsyncCallback\<void>): void    
起始版本： 11    
- hideNonSystemFloatingWindows(shouldHide: boolean): Promise\<void>    
起始版本： 11  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Window.SessionManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| shouldHide | boolean | true | 指示是否隐藏非系统级的悬浮窗口，true表示隐藏，false表示不隐藏。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 1300002 | This window state is abnormal. |  
| 1300003 | This window manager service works abnormally. |  
| 1300004 | Unauthorized operation. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
  
export default class EntryAbility extends UIAbility {  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    // 加载主窗口对应的页面  
    windowStage.loadContent('pages/Index', (err) => {  
      if (err.code) {  
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
        return;  
      }  
      console.info('Succeeded in loading the content.');  
    });  
  
    // 获取应用主窗口。  
    let mainWindow = null;  
    windowStage.getMainWindow((err, data) => {  
      if (err.code) {  
        console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
        return;  
      }  
      mainWindow = data;  
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
  
      let shouldHide = true;  
      // 调用带callback参数的hideNonSystemFloatingWindows接口  
      mainWindow.hideNonSystemFloatingWindows(shouldHide, (err) => {  
        if (err.code) {  
          console.error('Failed to hide the non-system floating windows. Cause: ' + JSON.stringify(err));  
          return;  
        }  
        console.info('Succeeded in hiding the non-system floating windows.');  
      });  
    })  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import window from '@ohos.window';  
  
export default class EntryAbility extends UIAbility {  
  onWindowStageCreate(windowStage: window.WindowStage) {  
    // 加载主窗口对应的页面  
    windowStage.loadContent('pages/Index', (err) => {  
      if (err.code) {  
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));  
        return;  
      }  
      console.info('Succeeded in loading the content.');  
    });  
  
    // 获取应用主窗口。  
    let mainWindow = null;  
    windowStage.getMainWindow((err, data) => {  
      if (err.code) {  
        console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));  
        return;  
      }  
      mainWindow = data;  
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));  
  
      let shouldHide = true;  
      // 调用hideNonSystemFloatingWindows接口，获取promise对象  
      let promise = mainWindow.hideNonSystemFloatingWindows(shouldHide);  
      promise.then(()=> {  
        console.info('Succeeded in hiding the non-system floating windows.');  
      }).catch((err)=>{  
        console.error('Failed to hide the non-system floating windows. Cause: ' + JSON.stringify(err));  
      });  
    })  
  }  
}  
    
```    
  
    
## WindowStage<sup>(9+)</sup>    
窗口管理器。管理各个基本窗口单元，即[Window](#window)实例。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### disableWindowDecor<sup>(9+)</sup>    
禁止窗口装饰。  
 **调用形式：**     
- disableWindowDecor(): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
    
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
    console.log('disableWindowDecor');  
    windowStage.disableWindowDecor();  
  }  
};  
    
```    
  
    
### setShowOnLockScreen<sup>(9+)</sup>    
设置应用显示在锁屏之上。  
 **调用形式：**     
- setShowOnLockScreen(showOnLockScreen: boolean): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| showOnLockScreen | boolean | true | 是否设置应用显示在锁屏之上。true表示显示在锁屏之上；false表示不显示在锁屏之上。 |  
    
    
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
      windowStage.setShowOnLockScreen(true);  
    } catch (exception) {  
      console.error('Failed to show on lockscreen. Cause:' + JSON.stringify(exception));  
    }  
  }  
};  
    
```    
  
