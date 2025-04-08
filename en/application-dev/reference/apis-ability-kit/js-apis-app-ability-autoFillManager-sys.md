# @ohos.app.ability.autoFillManager (autoFillManager) (System API)

The autoFillManager module provides APIs for saving accounts and passwords.

Unlike the system's auto-save feature that triggers during page transitions, this feature requires manual activation by the user. For example, the user must input their account and password on a website and click the **Save** button to initiate the saving process.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.autoFillManager (autoFillManager)](js-apis-app-ability-autoFillManager.md).

## Modules to Import

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## ViewData

type ViewData = _ViewData.default

Defines the view data used for auto-fill.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_ViewData.default](js-apis-inner-application-viewData-sys.md) | View data used for auto-fill.|

## PageNodeInfo

type PageNodeInfo = _PageNodeInfo.default

Defines the page node information used for auto-fill.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_PageNodeInfo.default](js-apis-inner-application-pageNodeInfo-sys.md) | Page node information used for auto-fill.|

## FillRequest

type FillRequest = _AutoFillRequest.FillRequest

Defines the information about an auto-fill request.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillRequest.FillRequest](js-apis-inner-application-autoFillRequest-sys.md#fillrequest) | Information about an auto-fill request.|

## SaveRequest

type SaveRequest = _AutoFillRequest.SaveRequest

Defines the information about an auto-save request.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillRequest.SaveRequest](js-apis-inner-application-autoFillRequest-sys.md#saverequest) | Information about an auto-save request.|

## UpdateRequest<sup>12+</sup>

type UpdateRequest = _AutoFillRequest.UpdateRequest

Defines the information about an auto-update request.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillRequest.UpdateRequest](js-apis-inner-application-autoFillRequest-sys.md#updaterequest12) | Information about an auto-update request.|

## FillResponse

type FillResponse = _AutoFillRequest.FillResponse

Defines the information about the response to an auto-fill request.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillRequest.FillResponse](js-apis-inner-application-autoFillRequest-sys.md#fillresponse) | Information about the response to an auto-fill request.|

## FillRequestCallback

type FillRequestCallback = _AutoFillRequest.FillRequestCallback

Defines the callback for an auto-fill request, which is used to automatically fill in or generate a password. The callback can be used to notify the client of the success or failure of the request.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillRequest.FillRequestCallback](js-apis-inner-application-autoFillRequest-sys.md#fillrequestcallback) | Callback for an auto-fill request, which is used to automatically fill in or generate a password. The callback can be used to notify the client of the success or failure of the request.|

## SaveRequestCallback

type SaveRequestCallback = _AutoFillRequest.SaveRequestCallback

Defines the callback for an automatic or a manual saving request.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillRequest.SaveRequestCallback](js-apis-inner-application-autoFillRequest-sys.md#saverequestcallback) | Callback for an automatic or a manual saving request.|

## CustomData<sup>13+</sup>

type CustomData = _CustomData.default

Defines the custom data.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_CustomData.default](js-apis-inner-application-customData-sys.md) | Custom data.|

## AutoFillRect<sup>12+</sup>

type AutoFillRect = _AutoFillRect.default

Defines the rectangle used for auto-fill.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillRect.default](js-apis-inner-application-autoFillRect-sys.md) | Rectangle used for auto-fill.|

## AutoFillPopupConfig<sup>12+</sup>

type AutoFillPopupConfig = _AutoFillPopupConfig.default

Defines the size and position information of an auto-fill pop-up.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillPopupConfig.default](js-apis-inner-application-autoFillPopupConfig-sys.md) | Size and position information of the auto-fill pop-up.|

## PopupSize<sup>12+</sup>

type PopupSize = _AutoFillPopupConfig.PopupSize

Defines the width and height of an auto-fill pop-up.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AutoFillPopupConfig.PopupSize](js-apis-inner-application-autoFillPopupConfig-sys.md#popupsize) | Width and height of the auto-fill pop-up.|
