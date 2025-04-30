# 使用运动和方向传感器监测设备状态

## 概述

运动和方向传感器，如加速度计、陀螺仪等，能够监测设备的运动状态和方向变化，例如设备的旋转、倾斜等。
通过W3C标准协议接口，Web组件能够访问这些传感器的数据，进而实现更加丰富的用户交互功能。例如，开发者在网页应用中可以利用加速度计识别运动模式，指导用户进行健身运动，利用陀螺仪捕获玩家手中设备的倾斜和旋转动作，实现无按钮操控的游戏体验。

通过在JavaScript中调用以下支持的W3C标准协议接口，可以访问运动和方向传感器。

| 接口                      | 名称         | 说明                                                                                                                                                     |
| ------------------------- | ------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Accelerometer             | 加速度       | 可获取设备X、Y、Z轴方向的加速度数据。                                                                                                                    |
| Gyroscope                 | 陀螺仪       | 可获取设备X、Y、Z轴方向的角速度数据。                                                                                                                    |
| AbsoluteOrientationSensor | 绝对定位     | 可获取表示设备绝对定位方向的四元数，包含X、Y、Z和W分量。                                                                                                 |
| RelativeOrientationSensor | 相对定位     | 可获取表示设备相对定位方向的四元数，包含X、Y、Z和W分量。                                                                                                 |
| DeviceMotionEvent         | 设备运动事件 | 通过监听该事件，可获取设备在X、Y、Z轴方向上的加速度数据，设备在X、Y、Z轴方向上包含重力的加速度数据，以及设备在alpha、beta、gamma轴方向上旋转的速率数据。 |
| DeviceOrientationEvent    | 设备方向事件 | 通过监听该事件，可获取设备绕X、Y、Z轴的角度。                                                                                                            |

## 需要权限

使用加速度、陀螺仪及设备运动事件接口时，需在配置文件module.json5中声明相应的传感器权限。具体配置方法请参考[在配置文件中声明权限](../security/AccessToken/declare-permissions.md)。

```
    "requestPermissions":[
      {
        "name" : "ohos.permission.ACCELEROMETER" // 加速度权限
      },
      {
        "name" : "ohos.permission.GYROSCOPE"     // 陀螺仪权限
      }
    ]
```

Web组件在对接运动和方向传感器时，需配置[onPermissionRequest](../reference/apis-arkweb/ts-basic-components-web.md#onpermissionrequest9)接口，通过该接口接收权限请求通知。

## 开发步骤

1. 应用侧代码中，Web组件配置[onPermissionRequest](../reference/apis-arkweb/ts-basic-components-web.md#onpermissionrequest9)接口，可通过[PermissionRequest](../reference/apis-arkweb/ts-basic-components-web.md#permissionrequest9)的[getAccessibleResource](../reference/apis-arkweb/ts-basic-components-web.md#getaccessibleresource9)接口获取请求权限的资源类型，当资源类型为TYPE_SENSOR时，进行传感器授权处理。

   ```ts
   import { webview } from '@kit.ArkWeb';
   import { abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController();
     uiContext: UIContext = this.getUIContext();

     aboutToAppear() {
       // 配置Web开启调试模式
       webview.WebviewController.setWebDebuggingAccess(true);
       // 访问控制管理, 获取访问控制模块对象。
       let atManager = abilityAccessCtrl.createAtManager();
       try {
         atManager.requestPermissionsFromUser(this.uiContext.getHostContext(), ['ohos.permission.ACCELEROMETER', 'ohos.permission.GYROSCOPE']
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

2. 在前端页面代码中，利用JavaScript调用传感器相关的W3C标准协议接口。

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
           // 访问设备的加速度计传感器，并获取其数据。
           function getAccelerometer() {
               var acc = new Accelerometer({frequency: 60});
               acc.addEventListener('activate', () => console.log('Ready to measure.'));
               acc.addEventListener('error', error => console.log('Error type: ' + error.type + ', error: ' + error.error ));
               acc.addEventListener('reading', () => {
                   console.log(`Accelerometer ${acc.timestamp}, ${acc.x}, ${acc.y}, ${acc.z}.`);
               });
               acc.start();
           }
   
           // 访问设备的陀螺仪传感器，并获取其数据。
           function getGyroscope() {
               var gyr = new Gyroscope({frequency: 60});
               gyr.addEventListener('activate', () => console.log('Ready to measure.'));
               gyr.addEventListener('error', error => console.log('Error type: ' + error.type + ', error: ' + error.error ));
               gyr.addEventListener('reading', () => {
                   console.log(`Gyroscope ${gyr.timestamp}, ${gyr.x}, ${gyr.y}, ${gyr.z}.`);
               });
               gyr.start();
           }
   
           // 访问设备的方向传感器，并获取其数据。
           function getAbsoluteOrientationSensor() {
               var aos = new AbsoluteOrientationSensor({frequency: 60});
               aos.addEventListener('activate', () => console.log('Ready to measure.'));
               aos.addEventListener('error', error => console.log('Error type: ' + error.type + ', error: ' + error.error ));
               aos.addEventListener('reading', () => {
                   console.log(`AbsoluteOrientationSensor data: ${aos.timestamp}, ${aos.quaternion}`);
               });
               aos.start();
           }
   
           // 监听设备的运动事件，并执行相应的处理逻辑。
           function listenDeviceMotionEvent() {
               removeDeviceMotionEvent();
               if ('DeviceMotionEvent' in window) {
                   window.addEventListener('devicemotion', handleMotionEvent, false);
               } else {
                 console.log('不支持DeviceMotionEvent');
               }
           }
   
           // 移除之前添加的设备运动事件监听器。
           function removeDeviceMotionEvent() {
               if ('DeviceMotionEvent' in window) {
                 window.removeEventListener('devicemotion', handleMotionEvent, false);
               } else {
                 console.log('不支持DeviceOrientationEvent');
               }
           }
   
           // 处理运动事件。
           function handleMotionEvent(event) {
               const x = event.accelerationIncludingGravity.x;
               const y = event.accelerationIncludingGravity.y;
               const z = event.accelerationIncludingGravity.z;
               console.log(`DeviceMotionEvent data: ${event.timeStamp}, ${x}, ${y}, ${z}`);
           }
   
           // 监听设备方向的变化，并执行相应的处理逻辑。
           function listenDeviceOrientationEvent() {
               removeDeviceOrientationEvent();
               if ('DeviceOrientationEvent' in window) {
                   window.addEventListener('deviceorientation', handleOrientationEvent, false);
               } else {
                   console.log('不支持DeviceOrientationEvent');
               }
           }
   
           // 移除之前添加的设备方向事件监听器。
           function removeDeviceOrientationEvent() {
               if ('DeviceOrientationEvent' in window) {
                 window.removeEventListener('deviceorientation', handleOrientationEvent, false);
               } else {
                 console.log('不支持DeviceOrientationEvent');
               }
           }
   
           // 监听设备方向的变化，并执行相应的处理逻辑。
           function listenDeviceOrientationEvent2() {
               removeDeviceOrientationEvent2();
               if ('DeviceOrientationEvent' in window) {
                   window.addEventListener('deviceorientationabsolute', handleOrientationEvent, false);
               } else {
                   console.log('不支持DeviceOrientationEvent');
               }
           }
   
           // 移除之前添加的设备方向事件监听器。
           function removeDeviceOrientationEvent2() {
               if ('DeviceOrientationEvent' in window) {
                 window.removeEventListener('deviceorientationabsolute', handleOrientationEvent, false);
               } else {
                 console.log('不支持DeviceOrientationEvent');
               }
           }
   
           // 处理方向事件。
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
