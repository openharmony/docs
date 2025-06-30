# native_drm_common.h

## 概述

定义DRM数据类型。

**引用文件：** <multimedia/drm_framework/native_drm_common.h>

**库：** libnative_drm.z.so

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [DRM_MediaKeyRequestInfo](capi-drm-drm-mediakeyrequestinfo.md) | DRM_MediaKeyRequestInfo | 媒体密钥请求信息。 |
| [DRM_MediaKeyRequest](capi-drm-drm-mediakeyrequest.md) | DRM_MediaKeyRequest | 媒体密钥请求。 |
| [DRM_Statistics](capi-drm-drm-statistics.md) | DRM_Statistics | MediaKeySystem的度量信息。 |
| [DRM_OfflineMediakeyIdArray](capi-drm-drm-offlinemediakeyidarray.md) | DRM_OfflineMediakeyIdArray | 离线媒体密钥ID数组。 |
| [DRM_KeysInfo](capi-drm-drm-keysinfo.md) | DRM_KeysInfo | 媒体密钥信息。 |
| [DRM_MediaKeyStatus](capi-drm-drm-mediakeystatus.md) | DRM_MediaKeyStatus | Media key status like pocily etc. |
| [DRM_PsshInfo](capi-drm-drm-psshinfo.md) | DRM_PsshInfo | uuid的PSSH信息。 |
| [DRM_MediaKeySystemInfo](capi-drm-drm-mediakeysysteminfo.md) | DRM_MediaKeySystemInfo | 用于播放器从媒体源获取媒体密钥系统信息。 |
| [DRM_MediaKeySystemDescription](capi-drm-drm-mediakeysystemdescription.md) | DRM_MediaKeySystemDescription | DRM插件的名称和UUID。 |
| [MediaKeySystem](capi-drm-mediakeysystem.md) | MediaKeySystem | 媒体密钥系统结构。 |
| [MediaKeySession](capi-drm-mediakeysession.md) | MediaKeySession | 媒体密钥会话结构。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [DRM_EventType](#drm_eventtype) | DRM_EventType | 监听事件类型。 |
| [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) | DRM_ContentProtectionLevel | 内容保护级别类型。 |
| [DRM_MediaKeyType](#drm_mediakeytype) | DRM_MediaKeyType | 许可证类型。 |
| [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) | DRM_MediaKeyRequestType | 许可证请求类型。 |
| [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) | DRM_OfflineMediaKeyStatus | 离线许可证状态。 |
| [DRM_CertificateStatus](#drm_certificatestatus) | DRM_CertificateStatus | 设备证书状态类型。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo *mediaKeySystemInfo)](#drm_mediakeysysteminfocallback) | DRM_MediaKeySystemInfoCallback | 应用为从媒体源获取DRM信息而设置的回调。 |

## 枚举类型说明

### DRM_EventType

```
enum DRM_EventType
```

**描述**

监听事件类型。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| EVENT_DRM_BASE = 200 | DRM基础事件。 |
| EVENT_PROVISION_REQUIRED = 201 | 设备证书请求事件。 |
| EVENT_KEY_REQUIRED = 202 | 密钥请求事件。 |
| EVENT_KEY_EXPIRED = 203 | 密钥过期事件。 |
| EVENT_VENDOR_DEFINED = 204 | 第三方定义事件。 |
| EVENT_EXPIRATION_UPDATE = 206 | 密钥过期更新事件。 |

### DRM_ContentProtectionLevel

```
enum DRM_ContentProtectionLevel
```

**描述**

内容保护级别类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| CONTENT_PROTECTION_LEVEL_UNKNOWN = 0 | 未知级别。 |
| CONTENT_PROTECTION_LEVEL_SW_CRYPTO | 软件安全级别。 |
| CONTENT_PROTECTION_LEVEL_HW_CRYPTO | 硬件安全级别。 |
| CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO | 硬件增强级别。 |
| CONTENT_PROTECTION_LEVEL_MAX | 最大安全级别。 |

### DRM_MediaKeyType

```
enum DRM_MediaKeyType
```

**描述**

许可证类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_KEY_TYPE_OFFLINE = 0 | 离线。 |
| MEDIA_KEY_TYPE_ONLINE | 在线。 |

### DRM_MediaKeyRequestType

```
enum DRM_MediaKeyRequestType
```

**描述**

许可证请求类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0 | 未知请求类型。 |
| MEDIA_KEY_REQUEST_TYPE_INITIAL | 初始化请求。 |
| MEDIA_KEY_REQUEST_TYPE_RENEWAL | 续订请求。 |
| MEDIA_KEY_REQUEST_TYPE_RELEASE | 释放请求。 |
| MEDIA_KEY_REQUEST_TYPE_NONE | 无请求。 |
| MEDIA_KEY_REQUEST_TYPE_UPDATE | 更新请求。 |

### DRM_OfflineMediaKeyStatus

```
enum DRM_OfflineMediaKeyStatus
```

**描述**

离线许可证状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0 | 未知状态。 |
| OFFLINE_MEDIA_KEY_STATUS_USABLE | 可用状态。 |
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE | 失活状态。 |

### DRM_CertificateStatus

```
enum DRM_CertificateStatus
```

**描述**

设备证书状态类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| CERT_STATUS_PROVISIONED = 0 | 设备已安装设备证书。 |
| CERT_STATUS_NOT_PROVISIONED | 设备未安装设备证书。 |
| CERT_STATUS_EXPIRED | 设备证书过期。 |
| CERT_STATUS_INVALID | 无效设备证书。 |
| CERT_STATUS_UNAVAILABLE | 设备证书不可用。 |


## 函数说明

### DRM_MediaKeySystemInfoCallback()

```
typedef void (*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**描述**

应用为从媒体源获取DRM信息而设置的回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [DRM_MediaKeySystemInfo](capi-drm-drm-mediakeysysteminfo.md) *mediaKeySystemInfo | 从媒体源获取的DRM信息。 |


