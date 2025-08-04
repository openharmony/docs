# 管理位置权限
<!--Kit: ArkWeb-->
<!--Subsystem: ArkWeb-->
<!--Owner: @zhang-yinglie-->
<!--SE: @handyohos-->
<!--TSE: @ghiker-->


Web组件提供位置权限管理能力（<!--RP1-->[隐私保护说明](../../device-dev/security/security-privacy-protection.md)<!--RP1End-->）。开发者可以通过[onGeolocationShow()](../reference/apis-arkweb/arkts-basic-components-web-events.md#ongeolocationshow)接口对某个网站进行位置权限管理。Web组件根据接口响应结果，决定是否赋予前端页面权限。

- 使用获取设备位置功能前请在module.json5中添加位置相关权限，权限的添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md)。

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

在下面的示例中，用户点击前端页面"获取位置"按钮，Web组件通过弹窗的形式通知应用侧位置权限请求消息。


- 前端页面代码。

  ```html
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>位置信息</title>
  </head>
  <body>
      <p id="locationInfo">位置信息</p>
      <button onclick="getLocation()">获取位置</button>

      <script>
          var locationInfo=document.getElementById("locationInfo");
          function getLocation(){
              if (navigator.geolocation) {
                  // 前端页面访问设备地理位置
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


- 应用代码。

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
      if (!context) {
        console.error("context is undefined");
        return;
      }
      // 向用户请求位置权限设置。
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
          .onGeolocationShow((event) => { // 地理位置权限申请通知
             this.uiContext.showAlertDialog({
              title: '位置权限请求',
              message: '是否允许获取位置信息',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  if (event) {
                    event.geolocation.invoke(event.origin, false, false); // 不允许此站点地理位置权限请求
                  }
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  if (event) {
                    event.geolocation.invoke(event.origin, true, false); // 允许此站点地理位置权限请求
                  }
                }
              },
              cancel: () => {
                if (event) {
                  event.geolocation.invoke(event.origin, false, false); // 不允许此站点地理位置权限请求
                }
              }
            })
          })
      }
    }
  }
  ```
