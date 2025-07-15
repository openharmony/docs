# P2P Connection Development

## Introduction
The peer-to-peer (P2P) mode provides a point-to-point connection between devices in a WLAN. It enables the direct establishment of a TCP/IP connection between two stations (STAs) without the involvement of an access point (AP).

## When to Use
You can use the APIs provided by the **wifiManager** module to:

- Create or remove a P2P group.
- Set up a P2P connection.

## Available APIs

For details about the JavaScript APIs and sample code, see the [P2P API Reference](../../reference/apis-connectivity-kit/js-apis-wifiManager.md).

The following table describes the APIs used in this topic.

| API| Description|
| -------- | -------- |
| createGroup() | Creates a P2P group.|
| removeGroup() | Removes a P2P group.|
| startDiscoverDevices()  | Starts to discover devices.|
| getP2pPeerDevices() | Obtains the P2P peer device list.|
| p2pConnect() | Sets up a P2P connection.|
| getP2pLinkedInfo() | Obtains P2P connection information.|
| on(type: 'p2pPersistentGroupChange') | Subscribes to P2P persistent group state changes.|
| off(type: 'p2pPersistentGroupChange') | Unsubscribes from P2P persistent group state changes.|
| on(type: 'p2pPeerDeviceChange') | Subscribes to P2P peer device state changes.|
| off(type: 'p2pPeerDeviceChange') | Unsubscribes from P2P peer device state changes.|
| on(type: 'p2pConnectionChange') | Subscribes to P2P connection state changes.|
| off(type: 'p2pConnectionChange') | Unsubscribes from P2P connection state changes.|

## How to Develop

### Creating or Removing a P2P Group
1. Import the Wi-Fi module.
2. Enable Wi-Fi on the device.
3. Check that the device has the SystemCapability.Communication.WiFi.P2P capability.
4. Create or remove a P2P group.
5. Example:

```ts
import { wifiManager } from '@kit.ConnectivityKit';

// Create a P2P group. To use the current device as the group owner (GO), set:
// netId: The value -1 means to create a temporary P2P group. When a device in the group is to be connected next time, GO negotiation and WPS key negotiation must be performed again.
// The value -2 means to create a persistent group. The device in the group can be reconnected without GO negotiation or WPS key negotiation.

let recvP2pPersistentGroupChangeFunc = () => {
	console.info("p2p persistent group change receive event");
  
	// Services to be processed after the persistent group is created.
}
// Create a persistent group, and register a listener callback for the persistent group status changes.
wifiManager.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
try {
	let config:wifiManager.WifiP2PConfig = {
		deviceAddress: "00:11:22:33:44:55",
		deviceAddressType: 1,
		netId: -2,
		passphrase: "12345678",
		groupName: "testGroup",
		goBand: 0
	}
	wifiManager.createGroup(config);	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
    
// Remove a P2P group.
try {
	wifiManager.removeGroup();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

6. For details about error codes, see [Wi-Fi Error Codes](../../reference/apis-connectivity-kit/errorcode-wifi.md).

### Setting Up a P2P Connection
1. Import the Wi-Fi module.
2. Enable Wi-Fi on the device.
3. Check that the device has the SystemCapability.Communication.WiFi.P2P capability.
4. Register a callback for **p2pPeerDeviceChange** and set up a P2P connection in the callback implementation.
5. Start P2P device discovery.
6. Example:

```ts
import { wifiManager } from '@kit.ConnectivityKit';
  
let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {
	console.info("p2p connection change receive event: " + JSON.stringify(result));
	wifiManager.getP2pLinkedInfo((err, data) => {
		if (err) {
			console.error("failed to get P2pLinkedInfo: " + JSON.stringify(err));
			return;
		}
		console.info("get getP2pLinkedInfo: " + JSON.stringify(data));
		// Add the service processing logic after a successful or failed P2P connection.
	});
}
// After the P2P connection is set up, the callback for p2pConnectionChange will be called.
wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);
  
let recvP2pPeerDeviceChangeFunc = (result:wifiManager.WifiP2pDevice[]) => {
	console.info("p2p peer device change receive event: " + JSON.stringify(result));
	wifiManager.getP2pPeerDevices((err, data) => {
		if (err) {
			console.error("failed to get peer devices: " + JSON.stringify(err));
			return;
		}
		console.info("get peer devices: " + JSON.stringify(data));
		let len = data.length;
		for (let i = 0; i < len; ++i) {
			// Select the peer P2P device that meets the conditions.
			if (data[i].deviceName === "my_test_device") {
				console.info("p2p connect to test device: " + data[i].deviceAddress);
				let config:wifiManager.WifiP2PConfig = {
					deviceAddress:data[i].deviceAddress,
					deviceAddressType: 1,
					netId:-2,
					passphrase:"",
					groupName:"",
					goBand:0,
				}
				// Set up a P2P connection. The GO cannot initiate connections.
				wifiManager.p2pConnect(config);
			}
		}
	});
}
// The callback for p2pPeerDeviceChange will be called when the P2P scanning result is reported.
wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  
setTimeout(() => {wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);}, 125 * 1000);
setTimeout(() =>  {wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);}, 125 * 1000);
// Start to discover P2P devices, that is, start P2P scanning.
console.info("start discover devices -> " + wifiManager.startDiscoverDevices());
```

7. For details about error codes, see [Wi-Fi Error Codes](../../reference/apis-connectivity-kit/errorcode-wifi.md).
