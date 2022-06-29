# 卷管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> - 本模块首批接口从API version 9开始支持。
> - API 9当前为Canary版本，仅供试用，不保证接口可稳定调用。
> - 本模块接口为系统接口，三方应用不支持调用。

该模块提供卷、磁盘查询和管理的相关功能：包括查询卷信息，对卷的挂载卸载、对磁盘分区以及卷的格式化等功能。

## 导入模块

```js
import volumemanager from "@ohos.volumeManager";
```

## volumemanager.getAllVolumes

getAllVolumes(): Promise&lt;Array&lt;Volume&gt;&gt;

异步获取当前所有可获得的卷信息，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 返回值

  | 类型                               | 说明                       |
  | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | 返回当前所有可获得的卷信息 |

- 示例

  ```js
  volumemanager.getAllVolumes().then(function(volumes){
      // do something
  });
  ```

## volumemanager.getAllVolumes

getAllVolumes(callback: AsyncCallback&lt;Array&lt;Volume&gt;&gt;): void

异步获取当前所有可获得的卷信息，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名   | 类型                                              | 必填 | 说明                                 |
  | -------- | ------------------------------------------------- | ---- | ------------------------------------ |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)[]&gt; | 是   | 获取当前所有可获得的卷信息之后的回调 |
  
- 示例

  ```js
  let uuid = "";
  volumemanager.getAllVolumes(function(error, volumes){
      // do something
  });
  ```


## volumemanager.mount

mount(volumeId: string): Promise&lt;boolean&gt;

异步挂载指定卷，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷id |

- 返回值

  | 类型                   | 说明       |
  | ---------------------- | ---------- |
  | Promise&lt;boolean&gt; | 挂载指定卷 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId).then(function(flag){
      // do something
  });
  ```

## volumemanager.mount

mount(volumeId: string, callback:AsyncCallback&lt;boolean&gt;):void

异步获取指定卷的可用空间大小，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名   | 类型                                  | 必填 | 说明                 |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | 是   | 卷id                 |
  | callback | callback:AsyncCallback&lt;boolean&gt; | 是   | 挂载指定卷之后的回调 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId, function(error, flag){
      // do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string): Promise&lt;boolean&gt;

异步卸载指定卷，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷id |

- 返回值

  | 类型                   | 说明       |
  | ---------------------- | ---------- |
  | Promise&lt;boolean&gt; | 卸载指定卷 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId).then(function(flag){
      // do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string, callback:AsyncCallback&lt;boolean&gt;):void

异步卸载指定卷，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名   | 类型                                  | 必填 | 说明                 |
  | -------- | ------------------------------------- | ---- | -------------------- |
  | volumeId | string                                | 是   | 卷id                 |
  | callback | callback:AsyncCallback&lt;boolean&gt; | 是   | 卸载指定卷之后的回调 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId, function(error, flag){
      // do something
  });
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string): Promise<Volume>;

异步通过uuid获得卷信息，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名   | 类型   | 必填 | 说明 |
    | -------- | ------ | ---- | ---- |
  | uuid | string | 是   | uuid |

- 返回值

  | 类型                               | 说明                       |
    | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | 返回当前所有可获得的卷信息 |

- 示例

  ```js
  let uuid = "";
  let volume = await volumemanager.getVolumeByUuid(uuid);
  ```

## volumemanager.getVolumeByUuid

getVolumeByUuid(uuid: string, callback: AsyncCallback<Volume>): void;

异步通过uuid获得卷信息，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名    | 类型                                                 | 必填 | 说明                 |
  | -------- | ------------------------------------------------ | ---- | -------------------- |
  | uuid | string                                                 | 是   | uuid                 |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)[]&gt;  | 是   | 获取卷信息之后的回调 |

- 示例

  ```js
  let uuid = "";
  volumemanager.getVolumeByUuid(uuid, (error, volume) => {
      // do something    
  });
  ```

## volumemanager.getVolumeById

getVolumeById(volumeId: string): Promise<Volume>;

异步通过卷id获得卷信息，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名   | 类型   | 必填 | 说明 |
      | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷id |

- 返回值

  | 类型                               | 说明                       |
      | ---------------------------------- | -------------------------- |
  | Promise&lt;[Volume](#volume)[]&gt; | 返回当前所有可获得的卷信息 |

- 示例

  ```js
  let volumeId = "";
  let volume = await volumemanager.getVolumeById(volumeId);
  ```

## volumemanager.getVolumeById

getVolumeById(volumeId: string, callback: AsyncCallback<Volume>): void;

异步通过卷id获得卷信息，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名    | 类型                                                 | 必填 | 说明                 |
    | -------- | ------------------------------------------------ | ---- | -------------------- |
  | volumeId | string                                              | 是   | volumeId                 |
  | callback | callback:AsyncCallback&lt;[Volume](#volume)[]&gt;  | 是   | 获取卷信息之后的回调 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.getVolumeById(volumeId, (error, volume) => {
      // do something    
  });
  ```

