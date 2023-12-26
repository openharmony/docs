# 管理通知角标

针对应用未读的通知，系统提供了角标设置接口，将未读通知个数显示在桌面图标的右上角角标上。

通知增加时，角标上显示的未读通知个数需要增加。

通知被查看后，角标上显示的未读通知个数需要减少，没有未读通知时，不显示角标。


## 接口说明

1. 通知服务提供了两种增加角标数的方法：

   - 发布通知时，在[NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest)的badgeNumber字段里携带，桌面收到通知后，在原角标数上累加、呈现。

   - 调用接口[`setBadgeNumber()`](../reference/apis/js-apis-notificationManager.md#notificationmanagersetbadgenumber10)设置，桌面按设置的角标数呈现。

2. 角标数减少，目前仅支持通过[`setBadgeNumber()`](../reference/apis/js-apis-notificationManager.md#notificationmanagersetbadgenumber10)设置。

| **接口名** | **描述** |
| -------- | -------- |
| setBadgeNumber(badgeNumber: number, callback: AsyncCallback\<void\>): void | 设置角标个数 |


## 开发步骤

1. 导入NotificationManager模块。

   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   import { logger } from '../util/Logger';
   ```

2. 增加角标个数。

   发布通知在[NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest)的badgeNumber字段里携带，可参考[通知发布](text-notification.md)章节。
   
   示例为调用setBadgeNumber接口增加角标，在发布完新的通知后，调用该接口。
   
   ```ts
   setBadgeNumberCallback = async (err: Base.BusinessError) => {
     if (err) {
       logger.error(`Failed to set badge number. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     logger.info(`Succeeded in setting badge number.`);
   }
   
   let badgeNumber = 9;
   notificationManager.setBadgeNumber(badgeNumber, this.setBadgeNumberCallback);
   ```

3. 减少角标个数。

   一条通知被查看后，应用需要调用接口设置剩下未读通知个数，桌面刷新角标。

   ```ts
   setBadgeNumberCallback = async (err: Base.BusinessError) => {
     if (err) {
       logger.error(`Failed to set badge number. Code is ${err.code}, message is ${err.message}`);
       return;
     }
     logger.info(`Succeeded in setting badge number.`);
   }
   
   let badgeNumber = 8;
   notificationManager.setBadgeNumber(badgeNumber, this.setBadgeNumberCallback);
   ```

   
