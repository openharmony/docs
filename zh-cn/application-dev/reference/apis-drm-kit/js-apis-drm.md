# @ohos.multimedia.drm (数字版权保护)

DRM（Digital Rights Management）框架组件支持音视频媒体业务数字版权管理功能的开发。开发者可以调用系统提供的DRM插件，完成以下功能：

* DRM证书管理：生成证书请求、设置证书响应，实现对证书Provision（下载）功能。
* DRM许可证管理：生成许可证请求、设置许可证响应，实现对许可证的离线管理等功能。
* DRM节目授权：支持底层DRM插件根据许可证对DRM节目授权。
* DRM节目解密：支持媒体播放功能的解密调用，实现对DRM节目的解密和播放。

> **说明：**
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import drm from '@ohos.multimedia.drm';
```

## DrmErrorCode

枚举，错误码。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| ERROR_UNKNOWN       | 24700101    | 未知错误   |
| MAX_SYSTEM_NUM_REACHED   | 24700103    | MediaKeySystem实例数量达到64     |
| MAX_SESSION_NUM_REACHED    | 24700104    | MediaKeySession实例数量达到64       |
| SERVICE_FATAL_ERROR  | 24700201    | IPC服务错误     |

## PreDefinedConfigName

枚举，配置选项名。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CONFIG_DEVICE_VENDOR        | 'vendor'    | 插件名   |
| CONFIG_DEVICE_VERSION    | 'version'    | 插件版本号     |
| CONFIG_DEVICE_DESCRIPTION     | 'description'    | 设备描述符       |
| CONFIG_DEVICE_ALGORITHMS   | 'algorithms'    | 算法名     |
| CONFIG_DEVICE_UNIQUE_ID    | 'deviceUniqueId'    | 设备唯一编号     |
| CONFIG_SESSION_MAX         | 'maxSessionNum'    | 设备支持的最大会话数     |
| CONFIG_SESSION_CURRENT   | 'currentSessionNum'    | 当前会话数量     |

## MediaKeyType

枚举，许可证类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| MEDIA_KEY_TYPE_OFFLINE        | 0    | 离线   |
| MEDIA_KEY_TYPE_ONLINE   | 1    | 在线     |

## OfflineMediaKeyStatus

枚举，离线许可证状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN        | 0    | 未知状态   |
| OFFLINE_MEDIA_KEY_STATUS_USABLE   | 1    | 可用状态     |
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE     | 2    | 失活状态       |

## CertificateStatus

枚举，证书状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CERT_STATUS_PROVISIONED        | 0    | 设备已安装设备证书   |
| CERT_STATUS_NOT_PROVISIONED   | 1    | 设备未安装设备证书     |
| CERT_STATUS_EXPIRED    | 2    | 设备证书过期       |
| CERT_STATUS_INVALID  | 3    | 设备证书无效     |
| CERT_STATUS_UNAVAILABLE  | 4    | 设备证书不可用     |

## MediaKeyRequestType

枚举，请求类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| MEDIA_KEY_REQUEST_TYPE_UNKNOWN        | 0    | 未知请求类型   |
| MEDIA_KEY_REQUEST_TYPE_INITIAL    | 1    | 初始化请求     |
| MEDIA_KEY_REQUEST_TYPE_RENEWAL     | 2    | 续订请求       |
| MEDIA_KEY_REQUEST_TYPE_RELEASE   | 3    | 释放请求     |
| MEDIA_KEY_REQUEST_TYPE_NONE    | 4    | 无请求     |
| MEDIA_KEY_REQUEST_TYPE_UPDATE    | 5    | 更新请求     |

## ContentProtectionLevel

枚举，内容保护级别。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CONTENT_PROTECTION_LEVEL_UNKNOWN        | 0    | 未知级别   |
| CONTENT_PROTECTION_LEVEL_SW_CRYPTO   | 1    | 软件内容保护级别     |
| CONTENT_PROTECTION_LEVEL_HW_CRYPTO    | 2    | 硬件内容保护级别       |
| CONTENT_PROTECTION_LEVEL_ENHANCED_HW  | 3    | 硬件增强级别     |
| CONTENT_PROTECTION_LEVEL_MAX  | 4    | 最高内容保护级别     |

## ProvisionRequest

设备证书请求。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| data   | Uint8Array | 是  | 设备证书请求数据      |
| defaultURL     | string                 | 是  | Provision服务器URL       |

## OptionsData

设备证书请求的操作数据。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | 是  | 操作数据名      |
| value     | string                 | 是  | 操作数据值       |

## MediaKeyRequest

许可证请求。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| mediaKeyRequestType   | [MediaKeyRequestType](#mediakeyrequesttype) | 是  | 许可证请求类型      |
| data     | Uint8Array                 | 是  | 许可证请求数据       |
| defaultURL     | string                 | 是  | License服务器URL       |

## EventInfo

事件类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| info   | Uint8Array | 是  | 事件信息      |
| extraInfo     | string                 | 是  | 事件额外信息       |

## StatisticKeyValue

统计信息。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | 是  | 统计信息名      |
| value     | string                 | 是  | 统计信息值       |

## MediaKeyStatus

许可证状态

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | 是  | 字符串类型许可证Id      |
| value     | string                 | 是  | 许可证状态值       |

## KeysInfo

许可证信息

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| keyId   | Uint8Array | 是  | 字符数组类型许可证Id      |
| value     | string                 | 是  | 许可证状态值       |

## MediaKeySystemInfo

指示媒体源的drm信息。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| uuid   | string | 是  | 插件唯一标识码      |
| pssh     | Uint8Array                 | 是  | drm info内的保护方案特定标头       |

## MediaKeySystemDescription<sup>12+</sup>

设备支持的插件信息，包含插件名称和插件唯一标识码uuid。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | 是  | 插件名称      |
| uuid   | string | 是  | 插件唯一标识码      |

## drm.createMediaKeySystem

createMediaKeySystem(name: string): MediaKeySystem

创建MediaKeySystem实例，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | 是   | 插件类型。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySystem](#mediakeysystem)           | MediaKeySystem实例。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700103                |  Meet max MediaKeySystem num limit                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';
try {
  let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySystem ERROR: ${error}`);  
}
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string): boolean

