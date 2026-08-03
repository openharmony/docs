# @ohos.display (屏幕属性)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk-->
<!--Designer: @logn; @wulong158-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息，获取所有显示设备的信息以及监听显示设备的插拔行为。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.display (屏幕属性)](js-apis-display.md)。

## 导入模块

```ts
import { display } from '@kit.ArkUI';
```

## display.hasPrivateWindow<sup>9+</sup>

hasPrivateWindow(displayId: number): boolean

查询指定display对象上是否有可见的隐私窗口。可通过[setWindowPrivacyMode()](arkts-apis-window-Window.md#setwindowprivacymode9)接口设置隐私窗口。隐私窗口内容将无法被截屏或录屏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- |----------|
| displayId    | number                    | 是   | 屏幕ID，该参数应为非负整数。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- |-----------------------------------------------------------------------|
|boolean | 查询的display对象上是否有可见的隐私窗口。true表示此display对象上有可见的隐私窗口，false表示此display对象上没有可见的隐私窗口。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
try {
  // 获取默认Display对象
  displayClass = display.getDefaultDisplaySync();

  let ret: boolean | undefined = undefined;
  try {
    // 查询默认屏幕上是否有隐私窗口
    ret = display.hasPrivateWindow(displayClass.id);
  } catch (exception) {
    console.error(`Failed to check has privateWindow or not. Code: ${exception.code}, message: ${exception.message}`);
  }
  if (ret === undefined) {
    console.error('Failed to check has privateWindow or not.');
  }
  if (ret) {
    console.info('There has privateWindow.');
  } else if (!ret) {
    console.info('There has no privateWindow.');
  }
} catch (exception) {
  console.error(`Failed to obtain the default display object. Code: ${exception.code}, message: ${exception.message}`);
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
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<boolean> = (data: boolean) => {
  console.info(`Listening enabled. Data: ${data}`);
};
try {
  // 注册隐私模式变化监听
  display.on('privateModeChange', callback);
} catch (exception) {
  console.error(`Failed to register callback. Code: ${exception.code}, message: ${exception.message}`);
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
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
try {
  // 取消隐私模式变化监听
  display.off('privateModeChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Code: ${exception.code}, message: ${exception.message}`);
}
```

## display.setFoldDisplayMode<sup>10+</sup>
setFoldDisplayMode(mode: FoldDisplayMode): void

更改可折叠设备的显示模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在折叠手机上可正常调用，在其他设备上不生效或返回1400003错误码。

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| mode     | [FoldDisplayMode](js-apis-display.md#folddisplaymode10)    | 是   | 可折叠设备的显示模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

try {
  let mode: display.FoldDisplayMode = display.FoldDisplayMode.FOLD_DISPLAY_MODE_FULL;
  // 设置折叠显示模式为全屏显示
  display.setFoldDisplayMode(mode);
} catch (exception) {
  console.error(`Failed to change the fold display mode. Code: ${exception.code}, message: ${exception.message}`);
}
```

## display.setFoldDisplayMode<sup>19+</sup>
setFoldDisplayMode(mode: FoldDisplayMode, reason: string): void

更改可折叠设备的显示模式，并指明更改原因。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在折叠手机上可正常调用，在其他设备上不生效或返回1400003错误码。

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| mode     | [FoldDisplayMode](js-apis-display.md#folddisplaymode10)    | 是   | 可折叠设备的显示模式。 |
| reason     | string    | 是   | 更改显示模式的原因。不设置时默认为空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

try {
  let mode: display.FoldDisplayMode = display.FoldDisplayMode.FOLD_DISPLAY_MODE_MAIN;
  // 设置折叠显示模式为主屏幕显示并指定原因为“backSelfie”
  display.setFoldDisplayMode(mode, 'backSelfie');
} catch (exception) {
  console.error(`Failed to change the fold display mode. Code: ${exception.code}, message: ${exception.message}`);
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
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

try {
  let locked: boolean = false;
  // 设置折叠状态不锁定
  display.setFoldStatusLocked(locked);
} catch (exception) {
  console.error(`Failed to change the fold status locked mode. Code: ${exception.code}, message: ${exception.message}`);
}
```

## display.addVirtualScreenBlocklist<sup>18+</sup>
addVirtualScreenBlocklist(windowIds: Array\<number>): Promise\<void>

将窗口添加到禁止投屏显示的名单中，被添加的窗口无法在投屏时显示。仅对应用主窗或系统窗口生效。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| windowIds     | Array\<number>    | 是   | 窗口ID列表，传入子窗口ID时不生效。窗口ID为大于0的整数。推荐使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)方法获取窗口ID属性。|

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801     | Capability not supported. Function addVirtualScreenBlocklist can not work correctly due to limited device capabilities. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display, window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    // ...
    let windowId = windowStage.getMainWindowSync().getWindowProperties().id; // 获取窗口ID
    let windowIds = [windowId];

    // 将窗口添加到禁止投屏显示的名单
    let promise = display.addVirtualScreenBlocklist(windowIds);
    promise.then(() => {
      console.info('Succeeded in adding virtual screen blocklist.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to add virtual screen blocklist. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## display.removeVirtualScreenBlocklist<sup>18+</sup>
removeVirtualScreenBlocklist(windowIds: Array\<number>): Promise\<void>

将窗口从禁止投屏显示的名单中移除，被移除的窗口可以在投屏时显示。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| windowIds     | Array\<number>    | 是   | 窗口ID列表，传入子窗口ID时不生效。窗口ID为大于0的整数。推荐使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)方法获取窗口ID属性。|

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801     | Capability not supported. Function removeVirtualScreenBlocklist can not work correctly due to limited device capabilities. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display, window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    // ...
    let windowId = windowStage.getMainWindowSync().getWindowProperties().id; // 获取窗口ID
    let windowIds = [windowId];

    // 将窗口添加到禁止投屏显示的名单
    let promise = display.addVirtualScreenBlocklist(windowIds);
    promise.then(() => {
      console.info('Succeeded in adding virtual screen blocklist.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to add virtual screen blocklist. Code: ${err.code}, message: ${err.message}`);
    });

    // 将窗口从禁止投屏显示的名单移除
    promise = display.removeVirtualScreenBlocklist(windowIds);
    promise.then(() => {
      console.info('Succeeded in removing virtual screen blocklist.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to remove virtual screen blocklist. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## display.addVirtualScreenSurface

addVirtualScreenSurface(screenId: number, surfaceId: string, surfaceRegion?: Rect): Promise&lt;void&gt;

为虚拟屏幕添加surface。使用Promise异步回调。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Window.SessionManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| screenId  | number | 是   | 虚拟屏幕ID，与创建的虚拟屏幕ID保持一致，即使用[createVirtualScreen()](js-apis-display.md#displaycreatevirtualscreen16)接口成功创建对应虚拟屏幕时的返回值，该参数仅支持整数输入。 |
| surfaceId | string | 是   | 虚拟屏幕绑定的surfaceId，由用户指定某一实际存在的surface对应的surfaceId。该参数最大长度为4096个字节，超出最大长度时则取前4096个字节。 |
| surfaceRegion | [Rect](js-apis-display.md#rect9) | 否   | surface中显示虚拟屏幕的矩形区域。如果虚拟屏幕未通过[setVirtualScreenSurface()](js-apis-display.md#displaysetvirtualscreensurface16)或[addVirtualScreenSurface()](#displayaddvirtualscreensurface)绑定过surface，surfaceRegion无效，默认全屏。在镜像模式下，surfaceRegion无效，默认全屏；在异源模式下，surfaceRegion有效。以虚拟屏幕左顶点为原点，当指定的surfaceRegion区域与虚拟屏幕无重叠区域时，返回1400004错误码。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息  |
| ------- | ----------------------- |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 801      | Capability not supported. Function addVirtualScreenSurface can not work correctly due to limited device capabilities. |
| 1400001  | Invalid display or screen. |
| 1400003  | This display manager service works abnormally. |
| 1400004  | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

```ts
// Index.ets
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  xComponentController: XComponentController = new XComponentController();

  addVirtualScreenSurface = () => {
    let screenId: number = 1;
    let surfaceId = this.xComponentController.getXComponentSurfaceId();
    display.addVirtualScreenSurface(screenId, surfaceId).then(() => {
      console.info('Succeeded in adding surface for the virtual screen.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to add surface for the virtual screen. Code:${err.code}, message is ${err.message}`);
    });
  }
  build() {
    RelativeContainer() {
      XComponent({
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
      Button('addSurface')
        .onClick((event: ClickEvent) => {
          this.addVirtualScreenSurface();
      }).width('100%')
      .height(20)
    }
    .width('100%')
    .height('100%')
  }
}
```

## display.removeVirtualScreenSurface

removeVirtualScreenSurface(screenId: number, surfaceId: string): Promise&lt;void&gt;

移除虚拟屏幕绑定的surface。使用Promise异步回调。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Window.SessionManager

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| screenId  | number | 是   | 虚拟屏幕ID，与创建的虚拟屏幕ID保持一致，即使用[createVirtualScreen()](js-apis-display.md#displaycreatevirtualscreen16)接口成功创建对应虚拟屏幕时的返回值，该参数仅支持整数输入。 |
| surfaceId | string | 是   | 虚拟屏幕绑定的surfaceId，由用户指定某一实际存在的surface对应的surfaceId。该参数最大长度为4096个字节，超出最大长度时则取前4096个字节。 |

**返回值：**

| 类型                | 说明                    |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 801      | Capability not supported. Function removeVirtualScreenSurface can not work correctly due to limited device capabilities. |
| 1400001  | Invalid display or screen. |
| 1400003  | This display manager service works abnormally. |
| 1400004  | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

```ts
// Index.ets
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  xComponentController: XComponentController = new XComponentController();

  removeVirtualScreenSurface = () => {
    let screenId: number = 1;
    let surfaceId = this.xComponentController.getXComponentSurfaceId();
    display.removeVirtualScreenSurface(screenId, surfaceId).then(() => {
      console.info('Succeeded in removing surface for the virtual screen.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to remove surface for the virtual screen. Code:${err.code}, message is ${err.message}`);
    });
  }
  build() {
    RelativeContainer() {
      XComponent({
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
      Button('removeSurface')
        .onClick((event: ClickEvent) => {
          this.removeVirtualScreenSurface();
      }).width('100%')
      .height(20)
    }
    .width('100%')
    .height('100%')
  }
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
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
// 获取默认Display对象
displayClass = display.getDefaultDisplaySync();
// 查询是否包含沉浸式窗口
displayClass.hasImmersiveWindow((err: BusinessError, data: boolean) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to check whether there is immersive window. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in checking whether there is immersive window. data: ${data}`);
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
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
// 获取默认Display对象
displayClass = display.getDefaultDisplaySync();
// 查询是否包含沉浸式窗口
let promise = displayClass.hasImmersiveWindow();
promise.then((data) => {
  console.info(`Succeeded in checking whether there is immersive window. data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether there is immersive window. Code: ${err.code}, message: ${err.message}`);
});
```
