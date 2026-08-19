# @ohos.bundle.bundleManager (Bundle Management Module)

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=74dbad5c7db60e1e7acbdd97ecfcb9536c7d7b13 translatedAt=2026-08-18T15:29:38.727Z pushedAt=2026-08-19T01:43:55.973Z -->

The module provides APIs for obtaining application information, including [bundle information](js-apis-bundleManager-bundleInfo.md), [application information](js-apis-bundleManager-applicationInfo.md), [ability information](js-apis-bundleManager-abilityInfo.md) (information about a UIAbility), and [ExtensionAbility information](js-apis-bundleManager-extensionAbilityInfo.md).

> **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## BundleFlag

Enumerates the bundle flags, which indicate the type of bundle information to obtain.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                                         | Value        | Description                                                        |
| --------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_BUNDLE_INFO_DEFAULT                       | 0x00000000 | Used to obtain the default bundle information. The obtained information does not contain information about the signature, application, HAP module, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_APPLICATION              | 0x00000001 | Used to obtain the bundle information with application information. The obtained information does not contain information about the signature, HAP module, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_HAP_MODULE               | 0x00000002 | Used to obtain the bundle information with HAP module information. The obtained information does not contain information about the signature, application, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_ABILITY                  | 0x00000004 | Used to obtain the bundle information with ability information. The obtained information does not contain information about the signature, application, ExtensionAbility, or permission. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY        | 0x00000008 | Used to obtain the bundle information with ExtensionAbility information. The obtained information does not contain information about the signature, application, ability, or permission. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION     | 0x00000010 | Used to obtain the bundle information with permission information. The obtained information does not contain information about the signature, application, HAP module, ability, or ExtensionAbility.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_METADATA                 | 0x00000020 | Used to obtain the metadata contained in the application, module, ability, or ExtensionAbility information. It must be used together with **GET_BUNDLE_INFO_WITH_APPLICATION**, **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**.<br>- To obtain the metadata contained in the application information, it must be used together with **GET_BUNDLE_INFO_WITH_APPLICATION**.<br>- To obtain the metadata contained in the module information, it must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>- To obtain the metadata contained in the ability information, it must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_ABILITY**.<br>- To obtain the metadata contained in the ExtensionAbility information, it must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE** and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_DISABLE                  | 0x00000040 | Used to obtain the information about disabled bundles and abilities of a bundle. The obtained information does not contain information about the signature, application, HAP module, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_SIGNATURE_INFO           | 0x00000080 | Used to obtain the bundle information with signature information. The obtained information does not contain information about the application, HAP module, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_MENU<sup>11+</sup>       | 0x00000100 | Used to obtain the bundle information with the file context menu configuration. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GET_BUNDLE_INFO_WITH_ROUTER_MAP<sup>12+</sup> | 0x00000200 | Used to obtain the bundle information with the router map. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| GET_BUNDLE_INFO_WITH_SKILL<sup>12+</sup>      | 0x00000800 | Used to obtain the bundle information with the skills. It must be used together with **GET_BUNDLE_INFO_WITH_HAP_MODULE**, **GET_BUNDLE_INFO_WITH_ABILITY**, and **GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| GET_BUNDLE_INFO_WITH_ENTRY_MODULE<sup>23+</sup>      | 0x00010000 | Used to obtain the bundle information with the HAP module information. It is valid only for bundleInfo.hapModulesInfo corresponding to the entry module. If the entry module does not exist, the bundleInfo.hapModulesInfo list is empty. The obtained bundle information does not contain information about the signature, application, ability, ExtensionAbility, or permission.<br>**Atomic service API**: This API can be used in atomic services since API version 23.|

## ExtensionAbilityType

Enumerates the types of ExtensionAbility components.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

<!--Table: 30%; 10%; 60%-->

