# @ohos.file.volumeManager (卷管理)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @ning-jingyou-->
<!--Designer: @renguang1116; @wang_zhangjun-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

该模块提供卷设备、磁盘设备查询和管理的相关功能：包括查询卷设备信息和磁盘设备信息，对卷设备的挂载卸载、弹出、擦除，对磁盘设备的分区创建、删除、格式化及分区表查询，卷设备的格式化，以及光盘刻录（包括创建ISO镜像、数据刻录、刻录数据校验和操作进度查询）等功能。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口。

## 导入模块

```ts
import { volumeManager } from '@kit.CoreFileKit';
```

## volumemanager.getAllVolumes

getAllVolumes(): Promise&lt;Array&lt;Volume&gt;&gt;

获取当前外置存储中所有卷设备信息，使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**返回值：**

  | 类型                               | 说明                       |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | Promise对象，返回当前所有可获得的卷设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    // 获取到所有卷设备信息
  }).catch((error: BusinessError) => {
    console.error(`Failed to getAllVolumes. Code: ${error.code}, message: ${error.message}`);
  });
  ```

## volumemanager.getAllVolumes

getAllVolumes(callback: AsyncCallback&lt;Array&lt;Volume&gt;&gt;): void

获取当前外置存储中所有卷设备信息，使用callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                                              | 必填 | 说明                                 |
  | -------- | ------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[Volume](#volume)[]&gt; | 是   | 获取当前所有可获得的卷设备信息之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  volumeManager.getAllVolumes((error: BusinessError, volumes: Array<volumeManager.Volume>) => {
    if (error) {
      console.error(`getAllVolumes failed, code is: ${error.code}, message is: ${error.message}`);
      return;
    }
    // 获取到所有卷设备信息
  });
  ```

## volumemanager.mount

mount(volumeId: string): Promise&lt;void&gt;

挂载指定卷设备，只有处于卸载状态的卷设备可以挂载。使用Promise异步回调。

当前仅支持以下文件系统的卷设备挂载：

vfat、exfat及ntfs。

从API版本26.0.0开始支持ext4。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。 |

**返回值：**

  | 类型                   | 说明       |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600003 | Failed to mount. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // volumeId可通过getAllVolumes()接口获取
  let volumeId: string = "";
  volumeManager.mount(volumeId).then(() => {
    // 挂载指定卷设备成功后的回调
  }).catch((error: BusinessError) => {
    console.error(`Failed to mount. Code: ${error.code}, message: ${error.message}`);
  });
  ```

## volumemanager.mount

mount(volumeId: string, callback:AsyncCallback&lt;void&gt;):void

挂载指定卷设备，只有处于卸载状态的卷设备可以挂载。使用callback异步回调。

当前仅支持以下文件系统的卷设备挂载：

vfat、exfat及ntfs。

从API版本26.0.0开始支持ext4。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                                  | 必填 | 说明                 |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。                 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 挂载指定卷设备之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600003 | Failed to mount. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // volumeId可通过getAllVolumes()接口获取
  let volumeId: string = "";
  volumeManager.mount(volumeId, (error: BusinessError) => {
    if (error) {
      console.error(`mount failed, code is: ${error.code}, message is: ${error.message}`);
      return;
    }
    // 挂载指定卷设备成功后的回调
  });
  ```

## volumemanager.unmount

unmount(volumeId: string): Promise&lt;void&gt;

卸载指定卷设备，使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。 |

