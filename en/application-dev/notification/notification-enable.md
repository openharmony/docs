# Requesting Notification Authorization

Your application can send notifications only after obtaining user authorization. Before publishing a notification, the application should call the [requestEnableNotification()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10-1) API to display a dialog box for the user to determine whether to allow notification sending. If the user rejects the authorization, the dialog box cannot be displayed again. To request another notification authorization from the user, the application can call the [openNotificationSettings](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanageropennotificationsettings13) API to display the semi-modal dialog box for notification management.

## Available APIs

For details about the APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md).

**Table 1** Notification authorization APIs

| **API** | **Description**|
| -------- | -------- |
| isNotificationEnabled():Promise\<boolean\>       | Checks whether notification is enabled. |
| requestEnableNotification(context: UIAbilityContext): Promise\<void\> | Requests notification to be enabled. When called for the first time, this API displays a dialog box prompting the user to select.    |
| openNotificationSettings(context: UIAbilityContext): Promise\<void\>  | Opens a dialog box for notification management.|


## How to Develop

1. Import the **NotificationManager** module.

    ```ts
    import { notificationManager } from '@kit.NotificationKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { common } from '@kit.AbilityKit';

    const TAG: string = '[PublishOperation]';
    const DOMAIN_NUMBER: number = 0xFF00;
    ```

2. Display a dialog box to request notification authorization from the user.

    You can determine whether the user has authorized the request based on the error code of **requestEnableNotification**. If the error code **1600004** is returned, the authorization is rejected.

    ```ts
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    notificationManager.isNotificationEnabled().then((data: boolean) => {
      hilog.info(DOMAIN_NUMBER, TAG, "isNotificationEnabled success, data: " + JSON.stringify(data));
      if(!data){
        notificationManager.requestEnableNotification(context).then(() => {
          hilog.info(DOMAIN_NUMBER, TAG, `[ANS] requestEnableNotification success`);
        }).catch((err : BusinessError) => {
          if(1600004 == err.code){
            hilog.error(DOMAIN_NUMBER, TAG, `[ANS] requestEnableNotification refused, code is ${err.code}, message is ${err.message}`);
          } else {
            hilog.error(DOMAIN_NUMBER, TAG, `[ANS] requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
          }
        });
      }
    }).catch((err : BusinessError) => {
        hilog.error(DOMAIN_NUMBER, TAG, `isNotificationEnabled fail, code is ${err.code}, message is ${err.message}`);
    });
    ```

3. (Optional) Display a semi-modal dialog box to request notification authorization from the user again.

    ```ts
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    notificationManager.isNotificationEnabled().then((data: boolean) => {
      hilog.info(DOMAIN_NUMBER, TAG, "isNotificationEnabled success, data: " + JSON.stringify(data));
      if(!data){
          notificationManager.openNotificationSettings(context).then(() => {
            hilog.info(0x0000, 'testTag', `[ANS] openNotificationSettings success`);
          }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', `[ANS] openNotificationSettings failed, code is ${err.code}, message is ${err.message}`);
          });
      }
    })
    ```
