# 使用WebRTC进行Web视频会议

Web组件可以通过W3C标准协议接口拉起摄像头和麦克风，通过[onPermissionRequest](../reference/apis-arkweb/ts-basic-components-web.md#onpermissionrequest9)接口接收权限请求通知，需在配置文件中声明相应的音频权限。

- 使用摄像头和麦克风功能前请在module.json5中添加音频相关权限，权限的添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md)。

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
    ],
   ```

通过在JavaScript中调用W3C标准协议接口navigator.mediaDevices.getUserMedia()，该接口用于拉起摄像头和麦克风。constraints参数是一个包含了video和audio两个成员的MediaStreamConstraints对象，用于说明请求的媒体类型。

在下面的示例中，点击前端页面中的开启摄像头按钮再点击onConfirm，打开摄像头和麦克风。

- 应用侧代码。

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
      // 配置Web开启调试模式
      webview.WebviewController.setWebDebuggingAccess(true);
      // 获取权限请求通知，点击onConfirm按钮后，拉起摄像头和麦克风。
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

- 前端页面index.html代码。

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
  <input type="button" title="HTML5摄像头" value="开启摄像头" onclick="getMedia()"/>
  <script>
    function getMedia()
    {
      let constraints = {
        video: {width: 500, height: 500},
        audio: true
      };
      // 获取video摄像头区域
      let video = document.getElementById("video");
      // 返回的Promise对象
      let promise = navigator.mediaDevices.getUserMedia(constraints);
      // then()异步，调用MediaStream对象作为参数
      promise.then(function (MediaStream) {
        video.srcObject = MediaStream;
        video.play();
      });
    }
  </script>
  </body>
  </html>
  ```