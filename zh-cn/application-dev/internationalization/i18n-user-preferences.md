# 用户偏好

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

## 使用场景

除区域设置和应用偏好语言设置外，系统还可以设置用户偏好，当前支持本地数字和时制两种偏好。用户偏好设置会保存到系统区域及应用偏好语言中，最终体现在用户界面的国际化特性上。

## 开发步骤

接口具体使用方法和说明请参考[System](../reference/apis-localization-kit/js-apis-i18n.md#system9)的API接口文档。

1. 导入模块。
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';
   ```

2. 获取用户偏好。
   ```ts
   // 判断系统当前是否使用本地数字
   let usingLocalDigit: boolean = i18n.System.getUsingLocalDigit();

   // 判断系统当前是否使用24小时制
   let is24HourClock: boolean = i18n.System.is24HourClock();

   // 通过监听公共事件COMMON_EVENT_TIME_CHANGED可以感知系统时制变化
   let subscriber: commonEventManager.CommonEventSubscriber; // 用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
   let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
     events: [commonEventManager.Support.COMMON_EVENT_TIME_CHANGED]
   };
   // 创建订阅者
   commonEventManager.createSubscriber(subscribeInfo)
     .then((commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
       console.info("CreateSubscriber");
       subscriber = commonEventSubscriber;
       commonEventManager.subscribe(subscriber, (err, data) => {
         if (err) {
           console.error(`Failed to subscribe common event. error code: ${err.code}, message: ${err.message}.`);
           return;
         }
         // 用于区分系统时间和系统时制变化
         if (data.data != undefined && data.data == '24HourChange') {
            console.info("The subscribed event has occurred."); // 系统时制变化时执行
          }
       })
     })
     .catch((err: BusinessError) => {
       console.error(`CreateSubscriber failed, code is ${err.code}, message is ${err.message}`);
     });
   ```

<!--Del-->
3. 设置使用本地数字。
   ```ts
   try {
     i18n.System.setUsingLocalDigit(true); // 使用本地数字
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.setUsingLocalDigit failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```

4. 设置时间显示格式为24小时制。
   ```ts
   try {
     i18n.System.set24HourClock(true); // 设置系统时制为24小时制
   } catch (error) {
     let err: BusinessError = error as BusinessError;
     console.error(`call System.set24HourClock failed, error code: ${err.code}, message: ${err.message}.`);
   }
   ```
<!--DelEnd-->
