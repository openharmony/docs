# mDNS Management

## Overview

Multicast DNS (mDNS) provides functions such as adding, removing, discovering, and resolving local services on a LAN.
- Local service: a service provider on a LAN, for example, a printer or scanner.

Typical mDNS management scenarios include:

- Managing local services on a LAN, such as adding, removing, and resolving local services.
- Discovering local services and listening to the status changes of local services of the specified type through the **DiscoveryService** object.

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the callback mode. For details about the APIs, see [mDNS Management](../reference/apis/js-apis-net-mdns.md).

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of APIs and example code, see [mDNS Management](../reference/apis/js-apis-net-mdns.md).

| Type| API| Description|
| ---- | ---- | ---- |
| ohos.net.mdns | addLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | Adds an mDNS service. This API uses an asynchronous callback to return the result.|
| ohos.net.mdns | removeLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | Removes an mDNS service. This API uses an asynchronous callback to return the result.|
| ohos.net.mdns | createDiscoveryService(context: Context, serviceType: string): DiscoveryService | Creates a **DiscoveryService** object, which is used to discover mDNS services of the specified type.|
| ohos.net.mdns | resolveLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | Resolves an mDNS service. This API uses an asynchronous callback to return the result.|
| ohos.net.mdns.DiscoveryService | startSearchingMDNS(): void | Searches for mDNS services on the LAN.|
| ohos.net.mdns.DiscoveryService | stopSearchingMDNS(): void | Stops searching for mDNS services on the LAN.|
| ohos.net.mdns.DiscoveryService | on(type: 'discoveryStart', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | Enables listening for **discoveryStart** events.|
| ohos.net.mdns.DiscoveryService | off(type: 'discoveryStart', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void | Disables listening for **discoveryStart** events.|
| ohos.net.mdns.DiscoveryService | on(type: 'discoveryStop', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | Enables listening for **discoveryStop** events.|
| ohos.net.mdns.DiscoveryService | off(type: 'discoveryStop', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void | Disables listening for **discoveryStop** events.|
| ohos.net.mdns.DiscoveryService | on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void | Enables listening for **serviceFound** events.|
| ohos.net.mdns.DiscoveryService | off(type: 'serviceFound', callback?: Callback\<LocalServiceInfo>): void | Disables listening for **serviceFound** events.|
| ohos.net.mdns.DiscoveryService | on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void | Enables listening for **serviceLost** events.|
| ohos.net.mdns.DiscoveryService | off(type: 'serviceLost', callback?: Callback\<LocalServiceInfo>): void | Disables listening for **serviceLost** events.|

## Managing Local Services

1. Connect the device to the Wi-Fi network.
2. Import the **mdns** namespace from **@ohos.net.mdns**.
3. Call **addLocalService** to add a local service.
4. (Optional) Call **resolveLocalService** to resolve the local service for the IP address of the local network.
5. Call **removeLocalService** to remove the local service.

```ts
// Import the mdns namespace from @ohos.net.mdns.
import mdns from '@ohos.net.mdns';
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import featureAbility from '@ohos.ability.featureAbility';
import window from '@ohos.window';

// Construct a singleton object.
export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

// Obtain the context of the stage model.
class EntryAbility extends UIAbility {
  value: number = 0;
  onWindowStageCreate(windowStage: window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

class ServiceAttribute {
  key: string = "111"
  value: Array<number> = [1]
}

// Create a LocalService object.
let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
    address: "10.14.**.***"
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

// Call addLocalService to add a local service.
mdns.addLocalService(context as Context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// (Optional) Call resolveLocalService to resolve the local service.
mdns.resolveLocalService(context as Context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// Call removeLocalService to remove the local service.
mdns.removeLocalService(context as Context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## Discovering Local Services

1. Connect the device to the Wi-Fi network.
2. Import the **mdns** namespace from **@ohos.net.mdns**.
3. Create a **DiscoveryService** object, which is used to discover mDNS services of the specified type.
4. Subscribe to mDNS service discovery status changes.
5. Enable discovery of mDNS services on the LAN.
6. Stop searching for mDNS services on the LAN.
7. Unsubscribe from mDNS service discovery status changes.

```ts
// Import the mdns namespace from @ohos.net.mdns.
import mdns from '@ohos.net.mdns';
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import featureAbility from '@ohos.ability.featureAbility';
import window from '@ohos.window';

// Construct a singleton object.
export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

// Obtain the context of the stage model.
class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage: window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}

let context = GlobalContext.getContext().getObject("value");

// Create a DiscoveryService object, which is used to discover mDNS services of the specified type.
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);

class DataServiceInfo{
  serviceInfo: mdns.LocalServiceInfo|null = null
  errorCode?: mdns.MdnsError = mdns.MdnsError.INTERNAL_ERROR
}
// Subscribe to mDNS service discovery status changes.
discoveryService.on('discoveryStart', (data: DataServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('discoveryStop', (data: DataServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

// Enable discovery of mDNS services on the LAN.
discoveryService.startSearchingMDNS();

// Stop searching for mDNS services on the LAN.
discoveryService.stopSearchingMDNS();

// Unsubscribe from mDNS service discovery status changes.
discoveryService.off('discoveryStart', (data: DataServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('discoveryStop', (data: DataServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```
