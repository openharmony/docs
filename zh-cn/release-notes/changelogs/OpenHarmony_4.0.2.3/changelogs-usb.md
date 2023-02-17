# USB服务子系统ChangeLog

## cl.usb_manager.1  包名变更

基于此前版本开发的应用，需修改导入的包名，否则会影响原有业务逻辑。

**关键接口/组件变更**

|       旧包名        |    新包名           |
|------------------  | ------------------- | 
| ohos.usbV9.d.ts | ohos.usbManager.d.ts | 

**适配指导**

开发者导入时将@ohos.usbV9更换为@ohos.usbManager即可。

## cl.usb_manager.2  接口参数类型变更

基于此前版本开发的应用，需修改参数类型，否则会影响原有业务逻辑。

**关键接口/组件变更**

|   旧类名   |   新类名   | 
|---------------| ------------- |
| interface USBConfig | interface USBConfiguration | 

|   旧命名空间   |   新命名空间   | 
|---------------| ------------- |
| @namespace usbV9 | @namespace usbManager | 

| 包名            | 旧接口                                                       | 新接口                                                       |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.usbManager.d.ts | function setConfiguration(pipe: USBDevicePipe, config: USBConfig): number; | function setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number; | 

**适配指导**

调用setConfiguration接口时参数类型USBConfig修改为USBConfiguration即可。