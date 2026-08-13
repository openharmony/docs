# Requesting Notification Authorization

<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=87516eb2d53d74e50d8d0d5e2de34178ba62e0e2 translatedAt=2026-08-13T03:11:29.048Z pushedAt=2026-08-13T07:37:29.950Z -->

An app must obtain user authorization before it can send notifications. Before publishing a notification, call [requestEnableNotification()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10-1) to display a dialog box for the user to choose whether to allow notifications. After the user denies authorization, the dialog box cannot be displayed again through this API. If the app needs to request notification authorization from the user again, it can use [openNotificationSettingsWithResult](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanageropennotificationsettingswithresult) to display a half-modal dialog box for notification management.

## Available APIs

For details about the APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md).

**Table 1** Notification authorization APIs

| **API** | **Description**|
| -------- | -------- |
| isNotificationEnabled():Promise\<boolean\>       | Checks whether notification is enabled. |
| requestEnableNotification(context: UIAbilityContext): Promise\<void\> | Requests notification to be enabled. When called for the first time, this API displays a dialog box prompting the user to select.    |
| openNotificationSettingsWithResult(context: UIAbilityContext): Promise\<NotificationSetting\>  | Opens the notification management dialog and returns the setting result after the user completes the settings.|

## How to Develop

1. Import the **NotificationManager** module.

   <!-- @[request_enable_notification_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/RequestEnableNotification.ets) -->

   ``` TypeScript
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { common } from '@kit.AbilityKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Display a dialog box to request notification authorization from the user.

   You can determine whether the user has authorized the request based on the error code of **requestEnableNotification**. If the error code **1600004** is returned, the authorization is rejected.

   <!-- @[request_enable_notification_permission](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/RequestEnableNotification.ets) -->

   ``` TypeScript
   let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
   notificationManager.isNotificationEnabled().then((data: boolean) => {
     hilog.info(DOMAIN_NUMBER, TAG, `isNotificationEnabled success, data: ${data}` );
     if (!data) {
       notificationManager.requestEnableNotification(context).then(() => {
         hilog.info(DOMAIN_NUMBER, TAG, `[ANS] requestEnableNotification success`);
       }).catch((err: BusinessError) => {
         if (1600004 == err.code) {
           hilog.error(DOMAIN_NUMBER, TAG,
             `[ANS] requestEnableNotification refused, code is ${err.code}, message is ${err.message}`);
         } else {
           hilog.error(DOMAIN_NUMBER, TAG,
             `[ANS] requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
         }
       });
     }
   }).catch((err: BusinessError) => {
     hilog.error(DOMAIN_NUMBER, TAG,
       `isNotificationEnabled fail, code is ${err.code}, message is ${err.message}`);
   });
   ```

3. (Optional) Display a semi-modal dialog box to request notification authorization from the user again.

After the user completes authorization, the setting result is returned, which includes the notification authorization switch and the setting results of the lock screen, banner, badge, ringtone, and vibration switches.

   <!-- @[reapply_notify_auth_halfModal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/RequestEnableNotification.ets) -->    

   ``` TypeScript
   let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
   notificationManager.isNotificationEnabled().then((data: boolean) => {
     hilog.info(DOMAIN_NUMBER, TAG, `isNotificationEnabled success, data:  ${data}`);
     if (!data) {
       notificationManager.openNotificationSettingsWithResult(context)
       .then((result: notificationManager.NotificationSetting) => {
         // result indicates the current setting result.
         hilog.info(DOMAIN_NUMBER, TAG, `[ANS] openNotificationSettingsWithResult success, result: ${JSON.stringify(result)}`);
       }).catch((err: BusinessError) => {
         hilog.error(DOMAIN_NUMBER, TAG,
           `[ANS] openNotificationSettingsWithResult failed, code is ${err.code}, message is ${err.message}`);
       });
     }
   }).catch((err: BusinessError) => {
     hilog.error(DOMAIN_NUMBER, TAG,
       `isNotificationEnabled fail, code is ${err.code}, message is ${err.message}`);
   });
   ```