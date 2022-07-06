# Volume Management

> **NOTE**<br>
>
> - The initial APIs of this module are supported since API version 9.
> - API version 9 is a canary version for trial use. The APIs of this version may be unstable.
> - The APIs of this module are system APIs and cannot be called by third-party applications.

Performs volume and disk management, including obtaining volume information, mounting and unmounting volumes, partitioning disks, and formatting volumes.

## Modules to Import

```js
import volumemanager from "@ohos.volumeManager";
```

## volumemanager.getAllVolumes

getAllVolumes(): Promise&lt;Array&lt;Volume&gt;&gt;

Asynchronously obtains information about all available volumes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Return value**

  | Type                              | Description                      |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | Promise used to return the execution result.|

**Example**

  ```js
  volumemanager.getAllVolumes().then(function(volumes){
      // Do something.
  });
  ```

## volumemanager.getAllVolumes

getAllVolumes(callback: AsyncCallback&lt;Array&lt;Volume&gt;&gt;): void

Asynchronously obtains information about all available volumes. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                                             | Mandatory| Description                                |
  | -------- | ------------------------------------------------- | ---- | ------------------------------------ |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)[]&gt; | Yes  | Callback invoked to return the volume information obtained.|

**Example**

  ```js
  let uuid = "";
  volumemanager.getAllVolumes(function(error, volumes){
      // Do something.
  });
  ```


## volumemanager.mount

mount(volumeId: string): Promise&lt;boolean&gt;

Asynchronously mounts a volume. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type  | Mandatory| Description|
  | -------- | ------ | ---- | ---- |
  | volumeId | string | Yes  | Volume ID.|

**Return value**

  | Type                  | Description      |
  | ---------------------- | ---------- |
  | Promise&lt;boolean&gt; | Promise used to return the execution result.|

**Example**

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId).then(function(flag){
      // Do something.
  });
  ```

## volumemanager.mount

mount(volumeId: string, callback:AsyncCallback&lt;boolean&gt;):void

Asynchronously obtains the available space of the specified volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                                 | Mandatory| Description                |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes  | Volume ID.                |
  | callback | callback:AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the execution result.|

**Example**

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId, function(error, flag){
      // Do something.
  });
  ```

## volumemanager.unmount

unmount(volumeId: string): Promise&lt;boolean&gt;

Asynchronously unmounts a volume. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type  | Mandatory| Description|
  | -------- | ------ | ---- | ---- |
  | volumeId | string | Yes  | Volume ID.|

**Return value**

  | Type                  | Description      |
  | ---------------------- | ---------- |
  | Promise&lt;boolean&gt; | Promise used to return the execution result.|

**Example**

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId).then(function(flag){
      // Do something.
  });
  ```

## volumemanager.unmount

unmount(volumeId: string, callback:AsyncCallback&lt;boolean&gt;):void

Asynchronously unmounts a volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                                 | Mandatory| Description                |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes  | Volume ID.                |
  | callback | callback:AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the execution result.|

**Example**

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId, function(error, flag){
      // Do something.
  });
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string): Promise&lt;Volume&gt;

Asynchronously obtains volume information based on the Universally unique identifier (UUID). This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type  | Mandatory| Description|
    | -------- | ------ | ---- | ---- |
  | uuid | string | Yes  | UUID of the volume.|

**Return value**

  | Type                              | Description                      |
    | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)&gt; | Promise used to return the execution result.|

**Example**

  ```js
  let uuid = "";
  let volume = await volumemanager.getVolumeByUuid(uuid);
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string, callback: AsyncCallback&lt;Volume&gt;): void

Asynchronously obtains volume information based on the UUID. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name   | Type                                                | Mandatory| Description                |
  | -------- | ------------------------------------------------ | ---- | -------------------- |
  | uuid | string                                                 | Yes  | UUID of the volume.                |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)&gt;  | Yes  | Callback invoked to return the volume information obtained.|

**Example**

  ```js
  let uuid = "";
  volumemanager.getVolumeByUuid(uuid, (error, volume) => {
      // Do something.    
  });
  ```

## volumemanager.getVolumeById

getVolumeById(id: string): Promise&lt;Volume&gt;

Asynchronously obtains volume information based on the volume ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name   | Type   | Mandatory | Description|
  | -------- | ------ | ---- | ---- |
  | id | string | Yes  | Volume ID.|

**Return value**

  | Type                              | Description                      |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)&gt; | Promise used to return the execution result.|

**Example**

  ```js
  let id = "";
  let volume = await volumemanager.getVolumeById(id);
  ```

## volumemanager.getVolumeById

getVolumeById(id: string, callback: AsyncCallback&lt;Volume&gt;): void

