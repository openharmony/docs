# @ohos.app.ability.autoFillManager (autoFillManager)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

autoFillManager模块提供账号密码保存等功能。

不同于页面切换时触发的系统自动保存功能，该功能需要由用户手动触发。例如用户在网站上输入了账号密码，并点击“保存”按钮，才能触发相应的自动保存操作。

> **说明：**
> 
> 本模块首批接口从API version 11 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.autoFillManager (autoFillManager)](js-apis-app-ability-autoFillManager.md)。

## 导入模块

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## ViewData

type ViewData = _ViewData.default

自动填充的视图数据信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_ViewData.default](js-apis-inner-application-viewData-sys.md) | 表示自动填充的视图数据信息。 |

## PageNodeInfo

type PageNodeInfo = _PageNodeInfo.default

自动填充的页面节点信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_PageNodeInfo.default](js-apis-inner-application-pageNodeInfo-sys.md) | 表示自动填充的页面节点信息。 |

## FillRequest

type FillRequest = _AutoFillRequest.FillRequest

自动填充的请求信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillRequest.FillRequest](js-apis-inner-application-autoFillRequest-sys.md#fillrequest) | 表示自动填充的请求信息。 |

## SaveRequest

type SaveRequest = _AutoFillRequest.SaveRequest

自动保存的请求信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillRequest.SaveRequest](js-apis-inner-application-autoFillRequest-sys.md#saverequest) | 表示自动保存的请求信息。 |

## UpdateRequest<sup>12+</sup>

type UpdateRequest = _AutoFillRequest.UpdateRequest

自动填充的更新信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillRequest.UpdateRequest](js-apis-inner-application-autoFillRequest-sys.md#updaterequest12) | 表示自动填充的更新信息。 |

## FillResponse

type FillResponse = _AutoFillRequest.FillResponse

自动填充的响应信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillRequest.FillResponse](js-apis-inner-application-autoFillRequest-sys.md#fillresponse) | 表示自动填充的响应信息。 |

## FillRequestCallback

type FillRequestCallback = _AutoFillRequest.FillRequestCallback

自动填充或者生成密码时的回调对象，可以通过此回调通知客户端成功或者失败。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillRequest.FillRequestCallback](js-apis-inner-application-autoFillRequest-sys.md#fillrequestcallback) | 表示自动填充或者生成密码时的回调对象，可以通过此回调通知客户端成功或者失败。 |

## SaveRequestCallback

type SaveRequestCallback = _AutoFillRequest.SaveRequestCallback

自动保存或者手动保存请求的回调对象。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillRequest.SaveRequestCallback](js-apis-inner-application-autoFillRequest-sys.md#saverequestcallback) | 表示自动保存或者手动保存请求的回调对象。 |

## CustomData<sup>13+</sup>

type CustomData = _CustomData.default

自定义数据。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_CustomData.default](js-apis-inner-application-customData-sys.md) | 表示自定义数据。 |

## AutoFillRect<sup>12+</sup>

type AutoFillRect = _AutoFillRect.default

用于自动填充的矩形区域。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillRect.default](js-apis-inner-application-autoFillRect-sys.md) | 表示用于自动填充的矩形区域。 |

## AutoFillPopupConfig<sup>12+</sup>

type AutoFillPopupConfig = _AutoFillPopupConfig.default

自动填充气泡弹窗的尺寸和位置信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillPopupConfig.default](js-apis-inner-application-autoFillPopupConfig-sys.md) | 表示自动填充气泡弹窗的尺寸和位置信息。 |

## PopupSize<sup>12+</sup>

type PopupSize = _AutoFillPopupConfig.PopupSize

气泡弹窗的宽和高。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AutoFillPopupConfig.PopupSize](js-apis-inner-application-autoFillPopupConfig-sys.md#popupsize) | 表示气泡弹窗的宽和高。 |