**返回值：**

  | 类型                   | 说明       |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600004 | Failed to unmount. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // volumeId可通过getAllVolumes()接口获取
  let volumeId: string = "";
  volumeManager.unmount(volumeId).then(() => {
    // 卸载指定卷设备成功后的回调
  }).catch((error: BusinessError) => {
    console.error(`Failed to unmount. Code: ${error.code}, message: ${error.message}`);
  });
  ```

## volumemanager.unmount

unmount(volumeId: string, callback: AsyncCallback&lt;void&gt;): void

卸载指定卷设备，使用callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                                  | 必填 | 说明                 |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。                 |
  | callback | AsyncCallback&lt;void&gt; | 是   | 卸载指定卷设备之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600004 | Failed to unmount. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // volumeId可通过getAllVolumes()接口获取
  let volumeId: string = "";
  volumeManager.unmount(volumeId, (error: BusinessError) => {
    if (error) {
      console.error(`unmount failed, code is: ${error.code}, message is: ${error.message}`);
      return;
    }
    // 卸载指定卷设备成功后的回调
  });
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string): Promise&lt;Volume&gt;

通过卷设备uuid获得指定卷设备信息，使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | uuid | string | 是   | 卷设备uuid。卷设备uuid不会随着插卡顺序变化而变化，但格式化后会改变。 |

**返回值：**

  | 类型                               | 说明                       |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)&gt; | Promise对象，返回指定uuid对应的卷设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // uuid可通过getAllVolumes()接口获取卷设备信息后获得
  let uuid: string = "";
  volumeManager.getVolumeByUuid(uuid).then((volume: volumeManager.Volume) => {
    console.info("getVolumeByUuid successfully:" + JSON.stringify(volume));
  }).catch((error: BusinessError) => {
    console.error(`Failed to getVolumeByUuid. Code: ${error.code}, message: ${error.message}`);
  });
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string, callback: AsyncCallback&lt;Volume&gt;): void

通过卷设备uuid获得指定卷设备信息，使用callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名    | 类型                                                 | 必填 | 说明                 |
  | -------- | ------------------------------------------------ | ---- | -------------------- |
  | uuid | string                                                 | 是   | 卷设备uuid。卷设备uuid不会随着插卡顺序变化而变化，但格式化后会改变。                 |
  | callback | AsyncCallback&lt;[Volume](#volume)&gt;  | 是   | 获取卷设备信息之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // uuid可通过getAllVolumes()接口获取卷设备信息后获得
  let uuid: string = "";
  volumeManager.getVolumeByUuid(uuid, (error: BusinessError, volume: volumeManager.Volume) => {
    if (error) {
      console.error(`getVolumeByUuid failed, code is: ${error.code}, message is: ${error.message}`);
      return;
    }
    // 获取到卷设备信息
  });
  ```
  
  ## volumemanager.getVolumeById

getVolumeById(volumeId: string): Promise&lt;Volume&gt;

通过卷设备ID获得指定卷设备信息，使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名    | 类型    | 必填  | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。 |

**返回值：**

  | 类型                               | 说明                       |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)&gt; | Promise对象，返回指定volumeId对应的卷设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // volumeId可通过getAllVolumes()接口获取
  let volumeId: string = "";
  volumeManager.getVolumeById(volumeId).then((volume: volumeManager.Volume) => {
    console.info("getVolumeById successfully:" + JSON.stringify(volume));
  }).catch((error: BusinessError) => {
    console.error(`Failed to getVolumeById. Code: ${error.code}, message: ${error.message}`);
  });
  ```

## volumemanager.getVolumeById

getVolumeById(volumeId: string, callback: AsyncCallback&lt;Volume&gt;): void

通过指定卷设备ID获得卷设备信息，使用callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                      | 必填 | 说明                          |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | volumeId | string                    | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。                |
  | callback | AsyncCallback&lt;[Volume](#volume)&gt; | 是   | 获取卷设备信息之后的回调。  |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // volumeId可通过getAllVolumes()接口获取
  let volumeId: string = "";
  volumeManager.getVolumeById(volumeId, (error: BusinessError, volume: volumeManager.Volume) => {
    if (error) {
      console.error(`getVolumeById failed, code is: ${error.code}, message is: ${error.message}`);
      return;
    }
    // 获取到卷设备信息
  });
  ```

## volumemanager.setVolumeDescription

setVolumeDescription(uuid: string, description: string): Promise&lt;void&gt;

