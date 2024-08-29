# Using Motion and Direction Sensors

The **Web** component can be connected to motion and orientation sensors through standard W3C APIs. When using the acceleration, gyroscope, and device motion event APIs, you need to declare the corresponding sensor permissions in the configuration file.

- Add the acceleration permission in the **module.json5** file before using the acceleration and device motion event APIs.
   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.ACCELEROMETER"
      }
    ]
   ```
- Add the gyroscope permission to the **module.json5** file before using the gyroscope APIs.
   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.GYROSCOPE"
      }
    ]
   ```
For details about how to add sensor permissions, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md).

When connecting the **Web** component to the motion and orientation sensors, configure **onPermissionRequest()** to receive permission request notifications.

You can obtain the motion and orientation sensors by calling the following standard W3C APIs in JavaScript.

| API                     | Name        | Supported| Description              |
| ------------------------- | ------------ | -------- | ------------------ |
| Accelerometer             | Acceleration      | Yes    | -                  |
| Gyroscope                 | Gyroscope      | Yes    | -                  |
| AbsoluteOrientationSensor | Absolute orientation    | Yes    | -                  |
| RelativeOrientationSensor | Relative orientation    | No  | Does not support by sensor data.|
| DeviceMotionEvent         | Device motion event| Yes    | -                  |
| DeviceOrientationEvent    | Device orientation event| Yes    | Obtains the absolute orientation.|

**RelativeOrientationSensor()** is not configured since it is not supported. Therefore, this API cannot be used to listen for the relative orientation data of the device.

Click buttons on the **index.html** page to listen for corresponding data. The example code is as follows:

- Code on the application side:

  ```ts
  import { webview } from '@kit.ArkWeb';
  import { abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController()
    aboutToAppear() {
      // Enable web frontend page debugging.
      webview.WebviewController.setWebDebuggingAccess(true);
      // Create an **AtManager** instance, which is used for application access control.
      let atManager = abilityAccessCtrl.createAtManager();
      try {
        atManager.requestPermissionsFromUser(getContext(this), ['ohos.permission.ACCELEROMETER', 'ohos.permission.GYROSCOPE']
          , (err: BusinessError, data: PermissionRequestResult) => {
          console.info('data:' + JSON.stringify(data));
          console.info('data permissions:' + data.permissions);
          console.info('data authResults:' + data.authResults);
        })
      } catch (error) {
        console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
      }
    }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onPermissionRequest((event) => {
            if (event) {
              AlertDialog.show({
                title: 'title',
                message: 'text',
                primaryButton: {
                  value: 'deny',
                  action: () => {
                    event.request.deny();
                  }
                },
                secondaryButton: {
                  value: 'onConfirm',
                  action: () => {
                    event.request.grant(event.request.getAccessibleResource());
                  }
                },
                autoCancel: false,
                cancel: () => {
                  event.request.deny();
                }
              })
            }
          })
      }
    }
  }
  ```

