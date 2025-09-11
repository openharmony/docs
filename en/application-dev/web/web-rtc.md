# Starting a Camera and Microphone
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @qq_42700029-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Web Real-Time Communications (WebRTC) is a real-time communication technology that allows network applications or sites to establish peer-to-peer (P2P) connections between browsers without an intermediary, implementing the transmission of video streams, audio streams, or other data. It enables users to create peer-to-peer (P2P) data sharing and conference calls without installing any plug-in or third-party software. WebRTC is applicable to all modern browsers and native clients on major platforms. The underlying technology is implemented as an open web standard and provided as a common JavaScript API in all major browsers.

The **Web** component can start a camera and microphone by calling the W3C Standards-compliant API **navigator.mediaDevices.getUserMedia()** in JavaScript, and receive the permission request notification through [onPermissionRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpermissionrequest9). To call these APIs, you need to declare the audio permissions in the **module.json5** file.

- For details about how to add audio permissions, see [Declaring Permissions in the Configuration File](../security/AccessToken/declare-permissions.md).

   ```json
    // src/main/resources/base/element/string.json
    {
      "name": "reason_for_camera",
      "value": "reason_for_camera"
    },
    {
      "name": "reason_for_microphone",
      "value": "reason_for_microphone"
    }
  ```

  ```json
    // src/main/module.json5
    "requestPermissions":[
      {
        "name" : "ohos.permission.CAMERA",
        "reason": "$string:reason_for_camera",
        "usedScene": {
          "abilities": [
            "EntryAbility"
          ],
          "when":"inuse"
        }
      },
      {
        "name" : "ohos.permission.MICROPHONE",
        "reason": "$string:reason_for_microphone",
        "usedScene": {
          "abilities": [
            "EntryAbility"
          ],
          "when":"inuse"
        }
      }
    ]
   ```

Invoke the **navigator.mediaDevices.getUserMedia()** API in JavaScript to start the camera and microphone. The **constraints** parameter in the API is a **MediaStreamConstraints** object that specifies the types of media to request. It contains two members: **video** and **audio**.

In the following example, when a user clicks the button for enabling the camera on the frontend page and the **onConfirm** button, the **Web** component starts the camera and microphone.

- Application code:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { abilityAccessCtrl } from '@kit.AbilityKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    aboutToAppear() {
      // Enable web frontend page debugging.
      webview.WebviewController.setWebDebuggingAccess(true);
      // Obtain the permission request notification. After the onConfirm button is clicked, the camera and microphone are started.
      let atManager = abilityAccessCtrl.createAtManager();
      atManager.requestPermissionsFromUser(this.uiContext.getHostContext(), ['ohos.permission.CAMERA', 'ohos.permission.MICROPHONE'])
        .then((data) => {
          console.info('data:' + JSON.stringify(data));
          console.info('data permissions:' + data.permissions);
          console.info('data authResults:' + data.authResults);
        }).catch((error: BusinessError) => {
        console.error(`Failed to request permissions from user. Code is ${error.code}, message is ${error.message}`);
      })
    }

    build() {
      Column() {
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .onPermissionRequest((event) => {
            if (event) {
              this.uiContext.showAlertDialog({
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
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
  </head>
  <body>
  <video id="video" width="500px" height="500px" autoplay></video>
  <canvas id="canvas" width="500px" height="500px"></canvas>
  <br>
  <input type="button" title="HTML5 Camera" value="Enable Camera" onclick="getMedia()"/>
  <script>
    function getMedia()
    {
      let constraints = {
        video: {width: 500, height: 500},
        audio: true
      };
      // Obtain the video camera area.
      let video = document.getElementById("video");
      // Returned Promise object
      let promise = navigator.mediaDevices.getUserMedia(constraints);
      // then() is asynchronous. Invoke the MediaStream object as a parameter.
      promise.then(function(MediaStream) {
        video.srcObject = MediaStream;
        video.play();
      }).catch(function(err) {
    	  console.info(err.name + ": " + err.message);
      });
    }
  </script>
  </body>
  </html>
  ```
