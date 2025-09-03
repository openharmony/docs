# Interfaces (其他)
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->
> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ProvisionRequest

设备证书请求。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                        | 只读 | 可选 | 说明         |
| -------- | ------------------------|----|----| ------------- |
| data   | Uint8Array| 否  | 否  | 设备证书请求数据。      |
| defaultURL     | string         | 否  | 否  | Provision服务（设备证书请求服务）URL。       |

## OptionsData

设备证书请求的可选数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                        | 只读 | 可选 | 说明         |
| -------- | --------------------------|----|----| ------------- |
| name   | string | 否  | 否  | 可选数据名。      |
| value     | string             | 否  | 否  | 可选数据值。 |

## MediaKeyRequest

媒体密钥请求参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                       | 只读 | 可选 | 说明         |
| -------- | --------------------------|----|----| ------------- |
| mediaKeyRequestType   | [MediaKeyRequestType](arkts-apis-drm-e.md#mediakeyrequesttype)| 否  | 否  | 媒体密钥请求类型。      |
| data     | Uint8Array               |  否  | 否  | 媒体密钥请求数据。       |
| defaultURL     | string              |  否  | 否  | 媒体密钥服务URL。       |

## EventInfo

事件信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                         | 只读 | 可选    | 说明         |
| -------- | --------------------------|----|-------| ------------- |
| info   | Uint8Array |   否 | 否      | 事件信息数据。      |
| extraInfo     | string             |   否 | 否  | 事件扩展信息。 |

## StatisticKeyValue

度量记录。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                       | 只读 | 可选   | 说明         |
| -------- | -------------------------|----|------| ------------- |
| name   | string | 否  | 否     | 度量记录名。      |
| value     | string              | 否   | 否   | 度量记录值。 |

## MediaKeyStatus

媒体密钥状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                        | 只读 | 可选      | 说明         |
| -------- | -------------------------|----|---------| ------------- |
| name   | string | 否  |  否       | 媒体密钥状态名称（如媒体密钥过期时间、内容保护安全级别等）。      |
| value     | string            | 否   | 否  | 媒体密钥状态值。 |

## KeysInfo

媒体密钥中密钥信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                       | 只读 | 可选 | 说明         |
| -------- | -------------------------|----|---| ------------- |
| keyId   | Uint8Array | 否  | 否 | 媒体密钥标识。      |
| value     | string                 | 否  | 否 | 媒体密钥状态值。 |

## MediaKeySystemInfo

加密媒体内容的DRM信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                      | 只读 | 可选 | 说明         |
| -------- | ------------------------|----|--| ------------- |
| uuid   | string |  否  | 否 | DRM内容保护系统的唯一标识。      |
| pssh     | Uint8Array              |  否  | 否 | DRM内容保护系统专用头（Protection System Specific Header）。 |

## MediaKeySystemDescription<sup>12+</sup>

插件信息。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Drm.Core

| 名称      | 类型                        | 只读 | 可选 | 说明         |
| -------- | --------------------------|----|--| ------------- |
| name   | string | 否  | 否 | 插件名称。      |
| uuid   | string | 否  | 否 | 插件唯一标识码。 |