判断设备是否支持指定DRM类型的DRM方案。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | 是   | 插件类型。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [boolean]          | 返回设备是否支持指定DRM类型的DRM方案。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

try {
  let Supported = drm.isMediaKeySystemSupported("com.clearplay.drm");
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);  
}

```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string, mimeType: string): boolean

判断设备是否支持指定DRM类型、媒体类型的DRM方案。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | 是   | 插件类型。                   |
| mimeType  | string     | 是   | 媒体类型，支持的媒体类型由设备上的DRM方案决定。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [boolean]          | 返回设备是否支持指定DRM类型、媒体类型的DRM方案。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.                |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

try {
  let Supported = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/mp4");
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);
}
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string, mimeType: string, level: ContentProtectionLevel): boolean

判断设备是否支持指定DRM类型、媒体类型和内容保护级别的DRM方案。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | 是   | 插件类型。                   |
| mimeType  | string     | 是   | 媒体类型，支持的媒体类型由设备上的DRM方案决定。                   |
| level  | [ContentProtectionLevel](#contentprotectionlevel)     | 是   | 设备内容保护级别。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [boolean]          | 返回设备是否支持指定DRM类型、媒体类型和内容保护级别的DRM方案。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed.  Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed, the param name's length is zero or too big(exceeds 4096 Bytes)               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

try {
  let Supported = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/mp4", drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);
}

```

## drm.getMediaKeySystemUuid<sup>12+</sup>

getMediaKeySystemUuid(): string

获取设备支持的DRM插件的名称和uuid。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | 是   | 插件名称。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| uuid  | string     | 是   | 插件唯一识别码。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed                |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';
try {
  let uuid: string = drm.getMediaKeySystemUuid();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getMediaKeySystemUuid ERROR: ${error}`);  
}
```

## drm.getMediaKeySystems<sup>12+</sup>

getMediaKeySystems(): MediaKeySystemDescription[]

获取设备支持的DRM插件的名称和uuid。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | 是   | 插件名称。                   |
| uuid  | string     | 是   | 插件唯一识别码。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySystemDescription[]](#mediakeysystemdescription12)           | 设备支持的插件信息，包含插件名称和插件唯一标识码uuid。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';
try {
  let description: drm.MediaKeySystemDescription[] = drm.getMediaKeySystems();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getMediaKeySystems ERROR: ${error}`);  
}
```

## MediaKeySystem
管理和记录MediaKeySession。在调用MediaKeySystem方法之前，必须使用[createMediaKeySystem](#drmcreatemediakeysystem)获取一个MediaKeySystem实例，然后才能调用其成员函数。

### setConfigurationString

setConfigurationString(configName: string, value: string): void

设置配置信息以字符串类型返回。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | 是   | 配置类型名，由设备上的DRM方案决定。                   |
| value  | string     | 是   | 配置属性值。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  mediaKeysystem.setConfigurationString("configName", "configValue");
} catch (err) {
  let error = err as BusinessError;
  console.error(`setConfigurationString ERROR: ${error}`);
}

```

### getConfigurationString

getConfigurationString(configName: string): string

获取配置信息以字符串类型返回。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | 是   | 配置类型名。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| string          | 返回字符串类型的配置属性值。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed, the param's length is zero or too big(exceeds 4096 Bytes).                              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let configValue: string = mediaKeysystem.getConfigurationString("configName");
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationString ERROR: ${error}`);  
}

