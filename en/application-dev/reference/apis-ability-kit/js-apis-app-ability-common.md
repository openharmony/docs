# @ohos.app.ability.common (Ability Common Module)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The module provides pure type definitions for common capabilities within Ability Kit, including various context objects, callback interfaces, and data structures. It exports type declarations only and does not include any implementation logic or executable code.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## UIAbilityContext

type UIAbilityContext = _UIAbilityContext.default

Defines the context environment for the [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md). It inherits from Context.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_UIAbilityContext.default](js-apis-inner-application-uiAbilityContext.md) | Default context of the UIAbility.|

## AbilityStageContext

type AbilityStageContext = _AbilityStageContext.default

Defines the context environment for the [AbilityStage](../apis-ability-kit/js-apis-app-ability-abilityStage.md). It inherits from Context.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AbilityStageContext.default](js-apis-inner-application-abilityStageContext.md) | Default context of the AbilityStage.|

## ApplicationContext

type ApplicationContext = _ApplicationContext.default

Defines the application context. It inherits from Context.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_ApplicationContext.default](js-apis-inner-application-applicationContext.md) | Application context.|

## BaseContext

type BaseContext = _BaseContext.default

Defines the parent class of all context types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_BaseContext.default](js-apis-inner-application-baseContext.md) | Parent class of all context types.|

## Context

type Context = _Context.default

Defines the base class of the context in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_Context.default](js-apis-inner-application-context.md) | Base class of the context in the stage model.|

## ExtensionContext

type ExtensionContext = _ExtensionContext.default

Defines the context environment for the [ExtensionAbility](../apis-ability-kit/js-apis-app-ability-extensionAbility.md). It inherits from Context.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_ExtensionContext.default](js-apis-inner-application-extensionContext.md) | Default context of the ExtensionAbility.|

## FormExtensionContext

type FormExtensionContext = _FormExtensionContext.default

Defines the context environment for the [FormExtensionAbility](../apis-form-kit/js-apis-app-form-formExtensionAbility.md). It inherits from Context.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_FormExtensionContext.default](../apis-form-kit/js-apis-inner-application-formExtensionContext.md) | Default context of the FormExtensionAbility.|

## VpnExtensionContext<sup>11+<sup>

type VpnExtensionContext = _VpnExtensionContext.default

Defines the context environment for the [VpnExtensionAbility](../apis-network-kit/js-apis-VpnExtensionAbility.md). It inherits from Context.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_VpnExtensionContext.default](../apis-network-kit/js-apis-inner-application-VpnExtensionContext.md) | Default context of the VpnExtensionAbility.|

## EventHub

type EventHub = _EventHub.default

Defines EventHub, which is an event communication mechanism based on the publish-subscribe pattern.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_EventHub.default](js-apis-inner-application-eventHub.md) | Event communication mechanism based on the publish-subscribe pattern.|

## PacMap

type PacMap = _PacMap

Defines the container of basic data types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap) | Container of basic data types.|

## AbilityResult

type AbilityResult = _AbilityResult

Defines the result code and data returned when a started ability is terminated.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AbilityResult](js-apis-inner-ability-abilityResult.md) | Result code and data returned when a started ability is terminated.|

## AbilityStartCallback<sup>11+<sup>

type AbilityStartCallback = _AbilityStartCallback

Defines the callback invoked to return the UIExtensionAbility startup result. It is usually used as an input parameter in [UIAbilityContext.startAbilityByType](js-apis-inner-application-uiAbilityContext.md#startabilitybytype11) or [UIExtensionContext.startAbilityByType](js-apis-app-ability-uiExtensionContentSession.md#startabilitybytype11).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | Callback invoked to return the UIExtensionAbility startup result.|

## ConnectOptions

type ConnectOptions = _ConnectOptions

Defines the connection options. It is used as an input parameter for connection to a background service, to receive the connection status with the background service.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_ConnectOptions](js-apis-inner-ability-connectOptions.md) | Input parameter used to receive the connection status with the background service.|

## UIExtensionContext<sup>10+</sup>

type UIExtensionContext = _UIExtensionContext.default

Defines the context environment for the [UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md). It inherits from Context.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_UIExtensionContext.default](js-apis-inner-application-uiExtensionContext.md) | Default context of the UIExtensionAbility.|

## EmbeddableUIAbilityContext<sup>12+<sup>

type EmbeddableUIAbilityContext = _EmbeddableUIAbilityContext.default

Defines the context environment for the [EmbeddableUIAbility](../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md). It inherits from Context.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_EmbeddableUIAbilityContext.default](js-apis-inner-application-EmbeddableUIAbilityContext.md) | Default context of the EmbeddableUIAbility.|

## PhotoEditorExtensionContext<sup>12+<sup>

type PhotoEditorExtensionContext = _PhotoEditorExtensionContext.default

Defines the context environment for the [PhotoEditorExtensionAbility](../apis-ability-kit/js-apis-app-ability-photoEditorExtensionAbility.md). It inherits from Context.

**System capability**: SystemCapability.Ability.AppExtension.PhotoEditorExtension

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_PhotoEditorExtensionContext.default](js-apis-app-ability-photoEditorExtensionContext.md) | Default context of the PhotoEditorExtensionAbility.|

## UIServiceProxy<sup>14+<sup>

type UIServiceProxy = _UIServiceProxy.default

Defines the capability for data communication with the UIServiceExtensionAbility. UIServiceExtensionAbility is a special type of ExtensionAbility provided by the system and is used to provide extended capabilities related to floating windows.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_UIServiceProxy.default](js-apis-inner-application-uiserviceproxy.md) | Capability for data communication with the UIServiceExtensionAbility.|

## UIServiceExtensionConnectCallback<sup>14+<sup>

type UIServiceExtensionConnectCallback = _UIServiceExtensionConnectCallback.default

Defines the connection callback. It is used as an input parameter for connection to a UIServiceExtensionAbility, to provide the callback for the connection.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_UIServiceExtensionConnectCallback.default](js-apis-inner-application-uiServiceExtensionconnectcallback.md) | Callback for connection to a UIServiceExtensionAbility.|

## AppServiceExtensionContext<sup>20+</sup>

type AppServiceExtensionContext = _AppServiceExtensionContext.default

Defines the context environment for the [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md). It inherits from Context.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| [_AppServiceExtensionContext.default](js-apis-inner-application-appServiceExtensionContext.md) | Default context of the AppServiceExtensionAbility.|

**Example**

```ts
import { common } from '@kit.AbilityKit';

let uiAbilityContext: common.UIAbilityContext;
let abilityStageContext: common.AbilityStageContext;
let applicationContext: common.ApplicationContext;
let baseContext: common.BaseContext;
let context: common.Context;
let uiExtensionContext: common.UIExtensionContext;
let extensionContext: common.ExtensionContext;
let formExtensionContext: common.FormExtensionContext;
let vpnExtensionContext: common.VpnExtensionContext;
let eventHub: common.EventHub;
let pacMap: common.PacMap;
let abilityResult: common.AbilityResult;
let abilityStartCallback: common.AbilityStartCallback;
let connectOptions: common.ConnectOptions;
let embeddableUIAbilityContext: common.EmbeddableUIAbilityContext;
let photoEditorExtensionContext: common.PhotoEditorExtensionContext;
let uiServiceProxy : common.UIServiceProxy;
let uiServiceExtensionConnectCallback : common.UIServiceExtensionConnectCallback;
let appServiceExtensionContext : common.AppServiceExtensionContext;
```
