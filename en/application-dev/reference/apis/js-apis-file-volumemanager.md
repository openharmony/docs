# @ohos.file.volumeManager (Volume Management)

The **volumeManager** module provides APIs for volume and disk management, including obtaining volume information, mounting or unmounting a volume, partitioning a disk, and formatting a volume.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import volumemanager from "@ohos.file.volumeManager";
```

## volumemanager.getAllVolumes

getAllVolumes(): Promise&lt;Array&lt;Volume&gt;&gt;

Obtains information about all volumes of this external storage device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Return value**

  | Type                              | Description                      |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | Promise used to return information about all available volumes.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  volumemanager.getAllVolumes().then(function(volumes){
      // Do something.
  }).catch(function(error){
    console.info("getAllVolumes failed");
  });
  ```

## volumemanager.getAllVolumes

getAllVolumes(callback: AsyncCallback&lt;Array&lt;Volume&gt;&gt;): void

Obtains information about all volumes of this external storage device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                                             | Mandatory| Description                                |
  | -------- | ------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[Volume](#volume)[]&gt; | Yes  | Callback invoked to return information about all available volumes.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let uuid = "";
  volumemanager.getAllVolumes(function(error, volumes){
      // Do something
  });
  ```

## volumemanager.mount

mount(volumeId: string): Promise&lt;void&gt;

Asynchronously mounts a volume. This API uses a promise to return the result. Currently, only the File Allocation Table (FAT), Extensible FAT (exFAT), and New Technology File System (NTFS) file systems are supported.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type  | Mandatory| Description|
  | -------- | ------ | ---- | ---- |
  | volumeId | string | Yes  | Volume ID.|

**Return value**

  | Type                  | Description      |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600003 | Failed to mount. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId).then(function(){
      // Do something.
  }).catch(function(error){
    console.info("mount failed");
  });
  ```

## volumemanager.mount

mount(volumeId: string, callback:AsyncCallback&lt;void&gt;):void

Asynchronously mounts a volume. This API uses an asynchronous callback to return the result. Currently, only the FAT, exFAT, and NTFS file systems are supported.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                                 | Mandatory| Description                |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes  | Volume ID.                |
  | callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600003 | Failed to mount. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId, function(error){
      // Do something.
  });
  ```

## volumemanager.unmount

unmount(volumeId: string): Promise&lt;void&gt;

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
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600004 | Failed to unmount. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId).then(function(){
      // Do something.
  }).catch(function(error){
    console.info("mount failed");
  });
  ```

## volumemanager.unmount

unmount(volumeId: string, callback: AsyncCallback&lt;void&gt;): void

Asynchronously unmounts a volume. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                                 | Mandatory| Description                |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | Yes  | Volume ID.                |
  | callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600004 | Failed to unmount. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId, function(error){
      // Do something.
  });
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string): Promise&lt;Volume&gt;

Obtains information about a volume based on the universally unique identifier (UUID). This API uses a promise to return the result.

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

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

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