```

### setConfigurationByteArray

setConfigurationByteArray(configName: string, value: Uint8Array): void

设置配置信息以字符数组类型返回。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | 是   | 配置类型名。                   |
| value  | Uint8Array     | 是   | 数组类型的配置属性值。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let configValue = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
try {
  mediaKeysystem.setConfigurationByteArray("configName", configValue);
} catch (err) {
  let error = err as BusinessError;
  console.error(`setConfigurationByteArray ERROR: ${error}`);  
}

```

### getConfigurationByteArray

getConfigurationByteArray(configName: string): Uint8Array

获取配置信息以字符数组类型返回。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | 是   | 配置类型名。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Uint8Array          | 返回数组类型的配置属性值。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.        |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let configValue: Uint8Array = mediaKeysystem.getConfigurationByteArray("configName");
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);  
}

```

### getStatistics

getStatistics(): StatisticKeyValue[]

获取性能统计信息。其中包括当前会话数、插件版本信息、解密次数和解密失败次数。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [StatisticKeyValue[]](#statistickeyvalue)          | 返回数组类型的性能统计信息。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let statisticKeyValue: drm.StatisticKeyValue[] = mediaKeysystem.getStatistics();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);
}

```

### getMaxContentProtectionLevel

getMaxContentProtectionLevel(): ContentProtectionLevel

获取设备支持的最大内容保护级别。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [ContentProtectionLevel](#contentprotectionlevel)          | 返回设备支持的最大内容保护级别。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let maxLevel: drm.ContentProtectionLevel = mediaKeysystem.getMaxContentProtectionLevel();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);
}

```

### generateKeySystemRequest

generateKeySystemRequest(): Promise<ProvisionRequest\>

生成获取mediaKeySystem设备证书的请求。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [ProvisionRequest](#provisionrequest)          | 获取mediaKeySystem设备证书的请求。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
mediaKeysystem.generateKeySystemRequest().then((ProvisionRequest: drm.ProvisionRequest) => {
  console.log("generateKeySystemRequest");
}).catch((err: BusinessError) => {
  console.error(`generateKeySystemRequest: ERROR: ${err}`);
});
```

### processKeySystemResponse

processKeySystemResponse(response: Uint8Array): Promise<void\>

处理应用程序获得的设备证书请求对应的响应。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| response  | Uint8Array     | 是   | 设备证书响应。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  he parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let keySystemResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeysystem.processKeySystemResponse(keySystemResponse).then(() => {
  console.log("processKeySystemResponse");
}).catch((err: BusinessError) => {
  console.error(`processKeySystemResponse: ERROR: ${err}`);
});
```

### getCertificateStatus

getCertificateStatus():CertificateStatus

获取Oem设备证书状态值。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [CertificateStatus](#certificatestatus)          | 返回Oem证书状态值。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let certificateStatus: drm.CertificateStatus = mediaKeysystem.getCertificateStatus();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getCertificateStatus ERROR: ${error}`);
}

```

### on('keySystemRequired')

on(type: 'keySystemRequired', callback: (eventInfo: EventInfo) => void): void

监听设备证书请求，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'keySystemRequired'，MediaKeySystem实例创建成功可监听。设备证书请求时触发该事件并返回。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 是   | 回调函数，用于获取结果，只要有该事件返回就证明需要请求设备证书。                 |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function registerkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
  mediaKeysystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
    console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
  });
}
```

### off('keySystemRequired')

off(type: 'keySystemRequired', callback?: (eventInfo: EventInfo) => void): void

