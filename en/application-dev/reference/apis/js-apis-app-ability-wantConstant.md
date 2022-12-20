# @ohos.app.ability.wantConstant

The **wantConstant** module provides the actions, entities, and flags used in **Want** objects.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import wantConstant from '@ohos.app.ability.wantConstant';
```

## wantConstant.Action

Enumerates the action constants of the **Want** object.

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
| ACTION_IMAGE_CAPTURE           | ohos.want.action.imageCapture            | Action of launching the UI for photographing.                                  |
| ACTION_VIDEO_CAPTURE           | ohos.want.action.videoCapture            | Action of launching the UI for shooting a video.                            |
| ACTION_SELECT                               | ohos.want.action.select                  | Action of launching the UI for application selection.                            |
| ACTION_SEND_DATA                            | ohos.want.action.sendData                | Action of launching the UI for sending a single data record.                                 |
| ACTION_SEND_MULTIPLE_DATA                   | ohos.want.action.sendMultipleData        | Action of launching the UI for sending multiple data records.                                 |
| ACTION_SCAN_MEDIA_FILE                      | ohos.want.action.scanMediaFile           | Action of requesting a media scanner to scan a file and add the file to the media library.         |
| ACTION_VIEW_DATA                            | ohos.want.action.viewData                | Action of viewing data.                                         |
|  ACTION_EDIT_DATA                           | ohos.want.action.editData                | Action of editing data.                                          |
|  INTENT_PARAMS_INTENT                       | ability.want.params.INTENT               | Action of displaying selection options with an action selector.                            |
|  INTENT_PARAMS_TITLE                        | ability.want.params.TITLE                | Title of the character sequence dialog box used with the action selector.               |
|  ACTION_FILE_SELECT            | ohos.action.fileSelect                   | Action of selecting a file.                                         |
|  PARAMS_STREAM                 | ability.params.stream                    | URI of the data stream associated with the target when the data is sent.                         |                                     |
|  ACTION_APP_ACCOUNT_AUTH      | account.appAccount.action.auth     | Action of providing the authentication service.                                     |
|  ACTION_MARKET_DOWNLOAD    | ohos.want.action.marketDownload     | Action of downloading an application from the application market.<br>**System API**: This is a system API and cannot be called by third-party applications. |
|  ACTION_MARKET_CROWDTEST    | ohos.want.action.marketCrowdTest     | Action of crowdtesting an application from the application market.<br>**System API**: This is a system API and cannot be called by third-party applications. |
|   DLP_PARAMS_SANDBOX    |ohos.dlp.params.sandbox  | Action of obtaining the sandbox flag.<br>**System API**: This is a system API and cannot be called by third-party applications. |
|   DLP_PARAMS_BUNDLE_NAME    |ohos.dlp.params.bundleName  |Action of obtaining the DLP bundle name.<br>**System API**: This is a system API and cannot be called by third-party applications. |
|   DLP_PARAMS_MODULE_NAME    |ohos.dlp.params.moduleName      |Action of obtaining the DLP module name.<br>**System API**: This is a system API and cannot be called by third-party applications. |
|   DLP_PARAMS_ABILITY_NAME   |ohos.dlp.params.abilityName      |Action of obtaining the DLP ability name.<br>**System API**: This is a system API and cannot be called by third-party applications. |
|   DLP_PARAMS_INDEX    |ohos.dlp.params.index      |Action of obtaining the DLP index.<br>**System API**: This is a system API and cannot be called by third-party applications. |

## wantConstant.Entity

Enumerates the entity constants of the **Want** object.

**System capability**: SystemCapability.Ability.AbilityBase

| Name     | Value         | Description    |
| ------------ | ------------------ | ---------------------- |
| ENTITY_DEFAULT                             | entity.system.default                    | Default entity. The default entity is used if no entity is specified.       |
| ENTITY_HOME                                | entity.system.home                       | Home screen entity.                                   |
| ENTITY_VOICE                               | entity.system.voice                      | Voice interaction entity.                                 |
| ENTITY_BROWSABLE                           | entity.system.browsable                  | Browser type entity.                                   |
| ENTITY_VIDEO                               | entity.system.video                      | Video type entity.                                     |


## wantConstant.Flags

Describes flags.

**System capability**: SystemCapability.Ability.AbilityBase

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_READ_URI_PERMISSION        | 0x00000001 | Indicates the permission to read the URI.                                 |
| FLAG_AUTH_WRITE_URI_PERMISSION       | 0x00000002 | Indicates the permission to write data to the URI.                                 |
| FLAG_ABILITY_FORWARD_RESULT          | 0x00000004 | Returns the result to the ability.                                          |
| FLAG_ABILITY_CONTINUATION            | 0x00000008 | Indicates whether the ability on the local device can be continued on a remote device.                  |
| FLAG_NOT_OHOS_COMPONENT              | 0x00000010 | Indicates that a component does not belong to OHOS.                                        |
| FLAG_ABILITY_FORM_ENABLED            | 0x00000020 | Indicates that an ability is enabled.                                         |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Indicates the permission to make the URI persistent.<br>**System API**: This is a system API and cannot be called by third-party applications. |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Indicates the permission to verify URIs by prefix matching.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| FLAG_ABILITYSLICE_MULTI_DEVICE       | 0x00000100 | Supports cross-device startup in a distributed scheduler.                              |
| FLAG_START_FOREGROUND_ABILITY        | 0x00000200 | Indicates that the Service ability is started regardless of whether the host application has been started.        |
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that ability continuation is reversible.<br>**System API**: This is a system API and cannot be called by third-party applications.     |
| FLAG_INSTALL_ON_DEMAND               | 0x00000800 | Indicates that the specific ability will be installed if it has not been installed.                             |
| FLAG_INSTALL_WITH_BACKGROUND_MODE    | 0x80000000 | Indicates that the specific ability will be installed in the background if it has not been installed.                             |
| FLAG_ABILITY_CLEAR_MISSION           | 0x00008000 | Clears other operation missions. This flag can be set for the **Want** object in the **startAbility** API passed to [ohos.app.Context](js-apis-ability-context.md) and must be used together with **flag_ABILITY_NEW_MISSION**.|
| FLAG_ABILITY_NEW_MISSION             | 0x10000000 | Indicates the operation of creating a mission on the history mission stack.                              |
| FLAG_ABILITY_MISSION_TOP             | 0x20000000 | Starts the mission on the top of the existing mission stack; creates an ability instance if no mission exists.|
