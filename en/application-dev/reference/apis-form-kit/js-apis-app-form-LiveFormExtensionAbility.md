# @ohos.app.form.LiveFormExtensionAbility  (LiveFormExtensionAbility)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--Designer: @xueyulong-->
<!--Tester: @chenmingze-->
<!--Adviser: @Brilliantry_Rui-->

The **LiveFormExtensionAbility** module, inherited from [ExtensionAbility](../apis-ability-kit/js-apis-app-ability-extensionAbility.md), provides interactive widget functions, including creating and destroying interactive widgets.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> Exceptions may occur if some APIs are called. For details about the API list, see [Appendix](js-apis-app-form-LiveFormExtensionAbility.md#appendix).

## Modules to Import

```ts
import { LiveFormExtensionAbility } from '@kit.FormKit';
```
## LiveFormExtensionAbility
Interactive widget extension class. It provides APIs for the widget provider to receive notifications about widget creation and destruction.

### Properties

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name| Type   | Read-Only| Optional |Description|
| ------ | ------ | ---- | ---- | ---- |
| context |  [LiveFormExtensionContext](./js-apis-application-LiveFormExtensionContext.md) | No  | No|Context of the **LiveFormExtensionAbility**. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).|

### onLiveFormCreate

onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession): void

Called after the UI content of **LiveFormExtensionAbility** is created.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| liveFormInfo | [LiveFormInfo](#liveforminfo) | Yes| Interactive widget information, including the widget ID.|
| session      | [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md) | Yes| UI information.|

**Example**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
import { LiveFormExtensionAbility, LiveFormInfo } from '@kit.FormKit';

const TAG: string = '[testTag] LiveFormExtAbility';

export default class LiveFormExtAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession) {
    console.info(TAG, `onLiveFormCreate, liveFormInfo: ${JSON.stringify(liveFormInfo)}`);
  }
}
```

### onLiveFormDestroy

onLiveFormDestroy(liveFormInfo: LiveFormInfo): void

Called to clear resources when this **LiveFormExtensionAbility** is destroyed.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| liveFormInfo | [LiveFormInfo](#liveforminfo) | Yes| Interactive widget information, including the widget ID.|

**Example**

```ts
import { LiveFormExtensionAbility, LiveFormInfo } from '@kit.FormKit';

const TAG: string = '[testTag] LiveFormExtAbility';

