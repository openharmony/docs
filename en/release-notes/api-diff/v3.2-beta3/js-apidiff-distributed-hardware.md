# JS API Changes of the Distributed Hardware Subsystem

The table below lists the APIs changes of the distributed hardware subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.distributedHardware.deviceManager | DeviceManager | off(type: 'publishFail', callback?: Callback<{ publishId: number, reason: number }>): void; | Added|
| ohos.distributedHardware.deviceManager | DeviceManager | on(type: 'publishFail', callback: Callback<{ publishId: number, reason: number }>): void;   | Added|
| ohos.distributedHardware.deviceManager | DeviceManager | off(type: 'publishSuccess', callback?: Callback<{ publishId: number }>): void;              | Added|
| ohos.distributedHardware.deviceManager | DeviceManager | on(type: 'publishSuccess', callback: Callback<{ publishId: number }>): void;                | Added|
| ohos.distributedHardware.deviceManager | DeviceManager | unPublishDeviceDiscovery(publishId: number): void;                                          | Added|
| ohos.distributedHardware.deviceManager | DeviceManager | publishDeviceDiscovery(publishInfo: PublishInfo): void;                                     | Added|
| ohos.distributedHardware.deviceManager | PublishInfo   | ranging : boolean;                                                                          | Added|
| ohos.distributedHardware.deviceManager | PublishInfo   | freq: ExchangeFreq;                                                                         | Added|
| ohos.distributedHardware.deviceManager | PublishInfo   | mode: DiscoverMode;                                                                         | Added|
| ohos.distributedHardware.deviceManager | PublishInfo   | publishId: number;                                                                          | Added|
| ohos.distributedHardware.deviceManager | DeviceInfo    | range: number;                                                                              | Added|
