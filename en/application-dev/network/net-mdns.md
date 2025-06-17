# MDNS Management

## Overview

Multicast DNS (MDNS) provides functions such as adding, removing, discovering, and resolving local services on a LAN.
- Local service: a service provider on a LAN, for example, a printer or scanner.

Typical MDNS management scenarios include:

- Managing local services on a LAN, such as adding, removing, and resolving local services.
- Discovering local services and listening to the status changes of local services of the specified type through the **DiscoveryService** object.

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [MDNS Management](../reference/apis-network-kit/js-apis-net-mdns.md).

The following describes the development procedure specific to each application scenario.

## Available APIs

For the complete list of JS APIs and example code, see, see [MDNS Management](../reference/apis-network-kit/js-apis-net-mdns.md).

| API                 | Description|
| ----------------------- | ---- |
| addLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | Adds an MDNS service. This API uses an asynchronous callback to return the result.|
| removeLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | Removes an MDNS service. This API uses an asynchronous callback to return the result.|
| createDiscoveryService(context: Context, serviceType: string): DiscoveryService | Creates a **DiscoveryService** object, which is used to discover MDNS services of the specified type.|
| resolveLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void | Resolves an MDNS service. This API uses an asynchronous callback to return the result.|
| startSearchingMDNS(): void | Searches for MDNS services on the LAN.|
| stopSearchingMDNS(): void | Stops searching for MDNS services on the LAN.|
| on(type: 'discoveryStart', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | Enables listening for **discoveryStart** events.|
| off(type: 'discoveryStart', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void | Disables listening for **discoveryStart** events.|
| on(type: 'discoveryStop', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | Enables listening for **discoveryStop** events.|
| off(type: 'discoveryStop', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void | Disables listening for **discoveryStop** events.|
| on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void | Enables listening for **serviceFound** events.|
| off(type: 'serviceFound', callback?: Callback\<LocalServiceInfo>): void | Disables listening for **serviceFound** events.|
| on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void | Enables listening for **serviceLost** events.|
| off(type: 'serviceLost', callback?: Callback\<LocalServiceInfo>): void | Disables listening for **serviceLost** events.|

## Managing Local Services

1. Connect the device to the Wi-Fi network.
2. Import the **mdns** namespace from **@kit.NetworkKit**.
3. Call **addLocalService** to add a local service.
4. (Optional) Call **resolveLocalService** to resolve the local service for the IP address of the local network.
5. Call **removeLocalService** to remove the local service.

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain the UIAbilityContext, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

```ts
// Import the mdns namespace from @kit.NetworkKit.
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { featureAbility, common } from '@kit.AbilityKit';

let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;

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
mdns.addLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

// (Optional) Call resolveLocalService to resolve the local service.
mdns.resolveLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

// Call removeLocalService to remove the local service.
mdns.removeLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## Discovering Local Services

1. Connect the device to the Wi-Fi network.
2. Import the **mdns** namespace from **@kit.NetworkKit**.
3. Create a **DiscoveryService** object, which is used to discover MDNS services of the specified type.
4. Subscribe to MDNS service discovery status changes.
5. Enable discovery of MDNS services on the LAN.
6. Stop searching for MDNS services on the LAN.
7. Unsubscribe from MDNS service discovery status changes.

```ts
// Import the mdns namespace from @kit.NetworkKit.
import { common, featureAbility, UIAbility } from '@kit.AbilityKit';
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

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

let context = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;

// Create a **DiscoveryService** object, which is used to discover MDNS services of the specified type.
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);

// Subscribe to MDNS service discovery status changes.
discoveryService.on('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

// Enable discovery of MDNS services on the LAN.
discoveryService.startSearchingMDNS();

// Stop searching for MDNS services on the LAN.
discoveryService.stopSearchingMDNS();

// Unsubscribe from MDNS service discovery status changes.
discoveryService.off('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
discoveryService.off('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```
