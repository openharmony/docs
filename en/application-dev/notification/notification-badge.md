# Managing the Notification Badge

The system provides APIs for setting the notification badge, which is displayed in the upper right corner of the application icon on the home screen to notify the user of the count of unread notifications.

When a new notification arrives, the count on the badge is incremented by 1.

After a notification is read, the count on the badge is decremented by 1. If there is no unread notification, the badge is not displayed.


## Available APIs

If **badgeNumber** is set to **0**, badges are cleared; if the value is greater than **99**, **99+** is displayed on the badge.

- You can use either of the following methods to increase the count on the badge:

   - When publishing a notification, pass the **badgeNumber** parameter in [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest). After the notification is received, the count on the badge is incremented.

   - Call the [setBadgeNumber()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagersetbadgenumber10) API to set the count on the badge.

- To decrease the count on the badge, call the [setBadgeNumber()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagersetbadgenumber10) API.

  | **API**| **Description**|
  | -------- | -------- |
  | setBadgeNumber(badgeNumber: number, callback: AsyncCallback\<void\>): void | Sets the number count on the badge.|


## How to Develop

1. Import the **NotificationManager** module.

   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. Increase the count on the badge.

   When publishing a notification, pass the **badgeNumber** parameter in [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest). For details, see [Publishing a Basic Notification](text-notification.md).
   
   In this example, the **setBadgeNumber** API is called to add a badge. This API is called after a new notification is published.
   
    ```ts
    let setBadgeNumberCallback = (err: BusinessError): void => {
      if (err) {
        hilog.error(DOMAIN_NUMBER, TAG, `Failed to set badge number. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      hilog.info(DOMAIN_NUMBER, TAG, `Succeeded in setting badge number.`);
    }

    let badgeNumber = 9;
    notificationManager.setBadgeNumber(badgeNumber, setBadgeNumberCallback);
    ```

3. Decrease the count on the badge.

   After a notification is read, the application needs to call the API to set the number of remaining unread notifications. The badge is then updated.

    ```ts
    let setBadgeNumberCallback = (err: BusinessError): void => {
      if (err) {
        hilog.error(DOMAIN_NUMBER, TAG, `Failed to set badge number. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      hilog.info(DOMAIN_NUMBER, TAG, `Succeeded in setting badge number.`);
    }

    let badgeNumber = 8;
    notificationManager.setBadgeNumber(badgeNumber, setBadgeNumberCallback);
    ```

## FAQs

**setBadgeNumber** is an asynchronous API. When **setBadgeNumber** is used to set badges consecutively, you should not set the value until the previous setting is complete, ensuring that the execution sequence meets the expectation.

- Negative example

    Independent API calling cannot guarantee a proper calling sequence during actual execution.

    The sample code is as follows:

    ```ts
    let badgeNumber: number = 10;
    notificationManager.setBadgeNumber(badgeNumber).then(() => {
      hilog.info(DOMAIN_NUMBER, TAG, `setBadgeNumber 10 success.`);
    });
    badgeNumber = 11;
    notificationManager.setBadgeNumber(badgeNumber).then(() => {
      hilog.info(DOMAIN_NUMBER, TAG, `setBadgeNumber 11 success.`);
    });
    ```

- Positive example

    Dependencies existing between multiple API callings ensures that the next setting can be performed only after the previous setting is complete.

    The sample code is as follows:

    ```ts
    let badgeNumber: number = 10;
    notificationManager.setBadgeNumber(badgeNumber).then(() => {
      hilog.info(DOMAIN_NUMBER, TAG, `setBadgeNumber 10 success.`);
      badgeNumber = 11;
      notificationManager.setBadgeNumber(badgeNumber).then(() => {
        hilog.info(DOMAIN_NUMBER, TAG, `setBadgeNumber 11 success.`);
      });
    });
    ```
