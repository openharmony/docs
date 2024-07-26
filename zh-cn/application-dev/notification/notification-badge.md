# 管理通知角标

针对未读的通知，系统提供了角标设置接口，将未读通知个数显示在桌面图标的右上角角标上。

通知增加时，角标上显示的未读通知个数需要增加。

通知被查看后，角标上显示的未读通知个数需要减少，没有未读通知时，不显示角标。


## 接口说明

- 增加角标数，支持如下两种方法：

   - 发布通知时，在[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest)的badgeNumber字段里携带，桌面收到通知后，在原角标数上累加、呈现。

   - 调用接口[setBadgeNumber()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagersetbadgenumber10)设置，桌面按设置的角标数呈现。

- 减少角标数，目前仅支持通过[setBadgeNumber()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagersetbadgenumber10)设置。

  | **接口名** | **描述** |
  | -------- | -------- |
  | setBadgeNumber(badgeNumber: number, callback: AsyncCallback\<void\>): void | 设置角标个数。 |


## 开发步骤

1. 导入NotificationManager模块。

   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. 增加角标个数。

   发布通知在[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest)的badgeNumber字段里携带，可参考[通知发布](text-notification.md)章节。
   
   示例为调用setBadgeNumber接口增加角标，在发布完新的通知后，调用该接口。
   
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

3. 减少角标个数。

   一条通知被查看后，应用需要调用接口设置剩下未读通知个数，桌面刷新角标。

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

   
