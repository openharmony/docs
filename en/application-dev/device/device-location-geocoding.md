# Geocoding and Reverse Geocoding Capabilities


## When to Use

Describing a location using coordinates is accurate, but neither intuitive nor user-friendly. To address this issue, the system provides your application the geocoding and reverse geocoding capabilities:

- Geocoding: converts geographic descriptions into specific coordinates.

- Reverse geocoding: converts coordinates into geographic descriptions.

The geocoding information describes a location using several attributes, including the country, administrative region, street, house number, and address, etc.


## Available APIs

The following table describes APIs available for mutual conversion between coordinates and location information.

  **Table 1** APIs for geocoding and reverse geocoding

| Name| Description| 
| -------- | -------- |
| isGeoServiceAvailable(callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void | Checks whether the (reverse) geocoding service is available. This API uses an asynchronous callback to return the result.| 
| isGeoServiceAvailable()&nbsp;:&nbsp;Promise&lt;boolean&gt; | Checks whether the (reverse) geocoding service is available. This API uses a promise to return the result.| 
| getAddressesFromLocation(request:&nbsp;ReverseGeoCodeRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;)&nbsp;:&nbsp;void | Converts coordinates into geographic descriptions through reverse geocoding. This API uses an asynchronous callback to return the result. | 
| getAddressesFromLocation(request:&nbsp;ReverseGeoCodeRequest)&nbsp;:&nbsp;Promise&lt;Array&lt;GeoAddress&gt;&gt;; | Converts coordinates into geographic descriptions through reverse geocoding. This API uses a promise to return the result. | 
| getAddressesFromLocationName(request:&nbsp;GeoCodeRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;)&nbsp;:&nbsp;void | Converts geographic descriptions into coordinates through geocoding. This API uses an asynchronous callback to return the result. | 
| getAddressesFromLocationName(request:&nbsp;GeoCodeRequest)&nbsp;:&nbsp;Promise&lt;Array&lt;GeoAddress&gt;&gt; | Converts geographic descriptions into coordinates through geocoding. This API uses a promise to return the result. | 


## How to Develop

> **NOTE**
> The **GeoConvert** instance needs to access backend services to obtain information. Therefore, before performing the following steps, ensure that your device is connected to the network.

1. Import the **geolocation** module by which you can implement all APIs related to the geocoding and reverse geocoding conversion capabilities.
     
   ```
   import geolocation from '@ohos.geolocation';
   ```

2. Obtain the geocoding conversion result.
   - Call **getAddressesFromLocation** to convert coordinates into geographical location information.
        
      ```
      var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      try {
          geolocation.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
              if (err) {
                  console.log('getAddressesFromLocation err: ' + JSON.stringify(err));
              } else {
                  console.log('getAddressesFromLocation data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + err.code + ",errMessage:" + err.message);
      }
      ```

      The application can access the **GeoAddress** list that matches the specified coordinates for the corresponding geographic descriptions. For details, see [Geolocation](../reference/apis/js-apis-geolocation.md).
   - Call **getAddressesFromLocationName** to convert geographic description into coordinates.
        
      ```
      var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
      try {
          geolocation.getAddressesFromLocationName(geocodeRequest, (err, data) => {
              if (err) {
                  console.log('getAddressesFromLocationName err: ' + JSON.stringify(err));
              } else {
                  console.log('getAddressesFromLocationName data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + err.code + ",errMessage:" + err.message);
      }
      ```

      The application can access the **GeoAddress** list that matches the specified geographic descriptions for the corresponding coordinates. For details, see [Geolocation](../reference/apis/js-apis-geolocation.md).

      To improve the accuracy of location results, you can set the longitude and latitude ranges in **GeoCodeRequest**.
