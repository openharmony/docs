# Volume Management

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import volumemanager from "@ohos.volumemanager";
```

## System Capabilities

SystemCapability.FileManagement.StorageService.Volume

## volumemanager.getAllVolumes

getAllVolumes(): Promise&lt;Volume[]&gt;

Asynchronously obtains information about all available volumes. This method uses a promise to return the result.

- Return value

  | Type| Description|
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | Promise used to return the execution result.|

- Example

  ```js
  volumemanager.getAllVolumes().then(function(volumes){
      // do something
  });
  ```

## volumemanager.getAllVolumes

getAllVolumes(callback:AsyncCallback&lt;Volume[]&gt;):void

Asynchronously obtains information about all available volumes. This method uses a callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------------------------- | ---- | ------------------------------------ |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)[]&gt; | Yes| Callback invoked to return the volume information obtained.|
  
- Example

  ```js
  let uuid = "";
  volumemanager.getAllVolumes(uuid, function(error, volumes){
      // do something
  });
  ```


## volumemanager.mount

mount(volumeId: string): Promise&lt;boolean&gt;

Asynchronously mounts a volume. This method uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------ | ---- | ---- |
  | volumeId | string | Yes| Volume ID.|

- Return value

  | Type| Description|
  | ---------------------- | ---------- |
  | Promise&lt;boolean&gt; | Promise used to return the execution result.|

- Example

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId).then(function(flag){
      // do something
  });
  ```

## volumemanager.mount

mount(volumeId: string, callback:AsyncCallback&lt;boolean&gt;):void

Asynchronously mounts a volume. This method uses a callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes| Volume ID.|
  | callback | callback:AsyncCallback&lt;boolean&gt; | Yes| Callback invoked to return the execution result.|

- Example

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId, function(error, flag){
      // do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string): Promise&lt;boolean&gt;

Asynchronously unmounts a volume. This method uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------ | ---- | ---- |
  | volumeId | string | Yes| Volume ID.|

- Return value

  | Type| Description|
  | ---------------------- | ---------- |
  | Promise&lt;boolean&gt; | Promise used to return the execution result.|

- Example

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId).then(function(flag){
      // do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string, callback:AsyncCallback&lt;boolean&gt;):void

Asynchronously unmounts a volume. This method uses a callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes| Volume ID.|
  | callback | callback:AsyncCallback&lt;boolean&gt; | Yes| Callback invoked to return the execution result.|

- Example

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId, function(error, flag){
      // do something
  });
  ```

## Volume

### Attributes

| Name| Type| Description|
| ----------- | ------- | -------------------- |
| id          | number  | Volume ID.|
| uuid        | string  | Universally unique identifier (UUID) of the volume.|
| description | string  | Description of the volume.|
| removeAble  | boolean | Whether the volume is a removable storage device.|
| state       | int     | Current volume status.|
| path        | string  | Mount address of the volume.|
