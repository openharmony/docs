# 卷管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本

## 导入模块

```js
import volumemanager from "@ohos.volumemanager";
```

## 系统能力

SystemCapability.FileManagement.StorageService.Volume

## volumemanager.getAllVolumes

getAllVolumes(): Promise\<Volume[]\>

异步获取当前所有可获得的卷信息，以promise方式返回。

- 返回值

  | 类型                           | 说明                       |
  | ------------------------------ | -------------------------- |
  | Promise\<[Volume](#volume)[]\> | 返回当前所有可获得的卷信息 |

- 示例

  ```js
  volumemanager.getAllVolumes().then(function(volumes){
      // do something
  });
  ```

## volumemanager.getAllVolumes

getAllVolumes(callback:AsyncCallback\<Volume[]\>):void

异步获取当前所有可获得的卷信息，以callback方式返回。

- 参数

  | 参数名   | 类型                                          | 必填 | 说明                                 |
  | -------- | --------------------------------------------- | ---- | ------------------------------------ |
  | callback | callback:AsyncCallback\<[Volume](#volume)[]\> | 是   | 获取当前所有可获得的卷信息之后的回调 |
  
- 示例

  ```js
  let uuid = "";
  volumemanager.getAllVolumes(uuid, function(error, volumes){
      // do something
  });
  ```


## volumemanager.mount

mount(volumeId: string): Promise\<boolean\>

异步挂载指定卷，以promise方式返回。

- 参数

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷id |

- 返回值

  | 类型               | 说明       |
  | ------------------ | ---------- |
  | Promise\<boolean\> | 挂载指定卷 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId).then(function(flag){
      // do something
  });
  ```

## volumemanager.mount

mount(volumeId: string, callback:AsyncCallback\<boolean\>):void

异步获取指定卷的可用空间大小，以callback方式返回。

- 参数

  | 参数名   | 类型                              | 必填 | 说明                 |
  | -------- | --------------------------------- | ---- | -------------------- |
  | volumeId | string                            | 是   | 卷id                 |
  | callback | callback:AsyncCallback\<boolean\> | 是   | 挂载指定卷之后的回调 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.mount(volumeId, function(error, flag){
      // do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string): Promise\<boolean\>

异步卸载指定卷，以promise方式返回。

- 参数

  | 参数名   | 类型   | 必填 | 说明 |
  | -------- | ------ | ---- | ---- |
  | volumeId | string | 是   | 卷id |

- 返回值

  | 类型               | 说明       |
  | ------------------ | ---------- |
  | Promise\<boolean\> | 卸载指定卷 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId).then(function(flag){
      // do something
  });
  ```

## volumemanager.unmount

unmount(volumeId: string, callback:AsyncCallback\<boolean\>):void

异步卸载指定卷，以callback方式返回。

- 参数

  | 参数名   | 类型                              | 必填 | 说明                 |
  | -------- | --------------------------------- | ---- | -------------------- |
  | volumeId | string                            | 是   | 卷id                 |
  | callback | callback:AsyncCallback\<boolean\> | 是   | 卸载指定卷之后的回调 |

- 示例

  ```js
  let volumeId = "";
  volumemanager.unmount(volumeId, function(error, flag){
      // do something
  });
  ```

## Volume

### 属性

| 名称        | 类型    | 说明                 |
| ----------- | ------- | -------------------- |
| id          | number  | 卷id                 |
| uuid        | string  | 卷uuid               |
| description | string  | 卷相关描述           |
| removeAble  | boolean | 是否为可移动存储设备 |
| state       | int     | 当前卷状态           |
| path        | string  | 卷的挂载地址         |