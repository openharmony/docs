# Enums
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## DrmErrorCode

枚举，错误码。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| ERROR_UNKNOWN       | 24700101    | 未知错误，当发生无法归类的异常时返回。建议检查输入参数是否合法、DRM服务是否正常运行，或联系技术支持获取详细错误信息。   |
| MAX_SYSTEM_NUM_REACHED   | 24700103    | MediaKeySystem实例数量超过上限（64个）。请调用[destroy](arkts-apis-drm-MediaKeySystem.md#destroy)方法释放不需要的MediaKeySystem实例后重试。    |
| MAX_SESSION_NUM_REACHED    | 24700104    | MediaKeySession实例数量超过上限（64个）。请调用[destroy](arkts-apis-drm-MediaKeySession.md#destroy)方法释放不需要的MediaKeySession实例后重试。     |
| SERVICE_FATAL_ERROR  | 24700201    | DRM服务异常，当DRM服务发生致命错误时返回。可能原因：系统资源不足、DRM服务进程崩溃或系统异常。建议重启应用或重启设备后重试，如问题持续存在请联系技术支持。     |

## PreDefinedConfigName

枚举，预定义的配置属性。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CONFIG_DEVICE_VENDOR        | 'vendor'    | 插件厂商名，通过[getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring)接口获取vendor对应配置值。   |
| CONFIG_DEVICE_VERSION    | 'version'    | 插件版本号，通过[getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring)接口获取version对应配置值。     |
| CONFIG_DEVICE_DESCRIPTION     | 'description'    | 设备描述，通过[getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring)接口获取description对应配置值。      |
| CONFIG_DEVICE_ALGORITHMS   | 'algorithms'    | 支持的算法，通过[getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring)接口获取algorithms对应配置值。     |
| CONFIG_DEVICE_UNIQUE_ID    | 'deviceUniqueId'    | 设备唯一标识，通过[getConfigurationByteArray](arkts-apis-drm-MediaKeySystem.md#getconfigurationbytearray)接口获取deviceUniqueId对应配置值。     |
| CONFIG_SESSION_MAX         | 'maxSessionNum'    | 设备支持的最大会话数，通过[getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring)接口获取maxSessionNum对应配置值。     |
| CONFIG_SESSION_CURRENT   | 'currentSessionNum'    | 当前会话数量，通过[getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring)接口获取currentSessionNum对应配置值。     |

## MediaKeyType

枚举，媒体密钥类型。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| MEDIA_KEY_TYPE_OFFLINE        | 0    | 离线媒体密钥，用于离线播放场景。   |
| MEDIA_KEY_TYPE_ONLINE   | 1    | 在线媒体密钥，用于在线播放场景。     |

## OfflineMediaKeyStatus

枚举，离线媒体密钥状态。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN        | 0    | 未知状态。   |
| OFFLINE_MEDIA_KEY_STATUS_USABLE   | 1    | 可用状态。     |
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE     | 2    | 失活状态，可能因密钥过期或被服务端禁用导致，需要重新获取密钥。       |

## CertificateStatus

枚举，设备证书状态。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CERT_STATUS_PROVISIONED        | 0    | 设备已安装设备证书。   |
| CERT_STATUS_NOT_PROVISIONED   | 1    | 设备未安装设备证书。     |
| CERT_STATUS_EXPIRED    | 2    | 设备证书过期。需要重新申请设备证书。       |
| CERT_STATUS_INVALID  | 3    | 设备证书无效。     |
| CERT_STATUS_UNAVAILABLE  | 4    | 设备证书不可用。     |

## MediaKeyRequestType

枚举，媒体密钥请求类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| MEDIA_KEY_REQUEST_TYPE_UNKNOWN        | 0    | 未知请求类型。   |
| MEDIA_KEY_REQUEST_TYPE_INITIAL    | 1    | 初始化请求，在首次获取媒体密钥时触发，用于建立许可证会话。     |
| MEDIA_KEY_REQUEST_TYPE_RENEWAL     | 2    | 续订请求，在许可证即将过期或需要延长有效期时触发。       |
| MEDIA_KEY_REQUEST_TYPE_RELEASE   | 3    | 释放请求，在主动释放离线密钥或关闭会话时触发，用于通知服务端释放资源。     |
| MEDIA_KEY_REQUEST_TYPE_NONE    | 4    | 无请求。     |
| MEDIA_KEY_REQUEST_TYPE_UPDATE    | 5    | 更新请求。     |

## ContentProtectionLevel

枚举，内容保护级别。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CONTENT_PROTECTION_LEVEL_UNKNOWN        | 0    | 未知内容保护级别。   |
| CONTENT_PROTECTION_LEVEL_SW_CRYPTO   | 1    | 软件内容保护级别，使用软件解密，适用于对安全性要求不高的播放场景。     |
| CONTENT_PROTECTION_LEVEL_HW_CRYPTO    | 2    | 硬件内容保护级别，使用硬件解密，安全性较高，适用于大多数商业内容播放场景。       |
| CONTENT_PROTECTION_LEVEL_ENHANCED_HW  | 3    | 硬件增强内容保护级别，使用硬件安全模块解密，安全性最高，适用于高价值内容播放场景。     |
| CONTENT_PROTECTION_LEVEL_MAX  | 4    | 最高内容保护级别。     |
