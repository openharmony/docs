# EmbeddedComponent
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

EmbeddedComponent用于支持在当前页面嵌入本应用内或满足跨应用权限条件的其他[EmbeddedUIExtensionAbility](../../apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)提供的UI。EmbeddedUIExtensionAbility在独立进程中运行，完成页面布局和渲染。

通常用于有进程隔离诉求的模块化开发场景。

> **说明：**
>
>- 该组件从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>- 本模块接口仅可在Stage模型下使用。
>
>- API版本26.0.0之前，EmbeddedComponent组件获焦时，其拉起的EmbeddedUIExtensionAbility进程内焦点直接下发到第一个可获焦子节点。从API版本26.0.0开始，
> 如果外部走焦到EmbeddedUIExtensionAbility，焦点正常下发到第一个可获焦子节点。
> 如果由于层级页面切换导致焦点转移到EmbeddedUIExtensionAbility，则采用与UIAbility一致的规则。EmbeddedUIExtensionAbility和UIAbility在拉起一个层级页面且该页面未设置[defaultFocus](ts-universal-attributes-focus.md#defaultfocus9)、未[主动请求焦点](../../../ui/arkts-common-events-focus-event.md#主动获焦失焦)时，焦点均停留在根容器，不下发到子节点。

## 使用约束

EmbeddedComponent仅支持在拥有多进程权限的设备上使用。开发者可通过canIUse相关接口或系统设置查询当前设备是否支持多进程权限。

EmbeddedComponent只能在UIAbility中使用，且默认情况下被拉起的EmbeddedUIExtensionAbility需与UIAbility属于同一应用。从API版本26.0.0开始，在同时满足以下条件时，允许EmbeddedComponent跨应用拉起EmbeddedUIExtensionAbility：
- EmbeddedComponent所属应用申请了ohos.permission.SUPPORT_CROSS_APP_EMBED_FOR_OA权限（该权限仅企业普通应用可申请）；
- 该应用的[appIdentifier](../../../quick-start/common-problem-of-application.md#什么是appidentifier)在EmbeddedUIExtensionAbility支持的应用清单（即[extensionAbilities标签](../../../quick-start/module-configuration-file.md#extensionabilities标签)的appIdentifierAllowList属性）中。

## 子组件

无

## 接口

### EmbeddedComponent

EmbeddedComponent(loader: import('../api/@ohos.app.ability.Want').default, type: EmbeddedType)

创建跨进程嵌入式组件，用于显示同包名或满足跨应用权限条件的EmbeddedUIExtensionAbility的UI。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                | 类型                          | 必填 |说明   |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------------------------ |
| loader                | import('../api/@ohos.app.ability.[Want](../../apis-ability-kit/js-apis-app-ability-want.md)').default | 是   | 要加载的EmbeddedUIExtensionAbility。 |
| type                  | [EmbeddedType](ts-appendix-enums.md#embeddedtype12)                              | 是   | 提供方的类型，当前支持值为[EmbeddedType](ts-appendix-enums.md#embeddedtype12).EMBEDDED_UI_EXTENSION，表示嵌入的是EmbeddedUIExtensionAbility提供的UI。                       |

### EmbeddedComponent

EmbeddedComponent(loader: import('../api/@ohos.app.ability.Want').default, type: EmbeddedType, options?: EmbeddedOptions)

创建跨进程嵌入式组件，用于显示同包名或满足跨应用权限条件的EmbeddedUIExtensionAbility的UI。相对于API version 12的接口，新增options参数用于传递构造参数。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                | 类型                          | 必填 |说明   |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------------------------ |
| loader                | import('../api/@ohos.app.ability.[Want](../../apis-ability-kit/js-apis-app-ability-want.md)').default | 是   | 要加载的EmbeddedUIExtensionAbility。 |
| type                  | [EmbeddedType](ts-appendix-enums.md#embeddedtype12)                              | 是   | 提供方的类型，当前支持值为[EmbeddedType](ts-appendix-enums.md#embeddedtype12).EMBEDDED_UI_EXTENSION，表示嵌入的是EmbeddedUIExtensionAbility提供的UI。                       |
| options| [EmbeddedOptions](#embeddedoptions) | 否   | 嵌入式组件的可选配置项，用于设置占位符、DPI跟随策略、窗口模式跟随策略等。详见[EmbeddedOptions](#embeddedoptions)。                     |

## 属性

支持[通用属性](ts-component-general-attributes.md)。

> **说明：**
>
> EmbeddedComponent组件宽高默认值和最小值均为10vp。不支持如下与宽高相关的属性：“constraintSize”、“aspectRatio”、“layoutWeight”、“flexBasis”、“flexGrow”和“flexShrink”。

## 事件

与屏幕坐标相关的事件信息会基于EmbeddedComponent的位置宽高进行坐标转换后传递给被拉起的EmbeddedUIExtensionAbility处理。

不支持[点击](ts-universal-events-click.md)等通用事件。仅支持以下事件：

### onTerminated

onTerminated(callback: import('../api/@ohos.base').Callback&lt;TerminationInfo&gt;)

被拉起的EmbeddedUIExtensionAbility通过调用[terminateSelfWithResult](../../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#terminateselfwithresult)或者[terminateSelf](../../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#terminateself)正常退出时，触发本回调函数。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------  | ------ | ---------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| callback | import('../api/@ohos.base').[Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](#terminationinfo)> | 是 | 回调函数，入参用于接收EmbeddedUIExtensionAbility的返回结果，类型为[TerminationInfo](#terminationinfo)。 |

> **说明：**
>
> - 若EmbeddedUIExtensionAbility通过调用`terminateSelfWithResult`退出，其携带的信息会传给回调函数的入参；
> - 若EmbeddedUIExtensionAbility通过调用`terminateSelf`退出，上述回调函数的入参中，`code`取默认值`0`，`want`为`undefined`。

### onError

onError(callback: import('../api/@ohos.base').ErrorCallback)

被拉起的EmbeddedUIExtensionAbility在运行过程中发生异常时触发本回调。可通过回调参数中的code、name和message获取错误信息并做处理，业务错误码详细介绍请参见[UIExtension错误码](../errorcode-uiextension.md)。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                                         | 必填                                                                       | 说明      |
| ------ | ---------------------------------------------------------------------------- | --------- | --------- |
| callback    | import('../api/@ohos.base').[ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是 | 回调函数，入参用于接收异常信息，类型为[BusinessError](../../apis-basic-services-kit/js-apis-base.md#businesserror)，可通过参数中的`code`、`name`和`message`获取错误信息并做处理。 |

> **说明：**
>
> 如下情形会触发本回调：
> - 拉起EmbeddedUIExtensionAbility失败。
> - 通知提供方EmbeddedUIExtensionAbility切后台失败。
> - 通知提供方销毁EmbeddedUIExtensionAbility失败。
> - 提供方EmbeddedUIExtensionAbility异常退出。
> - 在EmbeddedUIExtensionAbility中嵌套使用EmbeddedComponent。

### onDrawReady

onDrawReady(callback: Callback\<void>)

被拉起的[EmbeddedUIExtensionAbility](../../apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md#embeddeduiextensionability)绘制第一帧时触发该回调。

> **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                               | 必填 | 说明                                    |
| ------ | ---------------------------------- | ---- | --------------------------------------- |
| callback   | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<void> | 是   | 回调函数，在EmbeddedUIExtensionAbility绘制第一帧时触发。 |

## EmbeddedOptions

用于在EmbeddedComponent创建时传递可选的构造参数。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                               | 类型                                                         | 只读 | 可选 | 说明                                                         |
| ---------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| placeholder                        | [ComponentContent](../js-apis-arkui-ComponentContent.md)     | 否   | 是   | 设置占位符，在EmbeddedComponent与EmbeddedUIExtensionAbility建立连接前显示。<br>默认值：null，表示不显示占位符。 |
| areaChangePlaceholder              | Record\<string, [ComponentContent](../js-apis-arkui-ComponentContent.md)> | 否   | 是   | 设置尺寸变化占位符，在EmbeddedComponent尺寸发生变化并且EmbeddedUIExtensionAbility的内容渲染未完成时显示。key为尺寸变化场景类型（如“FOLD_TO_EXPAND”表示折叠展开场景），value为对应场景的占位符组件。当前支持的键值包括：FOLD_TO_EXPAND。传入不支持的键值时，该占位符不生效。默认值：null，表示不设置尺寸变化占位符。 |
| dpiFollowStrategy                  | [EmbeddedDpiFollowStrategy](#embeddeddpifollowstrategy)    | 否   | 是   | 设置DPI，使其能够跟随宿主或EmbeddedUIExtensionAbility。<br> 默认值：FOLLOW_UI_EXTENSION_ABILITY_DPI，表示跟随EmbeddedUIExtensionAbility。 |
| windowModeFollowStrategy | [EmbeddedWindowModeFollowStrategy](#embeddedwindowmodefollowstrategy) | 否   | 是   | 设置窗口模式，使其能够跟随宿主或EmbeddedUIExtensionAbility。<br> 默认值：FOLLOW_UI_EXTENSION_ABILITY_WINDOW_MODE，表示窗口模式跟随EmbeddedUIExtensionAbility。<br>**起始版本：** 26.0.0 |

## EmbeddedDpiFollowStrategy

DPI跟随策略，用于设置DPI，使其能够跟随宿主或EmbeddedUIExtensionAbility。例如，当EmbeddedUIExtensionAbility需要与宿主应用保持视觉一致性时，可选择跟随宿主DPI；当EmbeddedUIExtensionAbility需要独立适配自身资源的DPI配置时，可选择跟随EmbeddedUIExtensionAbility DPI。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                            | 值 | 说明                               |
| ------------------------------- | -- | ---------------------------------- |
| FOLLOW_HOST_DPI                 | 0  | 表示DPI跟随宿主。                  |
| FOLLOW_UI_EXTENSION_ABILITY_DPI | 1  | 表示DPI跟随EmbeddedUIExtensionAbility。 |

## EmbeddedWindowModeFollowStrategy

窗口模式跟随策略，用于设置窗口模式跟随宿主或EmbeddedUIExtensionAbility。例如，当EmbeddedUIExtensionAbility需要与宿主应用保持一致的窗口模式（如全屏、分屏）时，可选择跟随宿主；当EmbeddedUIExtensionAbility需要独立控制窗口模式时，可选择跟随EmbeddedUIExtensionAbility。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                                    | 值 | 说明                                        |
| --------------------------------------- | -- | ------------------------------------------- |
| FOLLOW_HOST_WINDOW_MODE                 | 0  | 表示窗口模式跟随宿主。                      |
| FOLLOW_UI_EXTENSION_ABILITY_WINDOW_MODE | 1  | 表示窗口模式跟随EmbeddedUIExtensionAbility。 |

## TerminationInfo

用于表示被拉起的EmbeddedUIExtensionAbility的返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                      | 只读 | 可选 | 说明                                                 |
| ---- | -------------------------| ---- | ---- | ---------------------------------------------------- |
| code | number                                                     | 否 | 否 | 被拉起的EmbeddedUIExtensionAbility退出时返回的结果码，由`terminateSelfWithResult`或者`terminateSelf`被调用时传入的数据决定。若通过`terminateSelf`退出，code取默认值0。 |
| want | import('../api/@ohos.app.ability.[Want](../../apis-ability-kit/js-apis-app-ability-want.md)').default | 否 | 是 | 被拉起的EmbeddedUIExtensionAbility退出时返回的数据。若通过`terminateSelf`退出，则该值为undefined。   |

## 示例（加载EmbeddedComponent）

本示例展示`EmbeddedComponent`组件和`EmbeddedUIExtensionAbility`的基础使用方式，示例应用的`bundleName`为“com.example.embeddedComponent”，同应用下被拉起的`EmbeddedUIExtensionAbility`为“ExampleEmbeddedAbility”。本示例仅支持在拥有多进程权限的设备上运行（如PC/2in1），开发者可通过设备类型判断接口或系统设置确认当前设备是否具备多进程权限。

从API版本26.0.0开始，新增[onDrawReady](#ondrawready)接口。

- 示例应用中的`EntryAbility(UIAbility)`加载首页文件`ets/pages/Index.ets`，其中内容如下：

  ```ts
  import { Want } from '@kit.AbilityKit';
  import { ComponentContent } from '@kit.ArkUI';

  class Params {
  }
  @Builder
  function LoadingBuilder(params: Params) {
    Column() {
      LoadingProgress()
        .color(Color.Blue)
    }
  }
  @Builder
  function AreaChangePlaceholderBuilder(params: Params) {
    Column() {
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.Orange)
  }
  @Entry
  @Component
  struct Index {
    @State message: string = 'Message: ';
    private want: Want = {
      bundleName: 'com.example.embeddedComponent',
      abilityName: 'ExampleEmbeddedAbility',
    };
    @State dpiFollowStrategy: EmbeddedDpiFollowStrategy = EmbeddedDpiFollowStrategy.FOLLOW_UI_EXTENSION_ABILITY_DPI;
    @State windowStrategy: EmbeddedWindowModeFollowStrategy =
    EmbeddedWindowModeFollowStrategy.FOLLOW_UI_EXTENSION_ABILITY_WINDOW_MODE;
    private initPlaceholder = new ComponentContent(this.getUIContext(), wrapBuilder(LoadingBuilder), new Params());
    private areaChangePlaceholder = new ComponentContent(this.getUIContext(), wrapBuilder(AreaChangePlaceholderBuilder), new Params());

    build() {
      Row() {
        Column() {
          Text(this.message)
            .fontSize(20)
            .fontWeight(FontWeight.Bold)
          EmbeddedComponent(this.want, EmbeddedType.EMBEDDED_UI_EXTENSION,
            {
              placeholder: this.initPlaceholder,
              areaChangePlaceholder: {
                'FOLD_TO_EXPAND' : this.areaChangePlaceholder,
              },
              windowModeFollowStrategy: this.windowStrategy,
              dpiFollowStrategy: this.dpiFollowStrategy
            })
            .width('100%')
            .height('90%')
            .onTerminated((info) => {
              // 点击extension页面内的terminateSelfWithResult按钮后触发onTerminated回调，文本框显示如下信息
              this.message = 'Termination: code = ' + info.code + ', want = ' + JSON.stringify(info.want);
            })
            .onError((error) => {
              // 失败或异常触发onError回调，文本框显示如下报错内容
              this.message = 'Error: code = ' + error.code;
            })
            .onDrawReady(() => {
              // 从API版本26.0.0开始，新增支持被拉起的EmbeddedUIExtensionAbility绘制第一帧时触发onDrawReady回调，文本框显示如下信息
              this.message = `onDrawReady`;
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

- `EmbeddedComponent`拉起的`ExampleEmbeddedAbility(EmbeddedUIExtensionAbility)`在`ets/extensionAbility/ExampleEmbeddedAbility.ets`文件中实现，内容如下：

  ```ts
  import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

  const TAG: string = '[ExampleEmbeddedAbility]';

  export default class ExampleEmbeddedAbility extends EmbeddedUIExtensionAbility {
    onCreate() {
      console.info(TAG, `onCreate`);
    }

    onForeground() {
      console.info(TAG, `onForeground`);
    }

    onBackground() {
      console.info(TAG, `onBackground`);
    }

    onDestroy() {
      console.info(TAG, `onDestroy`);
    }

    onSessionCreate(want: Want, session: UIExtensionContentSession) {
      console.info(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
      let param: Record<string, UIExtensionContentSession> = {
        'session': session
      };
      let storage: LocalStorage = new LocalStorage(param);
      // 加载pages/extension.ets页面内容
      session.loadContent('pages/extension', storage);
    }

    onSessionDestroy(session: UIExtensionContentSession) {
      console.info(TAG, `onSessionDestroy`);
    }
  }
  ```

- `ExampleEmbeddedAbility(EmbeddedUIExtensionAbility)`的入口页面文件`ets/pages/extension.ets`内容如下，同时需要在`resources/base/profile/main_pages.json`文件中配置该页面路径：

  ```ts
  import { UIExtensionContentSession } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Extension {
    @State message: string = 'EmbeddedUIExtensionAbility Index';
    private storage: LocalStorage | undefined = this.getUIContext()?.getSharedLocalStorage();
    private session: UIExtensionContentSession | undefined = this.storage?.get<UIExtensionContentSession>('session');

    build() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
        Button('terminateSelfWithResult').fontSize(20).onClick(() => {
          // 点击按钮后调用terminateSelfWithResult退出
          this.session?.terminateSelfWithResult({
            resultCode: 1,
            want: {
              bundleName: 'com.example.embeddedComponent',
              abilityName: 'ExampleEmbeddedAbility',
            }
          });
        })
      }.width('100%').height('100%')
    }
  }
  ```

- 在`module.json5`配置文件的"extensionAbilities"标签下增加`ExampleEmbeddedAbility`配置，其type类型为`embeddedUI`，具体内容如下：
  ```json
  {
    "name": "ExampleEmbeddedAbility",
    "srcEntry": "./ets/extensionAbility/ExampleEmbeddedAbility.ets",
    "type": "embeddedUI"
  }
  ```
- 文件目录结构如下：

  ```shell
  .
  └── main
      ├── ets
      │   ├── extensionAbility
      │   │   └── ExampleEmbeddedAbility.ets
      │   └── pages
      |       ├── extension.ets
      │       └── Index.ets  
      ├── resources
      |   └── base
      |       └── profile
      |           └── main_pages.json
      └── module.json5
  ```

- 示例图如下：

  ![EmbeddedComponent](figures/embeddedComponent.png)
