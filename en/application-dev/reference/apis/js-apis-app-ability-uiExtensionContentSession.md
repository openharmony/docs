# @ohos.app.ability.UIExtensionContentSession (UI Operation Class for ExtensionAbilities with UI)

**UIExtensionContentSession** is an instance created when the [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md) loads UI content. When the UIExtensionComponent starts a UIExtensionAbility, the UIExtensionAbility creates a UIExtensionContentSession instance and returns it through the [onSessionCreate](js-apis-app-ability-uiExtensionAbility.md#uiextensionabilityonsessioncreate) callback. One UIExtensionComponent corresponds to one **UIExtensionContentSession** instance, which provides methods such as UI loading and result notification. The **UIExtensionContentSession** instances of multiple UIExtensionAbilities are operated separately.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
```

## UIExtensionContentSession.sendData

sendData(data: { [key: string]: Object }): void

Sends data to the UIExtensionComponent.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | {[key:&nbsp;string]:&nbsp;Object} | Yes| Data to send.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.setReceiveDataCallback

setReceiveDataCallback(callback: (data: { [key: string]: Object }) => void): void

Sets a callback to receive data from the UIExtensionComponent.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | (data: { [key: string]: Object }) => void | Yes| Callback used to receive data.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.loadContent

loadContent(path: string, storage?: LocalStorage): void;

Loads content from a page associated with a local storage to the window corresponding to the current UIExtensionComponent.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                           | Mandatory| Description                                                        |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | Yes  | Path of the page from which the content will be loaded.                                        |
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | No  | A storage unit, which provides storage for variable state properties and non-variable state properties of an application. This parameter is left blank by default.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - The application where the UIExtensionComponent is located must be running in the foreground and gain focus.
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability with **options** specified. This API uses an asynchronous callback to return the result.

Observe the following when using this API:
 - The application where the UIExtensionComponent is located must be running in the foreground and gain focus.
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.startAbility

startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;;

Starts an ability. This API uses a promise to return the result.

Observe the following when using this API:
 - The application where the UIExtensionComponent is located must be running in the foreground and gain focus.
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden.        |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability. This API uses an asynchronous callback to return the result to the caller after the ability is terminated. An ability can be terminated in the following ways:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - The application where the UIExtensionComponent is located must be running in the foreground and gain focus.
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void;

Starts an ability with **options** specified. This API uses an asynchronous callback to return the result to the caller after the ability is terminated. An ability can be terminated in the following ways:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - The application where the UIExtensionComponent is located must be running in the foreground and gain focus.
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.startAbilityForResult

startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;;

Starts an ability. This API uses a promise to return the result to the caller after the ability is terminated. An ability can be terminated in the following ways:
 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

Observe the following when using this API:
 - The application where the UIExtensionComponent is located must be running in the foreground and gain focus.
 - If an application running in the background needs to call this API to start an ability, it must have the **ohos.permission.START_ABILITIES_FROM_BACKGROUND** permission.
 - If **exported** of the target ability is **false** in cross-application scenarios, the caller must have the **ohos.permission.START_INVISIBLE_ABILITY** permission.
 - For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|


**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Stops the window object corresponding to this **UIExtensionContentSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

## UIExtensionContentSession.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Stops the window object corresponding to this **UIExtensionContentSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

## UIExtensionContentSession.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;

Stops the window object corresponding to this **UIExtensionContentSession** instance and returns the result to the UIExtensionComponent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Result returned to the UIExtensionComponent.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

## UIExtensionContentSession.terminateSelfWithResult

terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;;

Stops the window object corresponding to this **UIExtensionContentSession** instance and returns the result to the UIExtensionComponent. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Result returned to the UIExtensionComponent.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

## UIExtensionContentSession.setWindowBackgroundColor

setWindowBackgroundColor(color: string): void

Sets the background color for the loading page of the UIExtensionAbility. This API must be used after [loadContent()](#uiextensioncontentsessionloadcontent) takes effect.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| color | string | Yes| Background color to set. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

## UIExtensionContentSession.setWindowPrivacyMode

setWindowPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

Sets whether the window is in privacy mode. This API uses a promise to return the result. A window in privacy mode cannot be captured or recorded.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PRIVACY_WINDOW

**Parameters**

| Name| Type| Mandatory| Description|
| ------------- | ------- | -- | ----------------------------------------------------- |
| isPrivacyMode | boolean | Yes| Whether the window is in privacy mode. The value **true** means that the window is in privacy mode, and **false** means the opposite.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

## UIExtensionContentSession.setWindowPrivacyMode

setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the window is in privacy mode. This API uses an asynchronous callback to return the result. A window in privacy mode cannot be captured or recorded.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Required permissions**: ohos.permission.PRIVACY_WINDOW

**Parameters**

| Name| Type| Mandatory| Description|
| ------------- | ------------------------- | -- | ------------------------------------------------------ |
| isPrivacyMode | boolean                   | Yes| Whether the window is in privacy mode. The value **true** means that the window is in privacy mode, and **false** means the opposite. |
| callback      | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                             |
