# 分布式硬件子系统JS API变更

OpenHarmony 3.1 LTS版本相较于OpenHarmony 3.1 Beta版本的API变更如下:

## 接口变更

| 模块名称  | 接口名称  | 变更类型  | 变更说明  |
|  --------  |  --------  |  --------  |  --------  |
| 分布式硬件子系统-DeviceManager | release(): void | 删除 | 为了降低安全风险，删除设备管理JS API |
| 分布式硬件子系统-DeviceManager | getTrustedDeviceListSync(): Array\<DeviceInfo> | 删除 | 为了降低安全风险，删除设备管理JS API |
| 分布式硬件子系统-DeviceManager | on(type: 'deviceStateChange', callback: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void | 删除 | 为了降低安全风险，删除设备管理JS API |
| 分布式硬件子系统-DeviceManager | off(type: 'deviceStateChange', callback?: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void | 删除 | 为了降低安全风险，删除设备管理JS API |
| 分布式硬件子系统-DeviceManager | on(type: 'serviceDie', callback: () => void): void | 删除 | 为了降低安全风险，删除设备管理JS API |
| 分布式硬件子系统-DeviceManager | off(type: 'serviceDie', callback?: () => void): void | 删除 | 为了降低安全风险，删除设备管理JS API |