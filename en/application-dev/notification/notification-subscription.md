# Subscribing to Notifications (for System Applications Only)


To receive notifications, an application must subscribe to notifications first. The notification subsystem provides two types of subscription APIs, allowing applications to subscribe to notifications from all applications or notifications from a specific application.


You can use the [NotificationSubscriber](../reference/apis/js-apis-inner-notification-notificationSubscriber.md) object to provide callbacks for subscription events, such as subscription success, notification reception, notification cancellation, and subscription cancellation.


## Available APIs

The major APIs for notification subscription are described as follows. For details about the APIs, see [@ohos.notificationSubscribe](../reference/apis/js-apis-notificationSubscribe.md).

**Table 1** Major APIs for notification subscription

| API| Description|
| -------- | -------- |
| subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback&lt;void&gt;): void | Subscribes to notifications from a specific application.|
| subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback&lt;void&gt;): void | Subscribes to notifications from all applications.    |

**Table 2** Callbacks for notification subscription

| API| Description|
| -------- | -------- |
| onConsume?:(data: SubscribeCallbackData) =&gt; void | Callback for receiving notifications.              |
| onCancel?:(data: SubscribeCallbackData) =&gt; void | Callback for canceling notifications.          |
| onUpdate?:(data: NotificationSortingMap) =&gt; void | Callback for notification sorting updates.      |
| onConnect?:() =&gt; void;                          | Callback for subscription.          |
| onDisconnect?:() =&gt; void;                       | Callback for unsubscription.          |
| onDestroy?:() =&gt; void                           | Callback for disconnecting from the notification subsystem.  |
| onDoNotDisturbDateChange<sup>deprecated</sup>?:(mode: notification.DoNotDisturbDate<sup>deprecated</sup>) =&gt; void | Callback for the Do Not Disturb (DNT) time changes. This API is deprecated since API version 11.|
| onDoNotDisturbChanged?:(mode: notificationManager.DoNotDisturbDate) =&gt; void | Callback for the Do Not Disturb (DNT) time changes.|
| onEnabledNotificationChanged?:(callbackData: EnabledNotificationCallbackData) =&gt; void | Callback for notification switch changes.      |
| onBadgeChanged?:(data: BadgeNumberCallbackData) =&gt; void | Callback for notification badge number changes.|


## How to Develop

1. Request the **ohos.permission.NOTIFICATION_CONTROLLER** permission. For details, see [Permission Application Guide](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Import the **notificationSubscribe** module.
   
   ```ts
   import notificationSubscribe from '@ohos.notificationSubscribe';
   import Base from '@ohos.base';
   ```

3. Create a **subscriber** object.
   
   ```ts
   let subscriber:notificationSubscribe.NotificationSubscriber = {
     onConsume: (data:notificationSubscribe.SubscribeCallbackData) => {
       let req = data.request;
       console.info(`onConsume callback. req.id: ${req.id}`);
     },
     onCancel: (data:notificationSubscribe.SubscribeCallbackData) => {
       let req = data.request;
       console.info(`onCancel callback. req.id: ${req.id}`);
     },
     onUpdate: (data) => {
       console.info(`onUpdate callback. req.id: ${data.sortedHashCode}`);
     },
     onConnect: () => {
       console.info(`onConnect callback.}`);
     },
     onDisconnect: () => {
       console.info(`onDisconnect callback.}`);
     },
     onDestroy: () => {
       console.info(`onDestroy callback.}`);
     },
   };
   ```
   
4. Initiate notification subscription.
   
   ```ts
   notificationSubscribe.subscribe(subscriber, (err:Base.BusinessError) => { // This API uses an asynchronous callback to return the result.
     if (err) {
       console.error(`Failed to subscribe notification. Code is ${err.code}, message is ${err.message}`);
       return;
     }
   });
   ```
