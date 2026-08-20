# @ohos.pasteboard (Pasteboard)

<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @zhusiyuan2-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=f6b2fdef05ea993cf15e154ceff415f35e69ba1a translatedAt=2026-08-19T10:01:48.935Z pushedAt=2026-08-19T12:01:34.679Z -->

This module provides the capabilities of managing the system pasteboard to support the copy and paste functions. You can use the APIs of this module to operate pasteboard content of the plain text, HTML, URI, Want, pixel map, and other types.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Overview

This module provides APIs for system pasteboard management.

## Modules to Import

```ts
import { pasteboard } from '@kit.BasicServicesKit';
```

## Constants

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Value| Description          |
| ---- | ---- |-----|-------------|
| MAX_RECORD_NUM<sup>7+</sup> | number | - | Maximum number of records in a **PasteData** object. In versions earlier than API version 10, the value is 512, indicating that no more records can be added once the number of records reaches 512.<br>Since API version 10, no limit is placed on the number of records in a **PasteData** object.|
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | 'text/html'  | MIME type of the HTML content.|
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | 'text/want'  | MIME type of the Want content.|
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | 'text/plain' | MIME type of the plain text content.|
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | 'text/uri'   | MIME type of the URI content.|
| MIMETYPE_PIXELMAP<sup>9+</sup> | string | 'pixelMap'   | MIME type of the pixel map.|

## ValueType<sup>9+</sup>

type ValueType = string | image.PixelMap | Want | ArrayBuffer

Enumerates the value types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Type| Description|
| -------- | -------- |
| string | The value is of the string type.|
| image.PixelMap | The value is of the [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) type.|
| Want | The value is of the [Want](../apis-ability-kit/js-apis-app-ability-want.md) type.|
| ArrayBuffer | The value is of the **ArrayBuffer** type.|

## pasteboard.createData<sup>9+</sup>

createData(mimeType: string, value: ValueType): PasteData

Creates a **PasteData** object of the specified type and creates a **PasteData** instance based on the input MIME type and data content. After this API is called, the system verifies the MIME type, encapsulates the data content, and returns a **PasteData** object that can be used in subsequent pasteboard operations. The value of **mimeType** can contain a maximum of 1024 bytes, and the value type must match the MIME type.

**Use scenarios**: Use this method when you need to save data of a single type (such as plain text, HTML, or images) to the pasteboard.

