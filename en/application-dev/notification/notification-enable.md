# Requesting Notification Authorization


Your application can send notifications only after obtaining user authorization. You can call the [requestEnableNotification()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification) API to display a dialog box prompting the user to enable notification for your application. The dialog box is displayed only when the API is called for the first time.

  

## Available APIs

For details about the APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10-1).

**Table 1** Notification authorization APIs

| Name | Description |
| -------- | -------- |
| isNotificationEnabled():Promise\<boolean\>       | Checks whether notification is enabled. |
| requestEnableNotification(context: UIAbilityContext): Promise\<void\> | Requests notification to be enabled. When called for the first time, this API displays a dialog box prompting the user to enable notification.    |


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

    ```ts
    let context = getContext(this) as common.UIAbilityContext;
    notificationManager.isNotificationEnabled().then((data: boolean) => {
      hilog.info(DOMAIN_NUMBER, TAG, "isNotificationEnabled success, data: " + JSON.stringify(data));
      if(!data){
        notificationManager.requestEnableNotification(context).then(() => {
          hilog.info(DOMAIN_NUMBER, TAG, `[ANS] requestEnableNotification success`);
        }).catch((err : BusinessError) => {
          if(1600004 == err.code){
            console.info(`[ANS] requestEnableNotification refused`);
          } else {
            console.error(`[ANS] requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
          }
        });
      }
    }).catch((err : BusinessError) => {
        hilog.error(DOMAIN_NUMBER, TAG, `isNotificationEnabled fail: ${JSON.stringify(err)}`);
    });
    ```
