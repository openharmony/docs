# 管理通知渠道
系统支持多种通知渠道，不同通知渠道对应的通知提醒方式不同，可以根据应用的实际场景选择适合的通知渠道，并对通知渠道进行管理（支持创建、查询、删除等操作）。

## 通知渠道类型说明

不同类型的通知渠道对应的通知提醒方式不同，详见下表。其中，Y代表支持，N代表不支持。

<!--RP1-->
<!--RP1End-->

| SlotType             | 取值   | 分类     | 通知中心 | 横幅 | 锁屏 | 铃声/振动 | 状态栏图标 | 自动亮屏 |
| -------------------- | ------ | --------| ------- |------|------|----------|-----------|---------|
| UNKNOWN_TYPE         | 0      | 未知类型 | Y | N | N | N | N | N |
| SOCIAL_COMMUNICATION | 1      | 社交通信 | Y | Y | Y | Y | Y | Y |
| SERVICE_INFORMATION  | 2      | 服务提醒 | Y | Y | Y | Y | Y | Y |
| CONTENT_INFORMATION  | 3      | 内容资讯 | Y | N | N | N | N | N |
| CUSTOMER_SERVICE     | 5      | 客服消息 | Y | N | N | Y | Y | N |
| OTHER_TYPES          | 0xFFFF | 其他     | Y | N | N | N | N | N |


## 接口说明

通知渠道主要接口如下。其他接口介绍详情参见[API参考](../reference/apis-notification-kit/js-apis-notificationManager.md)。

| **接口名** | **描述** |
| ---------- | -------- |
| addSlot(type: SlotType): Promise\<void\>                 | 创建指定类型的通知渠道。           |
| getSlot(slotType: SlotType): Promise\<NotificationSlot\> | 获取一个指定类型的通知渠道。       |
| removeSlot(slotType: SlotType): Promise\<void\>          | 删除此应用程序指定类型的通知渠道。  |

除了可以使用`addslot()`创建通知渠道，还可以在发布通知的[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest)中携带notificationSlotType字段，如果对应渠道不存在，会自动创建。

## 开发步骤

1. 导入notificationManager模块。

   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';

   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. 创建指定类型的通知渠道。

    ```ts
    // addSlot回调
    let addSlotCallBack = (err: BusinessError): void => {
      if (err) {
        hilog.error(DOMAIN_NUMBER, TAG, `addSlot failed, code is ${err.code}, message is ${err.message}`);
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, `addSlot success`);
      }
    }
    notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack);
    ```

3. 查询指定类型的通知渠道。

    获取对应渠道是否创建以及该渠道支持的通知提醒方式，比如是否有声音提示，是否有震动，锁屏是否可见等。
    ```ts
    // getSlot回调
    let getSlotCallback = (err: BusinessError, data: notificationManager.NotificationSlot): void => {
      if (err) {
        hilog.error(DOMAIN_NUMBER, TAG, `Failed to get slot. Code is ${err.code}, message is ${err.message}`);
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, `Succeeded in getting slot.`);
        if (data != null) {
          hilog.info(DOMAIN_NUMBER, TAG, `slot enable status is ${JSON.stringify(data.enabled)}`);
          hilog.info(DOMAIN_NUMBER, TAG, `slot level is ${JSON.stringify(data.level)}`);
          hilog.info(DOMAIN_NUMBER, TAG, `vibrationEnabled status is ${JSON.stringify(data.vibrationEnabled)}`);
          hilog.info(DOMAIN_NUMBER, TAG, `lightEnabled status is ${JSON.stringify(data.lightEnabled)}`);
        }
      }
    }
    let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
    notificationManager.getSlot(slotType, getSlotCallback);
    ```

4. 删除指定类型的通知渠道。

    ```ts
    // removeSlot回调
    let removeSlotCallback = (err: BusinessError): void => {
      if (err) {
        hilog.error(DOMAIN_NUMBER, TAG, `removeSlot failed, code is ${JSON.stringify(err.code)}, message is ${JSON.stringify(err.message)}`);
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, "removeSlot success");
      }
    }
    let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
    notificationManager.removeSlot(slotType, removeSlotCallback);
    ```
