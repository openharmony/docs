# USB服务子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，USB服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.usb | FunctionType | NCM = 256 | 新增 |
| ohos.usb | FunctionType | AUDIO_SOURCE = 128 | 新增 |
| ohos.usb | FunctionType | MIDI = 64 | 新增 |
| ohos.usb | FunctionType | RNDIS = 32 | 新增 |
| ohos.usb | FunctionType | PTP = 16 | 新增 |
| ohos.usb | FunctionType | MTP = 8 | 新增 |
| ohos.usb | FunctionType | HDC = 4 | 新增 |
| ohos.usb | FunctionType | ECM = 2 | 新增 |
| ohos.usb | FunctionType | ACM = 1 | 新增 |
| ohos.usb | FunctionType | NONE = 0 | 新增 |
| ohos.usb | USBPort | status: USBPortStatus; | 新增 |
| ohos.usb | USBPort | supportedModes: PortModeType; | 新增 |
| ohos.usb | USBPort | id: number; | 新增 |
| ohos.usb | USBPortStatus | currentDataRole: number; | 新增 |
| ohos.usb | USBPortStatus | currentPowerRole: number; | 新增 |
| ohos.usb | USBPortStatus | currentMode: number; | 新增 |
| ohos.usb | PortModeType | NUM_MODES = 4 | 新增 |
| ohos.usb | PortModeType | DRP = 3 | 新增 |
| ohos.usb | PortModeType | DFP = 2 | 新增 |
| ohos.usb | PortModeType | UFP = 1 | 新增 |
| ohos.usb | PortModeType | NONE = 0 | 新增 |
| ohos.usb | DataRoleType | DEVICE = 2 | 新增 |
| ohos.usb | DataRoleType | HOST = 1 | 新增 |
| ohos.usb | DataRoleType | NONE = 0 | 新增 |
| ohos.usb | PowerRoleType | SINK = 2 | 新增 |
| ohos.usb | PowerRoleType | SOURCE = 1 | 新增 |
| ohos.usb | PowerRoleType | NONE = 0 | 新增 |
| ohos.usb | usb | setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean>; | 新增 |
| ohos.usb | usb | getSupportedModes(portId: number): PortModeType; | 新增 |
| ohos.usb | usb | getPorts(): Array\<USBPort>; | 新增 |
| ohos.usb | usb | getCurrentFunctions(): FunctionType; | 新增 |
| ohos.usb | usb | setCurrentFunctions(funcs: FunctionType): Promise\<boolean>; | 新增 |
| ohos.usb | usb | usbFunctionsToString(funcs: FunctionType): string; | 新增 |
| ohos.usb | usb | usbFunctionsFromString(funcs: string): number; | 新增 |
