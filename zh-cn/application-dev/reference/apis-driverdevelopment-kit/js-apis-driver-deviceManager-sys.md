# @ohos.driver.deviceManager (外设管理)(系统接口)
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

本模块主要提供管理外部设备的相关功能，包括查询扩展外设详细信息和查询扩展外设驱动详细信息。

>  **说明：**
>
> * 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> * 当前页面仅包含本模块的系统接口，其他公开接口请参见[@ohos.driver.deviceManager (外设管理)](js-apis-driver-deviceManager.md)。

## 导入模块

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
```

## deviceManager.queryDeviceInfo

queryDeviceInfo(deviceId?: number): Array&lt;Readonly&lt;DeviceInfo&gt;&gt;

查询扩展外设详细信息列表。如果没有设备接入，那么将会返回一个空的列表。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：**  SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名      | 类型     | 必填  | 说明                     |
|----------|--------|-----|------------------------|
| deviceId | number | 否   | 设备ID，通过[queryDevices](js-apis-driver-deviceManager.md#devicemanagerquerydevices)获得。如果不传入设备ID，则默认获取所有的设备信息；如果没有外接设备，且没有传入设备ID则会返回空数组。 |

**返回值：**

| 类型                                                     | 说明          |
|--------------------------------------------------------|-------------|
| Array&lt;Readonly&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | 扩展外设详细信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[驱动错误码](errorcode-deviceManager.md)。

| 错误码ID    | 错误信息                                                                  |
|----------|-----------------------------------------------------------------------|
| 201      | The permission check failed.                                          |
| 202      | Permission denied. A non-system application cannot call a system API. |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types.        |
| 26300001 | ExternalDeviceManager service exception.                              |

**示例：**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
  let deviceInfos : Array<deviceManager.DeviceInfo> = deviceManager.queryDeviceInfo(12345678);
  for (let item of deviceInfos) {
    console.info(`Device id is ${item.deviceId}`)
  }
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to query device info. Code is ${err.code}, message is ${err.message}`);
}
```
## deviceManager.queryDriverInfo

queryDriverInfo(driverUid?: string): Array&lt;Readonly&lt;DriverInfo&gt;&gt;

查询扩展外设驱动详细信息列表。如果没有设备接入，那么将会返回一个空的列表。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：**  SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名       | 类型     | 必填  | 说明                         |
|-----------|--------|-----|----------------------------|
| driverUid | string | 否   | 驱动UID，通过queryDeviceInfo获得。 |

**返回值：**

| 类型                                                     | 说明            |
|--------------------------------------------------------|---------------|
| Array&lt;Readonly&lt;[DriverInfo](#driverinfo)&gt;&gt; | 扩展外设驱动详细信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[驱动错误码](errorcode-deviceManager.md)。

| 错误码ID    | 错误信息                                                                  |
|----------|-----------------------------------------------------------------------|
| 201      | The permission check failed.                                          |
| 202      | Permission denied. A non-system application cannot call a system API. |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types.        |
| 26300001 | ExternalDeviceManager service exception.                              |

**示例：**

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // driver-12345为示例driverUid，应用开发时可通过queryDeviceInfo查询到相应设备匹配到的驱动的driverUid作为入参
  let driverInfos : Array<deviceManager.DriverInfo> = deviceManager.queryDriverInfo("driver-12345");
  for (let item of driverInfos) {
    console.info(`driver name is ${item.driverName}`)
  }
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to query driver info. Code is ${err.code}, message is ${err.message}`);
}
```

## DeviceInfo

设备详细信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称              | 类型      | 只读  | 可选  | 说明          |
|-----------------|---------|-----|-----|-------------|
| deviceId        | number  | 否   | 否   | 设备ID。       |
| isDriverMatched | boolean | 否   | 否   | 设备是否匹配到驱动。`true`：匹配到驱动；`false`：未匹配到驱动。 |
| driverUid       | string  | 否   | 是   | 设备匹配的驱动UID。 |

## USBDeviceInfo

USB设备详细信息，继承自[DeviceInfo](#deviceinfo)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称                | 类型                                                                 | 只读  | 可选  | 说明               |
|-------------------|--------------------------------------------------------------------|-----|-----|------------------|
| vendorId          | number                                                             | 否   | 否   | USB设备Vendor ID。  |
| productId         | number                                                             | 否   | 否   | USB设备Product ID。 |
| interfaceDescList | Array&lt;Readonly&lt;[USBInterfaceDesc](#usbinterfacedesc)&gt;&gt; | 是   | 否   | USB设备接口描述符列表。    |

## USBInterfaceDesc

USB设备接口描述符。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称               | 类型     | 只读  | 可选  | 说明     |
|------------------|--------|-----|-----|--------|
| bInterfaceNumber | number | 否   | 否   | 接口编号。  |
| bClass           | number | 否   | 否   | 类型代码。  |
| bSubClass        | number | 否   | 否   | 子类型代码。 |
| bProtocol        | number | 否   | 否   | 协议代码。  |

## DriverInfo

驱动详细信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称            | 类型                                                 | 只读  | 可选  | 说明             |
|---------------|----------------------------------------------------|-----|-----|----------------|
| busType       | [BusType](js-apis-driver-deviceManager.md#bustype) | 否   | 否   | 总线类型。          |
| driverUid     | string                                             | 否   | 否   | 驱动Uid。         |
| driverName    | string                                             | 否   | 否   | 驱动名称。          |
| driverVersion | string                                             | 否   | 否   | 驱动版本。          |
| driverSize    | string                                             | 否   | 否   | 驱动大小(单位为Byte)。 |
| description   | string                                             | 否   | 否   | 驱动描述。          |

## USBDriverInfo

USB设备驱动详细信息，继承自[DriverInfo](#driverinfo)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称            | 类型                  | 只读  | 可选  | 说明                      |
|---------------|---------------------|-----|-----|-------------------------|
| productIdList | Array&lt;number&gt; | 否   | 否   | 驱动支持的USB设备product ID列表。 |
| vendorIdList  | Array&lt;number&gt; | 否   | 否   | 驱动支持的USB设备vendor ID列表。  |