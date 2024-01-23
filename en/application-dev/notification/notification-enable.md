# Requesting Notification Authorization


Your application can send notifications only after obtaining user authorization. You can call the [requestEnableNotification()](../reference/apis/js-apis-notificationManager.md#notificationmanagerrequestenablenotification) API to display a dialog box prompting the user to enable notification for your application. The dialog box is displayed only when the API is called for the first time.

  **Figure 1** Dialog box prompting the user to enable notification 
![en-us_image_0000001416585590](figures/en-us_image_0000001416585590.png)

- Touching **allow** enables notification for the application.

- Touching **ban** keeps notification disabled. In this case, since another call to [requestEnableNotification()](../reference/apis/js-apis-notificationManager.md#notificationmanagerrequestenablenotification) will not display the dialog box again, the user will need to perform the following to manually enable notification.
  
  | 1. Swipe down from the upper left corner of the screen and touch the Settings icon in the upper right corner.                             | 2. Access the notification screen and find the target application.| 3. Toggle on **Allow notifications**.                                         |
  | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | ![en-us_image_0000001417062434](figures/en-us_image_0000001417062434.png) | ![en-us_image_0000001466462297](figures/en-us_image_0000001466462297.png) | ![en-us_image_0000001466782025](figures/en-us_image_0000001466782025.png) |


## Available APIs

For details about the APIs, see [@ohos.notificationManager (NotificationManager)](../reference/apis/js-apis-notificationManager.md#notificationrequestenablenotification).

**Table 1** Notification authorization APIs

| Name | Description |
| -------- | -------- |
| isNotificationEnabled():Promise\<boolean\>       | Checks whether notification is enabled. |
| requestEnableNotification(callback: AsyncCallback&lt;void&gt;): void | Requests notification to be enabled. When called for the first time, this API displays a dialog box prompting the user to enable notification.    |


## How to Develop

1. Import the **NotificationManager** module.

    ```ts
    import notificationManager from '@ohos.notificationManager';
    import Base from '@ohos.base';
    ```

2. Request notification to be enabled.

    ```ts
    notificationManager.isNotificationEnabled().then((data: boolean) => {
      console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
      if(!data){
        notificationManager.requestEnableNotification().then(() => {
          console.info(`[ANS] requestEnableNotification success`);
        }).catch((err:Base.BusinessError) => {
          console.error(`[ANS] requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
        });
      }
    }).catch((err: Base.BusinessError) => {
      console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);
    });
    ```
