# Managing Location Permissions


The **Web** component provides the location permission management capability (<!--RP1-->[Privacy Protection](../../device-dev/security/security-privacy-protection.md)<!--RP1End-->). You can use [onGeolocationShow()](../reference/apis-arkweb/arkts-basic-components-web-events.md#ongeolocationshow) to manage the location permission specific to a website. Based on the API response, the **Web** component determines whether to grant the location permission to the frontend page.

- Before obtaining the device geolocation, add location-related permissions to the **module.json5** file. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.LOCATION"
      },
      {
        "name" : "ohos.permission.APPROXIMATELY_LOCATION"
      },
      {
        "name" : "ohos.permission.LOCATION_IN_BACKGROUND"
      }
    ]
   ```

In the following example, when a user clicks the **Get Location** button on the frontend page, the **Web** component notifies the application of the location permission request in a dialog box.


- Frontend page code:

  ```html
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Location Information</title>
  </head>
  <body>
      <p id="locationInfo">Location information</p>
      <button onclick="getLocation()">Get Location</button>

      <script>
          var locationInfo=document.getElementById("locationInfo");
          function getLocation(){
              if (navigator.geolocation) {
                  // Access to the device location by the frontend page
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

  let atManager = abilityAccessCtrl.createAtManager();

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    aboutToAppear(): void {
      let context : Context | undefined = this.uiContext.getHostContext() as common.UIAbilityContext;
      // Request the location permission from the user.
      atManager.requestPermissionsFromUser(context, ["ohos.permission.APPROXIMATELY_LOCATION"]).then((data) => {
        console.info('data:' + JSON.stringify(data));
        console.info('data permissions:' + data.permissions);
        console.info('data authResults:' + data.authResults);
      }).catch((error: BusinessError) => {
        console.error(`Failed to request permissions from user. Code is ${error.code}, message is ${error.message}`);
      })  
    }

    build() {
      Column() {
        Web({ src: $rawfile('getLocation.html'), controller: this.controller })
          .geolocationAccess(true)
          .onGeolocationShow((event) => { // Notification of the location permission request
             this.uiContext.showAlertDialog({
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
