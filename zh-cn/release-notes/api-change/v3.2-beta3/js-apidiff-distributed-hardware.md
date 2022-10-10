# 分布式硬件子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，分布式硬件子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.distributedHardware.deviceManager | DeviceManager | off(type: 'publishFail', callback?: Callback<{ publishId: number, reason: number }>): void; | 新增 |
| ohos.distributedHardware.deviceManager | DeviceManager | on(type: 'publishFail', callback: Callback<{ publishId: number, reason: number }>): void;   | 新增 |
| ohos.distributedHardware.deviceManager | DeviceManager | off(type: 'publishSuccess', callback?: Callback<{ publishId: number }>): void;              | 新增 |
| ohos.distributedHardware.deviceManager | DeviceManager | on(type: 'publishSuccess', callback: Callback<{ publishId: number }>): void;                | 新增 |
| ohos.distributedHardware.deviceManager | DeviceManager | unPublishDeviceDiscovery(publishId: number): void;                                          | 新增 |
| ohos.distributedHardware.deviceManager | DeviceManager | publishDeviceDiscovery(publishInfo: PublishInfo): void;                                     | 新增 |
| ohos.distributedHardware.deviceManager | PublishInfo   | ranging : boolean;                                                                          | 新增 |
| ohos.distributedHardware.deviceManager | PublishInfo   | freq: ExchangeFreq;                                                                         | 新增 |
| ohos.distributedHardware.deviceManager | PublishInfo   | mode: DiscoverMode;                                                                         | 新增 |
| ohos.distributedHardware.deviceManager | PublishInfo   | publishId: number;                                                                          | 新增 |
| ohos.distributedHardware.deviceManager | DeviceInfo    | range: number;                                                                              | 新增 |