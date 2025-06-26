# @ohos.file.fileExtensionInfo (公共文件访问与管理属性信息)(系统接口)

该模块提供公共文件访问和管理模块中RootInfo与FileInfo中部分属性值的定义。

>**说明：**
>
>- 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>- 本模块为系统接口。

## 导入模块

```ts
import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
```

## fileExtensionInfo.DeviceType

组成RootInfo中的deviceType字段，表明此设备的类型。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

| 名称 | 值 | 说明 |
| ----- | ------ | ------ |
| DEVICE_LOCAL_DISK | 1 | 本地c,d...盘。 |
| DEVICE_SHARED_DISK | 2 | 多用户共享盘。 |
| DEVICE_SHARED_TERMINAL | 3 | 分布式网络终端设备。 |
| DEVICE_NETWORK_NEIGHBORHOODS | 4 | 网络邻居设备。 |
| DEVICE_EXTERNAL_MTP | 5 | MTP设备。 |
| DEVICE_EXTERNAL_USB | 6 | USB设备。 |
| DEVICE_EXTERNAL_CLOUD | 7 | 云盘设备。 |

## fileExtensionInfo.DeviceFlag

组成RootInfo中的deviceFlags字段，通过与运算判断是否具备某种能力。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

### 属性

  | 名称 | 类型   | 只读 | 可选 | 说明     |
  | ------ | ------ | ---- | ---- | -------- |
  | SUPPORTS_READ   | number | 否   | 否   | 此设备支持读。 |
  | SUPPORTS_WRITE   | number | 否   | 否   | 此设备支持写。 |

## fileExtensionInfo.DocumentFlag

组成FileInfo中的mode字段，通过与运算判断是否具备某种能力。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileService

### 属性

  | 名称 | 类型   | 只读 | 可选 | 说明     |
  | ------ | ------ | ---- | ---- | -------- |
  | REPRESENTS_FILE   | number | 否   | 否   | 代表文件。 |
  | REPRESENTS_DIR   | number | 否   | 否   | 代表目录。 |
  | SUPPORTS_READ   | number | 否   | 否   | 此文件支持读。 |
  | SUPPORTS_WRITE   | number | 否   | 否   | 此文件支持写。 |
  