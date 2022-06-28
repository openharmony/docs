# JS API Changes of the Location Subsystem

The table below lists the APIs changes of the location subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.geolocation | LocationCommand | command: string; | Added|
| ohos.geolocation | LocationCommand | scenario: LocationRequestScenario; | Added|
| ohos.geolocation | LocationPrivacyType | CORE_LOCATION | Added|
| ohos.geolocation | LocationPrivacyType | STARTUP | Added|
| ohos.geolocation | LocationPrivacyType | OTHERS = 0 | Added|
| ohos.geolocation | GeoLocationErrorCode | LOCATION_REQUEST_TIMEOUT_ERROR | Added|
| ohos.geolocation | GeoLocationErrorCode | LAST_KNOWN_LOCATION_ERROR | Added|
| ohos.geolocation | GeoLocationErrorCode | LOCATION_SWITCH_ERROR | Added|
| ohos.geolocation | GeoLocationErrorCode | LOCATOR_ERROR | Added|
| ohos.geolocation | GeoLocationErrorCode | GEOCODE_ERROR | Added|
| ohos.geolocation | GeoLocationErrorCode | REVERSE_GEOCODE_ERROR | Added|
| ohos.geolocation | GeoLocationErrorCode | INPUT_PARAMS_ERROR = 101 | Added|
| ohos.geolocation | LocationRequestScenario | NO_POWER | Added|
| ohos.geolocation | LocationRequestScenario | DAILY_LIFE_SERVICE | Added|
| ohos.geolocation | LocationRequestScenario | CAR_HAILING | Added|
| ohos.geolocation | LocationRequestScenario | TRAJECTORY_TRACKING | Added|
| ohos.geolocation | LocationRequestScenario | NAVIGATION | Added|
| ohos.geolocation | LocationRequestScenario | UNSET = 0x300 | Added|
| ohos.geolocation | LocationRequestPriority | FIRST_FIX | Added|
| ohos.geolocation | LocationRequestPriority | LOW_POWER | Added|
| ohos.geolocation | LocationRequestPriority | ACCURACY | Added|
| ohos.geolocation | LocationRequestPriority | UNSET = 0x200 | Added|
| ohos.geolocation | Location | additionSize?: number; | Added|
| ohos.geolocation | Location | additions?: Array\<string>; | Added|
| ohos.geolocation | Location | timeSinceBoot: number; | Added|
| ohos.geolocation | Location | direction: number; | Added|
| ohos.geolocation | Location | timeStamp: number; | Added|
| ohos.geolocation | Location | speed: number; | Added|
| ohos.geolocation | Location | accuracy: number; | Added|
| ohos.geolocation | Location | altitude: number; | Added|
| ohos.geolocation | Location | longitude: number; | Added|
| ohos.geolocation | Location | latitude: number; | Added|
| ohos.geolocation | CurrentLocationRequest | timeoutMs?: number; | Added|
| ohos.geolocation | CurrentLocationRequest | maxAccuracy?: number; | Added|
| ohos.geolocation | CurrentLocationRequest | scenario?: LocationRequestScenario; | Added|
| ohos.geolocation | CurrentLocationRequest | priority?: LocationRequestPriority; | Added|
| ohos.geolocation | LocationRequest | maxAccuracy?: number; | Added|
| ohos.geolocation | LocationRequest | distanceInterval?: number; | Added|
| ohos.geolocation | LocationRequest | timeInterval?: number; | Added|
| ohos.geolocation | LocationRequest | scenario?: LocationRequestScenario; | Added|
| ohos.geolocation | LocationRequest | priority?: LocationRequestPriority; | Added|
| ohos.geolocation | GeoAddress | descriptionsSize?: number; | Added|
| ohos.geolocation | GeoAddress | descriptions?: Array\<string>; | Added|
| ohos.geolocation | GeoAddress | addressUrl?: string; | Added|
| ohos.geolocation | GeoAddress | phoneNumber?: string; | Added|
| ohos.geolocation | GeoAddress | postalCode?: string; | Added|
| ohos.geolocation | GeoAddress | premises?: string; | Added|
| ohos.geolocation | GeoAddress | subRoadName?: string; | Added|
| ohos.geolocation | GeoAddress | roadName?: string; | Added|
| ohos.geolocation | GeoAddress | subLocality?: string; | Added|
| ohos.geolocation | GeoAddress | locality?: string; | Added|
| ohos.geolocation | GeoAddress | subAdministrativeArea?: string; | Added|
| ohos.geolocation | GeoAddress | administrativeArea?: string; | Added|
| ohos.geolocation | GeoAddress | countryName?: string; | Added|
| ohos.geolocation | GeoAddress | countryCode?: string; | Added|
| ohos.geolocation | GeoAddress | placeName?: string; | Added|
| ohos.geolocation | GeoAddress | locale?: string; | Added|
| ohos.geolocation | GeoAddress | longitude?: number; | Added|
| ohos.geolocation | GeoAddress | latitude?: number; | Added|
| ohos.geolocation | GeoCodeRequest | maxLongitude?: number; | Added|
| ohos.geolocation | GeoCodeRequest | maxLatitude?: number; | Added|
| ohos.geolocation | GeoCodeRequest | minLongitude?: number; | Added|
| ohos.geolocation | GeoCodeRequest | minLatitude?: number; | Added|
| ohos.geolocation | GeoCodeRequest | maxItems?: number; | Added|
| ohos.geolocation | GeoCodeRequest | description: string; | Added|
| ohos.geolocation | GeoCodeRequest | locale?: string; | Added|
| ohos.geolocation | ReverseGeoCodeRequest | maxItems?: number; | Added|
| ohos.geolocation | ReverseGeoCodeRequest | longitude: number; | Added|
| ohos.geolocation | ReverseGeoCodeRequest | latitude: number; | Added|
| ohos.geolocation | ReverseGeoCodeRequest | locale?: string; | Added|
| ohos.geolocation | Geofence | expiration: number; | Added|
| ohos.geolocation | Geofence | radius: number; | Added|
| ohos.geolocation | Geofence | longitude: number; | Added|
| ohos.geolocation | Geofence | latitude: number; | Added|
| ohos.geolocation | GeofenceRequest | geofence: Geofence; | Added|
| ohos.geolocation | GeofenceRequest | scenario: LocationRequestScenario; | Added|
| ohos.geolocation | GeofenceRequest | priority: LocationRequestPriority; | Added|
| ohos.geolocation | CachedGnssLocationsRequest | wakeUpCacheQueueFull: boolean; | Added|
| ohos.geolocation | CachedGnssLocationsRequest | reportingPeriodSec: number; | Added|
| ohos.geolocation | SatelliteStatusInfo | carrierFrequencies: Array\<number>; | Added|
| ohos.geolocation | SatelliteStatusInfo | azimuths: Array\<number>; | Added|
| ohos.geolocation | SatelliteStatusInfo | altitudes: Array\<number>; | Added|
| ohos.geolocation | SatelliteStatusInfo | carrierToNoiseDensitys: Array\<number>; | Added|
| ohos.geolocation | SatelliteStatusInfo | satelliteIds: Array\<number>; | Added|
| ohos.geolocation | SatelliteStatusInfo | satellitesNumber: number; | Added|
| ohos.geolocation | geolocation | sendCommand(command: LocationCommand, callback: AsyncCallback\<boolean>) : void;<br>sendCommand(command: LocationCommand) : Promise\<boolean>; | Added|
| ohos.geolocation | geolocation | flushCachedGnssLocations(callback: AsyncCallback\<boolean>) : void;<br>flushCachedGnssLocations() : Promise\<boolean>; | Added|
| ohos.geolocation | geolocation | getCachedGnssLocationsSize(callback: AsyncCallback\<number>) : void;<br>getCachedGnssLocationsSize() : Promise\<number>; | Added|
| ohos.geolocation | geolocation | isGeoServiceAvailable(callback: AsyncCallback\<boolean>) : void;<br>isGeoServiceAvailable() : Promise\<boolean>; | Added|
| ohos.geolocation | geolocation | getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>) : void;<br>getAddressesFromLocationName(request: GeoCodeRequest) : Promise\<Array\<GeoAddress>>; | Added|
| ohos.geolocation | geolocation | getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>) : void;<br>getAddressesFromLocation(request: ReverseGeoCodeRequest) : Promise\<Array\<GeoAddress>>; | Added|
| ohos.geolocation | geolocation | requestEnableLocation(callback: AsyncCallback\<boolean>) : void;<br>requestEnableLocation() : Promise\<boolean>; | Added|
| ohos.geolocation | geolocation | isLocationEnabled(callback: AsyncCallback\<boolean>) : void;<br>isLocationEnabled() : Promise\<boolean>; | Added|
| ohos.geolocation | geolocation | getLastLocation(callback: AsyncCallback\<Location>) : void;<br>getLastLocation() : Promise\<Location>; | Added|
| ohos.geolocation | geolocation | getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>) : void;<br>getCurrentLocation(callback: AsyncCallback\<Location>) : void;<br>getCurrentLocation(request?: CurrentLocationRequest) : Promise\<Location>; | Added|
| ohos.geolocation | geolocation | off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void; | Added|
| ohos.geolocation | geolocation | on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void; | Added|
| ohos.geolocation | geolocation | off(type: 'nmeaMessageChange', callback?: Callback\<string>) : void; | Added|
| ohos.geolocation | geolocation | on(type: 'nmeaMessageChange', callback: Callback\<string>) : void; | Added|
| ohos.geolocation | geolocation | off(type: 'gnssStatusChange', callback?: Callback\<SatelliteStatusInfo>) : void; | Added|
| ohos.geolocation | geolocation | on(type: 'gnssStatusChange', callback: Callback\<SatelliteStatusInfo>) : void; | Added|
| ohos.geolocation | geolocation | off(type: 'cachedGnssLocationsReporting', callback?: Callback\<Array\<Location>>) : void; | Added|
| ohos.geolocation | geolocation | on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>) : void; | Added|
| ohos.geolocation | geolocation | off(type: 'locationServiceState', callback?: Callback\<boolean>) : void; | Added|
| ohos.geolocation | geolocation | on(type: 'locationServiceState', callback: Callback\<boolean>) : void; | Added|
| ohos.geolocation | geolocation | off(type: 'locationChange', callback?: Callback\<Location>) : void; | Added|
| ohos.geolocation | geolocation | on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>) : void; | Added|
