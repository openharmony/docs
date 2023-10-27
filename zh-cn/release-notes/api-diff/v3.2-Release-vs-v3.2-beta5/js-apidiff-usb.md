| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function getDevices(): Array\<Readonly\<USBDevice>>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function hasRight(deviceName: string): boolean;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function requestRight(deviceName: string): Promise\<boolean>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function removeRight(deviceName: string): boolean;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function addRight(bundleName: string, deviceName: string): boolean;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function usbFunctionsFromString(funcs: string): number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function usbFunctionsToString(funcs: FunctionType): string;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function setCurrentFunctions(funcs: FunctionType): Promise\<void>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function getCurrentFunctions(): FunctionType;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function getPorts(): Array\<USBPort>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function getSupportedModes(portId: number): PortModeType;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function getFileDescriptor(pipe: USBDevicePipe): number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: usbManager<br>方法 or 属性: function closePipe(pipe: USBDevicePipe): number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint<br>方法 or 属性: address: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint<br>方法 or 属性: attributes: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint<br>方法 or 属性: interval: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint<br>方法 or 属性: maxPacketSize: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint<br>方法 or 属性: direction: USBRequestDirection;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint<br>方法 or 属性: number: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint<br>方法 or 属性: type: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBEndpoint<br>方法 or 属性: interfaceId: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBInterface|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBInterface<br>方法 or 属性: id: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBInterface<br>方法 or 属性: protocol: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBInterface<br>方法 or 属性: clazz: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBInterface<br>方法 or 属性: subClass: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBInterface<br>方法 or 属性: alternateSetting: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBInterface<br>方法 or 属性: name: string;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBInterface<br>方法 or 属性: endpoints: Array\<USBEndpoint>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBConfiguration|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBConfiguration<br>方法 or 属性: id: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBConfiguration<br>方法 or 属性: attributes: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBConfiguration<br>方法 or 属性: maxPower: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBConfiguration<br>方法 or 属性: name: string;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBConfiguration<br>方法 or 属性: isRemoteWakeup: boolean;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBConfiguration<br>方法 or 属性: isSelfPowered: boolean;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBConfiguration<br>方法 or 属性: interfaces: Array\<USBInterface>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: busNum: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: devAddress: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: serial: string;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: name: string;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: manufacturerName: string;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: productName: string;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: version: string;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: vendorId: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: productId: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: clazz: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: subClass: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: protocol: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevice<br>方法 or 属性: configs: Array\<USBConfiguration>;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevicePipe|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevicePipe<br>方法 or 属性: busNum: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBDevicePipe<br>方法 or 属性: devAddress: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PowerRoleType|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PowerRoleType<br>方法 or 属性: NONE = 0|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PowerRoleType<br>方法 or 属性: SOURCE = 1|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PowerRoleType<br>方法 or 属性: SINK = 2|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: DataRoleType|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: DataRoleType<br>方法 or 属性: NONE = 0|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: DataRoleType<br>方法 or 属性: HOST = 1|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: DataRoleType<br>方法 or 属性: DEVICE = 2|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PortModeType|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PortModeType<br>方法 or 属性: NONE = 0|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PortModeType<br>方法 or 属性: UFP = 1|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PortModeType<br>方法 or 属性: DFP = 2|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PortModeType<br>方法 or 属性: DRP = 3|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: PortModeType<br>方法 or 属性: NUM_MODES = 4|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBPortStatus|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBPortStatus<br>方法 or 属性: currentMode: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBPortStatus<br>方法 or 属性: currentPowerRole: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBPortStatus<br>方法 or 属性: currentDataRole: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBPort|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBPort<br>方法 or 属性: id: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBPort<br>方法 or 属性: supportedModes: PortModeType;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBPort<br>方法 or 属性: status: USBPortStatus;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlParams|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlParams<br>方法 or 属性: request: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlParams<br>方法 or 属性: target: USBRequestTargetType;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlParams<br>方法 or 属性: reqType: USBControlRequestType;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlParams<br>方法 or 属性: value: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlParams<br>方法 or 属性: index: number;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlParams<br>方法 or 属性: data: Uint8Array;|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBRequestTargetType|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBRequestTargetType<br>方法 or 属性: USB_REQUEST_TARGET_DEVICE = 0|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBRequestTargetType<br>方法 or 属性: USB_REQUEST_TARGET_INTERFACE = 1|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBRequestTargetType<br>方法 or 属性: USB_REQUEST_TARGET_ENDPOINT = 2|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBRequestTargetType<br>方法 or 属性: USB_REQUEST_TARGET_OTHER = 3|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlRequestType|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlRequestType<br>方法 or 属性: USB_REQUEST_TYPE_STANDARD = 0|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlRequestType<br>方法 or 属性: USB_REQUEST_TYPE_CLASS = 1|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBControlRequestType<br>方法 or 属性: USB_REQUEST_TYPE_VENDOR = 2|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBRequestDirection|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBRequestDirection<br>方法 or 属性: USB_REQUEST_DIR_TO_DEVICE = 0|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: USBRequestDirection<br>方法 or 属性: USB_REQUEST_DIR_FROM_DEVICE = 0x80|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: NONE = 0|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: ACM = 1|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: ECM = 2|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: HDC = 4|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: MTP = 8|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: PTP = 16|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: RNDIS = 32|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: MIDI = 64|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: AUDIO_SOURCE = 128|@ohos.usbManager.d.ts|
|新增|NA|模块名: ohos.usbManager<br>类名: FunctionType<br>方法 or 属性: NCM = 256|@ohos.usbManager.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function getDevices(): Array\<Readonly\<USBDevice>>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function hasRight(deviceName: string): boolean;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function requestRight(deviceName: string): Promise\<boolean>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function removeRight(deviceName: string): boolean;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function addRight(bundleName: string, deviceName: string): boolean;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function usbFunctionsFromString(funcs: string): number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function usbFunctionsToString(funcs: FunctionType): string;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function setCurrentFunctions(funcs: FunctionType): Promise\<boolean>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function getCurrentFunctions(): FunctionType;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function getPorts(): Array\<USBPort>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function getSupportedModes(portId: number): PortModeType;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function setConfiguration(pipe: USBDevicePipe, config: USBConfig): number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function getFileDescriptor(pipe: USBDevicePipe): number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: usbV9<br>方法 or 属性：function closePipe(pipe: USBDevicePipe): number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint<br>方法 or 属性：address: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint<br>方法 or 属性：attributes: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint<br>方法 or 属性：interval: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint<br>方法 or 属性：maxPacketSize: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint<br>方法 or 属性：direction: USBRequestDirection;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint<br>方法 or 属性：number: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint<br>方法 or 属性：type: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBEndpoint<br>方法 or 属性：interfaceId: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBInterface|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBInterface<br>方法 or 属性：id: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBInterface<br>方法 or 属性：protocol: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBInterface<br>方法 or 属性：clazz: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBInterface<br>方法 or 属性：subClass: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBInterface<br>方法 or 属性：alternateSetting: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBInterface<br>方法 or 属性：name: string;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBInterface<br>方法 or 属性：endpoints: Array\<USBEndpoint>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBConfig|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBConfig<br>方法 or 属性：id: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBConfig<br>方法 or 属性：attributes: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBConfig<br>方法 or 属性：maxPower: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBConfig<br>方法 or 属性：name: string;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBConfig<br>方法 or 属性：isRemoteWakeup: boolean;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBConfig<br>方法 or 属性：isSelfPowered: boolean;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBConfig<br>方法 or 属性：interfaces: Array\<USBInterface>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：busNum: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：devAddress: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：serial: string;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：name: string;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：manufacturerName: string;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：productName: string;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：version: string;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：vendorId: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：productId: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：clazz: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：subClass: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：protocol: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevice<br>方法 or 属性：configs: Array\<USBConfig>;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevicePipe|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevicePipe<br>方法 or 属性：busNum: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBDevicePipe<br>方法 or 属性：devAddress: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PowerRoleType|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PowerRoleType<br>方法 or 属性：NONE = 0|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PowerRoleType<br>方法 or 属性：SOURCE = 1|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PowerRoleType<br>方法 or 属性：SINK = 2|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: DataRoleType|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: DataRoleType<br>方法 or 属性：NONE = 0|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: DataRoleType<br>方法 or 属性：HOST = 1|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: DataRoleType<br>方法 or 属性：DEVICE = 2|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PortModeType|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PortModeType<br>方法 or 属性：NONE = 0|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PortModeType<br>方法 or 属性：UFP = 1|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PortModeType<br>方法 or 属性：DFP = 2|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PortModeType<br>方法 or 属性：DRP = 3|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: PortModeType<br>方法 or 属性：NUM_MODES = 4|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBPortStatus|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBPortStatus<br>方法 or 属性：currentMode: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBPortStatus<br>方法 or 属性：currentPowerRole: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBPortStatus<br>方法 or 属性：currentDataRole: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBPort|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBPort<br>方法 or 属性：id: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBPort<br>方法 or 属性：supportedModes: PortModeType;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBPort<br>方法 or 属性：status: USBPortStatus;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlParams|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlParams<br>方法 or 属性：request: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlParams<br>方法 or 属性：target: USBRequestTargetType;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlParams<br>方法 or 属性：reqType: USBControlRequestType;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlParams<br>方法 or 属性：value: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlParams<br>方法 or 属性：index: number;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlParams<br>方法 or 属性：data: Uint8Array;|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBRequestTargetType|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBRequestTargetType<br>方法 or 属性：USB_REQUEST_TARGET_DEVICE = 0|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBRequestTargetType<br>方法 or 属性：USB_REQUEST_TARGET_INTERFACE = 1|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBRequestTargetType<br>方法 or 属性：USB_REQUEST_TARGET_ENDPOINT = 2|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBRequestTargetType<br>方法 or 属性：USB_REQUEST_TARGET_OTHER = 3|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlRequestType|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlRequestType<br>方法 or 属性：USB_REQUEST_TYPE_STANDARD = 0|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlRequestType<br>方法 or 属性：USB_REQUEST_TYPE_CLASS = 1|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBControlRequestType<br>方法 or 属性：USB_REQUEST_TYPE_VENDOR = 2|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBRequestDirection|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBRequestDirection<br>方法 or 属性：USB_REQUEST_DIR_TO_DEVICE = 0|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: USBRequestDirection<br>方法 or 属性：USB_REQUEST_DIR_FROM_DEVICE = 0x80|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：NONE = 0|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：ACM = 1|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：ECM = 2|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：HDC = 4|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：MTP = 8|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：PTP = 16|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：RNDIS = 32|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：MIDI = 64|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：AUDIO_SOURCE = 128|NA|@ohos.usbV9.d.ts|
|删除|模块名: ohos.usbV9<br>类名: FunctionType<br>方法 or 属性：NCM = 256|NA|@ohos.usbV9.d.ts|
