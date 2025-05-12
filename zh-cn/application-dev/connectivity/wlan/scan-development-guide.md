# Wi-Fi扫描开发指导

## 简介
Wi-Fi扫描是指设备（如手机、电脑、路由器等）搜索周围可用Wi-Fi网络的过程，通过扫描，设备可以获取附近网络的基本信息（如网络名称、信号强度、加密方式等），从而实现连接、管理或分析周围网络。

## 场景介绍

- Wi-Fi扫描

## 接口说明

完整的JS API说明以及示例代码请参考：[SCAN接口](../../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

具体接口说明如下表。

| 接口名 | 功能描述 |
| -------- | -------- |
| scan() | 启动WLAN扫描，使用前先使能WLAN。|
| getScanInfoList() | 获取扫描结果。|
| on(type: 'wifiScanStateChange') | 注册注册扫描状态改变事件。|
| off(type: 'wifiScanStateChange') | 取消注册扫描状态改变事件。|


## 主要场景开发步骤

### Wi-Fi扫描
1. import需要的WI-FI模块。
2. 需要SystemCapability.Communication.WiFi.STA系统能力。
3. 开启设备的WI-FI。
4. 示例代码：

```ts
  import { wifiManager } from '@kit.ConnectivityKit';

  try {
    let recvWifiScanStateChangeFunc = (result:number) => {
        console.info("Receive Wifi scan state change event: " + result);
    }

    // Register event
    wifiManager.on("wifiScanStateChange", recvWifiScanStateChangeFunc);

    let isWifiActive = wifiManager.isWifiActive();
    if (!isWifiActive) {
      console.info("wifi not enable"); // 请先手动打开WiFi
      return;
    }
    // 发起扫描, 从 API version 9开始支持，从API version 10开始废弃。替代接口仅向系统应用开放。
    wifiManager.scan(); 

    let scanInfoList = wifiManager.getScanInfoList();

    let len = scanInfoList.length;
    console.log("wifi received scan info: " + len);
    if(len > 0){
      for (let i = 0; i < len; ++i) {
        console.info("ssid: " + scanInfoList[i].ssid);
        console.info("bssid: " + scanInfoList[i].bssid);
        console.info("capabilities: " + scanInfoList[i].capabilities);
        console.info("securityType: " + scanInfoList[i].securityType);
        console.info("rssi: " + scanInfoList[i].rssi);
        console.info("band: " + scanInfoList[i].band);
        console.info("frequency: " + scanInfoList[i].frequency);
        console.info("channelWidth: " + scanInfoList[i].channelWidth);
        console.info("timestamp: " + scanInfoList[i].timestamp);
        console.info("supportedWifiCategory: " + scanInfoList[i].supportedWifiCategory);
        console.info("isHiLinkNetwork: " + scanInfoList[i].isHiLinkNetwork);
      }
    }

    // Unregister event
    wifiManager.off("wifiScanStateChange", recvWifiScanStateChangeFunc);
  }
```

 5. 错误码请参见[WIFI错误码](../../reference/apis-connectivity-kit/errorcode-wifi.md)。