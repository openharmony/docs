# Pasteboard


> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import pasteboard from '@ohos.pasteboard';
```


## Attributes

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| MAX_RECORD_NUM<sup>7+</sup> | number | Yes | No | Maximum&nbsp;number&nbsp;of&nbsp;records&nbsp;allowed&nbsp;in&nbsp;a&nbsp;**PasteData**&nbsp;object. |
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | Yes | No | MIME&nbsp;type&nbsp;of&nbsp;the&nbsp;HTML&nbsp;text. |
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | Yes | No | MIME&nbsp;type&nbsp;of&nbsp;the&nbsp;Want&nbsp;text. |
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | Yes | No | MIME&nbsp;type&nbsp;of&nbsp;the&nbsp;plain&nbsp;text. |
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | Yes | No | MIME&nbsp;type&nbsp;of&nbsp;the&nbsp;URI&nbsp;text. |


## pasteboard.createPlainTextData

createPlainTextData(text:string): PasteData

Creates a **PasteData** object for plain text.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | text | string | Yes | Plain&nbsp;text. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteData](#pastedata) | **PasteData**&nbsp;object&nbsp;with&nbsp;the&nbsp;specified&nbsp;content. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("content");
  ```


## pasteboard.createHtmlData<sup>7+</sup>

createHtmlData(htmlText:string): PasteData

