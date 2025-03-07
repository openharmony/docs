# 取消通知

用户收到通知提醒后，点击通知并拉起应用到前台时，应用可以选择取消某条通知或所有通知。

例如，用户收到某个好友的IM消息，点击通知进入应用查看消息后，应用可以取消相关通知提醒。

## 接口说明

通知取消接口如下。接口详情参见[API参考](../reference/apis-notification-kit/js-apis-notificationManager.md)。

| **接口名** | **描述** |
| -------- | -------- |
| cancel(id:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 取消指定的通知。           |
| cancelAll(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 取消所有该应用发布的通知。 |


## 开发步骤

本文以取消`文本类型通知`为例进行说明，其他类型通知取消操作与此类似。

1. 导入模块。
   
   ```ts
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   const TAG: string = '[PublishOperation]';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. 发布通知。

   参考[发布文本类型通知](./text-notification.md)。

3. 取消通知。

   ```ts
    // 当拉起应用到前台，查看消息后，调用该接口取消通知。
    notificationManager.cancel(1, (err: BusinessError) => {
      if (err) {
        hilog.error(DOMAIN_NUMBER, TAG, `Failed to cancel notification. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in canceling notification.');
    });
   ```