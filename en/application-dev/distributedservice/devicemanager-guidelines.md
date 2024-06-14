# Distributed Device Management Development

## Introduction

The distributed service allows multiple physically separated devices to be integrated into a virtual Super Device, allowing one device to control others and sharing data among devices with distributed communication capabilities.

As the entry of the distributed service, distributed device management implements unified management of trusted and untrusted devices nearby.

Distributed device management provides the following functionalities:

- **Discovering devices**<br>
  Discover and report the devices that are connected to the same LAN or have Bluetooth enabled. You can filter devices based on the device type, distance, and whether the device is trusted.

- **Binding a device**<br>
  Bind an untrusted device discovered to establish a trust relationship with each other. The device authentication framework provides a variety of authentication modes, such as PIN-based pairing, tap-to-pair, and scan-to-pair, and supports diversified authentication APIs.

- **Querying device information**<br>
  Obtain local device information, brief information about all the trusted devices, and detailed information about a trusted device.

- **Listening for devices**<br>
  Listen for online/offline status of nearby devices. If a device goes online, the device is trusted and distributed operations can be performed. If a device goes offline, the distributed service is unavailable.

### Working Principles

When discovering a device, the application initiates a request for binding the device to establish a trust relationship. When the service ends, the service determines whether to unbind the device.

### Constraints

The distributed service is available only for the devices connected to the same LAN or have Bluetooth enabled.

Device information is sensitive user data. Even if the devices are connected to the same LAN or have Bluetooth enabled, the application must request the ohos.permission.DISTRIBUTED_DATASYNC permission from the user before obtaining the device location. The system provides the device management capabilities for the application only after the user has granted the permission.

## Requesting Permissions

### Scenario

To use the distributed device management capabilities, your application must have the ohos.permission.DISTRIBUTED_DATASYNC permission, which allows application data to be exchanged between devices. This permission is a user_grant permission, which means the application must apply for user authorization.

Before using the distributed device management capabilities, the application must be checked for the required permission.

### How to Develop

The APIs used in this section are based on the stage model.

1. Declare the ohos.permission.DISTRIBUTED_DATASYNC permission in the **module.json5** file.

   ```ts
   {
     "module" : {
       "requestPermissions":[
         {
           "name" : "ohos.permission.DISTRIBUTED_DATASYNC",
           "reason": "$string:distributed_permission",
           "usedScene": {
             "abilities": [
               "MainAbility"
             ],
             "when": "inuse"
           }
         }
       ]
     }
   }
   ```
2. Import the **common** and **abilityAccessCtrl** modules.

   ```ts
   import { common, abilityAccessCtrl } from '@kit.AbilityKit';
   ```

3. Use **requestPermissionsFromUser** to request user authorization for the ohos.permission.DISTRIBUTED_DATASYNC permission.

   ```ts
   let context = getContext(this) as common.UIAbilityContext;
   let atManager = abilityAccessCtrl.createAtManager();
   try {
     atManager.requestPermissionsFromUser(context, ['ohos.permission.DISTRIBUTED_DATASYNC']).then((data) => {
       console.log('data: ' + JSON.stringify(data));
     }).catch((err: object) => {
       console.log('err: ' + JSON.stringify(err));
     })
   } catch (err) {
     console.log('catch err->' + JSON.stringify(err));
   }
   ```

## Discovering Devices

### Scenario

Discover nearby devices.

### Available APIs

startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object} ): void;

Starts to discover the devices that are in the same LAN or have Bluetooth enabled. For details, see [startDiscovering](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#startdiscovering).


### How to Develop

1. Request the ohos.permission.DISTRIBUTED_DATASYNC permission for your application.

2. Import the **distributedDeviceManager** module, which provides APIs for device management.
   
   ```ts
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
   ```

3. Import the **BusinessError** module, which provides the error codes thrown by the APIs of the **distributedDeviceManager** module.
   
   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

4. Create a **DeviceManager** instance, which is the entry for calling distributed device management APIs and registering the callback for discovering devices.

   ```ts
   try {
     let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
     dmInstance.on('discoverSuccess', data => console.log('discoverSuccess on:' + JSON.stringify(data)));
     dmInstance.on('discoverFailure', data => console.log('discoverFailure on:' + JSON.stringify(data)));
   } catch(err) {
     let e: BusinessError = err as BusinessError;
     console.error('createDeviceManager errCode:' + e.code + ',errMessage:' + e.message);
   }
   ```

5. Start to discover devices. The discovery process lasts 2 minutes, and a maximum of 99 devices can be discovered.
   
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

## Binding a Device

### Scenario

Bind an untrusted device discovered to establish a trust relationship.

### Available APIs

bindTarget(deviceId: string, bindParam: {[key:&nbsp;string]:&nbsp;Object} , callback: AsyncCallback&lt;{deviceId: string}>): void;

Binds a device. For details, see [bindTarget](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#bindtarget).

### How to Develop

1. Request the ohos.permission.DISTRIBUTED_DATASYNC permission for your application.

2. Discover devices nearby.
   
3. Bind an untrusted device.

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

## Querying Device Information

### Scenario

Obtain information about all the online and trusted devices.

### Available APIs

getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;;

Obtains information about all the available devices. For details, see [getAvailableDeviceListSync](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

### How to Develop

1. Request the ohos.permission.DISTRIBUTED_DATASYNC permission for your application.

2. Discover devices nearby.
   
3. Bind an untrust device to establish a trust relationship.

4. Obtain information about all the online and trusted devices.

   ```ts
   try {
     let deviceInfoList: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error('getAvailableDeviceListSync errCode:' + e.code + ',errMessage:' + e.message);
   }
   ```

## Listening for Device Online/Offline Status

### Scenario

You can listen for the device online/offline status. The service will be notified when a device goes offline or online.

### Available APIs

on(type: 'deviceStateChange', callback: Callback&lt;{ action: DeviceStateChange, device: DeviceBasicInfo }&gt;): void;

Listens for device online/offline status. For details, see [on('deviceStateChange')](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#ondevicestatechange).

### How to Develop

1. Request the ohos.permission.DISTRIBUTED_DATASYNC permission for your application.

2. Import the **distributedDeviceManager** module, which provides APIs for device management.
   
   ```ts
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
   ```

3. Import the **BusinessError** module, which provides the error codes thrown by the APIs of the **distributedDeviceManager** module.
   
   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

4. Create a **DeviceManager** instance.

   ```ts
   try {
     let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
     dmInstance.on('deviceStateChange', data => console.log('deviceStateChange on:' + JSON.stringify(data)));
   } catch(err) {
     let e: BusinessError = err as BusinessError;
     console.error('createDeviceManager errCode:' + e.code + ',errMessage:' + e.message);
   }
   ```
