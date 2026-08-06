# @ohos.enterprise.common (Common Module)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The module provides pure type definitions for common capabilities within MDM Kit, including enum types and data structs. It exports type declarations only and does not include any implementation logic or executable code.

**Use cases:**
In enterprise device administrator application development, the types defined in this module are used in scenarios such as configuring device management and control policies, managing application instances, handling application installation results, and listening for policy changes. These types provide unified parameter and return value standards for the APIs of various sub-modules within MDM Kit.

**Benefits:**
Standardized type definitions simplify the development process of enterprise device administrator applications, improve code maintainability and type safety, and reduce type-related runtime errors.

> **NOTE**
>
> The initial APIs of this module are supported since API version 22. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.MDMKit';
```

## ManagedPolicy

Enumerates enterprise device management policies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Value| Description                           |
| ----------- | -------- | ------------------------------- |
| DEFAULT | 0  | Default policy with no restrictions applied.|
| DISALLOW | 1  | Policy that disallows extensions from external sources to run.|
| FORCE_OPEN | 2  | Policy that forcibly enables extensions from external sources to run.|

## ApplicationInstance

Defines application instance data.

It is used as an input parameter in the [addUserNonStopApps](./js-apis-enterprise-applicationManager.md#applicationmanageraddusernonstopapps22), [removeUserNonStopApps](./js-apis-enterprise-applicationManager.md#applicationmanagerremoveusernonstopapps22), [addFreezeExemptedApps](./js-apis-enterprise-applicationManager.md#applicationmanageraddfreezeexemptedapps22), and [removeFreezeExemptedApps](./js-apis-enterprise-applicationManager.md#applicationmanagerremovefreezeexemptedapps22) APIs.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name         | Type                            | Read-Only| Optional| Description                                                       |
| ------------- | --------------------------------| ---- | -----| ------------------------------------------------------ |
| appIdentifier          | string       | No  | No| [Unique identifier](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) of an application. You can call the [bundleManager.getBundleInfo](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfo14-2) API to obtain **bundleInfo.signatureInfo.appIdentifier**.          |
| accountId        | number       | No  | No| Account ID. The value is an integer greater than or equal to 0.<br> You can obtain the account ID by calling the [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) API.           |
| appIndex        | number       | No  | No| Index of the application clone. The value is an integer greater than or equal to 0.<br> You can obtain the index by calling the [getAppCloneIdentity](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetappcloneidentity14) API.          |

## InstallationResult

An object that holds the application installation result.

This object is used as a callback parameter in [EnterpriseAdminExtensionAbility.onMarketAppInstallResult](./js-apis-EnterpriseAdminExtensionAbility.md#onmarketappinstallresult22).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name         | Type                            | Read-Only| Optional| Description                                                       |
| ------------- | --------------------------------| ---- | -----| ------------------------------------------------------ |
| result        | [Result](#result)       | No  | No| Application installation result. **SUCCESS** indicates that the application is successfully installed and can be properly used. **FAIL** indicates that the application fails to be installed and is unavailable.           |
| message        | string       | No  | No| Application installation result message.          |

## Result

Enumerates application installation results.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Value| Description                           |
| ----------- | -------- | ------------------------------- |
| SUCCESS | 0  | The application is installed successfully.|
| FAIL | -1  | The application fails to be installed.|

## EnterpriseAdminExtensionContext<sup>23+</sup>

type EnterpriseAdminExtensionContext = _EnterpriseAdminExtensionContext.default

**EnterpriseAdminExtensionContext** is the context of [EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md) and inherits from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Type| Description|
| --- | --- |
| _EnterpriseAdminExtensionContext.default | Context [EnterpriseAdminExtensionContext](js-apis-application-EnterpriseAdminExtensionContext.md) of the EnterpriseAdminExtensionAbility component.|

## StartupScene<sup>24+</sup>

Startup wizard completion scenario. When the initial switch to a sub-user (only on PCs), OTA upgrade, and first-time startup wizard are complete, the device system calls the [onStartupGuideCompleted](./js-apis-EnterpriseAdminExtensionAbility.md#onstartupguidecompleted24) API to notify the device administrator application.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name        | Value| Description                           |
| ----------- | -------- | ------------------------------- |
| USER_SETUP | 0  | A sub-user is switched to for the first time and the startup wizard for the sub-user is complete (only on PCs). The callback will not be triggered when the sub-user is switched again.|
| OTA | 1  | The OTA upgrade is complete.|
| DEVICE_PROVISION | 2  | The initial startup wizard is complete.|

## PolicyChangedEvent

Defines the policy change event.

This API is used as a callback input parameter of [onAdminPolicyChanged](./js-apis-EnterpriseAdminExtensionAbility.md#onadminpolicychanged).

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name         | Type                            | Read-Only| Optional| Description                                                       |
| ------------- | --------------------------------| ---- | -----| ------------------------------------------------------ |
| bundleName          | string       | No  | No| App bundle name.          |
| functionName        | string       | No  | No| API name. For example, if the [setPasswordPolicy](./js-apis-enterprise-securityManager.md#securitymanagersetpasswordpolicy) API is called, the value of this parameter is **setPasswordPolicy**.           |
| parameters        | string       | No  | No| Input parameter value (excluding the **admin** parameter) when an API is called. The value is a JSON string. For example, if the [setPasswordPolicy](./js-apis-enterprise-securityManager.md#securitymanagersetpasswordpolicy) API is called, the return value of this parameter is **{"policy":{"complexityRegex":"^(?=.\*[a-zA-Z])(?=.\*\\\\d).{8},$","validityPeriod":1808309786000,"additionalDescription":"It must contain at least eight characters, including digits and letters.** **"}}**.           |
| time        | number       | No  | No| Timestamp when an API is called, in milliseconds.          |
