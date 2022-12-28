# Pasteboard

The **pasteboard** module provides the copy and paste support for the system pasteboard. You can use the APIs of this module to operate pasteboard content of the plain text, HTML, URI, Want, pixel map, and other types.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import pasteboard from '@ohos.pasteboard';
```

## Constants

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Value| Description|
| -------- | -------- | -------- | -------- |
| MAX_RECORD_NUM<sup>7+</sup> | number | 512 | Maximum number of records in a **PasteData** object.|
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | 'text/html' | MIME type of the HTML content.|
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | 'text/want' | MIME type of the Want content.|
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | 'text/plain' | MIME type of the plain text content.|
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | 'text/uri' | MIME type of the URI content.|
| MIMETYPE_PIXELMAP<sup>9+</sup> | string | 'pixelMap' | MIME type of the pixel map.|

## ValueType<sup>9+</sup>

Enumerates the value types.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Type| Description|
| -------- | -------- |
| string | The value is a string.|
| image.PixelMap | The value is of the [image.PixelMap](js-apis-image.md#pixelmap7) type.|
| Want | The value is of the [Want](js-apis-app-ability-want.md) type.|
| ArrayBuffer | The value is of the **ArrayBuffer** type.|

## pasteboard.createData<sup>9+</sup>

createData(mimeType: string, value: ValueType): PasteData

Creates a **PasteData** object of a custom type.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| MIME type of custom data.|
| value | [ValueType](#valuetype9) | Yes| Content of custom data.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) |  **PasteData** object.|

**Example**

  ```js
  let dataXml = new ArrayBuffer(256);
  let pasteData = pasteboard.createData('app/xml', dataXml);
  ```

## pasteboard.createRecord<sup>9+</sup>

createRecord(mimeType: string, value: ValueType):PasteDataRecord;

Creates a **PasteDataRecord** object of the custom type.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| MIME type of custom data.|
| value | [ValueType](#valuetype9) | Yes| Content of custom data.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the custom type.|

**Example**

  ```js
  let dataXml = new ArrayBuffer(256);
  let pasteDataRecord = pasteboard.createRecord('app/xml', dataXml);
  ```

## pasteboard.getSystemPasteboard

getSystemPasteboard(): SystemPasteboard

Obtains this **SystemPasteboard** object.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [SystemPasteboard](#systempasteboard) | **SystemPasteboard** object.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
```

## ShareOption<sup>9+</sup>

Enumerates the paste options of data.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name | Description                   |
| -----  | ----------------------- |
| InApp  |Only intra-application pasting is allowed.|
| LocalDevice  |Paste is allowed in any application on the local device.|
| CrossDevice  |Paste is allowed in any application across devices.|

## pasteboard.createHtmlData<sup>(deprecated)</sup>

createHtmlData(htmlText: string): PasteData

Creates a **PasteData** object of the HTML type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```js
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData = pasteboard.createHtmlData(html);
```

## pasteboard.createWantData<sup>(deprecated)</sup>

createWantData(want: Want): PasteData

Creates a **PasteData** object of the Want type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```js
let object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData = pasteboard.createWantData(object);
```

## pasteboard.createPlainTextData<sup>(deprecated)</sup>

createPlainTextData(text: string): PasteData

Creates a **PasteData** object of the plain text type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9).

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

```js
let pasteData = pasteboard.createPlainTextData('content');
```

## pasteboard.createUriData<sup>(deprecated)</sup>

createUriData(uri: string): PasteData

Creates a **PasteData** object of the URI type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```js
let pasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
```
## pasteboard.createHtmlTextRecord<sup>(deprecated)</sup>

createHtmlTextRecord(htmlText: string): PasteDataRecord

Creates a **PasteDataRecord** object of the HTML text type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | **PasteDataRecord** object of the HTML text type.|

**Example**

```js
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record = pasteboard.createHtmlTextRecord(html);
```

## pasteboard.createWantRecord<sup>(deprecated)</sup>

createWantRecord(want: Want): PasteDataRecord

Creates a **PasteDataRecord** object of the Want type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the Want type.|

