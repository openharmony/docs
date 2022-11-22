# （逆）地理编码转化


## 场景介绍

使用坐标描述一个位置，非常准确，但是并不直观，面向用户表达并不友好。系统向开发者提供了以下两种转化能力。

- 地理编码转化：将地理描述转化为具体坐标。

- 逆地理编码转化能力：将坐标转化为地理描述。

其中地理编码包含多个属性来描述位置，包括国家、行政区划、街道、门牌号、地址描述等等，这样的信息更便于用户理解。


## 接口说明

进行坐标和地理编码信息的相互转化，所使用的接口说明如下，详细信息参见：[位置服务](../reference/apis/js-apis-geoLocationManager.md)。

  **表1** 地理编码转化能力和逆地理编码转化能力的API功能介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| isGeocoderAvailable(): boolean; | 判断（逆）地理编码服务状态。 | 
| getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void | 调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。 | 
| getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt; | 调用逆地理编码服务，将坐标转换为地理描述，使用Promise方式异步返回结果。 | 
| getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void | 调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。 | 
| getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt; | 调用地理编码服务，将地理描述转换为具体坐标，使用Promise方式异步返回结果。 | 


## 开发步骤

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> GeoConvert需要访问后端服务，请确保设备联网，以进行信息获取。

1. 导入geoLocationManager模块，所有与（逆）地理编码转化能力相关的功能API，都是通过该模块提供的。
     
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   ```

2. 查询geoCoder服务是否可用。
   - 调用isGeoServiceAvailable查询geoCoder服务是否可用，如果服务可用再继续进行步骤3。
        
      ```ts
      import geoLocationManager from '@ohos.geoLocationManager';
      try {
          var isAvailable = geoLocationManager.isGeocoderAvailable();
      } catch (err) {
          console.error("errCode:" + err.code + ",errMessage:" + err.message);
      }
      ```

3. 获取转化结果。
   - 调用getAddressesFromLocation，坐标转化地理位置信息。
        
      ```ts
      var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
          if (err) {
              console.log('getAddressesFromLocation err: ' + JSON.stringify(err));
          } else {
              console.log('getAddressesFromLocation data: ' + JSON.stringify(data));
          }
      });
      ```

      参考接口API说明[位置服务](../reference/apis/js-apis-geoLocationManager.md)，应用可以获得与此坐标匹配的GeoAddress列表，应用可以根据实际使用需求，读取相应的参数数据。
   - 调用getAddressesFromLocationName位置描述转化坐标。
        
      ```ts
      var geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
      geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
          if (err) {
              console.log('getAddressesFromLocationName err: ' + JSON.stringify(err));
          } else {
              console.log('getAddressesFromLocationName data: ' + JSON.stringify(data));
          }
      });
      ```

      参考接口API说明[位置服务](../reference/apis/js-apis-geoLocationManager.md)，应用可以获得与位置描述相匹配的GeoAddress列表，其中包含对应的坐标数据，请参考API使用。

      如果需要查询的位置描述可能出现多地重名的请求，可以设置GeoCodeRequest，通过设置一个经纬度范围，以高效地获取期望的准确结果。
