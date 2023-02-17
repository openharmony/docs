# @ohos.document (File Interaction)

> **NOTE**<br/>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module have been deprecated since API version 9 and are not recommended for use. An exception will be thrown if any of the APIs is called.

## Modules to Import

```js
import document from '@ohos.document';
```

## document.choose<sup>(deprecated)</sup>

choose(types? : string[]): Promise&lt;string&gt;

Chooses files of the specified types using the file manager. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | types   | string[] | No  | Types of the files to choose.|

**Return value**

  | Type                 | Description          |
  | --------------------- | -------------- |
  | Promise&lt;string&gt; | Promise used to return the result. An error code is returned.|

**Example**

  ```js
  let types = [];
  document.choose(types);
  ```
## document.choose<sup>(deprecated)</sup>

choose(callback:AsyncCallback&lt;string&gt;): void

Chooses a file using the file manager. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. An error code is returned.|

**Example**

  ```js
  let uri = "";
  document.choose(function(err, uri) {
        // Do something with the URI. 
  });
  ```
## document.choose<sup>(deprecated)</sup>

choose(types:string[], callback:AsyncCallback&lt;string&gt;): void

Chooses files using the file manager. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | types    | string[]                      | No  | Types of the files to choose.|
  | callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. An error code is returned.|

**Example**

  ```js
  let types = [];
  let uri = "";
  document.choose(types, function(err, uri) {
        // Do something with the URI. 
  });
  ```

## document.show<sup>(deprecated)</sup>

show(uri:string, type:string):Promise&lt;void&gt;

Opens a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ---- | ------ | ---- | ---------------------------- |
  | uri | string | Yes  | URI of the file to open.|
  | type | string | Yes  | Type of the file to open.|

**Return value**

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;void&gt; | Promise used to return the result. An error code is returned.|

**Example**

  ```js
  let type = "";
  let uri = "";
  document.show(uri, type);
  ```

## document.show<sup>(deprecated)</sup>

show(uri:string, type:string, callback:AsyncCallback&lt;void&gt;): void

Opens a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | uri | string | Yes  | URI of the file to open.|
  | type | string | Yes  | Type of the file to open.|
  | callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. An error code is returned.  |

**Example**

  ```js
  let type = "";
  let uri = "";
  document.show(uri, type, function(err) {
        //do something
  });
  ```