**Example**

```js
let object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let record = pasteboard.createWantRecord(object);
```

## pasteboard.createPlainTextRecord<sup>(deprecated)</sup>

createPlainTextRecord(text: string): PasteDataRecord

Creates a **PasteDataRecord** object of the plain text type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9).

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

```js
let record = pasteboard.createPlainTextRecord('hello');
```

## pasteboard.createUriRecord<sup>(deprecated)</sup>

createUriRecord(uri: string): PasteDataRecord

Creates a **PasteDataRecord** object of the URI type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the URI type.|

**Example**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
```


## PasteDataProperty<sup>7+</sup>

Defines the properties of all data records on the pasteboard, including the timestamp, data type, and additional data.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| additions<sup>7+</sup> | {[key:string]:object} | Yes| Yes| Additional data.|
| mimeTypes<sup>7+</sup> | Array&lt;string&gt; | Yes| No| Non-repeating data types of the data records on the pasteboard.|
| tag<sup>7+</sup> | string | Yes| Yes| Custom tag.|
| timestamp<sup>7+</sup> | number | Yes| No| Timestamp when data is written to the pasteboard (unit: ms).|
| localOnly<sup>7+</sup> | boolean | Yes| Yes| Whether the pasteboard content is set for local access only. The default value is **true**.<br>- **true**: The pasteboard content is set for local access only.<br>- **false**: The pasteboard content can be shared between devices.|
| shareOption<sup>9+</sup> | [ShareOption](#shareoption9) | Yes| Yes| Where the pasteboard content can be pasted. If this attribute is set incorrectly or not set, the default value **CrossDevice** is used.|

## PasteDataRecord<sup>7+</sup>

Provides **PasteDataRecord** APIs. A **PasteDataRecord** is an abstract definition of the content on the pasteboard. The pasteboard content consists of one or more plain text, HTML, URI, or Want records.

### Attributes

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| htmlText<sup>7+</sup> | string | Yes| No| HTML content.|
| want<sup>7+</sup> | [Want](js-apis-app-ability-want.md) | Yes| No| Want content.|
| mimeType<sup>7+</sup> | string | Yes| No| Data type.|
| plainText<sup>7+</sup> | string | Yes| No| Plain text.|
| uri<sup>7+</sup> | string | Yes| No| URI content.|
| pixelMap<sup>9+</sup> | [image.PixelMap](js-apis-image.md#pixelmap7) | Yes| No| Pixel map.|
| data<sup>9+</sup> | {[mimeType: string]: ArrayBuffer} | Yes| No| Content of custom data.|

### convertToTextV9<sup>9+</sup>

convertToTextV9(callback: AsyncCallback&lt;string&gt;): void

Forcibly converts the content in a **PasteData** object to text. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the text obtained from the conversion. Otherwise, **err** is error information.|

**Example**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToTextV9((err, data) => {
    if (err) {
        console.error(`Failed to convert to text. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in converting to text. Data: ${data}`);
});
```

### convertToTextV9<sup>9+</sup>

convertToTextV9(): Promise&lt;string&gt;

Forcibly converts the content in a **PasteData** object to text. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the text obtained from the conversion.|

**Example**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToTextV9().then((data) => {
    console.info(`Succeeded in converting to text. Data: ${data}`);
}).catch((err) => {
    console.error(`Failed to convert to text. Cause: ${err.message}`);
});
```

### convertToText<sup>(deprecated)</sup>

convertToText(callback: AsyncCallback&lt;string&gt;): void

Forcibly converts the content in a **PasteData** object to text. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [convertToTextV9](#converttotextv99).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the text obtained from the conversion. Otherwise, **err** is error information.|

**Example**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText((err, data) => {    
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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [convertToTextV9](#converttotextv99-1).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the text obtained from the conversion.|

**Example**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText().then((data) => {
    console.info(`Succeeded in converting to text. Data: ${data}`);
}).catch((err) => {
    console.error(`Failed to convert to text. Cause: ${err.message}`);
});
```

## PasteData