注销监听设备证书请求，注销设备证书请求事件回调函数。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'keySystemRequired'，MediaKeySystem实例创建成功可监听。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 否   | 回调函数，可选。                |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
function unregisterkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
  mediaKeysystem.off('keySystemRequired');
}
```

### createMediaKeySession

createMediaKeySession(level: ContentProtectionLevel): MediaKeySession

根据给定的内容保护级别进行创建drm会话实例。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| level  | [ContentProtectionLevel](#contentprotectionlevel)     | 是   | 设备支持的内容保护级别。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySession](#mediakeysession)          | 返回创建的MediaKeySession实例。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.The param level exceeds reasonable range, please use value in ContentProtectionLevel.          |
| 24700101                 |  MAll unknown errors                  |
| 24700104                 |  Meet max MediaKeySession num limit                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession(drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySession ERROR: ${error}`);
}

```

### createMediaKeySession

createMediaKeySession(): MediaKeySession

根据默认的软件内容保护级别进行创建drm会话实例。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySession](#mediakeysession)          | 返回创建的MediaKeySession实例。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700104                 |  Meet max MediaKeySession num limit                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySession ERROR: ${error}`);
}

```

### getOfflineMediaKeyIds

getOfflineMediaKeyIds(): Uint8Array[]

获取离线许可证Id。

**系统能力：** SystemCapability.Multimedia.Drm.Core


**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Uint8Array[]          | 返回数组类型的离线许可证的Id。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let offlineMediaKeyIds: Uint8Array[] = mediaKeysystem.getOfflineMediaKeyIds();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOfflineMediaKeyIds ERROR: ${error}`);
}

```

### getOfflineMediaKeyStatus

getOfflineMediaKeyStatus(mediaKeyId: Uint8Array): OfflineMediaKeyStatus

获取离线许可证返回状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId | Uint8Array     | 是   | 离线许可证Id。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [OfflineMediaKeyStatus](#offlinemediakeystatus)          | 返回指定mediaKeyId对应的许可证状态值。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeyIdString = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
try {
  let configValue: drm.OfflineMediaKeyStatus = mediaKeysystem.getOfflineMediaKeyStatus(mediaKeyIdString);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
}

```

### clearOfflineMediaKeys

clearOfflineMediaKeys(mediaKeyId: Uint8Array): void

根据指定的离线许可证Id删除离线许可证。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | 是   | 离线许可证Id。                   | 离线许可证Id可以在MediaKeySession成员processMeidaKeyResponse返回值中获取 |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed.Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.           |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeyIdString = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
try {
  mediaKeysystem.clearOfflineMediaKeys(mediaKeyIdString);
} catch (err) {
  let error = err as BusinessError;
  console.error(`clearOfflineMediaKeys ERROR: ${error}`);
}

```

### destroy

destroy(): void

销毁MediaKeySystem运行时申请的资源。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  mediaKeysystem.destroy();
} catch (err) {
  let error = err as BusinessError;
  console.error(`mediaKeysystem destroy ERROR: ${error}`);
}

```

## MediaKeySession
许可证及解密模块管理。在调用MediaKeySession方法之前，我们必须使用[createMediaKeySession](#createmediakeysession)获取一个MediaKeySession实例，然后才能调用其成员函数。

### generateMediaKeyRequest

generateMediaKeyRequest(mimeType: string, initData: Uint8Array, mediaKeyType: number, options?: OptionsData[]): Promise<MediaKeyRequest\>

生成许可证请求。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mimeType  | string     | 是   | 媒体类型。                   |
| initData  | Uint8Array     | 是   | pssh数据（未base64编码）。                   |
| mediaKeyType| number     | 是   | 许可证类型。                   | 0表示在线，1表示离线 |
| OptionsData  | [OptionsData[]](#optionsdata)     | 是   | 预留的操作数据。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeyRequest](#mediakeyrequest)          | 返回许可证请求。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                | The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let optionsData: drm.OptionsData[]  = [
    {name : "optionsDataNameA", value : "optionsDataValueA"},
    {name : "optionsDataNameB", value : "optionsDataValueB"}
];
let uint8pssh = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateMediaKeyRequest("video/mp4", uint8pssh, 0, optionsData).then((mediaKeyRequest: drm.MediaKeyRequest) =>{
  console.log('generateMediaKeyRequest' + mediaKeyRequest);
}).catch((err: BusinessError) => {
  console.error(`generateMediaKeyRequest: ERROR: ${err}`);
});
```

### processMediaKeyResponse

processMediaKeyResponse(response: Uint8Array): Promise<Uint8Array\>

处理离线许可证响应返回。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| response  | Uint8Array     | 是   | 许可证响应。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [Uint8Array]          | 返回许可证Id。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let mediaKeyResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(mediaKeyResponse).then((mediaKeyId: Uint8Array) => {
  console.log('processMediaKeyResponse:' + mediaKeyId);
}).catch((err: BusinessError) => {
  console.error(`processMediaKeyResponse: ERROR: ${err}`);
});
```

### checkMediaKeyStatus

 checkMediaKeyStatus(): MediaKeyStatus[]

检查在线许可证状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeyStatus[]](#mediakeystatus)          | 返回数组类型的许可证状态值。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  let keyStatus: drm.MediaKeyStatus[] =  mediaKeySession.checkMediaKeyStatus();
} catch (err) {
  let error = err as BusinessError;
  console.error(`checkMediaKeyStatus ERROR: ${error}`);
}

