# 使用运动和方向传感器

Web组件可以通过W3C标准协议接口对接运动和方向相关的传感器。开发者在使用该功能中的加速度、陀螺仪及设备运动事件接口时，需在配置文件中声明相应的传感器权限。

- 使用加速度和设备运动事件接口前请在module.json5中添加加速度权限。
   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.ACCELEROMETER"
      }
    ]
   ```
- 使用陀螺仪接口前请在module.json5中添加陀螺仪权限。
   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.GYROSCOPE"
      }
    ]
   ```
传感器权限的添加方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md)。

Web组件在对接运动和方向传感器时，需配置[onPermissionRequest](../reference/apis-arkweb/ts-basic-components-web.md#onpermissionrequest9)接口，通过该接口接收权限请求通知。

通过在JavaScript中调用下面这些W3C标准协议接口，可以访问运动和方向传感器。

| 接口                      | 名称         | 是否支持 | 说明               |
| ------------------------- | ------------ | -------- | ------------------ |
| Accelerometer             | 加速度       | 支持     | -                  |
| Gyroscope                 | 陀螺仪       | 支持     | -                  |
| AbsoluteOrientationSensor | 绝对定位     | 支持     | -                  |
| RelativeOrientationSensor | 相对定位     | 不支持   | 传感器数据暂不支持 |
| DeviceMotionEvent         | 设备运动事件 | 支持     | -                  |
| DeviceOrientationEvent    | 设备方向事件 | 支持     | 可获取绝对定位方向 |

RelativeOrientationSensor受限于使用到的传感器功能暂未配置，暂不支持使用该接口监听设备相对定位方向数据。

在下面的示例中，点击index.html前端页面各种按钮，监听相应数据。

- 应用侧代码。

  ```ts
  import { webview } from '@kit.ArkWeb';
  import { abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController()
    aboutToAppear() {
      // 配置Web开启调试模式
      webview.WebviewController.setWebDebuggingAccess(true);
      // 访问控制管理, 获取访问控制模块对象。
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

- 前端页面index.html代码。

  ```html
  <!DOCTYPE HTML>
  <html>
  <head>
      <meta charset="utf-8" />
      <meta name="viewport" content="initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
      <meta name="misapplication-tap-highlight" content="no" />
      <meta name="HandheldFriendly" content="true" />
      <meta name="MobileOptimized" content="320" />
      <title>运动和方向传感器</title>
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
                console.log('不支持DeviceMotionEvent');
              }
          }

          function removeDeviceMotionEvent() {
              if ('DeviceMotionEvent' in window) {
                window.removeEventListener('devicemotion', handleMotionEvent, false);
              } else {
                console.log('不支持DeviceOrientationEvent');
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
                  console.log('不支持DeviceOrientationEvent');
              }
          }

          function removeDeviceOrientationEvent() {
              if ('DeviceOrientationEvent' in window) {
                window.removeEventListener('deviceorientation', handleOrientationEvent, false);
              } else {
                console.log('不支持DeviceOrientationEvent');
              }
          }

          function listenDeviceOrientationEvent2() {
              removeDeviceOrientationEvent2();
              if ('DeviceOrientationEvent' in window) {
                  window.addEventListener('deviceorientationabsolute', handleOrientationEvent, false);
              } else {
                  console.log('不支持DeviceOrientationEvent');
              }
          }

          function removeDeviceOrientationEvent2() {
              if ('DeviceOrientationEvent' in window) {
                window.removeEventListener('deviceorientationabsolute', handleOrientationEvent, false);
              } else {
                console.log('不支持DeviceOrientationEvent');
              }
          }

          function handleOrientationEvent(event) {
              console.log(`DeviceOrientationEvent data: ${event.timeStamp}, ${event.absolute}, ${event.alpha}, ${event.beta}, ${event.gamma}`);
          }
      </script>
  </head>
  <body>
  <div id="dcontent" class="dcontent">
      <h3>运动和方向:</h3>
      <ul class="dlist">
          <li><button type="button" onclick="getAccelerometer()">加速度</button></li>
          <li><button type="button" onclick="getGyroscope()">陀螺仪</button></li>
          <li><button type="button" onclick="getAbsoluteOrientationSensor()">设备方向(绝对定位)</button></li>
          <li><button type="button" onclick="listenDeviceMotionEvent()">设备运动事件</button></li>
          <li><button type="button" onclick="listenDeviceOrientationEvent()">设备方向事件</button></li>
          <li><button type="button" onclick="listenDeviceOrientationEvent2()">设备方向事件(绝对定位)</button></li>
      </ul>
  </div>
  </body>
  </html>
  ```