export default class LiveFormExtAbility extends LiveFormExtensionAbility {
  onLiveFormDestroy(liveFormInfo: LiveFormInfo) {
    console.info(TAG, `onLiveFormDestroy, liveFormInfo: ${JSON.stringify(liveFormInfo)}`);
  }
}
```
### LiveFormInfo

Defines the interactive widget information.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.Form

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name| Type| Read-Only| Optional| Description|
| ------ | ------ | ---- | ---- | -------- |
| formId | string | No| No| Widget ID.|
| rect | [formInfo.Rect](js-apis-app-form-formInfo.md#rect20) | No| No| Widget location and dimension.|
| borderRadius | number | No| No| Widget corner radius. The value must be greater than 0, in vp.|

## Appendix

The following table lists the APIs that cannot be called by this module.

| Kit| Module|
| ------- | ------- |
| AbilityKit | [@ohos.ability.featureAbility (FeatureAbility)](../apis-ability-kit/js-apis-ability-featureAbility.md)<br>[@ohos.ability.particleAbility (ParticleAbility)](../apis-ability-kit/js-apis-ability-particleAbility.md)<br>[@ohos.bundle.launcherBundleManager (launcherBundleManager)](../apis-ability-kit/js-apis-launcherBundleManager.md)<br>[@ohos.continuation.continuationManager (Continuation/Collaboration Management)](../apis-ability-kit/js-apis-continuation-continuationManager.md)<br><!--Del-->[@ohos.app.ability.quickFixManager (quickFixManager) (System API)](../apis-ability-kit/js-apis-app-ability-quickFixManager-sys.md)<br>[@ohos.bundle.bundleMonitor (bundleMonitor) (System API)](../apis-ability-kit/js-apis-bundleMonitor-sys.md)<br>[@ohos.bundle.distributedBundleManager (distributedBundleManager) (System API)](../apis-ability-kit/js-apis-distributedBundleManager-sys.md)<br>[@ohos.bundle.freeInstall (freeInstall) (System API)](../apis-ability-kit/js-apis-freeInstall-sys.md)<br>[@ohos.bundle.innerBundleManager (innerBundleManager) (System API)](../apis-ability-kit/js-apis-Bundle-InnerBundleManager-sys.md)<br>[@ohos.bundle.installer (installer) (System API)](../apis-ability-kit/js-apis-installer-sys.md)<br>[@ohos.distributedBundle (Distributed Bundle Management) (System API)](../apis-ability-kit/js-apis-Bundle-distributedBundle-sys.md)<br>[@ohos.distributedMissionManager (Distributed Mission Management) (System API)](../apis-ability-kit/js-apis-distributedMissionManager-sys.md)<br>[@ohos.privacyManager (Privacy Management) (System API)](../apis-ability-kit/js-apis-privacyManager-sys.md)<!--DelEnd--> |
| BasicServicesKit | [@ohos.account.appAccount (App Account Management)](../apis-basic-services-kit/js-apis-appAccount.md)<br>[@ohos.account.distributedAccount (Distributed Account Management)](../apis-basic-services-kit/js-apis-distributed-account.md)<br>[@ohos.account.osAccount (System Account Management)](../apis-basic-services-kit/js-apis-osAccount.md)<br>[@ohos.pasteboard (Pasteboard)](../apis-basic-services-kit/js-apis-pasteboard.md)<br>[@ohos.request (Upload and Download)](../apis-basic-services-kit/js-apis-request.md)<br>[@ohos.wallpaper (Wallpaper)](../apis-basic-services-kit/js-apis-wallpaper.md)<!--Del--><br>[@ohos.update (Update) (System API)](../apis-basic-services-kit/js-apis-update-sys.md)<!--DelEnd--> |
| BackgroundTasksKit | [@ohos.backgroundTaskManager (Background Task Management)](../apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)<br>[@ohos.resourceschedule.backgroundTaskManager (Background Task Management)](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)<br>[@ohos.reminderAgent (reminderAgent)](../apis-backgroundtasks-kit/js-apis-reminderAgent.md)<br>[@ohos.reminderAgentManager (Agent-Powered Reminders)](../apis-backgroundtasks-kit/js-apis-reminderAgentManager.md)<!--Del--><br>[@ohos.resourceschedule.usageStatistics (Device Usage Statistics) (System API)](../apis-backgroundtasks-kit/js-apis-resourceschedule-deviceUsageStatistics-sys.md)<!--DelEnd--> |
| CalendarKit | [@ohos.calendarManager (Calendar Manager)](../apis-calendar-kit/js-apis-calendarManager.md)|
| ConnectivityKit | [@ohos.connectedTag (Active Tags)](../apis-connectivity-kit/js-apis-connectedTag.md)<br>[@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](../apis-connectivity-kit/js-apis-cardEmulation.md)<br>[@ohos.nfc.controller (Standard NFC)](../apis-connectivity-kit/js-apis-nfcController.md)<br>[@ohos.nfc.tag (Standard NFC Tags)](../apis-connectivity-kit/js-apis-nfcTag.md)<br>[nfctech (Standard NFC Technologies)](../apis-connectivity-kit/js-apis-nfctech.md)<br>[tagSession (Standard NFC Tag Session)](../apis-connectivity-kit/js-apis-tagSession.md)|
| ContactsKit | [@ohos.contact (Contacts)](../apis-contacts-kit/js-apis-contact.md)|
| ArkData | [@ohos.data.distributedData (Distributed Data Management)](../apis-arkdata/js-apis-distributed-data.md)<br>[@ohos.data.distributedDataObject (Distributed Data Object)](../apis-arkdata/js-apis-data-distributedobject.md)<br>[@ohos.data.distributedKVStore (Distributed KV Store)](../apis-arkdata/js-apis-distributedKVStore.md)|
| MDMKit | [@ohos.enterprise.adminManager (Administrator Permission Management)](../apis-mdm-kit/js-apis-enterprise-adminManager.md)<br>[@ohos.enterprise.deviceInfo (Device Information Management)](../apis-mdm-kit/js-apis-enterprise-deviceInfo.md)<!--Del--><br>[@ohos.enterprise.dateTimeManager (System Time Management) (System API)](../apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md)<!--DelEnd--> |
| CoreFileKit | [@ohos.file.picker (Picker)](../apis-core-file-kit/js-apis-file-picker.md)<!--Del--><br>[@ohos.filemanagement.userFileManager (User Data Management) (System API)](../apis-core-file-kit/js-apis-userFileManager-sys.md)<!--DelEnd--> |
| MediaLibraryKit | [@ohos.file.sendablePhotoAccessHelper (Album Management Based on a Sendable Object)](../apis-media-library-kit/js-apis-sendablePhotoAccessHelper.md)<br>[@ohos.file.AlbumPickerComponent (AlbumPickerComponent)](../apis-media-library-kit/ohos-file-AlbumPickerComponent.md)<br>[@ohos.file.PhotoPickerComponent (PhotoPicker Component)](../apis-media-library-kit/ohos-file-PhotoPickerComponent.md)<br>[@ohos.file.RecentPhotoComponent (RecentPhotoComponent)](../apis-media-library-kit/ohos-file-RecentPhotoComponent.md)<br>[@ohos.multimedia.movingphotoview (MovingPhotoView)](../apis-media-library-kit/ohos-multimedia-movingphotoview.md)|
| PerformanceAnalysisKit | [@ohos.hidebug (HiDebug)](../apis-performance-analysis-kit/js-apis-hidebug.md)|
| AudioKit | [@ohos.multimedia.audio (Audio Management)](../apis-audio-kit/arkts-apis-audio.md)|
| CameraKit | [@ohos.multimedia.cameraPicker (Camera Picker)](../apis-camera-kit/js-apis-cameraPicker.md)<br>[@ohos.multimedia.camera (Camera Management)](../apis-camera-kit/arkts-apis-camera.md)|
| AVSessionKit | [@ohos.multimedia.avCastPicker (AVCastPicker)](../apis-avsession-kit/ohos-multimedia-avcastpicker.md)<br>[@ohos.multimedia.avsession (AVSession Management)](../apis-avsession-kit/arkts-apis-avsession.md)|
| MediaKit | [@ohos.multimedia.media (Media)](../apis-media-kit/arkts-apis-media.md)|
| NotificationKit | [@ohos.notification (Notification)](../apis-notification-kit/js-apis-notification.md)<br>[@ohos.notificationManager (NotificationManager)](../apis-notification-kit/js-apis-notificationManager.md)<!--Del--><br>[@ohos.notificationSubscribe (NotificationSubscribe) (System API)](../apis-notification-kit/js-apis-notificationSubscribe-sys.md)<!--DelEnd--> |
| TelephonyKit | [@ohos.telephony.call (Call)](../apis-telephony-kit/js-apis-call.md)<br>[@ohos.telephony.data (Cellular Data)](../apis-telephony-kit/js-apis-telephony-data.md)<br>[@ohos.telephony.observer (observer)](../apis-telephony-kit/js-apis-observer.md)<br>[@ohos.telephony.radio (Network Search)](../apis-telephony-kit/js-apis-radio.md)<br>[@ohos.telephony.sim (SIM Management)](../apis-telephony-kit/js-apis-sim.md)<br>[@ohos.telephony.sms (SMS)](../apis-telephony-kit/js-apis-sms.md)|
| UserAuthenticationKit | [@ohos.userIAM.userAuth (User Authentication)](../apis-user-authentication-kit/js-apis-useriam-userauth.md)<!--Del--><br>[@ohos.userIAM.faceAuth (Facial Authentication) (System API)](../apis-user-authentication-kit/js-apis-useriam-faceauth-sys.md)<!--DelEnd--> |
| ArkUI | [@ohos.window (Window)](../apis-arkui/arkts-apis-window.md)|
|<!--DelRow--> AccessibilityKit | [@ohos.accessibility.config (System Accessibility Configuration) (System API)](../apis-accessibility-kit/js-apis-accessibility-config-sys.md)|
|<!--DelRow--> FormKit | [@ohos.app.form.formHost (formHost) (System API)](../apis-form-kit/js-apis-app-form-formHost-sys.md)<br>[@ohos.application.formHost (formHost) (System API)](../apis-form-kit/js-apis-application-formHost-sys.md)|
<!--RP1--><!--RP1End-->
