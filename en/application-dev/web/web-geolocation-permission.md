# Managing Location Permissions


The **Web** component provides the location permission management capability. You can use [onGeolocationShow()](../reference/arkui-ts/ts-basic-components-web.md#ongeolocationshow) to manage the location permission specific to a website. Based on the API response, the **Web** component determines whether to grant the location permission to the frontend page. To obtain the device location, you need to declare the [ohos.permission.LOCATION](../security/accesstoken-guidelines.md) permission.


In the following example, when a user clicks the **Get Location** button on the frontend page, the **Web** component notifies the application of the location permission request in a pop-up window.


- Frontend page code:

  ```html
  <!DOCTYPE html>
  <html>
  <body>
  <p id="locationInfo">Location information</p>
  <button onclick="getLocation()">Get Location</button>
  <script>
  var locationInfo=document.getElementById("locationInfo");
  function getLocation(){
    if (navigator.geolocation) {
      <!-- Access to the device location by the frontend page -->
      navigator.geolocation.getCurrentPosition(showPosition);
    }
  }
  function showPosition(position){
    locationInfo.innerHTML="Latitude: " + position.coords.latitude + "<br />Longitude: " + position.coords.longitude;
  }
  </script>
  </body>
  </html>
  ```


- Application code:

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();
    build() {
      Column() {
        Web({ src:$rawfile('getLocation.html'), controller:this.controller })
          .geolocationAccess(true)
          .onGeolocationShow((event) => {  // Notification of the location permission request
            AlertDialog.show({
              title: 'Location Permission',
              message:'Grant access to the device location?',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  event.geolocation.invoke(event.origin, false, false); // Deny access to the device location.
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  event.geolocation.invoke(event.origin, true, false);    // Allow access to the device location.
                }
              },
              cancel: () => {
                event.geolocation.invoke(event.origin, false, false); // Deny access to the device location.
              }
            })
          })
      }
    }
  }
  ```
