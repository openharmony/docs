# JS API Changes of the USB Subsystem

The table below lists the APIs changes of the USB subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.usb | FunctionType | NCM = 256 | Added|
| ohos.usb | FunctionType | AUDIO_SOURCE = 128 | Added|
| ohos.usb | FunctionType | MIDI = 64 | Added|
| ohos.usb | FunctionType | RNDIS = 32 | Added|
| ohos.usb | FunctionType | PTP = 16 | Added|
| ohos.usb | FunctionType | MTP = 8 | Added|
| ohos.usb | FunctionType | HDC = 4 | Added|
| ohos.usb | FunctionType | ECM = 2 | Added|
| ohos.usb | FunctionType | ACM = 1 | Added|
| ohos.usb | FunctionType | NONE = 0 | Added|
| ohos.usb | USBPort | status: USBPortStatus; | Added|
| ohos.usb | USBPort | supportedModes: PortModeType; | Added|
| ohos.usb | USBPort | id: number; | Added|
| ohos.usb | USBPortStatus | currentDataRole: number; | Added|
| ohos.usb | USBPortStatus | currentPowerRole: number; | Added|
| ohos.usb | USBPortStatus | currentMode: number; | Added|
| ohos.usb | PortModeType | NUM_MODES = 4 | Added|
| ohos.usb | PortModeType | DRP = 3 | Added|
| ohos.usb | PortModeType | DFP = 2 | Added|
| ohos.usb | PortModeType | UFP = 1 | Added|
| ohos.usb | PortModeType | NONE = 0 | Added|
| ohos.usb | DataRoleType | DEVICE = 2 | Added|
| ohos.usb | DataRoleType | HOST = 1 | Added|
| ohos.usb | DataRoleType | NONE = 0 | Added|
| ohos.usb | PowerRoleType | SINK = 2 | Added|
| ohos.usb | PowerRoleType | SOURCE = 1 | Added|
| ohos.usb | PowerRoleType | NONE = 0 | Added|
| ohos.usb | usb | setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean>; | Added|
| ohos.usb | usb | getSupportedModes(portId: number): PortModeType; | Added|
| ohos.usb | usb | getPorts(): Array\<USBPort>; | Added|
| ohos.usb | usb | getCurrentFunctions(): FunctionType; | Added|
| ohos.usb | usb | setCurrentFunctions(funcs: FunctionType): Promise\<boolean>; | Added|
| ohos.usb | usb | usbFunctionsToString(funcs: FunctionType): string; | Added|
| ohos.usb | usb | usbFunctionsFromString(funcs: string): number; | Added|
