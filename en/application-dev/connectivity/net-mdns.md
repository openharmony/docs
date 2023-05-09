# MDNS Management

## Introduction

Multicast DNS (mDNS) provides functions such as adding, removing, discovering, and resolving local services on a LAN.
- Local service: a service provider on a LAN, for example, a printer or scanner.

Typical MDNS management scenarios include:

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
| ohos.net.mdns.DiscoveryService | on(type: 'discoveryStop', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void | Enables listening for **discoveryStop** events.|
| ohos.net.mdns.DiscoveryService | on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void | Enables listening for **serviceFound** events.|
| ohos.net.mdns.DiscoveryService | on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void | Enables listening for **serviceLost** events.|

## Managing Local Services

1. Connect the device to the Wi-Fi network.
2. Import the **mdns** namespace from **@ohos.net.mdns**.
3. Call **addLocalService** to add a local service.
4. (Optional) Call **resolveLocalService** to resolve the local service for the IP address of the local network.
5. Call **removeLocalService** to remove the local service.

```js
// Import the mdns namespace from @ohos.net.mdns.
import mdns from '@ohos.net.mdns'

// Obtain the context of the FA model.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

// Obtain the context of the stage model.
import UIAbility from '@ohos.app.ability.UIAbility';
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage){
    globalThis.context = this.context;
  }
}
let context = globalThis.context;

// Create a LocalService object.
let localServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
    address: "10.14.**.***",
  },
  serviceAttribute: [{
    key: "111",
    value: [1]
  }]
}

// Call addLocalService to add a local service.
mdns.addLocalService(context, localServiceInfo, function (error, data) {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// (Optional) Call resolveLocalService to resolve the local service.
mdns.resolveLocalService(context, localServiceInfo, function (error, data) {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});

// Call removeLocalService to remove the local service.
mdns.removeLocalService(context, localServiceInfo, function (error, data) {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## Discovering Local Services

1. Connect the device to the Wi-Fi network.
2. Import the **mdns** namespace from **@ohos.net.mdns**.
3. Creates a **DiscoveryService** object, which is used to discover mDNS services of the specified type.
4. Subscribe to mDNS service discovery status changes.
5. Enable discovery of mDNS services on the LAN.
6. Stop searching for mDNS services on the LAN.

```js
// Import the mdns namespace from @ohos.net.mdns.
import mdns from '@ohos.net.mdns'

// Obtain the context of the FA model.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();

// Obtain the context of the stage model.
import UIAbility from '@ohos.app.ability.UIAbility';
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage){
    globalThis.context = this.context;
  }
}
let context = globalThis.context;

// Create a LocalService object.
let localServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
    address: "10.14.**.***",
  },
  serviceAttribute: [{
    key: "111",
    value: [1]
  }]
}

// Create a DiscoveryService object, which is used to discover mDNS services of the specified type.
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);

// Subscribe to mDNS service discovery status changes.
discoveryService.on('discoveryStart', (data) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('discoveryStop', (data) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceFound', (data) => {
  console.log(JSON.stringify(data));
});
discoveryService.on('serviceLost', (data) => {
  console.log(JSON.stringify(data));
});

// Enable discovery of mDNS services on the LAN.
discoveryService.startSearchingMDNS();

// Stop searching for mDNS services on the LAN.
discoveryService.stopSearchingMDNS();
```
