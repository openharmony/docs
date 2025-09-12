# 取消动态订阅公共事件

<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

## 场景介绍

动态订阅者完成业务需求后，应主动取消订阅。通过调用[unsubscribe()](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagerunsubscribe)方法，取消订阅事件。


## 接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| [unsubscribe](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagerunsubscribe)(subscriber:&nbsp;CommonEventSubscriber,&nbsp;callback?:&nbsp;AsyncCallback<void\>) | 取消订阅公共事件。 |


## 开发步骤

1. 导入模块。
   
   ```ts
   import { BusinessError, commonEventManager } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';

   const TAG: string = 'ProcessModel';
   const DOMAIN_NUMBER: number = 0xFF00;
   ```

2. 根据[动态订阅公共事件](common-event-subscription.md)章节的步骤来订阅某个事件。

3. 调用CommonEvent中的[unsubscribe()](../../reference/apis-basic-services-kit/js-apis-commonEventManager.md#commoneventmanagerunsubscribe)方法取消订阅某事件。
   
   ```ts
   // subscriber为订阅事件时创建的订阅者对象
   if (subscriber !== null) {
     commonEventManager.unsubscribe(subscriber, (err: BusinessError) => {
       if (err) {
         hilog.error(DOMAIN_NUMBER, TAG, `Failed to unsubscribe. code is ${err.code}, message is ${err.message}`);
       } else {
         hilog.info(DOMAIN_NUMBER, TAG, `Succeeded in unsubscribing.`);
         subscriber = null;
       }
     })
   }
   ```
