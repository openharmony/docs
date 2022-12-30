# 订阅通知（仅对系统应用开放）


应用需要接收通知，必须先发起订阅，通知子系统提供两种接口：订阅所有应用发布的通知和订阅某些应用发布的通知。


系统提供NotificationSubscriber对象，用于提供订阅成功、通知接收、通知取消、订阅取消等回调接口，将变化信息回调给订阅者。


## 接口说明

通知订阅主要接口如下。详细接口介绍请参见[API参考](../reference/apis/js-apis-notificationSubscribe.md)。

**表1** 通知订阅接口介绍

| **接口名** | **描述** |
| -------- | -------- |
| subscribe(subscriber:&nbsp;NotificationSubscriber,&nbsp;info:&nbsp;NotificationSubscribeInfo,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 订阅指定应用通知。 |
| subscribe(subscriber:&nbsp;NotificationSubscriber,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 订阅所有通知。     |

**表2** 通知订阅回调接口介绍

| | |
| -------- | -------- |
| **接口名** | **描述** |
| onConsume?:(data:&nbsp;SubscribeCallbackData)&nbsp;=&gt;&nbsp;void | 通知回调。 |
| onCancel?:(data:&nbsp;SubscribeCallbackData)&nbsp;=&gt;&nbsp;void | 通知取消回调。 |
| onUpdate?:(data:&nbsp;NotificationSortingMap)&nbsp;=&gt;&nbsp;void | 通知排序更新回调。 |
| onConnect?:()&nbsp;=&gt;&nbsp;void; | 订阅成功回调。 |
| onDisconnect?:()&nbsp;=&gt;&nbsp;void; | 取消订阅回调。 |
| onDestroy?:()&nbsp;=&gt;&nbsp;void | 与通知子系统断开回调。 |
| onDoNotDisturbDateChange?:(mode:&nbsp;notification.DoNotDisturbDate)&nbsp;=&gt;&nbsp;void | 免打扰时间选项变更回调。 |
| onEnabledNotificationChanged?:(callbackData:&nbsp;EnabledNotificationCallbackData)&nbsp;=&gt;&nbsp;void | 通知开关变更回调。 |


## 开发步骤

1. 申请`ohos.permission.NOTIFICATION_CONTROLLER`权限，配置方式请参见[访问控制授权申请](../security/accesstoken-guidelines.md#配置文件权限声明)。

2. 导入通知订阅模块。
   
   ```ts
   import NotificationSubscribe from '@ohos.notificationSubscribe';
   ```

3. 创建订阅者对象。
   
   ```ts
   let subscriber = {
       onConsume: function (data) {
           let req = data.request;
           console.info('[ANS] onConsume callback req.id: ' + req.id);
       },
       onCancel: function (data) {
           let req = data.request;
           console.info('[ANS] onCancel callback req.id: : ' + req.id);
       },
       onUpdate: function (data) {
           console.info('[ANS] onUpdate in test');
       },
       onConnect: function () {
           console.info('[ANS] onConnect in test');
       },
       onDisconnect: function () {
           console.info('[ANS] onDisConnect in test');
       },
       onDestroy: function () {
           console.info('[ANS] onDestroy in test');
       },
   };
   ```

4. 发起通知订阅。
   
   ```ts
   NotificationSubscribe.subscribe(subscriber, (err, data) => { // callback形式调用异步接口
     if (err) {
       console.error(`[ANS] failed to subscribe, error[${err}]`);
       return;
     }
     console.info(`[ANS] subscribeTest success : + ${data}`);
   });
   ```