| Name | Value | Description |
|:----------------:|:---:|-----|
| FORM             | 0   | [FormExtensionAbility](../apis-form-kit/js-apis-app-form-formExtensionAbility.md): widget extension capability, providing widget development capabilities.<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| WORK_SCHEDULER   | 1   | [WorkSchedulerExtensionAbility](../apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md): deferred task extension capability, allowing apps to execute tasks with low real-time requirements when the system is idle. |
| INPUT_METHOD     | 2   | [InputMethodExtensionAbility](../apis-ime-kit/js-apis-inputmethod-extension-ability.md): input method extension capability, used to develop input method apps. |
|<!--DelRow--> SERVICE          | 3   | [ServiceExtensionAbility](js-apis-app-ability-serviceExtensionAbility-sys.md): background service extension capability, providing background running and corresponding capabilities to the outside.|
| ACCESSIBILITY    | 4   | <!--RP1-->[AccessibilityExtensionAbility](../apis-accessibility-kit/js-apis-application-accessibilityExtensionAbility.md)<!--RP1End-->: accessibility service extension capability, supporting access to and operation of foreground UIs. |
|<!--DelRow--> DATA_SHARE       | 5   | [DataShareExtensionAbility](../apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md): data sharing extension capability, used to provide data read/write services to the outside. |
|<!--DelRow--> FILE_SHARE       | 6   | FileShareExtensionAbility: file sharing extension capability, used for file sharing between apps. Reserved capability, supported only by system applications. |
|<!--DelRow--> STATIC_SUBSCRIBER| 7   | [StaticSubscriberExtensionAbility](../apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md): static broadcast extension capability, used to process static events such as the boot event. |
|<!--DelRow--> WALLPAPER        | 8   | WallpaperExtensionAbility: wallpaper extension capability, used to implement desktop wallpapers. Reserved capability, supported only by system applications. |
| BACKUP           |  9  | [BackupExtensionAbility](../apis-core-file-kit/js-apis-application-backupExtensionAbility.md): data backup extension capability, providing backup and restoration capabilities for app data. |
|<!--DelRow--> WINDOW     |  10 | [WindowExtensionAbility](../apis-arkui/js-apis-application-windowExtensionAbility-sys.md): UI composition extension capability, allowing system applications to launch and embed UIs across apps. |
| ENTERPRISE_ADMIN |  11 | [EnterpriseAdminExtensionAbility](../apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md): enterprise device management extension capability, providing the capability to process management events during enterprise management. |
|<!--DelRow--> THUMBNAIL        | 13  | ThumbnailExtensionAbility: file thumbnail extension capability, used to provide icon thumbnails for files. Reserved capability, supported only by system applications. |
|<!--DelRow--> PREVIEW          | 14  | PreviewExtensionAbility: file preview extension capability, providing file preview capabilities so that other apps can embed and display them directly. Reserved capability, supported only by system applications. |
|<!--DelRow--> PRINT<sup>10+</sup> | 15 | PrintExtensionAbility: file printing extension capability, providing office scenarios such as printing photos and documents. Supported only by system applications. |
| SHARE<sup>10+</sup> | 16 | [ShareExtensionAbility](js-apis-app-ability-shareExtensionAbility.md): provides sharing service capabilities, providing developers with a sharing service template based on UIExtension. |
|<!--DelRow--> PUSH<sup>10+</sup> | 17 | PushExtensionAbility: push extension capability, providing the capability to push scenario-based messages. Reserved capability, supported only by system applications. |
| DRIVER<sup>10+</sup> | 18 | [DriverExtensionAbility](../apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md): driver extension capability, providing peripheral driver extension capabilities. After an app configures an ExtensionAbility of the driver type, it is regarded as a driver app. Driver apps are not distinguished by user during installation, uninstallation, and restoration, and existing driver apps on the device are also installed when a new user is created. For example, when a sub-user is created, the existing driver apps of the primary user are installed by default. When a driver app is uninstalled on a sub-user, the corresponding driver app on the primary user is also uninstalled. |
| ACTION<sup>10+</sup> | 19 | [ActionExtensionAbility](js-apis-app-ability-actionExtensionAbility.md): custom service extension capability, providing developers with a custom operation service template based on UIExtension. |
|<!--DelRow--> ADS_SERVICE<sup>11+</sup> | 20 | AdsServiceExtensionAbility: advertising service extension capability, providing custom background advertising services to the outside. Supported only by system applications. |
| EMBEDDED_UI<sup>12+</sup> | 21 | [EmbeddedUIExtensionAbility](js-apis-app-ability-embeddedUIExtensionAbility.md): embedded UI extension capability, providing the capability to embed UIs across processes. |
| INSIGHT_INTENT_UI<sup>12+</sup> | 22 | InsightIntentUIExtensionAbility: provides developers with the extension capability to be invoked by system entries and present content in window form. |
| FENCE<sup>18+</sup> | 24 | [FenceExtensionAbility](../apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md): provides developers with geofence-related capabilities, inherited from ExtensionAbility. |
| ASSET_ACCELERATION<sup>18+</sup> | 26 | AssetAccelerationExtensionAbility: resource pre-download extension capability, providing the capability to pre-download resources in the background when the device is idle. |
| FORM_EDIT<sup>18+</sup> | 27 | [FormEditExtensionAbility](../apis-form-kit/js-apis-app-form-formEditExtensionAbility.md): provides developers with the capability to edit widgets, inherited from UIExtensionAbility. |
| DISTRIBUTED<sup>20+</sup> | 28 | [DistributedExtensionAbility](../apis-distributedservice-kit/js-apis-distributedExtensionAbility.md): provides distributed-related extension capabilities, providing lifecycle callbacks for distributed creation, destruction, and connection. |
| APP_SERVICE<sup>20+</sup> | 29 | [AppServiceExtensionAbility](../apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md): provides background service capabilities for enterprise common apps. |
| LIVE_FORM<sup>20+</sup> | 30 | [LiveFormExtensionAbility](../apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md): interactive widget-related extension capability, providing lifecycle callbacks for interactive widget creation and destruction.<br>**Atomic service API:** This API can be used in atomic services since API version 20.|
| SELECTION<sup>24+</sup> | 31 | [SelectionExtensionAbility](../apis-basic-services-kit/js-apis-selectionInput-selectionExtensionAbility.md): ExtensionAbility that provides developers with the word-selection popup capability.<br>**Model restriction:** This API can be used only in the stage model.|
| WEB_NATIVE_MESSAGING<sup>21+</sup> | 32 | [WebNativeMessagingExtensionAbility](../apis-arkweb/arkts-apis-web-webNativeMessagingExtensionAbility.md): ExtensionAbility that provides developers with Web message communication capabilities.|
| FAULT_LOG<sup>21+</sup> | 33 | [FaultLogExtensionAbility](../apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md): provides the capability to delay fault notifications.|
| NOTIFICATION_SUBSCRIBER<sup>22+</sup> | 34 | [NotificationSubscriberExtensionAbility](../apis-notification-kit/js-apis-notificationSubscriberExtensionAbility.md): provides notification subscription-related functions.|
| CRYPTO<sup>22+</sup> | 35 | [CryptoExtensionAbility](../../security/UniversalKeystoreKit/huks-extension-ability-support-dev.md): provides external key management extension-related functions.|
| PARTNER_AGENT<sup>23+</sup> | 36 | [PartnerAgentExtensionAbility](../apis-connectivity-kit/js-apis-fusionConnectivity-partnerAgentExtensionAbility.md): provides device discovery and device offline notification functions based on Bluetooth communication technology.<br>**Model restriction:** This API can be used only in the stage model.|
| AGENT<sup>24+</sup> | 37 | [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md): provides agent extension capabilities, including lifecycle callback APIs for agent service creation, destruction, connection, and disconnection, as well as callback APIs for receiving data sent by clients and security authentication.<br>**Model restriction:** This API can be used only in the stage model.|
| AGENT_UI<sup>24+</sup> | 38 | [AgentUIExtensionAbility](js-apis-agent-agentUIExtensionAbility.md): provides developers with the capability to access and display on-device Agent UIs.<br>**Model restriction:** This API can be used only in the stage model.|
| MODULAR_OBJECT | 39 | [modular_object_extension_ability](capi-modular-object-extension-ability-h.md): provides [modular object](../../application-models/modular-object-extension-overview.md) extension capability, which can encapsulate an app's own functions into independent functional modules and open them to other apps.<br>**Model restriction:** This API can be used only in the stage model.<br>**Since:** 26.0.0|
| UNSPECIFIED      | 255 | No type specified<!--Del-->. When used with the [queryExtensionAbilityInfo API](js-apis-bundleManager-sys.md#bundlemanagerqueryextensionabilityinfo), all types of ExtensionAbility<!--DelEnd--> can be queried. |

<!--RP2--><!--RP2End-->

## PermissionGrantState

Enumerates the permission grant states.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| PERMISSION_DENIED|  -1 | Permission denied.|
| PERMISSION_GRANTED |  0  |  Permission granted. |

## SupportWindowMode

Enumerates the window modes supported by the ability.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| FULL_SCREEN      | 0   | A window in full-screen mode is supported.|
| SPLIT            | 1   | A window in split-screen mode is supported.|
| FLOATING         | 2   | A floating window is supported.  |

## LaunchType

Enumerates the [launch types](../../application-models/uiability-launch-type.md) of the UIAbility.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| SINGLETON        | 0   | The UIAbility can have only one instance.|
| MULTITON         | 1   | The UIAbility can have multiple instances.|
| SPECIFIED        | 2   | The UIAbility can have one or multiple instances, depending on the internal service of the ability.|

## AbilityType

Enumerates the types of ability components.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

|  Name  | Value  |                            Description                           |
| :-----: | ---- | :--------------------------------------------------------: |
| PAGE    | 1    | Ability that has the UI. FA developed using the Page template to provide the capability of interacting with users.       |
| SERVICE | 2    | Ability of the background service type, without a UI. It represents a [ParticleAbility](js-apis-ability-particleAbility.md) developed based on the Service template, used to provide the capability of running background tasks, such as background download or music playback.  |
|  DATA   | 3    | It represents a [ParticleAbility](js-apis-ability-particleAbility.md) developed based on the Data template, used to provide a unified data access object to the outside. |

## DisplayOrientation

Enumerates the display orientations of the ability. It is applicable only to [PageAbility](../../application-models/pageability-overview.md) in the FA model.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

<!--Table: 40%; 10%; 50%-->

| Name                              |Value|Description|
|:----------------------------------|---|---|
| UNSPECIFIED                        |0 |Unspecified. The orientation is determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LANDSCAPE                          |1 |Landscape.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PORTRAIT                           |2 |Portrait.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| FOLLOW_RECENT                      |3 |The last display orientation is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LANDSCAPE_INVERTED                 |4 |Reverse landscape.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PORTRAIT_INVERTED                  |5 |Reverse portrait.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION                      |6 |Automatically rotates when the sensor changes to landscape or portrait mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_LANDSCAPE            |7 |Automatically rotates when the sensor changes to landscape mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_PORTRAIT             |8 |Automatically rotates when the sensor changes to portrait mode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_RESTRICTED           |9 |Switched-determined auto rotation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_LANDSCAPE_RESTRICTED |10|Indicates the automatic landscape rotation mode controlled by the switch.<br/>**Atomic service API:** This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_PORTRAIT_RESTRICTED  |11|Switched-determined auto rotation in the vertical direction.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LOCKED                             |12|Locked.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_UNSPECIFIED<sup>12+</sup> |13|Auto rotation controlled by the switch and determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FOLLOW_DESKTOP<sup>12+</sup> |14|Following the orientation of the home screen.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## CompatiblePolicy<sup>10+</sup>

Defines the version compatibility type of the dynamic shared library.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                  | Value  | Description                            |
| ---------------------- | ---- | -------------------------------- |
| BACKWARD_COMPATIBILITY | 1    | The shared library is backward compatible.|

## ModuleType

Enumerates the module types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name   | Value  | Description                |
| ------- | ---- | -------------------- |
| ENTRY   | 1    | Main module of and entry to the application, providing the basic application functionality.  |
| FEATURE | 2    | Dynamic feature module of the application, extending the application functionality. This type of HAP can be installed based on user needs and device types.|
| SHARED  | 3    | [Dynamic shared library](../../quick-start/in-app-hsp.md) of the application. |

## BundleType

Enumerates the bundle types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name          | Value  | Description           |
| -------------- | ---- | --------------- |
| APP            | 0    | The bundle is an application.   |
| ATOMIC_SERVICE | 1    | The bundle is an atomic service.|

## MultiAppModeType<sup>12+</sup>

Enumerates the types of the multi-app mode.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name| Value| Description|
|:----------------:|:---:|:---:|
| UNSPECIFIED|  0 | Unspecified. It is the default value of [multiAppMode](../../quick-start/app-configuration-file.md#multiappmode).|
| MULTI_INSTANCE |  1  | [Multi-instance mode](../../quick-start/multiInstance.md). A resident process does not support this value. |
| APP_CLONE |  2  |  [App clone mode](../../quick-start/app-clone.md) |

## AbilityFlag<sup>20+</sup>

Enumerates the ability flags, which indicate the type of ability information to obtain.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                             | Value        | Description                                                        |
| --------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_ABILITY_INFO_DEFAULT          | 0x00000000 | Used to obtain the default [ability information](js-apis-bundleManager-abilityInfo.md), which does not contain permissions, metadata, or ability information of disabled abilities. <!--Del-->You can use [setAbilityEnabled](./js-apis-bundleManager-sys.md#bundlemanagersetabilityenabled) to set the ability enabling status and use [isAbilityEnabled](./js-apis-bundleManager-sys.md#bundlemanagerisabilityenabled-1) to obtain the ability enabling status.<!--DelEnd-->|
| GET_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | Used to obtain the ability information containing permissions.                        |
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | Used to obtain the ability information containing application information.                    |
| GET_ABILITY_INFO_WITH_METADATA    | 0x00000004 | Used to obtain the ability information containing metadata.                           |
| GET_ABILITY_INFO_WITH_DISABLE     | 0x00000008 | Used to obtain the ability information of disabled abilities.                  |
| GET_ABILITY_INFO_ONLY_SYSTEM_APP  | 0x00000010 | Used to obtain the ability information of system applications.                          |
| GET_ABILITY_INFO_WITH_APP_LINKING | 0x00000040 | Used to obtain the ability information that passes <!--RP3-->[domain name verification](../../application-models/app-linking-startup.md#working-principles)<!--RP3End-->.         |
| GET_ABILITY_INFO_WITH_SKILL       | 0x00000080 | Used to obtain the ability information containing skills.                   |

## bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: number): Promise\<BundleInfo>

Obtains the bundle information of the current application based on the given bundle flags. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
// Obtain the bundle information, which contains the application information including a metadata array.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags =
  bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;

try {
  bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
    hilog.info(0x0000, 'testTag', 'getBundleInfoForSelf successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getBundleInfoForSelf failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfoForSelf failed: %{public}s', message);
}
```

## bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information of the current application based on the given bundle flags. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **undefined** and **data** is the **BundleInfo** of the current app; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
// Obtain the bundle information, which contains the ability information including permissions.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags =
  bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_ABILITY |
  bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;

try {
  bundleManager.getBundleInfoForSelf(bundleFlags, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getBundleInfoForSelf failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getBundleInfoForSelf successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfoForSelf failed: %{public}s', message);
}
```

## bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string\>\>): void

Obtains the JSON string array of the current application's configuration file based on the given module name, ability name, and metadata name (name configured under **metadata** in [abilities](../../quick-start/module-configuration-file.md#abilities) of the **module.json5** file). This API uses an asynchronous callback to return the result.

> **NOTE**
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName   | string                        | Yes  | Module name.                                    |
| abilityName  | string                        | Yes  | Name of the UIAbility component.                                   |
| metadataName | string                        | Yes  | [Metadata name](../../quick-start/module-configuration-file.md#metadata) of the UIAbility component, that is, **name** of the **metadata** tag under [abilities](../../quick-start/module-configuration-file.md#abilities) in the **module.json5** file.                                 |
| callback     | AsyncCallback<Array\<string>> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained Array\<string>; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let abilityName = 'EntryAbility';
let metadataName = 'ability_metadata';

try {
  bundleManager.getProfileByAbility(moduleName, abilityName, metadataName, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getProfileByAbility successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', message);
}
```

## bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise\<Array\<string\>\>

Obtains the JSON string array of the current application's configuration file based on the given module name, ability name, and metadata name (name configured under **metadata** in [abilities](../../quick-start/module-configuration-file.md#abilities) of the **module.json5** file). This API uses a promise to return the result.

> **NOTE**
> If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                      |
| ------------ | ------ | ---- | -------------------------- |
| moduleName   | string | Yes  | Module name.  |
| abilityName  | string | Yes  | Name of the UIAbility component. |
| metadataName | string | No  | Metadata name of the UIAbility component, that is, **name** of the **metadata** tag under [abilities](../../quick-start/module-configuration-file.md#abilities) in the **module.json5** file. The default value is null.|

**Return value**

| Type                   | Description                           |
| ----------------------- | ------------------------------- |
| Promise<Array\<string>> | Promise used to return the array of JSON strings obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
  // Obtain the JSON string array of the configuration file based on the module name and ability name.
  bundleManager.getProfileByAbility(moduleName, abilityName).then((data) => {
    hilog.info(0x0000, 'testTag', 'getProfileByAbility successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let abilityName = 'EntryAbility';
let metadataName = 'ability_metadata';

try {
  // Obtain the JSON string array of the current application's configuration file based on the module name, ability name, and metadata name.
  bundleManager.getProfileByAbility(moduleName, abilityName, metadataName).then((data) => {
    hilog.info(0x0000, 'testTag', 'getProfileByAbility successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbility failed. Cause: %{public}s', message);
}
```

## bundleManager.getProfileByAbilitySync<sup>10+</sup>

getProfileByAbilitySync(moduleName: string, abilityName: string, metadataName?: string): Array\<string\>

Obtains the JSON string array of the current application's configuration file based on the given module name, ability name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API returns the result synchronously. The result value is a string array.

>If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                      |
| ------------ | ------ | ---- | -------------------------- |
| moduleName   | string | Yes  | Module name.  |
| abilityName  | string | Yes  | Name of the UIAbility component. |
| metadataName | string | No  | Metadata name of the UIAbility component, that is, **name** of the **metadata** tag under [abilities](../../quick-start/module-configuration-file.md#abilities) in the **module.json5** file. The default value is null.|

**Return value**

| Type                   | Description                           |
| ----------------------- | ------------------------------- |
| Array\<string> | An array of JSON strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |
| 17700029 | The specified ability is disabled.                            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
  // Obtain the JSON string array of the configuration file based on the module name and ability name.
  let data = bundleManager.getProfileByAbilitySync(moduleName, abilityName);
  hilog.info(0x0000, 'testTag', 'getProfileByAbilitySync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbilitySync failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName: string = 'entry';
let abilityName: string = 'EntryAbility';
let metadataName: string = 'ability_metadata';

try {
  // Obtain the JSON string array of the configuration file based on the module name, ability name, and metadata name.
  let data = bundleManager.getProfileByAbilitySync(moduleName, abilityName, metadataName);
  hilog.info(0x0000, 'testTag', 'getProfileByAbilitySync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByAbilitySync failed. Cause: %{public}s', message);
}
```

## bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string\>\>): void

Obtains the JSON string array of the current application's configuration file based on the given module name, ExtensionAbility name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API uses an asynchronous callback to return the result.

>If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type                         | Mandatory| Description                                                        |
| -------------------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName           | string                        | Yes  | Module name.                                  |
| extensionAbilityName | string                        | Yes  | Name of the ExtensionAbility component.                        |
| metadataName         | string                        | Yes  | Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under [extensionAbilities](../../quick-start/module-configuration-file.md#extensionabilities) in the **module.json5** file.                                |
| callback             | AsyncCallback<Array\<string>> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained Array\<string>; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'ability_metadata';

try {
  bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbility successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed: %{public}s', message);
}
```

## bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise\<Array\<string\>\>

Obtains the JSON string array of the current application's configuration file based on the given module name, ExtensionAbility name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API uses a promise to return the result.

>If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type  | Mandatory| Description                              |
| -------------------- | ------ | ---- | ---------------------------------- |
| moduleName           | string | Yes  | Module name.          |
| extensionAbilityName | string | Yes  | Name of the ExtensionAbility component.|
| metadataName         | string | No  | Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under [extensionAbilities](../../quick-start/module-configuration-file.md#extensionabilities) in the **module.json5** file. The default value is null.        |

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Promise<Array\<string>> | Promise used to return the array of JSON strings obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'ability_metadata';

try {
  bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName).then((data) => {
    hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbility successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed. Cause: %{public}s', message);
}

try {
  bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName).then((data) => {
    hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbility successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbility failed. Cause: %{public}s', message);
}
```

## bundleManager.getProfileByExtensionAbilitySync<sup>10+</sup>

getProfileByExtensionAbilitySync(moduleName: string, extensionAbilityName: string, metadataName?: string): Array\<string\>

Obtains the JSON string array of the current application's configuration file based on the given module name, ExtensionAbility name, and metadata name (name configured in [metadata](../../quick-start/module-configuration-file.md#metadata) of the **module.json5** file). This API returns the result synchronously. The result value is a string array.

>If the profile uses the resource reference format, the return value retains this format (for example, **$string:res_id**). You can obtain the referenced resources through related APIs of the [resource manager](../apis-localization-kit/js-apis-resource-manager.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                | Type  | Mandatory| Description                              |
| -------------------- | ------ | ---- | ---------------------------------- |
| moduleName           | string | Yes  | Module name.          |
| extensionAbilityName | string | Yes  | Name of the ExtensionAbility component.|
| metadataName         | string | No  | Metadata name of the ExtensionAbility component, that is, **name** of the **metadata** tag under [extensionAbilities](../../quick-start/module-configuration-file.md#extensionabilities) in the **module.json5** file. The default value is null.|

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| Array\<string> | An array of JSON strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName not existed.            |
| 17700024 | Failed to get the profile because there is no profile in the HAP. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'ability_metadata';

try {
  let data = bundleManager.getProfileByExtensionAbilitySync(moduleName, extensionAbilityName);
  hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbilitySync successfully. Data: %{public}s',
    JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbilitySync failed. Cause: %{public}s', message);
}

try {
  let data = bundleManager.getProfileByExtensionAbilitySync(moduleName, extensionAbilityName, metadataName);
  hilog.info(0x0000, 'testTag', 'getProfileByExtensionAbilitySync successfully. Data: %{public}s',
    JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getProfileByExtensionAbilitySync failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleInfoForSelfSync<sup>10+</sup>

getBundleInfoForSelfSync(bundleFlags: number): BundleInfo

Obtains the bundle information of the current application based on the given bundle flags. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type                                             | Description                |
| ------------------------------------------------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;

try {
  let data = bundleManager.getBundleInfoForSelfSync(bundleFlags);
  hilog.info(0x0000, 'testTag', 'getBundleInfoForSelfSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfoForSelfSync failed: %{public}s', message);
}
```

## bundleManager.canOpenLink<sup>12+</sup>

canOpenLink(link: string): boolean

Checks whether the target application can be accessed based on the provided link. The scheme specified in the link must be configured in the **querySchemes** field of the [module.json5](../../quick-start/module-configuration-file.md) file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| link | string | Yes  | Link to check.|

**Return value**

| Type                                             | Description                |
| ------------------------------------------------- | -------------------- |
| boolean | Check result for whether the link can be opened. **true** if it can be opened, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700055 | The specified link is invalid.                      |
| 17700056 | The scheme of the specified link is not in the querySchemes.        |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  let link = 'welink://';
  let data = bundleManager.canOpenLink(link);
  hilog.info(0x0000, 'testTag', 'canOpenLink successfully: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'canOpenLink failed: %{public}s', message);
}
```

## bundleManager.getLaunchWant<sup>13+</sup>

getLaunchWant(): Want

Obtains the **Want** parameters of the [entry UIAbility](../../quick-start/application-package-glossary.md#entry-uiability) of the current application.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                               | Description                                       |
| ----------------------------------- | ------------------------------------------- |
| [Want](js-apis-app-ability-want.md) | Want object that contains only the bundle name and ability name.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 17700072 | The launch want is not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  let want = bundleManager.getLaunchWant();
  hilog.info(0x0000, 'testTag', 'getLaunchWant ability name: %{public}s', want.abilityName);
  hilog.info(0x0000, 'testTag', 'getLaunchWant bundle name: %{public}s', want.bundleName);
} catch (error) {
  let message = (error as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getLaunchWant failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the [BundleInfo](./js-apis-bundleManager-bundleInfo.md) based on the given bundle name, bundle flags, and user ID. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes   | User ID, which can be obtained by [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).  |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained **BundleInfo**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
// Obtain the bundle information, which contains the ability information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags =
  bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_ABILITY;
let userId = 100;

try {
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

```ts
// Obtain the bundle information, which contains the application information including metadata.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags =
  bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;
let userId = 100;

try {
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given bundle name and bundle flags. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained **BundleInfo**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
// Obtain the bundle information with the ExtensionAbility information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE |
bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
  bundleManager.getBundleInfo(bundleName, bundleFlags, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<BundleInfo>

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.      |
| userId      | number | No   | User ID, which can be obtained by [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). Default value: the user where the caller is located. Value range: greater than or equal to 0.  |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
// Obtain the bundle information with the application and signature information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION |
bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let userId = 100;

try {
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId).then((data) => {
    hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
  bundleManager.getBundleInfo(bundleName, bundleFlags).then((data) => {
    hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleInfoSync<sup>14+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number, userId: number): BundleInfo

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | Yes  | Bundle name.                                |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes   | User ID, which can be obtained by [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).              |

**Return value**

| Type      | Description                |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);
}
```

## bundleManager.getBundleInfoSync<sup>14+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo

Obtains the bundle information for the caller's user based on the given bundle name and bundle flags. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                                  |
| ----------- | --------------------- | ---- | ------------------------------------------------------ |
| bundleName  | string                | Yes  | Bundle name.                            |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type                                             | Description                |
| ------------------------------------------------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
try {
  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags);
  hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);
}
```

## bundleManager.getBundleNameByUid<sup>14+</sup>

getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void

Obtains the bundle name based on the given UID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                 | Yes  | UID of the application.                                           |
| callback | AsyncCallback\<string> | Yes | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback). If the operation is successful, **err** is **undefined** and **data** is the obtained bundle name; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005;
try {
  bundleManager.getBundleNameByUid(uid, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully: %{public}s', JSON.stringify(data));
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', message);
}
```

## bundleManager.getBundleNameByUid<sup>14+</sup>

getBundleNameByUid(uid: number): Promise\<string>

Obtains the bundle name based on the given UID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------ |
| uid  | number | Yes  | UID of the application.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| Promise\<string> | Promise used to return the bundle name obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005;
try {
  bundleManager.getBundleNameByUid(uid).then((data) => {
    hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleNameByUidSync<sup>14+</sup>

getBundleNameByUidSync(uid: number): string

Obtains the bundle name based on the given UID. This API returns the result synchronously.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------ |
| uid  | number | Yes  | UID of the application.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| string | Bundle name obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005;
try {
  let data = bundleManager.getBundleNameByUidSync(uid);
  hilog.info(0x0000, 'testTag', 'getBundleNameByUidSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getBundleNameByUidSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppCloneIdentity<sup>14+</sup>

getAppCloneIdentity(uid: number): Promise\<AppCloneIdentity>;

Obtains the bundle name and clone index of a cloned application based on the given UID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

 - When the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - When the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO permission is required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------|
|    uid     | number |  Yes |     UID of the application.     |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[AppCloneIdentity](js-apis-bundleManager-bundleInfo.md#appcloneidentity14)> | Promise used to return the AppCloneIdentity information. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005;

try {
  bundleManager.getAppCloneIdentity(uid).then((res) => {
    hilog.info(0x0000, 'testTag', 'getAppCloneIdentity res = %{public}s', JSON.stringify(res));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getAppCloneIdentity failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getAppCloneIdentity failed. Cause: %{public}s', message);
}
```

## bundleManager.getSignatureInfo<sup>18+</sup>

getSignatureInfo(uid: number): SignatureInfo

Obtains the [signature information](./js-apis-bundleManager-bundleInfo.md#signatureinfo) of an application based on the given UID.

**Required permissions**: ohos.permission.GET_SIGNATURE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------ |
| uid  | number | Yes  | UID of the application.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| [SignatureInfo](./js-apis-bundleManager-bundleInfo.md#signatureinfo) | SignatureInfo object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let uid = 20010005; // Replace uid with the UID of the corresponding application.
try {
  let data = bundleManager.getSignatureInfo(uid);
  hilog.info(0x0000, 'testTag', 'getSignatureInfo successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getSignatureInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAbilityInfo<sup>20+</sup>

getAbilityInfo(uri: string, abilityFlags: number): Promise\<Array\<AbilityInfo>>

Obtains the ability information based on the given resource identifier and ability flag. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Required permissions**: ohos.permission.GET_ABILITY_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Device behavior differences**: This API can be properly called only on PCs/2-in-1 devices. If it is called on other device types, error code 201 is returned.

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| uri         | string   | Yes  | URI of the resource. The value is the same as that of the [uris field under skills in the module.json5 file](../../quick-start/module-configuration-file.md#skills).                  |
| abilityFlags  | number | Yes  | [Ability flag](js-apis-bundleManager.md#abilityflag20), indicating the ability information to be obtained.|

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Promise used to return an array of ability information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 17700003 | The ability is not found.    |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_WITH_APPLICATION;
let uri = "https://www.example.com";

try {
  bundleManager.getAbilityInfo(uri, abilityFlags).then((data) => {
    hilog.info(0x0000, 'testTag', 'getAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAbilityInfo failed. Cause: %{public}s', message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.cleanBundleCacheFilesForSelf<sup>21+</sup>

cleanBundleCacheFilesForSelf(): Promise\<void>

Clears the application cache. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 21.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

bundleManager.cleanBundleCacheFilesForSelf().then(() => {
  hilog.info(0x0000, 'testTag', 'cleanBundleCacheFilesForSelf complete.');
});
```

## bundleManager.getPluginBundlePathForSelf<sup>22+</sup>

getPluginBundlePathForSelf(pluginBundleName: string): string

Obtains the installation path of a specified plugin in the current [application sandbox](../../file-management/app-sandbox-directory.md).

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name           | Type   | Mandatory| Description               |
| ---------------- | ------ | ---- | ------------------ |
| pluginBundleName | string | Yes  | Bundle name of the target plugin.|

**Return value**

| Type    | Description                 |
| ------- | --------------------- |
| string  | Installation path of the target plugin in the current application sandbox.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID | Error Message                                 |
| -------- | --------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

// Use the actual bundle name of the plugin.
let pluginBundleName = 'com.ohos.pluginDemo';
try {
  let path = bundleManager.getPluginBundlePathForSelf(pluginBundleName);
  hilog.info(0x0000, 'testTag', 'getPluginBundlePathForSelf successfully. path: %{public}s', path);
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getPluginBundlePathForSelf failed. Cause: %{public}s', message);
}
```

## bundleManager.getLaunchWantForBundleSync<sup>24+</sup>

getLaunchWantForBundleSync(bundleName: string, userId?: number): Want

Obtains the **Want** parameters for starting an application based on the given bundle name and user ID.

**Required permissions:** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or (ohos.permission.GET_BUNDLE_INFO_PRIVILEGED and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS)

 - To obtain the **Want** parameters for starting an application under the current user, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required.

 - To obtain the **Want** parameters for starting an application under another user, if the caller is a system application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission is required; if the caller is a third-party application, the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS permissions are required.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory | Description                       |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | Yes   | Bundle name of the app. |
| userId     | number | No   | User ID, which can be obtained through [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).<br/>Default value: the user where the caller is located.<br/>Value range: greater than or equal to 0. |

**Return value**

| Type           | Description                      |
| -------------- | ------------------------- |
| [Want](js-apis-app-ability-want.md#want)| **Want** object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID | Error Message                             |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 17700001 | The specified bundle is not found.  |
| 17700004 | The specified user id is not found. |
| 17700026 | The specified bundle is disabled.   |

**Example**

```ts
// The sample API contains the userId parameter and obtains the Want parameter required for starting the application of a specified user.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';

let bundleName = 'com.example.myapplication';
let userId = 100;

try {
  let want: Want = bundleManager.getLaunchWantForBundleSync(bundleName, userId);
  hilog.info(0x0000, 'testTag', 'getLaunchWantForBundleSync successfully. Data: %{public}s', JSON.stringify(want));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getLaunchWantForBundleSync failed. Cause: %{public}s', message);
}
```

```ts
// The sample API does not contain the userId parameter and obtains the Want parameter required for starting the application of the current user.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';

let bundleName = 'com.example.myapplication';

try {
  let want: Want = bundleManager.getLaunchWantForBundleSync(bundleName);
  hilog.info(0x0000, 'testTag', 'getLaunchWantForBundleSync successfully. Data: %{public}s', JSON.stringify(want));
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getLaunchWantForBundleSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getApplicationLabel

getApplicationLabel(bundleName: string, appIndex: number): Promise\<string>

Obtains the app name based on the given bundle name and app index. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability:** SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name        | Type                                                | Mandatory | Description                    |
| ------------ | --------------------------------------------------- | ---- | ----------------------- |
| bundleName  | string |Yes | Bundle name of the app. |
| appIndex   | number  | Yes   | App index. The value ranges from 0 to 5, where 0 indicates the main app and 1 to 5 indicate the indexes of app clones.  |

**Return value**

| Type                                                         | Description                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<string> | Promise used to return the app name if the call succeeds, or an error object if the call fails. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID |    Error Message                   |
|----------|-------------------------|
| 201 | Permission denied. |
| 17700001 | The specified bundle is not found. |
| 17700061 | The specified app index is invalid. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  bundleManager.getApplicationLabel('com.hap.myapplication', 1).then((data: string) => {
    hilog.info(0x0000, 'testTag', 'getApplicationLabel succeed: Data: %{public}s', data);
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getApplicationLabel failed: %{public}d  %{public}s', err.code, err.message);
  });
} catch (err) {
  hilog.error(0x0000, 'testTag', 'getApplicationLabel failed: error %{public}d  %{public}s', err.code, err.message);
}
```

## bundleManager.getInstalledBundleList

getInstalledBundleList(bundleFlags: number): Promise<Array\<BundleInfo>>

Obtains all **BundleInfo** objects in the system based on the given bundleFlags. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ENTERPRISE_GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Device behavior differences:** This API is supported only on PC/2-in-1 devices. On other device types, it returns error code 201.

**Parameters**

| Name     | Type   | Mandatory | Description                                             |
| ----------- | ------ | ---- | -------------------------------------------------- |
| bundleFlags | number | Yes   | Information contained in the returned **BundleInfo**. For details, see [BundleFlag](js-apis-bundleManager.md#bundleflag).                |

**Return value**

| Type                                                         | Description                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1)>> | Promise used to return the list of information about the currently installed apps. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                         |
| -------- | ---------------------------------- |
| 201 | Permission denied. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
  bundleManager.getInstalledBundleList(bundleFlags).then((data) => {
    hilog.info(0x0000, 'testTag', 'getInstalledBundleList successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getInstalledBundleList failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getInstalledBundleList failed. Cause: %{public}s', message);
}
```

## bundleManager.setAlternateIcon

setAlternateIcon(alternateIconName: string): Promise\<void>;

Sets the alternate icon of the caller based on the given alternate icon name. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory | Description                       |
| ----------- | ------ | ---- | ---------------------------- |
| alternateIconName  | string | Yes   | Name of the alternate icon to set. The alternate icon name must be in the name field of the [alternateIcons tag](../../quick-start/app-configuration-file.md#alternateicons) in app.json5.<br/>If alternateIconName is empty, the alternate icon is canceled. |

**Return value**

| Type                                                        | Description                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID | Error Message                            |
| -------- | --------------------------------------|
| 17700308 | The alternateIconName must match the name field under alternateIcons in the app.json5 file. |
| 17700309 | No alternate icon is enabled. |
| 17700310 | Failed to set the alternate icon. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

// Replace alternateIconName with the name of the alternate icon to set.
let alternateIconName: string = 'com.ohos.demo';

try {
  bundleManager.setAlternateIcon(alternateIconName).then((data) => {
    hilog.info(0x0000, 'testTag', 'setAlternateIcon successfully');
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'setAlternateIcon failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'setAlternateIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.getAlternateIcons

getAlternateIcons(): Promise<Array\<AlternateIconInfo>>

Queries the alternate icon information configured in the [alternateIcons tag](../../quick-start/app-configuration-file.md#alternateicons) in app.json5 of the current app. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                                         | Description                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[AlternateIconInfo](js-apis-bundleManager-bundleInfo.md#alternateiconinfo)>> | Promise used to return the list of alternate icon information of the current app. |

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID | Error Message                         |
| -------- | ---------------------------------- |
| 17700311 | Failed to obtain the alternate icon. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
  bundleManager.getAlternateIcons().then((data) => {
    hilog.info(0x0000, 'testTag', 'getAlternateIcons successfully. Data: %{public}s', JSON.stringify(data));
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'getAlternateIcons failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'getAlternateIcons failed. Cause: %{public}s', message);
}
```

## ApplicationInfo

type ApplicationInfo = _ApplicationInfo

Defines the application information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ApplicationInfo](js-apis-bundleManager-applicationInfo.md#applicationinfo-1) | Application information.|

## ModuleMetadata<sup>10+</sup>

type ModuleMetadata = _ModuleMetadata

Defines the metadata of a module.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ModuleMetadata](js-apis-bundleManager-applicationInfo.md#modulemetadata10) | Metadata of the module.|

## Metadata

type Metadata = _Metadata

Defines the metadata.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_Metadata](js-apis-bundleManager-metadata.md#metadata-1) | Metadata.|

## BundleInfo

type BundleInfo = _BundleInfo.BundleInfo

Defines the bundle information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1) | Bundle information.|

## UsedScene

type UsedScene = _BundleInfo.UsedScene

Defines the use scenario and timing for using the permission.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.UsedScene](js-apis-bundleManager-bundleInfo.md#usedscene) | Use scenario and timing for using the permission.|

## ReqPermissionDetail

type ReqPermissionDetail = _BundleInfo.ReqPermissionDetail

Defines the detailed information of the permissions to request from the system.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.ReqPermissionDetail](js-apis-bundleManager-bundleInfo.md#reqpermissiondetail) | Detailed information of the permissions to request from the system.|

## SignatureInfo

type SignatureInfo = _BundleInfo.SignatureInfo

Defines the signature information of the bundle.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.SignatureInfo](js-apis-bundleManager-bundleInfo.md#signatureinfo) | Signature information of the bundle.|

## HapModuleInfo

type HapModuleInfo = _HapModuleInfo.HapModuleInfo

Defines the module information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md#hapmoduleinfo-1) | Module information.|

## PreloadItem

type PreloadItem = _HapModuleInfo.PreloadItem

Defines the preloaded module information in the atomic service.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.PreloadItem](js-apis-bundleManager-hapModuleInfo.md#preloaditem) | Preloaded module information in the atomic service.|

## Dependency

type Dependency = _HapModuleInfo.Dependency

Defines the information about the dynamic shared libraries on which the module depends.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.Dependency](js-apis-bundleManager-hapModuleInfo.md#dependency) | Information about the dynamic shared libraries on which the module depends.|

## RouterItem<sup>12+</sup>

type RouterItem = _HapModuleInfo.RouterItem

Defines the router table configuration of the module.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.RouterItem](js-apis-bundleManager-hapModuleInfo.md#routeritem12) | Router table configuration of the module.|

## DataItem<sup>12+</sup>

type DataItem = _HapModuleInfo.DataItem

Defines the user-defined data in the routing table configuration of the module.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_HapModuleInfo.DataItem](js-apis-bundleManager-hapModuleInfo.md#dataitem12) | User-defined data in the routing table configuration of the module.|

## AbilityInfo

type AbilityInfo = _AbilityInfo.AbilityInfo

Defines the ability information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_AbilityInfo.AbilityInfo](js-apis-bundleManager-abilityInfo.md#abilityinfo-1) |Ability information.|

## WindowSize

type WindowSize = _AbilityInfo.WindowSize

Defines the window size.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_AbilityInfo.WindowSize](js-apis-bundleManager-abilityInfo.md#windowsize) |Window size.|

## ExtensionAbilityInfo

type ExtensionAbilityInfo = _ExtensionAbilityInfo.ExtensionAbilityInfo

Defines the ExtensionAbility information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ExtensionAbilityInfo.ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md#extensionabilityinfo-1) |ExtensionAbility information.|

## ElementName

type ElementName = _ElementName

Defines the element name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_ElementName](js-apis-bundleManager-elementName.md#elementname-1) |Element name.|

## Skill<sup>12+</sup>

type Skill = _Skill.Skill

Skill information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_Skill.Skill](js-apis-bundleManager-skill.md#skill-1) |Skill information. |

## SkillUrl<sup>12+</sup>

type SkillUrl = _Skill.SkillUri

Defines the SkillUri information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_Skill.SkillUri](js-apis-bundleManager-skill.md#skilluri) |SkillUri information.|

## AppCloneIdentity<sup>15+</sup>

type AppCloneIdentity = _BundleInfo.AppCloneIdentity

Describes the identity information of an application clone.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.AppCloneIdentity](js-apis-bundleManager-bundleInfo.md#appcloneidentity14) |Identity information of an application clone.|

## AlternateIconInfo

type AlternateIconInfo = _BundleInfo.AlternateIconInfo

Alternate icon information of the app.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                         | Description           |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.AlternateIconInfo](js-apis-bundleManager-bundleInfo.md#alternateiconinfo) | Alternate icon information of the app. |