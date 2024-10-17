# @ohos.app.ability.wantConstant (wantConstant)

The wantConstant module provides the actions, entities, and flags used in **Want** objects.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { wantConstant } from '@kit.AbilityKit';
```

## Params

Defines **Params** (specifying the action that can be performed) in the Want.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                   | Value                                | Description                                                                          |
| ----------------------- | ---------------------------------- | ------------------------------------------------------------------------------ |
| ABILITY_BACK_TO_OTHER_MISSION_STACK   | ability.params.backToOtherMissionStack     | Action of redirection back across mission stacks.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| ABILITY_RECOVERY_RESTART<sup>10+</sup> | ohos.ability.params.abilityRecoveryRestart | Action of recovering an ability from a fault and restarting it.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| CONTENT_TITLE_KEY<sup>10+</sup>       | ohos.extra.param.key.contentTitle  | Action of sharing the content title.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| SHARE_ABSTRACT_KEY<sup>10+</sup>      | ohos.extra.param.key.shareAbstract | Action of sharing the abstract.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| SHARE_URL_KEY<sup>10+</sup>           | ohos.extra.param.key.shareUrl      | Action of sharing the URL.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| SUPPORT_CONTINUE_PAGE_STACK_KEY<sup>10+</sup>    | ohos.extra.param.key.supportContinuePageStack  | Action of migrating page stack information during cross-device migration. The default value is **true**, indicating that page stack information is automatically migrated.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SUPPORT_CONTINUE_SOURCE_EXIT_KEY<sup>10+</sup>  | ohos.extra.param.key.supportContinueSourceExit      | Action of exiting the application on the source device during cross-device migration. The default value is **true**, indicating that the application on the source device automatically exits.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SHOW_MODE_KEY<sup>12+</sup>  | ohos.extra.param.key.showMode      | Show mode. For details, see **wantConstant.ShowMode**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| PARAMS_STREAM<sup>12+</sup>  | ability.params.stream  | File URIs to be authorized to the target ability. The value must be an array of file URIs of the string type. For details about how to obtain the file URI, see [fileUri](../apis-core-file-kit/js-apis-file-fileuri.md#fileurigeturifrompath).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| APP_CLONE_INDEX_KEY<sup>12+</sup>  | ohos.extra.param.key.appCloneIndex  | Index of an application clone.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| CALLER_REQUEST_CODE<sup>12+</sup>  | ohos.extra.param.key.callerRequestCode  | Request code that uniquely idenfies the caller of [startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilityforresult) or [openLink](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12). When either of the APIs is called to start an ability, the target ability returns the result to the caller based on the request code.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
## Flags

 Enumerates the flags that specify how the Want will be handled.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Grant the permission to read the URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Grant the permission to write data to the URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                 |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION<sup>12+</sup> | 0x00000040 | Make the URI persisted. It takes effect only on tablets.|
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Install the ability if it has not been installed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                             |
| FLAG_START_WITHOUT_TIPS<sup>11+</sup>              | 0x40000000 | Do not display any tips if the ability implicitly started does not match any application.      |
## ShowMode<sup>12+</sup>

Enumerates the modes used to show the atomic service startup.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                               | Value| Description          |
| ----------------------------------- |---|--------------|
| WINDOW        | 0 | An independent window is used to show the ability startup. |
| EMBEDDED_FULL       | 1 | An embedded full-screen is used to show the ability startup.|