修改指定卷设备描述，使用Promise异步回调。当前仅支持修改ntfs和exfat两种文件系统类型的设备描述，只有处于卸载状态的卷设备可以修改设备描述。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | --------- | ------ | ---- | ---- |
  | uuid      | string | 是   | 卷设备uuid。卷设备uuid不会随着插卡顺序变化而变化，但格式化后会改变。 |
  | description | string | 是   | 卷设备描述。 |

**返回值：**

  | 类型                    | 说明                       |
  | ---------------------- | -------------------------- |
  | Promise&lt;void&gt; | 无返回结果的Promise对象。                  |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // uuid可通过getAllVolumes()接口获取卷设备信息后获得
  let uuid: string = "";
  let description: string = "";
  volumeManager.setVolumeDescription(uuid, description).then(() => {
    console.info("setVolumeDescription successfully");
  }).catch((error: BusinessError) => {
    console.error(`Failed to setVolumeDescription. Code: ${error.code}, message: ${error.message}`);
  });
  ```

## volumemanager.setVolumeDescription

setVolumeDescription(uuid: string, description: string, callback: AsyncCallback&lt;void&gt;): void

修改指定卷设备描述，使用callback异步回调。当前仅支持修改ntfs和exfat两种文件系统类型的设备描述，只有处于卸载状态的卷设备可以修改设备描述。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名      | 类型                                     | 必填 | 说明              |
  | ---------- | --------------------------------------- | ---- | ---------------- |
  | uuid       | string                                  | 是   | 卷设备uuid。卷设备uuid不会随着插卡顺序变化而变化，但格式化后会改变。            |
  | description | string                                 | 是   | 卷设备描述。            |
  | callback   | AsyncCallback&lt;void&gt;   | 是   | 设置卷描述之后的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // uuid可通过getAllVolumes()接口获取卷设备信息后获得
  let uuid: string = "";
  let description: string = "";
  volumeManager.setVolumeDescription(uuid, description, (error: BusinessError) => {
    if (error) {
      console.error(`setVolumeDescription failed, code is: ${error.code}, message is: ${error.message}`);
      return;
    }
    // 设置卷设备描述成功的回调
  });
  ```

## volumemanager.format

format(volumeId: string, fsType: string): Promise&lt;void&gt;

对指定卷设备进行格式化，使用Promise异步回调。

当前仅支持以下文件系统类型的格式化：

vfat和exfat。

从API版本26.0.0开始支持ext4文件系统的格式化。

只有处于卸载状态的卷设备可以进行格式化，格式化后卷设备的uuid、挂载路径和卷设备描述均会发生变化。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名       | 类型   | 必填 | 说明 |
  | ----------- | ------ | ---- | ---- |
  | volumeId    | string | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备须处于卸载状态，否则返回错误码13600005。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。 |
  | fsType    | string | 是   | 文件系统类型，当前支持vfat、exfat。<br>**说明**：从API版本26.0.0开始，支持ext4。 |

**返回值：**

  | 类型                   | 说明       |
  | ---------------------- | ---------- |
  | Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // volumeId可通过getAllVolumes()接口获取
  let volumeId: string = "";
  let fsType: string = "";
  volumeManager.format(volumeId, fsType).then(() => {
    console.info("format successfully");
  }).catch((error: BusinessError) => {
    console.error(`Failed to format. Code: ${error.code}, message: ${error.message}`);
  });
  ```

## volumemanager.format

format(volumeId: string, fsType: string, callback: AsyncCallback&lt;void&gt;): void

对指定卷设备进行格式化，使用callback异步回调。

当前仅支持以下文件系统类型的格式化：

vfat和exfat。

从API版本26.0.0开始支持ext4文件系统的格式化。

只有处于卸载状态的卷设备可以进行格式化，格式化后卷设备的uuid、挂载路径和卷设备描述均会发生变化。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名   | 类型                      | 必填 | 说明                          |
  | -------- | ------------------------- | ---- | ----------------------------- |
  | volumeId | string                    | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备须处于卸载状态，否则返回错误码13600005。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。                |
  | fsType    | string | 是   | 文件系统类型，当前支持vfat、exfat。<br>**说明**：从API版本26.0.0开始，支持ext4。 |
  | callback | AsyncCallback&lt;void&gt;  | 是   | 对指定卷设备格式化后的回调。  |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // volumeId可通过getAllVolumes()接口获取
  let volumeId: string = "";
  let fsType: string = "";
  volumeManager.format(volumeId, fsType, (error: BusinessError) => {
    if (error) {
      console.error(`format failed, code is: ${error.code}, message is: ${error.message}`);
      return;
    }
    // 对指定卷设备格式化成功的回调
  });
  ```