```

### clearMediaKeys

clearMediaKeys(): void

删除在线许可证。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  mediaKeySession.clearMediaKeys();
} catch (err) {
  let error = err as BusinessError;
  console.error(`clearMediaKeys ERROR: ${error}`);
}
 
```

### generateOfflineReleaseRequest

generateOfflineReleaseRequest(mediaKeyId: Uint8Array): Promise<Uint8Array\>

生成离线许可证释放请求。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array    | 是   | 离线许可证Id                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [Uint8Array]          | 返回离线许可证释放的请求。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let Request = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(Request).then((mediaKeyId: Uint8Array) => {
  console.log('processMediaKeyResponse:' + mediaKeyId);
}).catch((err: BusinessError) => {
  console.error(`processMediaKeyResponse: ERROR: ${err}`);
});
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateOfflineReleaseRequest(mediaKeyId).then((offlineReleaseRequest: Uint8Array) => {
  console.log('generateOfflineReleaseRequest:' + offlineReleaseRequest);
}).catch((err: BusinessError) => {
  console.error(`generateOfflineReleaseRequest: ERROR: ${err}`);
});
```

### processOfflineReleaseResponse

processOfflineReleaseResponse(mediaKeyId: Uint8Array, response: Uint8Array): Promise<void\>

处理离线许可证响应。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | 是   | 离线许可证Id。                   |
| response  | Uint8Array     | 是   | 离线许可证释放响应。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let offlineReleaseRequest = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(offlineReleaseRequest).then((mediaKeyId: Uint8Array) => {
  console.log('processMediaKeyResponse:' + mediaKeyId);
}).catch((err: BusinessError) => {
  console.error(`processMediaKeyResponse: ERROR: ${err}`);
});
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
let response = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processOfflineReleaseResponse(mediaKeyId, response).then(() => {
  console.log('processOfflineReleaseResponse');
}).catch((err: BusinessError) => {
  console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
});
```

### restoreOfflineMediaKeys

restoreOfflineMediaKeys(mediaKeyId: Uint8Array): Promise<void\>

恢复离线许可证。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | 是   | 离线许可证Id。                   |


**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let response = new Uint8Array ([0x00,0x00]);
let mediaKeyId = new Uint8Array ([0x00,0x00]);
mediaKeySession.processOfflineReleaseResponse(mediaKeyId, response).then(() => {
  console.log('processOfflineReleaseResponse');
}).catch((err: BusinessError) => {
  console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
});
mediaKeySession.restoreOfflineMediaKeys(mediaKeyId).then(() => {
  console.log("restoreOfflineMediaKeys");
}).catch((err: BusinessError) => {
  console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
});
```

### getContentProtectionLevel

getContentProtectionLevel(): ContentProtectionLevel

获取当前会话的内容保护级别。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [ContentProtectionLevel](#contentprotectionlevel)          | 返回当前会话内容保护级别的值。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  let contentProtectionLevel: drm.ContentProtectionLevel = mediaKeySession.getContentProtectionLevel();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getContentProtectionLevel ERROR: ${error}`);
}

```

### requireSecureDecoderModule

requireSecureDecoderModule(mimeType: string): boolean

获取安全解码模块状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mimeType  | string     | 是   | 媒体类型。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [boolean]          | 请求安全解码模块状态，true表示安全解码模块就绪，false表示安全解码模块未就绪。                   |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.      |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  let status: boolean = mediaKeySession.requireSecureDecoderModule("mimeType");
} catch (err) {
  let error = err as BusinessError;
  console.error(`requireSecureDecoderModule ERROR: ${error}`);
}

```

