# @ohos.app.ability.systemConfiguration

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @RuiChen_01-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e01350d88b673bbd3dab4c76e0fbd0aea5a52870 translatedAt=2026-08-13T13:25:04.907Z pushedAt=2026-08-14T10:07:37.175Z -->

The systemConfiguration module provides the capability to listen for system environment changes, including callbacks for changes in the system dark/light color mode, system language, and system font scale.

For example, by listening for changes in the system dark/light color mode, an app can sense the change and dynamically adjust its own dark/light theme to adapt to the system environment.

The difference between this module and the [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) module is as follows:

- systemConfiguration module: used to listen for changes in the system environment variable [Configuration](js-apis-app-ability-configuration.md).

- [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) module: used to listen for changes in the app environment variable [Configuration](js-apis-app-ability-configuration.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { systemConfiguration } from '@kit.AbilityKit';
```

## UpdatedCallback

UpdatedCallback is a callback used to listen for system environment changes. Developers can register a custom UpdatedCallback through [ApplicationContext.onSystemConfigurationUpdated](js-apis-inner-application-applicationContext.md#applicationcontextonsystemconfigurationupdated24) to listen for system environment changes.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| onColorModeUpdated | [OnColorModeUpdatedFn](#oncolormodeupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when the system color mode changes. |
| onFontSizeScaleUpdated | [OnFontSizeScaleUpdatedFn](#onfontsizescaleupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when the system font scale changes. |
| onFontWeightScaleUpdated | [OnFontWeightScaleUpdatedFn](#onfontweightscaleupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when the system font weight scale changes. |
| onLanguageUpdated | [OnLanguageUpdatedFn](#onlanguageupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when the system language changes. |
| onFontIdUpdated | [OnFontIdUpdatedFn](#onfontidupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when the system font ID changes. |
| onMCCUpdated | [OnMCCUpdatedFn](#onmccupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when the mobile device country code changes. |
| onMNCUpdated | [OnMNCUpdatedFn](#onmncupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when the mobile device network code changes. |
| onHasPointerDeviceUpdated | [OnHasPointerDeviceUpdatedFn](#onhaspointerdeviceupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when a pointer device is connected or disconnected. |
| onLocaleUpdated | [OnLocaleUpdatedFn](#onlocaleupdatedfn) | No | Yes | After the listener for system environment changes is registered, the callback is triggered when the system locale changes. |

**Example**

```ts
import { UIAbility, systemConfiguration, ConfigurationConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let CallBack: systemConfiguration.UpdatedCallback = {
      onColorModeUpdated(colorMode: ConfigurationConstant.ColorMode) {
        console.info(`system configuration updated colormode:` + colorMode);
      },
      onFontSizeScaleUpdated(fontSizeScale: number) {
        console.info(`system configuration updated fontSizeScale:` + fontSizeScale);
      },
      onFontWeightScaleUpdated(fontWeightScale: number) {
        console.info(`system configuration updated fontWeightScale:` + fontWeightScale);
      },
      onLanguageUpdated(language: string) {
        console.info(`system configuration updated language:` + language);
      },
      onFontIdUpdated(fontId: string) {
        console.info(`system configuration updated fontId:` + fontId);
      },
      onMCCUpdated(mcc: string) {
        console.info(`system configuration updated mcc:` + mcc);
      },
      onMNCUpdated(mnc: string) {
        console.info(`system configuration updated mnc:` + mnc);
      },
      onHasPointerDeviceUpdated(hasPointerDevice: boolean) {
        console.info(`system configuration updated hasPointerDevice:` + hasPointerDevice);
      },
      onLocaleUpdated(locale: string) {
        console.info(`system configuration updated locale:` + locale);
      }
    }
    // 1. Obtain the applicationContext through the context attribute.
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2. Register the listener through applicationContext.
      applicationContext.onSystemConfigurationUpdated(CallBack);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.info(`onSystemConfigurationUpdated finish`);
  }
}
```

## OnColorModeUpdatedFn

type OnColorModeUpdatedFn = (colorMode: ConfigurationConstant.ColorMode) => void

Called when the system color mode changes after the listener for system environment changes is registered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#colormode) | Yes | The system color mode after the change. |

## OnFontSizeScaleUpdatedFn

type OnFontSizeScaleUpdatedFn = (fontSizeScale: number) => void

Called when the system font scale changes after the listener for system environment changes is registered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | fontSizeScale | number | Yes | The system font scale after the change. |

## OnFontWeightScaleUpdatedFn

type OnFontWeightScaleUpdatedFn = (fontWeightScale: number) => void

Called when the system font weight scale changes after the listener for system environment changes is registered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | fontWeightScale | number | Yes | The system font weight scale after the change. |

## OnLanguageUpdatedFn

type OnLanguageUpdatedFn = (language: string) => void

Called to trigger a callback when the system language changes after the listener for system environment changes is registered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | language | string | Yes | The system language after the change. |

## OnFontIdUpdatedFn

type OnFontIdUpdatedFn = (fontId: string) => void

Called when the system font ID changes after the listener for system environment changes is registered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | fontId | string | Yes | The system font ID after the change. |

## OnMCCUpdatedFn

type OnMCCUpdatedFn = (mcc: string) => void

After the listener for system environment changes is registered, this callback is triggered when the country code of the mobile device changes.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | mcc | string | Yes | Country code of the mobile device after the change. |

## OnMNCUpdatedFn

type OnMNCUpdatedFn = (mnc: string) => void

Called when the mobile device network code changes after the listener for system environment changes is registered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | mnc | string | Yes | Network code of the mobile device after the change. |

## OnHasPointerDeviceUpdatedFn

type OnHasPointerDeviceUpdatedFn = (hasPointerDevice: boolean) => void

Called when a pointer device is connected or disconnected after the listener for system environment changes is registered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | hasPointerDevice | boolean | Yes | Whether a pointer device, such as a keyboard, mouse, or touchpad, is connected. The value **true** indicates that the device is connected, and **false** indicates the opposite. |

## OnLocaleUpdatedFn

type OnLocaleUpdatedFn = (locale: string) => void

Called when the system locale changes after the listener for system environment changes is registered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | locale | string | Yes | System locale after the change. For details about this field, see [Configuration](js-apis-app-ability-configuration.md). |