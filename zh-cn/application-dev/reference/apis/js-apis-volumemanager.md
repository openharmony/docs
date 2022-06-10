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

## Volume

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.StorageService.Volume。

### 属性

| 名称        | 类型    | 说明                 |
| ----------- | ------- | -------------------- |
| id          | number  | 卷id                 |
| uuid        | string  | 卷uuid               |
| description | string  | 卷相关描述           |
| removable | boolean | 是否为可移动存储设备 |
| state       | int     | 当前卷状态           |
| path        | string  | 卷的挂载地址         |