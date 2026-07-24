# @ohos.window.floatView (闪控窗)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @betafringe007-->
<!--Designer: @loumou-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

闪控窗是悬浮在桌面/应用界面上的小型窗口，提供灵活的窗口管理能力。

本模块提供闪控窗能力，包括判断设备是否支持闪控窗功能、创建闪控窗控制器以启动、更新或停止闪控窗等。

**适用场景：**

闪控窗适用于需要在独立小窗口中持续展示应用内容或提供快捷操作的场景。例如：
- 股市盯盘应用：用户在浏览其他应用时，通过闪控窗实时查看股票行情变化，无需频繁切换应用。
- 手机直播应用：主播在直播过程中使用闪控窗展示自定义的互动面板或控制界面，方便实时操作和互动。

**闪控窗和闪控球对比**

- 共同点：闪控窗和[闪控球](js-apis-floatingBall.md)均为一种特殊的应用辅助窗口，具备在应用主窗口和对应UIAbility（应用组件）退至后台后仍然可以在前台显示的能力。可以用于应用退至后台后，使用闪控窗或闪控球继续显示UI。
- 区别：
  - 显示形式不同。闪控球以小圆球的形式展现，适用于展示关键信息。闪控窗以小型窗口展示，展示区域较大，可以持续展示应用内容或提供快捷操作。
  - 闪控球只能贴边展示，闪控窗则没有此限制。
  - 闪控球模板固定，应用不能定制UI。闪控窗同样存在模板，并由系统管理并统一绘制UI，但是提供了可绘制的区域，可供应用加载指定页面内容。

**与闪控球联动：**

