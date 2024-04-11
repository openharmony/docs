# @ohos.app.ability.wantConstant (wantConstant)

The wantConstant module provides the actions, entities, and flags used in **Want** objects.

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
| ABILITY_BACK_TO_OTHER_MISSION_STACK   | ability.params.backToOtherMissionStack     | Whether to support redirection back across mission stacks. |
| ABILITY_RECOVERY_RESTART<sup>10+</sup> | ohos.ability.params.abilityRecoveryRestart | Action of recovering an ability from a fault and restarting it.|
| CONTENT_TITLE_KEY<sup>10+</sup>       | ohos.extra.param.key.contentTitle  | Action of sharing the content title. |
| SHARE_ABSTRACT_KEY<sup>10+</sup>      | ohos.extra.param.key.shareAbstract | Action of sharing the abstract. |
| SHARE_URL_KEY<sup>10+</sup>           | ohos.extra.param.key.shareUrl      | Action of sharing the URL. |
| SUPPORT_CONTINUE_PAGE_STACK_KEY<sup>10+</sup>    | ohos.extra.param.key.supportContinuePageStack  | Whether to migrate page stack information during cross-device migration. The default value is **true**, indicating that page stack information is automatically migrated.|
| SUPPORT_CONTINUE_SOURCE_EXIT_KEY<sup>10+</sup>  | ohos.extra.param.key.supportContinueSourceExit      | Whether to exit the application on the source device during cross-device migration. The default value is **true**, indicating that the application on the source device automatically exits.|
| SHOW_MODE_KEY<sup>12+</sup>  | ohos.extra.param.key.showMode      | Show mode. For details, see **wantConstant.ShowMode**.|

## wantConstant.Flags

 Enumerates the flags that specify how the Want will be handled.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write data to the URI.                                 |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION<sup>12+</sup> | 0x00000040 | Indicates that the URI can be persisted by the recipient.|
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.                             |
| FLAG_START_WITHOUT_TIPS<sup>11+</sup>              | 0x40000000 | Indicates that no tips are displayed if the ability implicitly started does not match any application.      |
## wantConstant.ShowMode<sup>12+</sup>

Enumerates the modes used to show the ability startup.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                               | Value| Description          |
| ----------------------------------- |---|--------------|
| WINDOW        | 0 | An independent window is used to show the ability startup. |
| EMBEDDED_FULL       | 1 | An embedded full-screen is used to show the ability startup.|