Creates a **PasteData** object for HTML text.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | htmlText | string | Yes | HTML&nbsp;text. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteData](#pastedata) | **PasteData**&nbsp;object&nbsp;with&nbsp;the&nbsp;specified&nbsp;content. |

- Example
  
  ```
  var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
  var pasteData = pasteboard.createHtmlData(html);
  ```


## pasteboard.createWantData<sup>7+</sup>

createWantData(want:Want): PasteData

Creates a **PasteData** object for Want text.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#want) | Yes | Want&nbsp;text. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteData](#pastedata) | **PasteData**&nbsp;object&nbsp;with&nbsp;the&nbsp;specified&nbsp;content. |

- Example
  
  ```
  var object = {
      bundleName: "com.example.aafwk.test",
      abilityName: "com.example.aafwk.test.TwoAbility"
  };
  var pasteData = pasteboard.createWantData(object);
  ```


## pasteboard.createUriData<sup>7+</sup>

createUriData(uri:string): PasteData

Creates a **PasteData** object for URI text.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | uri | string | Yes | URI&nbsp;text. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteData](#pastedata) | **PasteData**&nbsp;object&nbsp;with&nbsp;the&nbsp;specified&nbsp;content. |

- Example
  
  ```
  var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1?user.txt");
  ```


## pasteboard.createPlainTextRecord<sup>7+</sup>

createPlainTextRecord(text:string): PasteDataRecord

Creates a **PasteDataRecord** object of the plain text type.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | text | string | Yes | Plain&nbsp;text. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteDataRecord](#pastedatarecord7) | New&nbsp;plain&nbsp;text&nbsp;record. |

- Example
  
  ```
  var record = pasteboard.createPlainTextRecord("hello");
  ```


## pasteboard.createHtmlTextRecord<sup>7+</sup>

createHtmlTextRecord(htmlText:string): PasteDataRecord

Creates a **PasteDataRecord** object of the HTML text type.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | htmlText | string | Yes | HTML&nbsp;text. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteDataRecord](#pastedatarecord7) | New&nbsp;HTML&nbsp;record. |

- Example
  
  ```
  var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
  var record = pasteboard.createHtmlTextRecord(html);
  ```


## pasteboard.createWantRecord<sup>7+</sup>

createWantRecord(want:Want): PasteDataRecord

Creates a **PasteDataRecord** object of the Want text type.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#want) | Yes | Want&nbsp;text. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteDataRecord](#pastedatarecord7) | New&nbsp;Want&nbsp;record. |

- Example
  
  ```
  var object = {
      bundleName: "com.example.aafwk.test",
      abilityName: "com.example.aafwk.test.TwoAbility"
  };
  var record = pasteboard.createWantRecord(object);
  ```


## pasteboard.createUriRecord<sup>7+</sup>

createUriRecord(uri:string): PasteDataRecord

Creates a **PasteDataRecord** object of the URI text type.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | uri | string | Yes | URI&nbsp;text. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteDataRecord](#pastedatarecord7) | New&nbsp;URI&nbsp;record. |

- Example
  
  ```
  var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1?user.txt");
  ```


## PasteDataProperty<sup>7+</sup>

Defines the properties of all data records on the pasteboard, including the timestamp, data type, and additional data.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| additions | {[key:&nbsp;string]:&nbsp;object} | Yes | Yes | Additional&nbsp;property&nbsp;data. |
| mimeTypes | Array&lt;string&gt; | Yes | No | Non-repeating&nbsp;data&nbsp;types&nbsp;of&nbsp;the&nbsp;data&nbsp;records&nbsp;on&nbsp;the&nbsp;pasteboard. |
| tag | string | Yes | Yes | User-defined&nbsp;tag. |
| timestamp | number | Yes | No | Timestamp&nbsp;at&nbsp;which&nbsp;the&nbsp;data&nbsp;is&nbsp;written&nbsp;to&nbsp;the&nbsp;pasteboard,&nbsp;in&nbsp;milliseconds. |
| localOnly | boolean | Yes | Yes | Whether&nbsp;local&nbsp;access&nbsp;only&nbsp;is&nbsp;set&nbsp;for&nbsp;the&nbsp;pasteboard.<br/>-&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**true**.<br/>-&nbsp;**true**:&nbsp;The&nbsp;**PasteData**&nbsp;is&nbsp;set&nbsp;for&nbsp;local&nbsp;access&nbsp;only.<br/>-&nbsp;**false**:&nbsp;The&nbsp;**PasteData**&nbsp;can&nbsp;be&nbsp;shared&nbsp;between&nbsp;devices. |


## PasteDataRecord<sup>7+</sup>

A data record is an abstract definition of the content on the pasteboard. The pasteboard content consists of one or more plain text, HTML, URI, or Want records.


### Attributes

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| htmlText<sup>7+</sup> | string | Yes | No | HTML&nbsp;text. |
| want<sup>7+</sup> | [Want](js-apis-featureAbility.md#want) | Yes | No | Want&nbsp;text. |
| mimeType<sup>7+</sup> | string | Yes | No | Data&nbsp;type. |
| plainText<sup>7+</sup> | string | Yes | No | Plain&nbsp;text. |
| uri<sup>7+</sup> | string | Yes | No | URI&nbsp;text. |


### convertToText<sup>7+</sup>

convertToText(): Promise&lt;string&gt;

Forcibly converts the content in this **PasteData** object to the plain text. This method uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful,&nbsp;the&nbsp;plain&nbsp;text&nbsp;content&nbsp;after&nbsp;conversion&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;error&nbsp;information&nbsp;is&nbsp;returned. |

- Example
  
  ```
  var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1?user.txt");
  record.convertToText().then((data) => {
      console.info('convertToText success data : ' + JSON.stringify(data));
  }).catch((error) => { 
      console.error('convertToText failed because ' + JSON.stringify(error));
  });
  ```


### convertToText<sup>7+</sup>

convertToText(callback: AsyncCallback&lt;string&gt;): void

Forcibly converts the content in this **PasteData** object to the plain text. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;string&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;If&nbsp;this&nbsp;callback&nbsp;is&nbsp;successful,&nbsp;the&nbsp;plain&nbsp;text&nbsp;content&nbsp;after&nbsp;conversion&nbsp;is&nbsp;returned.&nbsp;Otherwise,&nbsp;error&nbsp;information&nbsp;is&nbsp;returned. |

- Example
  
  ```
  var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1?user.txt");
  record.convertToText((err, data) => {    
      if (err) {        
          console.error('convertToText failed because ' + JSON.stringify(err));        
          return;   
        }
      console.info('convertToText success data : ' + JSON.stringify(data));
  });
  ```


## PasteData

Before calling any **PasteData** method, you must obtain a **PasteData** object.

**System capability**: SystemCapability.MiscServices.Pasteboard


### getPrimaryText


getPrimaryText(): string


Obtains the plain text of the primary record.


**System capability**: SystemCapability.MiscServices.Pasteboard


- Parameters
  None


- Return values
    | Type | Description |
  | -------- | -------- |
  | string | Plain&nbsp;text. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var plainText = pasteData.getPrimaryText();
  ```


### getPrimaryHtml<sup>7+</sup>

getPrimaryHtml(): string

Obtains the HTML text of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | string | HTML&nbsp;text. |

- Example
  
  ```
  var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
  var pasteData = pasteboard.createHtmlData(html);
  var htmlText = pasteData.getPrimaryHtml();
  ```


### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

Obtains the **Want** object of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | [Want](js-apis-featureAbility.md#want) | Want&nbsp;object. |

- Example
  
  ```
  var object = { 
      bundleName: "com.example.aafwk.test",    
      abilityName: "com.example.aafwk.test.TwoAbility"
  };
  var pasteData = pasteboard.createWantData(object);
  var want = pasteData.getPrimaryWant();
  ```


### getPrimaryUri<sup>7+</sup>

getPrimaryUri(): string

Obtains the URI text of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | string | URI&nbsp;text. |

- Example
  
  ```
  var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1?user.txt");
  var uri = pasteData.getPrimaryUri();
  ```


### addTextRecord<sup>7+</sup>

addTextRecord(text: string): void

Adds a plain text record to this pasteboard, and adds **MIME_TEXT_PLAIN** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | text | string | Yes | Plain&nbsp;text. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  pasteData.addTextRecord("good");
  ```


### addHtmlRecord<sup>7+</sup>

addHtmlRecord(htmlText: string): void

Adds an HTML text record to this pasteboard, and adds **MIMETYPE_TEXT_HTML** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | htmlText | string | Yes | HTML&nbsp;text. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
  pasteData.addHtmlRecord(html);
  ```


### addWantRecord<sup>7+</sup>

addWantRecord(want: Want): void

Adds a Want text record to this pasteboard, and adds **MIMETYPE_TEXT_WANT** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#want) | Yes | Want&nbsp;object. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var object = { 
      bundleName: "com.example.aafwk.test",    
      abilityName: "com.example.aafwk.test.TwoAbility"
  };
  pasteData.addWantRecord(object);
  ```


### addUriRecord<sup>7+</sup>

addUriRecord(uri: string): void

Adds a URI text record to this pasteboard, and adds **MIMETYPE_TEXT_URI** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | uri | string | Yes | URI&nbsp;text. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  pasteData.addUriRecord("dataability:///com.example.myapplication1?user.txt");
  ```


### addRecord<sup>7+</sup>

addRecord(record: PasteDataRecord): void

Adds a data record to this pasteboard, and adds its type to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

The pasteboard supports a maximum number of 128 data records.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | record | [PasteDataRecord](#pastedatarecord7) | Yes | Record&nbsp;to&nbsp;add. |

- Example
  
  ```
  var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1?user.txt");
  var textRecord = pasteboard.createPlainTextRecord("hello");
  var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
  var htmlRecord = pasteboard.createHtmlTextRecord(html);
  pasteData.addRecord(textRecord);
  pasteData.addRecord(htmlRecord);
  ```


### getMimeTypes<sup>7+</sup>

getMimeTypes(): Array&lt;string&gt;

Obtains **mimeTypes** in [PasteDataProperty](#pastedataproperty7) from this pasteboard. If the pasteboard is empty, the returned list is also empty.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | Array&lt;string&gt; | List&nbsp;of&nbsp;non-duplicate&nbsp;MIME&nbsp;types. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var types = pasteData.getMimeTypes();
  ```


### getPrimaryMimeType<sup>7+</sup>

getPrimaryMimeType(): string

Obtains the data type of the primary record.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | string | Data&nbsp;type&nbsp;of&nbsp;the&nbsp;primary&nbsp;record. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var type = pasteData.getPrimaryMimeType();
  ```


### getProperty<sup>7+</sup>

getProperty(): PasteDataProperty

Obtains the property description object.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteDataProperty](#pastedataproperty7) | Property&nbsp;description&nbsp;object. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var property = pasteData.getProperty();
  ```


### getRecordAt<sup>7+</sup>

getRecordAt(index: number): PasteDataRecord

Obtains the record with the specified index.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | index | number | Yes | Index&nbsp;of&nbsp;the&nbsp;specified&nbsp;record. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | [PasteDataRecord](#pastedatarecord7) | Record&nbsp;with&nbsp;the&nbsp;specified&nbsp;index. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var record = pasteData.getRecordAt(0);
  ```


### getRecordCount<sup>7+</sup>

getRecordCount(): number

Obtains the number of data records in this pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | number | Number&nbsp;of&nbsp;records. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var count = pasteData.getRecordCount();
  ```


### getTag<sup>7+</sup>

getTag(): string

Obtains the user-defined tag content. If the tag content is not set, null is returned.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | string | User-defined&nbsp;tag&nbsp;content&nbsp;if&nbsp;obtained&nbsp;and&nbsp;null&nbsp;if&nbsp;no&nbsp;tag&nbsp;is&nbsp;set. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var tag = pasteData.getTag();
  ```


### hasMimeType<sup>7+</sup>

hasMimeType(mimeType: string): boolean

Checks whether the content of this pasteboard contains the specified data type.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | mimeType | string | Yes | Type&nbsp;of&nbsp;the&nbsp;data&nbsp;to&nbsp;query. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;specified&nbsp;data&nbsp;type&nbsp;exists;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var hasType = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
  ```


### removeRecordAt<sup>7+</sup>

removeRecordAt(index: number): boolean

Removes the data record with a specified index from this pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | index | number | Yes | Specified&nbsp;index. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var isRemove = pasteData.removeRecordAt(0);
  ```


### replaceRecordAt<sup>7+</sup>

replaceRecordAt(index: number, record: PasteDataRecord): boolean

Replaces the data record with a specified index in this pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | index | number | Yes | Specified&nbsp;index. |
  | record | [PasteDataRecord](#pastedatarecord7) | Yes | New&nbsp;record. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("hello");
  var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1?user.txt");
  var isReplace = pasteData.replaceRecordAt(0, record);
  ```


## pasteboard.getSystemPasteboard

getSystemPasteboard(): SystemPasteboard

Obtains the system pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | [SystemPasteboard](#systempasteboard) | System&nbsp;pasteboard. |

- Example
  
  ```
  var systemPasteboard = pasteboard.getSystemPasteboard();
  ```


## SystemPasteboard

  Before calling any **SystemPasteboard** method, you must obtain a **SystemPasteboard** object using [getSystemPasteboard](#pasteboardgetsystempasteboard).

```
var systemPasteboard = pasteboard.getSystemPasteboard();
```


### setPasteData

setPasteData(data:PasteData, callback:AsyncCallback&lt;void&gt;): void

Writes data to a pasteboard. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | data | [PasteData](#pastedata) | Yes | **PasteData**&nbsp;object. |
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;data&nbsp;write&nbsp;result. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("content");
  var systemPasteboard = pasteboard.getSystemPasteboard();
  systemPasteboard.setPasteData(pasteData, (error, data) => { 
      if (error) {
          console.error('Failed to setPasteData. Cause: ' + error.message);
          return;
      }
      console.info('setPasteData successfully.');
  });
  ```


### setPasteData

setPasteData(data:PasteData): Promise&lt;void&gt;

Writes data to a pasteboard. This method uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Description |
  | -------- | -------- | -------- |
  | data | [PasteData](#pastedata) | **PasteData**&nbsp;object. |

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;data&nbsp;write&nbsp;result. |

- Example
  
  ```
  var pasteData = pasteboard.createPlainTextData("content");
  var systemPasteboard = pasteboard.getSystemPasteboard();
  systemPasteboard.setPasteData(pasteData).then((data) => {
      console.info('setPasteData success.');
  }).catch((error) => {
      console.error('Failed to setPasteData. Cause: ' + error.message);
  });
  ```


### getPasteData

getPasteData( callback:AsyncCallback&lt;PasteData&gt;): void

Reads the system pasteboard content. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;system&nbsp;pasteboard&nbsp;data. |

- Example
  
  ```
  var systemPasteboard = pasteboard.getSystemPasteboard();
  systemPasteboard.getPasteData((error, pasteData) => {  
      if (error) {
          console.error('Failed to getPasteData. Cause: ' + error.message);
          return;
      }
      var text = pasteData.getPrimaryText();
  });
  ```


### getPasteData

getPasteData(): Promise&lt;PasteData&gt;

Reads the system pasteboard content. This method uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;[PasteData](#pastedata)&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;system&nbsp;pasteboard&nbsp;data. |

- Example
  
  ```
  var systemPasteboard = pasteboard.getSystemPasteboard();
  systemPasteboard.getPasteData().then((pasteData) => { 
      var text = pasteData.getPrimaryText();
  }).catch((error) => {
      console.error('Failed to getPasteData. Cause: ' + error.message);
  })
  ```


### on('update')<sup>7+</sup>

on(type:  'update', callback: () =&gt;void ): void

Subscribes to the content change event of the system pasteboard. If the pasteboard content changes, the callback is triggered.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Data&nbsp;type.&nbsp;The&nbsp;value&nbsp;**update**&nbsp;indicates&nbsp;the&nbsp;pasteboard&nbsp;content&nbsp;has&nbsp;changed. |
  | callback | function | Yes | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;pasteboard&nbsp;content&nbsp;changes. |

- Example
  
  ```
  var systemPasteboard = pasteboard.getSystemPasteboard();
  var listener = ()=>{
      console.info('The system pasteboard has changed');
  };
  systemPasteboard.on('update', listener);
  ```


### off('update')<sup>7+</sup>

off(type: 'update', callback? : () =&gt;void ): void

Unsubscribes from the system pasteboard content change event.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Data&nbsp;type.&nbsp;The&nbsp;value&nbsp;**update**&nbsp;indicates&nbsp;the&nbsp;pasteboard&nbsp;content&nbsp;has&nbsp;changed. |
  | callback | function | No | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;pasteboard&nbsp;content&nbsp;changes. |

- Example
  
  ```
  systemPasteboard.off('update', listener);
  ```


### hasPasteData<sup>7+</sup>

hasPasteData(callback:  AsyncCallback&lt;boolean&gt;): void

Checks whether the system pasteboard contains content. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;pasteboard&nbsp;contains&nbsp;content;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
  systemPasteboard.hasPasteData((err, data) => {
      if (err) {
          console.error('failed to hasPasteData because ' + JSON.stringify(err));
          return;
      }
      console.info('success hasPasteData : ' + JSON.stringify(data));
  });
  ```


### hasPasteData<sup>7+</sup>

hasPasteData():  Promise&lt;boolean&gt;

Checks whether the system pasteboard contains content. This method uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;pasteboard&nbsp;contains&nbsp;content;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

- Example
  
  ```
  systemPasteboard.hasPasteData().then((data) => { 
      console.info('Operation succeeded. ' + JSON.stringify(data));
  }).catch((error) => {
      console.error('failed to hasPasteData because ' + JSON.stringify(error));
  });
  ```


### clear<sup>7+</sup>

clear(callback:  AsyncCallback&lt;void&gt;): void

Clears the system pasteboard content. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Parameters
    | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  systemPasteboard.clear((err, data) => { 
      if (err) {        
          console.error('failed to clear because ' + JSON.stringify(err));        
          return;    
      }
      console.info('success clear');
  });
  ```


### clear<sup>7+</sup>

clear():  Promise&lt;void&gt;

Clears the system pasteboard content. This method uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

- Return values
    | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |

- Example
  
  ```
  systemPasteboard.clear().then((data) => { 
      console.info('success clear');
  }).catch((error) => {    
      console.error('failed to clear because ' + JSON.stringify(error));
  });
  ```
