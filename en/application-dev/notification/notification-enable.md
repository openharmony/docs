# Requesting Notification Authorization

Your application can send notifications only after obtaining user authorization. Call the [requestEnableNotification()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification) API before a notification is published. A dialog box is displayed for the user to determine whether to allow notification sending. When this API is called again, no dialog box is displayed.
  
## Available APIs

For details about the APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationrequestenablenotification).

**Table 1** Notification authorization APIs

| **API** | **Description**|
| -------- | -------- |
| isNotificationEnabled():Promise\<boolean\>       | Checks whether notification is enabled. |
| requestEnableNotification(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Requests notification to be enabled. When called for the first time, this API displays a dialog box prompting the user to select.    |


## How to Develop

1. Import the **NotificationManager** module.

    ```ts
    import notificationManager from '@ohos.notificationManager';
    import Base from '@ohos.base';
    ```

2. Request notification to be enabled.

    You can determine whether the user has authorized the request based on the error code of **requestEnableNotification**. If the error code **1600004** is returned, the authorization is rejected.

    ```ts
    notificationManager.isNotificationEnabled().then((data: boolean) => {
      console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
      if(!data){
        notificationManager.requestEnableNotification().then(() => {
          console.info(`[ANS] requestEnableNotification success`);
        }).catch((err : Base.BusinessError) => {
          if(1600004 == err.code){
            console.info(`[ANS] requestEnableNotification refused`);
          } else {
            console.error(`[ANS] requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
          }
        });
      }
    }).catch((err : Base.BusinessError) => {
        console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);
    });
    ```
