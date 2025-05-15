# Wi-Fi扫描开发指南

## 简介
Wi-Fi扫描是指设备（如手机、电脑、路由器等）搜索周围可用Wi-Fi网络的过程。通过扫描，设备可以获取附近网络的基本信息（如网络名称、信号强度、加密方式等），从而实现连接、管理或分析周围网络。

## 场景介绍

- [Wi-Fi扫描](#wi-fi扫描)
- [PNO扫描](#PNO扫描)
- [周期扫描](#周期扫描)
- [扫描管控](#扫描管控)

## 接口说明

完整的JS API说明以及示例代码请参考：[SCAN接口](../../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

具体接口说明如下表所示。

| 接口名 | 功能描述 |
| -------- | -------- |
| scan() | 启动WLAN扫描，使用前先使能WLAN。|
| getScanInfoList() | 获取扫描结果。|
| on(type: 'wifiScanStateChange') | 注册注册扫描状态改变事件。|
| off(type: 'wifiScanStateChange') | 取消注册扫描状态改变事件。|


## 开发步骤

### Wi-Fi扫描
1. 导入需要的Wi-Fi模块。
2. 需要SystemCapability.Communication.WiFi.STA系统能力。
3. 需要权限ohos.permission.GET_WIFI_INFO。
4. 开启设备的Wi-Fi。
5. 示例代码：

```ts
  import { wifiManager } from '@kit.ConnectivityKit';

  try {
    let recvWifiScanStateChangeFunc = (result:number) => {
        console.info("Receive Wifi scan state change event: " + result);
    }

    // 获取扫描状态 0：扫描失败；1：扫描成功。
    wifiManager.on("wifiScanStateChange", recvWifiScanStateChangeFunc);

    let isWifiActive = wifiManager.isWifiActive();
    if (!isWifiActive) {
      console.error("wifi not enable"); // 请先手动打开WiFi
      return;
    }
    // 发起扫描（从 API version 9开始支持，从API version 10开始废弃。替代接口仅向系统应用开放。）
    wifiManager.scan(); 

    let scanInfoList = wifiManager.getScanInfoList();

    let len = scanInfoList.length;
    console.info("wifi received scan info: " + len);
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

    // 取消注册，停止获取扫描状态。
    wifiManager.off("wifiScanStateChange", recvWifiScanStateChangeFunc);
  }
```

 5. 错误码详情请参见[WIFI错误码](../../reference/apis-connectivity-kit/errorcode-wifi.md)。

 ### PNO扫描

  PNO扫描即首选分流网络扫描（Preferred Network Offload scanning），是一种用于降低移动设备功耗的Wi-Fi扫描技术。
  触发PNO扫描条件：当设备未连接Wi-Fi且屏幕关闭后，会触发PNO扫描，支持设备在后台寻找并连接首选的Wi-Fi网络。

 ### 周期扫描

  WiFi周期扫描是指无线设备（如智能手机、平板电脑、笔记本电脑等）按照一定的时间间隔，自动搜索周围可用的WiFi网络的过程。<br>
  触发场景描述：<br>
  1. 设备已与Wi-Fi连接且亮屏，判断当前链路是否可以上网，可以上网的话扫描间隔1h，不可上网的话判断是否静止，静止场景下扫描周期从20s开始倍增，最大300s；非静止场景扫描周期从20s开始最大160s。<br>
  2. 设备亮屏且Wi-Fi未连接，静止场景扫描周期从20s开始倍增，最大300s；非静止场景扫描周期从20s开始最大160s。

### 扫描管控

  WiFi扫描管控是指对无线设备扫描WiFi网络的行为进行管理和控制，以下是一些常见的管控方式和应用场景：<br>
  1. WiFi在关闭的情况下不触发周期扫描和PNO扫描。<br>
  2. WiFi连接过程中不允许触发扫描。<br>
  3. 前台应用2分钟内最多发起4次扫描。<br>
  4. 设备温度达到阈值，设备扫描会被管控。<br>
  5. 扫描接口从 API version 9开始支持，从API version 10开始废弃，替代接口仅向系统应用开放。
  