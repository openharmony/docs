# @ohos.driver.deviceManager (外设管理)(系统接口)

本模块主要提供管理外部设备的相关功能，包括查询扩展外设详细信息和查询扩展外设驱动详细信息。

>  **说明：**
>
> * 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> * 当前页面仅包含本模块的系统接口，其他公开接口请参见[@ohos.driver.deviceManager (外设管理)](js-apis-driver-deviceManager.md)

## 导入模块

```ts
import { deviceManager } from '@kit.DriverDevelopmentKit';
```

## deviceManager.queryDeviceInfo

queryDeviceInfo(deviceId?: number): Array&lt;Readonly&lt;DeviceInfo&gt;&gt;

查询扩展外设详细信息列表。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：**  SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名      | 类型     | 必填  | 说明                     |
|----------|--------|-----|------------------------|
| deviceId | number | 否   | 设备ID，通过queryDevices获得。 |

**返回值：**

| 类型                                                     | 说明          |
|--------------------------------------------------------|-------------|
| Array&lt;Readonly&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | 扩展外设详细信息列表。 |

**错误码：**

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

查询扩展外设驱动详细信息列表。

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

| 名称              | 类型      | 必填  | 说明          |
|-----------------|---------|-----|-------------|
| deviceId        | number  | 是   | 设备ID。       |
| isDriverMatched | boolean | 是   | 设备是否匹配到驱动。  |
| driverUid       | string  | 否   | 设备匹配的驱动UID。 |

## USBDeviceInfo

USB设备详细信息，继承自[DeviceInfo](#deviceinfo)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称                | 类型                                                                 | 必填  | 说明               |
|-------------------|--------------------------------------------------------------------|-----|------------------|
| vendorId          | number                                                             | 是   | USB设备Vendor ID。  |
| productId         | number                                                             | 是   | USB设备Product ID。 |
| interfaceDescList | Array&lt;Readonly&lt;[USBInterfaceDesc](#usbinterfacedesc)&gt;&gt; | 是   | USB设备接口描述符列表。    |

## USBInterfaceDesc

USB设备接口描述符。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称               | 类型     | 必填  | 说明     |
|------------------|--------|-----|--------|
| bInterfaceNumber | number | 是   | 接口编号。  |
| bClass           | number | 是   | 类型代码。  |
| bSubClass        | number | 是   | 子类型代码。 |
| bProtocol        | number | 是   | 协议代码。  |

## DriverInfo

驱动详细信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称            | 类型                                                 | 必填  | 说明             |
|---------------|----------------------------------------------------|-----|----------------|
| busType       | [BusType](js-apis-driver-deviceManager.md#bustype) | 是   | 总线类型。          |
| driverUid     | string                                             | 是   | 驱动Uid。         |
| driverName    | string                                             | 是   | 驱动名称。          |
| driverVersion | string                                             | 是   | 驱动版本。          |
| driverSize    | string                                             | 是   | 驱动大小(单位为Byte)。 |
| description   | string                                             | 是   | 驱动描述。          |

## USBDriverInfo

USB设备驱动详细信息，继承自[DriverInfo](#driverinfo)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称            | 类型                  | 必填  | 说明                      |
|---------------|---------------------|-----|-------------------------|
| productIdList | Array&lt;number&gt; | 是   | 驱动支持的USB设备product ID列表。 |
| vendorIdList  | Array&lt;number&gt; | 是   | 驱动支持的USB设备vendor ID列表。  |