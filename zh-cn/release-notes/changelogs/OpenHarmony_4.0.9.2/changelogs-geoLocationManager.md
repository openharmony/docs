# 位置服务子系统ChangeLog

## cl.location.1 新增获取WiFi/BT扫描结果的系统接口

@ohos.geoLocationManager.d.ts中增加获取WiFi/BT扫描结果的接口，这些接口是systemApi。

**变更影响**

系统应用可以从调用@ohos.geoLocationManager.d.ts中的接口获取WiFi/BT扫描结果，用于网络定位。

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
|geoLocationManager| method | function on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void; | 新增接口 | 
|geoLocationManager| method | function off(type: 'locatingRequiredDataChange', callback?: Callback&lt;Array&lt;LocatingRequiredData&gt;&gt;): void; | 新增接口 | 
|geoLocationManager| method | function getLocatingRequiredData(config: LocatingRequiredDataConfig): Promise&lt;Array&lt;LocatingRequiredData&gt;&gt;; | 新增接口 | 

**适配指导**

以单次获取扫描信息为例：

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

