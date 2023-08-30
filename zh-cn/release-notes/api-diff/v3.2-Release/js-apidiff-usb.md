| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：USBPort;<br>方法or属性：id: number;|@ohos.usb.d.ts|
|新增|NA|类名：usb;<br>方法or属性：function usbFunctionsFromString(funcs: string): number;|@ohos.usb.d.ts|
|新增|NA|类名：usb;<br>方法or属性：function usbFunctionsToString(funcs: FunctionType): string;|@ohos.usb.d.ts|
|新增|NA|类名：usb;<br>方法or属性：function setCurrentFunctions(funcs: FunctionType): Promise\<boolean>;|@ohos.usb.d.ts|
|新增|NA|类名：usb;<br>方法or属性：function getCurrentFunctions(): FunctionType;|@ohos.usb.d.ts|
|新增|NA|类名：usb;<br>方法or属性：function getPorts(): Array\<USBPort>;|@ohos.usb.d.ts|
|新增|NA|类名：usb;<br>方法or属性：function getSupportedModes(portId: number): PortModeType;|@ohos.usb.d.ts|
|新增|NA|类名：usb;<br>方法or属性：function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<boolean>;|@ohos.usb.d.ts|
|新增|NA|类名：PowerRoleType;<br>方法or属性：NONE = 0|@ohos.usb.d.ts|
|新增|NA|类名：DataRoleType;<br>方法or属性：NONE = 0|@ohos.usb.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：NONE = 0|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：NONE = 0|@ohos.usb.d.ts|
|新增|NA|类名：PowerRoleType;<br>方法or属性：SOURCE = 1|@ohos.usb.d.ts|
|新增|NA|类名：PowerRoleType;<br>方法or属性：SINK = 2|@ohos.usb.d.ts|
|新增|NA|类名：DataRoleType;<br>方法or属性：HOST = 1|@ohos.usb.d.ts|
|新增|NA|类名：DataRoleType;<br>方法or属性：DEVICE = 2|@ohos.usb.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：UFP = 1|@ohos.usb.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：DFP = 2|@ohos.usb.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：DRP = 3|@ohos.usb.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：NUM_MODES = 4|@ohos.usb.d.ts|
|新增|NA|类名：USBPortStatus;<br>方法or属性：currentMode: number;|@ohos.usb.d.ts|
|新增|NA|类名：USBPortStatus;<br>方法or属性：currentPowerRole: number;|@ohos.usb.d.ts|
|新增|NA|类名：USBPortStatus;<br>方法or属性：currentDataRole: number;|@ohos.usb.d.ts|
|新增|NA|类名：USBPort;<br>方法or属性：supportedModes: PortModeType;|@ohos.usb.d.ts|
|新增|NA|类名：USBPort;<br>方法or属性：status: USBPortStatus;|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：ACM = 1|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：ECM = 2|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：HDC = 4|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：MTP = 8|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：PTP = 16|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：RNDIS = 32|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：MIDI = 64|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：AUDIO_SOURCE = 128|@ohos.usb.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：NCM = 256|@ohos.usb.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function getDevices(): Array\<Readonly\<USBDevice>>;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function hasRight(deviceName: string): boolean;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function requestRight(deviceName: string): Promise\<boolean>;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function removeRight(deviceName: string): boolean;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function addRight(bundleName: string, deviceName: string): boolean;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function usbFunctionsFromString(funcs: string): number;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function usbFunctionsToString(funcs: FunctionType): string;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function setCurrentFunctions(funcs: FunctionType): Promise\<void>;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function getCurrentFunctions(): FunctionType;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function getPorts(): Array\<USBPort>;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function getSupportedModes(portId: number): PortModeType;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise\<void>;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function getFileDescriptor(pipe: USBDevicePipe): number;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;|@ohos.usbManager.d.ts|
|新增|NA|类名：usbManager;<br>方法or属性：function closePipe(pipe: USBDevicePipe): number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBEndpoint;<br>方法or属性：address: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBEndpoint;<br>方法or属性：attributes: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBConfiguration;<br>方法or属性：attributes: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBEndpoint;<br>方法or属性：interval: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBEndpoint;<br>方法or属性：maxPacketSize: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBEndpoint;<br>方法or属性：direction: USBRequestDirection;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBEndpoint;<br>方法or属性：number: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBEndpoint;<br>方法or属性：type: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBEndpoint;<br>方法or属性：interfaceId: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBInterface;<br>方法or属性：id: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBConfiguration;<br>方法or属性：id: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBPort;<br>方法or属性：id: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBInterface;<br>方法or属性：protocol: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：protocol: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBInterface;<br>方法or属性：clazz: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：clazz: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBInterface;<br>方法or属性：subClass: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：subClass: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBInterface;<br>方法or属性：alternateSetting: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBInterface;<br>方法or属性：name: string;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBConfiguration;<br>方法or属性：name: string;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：name: string;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBInterface;<br>方法or属性：endpoints: Array\<USBEndpoint>;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBConfiguration;<br>方法or属性：maxPower: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBConfiguration;<br>方法or属性：isRemoteWakeup: boolean;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBConfiguration;<br>方法or属性：isSelfPowered: boolean;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBConfiguration;<br>方法or属性：interfaces: Array\<USBInterface>;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：busNum: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevicePipe;<br>方法or属性：busNum: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：devAddress: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevicePipe;<br>方法or属性：devAddress: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：serial: string;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：manufacturerName: string;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：productName: string;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：version: string;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：vendorId: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：productId: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBDevice;<br>方法or属性：configs: Array\<USBConfiguration>;|@ohos.usbManager.d.ts|
|新增|NA|类名：PowerRoleType;<br>方法or属性：NONE = 0|@ohos.usbManager.d.ts|
|新增|NA|类名：DataRoleType;<br>方法or属性：NONE = 0|@ohos.usbManager.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：NONE = 0|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：NONE = 0|@ohos.usbManager.d.ts|
|新增|NA|类名：PowerRoleType;<br>方法or属性：SOURCE = 1|@ohos.usbManager.d.ts|
|新增|NA|类名：PowerRoleType;<br>方法or属性：SINK = 2|@ohos.usbManager.d.ts|
|新增|NA|类名：DataRoleType;<br>方法or属性：HOST = 1|@ohos.usbManager.d.ts|
|新增|NA|类名：DataRoleType;<br>方法or属性：DEVICE = 2|@ohos.usbManager.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：UFP = 1|@ohos.usbManager.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：DFP = 2|@ohos.usbManager.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：DRP = 3|@ohos.usbManager.d.ts|
|新增|NA|类名：PortModeType;<br>方法or属性：NUM_MODES = 4|@ohos.usbManager.d.ts|
|新增|NA|类名：USBPortStatus;<br>方法or属性：currentMode: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBPortStatus;<br>方法or属性：currentPowerRole: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBPortStatus;<br>方法or属性：currentDataRole: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBPort;<br>方法or属性：supportedModes: PortModeType;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBPort;<br>方法or属性：status: USBPortStatus;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlParams;<br>方法or属性：request: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlParams;<br>方法or属性：target: USBRequestTargetType;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlParams;<br>方法or属性：reqType: USBControlRequestType;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlParams;<br>方法or属性：value: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlParams;<br>方法or属性：index: number;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlParams;<br>方法or属性：data: Uint8Array;|@ohos.usbManager.d.ts|
|新增|NA|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_DEVICE = 0|@ohos.usbManager.d.ts|
|新增|NA|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_INTERFACE = 1|@ohos.usbManager.d.ts|
|新增|NA|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_ENDPOINT = 2|@ohos.usbManager.d.ts|
|新增|NA|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_OTHER = 3|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_STANDARD = 0|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_CLASS = 1|@ohos.usbManager.d.ts|
|新增|NA|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_VENDOR = 2|@ohos.usbManager.d.ts|
|新增|NA|类名：USBRequestDirection;<br>方法or属性：USB_REQUEST_DIR_TO_DEVICE = 0|@ohos.usbManager.d.ts|
|新增|NA|类名：USBRequestDirection;<br>方法or属性：USB_REQUEST_DIR_FROM_DEVICE = 0x80|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：ACM = 1|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：ECM = 2|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：HDC = 4|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：MTP = 8|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：PTP = 16|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：RNDIS = 32|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：MIDI = 64|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：AUDIO_SOURCE = 128|@ohos.usbManager.d.ts|
|新增|NA|类名：FunctionType;<br>方法or属性：NCM = 256|@ohos.usbManager.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：declare usb<br>旧版本信息：|类名：usb;<br>方法or属性：declare usb<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function getDevices(): Array\<Readonly\<USBDevice>>;<br>旧版本信息：|类名：usb;<br>方法or属性：function getDevices(): Array\<Readonly\<USBDevice>>;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;<br>旧版本信息：|类名：usb;<br>方法or属性：function connectDevice(device: USBDevice): Readonly\<USBDevicePipe>;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function hasRight(deviceName: string): boolean;<br>旧版本信息：|类名：usb;<br>方法or属性：function hasRight(deviceName: string): boolean;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function requestRight(deviceName: string): Promise\<boolean>;<br>旧版本信息：|类名：usb;<br>方法or属性：function requestRight(deviceName: string): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;<br>旧版本信息：|类名：usb;<br>方法or属性：function claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;<br>旧版本信息：|类名：usb;<br>方法or属性：function releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function setConfiguration(pipe: USBDevicePipe, config: USBConfig): number;<br>旧版本信息：|类名：usb;<br>方法or属性：function setConfiguration(pipe: USBDevicePipe, config: USBConfig): number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;<br>旧版本信息：|类名：usb;<br>方法or属性：function setInterface(pipe: USBDevicePipe, iface: USBInterface): number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;<br>旧版本信息：|类名：usb;<br>方法or属性：function getRawDescriptor(pipe: USBDevicePipe): Uint8Array;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function getFileDescriptor(pipe: USBDevicePipe): number;<br>旧版本信息：|类名：usb;<br>方法or属性：function getFileDescriptor(pipe: USBDevicePipe): number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;<br>旧版本信息：|类名：usb;<br>方法or属性：function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;<br>旧版本信息：|类名：usb;<br>方法or属性：function bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,<br><br>        timeout?: number): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：usb;<br>方法or属性：function closePipe(pipe: USBDevicePipe): number;<br>旧版本信息：|类名：usb;<br>方法or属性：function closePipe(pipe: USBDevicePipe): number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：interface USBEndpoint<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：interface USBEndpoint<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：address: number;<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：address: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：attributes: number;<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：attributes: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBConfig;<br>方法or属性：attributes: number;<br>旧版本信息：|类名：USBConfig;<br>方法or属性：attributes: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：interval: number;<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：interval: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：maxPacketSize: number;<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：maxPacketSize: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：direction: USBRequestDirection;<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：direction: USBRequestDirection;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：number: number;<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：number: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：type: number;<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：type: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBEndpoint;<br>方法or属性：interfaceId: number;<br>旧版本信息：|类名：USBEndpoint;<br>方法or属性：interfaceId: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBInterface;<br>方法or属性：interface USBInterface<br>旧版本信息：|类名：USBInterface;<br>方法or属性：interface USBInterface<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBInterface;<br>方法or属性：id: number;<br>旧版本信息：|类名：USBInterface;<br>方法or属性：id: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBConfig;<br>方法or属性：id: number;<br>旧版本信息：|类名：USBConfig;<br>方法or属性：id: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBInterface;<br>方法or属性：protocol: number;<br>旧版本信息：|类名：USBInterface;<br>方法or属性：protocol: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：protocol: number;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：protocol: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBInterface;<br>方法or属性：clazz: number;<br>旧版本信息：|类名：USBInterface;<br>方法or属性：clazz: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：clazz: number;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：clazz: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBInterface;<br>方法or属性：subClass: number;<br>旧版本信息：|类名：USBInterface;<br>方法or属性：subClass: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：subClass: number;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：subClass: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBInterface;<br>方法or属性：alternateSetting: number;<br>旧版本信息：|类名：USBInterface;<br>方法or属性：alternateSetting: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBInterface;<br>方法or属性：name: string;<br>旧版本信息：|类名：USBInterface;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBConfig;<br>方法or属性：name: string;<br>旧版本信息：|类名：USBConfig;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：name: string;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBInterface;<br>方法or属性：endpoints: Array\<USBEndpoint>;<br>旧版本信息：|类名：USBInterface;<br>方法or属性：endpoints: Array\<USBEndpoint>;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBConfig;<br>方法or属性：interface USBConfig<br>旧版本信息：|类名：USBConfig;<br>方法or属性：interface USBConfig<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBConfig;<br>方法or属性：maxPower: number;<br>旧版本信息：|类名：USBConfig;<br>方法or属性：maxPower: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBConfig;<br>方法or属性：isRemoteWakeup: boolean;<br>旧版本信息：|类名：USBConfig;<br>方法or属性：isRemoteWakeup: boolean;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBConfig;<br>方法or属性：isSelfPowered: boolean;<br>旧版本信息：|类名：USBConfig;<br>方法or属性：isSelfPowered: boolean;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBConfig;<br>方法or属性：interfaces: Array\<USBInterface>;<br>旧版本信息：|类名：USBConfig;<br>方法or属性：interfaces: Array\<USBInterface>;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：interface USBDevice<br>旧版本信息：|类名：USBDevice;<br>方法or属性：interface USBDevice<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：busNum: number;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：busNum: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevicePipe;<br>方法or属性：busNum: number;<br>旧版本信息：|类名：USBDevicePipe;<br>方法or属性：busNum: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：devAddress: number;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：devAddress: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevicePipe;<br>方法or属性：devAddress: number;<br>旧版本信息：|类名：USBDevicePipe;<br>方法or属性：devAddress: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：serial: string;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：serial: string;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：manufacturerName: string;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：manufacturerName: string;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：productName: string;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：productName: string;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：version: string;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：version: string;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：vendorId: number;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：vendorId: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：productId: number;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：productId: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevice;<br>方法or属性：configs: Array\<USBConfig>;<br>旧版本信息：|类名：USBDevice;<br>方法or属性：configs: Array\<USBConfig>;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBDevicePipe;<br>方法or属性：interface USBDevicePipe<br>旧版本信息：|类名：USBDevicePipe;<br>方法or属性：interface USBDevicePipe<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlParams;<br>方法or属性：interface USBControlParams<br>旧版本信息：|类名：USBControlParams;<br>方法or属性：interface USBControlParams<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlParams;<br>方法or属性：request: number;<br>旧版本信息：|类名：USBControlParams;<br>方法or属性：request: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlParams;<br>方法or属性：target: USBRequestTargetType;<br>旧版本信息：|类名：USBControlParams;<br>方法or属性：target: USBRequestTargetType;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlParams;<br>方法or属性：reqType: USBControlRequestType;<br>旧版本信息：|类名：USBControlParams;<br>方法or属性：reqType: USBControlRequestType;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlParams;<br>方法or属性：value: number;<br>旧版本信息：|类名：USBControlParams;<br>方法or属性：value: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlParams;<br>方法or属性：index: number;<br>旧版本信息：|类名：USBControlParams;<br>方法or属性：index: number;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlParams;<br>方法or属性：data: Uint8Array;<br>旧版本信息：|类名：USBControlParams;<br>方法or属性：data: Uint8Array;<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBRequestTargetType;<br>方法or属性：export enum USBRequestTargetType<br>旧版本信息：|类名：USBRequestTargetType;<br>方法or属性：export enum USBRequestTargetType<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_DEVICE = 0<br>旧版本信息：|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_DEVICE = 0<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_INTERFACE = 1<br>旧版本信息：|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_INTERFACE = 1<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_ENDPOINT = 2<br>旧版本信息：|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_ENDPOINT = 2<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_OTHER = 3<br>旧版本信息：|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_OTHER = 3<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlRequestType;<br>方法or属性：export enum USBControlRequestType<br>旧版本信息：|类名：USBControlRequestType;<br>方法or属性：export enum USBControlRequestType<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_STANDARD = 0<br>旧版本信息：|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_STANDARD = 0<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_CLASS = 1<br>旧版本信息：|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_CLASS = 1<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_VENDOR = 2<br>旧版本信息：|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_VENDOR = 2<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBRequestDirection;<br>方法or属性：export enum USBRequestDirection<br>旧版本信息：|类名：USBRequestDirection;<br>方法or属性：export enum USBRequestDirection<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBRequestDirection;<br>方法or属性：USB_REQUEST_DIR_TO_DEVICE = 0<br>旧版本信息：|类名：USBRequestDirection;<br>方法or属性：USB_REQUEST_DIR_TO_DEVICE = 0<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|废弃版本有变化|类名：USBRequestDirection;<br>方法or属性：USB_REQUEST_DIR_FROM_DEVICE = 0x80<br>旧版本信息：|类名：USBRequestDirection;<br>方法or属性：USB_REQUEST_DIR_FROM_DEVICE = 0x80<br>新版本信息：9<br>代替接口： ohos.usbManager|@ohos.usb.d.ts|
|函数有变化|类名：usb;<br>方法or属性：function controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise\<number>;|类名：usb;<br>方法or属性：function controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise\<number>;|@ohos.usb.d.ts|
|函数有变化|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_INTERFACE|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_INTERFACE = 1|@ohos.usb.d.ts|
|函数有变化|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_ENDPOINT|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_ENDPOINT = 2|@ohos.usb.d.ts|
|函数有变化|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_OTHER|类名：USBRequestTargetType;<br>方法or属性：USB_REQUEST_TARGET_OTHER = 3|@ohos.usb.d.ts|
|函数有变化|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_CLASS|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_CLASS = 1|@ohos.usb.d.ts|
|函数有变化|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_VENDOR|类名：USBControlRequestType;<br>方法or属性：USB_REQUEST_TYPE_VENDOR = 2|@ohos.usb.d.ts|
