# Location Subsystem Changelog

## cl.location.1 Addition of APIs for Obtaining the Wi-Fi and Bluetooth Scanning Result

APIs for obtaining the Wi-Fi and Bluetooth scanning result are added to **@ohos.geoLocationManager.d.ts**. They are all system APIs.

**Change Impact**

The system application can use the Wi-Fi and Bluetooth scanning result obtained by these APIs for network positioning.

**Key API/Component Changes**

| Class| API Type| Declaration| Change Type| 
|  -- | -- | -- | -- |
|geoLocationManager| method | function on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void; | Added| 
|geoLocationManager| method | function off(type: 'locatingRequiredDataChange', callback?: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void; | Added| 
|geoLocationManager| method | function getLocatingRequiredData(config: LocatingRequiredDataConfig): Promise&lt;Array&lt;LocatingRequiredData&gt;&gt;; | Added| 

**Adaptation Guide**

The following example shows how to obtain Wi-Fi and Bluetooth scanning information at a time:

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let config = {'type': 1, 'needStartScan': true, 'scanInterval': 10000};
  try {
      geoLocationManager.getLocatingRequiredData(config).then((result) => {
          console.log('getLocatingRequiredData return: ' + JSON.stringify(result));
      })  
      .catch((error) => {
          console.log('promise, getLocatingRequiredData: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```