Asynchronously obtains volume information based on the volume ID. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name   | Type                                                | Mandatory| Description                |
    | -------- | ------------------------------------------------ | ---- | -------------------- |
  | id | string                                              | Yes  | Volume ID.                |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)&gt;  | Yes  | Callback invoked to return the volume information obtained.|

**Example**

  ```js
  let id = "";
  volumemanager.getVolumeById(id, (error, volume) => {
      // Do something.    
  });
  ```

## volumemanager.setVolumeDescription

setVolumeDescription(uuid: string, description: string): Promise&lt;void&gt;

Asynchronously sets the volume description based on the UUID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name    | Type  | Mandatory| Description|
  | --------- | ------ | ---- | ---- |
  | uuid      | string | Yes  | UUID of the volume.|
  | description | string | Yes  | Volume description.|

**Return value**

  | Type                   | Description                      |
  | ---------------------- | -------------------------- |
  | Promise&lt;void&gt; | Promise used to return the volume description.                  |

**Example**

  ```js
  let uuid = "";
  let description = "";
  let bool = await volumemanager.setVolumeDescription(uuid, description);
  ```

## volumemanager.setVolumeDescription

setVolumeDescription(uuid: string, description: string, callback: AsyncCallback&lt;void&gt;): void

Asynchronously sets the volume description based on the UUID. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name     | Type                                    | Mandatory| Description             |
  | ---------- | --------------------------------------- | ---- | ---------------- |
  | uuid       | string                                  | Yes  | UUID of the volume.           |
  | description | string                                 | Yes  | Volume description.           |
  | callback   | callback:AsyncCallback&lt;void&gt;   | Yes  | Callback invoked to return the volume description.|

**Example**

  ```js
  let uuid = "";
  let description = "";
  volumemanager.setVolumeDescription(uuid, description, (error, bool) => {
      // Do something.    
  });
  ```

## volumemanager.format

format(volId: string): Promise&lt;void&gt;

Asynchronously formats a volume. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name      | Type  | Mandatory| Description|
  | ----------- | ------ | ---- | ---- |
  | volId    | string | Yes  | Volume ID.|

**Return value**

  | Type                   | Description                      |
    | --------------------- | ----------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.           |

**Example**

  ```js
  let volId = "";
  let bool = await volumemanager.format(volId);
  ```

## volumemanager.format

format(volId: string, callback: AsyncCallback&lt;void&gt;): void

Asynchronously formats a volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name     | Type                                    | Mandatory| Description             |
    | -------- | --------------------------------------- | ---- | ---------------- |
  | volId   | string                                  | Yes  | Volume ID.           |
  | callback   | callback:AsyncCallback&lt;void&gt;   | Yes  | Callback invoked to return the result. |

**Example**

  ```js
  let volId = "";
  volumemanager.format(volId, (error, bool) => {
      // Do something.    
  });
  ```

## volumemanager.partition

partition(volId: string, fstype: string): Promise&lt;void&gt;

Asynchronously partitions a disk. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name      | Type  | Mandatory| Description|
    | ----------- | ------ | ---- | ---- |
  | volId    | string | Yes  | ID of the disk to which the volume belongs.|
  | fstype      | string | Yes  | Partition type.   |

**Return value**

  | Type                     | Description                      |
   | --------------------- | ----------------------- |
  | Promise&lt;void&gt;   | Promise used to return the result.             |

**Example**

  ```js
  let volId = "";
  let fstype = "";
  let bool = await volumemanager.partition(volId, fstype);
  ```

## volumemanager.partition

partition(volId: string, fstype : string, callback: AsyncCallback&lt;void&gt;): void

Asynchronously partitions a disk. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name     | Type                                  | Mandatory| Description             |
  | -------- | --------------------------------------- | ---- | ---------------- |
  | volId   | string                                  | Yes  | ID of the disk to which the volume belongs.     |
  | fstype     | string                                  | Yes  | Partition type.          |
  | callback | callback:AsyncCallback&lt;void&gt;   | Yes  | Callback invoked to return the result.     |

**Example**

  ```js
  let volId = "";
  let fstype = "";
  volumemanager.format(volId, fstype, (error, bool) => {
      // Do something.    
  });
  ```

## Volume

**System capability**: SystemCapability.FileManagement.StorageService.Volume

### Attributes

| Name        | Type   | Description                |
| ----------- | ------- | -------------------- |
| id          | string  | Volume ID.                |
| uuid        | string  | UUID of the volume.              |
| description | string  | Description of the volume.          |
| removable   | boolean | Whether the volume is a removable storage device.|
| state       | number  | Current volume status.          |
| path        | string  | Mount address of the volume.        |
