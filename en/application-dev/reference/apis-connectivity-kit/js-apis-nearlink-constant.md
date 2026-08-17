# @ohos.nearlink.constant (NearLink Common Constants)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=6610f64dcfdc39e7239dc52b313502bf3f4a9b0b translatedAt=2026-08-12T11:28:06.147Z pushedAt=2026-08-13T11:30:21.872Z -->

This module provides definitions of common constants.

**Since**: 26.0.0

## Modules to Import

```typescript
import { nearlinkConstant } from '@kit.ConnectivityKit';
```

## PairingState

Enumerates the pairing states with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| PAIRING_STATE_NONE | 1 | Not paired. |
| PAIRING_STATE_PAIRING | 2 | Pairing. |
| PAIRING_STATE_PAIRED | 3 | Paired. |

## ConnectionState

Enumerates the connection states with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| STATE_CONNECTING | 0 | Connecting. |
| STATE_CONNECTED | 1 | Connected. |
| STATE_DISCONNECTING | 2 | Disconnecting. |
| STATE_DISCONNECTED | 3 | Disconnected. |

## DeviceClass

Enumerates the device types.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| DEVICE_INVALID_CLASS | -1 | Invalid device type. The device type information is missing. |
| DEVICE_UNCATEGORIZED | 0x000100 | Uncategorized device. |
| DEVICE_PHONE | 0x000200 | Phone. |
| DEVICE_SMARTPHONE | 0x000201 | Smartphone. |
| DEVICE_COMPUTER | 0x000300 | Computer. |
| DEVICE_LAPTOP | 0x000301 | Laptop. |
| DEVICE_TABLET | 0x000302 | Tablet. |
| DEVICE_ALL_IN_ONE_COMPUTER | 0x000303 | 2-in-1 device. |
| DEVICE_MINI_PC | 0x000304 | Mini PC. |
| DEVICE_WATCH | 0x000400 | Watch. |
| DEVICE_SMART_WATCH | 0x000401 | Smartwatch. |
| DEVICE_HUMAN_INTERFACE | 0x000500 | Human-machine interface. |
| DEVICE_KEYBOARD | 0x000501 | Keyboard. |
| DEVICE_MOUSE | 0x000502 | Mouse. |
| DEVICE_HANDLE | 0x000503 | Handle. |
| DEVICE_STYLUS | 0x000504 | Stylus. |
| DEVICE_TOUCHPAD | 0x000505 | Touchpad. |
| DEVICE_AUDIO_PLAYBACK | 0x000600 | Audio player. |
| DEVICE_SMART_SPEAKER | 0x000601 | Smart speaker. |
| DEVICE_ECHO_WALL | 0x000602 | Echo device. |
| DEVICE_AUDIO_CAPTURE | 0x000700 | Audio recorder. |
| DEVICE_KARAOKE_MICROPHONE | 0x000701 | Karaoke microphone. |
| DEVICE_LAPEL_MICROPHONE | 0x000702 | Wearable microphone. |
| DEVICE_WEARABLE_AUDIO | 0x000800 | Wearable audio device. |
| DEVICE_IN_EAR_EARPHONE | 0x000801 | In-ear headphones. |
| DEVICE_HEADSET | 0x000802 | Headset. |
| DEVICE_OVER_EAR_HEADPHONE | 0x000803 | Over-ear headphones. |
| DEVICE_NECKBAND_EARPHONE | 0x000804 | Neckband earphones. |
| DEVICE_PERSONAL_CARE | 0x000900 | Personal care. |
| DEVICE_INTELLIGENT_TOOTHBRUSH | 0x000901 | Smart toothbrush. |
| DEVICE_SMART_CUP | 0x000902 | Smart cup. |
| DEVICE_INTELLIGENT_SHAVER | 0x000903 | Smart shaver. |
| DEVICE_HVAC | 0x000A00 | HVAC (heating, ventilation, and air conditioning). |
| DEVICE_AIR_PURIFIER | 0x000A01 | Air purifier. |
| DEVICE_HUMIDIFIER | 0x000A02 | Humidifier. |
| DEVICE_AIR_CIRCULATION_FAN | 0x000A03 | Air circulation fan. |
| DEVICE_ELECTRIC_RIDE | 0x000B00 | Electric cycling tool. |
| DEVICE_ELECTRIC_SCOOTER | 0x000B01 | Electric scooter. |
| DEVICE_ELECTRIC_BICYCLE | 0x000B02 | Electric bicycle. |
| DEVICE_LIGHT_FITTING | 0x000C00 | Light fittings. |
| DEVICE_SMART_TABLE_LAMP | 0x000C01 | Smart table lamp. |
| DEVICE_REMOTE_CONTROL | 0x000D00 | Remote control device. |
| DEVICE_TV_REMOTE_CONTROL | 0x000D01 | TV remote control. |
| DEVICE_IMAGING | 0x000E00 | Imaging device. |
| DEVICE_SMART_TV | 0x000E01 | Smart TV. |
| DEVICE_IP_CAMERA | 0x000E02 | IP camera. |
| DEVICE_SCREEN_CASTER | 0x000E03 | Projector. |
| DEVICE_NETWORKING | 0x000F00 | Network device. |
| DEVICE_IOT_GATEWAY | 0x000F01 | IoT gateway. |
| DEVICE_ACCESS_CONTROL | 0x001000 | Access control device. |
| DEVICE_INTELLIGENT_LOCK | 0x001001 | Smart lock. |
| DEVICE_SMART_KEY | 0x001002 | Smart key. |
| DEVICE_VEHICLE_KEY | 0x001003 | Vehicle key. |
| DEVICE_VEHICLE_LOCK | 0x001004 | Vehicle lock. |

## AcbState

Enumerates the logical link connection states with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| DISCONNECTED | 0 | Disconnected. |
| CONNECTED | 1 | Connected. |
| ENCRYPTED | 2 | Connected, with link encrypted. |