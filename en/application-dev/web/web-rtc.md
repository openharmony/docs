# Holding a Video Conference with WebRTC

The **\<Web>** component can start a camera and microphone by calling **navigator.mediaDevices.getUserMedia()**, a standard W3C API, in JavaScript. To call this API, you need to declare the **ohos.permission.CAMERA** and **ohos.permission.MICROPHONE** permissions.

 The **constraints** parameter in the API is a **MediaStreamConstraints** object that specifies the types of media to request. It contains two members: **video** and **audio**.

In the following example, when a user clicks the button for enabling the camera on the frontend page (**index.html**), the **\<Web>** component starts the camera and microphone.

- Application code:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { abilityAccessCtrl } from '@kit.AbilityKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController()

    aboutToAppear() {
      // Enable web frontend page debugging.
      webview.WebviewController.setWebDebuggingAccess(true);
      let atManager = abilityAccessCtrl.createAtManager();
      atManager.requestPermissionsFromUser(getContext(this), ['ohos.permission.CAMERA', 'ohos.permission.MICROPHONE'])
        .then(data => {
          let result: Array<number> = data.authResults;
          let hasPermissions1 = true;
          result.forEach(item => {
            if (item === -1) {
              hasPermissions1 = false;
            }
          })
          if (hasPermissions1) {
            console.info("hasPermissions1");
          } else {
            console.info(" not hasPermissions1");
          }
        }).catch(() => {
        return;
      });
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
  <video id="video" width="500px" height="500px" autoplay="autoplay"></video>
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
      promise.then(function (MediaStream) {
        video.srcObject = MediaStream;
        video.play();
      });
    }
  </script>
  </body>
  </html>
  ```
