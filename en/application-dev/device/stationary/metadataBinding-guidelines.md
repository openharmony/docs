# Metadata Binding Development

<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @codexu62-->
<!--Designer: @yuxiaoyang-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=0552be7434d9a0bd203232639bf8b2f95bface50 translatedAt=2026-07-29T01:37:32.844Z pushedAt=2026-07-29T02:11:58.416Z -->

## Overview

Metadata binding allows the system to map the content browsed by the current user to the [App Linking link](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/applinking-introduction) provided by a third-party application and save their mapping.

For detailed API introduction, refer to [@ohos.multimodalAwareness.metadataBinding (Metadata Binding)](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md).

## Overview

Third-party applications can use the metadata binding function to map the App Linking link to the desired content for easy access at a later time. For example, when a user is browsing a product in an e-commerce app and takes a screenshot of that product to save it, the system will record the mapping between the screenshot and the App Linking link provided by the e-commerce app. When the user views the screenshot again, the system will remind the user of whether to return to the e-commerce app to view the product details.

## Demonstration Example

![Metadatabinding](figures/metadatabinding.gif)

## Available APIs

  - The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.

  - This module supports the metadata binding function.

| Name                                                       | Description                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| [submitMetadata](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingsubmitmetadata)(metadata: string): void; | Passes the HarmonyOS App Linking link to be encoded from a third-party app to the multimodal awareness service, which determines the appropriate time to deliver the content to the system app that calls the encoding API. |
| [on](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingonoperationsubmitmetadata)(type: 'operationSubmitMetadata', bundleName: string, callback: Callback&lt;number&gt;): void; | Subscribes to system events to obtain encoded content. The app registers a callback, and the encoded content is returned when the event occurs. |
| [off](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingoffoperationsubmitmetadata)(type: 'operationSubmitMetadata', bundleName: string, callback?: Callback&lt;number&gt;): void; | Unsubscribes from system events for obtaining encoded content. This API cancels the registered callback. |

## Constraints

  - Encoding fails if a HarmonyOS App Linking URL exceeds 128 bytes, and a screenshot is taken to save the original image.

## How to Develop

1. Import the related modules.

   <!-- @[import_the_metadata_binding_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/MetadataBinding/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { metadataBinding } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Callback } from '@kit.BasicServicesKit';
   ```

2. Define the callback used to return the encoded metadata and the bundle name.   

   <!-- @[metadata_binding_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/MetadataBinding/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   let callback : Callback<number> = (event: number) => {};
   let bundleName: string = '';
   ```

3. Subscribe to the metadata binding service.

   <!-- @[metadata_binding_subscribe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/MetadataBinding/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   try {
     metadataBinding.on('operationSubmitMetadata', bundleName, callback);
     console.info('on succeeded');
     // ...
   } catch (err) {
     let error = err as BusinessError;
     console.error('Register event error and err code is ' + error.code);
     // ...
   }
   ```

4. Provide the App Linking link.

   <!-- @[metadata_binding_submit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/MetadataBinding/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let metadata: string = '';
   try {
     metadataBinding.submitMetadata(metadata);
     // ...
   } catch (err) {
     let error = err as BusinessError;
     console.error('Submit metadata error and err code is ' + error.code);
     // ...
   }
   ```

5. Unsubscribe from the metadata binding service.

   <!-- @[metadata_binding_unsubscribe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Stationary/MetadataBinding/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   try {
     metadataBinding.off('operationSubmitMetadata', bundleName, callback);
     console.info('off succeeded');
     // ...
   } catch (err) {
     let error = err as BusinessError;
     console.error('Unregister event error and err code is ' + error.code);
     // ...
   }
   ```