## volumemanager.partition

partition(diskId: string, type: number): Promise&lt;void&gt;

对磁盘设备进行分区，使用Promise异步回调。当前仅支持将磁盘设备重新分区为一个分区，系统支持读取已存在多分区的磁盘设备。不支持对光盘进行分区。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名       | 类型   | 必填 | 说明 |
  | ----------- | ------ | ---- | ---- |
  | diskId    | string | 是   | 卷设备所属的磁盘设备ID，格式为disk-{主设备号}-{次设备号}。 |
  | type      | number | 是   | 分区类型，用于指定分区方式。当前仅支持传入0，表示将磁盘重新分区为一个分区。    |

**返回值：**

  | 类型                      | 说明                       |
  | --------------------- | ----------------------- |
  | Promise&lt;void&gt;   | 无返回结果的Promise对象。              |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // diskId可通过getAllDisks()接口获取
  let diskId: string = "";
  let type: number = 0;
  volumeManager.partition(diskId, type).then(() => {
    console.info("partition successfully");
  }).catch((error: BusinessError) => {
    console.error(`Failed to partition. Code: ${error.code}, message: ${error.message}`);
  });
  ```

## volumemanager.partition

partition(diskId: string, type: number, callback: AsyncCallback&lt;void&gt;): void

对磁盘设备进行分区，使用callback异步回调。当前仅支持将磁盘设备重新分区为一个分区，系统支持读取已存在多分区的磁盘设备。不支持对光盘进行分区。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**参数：**

  | 参数名      | 类型                                   | 必填 | 说明              |
  | -------- | --------------------------------------- | ---- | ---------------- |
  | diskId   | string                                  | 是   | 卷设备所属的磁盘设备ID，格式为disk-{主设备号}-{次设备号}。      |
  | type     | number                                  | 是   | 分区类型，用于指定分区方式。当前仅支持传入0，表示将磁盘重新分区为一个分区。          |
  | callback | AsyncCallback&lt;void&gt;   | 是   | 对磁盘设备分区完成后的回调。      |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  // diskId可通过getAllDisks()接口获取
  let diskId: string = "";
  let type: number = 0;
  volumeManager.partition(diskId, type, (error: BusinessError) => {
    if (error) {
      console.error(`partition failed, code is: ${error.code}, message is: ${error.message}`);
      return;
    }
    // 对磁盘设备分区成功后的回调
  });
  ```

## volumemanager.erase

erase(volumeId: string): Promise&lt;void&gt;

擦除指定卷设备中的数据，使用Promise异步回调。适用于需要彻底清除卷设备上数据的场景，例如光盘重写前的数据擦除。擦除操作会清除卷设备上的所有数据，仅处于卸载状态的卷设备可执行擦除操作。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| volumeId | string | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600010 | The input parameter is invalid. |
| 13600026 | Erase operation failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// volumeId可通过getAllVolumes()接口获取
let volumeId: string = "";
volumeManager.erase(volumeId).then(() => {
  console.info("erase successfully.");
}).catch((error: BusinessError) => {
  console.error(`Failed to erase. Code: ${error.code}, message: ${error.message}`);
});
```

## volumemanager.eject

eject(diskId: string): Promise&lt;void&gt;

弹出指定磁盘设备及其所属卷设备，使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| diskId | string | 是 | 卷设备所属的磁盘设备ID，格式为disk-{主设备号}-{次设备号}。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600027 | Eject operation failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// diskId可通过getAllDisks()接口获取
let diskId: string = "";
volumeManager.eject(diskId).then(() => {
  console.info("eject successfully.");
}).catch((error: BusinessError) => {
  console.error(`Failed to eject. Code: ${error.code}, message: ${error.message}`);
});
```

