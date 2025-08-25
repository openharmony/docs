# 通知消息跨设备协同管理（仅对系统应用开放）

<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

默认情况下，通知消息会进行跨设备协同。如果应用已通过分布式通信能力实现跨设备协同（例如短信通知消息由短信应用本身协同到手表、平板、2in1等设备），为了避免通知消息在不同设备上重复发送，需要针对分布式通知的协同设备进行管理。

从API version 18开始，支持系统应用通过以下方式对分布式通知的协同设备进行管理：

- 当应用的某个通知消息仅在当前设备发布时，需要将[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md)参数中的**notDistributed**字段配置为true。
- 当应用的某个通知消息需要按设备管控名单发布时，需要将[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md)参数中的**notDistributed**字段配置为false，**forceDistributed**字段为配置true。

## 接口说明

| **接口名**  | **描述** | **说明** |
| -------- | -------- |-------- |
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish-1)(request: NotificationRequest): Promise\<void\>       | 发布通知。  | 具体使用方法见入参对象[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md)中**notDistributed**与**forceDistributed**字段说明。|
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish)(request: NotificationRequest, callback: AsyncCallback\<void\>): void | 发布通知。 | 具体使用方法见入参对象[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest-sys.md)中**notDistributed**与**forceDistributed**字段说明。 |

## 前提条件

 - 用户已通过手机中运动健康App连接手表。
 - 用户已在手机的“运动健康App > 设备 > 消息通知”中，开启“同步手机消息通知至手表”开关与“支持的应用”通知开关。

## 开发步骤

1. 导入模块。

    ```typescript
    import { notificationManager } from '@kit.NotificationKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 通知消息跨设备协同管理。

  - 配置应用通知消息仅在当前设备上发布。

    ```typescript
    // publish回调
    let publishCallback = (err: BusinessError): void => {
      if (err) {
        console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
      } else {
        console.info(`Succeeded in publishing notification.`);
      }
    }
    // 通知Request对象
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
      // 配置应用通知消息仅在当前设备上发布。
      notDistributed: true
    };
    notificationManager.publish(notificationRequest, publishCallback);
    ```

  - 配置应用通知消息根据管控名单跨设备协同发布。

    ```typescript
    // publish回调
    let publishCallback = (err: BusinessError): void => {
      if (err) {
        console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
      } else {
        console.info(`Succeeded in publishing notification.`);
      }
    }
    // 通知Request对象
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
      // 仅当应用在跨设备协同管控名单中且未配置notDistributed字段时，forceDistributed才会生效,且当forceDistributed为false按照协同管控名单显示
      notDistributed: false,
      forceDistributed: true
    };
    notificationManager.publish(notificationRequest, publishCallback);
    ```
