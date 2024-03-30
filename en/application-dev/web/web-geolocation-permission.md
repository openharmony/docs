# Managing Location Permissions


The **Web** component provides the location permission management capability. You can use [onGeolocationShow()](../reference/apis-arkweb/ts-basic-components-web.md#ongeolocationshow) to manage the location permission specific to a website. Based on the API response, the **Web** component determines whether to grant the location permission to the frontend page. To obtain the device location, you need to declare the [ohos.permission.LOCATION](../security/AccessToken/request-user-authorization.md) permission, and enable on the device the location permission for the application and the location information for the control panel.


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
  import web_webview from '@ohos.web.webview';
  import { abilityAccessCtrl, common }from '@kit.AbilityKit';
  import {geoLocationManager} from '@kit.LocationKit';

  let context = getContext(this) as common.UIAbilityContext;
  let atManager = abilityAccessCtrl.createAtManager();

  try{
    atManager.requestPermissionsFromUser(context, ["ohos.permission.APPROXIMATELY_LOCATION"], (err, data) => {
      let requestInfo: geoLocationManager.LocationRequest = {
        'priority': 0x203,
        'scenario': 0x300,
        'maxAccuracy': 0
      };
      let locationChange = (location: geoLocationManager.Location):void => {
        if(location){
          console.log('locationChanger: location=' + JSON.stringify(location));
        }
      };
      try{
        geoLocationManager.on('locationChange', requestInfo, locationChange);
        geoLocationManager.off('locationChange', locationChange);
      } catch (err) {
        console.error("errCode:" + err.code + ", errMessage:" + err.message);
      }
    })
  } catch (err) {
    console.error("err:", err);
  }

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
                  if (event) {
                    event.geolocation.invoke(event.origin, false, false); // Deny access to the device location.
                  }
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  if (event) {
                    event.geolocation.invoke(event.origin, true, false);    // Allow access to the device location.
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
