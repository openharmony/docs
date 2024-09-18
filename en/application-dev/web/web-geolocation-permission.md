# Managing Location Permissions


The **Web** component provides the location permission management capability. You can use [onGeolocationShow()](../reference/apis-arkweb/ts-basic-components-web.md#ongeolocationshow) to manage the location permission specific to a website. Based on the API response, the **Web** component determines whether to grant the location permission to the frontend page. To obtain the device location, you need to declare the [ohos.permission.LOCATION](../security/AccessToken/request-user-authorization.md), [ohos.permission.APPROXIMATELY_LOCATION](../security/AccessToken/request-user-authorization.md), and [ohos.permission.LOCATION_IN_BACKGROUND](../security/AccessToken/request-user-authorization.md) permissions, and enable on the device the location permission for the application and the location information for the control panel. For details, see [Geolocation](../reference/apis-location-kit/js-apis-geolocation.md).


In the following example, when a user clicks the **Get Location** button on the frontend page, the **Web** component notifies the application of the location permission request in a dialog box.


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
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { abilityAccessCtrl, common } from '@kit.AbilityKit';

  let context = getContext(this) as common.UIAbilityContext;
  let atManager = abilityAccessCtrl.createAtManager();

  // Request the location permission from the user.
  atManager.requestPermissionsFromUser(context, ["ohos.permission.APPROXIMATELY_LOCATION"]).then((data) => {
    console.info('data:' + JSON.stringify(data));
    console.info('data permissions:' + data.permissions);
    console.info('data authResults:' + data.authResults);
  }).catch((error: BusinessError) => {
    console.error(`Failed to request permissions from user. Code is ${error.code}, message is ${error.message}`);
  })

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile('getLocation.html'), controller: this.controller })
          .geolocationAccess(true)
          .onGeolocationShow((event) => { // Notification of the location permission request
            AlertDialog.show({
              title: 'Location Permission',
              message:'Grant access to the device location?',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  if (event) {
                    event.geolocation.invoke(event.origin, false, false); // Deny access to the device location.
                  }
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  if (event) {
                    event.geolocation.invoke(event.origin, true, false); // Allow access to the device location.
                  }
                }
              },
              cancel: () => {
                if (event) {
                  event.geolocation.invoke(event.origin, false, false); // Deny access to the device location.
                }
              }
            })
          })
      }
    }
  }
  ```
