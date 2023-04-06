# Wi-Fi Subsystem ChangeLog

## cl.location.1 Location Service Permission Change

From API version 9, the **ohos.permission.APPROXIMATELY_LOCATION** permission is added for obtaining the approximate location.

If you use API version 9 or later, you need to apply for both the **ohos.permission.LOCATION** and **ohos.permission.APPROXIMATELY_LOCATION** permissions. Applying for only the **ohos.permission.LOCATION** permission will fail.

**Change Impacts**

Applications using API versions earlier than 9 are not affected. For an application using API version 9 or later, the method for applying for the location permission is changed. The details are as follows:

Before using basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user as described below.

The system provides the following location permissions:

- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

If your application needs to access the device location information, it must first apply for required permissions. Specifically speaking:

API versions earlier than 9: Apply for **ohos.permission.LOCATION**.

API version 9 and later: Apply for **ohos.permission.APPROXIMATELY_LOCATION**, or apply for **ohos.permission.APPROXIMATELY_LOCATION** and **ohos.permission.LOCATION**. Note that **ohos.permission.LOCATION** cannot be applied for separately.

| API Version| Location Permission                                                | Permission Application Result| Location Accuracy                    |
| ------------- | ------------------------------------------------------------ | -------- | -------------------------------- |
| Earlier than 9        | ohos.permission.LOCATION                                     | Success    | Location accurate to meters|
| 9 and later    | ohos.permission.LOCATION                                     | Failure    | No location obtained                  |
| 9 and later    | ohos.permission.APPROXIMATELY_LOCATION                       | Success    | Location accurate to 5 kilometers |
| 9 and later    | ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Success    | Location accurate to meters|

If your application needs to access the device location information when running in the background, it must be configured to be able to run in the background and be granted the **ohos.permission.LOCATION_IN_BACKGROUND** permission. In this way, the system continues to report device location information after your application moves to the background.

You can declare the required permissions in your application's configuration file. For details, see the [permission application guide](../../../application-dev/security/accesstoken-guidelines.md).

**Key API/Component Changes**

| Class       | API Type| Declaration                                                    | Change Type                                                    |
| ----------- | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| wifiManager | method   | function scan(): void;                                       | The permission is changed to **ohos.permission.SET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getScanResults(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt;; | The permission is changed to **ohos.permission.GET_WIFI_INFO** and **ohos.permission.GET_WIFI_PEERS_MAC** or **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getScanResults(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void; | The permission is changed to **ohos.permission.GET_WIFI_INFO** and **ohos.permission.GET_WIFI_PEERS_MAC** or **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getScanResultsSync(): Array&lt;WifiScanInfo&gt;;    | The permission is changed to **ohos.permission.GET_WIFI_INFO** and **ohos.permission.GET_WIFI_PEERS_MAC** or **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getCandidateConfigs(): Array&lt;WifiDeviceConfig&gt;; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getDeviceConfigs(): Array&lt;WifiDeviceConfig&gt;;  | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, **ohos.permission.APPROXIMATELY_LOCATION**, and **ohos.permission.GET_WIFI_CONFIG**.|
| wifiManager | method   | function getStations(): Array&lt;StationInfo&gt;;            | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, **ohos.permission.APPROXIMATELY_LOCATION**, and **ohos.permission.MANAGE_WIFI_HOTSPOT**.|
| wifiManager | method   | function getCurrentGroup(): Promise&lt;WifiP2pGroupInfo&gt;; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getCurrentGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getP2pPeerDevices(): Promise&lt;WifiP2pDevice[]&gt;; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function p2pConnect(config: WifiP2PConfig): void;            | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function startDiscoverDevices(): void;                       | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getP2pGroups(): Promise&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function on(type: "p2pDeviceChange", callback: Callback&lt;WifiP2pDevice&gt;): void; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function off(type: "p2pDeviceChange", callback?: Callback&lt;WifiP2pDevice&gt;): void; | The permission is changed to **ohos.permission.LOCATION** and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function on(type: "p2pPeerDeviceChange", callback: Callback&lt;WifiP2pDevice[]&gt;): void; | The permission is changed to **ohos.permission.GET_WIFI_INFO**, **ohos.permission.LOCATION**, and **ohos.permission.APPROXIMATELY_LOCATION**.|
| wifiManager | method   | function off(type: "p2pPeerDeviceChange", callback?: Callback&lt;WifiP2pDevice[]&gt;): void; | The permission is changed to **ohos.permission.LOCATION** and **ohos.permission.APPROXIMATELY_LOCATION**.|
