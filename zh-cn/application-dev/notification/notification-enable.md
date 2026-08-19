# 请求通知授权
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

应用需要获取用户授权才能发送通知。在通知发布前调用[requestEnableNotification()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10-1)接口，弹窗让用户选择是否允许发送通知。当用户拒绝授权后，将无法通过该接口再次拉起弹窗。如果应用需要向用户再次申请[通知授权](notification-glossary.md#notification-authorization通知授权)，则可以使用[openNotificationSettingsWithResult](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanageropennotificationsettingswithresult)接口拉起通知管理半模态弹窗。

## 接口说明

接口详情参见[@ohos.notificationManager (NotificationManager模块)](../reference/apis-notification-kit/js-apis-notificationManager.md)。

**表1** [通知授权](notification-glossary.md#notification-authorization通知授权)接口功能介绍

| **接口名**  | **描述** |
| -------- | -------- |
| isNotificationEnabled():Promise\<boolean\>       | 查询通知是否授权。  |
| requestEnableNotification(context: UIAbilityContext): Promise\<void\> | 请求发送通知的许可，第一次调用会弹窗让用户选择。     |
| openNotificationSettingsWithResult(context: UIAbilityContext): Promise\<NotificationSetting\>  | 拉起通知管理弹窗，用户设置完成后返回设置结果。|


## 开发步骤

1. 导入NotificationManager模块。

   <!-- @[request_enable_notification_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/RequestEnableNotification.ets) -->
   
   ``` TypeScript
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { common } from '@kit.AbilityKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. 拉起通知弹窗，向用户请求[通知授权](notification-glossary.md#notification-authorization通知授权)。

   可通过requestEnableNotification的错误码判断用户是否授权。若返回的错误码为1600004，即为拒绝授权。

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

3. （可选）拉起通知管理半模态弹窗，向用户再次申请通知授权。

   用户授权完成后会返回设置结果，其中包含通知授权开关以及锁屏、横幅、角标、铃声、振动的开关设置结果。

   <!-- @[reapply_notify_auth_halfModal](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/RequestEnableNotification.ets) -->    
   
   ``` TypeScript
   let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
   notificationManager.isNotificationEnabled().then((data: boolean) => {
     hilog.info(DOMAIN_NUMBER, TAG, `isNotificationEnabled success, data:  ${data}`);
     if (!data) {
       notificationManager.openNotificationSettingsWithResult(context)
       .then((result: notificationManager.NotificationSetting) => {
         // result为当前设置的结果
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



