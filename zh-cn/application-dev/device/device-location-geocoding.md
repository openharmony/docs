# （逆）地理编码转化


## 场景介绍

使用坐标描述一个位置，非常准确，但是并不直观，面向用户表达并不友好。系统向开发者提供了以下两种转化能力。

- 地理编码转化：将地理描述转化为具体坐标。

- 逆地理编码转化能力：将坐标转化为地理描述。

其中地理编码包含多个属性来描述位置，包括国家、行政区划、街道、门牌号、地址描述等等，这样的信息更便于用户理解。


## 接口说明

进行坐标和地理编码信息的相互转化，所使用的接口说明如下。

  **表1** 地理编码转化能力和逆地理编码转化能力的API功能介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| isGeoServiceAvailable(callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void | 判断（逆）地理编码服务状态，使用callback回调异步返回结果。 | 
| isGeoServiceAvailable()&nbsp;:&nbsp;Promise&lt;boolean&gt; | 判断（逆）地理编码服务状态，使用Promise方式异步返回结果。 | 
| getAddressesFromLocation(request:&nbsp;ReverseGeoCodeRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;)&nbsp;:&nbsp;void | 调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。 | 
| getAddressesFromLocation(request:&nbsp;ReverseGeoCodeRequest)&nbsp;:&nbsp;Promise&lt;Array&lt;GeoAddress&gt;&gt;; | 调用逆地理编码服务，将坐标转换为地理描述，使用Promise方式异步返回结果。 | 
| getAddressesFromLocationName(request:&nbsp;GeoCodeRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;)&nbsp;:&nbsp;void | 调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。 | 
| getAddressesFromLocationName(request:&nbsp;GeoCodeRequest)&nbsp;:&nbsp;Promise&lt;Array&lt;GeoAddress&gt;&gt; | 调用地理编码服务，将地理描述转换为具体坐标，使用Promise方式异步返回结果。 | 


## 开发步骤

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> GeoConvert需要访问后端服务，请确保设备联网，以进行信息获取。

1. 导入geolocation模块，所有与（逆）地理编码转化能力相关的功能API，都是通过该模块提供的。
     
   ```
   import geolocation from '@ohos.geolocation';
   ```

2. 获取转化结果。
   - 调用getAddressesFromLocation，坐标转化地理位置信息。
        
      ```
      var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      geolocation.getAddressesFromLocation(reverseGeocodeRequest, (data) => {
          console.log('getAddressesFromLocation: ' + JSON.stringify(data));
      });
      ```

      参考接口API说明[位置服务](../reference/apis/js-apis-geolocation.md)，应用可以获得与此坐标匹配的GeoAddress列表，应用可以根据实际使用需求，读取相应的参数数据。
   - 调用getAddressesFromLocationName位置描述转化坐标。
        
      ```
      var geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
      geolocation.getAddressesFromLocationName(geocodeRequest, (data) => {
          console.log('getAddressesFromLocationName: ' + JSON.stringify(data));
      });
      ```

      参考接口API说明[位置服务](../reference/apis/js-apis-geolocation.md)，应用可以获得与位置描述相匹配的GeoAddress列表，其中包含对应的坐标数据，请参考API使用。

      如果需要查询的位置描述可能出现多地重名的请求，可以设置GeoCodeRequest，通过设置一个经纬度范围，以高效地获取期望的准确结果。
