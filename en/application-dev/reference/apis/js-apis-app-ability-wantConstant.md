# @ohos.app.ability.wantConstant (wantConstant)

The **wantConstant** module provides the actions, entities, and flags used in **Want** objects.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import wantConstant from '@ohos.app.ability.wantConstant';
```

## wantConstant.Params

Defines **Params** (specifying the action that can be performed) in the Want.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                   | Value                                | Description                                                                          |
| ----------------------- | ---------------------------------- | ------------------------------------------------------------------------------ |
| DLP_PARAMS_SANDBOX      | ohos.dlp.params.sandbox            | Action of obtaining the sandbox flag.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| DLP_PARAMS_BUNDLE_NAME  | ohos.dlp.params.bundleName         | Action of obtaining the DLP bundle name.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| DLP_PARAMS_MODULE_NAME  | ohos.dlp.params.moduleName         | Action of obtaining the DLP module name.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| DLP_PARAMS_ABILITY_NAME | ohos.dlp.params.abilityName        | Action of obtaining the DLP ability name.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| DLP_PARAMS_INDEX        | ohos.dlp.params.index              | Action of obtaining the DLP index.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| ABILITY_BACK_TO_OTHER_MISSION_STACK   | ability.params.backToOtherMissionStack     | Whether to support redirection back across mission stacks. |
| ABILITY_RECOVERY_RESTART<sup>10+</sup> | ohos.ability.params.abilityRecoveryRestart | Action of recovering an ability from a fault and restarting it.|
| CONTENT_TITLE_KEY<sup>10+</sup>       | ohos.extra.param.key.contentTitle  | Action of sharing the content title. |
| SHARE_ABSTRACT_KEY<sup>10+</sup>      | ohos.extra.param.key.shareAbstract | Action of sharing the abstract. |
| SHARE_URL_KEY<sup>10+</sup>           | ohos.extra.param.key.shareUrl      | Action of sharing the URL. |
| SUPPORT_CONTINUE_PAGE_STACK_KEY<sup>10+</sup>    | ohos.extra.param.key.supportContinuePageStack  | Whether to migrate page stack information during cross-device migration. The default value is **true**, indicating that page stack information is automatically migrated.|
| SUPPORT_CONTINUE_SOURCE_EXIT_KEY<sup>10+</sup>  | ohos.extra.param.key.supportContinueSourceExit      | Whether to exit the application on the source device during cross-device migration. The default value is **true**, indicating that the application on the source device automatically exits.|


## wantConstant.Flags

 Enumerates the flags that specify how the Want will be handled.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write data to the URI.                                 |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION<sup>10+</sup> | 0x00000040 | Indicates the permanent permission of the URI. This flag is valid only for 2-in-1 applications.<br>**System API**: This is a system API and cannot be called by third-party applications.<br>If this flag is used together with **FLAG_AUTH_READ_URI_PERMISSION**, the permanent read permission is granted.<br>If this flag is used together with **FLAG_AUTH_WRITE_URI_PERMISSION**, the permanent write permission is granted.<br>The flag takes effect only when the **PERMISSION_PROXY_AUTHORIZATION_URI** permission is configured for the application.|
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.                             |
