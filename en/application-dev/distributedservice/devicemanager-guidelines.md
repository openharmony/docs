# Distributed Device Management Development
<!--Kit: Distributed Service Kit-->
<!--Subsystem: DistributedHardware-->
<!--Owner: @hwzhangchuang-->
<!--Designer: @hwzhangchuang-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->

## Introduction

As users own an increasing number of different types of terminal devices, distributed services allow one device to use the capabilities of other devices as an extension of its own capabilities so that devices can collaborate to complete complex service scenarios.

Distributed device management serves as the entry to distributed services and provides unified management of nearby trusted and untrusted devices in distributed service scenarios.

Distributed device management provides the following four capabilities:

- **Discovering devices**<br/>
  Discovers and reports nearby terminal devices. Nearby devices must be connected to the same LAN or have Bluetooth enabled at the same time.

- **Binding a device**<br/>
  Trust between devices is the prerequisite for devices to work together in distributed service scenarios. For nearby untrusted devices that are discovered, you can bind them to establish a trusted relationship. The framework provides device authentication capabilities such as PIN-based pairing, touch-to-pair, scan-to-pair, and proximity-based pairing, and supports integration with different authentication interaction APIs.

- **Querying device information**<br/>
  Queries local device information, nearby online trusted devices, and trusted device information.
  
- **Listening for devices**<br/>
  Listens for device online and offline events. When a device goes online, the devices have become trusted and distributed operations can be initiated. When a device goes offline, distributed services are unavailable.

### Working Principles

  As the entry to distributed services, device management requires the application to actively initiate binding to discovered devices in the corresponding service scenario to establish a trusted relationship. After the service ends, the application decides whether to remove the binding relationship. The application itself controls whether the trusted relationship between devices is released.

### Constraints

  To use device management capabilities, the user must ensure that the devices are connected to the same LAN or that Bluetooth is enabled. Otherwise, the capability is unavailable.

  Device information is sensitive user data. Therefore, even if the devices are already connected to the same LAN or Bluetooth is enabled, the application must still request the data synchronization permission from the user before obtaining device information. Only after the user grants the permission does the system provide device management capabilities to the application.

<!--RP1-->
<!--RP1End-->

## Requesting Permissions

### Scenario

Before using distributed device management capabilities, the application must check whether it has obtained user authorization to access distributed data synchronization information. If authorization has not been granted, the application can request the required permission from the user.

`ohos.permission.DISTRIBUTED_DATASYNC`: permission for distributed data synchronization

To use device management capabilities, you must request this permission and obtain user authorization.

### How to Develop

This topic applies to the Stage model.

1. Declare the `ohos.permission.DISTRIBUTED_DATASYNC` permission in the `module.json5` configuration file.

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
2. Import the `abilityAccessCtrl` module to obtain the permission request capability.

   ```ts
   import { abilityAccessCtrl } from '@kit.AbilityKit';
   ```

