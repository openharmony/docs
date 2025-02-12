# 位置服务错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 3301000 位置服务不可用

**错误信息**

The location service is unavailable.

**错误描述**

位置服务不可用，位置服务相关的接口无法调用。

**可能原因**

1.位置服务启动异常，导致应用和位置服务子系统通信失败，导致位置服务不可用。

2.GNSS芯片初始化失败导致GNSS定位功能失效。

3.网络定位服务异常，导致网络定位功能失效。

**处理步骤**

建议增加重试机制。

## 3301100 位置功能的开关未开启导致功能失败

**错误信息**

The location switch is off.

**错误描述**

位置功能的开关未开启导致功能失败。

**可能原因**

位置功能的开关未开启，导致持续定位，单次定位等基本功能不可用。

**处理步骤**

请提示用户开启位置功能的开关。

## 3301200 定位失败，未获取到定位结果

**错误信息**

The network locating is failed because the network cannot be accessed.

**错误描述**

无法访问网络导致网络定位失败。

**处理步骤**

请检查设备是否能联网，设备是否插入SIM卡，Wi-Fi开关是否开启等。</br>
</br>

**错误信息**

The positioning result does not meet the precision requirement (maxAccuracy) in the positioning request parameters.

**错误描述**

定位结果不满足定位请求参数中的精度要求(maxAccuracy)，导致定位超时。

**处理步骤**

请将定位请求参数[LocationRequest](./js-apis-geoLocationManager.md#locationrequest)、[CurrentLocationRequest](./js-apis-geoLocationManager.md#currentlocationrequest)中的精度要求(maxAccuracy)适当放宽，可参考如下场景建议：

- 当[scenario](./js-apis-geoLocationManager.md#locationrequestscenario)为NAVIGATION/TRAJECTORY_TRACKING/CAR_HAILING，或者[priority](./js-apis-geoLocationManager.md#locationrequestpriority)为ACCURACY时，建议设置maxAccuracy为大于10的值。

- 当[scenario](./js-apis-geoLocationManager.md#locationrequestscenario)为DAILY_LIFE_SERVICE/NO_POWER，或者[priority](./js-apis-geoLocationManager.md#locationrequestpriority)为LOW_POWER/FIRST_FIX时，建议设置maxAccuracy为大于100的值。</br>

**错误信息**

The system does not have a cache locaiton.

**错误描述**

系统无缓存位置，导致获取上一次位置失败。

**处理步骤**

系统未提前将位置信息进行缓存的情况下，需使用[getCurrentLocation](./js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation)接口获取实时位置信息。</br>
</br>

**错误信息**

Failed to obtain the geographical location.

**错误描述**

定位失败，未获取到定位结果。

**可能原因**

1.GNSS信号弱，导致定位超时。

2.系统时间设置错误，导致获取位置失败。

**处理步骤**

1.请移动至开阔地带再发起定位。

2.请在“日期和时间”页面勾选自动设置。


## 3301300 逆地理编码查询失败

**错误信息**

Reverse geocoding query failed.

**错误描述**

逆地理编码查询失败。

**可能原因**

- 数据网络比较卡顿，导致端侧的请求发送失败或者云端的结果未返回到端侧。

- 由于X86模拟器不支持逆地理编码功能，导致使用X86模拟器调试时逆地理编码查询失败。

**处理步骤**

- 网络原因请尝试重试逆地理编码查询功能。

- X86模拟器原因建议在真机进行验证。

## 3301400 地理编码查询失败

**错误信息**

Geocoding query failed.

**错误描述**

地理编码查询失败。

**可能原因**

1、请求参数有误，或根据参数无法查到结果。</br>
2、数据网络比较卡顿，导致端侧的请求发送失败或者云端的结果未返回到端侧。

**处理步骤**

请检查请求参数或检查网络状态后重试

## 3301500 区域信息（包含国家码）查询失败

**错误信息**

Failed to query the area information.

**错误描述**

区域信息（包含国家码）查询失败。

**可能原因**

未查询到正确的区域信息。

**处理步骤**

建议增加重试机制。

## 3301600 地理围栏操作失败

**错误信息**

Failed to operate the geofence.

**错误描述**

地理围栏操作失败，包含添加，删除，暂停和恢复等操作。

**可能原因**

1.GNSS芯片不支持地理围栏功能。

2.底层业务逻辑异常导致操作地理围栏失败。

**处理步骤**

- 增加SysCap校验。

- 建议增加重试机制。

## 3301601 地理围栏个数超过最大值限制导致添加围栏失败

**错误信息**

The number of geofences exceeds the maximum.

**错误描述**

地理围栏个数超过最大限制导致添加围栏失败。

**可能原因**

1.系统中存在的地理围栏个数超过最大值(1000)限制。

**处理步骤**

请在删除多余围栏之后再添加新的围栏。

## 3301602 地理围栏ID错误导致删除围栏失败

**错误信息**

Failed to delete a geofence due to an incorrect ID.

**错误描述**

地理围栏ID错误导致删除围栏失败。

**可能原因**

1.APP调用删除地理围栏接口时传入的围栏ID错误。

**处理步骤**

请在调用删除地理围栏接口时传入正确的围栏ID。

## 3301700 请求无响应

**错误信息**

No response to the request.

**错误描述**

某些异步请求需要用户点击按钮确认，或者需要GNSS芯片和网络服务器响应，这些场景下未收到响应导致业务失败。

**可能原因**

1.用户未点击按钮确认。

2.GNSS芯片未响应。

3.网络服务器未响应。

**处理步骤**

建议增加重试机制。

## 3301800 启动Wi-Fi或蓝牙扫描失败

**错误信息**

Failed to start Wi-Fi or Bluetooth scanning.

**错误描述**

在订阅Wi-Fi蓝牙扫描信息时，可能会先启动Wi-Fi蓝牙扫描，如果启动扫描失败则会返回错误码给APP。

**可能原因**

1.Wi-Fi或蓝牙服务内部错误导致启动扫描失败。

2.低电量场景下，受功耗管控，导致无法发起扫描。

3.Wi-Fi或蓝牙开关未开启。

**处理步骤**

重新关闭开启Wi-Fi或蓝牙开关。

## 3301900 由于Wi-Fi未连接导致获取Wi-Fi热点的MAC地址失败

**错误信息**

Failed to obtain the hotpot MAC address because the Wi-Fi is not connected.

**错误描述**

设备未连接Wi-Fi热点或路由器，导致获取Wi-Fi热点或路由器的MAC地址失败。

**可能原因**

1.Wi-Fi开关未开启。

2.开启Wi-Fi开关但未连接热点或路由器。

**处理步骤**

1.请打开Wi-Fi开关。

2.请连接路由器或者热点。
