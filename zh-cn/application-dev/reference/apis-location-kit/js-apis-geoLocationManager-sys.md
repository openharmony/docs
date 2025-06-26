# @ohos.geoLocationManager (位置服务)(系统接口)

位置服务提供GNSS定位、网络定位、地理编码、逆地理编码、国家码和地理围栏等基本功能。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.geoLocationManager (位置服务)](js-apis-geoLocationManager.md)。
> 本模块能力仅支持WGS-84坐标系。

## 申请权限

应用在使用系统能力前，需要检查是否已经获取用户授权访问设备位置信息。如未获得授权，可以向用户申请需要的位置权限，申请方式请参考下文。

系统提供的定位权限有：
- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

访问设备的位置信息，必须申请权限，并且获得用户授权。

API9之前的版本，申请ohos.permission.LOCATION即可。

API9及之后的版本，需要申请ohos.permission.APPROXIMATELY_LOCATION或者同时申请ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION；无法单独申请ohos.permission.LOCATION。

| 使用的API版本 | 申请位置权限 | 申请结果 | 位置的精确度 |
| -------- | -------- | -------- | -------- |
| 小于9 | ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |
| 大于等于9 | ohos.permission.LOCATION | 失败 | 无法获取位置。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION | 成功 | 获取到模糊位置，精确度为5公里。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |

如果应用在后台运行时也需要访问设备位置，需要申请LOCATION类型的长时任务，这样应用在切入后台之后，系统可以继续上报位置信息。长时任务申请可参考[长时任务](../../task-management/continuous-task.md)。

