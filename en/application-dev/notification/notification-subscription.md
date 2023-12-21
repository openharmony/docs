# Notification Subscription (for System Applications Only)


To receive notifications, an application must subscribe to notifications first. The notification subsystem provides two types of subscription APIs, allowing applications to subscribe to notifications from all applications or notifications from a specific application.


You can use the [NotificationSubscriber](../reference/apis/js-apis-notification.md#notificationsubscriber) object to provide callbacks for subscription events, such as subscription success, notification reception, notification cancellation, and subscription cancellation.


## Available APIs

The major APIs for notification subscription are described as follows. For details about the APIs, see [@ohos.notificationSubscribe](../reference/apis/js-apis-notificationSubscribe.md).

**Table 1** Major APIs for notification subscription

| Name | Description|
| -------- | -------- |
| subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback&lt;void&gt;): void | Subscribes to notifications from a specific application.|
| subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback&lt;void&gt;): void                                  | Subscribes to notifications from all applications.    |

**Table 2** Callbacks for notification subscription

| Name | Description|
| -------- | -------- |
| onConsume?:(data: SubscribeCallbackData) =&gt; void                                      | Callback for receiving notifications.              |
| onCancel?:(data: SubscribeCallbackData) =&gt; void                                       | Callback for canceling notifications.          |
| onUpdate?:(data: NotificationSortingMap) =&gt; void                                      | Callback for notification sorting updates.      |
| onConnect?:() =&gt; void;                                                                | Callback for subscription.          |
| onDisconnect?:() =&gt; void;                                                             | Callback for unsubscription.          |
| onDestroy?:() =&gt; void                                                                 | Callback for disconnecting from the notification subsystem.  |
| onDoNotDisturbDateChange?:(mode: notification.DoNotDisturbDate) =&gt; void               | Callback for the Do Not Disturb (DNT) time changes.|
| onEnabledNotificationChanged?:(callbackData: EnabledNotificationCallbackData) =&gt; void | Callback for notification switch changes.      |


## How to Develop

1. Request the **ohos.permission.NOTIFICATION_CONTROLLER** permission. For details, see [Permission Application Guide](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Import the **notificationSubscribe** module.
   
   ```ts
   import notificationSubscribe from '@ohos.notificationSubscribe';
   ```

3. Create a **subscriber** object.
   
   ```ts
   let subscriber = {
     onConsume: function (data) {
       let req = data.request;
       console.info(`onConsume callback. req.id: ${req.id}`);
     },
     onCancel: function (data) {
       let req = data.request;
       console.info(`onCancel callback. req.id: ${req.id}`);
     },
     onUpdate: function (data) {
       let req = data.request;
       console.info(`onUpdate callback. req.id: ${req.id}`);
     },
     onConnect: function () {
       console.info(`onConnect callback.}`);
     },
     onDisconnect: function () {
       console.info(`onDisconnect callback.}`);
     },
     onDestroy: function () {
       console.info(`onDestroy callback.}`);
     },
   };
   ```

4. Initiate notification subscription.
   
   ```ts
   notificationSubscribe.subscribe(subscriber, (err, data) => { // This API uses an asynchronous callback to return the result.
     if (err) {
       console.error(`Failed to subscribe notification. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     console.info(`Succeeded in subscribing to notification. Data: ${data}`);
   });
   ```
