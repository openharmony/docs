# File Interaction

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
- The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
- The APIs of this module will be deprecated and are not recommended for use. An exception will be thrown if any of the APIs is called.

## Modules to Import

```js
import document from '@ohos.document';
```

## document.choose

choose(type:string[]): Promise&lt;string&gt;

Chooses a file of the specified type using the file manager. This method uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- Parameters

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | type   | string[] | No  | Type of the file to choose.|

- Return value

  | Type                 | Description          |
  | --------------------- | -------------- |
  | Promise&lt;string&gt; | Promise used to return the result. An error code is returned.|

- Example

  ```js
  await document.choose(type);
  ```
## document.choose

choose(callback:AsyncCallback&lt;string&gt;): void

Chooses a file using the file manager. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- Parameters

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. An error code is returned.|

- Example

  ```js
  await document.choose(function(err, uri) {
        // Do something with the URI. 
  });
  ```
## document.choose

choose(type:string[], callback:AsyncCallback&lt;string&gt;): void

Chooses a file of the specified type using the file manager. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- Parameters

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | type     | string[]                      | No  | Type of the file to choose.|
  | callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. An error code is returned.|

- Example

  ```js
  await document.choose(type, function(err, uri) {
        // Do something with the URI. 
  });
  ```

## document.show

show(url:string, type:string):Promise&lt;number&gt;

Opens a file. This method uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- Parameters

  | Name| Type  | Mandatory| Description                        |
  | ---- | ------ | ---- | ---------------------------- |
  | uri | string | Yes  | URI of the file to open.|
  | type | string | Yes  | Type of the file to open.|

- Return value

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;void&gt; | Promise used to return the result. An error code is returned.|

- Example

  ```js
  await document.show(uri, type);
  ```

## document.show

show(url:string, type:string, callback:AsyncCallback&lt;void&gt;): void

Opens a file. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.File.FileIO

- Parameters

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | uri | string | Yes  | URI of the file to open.|
  | type | string | Yes  | Type of the file to open.|
  | callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. An error code is returned.  |

- Example

  ```js
  await document.show(uri, type, function(err) {
        //do something
  });
  ```
