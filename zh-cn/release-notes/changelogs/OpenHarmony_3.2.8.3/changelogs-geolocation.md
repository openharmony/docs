# 位置服务子系统ChangeLog

## cl.location.1 系统API和API9接口迁移到新增的@ohos.geoLocationManager.d.ts

@ohos.geolocation.d.ts接口不支持抛出错误码，而API9和systemApi都需要支持抛出错误码，为了支持该功能，把@ohos.geolocation.d.ts中systemApi和API9所有接口，迁移到新增的@ohos.geoLocationManager.d.ts中，并增加错误码描述。

后续需要import @ohos.geoLocationManager才能使用位置服务的系统API和API9接口：

import geoLocationManager from '@ohos.geoLocationManager';


**变更影响**

仅对系统API和API9所有接口的使用有影响，需要import @ohos.geoLocationManager才能使用位置服务的系统API和API9接口：

import geoLocationManager from '@ohos.geoLocationManager';

对于其他接口无影响。

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
|geolocation| namespace | declare namespacegeolocation| API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation | interface | export interface ReverseGeocodingMockInfo  | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation | interface | export interface LocationMockConfig  | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation | interface | export interface CountryCode   | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation | enum | export enum CountryCodeType   | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation.GeoAddress | field | isFromMock?: Boolean; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation.Location  | field | isFromMock?: Boolean; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation.GeoLocationErrorCode  | field | NOT_SUPPORTED = 100 | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation.GeoLocationErrorCode  | field | QUERY_COUNTRY_CODE_ERROR | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function on(type: 'countryCodeChange', callback: Callback&lt;CountryCode&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function off(type: 'countryCodeChange', callback?: Callback&lt;CountryCode&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getCountryCode(callback: AsyncCallback&lt;CountryCode&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getCountryCode(): Promise&lt;CountryCode&gt;; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function enableLocationMock(scenario: LocationRequestScenario, callback: AsyncCallback&lt;void&gt;): void; | API9接口变更，该接口删除。 | 
|geolocation| method | function enableLocationMock(callback: AsyncCallback&lt;void&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function enableLocationMock(scenario: LocationRequestScenario): Promise&lt;void&gt;; | API9接口变更，该接口删除。 | 
|geolocation| method | function enableLocationMock(): Promise&lt;void&gt;; |  API9接口变更，迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function disableLocationMock(scenario: LocationRequestScenario, callback: AsyncCallback&lt;void&gt;): void; | API9接口变更，该接口删除。 | 
|geolocation| method | function disableLocationMock(callback: AsyncCallback&lt;void&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  | 
|geolocation| method | function disableLocationMock(scenario: LocationRequestScenario): Promise&lt;void&gt;; | API9接口变更，该接口删除。 | 
|geolocation| method | function disableLocationMock(): Promise&lt;void&gt;; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  | 
|geolocation| method | function setMockedLocations(config: LocationMockConfig, callback: AsyncCallback&lt;void&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  | 
|geolocation| method | function setMockedLocations(config: LocationMockConfig): Promise&lt;void&gt;; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  | 
|geolocation| method | function enableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  | 
|geolocation| method | function enableReverseGeocodingMock(): Promise&lt;void&gt;; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  | 
|geolocation| method | function disableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  | 
|geolocation| method | function disableReverseGeocodingMock(): Promise&lt;void&gt;; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  |
|geolocation| method | function setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;, callback: AsyncCallback&lt;void&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  |
|geolocation| method | function setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;): Promise&lt;void&gt;; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  |
|geolocation| method | function isLocationPrivacyConfirmed(type: LocationPrivacyType, callback: AsyncCallback&lt;boolean&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  |
|geolocation| method | function isLocationPrivacyConfirmed(type: LocationPrivacyType): Promise&lt;boolean&gt;; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts  |
|geolocation| method | function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean, callback: AsyncCallback&lt;boolean&gt;): void; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts，callback返回值改为void。  |
|geolocation| method | function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): Promise&lt;boolean&gt;; | API9接口变更，迁移到@ohos.geoLocationManager.d.ts，promise返回值改为void。  |

**适配指导（可选，不涉及则可以删除）**

以enableLocation为例，在新版本上需要使用如下方式进行调用：

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableLocation((err, data) => {
          if (err) {
              console.log('enableLocation: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## cl.location.2 位置服务权限变更

从API9开始，增加ohos.permission.APPROXIMATELY_LOCATION，表示模糊位置权限。

如果应用开发者使用的API版本大于等于9，则需要同时申请ohos.permission.LOCATION和ohos.permission.APPROXIMATELY_LOCATION，单独申请ohos.permission.LOCATION会失败。

**变更影响**

如果是存量应用（使用的API版本小于9），则无影响。如果使用的API版本大于等于9，位置服务权限申请方式有变更，详情如下：

应用在使用系统能力前，需要检查是否已经获取用户授权访问设备位置信息。如未获得授权，可以向用户申请需要的位置权限，申请方式请参考下文。

系统提供的定位权限有：

- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

访问设备的位置信息，必须申请权限，并且获得用户授权。

API9之前的版本，申请ohos.permission.LOCATION即可。

API9及之后的版本，需要申请ohos.permission.APPROXIMATELY_LOCATION或者同时申请ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION；无法单独申请ohos.permission.LOCATION。

| 使用的API版本 | 申请位置权限 | 申请结果 | 位置的精确度 |
| -------- | -------- | -------- | -------- |
| 小于9 | ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |
| 大于等于9 | ohos.permission.LOCATION | 失败 | 无法获取位置。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION | 成功 | 获取到模糊位置，精确度为5公里。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |

如果应用在后台运行时也需要访问设备位置，除需要将应用声明为允许后台运行外，还必须申请ohos.permission.LOCATION_IN_BACKGROUND权限，这样应用在切入后台之后，系统可以继续上报位置信息。

开发者可以在应用配置文件中声明所需要的权限，具体可参考[授权申请指导](../../../application-dev/security/accesstoken-guidelines.md)。

**关键的接口/组件变更**

如果是存量应用（使用的API版本小于9），则无影响。

如果使用的API版本大于等于9，则在使用@ohos.geolocation和@ohos.geoLocationManager中需要ohos.permission.LOCATION权限的接口时，都需要按照上文所述方式申请对应权限。