### on('keyRequired')

on(type: 'keyRequired', callback: (eventInfo: EventInfo) => void): void

监听密钥请求事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'keyRequired'，MediaKeySystem实例创建成功可监听。key请求时触发该事件并返回。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明在进行key请求。                 |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function registerKeyRequired(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('keyRequired', (eventInfo: drm.EventInfo) => {
        console.log('keyRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
}
```

### off('keyRequired')

off(type: 'keyRequired', callback?: (eventInfo: EventInfo) => void): void

注销监听密钥请求事件，注销密钥请求事件回调函数。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'keyRequired'，MediaKeySystem实例创建成功可监听。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 否   | 回调函数，可选                |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.             |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterKeyRequired(mediaKeysession: drm.MediaKeySession): void {
  mediaKeysession.off('keyRequired');
}
```

### on('keyExpired')

on(type: 'keyExpired', callback: (eventInfo: EventInfo) => void): void

监听密钥过期，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'keyExpired'，MediaKeySystem实例创建成功可监听。密钥过期时触发该事件并返回。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明会话丢失。                 |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.          |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function registerKeyExpired(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('keyExpired', (eventInfo: drm.EventInfo) => {
        console.log('keyExpired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
}
```

### off('keyExpired')

off(type: 'keyExpired', callback?: (eventInfo: EventInfo) => void): void

注销监听密钥过期事件，注销密钥过期事件回调函数。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'keyExpired'，MediaKeySystem实例创建成功可监听。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 否   | 回调函数，可选                |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterKeyExpired(mediaKeysession: drm.MediaKeySession): void {
  mediaKeysession.off('keyExpired');
}
```

### on('vendorDefined')

on(type: 'vendorDefined', callback: (eventInfo: EventInfo) => void): void

监听第三方定义事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'vendorDefined'，MediaKeySystem实例创建成功可监听。第三方定义事件发生时触发该事件并返回。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明会话丢失。                 |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function registerVendorDefinedt(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('vendorDefined', (eventInfo: drm.EventInfo) => {
        console.log('vendorDefined' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
}
```

### off('vendorDefined')

off(type: 'vendorDefined', callback?: (eventInfo: EventInfo) => void): void

注销监听第三方定义事件，注销第三方定义事件回调函数。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'vendorDefined'，MediaKeySystem实例创建成功可监听。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 否   | 回调函数，可选                |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.      |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterVendorDefined(mediaKeysession: drm.MediaKeySession): void {
  mediaKeysession.off('vendorDefined');
}
```

### on('expirationUpdate')

on(type: 'expirationUpdate', callback: (eventInfo: EventInfo) => void): void

监听过期更新事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'expirationUpdate'，MediaKeySystem实例创建成功可监听。密钥过期更新时触发该事件并返回。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明会话丢失。                 |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.        |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function registerExpirationUpdate(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
        console.log('expirationUpdate' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
}
```

### off('expirationUpdate')

off(type: 'expirationUpdate', callback?: (eventInfo: EventInfo) => void): void

注销监听过期更新事件，注销过期更新事件回调函数。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'expirationUpdate'，MediaKeySystem实例创建成功可监听。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 否   | 回调函数，可选                |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.       |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterExpirationUpdate(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.off('expirationUpdate');
}
```

### on('keysChange')

on(type: 'keysChange', callback: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void

监听密钥变化事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'keysChange'，MediaKeySystem实例创建成功可监听。密钥变化时触发该事件并返回。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明会话丢失。                 |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.             |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function registerkeysChange(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('keysChange', (keyInfo: drm.KeysInfo[], newKeyAvailable: boolean) => {
        console.log('keysChange' + 'keyId:' + keyInfo.keyId + ' data:' + keyInfo.value);
    });
}
```

### off('keysChange')

off(type: 'keysChange', callback?: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void

注销监听密钥变化事件，注销密钥变化事件回调函数。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'keysChange'，MediaKeySystem实例创建成功可监听。 |
| callback | Callback\<[EventInfo](#eventinfo)\> | 否   | 回调函数，可选                |

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterkeyChange(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.off('keysChange');
}
```

### destroy

destroy(): void

销毁MediaKeySession运行时申请的资源。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**错误码：**

以下错误码的详细介绍请参见[DRM错误码](errorcode-drm.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**示例：**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';
let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  mediaKeySession.destroy();
} catch (err) {
  let error = err as BusinessError;
  console.error(`mediaKeySession destroy ERROR: ${error}`);
}

```
