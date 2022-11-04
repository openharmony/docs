# Volume Management

The volumeManager module provides APIs for volume and disk management, including obtaining volume information, mounting or unmounting volumes, partitioning disks, and formatting volumes.

> **NOTE**<br>
>
> - The initial APIs of this module are supported since API version 9.
> - API version 9 is a canary version for trial use. The APIs of this version may be unstable.
> - The APIs of this module are system APIs and cannot be called by third-party applications.

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
  | callback | callback: AsyncCallback&lt;[Volume](#volume)[]&gt; | Yes  | Callback invoked to return the volume information obtained.|

**Example**

  ```js
  let uuid = "";
  volumemanager.getAllVolumes(function(error, volumes){
      // Do something
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
      // Do something
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
  | callback | callback: AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the execution result.|

**Example**

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId, function(error, flag){
      // Do something
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
      // Do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string, callback: AsyncCallback&lt;boolean&gt;): void

Asynchronously unmounts a volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                                 | Mandatory| Description                |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes  | Volume ID.                |
  | callback | callback: AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the execution result.|

**Example**

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId, function(error, flag){
      // Do something
  });
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string): Promise&lt;Volume&gt;

Asynchronously obtains volume information based on the universally unique identifier (UUID). This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type  | Mandatory| Description|
  | -------- | ------ | ---- | ---- |
  | uuid | string | Yes  | UUID of the volume.|

**Return value**

  | Type                              | Description                      |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)&gt; | Promise used to return the volume information obtained.|

**Example**

  ```js
  let uuid = "";
  volumemanager.getVolumeByUuid(uuid).then(function(volume) {
      console.info("getVolumeByUuid successfully:" + JSON.stringify(volume));
  }).catch(function(error){
      console.info("getVolumeByUuid failed with error:"+ error);
  });
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
  | callback | callback: AsyncCallback&lt;[Volume](#volume)&gt;  | Yes  | Callback invoked to return the volume information obtained.|

**Example**

  ```js
  let uuid = "";
  volumemanager.getVolumeByUuid(uuid, (error, volume) => {
      // Do something.   
  });
  ```

## volumemanager.getVolumeById

getVolumeById(volumeId: string): Promise&lt;Volume&gt;

Asynchronously obtains volume information based on the volume ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name   | Type   | Mandatory | Description|
  | -------- | ------ | ---- | ---- |
  | volumeId | string | Yes  | Volume ID.|

**Return value**

  | Type                              | Description                      |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)&gt; | Promise used to return the volume information obtained.|

**Example**

  ```js
  let volumeId = "";
  volumemanager.getVolumeById(volumeId).then(function(volume) {
      console.info("getVolumeById successfully:" + JSON.stringify(volume));
  }).catch(function(error){
      console.info("getVolumeById failed with error:"+ error);
  });
  ```

## volumemanager.getVolumeById

getVolumeById(volumeId: string, callback: AsyncCallback&lt;Volume&gt;): void

Asynchronously obtains volume information based on the volume ID. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                     | Mandatory| Description                         |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | volumeId | string                    | Yes  | Volume ID.               |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)&gt; | Yes  | Callback invoked to return the volume information obtained. |

**Example**

  ```js
  let volumeId = "";
  volumemanager.getVolumeById(volumeId, (error, volume) => {
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
  | Promise&lt;void&gt; | Promise used to return the result.                 |

**Example**

  ```js
  let uuid = "";
  let description = "";
  volumemanager.setVolumeDescription(uuid, description).then(function() {
      console.info("setVolumeDescription successfully");
  }).catch(function(error){
      console.info("setVolumeDescription failed with error:"+ error);
  });
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
  | callback   | callback: AsyncCallback&lt;void&gt;   | Yes  | Callback invoked to return the result.|

**Example**

  ```js
  let uuid = "";
  let description = "";
  volumemanager.setVolumeDescription(uuid, description, (error, bool) => {
      // Do something.   
  });
  ```

## volumemanager.format

format(volumeId: string, fsType: string): Promise&lt;void&gt;

Asynchronously formats a volume. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name      | Type  | Mandatory| Description|
  | ----------- | ------ | ---- | ---- |
  | volumeId    | string | Yes  | Volume ID.|
  | fsType    | string | Yes  | File system type.|

**Return value**

  | Type                  | Description      |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  let volumeId = "";
  let fsType = "";
  volumemanager.format(volumeId, fsType).then(function() {
      console.info("format successfully");
  }).catch(function(error){
      console.info("format failed with error:"+ error);
  });
  ```

## volumemanager.format

format(volumeId: string, fsType: string, callback: AsyncCallback&lt;void&gt;): void

Asynchronously formats a volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                     | Mandatory| Description                         |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | volumeId | string                    | Yes  | Volume ID.               |
  | fsType    | string | Yes  | File system type.|
  | callback | callback: AsyncCallback&lt;void&gt;  | Yes  | Called after the volume is formatted. |

**Example**

  ```js
  let volumeId = "";
  let fsType = "";
  volumemanager.format(volumeId, fsType, (error, bool) => {
      // Do something.   
  });
  ```

## volumemanager.partition

partition(diskId: string, type: number): Promise&lt;void&gt;

Asynchronously partitions a disk. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name      | Type  | Mandatory| Description|
  | ----------- | ------ | ---- | ---- |
  | diskId    | string | Yes  | ID of the disk to which the volume belongs.|
  | type      | number | Yes  | Partition type.   |

**Return value**

  | Type                     | Description                      |
   | --------------------- | ----------------------- |
  | Promise&lt;void&gt;   | Promise used to return the result.             |

**Example**

  ```js
  let diskId = "";
  let type = 0;
  volumemanager.partition(diskId, type).then(function() {
      console.info("partition successfully");
  }).catch(function(error){
      console.info("partition failed with error:"+ error);
  });
  ```

## volumemanager.partition

partition(diskId: string, type: number, callback: AsyncCallback&lt;void&gt;): void

Asynchronously partitions a disk. This API uses a callback to return the result.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name     | Type                                  | Mandatory| Description             |
  | -------- | --------------------------------------- | ---- | ---------------- |
  | diskId   | string                                  | Yes  | ID of the disk to which the volume belongs.     |
  | type     | number                                  | Yes  | Partition type.          |
  | callback | callback: AsyncCallback&lt;void&gt;   | Yes  | Callback invoked to return the result.     |

**Example**

  ```js
  let diskId = "";
  let type = 0;
  volumemanager.partition(diskId, type, (error, bool) => {
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
| diskId      | string  | ID of the disk to which the volume belongs.       |
| description | string  | Description of the volume.          |
| removable   | boolean | Whether the volume is a removable storage device.|
| state       | number  | Volume state.          |
| path        | string  | Mount address of the volume.        |
