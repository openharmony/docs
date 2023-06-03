# USB服务子系统ChangeLog

## cl.usb_manager.1  系统接口变更

USB系统API运行时鉴权，异步接口以Promise reject形式抛出错误码。

基于此前版本开发的应用，需修改函数的返回值，否则会影响原有业务逻辑。

**关键接口/组件变更**

| 包名            | 旧接口                                                       | 新接口                                                       |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.usbV9.d.ts | function setCurrentFunctions(funcs: FunctionType): Promise<boolean>; | function setCurrentFunctions(funcs: FunctionType): Promise<void>; |
| ohos.usbV9.d.ts | function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise<boolean>; | function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise<void>; |

## cl.usb_manager.2  sdk接口删除

继OpenHarmony 4.0.5.5版本3.30之后，@ohos.usbV9.d.ts文件已删除。

后续需要import @ohos.usbManager才能使用USB服务的接口：

  ```ts
  import usbManager from '@ohos.usbManager';
  ```

**适配指导**

请参考各接口的[API文档](../../../application-dev/reference/apis/js-apis-usbManager.md)


## cl.usb_manager.2  包名变更

基于此前版本开发的应用，需修改导入的包名，否则会影响原有业务逻辑。

**关键接口/组件变更**

|       旧包名        |    新包名           |
|------------------  | ------------------- | 
| ohos.usbV9.d.ts | ohos.usbManager.d.ts | 

**适配指导**

开发者导入时将@ohos.usbV9更换为@ohos.usbManager即可。

## cl.usb_manager.3  接口参数类型变更

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


## cl.usb_manager.4  sdk接口删除

基于此前版本开发的应用，需修改导入的包名，否则会影响原有业务逻辑。

**关键接口/组件变更**

@ohos.usbV9.d.ts文件已删除，由@ohos.usbManager.d.ts替代。

|         新包名        |     旧包名    |    已删除包名    |
| -------------------- | ------------- | --------------- |
| ohos.usbManager.d.ts | ohos.usb.d.ts | ohos.usbV9.d.ts |

后续需要import @ohos.usbManager才能使用USB服务的接口：

  ```ts
  import usbManager from '@ohos.usbManager';
  ```

**适配指导**

请参考各接口的[API文档](../../../application-dev/reference/apis/js-apis-usbManager.md)
