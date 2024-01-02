# 分布式设备管理开发指南

## 分布式设备管理简介

随着用户不同种类的终端设备数量不断增多，将不同设备作为本端设备能力的扩展，使设备之间协同合作完成各种复杂场景即为设备的分布式业务。

分布式设备管理是分布式业务入口，在分布式业务中对周边可信和非可信设备进行统一管理。

分布式设备管理提供如下四大功能：

- **发现**<br/>
  发现周围终端设备并上报。周围设备需要连接同局域网或者同时打开蓝牙，可以根据设备类型、距离、设备是否可信等进行筛选。

- **绑定**<br/>
  不同设备协同合作完成分布式业务的前提是设备间可信，对于周边发现的不可信设备，可通过绑定使彼此建立可信关系，提供pin码、碰、扫、靠等设备认证框架，支持对接各种认证交互接口。

- **查询**<br/>
  查询功能包含：查询本机设备信息、查询周围的在线的可信设备、查询可信设备信息。

- **监听**<br/>
  监听设备上、下线。设备上线表示设备间已经可信，业务可以发起分布式操作；设备下线表示分布业务不可用。

### 运作机制

  设备管理作为分布式业务入口，需要应用在所使用的业务场景，向发现设备主动发起绑定建立可信关系；业务结束后由业务自主判断是否解除绑定关系，设备间可信关系的解除由业务自己控制。

### 约束与限制

  使用设备管理能力，需要用户确认不同设备已连接同一局域网或者蓝牙开关已开启，否则该能力不可用。

  设备信息属于用户敏感数据，所以即使用户已连接同一局域网或者蓝牙开关已开启，应用在获取设备位置前仍需向用户申请数据同步权限。在用户确认允许后，系统才会向应用提供设备管理能力。

## 申请分布式数据同步权限开发指导

### 场景概述

应用在使用分布式设备管理系统能力前，需要检查是否已经获取用户授权访问分布式数据同步信息。如未获得授权，可以向用户申请需要的分布式数据同步权限。

- ohos.permission.DISTRIBUTED_DATASYNC：分布式数据同步权限

使用设备管理能力，必须申请权限，并且获得用户授权。

### 开发步骤

1. 导入featureAbility模块，相关窗口的API都是通过该模块提供。
  
  ```ts
   import featureAbility from '@ohos.ability.featureAbility';
  ``` 
  
2. 调用窗口API拉起用户授权弹框
  
  ```ts
   let context = featureAbility.getContext();
   context.requestPermissionsFromUser(['ohos.permission.DISTRIBUTED_DATASYNC'], 000, function(err, result){
     console.log("reqPermission" + JSON.stringify(err));
     console.log("reqPermission" + JSON.stringify(result));
   });
  ```

## 设备发现开发指导

### 场景概述

开发者可以调用DeviceManager设备发现相关接口，获取周边可用的设备。

### 接口说明

发现周边同局域网或者开启蓝牙的设备，所使用的接口说明如下，详细信息参见：[DeviceManager](../reference/apis/js-apis-distributedDeviceManager.md)。

### 开发步骤

