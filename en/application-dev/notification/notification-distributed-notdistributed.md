# Cross-Device Notification Management (for System Applications Only)

<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

By default, notifications are published across devices. If an application has implemented notification across devices (for example, SMS notifications are sent to devices such as watches, tablets, and 2-in-1 devices), you need to manage the distributed devices to avoid duplicate notifications.

Since API version 18, a system application is supported to publish notifications in the following manners:

- If a notification of an application is published only on the current device, set the **notDistributed** field in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md) parameter to **true**.
- If a notification of an application is published based on the device management list, set the **notDistributed** field in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md) parameter to **false** and **forceDistributed** to **true**.

## Available APIs

| **API** | **Description**| **Note**|
| -------- | -------- |-------- |
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish-1)(request: NotificationRequest): Promise\<void\>       | Publishes a notification. | For details, see the description of the **notDistributed** and **forceDistributed** fields in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md) object.|
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish)(request: NotificationRequest, callback: AsyncCallback\<void\>): void | Publishes a notification.| For details, see the description of the **notDistributed** and **forceDistributed** fields in the [NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md) object.|

## Prerequisites

 - The user has connected the watch to the phone through the Huawei Health app.
 - The user has turned on the switch for syncing notifications from phone to watch for specified applications in **Huawei Health** > **Devices** > **Notifications** on their phones.

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
          title: 'test_title',
          text: 'test_text',
          additionalText: 'test_additionalText'
        }
      },
      // Set the notification to be published only on the current device.
      notDistributed: true
    };
    notificationManager.publish(notificationRequest, publishCallback);
    ```

  - Publish the notification across devices based on the device management list.

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
          title: 'test_title',
          text: 'test_text',
          additionalText: 'test_additionalText'
        }
      },
      // If forceDistributed is set to true, it takes effect only when the application is in the device management list and the notDistributed field is not set. If forceDistributed is set to false, the notification is published to the devices according to the device management list.
      notDistributed: false,
      forceDistributed: true
    };
    notificationManager.publish(notificationRequest, publishCallback);
    ```
