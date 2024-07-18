# Delayed Copy and Paste Function of the Pasteboard

## When to Use

[The pasteboard service](../../reference/apis-basic-services-kit/js-apis-pasteboard.md) provides the capability of managing the pasteboard of the system to support the copy and paste functions of the system.

When the copy operation is performed repeatedly, redundant data is stored in the pasteboard cache, which increases the memory usage. To optimize the memory and support the paste of specified data types, the pasteboard provides the delayed copy and paste function.

When a user copies data in an application that uses the delayed paste technology, the real data is not immediately written into the cache of the pasteboard service, but is obtained from the application when the data needs to be pasted.

## Constraints

- This function is supported when the size of the pasteboard content is less than 128 MB.

## Description

| Name | Description                                                                  |
| -------- |----------------------------------------------------------------------|
| setUnifiedData(data: udc.UnifiedData): Promise\<void> | Writes data of the unified data type to the system pasteboard.
| setUnifiedDataSync(data: udc.UnifiedData): void | Writes data of the unified data type to the system pasteboard. This API is a synchronous API.
| getUnifiedData(): Promise\<udc.UnifiedData> | Reads data of a unified data type from the system pasteboard.|
| getUnifiedDataSync(): udc.UnifiedData | Reads data of the unified data type from the pasteboard. This API is a synchronous API.

## How to Develop

1. Import the **pasteboard**, **unifiedDataChannel**, and **uniformTypeDescriptor** modules.
   
   ```ts\
   import {unifiedDataChannel, uniformTypeDescriptor} from '@kit.ArkData';
   import {BusinessError, pasteboard} from '@kit.BasicServicesKit'
   ```

2. Construct a piece of PlainText data and write the function for obtaining the delay data.

   ```ts
   let plainTextData = new unifiedDataChannel.UnifiedData();
   globalThis.GetDelayPlainText = ((dataType:string) => {
     let plainText = new unifiedDataChannel.PlainText();
     plainText.details = {
       Key: 'delayPlaintext',
       Value: 'delayPlaintext',
     };
     plainText.textContent = 'delayTextContent';
     plainText.abstract = 'delayTextContent';
     plainTextData.addRecord(plainText);
     return plainTextData;
   });
   ``` 

3. Save a piece of PlainText data to the system pasteboard.

   ```ts
   globalThis.SetDelayPlainText = (() => {
     plainTextData.properties.shareOptions = unifiedDataChannel.ShareOptions.CROSS_APP;
     // For cross-application use, set this parameter to CROSS_APP. For intra-application use, set this parameter to IN_APP.
     plainTextData.properties.getDelayData = globalThis.GetDelayPlainText;
     pasteboard.getSystemPasteboard().setUnifiedData(plainTextData).then(()=>{
       // The data is successfully saved, which is a normal case.
     }).catch((error: BusinessError) => {
       // Error case
     });
   })
   ```

4. Read the text data from the system pasteboard.

   ```ts
   globalThis.GetPlainTextUnifiedData = (() => {
     pasteboard.getSystemPasteboard().getUnifiedData().then((data) => {
       let outputData = data;
       let records = outputData.getRecords();
       if (records[0].getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
         let record = records[0] as unifiedDataChannel.PlainText;
         globalThis.setLog('GetPlainText success, type:' + records[0].getType + ', details:' +
         JSON.stringify(record.details) + ', textContent:' + record.textContent + ', abstract:' + record.abstract);
       } else {
         globalThis.setLog('Get Plain Text Data No Success, Type is: ' + records[0].getType());
       }
     }).catch((error: BusinessError) => {
       // Error case
     })
   })
   ```