3. Authorization for distributed data synchronization is granted in `user_grant` mode. Therefore, call [requestPermissionsFromUser9+](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to request authorization from the user through a dynamic dialog box.

   <!-- @[permissions_user_grant](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DistributedAppDev/DistributedAuthentication/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   let atManager = abilityAccessCtrl.createAtManager();
   atManager.requestPermissionsFromUser(context, ['ohos.permission.DISTRIBUTED_DATASYNC'])
     .then(async (data) => {
       logger.info(`data: ${JSON.stringify(data)}`);
       // ...
     })
     .catch((err: BusinessError) => {
       logger.error(`requestPermissionsFromUser error: ${JSON.stringify(err)}`);
     });
   ```


## Discovering Devices

### Scenario

Developers can call the device discovery APIs to obtain nearby available devices.

### Available APIs

startDiscovering(discoverParam: {[key:&nbsp;string]:&nbsp;Object;} , filterOptions?: {[key:&nbsp;string]:&nbsp;Object;} ): void;

Discovers devices on the same LAN or with Bluetooth enabled. For details, see [startDiscovering](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#startdiscovering).


### How to Develop

1. Request the distributed data synchronization permission.

2. Import the `distributedDeviceManager` module, which provides all device management APIs.
   
   ```ts
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
   ```

3. Import the `BusinessError` module, which provides the error codes thrown by the APIs in the `distributedDeviceManager` module.
   
   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

4. Create a device management instance, which serves as the entry for calling distributed device management APIs.

   <!-- @[create_device_manager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DistributedAppDev/DistributedAuthentication/entry/src/main/ets/model/RemoteDeviceModel.ets) -->
   
   ``` TypeScript
   async createDeviceManager(): Promise<void> {
     if (typeof (this.deviceManager) != 'undefined') {
       return;
     }
   
     logger.info('[DeviceManager.RemoteDeviceModel] deviceManager.createDeviceManager begin');
     try {
       let dmInstance = distributedDeviceManager.createDeviceManager('com.samples.devicemanager');
       this.deviceManager = dmInstance
       // ...
       logger.info(`[DeviceManager.RemoteDeviceModel] createDeviceManager callback returned,
       value= ${JSON.stringify(this.deviceManager)}`);
     } catch (err) {
       let error: BusinessError = err as BusinessError;
       logger.error(`[DeviceManager.RemoteDeviceModel] createDeviceManager throw error,
       error=${error} message=${error.message}`);
     }
     logger.info('[DeviceManager.RemoteDeviceModel] distributedDeviceManager.createDeviceManager end');
   }
   ```

5. Register callbacks for device discovery and call the discovery API to discover nearby devices. Discovery lasts for 2 minutes. After 2 minutes, discovery stops automatically. Up to 99 devices can be discovered.
   
   <!-- @[start_discovering](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DistributedAppDev/DistributedAuthentication/entry/src/main/ets/model/RemoteDeviceModel.ets) -->
   
   ``` TypeScript
   startDeviceDiscovery(): void {
     if (typeof (this.deviceManager) == 'undefined') {
       logger.error('[DeviceManager.RemoteDeviceModel] deviceManager has not initialized');
       this.showErrMsg('deviceManager has not initialized');
       return;
     }
     let self = this;
     try {
       this.deviceManager.on('discoverSuccess', (data) => {
         if (data == null) {
           return;
         }
         logger.info('[DeviceManager.RemoteDeviceModel] deviceFound data=' + JSON.stringify(data));
         self.deviceFound(data);
       })
       this.deviceManager.on('discoverFailure', (data) => {
         logger.info('[DeviceManager.RemoteDeviceModel] discoverFail data=' + JSON.stringify(data));
       })
       // ...
       let discoverParam: Record<string, number> = {
         'discoverTargetType': 1
       };
       let filterOptions: Record<string, number> = this.getFilterOptions();
       logger.info('[DeviceManager.RemoteDeviceModel] startDeviceDiscovery filterOptions = ' + JSON.stringify(filterOptions));
       if (Object.entries(filterOptions).length == 0) {
         this.deviceManager.startDiscovering(discoverParam);
       } else {
         this.deviceManager.startDiscovering(discoverParam, filterOptions);
       }
     } catch (err) {
       let e: BusinessError = err as BusinessError;
       logger.error('[DeviceManager.RemoteDeviceModel] startDeviceDiscovery failed err: ' + e.toString());
     }
   }
   ```


6. When discovery ends or the page exits, call the API for stopping discovery to release the discovery listeners.

   <!-- @[stop_discovering](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DistributedAppDev/DistributedAuthentication/entry/src/main/ets/model/RemoteDeviceModel.ets) -->
   
   ``` TypeScript
   stopDeviceDiscovery(): void {
     if (typeof (this.deviceManager) == 'undefined') {
       logger.error('[DeviceManager.RemoteDeviceModel] deviceManager has not initialized');
       this.showErrMsg('deviceManager has not initialized');
       return;
     }
     logger.info('[DeviceManager.RemoteDeviceModel] stopDeviceDiscovery');
     try {
       this.deviceManager.stopDiscovering();
       this.deviceManager.off('discoverSuccess');
       this.deviceManager.off('discoverFailure');
     } catch (e) {
       logger.error('[DeviceManager.RemoteDeviceModel] stopDeviceDiscovery failed err: ' + e.toString());
     }
   }
   ```

## Binding a Device

### Scenario

After discovering nearby untrusted devices, developers can establish a trusted relationship by using the binding API.

### Available APIs

bindTarget(deviceId: string, bindParam: {[key:&nbsp;string]:&nbsp;Object;} , callback: AsyncCallback&lt;{deviceId: string;}>): void;

Binds a device. For details, see [bindTarget](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#bindtarget).

### How to Develop

1. Request the distributed data synchronization permission.

2. Discover nearby untrusted devices.
   
3. Select the untrusted device ID and initiate device binding.

   <!-- @[bind_target](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DistributedAppDev/DistributedAuthentication/entry/src/main/ets/model/RemoteDeviceModel.ets) -->
   
   ``` TypeScript
   authenticateDevice(device: distributedDeviceManager.DeviceBasicInfo): void {
     logger.info('[DeviceManager.RemoteDeviceModel] authenticateDevice ' + JSON.stringify(device));
     if (typeof (this.deviceManager) == 'undefined') {
       logger.error('[DeviceManager.RemoteDeviceModel] deviceManager has not initialized');
       this.showErrMsg('deviceManager has not initialized');
       return;
     }
   
     for (let i = 0; i < this.discoverList.length; i++) {
       if (this.discoverList[i].deviceId != device.deviceId) {
         continue;
       }
   
       let bindParam: Record<string, number | string> = {
         'bindLevel': 3,
         'bindType': 1, // PIN-based authentication
         'targetPkgName': 'ohos.samples.etsdevicemanager',
         'appName': 'DeviceManager',
       };
       try {
         this.deviceManager.bindTarget(device.deviceId, bindParam, (err: BusinessError, data: Object) => {
           if (err) {
             logger.error('[DeviceManager.RemoteDeviceModel] authenticateDevice error:' + JSON.stringify(err));
             return;
           }
           logger.info('[DeviceManager.RemoteDeviceModel] authenticateDevice succeed:' + JSON.stringify(data));
         })
       } catch (err) {
         let e: BusinessError = err as BusinessError;
         logger.error('[DeviceManager.RemoteDeviceModel] authenticateDevice failed err: ' + e.toString());
       }
     }
   }
   ```



## Querying Device Information

### Scenario

After a trusted relationship is established between devices, the device information query API can be used to obtain all nearby devices that are online and trusted.

### Available APIs

getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;;

Queries device information. For details, see [getAvailableDeviceListSync](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

### How to Develop

1. Request the distributed data synchronization permission.

2. Discover nearby untrusted devices.
   
3. Establish a trusted relationship between devices.

4. Query nearby devices that are online and trusted.

   <!-- @[get_available_device_list](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DistributedAppDev/DistributedAuthentication/entry/src/main/ets/model/RemoteDeviceModel.ets) -->
   
   ``` TypeScript
   getTrustedDeviceList(): void {
     if (typeof (this.deviceManager) == 'undefined') {
       logger.error('[DeviceManager.RemoteDeviceModel] deviceManager has not initialized');
       this.showErrMsg('deviceManager has not initialized');
       return;
     }
   
     logger.info('[DeviceManager.RemoteDeviceModel] getTrustedDeviceList begin');
     try {
       this.trustedDeviceList = this.deviceManager.getAvailableDeviceListSync();
       // ...
     } catch (error) {
       logger.error('[DeviceManager.RemoteDeviceModel] getTrustedDeviceList error: ${error}' + error.toString());
       this.showErrMsg('getTrustedDeviceList failed');
     }
   }
   ```



## Listening for Device Online/Offline Status

### Scenario

When a nearby trusted device becomes available, the service receives an online notification. When the device becomes unavailable, the service receives an offline notification.

### Available APIs

on(type: 'deviceStateChange', callback: Callback&lt;{ action: DeviceStateChange; device: DeviceBasicInfo; }&gt;): void;

Listens for device online and offline status. For details, see [on('deviceStateChange')](../reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md#ondevicestatechange).

### How to Develop

1. Request the distributed data synchronization permission.

2. Import the `distributedDeviceManager` module, which provides all device management APIs.
   
   ```ts
   import { distributedDeviceManager } from '@kit.DistributedServiceKit';
   ```

3. Import the `BusinessError` module, which provides the error codes thrown by the APIs in the `distributedDeviceManager` module.
   
   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

4. Create a device management instance, which serves as the entry for calling distributed device management APIs, and register callbacks for device online and offline events.

   <!-- @[device_state_change](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/DistributedAppDev/DistributedAuthentication/entry/src/main/ets/model/RemoteDeviceModel.ets) -->
   
   ``` TypeScript
   registerDeviceStateListener(): void {
     logger.info('[DeviceManager.RemoteDeviceModel] registerDeviceStateListener');
     if (typeof (this.deviceManager) == 'undefined') {
       logger.error('[DeviceManager.RemoteDeviceModel] deviceManager has not initialized');
       this.showErrMsg('deviceManager has not initialized');
       return;
     }
   
     // ...
     try {
       this.deviceManager.on('deviceStateChange', (data: dataType) => {
         if (data == null) {
           return;
         }
         logger.info('[DeviceManager.RemoteDeviceModel] deviceStateChange data=' + JSON.stringify(data));
         switch (data.action) {
           case distributedDeviceManager.DeviceStateChange.AVAILABLE:
             logger.info('[DeviceManager.RemoteDeviceModel] deviceStateChange ONLINE');
             // ...
             break;
           case distributedDeviceManager.DeviceStateChange.UNAVAILABLE:
             logger.info('[DeviceManager.RemoteDeviceModel] deviceStateChange OFFLINE');
             // ...
             break;
           default:
             break;
         }
       })
     } catch(err) {
       let e: BusinessError = err as BusinessError;
       logger.error('[DeviceManager.RemoteDeviceModel] deviceStateChange failed err: ' + e.toString());
     }
   }
   ```
