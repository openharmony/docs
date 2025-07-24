# ResourceManager_Configuration

## Overview

Enumerates device states.

**Since**: 12

**Related module**: [resourcemanager](capi-resourcemanager.md)

**Header file**: [resmgr_common.h](capi-resmgr-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| ResourceManager_Direction direction | Screen orientation.|
| char* locale | Locale, for example, zh-Hans-CN.|
| ResourceManager_DeviceType deviceType | Device type.|
| ScreenDensity screenDensity | Screen density.|
| ResourceManager_ColorMode colorMode | Color mode.|
| uint32_t mcc | Mobile country code (MCC).|
| uint32_t mnc | Mobile network code (MNC).|
| uint32_t reserved[20] | Reserved.|
