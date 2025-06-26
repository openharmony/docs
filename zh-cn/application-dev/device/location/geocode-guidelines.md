# 地理编码转化与逆地理编码转化开发指导(ArkTS)

## 场景概述

使用坐标描述一个位置，非常准确，但是并不直观，面向用户表达并不友好。系统向开发者提供了以下两种转化能力。

- 地理编码转化：将地理描述转化为具体坐标。

- 逆地理编码转化能力：将坐标转化为地理描述。

其中地理编码包含多个属性来描述位置，包括国家、行政区划、街道、门牌号、地址描述等等，这样的信息更便于用户理解。

## 接口说明

进行坐标和地理编码信息的相互转化，所使用的接口说明如下，详细信息参见：[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)。

| 接口名 | 功能描述 | 
| -------- | -------- |
| [isGeocoderAvailable(): boolean](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerisgeocoderavailable) | 判断地理编码与逆地理编码服务是否可用。 | 
| [getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetaddressesfromlocation) | 调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。 | 
| [getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetaddressesfromlocationname) | 调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。 | 

## 开发步骤

> **说明：**
> 地理编码与逆地理编码功能需要访问后端服务，请确保设备联网，以进行信息获取。

1. 导入geoLocationManager模块，所有与地理编码转化&逆地理编码转化能力相关的功能API，都是通过该模块提供的。
   
   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   ```

2. 查询地理编码与逆地理编码服务是否可用。
   - 调用isGeoServiceAvailable查询地理编码与逆地理编码服务是否可用，如果服务可用再继续进行步骤3。如果服务不可用，说明该设备不具备地理编码与逆地理编码能力，请勿使用相关接口。
     
      ```ts
      import { geoLocationManager } from '@kit.LocationKit';
      try {
          let isAvailable = geoLocationManager.isGeocoderAvailable();
      } catch (err) {
          console.error("errCode:" + JSON.stringify(err));
      }
      ```

3. 获取转化结果。
   - 调用getAddressesFromLocation，把坐标转化为地理位置信息。应用可以获得与此坐标匹配的[GeoAddress](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geoaddress)（地理编码地址信息）列表，应用可以根据实际使用需求，读取相应的参数数据。
     
      ```ts
      let reverseGeocodeRequest:geoLocationManager.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      try {
          geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
              if (err) {
                  console.error('getAddressesFromLocation err: ' + JSON.stringify(err));
              } else {
                  console.info('getAddressesFromLocation data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + JSON.stringify(err));
      }
      ```

   - 调用getAddressesFromLocationName把位置描述转化为坐标。
     
      ```ts
      let geocodeRequest:geoLocationManager.GeoCodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
      try {
          geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
              if (err) {
                  console.error('getAddressesFromLocationName err: ' + JSON.stringify(err));
              } else {
                  console.info('getAddressesFromLocationName data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + JSON.stringify(err));
      }
      ```

      应用可以获得与位置描述相匹配的[GeoAddress](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geoaddress)（地理编码地址信息）列表，其中包含对应的坐标数据。

      如果需要查询的位置描述可能出现多地重名的请求，可以设置[GeoCodeRequest](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geocoderequest)，通过设置一个经纬度范围，以高效地获取期望的准确结果。