# Interfaces (Others)

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1a12579b2a51516a60175d571afbafa0d14afbf6 translatedAt=2026-07-31T02:11:10.455Z pushedAt=2026-07-31T03:50:46.750Z -->

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ProvisionRequest

Defines a device certificate provisioning request.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                       | Read-Only| Optional| Description        |
| -------- | ------------------------|----|----| ------------- |
| data   | Uint8Array| No | No | Binary data of the provisioning request.     |
| defaultURL     | string         | No | No | URL of the device certificate provisioning server.      |

## OptionsData

Defines optional parameters for a device certificate request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                       | Read-Only| Optional| Description        |
| -------- | --------------------------|----|----| ------------- |
| name   | string | No | No | Name of the optional parameter.     |
| value     | string             | No | No | Value of the optional parameter.|

## MediaKeyRequest

Defines a media key request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                      | Read-Only| Optional| Description        |
| -------- | --------------------------|----|----| ------------- |
| mediaKeyRequestType   | [MediaKeyRequestType](arkts-apis-drm-e.md#mediakeyrequesttype)| No | No | Type of the media key request.     |
| data     | Uint8Array               |  No | No | Data of the media key request.      |
| defaultURL     | string              |  No | No | URL of the media key service.      |

## EventInfo

Defines the DRM event information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                        | Read-Only| Optional   | Description        |
| -------- | --------------------------|----|-------| ------------- |
| info   | Uint8Array |   No| No     | Event payload data.     |
| extraInfo     | string             |   No| No | Additional event context.|

## StatisticKeyValue

Defines a key-value pair for metrics.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                      | Read-Only| Optional  | Description        |
| -------- | -------------------------|----|------| ------------- |
| name   | string | No | No    | Name of the metric.     |
| value     | string              | No  | No  | Value of the metric.|

## MediaKeyStatus

Defines a status attribute for a media key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                       | Read-Only| Optional     | Description        |
| -------- | -------------------------|----|---------| ------------- |
| name   | string | No  |  No       | Media key status name. Common names include media key expiration time and content protection security level. The specific available names are determined by the DRM solution.      |
| value     | string            | No  | No | Value of the media key status attribute.|

## KeysInfo

Defines the key information of a media key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                      | Read-Only| Optional| Description        |
| -------- | -------------------------|----|---| ------------- |
| keyId   | Uint8Array | No | No| Media key ID.     |
| value     | string                 | No | No| Media key status.|

## MediaKeySystemInfo

Defines the DRM information for encrypted content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                     | Read-Only| Optional| Description        |
| -------- | ------------------------|----|--| ------------- |
| uuid   | string |  No | No| UUID of the DRM system.     |
| pssh     | Uint8Array              |  No | No| Protection System Specific Header (PSSH) data.|

## MediaKeySystemDescription<sup>12+</sup>

Defines the DRM plugin information.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                       | Read-Only| Optional| Description        |
| -------- | --------------------------|----|--| ------------- |
| name   | string | No | No| Plugin name.     |
| uuid   | string | No | No| Unique identifier of the plugin.|