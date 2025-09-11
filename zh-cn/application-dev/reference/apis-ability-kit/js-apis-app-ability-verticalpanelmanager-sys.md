# @ohos.app.ability.verticalPanelManager (启动垂域面板选择器)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yuhong35-->
<!--Designer: @xukeke-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

本模块提供拉起垂域面板选择器功能。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 <br>
> 本模块接口仅可在Stage模型下使用。 <br>
> 本模块接口均为系统接口。

## 导入模块

```ts
import { verticalPanelManager } from '@kit.AbilityKit';
```

## verticalPanelManager.startVerticalPanel

startVerticalPanel(context: common.UIAbilityContext, wantParam: Record\<string, Object>, panelConfig: PanelConfig, panelStartCallback: PanelStartCallback): Promise\<void>

启动带有面板配置的垂域UIAbility。使用Promise异步回调。仅支持在主线程调用和处于前台的应用调用。

**系统能力：** SystemCapability.Ability.AppExtension.VerticalPanel

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- |  -------- |
| context | [common.UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | 是 | 调用方应用的上下文。 |
| wantParam | Record<string, Object> | 是 | 表示启动UIExtensionAbility组件时传递的参数。 |
| panelConfig | [PanelConfig](#panelconfig) | 是 | 面板配置参数。 |
| panelStartCallback | [PanelStartCallback](#panelstartcallback) | 是 | 拉起面板执行结果的回调。 |

**返回值：**

| 参数名 | 说明 |
| -------- |  -------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 16000050 | Failed to connect to the system service or system server handle failed. |
| 16000135 | The main window of this ability of this context does not exits. |

**示例：**

```ts
import { common, verticalPanelManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'StartVerticalPanel';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('StartVerticalPanel')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          this.callStartVerticalPanelNapi();
        })
    }
    .height('100%')
    .width('100%');
  }

  callStartVerticalPanelNapi() {
    // Param[0] UIAbilityContext
    const context = this.getUIContext().getHostContext() as common.UIAbilityContext;

    // Param[1] wantParam: Record<string, Object>
    let wantParam: Record<string, Object> = {
      'sceneType': 3,
      'destinationName': '练秋湖研发中心'
    };

    // Param[2] PanelConfig
    let sourceAppInfo: Record<string, string> = {};
    sourceAppInfo[verticalPanelManager.SOURCE_APP_BUNDLE_NAME] = 'com.huawei.hmos.browser';
    sourceAppInfo[verticalPanelManager.SOURCE_APP_MODULE_NAME] = 'entry';
    sourceAppInfo[verticalPanelManager.SOURCE_APP_ABILITY_NAME] = 'MainAbility';
    sourceAppInfo[verticalPanelManager.SOURCE_APP_WINDOW_ID] = '0';
    sourceAppInfo[verticalPanelManager.SOURCE_APP_SCREEN_MODE] = '1';

    let panelConfig: verticalPanelManager.PanelConfig = {
      type: verticalPanelManager.VerticalType.NAVIGATION,
      sourceAppInfo: sourceAppInfo
    };

    // Param[3] PanelStartCallback
    let callback: verticalPanelManager.PanelStartCallback = {
      onError: (code: number, name: string, message: string): void => {
        console.info(`startVerticalPanel onError code ${code} name: ${name} message: ${message}`);
      },
      onResult: (result: common.AbilityResult): void => {
        console.info(`startVerticalPanel onResult result ${JSON.stringify(result)}`);
      },
    };

    try {
      console.info(`call startVerticalPanel`);
      verticalPanelManager.startVerticalPanel(context, wantParam, panelConfig, callback)
        .then(() => {
          console.info(`call startVerticalPanel end`);
        })
        .catch((error: BusinessError) => {
          console.error(`call startVerticalPanel promise catch error : ${error}`);
        });
    } catch (error) {
      console.error(`call startVerticalPanel catch error : ${error}`);
    }
  }
}
```

## PanelConfig

垂域面板的配置。

**系统能力：** SystemCapability.Ability.AppExtension.VerticalPanel

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| type | [VerticalType](#verticaltype) | 否 | 否 | 垂域面板的类型。 |
| sourceAppInfo | Record<string, string> | 否 | 否 | 表示源应用的相关信息，包括bundleName、moduleName、abilityName、windowId和screenMode。 |

## VerticalType 

提供拉起垂域面板选择器类型的枚举。

**系统能力：** SystemCapability.Ability.AppExtension.VerticalPanel

**系统接口：** 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NAVIGATION | 'navigation' | 指示导航的类型。 |

## PanelStartCallback

开启垂域面板的回调。

**系统能力：** SystemCapability.Ability.AppExtension.VerticalPanel

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| onError | [OnErrorFn](#onerrorfn) | 否 | 否 | 在发生除与UIAbility或UIExtensionAbility断开连接之外的错误时回调。|
| onResult |  [OnResultFn](#onresultfn) | 否 | 是 | 在UIExtensionAbility终止并返回结果时回调。 |

## OnErrorFn

type OnErrorFn = (code: number, name: string, message: string) => void

**系统能力：** SystemCapability.Ability.AppExtension.VerticalPanel

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型  | 必填  | 说明 |
| -------- | -------- | -------- | -------- |
| code | number | 是 | 拉起UIAbility或UIExtensionAbility执行失败时返回的结果码。 |
| name | string | 是 | 拉起UIAbility或UIExtensionAbility执行失败时返回的名称。 |
| message | string | 是 | 拉起UIAbility或UIExtensionAbility执行失败时返回的错误信息。 |

**示例：**

```ts
let callback: verticalPanelManager.PanelStartCallback = {
  onError: (code: number, name: string, message: string): void => {
    console.info(`startVerticalPanel onError code ${code} name: ${name} message: ${message}`);
  },
  onResult: (result: common.AbilityResult):void => {
    console.info(`startVerticalPanel onResult result ${JSON.stringify(result)}`);
  },
}
```

## OnResultFn

type OnResultFn = (parameter: AbilityResult) => void

**系统能力：** SystemCapability.Ability.AppExtension.VerticalPanel

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填  | 说明 |
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | UIExtensionAbility调用[terminateSelfWithResult](js-apis-inner-application-uiExtensionContext.md#terminateselfwithresult12)时返回的参数。 |

**示例：**

```ts
let callback: verticalPanelManager.PanelStartCallback = {
  onError: (code: number, name: string, message: string): void => {
    console.info(`startVerticalPanel onError code ${code} name: ${name} message: ${message}`);
  },
  onResult: (result: common.AbilityResult):void => {
    console.info(`startVerticalPanel onResult result ${JSON.stringify(result)}`);
  },
}
```

## 常量

**系统能力：** SystemCapability.Ability.AppExtension.VerticalPanel

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 值 | 说明 |
| -------- | -------- | -------- | -------- |
| SOURCE_APP_BUNDLE_NAME | string | 'bundleName' | 常量字符串bundleName，可以作为[sourceAppInfo](#panelconfig)的key值。 |
| SOURCE_APP_MODULE_NAME | string | 'moduleName' | 常量字符串moduleName，可以作为[sourceAppInfo](#panelconfig)的key值。 |
| SOURCE_APP_ABILITY_NAME | string | 'abilityName' | 常量字符串abilityName，可以作为[sourceAppInfo](#panelconfig)的key值。 |
| SOURCE_APP_WINDOW_ID | string | 'windowId' | 常量字符串windowId，可以作为[sourceAppInfo](#panelconfig)的key值。 |
| SOURCE_APP_SCREEN_MODE | string | 'screenMode' | 常量字符串screenMode，可以作为[sourceAppInfo](#panelconfig)的key值。 |