Provides **PasteData** APIs.

Before calling any **PasteData** API, you must obtain a **PasteData** object. 

**System capability**: SystemCapability.MiscServices.Pasteboard

### getPrimaryText

getPrimaryText(): string

Obtains the plain text of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Plain text.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let plainText = pasteData.getPrimaryText();
```

### getPrimaryHtml<sup>7+</sup>

getPrimaryHtml(): string

Obtains the HTML content of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | HTML content.|

**Example**

```js
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData = pasteboard.createHtmlData(html);
let htmlText = pasteData.getPrimaryHtml();
```

### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

Obtains the Want object of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [Want](js-apis-app-ability-want.md) | Want object.|

**Example**

```js
let object = { 
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData = pasteboard.createWantData(object);
let want = pasteData.getPrimaryWant();
```

### getPrimaryUri<sup>7+</sup>

getPrimaryUri(): string

Obtains the URI of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | URI content.|

**Example**

```js
let pasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
let uri = pasteData.getPrimaryUri();
```

### getPrimaryPixelMap<sup>9+</sup>

getPrimaryPixelMap(): image.PixelMap

Obtains the pixel map of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [image.PixelMap](js-apis-image.md#pixelmap7) | Pixel map.|

**Example**

```js
import image from '@ohos.multimedia.image';

let buffer = new ArrayBuffer(128);
let opt = {
  size: { height: 3, width: 5 },
  pixelFormat: 3,
  editable: true,
  alphaType: 1,
  scaleMode: 1
};
image.createPixelMap(buffer, opt).then((pixelMap) => {
    let pasteData = pasteboard.createData('app/xml',pixelMap);
    let PixelMap = pasteData.getPrimaryPixelMap();
});
```

### addRecord<sup>7+</sup>

addRecord(record: PasteDataRecord): void

Adds a data record to this pasteboard, and adds its type to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 512 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| record | [PasteDataRecord](#pastedatarecord7) | Yes| Record to add.|

**Example**

```js
let pasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
let textRecord = pasteboard.createPlainTextRecord('hello');
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let htmlRecord = pasteboard.createHtmlTextRecord(html);
pasteData.addRecord(textRecord);
pasteData.addRecord(htmlRecord);
```
### addRecord<sup>9+</sup>

addRecord(mimeType: string, value: ValueType): void

Adds a custom-type record to this pasteboard, and adds the custom type to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 512 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| MIME type of custom data.|
| value | [ValueType](#valuetype9) | Yes| Content of custom data.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](../errorcodes/errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900002 | The number of record exceeds the maximum limit. |

**Example**

  ```js
  let pasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
  let dataXml = new ArrayBuffer(256);
  pasteData.addRecord('app/xml', dataXml);
  ```

### getMimeTypes<sup>7+</sup>

getMimeTypes(): Array&lt;string&gt;

Obtains a list of **mimeTypes** objects in [PasteDataProperty](#pastedataproperty7) from this pasteboard. If the pasteboard is empty, the returned list is also empty.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;string&gt; | Non-repeating data types of the data records on the pasteboard.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let types = pasteData.getMimeTypes();
```

### getPrimaryMimeType<sup>7+</sup>

getPrimaryMimeType(): string

Obtains the data type of the primary record in this pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Data type of the primary record.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let type = pasteData.getPrimaryMimeType();
```

### getProperty<sup>7+</sup>

getProperty(): PasteDataProperty

Obtains the property of the pasteboard data.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataProperty](#pastedataproperty7) | Property of the pasteboard data.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let property = pasteData.getProperty();
```

### setProperty<sup>9+</sup>

setProperty(property: PasteDataProperty): void

Sets the property (attributes) for the pasteboard data. Currently, only the **shareOption** attribute is supported.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| property | [PasteDataProperty](#pastedataproperty7) | Yes| Property of the pasteboard data.|

**Example**

```js
let pasteData = pasteboard.createHtmlData('application/xml');
let prop = pasteData.getProperty();
prop.shareOption = pasteboard.ShareOption.InApp;
pasteData.setProperty(prop);
```

### getRecord<sup>9+</sup>

getRecord(index: number): PasteDataRecord

Obtains the specified record in the pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Index of the target record.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | Record with the specified index.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](../errorcodes/errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of range. |

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let record = pasteData.getRecord(0);
```

### getRecordCount<sup>7+</sup>

getRecordCount(): number

Obtains the number of records in the pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of records.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let count = pasteData.getRecordCount();
```

### getTag<sup>7+</sup>

getTag(): string

Obtains the custom tag from the pasteboard. If no custom tag is set, null is returned.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Custom tag. If no custom tag is set, null is returned.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let tag = pasteData.getTag();
```

### hasType<sup>9+</sup>

hasType(mimeType: string): boolean

Checks whether the pasteboard contains data of the specified type.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| Type of the data to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified data type exists; returns **false** otherwise.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let hasType = pasteData.hasType(pasteboard.MIMETYPE_TEXT_PLAIN);
```

### removeRecord<sup>9+</sup>

removeRecord(index: number): void

Removes the record with the specified index from the pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](../errorcodes/errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of range. |

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
pasteData.removeRecord(0);
```

### replaceRecord<sup>9+</sup>

replaceRecord(index: number, record: PasteDataRecord): void

Replaces the record with the specified index in the pasteboard with a new record.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index.|
| record | [PasteDataRecord](#pastedatarecord7) | Yes| New record.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](../errorcodes/errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of range. |

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
pasteData.replaceRecord(0, record);
```
### addHtmlRecord<sup>(deprecated)</sup>

addHtmlRecord(htmlText: string): void

Adds an HTML record to this pasteboard, and adds **MIMETYPE_TEXT_HTML** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 512 data records.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML content.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
pasteData.addHtmlRecord(html);
```

### addWantRecord<sup>(deprecated)</sup>

addWantRecord(want: Want): void

Adds a Want record to this pasteboard, and adds **MIMETYPE_TEXT_WANT** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 512 data records.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want object.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let object = { 
    bundleName: "com.example.aafwk.test",    
    abilityName: "com.example.aafwk.test.TwoAbility"
};
pasteData.addWantRecord(object);
```

### addTextRecord<sup>(deprecated)</sup>

addTextRecord(text: string): void

Adds a plain text record to this pasteboard, and adds **MIME_TEXT_PLAIN** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 512 data records.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Plain text.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
pasteData.addTextRecord('good');
```

### addUriRecord<sup>(deprecated)</sup>

addUriRecord(uri: string): void

Adds a URI record to this pasteboard, and adds **MIMETYPE_TEXT_URI** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 512 data records.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI content.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
pasteData.addUriRecord('dataability:///com.example.myapplication1/user.txt');
```
### getRecordAt<sup>(deprecated)</sup>

getRecordAt(index: number): PasteDataRecord

Obtains the specified record in the pasteboard.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getRecord](#getrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Index of the target record.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | Record with the specified index.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let record = pasteData.getRecordAt(0);
```

### hasMimeType<sup>(deprecated)</sup>

hasMimeType(mimeType: string): boolean

Checks whether the pasteboard contains data of the specified type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasType](#hastype9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| Type of the data to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified data type exists; returns **false** otherwise.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let hasType = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
```
### removeRecordAt<sup>(deprecated)</sup>

removeRecordAt(index: number): boolean

Removes the record with the specified index from the pasteboard.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [removeRecord](#removerecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let isRemove = pasteData.removeRecordAt(0);
```
### replaceRecordAt<sup>(deprecated)</sup>

replaceRecordAt(index: number, record: PasteDataRecord): boolean

Replaces the record with the specified index in the pasteboard with a new record.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [replaceRecord](#replacerecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index.|
| record | [PasteDataRecord](#pastedatarecord7) | Yes| New record.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
let isReplace = pasteData.replaceRecordAt(0, record);
```

## SystemPasteboard

Provides **SystemPasteboard** APIs.

Before calling any **SystemPasteboard** API, you must obtain a **SystemPasteboard** object using [getSystemPasteboard](#pasteboardgetsystempasteboard).

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
```

### on('update')<sup>7+</sup>

on(type:  'update', callback: () =&gt;void ): void

Subscribes to the content change event of the system pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value **'update'** indicates changes in the pasteboard content.|
| callback | function | Yes| Callback invoked when the pasteboard content changes.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The system pasteboard has changed.');
};
systemPasteboard.on('update', listener);
```

### off('update')<sup>7+</sup>

off(type:  'update', callback?: () =&gt;void ): void

Unsubscribes from the system pasteboard content change event.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value **'update'** indicates changes in the pasteboard content.|
| callback | function | No| Callback invoked when the pasteboard content changes.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The system pasteboard has changed.');
};
systemPasteboard.off('update', listener);
```

### clearData<sup>9+</sup>

clearData(callback: AsyncCallback&lt;void&gt;): void

Clears the system pasteboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
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

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clearData().then((data) => { 
    console.info('Succeeded in clearing the pasteboard.');
}).catch((err) => {
    console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
});
```

### setData<sup>9+</sup>

setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|
| callback | AsyncCallback&lt;void> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](../errorcodes/errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900003 | Another copy or paste is in progress. |
| 12900004 | Replication is prohibited. |

**Example**

```js
let pasteData = pasteboard.createPlainTextData('content');
let systemPasteboard = pasteboard.getSystemPasteboard();
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

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](../errorcodes/errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900003 | Another copy or paste is in progress. |
| 12900004 | Replication is prohibited. |

**Example**

```js
let pasteData = pasteboard.createPlainTextData('content');
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setData(pasteData).then((data) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```

### getData<sup>9+</sup>

getData( callback: AsyncCallback&lt;PasteData&gt;): void

Obtains a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the system pasteboard data. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](../errorcodes/errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900003 | Another copy or paste is in progress. |

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err, pasteData) => {  
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    let text = pasteData.getPrimaryText();
});
```

### getData<sup>9+</sup>

getData(): Promise&lt;PasteData&gt;

Obtains a **PasteData** object from the pasteboard. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](../errorcodes/errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900003 | Another copy or paste is in progress. |

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData) => { 
    let text = pasteData.getPrimaryText();
}).catch((err) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
})
```

### hasData<sup>9+</sup>

hasData(callback:  AsyncCallback&lt;boolean&gt;): void

Checks whether the system pasteboard contains data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData((err, data) => {
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

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData().then((data) => { 
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### clear<sup>(deprecated)</sup>

clear(callback: AsyncCallback&lt;void&gt;): void

Clears the system pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.clearData](#cleardata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```js
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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.clearData](#cleardata9-1).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
systemPasteboard.clear().then((data) => { 
    console.info('Succeeded in clearing the PasteData.');
}).catch((err) => {    
    console.error(`Failed to clear the PasteData. Cause: ${err.message}`);
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData( callback: AsyncCallback&lt;PasteData&gt;): void

Obtains a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getData](#getdata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the system pasteboard data. Otherwise, **err** is an error object.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData((err, pasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    let text = pasteData.getPrimaryText();
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData(): Promise&lt;PasteData&gt;

Obtains a **PasteData** object from the pasteboard. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getData](#getdata9-1).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Example**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData().then((pasteData) => { 
    let text = pasteData.getPrimaryText();
}).catch((err) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
})
```

### hasPasteData<sup>(deprecated)</sup>

hasPasteData(callback:  AsyncCallback&lt;boolean&gt;): void

Checks whether the system pasteboard contains data. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasData](#hasdata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```js
systemPasteboard.hasPasteData((err, data) => {
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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasData](#hasdata9-1).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```js
systemPasteboard.hasPasteData().then((data) => { 
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setData](#setdata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|
| callback | AsyncCallback&lt;void> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```js
let pasteData = pasteboard.createPlainTextData('content');
let systemPasteboard = pasteboard.getSystemPasteboard();
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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setData](#setdata9-1).

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

```js
let pasteData = pasteboard.createPlainTextData('content');
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData).then((data) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```
