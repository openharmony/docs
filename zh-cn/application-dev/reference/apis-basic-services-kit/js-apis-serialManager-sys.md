# @ohos.usbManager.serial (串口管理)(系统接口)

本模块主要提供串口管理功能，包括打开和关闭设备的串口、写入和读取数据、设置和获取串口的配置参数、权限管理等。

> **说明：**
>
> 本模块首批接口从API version 19开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.usbManager.serial (串口管理)](js-apis-serialManager.md)。

## 导入模块

```ts
import { serialManager } from '@kit.BasicServicesKit';
```

## serialManager.addSerialRight

addSerialRight(tokenId: number, portId: number): void

为应用程序添加访问串口设备权限。

serialManager.requestSerialRight会触发弹窗请求用户授权；addSerialRight不会触发弹窗，而是直接添加应用程序访问设备的权限。应用退出自动移除对串口设备的访问权限，在应用重启后需要重新申请授权。

**系统接口：** 此接口为系统接口

**需要权限：**  ohos.permission.MANAGE_USB_CONFIG

**系统能力：**  SystemCapability.USB.USBManager.Serial

**参数：**

| 参数名     | 类型     | 必填 | 说明                                  |
|---------|--------|----|-------------------------------------|
| tokenId | number | 是  | 需要访问权限的tokenId。                  |
| portId  | number | 是  | 端口号。 |

**错误码：**

以下错误码的详细介绍参见[USB服务错误码](errorcode-usb.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14400005 | Database operation exception. |
| 31400001 | Serial port management exception. |
| 31400003 | Device does not exist. |

**示例：**
```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { JSON } from '@kit.ArkTS';
import { serialManager } from '@kit.BasicServicesKit';

// 获取串口列表
let portList: serialManager.SerialPort[] = serialManager.getPortList();
console.info('portList: ', JSON.stringify(portList));
if (portList === undefined || portList.length === 0) {
  console.info('portList is empty');
  return;
}

let portId: number = portList[0].portId;
// 串口增加权限
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo) => {
  console.info('getBundleInfoForSelf successfully. Data: %{public}s', JSONstringify(bundleInfo));
  let tokenId = bundleInfo.appInfo.accessTokenId;
  try {
    serialManager.addSerialRight(tokenId, portId);
    console.info('addSerialRight success, portId: ' + portId);
  } catch (error) {
    console.error('addSerialRight error, ' + JSON.stringify(error));
  }
}).catch((err : BusinessError) => {
  console.error('getBundleInfoForSelf failed');
});
```
