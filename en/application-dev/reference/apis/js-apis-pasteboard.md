# Pasteboard

The **pasteboard** module provides the copy and paste support for the system pasteboard. You can use the APIs of this module to operate pasteboard content of the plain text, HTML, URI, Want, pixel map, and other types.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import pasteboard from '@ohos.pasteboard';
```

## Attributes

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| MAX_RECORD_NUM<sup>7+</sup> | number | Yes| No| Maximum number of records in a **PasteData** object.|
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | Yes| No| MIME type of the HTML content.|
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | Yes| No| MIME type of the Want content.|
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | Yes| No| MIME type of the plain text content.|
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | Yes| No| MIME type of the URI content.|


## pasteboard.createPlainTextData

createPlainTextData(text: string): PasteData

Creates a **PasteData** object of the plain text type.

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
var pasteData = pasteboard.createPlainTextData("content");
```


## pasteboard.createHtmlData<sup>7+</sup>

createHtmlData(htmlText: string): PasteData

Creates a **PasteData** object of the HTML type.

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
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
var pasteData = pasteboard.createHtmlData(html);
```


## pasteboard.createWantData<sup>7+</sup>

createWantData(want: Want): PasteData

Creates a **PasteData** object of the Want type.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#want) | Yes| Want content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```js
var object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
var pasteData = pasteboard.createWantData(object);
```


## pasteboard.createUriData<sup>7+</sup>

createUriData(uri: string): PasteData

Creates a **PasteData** object of the URI type.

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
var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1/user.txt");
```

## pasteboard.createPlainTextRecord<sup>7+</sup>

createPlainTextRecord(text: string): PasteDataRecord

Creates a **PasteDataRecord** object of the plain text type.

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
var record = pasteboard.createPlainTextRecord("hello");
```


## pasteboard.createHtmlTextRecord<sup>7+</sup>

createHtmlTextRecord(htmlText: string): PasteDataRecord

Creates a **PasteDataRecord** object of the HTML text type.

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
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
var record = pasteboard.createHtmlTextRecord(html);
```


## pasteboard.createWantRecord<sup>7+</sup>

createWantRecord(want: Want): PasteDataRecord

Creates a **PasteDataRecord** object of the Want type.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#want) | Yes| Want content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the Want type.|

**Example**

```js
var object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
var record = pasteboard.createWantRecord(object);
```


## pasteboard.createUriRecord<sup>7+</sup>

createUriRecord(uri: string): PasteDataRecord