- Code of the **index.html** page:

  ```html
  <!DOCTYPE HTML>
  <html>
  <head>
      <meta charset="utf-8" />
      <meta name="viewport" content="initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
      <meta name="misapplication-tap-highlight" content="no" />
      <meta name="HandheldFriendly" content="true" />
      <meta name="MobileOptimized" content="320" />
      <title>Motion and direction sensor</title>
      <meta charset="UTF-8">
      <style>
          body {
              font-family: Arial, sans-serif;
          }
      </style>
      <script type="text/javascript">
          function getAccelerometer() {
              var acc = new Accelerometer({frequency: 60});
              acc.addEventListener('activate', () => console.log('Ready to measure.'));
              acc.addEventListener('error', error => console.log(`Error: ${error.name}`));
              acc.addEventListener('reading', () => {
                  console.log(`[doc_sensor]Accelerometer ${acc.timestamp}, ${acc.x}, ${acc.y}, ${acc.z}.`);
              });
              acc.start();
          }

          function getGyroscope() {
              var gyr = new Gyroscope({frequency: 60});
              gyr.addEventListener('activate', () => console.log('Ready to measure.'));
              gyr.addEventListener('error', error => console.log(`Error: ${error.name}`));
              gyr.addEventListener('reading', () => {
                  console.log(`[doc_sensor]Gyroscope ${gyr.timestamp}, ${gyr.x}, ${gyr.y}, ${gyr.z}.`);
              });
              gyr.start();
          }

          function getAbsoluteOrientationSensor() {
              var aos = new AbsoluteOrientationSensor({frequency: 60});
              aos.addEventListener('activate', () => console.log('Ready to measure.'));
              aos.addEventListener('error', error => console.log(`Error: ${error.name}`));
              aos.addEventListener('reading', () => {
                  console.log(`AbsoluteOrientationSensor data: ${ros.timestamp}, ${ros.quaternion}`);
              });
              aos.start();
          }

          function listenDeviceMotionEvent() {
              removeDeviceMotionEvent();
              if ('DeviceMotionEvent' in window) {
                  window.addEventListener('devicemotion', handleMotionEvent, false);
              } else {
                console.log ("DeviceMotionEvent is not supported.");
              }
          }

          function removeDeviceMotionEvent() {
              if ('DeviceMotionEvent' in window) {
                window.removeEventListener('devicemotion', handleMotionEvent, false);
              } else {
                console.log ("DeviceOrientationEvent is not supported.");
              }
          }

          function handleMotionEvent(event) {
              const x = event.accelerationIncludingGravity.x;
              const y = event.accelerationIncludingGravity.y;
              const z = event.accelerationIncludingGravity.z;
              console.log(`DeviceMotionEvent data: ${event.timeStamp}, ${x}, ${y}, ${z}`);
          }

          function listenDeviceOrientationEvent() {
              removeDeviceOrientationEvent();
              if ('DeviceOrientationEvent' in window) {
                  window.addEventListener('deviceorientation', handleOrientationEvent, false);
              } else {
                  console.log ("DeviceOrientationEvent is not supported.");
              }
          }

          function removeDeviceOrientationEvent() {
              if ('DeviceOrientationEvent' in window) {
                window.removeEventListener('deviceorientation', handleOrientationEvent, false);
              } else {
                console.log ("DeviceOrientationEvent is not supported.");
              }
          }

          function listenDeviceOrientationEvent2() {
              removeDeviceOrientationEvent2();
              if ('DeviceOrientationEvent' in window) {
                  window.addEventListener('deviceorientationabsolute', handleOrientationEvent, false);
              } else {
                  console.log ("DeviceOrientationEvent is not supported.");
              }
          }

          function removeDeviceOrientationEvent2() {
              if ('DeviceOrientationEvent' in window) {
                window.removeEventListener('deviceorientationabsolute', handleOrientationEvent, false);
              } else {
                console.log ("DeviceOrientationEvent is not supported.");
              }
          }

          function handleOrientationEvent(event) {
              console.log(`DeviceOrientationEvent data: ${event.timeStamp}, ${event.absolute}, ${event.alpha}, ${event.beta}, ${event.gamma}`);
          }
      </script>
  </head>
  <body>
  <div id="dcontent" class="dcontent">
      <h3>Motion and direction:</h3>
      <ul class="dlist">
          <li><button type="button" onclick="getAccelerometer()">Acceleration</button></li>;
          <li><button type="button" onclick="getGyroscope()">Gyroscope</button></li>
          <li><button type="button" onclick="getAbsoluteOrientationSensor()">Device orientation (absolute positioning) </button></li>;
          <li><button type="button" onclick="listenDeviceMotionEvent()">Device motion event</button></li>;
          <li><button type="button" onclick="listenDeviceOrientationEvent()">Device orientation event</button></li>;
          <li><button type="button" onclick="listenDeviceOrientationEvent2()">Device orientation event (absolute positioning) </button></li>;
      </ul>
  </div>
  </body>
  </html>
  ```
