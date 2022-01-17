# WLAN

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

##  Modules to Import

```
import wifi from '@ohos.wifi_native_js';
```

## wifi.isWifiActive

isWifiActive(): boolean

Checks whether WLAN is activated.

**Return values**

| Type| Description|
| -------- | ---------------------------- |
| boolean  | Returns **true** if WLAN is activated; returns **false** otherwise.|

## wifi.getSignalLevel

getSignalLevel(rssi: number, band: number): number

Obtains the WLAN signal strength.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | -------- | -------- | --------------------- |
| rssi       | number   | Yes| Signal strength (in dBm) of the hotspot.|
| band       | number   | Yes| Frequency band of the WLAN access point (AP).|

**Return values**

| Type| Description|
| -------- | ---------------------------- |
| number   | Signal strength obtained. The value range is 0 to 4.|

## wifi.scan

scan(): boolean

Starts a scan for WLAN.

**Return values**

| Type| Description|
| -------- | -------------------------------------------- |
| boolean  | Returns **true** if the scan is successful; returns **false** otherwise.|

## wifi.getScanInfos

getScanInfos(): Promise<Array\<WifiScanInfo>>

Obtains the scan result. This method uses a promise to return the result.

**Return values**

| Type| Description|
| ------------------------------------------------ | ---------------------- |
| Promise< Array\<[WifiScanInfo](#wifiscaninfo)> > | Promise used to return the scan result, which is a list of hotspots detected.|

## wifi.getScanInfos

getScanInfos(callback: AsyncCallback<Array\<WifiScanInfo>>): void

Obtains the scan result. This method uses an asynchronous callback to return the result.

| Name| Type| Mandatory| Description|
| ---------- | ----------------------------------------------------- | -------- | ------------------------------ |
| callback   | AsyncCallback< Array\<[WifiScanInfo](#wifiscaninfo)>> | Yes| Callback invoked to return the result, which is a list of hotspots detected.|

**Example**

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

Defines WLAN hotspot information.

| Name| Type| Readable/Writable| Description|
| ------------ | ---------------- | ------------ | ----------------------------- |
| ssid         | string           | Read-only| Hotspot service set identifier (SSID), in UTF-8 format.|
| bssid        | string           | Read-only| Basic service set identifier (BSSID) of the hotspot.|
| securityType | WifiSecurityType | Read-only| WLAN encryption type.|
| rssi         | number           | Read-only| Signal strength (in dBm) of the hotspot.|
| band         | number           | Read-only| Frequency band of the WLAN AP.|
| frequency    | number           | Read-only| Frequency of the WLAN AP.|
| timestamp    | number           | Read-only| Timestamp.|
