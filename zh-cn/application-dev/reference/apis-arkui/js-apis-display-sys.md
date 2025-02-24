# @ohos.display (屏幕属性)(系统接口)

屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息，获取所有显示设备的信息以及监听显示设备的插拔行为。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohso.display (屏幕属性)](js-apis-display.md)。

## 导入模块

```ts
import { display } from '@kit.ArkUI';
```

## display.hasPrivateWindow<sup>9+</sup>

hasPrivateWindow(displayId: number): boolean

查询指定display对象上是否有可见的隐私窗口。可通过[setWindowPrivacyMode()](js-apis-window.md#setwindowprivacymode9)接口设置隐私窗口。隐私窗口内容将无法被截屏或录屏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- |----------|
| displayId    | number                    | 是   | 显示设备的id，该参数仅支持整数输入。该参数大于等于0。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- |-----------------------------------------------------------------------|
|boolean | 查询的display对象上是否有可见的隐私窗口。true表示此display对象上有可见的隐私窗口，false表示此display对象上没有可见的隐私窗口。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  let ret: boolean = true;
  try {
    ret = display.hasPrivateWindow(displayClass.id);
  } catch (exception) {
    console.error('Failed to check has privateWindow or not. Code: ' + JSON.stringify(exception));
  }
  if (ret == undefined) {
    console.log("Failed to check has privateWindow or not.");
  }
  if (ret) {
    console.log("There has privateWindow.");
  } else if (!ret) {
    console.log("There has no privateWindow.");
  }
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```

## display.on('privateModeChange')<sup>10+</sup>

on(type: 'privateModeChange', callback: Callback&lt;boolean&gt;): void

开启屏幕隐私模式变化的监听。当屏幕前台有隐私窗口，则屏幕处于隐私模式，屏幕中的隐私窗口内容无法被截屏或录屏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'privateModeChange'，表示屏幕隐私模式状态发生变化。 |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。表示屏幕隐私模式是否改变。true表示屏幕由非隐私窗口模式变为隐私模式，false表示屏幕由隐私模式变为非隐私模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<boolean> = (data: boolean) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on("privateModeChange", callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('privateModeChange')<sup>10+</sup>

off(type: 'privateModeChange', callback?: Callback&lt;boolean&gt;): void

关闭屏幕隐私模式变化的监听。当屏幕前台有隐私窗口，则屏幕处于隐私模式，屏幕中的隐私窗口内容无法被截屏或录屏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'privateModeChange'，表示屏幕隐私模式状态发生变化。 |
| callback | Callback&lt;boolean&gt; | 否   | 需要取消注册的回调函数。表示屏幕隐私模式是否改变。true表示屏幕由非隐私窗口模式变为隐私模式，false表示屏幕由隐私模式变为非隐私模式。若无此参数，则取消注册屏幕隐私模式变化监听的所有回调函数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**示例：**

```ts
try {
  display.off("privateModeChange");
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.setFoldDisplayMode<sup>10+</sup>
setFoldDisplayMode(mode: FoldDisplayMode): void

更改可折叠设备的显示模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| mode     | [FoldDisplayMode](js-apis-display.md#folddisplaymode10)    | 是   | 可折叠设备的显示模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

try {
  let mode: display.FoldDisplayMode = display.FoldDisplayMode.FOLD_DISPLAY_MODE_FULL;
  display.setFoldDisplayMode(mode);
} catch (exception) {
  console.error('Failed to change the fold display mode. Code: ' + JSON.stringify(exception));
}
```

## display.setFoldStatusLocked<sup>11+</sup>
setFoldStatusLocked(locked: boolean): void

设置可折叠设备当前折叠状态的锁定状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| locked     | boolean    | 是   | 可折叠设备的折叠状态是否锁定。true表示锁定，false表示不锁定。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

try {
  let locked: boolean = false;
  display.setFoldStatusLocked(locked);
} catch (exception) {
  console.error('Failed to change the fold status locked mode. Code: ' + JSON.stringify(exception));
}
```

## Display
屏幕实例。描述display对象的属性和方法。

下列API示例中都需先使用[getAllDisplays()](js-apis-display.md#displaygetalldisplays9)、[getDefaultDisplaySync()](js-apis-display.md#displaygetdefaultdisplaysync9)中的任一方法获取到Display实例，再通过此实例调用对应方法。

### hasImmersiveWindow<sup>11+</sup>
hasImmersiveWindow(callback: AsyncCallback&lt;boolean&gt;): void

判断当前屏幕是否包含沉浸式窗口，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;boolean&gt;   | 是   | 回调函数。返回true表示当前屏幕包含沉浸式窗口，false表示不包含。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 801 | Capability not supported on this device. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();
displayClass.hasImmersiveWindow((err: BusinessError, data) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in checking whether there is immersive window. data: ' + JSON.stringify(data));
});
```
### hasImmersiveWindow<sup>11+</sup>
hasImmersiveWindow(): Promise&lt;boolean&gt;

判断当前屏幕是否包含沉浸式窗口，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前屏幕包含沉浸式窗口，false表示不包含。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 801 | Capability not supported on this device. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();
let promise = displayClass.hasImmersiveWindow();
promise.then((data) => {
  console.info('Succeeded in checking whether there is immersive window. data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(err));
})
```
