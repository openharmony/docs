# Metadata Binding Development

## Overview

Metadata binding allows the system to map the content browsed by the current user to the [App Linking link](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/applinking-introduction) provided by a third-party application and save their mapping.

For details about the APIs, see the [MetadataBinding API Reference](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md).

## When to Use

Third-party applications can use the metadata binding function to map the App Linking link to the desired content for easy access at a later time. For example, when a user is browsing a product in an e-commerce app and takes a screenshot of that product to save it, the system will record the mapping between the screenshot and the App Linking link provided by the e-commerce app. When the user views the screenshot again, the system will remind the user of whether to return to the e-commerce app to view the product details.

## Available APIs

| Name                                                      | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| [submitMetadata](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingsubmitmetadata)(metadata: string): void; | Passes the App Linking link mapped to the encoded metadata to Multimodal Awareness Kit, which then forwards the link to the system application that calls the encoding API at an appropriate time.|
| [on](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingonoperationsubmitmetadata)(type: 'operationSubmitMetadata', bundleName: string, callback: Callback&lt;number&gt;): void; | Subscribes to system events that are used to obtain the encoded metadata. The application needs to register a callback to return the encoded metadata when the registered system event occurs.|
| [off](../../reference/apis-multimodalawareness-kit/js-apis-awareness-metadataBinding.md#metadatabindingoffoperationsubmitmetadata)(type: 'operationSubmitMetadata', bundleName: string, callback?: Callback&lt;number&gt;): void; | Unsubscribes from system events that are used to obtain the encoded metadata. The respective callback will be unregistered.|
  
## Constraints

  - The maximum length of an App Linking link is 99 bytes.

## How to Develop

1. Import the related modules.

   ```ts
   import { metadataBinding } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Callback } from '@ohos.base';
   ```

2. Define the callback used to return the encoded metadata.

   ```
   let callback : Callback<number> = (event: number) => {};
   ```

3. Subscribe to system events that are used to obtain the encoded metadata.

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

4. Configure the App Linking link.

   ```
    let metadata: string = "";
    try {
        metadataBinding.submitMetadata(metadata);
    } catch (err) {
        let error = err as BusinessError;
        console.error("Submit metadata error and err code is " + error.code);
    }
   ```

5. Unsubscribe from system events that are used to obtain the encoded metadata.

   ```
   try {
      metadataBinding.off('operationSubmitMetadata', bundleName, this.callback);
      console.info("off succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Unregister event error and err code is " + error.code);
   }
   ```
