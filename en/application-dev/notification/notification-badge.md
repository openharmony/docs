# Managing the Notification Badge

The system provides APIs for setting the notification badge, which is displayed in the upper right corner of the application icon on the home screen to notify the user of the count of unread notifications.

When a new notification arrives, the count on the badge is incremented by 1.

After a notification is read, the count on the badge is decremented by 1. If there is no unread notification, the badge is not displayed.


## Available APIs

1. The notification service provides two methods to increase the count on the notification badge:

   - When publishing a notification, pass the **badgeNumber** parameter in [NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest). After the notification is received, the count on the badge is incremented.

   - Call the [setBadgeNumber()](../reference/apis/js-apis-notificationManager.md#notificationmanagersetbadgenumber10) API to set the count on the badge.

2. To decrease the count on the badge, call the [setBadgeNumber()](../reference/apis/js-apis-notificationManager.md#notificationmanagersetbadgenumber10) API.

| API| Description|
| -------- | -------- |
| setBadgeNumber(badgeNumber: number, callback: AsyncCallback\<void\>): void | Sets the count on the badge.|


## How to Develop

1. Import the **NotificationManager** module.

   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

2. Increase the count on the badge.

   When publishing a notification, pass the **badgeNumber** parameter in [NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest). For details, see [Publishing a Basic Notification](text-notification.md).
   
   In this example, the **setBadgeNumber** API is called to add a badge. This API is called after a new notification is published.
   
   ```ts
   function setBadgeNumberCallback(err:Base.BusinessError) {
     if (err) {
       console.error(`Failed to set badge number. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     console.info(`Succeeded in seting badge number.`);
   }
   
   let badgeNumber = 10;
   notificationManager.setBadgeNumber(badgeNumber, setBadgeNumberCallback);
   ```

3. Decrease the count on the badge.

   After a notification is read, the application needs to call the API to set the number of remaining unread notifications. The badge is then updated.

   ```ts
   function setBadgeNumberCallback(err:Base.BusinessError) {
     if (err) {
       console.error(`Failed to set badge number. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     console.info(`Succeeded in seting badge number.`);
   }
   
   let badgeNumber = 9;
   notificationManager.setBadgeNumber(badgeNumber, setBadgeNumberCallback);
   ```

   