Creates a **PasteDataRecord** object of the URI type.

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
var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1/user.txt");
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
var systemPasteboard = pasteboard.getSystemPasteboard();
```


## PasteDataProperty<sup>7+</sup>

Defines the properties of all data records on the pasteboard, including the timestamp, data type, and additional data.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| additions | {[key:string]:object} | Yes| Yes| Additional data. This attribute is not supported currently. |
| mimeTypes | Array&lt;string&gt; | Yes| No| Non-repeating data types of the data records on the pasteboard.|
| tag | string | Yes| Yes| Custom tag. This attribute is not supported currently. |
| timestamp | number | Yes| No| Timestamp when data is written to the pasteboard (unit: ms).|
| localOnly | boolean | Yes| Yes| Whether the pasteboard content is set for local access only. The default value is **true**. This attribute is not supported currently.<br>- **true**: The pasteboard content is set for local access only.<br>- **false**: The pasteboard content can be shared between devices. |


## PasteDataRecord<sup>7+</sup>

Provides **PasteDataRecord** APIs. A **PasteDataRecord** is an abstract definition of the content on the pasteboard. The pasteboard content consists of one or more plain text, HTML, URI, or Want records.


### Attributes

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| htmlText<sup>7+</sup> | string | Yes| No| HTML content.|
| want<sup>7+</sup> | [Want](js-apis-featureAbility.md#want) | Yes| No| Want content.|
| mimeType<sup>7+</sup> | string | Yes| No| Data type.|
| plainText<sup>7+</sup> | string | Yes| No| Plain text.|
| uri<sup>7+</sup> | string | Yes| No| URI content.|


### convertToText<sup>7+</sup>

convertToText(): Promise&lt;string&gt;

Forcibly converts the content in a **PasteData** object to text. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the text obtained from the conversion.|

**Example**

```js
var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1/user.txt");
record.convertToText().then((data) => {
    console.info('Succeeded in converting to text. Data: ' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to convert to text. Cause: ' + JSON.stringify(err));
});
```


### convertToText<sup>7+</sup>

convertToText(callback: AsyncCallback&lt;string&gt;): void

Forcibly converts the content in a **PasteData** object to text. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the text obtained from the conversion. Otherwise, **err** is error information.|

**Example**

```js
var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1/user.txt");
record.convertToText((err, data) => {
    if (err) {
        console.error('Failed to convert to text. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in converting to text. Data: ' + JSON.stringify(data));
});
```


## PasteData

Implements a **PasteData** object. Paste data contains one or more data records ([PasteDataRecord](#pastedatarecord7)) and property description objects ([PasteDataProperty](#pastedataproperty7)).

Before calling any API in **PasteData**, you must use [createPlainTextData()](#pasteboardcreateplaintextdata), [createHtmlData()](#pasteboardcreatehtmldata7), [createUriData()](#pasteboardcreateuridata7), [createWantData()](#pasteboardcreatewantdata7), or [getPasteData()](#getpastedata) to create a **PasteData** object.

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
var pasteData = pasteboard.createPlainTextData("hello");
var plainText = pasteData.getPrimaryText();
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
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
var pasteData = pasteboard.createHtmlData(html);
var htmlText = pasteData.getPrimaryHtml();
```


### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

Obtains the Want object of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [Want](js-apis-featureAbility.md#want) | Want object.|

**Example**

```js
var object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
var pasteData = pasteboard.createWantData(object);
var want = pasteData.getPrimaryWant();
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
var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1/user.txt");
var uri = pasteData.getPrimaryUri();
```


### addTextRecord<sup>7+</sup>

addTextRecord(text: string): void

Adds a plain text record to this pasteboard, and adds **MIME_TEXT_PLAIN** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Plain text.|

**Example**

```js
var pasteData = pasteboard.createPlainTextData("hello");
pasteData.addTextRecord("good");
```


### addHtmlRecord<sup>7+</sup>

addHtmlRecord(htmlText: string): void

Adds an HTML record to this pasteboard, and adds **MIMETYPE_TEXT_HTML** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML content.|

**Example**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
pasteData.addHtmlRecord(html);
```


### addWantRecord<sup>7+</sup>

addWantRecord(want: Want): void

Adds a Want record to this pasteboard, and adds **MIMETYPE_TEXT_WANT** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-featureAbility.md#want) | Yes| Want object.|

**Example**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
pasteData.addWantRecord(object);
```


### addUriRecord<sup>7+</sup>

addUriRecord(uri: string): void

Adds a URI record to this pasteboard, and adds **MIMETYPE_TEXT_URI** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI content.|

**Example**

```js
var pasteData = pasteboard.createPlainTextData("hello");
pasteData.addUriRecord("dataability:///com.example.myapplication1/user.txt");
```


### addRecord<sup>7+</sup>

addRecord(record: PasteDataRecord): void

Adds a data record to this pasteboard, and adds its type to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| record | [PasteDataRecord](#pastedatarecord7) | Yes| Record to add.|

**Example**

```js
var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1/user.txt");
var textRecord = pasteboard.createPlainTextRecord("hello");
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
var htmlRecord = pasteboard.createHtmlTextRecord(html);
pasteData.addRecord(textRecord);
pasteData.addRecord(htmlRecord);
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
var pasteData = pasteboard.createPlainTextData("hello");
var types = pasteData.getMimeTypes();
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
var pasteData = pasteboard.createPlainTextData("hello");
var type = pasteData.getPrimaryMimeType();
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
var pasteData = pasteboard.createPlainTextData("hello");
var property = pasteData.getProperty();
```

### getRecordAt<sup>7+</sup>

getRecordAt(index: number): PasteDataRecord

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

**Example**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var record = pasteData.getRecordAt(0);
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
var pasteData = pasteboard.createPlainTextData("hello");
var count = pasteData.getRecordCount();
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
var pasteData = pasteboard.createPlainTextData("hello");
var tag = pasteData.getTag();
```


### hasMimeType<sup>7+</sup>

hasMimeType(mimeType: string): boolean

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
var pasteData = pasteboard.createPlainTextData("hello");
var hasType = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
```


### removeRecordAt<sup>7+</sup>

removeRecordAt(index: number): boolean

Removes the record with the specified index from the pasteboard.

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
var pasteData = pasteboard.createPlainTextData("hello");
var isRemove = pasteData.removeRecordAt(0);
```


### replaceRecordAt<sup>7+</sup>

replaceRecordAt(index: number, record: PasteDataRecord): boolean

Replaces the record with the specified index in the pasteboard with a new record.

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
var pasteData = pasteboard.createPlainTextData("hello");
var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1/user.txt");
var isReplace = pasteData.replaceRecordAt(0, record);
```

## SystemPasteboard

Provides **SystemPasteboard** APIs. 

Before calling any **SystemPasteboard** API, you must obtain a **SystemPasteboard** object using [getSystemPasteboard](#pasteboardgetsystempasteboard).

```js
var systemPasteboard = pasteboard.getSystemPasteboard();
```


### setPasteData

setPasteData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|
| callback | AsyncCallback&lt;void> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```js
var pasteData = pasteboard.createPlainTextData("content");
var systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData, (err, data) => { 
    if (err) {
        console.error('Failed to set PasteData. Cause: ' + err.message);
        return;
    }
    console.info('Succeeded in setting PasteData.');
});
```


### setPasteData

setPasteData(data: PasteData): Promise&lt;void&gt;

Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| data | [PasteData](#pastedata) | **PasteData** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var pasteData = pasteboard.createPlainTextData("content");
var systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData).then((data) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```


### getPasteData

getPasteData( callback: AsyncCallback&lt;PasteData&gt;): void

Obtains a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the system pasteboard data. Otherwise, **err** is an error object.|

**Example**

```js
var systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData((err, pasteData) => {  
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    var text = pasteData.getPrimaryText();
});
```


### getPasteData

getPasteData(): Promise&lt;PasteData&gt;

Obtains a **PasteData** object from the pasteboard. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Example**

```js
var systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData().then((pasteData) => { 
    var text = pasteData.getPrimaryText();
}).catch((err) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
})
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
var systemPasteboard = pasteboard.getSystemPasteboard();
var listener = () => {
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
| callback | function | No| Callback invoked when the pasteboard content changes. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application. |

**Example**

```js
let listener = () => {
    console.info('The system pasteboard has changed.');
};    
systemPasteboard.off('update', listener);
```


### hasPasteData<sup>7+</sup>

hasPasteData(callback:  AsyncCallback&lt;boolean&gt;): void

Checks whether the system pasteboard contains data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```js
systemPasteboard.hasPasteData((err, data) => {
    if (err) {
        console.error('Failed to check the PasteData. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in checking the PasteData. Data: ' + JSON.stringify(data));
});
```


### hasPasteData<sup>7+</sup>

hasPasteData(): Promise&lt;boolean&gt;

Checks whether the system pasteboard contains data. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```js
systemPasteboard.hasPasteData().then((data) => { 
    console.info('Succeeded in checking the PasteData. Data: ' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to check the PasteData. Cause: ' + JSON.stringify(err));
});
```


### clear<sup>7+</sup>

clear(callback: AsyncCallback&lt;void&gt;): void

Clears the system pasteboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```js
systemPasteboard.clear((err, data) => { 
    if (err) {        
        console.error('Failed to clear the PasteData. Cause: ' + JSON.stringify(err));        
        return;    
    }
    console.info('Succeeded in clearing the PasteData.');
});
```


### clear<sup>7+</sup>

clear(): Promise&lt;void&gt;

Clears the system pasteboard. This API uses a promise to return the result.

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
    console.error('Failed to clear the PasteData. Cause: ' + JSON.stringify(err));
});
```
