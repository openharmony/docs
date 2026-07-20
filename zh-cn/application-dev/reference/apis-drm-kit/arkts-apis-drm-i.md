# Interfaces (其他)
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
## ProvisionRequest

设备证书请求。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                        | 只读 | 可选 | 说明         |
| -------- | ------------------------|----|----| ------------- |
| data   | Uint8Array| 否  | 否  | 设备证书请求数据，包含设备证书请求的原始字节数据。具体格式和大小由DRM解决方案决定。      |
| defaultURL     | string         | 否  | 否  | Provision服务（设备证书请求服务）URL。需符合URL格式规范，建议使用HTTPS协议。       |

## OptionsData

设备证书请求的可选数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                        | 只读 | 可选 | 说明         |
| -------- | --------------------------|----|----| ------------- |
| name   | string | 否  | 否  | 可选数据名，用于标识可选数据的键名。具体可用的名称由DRM解决方案决定。      |
| value     | string             | 否  | 否  | 可选数据值，与可选数据名对应的值。具体格式和取值范围由DRM解决方案决定。 |

## MediaKeyRequest

媒体密钥请求参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                       | 只读 | 可选 | 说明         |
| -------- | --------------------------|----|----| ------------- |
| mediaKeyRequestType   | [MediaKeyRequestType](arkts-apis-drm-e.md#mediakeyrequesttype)| 否  | 否  | 媒体密钥请求类型。用于指定请求密钥的场景，包括初始请求、续订请求、释放请求、更新请求等不同类型。      |
| data     | Uint8Array               |  否  | 否  | 媒体密钥请求数据，包含媒体密钥请求的原始字节数据。具体格式和大小由DRM解决方案决定。       |
| defaultURL     | string              |  否  | 否  | 媒体密钥服务URL。需符合URL格式规范，建议使用HTTPS协议。       |

## EventInfo

事件信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                         | 只读 | 可选    | 说明         |
| -------- | --------------------------|----|-------| ------------- |
| info   | Uint8Array |   否 | 否      | 事件信息数据，包含事件相关的原始字节数据。具体格式和内容取决于事件类型。      |
| extraInfo     | string             |   否 | 否  | 事件扩展信息，提供事件的附加描述或元数据。具体内容取决于事件类型。 |

## StatisticKeyValue

度量记录。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                       | 只读 | 可选   | 说明         |
| -------- | -------------------------|----|------| ------------- |
| name   | string | 否  | 否     | 度量记录名，用于标识度量指标的键名。具体可用的名称由DRM解决方案决定。      |
| value     | string              | 否   | 否   | 度量记录值，表示度量指标的数值或状态。具体格式和取值范围由DRM解决方案决定。 |

## MediaKeyStatus

媒体密钥状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                        | 只读 | 可选      | 说明         |
| -------- | -------------------------|----|---------| ------------- |
| name   | string | 否  |  否       | 媒体密钥状态类型名称。常见类型包括：媒体密钥过期时间、内容保护安全级别等。具体可选类型由DRM解决方案决定。      |
| value     | string            | 否   | 否  | 媒体密钥状态值，表示与状态名称对应的具体状态信息。具体取值由DRM解决方案决定。 |

## KeysInfo

媒体密钥中密钥信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                       | 只读 | 可选 | 说明         |
| -------- | -------------------------|----|---| ------------- |
| keyId   | Uint8Array | 否  | 否 | 媒体密钥标识，用于唯一标识媒体密钥的字节数组，通常为16字节（128位）。      |
| value     | string                 | 否  | 否 | 媒体密钥状态值。 |

## MediaKeySystemInfo

加密媒体内容的DRM信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                      | 只读 | 可选 | 说明         |
| -------- | ------------------------|----|--| ------------- |
| uuid   | string |  否  | 否 | DRM内容保护系统的唯一标识，必须为有效的UUID格式。传入无效UUID时，接口返回失败。      |
| pssh     | Uint8Array              |  否  | 否 | DRM内容保护系统专用头，包含DRM相关的元数据和初始化数据的字节数组。具体结构由DRM方案定义。 |

## MediaKeySystemDescription<sup>12+</sup>

插件信息。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                        | 只读 | 可选 | 说明         |
| -------- | --------------------------|----|--| ------------- |
| name   | string | 否  | 否 | 插件名称，用于标识DRM插件的名称字符串。通常由DRM方案提供商定义。      |
| uuid   | string | 否  | 否 | 插件唯一标识码，必须为有效的UUID格式。传入无效UUID时，接口返回失败。 |