## volumemanager.createIsoImage

createIsoImage(volumeId: string, filePath: string): Promise&lt;void&gt;

从指定卷设备创建ISO镜像文件，使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| volumeId | string | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。 |
| filePath | string | 是   | ISO镜像文件的保存路径。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600010 | The input parameter is invalid. |
| 13600024 | Empty disc. |
| 13600025 | Failed to write the ISO file. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// volumeId可通过getAllVolumes()接口获取
let volumeId: string = "";
let filePath: string = "";
volumeManager.createIsoImage(volumeId, filePath).then(() => {
  console.info("createIsoImage successfully.");
}).catch((error: BusinessError) => {
  console.error(`Failed to createIsoImage. Code: ${error.code}, message: ${error.message}`);
});
```

## volumemanager.burn

burn(volumeId: string, want: Want): Promise&lt;void&gt;

向指定卷设备刻录数据，使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| volumeId | string | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。 |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 启动Ability的Want信息。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |
 
**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600010 | The input parameter is invalid. |
| 13600028 | Burn operation failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

import { Want } from '@kit.AbilityKit';
// volumeId可通过getAllVolumes()接口获取
let volumeId: string = "";
let want: Want = {
  diskName: "MyDisc",
  burnPath: "/data/storage/el2/base/files/burn_data",
  isIsoImage: false,
  burnSpeed: 0,
  fsType: "ISO9660"
};
volumeManager.burn(volumeId, want).then(() => {
  console.info("burn successfully.");
}).catch((error: BusinessError) => {
  console.error(`Failed to burn. Code: ${error.code}, message: ${error.message}`);
});
```

## volumemanager.getOpProcess

getOpProcess(volumeId: string): Promise&lt;number&gt;

获取指定卷设备的光驱刻录操作进度，使用Promise异步回调。在调用burn接口向光盘刻录数据后，可通过本接口获取刻录进度。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| volumeId | string | 是   | 卷设备ID，格式为vol-{主设备号}-{次设备号}。卷设备ID会随着插卡顺序不同而变化，请勿缓存后复用。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;number&gt; | Promise对象，返回当前操作的进度，进度值为0-100的整数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600010 | The input parameter is invalid. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// volumeId可通过getAllVolumes()接口获取
let volumeId: string = "";
volumeManager.getOpProcess(volumeId).then((progress: number) => {
  console.info("getOpProcess successfully, progress:" + progress);
}).catch((error: BusinessError) => {
  console.error(`Failed to getOpProcess. Code: ${error.code}, message: ${error.message}`);
});
```

## volumemanager.getAllDisks

getAllDisks(): Promise&lt;Array&lt;Disk&gt;&gt;

获取当前外置存储中所有磁盘设备信息。使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;Array&lt;[Disk](#disk)&gt;&gt; | Promise对象，返回所有磁盘的设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

volumeManager.getAllDisks().then((disks: Array<volumeManager.Disk>) => {
  console.info("getAllDisks successfully:" + JSON.stringify(disks));
}).catch((error: BusinessError) => {
  console.error(`getAllDisks failed with error, code is: ${error.code}, message is: ${error.message}`);
});
```

## volumemanager.getDiskById

getDiskById(diskId: string): Promise&lt;Disk&gt;

