# USB服务子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，USB服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.usb | USBRequestDirection | USB_REQUEST_DIR_FROM_DEVICE = 0x80 | 新增 |
| ohos.usb | USBRequestDirection | USB_REQUEST_DIR_TO_DEVICE = 0 | 新增 |
| ohos.usb | USBControlRequestType | USB_REQUEST_TYPE_VENDOR | 新增 |
| ohos.usb | USBControlRequestType | USB_REQUEST_TYPE_CLASS | 新增 |
| ohos.usb | USBControlRequestType | USB_REQUEST_TYPE_STANDARD = 0 | 新增 |
| ohos.usb | USBRequestTargetType | USB_REQUEST_TARGET_OTHER | 新增 |
| ohos.usb | USBRequestTargetType | USB_REQUEST_TARGET_ENDPOINT | 新增 |
| ohos.usb | USBRequestTargetType | USB_REQUEST_TARGET_INTERFACE | 新增 |
| ohos.usb | USBRequestTargetType | USB_REQUEST_TARGET_DEVICE = 0 | 新增 |
| ohos.usb | USBControlParams | data: Uint8Array; | 新增 |
| ohos.usb | USBControlParams | index: number; | 新增 |
| ohos.usb | USBControlParams | value: number; | 新增 |
| ohos.usb | USBControlParams | reqType: USBControlRequestType; | 新增 |
| ohos.usb | USBControlParams | target: USBRequestTargetType; | 新增 |
| ohos.usb | USBControlParams | request: number; | 新增 |
| ohos.usb | USBDevicePipe | devAddress: number; | 新增 |
| ohos.usb | USBDevicePipe | busNum: number; | 新增 |
| ohos.usb | USBDevice | configs: Array\<USBConfig>; | 新增 |
| ohos.usb | USBDevice | protocol: number; | 新增 |
| ohos.usb | USBDevice | subClass: number; | 新增 |
| ohos.usb | USBDevice | clazz: number; | 新增 |
| ohos.usb | USBDevice | productId: number; | 新增 |
| ohos.usb | USBDevice | vendorId: number; | 新增 |
| ohos.usb | USBDevice | version: string; | 新增 |
| ohos.usb | USBDevice | productName: string; | 新增 |
| ohos.usb | USBDevice | manufacturerName: string; | 新增 |
| ohos.usb | USBDevice | name: string; | 新增 |
| ohos.usb | USBDevice | serial: string; | 新增 |
| ohos.usb | USBDevice | devAddress: number; | 新增 |
| ohos.usb | USBDevice | busNum: number; | 新增 |
| ohos.usb | USBConfig | interfaces: Array\<USBInterface>; | 新增 |
| ohos.usb | USBConfig | isSelfPowered: boolean; | 新增 |
| ohos.usb | USBConfig | isRemoteWakeup: boolean; | 新增 |
| ohos.usb | USBConfig | name: string; | 新增 |
| ohos.usb | USBConfig | maxPower: number; | 新增 |
| ohos.usb | USBConfig | attributes: number; | 新增 |
| ohos.usb | USBConfig | id: number; | 新增 |
| ohos.usb | USBInterface | endpoints: Array\<USBEndpoint>; | 新增 |
| ohos.usb | USBInterface | name: string; | 新增 |
| ohos.usb | USBInterface | alternateSetting: number; | 新增 |
| ohos.usb | USBInterface | subClass: number; | 新增 |
| ohos.usb | USBInterface | clazz: number; | 新增 |
| ohos.usb | USBInterface | protocol: number; | 新增 |
| ohos.usb | USBInterface | id: number; | 新增 |
| ohos.usb | USBEndpoint | interfaceId: number; | 新增 |
| ohos.usb | USBEndpoint | type: number; | 新增 |
| ohos.usb | USBEndpoint | number: number; | 新增 |
| ohos.usb | USBEndpoint | direction: USBRequestDirection; | 新增 |
| ohos.usb | USBEndpoint | maxPacketSize: number; | 新增 |
| ohos.usb | USBEndpoint | interval: number; | 新增 |
| ohos.usb | USBEndpoint | attributes: number; | 新增 |
| ohos.usb | USBEndpoint | address: number; | 新增 |
| ohos.usb | usb | closePipe(pipe: USBDevicePipe): number; | 新增 |
| ohos.usb | usb | bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,timeout?: number): Promise\<number>; | 新增 |
| ohos.usb | usb | controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise\<number>; | 新增 |
| ohos.usb | usb | getFileDescriptor(pipe: USBDevicePipe): number; | 新增 |
| ohos.usb | usb | getRawDescriptor(pipe: USBDevicePipe): Uint8Array; | 新增 |
| ohos.usb | usb | setInterface(pipe: USBDevicePipe, iface: USBInterface): number; | 新增 |
| ohos.usb | usb | setConfiguration(pipe: USBDevicePipe, config: USBConfig): number; | 新增 |
| ohos.usb | usb | releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number; | 新增 |
| ohos.usb | usb | claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number; | 新增 |
| ohos.usb | usb | requestRight(deviceName: string): Promise\<boolean>; | 新增 |
| ohos.usb | usb | hasRight(deviceName: string): boolean; | 新增 |
| ohos.usb | usb | connectDevice(device: USBDevice): Readonly\<USBDevicePipe>; | 新增 |
| ohos.usb | usb | getDevices(): Array\<Readonly\<USBDevice>>; | 新增 |
