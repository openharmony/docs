# 管理通知渠道
系统支持多种通知渠道，不同通知渠道对应的通知提醒方式不同，应用可以选择适合自己的通知渠道，并对通知渠道进行管理(支持创建，查询，删除等操作)。

## 通知渠道类型说明

不同类型的通知渠道对应的通知提醒方式不同，详见下表。其中，Y代表支持，N代表不支持。

| SlotType             | 取值   | 分类     | 通知中心 | 横幅 | 锁屏 | 铃声/振动 | 状态栏图标 | 自动亮屏 |
| -------------------- | ------ | --------| ------- |------|------|----------|-----------|---------|
| SOCIAL_COMMUNICATION | 1      | 社交通信 | Y | Y | Y | Y | Y | Y |
| SERVICE_INFORMATION  | 2      | 服务提醒 | Y | N | Y | Y | Y | Y |
| CONTENT_INFORMATION  | 3      | 内容资讯 | Y | N | N | N | Y | N |
| CUSTOMER_SERVICE     | 5      | 客服消息 | Y | N | N | Y | Y | N |
| OTHER_TYPES          | 0xFFFF | 其他     | Y | N | N | N | N | N |


## 接口说明

| **接口名** | **描述** |
| ---------- | -------- |
| [addSlot](../reference/apis/js-apis-notificationManager.md#notificationmanageraddslot-2)(type: SlotType, callback: AsyncCallback\<void\>): void <br> [addSlot](../reference/apis/js-apis-notificationManager.md#notificationmanageraddslot-3)(type: SlotType): Promise\<void\> | 创建指定类型的通知渠道。          |
| [getSlot](../reference/apis/js-apis-notificationManager.md#notificationmanagergetslot)(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void <br>[getSlot](../reference/apis/js-apis-notificationManager.md#notificationmanagergetslot-1)(slotType: SlotType): Promise\<NotificationSlot\> | 获取一个指定类型的通知渠道。  |
| [getSlots](../reference/apis/js-apis-notificationManager.md#notificationmanagergetslots)(callback: AsyncCallback\<Array\<NotificationSlot>>): void <br> [getSlots](../reference/apis/js-apis-notificationManager.md#notificationmanagergetslots-1)(): Promise\<Array\<NotificationSlot>>  | 获取此应用程序的所有通知渠道。     |
| [removeSlot](../reference/apis/js-apis-notificationManager.md#notificationmanagerremoveslot)(slotType: SlotType, callback: AsyncCallback\<void\>): void  <br> [removeSlot](../reference/apis/js-apis-notificationManager.md#notificationmanagerremoveslot-1)(slotType: SlotType): Promise\<void\>  | 删除此应用程序指定类型的通知渠道。  |
| [removeAllSlots](../reference/apis/js-apis-notificationManager.md#notificationmanagerremoveallslots)(callback: AsyncCallback\<void\>): void <br> [removeAllSlots](../reference/apis/js-apis-notificationManager.md#notificationmanagerremoveallslots-1)(): Promise\<void\>   | 删除此应用程序所有通知渠道。       |

除了可以使用`addslot()`创建通知渠道，还可以在发布通知的[NotificationRequest](../reference/apis/js-apis-inner-notification-notificationRequest.md#notificationrequest)中携带notificationSlotType字段，如果对应渠道不存在，会自动创建
。

## 开发步骤

1. 导入notificationManager模块。

   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

2. 创建指定类型的通知渠道。

    ```ts
    import Base from '@ohos.base';

    // addslot回调
    let addSlotCallBack = (err: Base.BusinessError): void => {
        if (err) {
            console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
        } else {
            console.info("addSlot success");
        }
    }
    notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack);
    ```

3. 查询指定类型的通知渠道。

    ```ts
    // getSlot回调
    let getSlotCallback = (err: Base.BusinessError, data: notificationManager.NotificationSlot): void => {
        if (err) {
            console.error(`getSlot failed, code is ${err.code}, message is ${err.message}`);
        } else {
            console.info(`getSlot success, data is ${JSON.stringify(data)}`);
        }
    }
    let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
    notificationManager.getSlot(slotType, getSlotCallback);
    ```

4. 删除指定类型的通知渠道。

    ```ts
    // removeSlot回调
    let removeSlotCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`removeSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeSlot success");
    }
    }
    let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
    notificationManager.removeSlot(slotType, removeSlotCallback);
    ```