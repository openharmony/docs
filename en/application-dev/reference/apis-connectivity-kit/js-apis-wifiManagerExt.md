# @ohos.wifiManagerExt (WLAN Extension)
This **wifiext** module provides WLAN extension interfaces for non-universal products.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs described in this document are used only for non-universal products, such as routers.


## Modules to Import

```js
import { wifiManagerExt } from '@kit.ConnectivityKit';
```

## wifiManagerExt.enableHotspot<sup>9+</sup>

enableHotspot(): void;

Enables the WLAN hotspot.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2701000 | Operation failed. |

**Example**

```ts
  import { wifiManagerExt } from '@kit.ConnectivityKit';

  try {
      wifiManagerExt.enableHotspot();
  }catch(error){
      console.error("failed:" + JSON.stringify(error));
  }
```

## wifiManagerExt.disableHotspot<sup>9+</sup>

disableHotspot(): void;

Disables the WLAN hotspot.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2701000 | Operation failed. |

**Example**

```ts
  import { wifiManagerExt } from '@kit.ConnectivityKit';

  try {
      wifiManagerExt.disableHotspot();
  }catch(error){
      console.error("failed:" + JSON.stringify(error));
  }
```

## wifiManagerExt.getSupportedPowerMode<sup>9+</sup>

getSupportedPowerMode(): Promise&lt;Array&lt;PowerMode&gt;&gt;

Obtains the supported power modes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[PowerMode](#powermode9)&gt;&gt; | Promise used to return the power modes obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2701000 | Operation failed. |
## PowerMode<sup>9+</sup>

Enumerates the power modes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| SLEEPING | 0 | Sleeping|
| GENERAL | 1 | General|
| THROUGH_WALL | 2 | Through_wall|


## wifiManagerExt.getSupportedPowerMode<sup>9+</sup>

getSupportedPowerMode(callback: AsyncCallback&lt;Array&lt;PowerMode&gt;&gt;): void

Obtains the supported power modes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[PowerMode](#powermode9)&gt;&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the power modes obtained. If the operation fails, **err** is not **0**.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2701000 | Operation failed. |

**Example**

```ts
  import { wifiManagerExt } from '@kit.ConnectivityKit';

  wifiManagerExt.getSupportedPowerMode((err, data:wifiManagerExt.PowerMode) => {
      if (err) {
          console.error("get supported power mode info error");
          return;
      }
      console.info("get supported power mode info: " + JSON.stringify(data));
  });

  wifiManagerExt.getSupportedPowerMode().then(data => {
      console.info("get supported power mode info: " + JSON.stringify(data));
  }).catch((error:number) => {
      console.info("get supported power mode error");
  });
```

## wifiManagerExt.getPowerMode<sup>9+</sup>

getPowerMode(): Promise&lt;PowerMode&gt;

Obtains the power mode. This API uses a promise to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PowerMode](#powermode9)&gt; | Promise used to return the power modes obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2701000 | Operation failed. |

**Example**

```ts
  import { wifiManagerExt } from '@kit.ConnectivityKit';

  try {
      let model = wifiManagerExt.getPowerMode();
      console.info("model info:" + model);
  }catch(error){
      console.error("failed:" + JSON.stringify(error));
  }
```

## wifiManagerExt.getPowerMode<sup>9+</sup>

getPowerMode(callback: AsyncCallback&lt;PowerMode&gt;): void

Obtains the power mode. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PowerMode](#powermode9)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the power mode obtained. If the operation fails, **err** is not **0**.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2701000 | Operation failed. |

**Example**

```ts
  import { wifiManagerExt } from '@kit.ConnectivityKit';

  wifiManagerExt.getPowerMode((err, data:wifiManagerExt.PowerMode) => {
      if (err) {
          console.error("get linked info error");
          return;
      }
      console.info("get power mode info: " + JSON.stringify(data));
  });

  wifiManagerExt.getPowerMode().then(data => {
      console.info("get power mode info: " + JSON.stringify(data));
  }).catch((error:number) => {
      console.info("get power mode error");
  });
```

## wifiManagerExt.setPowerMode<sup>9+</sup>

setPowerMode(mode: PowerMode) : void;

 Sets the power mode.


**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT_EXT

**System capability**: SystemCapability.Communication.WiFi.AP.Extension

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mode | [PowerMode](#powermode9) | Yes| Power mode to set.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2701000 | Operation failed. |

**Example**

```ts
  import { wifiManagerExt } from '@kit.ConnectivityKit';

  try {
      let model = 0;
      wifiManagerExt.setPowerMode(model);
  }catch(error){
      console.error("failed:" + JSON.stringify(error));
  }
```
