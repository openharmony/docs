# JS API Changes of the Distributed Hardware Subsystem

The table below lists the APIs changes of the Distributed Data Management subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module | API | Change Type | Change Description |
|  --------  |  --------  |  --------  |  --------  |
| Distributed Hardware Subsystem - DeviceManager| release(): void | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| getTrustedDeviceListSync(): Array\<DeviceInfo> | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| on(type: 'deviceStateChange', callback: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| off(type: 'deviceStateChange', callback?: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| on(type: 'serviceDie', callback: () => void): void | Deleted| This API is deleted to reduce security risks.|
| Distributed Hardware Subsystem - DeviceManager| off(type: 'serviceDie', callback?: () => void): void | Deleted| This API is deleted to reduce security risks.|
