# wantConstant

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import wantConstant from '@ohos.ability.wantConstant'
```

## wantConstant.Action

**System capability**: SystemCapability.Ability.AbilityBase

Lists the permissions.

| Common Event Macro     | Common Event Name         | Subscriber Permission    |
| ------------ | ------------------ | ---------------------- |
| ACTION_HOME                                 | ohos.want.action.home                    | None                                                          |
| ACTION_DIAL                                 | ohos.want.action.dial                    | None                                                          |
| ACTION_SEARCH                               | ohos.want.action.search                  | None                                                          |
| ACTION_WIRELESS_SETTINGS                    | ohos.settings.wireless                   | None                                                          |
| ACTION_MANAGE_APPLICATIONS_SETTINGS         | ohos.settings.manage.applications        | None                                                          |
| ACTION_APPLICATION_DETAILS_SETTINGS         | ohos.settings.application.details        | None                                                          |
| ACTION_SET_ALARM                            | ohos.want.action.setAlarm                | None                                                          |
| ACTION_SHOW_ALARMS                          | ohos.want.action.showAlarms              | None                                                          |
| ACTION_SNOOZE_ALARM                         | ohos.want.action.snoozeAlarm             | None                                                          |
| ACTION_DISMISS_ALARM                        | ohos.want.action.dismissAlarm            | None                                                          |
| ACTION_DISMISS_TIMER                        | ohos.want.action.dismissTimer            | None                                                          |
|  ACTION_SEND_SMS                            | ohos.want.action.sendSms                 | None                                                          |
| ACTION_CHOOSE                               | ohos.want.action.choose                  | None                                                          |
| ACTION_IMAGE_CAPTURE<sup>8+</sup>           | ohos.want.action.imageCapture            | None                                                          |
| ACTION_VIDEO_CAPTUR<sup>8+</sup>            | ohos.want.action.videoCapture            | None                                                          |
| ACTION_SELECT                               | ohos.want.action.select                  | None                                                          |
| ACTION_SEND_DATA                            | ohos.want.action.sendData                | None                                                          |
| ACTION_SEND_MULTIPLE_DATA                   | ohos.want.action.sendMultipleData        | None                                                          |
| ACTION_SCAN_MEDIA_FILE                      | ohos.want.action.scanMediaFile           | None                                                          |
| ACTION_VIEW_DATA                            | ohos.want.action.viewData                | None                                                          |
|  ACTION_EDIT_DATA                           | ohos.want.action.editData                | None                                                          |
|  INTENT_PARAMS_INTENT                       | ability.want.params.INTENT               | None                                                          |
|  INTENT_PARAMS_TITLE                        | ability.want.params.TITLE                | None                                                          |
|  ACTION_FILE_SELECT<sup>7+</sup>            | ohos.action.fileSelect                   | None                                                          |
|  PARAMS_STREAM<sup>7+</sup>                 | ability.params.stream                    | None                                                          |
|  ACTION_APP_ACCOUNT_OAUTH <sup>8+</sup>     | ohos.account.appAccount.action.oauth     | None                                                          |


## wantConstant.Entity

**System capability**: SystemCapability.Ability.AbilityBase

Lists the permissions.

| Common Event Macro     | Common Event Name         | Subscriber Permission    |
| ------------ | ------------------ | ---------------------- |
| ENTITY_DEFAULT                             | entity.system.default                    | None                                                          |
| ENTITY_HOME                                | entity.system.homel                      | None                                                          |
| ENTITY_VOICE                               | ENTITY_VOICE                             | None                                                          |
| ENTITY_BROWSABLE                           | entity.system.browsable                  | None                                                          |
| ENTITY_VIDEO                               | entity.system.video                      | None                                                          |
| ACTION_APPLICATION_DETAILS_SETTINGS        | ohos.settings.application.details        | None                                                          |


## flags

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write the URI.                                 |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.                                          |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Indicates whether the ability on the local device can be continued on a remote device.                  |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.                                        |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates that an ability is enabled.                                         |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Indicates the permission to make the URI persistent.                                    |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Indicates the permission to verify URIs by prefix matching.                                |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Supports cross-device startup in a distributed scheduler.                              |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the Service ability is started regardless of whether the host application has been started.        |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that ability continuation is reversible.                                            |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.                             |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.                             |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the **Want** object in the **startAbility** API passed to [ohos.app.Context](js-apis-ability-context.md) and must be used together with **flag_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Indicates the operation of creating a mission on the history mission stack.                              |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Starts the mission on the top of the existing mission stack; creates an ability instance if no mission exists.|
