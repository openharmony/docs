# USB子系统变更说明

## cl.USB .1 USB管理功能模块接口废弃

**访问级别**

系统接口

**废弃原因**

USB模块接口增加权限控制，新开放的接口包含旧的系统级接口完整功能，接口更加标准并且原子化，符合社区API规范。

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.5.1开始。

**废弃的接口**

修改不合理的鉴权方式整改。不允许使用调用方进程APL等级进行权限校验，需要修改为使用AccessTokenKit::VerifyAccessToken对访问者进行权限校验，新接口调用者需要申请ohos.permission. MANAGE_USB_CONFIG权限。
| 接口声明                                                     | 废弃说明                                                     | 替代接口                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| function addRight(bundleName: string, deviceName: string): boolean; | 使用usb.addDeviceAccessRight接口添加软件包访问设备的权限。 | function addDeviceAccessRight(bundleName: string, deviceName: string): boolean; |
| function usbFunctionsFromString(funcs: string): number; | 使用usb.getFunctionsFromString接口将字符串形式的USB功能列表转化为数字掩码 | function getFunctionsFromString(funcs: string): number; |
| function usbFunctionsToString(funcs: FunctionType): string; | 使用usb.convertFunctionsToString接口将数字掩码形式的USB功能列表转化为字符串。 | function convertFunctionsToString(funcs: FunctionType): string; |
| function setCurrentFunctions(funcs: FunctionType): Promise&lt;void&gt;; | 使用usb.setDeviceFunctions接口设置当前的USB功能列表。 | function setDeviceFunctions(funcs: FunctionType): Promise&lt;void&gt;; |
| function getCurrentFunctions(): FunctionType; | 使用usb.getDeviceFunctions接口获取当前的USB功能列表的数字组合掩码。 | function getDeviceFunctions(): FunctionType; |
| function getPorts(): Array&lt;USBPort&gt;; | 使用usb.getUsbPorts接口获取所有物理USB端口描述信息。 | function getUsbPorts(): Array&lt;USBPort&gt;; |
| function getSupportedModes(portId: number): PortModeType; | 使用usb.getUsbPortSupportModes接口获取指定的端口支持的模式列表的组合掩码 | function getUsbPortSupportModes(portId: number): PortModeType; |
| function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise&lt;void&gt;; | 使用usb.setUsbPortRoles接口设置指定的端口支持的角色模式，包含充电角色、数据传输角色。 | function setUsbPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise&lt;void&gt;; |

**适配指导**

变更前
应用配置文件xxx.cfg中的apl字段是system_basic 或者 system_core。
变更后
配置文件中的permission 字段需要添加ohos.permission.MANAGE_USB_CONFIG权限。
