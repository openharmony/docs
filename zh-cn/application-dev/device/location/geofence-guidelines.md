# 地理围栏开发指导

## 场景概述

地理围栏就是虚拟地理边界，当设备进入、离开某个特定地理区域时，可以接收自动通知和警告。

目前仅支持圆形围栏，并且依赖GNSS芯片的地理围栏功能，仅在室外开阔区域才能准确识别用户进出围栏事件。

应用场景举例：开发者可以使用地理围栏，在企业周围创建一个区域进行广告定位，在不同的地点，在移动设备上进行有针对性的促销优惠。

## 接口说明

地理围栏所使用的接口如下，详细说明参见：[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)。

**表4** 地理围栏接口介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| [on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerongnssfencestatuschange) | 添加一个围栏，并订阅地理围栏事件。 | 
| [off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageroffgnssfencestatuschange) | 删除一个围栏，并取消订阅该围栏事件。 | 

## 开发步骤

1. 使用地理围栏功能，需要有权限ohos.permission.APPROXIMATELY_LOCATION，位置权限申请的方法和步骤见[申请位置权限开发指导](location-permission-guidelines.md)。

2. 导入geoLocationManager模块、wantAgent模块和BusinessError模块。
   
   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   import { wantAgent } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit'
   ```

3. 创建WantAgentInfo信息。

   场景一：创建拉起Ability的WantAgentInfo信息。

   ```ts
   // 通过WantAgentInfo的operationType设置动作类型
   let wantAgentInfo:wantAgent.WantAgentInfo = {
       wants: [
           {
               deviceId: '',
               bundleName: 'com.example.myapplication',
               abilityName: 'EntryAbility',
               action: '',
               entities: [],
               uri: '',
               parameters: {}
           }
       ],
       operationType: wantAgent.OperationType.START_ABILITY,
       requestCode: 0,
       wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
   };
   ```

   场景二：创建发布公共事件的WantAgentInfo信息。

   ```ts
   // 通过WantAgentInfo的operationType设置动作类型
   let wantAgentInfo:wantAgent.WantAgentInfo = {
       wants: [
           {
               action: 'event_name', // 设置事件名
               parameters: {},
           }
       ],
       operationType: wantAgent.OperationType.SEND_COMMON_EVENT,
       requestCode: 0,
       wantAgentFlags: [wantAgent.WantAgentFlags.CONSTANT_FLAG],
   }
   ```

4. 调用getWantAgent()方法进行创建WantAgent。

   并且在获取到WantAgent对象之后调用地理围栏接口添加围栏，当设备进入或者退出该围栏时，系统会自动触发WantAgent的动作。

   ```ts
   let wantAgentObj : object | undefined = undefined;
   // 创建WantAgent
   wantAgent.getWantAgent(wantAgentInfo, (err, data) => {
       if (err) {
         console.error('getWantAgent err=' + JSON.stringify(err));
         return;
       }
       console.info('getWantAgent success');
       wantAgentObj = data;
       let requestInfo:geoLocationManager.GeofenceRequest = {'scenario': 0x301, "geofence": {"latitude": 31.12, "longitude": 121.11, "radius": 100, "expiration": 10000}};
       try {
           geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
       } catch (err) {
           console.error("errCode:" + JSON.stringify(err));
       }
   });
   ```
