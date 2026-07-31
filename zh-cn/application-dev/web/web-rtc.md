# 在Web中打开摄像头和麦克风
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @qq_42700029-->
<!--Designer: @gzweioh-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebRTC（Web Real-Time Communications）是一项实时通讯技术，它允许网络应用或站点在无需中间媒介的情况下建立浏览器之间的点对点（Peer-to-Peer）连接，实现视频流、音频流或其他任意数据的传输。WebRTC所包含的标准使得用户无需安装任何插件或第三方软件即可创建点对点（Peer-to-Peer）的数据共享与音视频会议。WebRTC技术适用于所有现代浏览器和主要平台的本机客户端，其背后的技术作为开放的Web标准实现，并在所有主要浏览器中作为常规JavaScript API提供。

## 申请权限

Web组件可以通过W3C标准协议接口访问摄像头和麦克风，通过[onPermissionRequest](../reference/apis-arkweb/arkts-basic-components-web-events.md#onpermissionrequest9)接口接收权限请求通知，需在配置文件中声明相应的音视频权限并且进行系统侧授权与应用侧授权。

### 在module.json5配置权限
- 使用摄像头和麦克风功能前请在module.json5中添加音视频相关权限，权限的添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md#在配置文件中声明权限)。

  ```json5
    // src/main/resources/base/element/string.json
    "string":[
      {
        "name": "reason_for_camera",
        "value": "reason_for_camera"
      },
      {
        "name": "reason_for_microphone",
        "value": "reason_for_microphone"
      }
    ]
  ```

  ```json5
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

通过在JavaScript中调用W3C标准协议接口navigator.mediaDevices.getUserMedia()，该接口用于打开摄像头和麦克风。constraints参数是一个包含了video和audio两个成员的MediaStreamConstraints对象，用于说明请求的媒体类型。

### 系统侧授权
参考[完整示例代码](../web/web-rtc.md#完整示例代码)中，调用requestPermissionsFromUser，使得进入应用后会弹出是否允许该应用访问摄像头和麦克风的授权框，需点击"始终允许"或"每次使用时询问"按钮，授权应用访问摄像头和麦克风。

### 应用侧授权
参考[完整示例代码](../web/web-rtc.md#完整示例代码)中，点击前端界面中的"开启摄像头"按钮后会通过onPermissionRequest触发权限请求，在弹出的对话框中单击"onConfirm"按钮后，打开摄像头和麦克风。

## 完整示例代码

  <!-- @[click_button_to_turn_on_camera_microphone](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/UsingWebMultimedia/entry/src/main/ets/pages/Index.ets) --> 
  
  ``` TypeScript
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
      // 获取摄像头和麦克风权限，在组件创建时主动申请权限。
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

- 前端界面index.html代码。

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

<!--RP1-->
<!--RP1End-->