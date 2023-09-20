| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: USBPort;<br>Method or attribute name: id: number;|@ohos.usb.d.ts|
|Added|NA|Class name: usb;<br>Method or attribute name: function usbFunctionsFromString(funcs: string): number;|@ohos.usb.d.ts|
|Added|NA|Class name: usb;<br>Method or attribute name: function usbFunctionsToString(funcs: FunctionType): string;|@ohos.usb.d.ts|
|Added|NA|Class name: usb;<br>Method or attribute name: function setCurrentFunctions(funcs: FunctionType): Promise\<boolean>;|@ohos.usb.d.ts|
|Added|NA|Class name: usb;<br>Method or attribute name: function getCurrentFunctions(): FunctionType;|@ohos.usb.d.ts|
|Added|NA|Class name: usb;<br>Method or attribute name: function getPorts(): Array\<USBPort>;|@ohos.usb.d.ts|
|Added|NA|Class name: usb;<br>Method or attribute name: function getSupportedModes(portId: number): PortModeType;|@ohos.usb.d.ts|
|Added|NA|Class name: usb;<br>Method or attribute name: function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean>;|@ohos.usb.d.ts|
|Added|NA|Class name: PowerRoleType;<br>Method or attribute name: NONE = 0|@ohos.usb.d.ts|
|Added|NA|Class name: DataRoleType;<br>Method or attribute name: NONE = 0|@ohos.usb.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: NONE = 0|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: NONE = 0|@ohos.usb.d.ts|
|Added|NA|Class name: PowerRoleType;<br>Method or attribute name: SOURCE = 1|@ohos.usb.d.ts|
|Added|NA|Class name: PowerRoleType;<br>Method or attribute name: SINK = 2|@ohos.usb.d.ts|
|Added|NA|Class name: DataRoleType;<br>Method or attribute name: HOST = 1|@ohos.usb.d.ts|
|Added|NA|Class name: DataRoleType;<br>Method or attribute name: DEVICE = 2|@ohos.usb.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: UFP = 1|@ohos.usb.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: DFP = 2|@ohos.usb.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: DRP = 3|@ohos.usb.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: NUM_MODES = 4|@ohos.usb.d.ts|
|Added|NA|Class name: USBPortStatus;<br>Method or attribute name: currentMode: number;|@ohos.usb.d.ts|
|Added|NA|Class name: USBPortStatus;<br>Method or attribute name: currentPowerRole: number;|@ohos.usb.d.ts|
|Added|NA|Class name: USBPortStatus;<br>Method or attribute name: currentDataRole: number;|@ohos.usb.d.ts|
|Added|NA|Class name: USBPort;<br>Method or attribute name: supportedModes: PortModeType;|@ohos.usb.d.ts|
|Added|NA|Class name: USBPort;<br>Method or attribute name: status: USBPortStatus;|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: ACM = 1|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: ECM = 2|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: HDC = 4|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: MTP = 8|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: PTP = 16|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: RNDIS = 32|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: MIDI = 64|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: AUDIO_SOURCE = 128|@ohos.usb.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: NCM = 256|@ohos.usb.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function getDevices(): Array\<Readonly\<USBDevice>>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function hasRight(deviceName: string): boolean;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function requestRight(deviceName: string): Promise\<boolean>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function removeRight(deviceName: string): boolean;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function addRight(bundleName: string, deviceName: string): boolean;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function usbFunctionsFromString(funcs: string): number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function usbFunctionsToString(funcs: FunctionType): string;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function setCurrentFunctions(funcs: FunctionType): Promise\<void>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function getCurrentFunctions(): FunctionType;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function getPorts(): Array\<USBPort>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function getSupportedModes(portId: number): PortModeType;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function getFileDescriptor(pipe: USBDevicePipe): number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: usbManager;<br>Method or attribute name: function closePipe(pipe: USBDevicePipe): number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBEndpoint;<br>Method or attribute name: address: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBEndpoint;<br>Method or attribute name: attributes: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBConfiguration;<br>Method or attribute name: attributes: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBEndpoint;<br>Method or attribute name: interval: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBEndpoint;<br>Method or attribute name: maxPacketSize: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBEndpoint;<br>Method or attribute name: direction: USBRequestDirection;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBEndpoint;<br>Method or attribute name: number: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBEndpoint;<br>Method or attribute name: type: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBEndpoint;<br>Method or attribute name: interfaceId: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBInterface;<br>Method or attribute name: id: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBConfiguration;<br>Method or attribute name: id: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBPort;<br>Method or attribute name: id: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBInterface;<br>Method or attribute name: protocol: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: protocol: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBInterface;<br>Method or attribute name: clazz: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: clazz: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBInterface;<br>Method or attribute name: subClass: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: subClass: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBInterface;<br>Method or attribute name: alternateSetting: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBInterface;<br>Method or attribute name: name: string;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBConfiguration;<br>Method or attribute name: name: string;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: name: string;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBInterface;<br>Method or attribute name: endpoints: Array\<USBEndpoint>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBConfiguration;<br>Method or attribute name: maxPower: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBConfiguration;<br>Method or attribute name: isRemoteWakeup: boolean;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBConfiguration;<br>Method or attribute name: isSelfPowered: boolean;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBConfiguration;<br>Method or attribute name: interfaces: Array\<USBInterface>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: busNum: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevicePipe;<br>Method or attribute name: busNum: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: devAddress: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevicePipe;<br>Method or attribute name: devAddress: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: serial: string;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: manufacturerName: string;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: productName: string;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: version: string;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: vendorId: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: productId: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBDevice;<br>Method or attribute name: configs: Array\<USBConfiguration>;|@ohos.usbManager.d.ts|
|Added|NA|Class name: PowerRoleType;<br>Method or attribute name: NONE = 0|@ohos.usbManager.d.ts|
|Added|NA|Class name: DataRoleType;<br>Method or attribute name: NONE = 0|@ohos.usbManager.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: NONE = 0|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: NONE = 0|@ohos.usbManager.d.ts|
|Added|NA|Class name: PowerRoleType;<br>Method or attribute name: SOURCE = 1|@ohos.usbManager.d.ts|
|Added|NA|Class name: PowerRoleType;<br>Method or attribute name: SINK = 2|@ohos.usbManager.d.ts|
|Added|NA|Class name: DataRoleType;<br>Method or attribute name: HOST = 1|@ohos.usbManager.d.ts|
|Added|NA|Class name: DataRoleType;<br>Method or attribute name: DEVICE = 2|@ohos.usbManager.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: UFP = 1|@ohos.usbManager.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: DFP = 2|@ohos.usbManager.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: DRP = 3|@ohos.usbManager.d.ts|
|Added|NA|Class name: PortModeType;<br>Method or attribute name: NUM_MODES = 4|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBPortStatus;<br>Method or attribute name: currentMode: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBPortStatus;<br>Method or attribute name: currentPowerRole: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBPortStatus;<br>Method or attribute name: currentDataRole: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBPort;<br>Method or attribute name: supportedModes: PortModeType;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBPort;<br>Method or attribute name: status: USBPortStatus;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlParams;<br>Method or attribute name: request: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlParams;<br>Method or attribute name: target: USBRequestTargetType;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlParams;<br>Method or attribute name: reqType: USBControlRequestType;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlParams;<br>Method or attribute name: value: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlParams;<br>Method or attribute name: index: number;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlParams;<br>Method or attribute name: data: Uint8Array;|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_DEVICE = 0|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_INTERFACE = 1|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_ENDPOINT = 2|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_OTHER = 3|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_STANDARD = 0|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_CLASS = 1|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_VENDOR = 2|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBRequestDirection;<br>Method or attribute name: USB_REQUEST_DIR_TO_DEVICE = 0|@ohos.usbManager.d.ts|
|Added|NA|Class name: USBRequestDirection;<br>Method or attribute name: USB_REQUEST_DIR_FROM_DEVICE = 0x80|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: ACM = 1|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: ECM = 2|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: HDC = 4|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: MTP = 8|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: PTP = 16|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: RNDIS = 32|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: MIDI = 64|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: AUDIO_SOURCE = 128|@ohos.usbManager.d.ts|
|Added|NA|Class name: FunctionType;<br>Method or attribute name: NCM = 256|@ohos.usbManager.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: declare usb<br>Old version: |Class name: usb;<br>Method or attribute name: declare usb<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function getDevices(): Array\<Readonly\<USBDevice>>;<br>Old version: |Class name: usb;<br>Method or attribute name: function getDevices(): Array\<Readonly\<USBDevice>>;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;<br>Old version: |Class name: usb;<br>Method or attribute name: function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function hasRight(deviceName: string): boolean;<br>Old version: |Class name: usb;<br>Method or attribute name: function hasRight(deviceName: string): boolean;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function requestRight(deviceName: string): Promise\<boolean>;<br>Old version: |Class name: usb;<br>Method or attribute name: function requestRight(deviceName: string): Promise\<boolean>;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;<br>Old version: |Class name: usb;<br>Method or attribute name: function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;<br>Old version: |Class name: usb;<br>Method or attribute name: function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function setConfiguration(pipe: USBDevicePipe, config: USBConfig): number;<br>Old version: |Class name: usb;<br>Method or attribute name: function setConfiguration(pipe: USBDevicePipe, config: USBConfig): number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;<br>Old version: |Class name: usb;<br>Method or attribute name: function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;<br>Old version: |Class name: usb;<br>Method or attribute name: function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function getFileDescriptor(pipe: USBDevicePipe): number;<br>Old version: |Class name: usb;<br>Method or attribute name: function getFileDescriptor(pipe: USBDevicePipe): number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;<br>Old version: |Class name: usb;<br>Method or attribute name: function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;<br>Old version: |Class name: usb;<br>Method or attribute name: function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: usb;<br>Method or attribute name: function closePipe(pipe: USBDevicePipe): number;<br>Old version: |Class name: usb;<br>Method or attribute name: function closePipe(pipe: USBDevicePipe): number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: interface USBEndpoint<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: interface USBEndpoint<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: address: number;<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: address: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: attributes: number;<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: attributes: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBConfig;<br>Method or attribute name: attributes: number;<br>Old version: |Class name: USBConfig;<br>Method or attribute name: attributes: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: interval: number;<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: interval: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: maxPacketSize: number;<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: maxPacketSize: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: direction: USBRequestDirection;<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: direction: USBRequestDirection;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: number: number;<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: number: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: type: number;<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: type: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBEndpoint;<br>Method or attribute name: interfaceId: number;<br>Old version: |Class name: USBEndpoint;<br>Method or attribute name: interfaceId: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBInterface;<br>Method or attribute name: interface USBInterface<br>Old version: |Class name: USBInterface;<br>Method or attribute name: interface USBInterface<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBInterface;<br>Method or attribute name: id: number;<br>Old version: |Class name: USBInterface;<br>Method or attribute name: id: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBConfig;<br>Method or attribute name: id: number;<br>Old version: |Class name: USBConfig;<br>Method or attribute name: id: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBInterface;<br>Method or attribute name: protocol: number;<br>Old version: |Class name: USBInterface;<br>Method or attribute name: protocol: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: protocol: number;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: protocol: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBInterface;<br>Method or attribute name: clazz: number;<br>Old version: |Class name: USBInterface;<br>Method or attribute name: clazz: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: clazz: number;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: clazz: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBInterface;<br>Method or attribute name: subClass: number;<br>Old version: |Class name: USBInterface;<br>Method or attribute name: subClass: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: subClass: number;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: subClass: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBInterface;<br>Method or attribute name: alternateSetting: number;<br>Old version: |Class name: USBInterface;<br>Method or attribute name: alternateSetting: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBInterface;<br>Method or attribute name: name: string;<br>Old version: |Class name: USBInterface;<br>Method or attribute name: name: string;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBConfig;<br>Method or attribute name: name: string;<br>Old version: |Class name: USBConfig;<br>Method or attribute name: name: string;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: name: string;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: name: string;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBInterface;<br>Method or attribute name: endpoints: Array\<USBEndpoint>;<br>Old version: |Class name: USBInterface;<br>Method or attribute name: endpoints: Array\<USBEndpoint>;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBConfig;<br>Method or attribute name: interface USBConfig<br>Old version: |Class name: USBConfig;<br>Method or attribute name: interface USBConfig<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBConfig;<br>Method or attribute name: maxPower: number;<br>Old version: |Class name: USBConfig;<br>Method or attribute name: maxPower: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBConfig;<br>Method or attribute name: isRemoteWakeup: boolean;<br>Old version: |Class name: USBConfig;<br>Method or attribute name: isRemoteWakeup: boolean;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBConfig;<br>Method or attribute name: isSelfPowered: boolean;<br>Old version: |Class name: USBConfig;<br>Method or attribute name: isSelfPowered: boolean;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBConfig;<br>Method or attribute name: interfaces: Array\<USBInterface>;<br>Old version: |Class name: USBConfig;<br>Method or attribute name: interfaces: Array\<USBInterface>;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: interface USBDevice<br>Old version: |Class name: USBDevice;<br>Method or attribute name: interface USBDevice<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: busNum: number;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: busNum: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevicePipe;<br>Method or attribute name: busNum: number;<br>Old version: |Class name: USBDevicePipe;<br>Method or attribute name: busNum: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: devAddress: number;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: devAddress: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevicePipe;<br>Method or attribute name: devAddress: number;<br>Old version: |Class name: USBDevicePipe;<br>Method or attribute name: devAddress: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: serial: string;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: serial: string;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: manufacturerName: string;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: manufacturerName: string;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: productName: string;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: productName: string;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: version: string;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: version: string;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: vendorId: number;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: vendorId: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: productId: number;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: productId: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevice;<br>Method or attribute name: configs: Array\<USBConfig>;<br>Old version: |Class name: USBDevice;<br>Method or attribute name: configs: Array\<USBConfig>;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBDevicePipe;<br>Method or attribute name: interface USBDevicePipe<br>Old version: |Class name: USBDevicePipe;<br>Method or attribute name: interface USBDevicePipe<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlParams;<br>Method or attribute name: interface USBControlParams<br>Old version: |Class name: USBControlParams;<br>Method or attribute name: interface USBControlParams<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlParams;<br>Method or attribute name: request: number;<br>Old version: |Class name: USBControlParams;<br>Method or attribute name: request: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlParams;<br>Method or attribute name: target: USBRequestTargetType;<br>Old version: |Class name: USBControlParams;<br>Method or attribute name: target: USBRequestTargetType;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlParams;<br>Method or attribute name: reqType: USBControlRequestType;<br>Old version: |Class name: USBControlParams;<br>Method or attribute name: reqType: USBControlRequestType;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlParams;<br>Method or attribute name: value: number;<br>Old version: |Class name: USBControlParams;<br>Method or attribute name: value: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlParams;<br>Method or attribute name: index: number;<br>Old version: |Class name: USBControlParams;<br>Method or attribute name: index: number;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlParams;<br>Method or attribute name: data: Uint8Array;<br>Old version: |Class name: USBControlParams;<br>Method or attribute name: data: Uint8Array;<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBRequestTargetType;<br>Method or attribute name: export enum USBRequestTargetType<br>Old version: |Class name: USBRequestTargetType;<br>Method or attribute name: export enum USBRequestTargetType<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_DEVICE = 0<br>Old version: |Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_DEVICE = 0<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_INTERFACE = 1<br>Old version: |Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_INTERFACE = 1<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_ENDPOINT = 2<br>Old version: |Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_ENDPOINT = 2<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_OTHER = 3<br>Old version: |Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_OTHER = 3<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlRequestType;<br>Method or attribute name: export enum USBControlRequestType<br>Old version: |Class name: USBControlRequestType;<br>Method or attribute name: export enum USBControlRequestType<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_STANDARD = 0<br>Old version: |Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_STANDARD = 0<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_CLASS = 1<br>Old version: |Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_CLASS = 1<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_VENDOR = 2<br>Old version: |Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_VENDOR = 2<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBRequestDirection;<br>Method or attribute name: export enum USBRequestDirection<br>Old version: |Class name: USBRequestDirection;<br>Method or attribute name: export enum USBRequestDirection<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBRequestDirection;<br>Method or attribute name: USB_REQUEST_DIR_TO_DEVICE = 0<br>Old version: |Class name: USBRequestDirection;<br>Method or attribute name: USB_REQUEST_DIR_TO_DEVICE = 0<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Deprecated version changed|Class name: USBRequestDirection;<br>Method or attribute name: USB_REQUEST_DIR_FROM_DEVICE = 0x80<br>Old version: |Class name: USBRequestDirection;<br>Method or attribute name: USB_REQUEST_DIR_FROM_DEVICE = 0x80<br>New version: 9<br>Substitute API: ohos.usbManager|@ohos.usb.d.ts|
|Function changed|Class name: usb;<br>Method or attribute name: function controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise\<number>;|Class name: usb;<br>Method or attribute name: function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;|@ohos.usb.d.ts|
|Function changed|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_INTERFACE|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_INTERFACE = 1|@ohos.usb.d.ts|
|Function changed|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_ENDPOINT|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_ENDPOINT = 2|@ohos.usb.d.ts|
|Function changed|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_OTHER|Class name: USBRequestTargetType;<br>Method or attribute name: USB_REQUEST_TARGET_OTHER = 3|@ohos.usb.d.ts|
|Function changed|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_CLASS|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_CLASS = 1|@ohos.usb.d.ts|
|Function changed|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_VENDOR|Class name: USBControlRequestType;<br>Method or attribute name: USB_REQUEST_TYPE_VENDOR = 2|@ohos.usb.d.ts|
