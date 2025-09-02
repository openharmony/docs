# @ohos.app.ability.VerticalPanelManager (启动垂域面板选择器 )

本模块提供拉起垂域面板选择器功能。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
## 导入模块

```ts
import { verticalPanelManager } from '@kit.AbilityKit';
```

## StartVerticalPanel

startVerticalPanel(
      context: common.UIAbilityContext,
      wantParam: Record<string, Object>,
      panelConfig: PanelConfig,
      panelStartCallback: PanelStartCallback
): Promise<void>

启动带有面板配置的垂域选择器。如果目标能力是可见的，您可以启动目标能力；如果目标能力是不可见的，

您需要申请权限：ohos.permission.START_INVISIBLE_ABILITY 来启动目标不可见能力。

如果调用方应用处于后台，不允许调用此接口。

**系统能力**：SystemCapability.Ability.AppExtension.VerticalPanel

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- |  -------- |
| context | [common.UIAbilityContext](./js-apis-inner-application-uiAbilityContext.md) | 是 | 指示媒体应用程序的UI功能上下文。 |
| wantParam | Record<string, Object> | 是 | 表示启动UIExtensionAbility组件时传递的参数。 |
| panelConfig | [PanelConfig](##PanelConfig) | 是 | 面板配置参数。 |
| panelStartCallback | [PanelStartCallback](##PanelStartCallback) | 是 | 拉起面板执行结果的回调。 |

**返回值：**

| 参数名 | 说明 |
| -------- |  -------- |
| Promise<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 16000050 | Failed to connect to the system service or system server handle failed. |
| 16000135 | The main window of this ability of this context does not exits. |

**实例：**

```typescript
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
          this.callStartVerticalPanelNapi()

        })
    }
    .height('100%')
    .width('100%')
  }

  callStartVerticalPanelNapi() {
    // Param[0] UIAbilityContext
    const context = getContext(this) as common.UIAbilityContext;

    // Param[1] wantParam: Record<string, Object>
    let wantParam: Record<string, Object> = {
      'sceneType': 3,
      'destinationName': 'address'
    };

    // Param[2] PanelConfig
    let sourceAppInfo: Record<string, string> = {
    }
    sourceAppInfo[verticalPanelManager.SOURCE_APP_BUNDLE_NAME] = 'unknown.bundle.name'
    sourceAppInfo[verticalPanelManager.SOURCE_APP_MODULE_NAME] = 'unknown.module.name'
    sourceAppInfo[verticalPanelManager.SOURCE_APP_ABILITY_NAME] = 'unknown.ability.name'
    sourceAppInfo[verticalPanelManager.SOURCE_APP_WINDOW_ID] = '30'
    sourceAppInfo[verticalPanelManager.SOURCE_APP_SCREEN_MODE] = '1'
    
    let panelConfig: verticalPanelManager.PanelConfig = {
      type: verticalPanelManager.VerticalType.NAVIGATION,
      sourceAppInfo: sourceAppInfo
    }

    // Param[3] PanelStartCallback
    let callback: verticalPanelManager.PanelStartCallback = {
      onError: (code: number, name: string, message: string): void => {
        console.log(`startVerticalPanel onError code ${code} name: ${name} message: ${message}`);
      },
      onResult: (result: common.AbilityResult):void => {
        console.log(`startVerticalPanel onResult result ${JSON.stringify(result)}`);
      },
    }

    try {
      console.log(`call startVerticalPanel`);
      verticalPanelManager.startVerticalPanel(context, wantParam, panelConfig, callback)
        .then(() => {
          console.log(`call startVerticalPanel end`);
        })
        .catch((error: BusinessError) => {
          console.log(`call startVerticalPanel promise catch error : ${error}`);
        })
    } catch (error) {
      console.log(`call startVerticalPanel catch error : ${error}`);
    }
  }
}
```

## PanelConfig

垂域面板的配置。

**系统能力**：SystemCapability.Ability.AppExtension.VerticalPanel

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| type | [VerticalType](##VerticalType) | 否 | 否 | 垂域面板的类型 。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。|
| sourceAppInfo | Record<string, string> | 否 | 否 | 表示源应用的相关信息，包括包名（bundleName）、模块名（moduleName）、能力名（abilityName）、窗口ID（windowId）和屏幕模式（screenMode）。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |

## VerticalType 

提供能力类型定义的枚举。

**元服务API：**从API version 20开始，该接口支持在元服务中使用。

**系统能力：**SystemCapability.Ability.AppExtension.VerticalPanel

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NAVIGATION | 'navigation' | 指示导航的类型。<br>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |

## PanelStartCallback

开启垂域面板的回调。

### onError

onError?: (code: number, name: string, message: string) => void

在发生除与UIAbility或UIExtensionAbility断开连接之外的错误时调用。 

**元服务API：**从API version 20开始，该接口支持在元服务中使用。

**系统能力：**SystemCapability.Ability.AppExtension.VerticalPanel

**参数：**

| 参数名 | 类型  | 必填  | 说明 |
| -------- | -------- | -------- | -------- |
| code | number | Yes | 如果UIAbility或UIExtensionAbility无法启动，则返回的代码。 |
| name | string | Yes | UIAbility或UIExtensionAbility启动失败时返回的名称。 |
| message | string | Yes | UIAbility或UIExtensionAbility启动失败时返回的消息。 |

**示例：**

```ts
let callback: verticalPanelManager.PanelStartCallback = {
    onError: (code: number, name: string, message: string): void => {
        console.log(`startVerticalPanel onError code ${code} name: ${name} message: ${message}`);
    },
    onResult: (result: common.AbilityResult):void => {
        console.log(`startVerticalPanel onResult result ${JSON.stringify(result)}`);
    },
}
```

### onResult

onResult?: (parameter: AbilityResult) => void

在UIExtensionAbility终止并返回结果时调用。

**元服务API：**从API version 20开始，该接口支持在元服务中使用。

**系统能力：**SystemCapability.Ability.AppExtension.VerticalPanel

**参数：**

| 参数名 | 类型 | 必填  | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 是 | UIExtensionAbility调用[terminateSelfWithResult](js-apis-inner-application-uiExtensionContext.md#terminateselfwithresult12)时返回的参数。 |

**示例：**

```ts
let callback: verticalPanelManager.PanelStartCallback = {
    onError: (code: number, name: string, message: string): void => {
        console.log(`startVerticalPanel onError code ${code} name: ${name} message: ${message}`);
    },
    onResult: (result: common.AbilityResult):void => {
        console.log(`startVerticalPanel onResult result ${JSON.stringify(result)}`);
    },
}
```

## Constants

**元服务API：**从API version 20开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Ability.AppExtension.VerticalPanel

| 名字 | 类型 | 值 | Description |
| -------- | -------- | -------- | -------- | -------- |
| SOURCE_APP_BUNDLE_NAME | string | 'bundleName' | 导出 bundleName 的常量字符串并将其提供给 sourceAppInfo |
| SOURCE_APP_MODULE_NAME | string | 'moduleName' | 导出 moduleName的常量字符串并将其提供给 sourceAppInfo |
| SOURCE_APP_ABILITY_NAME | string | 'abilityName' | 导出 abilityName的常量字符串并将其提供给 sourceAppInfo |
| SOURCE_APP_WINDOW_ID | string | 'windowId' | 导出 windowId的常量字符串并将其提供给 sourceAppInfo |
| SOURCE_APP_SCREEN_MODE | string | 'screenMode' | 导出 screenMode 的常量字符串，并将其提供给 sourceAppInfo。 |