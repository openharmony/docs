# @ohos.app.ability.wantConstant (Want Constants)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @linjunjie6-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


The wantConstant provides predefined enums and constants related to [Want](js-apis-app-ability-want.md) operations, such as the **flags** and **params** fields used during ability startup.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { wantConstant } from '@kit.AbilityKit';
```

## Params

Enumerates the common system-defined keywords for the [Want.parameters](js-apis-app-ability-want.md#want) field. You can use these predefined keywords to set or retrieve additional parameter information carried in application transitions. For example, during the launch phase of a UIAbility, if the value of **ABILITY_RECOVERY_RESTART** obtained from the **want** field in the **onCreate** callback is **true**, the current UIAbility has restarted due to a fault.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                   | Value                                | Description                                                                          |
| ----------------------- | ---------------------------------- | ------------------------------------------------------------------------------ |
| ABILITY_BACK_TO_OTHER_MISSION_STACK   | ability.params.backToOtherMissionStack     | Whether redirection back across mission stacks is supported.<br>This parameter controls the redirection-back logic across applications, altering the application transition behavior when the user presses the back button. For example, if UIAbility A is currently displayed and UIAbility B is launched with this parameter set to **true**, exiting UIAbility B will return to UIAbility A. If this parameter is not set, the system defaults to returning to the home screen. Note that this parameter is only supported for system applications and does not take effect for third-party applications.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| ABILITY_RECOVERY_RESTART<sup>10+</sup> | ohos.ability.params.abilityRecoveryRestart | Whether the ability has been restarted due to a fault.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| CONTENT_TITLE_KEY<sup>10+</sup>       | ohos.extra.param.key.contentTitle  | Title for sharing in an atomic service.<br>You can set the sharing title using this field in the [onShare](js-apis-app-ability-uiAbility.md#onshare10) callback.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| SHARE_ABSTRACT_KEY<sup>10+</sup>      | ohos.extra.param.key.shareAbstract | Content abstract for sharing in an atomic service.<br>You can set the sharing abstract using this field in the [onShare](js-apis-app-ability-uiAbility.md#onshare10) callback.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| SHARE_URL_KEY<sup>10+</sup>           | ohos.extra.param.key.shareUrl      | URL link for sharing in an atomic service.<br>You can set the URL link using this field in the [onShare](js-apis-app-ability-uiAbility.md#onshare10) callback.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| SUPPORT_CONTINUE_PAGE_STACK_KEY<sup>10+</sup>    | ohos.extra.param.key.supportContinuePageStack  | Whether to migrate the page stack information during cross-device migration. The default value is **true**, indicating that the page stack information is automatically migrated during cross-device migration.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SUPPORT_CONTINUE_SOURCE_EXIT_KEY<sup>10+</sup>  | ohos.extra.param.key.supportContinueSourceExit      | Whether the source application exits during cross-device migration. The default value is** true**, indicating that the source application automatically exits during cross-device migration.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SHOW_MODE_KEY<sup>12+</sup>  | ohos.extra.param.key.showMode      | Display mode of the [EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md). The value is an enumerated value of [ShowMode](#showmode12).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PARAMS_STREAM<sup>12+</sup>  | ability.params.stream  | List of file URIs authorized to the target. The value must be an array of file URIs of the string type. For details about how to obtain the file URI, see [fileUri](../apis-core-file-kit/js-apis-file-fileuri.md#fileurigeturifrompath). This field must be used in conjunction with file URI [read/write flag](js-apis-app-ability-wantConstant.md#flags).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| APP_CLONE_INDEX_KEY<sup>12+</sup>  | ohos.extra.param.key.appCloneIndex  | Index of an application clone.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| CALLER_REQUEST_CODE<sup>12+</sup>  | ohos.extra.param.key.callerRequestCode  | Request code<br>that uniquely identifies the caller of [startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#startabilityforresult) or [openLink](js-apis-inner-application-uiAbilityContext.md#openlink12). When either of the APIs is called to start an ability, the target ability returns the result to the caller based on the request code.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PAGE_PATH<sup>12+</sup>  | ohos.param.atomicservice.pagePath | Page path for an atomic service.<br>If page redirection in an atomic service is implemented using [router](../../ui/arkts-routing.md), you can use this parameter to specify the target page, for example, **library/ets/pages/menu**.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| ROUTER_NAME<sup>12+</sup>  | ohos.param.atomicservice.routerName | Router name for page redirection in an atomic service.<br>If page redirection in an atomic service is implemented using [Navigation](../../ui/arkts-navigation-navigation.md), you can use **ROUTER_NAME**, **PAGE_SOURCE_FILE**, and **BUILD_FUNCTION** together to specify the target page.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| PAGE_SOURCE_FILE<sup>12+</sup>  | ohos.param.atomicservice.pageSourceFile | Source file for the page in an atomic service.<br>If page redirection in an atomic service is implemented using [Navigation](../../ui/arkts-navigation-navigation.md), you can use **ROUTER_NAME**, **PAGE_SOURCE_FILE**, and **BUILD_FUNCTION** together to specify the target page.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| BUILD_FUNCTION<sup>12+</sup>  | ohos.param.atomicservice.buildFunction | Build function for the page in an atomic service.<br>If page redirection in an atomic service is implemented using [Navigation](../../ui/arkts-navigation-navigation.md), you can use **ROUTER_NAME**, **PAGE_SOURCE_FILE**, and **BUILD_FUNCTION** together to specify the target page.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| SUB_PACKAGE_NAME<sup>12+</sup>  | ohos.param.atomicservice.subpackageName | Sub-package name for an atomic service. Application packages can be developed with multiple modules, and each package may include one or multiple HAPs or HSPs. To enhance the launch speed, atomic services restrict the size of HAP and HSP files and optimize the startup process. This modular development approach is known as sub-packaging.<br>When you open an atomic service, you can use this parameter to activate the specific sub-package.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| APP_INSTANCE_KEY<sup>14+</sup>  | ohos.extra.param.key.appInstance  | Specific application instance.<br>When you create [multiple instances](../../quick-start/multiInstance.md) of an application, the system assigns a unique ID to each instance. During application transitions, you can use this parameter to specify which created application instance you want to transition to.|
| CREATE_APP_INSTANCE_KEY<sup>14+</sup>  | ohos.extra.param.key.createAppInstance  | Whether to create an application instance. The default value is **false**, indicating that no new application instance is created.<br>You can set this parameter to **true** to launch a new application instance. Note that the application to be launched must support multiple instances. For details, see [Creating an Application Multi-Instance](../../quick-start/multiInstance.md).|
| CALLER_APP_CLONE_INDEX<sup>14+</sup>  | ohos.param.callerAppCloneIndex  | Index of the application clone to be launched. When an application has multiple [clones](../../quick-start/app-clone.md), you can use this parameter to specify which clone of the application is being launched.|
| APP_LAUNCH_TRUSTLIST<sup>17+</sup>  | ohos.params.appLaunchTrustList  | Filter list of applications for implicit launch.<br>Only applications in the list are matched during implicit launch. The value is an array of [AppIdentifiers](js-apis-bundleManager-bundleInfo.md#signatureinfo) of the string type. The filter list supports a maximum of 50 applications. Passing an empty array will have no effect.<br>**Atomic service API**: This API can be used in atomic services since API version 17.|
| LAUNCH_REASON_MESSAGE<sup>18+</sup>  | ohos.params.launchReasonMessage  | Reason for launching the application.<br>The caller must be a system application and must request the ohos.permission.SET_LAUNCH_REASON_MESSAGE permission. Currently, the value can only be **ReasonMessage_SystemShare**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| DESTINATION_PLUGIN_ABILITY<sup>19+</sup>  | ohos.params.pluginAbility  | The target ability is a plugin ability.|
| ATOMIC_SERVICE_SHARE_ROUTER<sup>20+</sup>  | ohos.params.atomicservice.shareRouter  | Page stack information of the atomic service being launched. This parameter takes effect only when the caller is a UIAbilityContext and the callee is an atomic service.<br>For example, if an atomic service contains a home page and a second page, and you want to directly launch the second page, you can pass the page stack information of the second page through this field when launching the atomic service.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| ABILITY_UNIFIED_DATA_KEY<sup>20+</sup>  | ohos.param.ability.udKey  | Unique identifier for file sharing based on [UDMF](../../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md). This field can only be set by system applications, but third-party applications can read it.<br>If the Want contains a URI authorization flag (for example, [FLAG_AUTH_READ_URI_PERMISSION](#flags) or [FLAG_AUTH_WRITE_URI_PERMISSION](#flags)) and the **PARAMS_STREAM** field is also present, this field does not take effect.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## Flags

Enumerates the common preset keywords of the [Want.flags](js-apis-app-ability-want.md#want) field. You can use these predefined keywords to set or retrieve additional flag information carried in application transitions.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Temporarily grants the receiver read permission for the URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Temporarily grants the receiver write permission for the URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                 |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION<sup>12+</sup> | 0x00000040 | The URI can be persisted by the receiver. It takes effect only on 2-in-1 devices and tablets.|
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Enables on-demand installation when launching an atomic service.<br>- If enabled, the system automatically installs the atomic service if it is not already installed before proceeding with the launch.<br>- If disabled, the launch fails if the atomic service is not installed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                             |
| FLAG_START_WITHOUT_TIPS<sup>11+</sup>              | 0x40000000 | Disables the "No available applications" prompt during implicit application launches.<br>When [launching an application implicitly](../../application-models/app-startup-overview.md), a prompt saying "No available applications" will appear if no matching application is found. You can use this flag to prevent this prompt from appearing.      |
| FLAG_ABILITY_ON_COLLABORATE<sup>18+</sup> | 0x00002000 | In multi-device collaboration scenario, the caller application must initiate a request through the DMS, with this flag included in the **Flags** field, in order to invoke the lifecycle callback [onCollaborate()](js-apis-app-ability-uiAbility.md#oncollaborate18) of the target application.|

## ShowMode<sup>12+</sup>

Enumerates the display modes of an [EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md) when it is launched.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                               | Value| Description          |
| ----------------------------------- |---|--------------|
| WINDOW        | 0 | An independent window is used to show the ability startup. |
| EMBEDDED_FULL       | 1 | An embedded full-screen is used to show the ability startup.|
