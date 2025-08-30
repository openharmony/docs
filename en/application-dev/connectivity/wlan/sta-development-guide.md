# STA Development

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @qq_43802146-->
<!--Designer: @qq_43802146-->
<!--Tester: @furryfurry123-->
<!--Adviser: @zhang_yixin13-->

## Introduction
The Wi-Fi STA mode (that is, station mode) enables wireless devices to connect to a wireless local area network (WLAN) as clients. In this mode, devices such as mobile phones, computers, and tablets can access the network by connecting to an access point (AP) or wireless router.


## Use Cases

- [Checking the Wi-Fi Status](#checking-the-wi-fi-status)
- [Establishing a Wi-Fi Connection](#establishing-a-wi-fi-connection)

## Available APIs

For details about the JavaScript APIs and sample code, see the [STA API Reference](../../reference/apis-connectivity-kit/js-apis-wifiManager.md).

The following table describes the related APIs.

| API| Description|
| -------- | -------- |
| isWifiActive() | Checks whether WLAN is enabled.|
| addCandidateConfig() | Adds candidate network configurations. Enable WLAN before using this API.|
| connectToCandidateConfig() | Connects to a candidate network.|
| isConnected() | Checks whether WLAN is connected.|
| removeCandidateConfig() | Removes candidate network configurations.|
| getCandidateConfigs() | Obtains candidate network configurations.|
| on(type: 'wifiStateChange') | Subscribes to WLAN state changes.|
| off(type: 'wifiStateChange') | Unsubscribes from WLAN state changes.|
| on(type: 'wifiConnectionChange') | Subscribes to WLAN connection state changes.|
| off(type: 'wifiConnectionChange') | Unsubscribes from WLAN connection state changes.|


## How to Develop

### Checking the Wi-Fi Status
1. Import the required Wi-Fi module.
2. Check that the **SystemCapability.Communication.WiFi.STA** capability is available.
3. Apply for the **ohos.permission.GET_WIFI_INFO** permission.
4. Enable Wi-Fi on the device.
5. Sample code:

```ts
   import { wifiManager } from '@kit.ConnectivityKit';
   try {
   let recvPowerNotifyFunc = (result:number) => {
     let wifiState = "";
       switch (result) {
       case 0:
       wifiState += 'DISABLING';
       break;
       case 1:
       wifiState += 'DISABLED';
       break;
       case 2:
       wifiState += 'ENABLING';
       break;
       case 3:
       wifiState += 'ENABLED';
       break;
       default:
       wifiState += 'UNKNOWN STATUS';
       break;
     }
   }
     // Subscribe to Wi-Fi connection state changes.
     wifiManager.on("wifiStateChange", recvPowerNotifyFunc);
     // Check whether Wi-Fi is enabled.
     let isWifiActive = wifiManager.isWifiActive();
     if (!isWifiActive) {
       console.info("Wi-Fi not enabled"); // Enable Wi-Fi manually.
       return;
     }

     wifiManager.off("wifiStateChange", recvPowerNotifyFunc);
   } catch (error) {
     console.error(`WiFi state monitor failed. ${error.message}`);
   }
```

### Establishing a Wi-Fi Connection
1. Import the required Wi-Fi module.
2. Enable Wi-Fi on the device.
3. Check that the **SystemCapability.Communication.WiFi.STA** capability is available.
4. Apply for the **ohos.permission.GET_WIFI_INFO** and **ohos.permission.SET_WIFI_INFO** permissions.
5. Sample code:

   ```ts
   import { wifiManager } from '@kit.ConnectivityKit';

   try {
       let recvWifiConnectionChangeFunc = (result:number) => {
       console.info("Receive wifi connection change event: " + result);
     }

     let config:wifiManager.WifiDeviceConfig = {
       ssid : "****",
       bssid : "****",
       preSharedKey : "****",
       securityType : 0
	   }

       // Update the current Wi-Fi connection status.
     wifiManager.on("wifiConnectionChange", recvWifiConnectionChangeFunc);
       // Add candidate network configurations.
	   wifiManager.addCandidateConfig(config).then(result => {
       // Connect to the specified network.
       wifiManager.connectToCandidateConfig(result);
     });

     if (!wifiManager.isConnected()) {
         console.info("Wi-Fi not connected");
     }
     // Obtain link information.
     wifiManager.getLinkedInfo().then(data => {
       console.info("get Wi-Fi linked info: " + JSON.stringify(data));
     })
     // Query the signal strength.
     let rssi = -88;
     let band = 1;
     let level = wifiManager.getSignalLevel(rssi,band);
     console.info("level:" + JSON.stringify(level));

     // Unsubscribe from Wi-Fi connection state changes.
     wifiManager.off("wifiConnectionChange", recvWifiConnectionChangeFunc);
   } catch (error) {
     console.error(`WiFi Connection failed. ${error.message}`);
   }
   ```
6. Check the Wi-Fi connection status. For details, see [ConnState](../../reference/apis-connectivity-kit/js-apis-wifiManager.md#connstate9).
7. For details about error codes, see [Wi-Fi Error Codes](../../reference/apis-connectivity-kit/errorcode-wifi.md).
