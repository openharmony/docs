| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: GeoLocationErrorCode<br>Method or attribute name: INPUT_PARAMS_ERROR|@ohos.geolocation.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function off(type: 'locationChange', callback?: Callback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function on(type: 'locationEnabledChange', callback: Callback\<boolean>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function off(type: 'locationEnabledChange', callback?: Callback\<boolean>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function off(type: 'cachedGnssLocationsChange', callback?: Callback\<Array\<Location>>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function on(type: 'satelliteStatusChange', callback: Callback\<SatelliteStatusInfo>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function off(type: 'satelliteStatusChange', callback?: Callback\<SatelliteStatusInfo>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function on(type: 'nmeaMessage', callback: Callback\<string>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function off(type: 'nmeaMessage', callback?: Callback\<string>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function on(type: 'countryCodeChange', callback: Callback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function off(type: 'countryCodeChange', callback?: Callback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getCurrentLocation(callback: AsyncCallback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getLastLocation(): Location;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function isLocationEnabled(): boolean;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function enableLocation(callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function enableLocation(): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function disableLocation(): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function isGeocoderAvailable(): boolean;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getCachedGnssLocationsSize(callback: AsyncCallback\<number>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getCachedGnssLocationsSize(): Promise\<number>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function flushCachedGnssLocations(callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function flushCachedGnssLocations(): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function sendCommand(command: LocationCommand, callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function sendCommand(command: LocationCommand): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getCountryCode(callback: AsyncCallback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function getCountryCode(): Promise\<CountryCode>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function enableLocationMock(): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function disableLocationMock(): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function setMockedLocations(config: LocationMockConfig): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function enableReverseGeocodingMock(): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function disableReverseGeocodingMock(): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function setReverseGeocodingMockInfo(mockInfos: Array\<ReverseGeocodingMockInfo>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: geoLocationManager<br>Method or attribute name: function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: ReverseGeocodingMockInfo|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: ReverseGeocodingMockInfo<br>Method or attribute name: location: ReverseGeoCodeRequest;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: ReverseGeocodingMockInfo<br>Method or attribute name: geoAddress: GeoAddress;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationMockConfig|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationMockConfig<br>Method or attribute name: timeInterval: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationMockConfig<br>Method or attribute name: locations: Array\<Location>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: SatelliteStatusInfo|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: SatelliteStatusInfo<br>Method or attribute name: satellitesNumber: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: SatelliteStatusInfo<br>Method or attribute name: satelliteIds: Array\<number>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: SatelliteStatusInfo<br>Method or attribute name: carrierToNoiseDensitys: Array\<number>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: SatelliteStatusInfo<br>Method or attribute name: altitudes: Array\<number>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: SatelliteStatusInfo<br>Method or attribute name: azimuths: Array\<number>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: SatelliteStatusInfo<br>Method or attribute name: carrierFrequencies: Array\<number>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CachedGnssLocationsRequest|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CachedGnssLocationsRequest<br>Method or attribute name: reportingPeriodSec: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CachedGnssLocationsRequest<br>Method or attribute name: wakeUpCacheQueueFull: boolean;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeofenceRequest|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeofenceRequest<br>Method or attribute name: scenario: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeofenceRequest<br>Method or attribute name: geofence: Geofence;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Geofence|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Geofence<br>Method or attribute name: latitude: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Geofence<br>Method or attribute name: longitude: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Geofence<br>Method or attribute name: radius: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Geofence<br>Method or attribute name: expiration: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: ReverseGeoCodeRequest|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: ReverseGeoCodeRequest<br>Method or attribute name: locale?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: ReverseGeoCodeRequest<br>Method or attribute name: latitude: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: ReverseGeoCodeRequest<br>Method or attribute name: longitude: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: ReverseGeoCodeRequest<br>Method or attribute name: maxItems?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoCodeRequest|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoCodeRequest<br>Method or attribute name: locale?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoCodeRequest<br>Method or attribute name: description: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoCodeRequest<br>Method or attribute name: maxItems?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoCodeRequest<br>Method or attribute name: minLatitude?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoCodeRequest<br>Method or attribute name: minLongitude?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoCodeRequest<br>Method or attribute name: maxLatitude?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoCodeRequest<br>Method or attribute name: maxLongitude?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: latitude?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: longitude?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: locale?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: placeName?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: countryCode?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: countryName?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: administrativeArea?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: subAdministrativeArea?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: locality?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: subLocality?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: roadName?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: subRoadName?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: premises?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: postalCode?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: phoneNumber?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: addressUrl?: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: descriptions?: Array\<string>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: descriptionsSize?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: GeoAddress<br>Method or attribute name: isFromMock?: Boolean;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequest|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequest<br>Method or attribute name: priority?: LocationRequestPriority;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequest<br>Method or attribute name: scenario?: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequest<br>Method or attribute name: timeInterval?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequest<br>Method or attribute name: distanceInterval?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequest<br>Method or attribute name: maxAccuracy?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CurrentLocationRequest|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CurrentLocationRequest<br>Method or attribute name: priority?: LocationRequestPriority;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CurrentLocationRequest<br>Method or attribute name: scenario?: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CurrentLocationRequest<br>Method or attribute name: maxAccuracy?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CurrentLocationRequest<br>Method or attribute name: timeoutMs?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: latitude: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: longitude: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: altitude: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: accuracy: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: speed: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: timeStamp: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: direction: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: timeSinceBoot: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: additions?: Array\<string>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: additionSize?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: Location<br>Method or attribute name: isFromMock?: Boolean;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestPriority|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestPriority<br>Method or attribute name: UNSET = 0x200|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestPriority<br>Method or attribute name: ACCURACY|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestPriority<br>Method or attribute name: LOW_POWER|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestPriority<br>Method or attribute name: FIRST_FIX|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestScenario|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestScenario<br>Method or attribute name: UNSET = 0x300|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestScenario<br>Method or attribute name: NAVIGATION|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestScenario<br>Method or attribute name: TRAJECTORY_TRACKING|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestScenario<br>Method or attribute name: CAR_HAILING|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestScenario<br>Method or attribute name: DAILY_LIFE_SERVICE|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationRequestScenario<br>Method or attribute name: NO_POWER|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationPrivacyType|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationPrivacyType<br>Method or attribute name: OTHERS = 0|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationPrivacyType<br>Method or attribute name: STARTUP|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationPrivacyType<br>Method or attribute name: CORE_LOCATION|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationCommand|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationCommand<br>Method or attribute name: scenario: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: LocationCommand<br>Method or attribute name: command: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CountryCode|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CountryCode<br>Method or attribute name: country: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CountryCode<br>Method or attribute name: type: CountryCodeType;|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CountryCodeType|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CountryCodeType<br>Method or attribute name: COUNTRY_CODE_FROM_LOCALE = 1|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CountryCodeType<br>Method or attribute name: COUNTRY_CODE_FROM_SIM|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CountryCodeType<br>Method or attribute name: COUNTRY_CODE_FROM_LOCATION|@ohos.geoLocationManager.d.ts|
|Added|NA|Module name: ohos.geoLocationManager<br>Class name: CountryCodeType<br>Method or attribute name: COUNTRY_CODE_FROM_NETWORK|@ohos.geoLocationManager.d.ts|
|Deleted|Module name: ohos.geolocation<br>Class name: geolocation<br>Method or attribute name: function enableLocation(callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|Deleted|Module name: ohos.geolocation<br>Class name: geolocation<br>Method or attribute name: function enableLocation() : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|Deleted|Module name: ohos.geolocation<br>Class name: geolocation<br>Method or attribute name: function disableLocation(callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|Deleted|Module name: ohos.geolocation<br>Class name: geolocation<br>Method or attribute name: function disableLocation() : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|Deleted|Module name: ohos.geolocation<br>Class name: geolocation<br>Method or attribute name: function isLocationPrivacyConfirmed(type : LocationPrivacyType, callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|Deleted|Module name: ohos.geolocation<br>Class name: geolocation<br>Method or attribute name: function isLocationPrivacyConfirmed(type : LocationPrivacyType,) : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|Deleted|Module name: ohos.geolocation<br>Class name: geolocation<br>Method or attribute name: function setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean, callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|Deleted|Module name: ohos.geolocation<br>Class name: geolocation<br>Method or attribute name: function setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean) : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: geolocation<br>Deprecated version: N/A|Class name: geolocation<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: SatelliteStatusInfo<br>Deprecated version: N/A|Class name: SatelliteStatusInfo<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: CachedGnssLocationsRequest<br>Deprecated version: N/A|Class name: CachedGnssLocationsRequest<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.CachedGnssLocationsRequest     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: GeofenceRequest<br>Deprecated version: N/A|Class name: GeofenceRequest<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.GeofenceRequest     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: Geofence<br>Deprecated version: N/A|Class name: Geofence<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.Geofence     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: ReverseGeoCodeRequest<br>Deprecated version: N/A|Class name: ReverseGeoCodeRequest<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.ReverseGeoCodeRequest     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: GeoCodeRequest<br>Deprecated version: N/A|Class name: GeoCodeRequest<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.GeoCodeRequest     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: GeoAddress<br>Deprecated version: N/A|Class name: GeoAddress<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.GeoAddress     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: LocationRequest<br>Deprecated version: N/A|Class name: LocationRequest<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.LocationRequest     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: CurrentLocationRequest<br>Deprecated version: N/A|Class name: CurrentLocationRequest<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: Location<br>Deprecated version: N/A|Class name: Location<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.Location     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: LocationRequestPriority<br>Deprecated version: N/A|Class name: LocationRequestPriority<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.LocationRequestPriority     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: LocationRequestScenario<br>Deprecated version: N/A|Class name: LocationRequestScenario<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.LocationRequestScenario     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: GeoLocationErrorCode<br>Deprecated version: N/A|Class name: GeoLocationErrorCode<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: LocationPrivacyType<br>Deprecated version: N/A|Class name: LocationPrivacyType<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.LocationPrivacyType     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: LocationCommand<br>Deprecated version: N/A|Class name: LocationCommand<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.LocationCommand     |@ohos.geolocation.d.ts|
|Deprecated version changed|Class name: GeolocationResponse<br>Deprecated version: N/A|Class name: GeolocationResponse<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.Location |@system.geolocation.d.ts|
|Deprecated version changed|Class name: GetLocationOption<br>Deprecated version: N/A|Class name: GetLocationOption<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest |@system.geolocation.d.ts|
|Deprecated version changed|Class name: GetLocationTypeResponse<br>Deprecated version: N/A|Class name: GetLocationTypeResponse<br>Deprecated version: 9<br>Substitute API: N/A|@system.geolocation.d.ts|
|Deprecated version changed|Class name: GetLocationTypeOption<br>Deprecated version: N/A|Class name: GetLocationTypeOption<br>Deprecated version: 9<br>Substitute API: N/A|@system.geolocation.d.ts|
|Deprecated version changed|Class name: SubscribeLocationOption<br>Deprecated version: N/A|Class name: SubscribeLocationOption<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.LocationRequest |@system.geolocation.d.ts|
|Deprecated version changed|Class name: Geolocation<br>Deprecated version: N/A|Class name: Geolocation<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager |@system.geolocation.d.ts|
|Deprecated version changed|Class name: Geolocation<br>Method or attribute name: static getLocation(options?: GetLocationOption): void;<br>Deprecated version: N/A|Class name: Geolocation<br>Method or attribute name: static getLocation(options?: GetLocationOption): void;<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.getCurrentLocation   |@system.geolocation.d.ts|
|Deprecated version changed|Class name: Geolocation<br>Method or attribute name: static getLocationType(options?: GetLocationTypeOption): void;<br>Deprecated version: N/A|Class name: Geolocation<br>Method or attribute name: static getLocationType(options?: GetLocationTypeOption): void;<br>Deprecated version: 9<br>Substitute API: N/A|@system.geolocation.d.ts|
|Deprecated version changed|Class name: Geolocation<br>Method or attribute name: static subscribe(options: SubscribeLocationOption): void;<br>Deprecated version: N/A|Class name: Geolocation<br>Method or attribute name: static subscribe(options: SubscribeLocationOption): void;<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.on|@system.geolocation.d.ts|
|Deprecated version changed|Class name: Geolocation<br>Method or attribute name: static unsubscribe(): void;<br>Deprecated version: N/A|Class name: Geolocation<br>Method or attribute name: static unsubscribe(): void;<br>Deprecated version: 9<br>Substitute API: ohos.geoLocationManager/geoLocationManager.off|@system.geolocation.d.ts|
|Deprecated version changed|Class name: Geolocation<br>Method or attribute name: static getSupportedCoordTypes(): Array\<string>;<br>Deprecated version: N/A|Class name: Geolocation<br>Method or attribute name: static getSupportedCoordTypes(): Array\<string>;<br>Deprecated version: 9<br>Substitute API: N/A|@system.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: latitude?: number;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: latitude?: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: longitude?: number;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: longitude?: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: locale?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: locale?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: placeName?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: placeName?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: countryCode?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: countryCode?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: countryName?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: countryName?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: administrativeArea?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: administrativeArea?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: subAdministrativeArea?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: subAdministrativeArea?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: locality?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: locality?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: subLocality?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: subLocality?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: roadName?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: roadName?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: subRoadName?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: subRoadName?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: premises?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: premises?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: postalCode?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: postalCode?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: phoneNumber?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: phoneNumber?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: addressUrl?: string;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: addressUrl?: string;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: descriptions?: Array\<string>;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: descriptions?: Array\<string>;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoAddress<br>Method or attribute name: descriptionsSize?: number;<br>Initial version: N/A|Class name: GeoAddress<br>Method or attribute name: descriptionsSize?: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: latitude: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: latitude: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: longitude: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: longitude: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: altitude: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: altitude: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: accuracy: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: accuracy: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: speed: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: speed: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: timeStamp: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: timeStamp: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: direction: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: direction: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: timeSinceBoot: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: timeSinceBoot: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: additions?: Array\<string>;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: additions?: Array\<string>;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: Location<br>Method or attribute name: additionSize?: number;<br>Initial version: N/A|Class name: Location<br>Method or attribute name: additionSize?: number;<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoLocationErrorCode<br>Method or attribute name: REVERSE_GEOCODE_ERROR<br>Initial version: N/A|Class name: GeoLocationErrorCode<br>Method or attribute name: REVERSE_GEOCODE_ERROR<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoLocationErrorCode<br>Method or attribute name: GEOCODE_ERROR<br>Initial version: N/A|Class name: GeoLocationErrorCode<br>Method or attribute name: GEOCODE_ERROR<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoLocationErrorCode<br>Method or attribute name: LOCATOR_ERROR<br>Initial version: N/A|Class name: GeoLocationErrorCode<br>Method or attribute name: LOCATOR_ERROR<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoLocationErrorCode<br>Method or attribute name: LOCATION_SWITCH_ERROR<br>Initial version: N/A|Class name: GeoLocationErrorCode<br>Method or attribute name: LOCATION_SWITCH_ERROR<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoLocationErrorCode<br>Method or attribute name: LAST_KNOWN_LOCATION_ERROR<br>Initial version: N/A|Class name: GeoLocationErrorCode<br>Method or attribute name: LAST_KNOWN_LOCATION_ERROR<br>Initial version: 7|@ohos.geolocation.d.ts|
|Initial version changed|Class name: GeoLocationErrorCode<br>Method or attribute name: LOCATION_REQUEST_TIMEOUT_ERROR<br>Initial version: N/A|Class name: GeoLocationErrorCode<br>Method or attribute name: LOCATION_REQUEST_TIMEOUT_ERROR<br>Initial version: 7|@ohos.geolocation.d.ts|