1. 申请分布式数据同步权限[申请分布式数据同步权限开发指导](#申请分布式数据同步权限开发指导)。

2. 导入deviceManager模块，所有与设备管理相关的功能API，都是通过该模块提供的。
   
  ```ts
   import deviceManager from '@ohos.distributedDeviceManager';
  ```

3. 导入BusinessError模块，用于获取deviceManager模块相关接口抛出的错误码。
   
  ```ts
   import { BusinessError } from '@ohos.base';
  ```

4. 创建设备管理实例，设备管理实例是分布式设备管理方法的调用入口，并注册发现设备的回调。

  ```ts
   try {
     let dmInstance = deviceManager.createDeviceManager('ohos.samples.jshelloworld');
     dmInstance.on('discoverSuccess', data => this.log("discoverSuccess on:" + JSON.stringify(data)));
     dmInstance.on('discoverFail', data => this.log("discoverFail on:" + JSON.stringify(data)));
   } catch(err) {
     let e: BusinessError = err as BusinessError;
     console.error('createDeviceManager errCode:' + e.code + ',errMessage:' + e.message);
   }
  ``` 

5. 发现周边设备。发现状态持续两分钟，超过两分钟，会停止发现，最大发现数量99个。
   
  ```ts
   interface DiscoverParam {
     discoverTargetType: number;
   }
   interface FilterOptions {
     availableStatus: number;
     discoverDistance: number;
     authenticationStatus: number;
     authorizationType: number;
   }
   let discoverParam: Record<string, number> = {
     'discoverTargetType': 1
   };
   let filterOptions: Record<string, number> = {
     'availableStatus': 0
   };
   try {
     dmInstance.startDiscovering(discoverParam, filterOptions);
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error('startDiscovering errCode:' + e.code + ',errMessage:' + e.message);
   }
  ```

## 设备绑定开发指导

### 场景概述

开发者发现周边不可信设备后，通过绑定接口建立可信关系。

### 接口说明

绑定接口说明如下，详细信息参见：[DeviceManager](../reference/apis/js-apis-distributedDeviceManager.md)。

### 开发步骤

1. 申请分布式数据同步权限[申请分布式数据同步权限开发指导](#申请分布式数据同步权限开发指导)。

2. 发现周边不可信设备[设备发现开发指导](#设备发现开发指导)。
   
3. 选择不可信设备id，发起设备绑定。

  ```ts
   class Data {
     deviceId: string = '';
   }
   let deviceId = 'XXXXXXXX';
   let bindParam: Record<string, string | number> = {
     'bindType': 1, 
     'targetPkgName': 'xxxx',
     'appName': 'xxxx',
     'appOperation': 'xxxx',
     'customDescription': 'xxxx'
   };
   try {
     dmInstance.bindTarget(deviceId, bindParam, (err: BusinessError, data: Data) => {
       if (err) {
         console.error('bindTarget errCode:' + err.code + ',errMessage:' + err.message);
         return;
       }
       console.info('bindTarget result:' + JSON.stringify(data));
     });
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error('bindTarget errCode:' + e.code + ',errMessage:' + e.message);
   }
  ``` 

## 设备信息查询开发指导

### 场景概述

设备与周边设备建立可信关系后，通过设备信息查询接口可以获取所有上线并且可信的设备。

### 接口说明

设备信息查询接口说明如下，详细信息参见：[DeviceManager](../reference/apis/js-apis-distributedDeviceManager.md)。

### 开发步骤

1. 申请分布式数据同步权限[申请分布式数据同步权限开发指导](#申请分布式数据同步权限开发指导)。

2. 发现周边不可信设备[设备发现开发指导](#设备发现开发指导)。
   
3. 建立设备间的可信关系[设备绑定开发指导](#设备绑定开发指导)。

4. 查询周围上线并且可行的设备

  ```ts
   try {
     let deviceInfoList: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error('getAvailableDeviceListSync errCode:' + e.code + ',errMessage:' + e.message);
   }
  ``` 

## 设备上下线监听开发指导

### 场景概述

周边可信设备可用后会给业务报上线通知，当设备不可用时会给业务报下线通知。

### 接口说明

设备上下线监听接口说明如下，详细信息参见：[DeviceManager](../reference/apis/js-apis-distributedDeviceManager.md)。

### 开发步骤

1. 申请分布式数据同步权限[申请分布式数据同步权限开发指导](#申请分布式数据同步权限开发指导)。

2. 导入deviceManager模块，所有与设备管理相关的功能API，都是通过该模块提供的。
   
   ```ts
    import deviceManager from '@ohos.distributedDeviceManager';
   ```

3. 导入BusinessError模块，用于获取deviceManager模块相关接口抛出的错误码。
   
   ```ts
    import { BusinessError } from '@ohos.base';
   ```

4. 创建设备管理实例，设备管理实例是分布式设备管理方法的调用入口，并注册设备上下线回调。

   ```ts
    try {
      let dmInstance = deviceManager.createDeviceManager('ohos.samples.jshelloworld');
      dmInstance.on('deviceStateChange', data => this.log("discoverSuccess on:" + JSON.stringify(data)));
    } catch(err) {
      let e: BusinessError = err as BusinessError;
      console.error('createDeviceManager errCode:' + e.code + ',errMessage:' + e.message);
    }
   ``` 
