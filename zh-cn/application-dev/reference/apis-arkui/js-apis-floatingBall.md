# @ohos.window.floatingBall (闪控球窗口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @betafringe007-->
<!--Designer: @taoweihua-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

该模块提供闪控球的基础功能，包括判断设备是否支持闪控球功能，以及创建闪控球控制器来启动、更新或停止闪控球。适用于跨应用的题目搜索、账单记录、商品比价、抢单、翻译场景，以及金融类应用的实时盯盘场景，以小窗模式呈现内容。闪控球以悬浮小组件形式显示在其他应用之上，即时呈现应用的关键信息。

> **说明：**
>
> - 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 在OpenHarmony 7.0.0之前，支持在Tablet设备的非[电脑模式](../../windowmanager/freeform-window-overview.md#电脑模式)、Phone设备使用闪控球功能，其他设备不可用；从OpenHarmony 7.0.0开始，支持在Phone、PC/2in1、Tablet设备使用闪控球功能，其他设备不可用。
>
> - 针对系统能力SystemCapability.Window.SessionManager，请先使用[canIUse()](../common/js-apis-syscap.md#caniuse)接口判断当前设备是否支持此syscap及对应接口。

**闪控球和闪控窗对比**

- 共同点：闪控球和[闪控窗](js-apis-floatView.md)均为一种特殊的应用辅助窗口，具备在应用主窗口和对应UIAbility退至后台后仍然可以在前台显示的能力。可以用于应用退至后台后，使用其继续显示UI。
- 区别：
  - 显示形式不同。闪控球以小圆球的形式展现，适用于展示关键信息。闪控窗以小型窗口展示，展示区域较大，可以持续展示应用内容或提供快捷操作。
  - 闪控球只能贴边展示，闪控窗则没有此限制。
  - 闪控球模板固定，应用不能定制UI。闪控窗同样存在模板，并由系统管理并统一绘制UI，但是提供了可绘制的区域，可供应用加载指定页面内容。

**与闪控窗联动：**

本模块可与[@ohos.window.floatView](js-apis-floatView.md)（闪控窗）联合使用。通过[floatView.bind](js-apis-floatView.md#floatviewbind)接口将闪控窗控制器与闪控球控制器绑定后，用户点击闪控球可展开为闪控窗，点击闪控窗左上角的缩小按钮可收起为闪控球，实现两种窗口形态的相互切换。

## 导入模块

```ts
import { floatingBall } from '@kit.ArkUI';
```

## floatingBall.isFloatingBallEnabled

isFloatingBallEnabled(): boolean

判断当前设备是否支持闪控球功能。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
|------------|------------|
| boolean  | 当前设备是否支持闪控球功能。true表示支持，false则表示不支持。 |

**示例：**

```ts
// 判断当前设备是否支持闪控球功能
let enable: boolean = floatingBall.isFloatingBallEnabled();
console.info('Floating ball enabled is: ' + enable);
```

## floatingBall.create

create(config: FloatingBallConfiguration): Promise&lt;FloatingBallController&gt;

创建闪控球控制器，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 在OpenHarmony 7.0.0之前，该接口在Tablet设备的非[电脑模式](../../windowmanager/freeform-window-overview.md#电脑模式)、Phone设备下可正常调用，在其他设备、Tablet设备的[电脑模式](../../windowmanager/freeform-window-overview.md#电脑模式)下调用返回801错误码。从OpenHarmony 7.0.0开始，支持在Phone、PC/2in1、Tablet设备使用，其他设备调用返回801错误码。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| config | [FloatingBallConfiguration](#floatingballconfiguration) | 是 | 创建闪控球控制器的参数。该参数不能为空，并且构造该参数的context不能为空。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;[FloatingBallController](#floatingballcontroller)&gt; | Promise对象。返回当前创建的闪控球控制器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 801 | Capability not supported.Failed to call the API due to limited device capabilities. |
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

// 声明闪控球控制器实例
let floatingBallController: floatingBall.FloatingBallController | undefined = undefined;
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回的结果为UIAbilityContext
let ctx = this.getUIContext().getHostContext() as common.UIAbilityContext; 
// 配置闪控球控制器参数
let config: floatingBall.FloatingBallConfiguration = {
  context: ctx,
};
try {
  // 创建闪控球控制器
  floatingBall.create(config).then((data: floatingBall.FloatingBallController) => {
    // 保存控制器实例
    floatingBallController = data;
    console.info(`Succeeded in creating floating ball controller. Data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create floating ball controller. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to create floating ball controller. Cause:${e.code}, message:${e.message}`);
}
```

## FloatingBallConfiguration

创建闪控球控制器时需要提供的参数配置。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 否 | 否 | 表示上下文环境，用于创建闪控球控制器时关联应用的主窗口。该参数不能为空，通常传入UIAbilityContext对象。|

## FloatingBallController

闪控球控制器实例，用于启动、更新、停止闪控球以及注册回调等操作。

下列API示例中都需先使用[floatingBall.create()](#floatingballcreate)方法获取到闪控球控制器实例（即floatingBallController），再通过此实例调用对应方法。

**系统能力：** SystemCapability.Window.SessionManager

### startFloatingBall

startFloatingBall(params: FloatingBallParams): Promise&lt;void&gt;

启动闪控球，使用Promise异步回调。

**需要权限：** ohos.permission.USE_FLOAT_BALL

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| params | [FloatingBallParams](#floatingballparams) | 是 | 启动闪控球的参数，用于配置闪控球的标题、内容或背景色等。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 201 | Permission verification failed, usually returned by VerifyAccessToken. |
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300020 | Failed to create the floating ball window. |
| 1300021 | Failed to start multiple floating ball windows. |
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |
| 1300025 | The floating ball state does not support this operation. |
| 1300034 | This operation conflicts with other floating windows. Possible cause: App has already started float view.</br>适用版本：26.0.0+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 配置闪控球启动参数
let startParams: floatingBall.FloatingBallParams = {
  template: floatingBall.FloatingBallTemplate.EMPHATIC,
  title: 'title',
  content: 'content'
};
try {
  // 启动闪控球
  floatingBallController.startFloatingBall(startParams).then(() => {
    console.info('Succeeded in starting floating ball.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start floating ball. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to start floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### updateFloatingBall

updateFloatingBall(params: FloatingBallParams): Promise&lt;void&gt;

更新闪控球，使用Promise异步回调。必须先调用[startFloatingBall()](#startfloatingball)启动闪控球后，才能调用此方法更新闪控球参数。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| params | [FloatingBallParams](#floatingballparams) | 是 | 更新闪控球的参数，用于更新闪控球的标题、内容或背景色等。调用此接口更新闪控球时，模板类型template字段不可更改。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |
| 1300025 | The floating ball state does not support this operation. |
| 1300027 | When updating the floating ball, the template type cannot be changed. |
| 1300028 | Updating static template-based floating balls is not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 配置闪控球更新参数
let updateParams: floatingBall.FloatingBallParams = {
  template: floatingBall.FloatingBallTemplate.EMPHATIC,
  title: 'title2',
  content: 'content2'
};
try {
  // 更新闪控球
  floatingBallController.updateFloatingBall(updateParams).then(() => {
    console.info('Succeeded in updating floating ball.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to update floating ball. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to update floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### stopFloatingBall

stopFloatingBall(): Promise&lt;void&gt;

停止闪控球，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 停止闪控球
floatingBallController.stopFloatingBall().then(() => {
  console.info('Succeeded in stopping floating ball.');
}).catch((err: BusinessError) => {
  console.error(`Failed to stop floating ball. Cause:${err.code}, message:${err.message}`);
});
```

### on('stateChange')

on(type: 'stateChange', callback: Callback&lt;FloatingBallState&gt;): void

注册闪控球生命周期状态变化的监听事件。不再使用时，取消监听以避免内存泄漏。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| type | string | 是 | 监听事件，固定为'stateChange'，即闪控球生命周期状态变化事件。 |
| callback | Callback&lt;[FloatingBallState](#floatingballstate)&gt; | 是 | 回调函数。返回当前的闪控球生命周期状态。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**示例：**

```ts
// 定义状态变化回调函数
let onStateChange = (state: floatingBall.FloatingBallState) => {
  console.info('Floating ball stateChange: ' + state);
};
try {
  // 注册闪控球状态变化监听
  floatingBallController.on('stateChange', onStateChange);
} catch (e) {
  console.error(`Failed to on stateChange floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### off('stateChange')

off(type: 'stateChange', callback?: Callback&lt;FloatingBallState&gt;): void

取消闪控球生命周期状态变化的监听事件。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| type | string | 是 | 监听事件，固定为'stateChange'，即闪控球生命周期状态变化事件。 |
| callback | Callback&lt;[FloatingBallState](#floatingballstate)&gt; | 否 | 回调函数。返回当前的闪控球生命周期状态。若传入参数，则停止该监听。若未传入参数，则停止所有闪控球生命周期状态变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**示例：**

```ts
// 定义状态变化回调函数（需与注册时的回调一致）
let onStateChange = (state: floatingBall.FloatingBallState) => {
  console.info('Floating ball stateChange: ' + state);
};
try {
  // 取消闪控球状态变化监听
  floatingBallController.off('stateChange', onStateChange);
} catch (e) {
  console.error(`Failed to off stateChange floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### on('click')

on(type: 'click', callback: Callback&lt;void&gt;): void

注册闪控球的点击监听事件，不使用时，取消监听以避免内存泄漏。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| type | string | 是 | 监听事件，固定为'click'，即闪控球点击事件。 |
| callback | Callback&lt;void&gt; | 是 | 回调函数。当点击闪控球事件发生时的回调。该回调函数不返回任何参数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**示例：**

```ts
// 定义点击事件回调函数
let onClick = () => {
  console.info('Floating ball onClick');
};
try {
  // 注册闪控球点击监听
  floatingBallController.on('click', onClick);
} catch (e) {
  console.error(`Failed to on click floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### off('click')

off(type: 'click', callback?: Callback&lt;void&gt;): void

取消闪控球点击的监听事件。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| type | string | 是 | 监听事件，固定为'click'，即闪控球点击事件。 |
| callback | Callback&lt;void&gt; | 否 | 回调函数。当点击闪控球事件发生时的回调。该回调函数不返回任何参数。若传入参数，则关闭特定的监听。若未传入参数，则关闭所有闪控球点击的监听。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |

**示例：**

```ts
// 定义点击事件回调函数（需与注册时的回调一致）
let onClick = () => {
  console.info('Floating ball onClick');
};
try {
  // 取消闪控球点击监听
  floatingBallController.off('click', onClick);
} catch (e) {
  console.error(`Failed to off click floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### getFloatingBallWindowInfo

getFloatingBallWindowInfo(): Promise&lt;FloatingBallWindowInfo&gt;

获取闪控球窗口信息，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;[FloatingBallWindowInfo](#floatingballwindowinfo)&gt; | Promise对象，返回闪控球窗口信息。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |
| 1300025 | The floating ball state does not support this operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 获取闪控球窗口信息
floatingBallController.getFloatingBallWindowInfo().then((data: floatingBall.FloatingBallWindowInfo) => {
  console.info('Succeeded in getting floating ball window info. Info: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to get floating ball window info. Cause code: ${err.code}, message: ${err.message}`);
});
```

### restoreMainWindow

restoreMainWindow(want: Want): Promise&lt;void&gt;

恢复应用主窗口并加载指定页面。使用Promise异步回调。仅支持在点击闪控球后调用；若应用拥有`ohos.permission.AUTO_RESTORE_MAIN_WINDOW`权限，可以无需点击直接调用该接口。

**需要权限：** ohos.permission.USE_FLOAT_BALL

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 加载指定页面的Want。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 201 | Permission verification failed, usually returned by VerifyAccessToken. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300019 | Wrong parameters for operating the floating ball. |
| 1300023 | Floating ball internal error. |
| 1300024 | The floating ball window state is abnormal. |
| 1300025 | The floating ball state does not support this operation. |
| 1300026 | Failed to restore the main window. Possible causes: </br>1. Invalid parameter. The provided bundleName does not match the caller's application bundleName.</br>2. The application lacks the ohos.permission.AUTO_RESTORE_MAIN_WINDOW permission, and no user interaction (click) on the floating ball has occurred. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

// 配置要恢复的主窗口Want参数
let want: Want = {
  bundleName: 'xxx.xxx.xxx',
  abilityName: 'EntryAbility'
};
try {
  // 恢复应用主窗口并加载指定页面
  floatingBallController.restoreMainWindow(want).then(() => {
    console.info('Succeeded in restoring floating ball main window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to restore floating ball main window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (e) {
  console.error(`Failed to restore floating ball main window. Cause:${e.code}, message:${e.message}`);
}
```

### setFloatingBallVisibilityInApp<sup>24+</sup>

setFloatingBallVisibilityInApp(isVisible: boolean): Promise&lt;void&gt;

设置闪控球在应用内是否可见。使用Promise异步回调。
- 当应用处于多任务界面时（[生命周期状态](../../windowmanager/window-lifecycle.md#应用主窗的生命周期状态)为PAUSED），闪控球不可见。
- 默认情况（即未调用此接口设置时）和调用此接口传入true时：除多任务界面外，闪控球均可见。
- 调用此接口传入false时：当应用处于前台（[生命周期状态](../../windowmanager/window-lifecycle.md#应用主窗的生命周期状态)为SHOWN或者RESUMED）时，闪控球不可见；当应用处于后台（[生命周期状态](../../windowmanager/window-lifecycle.md#应用主窗的生命周期状态)为HIDDEN）时，闪控球可见。

**系统能力：** SystemCapability.Window.SessionManager

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| isVisible | boolean | 是 | true表示闪控球在应用内可见；false表示闪控球在应用内不可见。|

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300023 | Floating ball internal error. Possible cause: The floating ball controller is null. |
| 1300024 | The floating ball window state is abnormal. Possible causes: The floating ball window has not been created or has been destroyed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置闪控球在应用内不可见
floatingBallController?.setFloatingBallVisibilityInApp(false).then(() => {
  console.info('Succeeded in setting floating ball visibility.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set floating ball visibility. Cause code: ${err.code}, message: ${err.message}`);
});
```

### onDestroy

onDestroy(callback: Callback&lt;string&gt;): void

注册闪控球销毁事件的监听。当闪控球销毁时，回调函数会接收到销毁原因的字符串。不再使用时，调用[offDestroy](#offdestroy)接口取消监听以避免内存泄漏。

**系统能力：** SystemCapability.Window.SessionManager

**模型约束：** 此接口仅可在Stage模型下使用。

**起始版本：** 26.0.0

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| callback | Callback&lt;string&gt; | 是 | 回调函数。返回闪控球停止的原因。停止原因包括：<br>- "APP_STOP"：应用主动停止。<br>- "DUMPSTER_STOP"：拖动到垃圾桶触发停止。<br>- "LONG_PRESS_SINGLE_STOP"：长按单个闪控球触发停止。<br>- "LONG_PRESS_ALL_STOP"：长按全部闪控球触发停止。<br>- "MAIN_WINDOW_DESTROY_STOP"：context关联的主窗口被销毁后触发停止。<br>- "SQUEEZE"：超出设备闪控球数量上限，被其他闪控球挤占停止。<br>- "FLOAT_VIEW_STOP"：与闪控窗绑定后，绑定状态下跟随闪控窗停止。<br>- "STOP_IN_SIDEBAR"：在侧边栏中被停止。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. Possible cause: Callback is null or not callable. |
| 1300022 | Repeated floating ball operation. |
| 1300023 | Floating ball internal error. Possible cause: System error, such as a null pointer, insufficient memory. |
| 1300024 | The floating ball window state is abnormal. Possible cause: The floating ball controller has been destroyed. |

**示例：**

```ts
// 定义销毁事件回调函数
let onDestroy = (reason: string) => {
  console.info('Floating ball has destroyed, reason: ' + reason);
};
try {
  // 注册闪控球销毁事件监听
  floatingBallController?.onDestroy(onDestroy);
} catch (e) {
  console.error(`Failed to onDestroy floating ball. Cause:${e.code}, message:${e.message}`);
}
```

### offDestroy

offDestroy(callback?: Callback&lt;string&gt;): void

取消闪控球销毁事件的监听。

**系统能力：** SystemCapability.Window.SessionManager

**模型约束：** 此接口仅可在Stage模型下使用。

**起始版本：** 26.0.0

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| callback | Callback&lt;string&gt; | 否 | 回调函数。若传入参数，则取消该监听；若未传入参数，则取消所有闪控球销毁事件的监听。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300019 | Wrong parameters for operating the floating ball. Possible cause: Callback is null or not callable. |
| 1300023 | Floating ball internal error. Possible cause: System error, such as a null pointer, insufficient memory. |
| 1300024 | The floating ball window state is abnormal. Possible cause: The floating ball controller has been destroyed. |

**示例：**

```ts
// 定义销毁事件回调函数（需与注册时的回调一致）
let onDestroy = (reason: string) => {
  console.info('Floating ball has destroyed, reason: ' + reason);
};
try {
  // 取消闪控球销毁事件监听
  floatingBallController?.offDestroy(onDestroy);
} catch (e) {
  console.error(`Failed to offDestroy floating ball. Cause:${e.code}, message:${e.message}`);
}
// 取消所有监听
try {
  floatingBallController?.offDestroy();
} catch (e) {
  console.error(`Failed to offDestroy all listeners. Cause:${e.code}, message:${e.message}`);
}
```

## FloatingBallParams

启动和更新闪控球的配置参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| template | [FloatingBallTemplate](#floatingballtemplate) | 否 | 否 | 闪控球模板。不同模板对其他参数有不同要求，详见FloatingBallTemplate枚举说明。 |
| title | string | 否 | 否 | 闪控球标题，不可为空字符串，大小不超过64字节。传入空字符串或超过64字节时返回错误码[1300019](errorcode-window.md#1300019-闪控球参数校验错误)。 |
| content | string | 否 | 是 | 闪控球内容，大小不超过64字节。不传入时默认为空字符串，不显示闪控球内容。超过64字节时返回错误码[1300019](errorcode-window.md#1300019-闪控球参数校验错误)。 |
| backgroundColor | string | 否 | 是 | 闪控球背景颜色，为不带透明度的十六进制颜色格式（例如'#008EF5'或'#FF008EF5'）。格式错误时返回错误码[1300019](errorcode-window.md#1300019-闪控球参数校验错误)。不传入时闪控球跟随系统深浅色模式的默认背景色。 |
| titleColor | string | 否 | 是 | 闪控球标题文字颜色，为不带透明度的十六进制颜色格式（例如'#008EF5'或'#FF008EF5'），不传入时根据背景色色度自动填充，若背景色为亮色则填充黑色('#E5000000')，若背景色为暗色则填充白色('#E5FFFFFF')。配置此属性时，必须配置背景色backgroundColor，否则返回错误码[1300019](errorcode-window.md#1300019-闪控球参数校验错误)。<br>**起始版本**：26.0.0 <br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| contentColor | string | 否 | 是 | 闪控球内容文字颜色，为不带透明度的十六进制颜色格式（例如'#008EF5'或'#FF008EF5'），不传入时根据背景色色度自动填充，若背景色为亮色则填充黑色('#99000000')，若背景色为暗色则填充白色('#99FFFFFF')。配置此属性时，必须配置背景色backgroundColor，否则返回错误码[1300019](errorcode-window.md#1300019-闪控球参数校验错误)。<br>**起始版本**：26.0.0 <br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| icon | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否 | 是 | 闪控球图标，图标像素的总字节数不超过192KB（图标像素的总字节数通过[getPixelBytesNumber](../apis-image-kit/arkts-apis-image-PixelMap.md#getpixelbytesnumber7)获取），超过192KB时返回错误码[1300019](errorcode-window.md#1300019-闪控球参数校验错误)。建议图标像素宽高为128px*128px。实际显示效果依赖于设备能力和闪控球UI样式。 |
| textUpdateAnimationType | [FloatingBallTextUpdateAnimationType](#floatingballtextupdateanimationtype) | 否 | 是 | 闪控球文本更新时的动画类型。默认为FloatingBallTextUpdateAnimationType.ANIMATION_NONE。<br>**起始版本**：26.0.0 <br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## FloatingBallState

闪控球生命周期状态的枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
|------------|------------|------------|
| STARTED | 1 | 表示闪控球启动。 |
| STOPPED | 2 | 表示闪控球停止。 |

## FloatingBallTemplate

闪控球模板类型的枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
|------------|------------|------------|
| STATIC | 1 | 静态布局，支持标题和图标。使用此模板时，FloatingBallParams中的title参数和icon参数必传。 |
| NORMAL | 2 | 普通文本布局，支持标题和内容。使用此模板时，FloatingBallParams中的title参数必传。 |
| EMPHATIC | 3 | 强调文本布局，支持图标、标题和内容。使用此模板时，FloatingBallParams中的title参数必传。 |
| SIMPLE | 4 | 纯文本布局，只支持标题。使用此模板时，FloatingBallParams中的title参数必传。 |

## FloatingBallWindowInfo

闪控球窗口信息。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| windowId | number | 是 | 否 | 闪控球窗口ID。 |

## FloatingBallTextUpdateAnimationType

闪控球文本更新动画类型的枚举。

**系统能力：** SystemCapability.Window.SessionManager

**模型约束：** 此接口仅可在Stage模型下使用。

**起始版本**：26.0.0

| 名称 | 值 | 说明 |
|------------|------------|------------|
| ANIMATION_NONE | 0 | 无动画。 |
| ANIMATION_OPACITY | 1 | 淡入淡出动画。 |