# document

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE:**<br/>
- The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
- The interface of this module will be discarded later.Calling the following interface throws an exception. It is not recommended to use the following interface in OpenHarmony.

## Modules to Import

```js
import document from '@ohos.document';
```

## document.choose

choose(type:string[]): Promise&lt;string&gt;

Selects a file using the file manager and returns the file URI asynchronously using a promise.

**System capability**：SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | type   | string[] | No   | Type of the file selected.  |

- Return value

  | Type                 | Description        |
  | --------------------- | -------------- |
  | Promise&lt;string&gt; | URI of the file（Note: the current returned error code） |

- Example

  ```js
  await document.choose(type);
  ```
## document.choose

choose(callback:AsyncCallback&lt;string&gt;): void

Selects a file using the file manager and returns the file URI using an asynchronous callback.

**System capability**：SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to obtain the URI of the file asynchronously（Note: the current returned error code） |

- Example

  ```js
  await document.choose(function(err, uri) {
        //do something with uri
  });
  ```
## document.choose

choose(type:string[], callback:AsyncCallback&lt;string&gt;): void

Selects a file using the file manager and returns the file URI using an asynchronous callback.

**System capability**：SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | type     | string[]                      | No   | Type of the file selected. |
  | callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to obtain the URI of the file asynchronously（Note: the current returned error code） |

- Example

  ```js
  await document.choose(type, function(err, uri) {
        //do something with uri
  });
  ```

## document.show

show(url:string, type:string):Promise&lt;number&gt;

Asynchronously opens the file corresponding to the URI and returns the result using a promise.

**System capability**：SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | ---- | ------ | ---- | ---------------------------- |
  | uri | string | Yes   | URI of the file to open |
  | type | string | Yes   | Type of the file. Currently |

- Return value

  | Type                 | Description        |
  | --------------------- | ------------ |
  | Promise&lt;void&gt; | Returns void if the file is open successfully（Note: the current returned error code） |

- Example

  ```js
  await document.show(uri, type);
  ```

## document.show

show(url:string, type:string, callback:AsyncCallback&lt;void&gt;): void

Asynchronously opens the file corresponding to the URI and returns the result using a callback.

**System capability**：SystemCapability.FileManagement.File.FileIO

- **Parameters**

  | Name  | Type                       | Mandatory| Description                        |
  | -------- | --------------------------- | ---- | ---------------------------- |
  | uri | string | Yes   | URI of the file to open|
  | type | string | Yes   | Type of the file. Currently |
  | callback | AsyncCallback&lt;void&gt; | Yes   | Asynchronous callback used to open the file corresponding to the URI（Note: the current returned error code）   |

- Example

  ```js
  await document.show(uri, type, function(err) {
        //do something
  });
  ```

