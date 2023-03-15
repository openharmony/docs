# 位置服务子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，位置服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.geolocation | CountryCodeType | COUNTRY_CODE_FROM_NETWORK | 新增 |
| ohos.geolocation | CountryCodeType | COUNTRY_CODE_FROM_LOCATION | 新增 |
| ohos.geolocation | CountryCodeType | COUNTRY_CODE_FROM_SIM | 新增 |
| ohos.geolocation | CountryCodeType | COUNTRY_CODE_FROM_LOCALE = 1 | 新增 |
| ohos.geolocation | CountryCode | type: CountryCodeType; | 新增 |
| ohos.geolocation | CountryCode | country: string; | 新增 |
| ohos.geolocation | GeoLocationErrorCode | QUERY_COUNTRY_CODE_ERROR | 新增 |
| ohos.geolocation | GeoLocationErrorCode | NOT_SUPPORTED = 100 | 新增 |
| ohos.geolocation | Location | isFromMock: Boolean; | 新增 |
| ohos.geolocation | GeoAddress | isFromMock: Boolean; | 新增 |
| ohos.geolocation | LocationMockConfig | locations: Array\<Location>; | 新增 |
| ohos.geolocation | LocationMockConfig | timeInterval: number; | 新增 |
| ohos.geolocation | ReverseGeocodingMockInfo | geoAddress: GeoAddress; | 新增 |
| ohos.geolocation | ReverseGeocodingMockInfo | location: ReverseGeoCodeRequest; | 新增 |
| ohos.geolocation | geolocation | setReverseGeocodingMockInfo(mockInfos: Array\<ReverseGeocodingMockInfo>, callback: AsyncCallback\<void>) : void;<br>setReverseGeocodingMockInfo(mockInfos: Array\<ReverseGeocodingMockInfo>) : Promise\<void>; | 新增 |
| ohos.geolocation | geolocation | disableReverseGeocodingMock(callback: AsyncCallback\<void>) : void;<br>disableReverseGeocodingMock() : Promise\<void>; | 新增 |
| ohos.geolocation | geolocation | enableReverseGeocodingMock(callback: AsyncCallback\<void>) : void;<br>enableReverseGeocodingMock() : Promise\<void>; | 新增 |
| ohos.geolocation | geolocation | setMockedLocations(config: LocationMockConfig, callback: AsyncCallback\<void>) : void;<br>setMockedLocations(config: LocationMockConfig) : Promise\<void>; | 新增 |
| ohos.geolocation | geolocation | disableLocationMock(scenario?: LocationRequestScenario, callback: AsyncCallback\<void>) : void;<br>disableLocationMock(scenario?: LocationRequestScenario) : Promise\<void>; | 新增 |
| ohos.geolocation | geolocation | enableLocationMock(scenario?: LocationRequestScenario, callback: AsyncCallback\<void>) : void;<br>enableLocationMock(scenario?: LocationRequestScenario) : Promise\<void>; | 新增 |
| ohos.geolocation | geolocation | getCountryCode(callback: AsyncCallback\<CountryCode>) : void;<br>getCountryCode() : Promise\<CountryCode>; | 新增 |
| ohos.geolocation | geolocation | off(type: 'countryCodeChange', callback?: Callback\<CountryCode>) : void; | 新增 |
| ohos.geolocation | geolocation | on(type: 'countryCodeChange', callback: Callback\<CountryCode>) : void; | 新增 |