本模块可与[@ohos.window.floatingBall](js-apis-floatingBall.md)（闪控球）联合使用。通过[floatView.bind](#floatviewbind)接口将闪控窗控制器与闪控球控制器绑定后，用户点击闪控球可展开为闪控窗，点击闪控窗左上角的缩小按钮可收起为闪控球，实现两种窗口形态的相互切换。

**全局悬浮窗和闪控窗对比**

- 共同点：全局悬浮窗和闪控窗均为一种特殊的应用辅助窗口，具备在应用主窗口和对应UIAbility退至后台后仍然可以在前台显示的能力。可以用于应用退至后台后，使用全局悬浮窗或闪控窗继续显示UI。
- 区别：
  - 全局悬浮窗由开发者管理并实现UI绘制，无统一UI及动效。
  - 闪控窗由系统管理并统一绘制UI，动效更为高端精致。
  - 闪控窗支持与[闪控球](js-apis-floatingBall.md)互相绑定联合使用，实现更复杂场景。

**起始版本：** 26.0.0

> **说明：**
>
> - 针对系统能力SystemCapability.Window.SessionManager，请先使用[canIUse()](../common/js-apis-syscap.md#caniuse)接口判断当前设备是否支持此syscap及对应接口。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { floatView } from '@kit.ArkUI';
```

## floatView.isFloatViewEnabled

isFloatViewEnabled(): boolean

判断当前设备是否支持闪控窗功能。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Window.SessionManager

**模型约束：** 此接口仅可在Stage模型下使用。

**返回值：**

| 类型 | 说明 |
|------------|------------|
| boolean  | 当前设备是否支持闪控窗功能。true表示支持，false则表示不支持。 |

**示例：**

```ts
// 判断当前设备是否支持闪控窗功能
let enable: boolean = floatView.isFloatViewEnabled();
console.info('Float view enabled is: ' + enable);
```

## floatView.create

create(config: FloatViewConfiguration): Promise&lt;FloatViewController&gt;

创建闪控窗控制器。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| config | [FloatViewConfiguration](#floatviewconfiguration) | 是 | 创建闪控窗控制器的参数。该参数及其context字段不能为null或undefined，否则抛出401。其他参数异常情况抛出1300016。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;[FloatViewController](#floatviewcontroller)&gt; | Promise对象。返回当前创建的闪控窗控制器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 801 | Capability not supported. Possible cause: Call the API on unsupported device. |
| 1300002 | This window state is abnormal. Possible cause: 1. This window context is abnormal. 2. System error, such as a null pointer, insufficient memory or a JS engine exception. |
| 1300016 | Parameter error. Possible cause: Invalid template type. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { floatView } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private floatViewController: floatView.FloatViewController | undefined = undefined;
  aboutToAppear(): void {
    // 请在组件内获取context，确保this.getUIContext().getHostContext()返回的结果为UIAbilityContext
    let ctx = this.getUIContext().getHostContext() as common.UIAbilityContext;
    // 创建闪控窗配置对象
    let config: floatView.FloatViewConfiguration = {
      context: ctx,
      templateType: floatView.FloatViewTemplateType.ROUNDED_RECTANGLE
    };
    try {
      // 创建闪控窗控制器
      floatView.create(config).then((data: floatView.FloatViewController) => {
        this.floatViewController = data;
        console.info(`Succeeded in creating float view controller. Data: ${data}`);
      }).catch((err: BusinessError): void => {
        console.error(`Failed to create float view controller. Cause:${err.code}, message:${err.message}`);
      });
    } catch (e) {
      console.error(`Failed to create float view controller. Cause:${e.code}, message:${e.message}`);
    }
  }
}
```

## floatView.bind

bind(floatViewController: FloatViewController, floatingBallController: floatingBall.FloatingBallController, floatingBallParams: floatingBall.FloatingBallParams): Promise&lt;void&gt;

绑定闪控窗和闪控球。需要先创建[闪控窗控制器](#floatviewcontroller)和[闪控球控制器](js-apis-floatingBall.md#floatingballcontroller)，且均未启动。使用Promise异步回调。

> **说明：**
>
> - 绑定成功后，调用[start()](#start)或[startFloatingBall()](js-apis-floatingBall.md#startfloatingball)均会同时创建闪控窗窗口和闪控球窗口，并触发对应窗口已注册的状态回调。但同一时刻仅展示其中一个窗口，展示顺序取决于先调用哪个控制器的启动接口。
> - 绑定成功后，用户可通过点击操作在闪控窗窗口与闪控球之间进行切换。
> - 绑定成功后，调用任一控制器的停止接口（[stop()](#stop)或[stopFloatingBall()](js-apis-floatingBall.md#stopfloatingball)）会同时销毁闪控窗窗口和闪控球窗口，并触发对应窗口已注册的状态回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.USE_FLOAT_BALL 和 ohos.permission.FLOAT_VIEW

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| floatViewController | [FloatViewController](#floatviewcontroller) | 是 | 闪控窗控制器，用于管理闪控窗的启动、停止和状态监听等操作。 |
| floatingBallController | [floatingBall.FloatingBallController](js-apis-floatingBall.md#floatingballcontroller) | 是 | 闪控球控制器，用于管理闪控球的启动、停止和状态监听等操作。 |
| floatingBallParams | [floatingBall.FloatingBallParams](js-apis-floatingBall.md#floatingballparams) | 是 | 闪控球参数。绑定时设置的参数会覆盖掉闪控球控制器启动时已保存的参数。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 201 | Permission verification failed. Possible cause: The application does not have the permission required to call the API. |
| 801 | Capability not supported on this device. Possible cause: Call api on unsupported device. |
| 1300019 | Wrong parameters for operating the floating ball. Possible cause: Invalid floating ball params. |
| 1300025 | The floating ball state does not support this operation. Possible cause: 1. The floating ball has started but not stopped yet. 2. The floating ball controller has been bound. |
| 1300031 | The floatView state does not support this operation. Possible cause: 1. The float view has started but not stopped yet. 2. The float view controller has been bound. |

**示例：**

```ts
// Entry.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { floatingBall, floatView } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private floatingBallController: floatingBall.FloatingBallController | undefined = undefined;
  private floatViewController: floatView.FloatViewController | undefined = undefined;
  // 创建控制器
  // ...
  public bindController(): void {
    let floatingBallParams: floatingBall.FloatingBallParams = {
      template: floatingBall.FloatingBallTemplate.EMPHATIC,
      title: 'title',
      content: 'content'
    };

    try {
      if (this.floatViewController && this.floatingBallController) {
        // 绑定闪控窗和闪控球
        floatView.bind(this.floatViewController!, this.floatingBallController!, floatingBallParams).then(() => {
          console.info('Succeeded in binding float view and floating ball.');
        }).catch((err: BusinessError): void => {
          console.error(`Failed to bind float view and floating ball. Cause:${err.code}, message:${err.message}`);
        });
      }
    } catch (e) {
      console.error(`Failed to bind float view and floating ball. Cause:${e.code}, message:${e.message}`);
    }
  }
}
```

## floatView.unbind

unbind(floatViewController: FloatViewController, floatingBallController: floatingBall.FloatingBallController): Promise&lt;void&gt;

解绑闪控窗和闪控球。需要在[闪控窗控制器](#floatviewcontroller)和[闪控球控制器](js-apis-floatingBall.md#floatingballcontroller)均停止后才可解绑。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| floatViewController | [FloatViewController](#floatviewcontroller) | 是 | 闪控窗控制器，用于管理闪控窗的启动、停止和状态监听等操作。 |
| floatingBallController | [floatingBall.FloatingBallController](js-apis-floatingBall.md#floatingballcontroller) | 是 | 闪控球控制器，用于管理闪控球的启动、停止和状态监听等操作。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 801 | Capability not supported on this device. Possible cause: Call api on unsupported device. |
| 1300025 | The floating ball state does not support this operation. Possible cause: 1. The floating ball has started but not stopped yet. 2. The floatingBallController has not been bound. |
| 1300031 | The floatView state does not support this operation. Possible cause: 1. The float view has started but not stopped yet. 2. The floatViewController has not been bound. 3. The floatViewController and the floatingBallController are not bound together. |

**示例：**

```ts
// Entry.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { floatingBall, floatView } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private floatingBallController: floatingBall.FloatingBallController | undefined = undefined;
  private floatViewController: floatView.FloatViewController | undefined = undefined;
  // 创建控制器
  // ...
  public unbindController(): void {
    try {
      // 使用绑定时传入的闪控窗和闪控球控制器
      if (this.floatViewController && this.floatingBallController) {
        // 解绑闪控窗和闪控球
        floatView.unbind(this.floatViewController!, this.floatingBallController!).then(() => {
          console.info('Succeeded in unbinding float view and floating ball.');
        }).catch((err: BusinessError): void => {
          console.error(`Failed to unbind float view and floating ball. Cause:${err.code}, message:${err.message}`);
        });
      }
    } catch (e) {
      console.error(`Failed to unbind float view and floating ball. Cause:${e.code}, message:${e.message}`);
    }
  }
}
```

## floatView.getFloatViewLimits

getFloatViewLimits(templateType: FloatViewTemplateType): FloatViewLimits

根据传入的模板类型获取对应闪控窗窗口的限制，单位为px。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| templateType | [FloatViewTemplateType](#floatviewtemplatetype) | 是 | 闪控窗模板类型。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| [FloatViewLimits](#floatviewlimits) | 返回闪控窗窗口的限制，包括最大尺寸、最小尺寸和宽高比的限制范围。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 801 | Capability not supported. Possible cause: Call the API on unsupported device. |
| 1300002 | This window state is abnormal. Possible cause: System error, such as a null pointer, insufficient memory or a JS engine exception. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300016 | Parameter error. Possible cause: Invalid template type. |

**示例：**

```ts
// 获取圆角矩形模板的闪控窗窗口限制
let limits: floatView.FloatViewLimits = floatView.getFloatViewLimits(floatView.FloatViewTemplateType.ROUNDED_RECTANGLE);
console.info('Float view limits: ' + JSON.stringify(limits));
```

## FloatViewConfiguration

创建闪控窗控制器时需要提供的参数配置。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| context | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 否 | 否 | 表示上下文环境，用于创建闪控窗控制器时关联应用主窗口。必须传入有效的UIAbilityContext实例。 |
| templateType | [FloatViewTemplateType](#floatviewtemplatetype) | 否 | 否 | 闪控窗的模板类型。 |
| isConfirmOnClose | boolean | 否 | 是 | 点击关闭按钮时是否需要用户确认。true表示点击关闭按钮时需要用户确认，否则不需要确认。默认值为false。 |

## TemplateProperty

切换闪控窗模板并修改窗口尺寸时需要提供的参数配置。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| templateType | [FloatViewTemplateType](#floatviewtemplatetype) | 否 | 否 | 闪控窗的模板类型。 |
| size | [window.Size](arkts-apis-window-i.md#size7) | 否 | 否 | 更新模板类型时需要提供的窗口尺寸。 |

## FloatViewController

闪控窗控制器实例。用于启动、停止闪控窗以及注册回调等操作。

下列API示例中都需先使用[floatView.create()](#floatviewcreate)方法获取到闪控窗控制器实例（即floatViewController），再通过此实例调用对应方法。

**模型约束：** 此接口仅可在Stage模型下使用。

### setUIContext

setUIContext(path: string, storage?: LocalStorage): Promise&lt;void&gt;

根据当前工程中指定的页面路径为闪控窗加载具体页面内容，通过LocalStorage传递状态属性至加载页面。使用Promise异步回调。

建议在闪控窗启动前使用该接口，重复调用将先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

本接口不支持加载跨包页面，若有需要请使用[setUIContextByName()](#setuicontextbyname)接口。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| path | string | 是 | 要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。不支持相对路径写法，需与main_pages.json中的src取值保持一致。若路径无效或不满足上述要求，将抛出错误码1300016。 |
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | 否 | 页面级UI状态存储单元，用于为加载到窗口的页面内容传递状态属性。默认值为空。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300016 | Parameter error. Possible causes: Invalid path. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { floatView } from '@kit.ArkUI';

try {
  // floatViewController需通过floatView.create()获取，详见floatView.create()示例
  // 设置闪控窗的页面内容路径
  this.floatViewController?.setUIContext('pages/Index').then(() => {
    console.info('Succeeded in setting UI context.');
  }).catch((err: BusinessError): void => {
    console.error(`Failed to set UI context. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to set UI context. Cause:${e.code}, message:${e.message}`);
}
```

### setUIContextByName

setUIContextByName(name: string, storage?: LocalStorage): Promise&lt;void&gt;

根据指定路由页面名称为当前窗口加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，通过LocalStorage传递状态属性至加载页面，使用Promise异步回调。

建议在闪控窗启动前使用该接口，重复调用将先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| name | string | 是 | 命名路由页面的名称，用于加载指定的命名路由页面内容。需与@Entry装饰器中routeName参数指定的名称一致。 |
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | 否 | 页面级UI状态存储单元，用于为加载到窗口的页面内容传递状态属性。默认值为空。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300016 | Parameter error. Possible causes: Invalid name. |

**示例：**

<!--code_no_check-->
```ts
// Index.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { entryName } from './Hello'; // 导入命名路由页面
import { floatView } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private floatViewController: floatView.FloatViewController | undefined = undefined;
  // 创建控制器
  // ...
  public setUIContextByName(): void {
    try {
      // 根据命名路由名称设置闪控窗的页面内容
      this.floatViewController?.setUIContextByName(entryName).then(() => {
        console.info('Succeeded in loading the content.');
      }).catch((err: BusinessError): void => {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (e) {
      console.error(`Failed to load the content. Cause code: ${e.code}, message: ${e.message}`);
    }
  }
}
```
<!--code_no_check-->
```ts
// Hello.ets
export const entryName : string = 'Hello';
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Hello {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### setWindowSize

setWindowSize(size: window.Size): Promise&lt;void&gt;

设置闪控窗窗口大小。建议先调用[getFloatViewLimits](#floatviewgetfloatviewlimits)接口获取推荐的宽高范围和宽高比范围，再根据推荐值调用本接口。窗口实际大小变化可通过[onRectChange](#onrectchange)接口监听。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| size | [window.Size](arkts-apis-window-i.md#size7) | 是 | 表示窗口的大小，单位为px，宽度和高度必须大于0，超出有效范围时抛出错误码1300016。建议大小满足[getFloatViewLimits](#floatviewgetfloatviewlimits)接口返回的限制。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300016 | Parameter error. Possible cause: The value of the size is less than or equal to 0. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { floatView, window } from '@kit.ArkUI';

// 设置窗口大小
let size: window.Size = {
  width: 400,
  height: 600
};
try {
  // 设置闪控窗窗口大小
  this.floatViewController?.setWindowSize(size).then(() => {
    console.info('Succeeded in setting window size.');
  }).catch((err: BusinessError): void => {
    console.error(`Failed to set window size. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to set window size. Cause:${e.code}, message:${e.message}`);
}
```

### switchTemplate

switchTemplate(templateProperty: TemplateProperty): Promise&lt;void&gt;

切换闪控窗的模板并改变其窗口尺寸。建议先调用[getFloatViewLimits](#floatviewgetfloatviewlimits)接口获取目标模板类型推荐的宽高范围和宽高比范围，再根据推荐值调用本接口。窗口实际大小变化可通过[onRectChange](#onrectchange)接口监听。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| templateProperty | [TemplateProperty](#templateproperty) | 是 | 表示需要切换的窗口模板类型及大小。size中的宽度和高度必须大于0，超出有效范围时抛出错误码1300016。建议大小满足[getFloatViewLimits](#floatviewgetfloatviewlimits)接口返回的限制。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300016 | Parameter error. Possible cause: 1. Invalid template type. 2. The value of the size is less than or equal to 0. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { floatView, window } from '@kit.ArkUI';

// 设置新窗口大小
let newSize: window.Size = {
  width: 800,
  height: 100
};
// 设置模板属性
let templateProperty: floatView.TemplateProperty = {
  templateType: floatView.FloatViewTemplateType.HORIZONTAL_BAR,
  size: newSize
};
try {
  // 切换闪控窗模板并改变窗口尺寸
  this.floatViewController?.switchTemplate(templateProperty).then(() => {
    console.info('Succeeded in switching window type and size.');
  }).catch((err: BusinessError): void => {
    console.error(`Failed to switch window type and size. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to switch window type and size. Cause:${e.code}, message:${e.message}`);
}
```

### start

start(): Promise&lt;void&gt;

启动闪控窗窗口。接口返回不表示start流程结束，需要通过[onStateChange](#onstatechange)接口监听到STARTED回调时判断启动成功。建议在调用[setUIContext()](#setuicontext)或[setUIContextByName()](#setuicontextbyname)后调用start()。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.FLOAT_VIEW

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 201 | Permission verification failed. Possible cause: The application does not have the permission required to call the API. |
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300030 | Repeated operations on the float view. Possible cause: The float view is starting or has already started. |
| 1300031 | The float view state does not support this operation. Possible cause: The float view is stopping. |
| 1300033 | Failed to start float view. Possible causes: 1. Start multiple float views. 2. The main window of context is not foreground. |
| 1300034 | This operation conflicts with other floating windows. Possible cause: App has already started floating ball or pip window. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { floatView } from '@kit.ArkUI';

try {
  // 启动闪控窗
  this.floatViewController?.start().then(() => {
    console.info('Succeeded in starting float view.');
  }).catch((err: BusinessError): void => {
    console.error(`Failed to start float view. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to start float view. Cause:${e.code}, message:${e.message}`);
}
```

### stop

stop(): Promise&lt;void&gt;

停止闪控窗窗口。接口返回不表示stop流程结束，需要通过[onStateChange](#onstatechange)接口监听到STOPPED回调时判断停止成功。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300030 | Repeated operations on the float view. Possible cause: The float view is stopping or has already stopped. |
| 1300031 | This operation is not supported on the float view in the current state. Possible cause: The float view window is not started. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { floatView } from '@kit.ArkUI';

try {
  // 停止闪控窗
  this.floatViewController?.stop().then(() => {
    console.info('Succeeded in stopping float view.');
  }).catch((err: BusinessError): void => {
    console.error(`Failed to stop float view. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to stop float view. Cause:${e.code}, message:${e.message}`);
}
```

### setFloatViewVisibilityInApp

setFloatViewVisibilityInApp(isVisible: boolean): Promise&lt;void&gt;

设置应用在前台时闪控窗窗口是否可见。使用Promise异步回调。

创建闪控窗后未调用此接口前，默认其在应用处于前台时为可见状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| isVisible | boolean | 是 | 应用在前台时闪控窗是否可见，true表示可见，false表示不可见。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { floatView } from '@kit.ArkUI';

try {
  // 设置应用在前台时闪控窗可见
  this.floatViewController?.setFloatViewVisibilityInApp(true).then(() => {
    console.info('Succeeded in setting float view visibility in app.');
  }).catch((err: BusinessError): void => {
    console.error(`Failed to set float view visibility in app. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to set float view visibility in app. Cause:${e.code}, message:${e.message}`);
}
```

### restoreMainWindow

restoreMainWindow(wantParameters?: Record&lt;string, Object&gt;): Promise&lt;void&gt;

恢复闪控窗的主窗口到前台显示。如果主窗口已处于前台时调用，将抬升主窗口层级。此接口要求闪控窗处于STARTED状态，且只能在用户点击闪控窗窗口后调用。当主窗口处于PAUSED生命周期或处于多任务状态时，调用接口将抛出错误码1300032。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| wantParameters | Record&lt;string, Object&gt; | 否 | 恢复闪控窗的主窗口时会给主窗口传递的自定义参数，主窗口会在触发[onNewWant](../apis-ability-kit/js-apis-app-ability-abilityLifecycleCallback.md#onnewwant12)回调时收到。默认值为空，代表不向主窗口传入任何自定义参数。 |

**返回值：**

| 类型 | 说明 |
|------------|------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300031 | This operation is not supported on the float view in the current state. Possible cause: The float view window is not started when restoring. |
| 1300032 | Failed to restore the main window. Possible cause: 1. User has never clicked the float view window before restore. 2. The float view window is not in the foreground. 3. The main window is in PAUSED lifecycle state. 4. The main window is in background during recent. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { floatView } from '@kit.ArkUI';

// 创建恢复主窗口的参数
let param: Record<string, Object> = {
  'info': 'helloworld',
};
// 闪控窗状态需是STARTED
try {
  // 恢复闪控窗的主窗口到前台显示
  this.floatViewController?.restoreMainWindow(param).then(() => {
    console.info('Succeeded in restoring main window.');
  }).catch((err: BusinessError): void => {
    console.error(`Failed to restore main window. Cause:${err.code}, message:${err.message}`);
  });
} catch (e) {
  console.error(`Failed to restore main window. Cause:${e.code}, message:${e.message}`);
}
```

### getWindowProperties

getWindowProperties(): FloatViewProperties

获取闪控窗窗口的属性。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
|------------|------------|
| [FloatViewProperties](#floatviewproperties) | 返回闪控窗窗口的属性。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300031 | This operation is not supported on the float view in the current state. Possible cause: The float view window has not started, has stopped, or is in an error state. |

**示例：**

```ts
try {
  // 获取闪控窗窗口属性
  let properties: floatView.FloatViewProperties | undefined = this.floatViewController?.getWindowProperties();
  console.info('Float view properties: ' + JSON.stringify(properties));
} catch (e) {
  console.error(`Failed to get window properties. Cause:${e.code}, message:${e.message}`);
}
```

### onStateChange

onStateChange(callback: Callback&lt;FloatViewStateChangeInfo&gt;): void

注册闪控窗状态变化的监听事件。不再使用时，取消监听以避免内存泄漏。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| callback | Callback&lt;[FloatViewStateChangeInfo](#floatviewstatechangeinfo)&gt; | 是 | 回调函数。返回当前的闪控窗状态变化信息。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300030 | Repeated operations on the float view. Possible cause: The callback has already registered. |

**示例：**

```ts
// 定义状态变化回调函数
let onStateChange = (info: floatView.FloatViewStateChangeInfo) => {
  console.info('Float view stateChange: ' + JSON.stringify(info));
};
try {
  // 注册闪控窗状态变化监听
  this.floatViewController?.onStateChange(onStateChange);
} catch (e) {
  console.error(`Failed to on stateChange float view. Cause:${e.code}, message:${e.message}`);
}
```

### offStateChange

offStateChange(callback?: Callback&lt;FloatViewStateChangeInfo&gt;): void

取消闪控窗状态变化的监听事件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| callback | Callback&lt;[FloatViewStateChangeInfo](#floatviewstatechangeinfo)&gt; | 否 | 回调函数。返回当前的闪控窗状态变化信息。若传入参数，则停止该监听。若未传入参数，则停止所有闪控窗状态变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |

**示例：**

```ts
// 定义状态变化回调函数
let onStateChange = (info: floatView.FloatViewStateChangeInfo) => {
  console.info('Float view stateChange: ' + JSON.stringify(info));
};
try {
  // 取消闪控窗状态变化监听
  this.floatViewController?.offStateChange(onStateChange);
} catch (e) {
  console.error(`Failed to off stateChange float view. Cause:${e.code}, message:${e.message}`);
}
```

### onRectChange

onRectChange(callback: Callback&lt;FloatViewRectChangeInfo&gt;): void

注册闪控窗矩形区域（位置和大小）变化的监听事件。不再使用时，取消监听以避免内存泄漏。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| callback | Callback&lt;[FloatViewRectChangeInfo](#floatviewrectchangeinfo)&gt; | 是 | 回调函数。返回当前的闪控窗矩形区域变化信息。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300030 | Repeated operations on the float view. Possible cause: The callback has already registered. |

**示例：**

```ts
// 定义矩形区域变化回调函数
let onRectChange = (info: floatView.FloatViewRectChangeInfo) => {
  console.info('Float view rectChange: ' + JSON.stringify(info));
};
try {
  // 注册闪控窗矩形区域变化监听
  this.floatViewController?.onRectChange(onRectChange);
} catch (e) {
  console.error(`Failed to on rectChange float view. Cause:${e.code}, message:${e.message}`);
}
```

### offRectChange

offRectChange(callback?: Callback&lt;FloatViewRectChangeInfo&gt;): void

取消闪控窗矩形区域变化的监听事件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| callback | Callback&lt;[FloatViewRectChangeInfo](#floatviewrectchangeinfo)&gt; | 否 | 回调函数。返回当前的闪控窗矩形区域变化信息。若传入参数，则停止该监听。若未传入参数，则停止所有闪控窗矩形区域变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |

**示例：**

```ts
// 定义矩形区域变化回调函数
let onRectChange = (info: floatView.FloatViewRectChangeInfo) => {
  console.info('Float view rectChange: ' + JSON.stringify(info));
};
try {
  // 取消闪控窗矩形区域变化监听
  this.floatViewController?.offRectChange(onRectChange);
} catch (e) {
  console.error(`Failed to off rectChange float view. Cause:${e.code}, message:${e.message}`);
}
```

### onLimitsChange

onLimitsChange(callback: Callback&lt;FloatViewLimits&gt;): void

注册闪控窗限制变化的监听事件。当限制规格变化时（例如折叠展开导致屏幕宽度变化或切换模板），触发回调并返回当前窗口模板类型的限制信息。不再使用时，取消监听以避免内存泄漏。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| callback | Callback&lt;[FloatViewLimits](#floatviewlimits)&gt; | 是 | 回调函数。返回当前的闪控窗限制变化信息。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |
| 1300030 | Repeated operations on the float view. Possible cause: The callback has already registered. |

**示例：**

```ts
// 定义限制变化回调函数
let onLimitsChange = (limits: floatView.FloatViewLimits) => {
  console.info('Float view limitsChange: ' + JSON.stringify(limits));
};
try {
  // 注册闪控窗限制变化监听
  this.floatViewController?.onLimitsChange(onLimitsChange);
} catch (e) {
  console.error(`Failed to on limitsChange float view. Cause:${e.code}, message:${e.message}`);
}
```

### offLimitsChange

offLimitsChange(callback?: Callback&lt;FloatViewLimits&gt;): void

取消闪控窗限制变化的监听事件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|------------|------------|------------|------------|
| callback | Callback&lt;[FloatViewLimits](#floatviewlimits)&gt; | 否 | 回调函数。返回当前的闪控窗限制变化信息。若传入参数，则停止该监听。若未传入参数，则停止所有闪控窗限制变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
|------------|------------|
| 1300002 | This window state is abnormal. Possible cause: The float view controller object is null. |

**示例：**

```ts
// 定义限制变化回调函数
let onLimitsChange = (limits: floatView.FloatViewLimits) => {
  console.info('Float view limitsChange: ' + JSON.stringify(limits));
};
try {
  // 取消闪控窗限制变化监听
  this.floatViewController?.offLimitsChange(onLimitsChange);
} catch (e) {
  console.error(`Failed to off limitsChange float view. Cause:${e.code}, message:${e.message}`);
}
```

## FloatViewTemplateType

闪控窗模板类型的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
|------------|------------|------------|
| ROUNDED_RECTANGLE | 0 | 圆角矩形。 |
| HORIZONTAL_BAR | 1 | 水平的条状矩形。 |

## FloatViewProperties

闪控窗窗口的属性。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Window.SessionManager

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| templateType | [FloatViewTemplateType](#floatviewtemplatetype) | 否 | 否 | 闪控窗的模板类型。 |
| windowId | number | 否 | 否 | 闪控窗窗口ID。 |
| displayId | number | 否 | 否 | 闪控窗所在屏幕ID。 |
| windowRect | [window.Rect](arkts-apis-window-i.md#rect7) | 否 | 否 | 闪控窗窗口矩形区域。 |
| windowScale | number | 否 | 否 | 闪控窗窗口缩放比例。 |
| avoidArea | [window.AvoidArea](arkts-apis-window-i.md#avoidarea7) | 否 | 否 | 闪控窗内容的避让区域。<br>**注意：**<br/>通过[setUIContext()](#setuicontext)或[setUIContextByName()](#setuicontextbyname)加载的页面中，位于避让区域的组件将不响应手势事件，开发者在添加需要手势响应事件的组件时，请注意避让这些区域。 |
| inSidebar | boolean | 否 | 否 | 闪控窗是否在侧边栏中。true为在侧边栏中，false为不在侧边栏中。 |

## RatioLimit

闪控窗的宽高比限制范围。宽高比比值由窗口矩形区域的宽除以高获得。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| minRatio | number | 否 | 否 | 闪控窗的宽高比最小值。 |
| maxRatio | number | 否 | 否 | 闪控窗的宽高比最大值。 |

## FloatViewLimits

闪控窗窗口的限制。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| minSize | [window.Size](arkts-apis-window-i.md#size7) | 否 | 否 | 闪控窗的最小尺寸。 |
| maxSize | [window.Size](arkts-apis-window-i.md#size7) | 否 | 否 | 闪控窗的最大尺寸。 |
| ratioLimits | Array&lt;[RatioLimit](#ratiolimit)&gt; | 否 | 否 | 闪控窗的宽高比限制范围，数组中每个元素包含minRatio（最小宽高比）和maxRatio（最大宽高比）。 |

## FloatViewStateChangeInfo

闪控窗状态变化信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| state | [FloatViewState](#floatviewstate) | 否 | 否 | 闪控窗的状态。 |
| stopReason | string | 否 | 否 | 闪控窗停止的原因。该参数仅在状态为FloatViewState.STOPPED时有效，在其他状态下默认为空字符串。停止原因和对应含义如下：<br/>"APP_STOP"：应用主动停止<br/>"STOP_IN_SIDEBAR"：在侧边栏被关闭<br/>"TITLE_BAR_STOP_CLICK"：标题栏点击关闭按钮<br/>"DUMPSTER_STOP"：拖入垃圾桶停止<br/>"REPLACE_STOP"：被其他闪控窗挤占<br/>"FLOATING_BALL_STOP"：绑定状态下跟随闪控球停止 <br/> "MAIN_WINDOW_DESTROY_STOP"：context关联的主窗被销毁后停止 |

## FloatViewState

闪控窗状态的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
|------------|------------|------------|
| STARTED | 1 | 闪控窗已启动并显示。 |
| HIDDEN | 2 | 闪控窗已隐藏。上滑进入多任务界面时触发；或使用[setFloatViewVisibilityInApp](#setfloatviewvisibilityinapp)接口设置应用在前台时隐藏闪控窗后，应用处于前台时触发。 |
| STOPPED | 3 | 闪控窗已停止。 |
| IN_SIDEBAR | 4 | 闪控窗在侧边栏中。 |
| IN_FLOATING_BALL | 5 | 闪控窗切换为闪控球。 |
| ERROR | 6 | 闪控窗发生异常。 |

## FloatViewRectChangeInfo

闪控窗矩形区域变化信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型 | 只读 | 可选 | 说明 |
|------------|------------|------------|------------|------------|
| windowRect | [window.Rect](arkts-apis-window-i.md#rect7) | 否 | 否 | 闪控窗窗口矩形区域。 |
| windowScale | number | 否 | 否 | 闪控窗窗口缩放比例。 |
| reason | string | 否 | 否 | 闪控窗矩形区域变化的原因。原因和对应含义如下：<br/>"POSITION_CHANGE"：位置变化<br/>"SIZE_CHANGE"：大小变化<br/>"RECT_CHANGE"：位置大小同时变化 |