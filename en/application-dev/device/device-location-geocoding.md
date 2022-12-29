# Geocoding and Reverse Geocoding Capabilities


## When to Use

Describing a location using coordinates is accurate, but neither intuitive nor user-friendly. With the geocoding and reverse geocoding capabilities, you will be able to convert geographic description into specific coordinates and vice versa.

The geographic description helps users understand a location easily by providing several key attributes, for example, country, administrative region, street, house number, and address.


## Available APIs

The following table describes APIs available for mutual conversion between coordinates and geographic description. For details, see [Geolocation Manager](../reference/apis/js-apis-geolocation.md).

  **Table1** APIs for geocoding and reverse geocoding

| API | Description | 
| -------- | -------- |
| isGeoServiceAvailable(callback: AsyncCallback&lt;boolean&gt;) : void | 判断（逆）地理编码服务状态，使用callback回调异步返回结果。 | 
| isGeoServiceAvailable() : Promise&lt;boolean&gt; | 判断（逆）地理编码服务状态，使用Promise方式异步返回结果。 | 
| getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;) : void | 调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。 | 
| getAddressesFromLocation(request: ReverseGeoCodeRequest) : Promise&lt;Array&lt;GeoAddress&gt;&gt; | 调用逆地理编码服务，将坐标转换为地理描述，使用Promise方式异步返回结果。 | 
| getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;) : void | 调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。 | 
| getAddressesFromLocationName(request: GeoCodeRequest) : Promise&lt;Array&lt;GeoAddress&gt;&gt; | 调用地理编码服务，将地理描述转换为具体坐标，使用Promise方式异步返回结果。 | 


## How to Develop

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> 
> The **GeoConvert** instance needs to access backend services to obtain information. Therefore, before performing the following steps, ensure that your device is connected to the network.

1. Import the **geolocation** module by which you can implement all APIs related to the geocoding and reverse geocoding conversion capabilities.
   
   ```ts
   import geolocation from '@ohos.geolocation';
   ```

2. Query whether geocoder service is available.
   - Call **isGeoServiceAvailable** to query whether the geocoder service is available. If the service is available, continue with step 3.
      ```ts
      geolocation.isGeoServiceAvailable((err, data) => {
          if (err) {
              console.log('isGeoServiceAvailable err: ' + JSON.stringify(err));
          } else {
              console.log('isGeoServiceAvailable data: ' + JSON.stringify(data));
          }
      });
      ```

3. Obtain the conversion result.
   - Call **getAddressesFromLocation** to convert coordinates into geographical location information.
     
      ```ts
      var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      geolocation.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
          if (err) {
              console.log('getAddressesFromLocation err: ' + JSON.stringify(err));
          } else {
              console.log('getAddressesFromLocation data: ' + JSON.stringify(data));
          }
      });
      ```

      Your application can obtain the **GeoAddress** list that matches the specified coordinates and then read location information from it. For details, see [Geolocation](../reference/apis/js-apis-geolocation.md).
   - Call **getAddressesFromLocationName** to convert geographic description into coordinates.
     
      ```ts
      var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
      geolocation.getAddressesFromLocationName(geocodeRequest, (err, data) => {
          if (err) {
              console.log('getAddressesFromLocationName err: ' + JSON.stringify(err));
          } else {
              console.log('getAddressesFromLocationName data: ' + JSON.stringify(data));
          }
      });
      ```

      Your application can obtain the **GeoAddress** list that matches the specified location information and read coordinates from it. For details, see [Geolocation](../reference/apis/js-apis-geolocation.md).

      To improve the accuracy of location results, you can set the longitude and latitude ranges in **GeoCodeRequest**.