## volumemanager.setVolumeDescription

setVolumeDescription(uuid: string, description: string): Promise<boolean>;

异步通过uuid设置卷描述，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名     | 类型   | 必填 | 说明 |
  | --------- | ------ | ---- | ---- |
  | uuid      | string | 是   | 卷uuid |
  | description | string | 是   | 卷描述 |

- 返回值

  | 类型                    | 说明                       |
  | ---------------------- | -------------------------- |
  | Promise&lt;boolean&gt; | 设置卷信息                  |

- 示例

  ```js
  let uuid = "";
  let description = "";
  let bool = await volumemanager.setVolumeDescription(uuid, description);
  ```

## volumemanager.setVolumeDescription

function setVolumeDescription(uuid: string, description: string, callback: AsyncCallback<boolean>): void;

异步通过uuid设置卷描述，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名      | 类型                                     | 必填 | 说明              |
  | ---------- | --------------------------------------- | ---- | ---------------- |
  | uuid       | string                                  | 是   | 卷uuid            |
  | description | string                                 | 是   | 卷描述            |
  | callback   | callback:AsyncCallback&lt;boolean&gt;   | 是   | 设置卷描述之后的回调 |

- 示例

  ```js
  let uuid = "";
  let description = "";
  volumemanager.setVolumeDescription(uuid, description, (error, bool) => {
      // do something    
  });
  ```

## volumemanager.format

format(volumeId: string, fsType: string): Promise<boolean>;

异步对指定卷进行格式化，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名       | 类型   | 必填 | 说明 |
  | ----------- | ------ | ---- | ---- |
  | volumeId    | string | 是   | 卷id |
  | fsType      | string | 是   | 文件系统类型 |

- 返回值

  | 类型                    | 说明                       |
    | --------------------- | ----------------------- |
  | Promise&lt;boolean&gt; | 对指定卷进行格式化            |

- 示例

  ```js
  let volumeId = "";
  let fsType = "";
  let bool = await volumemanager.format(volumeId, fsType);
  ```

## volumemanager.format

format(volumeId: string, fsType: string, callback: AsyncCallback<boolean>): void;

异步对指定卷进行格式化，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名      | 类型                                     | 必填 | 说明              |
    | -------- | --------------------------------------- | ---- | ---------------- |
  | volumeId   | string                                  | 是   | 卷id            |
  | fsType     | string                                  | 是   | 文件系统类型            |
  | callback   | callback:AsyncCallback&lt;boolean&gt;   | 是   | 对指定卷进行格式化  |

- 示例

  ```js
  let volumeId = "";
  let fsType = "";
  volumemanager.format(volumeId, fsType, (error, bool) => {
      // do something    
  });
  ```

## volumemanager.partition

partition(diskId: string, type: number): Promise<boolean>;

异步对磁盘进行分区，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名       | 类型   | 必填 | 说明 |
    | ----------- | ------ | ---- | ---- |
  | diskId    | string | 是   | 卷所属的磁盘id |
  | type      | number | 是   | 分区类型    |

- 返回值

  | 类型                      | 说明                       |
   | --------------------- | ----------------------- |
  | Promise&lt;boolean&gt;   | 对磁盘进行分区              |

- 示例

  ```js
  let diskId = "";
  let type = 0;
  let bool = await volumemanager.partition(diskId, type);
  ```

## volumemanager.partition

partition(diskId: string, type: number, callback: AsyncCallback<boolean>): void;

异步对磁盘进行分区，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.Volume

- 参数

  | 参数名      | 类型                                     | 必填 | 说明              |
      | -------- | ------------------------------------- | ---- | ---------------- |
  | diskId   | string                                    | 是   | 卷所属的磁盘id            |
  | type     | number                                    | 是   | 分区类型            |
  | callback   | callback:AsyncCallback&lt;boolean&gt;   | 是   | 对磁盘进行分区  |

- 示例

  ```js
  let diskId = "";
  let type = 0;
  volumemanager.format(diskId, type, (error, bool) => {
      // do something    
  });
  ```

## Volume

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.StorageService.Volume。

### 属性

| 名称         | 类型    | 说明                 |
| ----------- | ------- | -------------------- |
| id          | number  | 卷id                 |
| uuid        | string  | 卷uuid               |
| diskId      | string  | 卷diskId               |
| description | string  | 卷相关描述           |
| removable   | boolean | 是否为可移动存储设备 |
| state       | int     | 当前卷状态           |
| path        | string  | 卷的挂载地址         |