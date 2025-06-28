# Cross-Device Notification Management (for System Applications Only)

By default, notifications are published across devices. If an application has implemented notification across devices (for example, SMS notifications are sent to devices such as watches, tablets, and 2-in-1 devices), you need to manage the distributed devices to avoid repeated notifications.

Since API version 18, a system application is supported to publish notifications in the following manners:

- If a notification of an application is published only on the current device, set the **notDistributed** field in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md) parameter to **true**.
- If a notification of an application is published based on the cross-device collaborative management list, set the **notDistributed** field in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md) parameter to **false** and **forceDistributed** to **true**.

## Available APIs

| **API** | **Description**| **Note**|
| -------- | -------- |-------- |
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish-1)(request: [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md)): Promise\<void\>       | Publishes a notification. | For details, see the description of the **notDistributed** and **forceDistributed** fields in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md) object.|


## How to Develop

1. Import the related modules.

    ```typescript
    import { notificationManager } from '@kit.NotificationKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Set the manner for publishing a notification.

  - Publish the notification only on the current device.

    ```typescript
    // publish callback
    let publishCallback = (err: BusinessError): void => {
      if (err) {
        console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
      } else {
        console.info(`Succeeded in publishing notification.`);
      }
    }
    // NotificationRequest object
    let notificationRequest: notificationManager.NotificationRequest = {
      id: 1,
      content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
          title: "test_title",
          text: "test_text",
          additionalText: "test_additionalText"
          }
        },
        // Set notDistributed to true, indicating that the notification is not published across devices.
        notDistributed: true
    };
    notificationManager.publish(notificationRequest, publishCallback);
    ```

  - Publish the notification based on the cross-device collaborative management list.

    ```typescript
    // publish callback
    let publishCallback = (err: BusinessError): void => {
      if (err) {
        console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
      } else {
        console.info(`Succeeded in publishing notification.`);
      }
    }
    // NotificationRequest object
    let notificationRequest: notificationManager.NotificationRequest = {
      id: 1,
      content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
          title: "test_title",
          text: "test_text",
          additionalText: "test_additionalText"
          }
        },
        // Set notDistributed to false and forceDistributed to true, indicating that the notification is published across devices based on the cross-device collaborative management list.
        notDistributed: false,
        forceDistributed: true
    };
    notificationManager.publish(notificationRequest, publishCallback);
    ```
