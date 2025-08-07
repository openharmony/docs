# @ohos.app.form.LiveFormExtensionAbility  (LiveFormExtensionAbility)

LiveFormExtensionAbility模块提供互动卡片功能，包括创建、销毁互动卡片等，继承自[ExtensionAbility](../apis-ability-kit/js-apis-app-ability-extensionAbility.md)。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块设置了不允许调用的API名单，调用名单中的API将导致功能异常，详情请参见[附录](js-apis-app-form-LiveFormExtensionAbility.md#附录)。

## 导入模块

```ts
import { LiveFormExtensionAbility } from '@kit.FormKit';
```
## LiveFormExtensionAbility
互动卡片扩展类。包含互动卡片提供方接收创建和销毁互动卡片的通知接口。

### 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

| 名称 | 类型    | 只读 | 可选  |说明|
| ------ | ------ | ---- | ---- | ---- |
| context |  [LiveFormExtensionContext](./js-apis-application-LiveFormExtensionContext.md) | 否   | 否 |LiveFormExtensionAbility的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。|

### onLiveFormCreate

onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession): void

LiveFormExtensionAbility界面内容对象创建后调用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| liveFormInfo | [LiveFormInfo](#liveforminfo) | 是 | 互动卡片信息，包括卡片id等信息。|
| session      | [UIExtensionContentSession](../apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md) | 是 | LiveFormExtensionAbility界面内容相关信息。 |

**示例：**

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

LiveFormExtensionAbility生命周期回调，在销毁时回调，执行资源清理等操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| liveFormInfo | [LiveFormInfo](#liveforminfo) | 是 | 互动卡片信息，包括卡片id等信息。|

**示例：**

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

互动卡片信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ------ | ---- | ---- | -------- |
| formId | string | 否 | 否 | 卡片id。 |
| rect | [formInfo.Rect](js-apis-app-form-formInfo.md#rect20) | 否 | 否 | 卡片位置和大小信息。 |
| borderRadius | number | 否 | 否 | 卡片圆角半径信息。取值大于0，单位vp。 |

## 附录

本模块不允许调用的API名单如下。

| Kit名称 | 模块名称 |
| ------- | ------- |
| AbilityKit | [@ohos.ability.featureAbility (FeatureAbility模块)](../apis-ability-kit/js-apis-ability-featureAbility.md)<br>[@ohos.ability.particleAbility (ParticleAbility模块)](../apis-ability-kit/js-apis-ability-particleAbility.md)<br>[@ohos.bundle.launcherBundleManager (launcherBundleManager模块)](../apis-ability-kit/js-apis-launcherBundleManager.md)<br>[@ohos.continuation.continuationManager (continuationManager)](../apis-ability-kit/js-apis-continuation-continuationManager.md)<br><!--Del-->[@ohos.app.ability.quickFixManager (quickFixManager)(系统接口)](../apis-ability-kit/js-apis-app-ability-quickFixManager-sys.md)<br>[@ohos.bundle.bundleMonitor (bundleMonitor模块)(系统接口)](../apis-ability-kit/js-apis-bundleMonitor-sys.md)<br>[@ohos.bundle.distributedBundleManager (distributedBundleManager模块)(系统接口)](../apis-ability-kit/js-apis-distributedBundleManager-sys.md)<br>[@ohos.bundle.freeInstall (freeInstall模块)(系统接口)](../apis-ability-kit/js-apis-freeInstall-sys.md)<br>[@ohos.bundle.innerBundleManager (innerBundleManager模块)(系统接口)](../apis-ability-kit/js-apis-Bundle-InnerBundleManager-sys.md)<br>[@ohos.bundle.installer (installer模块)(系统接口)](../apis-ability-kit/js-apis-installer-sys.md)<br>[@ohos.distributedBundle (分布式包管理)(系统接口)](../apis-ability-kit/js-apis-Bundle-distributedBundle-sys.md)<br>[@ohos.distributedMissionManager (分布式任务管理)(系统接口)](../apis-ability-kit/js-apis-distributedMissionManager-sys.md)<br>[@ohos.privacyManager (隐私管理)(系统接口)](../apis-ability-kit/js-apis-privacyManager-sys.md)<!--DelEnd--> |
| BasicServicesKit | [@ohos.account.appAccount (应用账号管理)](../apis-basic-services-kit/js-apis-appAccount.md)<br>[@ohos.account.distributedAccount (分布式账号管理)](../apis-basic-services-kit/js-apis-distributed-account.md)<br>[@ohos.account.osAccount (系统账号管理)](../apis-basic-services-kit/js-apis-osAccount.md)<br>[@ohos.pasteboard (剪贴板)](../apis-basic-services-kit/js-apis-pasteboard.md)<br>[@ohos.request (上传下载)](../apis-basic-services-kit/js-apis-request.md)<br>[@ohos.wallpaper (壁纸)](../apis-basic-services-kit/js-apis-wallpaper.md)<!--Del--><br>[@ohos.update (升级)(系统接口)](../apis-basic-services-kit/js-apis-update-sys.md)<!--DelEnd--> |
| BackgroundTasksKit | [@ohos.backgroundTaskManager (后台任务管理)](../apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)<br>[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)<br>[@ohos.reminderAgent (后台代理提醒)](../apis-backgroundtasks-kit/js-apis-reminderAgent.md)<br>[@ohos.reminderAgentManager (后台代理提醒)](../apis-backgroundtasks-kit/js-apis-reminderAgentManager.md)<!--Del--><br>[@ohos.resourceschedule.usageStatistics (设备使用信息统计)(系统接口)](../apis-backgroundtasks-kit/js-apis-resourceschedule-deviceUsageStatistics-sys.md)<!--DelEnd--> |
| CalendarKit | [@ohos.calendarManager (日程管理能力)](../apis-calendar-kit/js-apis-calendarManager.md) |
| ConnectivityKit | [@ohos.connectedTag (有源标签)](../apis-connectivity-kit/js-apis-connectedTag.md)<br>[@ohos.nfc.cardEmulation (标准NFC-cardEmulation)](../apis-connectivity-kit/js-apis-cardEmulation.md)<br>[@ohos.nfc.controller (标准NFC)](../apis-connectivity-kit/js-apis-nfcController.md)<br>[@ohos.nfc.tag (标准NFC-Tag)](../apis-connectivity-kit/js-apis-nfcTag.md)<br>[nfctech (标准NFC-Tag Nfc 技术)](../apis-connectivity-kit/js-apis-nfctech.md)<br>[tagSession (标准NFC-Tag TagSession)](../apis-connectivity-kit/js-apis-tagSession.md) |
| ContactsKit | [@ohos.contact (联系人)](../apis-contacts-kit/js-apis-contact.md) |
| ArkData | [@ohos.data.distributedData (分布式数据管理)](../apis-arkdata/js-apis-distributed-data.md)<br>[@ohos.data.distributedDataObject (分布式数据对象)](../apis-arkdata/js-apis-data-distributedobject.md)<br>[@ohos.data.distributedKVStore (分布式键值数据库)](../apis-arkdata/js-apis-distributedKVStore.md) |
| MDMKit | [@ohos.enterprise.adminManager (admin权限管理)](../apis-mdm-kit/js-apis-enterprise-adminManager.md)<br>[@ohos.enterprise.deviceInfo（设备信息管理）](../apis-mdm-kit/js-apis-enterprise-deviceInfo.md)<!--Del--><br>[@ohos.enterprise.dateTimeManager （系统时间管理）(系统接口)](../apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md)<!--DelEnd--> |
| CoreFileKit | [@ohos.file.picker (选择器)](../apis-core-file-kit/js-apis-file-picker.md)<!--Del--><br>[@ohos.filemanagement.userFileManager (用户数据管理)(系统接口)](../apis-core-file-kit/js-apis-userFileManager-sys.md)<!--DelEnd--> |
| MediaLibraryKit | [@ohos.file.sendablePhotoAccessHelper (基于Sendable对象的相册管理模块)](../apis-media-library-kit/js-apis-sendablePhotoAccessHelper.md)<br>[@ohos.file.AlbumPickerComponent (Album Picker组件)](../apis-media-library-kit/ohos-file-AlbumPickerComponent.md)<br>[@ohos.file.PhotoPickerComponent (PhotoPicker组件)](../apis-media-library-kit/ohos-file-PhotoPickerComponent.md)<br>[@ohos.file.RecentPhotoComponent (最近图片组件)](../apis-media-library-kit/ohos-file-RecentPhotoComponent.md)<br>[@ohos.multimedia.movingphotoview (动态照片)](../apis-media-library-kit/ohos-multimedia-movingphotoview.md) |
| PerformanceAnalysisKit | [@ohos.hidebug (Debug调试)](../apis-performance-analysis-kit/js-apis-hidebug.md) |
| AudioKit | [@ohos.multimedia.audio (音频管理)](../apis-audio-kit/arkts-apis-audio.md) |
| CameraKit | [@ohos.multimedia.cameraPicker (相机选择器)](../apis-camera-kit/js-apis-cameraPicker.md)<br>[@ohos.multimedia.camera (相机管理)](../apis-camera-kit/arkts-apis-camera.md) |
| AVSessionKit | [@ohos.multimedia.avCastPicker (投播组件)](../apis-avsession-kit/ohos-multimedia-avcastpicker.md)<br>[@ohos.multimedia.avsession (媒体会话管理)](../apis-avsession-kit/arkts-apis-avsession.md) |
| MediaKit | [@ohos.multimedia.media (媒体服务)](../apis-media-kit/arkts-apis-media.md) |
| NotificationKit | [@ohos.notification (Notification模块)](../apis-notification-kit/js-apis-notification.md)<br>[@ohos.notificationManager (NotificationManager模块)](../apis-notification-kit/js-apis-notificationManager.md)<!--Del--><br>[@ohos.notificationSubscribe (NotificationSubscribe模块)(系统接口)](../apis-notification-kit/js-apis-notificationSubscribe-sys.md)<!--DelEnd--> |
| TelephonyKit | [@ohos.telephony.call (拨打电话)](../apis-telephony-kit/js-apis-call.md)<br>[@ohos.telephony.data (蜂窝数据)](../apis-telephony-kit/js-apis-telephony-data.md)<br>[@ohos.telephony.observer (observer)](../apis-telephony-kit/js-apis-observer.md)<br>[@ohos.telephony.radio (网络搜索)](../apis-telephony-kit/js-apis-radio.md)<br>[@ohos.telephony.sim (SIM卡管理)](../apis-telephony-kit/js-apis-sim.md)<br>[@ohos.telephony.sms (短信服务)](../apis-telephony-kit/js-apis-sms.md) |
| UserAuthenticationKit | [@ohos.userIAM.userAuth (用户认证)](../apis-user-authentication-kit/js-apis-useriam-userauth.md)<!--Del--><br>[@ohos.userIAM.faceAuth (人脸认证)(系统接口)](../apis-user-authentication-kit/js-apis-useriam-faceauth-sys.md)<!--DelEnd--> |
| ArkUI | [@ohos.window (窗口)](../apis-arkui/arkts-apis-window.md) |
|<!--DelRow--> AccessibilityKit | [@ohos.accessibility.config (系统辅助功能配置)(系统接口)](../apis-accessibility-kit/js-apis-accessibility-config-sys.md) |
|<!--DelRow--> FormKit | [@ohos.app.form.formHost (formHost)(系统接口)](../apis-form-kit/js-apis-app-form-formHost-sys.md)<br>[@ohos.application.formHost (formHost)(系统接口)](../apis-form-kit/js-apis-application-formHost-sys.md) |
<!--RP1--><!--RP1End-->