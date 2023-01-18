# JS API Changes of the Location Subsystem

The table below lists the APIs changes of the location subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.geolocation | CountryCodeType | COUNTRY_CODE_FROM_NETWORK | Added|
| ohos.geolocation | CountryCodeType | COUNTRY_CODE_FROM_LOCATION | Added|
| ohos.geolocation | CountryCodeType | COUNTRY_CODE_FROM_SIM | Added|
| ohos.geolocation | CountryCodeType | COUNTRY_CODE_FROM_LOCALE = 1 | Added|
| ohos.geolocation | CountryCode | type: CountryCodeType; | Added|
| ohos.geolocation | CountryCode | country: string; | Added|
| ohos.geolocation | GeoLocationErrorCode | QUERY_COUNTRY_CODE_ERROR | Added|
| ohos.geolocation | GeoLocationErrorCode | NOT_SUPPORTED = 100 | Added|
| ohos.geolocation | Location | isFromMock: Boolean; | Added|
| ohos.geolocation | GeoAddress | isFromMock: Boolean; | Added|
| ohos.geolocation | LocationMockConfig | locations: Array\<Location>; | Added|
| ohos.geolocation | LocationMockConfig | timeInterval: number; | Added|
| ohos.geolocation | ReverseGeocodingMockInfo | geoAddress: GeoAddress; | Added|
| ohos.geolocation | ReverseGeocodingMockInfo | location: ReverseGeoCodeRequest; | Added|
| ohos.geolocation | geolocation | setReverseGeocodingMockInfo(mockInfos: Array\<ReverseGeocodingMockInfo>, callback: AsyncCallback\<void>) : void;<br>setReverseGeocodingMockInfo(mockInfos: Array\<ReverseGeocodingMockInfo>) : Promise\<void>; | Added|
| ohos.geolocation | geolocation | disableReverseGeocodingMock(callback: AsyncCallback\<void>) : void;<br>disableReverseGeocodingMock() : Promise\<void>; | Added|
| ohos.geolocation | geolocation | enableReverseGeocodingMock(callback: AsyncCallback\<void>) : void;<br>enableReverseGeocodingMock() : Promise\<void>; | Added|
| ohos.geolocation | geolocation | setMockedLocations(config: LocationMockConfig, callback: AsyncCallback\<void>) : void;<br>setMockedLocations(config: LocationMockConfig) : Promise\<void>; | Added|
| ohos.geolocation | geolocation | disableLocationMock(scenario?: LocationRequestScenario, callback: AsyncCallback\<void>) : void;<br>disableLocationMock(scenario?: LocationRequestScenario) : Promise\<void>; | Added|
| ohos.geolocation | geolocation | enableLocationMock(scenario?: LocationRequestScenario, callback: AsyncCallback\<void>) : void;<br>enableLocationMock(scenario?: LocationRequestScenario) : Promise\<void>; | Added|
| ohos.geolocation | geolocation | getCountryCode(callback: AsyncCallback\<CountryCode>) : void;<br>getCountryCode() : Promise\<CountryCode>; | Added|
| ohos.geolocation | geolocation | off(type: 'countryCodeChange', callback?: Callback\<CountryCode>) : void; | Added|
| ohos.geolocation | geolocation | on(type: 'countryCodeChange', callback: Callback\<CountryCode>) : void; | Added|
