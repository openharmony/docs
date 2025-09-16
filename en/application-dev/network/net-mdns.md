# Using MDNS for LAN Access
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## Overview

Multicast DNS (MDNS) provides functions such as adding, removing, discovering, and resolving local services on a LAN.
- Local service: a service provider on a LAN, for example, a printer or scanner.

Typical MDNS management scenarios include:

- Managing local services on a LAN, such as adding, removing, and resolving local services.
- Discovering local services and listening to the status changes of local services of the specified type through the **DiscoveryService** object.

> **NOTE**
> To maximize the application running efficiency, most API calls are called asynchronously in callback or promise mode. The following code examples use the promise mode. For details about the APIs, see [MDNS Management](../reference/apis-network-kit/js-apis-net-mdns.md).

The following describes the development procedure specific to each application scenario.

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain the UIAbilityContext, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

## Managing Local Services

1. Connect the device to the Wi-Fi network.
2. Import the **mdns**, **BusinessError**, **featureAbility**, and **common** namespaces from @kit.NetworkKit.

    ```ts
    // Import the mdns namespace from @kit.NetworkKit.
    import { mdns } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { featureAbility, common } from '@kit.AbilityKit';
    ```

3. Call **addLocalService** to add a local service.

    <!--code_no_check-->
    ```ts
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
        address: "10.14.**.**"
      },
      serviceAttribute: [{key: "111", value: [1]}]
    }

    // Call addLocalService to add a local service.
    mdns.addLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
      console.info(JSON.stringify(data));
    });
    ```

4. (Optional) Call **resolveLocalService** to resolve the local service for the IP address of the local network.
   
     ```ts
    // (Optional) Call resolveLocalService to resolve the local service.
    mdns.resolveLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
      console.info(JSON.stringify(data));
    });
    ```

5. Call **removeLocalService** to remove the local service.
   
    ```ts
    // Call removeLocalService to remove the local service.
    mdns.removeLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
      console.info(JSON.stringify(data));
    });
    ```

## Discovering Local Services

1. Connect the device to the Wi-Fi network.
2. Import the **mdns** namespace from **@kit.NetworkKit**.

    ```ts
    // Import the mdns namespace from @kit.NetworkKit.
    import { common, featureAbility, UIAbility } from '@kit.AbilityKit';
    import { mdns } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { window } from '@kit.ArkUI';
    ```

3. Create a **DiscoveryService** object, which is used to discover MDNS services of the specified type.

    <!--code_no_check-->
    ```ts
   let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;

    // Create a DiscoveryService object, which is used to discover mDNS services of the specified type.
    let serviceType = "_print._tcp";
    let discoveryService = mdns.createDiscoveryService(context, serviceType);
    ```
  
4. Subscribe to MDNS service discovery status changes.

    ```ts
    // Subscribe to mDNS service discovery status changes.
    discoveryService.on('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
      console.info(JSON.stringify(data));
    });
    discoveryService.on('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
      console.info(JSON.stringify(data));
    });
    discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
      console.info(JSON.stringify(data));
    });
    discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
      console.info(JSON.stringify(data));
    });
    ```

5. Enable discovery of MDNS services on the LAN.

    ```ts
    // Enable discovery of mDNS services on the LAN.
    discoveryService.startSearchingMDNS();
    ```

6. Stop searching for MDNS services on the LAN.

    ```ts
    // Stop searching for mDNS services on the LAN.
    discoveryService.stopSearchingMDNS();
    ```

7. Unsubscribe from MDNS service discovery status changes.

    ```ts
    // Unsubscribe from mDNS service discovery status changes.
    discoveryService.off('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
      console.info(JSON.stringify(data));
    });
    discoveryService.off('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
      console.info(JSON.stringify(data));
    });
    discoveryService.off('serviceFound', (data: mdns.LocalServiceInfo) => {
      console.info(JSON.stringify(data));
    });
    discoveryService.off('serviceLost', (data: mdns.LocalServiceInfo) => {
      console.info(JSON.stringify(data));
    });
    ```

