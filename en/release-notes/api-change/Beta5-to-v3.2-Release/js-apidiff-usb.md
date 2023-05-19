| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function getDevices(): Array\<Readonly\<USBDevice>>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function hasRight(deviceName: string): boolean;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function requestRight(deviceName: string): Promise\<boolean>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function removeRight(deviceName: string): boolean;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function addRight(bundleName: string, deviceName: string): boolean;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function usbFunctionsFromString(funcs: string): number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function usbFunctionsToString(funcs: FunctionType): string;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function setCurrentFunctions(funcs: FunctionType): Promise\<void>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function getCurrentFunctions(): FunctionType;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function getPorts(): Array\<USBPort>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function getSupportedModes(portId: number): PortModeType;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function getFileDescriptor(pipe: USBDevicePipe): number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: usbManager<br>Method or attribute name: function closePipe(pipe: USBDevicePipe): number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint<br>Method or attribute name: address: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint<br>Method or attribute name: attributes: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint<br>Method or attribute name: interval: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint<br>Method or attribute name: maxPacketSize: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint<br>Method or attribute name: direction: USBRequestDirection;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint<br>Method or attribute name: number: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint<br>Method or attribute name: type: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBEndpoint<br>Method or attribute name: interfaceId: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBInterface|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBInterface<br>Method or attribute name: id: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBInterface<br>Method or attribute name: protocol: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBInterface<br>Method or attribute name: clazz: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBInterface<br>Method or attribute name: subClass: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBInterface<br>Method or attribute name: alternateSetting: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBInterface<br>Method or attribute name: name: string;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBInterface<br>Method or attribute name: endpoints: Array\<USBEndpoint>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBConfiguration|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBConfiguration<br>Method or attribute name: id: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBConfiguration<br>Method or attribute name: attributes: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBConfiguration<br>Method or attribute name: maxPower: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBConfiguration<br>Method or attribute name: name: string;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBConfiguration<br>Method or attribute name: isRemoteWakeup: boolean;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBConfiguration<br>Method or attribute name: isSelfPowered: boolean;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBConfiguration<br>Method or attribute name: interfaces: Array\<USBInterface>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: busNum: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: devAddress: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: serial: string;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: name: string;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: manufacturerName: string;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: productName: string;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: version: string;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: vendorId: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: productId: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: clazz: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: subClass: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: protocol: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevice<br>Method or attribute name: configs: Array\<USBConfiguration>;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevicePipe|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevicePipe<br>Method or attribute name: busNum: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBDevicePipe<br>Method or attribute name: devAddress: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PowerRoleType|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PowerRoleType<br>Method or attribute name: NONE = 0|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PowerRoleType<br>Method or attribute name: SOURCE = 1|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PowerRoleType<br>Method or attribute name: SINK = 2|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: DataRoleType|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: DataRoleType<br>Method or attribute name: NONE = 0|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: DataRoleType<br>Method or attribute name: HOST = 1|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: DataRoleType<br>Method or attribute name: DEVICE = 2|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PortModeType|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PortModeType<br>Method or attribute name: NONE = 0|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PortModeType<br>Method or attribute name: UFP = 1|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PortModeType<br>Method or attribute name: DFP = 2|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PortModeType<br>Method or attribute name: DRP = 3|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: PortModeType<br>Method or attribute name: NUM_MODES = 4|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBPortStatus|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBPortStatus<br>Method or attribute name: currentMode: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBPortStatus<br>Method or attribute name: currentPowerRole: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBPortStatus<br>Method or attribute name: currentDataRole: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBPort|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBPort<br>Method or attribute name: id: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBPort<br>Method or attribute name: supportedModes: PortModeType;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBPort<br>Method or attribute name: status: USBPortStatus;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlParams|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlParams<br>Method or attribute name: request: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlParams<br>Method or attribute name: target: USBRequestTargetType;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlParams<br>Method or attribute name: reqType: USBControlRequestType;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlParams<br>Method or attribute name: value: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlParams<br>Method or attribute name: index: number;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlParams<br>Method or attribute name: data: Uint8Array;|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBRequestTargetType|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBRequestTargetType<br>Method or attribute name: USB_REQUEST_TARGET_DEVICE = 0|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBRequestTargetType<br>Method or attribute name: USB_REQUEST_TARGET_INTERFACE = 1|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBRequestTargetType<br>Method or attribute name: USB_REQUEST_TARGET_ENDPOINT = 2|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBRequestTargetType<br>Method or attribute name: USB_REQUEST_TARGET_OTHER = 3|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlRequestType|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlRequestType<br>Method or attribute name: USB_REQUEST_TYPE_STANDARD = 0|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlRequestType<br>Method or attribute name: USB_REQUEST_TYPE_CLASS = 1|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBControlRequestType<br>Method or attribute name: USB_REQUEST_TYPE_VENDOR = 2|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBRequestDirection|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBRequestDirection<br>Method or attribute name: USB_REQUEST_DIR_TO_DEVICE = 0|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: USBRequestDirection<br>Method or attribute name: USB_REQUEST_DIR_FROM_DEVICE = 0x80|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: NONE = 0|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: ACM = 1|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: ECM = 2|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: HDC = 4|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: MTP = 8|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: PTP = 16|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: RNDIS = 32|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: MIDI = 64|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: AUDIO_SOURCE = 128|@ohos.usbManager.d.ts|
|Added|NA|Module name: ohos.usbManager<br>Class name: FunctionType<br>Method or attribute name: NCM = 256|@ohos.usbManager.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function getDevices(): Array\<Readonly\<USBDevice>>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function hasRight(deviceName: string): boolean;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function requestRight(deviceName: string): Promise\<boolean>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function removeRight(deviceName: string): boolean;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function addRight(bundleName: string, deviceName: string): boolean;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function usbFunctionsFromString(funcs: string): number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function usbFunctionsToString(funcs: FunctionType): string;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function setCurrentFunctions(funcs: FunctionType): Promise\<boolean>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function getCurrentFunctions(): FunctionType;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function getPorts(): Array\<USBPort>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function getSupportedModes(portId: number): PortModeType;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function setConfiguration(pipe: USBDevicePipe, config: USBConfig): number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function getFileDescriptor(pipe: USBDevicePipe): number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: usbV9<br>Method or attribute name: function closePipe(pipe: USBDevicePipe): number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint<br>Method or attribute name: address: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint<br>Method or attribute name: attributes: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint<br>Method or attribute name: interval: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint<br>Method or attribute name: maxPacketSize: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint<br>Method or attribute name: direction: USBRequestDirection;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint<br>Method or attribute name: number: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint<br>Method or attribute name: type: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBEndpoint<br>Method or attribute name: interfaceId: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBInterface|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBInterface<br>Method or attribute name: id: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBInterface<br>Method or attribute name: protocol: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBInterface<br>Method or attribute name: clazz: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBInterface<br>Method or attribute name: subClass: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBInterface<br>Method or attribute name: alternateSetting: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBInterface<br>Method or attribute name: name: string;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBInterface<br>Method or attribute name: endpoints: Array\<USBEndpoint>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBConfig|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBConfig<br>Method or attribute name: id: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBConfig<br>Method or attribute name: attributes: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBConfig<br>Method or attribute name: maxPower: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBConfig<br>Method or attribute name: name: string;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBConfig<br>Method or attribute name: isRemoteWakeup: boolean;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBConfig<br>Method or attribute name: isSelfPowered: boolean;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBConfig<br>Method or attribute name: interfaces: Array\<USBInterface>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: busNum: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: devAddress: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: serial: string;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: name: string;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: manufacturerName: string;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: productName: string;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: version: string;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: vendorId: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: productId: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: clazz: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: subClass: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: protocol: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevice<br>Method or attribute name: configs: Array\<USBConfig>;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevicePipe|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevicePipe<br>Method or attribute name: busNum: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBDevicePipe<br>Method or attribute name: devAddress: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PowerRoleType|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PowerRoleType<br>Method or attribute name: NONE = 0|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PowerRoleType<br>Method or attribute name: SOURCE = 1|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PowerRoleType<br>Method or attribute name: SINK = 2|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: DataRoleType|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: DataRoleType<br>Method or attribute name: NONE = 0|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: DataRoleType<br>Method or attribute name: HOST = 1|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: DataRoleType<br>Method or attribute name: DEVICE = 2|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PortModeType|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PortModeType<br>Method or attribute name: NONE = 0|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PortModeType<br>Method or attribute name: UFP = 1|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PortModeType<br>Method or attribute name: DFP = 2|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PortModeType<br>Method or attribute name: DRP = 3|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: PortModeType<br>Method or attribute name: NUM_MODES = 4|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBPortStatus|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBPortStatus<br>Method or attribute name: currentMode: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBPortStatus<br>Method or attribute name: currentPowerRole: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBPortStatus<br>Method or attribute name: currentDataRole: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBPort|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBPort<br>Method or attribute name: id: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBPort<br>Method or attribute name: supportedModes: PortModeType;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBPort<br>Method or attribute name: status: USBPortStatus;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlParams|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlParams<br>Method or attribute name: request: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlParams<br>Method or attribute name: target: USBRequestTargetType;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlParams<br>Method or attribute name: reqType: USBControlRequestType;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlParams<br>Method or attribute name: value: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlParams<br>Method or attribute name: index: number;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlParams<br>Method or attribute name: data: Uint8Array;|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBRequestTargetType|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBRequestTargetType<br>Method or attribute name: USB_REQUEST_TARGET_DEVICE = 0|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBRequestTargetType<br>Method or attribute name: USB_REQUEST_TARGET_INTERFACE = 1|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBRequestTargetType<br>Method or attribute name: USB_REQUEST_TARGET_ENDPOINT = 2|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBRequestTargetType<br>Method or attribute name: USB_REQUEST_TARGET_OTHER = 3|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlRequestType|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlRequestType<br>Method or attribute name: USB_REQUEST_TYPE_STANDARD = 0|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlRequestType<br>Method or attribute name: USB_REQUEST_TYPE_CLASS = 1|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBControlRequestType<br>Method or attribute name: USB_REQUEST_TYPE_VENDOR = 2|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBRequestDirection|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBRequestDirection<br>Method or attribute name: USB_REQUEST_DIR_TO_DEVICE = 0|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: USBRequestDirection<br>Method or attribute name: USB_REQUEST_DIR_FROM_DEVICE = 0x80|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: NONE = 0|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: ACM = 1|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: ECM = 2|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: HDC = 4|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: MTP = 8|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: PTP = 16|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: RNDIS = 32|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: MIDI = 64|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: AUDIO_SOURCE = 128|NA|@ohos.usbV9.d.ts|
|Deleted|Module name: ohos.usbV9<br>Class name: FunctionType<br>Method or attribute name: NCM = 256|NA|@ohos.usbV9.d.ts|
