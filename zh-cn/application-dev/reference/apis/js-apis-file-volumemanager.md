# @ohos.file.volumeManager (卷管理)

该模块提供卷设备、磁盘设备查询和管理的相关功能：包括查询卷设备信息，对卷设备的挂载卸载、对磁盘设备分区以及卷设备的格式化等功能。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```js
import volumemanager from "@ohos.file.volumeManager";
```

## volumemanager.getAllVolumes

getAllVolumes(): Promise&lt;Array&lt;Volume&gt;&gt;

异步获取当前外置存储中所有卷设备信息，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**返回值：**

  | 类型                               | 说明                       |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | 返回当前所有可获得的卷设备信息 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  volumemanager.getAllVolumes().then(function(volumes){
      // do something
  }).catch(function(error){
    console.info("getAllVolumes failed");
  });
  ```

## volumemanager.getAllVolumes

getAllVolumes(callback: AsyncCallback&lt;Array&lt;Volume&gt;&gt;): void

异步获取当前外置存储中所有卷设备信息，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                                              | 必填 | 说明                                 |
  | -------- | ------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[Volume](#volume)[]&gt; | 是   | 获取当前所有可获得的卷设备信息之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let uuid = "";
  volumemanager.getAllVolumes(function(error, volumes){
      // do something
  });
  ```

## volumemanager.mount

mount(volumeId: string): Promise&lt;void&gt;

异步挂载指定卷设备，以promise方式返回。当前仅支持fat、exfat以及ntfs三中文件系统的卷设备挂载。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷设备id |

**返回值：**

  | 类型                   | 说明       |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | 挂载指定卷设备 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
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

**示例：**

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId).then(function(){
      // do something
  }).catch(function(error){
    console.info("mount failed");
  });
  ```

## volumemanager.mount

mount(volumeId: string, callback:AsyncCallback&lt;void&gt;):void

异步挂载指定卷设备，以callback方式返回。当前仅支持fat、exfat以及ntfs三中文件系统的卷设备挂载。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                                  | 必填 | 说明                 |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | 是   | 卷设备id                 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 挂载指定卷设备之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
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

**示例：**

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId, function(error){
      // do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string): Promise&lt;void&gt;

异步卸载指定卷设备，以promise方式返回。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷设备id |

**返回值：**

  | 类型                   | 说明       |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | 卸载指定卷设备 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
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

**示例：**

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId).then(function(){
      // do something
  }).catch(function(error){
    console.info("mount failed");
  });
  ```

## volumemanager.unmount

unmount(volumeId: string, callback: AsyncCallback&lt;void&gt;): void

异步卸载指定卷设备，以callback方式返回。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                                  | 必填 | 说明                 |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | 是   | 卷设备id                 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 卸载指定卷设备之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
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

**示例：**

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId, function(error){
      // do something
  });
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string): Promise&lt;Volume&gt;

异步通过卷设备uuid获得指定卷设备信息，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | uuid | string | 是   | 卷设备uuid |

**返回值：**

  | 类型                               | 说明                       |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)&gt; | 返回当前所有可获得的卷设备信息 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

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

