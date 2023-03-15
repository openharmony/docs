# @ohos.wifiManagerExt (WLAN Extension Interface)
This **wifiext** module provides WLAN extension interfaces for non-universal products.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
The APIs described in this document are used only for non-universal products, such as routers.


## Modules to Import

```js
import wifiManagerExt from '@ohos.wifiManagerExt';
```

## wifiext.enableHotspot

enableHotspot(): boolean;

Enables the WLAN hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.disableHotspot

disableHotspot(): boolean;

Disables the WLAN hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getSupportedPowerModel

getSupportedPowerModel(): Promise&lt;Array&lt;PowerModel&gt;&gt;

Obtains the supported power models. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;[PowerModel](#powermodel)&gt;&gt; | Promise used to return the power models obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
  | -------- | -------- |
| 2701000  | Operation failed.|

## PowerModel

Enumerates the power models.

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

| Name| Value| Description|
| -------- | -------- | -------- |
| SLEEPING | 0 | Sleeping|
| GENERAL | 1 | General|
| THROUGH_WALL | 2 | Through_wall|


## wifiext.getSupportedPowerModel

getSupportedPowerModel(callback: AsyncCallback&lt;Array&lt;PowerModel&gt;&gt;): void

Obtains the supported power models. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Array&lt;[PowerModel](#powermodel)&gt;&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the power models obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getPowerModel

getPowerModel(): Promise&lt;PowerModel&gt;

Obtains the power model. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[PowerModel](#powermodel)&gt; | Promise used to return the power models obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.getPowerModel

getPowerModel(callback: AsyncCallback&lt;PowerModel&gt;): void

Obtains the power model. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[PowerModel](#powermodel)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the power model obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
  | -------- | -------- |
| 2701000  | Operation failed.|

## wifiext.setPowerModel

setPowerModel(model: PowerModel) : boolean;

 Sets the power model.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | model | [PowerModel](#powermodel) | Yes| Power model to set.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **Type**| **Description**|
  | -------- | -------- |
| 2701000  | Operation failed.|
