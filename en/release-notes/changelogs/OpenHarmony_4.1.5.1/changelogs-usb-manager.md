# USB Subsystem Changelog

## cl.USB.1 USB APIs Deprecated

**Access Level**

System APIs

**Reason for Change**

Permission control is added to the USB APIs. The new APIs incorporate complete functions of the old system APIs and are more standard and atomic with full compliance with community API specifications.

**Change Impact**

The change is not compatible with earlier versions. You are advised to use new APIs.

**Deprecated Since**

OpenHarmony SDK 4.1.5.1

**Deprecated APIs**

The authentication mode is modified. **AccessTokenKit::VerifyAccessToken** is used instead of the APL level of the caller process for permission verification. The caller of the new APIs needs to apply for the **ohos.permission.** **MANAGE_USB_CONFIG** permission.
| API                                                    | Description                                                    | Substitute API                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| function addRight(bundleName: string, deviceName: string): boolean; | Use the **usb.addDeviceAccessRight** API to grant device access permission for an application.| function addDeviceAccessRight(bundleName: string, deviceName: string): boolean; |
| function usbFunctionsFromString(funcs: string): number; | Use the **usb.getFunctionsFromString** API to convert the USB function list from strings to numeric masks.| function getFunctionsFromString(funcs: string): number; |
| function usbFunctionsToString(funcs: FunctionType): string; | Use the **usb.convertFunctionsToString** API to convert the USB function list from numeric masks to strings.| function convertFunctionsToString(funcs: FunctionType): string; |
| function setCurrentFunctions(funcs: FunctionType): Promise&lt;void&gt;; | Use the **usb.setDeviceFunctions** API to set the current USB function list.| function setDeviceFunctions(funcs: FunctionType): Promise&lt;void&gt;; |
| function getCurrentFunctions(): FunctionType; | Use the **usb.getDeviceFunctions** API to obtain the numeric mask combination of the USB function list.| function getDeviceFunctions(): FunctionType; |
| function getPorts(): Array&lt;USBPort&gt;; | Use the **usb.getUsbPorts** API to obtain the description of all physical USB ports.| function getUsbPorts(): Array&lt;USBPort&gt;; |
| function getSupportedModes(portId: number): PortModeType; | Use the **usb.getUsbPortSupportModes** API to obtain the numeric mask combination for the supported mode list of the USB port.| function getUsbPortSupportModes(portId: number): PortModeType; |
| function setPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise&lt;void&gt;; | Use the **usb.setUsbPortRoles** API to set the role types supported by a specified port, which can be **powerRole** (for charging) and **dataRole** (for data transfer).| function setUsbPortRoles(portId: number, powerRole: PowerRoleType, dataRole: DataRoleType): Promise&lt;void&gt;; |

**Adaptation Guide**

Before change:
The **apl** field in the application configuration file **xxx.cfg** is **system_basic** or **system_core**.
After change:
Add the **ohos.permission.MANAGE_USB_CONFIG** permission to the **permission** field in the configuration file.
