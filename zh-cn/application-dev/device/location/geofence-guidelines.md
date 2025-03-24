# 地理围栏开发指导(ArkTS)

## 场景概述

地理围栏就是虚拟地理边界，当设备进入、离开某个特定地理区域时，可以接收自动通知和警告。

目前仅支持圆形围栏，并且依赖GNSS芯片的地理围栏功能，仅在室外开阔区域才能准确识别用户进出围栏事件。

应用场景举例：开发者可以使用地理围栏，在企业周围创建一个区域进行广告定位，在不同的地点，在移动设备上进行有针对性的促销优惠。

## 接口说明

地理围栏所使用的接口如下，详细说明参见：[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)。

| 接口名 | 功能描述 | 
| -------- | -------- |
| [addGnssGeofence(fenceRequest: GnssGeofenceRequest): Promise&lt;number&gt;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageraddgnssgeofence12) | 添加一个GNSS地理围栏，并订阅地理围栏事件。使用Promise异步回调。 | 
| [removeGnssGeofence(geofenceId: number): Promise&lt;void&gt;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerremovegnssgeofence12) | 删除一个GNSS地理围栏，并取消订阅该地理围栏事件。使用Promise异步回调。 | 

## 开发步骤

1. 使用地理围栏功能，需要有权限ohos.permission.APPROXIMATELY_LOCATION，位置权限申请的方法和步骤见[申请位置权限开发指导](location-permission-guidelines.md)。

2. 导入geoLocationManager模块、wantAgent模块和BusinessError模块。

   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { notificationManager } from '@kit.NotificationKit';
   ```

3. 创建围栏。

   ```ts
   // 通过WantAgentInfo的operationType设置动作类型
   let geofence: geoLocationManager.Geofence = {
       "latitude": 34.12, "longitude": 124.11, "radius": 10000.0, "expiration": 10000.0
   }
   ```

4. 指定APP需要监听的地理围栏事件类型，这里表示需要监听进入围栏和退出围栏事件。

   ```ts
   let transitionStatusList: Array<geoLocationManager.GeofenceTransitionEvent> = [
       geoLocationManager.GeofenceTransitionEvent.GEOFENCE_TRANSITION_EVENT_ENTER,
       geoLocationManager.GeofenceTransitionEvent.GEOFENCE_TRANSITION_EVENT_EXIT,
   ];
   ```

4. 创建GEOFENCE_TRANSITION_EVENT_ENTER、GEOFENCE_TRANSITION_EVENT_EXIT事件对应的通知对象。

   ```ts
   // GEOFENCE_TRANSITION_EVENT_ENTER事件
   let notificationRequest1: notificationManager.NotificationRequest = {
       id: 1,
       content: {
         notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
         normal: {
         title: "围栏通知",
           text: "围栏进入",
           additionalText: ""
         }
        }
   };
   // 创建GEOFENCE_TRANSITION_EVENT_EXIT事件对应的通知对象
   let notificationRequest2: notificationManager.NotificationRequest = {
     id: 2,
     content: {
       notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
       normal: {
         title: '围栏通知',
         text: '围栏退出',
         additionalText: ""
       }
     }
   };
   ```

5. 添加围栏

   ```ts
   // 把创建的通知对象存入Array中，存入顺序与transitionStatusList一致
   let notificationRequestList: Array<notificationManager.NotificationRequest> =
     [notificationRequest1, notificationRequest2];
   // 构造GNSS地理围栏请求对象gnssGeofenceRequest
   let gnssGeofenceRequest: geoLocationManager.GnssGeofenceRequest = {
     // 围栏属性，包含圆心和半径等信息
     geofence: geofence,
     // 指定APP需要监听的地理围栏事件类型
     monitorTransitionEvents: transitionStatusList,
     // 地理围栏事件对应的通知对象，该参数为可选
     notifications: notificationRequestList,
     // 用于监听围栏事件的callback
     geofenceTransitionCallback: (err : BusinessError, transition : geoLocationManager.GeofenceTransition) => {
       if (err) {
         console.error('geofenceTransitionCallback: err=' + JSON.stringify(err));
       }
       if (transition) {
         console.info("GeofenceTransition: %{public}s", JSON.stringify(transition));
     }
     }
   }
   try {
     // 添加围栏
     geoLocationManager.addGnssGeofence(gnssGeofenceRequest).then((id) => {
       // 围栏添加成功后返回围栏ID
       console.info("addGnssGeofence success, fence id: " + id);
       let fenceId = id;
     }).catch((err: BusinessError) => {
       console.error("addGnssGeofence failed, promise errCode:" + (err as BusinessError).code + 
         ",errMessage:" + (err as BusinessError).message);
     });
   } catch(error) {
       console.error("addGnssGeofence failed, err:" + JSON.stringify(error));
   }
   ```

5. 删除围栏

   ```ts
   // fenceId是在geoLocationManager.addGnssGeofence执行成功后获取的
   let fenceId = 1;
   try {
     geoLocationManager.removeGnssGeofence(fenceId).then(() => {
       console.info("removeGnssGeofence success fenceId:" + fenceId);
     }).catch((error : BusinessError) => {
       console.error("removeGnssGeofence: error=" + JSON.stringify(error));
     });
   } catch(error) {
     console.error("removeGnssGeofence: error=" + JSON.stringify(error));
   }
   ```