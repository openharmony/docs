# JS API Changes of the USB Subsystem

The table below lists the APIs changes of the USB subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.usb | USBRequestDirection | USB_REQUEST_DIR_FROM_DEVICE = 0x80 | Added|
| ohos.usb | USBRequestDirection | USB_REQUEST_DIR_TO_DEVICE = 0 | Added|
| ohos.usb | USBControlRequestType | USB_REQUEST_TYPE_VENDOR | Added|
| ohos.usb | USBControlRequestType | USB_REQUEST_TYPE_CLASS | Added|
| ohos.usb | USBControlRequestType | USB_REQUEST_TYPE_STANDARD = 0 | Added|
| ohos.usb | USBRequestTargetType | USB_REQUEST_TARGET_OTHER | Added|
| ohos.usb | USBRequestTargetType | USB_REQUEST_TARGET_ENDPOINT | Added|
| ohos.usb | USBRequestTargetType | USB_REQUEST_TARGET_INTERFACE | Added|
| ohos.usb | USBRequestTargetType | USB_REQUEST_TARGET_DEVICE = 0 | Added|
| ohos.usb | USBControlParams | data: Uint8Array; | Added|
| ohos.usb | USBControlParams | index: number; | Added|
| ohos.usb | USBControlParams | value: number; | Added|
| ohos.usb | USBControlParams | reqType: USBControlRequestType; | Added|
| ohos.usb | USBControlParams | target: USBRequestTargetType; | Added|
| ohos.usb | USBControlParams | request: number; | Added|
| ohos.usb | USBDevicePipe | devAddress: number; | Added|
| ohos.usb | USBDevicePipe | busNum: number; | Added|
| ohos.usb | USBDevice | configs: Array\<USBConfig>; | Added|
| ohos.usb | USBDevice | protocol: number; | Added|
| ohos.usb | USBDevice | subClass: number; | Added|
| ohos.usb | USBDevice | clazz: number; | Added|
| ohos.usb | USBDevice | productId: number; | Added|
| ohos.usb | USBDevice | vendorId: number; | Added|
| ohos.usb | USBDevice | version: string; | Added|
| ohos.usb | USBDevice | productName: string; | Added|
| ohos.usb | USBDevice | manufacturerName: string; | Added|
| ohos.usb | USBDevice | name: string; | Added|
| ohos.usb | USBDevice | serial: string; | Added|
| ohos.usb | USBDevice | devAddress: number; | Added|
| ohos.usb | USBDevice | busNum: number; | Added|
| ohos.usb | USBConfig | interfaces: Array\<USBInterface>; | Added|
| ohos.usb | USBConfig | isSelfPowered: boolean; | Added|
| ohos.usb | USBConfig | isRemoteWakeup: boolean; | Added|
| ohos.usb | USBConfig | name: string; | Added|
| ohos.usb | USBConfig | maxPower: number; | Added|
| ohos.usb | USBConfig | attributes: number; | Added|
| ohos.usb | USBConfig | id: number; | Added|
| ohos.usb | USBInterface | endpoints: Array\<USBEndpoint>; | Added|
| ohos.usb | USBInterface | name: string; | Added|
| ohos.usb | USBInterface | alternateSetting: number; | Added|
| ohos.usb | USBInterface | subClass: number; | Added|
| ohos.usb | USBInterface | clazz: number; | Added|
| ohos.usb | USBInterface | protocol: number; | Added|
| ohos.usb | USBInterface | id: number; | Added|
| ohos.usb | USBEndpoint | interfaceId: number; | Added|
| ohos.usb | USBEndpoint | type: number; | Added|
| ohos.usb | USBEndpoint | number: number; | Added|
| ohos.usb | USBEndpoint | direction: USBRequestDirection; | Added|
| ohos.usb | USBEndpoint | maxPacketSize: number; | Added|
| ohos.usb | USBEndpoint | interval: number; | Added|
| ohos.usb | USBEndpoint | attributes: number; | Added|
| ohos.usb | USBEndpoint | address: number; | Added|
| ohos.usb | usb | closePipe(pipe: USBDevicePipe): number; | Added|
| ohos.usb | usb | bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array,timeout?: number): Promise\<number>; | Added|
| ohos.usb | usb | controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise\<number>; | Added|
| ohos.usb | usb | getFileDescriptor(pipe: USBDevicePipe): number; | Added|
| ohos.usb | usb | getRawDescriptor(pipe: USBDevicePipe): Uint8Array; | Added|
| ohos.usb | usb | setInterface(pipe: USBDevicePipe, iface: USBInterface): number; | Added|
| ohos.usb | usb | setConfiguration(pipe: USBDevicePipe, config: USBConfig): number; | Added|
| ohos.usb | usb | releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number; | Added|
| ohos.usb | usb | claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number; | Added|
| ohos.usb | usb | requestRight(deviceName: string): Promise\<boolean>; | Added|
| ohos.usb | usb | hasRight(deviceName: string): boolean; | Added|
| ohos.usb | usb | connectDevice(device: USBDevice): Readonly\<USBDevicePipe>; | Added|
| ohos.usb | usb | getDevices(): Array\<Readonly\<USBDevice>>; | Added|
