# 请求通知授权


应用需要被授权才能发送通知。开发者可以在通知发布前调用[requestEnableNotification()](../reference/apis/js-apis-notificationManager.md#notificationmanagerrequestenablenotification)方法，弹窗让用户选择是否允许发送通知，仅弹窗一次，后续调用该接口不再弹窗。

  **图1** 请求通知授权示意图  
![zh-cn_image_0000001416585590](figures/zh-cn_image_0000001416585590.png)

- 点击“允许”后，则表示允许应用发送通知。

- 点击“取消”后，再次调用[requestEnableNotification()](../reference/apis/js-apis-notificationManager.md#notificationmanagerrequestenablenotification)方法，则不再弹窗。此时如需要手动获取通知授权，操作步骤如下所示。
  
  | ①从设备左上方下拉，进入通知界面                              | ②点击右上角“设置”图标，进入通知界面，找到需要请求通知授权的应用 | ③打开“允许通知”开关                                          |
  | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | ![zh-cn_image_0000001417062434](figures/zh-cn_image_0000001417062434.png) | ![zh-cn_image_0000001466462297](figures/zh-cn_image_0000001466462297.png) | ![zh-cn_image_0000001466782025](figures/zh-cn_image_0000001466782025.png) |


## 接口说明

详细接口见[接口文档](../reference/apis/js-apis-notificationManager.md#notificationrequestenablenotification)。

**表1** 通知授权接口功能介绍

| **接口名**  | **描述** |
| -------- | -------- |
| isNotificationEnabled(bundle:&nbsp;BundleOption,&nbsp;callback:&nbsp;AsyncCallback&lt;boolean&gt;):&nbsp;void       | 查询通知是否授权。  |
| requestEnableNotification(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 请求发送通知的许可，第一次调用弹窗供用户选择允许或禁止。     |


## 开发步骤

1. 导入NotificationManager模块。

   ```ts
   import notificationManager from '@ohos.notificationManager';
   import Base from '@ohos.base';
   ```

2. 请求通知授权。

   ```ts
   notificationManager.requestEnableNotification().then(() => {
       console.info(`[ANS] requestEnableNotification success`);
   }).catch((err:Base.BusinessError) => {
       console.error(`[ANS] requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
   });
   ```

