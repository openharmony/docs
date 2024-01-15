# @ohos.wifiManager (WLAN)
该模块主要提供查询WLAN是否已使能的方法。

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import wifiManager from '@ohos.wifiManager';
```

## wifiManager.isWifiActive<sup>9+</sup>

isWifiActive(): boolean

查询WLAN是否已使能。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已使能，&nbsp;false:未使能。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](../errorcodes/errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
  | -------- | -------- |
| 2501000  | Operation failed.|

**示例：**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let isWifiActive = wifiManager.isWifiActive();
		console.info("isWifiActive:" + isWifiActive);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

