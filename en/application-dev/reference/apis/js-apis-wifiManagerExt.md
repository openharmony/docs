# @ohos.wifiManagerExt (WLAN Extension)

This **wifiext** module provides WLAN extension interfaces for non-universal products.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs described in this document are used only for non-universal products, such as routers.


## Modules to Import

```js
import wifiManagerExt from '@ohos.wifiManagerExt';
```

## wifiext.enableHotspot<sup>9+</sup>

enableHotspot(): void;

Enables the WLAN hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
| -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.disableHotspot<sup>9+</sup>

disableHotspot(): void;

Disables the WLAN hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
| -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getSupportedPowerMode<sup>9+</sup>

getSupportedPowerMode(): Promise&lt;Array&lt;PowerMode&gt;&gt;

Obtains the supported power modes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[PowerMode](#powermode)&gt;&gt; | Promise used to return the power modes obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
| -------- | -------- |
| 2701000  | Operation failed.|

## PowerMode

Enumerates the power modes.

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

| Name| Value| Description|
| -------- | -------- | -------- |
| SLEEPING | 0 | Sleeping|
| GENERAL | 1 | General|
| THROUGH_WALL | 2 | Through_wall|


## wifiext.getSupportedPowerMode<sup>9+</sup>

getSupportedPowerMode(callback: AsyncCallback&lt;Array&lt;PowerMode&gt;&gt;): void

Obtains the supported power modes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[PowerMode](#powermode)&gt;&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the power modes obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
| -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getPowerMode<sup>9+</sup>

getPowerMode(): Promise&lt;PowerMode&gt;

Obtains the power mode. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PowerMode](#powermode)&gt; | Promise used to return the power modes obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
| -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getPowerMode<sup>9+</sup>

getPowerMode(callback: AsyncCallback&lt;PowerMode&gt;): void

Obtains the power mode. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PowerMode](#powermode)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the power mode obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
| -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.setPowerMode<sup>9+</sup>

setPowerMode(model: PowerMode) : boolean;

 Sets the power mode.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| model | [PowerMode](#powermode) | Yes| Power mode to set.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
| -------- | -------- |
| 2701000  | Operation failed.|
