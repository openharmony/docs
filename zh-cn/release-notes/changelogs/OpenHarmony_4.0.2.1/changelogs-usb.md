USB管理 changeLog

## cl.usb_manager.1  系统接口变更

USB系统API运行时鉴权，异步接口以Promise reject形式抛出错误码。

基于此前版本开发的应用，需修改函数的返回值，否则会影响原有业务逻辑。

**关键接口/组件变更**

| 包名            | 旧接口                                                       | 新接口                                                       |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.usbV9.d.ts | function setCurrentFunctions(funcs: FunctionType): Promise<boolean>; | function setCurrentFunctions(funcs: FunctionType): Promise<void>; |
| ohos.usbV9.d.ts | function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise<boolean>; | function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise<void>; |

**适配指导**

请参考各接口的[API参考](../../../application-dev/reference/errorcodes/errorcode-universal.md)