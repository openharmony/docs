# P2P模式开发指导

## 简介
P2P模式，主要提供了wlan设备的一种点对点连接技术，它可以在两台 STA 之间直接建立 TCP/IP 链接，并不需要AP的参与。

## 场景介绍
主要场景有：

- 创建/删除P2P群组
- 建立P2P连接

## 接口说明

完整的 JS API 说明以及实例代码请参考：[P2P 接口](../../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

具体接口说明如下表。

| 接口名 | 功能描述 |
| -------- | -------- |
| createGroup() | 创建群组。 |
| removeGroup() | 删除群组。 |
| startDiscoverDevices()  | 开始发现设备。 |
| getP2pPeerDevices() | 获取P2P对端设备列表信息。 |
| p2pConnect() | 执行P2P连接。 |
| getP2pLinkedInfo() | 获取P2P连接信息。 |
| on(type: 'p2pPersistentGroupChange') | 注册P2P永久组状态改变事件。 |
| off(type: 'p2pPersistentGroupChange') | 取消注册P2P永久组状态改变事件。 |
| on(type: 'p2pPeerDeviceChange') | 注册P2P对端设备状态改变事件。 |
| off(type: 'p2pPeerDeviceChange') | 取消注册P2P对端设备状态改变事件。 |
| on(type: 'p2pConnectionChange') | 注册P2P连接状态改变事件。 |
| off(type: 'p2pConnectionChange') | 取消注册P2P连接状态改变事件。 |

## 主要场景开发步骤

### 创建/删除P2P群组
1. import需要的WI-FI模块。
2. 开启设备的WI-FI。
3. 需要SystemCapability.Communication.WiFi.P2P系统能力。
4. 创建/删除P2P群组。
5. 示例代码：

```ts
import wifiManager from '@ohos.wifiManager';

// 创建群组，将当前设备当做GO使用时，需要该步骤
// netId：-1表示创建临时组，下次和已连接过的设备连接，需要重新进行GO协商，以及wps秘钥协商;
//        -2表示创建永久组，下次和已连接过的设备连接，不需要重新进行GO和wps秘钥协商;

let recvP2pPersistentGroupChangeFunc = () => {
	console.info("p2p persistent group change receive event");
  
	// 永久组创建好后需要处理的业务
}
// 创建永久组，需要注册永久组状态改变事件回调
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
    
// 删除群组
try {
	wifiManager.removeGroup();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

6. 错误码请参见[WIFI错误码](../../reference/apis-connectivity-kit/errorcode-wifi.md)。

### 建立P2P连接
1. import需要的WI-FI模块。
2. 开启设备的WI-FI。
3. 需要SystemCapability.Communication.WiFi.P2P系统能力。
4. 注册"p2pPeerDeviceChange"事件回调，并在回调实现中执行P2P连接。
5. 开始P2P设备发现。
6. 示例代码：

```ts
import wifiManager from '@ohos.wifiManager';
  
let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {
	console.info("p2p connection change receive event: " + JSON.stringify(result));
	wifiManager.getP2pLinkedInfo((err, data) => {
		if (err) {
			console.error('failed to get getP2pLinkedInfo: ' + JSON.stringify(err));
			return;
		}
		console.info("get getP2pLinkedInfo: " + JSON.stringify(data));
		// 添加P2P连接成功或者失败场景的业务处理
	});
}
// P2P连接完成，会调用"p2pConnectionChange"事件回调
wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);
  
let recvP2pPeerDeviceChangeFunc = (result:wifiManager.WifiP2pDevice[]) => {
	console.info("p2p peer device change receive event: " + JSON.stringify(result));
	wifiManager.getP2pPeerDevices((err, data) => {
		if (err) {
			console.error('failed to get peer devices: ' + JSON.stringify(err));
			return;
		}
		console.info("get peer devices: " + JSON.stringify(data));
		let len = data.length;
		for (let i = 0; i < len; ++i) {
			// 选择符合条件的对端P2P设备
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
				// 执行P2P连接
				wifiManager.p2pConnect(config);
			}
		}
	});
}
// P2P扫描结果上报时会调用"p2pPeerDeviceChange"事件回调
wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  
setTimeout(() => {wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);}, 125 * 1000);
setTimeout(() =>  {wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);}, 125 * 1000);
// 开始发现P2P设备，即，开始P2P扫描
console.info("start discover devices -> " + wifiManager.startDiscoverDevices());
```

7. 错误码请参见[WIFI错误码](../../reference/apis-connectivity-kit/errorcode-wifi.md)。
