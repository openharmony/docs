# Using the Pasteboard to Copy and Paste
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @guo867-->
<!--Tester: @maxiaorong-->
<!--Adviser: @HelloCrease-->

## When to Use

The [pasteboard](../../reference/apis-basic-services-kit/js-apis-pasteboard.md) allows you to copy and paste data. For example, you can copy text content and paste it to Notepad, or copy a photo from Gallery and paste it to Files.

## Constraints

- The pasteboard content, including system service metadata and application settings, has a maximum size of 128 MB by default. For PCs/2-in-1 devices, the maximum size can be changed through system settings, with a valid range from 128 MB to 2 GB.
- To ensure the accuracy of the pasteboard data, only one copy can be performed at a time.
- In API version 12 and later, [permission control](get-pastedata-permission-guidelines.md) is added to the pasteboard reading API to enhance user privacy protection.

## Using a Basic Data Types

Currently, the following basic data types are supported for copy and paste: text, HTML, URI, Want, and pixel map. The data types supported by ArkTS APIs are different from those supported by NDK APIs. You need to match the data types with the corresponding APIs during usage.

You are advised to use the solution discussed here to implement the copy-and-paste function for new applications.

### Mapping between ArkTS and NDK Data Types
| ArkTS| NDK                                                                                                                                       |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| MIMETYPE_PIXELMAP : "pixelMap" | UDMF_META_OPENHARMONY_PIXEL_MAP : "openharmony.pixel-map" |
| MIMETYPE_TEXT_HTML : "text/html" | UDMF_META_HTML : "general.html" |
| MIMETYPE_TEXT_PLAIN : "text/plain" | UDMF_META_PLAIN_TEXT : "general.plain-text" |
| MIMETYPE_TEXT_URI : "text/uri" | UDMF_META_GENERAL_FILE_URI : "general.file-uri" |
| MIMETYPE_TEXT_WANT : "text/want" | Not supported.|

The ArkTS data type corresponds to the pasteboard type. For details, see [ohos.pasteboard](../../reference/apis-basic-services-kit/js-apis-pasteboard.md). The NDK data type corresponds to the unified data management framework. For details, see [UDMF](../../reference/apis-arkdata/capi-udmf.md).

### Available APIs

For details about the APIs, see [API Reference](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdata9).

After obtaining URI data using the **getData** API, use the [fs.copy](../../reference/apis-core-file-kit/js-apis-file-fs.md#fscopy11) API of File Manager to obtain the file.

| Name| Description                                                                                                                                       |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void | Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result.|
| setData(data: PasteData): Promise&lt;void&gt; | Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.|
| getData( callback: AsyncCallback&lt;PasteData&gt;): void | Reads a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.|
| getData(): Promise&lt;PasteData&gt; | Reads a **PasteData** object from the pasteboard. This API uses a promise to return the result.|
| getDataSync(): PasteData | Reads a **PasteData** object from the pasteboard. This API returns the result synchronously and cannot be called in the same thread as **SetData**.|

### Example
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
        console.info('Get data success, record:' + record);
      }
    }).catch((error: BusinessError) => {
      // Error case
    })
  }
}
```

## Using a Unified Data Object

To facilitate data interactions between the pasteboard and other applications and reduce the workload of data type adaptation, the pasteboard supports a unified data object for copying and pasting. For details about the unified data object, see [Unified Data Channel](../../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md).

Currently, the following basic data types are supported for copy and paste: text and HTML. The data types supported by ArkTS APIs are different from those supported by NDK APIs. You need to match the data types with the corresponding APIs during usage.

### Available APIs

For details about the APIs, see [API Reference](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddata12).

| Name| Description                                                                                                                                       |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| setUnifiedData(data: udc.UnifiedData): Promise\<void\> | Writes the data of a unified data object to the system pasteboard. |
| setUnifiedDataSync(data: udc.UnifiedData): void | Writes the data of a unified data object to the system pasteboard. This API returns the result synchronously.                                                                                                                         |
| getUnifiedData(): Promise\<udc.UnifiedData\> | Reads the data of a unified data object from the system pasteboard.                                                                                                                         |
| getUnifiedDataSync(): udc.UnifiedData | Reads the data of a unified data object from the system pasteboard. This API returns the result synchronously. |

### Example
```ts
import {BusinessError, pasteboard} from '@kit.BasicServicesKit';
import { unifiedDataChannel, uniformDataStruct, uniformTypeDescriptor } from '@kit.ArkData';

// Construct a PlainText data object.
let plainText : uniformDataStruct.PlainText = {
    uniformDataType: uniformTypeDescriptor.UniformDataType.PLAIN_TEXT,
    textContent : 'PLAINTEXT_CONTENT',
    abstract : 'PLAINTEXT_ABSTRACT',
}
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainText);
let data = new unifiedDataChannel.UnifiedData();
data.addRecord(record);

// Save a piece of PlainText data to the system pasteboard.
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setUnifiedData(data).then((data: void) => {
    console.info('Succeeded in setting UnifiedData.');
    // The data is successfully saved, which is a normal case.
}).catch((err: BusinessError) => {
    console.error('Failed to set UnifiedData. Cause: ' + err.message);
    // Error case
});

// Read the text data from the system pasteboard.
systemPasteboard.getUnifiedData().then((data) => {
    let records: Array<unifiedDataChannel.UnifiedRecord> = data.getRecords();
    for (let j = 0; j < records.length; j++) {
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
            let text = records[j].getValue() as uniformDataStruct.PlainText;
            console.info(`${j + 1}.${text.textContent}`);
        }
    }
}).catch((err: BusinessError) => {
    console.error('Failed to get UnifiedData. Cause: ' + err.message);
    // Error case
});
```

<!--RP1-->
<!--RP1End-->