异步通过卷设备uuid获得指定卷设备信息，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名    | 类型                                                 | 必填 | 说明                 |
  | -------- | ------------------------------------------------ | ---- | -------------------- |
  | uuid | string                                                 | 是   | 卷设备uuid                 |
  | callback | AsyncCallback&lt;[Volume](#volume)&gt;  | 是   | 获取卷设备信息之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let uuid = "";
  volumemanager.getVolumeByUuid(uuid, (error, volume) => {
      // do something    
  });
  ```

## volumemanager.getVolumeById

getVolumeById(volumeId: string): Promise&lt;Volume&gt;

异步通过卷设备id获得指定卷设备信息，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名    | 类型    | 必填  | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷设备id |

**返回值：**

  | 类型                               | 说明                       |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)&gt; | 返回当前所有可获得的卷设备信息 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

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

异步通过指定卷设备id获得卷设备信息，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                      | 必填 | 说明                          |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | volumeId | string                    | 是   | 卷设备id                |
  | callback | AsyncCallback&lt;[Volume](#volume)&gt; | 是   | 获取卷设备信息之后的回调  |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let volumeId = "";
  volumemanager.getVolumeById(volumeId, (error, volume) => {
      // do something    
  });
  ```

## volumemanager.setVolumeDescription

setVolumeDescription(uuid: string, description: string): Promise&lt;void&gt;

异步修改指定卷设备描述，以promise方式返回。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | --------- | ------ | ---- | ---- |
  | uuid      | string | 是   | 卷设备uuid |
  | description | string | 是   | 卷设备描述 |

**返回值：**

  | 类型                    | 说明                       |
  | ---------------------- | -------------------------- |
  | Promise&lt;void&gt; | 设置卷设备信息                  |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

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

异步修改指定卷设备描述，以callback方式返回。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名      | 类型                                     | 必填 | 说明              |
  | ---------- | --------------------------------------- | ---- | ---------------- |
  | uuid       | string                                  | 是   | 卷设备uuid            |
  | description | string                                 | 是   | 卷设备描述            |
  | callback   | AsyncCallback&lt;void&gt;   | 是   | 设置卷描述之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let uuid = "";
  let description = "";
  volumemanager.setVolumeDescription(uuid, description, (error) => {
      // do something    
  });
  ```

## volumemanager.format

format(volumeId: string, fsType: string): Promise&lt;void&gt;

异步对指定卷设备进行格式化，以promise方式返回。当前仅支持vfat和exfat两种文件系统类型的格式化，只有处于卸载状态的卷设备可以进行格式化，格式化后卷设备的uuid、挂载路径和卷设备描述均会发生变化。

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名       | 类型   | 必填 | 说明 |
  | ----------- | ------ | ---- | ---- |
  | volumeId    | string | 是   | 卷设备id |
  | fsType    | string | 是   | 文件系统类型（vfat或者exfat） |

**返回值：**

  | 类型                   | 说明       |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | 对指定卷设备进行格式化 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

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

异步对指定卷设备进行格式化，以callback方式返回。当前仅支持vfat和exfat两种文件系统类型的格式化，只有处于卸载状态的卷设备可以进行格式化，格式化后卷设备的uuid、挂载路径和卷设备描述均会发生变化。

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                      | 必填 | 说明                          |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | volumeId | string                    | 是   | 卷设备id                |
  | fsType    | string | 是   | 文件系统类型(vfat或者exfat) |
  | callback | AsyncCallback&lt;void&gt;  | 是   | 对指定卷设备格式化后的回调  |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let volumeId = "";
  let fsType = "";
  volumemanager.format(volumeId, fsType, (error) => {
      // do something    
  });
  ```

## volumemanager.partition

partition(diskId: string, type: number): Promise&lt;void&gt;

异步对磁盘设备进行分区，以promise方式返回。当前仅支持将磁盘设备重新分区为一个分区，系统是支持读取多分区的磁盘设备。

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名       | 类型   | 必填 | 说明 |
  | ----------- | ------ | ---- | ---- |
  | diskId    | string | 是   | 卷设备所属的磁盘设备id |
  | type      | number | 是   | 分区类型    |

**返回值：**

  | 类型                      | 说明                       |
   | --------------------- | ----------------------- |
  | Promise&lt;void&gt;   | 对磁盘进行分区              |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

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

异步对磁盘进行分区，以callback方式返回。当前仅支持将磁盘设备重新分区为一个分区，系统是支持读取多分区的磁盘设备。

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名      | 类型                                   | 必填 | 说明              |
  | -------- | --------------------------------------- | ---- | ---------------- |
  | diskId   | string                                  | 是   | 卷设备所属的磁盘id      |
  | type     | number                                  | 是   | 分区类型           |
  | callback | AsyncCallback&lt;void&gt;   | 是   | 对磁盘设备进行分区      |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let diskId = "";
  let type = 0;
  volumemanager.partition(diskId, type, (error) => {
      // do something    
  });
  ```

## Volume

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.StorageService.Volume。

### 属性

| 名称         | 类型    | 可读   | 可写   | 说明                 |
| ----------- | ------- | ------- | ----- | -------------------- |
| id          | string  | 是 | 否 | 卷设备ID的格式为vol-{主设备号}-{次设备号}，主设备号用来区分不同种类的设备，次设备号用来区分同一类型的多个设备，卷设备ID会随着插卡顺序不同而变化。                 |
| uuid        | string  | 是 | 否 | 卷设备uuid是卷设备的通用唯一识别码，不会随着插卡顺序变化而变化，但是卷设备的格式化会改变卷设备的uuid               |
| diskId      | string  | 是 | 否 | 卷设备所属的磁盘ID，一个磁盘可以有一个或者多个卷设备。磁盘设备ID好格式为disk-{主设备号}-{次设备号}，与卷设备ID相似。        |
| description | string  | 是 | 否 | 卷设备描述、           |
| removable   | boolean | 是 | 否 | 表示卷设备是否可移除，当前仅支持可移除存储设备、 |
| state       | number  | 是 | 否 | 卷设备状态标识：<br>0：卸载状态 UNMOUNTED<br> 1：检查状态 CHECKING<br> 2：挂载状态 MOUNTED<br> 3：正在弹出状态 EJECTING          |
| path        | string  | 是 | 否 | 卷设备的挂载地址，一般为/mnt/external/{uuid}         |