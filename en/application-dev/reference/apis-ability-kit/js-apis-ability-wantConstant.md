# @ohos.ability.wantConstant (wantConstant)

The **wantConstant** module provides the actions, entities, and flags used in **Want** objects.

> **NOTE**
> 
> The APIs of this module are supported since API version 6 and deprecated since API version 9. You are advised to use [@ohos.app.ability.wantConstant](js-apis-app-ability-wantConstant.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import wantConstant from '@ohos.ability.wantConstant';
```

## wantConstant.Action

Enumerates the action constants of the **Want** object. **action** specifies the operation to execute.

**System capability**: SystemCapability.Ability.AbilityBase

| Name     | Value         | Description    |
| ------------ | ------------------ | ---------------------- |
| ACTION_HOME                                 | ohos.want.action.home                    | Action of returning to the home page.                                       |
| ACTION_DIAL                                 | ohos.want.action.dial                    | Action of launching the numeric keypad.                          |
| ACTION_SEARCH                               | ohos.want.action.search                  | Action of launching the search function.                                |
| ACTION_WIRELESS_SETTINGS                    | ohos.settings.wireless                   | Action of launching the UI that provides wireless network settings, for example, Wi-Fi options.   |
| ACTION_MANAGE_APPLICATIONS_SETTINGS         | ohos.settings.manage.applications        | Action of launching the UI for managing installed applications.                 |
| ACTION_APPLICATION_DETAILS_SETTINGS         | ohos.settings.application.details        | Action of launching the UI that displays the details of an application.            |
| ACTION_SET_ALARM                            | ohos.want.action.setAlarm                | Action of launching the UI for setting the alarm clock.                         |
| ACTION_SHOW_ALARMS                          | ohos.want.action.showAlarms              | Action of launching the UI that displays all alarms.                    |
| ACTION_SNOOZE_ALARM                         | ohos.want.action.snoozeAlarm             | Action of launching the UI for snoozing an alarm.                      |
| ACTION_DISMISS_ALARM                        | ohos.want.action.dismissAlarm            | Action of launching the UI for deleting an alarm.                            |
| ACTION_DISMISS_TIMER                        | ohos.want.action.dismissTimer            | Action of launching the UI for dismissing a timer.                          |
|  ACTION_SEND_SMS                            | ohos.want.action.sendSms                 | Action of launching the UI for sending an SMS message.                             |
| ACTION_CHOOSE                               | ohos.want.action.choose                  | Action of launching the UI for opening a contact or picture.                     |
| ACTION_IMAGE_CAPTURE<sup>8+</sup>           | ohos.want.action.imageCapture            | Action of launching the UI for photographing.                                  |
| ACTION_VIDEO_CAPTURE<sup>8+</sup>           | ohos.want.action.videoCapture            | Action of launching the UI for shooting a video.                            |
| ACTION_SELECT                               | ohos.want.action.select                  | Action of launching the UI for application selection.                            |
| ACTION_SEND_DATA                            | ohos.want.action.sendData                | Action of launching the UI for sending a single data record.                                 |
| ACTION_SEND_MULTIPLE_DATA                   | ohos.want.action.sendMultipleData        | Action of launching the UI for sending multiple data records.                                 |
| ACTION_SCAN_MEDIA_FILE                      | ohos.want.action.scanMediaFile           | Action of requesting a media scanner to scan a file and add the file to the media library.         |
| ACTION_VIEW_DATA                            | ohos.want.action.viewData                | Action of viewing data.                                         |
|  ACTION_EDIT_DATA                           | ohos.want.action.editData                | Action of editing data.                                          |
|  INTENT_PARAMS_INTENT                       | ability.want.params.INTENT               | Action of displaying selection options with an action selector.                            |
|  INTENT_PARAMS_TITLE                        | ability.want.params.TITLE                | Title of the character sequence dialog box used with the action selector.               |
|  ACTION_FILE_SELECT<sup>7+</sup>            | ohos.action.fileSelect                   | Action of selecting a file.                                         |
|  PARAMS_STREAM<sup>7+</sup>                 | ability.params.stream                    | URI of the data stream associated with the target when the data is sent. The value must be an array of the string type. |
|  ACTION_APP_ACCOUNT_OAUTH <sup>8+</sup>     | ohos.account.appAccount.action.oauth     | Action of providing the OAuth service.                                    |


## wantConstant.Entity

Enumerates the entity constants of the **Want** object. **entity** specifies additional information of the target ability.

**System capability**: SystemCapability.Ability.AbilityBase

| Name     | Value         | Description    |
| ------------ | ------------------ | ---------------------- |
| ENTITY_DEFAULT                             | entity.system.default                    | Default entity. The default entity is used if no entity is specified.       |
| ENTITY_HOME                                | entity.system.home                       | Home screen entity.                                   |
| ENTITY_VOICE                               | entity.system.voice                      | Voice interaction entity.                                 |
| ENTITY_BROWSABLE                           | entity.system.browsable                  | Browser type entity.                                   |
| ENTITY_VIDEO                               | entity.system.video                      | Video type entity.                                     |


## wantConstant.Flags

 Enumerates the flags that specify how the Want will be handled.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Grants the permission to read the URI.                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Grants the permission to write data to the URI.                                 |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.                                          |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Indicates whether the ability on the local device can be continued on a remote device.                  |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.                                        |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates that an ability is enabled.                                         |
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Indicates the support for cross-device startup in the distributed scheduler.                              |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the ServiceAbility is started regardless of whether the host application has been started.        |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.                             |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.                             |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for **Want** passed in [startAbility](js-apis-ability-featureAbility.md#startability). It must be used together with **FLAG_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Creates a mission on the history mission stack.                              |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Reuses an ability instance if it is on the top of an existing mission stack; creates an ability instance otherwise.|
