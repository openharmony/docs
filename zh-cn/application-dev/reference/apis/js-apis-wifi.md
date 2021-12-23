# WLAN

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

##  导入模块

```
import wifi from '@ohos.wifi_native_js';
```

## wifi.isWifiActive

isWifiActive(): boolean

查询WLAN是否已激活。

**返回值：**

| **类型** | **说明**                     |
| -------- | ---------------------------- |
| boolean  | true:已激活， false:未激活。 |

## wifi.getSignalLevel

getSignalLevel(rssi: number, band: number): number

查询WLAN信号强度。

**参数：**

| **参数名** | **类型** | **必填** | **说明**              |
| ---------- | -------- | -------- | --------------------- |
| rssi       | number   | 是       | 热点的信号强度(dBm)。 |
| band       | number   | 是       | WLAN接入点的频段。    |

**返回值：**

| **类型** | **说明**                     |
| -------- | ---------------------------- |
| number   | 信号强度，取值范围为[0, 4]。 |

## wifi.scan

scan(): boolean

启动WLAN扫描。

**返回值：**

| **类型** | **说明**                                     |
| -------- | -------------------------------------------- |
| boolean  | true:扫描操作成功， false:扫描操作执行失败。 |

## wifi.getScanInfos

getScanInfos(): Promise<Array\<WifiScanInfo>>

获取扫描结果，使用promise方式作为异步方法。

**返回值：**

| **类型**                                         | **说明**               |
| ------------------------------------------------ | ---------------------- |
| Promise< Array\<[WifiScanInfo](#wifiscaninfo)> > | 返回扫描到的热点列表。 |

## wifi.getScanInfos

getScanInfos(callback: AsyncCallback<Array\<WifiScanInfo>>): void

获取扫描结果，使用callback方式作为异步方法。

| **参数名** | **类型**                                              | **必填** | **说明**                       |
| ---------- | ----------------------------------------------------- | -------- | ------------------------------ |
| callback   | AsyncCallback< Array\<[WifiScanInfo](#wifiscaninfo)>> | 是       | 扫描到的热点列表结果回调函数。 |

**示例：**

```
import wifi from '@ohos.wifi_native_js';


wifi.getScanInfos(result => {
    var len = Object.keys(result).length;
    console.log("received scan info size: " + len);
    for (var i = 0; i < len; ++j) {
        console.info("ssid: " + result[i].ssid);
        console.info("bssid: " + result[i].bssid);
        console.info("securityType: " + result[i].securityType);
        console.info("rssi: " + result[i].rssi);
        console.info("band: " + result[i].band);
        console.info("frequency: " + result[i].frequency);
        console.info("timestamp: " + result[i].timestamp);
    }
});

wifi.getScanInfos().then(result => {
    var len = Object.keys(result).length;
    console.log("received scan info size: " + len);
    for (var i = 0; i < len; ++i) {
        console.info("ssid: " + result[i].ssid);
        console.info("bssid: " + result[i].bssid);
        console.info("securityType: " + result[i].securityType);
        console.info("rssi: " + result[i].rssi);
        console.info("band: " + result[i].band);
        console.info("frequency: " + result[i].frequency);
        console.info("timestamp: " + result[i].timestamp);
    }
});
```

## WifiScanInfo

WLAN热点信息。

| **参数名**   | **类型**         | **读写属性** | **说明**                      |
| ------------ | ---------------- | ------------ | ----------------------------- |
| ssid         | string           | 只读         | 热点的SSID，编码格式为UTF-8。 |
| bssid        | string           | 只读         | 热点的BSSID。                 |
| securityType | WifiSecurityType | 只读         | WLAN加密类型。                |
| rssi         | number           | 只读         | 热点的信号强度(dBm)。         |
| band         | number           | 只读         | WLAN接入点的频段。            |
| frequency    | number           | 只读         | WLAN接入点的频率。            |
| timestamp    | number           | 只读         | 时间戳。                      |