Obtains information about a volume based on the UUID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name   | Type                                                | Mandatory| Description                |
  | -------- | ------------------------------------------------ | ---- | -------------------- |
  | uuid | string                                                 | Yes  | UUID of the volume.                |
  | callback | AsyncCallback&lt;[Volume](#volume)&gt;  | Yes  | Callback invoked to return the volume information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let uuid = "";
  volumemanager.getVolumeByUuid(uuid, (error, volume) => {
      // Do something.   
  });
  ```

## volumemanager.getVolumeById

getVolumeById(volumeId: string): Promise&lt;Volume&gt;

Obtains information about a volume based on the volume ID. This API uses a promise to return the result.

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

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

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

Obtains information about a volume based on the volume ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                     | Mandatory| Description                         |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | volumeId | string                    | Yes  | Volume ID.               |
  | callback | AsyncCallback&lt;[Volume](#volume)&gt; | Yes  | Callback invoked to return the volume information obtained. |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let volumeId = "";
  volumemanager.getVolumeById(volumeId, (error, volume) => {
      // Do something.   
  });
  ```

## volumemanager.setVolumeDescription

setVolumeDescription(uuid: string, description: string): Promise&lt;void&gt;

Sets volume description. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name    | Type  | Mandatory| Description|
  | --------- | ------ | ---- | ---- |
  | uuid      | string | Yes  | UUID of the volume.|
  | description | string | Yes  | Volume description to set.|

**Return value**

  | Type                   | Description                      |
  | ---------------------- | -------------------------- |
  | Promise&lt;void&gt; | Promise that returns no value.                 |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

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

Sets volume description. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MOUNT_UNMOUNT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name     | Type                                    | Mandatory| Description             |
  | ---------- | --------------------------------------- | ---- | ---------------- |
  | uuid       | string                                  | Yes  | UUID of the volume.           |
  | description | string                                 | Yes  | Volume description to set.           |
  | callback   | AsyncCallback&lt;void&gt;   | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let uuid = "";
  let description = "";
  volumemanager.setVolumeDescription(uuid, description, (error) => {
      // Do something.   
  });
  ```

## volumemanager.format

format(volumeId: string, fsType: string): Promise&lt;void&gt;

Formats a volume. This API uses a promise to return the result. Currently, only the virtual file allocation table (VFAT) and exFAT file systems are supported. Only unmounted volumes can be formatted. After a volume is formatted, the UUID, mounting path, and description of the volume change.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name      | Type  | Mandatory| Description|
  | ----------- | ------ | ---- | ---- |
  | volumeId    | string | Yes  | Volume ID.|
  | fsType    | string | Yes  | File system type, which can be VFAT or exFAT.|

**Return value**

  | Type                  | Description      |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

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

Formats a volume. This API uses an asynchronous callback to return the result. Currently, only the VFAT and exFAT file systems are supported. Only unmounted volumes can be formatted. After a volume is formatted, the UUID, mounting path, and description of the volume change.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name  | Type                     | Mandatory| Description                         |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | volumeId | string                    | Yes  | Volume ID.               |
  | fsType    | string | Yes  | File system type, which can be VFAT or exFAT.|
  | callback | AsyncCallback&lt;void&gt;  | Yes  | Callback that returns no value. |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let volumeId = "";
  let fsType = "";
  volumemanager.format(volumeId, fsType, (error) => {
      // Do something.   
  });
  ```

## volumemanager.partition

partition(diskId: string, type: number): Promise&lt;void&gt;

Partitions a disk. This API uses a promise to return the result. The system supports access to multi-partition disks. Currently, this API can partition a disk into only one partition.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name      | Type  | Mandatory| Description|
  | ----------- | ------ | ---- | ---- |
  | diskId    | string | Yes  | ID of the disk to partition.|
  | type      | number | Yes  | Partition type.   |

**Return value**

  | Type                     | Description                      |
   | --------------------- | ----------------------- |
  | Promise&lt;void&gt;   | Promise used to return the result.             |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

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

Asynchronously partitions a disk. This API uses a callback to return the result. The system supports access to multi-partition disks. Currently, this API can partition a disk into only one partition.

**Required permissions**: ohos.permission.MOUNT_FORMAT_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.Volume

**Parameters**

  | Name     | Type                                  | Mandatory| Description             |
  | -------- | --------------------------------------- | ---- | ---------------- |
  | diskId   | string                                  | Yes  | ID of the disk to partition.     |
  | type     | number                                  | Yes  | Partition type.          |
  | callback | AsyncCallback&lt;void&gt;   | Yes  | Callback that returns no value.     |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let diskId = "";
  let type = 0;
  volumemanager.partition(diskId, type, (error) => {
      // Do something.   
  });
  ```

## Volume

**System capability**: SystemCapability.FileManagement.StorageService.Volume

### Attributes

| Name        | Type   | Readable  | Writable  | Description                |
| ----------- | ------- | ------- | ----- | -------------------- |
| id          | string  | Yes| No| Volume ID, in the vol-{Primary device ID}-{Secondary device ID} format. The primary device IDs identify devices of different types. The secondary device IDs identify different devices of the same type. The volume IDs vary depending on the card insertion sequence.                |
| uuid        | string  | Yes| No| Volume UUID, which uniquely identifies a volume irrespective of the card insertion sequence. However, the UUID of a volume will change after the volume is formatted.              |
| diskId      | string  | Yes| No| ID of the disk to which the volume belongs. A disk can have one or more volumes. The disk ID is in the disk-{Primary device ID}-{Secondary device ID} format, which is similar to the volume ID.       |
| description | string  | Yes| No| Description of the volume.          |
| removable   | boolean | Yes| No| Whether the volume can be removed. Currently, only removable storage devices are supported.|
| state       | number  | Yes| No| Volume status.<br>**0**: The volume is unmounted.<br> **1**: The volume is being checked.<br> **2**: The volume is mounted.<br> **3**: The volume is being ejected.         |
| path        | string  | Yes| No| Path of the volume mounted. Generally, the path is **/mnt/external/{uuid}**.        |
