# 管理位置权限
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhang-yinglie-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

从API version 9开始，支持Web组件的[GeolocationPermissions](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md)类和[onGeolocationShow](../reference/apis-arkweb/arkts-basic-components-web-events.md#ongeolocationshow)方法对网页进行位置权限管理。更多信息请参见<!--RP1-->[隐私保护说明](../../device-dev/security/security-privacy-protection.md)<!--RP1End-->。

Web组件根据[GeolocationPermissions](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md)类和[onGeolocationShow](../reference/apis-arkweb/arkts-basic-components-web-events.md#ongeolocationshow)方法的响应结果，决定是否赋予前端页面权限。用户可以获取位置信息，以便使用出行导航、天气预报等服务。

## 需要权限
使用获取位置功能，需在module.json5中配置位置权限。具体添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md#在配置文件中声明权限)。

   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.LOCATION" // 精准定位
      },
      {
        "name" : "ohos.permission.APPROXIMATELY_LOCATION" // 模糊定位
      },
      {
        "name" : "ohos.permission.LOCATION_IN_BACKGROUND" // 后台定位
      }
    ]
   ```

## 申请位置权限
在下面的示例中，用户点击前端页面"获取位置"按钮，Web组件通过弹窗通知应用侧位置权限请求消息。


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
                  // 访问设备地理位置
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
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { abilityAccessCtrl, common } from '@kit.AbilityKit';

  let atManager = abilityAccessCtrl.createAtManager();

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    uiContext: UIContext = this.getUIContext();

    // 组件的生命周期函数，创建组件实例后触发
    aboutToAppear(): void {
      let context : Context | undefined = this.uiContext.getHostContext() as common.UIAbilityContext;
      if (!context) {
        console.error("context is undefined");
        return;
      }
      // 向用户请求位置权限，对整个应用生效
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
        // Web组件的geolocationAccess属性默认为true，可以显式配置为false以禁止Web组件获取地理位置信息
        Web({ src: $rawfile('getLocation.html'), controller: this.controller })
          .geolocationAccess(true)
          .onGeolocationShow((event) => {
            // 位置权限申请通知仅对当前Web组件生效，应用内的其他Web组件不受影响
            this.uiContext.showAlertDialog({
              title: '位置权限请求',
              message: '是否允许获取位置信息',
              primaryButton: {
                value: 'cancel',
                action: () => {
                  if (event) {
                    // 不允许此站点位置权限请求
                    // 注意invoke的第3个参数表示是否记住当前选择，如果传true，则下次不再弹框
                    event.geolocation.invoke(event.origin, false, false);
                  }
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  if (event) {
                    // 允许此站点位置权限请求
                    // 注意invoke的第3个参数表示是否记住当前选择，如果传true，则下次不再弹框
                    event.geolocation.invoke(event.origin, true, false);
                  }
                }
              },
              cancel: () => {
                if (event) {
                  // 不允许此站点位置权限请求
                  // 注意invoke的第3个参数表示是否记住当前选择，如果传true，则下次不再弹框
                  event.geolocation.invoke(event.origin, false, false);
                }
              }
            })
          })
      }
    }
  }
  ```

## 管理位置权限
通过Web组件的[GeolocationPermissions](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md)类管理网页的位置权限，提供了新增（[allowgeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#allowgeolocation)）、查看（[getaccessiblegeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#getaccessiblegeolocation)）和删除（[deleteallgeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#deleteallgeolocation)）网页位置权限的方法。例如查看网页是否已申请位置权限、将网页已申请的位置权限删除。


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
      // 新增指定源的位置权限，再次获取位置信息时则不再触发onGeolocationShow的回调
      Button('allowGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.allowGeolocation(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      // 删除指定源的位置权限，再次获取位置信息时则触发onGeolocationShow的回调
      Button('deleteGeolocation')
        .onClick(() => {
          try {
            webview.GeolocationPermissions.deleteGeolocation(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      // 查询指定源的位置权限
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

      // 注意添加网络权限ohos.permission.INTERNET
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
