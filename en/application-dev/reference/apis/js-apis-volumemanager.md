# Volume Management

> **NOTE**<br>
>
> - The initial APIs of this module are supported since API version 9.
> - API version 9 is a canary version for trial use. The APIs of this version may be unstable.
> - The APIs of this module are system APIs and cannot be called by third-party applications.

The APIs of this module can be used to perform volume and disk management, including obtaining volume information, mounting and unmounting volumes, partitioning disks, and formatting volumes.

## Modules to Import

```js
import volumemanager from "@ohos.volumeManager";
```

## volumemanager.getAllVolumes

getAllVolumes(): Promise&lt;Array&lt;Volume&gt;&gt;

Asynchronously obtains information about all available volumes. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.Volume

- Return value

  | Type                              | Description                      |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | Promise used to return the execution result.|

- Example

  ```js
  volumemanager.getAllVolumes().then(function(volumes){
      // do something
  });
  ```

## volumemanager.getAllVolumes

getAllVolumes(callback: AsyncCallback&lt;Array&lt;Volume&gt;&gt;): void

Asynchronously obtains information about all available volumes. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.Volume

- Parameters

  | Name  | Type                                             | Mandatory| Description                                |
  | -------- | ------------------------------------------------- | ---- | ------------------------------------ |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)[]&gt; | Yes  | Callback invoked to return the volume information obtained.|
  
- Example

  ```js
  let uuid = "";
  volumemanager.getAllVolumes(uuid, function(error, volumes){
      // do something
  });
  ```


## volumemanager.mount

mount(volumeId: string): Promise&lt;boolean&gt;

Asynchronously mounts a volume. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.Volume

- Parameters

  | Name  | Type  | Mandatory| Description|
  | -------- | ------ | ---- | ---- |
  | volumeId | string | Yes  | Volume ID.|

- Return value

  | Type                  | Description      |
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

Asynchronously obtains the available space of the specified volume. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.Volume

- Parameters

  | Name  | Type                                 | Mandatory| Description                |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes  | Volume ID.                |
  | callback | callback:AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the execution result.|

- Example

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId, function(error, flag){
      // do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string): Promise&lt;boolean&gt;

Asynchronously unmounts a volume. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.Volume

- Parameters

  | Name  | Type  | Mandatory| Description|
  | -------- | ------ | ---- | ---- |
  | volumeId | string | Yes  | Volume ID.|

- Return value

  | Type                  | Description      |
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

Asynchronously unmounts a volume. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.Volume

- Parameters

  | Name  | Type                                 | Mandatory| Description                |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes  | Volume ID.                |
  | callback | callback:AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the execution result.|

- Example

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId, function(error, flag){
      // do something
  });
  ```

## Volume

**System capability**: SystemCapability.FileManagement.StorageService.Volume

### Attributes

| Name       | Type   | Description                |
| ----------- | ------- | -------------------- |
| id          | number  | Volume ID.                |
| uuid        | string  | Universally unique identifier (UUID) of the volume.              |
| description | string  | Description of the volume.          |
| removable | boolean | Whether the volume is a removable storage device.|
| state       | int     | Current volume status.          |
| path        | string  | Mount address of the volume.        |
