# JS API Diff

This document describes the changes of APIs in OpenHarmony 3.1 LTS when compared with OpenHarmony 3.1 Beta.

## API Changes

| Module| API| Change Type| Change Description|
|  --------  |  --------  |  --------  |  --------  |
| Distributed Hardware Subsystem - DeviceManager| release(): void | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| getTrustedDeviceListSync(): Array<DeviceInfo> | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| on(type: 'deviceStateChange', callback: Callback<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| off(type: 'deviceStateChange', callback?: Call back<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| on(type: 'serviceDie', callback: () => void): void | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| off(type: 'serviceDie', callback?: () => void): void | Deleted| This API is deleted to reduce security risks.|
