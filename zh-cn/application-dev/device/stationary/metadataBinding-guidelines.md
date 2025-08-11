# 记忆链接开发指导
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--SE: @zou_ye-->
<!--TSE: @judan-->

## 概述

MetadataBinding（记忆链接）指由第三方应用提供[鸿蒙App Linking链接](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/applinking-introduction)，系统将当前用户浏览的内容与鸿蒙App Linking链接进行关联并保存的功能。

详细的接口介绍请参考[MetadataBinding接口](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md)。

## 场景介绍

第三方应用可使用记忆链接功能，将鸿蒙App Linking链接映射到调用接口的系统应用或服务。例如，用户在【电商应用】中浏览某个商品时，截图保存了该商品的图片，系统将记录图片与【电商应用】提供的鸿蒙App Linking链接的映射关系。当用户再次浏览该图片时，系统会提醒用户是否需要返回【电商应用】查看商品详情。

## 接口说明

| 接口名                                                       | 描述                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| [submitMetadata](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingsubmitmetadata)(metadata: string): void; | 第三方应用将待编码的鸿蒙App Linking链接传递给多模态融合感知服务，该服务决定适当时机将内容传递给调用编码接口的系统应用。 |
| [on](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingonoperationsubmitmetadata)(type: 'operationSubmitMetadata', bundleName: string, callback: Callback&lt;number&gt;): void; | 订阅系统事件以获取编码内容，应用注册回调，事件发生时回传编码内容。|
| [off](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingoffoperationsubmitmetadata)(type: 'operationSubmitMetadata', bundleName: string, callback?: Callback&lt;number&gt;): void; | 取消订阅系统获取编码内容的事件。取消注册回调接口。|
  
## 约束与限制

  - 鸿蒙App Linking链接的最大字节数为99。

## 开发步骤

1. 导入模块。

   ```ts
   import { metadataBinding } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Callback } from '@ohos.base';
   ```

2. 定义记忆服务回调，函数接收回传编码的内容。

   ```
   let callback : Callback<number> = (event: number) => {};
   ```

3. 订阅记忆服务。

   ```
   let bundleName: string = '';
   try {
      metadataBinding.on('operationSubmitMetadata', bundleName, this.callback);  
      console.info("on succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Register event error and err code is " + error.code);
   }
   ```

4. 提供鸿蒙App Linking链接。

   ```
    let metadata: string = "";
    try {
        metadataBinding.submitMetadata(metadata);
    } catch (err) {
        let error = err as BusinessError;
        console.error("Submit metadata error and err code is " + error.code);
    }
   ```

5. 取消订阅记忆服务。

   ```
   try {
      metadataBinding.off('operationSubmitMetadata', bundleName, this.callback);
      console.info("off succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Unregister event error and err code is " + error.code);
   }
   ```