应用如需使用ohos.permission.LOCATION_IN_BACKGROUND权限，需要在设置界面由用户手动授予，具体授权方式可参考[ohos.permission.LOCATION_IN_BACKGROUND权限说明](../../security/AccessToken/permissions-for-all-user.md#ohospermissionlocation_in_background)。

开发者可以在应用配置文件中声明所需要的权限，具体可参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。


## 导入模块

```ts
import { geoLocationManager } from '@kit.LocationKit';
```

## GeoAddress

地理编码地址信息。

**系统能力**：SystemCapability.Location.Location.Geocoder

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| isFromMock | Boolean | 否 | 是 | true：地名信息来自于逆地理编码模拟功能。<br/>false：地名信息不是来自于逆地理编码模拟功能。<br/>**系统API**：此接口为系统接口。 |


## Location

位置信息。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| isFromMock | Boolean | 否 | 是 | true：位置信息来自于位置模拟功能。<br/>false：位置信息不是来自于位置模拟功能。<br/>**系统API**：此接口为系统接口。 |


## ReverseGeocodingMockInfo

逆地理编码模拟功能的配置信息，包含一个位置信息和一个地名信息。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| location |  [ReverseGeoCodeRequest](js-apis-geoLocationManager.md#reversegeocoderequest) | 否 | 否 | 表示经纬度信息。 **系统API**：此接口为系统接口。|
| geoAddress |  [GeoAddress](#geoaddress) | 否 | 否 |表示地名信息。 **系统API**：此接口为系统接口。|


## LocationMockConfig

位置模拟功能的配置参数，包含了模拟位置上报的时间间隔和模拟位置数组。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| timeInterval | number | 否 | 否 | 表示模拟位置上报的时间间隔，单位是秒。 **系统API**：此接口为系统接口。|
| locations | Array&lt;[Location](#location)&gt; | 否 | 否 | 表示模拟位置数组。 **系统API**：此接口为系统接口。|

## LocatingRequiredDataConfig<sup>10+</sup>

获取定位所需数据时的配置参数。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| type | [LocatingRequiredDataType](#locatingrequireddatatype10) | 否 | 否 | 表示请求获取数据的类型。 **系统API**：此接口为系统接口。|
| needStartScan |  boolean | 否 | 否 | true：需要发起扫描。<br/>false：不需要发起扫描。 **系统API**：此接口为系统接口。|
| scanInterval |  number | 否 | 是 | 表示扫描的时间间隔。单位是毫秒，默认值是10000毫秒，取值范围为大于0。 **系统API**：此接口为系统接口。|
| scanTimeout |  number | 否 | 是 | 表示单次扫描的超时时间。单位是毫秒，默认值是10000毫秒，取值范围为大于0小于600000。 **系统API**：此接口为系统接口。|


## ContinuousLocationRequest<sup>12+</sup>

持续定位的请求参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| sportsType<sup>18+</sup> | [SportsType](#sportstype18) | 否 | 是 | 表示运动类型。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。**系统API**：此接口为系统接口。|


## LocatingRequiredData<sup>10+</sup>

表示定位业务所需的数据，包含WiFi或蓝牙扫描结果，APP拿到这些数据之后可以用于网络定位等业务。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| wifiData | [WifiScanInfo](#wifiscaninfo10) | 否 | 是 | 表示WiFi扫描结果。 **系统API**：此接口为系统接口。|
| bluetoothData |  [BluetoothScanInfo](#bluetoothscaninfo10) | 否 | 是 | 表示蓝牙扫描结果。 **系统API**：此接口为系统接口。|


## WifiScanInfo<sup>10+</sup>

WiFi扫描信息，包含扫描到的WiFi热点的ssid、bssid和rssi等信息。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 否 | 否 | WiFi热点的SSID，编码格式为UTF-8。 **系统API**：此接口为系统接口。|
| bssid | string | 否 | 否 | WiFi热点的BSSID。 **系统API**：此接口为系统接口。|
| rssi | number | 否 | 否 | WiFi热点的信号强度(dBm)。 **系统API**：此接口为系统接口。|
| frequency | number | 否 | 否 | WiFi热点的频率。单位是赫兹。 **系统API**：此接口为系统接口。|
| timestamp | number | 否 | 否 | 时间戳。 **系统API**：此接口为系统接口。|


## BluetoothScanInfo<sup>10+</sup>

蓝牙扫描信息。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceName | string | 否 | 否 | 蓝牙设备名称。 **系统API**：此接口为系统接口。|
| macAddress | string | 否 | 否 | 蓝牙设备的MAC地址。 **系统API**：此接口为系统接口。|
| rssi | number | 否 | 否 | 蓝牙设备的信号强度(dBm)。 **系统API**：此接口为系统接口。|
| timestamp | number | 否 | 否 | 时间戳。 **系统API**：此接口为系统接口。|

## LocationPrivacyType

定位服务隐私协议类型。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| OTHERS | 0 | 其他场景。预留字段。 **系统API**：此接口为系统接口。|
| STARTUP | 1 | 开机向导场景下的隐私协议。在开机时弹出协议，提醒用户阅读并选择是否授权。 **系统API**：此接口为系统接口。|
| CORE_LOCATION | 2 | 开启网络定位时弹出的隐私协议。 **系统API**：此接口为系统接口。|

## LocatingRequiredDataType<sup>10+</sup>

定位业务所需数据的类型。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| WIFI  | 1 | 表示WiFi扫描信息。 **系统API**：此接口为系统接口。|
| BLUETOOTH | 2 | 表示蓝牙扫描信息。 **系统API**：此接口为系统接口。|


## LocationIconStatus<sup>12+</sup>

定位图标状态。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| LOCATING_NOT_STARTED  | 0 | 表示当前无定位业务，无需显示定位图标。 **系统API**：此接口为系统接口。|
| LOCATING_STARTED | 1 | 表示当前在进行普通定位业务，需要显示普通定位图标。 **系统API**：此接口为系统接口。|
| HD_LOCATING_STARTED | 2 | 表示当前正在进行高精度定位业务，需要显示高精度定位图标。 **系统API**：此接口为系统接口。|


## SportsType<sup>18+</sup>

运动类型。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| RUNNING   | 1 |  表示跑步。 |
| WALKING    | 2 | 表示步行。 |
| CYCLING     | 3 | 表示骑行。 |


## geoLocationManager.on('locatingRequiredDataChange')<sup>10+</sup>

on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void

订阅定位业务所需数据的变化，主要包含WiFi和蓝牙扫描信息；根据入参决定是否启动WiFi和蓝牙扫描。使用callback异步回调。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locatingRequiredDataChange”，表示订阅定位业务所需数据的变化。 |
  | config | [LocatingRequiredDataConfig](#locatingrequireddataconfig10) | 是 | 表示获取定位所需数据时的配置参数。 |
  | callback | Callback&lt;Array&lt;[LocatingRequiredData](#locatingrequireddata10)&gt;&gt; | 是 | 回调函数，返回定位业务所需数据。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locatingRequiredDataChange')} due to limited device capabilities.          |
|3301800 | Failed to start WiFi or Bluetooth scanning.                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let callback = (code:Array<geoLocationManager.LocatingRequiredData>):void => {
      console.info('locatingRequiredDataChange: ' + JSON.stringify(code));
  }
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.on('locatingRequiredDataChange', config, callback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.off('locatingRequiredDataChange')<sup>10+</sup>

off(type: 'locatingRequiredDataChange', callback?: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void

取消订阅定位业务所需数据的变化，并停止WiFi和蓝牙扫描。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locatingRequiredDataChange”，表示取消订阅定位业务所需数据的变化。 |
  | callback | Callback&lt;Array&lt;[LocatingRequiredData](#locatingrequireddata10)&gt;&gt; | 否 | 需要取消订阅的回调函数。该回调函数需要与on接口传入的回调函数保持一致。若无此参数，则取消当前类型的所有订阅。 |

**错误码**：

错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locatingRequiredDataChange')} due to limited device capabilities.          |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let callback = (code:Array<geoLocationManager.LocatingRequiredData>):void => {
      console.info('locatingRequiredDataChange: ' + JSON.stringify(code));
  }
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.on('locatingRequiredDataChange', config, callback);
      geoLocationManager.off('locatingRequiredDataChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.enableLocation

enableLocation(callback: AsyncCallback&lt;void&gt;): void

打开位置服务，使用callback异步回调。

**系统API**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS 和 ohos.permission.CONTROL_LOCATION_SWITCH

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，当打开位置服务成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                              |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.enableLocation((err) => {
          if (err) {
              console.error('enableLocation: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.enableLocation

enableLocation(): Promise&lt;void&gt;

打开位置服务，使用Promise异步回调。

**系统API**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS 和 ohos.permission.CONTROL_LOCATION_SWITCH

**系统能力**：SystemCapability.Location.Location.Core

**返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  try {
      geoLocationManager.enableLocation().then(() => {
          console.info('promise, enableLocation succeed');
      })
      .catch((error:BusinessError) => {
          console.error('promise, enableLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.disableLocation

disableLocation(): void

关闭位置服务。

**系统API**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS 和 ohos.permission.CONTROL_LOCATION_SWITCH

**系统能力**：SystemCapability.Location.Location.Core

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.disableLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.disableLocation();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.enableLocationMock

enableLocationMock(): void

使能位置模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**需要权限**: ohos.permission.MOCK_LOCATION

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableLocationMock} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.enableLocationMock();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.disableLocationMock

disableLocationMock(): void

去使能位置模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**需要权限**: ohos.permission.MOCK_LOCATION

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.disableLocationMock} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.disableLocationMock();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.setMockedLocations

setMockedLocations(config: LocationMockConfig): void

设置模拟的位置信息，后面会以该接口中携带的时间间隔上报模拟位置。

该接口需要在调用[geoLocationManager.enableLocationMock](#geolocationmanagerenablelocationmock)之后才能调用。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**需要权限**: ohos.permission.MOCK_LOCATION

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config |  [LocationMockConfig](#locationmockconfig) | 是 | 指示位置模拟的配置参数，包含模拟位置上报的时间间隔和模拟位置数组。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.setMockedLocations} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let locations:Array<geoLocationManager.Location> = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  let config:geoLocationManager.LocationMockConfig = {"timeInterval": 5, "locations": locations};
  try {
      geoLocationManager.enableLocationMock();
      geoLocationManager.setMockedLocations(config);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.enableReverseGeocodingMock

enableReverseGeocodingMock(): void

使能逆地理编码模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**需要权限**: ohos.permission.MOCK_LOCATION

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableReverseGeocodingMock} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.enableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.disableReverseGeocodingMock

disableReverseGeocodingMock(): void

去使能逆地理编码模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**需要权限**: ohos.permission.MOCK_LOCATION

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.disableReverseGeocodingMock} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.disableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.setReverseGeocodingMockInfo

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;): void

设置逆地理编码模拟功能的配置信息，包含了位置和地名的对应关系，后续进行逆地理编码查询时如果位置信息位于配置信息中，就返回对应的地名。

该接口需要在调用[geoLocationManager.enableReverseGeocodingMock](#geolocationmanagerenablereversegeocodingmock)之后才能调用。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**需要权限**: ohos.permission.MOCK_LOCATION

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | mockInfos | Array&lt;[ReverseGeocodingMockInfo](#reversegeocodingmockinfo)&gt; | 是 | 指示逆地理编码模拟功能的配置参数数组。逆地理编码模拟功能的配置参数包含了一个位置和一个地名。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.setReverseGeocodingMockInfo} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let mockInfos:Array<geoLocationManager.ReverseGeocodingMockInfo> = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "isFromMock": true}},
  ];
  try {
      geoLocationManager.enableReverseGeocodingMock();
      geoLocationManager.setReverseGeocodingMockInfo(mockInfos);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.isLocationPrivacyConfirmed

isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean

查询用户是否同意定位服务隐私申明，是否同意启用定位服务。只有系统应用才能调用。

**系统API**：此接口为系统接口。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type |  [LocationPrivacyType](#locationprivacytype)| 是 | 指定隐私申明场景，例如开机向导中的隐私申明、开启网络定位功能时弹出的隐私申明等。 |

**返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true：用户同意定位服务隐私申明。<br/>false：用户不同意定位服务隐私申明。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.isLocationPrivacyConfirmed} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let isConfirmed = geoLocationManager.isLocationPrivacyConfirmed(1);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.setLocationPrivacyConfirmStatus

setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void

设置用户勾选定位服务隐私申明的状态，记录用户是否同意启用定位服务。只有系统应用才能调用。

**系统API**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | [LocationPrivacyType](#locationprivacytype) | 是 | 指定隐私申明场景，例如开机向导中的隐私申明、开启网络定位功能时弹出的隐私申明等。 |
  | isConfirmed | boolean | 是 | true：用户同意定位服务隐私申明。<br/>false：用户不同意定位服务隐私申明。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.setLocationPrivacyConfirmStatus} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.setLocationPrivacyConfirmStatus(1, true);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.getLocatingRequiredData<sup>10+</sup>

getLocatingRequiredData(config: LocatingRequiredDataConfig): Promise&lt;Array&lt;LocatingRequiredData&gt;&gt;

单次获取定位业务所需数据，包含WiFi蓝牙扫描信息，使用Promise方式异步返回结果。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [LocatingRequiredDataConfig](#locatingrequireddataconfig10) | 是 | 表示获取定位所需数据时的配置参数。 |

**返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[LocatingRequiredData](#locatingrequireddata10)&gt;&gt; | 以Promise形式返回定位业务所需数据，包含WiFi蓝牙扫描信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getLocatingRequiredData} due to limited device capabilities.          |
|3301800  | Failed to start WiFi or Bluetooth scanning.                    |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let config:geoLocationManager.LocatingRequiredDataConfig = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.getLocatingRequiredData(config).then((result) => {
          console.info('getLocatingRequiredData return: ' + JSON.stringify(result));
      })  
      .catch((error:BusinessError) => {
          console.error('promise, getLocatingRequiredData: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.on('locationIconStatusChange')<sup>12+</sup>

on(type: 'locationIconStatusChange', callback: Callback&lt;LocationIconStatus&gt;): void

订阅定位图标状态变化。使用callback异步回调。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationIconStatusChange”，表示订阅定位图标状态变化。 |
  | callback | Callback&lt;[LocationIconStatus](#locationiconstatus12)&gt; | 是 | 回调函数，返回定位图标状态。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locationIconStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                        |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let callback = (code: geoLocationManager.LocationIconStatus):void => {
      console.info('LocationIconStatus: ' + JSON.stringify(code));
  }
  try {
      geoLocationManager.on('locationIconStatusChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.off('locationIconStatusChange')<sup>12+</sup>

off(type: 'locationIconStatusChange', callback?: Callback&lt;LocationIconStatus&gt;): void

取消订阅定位图标状态的变化。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationIconStatusChange”，表示取消订阅定位图标状态变化。 |
  | callback | Callback&lt;[LocationIconStatus](#locationiconstatus12)&gt;  | 否 | 需要取消订阅的回调函数。该回调函数需要与on接口传入的回调函数保持一致。若无此参数，则取消当前类型的所有订阅。 |

**错误码**：

错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locationIconStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.        |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let callback = (code: geoLocationManager.LocationIconStatus):void => {
      console.info('LocationIconStatus: ' + JSON.stringify(code));
  }
  try {
      geoLocationManager.on('locationIconStatusChange', callback);
	  geoLocationManager.off('locationIconStatusChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.getLocationIconStatus<sup>12+</sup>

getLocationIconStatus(): LocationIconStatus

获取当前的定位图标状态。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口。

**返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | [LocationIconStatus](#locationiconstatus12) | 返回定位图标状态。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.getLocationIconStatus} due to limited device capabilities.          |
|3301000  | The location service is unavailable.                  |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let iconStatus = geoLocationManager.getLocationIconStatus();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.enableLocationByUserId<sup>18+</sup>

enableLocationByUserId(userId: number): Promise&lt;void&gt;

打开指定系统账号的定位开关，使用Promise异步回调。

**系统API**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS 和 ohos.permission.CONTROL_LOCATION_SWITCH

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | userId | number | 是 | 系统账号ID，获取系统账号ID可参考[查询所有已创建的系统账号](../../basic-services/account/manage-os-account.md#查询所有已创建的系统账号)|

**返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.enableLocationByUserId} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  try {
      // 打开指定系统账号的位置开关，如：处于ID为101的账号下，可以打开ID为100的账号的位置开关
      let userId:number = 100;
      geoLocationManager.enableLocationByUserId(userId).then(() => {
          console.info('promise, enableLocationByUserId succeed');
      })
      .catch((error:BusinessError) => {
          console.error('promise, enableLocationByUserId: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.disableLocationByUserId<sup>18+</sup>

disableLocationByUserId(userId: number): void

关闭指定系统账号的定位开关。

**系统API**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS 和 ohos.permission.CONTROL_LOCATION_SWITCH

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | userId | number | 是 | 系统账号ID，获取系统账号ID可参考[查询所有已创建的系统账号](../../basic-services/account/manage-os-account.md#查询所有已创建的系统账号)|

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.disableLocationByUserId} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      // 关闭指定系统账号的位置开关，如：处于ID为101的账号下，可以关闭ID为100的账号的位置开关
      let userId:number = 100;
      geoLocationManager.disableLocationByUserId(userId);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.isLocationEnabledByUserId<sup>18+</sup>

isLocationEnabledByUserId(userId: number): boolean

判断指定系统账号的位置开关是否开启。

**系统API**：此接口为系统接口。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | userId | number | 是 | 系统账号ID，获取系统账号ID可参考 [查询所有已创建的系统账号](../../basic-services/account/manage-os-account.md#查询所有已创建的系统账号)|

**返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true：位置信息开关已开启。<br/>false：位置信息开关已关闭。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.isLocationEnabledByUserId} due to limited device capabilities.          |
|3301000 | The location service is unavailable. |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      // 查询指定系统账号的位置开关状态，如：处于ID为101的账号下，可以查询ID为100的账号的位置开关状态
      let userId:number = 100;
      let locationEnabled = geoLocationManager.isLocationEnabledByUserId(userId);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.setLocationSwitchIgnored<sup>18+</sup>

setLocationSwitchIgnored(isIgnored: boolean): void

设置应用获取位置信息是否受位置开关控制。

设置为true后，允许应用在位置开关关闭的场景获取到位置信息，有效时间为从调用接口成功开始的两分钟。

**系统API**：此接口为系统接口。

**需要权限**：ohos.permission.LOCATION_SWITCH_IGNORED

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | isIgnored | boolean | 是 | true：需要在位置开关关闭的场景下获取位置信息。有效时间为从调用接口成功开始的两分钟。<br/>false：不需要在位置开关关闭的场景下获取位置信息。|

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|202 | Permission verification failed. A non-system application calls a system API. |
|801 | Capability not supported. Failed to call ${geoLocationManager.setLocationSwitchIgnored} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                            |

**示例**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let isIgnored:boolean = true;
      geoLocationManager.setLocationSwitchIgnored(isIgnored);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```