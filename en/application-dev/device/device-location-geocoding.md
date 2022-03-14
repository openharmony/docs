# Geocoding and Reverse Geocoding Capabilities


## When to Use

Describing a location using coordinates is accurate, but neither intuitive nor user-friendly.

With the geocoding and reverse geocoding capabilities, you will be able to convert geographic description into specific coordinates and vice versa. The geocoding information describes a location using several attributes, including the country, administrative region, street, house number, and address, etc.


## Available APIs

The following table describes APIs available for mutual conversion between coordinates and location information.

  **Table1** APIs for geocoding and reverse geocoding

| API | Description | 
| -------- | -------- |
| isGeoServiceAvailable(callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void | Checks&nbsp;whether&nbsp;the&nbsp;(reverse)&nbsp;geocoding&nbsp;service&nbsp;is&nbsp;available.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| isGeoServiceAvailable()&nbsp;:&nbsp;Promise&lt;boolean&gt; | Checks&nbsp;whether&nbsp;the&nbsp;(reverse)&nbsp;geocoding&nbsp;service&nbsp;is&nbsp;available.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| getAddressesFromLocation(request:&nbsp;ReverseGeoCodeRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;)&nbsp;:&nbsp;void | Converts&nbsp;coordinates&nbsp;into&nbsp;geographic&nbsp;description&nbsp;through&nbsp;reverse&nbsp;geocoding.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| getAddressesFromLocation(request:&nbsp;ReverseGeoCodeRequest)&nbsp;:&nbsp;Promise&lt;Array&lt;GeoAddress&gt;&gt;; | Converts&nbsp;coordinates&nbsp;into&nbsp;geographic&nbsp;description&nbsp;through&nbsp;reverse&nbsp;geocoding.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| getAddressesFromLocationName(request:&nbsp;GeoCodeRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;)&nbsp;:&nbsp;void | Converts&nbsp;geographic&nbsp;description&nbsp;into&nbsp;coordinates&nbsp;through&nbsp;geocoding.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| getAddressesFromLocationName(request:&nbsp;GeoCodeRequest)&nbsp;:&nbsp;Promise&lt;Array&lt;GeoAddress&gt;&gt; | Converts&nbsp;geographic&nbsp;description&nbsp;into&nbsp;coordinates&nbsp;through&nbsp;geocoding.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 


## How to Develop

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> The **GeoConvert** instance needs to access backend services to obtain information. Therefore, before performing the following steps, ensure that your device is connected to the network.

1. Import the **geolocation** module by which you can implement all APIs related to the geocoding and reverse geocoding conversion capabilities.
   
   ```
   import geolocation from '@ohos.geolocation';
   ```

2. Obtain the conversion result.
   - Call **getAddressesFromLocation** to convert coordinates into geographical location information.
     
      ```
      var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      geolocation.getAddressesFromLocation(reverseGeocodeRequest, (data) => {
          console.log('getAddressesFromLocation: ' + JSON.stringify(data));
      });
      ```

      Your application can obtain the **GeoAddress** list that matches the specified coordinates and then read location information from it. For details, see the _API Reference_.
   - Call **getAddressesFromLocationName** to convert geographic description into coordinates.
     
      ```
      var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
      geolocation.getAddressesFromLocationName(geocodeRequest, (data) => {
          console.log('getAddressesFromLocationName: ' + JSON.stringify(data));
      });
      ```

      Your application can obtain the **GeoAddress** list that matches the specified location information and read coordinates from it. For details, see the _API Reference_.

      To improve the accuracy of location results, you can set the longitude and latitude ranges in **GeoCodeRequest**.