**Parameter selection suggestions**: Use the defined constant types (for example, **MIMETYPE_TEXT_PLAIN**) for **mimeType**. If you need to pass data in a custom format, you can use a custom MIME type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description                                                                                                    |
| -------- | -------- | -------- |--------------------------------------------------------------------------------------------------------|
| mimeType | string | Yes | MIME type of custom data. The value can be a predefined MIME type listed in [Constants](#constants), including HTML, WANT, plain text, URI, and pixel map, or a custom MIME type. The value of **mimeType** cannot exceed 1024 bytes. |
| value | [ValueType](#valuetype9) | Yes| Content of custom data. You are advised to select a proper data type based on the actual scenario. Using a large data object will affect the app's copy and paste performance and memory usage. For the **ArrayBuffer** type, you are advised to set a proper data size. For the **PixelMap** type, you are advised to release objects that are no longer used in a timely manner.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) |  **PasteData** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example 1**

  ```ts
  // Create an ArrayBuffer data object.
  let dataXml = new ArrayBuffer(256);
  // Create a PasteData object of the custom MIME type.
  let pasteData: pasteboard.PasteData = pasteboard.createData('app/xml', dataXml);
  ```

**Example 2**

  ```ts
  // Define the plain text content.
  let dataText = 'hello';
  // Create a PasteData object of the plain text type.
  let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, dataText);
  ```

## pasteboard.createData<sup>14+</sup>

createData(data: Record&lt;string, ValueType&gt;): PasteData

Creates a **PasteData** object that contains multiple types of data. Multiple MIME data records can be created at a time. After this API is called, the system parses multiple key-value pairs in the record and creates multiple **PasteDataRecord** records. The first MIME type is used as the default type. Data of non-default types is read using [getData](#getdata14).

**Use scenarios**: When an application needs to copy multiple types of data (such as text, URI, and HTML) to the pasteboard at the same time, this API can be used to create a **PasteData** object that contains data of multiple MIME types.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description |
| -------- |------------------------------------------------| -------- |-----------|
| data | [Record](../../quick-start/arkts-language-guide-collection-types.md#recordkv-type)&lt;string, [ValueType](#valuetype9)&gt; | Yes | The key of **Record** can be the MIME type corresponding to the pasteboard data, including HTML, WANT, plain text, URI, and PixelMap defined in [Constants](#constants). Alternatively, the key could be a custom MIME type, whose parameter, the length of **mimeType**, cannot exceed 1024 bytes.<br/>The value of **Record** is the data corresponding to the MIME type specified in the key.<br/>The first MIME type specified by the key-value in **Record** is used as the default MIME type of the first **PasteDataRecord** in the **PasteData** object. Data of non-default types can be read only by using the [getData](#getdata14) API. |

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) |  **PasteData** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example 1**

```ts
// Create a PasteData object that contains multiple MIME types of data.
let pasteData: pasteboard.PasteData = pasteboard.createData({
    'text/plain': 'hello',
    'app/xml': new ArrayBuffer(256),
});
```

**Example 2**

```ts
// Create a Record object to store multiple types of data.
let record: Record<string, pasteboard.ValueType> = {};
// Add plain text data.
record[pasteboard.MIMETYPE_TEXT_PLAIN] = 'hello';
// Add URI data.
record[pasteboard.MIMETYPE_TEXT_URI] = 'dataability:///com.example.myapplication1/user.txt';
// Create a PasteData object.
let pasteData: pasteboard.PasteData = pasteboard.createData(record);
```

## pasteboard.createRecord<sup>9+</sup>

createRecord(mimeType: string, value: ValueType): PasteDataRecord

Creates a data record of the specified type and encapsulates the data record into a **PasteDataRecord** object. After this API is called, the system encapsulates data of the specified MIME type and returns records that can be added to the **PasteData** object. The value of **mimeType** contains a maximum of 1024 bytes. The value type must match the MIME type. For example, if the MIME type is **MIMETYPE_TEXT_PLAIN**, the value must be of the string type. The parameter cannot be empty.

**API called in pairs**

- The created record takes effect only after being added to the [PasteData](#pastedata) object using [addRecord](#addrecord7).

- The typical process is as follows: Use [createData](#pasteboardcreatedata9) to create a **PasteData** object, use **createRecord** to create a record, and then use **addRecord** to add the record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description               |
| -------- | -------- | -------- |-------------------|
| mimeType | string | Yes | MIME type of custom data. The value can be a predefined MIME type listed in [Constants](#constants), including HTML, WANT, plain text, URI, and pixel map, or a custom MIME type. The value of **mimeType** cannot exceed 1024 bytes. |
| value | [ValueType](#valuetype9) | Yes| Content of the specified type. You are advised to select a proper data type based on the actual scenario. Using a large data object will affect the pasteboard performance and memory usage. For the **ArrayBuffer** type, you are advised to set a proper data size. For the **PixelMap** type, you are advised to release objects that are no longer used in a timely manner.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | A new paste data record of a specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types;  3. Parameter verification failed. |

**Example 1**

  ```ts
  // Create an ArrayBuffer data object.
  let dataXml = new ArrayBuffer(256);
  // Create a data record of a custom MIME type.
  let pasteDataRecord: pasteboard.PasteDataRecord = pasteboard.createRecord('app/xml', dataXml);
  ```

**Example 2**

  ```ts
  // Create a PasteData object of the plain text type.
  let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
  // Create an URI data record.
  let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'file://com.example.myapplication1/data/storage/el2/base/files/file.txt');
  // Replace the first record in the pasteboard.
  pasteData.replaceRecord(0, record);
  ```

## pasteboard.getSystemPasteboard

getSystemPasteboard(): SystemPasteboard

Obtains a **SystemPasteboard** object and returns a singleton instance of the pasteboard service. After this API is called, the **SystemPasteboard** object can be used to access the read, write, and listening functions of the pasteboard. The same instance is returned each time this API is called. Before calling this API, ensure that the pasteboard service is running properly.

**Use scenarios**: Before performing any read or write operation on the pasteboard, you need to call this API to obtain the **SystemPasteboard** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [SystemPasteboard](#systempasteboard) | **SystemPasteboard** object.|

**Example**

```ts
// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
```

## ShareOption<sup>9+</sup>

Enumerates the pasteable ranges of pasteboard data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name                              | Value | Description                                                                                 |
| ---------------------------------- | --- | ------------------------------------------------------------------------------------- |
| INAPP                              | 0   | Only intra-application pasting is allowed.                                                             |
| LOCALDEVICE                        | 1   | Paste is allowed in any application.<!--RP1--><!--RP1End-->  |
| CROSSDEVICE<sup>(deprecated)</sup> | 2   | Paste is allowed in any application across devices.<br>This API is deprecated since API version 12 without any alternative API or method. <!--RP2--><!--RP2End-->|

## pasteboard.createHtmlData<sup>(deprecated)</sup>

createHtmlData(htmlText: string): PasteData

Creates a **PasteData** object of the HTML type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML text. The value must comply with the standard HTML format.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData: pasteboard.PasteData = pasteboard.createHtmlData(html);
```

## pasteboard.createWantData<sup>(deprecated)</sup>

createWantData(want: Want): PasteData

Creates a **PasteData** object of the Want type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData: pasteboard.PasteData = pasteboard.createWantData(object);
```

## pasteboard.createPlainTextData<sup>(deprecated)</sup>

createPlainTextData(text: string): PasteData

Creates a **PasteData** object of the plain text type.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Plain text.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
```

## pasteboard.createUriData<sup>(deprecated)</sup>

createUriData(uri: string): PasteData

Creates a **PasteData** object of the URI type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI text. The value must comply with the standard URI format.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
```

## pasteboard.createHtmlTextRecord<sup>(deprecated)</sup>

createHtmlTextRecord(htmlText: string): PasteDataRecord

Creates a **PasteDataRecord** object of the HTML text type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML text. The value must comply with the standard HTML format.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | **PasteDataRecord** object of the HTML text type.|

**Example**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createHtmlTextRecord(html);
```

## pasteboard.createWantRecord<sup>(deprecated)</sup>

createWantRecord(want: Want): PasteDataRecord

Creates a **PasteDataRecord** object of the Want type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the Want type.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let record: pasteboard.PasteDataRecord = pasteboard.createWantRecord(object);
```

## pasteboard.createPlainTextRecord<sup>(deprecated)</sup>

createPlainTextRecord(text: string): PasteDataRecord

Creates a **PasteDataRecord** object of the plain text type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Plain text.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the plain text type.|

**Example**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createPlainTextRecord('hello');
```

## pasteboard.createUriRecord<sup>(deprecated)</sup>

createUriRecord(uri: string): PasteDataRecord

Creates a **PasteDataRecord** object of the URI type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI text. The value must comply with the standard URI format.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the URI type.|

**Example**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
```

## PasteDataProperty<sup>7+</sup>

Defines the properties of all data records on the pasteboard, including the timestamp, data type, pasteable range, and additional data. The defined properties can be applied to the pasteboard only with the [setProperty](#setproperty9) method.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- |-------------------------------|
| additions | Record<string, object> | No| No| Additional property data. It does not allow for dynamic adding of properties. Properties can be added only by re-assigning values. This parameter is left empty by default. For details, see the example of **setProperty**.|
| mimeTypes | Array&lt;string&gt; | Yes| No| Non-repeating data types of the data records on the pasteboard.|
| tag | string | No| No| Custom tag. This parameter is left empty by default.|
| timestamp | number | Yes| No| Timestamp when data is written to the pasteboard (unit: nanoseconds since the device is powered on).|
| localOnly | boolean | No| No| Whether the pasteboard content is for local access only. The value **true** indicates that content is for local access only, and the value **false** indicates that cross-device data transfer is allowed. The default value is **false**. The value will be overwritten by the value of the **shareOption** attribute. You are advised to use the [ShareOption](#shareoption9) attribute instead.|
| shareOption<sup>9+</sup> | [ShareOption](#shareoption9) | No| No| Pasteable ranges of pasteboard data. The default value is **CROSSDEVICE**. This parameter is mutually exclusive with **localOnly**. Setting **shareOption** affects the actual value of **localOnly**.|

## FileConflictOptions<sup>15+</sup>

Defines options for file copy conflicts.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name     | Value  | Description                                                        |
| --------- | ---- | ------------------------------------------------------------ |
| OVERWRITE | 0    | Overwrites the file with the same name in the destination path.                                |
| SKIP      | 1    | Skips the file with the same name in the destination path. If **SKIP** is set, the copied data of the skipped file is not pasted to the application.|

## ProgressIndicator<sup>15+</sup>

Enumerates the progress indicator options. You can use the default progress indicator as required.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name   | Value  | Description                    |
| ------- | ---- | ------------------------ |
| NONE    | 0    | The default progress indicator is not used.|
| DEFAULT | 1    | The default progress indicator is used.  |

## ProgressInfo<sup>15+</sup>

Defines the progress information. This information is reported only when [ProgressIndicator](#progressindicator15) is set to **NONE**.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name    | Type  | Read-Only| Optional| Description                                                      |
| -------- | ------ | ---- | ---- | ---------------------------------------------------------- |
| progress | number | No  | No  | If the progress indicator provided by the system is not used, the system reports the progress percentage of the copy-and-paste task.|

## ProgressListener<sup>15+</sup>

type ProgressListener = (progress: ProgressInfo) => void

Defines a listener for progress data changes. If the default progress indicator is not used, you can set this API to obtain the paste progress.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| progress | [ProgressInfo](#progressinfo15) | Yes  | Defines the progress information. This information is reported only when [ProgressIndicator](#progressindicator15) is set to **NONE**.|

## ProgressSignal<sup>15+</sup>

Defines a function for canceling the progress indicator. The task can be canceled during pasting. The pasteboard progress indicator is valid only when [ProgressIndicator](#progressindicator15) is set to **NONE**.

**System capability**: SystemCapability.MiscServices.Pasteboard

### cancel<sup>15+</sup>

cancel(): void

Cancels an ongoing copy-and-paste task.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Example**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';
@Entry
@Component
struct PasteboardTest {
 build() {
   RelativeContainer() {
     Column() {
       Column() {
         Button("Copy txt")
           .onClick(async ()=>{
              let text = "test";
              let pasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, text);
              let systemPasteboard = pasteboard.getSystemPasteboard();
              await systemPasteboard.setData(pasteData);
              let signal = new pasteboard.ProgressSignal;
              let progressListenerInfo = (progress: pasteboard.ProgressInfo) => {
                console.info('progressListener success, progress:' + progress.progress);
                signal.cancel();
              };
              let destPath: string = '/data/storage/el2/base/files/';
              let destUri : string = fileUri.getUriFromPath(destPath);
              let params: pasteboard.GetDataParams = {
                destUri: destUri,
                fileConflictOptions: pasteboard.FileConflictOptions.OVERWRITE,
                progressIndicator: pasteboard.ProgressIndicator.DEFAULT,
                progressListener: progressListenerInfo,
              };
              systemPasteboard.getDataWithProgress(params).then((pasteData: pasteboard.PasteData) => {
                console.info('getDataWithProgress success');
              }).catch((err: BusinessError) => {
                console.error('Failed to get PasteData. Cause: ' + err.message);
              })
          })
        }
      }
    }
  }
}
```

## GetDataParams<sup>15+</sup>

Obtains parameters when an application uses the file copy capability provided by the pasteboard, including the destination path, file conflict options, and progress indicator types. Before calling this API, ensure that no other copy or paste operation is in progress.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name               | Type                                         | Read-Only| Optional| Description                                                        |
| ------------------- | -------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| destUri             | string                                        | No | Yes | URI of the destination directory for the file copied. If file processing is not supported, this parameter is not required. If the application involves complex file processing policies or needs to distinguish file multipathing storage, you are advised not to set this parameter but let the application copy files by itself. This parameter is left empty by default. |
| fileConflictOptions | [FileConflictOptions](#fileconflictoptions15) | No| Yes| Options used to resolve file copy conflicts. Set this parameter to **OVERWRITE** when the latest file content must be used in the destination URI. Set this parameter to **SKIP** when the original file in the destination URI needs to be retained to prevent accidental overwriting. The default value is **OVERWRITE**.|
| progressIndicator   | [ProgressIndicator](#progressindicator15)     | No| No| Progress indicator options. You can use the default progress indicator as required. If this parameter is set to **DEFAULT**, the default system progress indicator is used. If this parameter is set to **NONE**, the app progress indicator is used. Only in the second case, the **progressListener** and **progressSignal** parameters are valid.|
| progressListener    | [ProgressListener](#progresslistener15)       | No| Yes| Listener for progress data changes, which is used to obtain the pasting progress. This parameter is valid only when **progressIndicator** is set to **NONE**. When **progressIndicator** is set to **DEFAULT**, this parameter is invalid. By default, this parameter is left empty (the progress is not listened to).|
| progressSignal      | [ProgressSignal](#progresssignal15)           | No | Yes | Function for canceling the paste task. This parameter is valid only when [ProgressIndicator](#progressindicator15) is set to **NONE**. This parameter is left empty by default. |

## PasteDataRecord<sup>7+</sup>

Provides **PasteDataRecord** APIs. A **PasteDataRecord** is an abstract definition of the content on the pasteboard. The pasteboard content consists of one or more plain text, HTML, URI, or Want records. The default data type of a **PasteDataRecord** cannot be changed after the record is created. You must specify the correct default data type when creating a **PasteDataRecord**. To update the attributes of a **PasteDataRecord**, use [addEntry](#addentry14).

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| htmlText| string | No | No | HTML text. The value must comply with the standard HTML format. Modifications to this attribute are invalid. To update the attribute value, use [addEntry](#addentry14). |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | No | No | Want content. Modifications to this attribute are invalid. To update the attribute value, use [addEntry](#addentry14). |
| mimeType | string | No | No | Default data type. Modifications to this attribute are invalid. |
| plainText | string | No | No | Plain text content. Modifications to this attribute are invalid. To update the attribute value, use [addEntry](#addentry14).|
| uri | string | No | No | URI text. The value must comply with the standard URI format. Modifications to this attribute are invalid. To update the attribute value, use [addEntry](#addentry14). |
| pixelMap<sup>9+</sup> | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | No | No | Pixel map. Modifications to this attribute are invalid. To update the attribute value, use [addEntry](#addentry14). |
| data<sup>9+</sup> | Record<string, ArrayBuffer> | No | No | Content of custom data. Modifications to this attribute are invalid. |

### toPlainText<sup>9+</sup>

toPlainText(): string

Forcibly converts HTML, plain, and URI content in **PasteDataRecord** to the plain text. If **PasteDataRecord** contains other data types (such as PixelMap and Want), the conversion result is an empty string.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Plain text.|

**Example**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_HTML, '<html>hello</html>');
let text: string = record.toPlainText();
console.info(`Succeeded in converting to text. Text: ${text}`);
```

### addEntry<sup>14+</sup>

addEntry(type: string, value: ValueType): void

Adds custom data of an extra type to **PasteDataRecord**. The MIME type added using this method is not the default type of **Record**. You can only use the [getData](#getdata14) API to read the corresponding data.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name  | Type| Mandatory| Description               |
|-------| -------- | -------- |-------------------|
| type  | string | Yes | MIME type of custom data. The value can be a predefined MIME type listed in [Constants](#constants), including HTML, WANT, plain text, URI, and pixel map, or a custom MIME type. The value of **mimeType** cannot exceed 1024 bytes.  |
| value | [ValueType](#valuetype9) | Yes| Content of custom data.         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example**

```ts
// Build an HTML string.
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
// Create an URI data record.
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
// Add plain text data.
record.addEntry(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
// Add HTML data.
record.addEntry(pasteboard.MIMETYPE_TEXT_HTML, html);
```

### getValidTypes<sup>14+</sup>

getValidTypes(types: Array&lt;string&gt;): Array&lt;string&gt;

Obtains the intersection of the input MIME type and the MIME type of the pasteboard data.

**Use scenarios**: Before pasting, check whether the pasteboard data formats include the formats supported by the app. For example, if the app supports only plain text and HTML, you can call this API to check whether the pasteboard data formats include these formats and determine whether to perform the paste operation based on the returned result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name  | Type| Mandatory| Description            |
|-------| -------- | -------- |----------------|
| types | Array&lt;string&gt; | Yes| MIME types. The value can be compared with the MIME types of the pasteboard data, and the matched MIME types are returned.|

**Return value**

| Type| Description                                  |
| -------- |--------------------------------------|
| Array&lt;string&gt; | Intersection of the input MIME type and the MIME type of the pasteboard data obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
record.addEntry(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
record.addEntry(pasteboard.MIMETYPE_TEXT_HTML, html);
let types: string[] = record.getValidTypes([
    pasteboard.MIMETYPE_TEXT_PLAIN,
    pasteboard.MIMETYPE_TEXT_HTML,
    pasteboard.MIMETYPE_TEXT_URI,
    pasteboard.MIMETYPE_TEXT_WANT,
    pasteboard.MIMETYPE_PIXELMAP
]);
```

### getData<sup>14+</sup>

getData(type: string): Promise&lt;ValueType&gt;

Obtains custom data of the specified MIME type from **PasteDataRecord**. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name | Type    |Mandatory| Description      |
|------|--------|-------- |----------|
| type | string | Yes| MIME type. The value contains a maximum of 1024 bytes. If the value is out of range, error code 401 is returned.|

**Return value**

| Type                                     | Description                                                                                                                  |
|-----------------------------------------|----------------------------------------------------------------------------------------------------------------------|
| Promise&lt;[ValueType](#valuetype9)&gt; | Promise used to return the custom data of the specified MIME type in **PasteDataRecord**.<br>If **PasteDataRecord** contains data of multiple MIME types, the non-**PasteDataRecord** data of the default MIME type can be obtained only through this API.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
record.addEntry(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
record.addEntry(pasteboard.MIMETYPE_TEXT_HTML, html);
record.getData(pasteboard.MIMETYPE_TEXT_PLAIN).then((value: pasteboard.ValueType) => {
    let textPlainContent = value as string;
    console.info('Success to get text/plain value. value is: ' + textPlainContent);
}).catch((err: BusinessError) => {
    console.error('Failed to get text/plain value. Cause: ' + err.message);
});
record.getData(pasteboard.MIMETYPE_TEXT_URI).then((value: pasteboard.ValueType) => {
    let uri = value as string;
    console.info('Success to get text/uri value. value is: ' + uri);
}).catch((err: BusinessError) => {
    console.error('Failed to get text/uri value. Cause: ' + err.message);
});
```

### convertToText<sup>(deprecated)</sup>

convertToText(callback: AsyncCallback&lt;string&gt;): void

Forcibly converts the content in a **PasteData** object to text. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [toPlainText](#toplaintext9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the text obtained from the conversion. Otherwise, **err** is error information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText((err: BusinessError, data: string) => {
    if (err) {
        console.error(`Failed to convert to text. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in converting to text. Data: ${data}`);
});
```

### convertToText<sup>(deprecated)</sup>

convertToText(): Promise&lt;string&gt;

Forcibly converts the content in a **PasteData** object to text. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [toPlainText](#toplaintext9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the text obtained from the conversion.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText().then((data: string) => {
    console.info(`Succeeded in converting to text. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to convert to text. Cause: ${err.message}`);
});
```

## PasteData

Implements a **PasteData** object. Paste data contains one or more data records ([PasteDataRecord](#pastedatarecord7)) and property description objects ([PasteDataProperty](#pastedataproperty7)).

Before calling any API in **PasteData**, you must use **[createData()](#pasteboardcreatedata9)** or **[getData()](#getdata9)** to create a **PasteData** object.

**System capability**: SystemCapability.MiscServices.Pasteboard

### getPrimaryText

getPrimaryText(): string

Obtains the plain text of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Plain text. If the **PasteData** object does not contain plain text, **undefined** is returned by default.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Asynchronously read the pasteboard data.
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    // Obtain the plain text content from the pasteboard.
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    // Handle the failure of obtaining the content.
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getPrimaryHtml<sup>7+</sup>

getPrimaryHtml(): string

Obtains the HTML content of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | HTML content. If the **PasteData** object does not contain HTML content, **undefined** is returned by default.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    let htmlText: string = pasteData.getPrimaryHtml();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

Obtains the **Want** object of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Want object. If the **PasteData** object does not contain the **Want** object, **undefined** is returned by default.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    let want: Want = pasteData.getPrimaryWant();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getPrimaryUri<sup>7+</sup>

getPrimaryUri(): string

Obtains the URI of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | URI content. If the **PasteData** object does not contain the URI, **undefined** is returned by default.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    let uri: string = pasteData.getPrimaryUri();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getPrimaryPixelMap<sup>9+</sup>

getPrimaryPixelMap(): image.PixelMap

Obtains the pixel map of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Pixel map. If the **PasteData** object does not contain the pixel map, **undefined** is returned by default.|

**Example**

```ts
import { image } from '@kit.ImageKit';

// Create a buffer for storing image data.
let buffer = new ArrayBuffer(128);
// Define the image size.
let realSize: image.Size = { height: 3, width: 5 };
let opt: image.InitializationOptions = {
    size: realSize,
    pixelFormat: 3,
    editable: true,
    alphaType: 1,
    scaleMode: 1
};
image.createPixelMap(buffer, opt).then((pixelMap: image.PixelMap) => {
    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_PIXELMAP, pixelMap);
    let PixelMap: image.PixelMap = pasteData.getPrimaryPixelMap();
});
```

### addRecord<sup>7+</sup>

addRecord(record: PasteDataRecord): void

Adds a data record to this pasteboard, and adds its type to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation is invalid.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| record | [PasteDataRecord](#pastedatarecord7) | Yes| Record to be added. After this parameter is set, the record is added to the pasteboard and the **mimeTypes** attribute list is updated.|

**Example**

```ts
// Create a PasteData object of the URI type.
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
// Create a data record of the plain text type.
let textRecord: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let htmlRecord: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_HTML, html);
pasteData.addRecord(textRecord);
pasteData.addRecord(htmlRecord);
```

### addRecord<sup>9+</sup>

addRecord(mimeType: string, value: ValueType): void

Adds a data record to this pasteboard, and adds its type to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

**Use scenarios**: Use this method to add additional data records to an existing **PasteData** object when the pasteboard needs to contain multiple types of data, for example, plain text and HTML.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| MIME type of data. The value contains a maximum of 1024 bytes. If the value is out of range, error code 401 is returned.|
| value | [ValueType](#valuetype9) | Yes| Data content. After this parameter is set, the pasteboard data properties are updated, including the timestamp, data type, and pasteable scope.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 12900002 | The number of records exceeds the upper limit, <br>**Applicable versions**: 9|

**Example**

  ```ts
  let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
  // Create ArrayBuffer data.
  let dataXml = new ArrayBuffer(256);
  pasteData.addRecord('app/xml', dataXml);
  ```

### getMimeTypes<sup>7+</sup>

getMimeTypes(): Array&lt;string&gt;

Obtains MIME types of [PasteDataProperty](#pastedataproperty7) on the pasteboard. If an exception occurs during API invoking, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;string&gt; | Non-repeating data types of the data records on the pasteboard.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let types: string[] = pasteData.getMimeTypes();
```

### getPrimaryMimeType<sup>7+</sup>

getPrimaryMimeType(): string

Obtains the data type of the primary record in this pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Data type of the primary record.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let type: string = pasteData.getPrimaryMimeType();
```

### getProperty<sup>7+</sup>

getProperty(): PasteDataProperty

Obtains the property of the pasteboard data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataProperty](#pastedataproperty7) | Property of the pasteboard data.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let property: pasteboard.PasteDataProperty = pasteData.getProperty();
```

### setProperty<sup>9+</sup>

setProperty(property: PasteDataProperty): void

Sets a [PasteDataProperty](#pastedataproperty7) object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| property | [PasteDataProperty](#pastedataproperty7) | Yes| Data properties. After this parameter is set, the pasteboard data properties updated, including the timestamp, data type, and pasteable scope.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
// Define the type of the additional property.
type AdditionType = Record<string, Record<string, Object>>;

// Create a PasteData object of the HTML type.
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_HTML, 'application/xml');
// Obtain a PasteDataProperty object.
let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
prop.shareOption = pasteboard.ShareOption.INAPP;
// Note that attributes cannot be added to additions. Attributes can be added only by re-assigning values.
prop.additions = { 'TestOne': { 'Test': 123 }, 'TestTwo': { 'Test': 'additions' } } as AdditionType;
prop.tag = 'TestTag';
pasteData.setProperty(prop);
```

The **localOnly** and **shareOption** attributes of [PasteDataProperty](#pastedataproperty7) are mutually exclusive. The **shareOption** attribute is prioritized, and its value affects the value of **localOnly**.

```ts
(async () => {
    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
    let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
    prop.shareOption = pasteboard.ShareOption.INAPP;
    prop.localOnly = false;
    pasteData.setProperty(prop);
    const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();

    await systemPasteboard.setData(pasteData).then(async () => {
        console.info('Succeeded in setting PasteData.');
        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
            prop.localOnly; // true
        });
    });

    prop.shareOption = pasteboard.ShareOption.LOCALDEVICE;
    prop.localOnly = false;
    pasteData.setProperty(prop);

    await systemPasteboard.setData(pasteData).then(async () => {
        console.info('Succeeded in setting PasteData.');
        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
            prop.localOnly; // true
        });
    });
})
```

### getRecord<sup>9+</sup>

getRecord(index: number): PasteDataRecord

Obtains the record with a specific index from the pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Index of the target record. The value ranges from 0 to the value of **getRecordCount()** minus 1. If the value is out of range, error code 12900001 is triggered.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | Record with the specified index.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let record: pasteboard.PasteDataRecord = pasteData.getRecord(0);
```

### getRecordCount<sup>7+</sup>

getRecordCount(): number

Obtains the number of records in the pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of records.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let count: number = pasteData.getRecordCount();
```

### getTag<sup>7+</sup>

getTag(): string

Obtains the custom tag from the pasteboard. If no custom tag is set, null is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Custom tag. If no custom tag is set, null is returned.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let tag: string = pasteData.getTag();
```

### hasType<sup>9+</sup>

hasType(mimeType: string): boolean

Checks whether the pasteboard contains data of the specified MIME type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| Type of the data to query. The value can be a predefined type listed in [Constants](#constants), including HTML, WANT, plain text, URI, and pixel map, or a custom MIME type. The length cannot exceed 1024 bytes.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified data type exists; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let hasType: boolean = pasteData.hasType(pasteboard.MIMETYPE_TEXT_PLAIN);
```

### removeRecord<sup>9+</sup>

removeRecord(index: number): void

Removes the record with a specific index from the pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index. The value ranges from 0 to the value of **getRecordCount()** minus 1. If the value is out of range, error code 12900001 is triggered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
pasteData.removeRecord(0);
```

### replaceRecord<sup>9+</sup>

replaceRecord(index: number, record: PasteDataRecord): void

Replaces the record with a specific index from the pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index. The value ranges from 0 to the value of **getRecordCount()** minus 1. If the value is out of range, error code 12900001 is triggered.|
| record | [PasteDataRecord](#pastedatarecord7) | Yes| New record. After this parameter is set, the original record with the specified index is replaced.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'file://com.example.myapplication1/data/storage/el2/base/files/file.txt');
pasteData.replaceRecord(0, record);
```

### pasteStart<sup>12+</sup>

pasteStart(): void

Notifies the pasteboard service to retain the cross-device channel before reading data from the pasteboard. Notifies the pasteboard service to retain the cross-device link before accessing cross-device data in the pasteboard. The cross-device link is used to connect to the peer device and transfer files from the peer device to the local device. If this API is not called, the cross-device link will be automatically disconnected 30 seconds later. It is applicable to the cross-device pasting scenario.

**Use scenarios**: This API is used when you need to ensure that the cross-device channel for pasteboard data transfer remains connected for subsequent reading of the pasteboard data from the peer device.

**API called in pairs**

- This API must be used with [pasteComplete](#pastecomplete12) in pairs.

- Calling sequence: Call **pasteStart()** to notify the system to reserve the channel. After data processing is complete, call **pasteComplete()** to notify the system that the processing is complete.

- If **pasteComplete()** is not called, the cross-device channel will not be correctly closed, affecting subsequent cross-device pasteboard operations.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    pasteData.pasteStart();
    console.info(`using data: ${pasteData.getPrimaryText()}`);
    pasteData.pasteComplete();
});
```

### pasteComplete<sup>12+</sup>

pasteComplete(): void

Notifies the pasteboard service that the paste is complete, and resources such as the cross-device channel can be released. This API should be called after **pasteStart()** is called and data processing is complete to prevent resource waste. If this API is not called, the cross-device channel may be occupied for a long time, affecting subsequent cross-device paste operations.

For details about how to use **pasteComplete()** and other APIs, see the following:

1. Obtain the pasteboard data by calling **getData()**.

2. Reserve the cross-device channel by calling **pasteStart()**.

3. Use the pasteboard data.

4. Release the channel by calling **pasteComplete()**.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    pasteData.pasteStart();
    console.info(`using data: ${pasteData.getPrimaryText()}`);
    pasteData.pasteComplete();
});
```

### addHtmlRecord<sup>(deprecated)</sup>

addHtmlRecord(htmlText: string): void

Adds an HTML record to this pasteboard, and adds **MIMETYPE_TEXT_HTML** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML text. The value must comply with the standard HTML format.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
pasteData.addHtmlRecord(html);
```

### addWantRecord<sup>(deprecated)</sup>

addWantRecord(want: Want): void

Adds a Want record to this pasteboard, and adds **MIMETYPE_TEXT_WANT** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want object.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
pasteData.addWantRecord(object);
```

### addTextRecord<sup>(deprecated)</sup>

addTextRecord(text: string): void

Adds a plain text record to this pasteboard, and adds **MIMETYPE_TEXT_PLAIN** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Plain text.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
pasteData.addTextRecord('good');
```

### addUriRecord<sup>(deprecated)</sup>

addUriRecord(uri: string): void

Adds a URI record to this pasteboard, and adds **MIMETYPE_TEXT_URI** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI content.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
pasteData.addUriRecord('dataability:///com.example.myapplication1/user.txt');
```

### getRecordAt<sup>(deprecated)</sup>

getRecordAt(index: number): PasteDataRecord

Obtains the record with a specific index from the pasteboard.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getRecord](#getrecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Index of the target record. The value ranges from 0 to the value of **getRecordCount()** minus 1. If the value is out of range, error code 401 is returned.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | Record with the specified index.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let record: pasteboard.PasteDataRecord = pasteData.getRecordAt(0);
```

### hasMimeType<sup>(deprecated)</sup>

hasMimeType(mimeType: string): boolean

Checks whether the pasteboard contains data of the specified type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasType](#hastype9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| Type of the data to query. The value can be a predefined type listed in [Constants](#constants), including HTML, WANT, plain text, URI, and pixel map, or a custom MIME type. The length cannot exceed 1024 bytes.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified data type exists; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let hasType: boolean = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
```

### removeRecordAt<sup>(deprecated)</sup>

removeRecordAt(index: number): boolean

Removes the record with a specific index from the pasteboard.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [removeRecord](#removerecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index. The value ranges from 0 to the value of **getRecordCount()** minus 1. If the value is out of range, error code 401 is returned.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | The value **true** is returned if the record with the specified index is successfully removed; the value **false** is returned if the record fails to be removed (for example, the specified index does not exist or is out of range).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let isRemove: boolean = pasteData.removeRecordAt(0);
```

### replaceRecordAt<sup>(deprecated)</sup>

replaceRecordAt(index: number, record: PasteDataRecord): boolean

Replaces the record with a specific index from the pasteboard.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [replaceRecord](#replacerecord9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index. The value ranges from 0 to the value of **getRecordCount()** minus 1. If the value is out of range, error code 401 is returned.|
| record | [PasteDataRecord](#pastedatarecord7) | Yes| New record.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | The value **true** is returned if the record with the specified index is successfully replaced; the value **false** is returned if the record fails to be removed (for example, the specified index does not exist or is out of range, or the parameter is empty).|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
let isReplace: boolean = pasteData.replaceRecordAt(0, record);
```

## SystemPasteboard

Provides **SystemPasteboard** APIs.

Before calling any **SystemPasteboard** API, you must obtain a **SystemPasteboard** object using [getSystemPasteboard](#pasteboardgetsystempasteboard).

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
```

### on('update')<sup>7+</sup>

on(type: 'update', callback: () =&gt;void): void

Subscribes to the content change event of the system pasteboard. After this method is called, the system registers a listener in the pasteboard service. The callback is triggered when content is written, cleared, or modified in the pasteboard. Multiple listeners can be registered. You need to call **off('update')** to unsubscribe from the content change event at a proper time to release resources.

**Use scenarios**: This API is called when an app needs to respond to pasteboard content changes in real time, for example, to automatically detect data in a specific format or to implement intelligent paste suggestions.

**API called in pairs**

- Call [off('update')](#offupdate7) to unsubscribe from the content change event of the system pasteboard when it is no longer needed.

- If the event is not unsubscribed from, the callback function will continuously listen for pasteboard changes, which may cause memory leaks or the callback being triggered from multiple times.

- You are advised to unsubscribe from the event when the component or page is destroyed.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value **'update'** indicates changes in the pasteboard content. Other values are invalid.|
| callback | function | Yes| Callback invoked when the pasteboard content changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Define a callback to be invoked when the pasteboard content changes.
let listener = () => {
    console.info('The system pasteboard has changed.');
};
// Subscribe to the pasteboard content change event.
systemPasteboard.on('update', listener);
```

### off('update')<sup>7+</sup>

off(type: 'update', callback?: () =&gt;void): void

Unsubscribes from the system pasteboard content change event.

**API called in pairs**

- This API is used to unsubscribe from the event subscribed to by **on('update')**.

- This API can be called only after an event has been subscribed to.

- If the **callback** parameter is not specified, listening will be disabled for all callbacks registered by the current application.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description                                                     |
| -------- | -------- | -------- |---------------------------------------------------------|
| type | string | Yes| Event type. The value **'update'** indicates changes in the pasteboard content.                             |
| callback | function | No| Callback invoked when the pasteboard content changes. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Define a callback to be invoked when the pasteboard content changes.
let listener = () => {
    console.info('The system pasteboard has changed.');
};
// Subscribe to the pasteboard content change event.
systemPasteboard.off('update', listener);
```

### clearData<sup>9+</sup>

clearData(callback: AsyncCallback&lt;void&gt;): void

Clears the system pasteboard. This API uses an asynchronous callback to return the result. After this API is called, the system deletes all data from the pasteboard and triggers the registered listener callback **'update'**. After the pasteboard is cleared, it will contain no data, and **false** will be returned for **hasData**.

**Use scenarios**: This API can be used to clear the pasteboard asynchronously without blocking the main thread, such as the interaction process that requires the UI response. Unlike the synchronous API [clearDataSync](#cleardatasync11), this API does not block the UI thread and is more suitable for UI interactions.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Clear the system pasteboard content.
systemPasteboard.clearData((err, data) => {
    if (err) {
        console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
        return;
    }
    console.info('Succeeded in clearing the pasteboard.');
});
```

### clearData<sup>9+</sup>

clearData(): Promise&lt;void&gt;

Clears the system pasteboard. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clearData().then((data: void) => {
    console.info('Succeeded in clearing the pasteboard.');
}).catch((err: BusinessError) => {
    console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
});
```

### setData<sup>9+</sup>

setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result. After this API is called, the system writes the data of the **PasteData** object to the pasteboard. After the data is written successfully, other apps can read the data from the pasteboard. The written data will replace the existing data in the pasteboard.

**Constraints**

- If another copy or paste operation is in progress, error code 27787277 is returned.

- If the copy operation is prohibited, error code 27787278 is returned.

- The **PasteData** object cannot be empty.

**Use scenarios**: This API can be used to write data to the pasteboard asynchronously, such as when the UI response is required or the main thread should not be blocked. Unlike [setDataSync](#setdatasync11), **setData** does not block the UI thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object. After this parameter is set, the data is written to the system pasteboard for the app to read and paste.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
// Create a PasteData object of the plain text type.
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Write data to the system pasteboard.
systemPasteboard.setData(pasteData, (err, data) => {
    if (err) {
        console.error('Failed to set PasteData. Cause: ' + err.message);
        return;
    }
    console.info('Succeeded in setting PasteData.');
});
```

### setData<sup>9+</sup>

setData(data: PasteData): Promise&lt;void&gt;

Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.

**Use scenarios**: This API can be used to write date to the pasteboard asynchronously without blocking the main thread, such as the interaction process that requires the UI response. Unlike the synchronous API [setDataSync](#setdatasync11), this API does not block the UI thread and is more suitable for UI interactions.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object. Before calling this API, ensure that no other copy or paste operation is in progress.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Create a PasteData object of the plain text type.
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Write data to the system pasteboard.
systemPasteboard.setData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```

### getData<sup>9+</sup>

getData(callback: AsyncCallback&lt;PasteData&gt;): void

Reads data from the system pasteboard and encapsulates the data into a **PasteData** object. This API uses an asynchronous callback to return the result. After this API is called, the system reads the current content from the pasteboard service and returns a **PasteData** object using a callback. After the data is read successfully, the app can obtain the specific data content (such as text, HTML, and URI) using the **PasteData** object. This API can be used to read data from the pasteboard asynchronously, such as when the UI response is required or the main thread should not be blocked. Compared with [getDataSync](#getdatasync11), **getData** does not block the UI thread and is suitable for processing a large amount of data or remote data.

**Required permissions**: ohos.permission.READ_PASTEBOARD. While most applications must [request permissions to access the pasteboard](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md), those using [PasteButton](../../security/AccessToken/pastebutton.md) can access the pasteboard content without permission requests.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the system pasteboard data. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. <br>**Applicable versions**: 12 and later|
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Read the system clipboard content.
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    // Obtain the plain text content from the pasteboard.
    let text: string = pasteData.getPrimaryText();
});
```

### getData<sup>9+</sup>

getData(): Promise&lt;PasteData&gt;

Obtains data from the system pasteboard and encapsulates the data into a **PasteData** object. This API uses a promise to return the result. This API can be used to read data from the pasteboard asynchronously, such as when the UI response is required or the main thread should not be blocked.

**Use scenarios**: This API can be used when an app needs to read data from the pasteboard using [UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata).

**Required permissions**: ohos.permission.READ_PASTEBOARD. While most applications must [request permissions to access the pasteboard](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md), those using [PasteButton](../../security/AccessToken/pastebutton.md) can access the pasteboard content without permission requests.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. <br>**Applicable versions**: 12 and later|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Read the system clipboard content.
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    // Obtain the plain text content from the pasteboard.
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### hasRemoteData<sup>24+</sup>

hasRemoteData(): boolean

Checks whether the pasteboard data is on a remote device. Transferring data across devices takes time. If the pasteboard data is on a remote device, do not check for custom data types or read the pasteboard data on the UI thread.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns the check result. The value **true** indicates that the pasteboard data is on a remote device, and **false** indicates the opposite. Default value: **false**.|

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();

let result: boolean = systemPasteboard.hasRemoteData();
console.info(`Succeeded in checking the remote data. Result: ${result}`);

```

### hasData<sup>9+</sup>

hasData(callback:  AsyncCallback&lt;boolean&gt;): void

Checks whether the system pasteboard contains data. This API uses an asynchronous callback to return the result.

**Use scenarios**: This API can be used to check whether the pasteboard contains data. asynchronously without blocking the main thread, such as the interaction process that requires the UI response. Unlike the synchronous API [hasDataSync](#hasdatasync11), this API does not block the UI thread and is more suitable for UI interactions.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result of whether pasteboard contains data. Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`Failed to check the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
});
```

### hasData<sup>9+</sup>

hasData(): Promise&lt;boolean&gt;

Checks whether the system pasteboard contains data. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData().then((data: boolean) => {
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### clear<sup>(deprecated)</sup>

clear(callback: AsyncCallback&lt;void&gt;): void

Clears the system pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.clearData](#cleardata9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clear((err, data) => {
    if (err) {
        console.error(`Failed to clear the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info('Succeeded in clearing the PasteData.');
});
```

### clear<sup>(deprecated)</sup>

clear(): Promise&lt;void&gt;

Clears the system pasteboard. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [pasteboard.clearData](#cleardata9-1) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clear().then((data) => {
    console.info('Succeeded in clearing the PasteData.');
}).catch((err: BusinessError) => {
    console.error(`Failed to clear the PasteData. Cause: ${err.message}`);
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData(callback: AsyncCallback&lt;PasteData&gt;): void

Obtains a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getData](#getdata9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the system pasteboard data. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Read the system clipboard content.
systemPasteboard.getPasteData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    // Obtain the plain text content from the pasteboard.
    let text: string = pasteData.getPrimaryText();
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData(): Promise&lt;PasteData&gt;

Obtains a **PasteData** object from the pasteboard. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getData](#getdata9-1) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the SystemPasteboard object.
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// Read the system clipboard content.
systemPasteboard.getPasteData().then((pasteData: pasteboard.PasteData) => {
    // Obtain the plain text content from the pasteboard.
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### hasPasteData<sup>(deprecated)</sup>

hasPasteData(callback:  AsyncCallback&lt;boolean&gt;): void

Checks whether the system pasteboard contains data. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasData](#hasdata9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasPasteData((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`Failed to check the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
});
```

### hasPasteData<sup>(deprecated)</sup>

hasPasteData(): Promise&lt;boolean&gt;

Checks whether the system pasteboard contains data. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasData](#hasdata9-1) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasPasteData().then((data: boolean) => {
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setData](#setdata9) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|
| callback | AsyncCallback&lt;void> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData, (err, data) => {
    if (err) {
        console.error('Failed to set PasteData. Cause: ' + err.message);
        return;
    }
    console.info('Succeeded in setting PasteData.');
});
```

### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData): Promise&lt;void&gt;

Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setData](#setdata9-1) instead.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```

### isRemoteData<sup>11+</sup>

isRemoteData(): boolean

Checks whether the data in the pasteboard is from another device. Transferring data across devices takes time. If the pasteboard data is on a remote device, do not check for custom data types or read the pasteboard data on the UI thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type   | Description                                 |
| ------- | ------------------------------------- |
| boolean | Checks whether the data in the pasteboard is from another device. The value **true** indicates the data in the pasteboard is from another device; the value **false** indicates the data is from the local device.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.isRemoteData();
    console.info(`Succeeded in checking the RemoteData. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the RemoteData. Cause: ' + err.message);
};
```

### getDataSource<sup>11+</sup>

getDataSource(): string

Obtains the name of the application that provides data.

**Use scenarios**: This API is used to identify the source app of pasteboard data. It is applicable to security audit, data tracking, and notifying users of the data source.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type  | Description  |
| ------ | ------ |
| string | Application name.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: string = systemPasteboard.getDataSource();
    console.info(`Succeeded in getting DataSource. Result: ${result}`);
} catch (err) { 
    console.error('Failed to get DataSource. Cause: ' + err.message);
};
```

### hasDataType<sup>11+</sup>

hasDataType(mimeType: string): boolean

Checks whether the pasteboard contains data of the specified type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | ---- | ------------------ |
| mimeType | string | Yes  | Data type, which is used to check whether specific data of this type exists in the pasteboard. The length of **mimeType** cannot exceed 1024 bytes. If the length exceeds 1024 bytes, error code 401 is returned.|

**Return value**

| Type   | Description                                       |
| ------- | ------------------------------------------- |
| boolean | Checks whether the pasteboard contains data of the specified type. The value **true** indicates the pasteboard contains data of the specified type; the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Excessive processing time for internal data. |

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.hasDataType(pasteboard.MIMETYPE_TEXT_PLAIN);
    console.info(`Succeeded in checking the DataType. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the DataType. Cause: ' + err.message);
};
```

### clearDataSync<sup>11+</sup>

clearDataSync(): void

Clears data in the system pasteboard. This API returns the result synchronously.

**Use scenarios**: This API is used to clear the pasteboard data synchronously in a key service process or confirm the clearing result immediately.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.clearDataSync();
    console.info('Succeeded in clearing the pasteboard.');
} catch (err) {
    console.error('Failed to clear the pasteboard. Cause: ' + err.message);
};
```

### getDataSync<sup>11+</sup>

getDataSync(): PasteData

Reads data in the system pasteboard. This API returns the result synchronously. This API is used to obtain pasteboard data synchronously in key service processes or process pasteboard data immediately. Do not call this API on the UI thread to prevent blocking the UI. Use the asynchronous API [getData](#getdata9) to process a large amount of data or remote data.

**Required permissions**: ohos.permission.READ_PASTEBOARD. While most applications must [request permissions to access the pasteboard](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md), those using [PasteButton](../../security/AccessToken/pastebutton.md) can access the pasteboard content without permission requests.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type                   | Description                |
| ----------------------- | -------------------- |
| [PasteData](#pastedata) | Data in the system pasteboard.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. <br>**Applicable versions**: 12 and later|

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: pasteboard.PasteData = systemPasteboard.getDataSync();
    console.info('Succeeded in getting PasteData.');
} catch (err) {
    console.error('Failed to get PasteData. Cause:' + err.message);
};   
```

### setDataSync<sup>11+</sup>

setDataSync(data: PasteData): void

Writes data to the system pasteboard. This API returns the result synchronously.

**Use scenarios**: This API can be used to write data to the pasteboard synchronously in key service processes or confirm the write result immediately.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type                   | Mandatory| Description            |
| ------ | ----------------------- | ---- | ---------------- |
| data   | [PasteData](#pastedata) | Yes  | Data to be written to the pasteboard.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Excessive processing time for internal data. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.setDataSync(pasteData);
    console.info('Succeeded in setting PasteData.');
} catch (err) {
    console.error('Failed to set PasteData. Cause:' + err.message);
};  
```

### hasDataSync<sup>11+</sup>

hasDataSync(): boolean

Checks whether the system pasteboard contains data. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type   | Description                                                                   |
| ------- | ----------------------------------------------------------------------- |
| boolean | Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.hasDataSync();
    console.info(`Succeeded in checking the PasteData. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the PasteData. Cause: ' + err.message);
};    
```

### getUnifiedData<sup>12+</sup>

getUnifiedData(): Promise&lt;unifiedDataChannel.UnifiedData&gt;

Obtains a **PasteData** object from the pasteboard. This API uses a promise to return the result.

**Use scenarios**: This API is used for cross-app data exchange using [UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata). This API can be used to share data with other apps that support **UnifiedData** or process complex data of multiple types. Compared with [getData](#getdata14), **getUnifiedData** provides more standard data formats.

**Required permissions**: ohos.permission.READ_PASTEBOARD. While most applications must [request permissions to access the pasteboard](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md), those using [PasteButton](../../security/AccessToken/pastebutton.md) can access the pasteboard content without permission requests.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata)&gt; | Promise used to return the system pasteboard data.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 27787277 | Another copy or paste operation is in progress. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { unifiedDataChannel, uniformDataStruct, uniformTypeDescriptor } from '@kit.ArkData';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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
});
```

### getUnifiedDataSync<sup>12+</sup>

getUnifiedDataSync(): unifiedDataChannel.UnifiedData

Reads data in the system pasteboard. This API returns the result synchronously.

**Use scenarios**: This API is used for cross-app data exchange using **UnifiedData**. This API can be used to immediately obtain data from the pasteboard in key service processes and share the data with other apps that support **UnifiedData**. The delay in obtaining data from the pasteboard is affected by the data volume and network environment. Therefore, calling this API may take a long time. You are advised to call this API in non-UI threads.

**Required permissions**: ohos.permission.READ_PASTEBOARD. While most applications must [request permissions to access the pasteboard](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md), those using [PasteButton](../../security/AccessToken/pastebutton.md) can access the pasteboard content without permission requests.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type                | Description                |
| -------------------- | -------------------- |
| [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | Data in the system pasteboard.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 12900005 | Excessive processing time for internal data. |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: unifiedDataChannel.UnifiedData = systemPasteboard.getUnifiedDataSync();
    console.info('Succeeded in getting UnifiedData.');
} catch (err) {
    console.error('Failed to get UnifiedData. Cause:' + err.message);
};   
```

### setUnifiedData<sup>12+</sup>

setUnifiedData(data: unifiedDataChannel.UnifiedData): Promise&lt;void&gt;

Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.

**Use scenarios**: This API can be used to write date to the pasteboard asynchronously without blocking the main thread, such as the interaction process that requires the UI response. Unlike the synchronous API [setUnifiedDataSync](#setunifieddatasync12), this API does not block the UI thread and is more suitable for UI interactions.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | Yes| Data to be written to the pasteboard. Before calling this API, ensure that no other copy or paste operation is in progress.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { unifiedDataChannel, uniformDataStruct, uniformTypeDescriptor } from '@kit.ArkData';

// Create a data structure object of the plain text type.
let plainText : uniformDataStruct.PlainText = {
    uniformDataType: uniformTypeDescriptor.UniformDataType.PLAIN_TEXT,
    textContent : 'PLAINTEXT_CONTENT',
    abstract : 'PLAINTEXT_ABSTRACT',
}
// Create a UnifiedRecord object.
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainText);
// Create a UnifiedData object.
let data = new unifiedDataChannel.UnifiedData();
// Add the data record to the UnifiedData object.
data.addRecord(record);

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setUnifiedData(data).then((data: void) => {
    console.info('Succeeded in setting UnifiedData.');
}).catch((err: BusinessError) => {
    console.error('Failed to setUnifiedData. Cause: ' + err.message);
});
```

### setUnifiedDataSync<sup>12+</sup>

setUnifiedDataSync(data: unifiedDataChannel.UnifiedData): void

Writes data to the system pasteboard. This API returns the result synchronously.

**Use scenarios**: This API is used for cross-app data exchange using **UnifiedData**. This API can be used to immediately write data to the pasteboard in key service processes and share the data with other apps that support [UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type       | Mandatory| Description            |
| ------ | ----------- | ---- | ---------------- |
| data   | [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | Yes  | Data to be written to the pasteboard. Cross-app data exchange is supported. Other apps can read the data using **unifiedDataChannel**.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Excessive processing time for internal data. |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';

// Create a UnifiedData object.
let plainTextData = new unifiedDataChannel.UnifiedData();
// Create a data object of the plain text type.
let plainText = new unifiedDataChannel.PlainText();
// Set the detailed information about the plain text.
plainText.details = {
    Key: 'delayPlaintext',
    Value: 'delayPlaintext',
};
// Set the text content.
plainText.textContent = 'delayTextContent';
// Set the abstract content.
plainText.abstract = 'delayTextContent';
// Add the data record to the UnifiedData object.
plainTextData.addRecord(plainText);

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.setUnifiedDataSync(plainTextData);
    console.info('Succeeded in setting UnifiedData.');
} catch (err) {
    console.error('Failed to set UnifiedData. Cause:' + err.message);
};
```

### setAppShareOptions<sup>14+</sup>

setAppShareOptions(shareOptions: ShareOption): void

Sets pasteable range of pasteboard data for applications.

**Use scenarios**: This API can be used to globally restrict the pasteable scope of pasteboard data generated by the app. For example, a financial app needs to protect sensitive user information.

**API called in pairs**

- This API is used together with **removeAppShareOptions()**.

- To delete the configured sharing scope, call **removeAppShareOptions()**.

- The sharing scope must be deleted from the same place where it was set, ensuring consistency between the setting and deletion of the sharing scope.

**Required permissions**: ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| shareOptions | [ShareOption](#shareoption9) | Yes| Pasteable range. Only **pasteboard.ShareOption.INAPP** is allowed. If other values are passed, error code 401 is returned.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12900006 | Settings already exist. |

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.setAppShareOptions(pasteboard.ShareOption.INAPP);
  console.info('Set app share options success.');
} catch (error) {
  console.error(`Set app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```

### removeAppShareOptions<sup>14+</sup>

removeAppShareOptions(): void

Deletes the global pasteable range of the application.

**Use scenarios**: This API can be used to delete the previously set pasteable scope and restore the default pasteable scope for pasteboard data.

**API called in pairs**

- This API must be used together with **setAppShareOptions()**.

- The sharing scope set by **setAppShareOptions()** is deleted.

- This API can be called only after the sharing scope has been set.

**Required permissions**: ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

**System capability**: SystemCapability.MiscServices.Pasteboard

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.removeAppShareOptions();
  console.info('Remove app share options success.');
} catch (error) {
  console.error(`Remove app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```

### Pattern<sup>13+</sup>

Describes the modes supported by the pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name                              | Value | Description                                                                                 |
| ---------------------------------- | --- | ------------------------------------------------------------------------------------- |
| URL                              | 0   | URL.                                                             |
| NUMBER                        | 1   | Number.                                                   |
| EMAIL_ADDRESS | 2   | Email address.|
| HTTP_URL<sup>24+</sup> | 3   | HTTP URL.<br> **Model constraint**: This API can be used only in the stage model.|
| FLIGHT_NUMBER<sup>24+</sup> | 4   | Flight number.<br> **Model constraint**: This API can be used only in the stage model.|

### detectPatterns<sup>13+</sup>

detectPatterns(patterns: Array&lt;Pattern&gt;): Promise&lt;Array&lt;Pattern&gt;&gt;

Detects [patterns](#pattern13) on the local pasteboard. This API uses a promise to return the result. The local pasteboard data refers to the pasteboard data on the current device, excluding the pasteboard data transferred across devices.

**Use scenarios**: This API can be used to check whether the pasteboard contains specific types of data (such as URLs, email addresses, and phone numbers) before pasting, so that the app can perform corresponding processing or provide intelligent prompts.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| patterns | Array&lt;[Pattern](#pattern13)&gt; | Yes| Patterns to be detected in the pasteboard, which is used to check whether the pasteboard data complies with a specific format. The options are **URL**, **NUMBER**, and **EMAIL_ADDRESS**. The number of elements in the array is not limited, and the element value must be an enumerated value of **Pattern**. If an invalid value is passed, error code 401 is returned.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[Pattern](#pattern13)&gt;&gt; | Promise used to return the detected pattern.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |

**Example**

```ts
import { pasteboard } from '@kit.BasicServicesKit'

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let patterns: Array<pasteboard.Pattern> = [pasteboard.Pattern.URL, pasteboard.Pattern.EMAIL_ADDRESS];

systemPasteboard.detectPatterns(patterns).then((data: Array<pasteboard.Pattern>) => {
    if (patterns.sort().join('')==data.sort().join('')) {
      console.info('All needed patterns detected, next get data');
      try {
        let result: pasteboard.PasteData = systemPasteboard.getDataSync();
        console.info('Succeeded in getting PasteData.');
      } catch (err) {
        console.error('Failed to get PasteData. Cause:' + err.message);
      };
    } else {
      console.info("Not all needed patterns detected, no need to get data.");
    }
});
```

### getMimeTypes<sup>14+</sup>

getMimeTypes(): Promise&lt;Array&lt;string&gt;&gt;

Obtains the MIME type from the pasteboard. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the read MIME type.|

**Example**

```ts
import { pasteboard, BusinessError } from '@kit.BasicServicesKit'

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getMimeTypes().then((data: Array<string>) => {
    console.info('Succeeded in getting mimeTypes. mimeTypes: ' + data.sort().join(','));
}).catch((err: BusinessError) => {
    console.error('Failed to get mimeTypes. Cause: ' + err.message);
});
```

### getDataWithProgress<sup>15+</sup>

getDataWithProgress(params: GetDataParams): Promise&lt;PasteData&gt;

Obtains the pasteboard data and progress. This API uses a promise to return the result. Folders cannot be copied. For the copy operation of large files, you are advised to register a listener to track the copy progress and prevent long waiting time on the UI thread. You are also advised to set a proper destination path to ensure sufficient storage space.

**Use scenarios**: This API can be used display the copy progress or listen for the copy process to cancel the operation if necessary during pasting of large files.

**Required permissions**: ohos.permission.READ_PASTEBOARD. While most applications must [request permissions to access the pasteboard](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md), those using [PasteButton](../../security/AccessToken/pastebutton.md) can access the pasteboard content without permission requests.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type                             | Mandatory| Description                                                        |
| ------ | --------------------------------- | ---- | ------------------------------------------------------------ |
| params | [GetDataParams](#getdataparams15) | Yes  | Parameters required when an application uses the file copy capability provided by the pasteboard, including the destination path, file conflict options, and progress indicator types.|

**Return value**

| Type                                  | Description                             |
| -------------------------------------- | --------------------------------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error.                                             |
| 12900003 | Another copy or paste operation is in progress.              |
| 12900007 | Invalid destUri or file system error.                        |
| 12900008 | Failed to start progress.                                    |
| 12900009 | Progress exits abnormally.                                   |
| 12900010 | System error occurred during paste execution.                |

**Example**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';
@Entry
@Component
struct PasteboardTest {
 build() {
   RelativeContainer() {
     Column() {
       Column() {
         Button("Copy txt")
           .onClick(async ()=>{
              let text = "test";
              let pasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, text);
              let systemPasteboard = pasteboard.getSystemPasteboard();
              await systemPasteboard.setData(pasteData);
              let progressListenerInfo = (progress: pasteboard.ProgressInfo) => {
                console.info('progressListener success, progress:' + progress.progress);
              };
              let destPath: string = '/data/storage/el2/base/files/';
              let destUri : string = fileUri.getUriFromPath(destPath);
              let params: pasteboard.GetDataParams = {
                destUri: destUri,
                fileConflictOptions: pasteboard.FileConflictOptions.OVERWRITE,
                progressIndicator: pasteboard.ProgressIndicator.DEFAULT,
                progressListener: progressListenerInfo,
              };
              systemPasteboard.getDataWithProgress(params).then((pasteData: pasteboard.PasteData) => {
                console.info('getDataWithProgress success');
              }).catch((err: BusinessError) => {
                console.error('Failed to get PasteData. Cause: ' + err.message);
              })
          })
        }
      }
    }
  }
}
```

### getChangeCount<sup>18+</sup>

getChangeCount(): number

Obtains the number of pasteboard content changes.

Returns the number of pasteboard content changes if this API is called successfully; returns **0** otherwise.

Even though the pasteboard data expires, or the data becomes empty because of the called [clearDataSync](#cleardatasync11) API, the number of data changes remains.

When the system is restarted, or the pasteboard service is restarted due to an exception, the number of pasteboard data changes counts from 0. If the same data is copied repeatedly, multiple changes will be recorded.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| number | The number of pasteboard content changes obtained.|

**Example**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result : number = systemPasteboard.getChangeCount();
    console.info(`Succeeded in getting the ChangeCount. Result: ${result}`);
} catch (err) {
    console.error(`Failed to get the ChangeCount. Cause: ${err.message}`);
};
```

### UpdateCallback<sup>22+</sup>

type UpdateCallback = () => void

Callback to be invoked when the pasteboard content changes.

**System capability**: SystemCapability.MiscServices.Pasteboard

### onRemoteUpdate<sup>22+</sup>

onRemoteUpdate(callback: UpdateCallback): void

Subscribes to the content change events of the pasteboard on a remote device. This callback is triggered when the pasteboard content on the remote device changes.

**API called in pairs**

- Call [offRemoteUpdate](#offremoteupdatecallback-updatecallback22) to unsubscribe from the content change event of the pasteboard when it is no longer needed.

- If the event is not unsubscribed from, the callback function will continuously listen for remote changes, which may cause memory leaks.

- You are advised to unsubscribe from the event when the component or page is destroyed.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [UpdateCallback](#updatecallback22) | Yes| Callback invoked when the pasteboard content changes. The listener parameters are not specified. The callback is used to listen for cross-device pasteboard data update events, which is triggered when the pasteboard data on a remote device changes.|

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The remote pasteboard has changed.');
};
systemPasteboard.onRemoteUpdate(listener);
```

### offRemoteUpdate(callback?: UpdateCallback)<sup>22+</sup>

offRemoteUpdate(callback?: UpdateCallback): void

Unsubscribes from the content change events of the pasteboard on a remote device.

**API called in pairs**

- This API is used to unsubscribe from the event subscribed to by **onRemoteUpdate()**.

- This API can be called only after an event has been subscribed to.

- If the **callback** parameter is not specified, remote listening will be disabled for all callbacks registered by the current application.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description                                                     |
| -------- | -------- | -------- |---------------------------------------------------------|
| callback | [UpdateCallback](#updatecallback22) | No| Callback to be invoked when the pasteboard content on the remote device changes. If this parameter is not specified, remote listening will be disabled for all callbacks registered by the current application.|

**Example**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The remote pasteboard has changed.');
};
systemPasteboard.offRemoteUpdate(listener);
```