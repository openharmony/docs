# Interfaces (Others)

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ProvisionRequest

Describes a provision request, which is used to request a DRM certificate from a provisioning server.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| data   | Uint8Array | Yes | Data carried in the provision request.     |
| defaultURL     | string                 | Yes | URL of the provisioning server (which provisions DRM certificates).      |

## OptionsData

Describes the optional data carried in a media key request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the optional data.     |
| value     | string                 | Yes | Value of the optional data.      |

## MediaKeyRequest

Describes a media key request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| mediaKeyRequestType   | [MediaKeyRequestType](arkts-apis-drm-e.md#mediakeyrequesttype) | Yes | Type of the media key request.     |
| data     | Uint8Array                 | Yes | Data carried in the media key request.      |
| defaultURL     | string                 | Yes | URL of the license server (which provisions media keys).      |

## EventInfo

Describes the event information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| info   | Uint8Array | Yes | Event information.     |
| extraInfo     | string                 | Yes | Extended event information.      |

## StatisticKeyValue

Describes the statistical information.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the statistical item.     |
| value     | string                 | Yes | Value of the statistical item.      |

## MediaKeyStatus

Describes the media key status.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the media key status (such as the media key expiration time and content protection level).     |
| value     | string                 | Yes | Value of the media key status.      |

## KeysInfo

Describes the information about media keys.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| keyId   | Uint8Array | Yes | Media key ID.     |
| value     | string                 | Yes | Media key status.      |

## MediaKeySystemInfo

Describes the DRM information, which is used to encrypt content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| uuid   | string | Yes | UUID of the DRM content protection system.     |
| pssh     | Uint8Array                 | Yes | Protection System Specific Header (PSSH) in the DRM information.      |

## MediaKeySystemDescription<sup>12+</sup>

Describes the plugin information.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the plugin.     |
| uuid   | string | Yes | UUID of the plugin.     |
