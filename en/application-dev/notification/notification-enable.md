# Requesting Notification Authorization

Your application can send notifications only after obtaining user authorization. Call the [requestEnableNotification()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10-1) API before a notification is published. A dialog box is displayed for the user to determine whether to allow notification sending. When this API is called again, no dialog box is displayed.
  
## Available APIs

For details about the APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10-1).

**Table 1** Notification authorization APIs

| **API** | **Description**|
| -------- | -------- |
| isNotificationEnabled():Promise\<boolean\>       | Checks whether notification is enabled. |
| requestEnableNotification(context: UIAbilityContext): Promise\<void\> | Requests notification to be enabled. When called for the first time, this API displays a dialog box prompting the user to select.    |


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

2. Request notification to be enabled.

    You can determine whether the user has authorized the request based on the error code of **requestEnableNotification**. If the error code **1600004** is returned, the authorization is rejected.

    ```ts
    let context = getContext(this) as common.UIAbilityContext;
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
