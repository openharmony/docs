# Managing Location Permissions
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Since API version 9, the **Web** component supports the [GeolocationPermissions](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md) class and [onGeolocationShow](../reference/apis-arkweb/arkts-basic-components-web-events.md#ongeolocationshow) method for managing web page location permissions. For details, see <!--RP1-->[Privacy Protection](../../device-dev/security/security-privacy-protection.md)<!--RP1End-->.

The **Web** component determines whether to grant the frontend page permission based on the response of the [GeolocationPermissions](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md) class and [onGeolocationShow](../reference/apis-arkweb/arkts-basic-components-web-events.md#ongeolocationshow) method. Users can grant applications access to their location for services such as navigation and weather forecasts.

## Required Permissions
To obtain the location, you need to configure the location permission in **module.json5**. For details, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md#declaring-permissions-in-the-configuration-file).

   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.LOCATION" // Precise location
      },
      {
        "name" : "ohos.permission.APPROXIMATELY_LOCATION" // Approximate location
      },
      {
        "name" : "ohos.permission.LOCATION_IN_BACKGROUND" // Background location
      }
    ]
   ```

## Requesting Location Permission
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
                  // Access the device's geolocation.
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
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { abilityAccessCtrl, common } from '@kit.AbilityKit';

  let atManager = abilityAccessCtrl.createAtManager();

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    // Component lifecycle function, which is triggered after a component instance is created.
    aboutToAppear(): void {
      let context : Context | undefined = this.uiContext.getHostContext() as common.UIAbilityContext;
      if (!context) {
        console.error("context is undefined");
        return;
      }
      // Request the location permission from the user, which takes effect for the entire application.
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
        // The geolocationAccess attribute of the Web component is true by default. You can explicitly set it to false to disable the Web component from obtaining the geolocation information.
        Web({ src: $rawfile('getLocation.html'), controller: this.controller })
          .geolocationAccess(true)
          .onGeolocationShow((event) => {
            // The location permission request is notified only to the current Web component. Other Web components in the application are not affected.
            this.uiContext.showAlertDialog({
              title: 'Location Permission',
              message:'Grant access to the device location?',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  if (event) {
                    // Deny the location permission request of this site.
                    // Note that the third parameter of invoke indicates whether to remember the current selection. If true is passed, the dialog box will not be displayed next time.
                    event.geolocation.invoke(event.origin, false, false);
                  }
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  if (event) {
                    // Allow the location permission request of this site.
                    // Note that the third parameter of invoke indicates whether to remember the current selection. If true is passed, the dialog box will not be displayed next time.
                    event.geolocation.invoke(event.origin, true, false);
                  }
                }
              },
              cancel: () => {
                if (event) {
                  // Deny the location permission request of this site.
                  // Note that the third parameter of invoke indicates whether to remember the current selection. If true is passed, the dialog box will not be displayed next time.
                  event.geolocation.invoke(event.origin, false, false);
                }
              }
            })
          })
      }
    }
  }
  ```

## Managing Location Permissions
The Web component provides the [GeolocationPermissions](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md) class for managing web page location permissions, including [allowgeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#allowgeolocation) for adding a location permission, [getaccessiblegeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#getaccessiblegeolocation) for viewing location permissions, and [deleteallgeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#deleteallgeolocation) for deleting a location permission.  


```ts
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  origin: string = "www.example.com";

  build() {
    Column() {
      // Add the location permission for the specified source so that the onGeolocationShow callback is not triggered when location information is obtained again.
      Button('allowGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.allowGeolocation(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      // Delete the location permission for the specified source so that the onGeolocationShow callback is triggered when location information is obtained again.
      Button('deleteGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.deleteGeolocation(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      // Query the location permission of the specified source.
      Button('getAccessibleGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.getAccessibleGeolocation(this.origin)
              .then(result => {
                console.info('getAccessibleGeolocationPromise result: ' + result);
              }).catch((error: BusinessError) => {
              console.error(`getAccessibleGeolocationPromise error, ErrorCode: ${error.code},  Message: ${error.message}`);
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      // Add the network permission ohos.permission.INTERNET.
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
