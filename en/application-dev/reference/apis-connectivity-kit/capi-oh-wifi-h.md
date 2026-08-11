# oh_wifi.h

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @qq_43802146-->
<!--Designer: @qq_43802146-->
<!--Tester: @furryfurry123-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=8087b66eac59cdc7926e12a99168375d64ab4675 translatedAt=2026-08-03T02:10:11.472Z pushedAt=2026-08-03T03:03:48.288Z -->

## Overview

Defines APIs for obtaining Wi-Fi switch state.

**File to include**: <ConnectivityKit/wifi/oh_wifi.h>

**Library**: libwifi_ndk.so

**System capability**: SystemCapability.Communication.WiFi.STA

**Since**: 13

**Related module**: [Wifi](capi-wifi.md)

## Summary

### Macros

| Name| Description|
| -------- | -------- |
| WIFI_MAX_SSID_LEN 33 | Length of the **ssid** array of the [OH_WifiLinkedInfo](capi-oh-wifi-h.md#oh_wifilinkedinfo) member variables. The value is 32 plus the terminator (\0).<br>**Since**: 24|
| WIFI_MAC_LEN 18 | Lengths of the **macAddress** and **bssid** arrays of the [OH_WifiLinkedInfo](capi-oh-wifi-h.md#oh_wifilinkedinfo) member variables. The value is 17 plus the terminator (\0).<br>**Since**: 24|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Wifi_ResultCode](#wifi_resultcode) | Wifi_ResultCode | Enumerates the error codes returned by Wi-Fi APIs.|
| [OH_WifiConnState](#oh_wificonnstate) | OH_WifiConnState | Enumerates the Wi-Fi connection states.|
| [OH_WifiChannelWidth](#oh_wifichannelwidth) | OH_WifiChannelWidth | Enumerates the channel bandwidths of the connected hotspot.|
| [OH_WifiStandard](#oh_wifistandard) | OH_WifiStandard | Enumerates the Wi-Fi standards used by the connected hotspot.|
| [OH_WifiCategory](#oh_wificategory) | OH_WifiCategory | Enumerates the highest Wi-Fi categories supported by the hotspot.|
| [OH_WifiLinkType](#oh_wifilinktype) | OH_WifiLinkType | Enumerates the Wi-Fi 7 connection types.|

### Structs

| Name| Description|
| -- | -- |
| [OH_WifiLinkedInfo](#oh_wifilinkedinfo) | Provides the WLAN connection information. Information about the connected Wi-Fi hotspot of the current device can be obtained.|

### Functions

| Name| Description|
| -- | -- |
| [Wifi_ResultCode OH_Wifi_IsWifiEnabled(bool *enabled)](#oh_wifi_iswifienabled) | Checks whether Wi-Fi is enabled.|
| [Wifi_ResultCode OH_Wifi_GetDeviceMacAddress(char *macAddr, unsigned int *macAddrLen)](#oh_wifi_getdevicemacaddress) | Obtains the actual MAC address of a device.|
| [Wifi_ResultCode OH_Wifi_GetLinkedInfo(OH_WifiLinkedInfo *info)](#oh_wifi_getlinkedinfo) | Obtains Wi-Fi connection information.|

## Enum Description

### Wifi_ResultCode

```c
enum Wifi_ResultCode
```

**Description**

Enumerates the error codes returned by Wi-Fi APIs.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| WIFI_SUCCESS = 0 | Operation success.|
| WIFI_PERMISSION_DENIED = 201 | Permission verification fails.|
| WIFI_INVALID_PARAM = 401 | Invalid parameter.<br> Possible causes: 1. The input parameter is a null pointer. 2. The parameter value is out of the value range.|
| WIFI_NOT_SUPPORTED = 801 | Function not supported due to limited device capabilities.|
| WIFI_OPERATION_FAILED = 2501000 | Operation failed.<br> Possible cause: The internal execution of the service fails.|
| WIFI_STA_DISABLED = 2501001 | STA service not started.<br> Possible cause: Wi-Fi is disabled.<br>**Since**: 21|

### OH_WifiConnState

```c
enum OH_WifiConnState
```

**Description**

Enumerates the WLAN connection states.

**Since**: 24

| Enum Item| Description|
| -------- | -------- |
| OH_WIFI_CONN_SCANNING = 0 | The device is scanning for available hotspots.|
| OH_WIFI_CONN_CONNECTING = 1| A WLAN connection is being established.|
| OH_WIFI_CONN_AUTHENTICATING = 2 | An authentication is being performed for a WLAN connection.|
| OH_WIFI_CONN_OBTAINING_IPADDR = 3 | The IP address of the WLAN connection is being acquired.|
| OH_WIFI_CONN_CONNECTED = 4 | A WLAN connection is established.|
| OH_WIFI_CONN_DISCONNECTING = 5 | The WLAN connection is being disconnected.|
| OH_WIFI_CONN_DISCONNECTED = 6 | The WLAN connection is disconnected.|
| OH_WIFI_CONN_SPECIAL_CONNECT = 7 | The WLAN connection is in a special state.|
| OH_WIFI_CONN_UNKNOWN = 8 | Failed to establish the WLAN connection.|

### OH_WifiChannelWidth

```c
enum OH_WifiChannelWidth
```

**Description**

Enumerates the WLAN channel bandwidths.

**Since**: 24

| Enum Item| Description|
| -------- | -------- |
| OH_WIFI_WIDTH_20MHZ = 0 | Channel bandwidth of 20 MHz.|
| OH_WIFI_WIDTH_40MHZ = 1 | Channel bandwidth of 40 MHz.|
| OH_WIFI_WIDTH_80MHZ = 2 | Channel bandwidth of 80 MHz.|
| OH_WIFI_WIDTH_160MHZ = 3 | Channel bandwidth of 160 MHz.|
| OH_WIFI_WIDTH_80MHZ_PLUS = 4 | Bandwidth of 80 MHz for two channels.|
| OH_WIFI_WIDTH_INVALID = 5 | Invalid channel bandwidth.|

### OH_WifiStandard

```c
enum OH_WifiStandard
```

**Description**

Enumerates the Wi-Fi standards.

**Since**: 24

| Enum Item| Description|
| -------- | -------- |
| OH_WIFI_STANDARD_UNDEFINED = 0 | Invalid Wi-Fi standard.|
| OH_WIFI_STANDARD_11A = 1 | 802.11a.|
| OH_WIFI_STANDARD_11B = 2 | 802.11b.|
| OH_WIFI_STANDARD_11G = 3 | 802.11g.|
| OH_WIFI_STANDARD_11N = 4 | 802.11n.|
| OH_WIFI_STANDARD_11AC = 5 | 802.11ac.|
| OH_WIFI_STANDARD_11AX = 6 | 802.11ax.|
| OH_WIFI_STANDARD_11AD = 7 | 802.11ad.|

### OH_WifiCategory

```c
enum OH_WifiCategory
```

**Description**

Enumerates the Wi-Fi categories.

**Since**: 24

|Enum Item| Description|
| -------- | -------- |
| OH_WIFI_CATEGORY_DEFAULT = 1 | Default category.|
| OH_WIFI_CATEGORY_WIFI6 = 2 | WI-FI 6.|
| OH_WIFI_CATEGORY_WIFI6_PLUS = 3 | WI-FI 6+.|
| OH_WIFI_CATEGORY_WIFI7 = 4 | WI-FI 7.|
| OH_WIFI_CATEGORY_WIFI7_PLUS = 5 | WI-FI 7+.|

### OH_WifiLinkType

```c
enum OH_WifiLinkType
```

**Description**

Enumerates the Wi-Fi 7 connection types.

**Since**: 24

| Enum Item| Description|
| -------- | -------- |
| OH_WIFI_LINK_DISCONNECT = -1 | Not connected.|
| OH_WIFI_LINK_DEFAULT_LINK = 0 | Default connection.|
| OH_WIFI_LINK_WIFI7_SINGLE_LINK = 1 | Wi-Fi 7 single-link connection.|
| OH_WIFI_LINK_WIFI7_MLSR = 2 | Wi-Fi 7 multi-link single radio (MLSR) connection.|
| OH_WIFI_LINK_WIFI7_EMLSR = 3 | Wi-Fi 7 enhanced multi-link single radio (EMLSR) connection.|
| OH_WIFI_LINK_WIFI7_STR = 4 | Wi-Fi 7 simultaneous transmit and receive (STR) connection.|
| OH_WIFI_LINK_WIFI7_LEGACY = 5 | Wi-Fi 7 traditional mode.|

## Struct Description

### OH_WifiLinkedInfo

```c
struct OH_WifiLinkedInfo
```

**Description**

Provides the WLAN connection information. Information about the connected Wi-Fi hotspot of the current device can be obtained.

**Since**: 24

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| ssid | char[] | No| No| Service set identifier (SSID) of the hotspot, which is used to obtain the public name (name of the wireless network) of the Wi-Fi hotspot connected to the current device. The encoding format is UTF-8.<br>The length is defined by **WIFI_MAX_SSID_LEN** whose value is **18**.|
| bssid | char[] | No| No| Basic service set identifier (BSSID) of the hotspot, which is the MAC address of the wireless network. If the application has the ohos.permission.GET_WIFI_PEERS_MAC permission, **bssid** in the return value is a real BSSID; otherwise, **bssid** is a random device address.<br>The format is AA:BB:CC:DD:EE:FF.<br>The maximum length is defined by **WIFI_MAC_LEN** whose value is **33**.|
| rssi | int32_t | No| No| Received signal strength indicator (RSSI) of the hotspot, in dBm.|
| band | int32_t | No| No| Frequency band of the WLAN access point (AP). The value **1** indicates 2.4 GHz, and the value **2** indicates 5 GHz.|
| linkSpeed | int32_t | No| No| Uplink speed of the WLAN AP, in Mbit/s.|
| rxLinkSpeed | int32_t | No| No| Downlink speed of the WLAN AP, in Mbit/s.|
| maxSupportedTxLinkSpeed | int32_t | No| No| Maximum uplink speed supported, in Mbit/s.|
| maxSupportedRxLinkSpeed | int32_t | No| No| Maximum downlink speed supported, in Mbit/s.|
| frequency | int32_t | No| No| Frequency of the WLAN AP, in MHz.|
| isHidden | bool | No| No| Whether the WLAN AP is hidden. The value **true** indicates that the WLAN AP is hidden; the value **false** indicates the opposite.|
| isRestricted | bool | No| No| Whether data volume is restricted at the WLAN AP. The value **true** indicates that data volume is restricted, and the value **false** indicates the opposite.|
| macType | int32_t | No| No| MAC address type. The value **0** indicates a random MAC address, and the value **1** indicates a device MAC address.|
| macAddress | char[] | No| No| MAC address of the device. If **macType** is set to **1**, you also need to obtain the ohos.permission.GET_WIFI_LOCAL_MAC permission.<br>The format is AA:BB:CC:DD:EE:FF.<br>The length is defined by **WIFI_MAC_LEN** whose value is 18.|
| ipAddress | uint32_t | No| No| IP address of the device that sets up the WLAN connection.|
| connState | [OH_WifiConnState](capi-oh-wifi-h.md#oh_wificonnstate) | No| No| WLAN connection state. For details, see **OH_WifiConnState**.|
| channelWidth | [OH_WifiChannelWidth](capi-oh-wifi-h.md#oh_wifichannelwidth) | No| No| Channel bandwidth of the connected hotspot. For details, see **OH_WifiChannelWidth**.|
| wifiStandard | [OH_WifiStandard](capi-oh-wifi-h.md#oh_wifistandard) | No| No| Wi-Fi standard used by the connected hotspot. For details, see **OH_WifiStandard**.|
| supportedWifiCategory | [OH_WifiCategory](capi-oh-wifi-h.md#oh_wificategory) | No| No| Highest Wi-Fi category supported by the hotspot. For details, see **OH_WifiCategory**.|
| isHiLinkNetwork | bool | No| No| Whether HiLink is supported by the hotspot. The value **true** indicates that HiLink is supported, and the value **false** indicates the opposite.|
| wifiLinkType | [OH_WifiLinkType](capi-oh-wifi-h.md#oh_wifilinktype) | No| No| Wi-Fi 7 connection type. For details, see **OH_WifiLinkType**.|

## Function Description

### OH_Wifi_IsWifiEnabled()

```c
Wifi_ResultCode OH_Wifi_IsWifiEnabled(bool *enabled)
```

**Description**

Checks whether Wi-Fi is enabled.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| bool *enabled | Pointer to the boolean value indicating the Wi-Fi state.<br> The value **true** indicates that Wi-Fi is enabled, and the value **false** indicates the opposite.<br> A null pointer is prohibited. If a null pointer is passed in, an error is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode) | Operation result, which is specified by [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode). The value can be:<br>     [WIFI_SUCCESS](capi-oh-wifi-h.md#wifi_resultcode): The Wi-Fi switch status is obtained successfully.<br>     [WIFI_INVALID_PARAM](capi-oh-wifi-h.md#wifi_resultcode): The input parameter is a null pointer.<br>     [WIFI_OPERATION_FAILED](capi-oh-wifi-h.md#wifi_resultcode): An internal error occurs during service execution.|

### OH_Wifi_GetDeviceMacAddress()

```c
Wifi_ResultCode OH_Wifi_GetDeviceMacAddress(char *macAddr, unsigned int *macAddrLen)
```

**Description**

Obtains the actual MAC address of a device.

**Required permissions**: ohos.permission.GET_WIFI_LOCAL_MAC and ohos.permission.GET_WIFI_INFO

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| char *macAddr | Character array of the device MAC address, which ends with **\0**.|
| unsigned int *macAddrLen | Memory size allocated to **macAddr**.|

**Returns**

| Type| Description|
| -- | -- |
| [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode) | Operation result, which is specified by [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode). The value can be:<br>     [WIFI_SUCCESS](capi-oh-wifi-h.md#wifi_resultcode): The MAC address of the device is obtained successfully.<br>     [WIFI_PERMISSION_DENIED](capi-oh-wifi-h.md#wifi_resultcode): The permission is denied.<br>     [WIFI_NOT_SUPPORTED](capi-oh-wifi-h.md#wifi_resultcode): This capability is not supported.<br>     [WIFI_INVALID_PARAM](capi-oh-wifi-h.md#wifi_resultcode): The input **macAddr** is a null pointer.<br>     [WIFI_OPERATION_FAILED](capi-oh-wifi-h.md#wifi_resultcode): An internal error occurs during internal execution.<br>     [WIFI_STA_DISABLED](capi-oh-wifi-h.md#wifi_resultcode): The Wi-Fi STA mode is disabled.|

### OH_Wifi_GetLinkedInfo()

```c
Wifi_ResultCode OH_Wifi_GetLinkedInfo(OH_WifiLinkedInfo *info)
```

**Description**

Obtains Wi-Fi connection information.

> **NOTE**
> - If **macType** is set to **1** (device MAC address), you also need to apply for the ohos.permission.GET_WIFI_LOCAL_MAC permission to obtain the value of **macAddress**. (For API version 8 to 15, this permission is available only to system applications. For API version 16 and later, this permission is available to common applications on PCs/2-in-1 devices, and is available only to system applications on other devices.) If the ohos.permission.GET_WIFI_LOCAL_MAC permission is not granted, no value is returned for **macAddress**.
> - If the application has the ohos.permission.GET_WIFI_PEERS_MAC permission, **bssid** in the return value is a real BSSID; otherwise, **bssid** is a random device address.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| OH_WifiLinkedInfo *info | **OH_WifiLinkedInfo** struct.|

**Returns**

| Type| Description|
| -- | -- |
| [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode) | Operation result, which is specified by [Wifi_ResultCode](capi-oh-wifi-h.md#wifi_resultcode). The value can be:<br>     [WIFI_SUCCESS](capi-oh-wifi-h.md#wifi_resultcode): The Wi-Fi connection information is obtained successfully.<br>     [WIFI_PERMISSION_DENIED](capi-oh-wifi-h.md#wifi_resultcode): The permission is denied.<br>     [WIFI_NOT_SUPPORTED](capi-oh-wifi-h.md#wifi_resultcode): The connection information cannot be obtained.<br>     [WIFI_INVALID_PARAM](capi-oh-wifi-h.md#wifi_resultcode): The input **info** is a null pointer.<br>     [WIFI_OPERATION_FAILED](capi-oh-wifi-h.md#wifi_resultcode): An internal error occurs during internal execution.|