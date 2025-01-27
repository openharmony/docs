# Using the Pasteboard to Copy and Paste

## When to Use

The [pasteboard](../../reference/apis-basic-services-kit/js-apis-pasteboard.md) allows you to copy and paste data.
For example, you can copy text content and paste it to Notepad, or copy a photo from Gallery and paste it to Files.

## Constraints

- Pasteboard content size < 128 MB.
- To ensure the accuracy of the pasteboard data, only one copy can be performed at a time.
- Since API version 12, [permission control](get-pastedata-permission-guidelines.md) is added to the pasteboard reading API to enhance user privacy protection.

## Using a Basic Data Object

Currently, the following basic data types are supported for copy and paste: text, HTML, URI, Want, and PixelMap. The data types supported by JS APIs are different from those supported by NDK APIs. You need to match the data types with the corresponding APIs during usage.

You are advised to use the solution discussed here to implement the copy and paste functions for new applications.

### Mapping between JS and NDK Data Types
| JS| NDK                                                                                                                                       |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| MIMETYPE_PIXELMAP : "pixelMap" | UDMF_META_OPENHARMONY_PIXEL_MAP : "openharmony.pixle-map" |
| MIMETYPE_TEXT_HTML : "text/html" | UDMF_META_HTML : "general.html" |
| MIMETYPE_TEXT_PLAIN : "text/plain" | UDMF_META_PLAIN_TEXT : "general.plain-text" |
| MIMETYPE_TEXT_URI : "text/uri" | UDMF_META_GENERAL_FILE_URI : "general.file-uri" |
| MIMETYPE_TEXT_WANT : "text/want" | Not supported.|

The JS data type corresponds to the pasteboard type. For details, see [ohos.pasteboard](../../reference/apis-basic-services-kit/js-apis-pasteboard.md).
The NDK data type corresponds to the unified data management framework. For details, see [UDMF](../../reference/apis-arkdata/_u_d_m_f.md).

### Available APIs

For details about the APIs, see [API Reference](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdata9).

After obtaining URI data using the **getData** API, use the [fs.copy](../../reference/apis-core-file-kit/js-apis-file-fs.md#fscopy11) API of File Manager to obtain the file.

| Name| Description                                                                                                                                       |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void | Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result.|
| setData(data: PasteData): Promise&lt;void&gt; | Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.|
| getData( callback: AsyncCallback&lt;PasteData&gt;): void | Reads a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.|
| getData(): Promise&lt;PasteData&gt; | Reads a **PasteData** object from the pasteboard. This API uses a promise to return the result.|   
| getDataSync(): PasteData | Reads a **PasteData** object from the pasteboard. This API is synchronous and cannot be called in the same thread as **SetData**.|

### Sample Code
```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  async onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): Promise<void> {
    // Obtain the system pasteboard object.
    let text = "test";
    // Create a pasteboard content object of the plain text type.
    let pasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, text);
    // Write data to the system pasteboard.
    let systemPasteboard = pasteboard.getSystemPasteboard();
    await systemPasteboard.setData(pasteData);
    // Read data from the system pasteboard.
    systemPasteboard.getData().then((data) => {
      let outputData = data;
      // Obtain the number of records from the pasteboard.
      let recordCount = outputData.getRecordCount();
      // Obtain the corresponding record information from the pasteboard data.
      for (let i = 0; i < recordCount; i++) {
        let record = outputData.getRecord(i).toPlainText();
        console.log('Get data success, record:' + record);
      }
    }).catch((error: BusinessError) => {
      // Error case
    })
  }
}
```

## Using a Unified Data Object

To facilitate data interactions between the pasteboard and other applications and reduce the workload of data type adaptation, the pasteboard supports a unified data object for copying and pasting. For details about the unified data object, see [Unified Data Channel](../../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md).

Currently, the following basic data types are supported for copy and paste: text and HTML. The data types supported by JS APIs are different from those supported by NDK APIs. You need to match the data types with the corresponding APIs during usage.

### Available APIs

For details about the APIs, see [API Reference](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddata12).

| Name| Description                                                                                                                                       |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| setUnifiedData(data: udc.UnifiedData): Promise\<void\> | Writes the data of a unified data object to the system pasteboard.
| setUnifiedDataSync(data: udc.UnifiedData): void | Writes the data of a unified data object to the system pasteboard. This API returns the result synchronously.                                                                                                                         |
| getUnifiedData(): Promise\<udc.UnifiedData\> | Reads the data of a unified data object from the system pasteboard.                                                                                                                         |
| getUnifiedDataSync(): udc.UnifiedData | Reads the data of a unified data object from the system pasteboard. This API returns the result synchronously.   

### Sample Code
```ts
import {unifiedDataChannel, uniformTypeDescriptor} from '@kit.ArkData';
import {BusinessError, pasteboard} from '@kit.BasicServicesKit';

// Construct a piece of PlainText data and write the function for obtaining the delay data.
let plainTextData = new unifiedDataChannel.UnifiedData();
let GetDelayPlainText = ((dataType:string) => {
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

// Save a piece of PlainText data to the system pasteboard.
let SetDelayPlainText = (() => {
  plainTextData.properties.shareOptions = unifiedDataChannel.ShareOptions.CROSS_APP;
  // For cross-application use, set this parameter to CROSS_APP. For intra-application use, set this parameter to IN_APP.
  plainTextData.properties.getDelayData = GetDelayPlainText;
  pasteboard.getSystemPasteboard().setUnifiedData(plainTextData).then(()=>{
    // The data is successfully saved, which is a normal case.
  }).catch((error: BusinessError) => {
    // Error case
  });
})

// Read the text data from the system pasteboard.
let GetPlainTextUnifiedData = (() => {
  pasteboard.getSystemPasteboard().getUnifiedData().then((data) => {
    let outputData = data;
    let records = outputData.getRecords();
    if (records[0].getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
      let record = records[0] as unifiedDataChannel.PlainText;
      console.log('GetPlainText success, type:' + records[0].getType + ', details:' +
      JSON.stringify(record.details) + ', textContent:' + record.textContent + ', abstract:' + record.abstract);
    } else {
      console.log('Get Plain Text Data No Success, Type is: ' + records[0].getType());
    }
  }).catch((error: BusinessError) => {
    // Error case
  })
})
```                                                                                              

<!--RP1-->
<!--RP1End-->