通过磁盘设备ID获得指定磁盘设备信息。使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| diskId | string | 是   | 磁盘设备ID，格式为disk-{主设备号}-{次设备号}。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;[Disk](#disk)&gt; | Promise对象，返回指定磁盘的设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13600010 | The input parameter is invalid. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// diskId可通过getAllDisks()接口获取
let diskId: string = "";
volumeManager.getDiskById(diskId).then((disk: volumeManager.Disk) => {
  console.info("getDiskById successfully:" + JSON.stringify(disk));
}).catch((error: BusinessError) => {
  console.error(`getDiskById failed with error, code is: ${error.code}, message is: ${error.message}`);
});
```

## volumemanager.getPartitionTable

getPartitionTable(diskId: string): Promise&lt;PartitionTableInfo&gt;

通过磁盘设备ID获取指定磁盘设备的分区表信息。使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| diskId | string | 是   | 磁盘设备ID，格式为disk-{主设备号}-{次设备号}。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;[PartitionTableInfo](#partitiontableinfo)&gt; | Promise对象，返回指定磁盘设备的分区表信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13600010 | The input parameter is invalid. |
| 13600021 | Get partition table failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// diskId可通过getAllDisks()接口获取
let diskId: string = "";
volumeManager.getPartitionTable(diskId).then((partitionTableInfo: volumeManager.PartitionTableInfo) => {
  console.info("getPartitionTable successfully:" + JSON.stringify(partitionTableInfo));
}).catch((error: BusinessError) => {
  console.error(`getPartitionTable failed with error, code is: ${error.code}, message is: ${error.message}`);
});
```

## volumemanager.createPartition

createPartition(diskId: string, params: PartitionParams): Promise&lt;void&gt;

对指定磁盘设备创建分区，不支持对光盘进行分区。使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| diskId | string | 是   | 磁盘设备ID，格式为disk-{主设备号}-{次设备号}。 |
| params | [PartitionParams](#partitionparams) | 是   | 分区创建参数。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13600010 | The input parameter is invalid. |
| 13600022 | Create partition failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// diskId可通过getAllDisks()接口获取
let diskId: string = "";
let params: volumeManager.PartitionParams = {
  partitionNum: 1,
  startSector: 2048,
  endSector: 1024000,
  typeCode: "ext4"
};
volumeManager.createPartition(diskId, params).then(() => {
  console.info("createPartition successfully.");
}).catch((error: BusinessError) => {
  console.error(`createPartition failed with error, code is: ${error.code}, message is: ${error.message}`);
});
```

## volumemanager.deletePartition

deletePartition(diskId: string, partitionNum: number): Promise&lt;void&gt;

对指定磁盘设备删除指定分区，不支持对光盘进行分区。使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| diskId | string | 是   | 磁盘设备ID，格式为disk-{主设备号}-{次设备号}。 |
| partitionNum | number | 是   | 分区号。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13600010 | The input parameter is invalid. |
| 13600023 | Delete partition failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// diskId可通过getAllDisks()接口获取
let diskId: string = "";
let partitionNum: number = 1;
volumeManager.deletePartition(diskId, partitionNum).then(() => {
  console.info("deletePartition successfully.");
}).catch((error: BusinessError) => {
  console.error(`deletePartition failed with error, code is: ${error.code}, message is: ${error.message}`);
});
```

## volumemanager.formatPartition

formatPartition(diskId: string, partitionNum: number, params: FormatParams): Promise&lt;void&gt;

对指定磁盘设备的指定分区进行格式化，需确保相关卷设备处于卸载状态。使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_FORMAT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| diskId | string | 是   | 磁盘设备ID，格式为disk-{主设备号}-{次设备号}。 |
| partitionNum | number | 是   | 分区号。 |
| params | [FormatParams](#formatparams) | 是   | 格式化参数。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600002 | Not supported filesystem. |
| 13600005 | Incorrect volume state. |
| 13600008 | No such object. |
| 13600010 | The input parameter is invalid. |
| 13600032 | Format partition failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// diskId可通过getAllDisks()接口获取
let diskId: string = "";
let partitionNum: number = 1;
let params: volumeManager.FormatParams = {
  fsType: "ext4",
  quickFormat: true,
  volumeName: "myVolume"
};
volumeManager.formatPartition(diskId, partitionNum, params).then(() => {
  console.info("formatPartition successfully.");
}).catch((error: BusinessError) => {
  console.error(`formatPartition failed with error, code is: ${error.code}, message is: ${error.message}`);
});
```

## volumemanager.isVolumeInUse

isVolumeInUse(volumePath: string): Promise&lt;boolean&gt;

查询指定卷是否处于占用状态。使用Promise异步回调。

**起始版本**：26.0.0

**需要权限**：ohos.permission.MOUNT_UNMOUNT_MANAGER

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

**参数：**

| 参数名   | 类型   | 必填 | 说明 |
| -------- | ------ | ---- | ---- |
| volumePath | string | 是   | 指定卷的物理路径。 |

**返回值：**

| 类型                   | 说明       |
| ---------------------- | ---------- |
| Promise&lt;boolean&gt; | Promise对象，返回指定卷是否处于被占用状态，true代表正在被占用，false代表未被占用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600010 | The input parameter is invalid. |
| 13600033 | Failed to query whether the specified volume is currently in use. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let volumePath: string = "";
volumeManager.isVolumeInUse(volumePath).then(() => {
  console.info("isVolumeInUse successfully.");
}).catch((error: BusinessError) => {
  console.error(`isVolumeInUse failed with error, code is: ${error.code}, message is: ${error.message}`);
});
```

## Volume

卷信息详情。

### 属性

**系统接口**：此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.StorageService.Volume。

| 名称         | 类型    | 只读   | 可选   | 说明                 |
| ----------- | ------- | ------- | ----- | -------------------- |
| id          | string  | 否 | 否 | 卷设备ID的格式为vol-{主设备号}-{次设备号}，主设备号用来区分不同种类的设备，次设备号用来区分同一类型的多个设备，卷设备ID会随着插卡顺序不同而变化。                 |
| uuid        | string  | 否 | 否 | 卷设备uuid是卷设备的通用唯一识别码，不会随着插卡顺序变化而变化，但是卷设备的格式化会改变卷设备的uuid。               |
| diskId      | string  | 否 | 否 | 卷设备所属的磁盘ID，一个磁盘可以有一个或者多个卷设备。磁盘设备ID的格式为disk-{主设备号}-{次设备号}，与卷设备ID的格式结构类似，均采用{主设备号}-{次设备号}的命名规则。        |
| description | string  | 否 | 否 | 卷设备描述。卷设备的格式化会改变卷设备描述。           |
| removable   | boolean | 否 | 否 | 表示卷设备是否可移除。当前仅支持查询可移除存储设备，因此该字段值始终为true。true表示可移除；false表示不可移除。 |
| state       | number  | 否 | 否 | 卷设备状态标识：<br>0：卸载状态 UNMOUNTED。<br> 1：检查状态 CHECKING。<br> 2：挂载状态 MOUNTED。<br> 3：正在弹出状态 EJECTING。          |
| path        | string  | 否 | 否 | 卷设备的挂载地址，一般为/mnt/data/external/{uuid}。卷设备的格式化会改变挂载路径。         |
| fsType<sup>12+</sup>        | string  | 否 | 否 | 文件系统的类型，取值包括ext2、vfat、ntfs等。<br>**说明**：从API version 24开始，还支持ISO9660、UDF。      |
| partitionNum   | number  | 否 | 是 | 卷设备的分区号。该字段为可选字段，不存在时表示无分区号信息。<br>**起始版本：** 26.0.0<br>**模型约束**：此接口仅可在Stage模型下使用。         |
| extraInfo   | string  | 否 | 是 | 卷设备的扩展信息，包含设备的附加属性数据，具体内容因设备类型不同而异。该字段为可选字段，不存在时表示无扩展信息。<br>**起始版本：** 26.0.0<br>**模型约束**：此接口仅可在Stage模型下使用。         |

## DiskType

磁盘类型的枚举。

### 枚举值

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

| 名称         | 值    | 说明                 |
| ----------- | ------- | -------------------- |
| SD_CARD     | 1       | SD卡类型。     |
| USB_FLASH   | 2       | U盘类型。     |
| CD_DVD_BD   | 3       | 光盘类型。     |
| DATA_DISK_SSD | 4       | SSD数据盘类型。     |
| DATA_DISK_HDD | 5       | HDD数据盘类型。     |
| DVR_USB  | 6       | 行车记录仪U盘类型。     |
| UNKNOWN_DISK_TYPE | 255       | 未知磁盘类型。     |

## Disk

磁盘信息详情。

### 属性

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

| 名称         | 类型    | 只读   | 可选   | 说明                 |
| ----------- | ------- | ------- | ----- | -------------------- |
| diskId      | string  | 否 | 否 | 磁盘设备ID，格式为disk-{主设备号}-{次设备号}。                 |
| sizeBytes   | number  | 否 | 否 | 磁盘总大小，单位Byte。               |
| diskType    | [DiskType](#disktype) | 否 | 否 | 磁盘类型。        |
| removable   | boolean | 否 | 否 | 表示磁盘是否可移除，true为可移除；false为不可移除。默认为true。           |
| volumeIds   | Array&lt;string&gt; | 否 | 否 | 磁盘包含的卷设备ID数组，一个磁盘可以包含一个或多个卷设备。         |
| extraInfo   | string  | 否 | 否 | 磁盘设备的扩展信息，包含磁盘的附加属性数据，具体内容因设备类型不同而异。         |

## PartitionInfo

分区信息详情。

### 属性

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

| 名称         | 类型    | 只读   | 可选   | 说明                 |
| ----------- | ------- | ------- | ----- | -------------------- |
| partitionNum | number  | 否 | 否 | 分区号。                 |
| diskId      | string  | 否 | 否 | 磁盘设备ID，格式为disk-{主设备号}-{次设备号}。               |
| startSector | number  | 否 | 否 | 分区的起始扇区号。        |
| endSector   | number  | 否 | 否 | 分区的结束扇区号。           |
| sizeBytes   | number  | 否 | 否 | 分区总大小，单位Byte。         |
| fsType      | string  | 否 | 否 | 文件系统类型，当前支持的格式为ext4、vfat、exfat、ntfs、f2fs和hmfs。         |

## PartitionTableInfo

分区表信息详情。

### 属性

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

| 名称         | 类型    | 只读   | 可选   | 说明                 |
| ----------- | ------- | ------- | ----- | -------------------- |
| diskId      | string  | 否 | 否 | 磁盘设备ID，格式为disk-{主设备号}-{次设备号}。                 |
| tableType   | string  | 否 | 否 | 分区表类型，如gpt或mbr。               |
| partitionCount | number  | 否 | 否 | 分区数量。        |
| totalSector | number  | 否 | 否 | 总扇区数。           |
| sectorSize  | number  | 否 | 否 | 每个扇区的大小，单位Byte。         |
| alignSector | number  | 否 | 否 | 分区对齐所依据的扇区号，用于确保分区起始位置与物理扇区边界对齐。         |
| partitions  | Array&lt;[PartitionInfo](#partitioninfo)&gt; | 否 | 否 | 分区信息数组。         |

## PartitionParams

对指定磁盘执行创建分区时所需的参数。

### 属性

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

| 名称         | 类型    | 只读   | 可选   | 说明                 |
| ----------- | ------- | ------- | ----- | -------------------- |
| partitionNum | number  | 否 | 否 | 分区号。                 |
| startSector | number  | 否 | 否 | 分区的起始扇区号。               |
| endSector   | number  | 否 | 否 | 分区的结束扇区号。        |
| typeCode    | string  | 否 | 否 | 文件系统代码，当前支持的格式为ext4、vfat、exfat、ntfs、f2fs和hmfs。           |

## FormatParams

对指定分区执行格式化时所需的参数。

### 属性

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

**系统接口**：此接口为系统接口。

| 名称         | 类型    | 只读   | 可选   | 说明                 |
| ----------- | ------- | ------- | ----- | -------------------- |
| fsType      | string  | 否 | 否 | 文件系统类型，当前支持格式化为ext4、vfat和exfat。                 |
| quickFormat | boolean | 否 | 是 | 是否执行快速格式化。当前仅支持快速格式化，因此该参数只支持传true。传false时将返回参数非法错误，错误码13600010。默认值为true。               |
| volumeName  | string  | 否 | 是 | 格式化后的卷名称。不传入时默认使用空字符串作为卷名称。        |