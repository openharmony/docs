# 发布进度条类型通知


进度条通知也是常见的通知类型，主要应用于文件下载、事务处理进度显示。OpenHarmony提供了进度条模板，发布通知应用设置好进度条模板的属性值，如模板名、模板数据，通过通知子系统发送到通知栏显示。

目前系统模板仅支持进度条模板，通知模板[NotificationTemplate](../reference/apis/js-apis-notificationManager.md#notificationtemplate)中的data参数为用户自定义数据，用于显示与模块相关的数据，效果示意如下图所示。

![zh-cn_image_0000001416903138](figures/zh-cn_image_0000001416903138.png)


## 接口说明

[isSupportTemplate()](../reference/apis/js-apis-notificationManager.md#notificationissupporttemplate)是查询模板是否支持接口，目前仅支持进度条模板。

| | |
| -------- | -------- |
| **接口名** | **描述** |
| isSupportTemplate(templateName:&nbsp;string,&nbsp;callback:&nbsp;AsyncCallback&lt;boolean&gt;):&nbsp;void | 查询模板是否存在。 |


## 开发步骤

1. [使能通知开关](notification-enable.md)，获得用户授权后，才能使用通知功能。

2. 导入模块。
   
   ```ts
   import NotificationManager from '@ohos.notificationManager';
   ```

3. 查询系统是否支持进度条模板，查询结果为支持downloadTemplate模板类通知。
   
   ```ts
   NotificationManager.isSupportTemplate('downloadTemplate').then((data) => {
     console.info(`[ANS] isSupportTemplate success`);
     let isSupportTpl: boolean = data; // isSupportTpl的值为true表示支持支持downloadTemplate模板类通知，false表示不支持
     // ...
   }).catch((err) => {
     console.error(`[ANS] isSupportTemplate failed, error[${err}]`);
   });
   ```

   > **说明：**
   > 查询系统支持进度条模板后，再进行后续的步骤操作。

4. 构造进度条模板对象，并发布通知。
   
   ```ts
   let notificationRequest = {
     id: 1,
     content: {
       contentType: NotificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
       normal: {
         title: 'test_title',
         text: 'test_text',
         additionalText: 'test_additionalText'
       }
     },
     // 构造进度条模板，name字段当前需要固定配置为downloadTemplate
     template: {
       name: 'downloadTemplate',
       data: { title: 'File Title', fileName: 'music.mp4', progressValue: 45 }
     }
   }
   
   // 发布通知
   NotificationManager.publish(notificationRequest, (err) => {
     if (err) {
       console.error(`[ANS] failed to publish, error[${err}]`);
       return;
     }
     console.info(`[ANS] publish success `);
   });
   ```
