# @ohos.driver.deviceManager (外设管理)

本模块主要提供管理外部设备的相关功能，包括查询设备列表、绑定设备和解除绑定设备。

>  **说明：**
> 
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import deviceManager from "@ohos.driver.deviceManager";
```

## deviceManager.queryDevices

queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;

获取接入主设备的外部设备列表。如果没有设备接入，那么将会返回一个空的列表。

**需要权限：** ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：** SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名  | 类型   | 必填 | 说明                                 |
| ------- | ------ | ---- | ------------------------------------ |
| busType | number | 否   | 设备总线类型，不填则查找所有类型设备。 |

**返回值：**

| 类型                                           | 说明           |
| ---------------------------------------------- | -------------- |
| Array&lt;Readonly&lt;[Device](#device)&gt;&gt; | 设备信息列表。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 401      | The parameter check failed.              |
| 22900001 | ExternalDeviceManager service exception. |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";


try {
  let devices : Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);
  for (let item of devices) {
    let device : deviceManager.USBDevice = item as deviceManager.USBDevice;
    console.info(`Device id is ${device.deviceId}`)
  }
} catch (error) {
  console.error(`Failed to query device. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.bindDevice

bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;,
  callback: AsyncCallback&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;): void;

根据queryDevices()返回的设备信息绑定设备。

需要调用[deviceManager.queryDevices()](#devicemanagerquerydevices)获取设备信息以及device。

**需要权限：** ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：** SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名       | 类型                                                                                                 | 必填 | 说明                                   |
| ------------ | ---------------------------------------------------------------------------------------------------- | ---- | -------------------------------------- |
| deviceId     | number                                                                                               | 是   | 设备ID，通过queryDevices获得。           |
| onDisconnect | AsyncCallback&lt;number&gt;                                                                          | 是   | 绑定设备断开的回调。                     |
| callback     | AsyncCallback&lt;{deviceId: number, remote: [rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject)}&gt; | 是   | 绑定设备的回调，返回绑定设备的通信对象。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 401      | The parameter check failed.              |
| 22900001 | ExternalDeviceManager service exception. |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";
import { BusinessError } from '@ohos.base';
import type rpc from '@ohos.rpc';

interface DataType {
  deviceId : number;
  remote : rpc.IRemoteObject;
}

try {
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
  deviceManager.bindDevice(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }, (error : BusinessError, data : DataType) => {
    if (error) {
      console.error(`bindDevice async fail. Code is ${error.code}, message is ${error.message}`);
      return;
    }
    console.info(`bindDevice success`);
  });
} catch (error) {
  console.error(`bindDevice fail. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.bindDeviceDriver<sup>11+</sup>
bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;,
  callback: AsyncCallback&lt;RemoteDeviceDriver&gt;): void;

根据queryDevices()返回的设备信息绑定设备。

需要调用[deviceManager.queryDevices()](#devicemanagerquerydevices)获取设备信息以及device。

**需要权限：** ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：** SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名       | 类型                        | 必填 | 说明                         |
| ------------ | --------------------------- | ---- | ---------------------------- |
| deviceId     | number                      | 是   | 设备ID，通过queryDevices获得。 |
| onDisconnect | AsyncCallback&lt;number&gt; | 是   | 绑定设备断开的回调。           |
| callback     | AsyncCallback&lt;RemoteDeviceDriver&gt;| 是 | 指示绑定结果，包括设备 ID 和远程对象。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 401      | The parameter check failed.              |
| 22900001 | ExternalDeviceManager service exception. |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";
import { BusinessError } from '@ohos.base';
import type rpc from '@ohos.rpc';

try {
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
  deviceManager.bindDeviceDriver(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }, (error : BusinessError, data : deviceManager.RemoteDeviceDriver) => {
    if (error) {
      console.error(`bindDeviceDriver async fail. Code is ${error.code}, message is ${error.message}`);
      return;
    }
    console.info(`bindDeviceDriver success`);
  });
} catch (error) {
  console.error(`bindDeviceDriver fail. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.bindDevice

bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number,
  remote: rpc.IRemoteObject}&gt;;

根据queryDevices()返回的设备信息绑定设备。

需要调用[deviceManager.queryDevices](#devicemanagerquerydevices)获取设备信息以及device。

**需要权限：** ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：** SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名       | 类型                        | 必填 | 说明                         |
| ------------ | --------------------------- | ---- | ---------------------------- |
| deviceId     | number                      | 是   | 设备ID，通过queryDevices获得。 |
| onDisconnect | AsyncCallback&lt;number&gt; | 是   | 绑定设备断开的回调。           |

**返回值：** 

| 类型                                                                                           | 说明                                         |
| ---------------------------------------------------------------------------------------------- | -------------------------------------------- |
| Promise&lt;{deviceId: number, remote: [rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject)}&gt; | Promise对象，返回设备ID和IRemoteObject对象。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 401      | The parameter check failed.              |
| 22900001 | ExternalDeviceManager service exception. |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";
import { BusinessError } from '@ohos.base';

try {
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
  deviceManager.bindDevice(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }).then(data => {
    console.info(`bindDevice success, Device_Id is ${data.deviceId}.
    remote is ${data.remote != null ? data.remote.getDescriptor() : "null"}`);
  }, (error: BusinessError) => {
    console.error(`bindDevice async fail. Code is ${error.code}, message is ${error.message}`);
  });
} catch (error) {
  console.error(`bindDevice fail. Code is ${error.code}, message is ${error.message}`);
}
```
## deviceManager.bindDeviceDriver<sup>11+</sup>

bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;RemoteDeviceDriver&gt;;

根据queryDevices()返回的设备信息绑定设备。

需要调用[deviceManager.queryDevices](#devicemanagerquerydevices)获取设备信息以及device。

**需要权限：** ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：** SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名       | 类型                        | 必填 | 说明                         |
| ------------ | --------------------------- | ---- | ---------------------------- |
| deviceId     | number                      | 是   | 设备ID，通过queryDevices获得。 |
| onDisconnect | AsyncCallback&lt;number&gt; | 是   | 绑定设备断开的回调。           |

**返回值：** 

| 类型                              | 说明                                      |
| --------------------------------- | -----------------------------------------|
| Promise&lt;RemoteDeviceDriver&gt; | Promise对象，返回RemoteDeviceDriver对象。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 401      | The parameter check failed.              |
| 22900001 | ExternalDeviceManager service exception. |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";
import { BusinessError } from '@ohos.base';

try {
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
  deviceManager.bindDeviceDriver(12345678, (error : BusinessError, data : number) => {
    console.error(`Device is disconnected`);
  }).then((data: deviceManager.RemoteDeviceDriver) => {
    console.info(`bindDeviceDriver success, Device_Id is ${data.deviceId}.
    remote is ${data.remote != null ? data.remote.getDescriptor() : "null"}`);
  }, (error: BusinessError) => {
    console.error(`bindDeviceDriver async fail. Code is ${error.code}, message is ${error.message}`);
  });
} catch (error) {
  console.error(`bindDeviceDriver fail. Code is ${error.code}, message is ${error.message}`);
}
```

## deviceManager.unbindDevice

unbindDevice(deviceId: number, callback: AsyncCallback&lt;number&gt;): void

解除设备绑定。

**需要权限**：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：**  SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名   | 类型                        | 必填 | 说明                           |
| -------- | --------------------------- | ---- | ------------------------------ |
| deviceId | number                      | 是   | 设备ID，通过queryDevices获得。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 解绑完成的回调。               |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 401      | The parameter check failed.              |
| 22900001 | ExternalDeviceManager service exception. |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";

try {
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
  deviceManager.unbindDevice(12345678, (error : BusinessError, data : number) => {
    if (error) {
      console.error(`unbindDevice async fail. Code is ${error.code}, message is ${error.message}`);
      return;
    }
    console.info(`unbindDevice success`);
  });
} catch (error) {
  console.error(`unbindDevice fail. Code is ${error.code}, message is ${error.message}`);
}
```
## deviceManager.unbindDevice

unbindDevice(deviceId: number): Promise&lt;number&gt;

解除设备绑定。

**需要权限**：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：**  SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名   | 类型   | 必填 | 说明                           |
| -------- | ------ | ---- | ------------------------------ |
| deviceId | number | 是   | 设备ID，通过queryDevices获得。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 401      | The parameter check failed.              |
| 22900001 | ExternalDeviceManager service exception. |

**返回值：** 

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise对象，返回设备ID。 |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";
import { BusinessError } from '@ohos.base';

try {
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
  deviceManager.unbindDevice(12345678).then((data : number) => {
    console.info(`unbindDevice success, Device_Id is ${data}.`);
  }, (error : BusinessError) => {
    console.error(`unbindDevice async fail. Code is ${error.code}, message is ${error.message}`);
  });
} catch (error) {
  console.error(`unbindDevice fail. Code is ${error.code}, message is ${error.message}`);
}
```
## deviceManager.queryDeviceInfo<sup>12+</sup>

queryDeviceInfo(deviceId?: number): Array&lt;Readonly&lt;DeviceInfo&gt;&gt;

查询设备详细信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：**  SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名   | 类型   | 必填  | 说明                           |
| -------- | ------ |-----| ------------------------------ |
| deviceId | number | 否   | 设备ID，通过queryDevices获得。 |

**返回值：**

| 类型                                                     | 说明        |
|--------------------------------------------------------|-----------|
| Array&lt;Readonly&lt;[DeviceInfo](#deviceInfo)&gt;&gt; | 设备详细信息列表。 |

**错误码：**

| 错误码ID    | 错误信息                                                                  |
|----------|-----------------------------------------------------------------------|
| 201      | The permission check failed.                                          |
| 202      | Permission denied. A non-system application cannot call a system API. |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types.        |
| 26300001 | ExternalDeviceManager service exception.                              |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";
import { BusinessError } from '@ohos.base';

try {
  // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
  let deviceInfos : Array<deviceManager.DeviceInfo> = deviceManager.queryDeviceInfo(12345678);
  for (let item of deviceInfos) {
    console.info(`Device id is ${item.deviceId}`)
  }
} catch (error: BusinessError) {
  console.error(`Failed to query device info. Code is ${error.code}, message is ${error.message}`);
}
```
## deviceManager.queryDriverInfo<sup>12+</sup>

queryDriverInfo(driverUid?: string): Array&lt;Readonly&lt;DriverInfo&gt;&gt;

查询驱动详细信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

**系统能力：**  SystemCapability.Driver.ExternalDevice

**参数：**

| 参数名       | 类型     | 必填  | 说明                         |
|-----------|--------|-----|----------------------------|
| driverUid | string | 否   | 驱动UID，通过queryDeviceInfo获得。 |

**返回值：**

| 类型                                                     | 说明        |
|--------------------------------------------------------|-----------|
| Array&lt;Readonly&lt;[DriverInfo](#driverInfo)&gt;&gt; | 驱动详细信息列表。 |

**错误码：**

| 错误码ID    | 错误信息                                                                  |
|----------|-----------------------------------------------------------------------|
| 201      | The permission check failed.                                          |
| 202      | Permission denied. A non-system application cannot call a system API. |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types.        |
| 26300001 | ExternalDeviceManager service exception.                              |

**示例：**

```ts
import deviceManager from "@ohos.driver.deviceManager";
import { BusinessError } from '@ohos.base';

try {
  // driver-12345为示例driverUid，应用开发时可通过queryDeviceInfo查询到相应设备匹配到的驱动的driverUid作为入参
  let driverInfos : Array<deviceManager.DriverInfo> = deviceManager.queryDriverInfo("driver-12345");
  for (let item of driverInfos) {
    console.info(`driver name is ${item.driverName}`)
  }
} catch (error: BusinessError) {
  console.error(`Failed to query driver info. Code is ${error.code}, message is ${error.message}`);
}
```

## Device

外设信息。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称        | 类型                | 必填 | 说明       |
| ----------- | ------------------- | ---- | ---------- |
| busType     | [BusType](#bustype) | 是   | 总线类型。 |
| deviceId    | number              | 是   | 设备ID。   |
| description | string              | 是   | 设备描述。 |

## USBDevice

USB设备信息。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称      | 类型   | 必填 | 说明                |
| --------- | ------ | ---- | ------------------- |
| vendorId  | number | 是   | USB设备Vendor ID。  |
| productId | number | 是   | USB设备Product ID。 |

## BusType

设备总线类型。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称 | 值  | 说明          |
| ---- | --- | ------------- |
| USB  | 1   | USB总线类型。 |

## RemoteDeviceDriver<sup>11+</sup>

远程设备驱动。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称      | 类型   | 必填 | 说明                |
| --------- | ------ | ---- | ------------------- |
| deviceId<sup>11+</sup>  | number | 是   | 设备ID。  |
| remote<sup>11+</sup> | [rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject) | 是   | 远程驱动程序对象。 |

## <text id="deviceInfo">DeviceInfo<sup>12+</sup></text>

设备详细信息。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称              | 类型      | 必填  | 说明          |
|-----------------|---------|-----|-------------|
| deviceId        | number  | 是   | 设备ID。       |
| isDriverMatched | boolean | 是   | 设备是否匹配到驱动。  |
| driverUid       | string  | 否   | 设备匹配的驱动UID。 |

## USBDeviceInfo<sup>12+</sup>

USB设备详细信息。

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称                | 类型                                                                 | 必填  | 说明               |
|-------------------|--------------------------------------------------------------------|-----|------------------|
| vendorId          | number                                                             | 是   | USB设备Vendor ID。  |
| productId         | number                                                             | 是   | USB设备Product ID。 |
| interfaceDescList | Array&lt;Readonly&lt;[USBInterfaceDesc](#usbInterfaceDesc)&gt;&gt; | 是   | USB设备接口描述符列表。    |

## <text id="usbInterfaceDesc">USBInterfaceDesc<sup>12+</sup></text>

USB设备接口描述符

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称               | 类型     | 必填  | 说明     |
|------------------|--------|-----|--------|
| bInterfaceNumber | number | 是   | 接口编号。  |
| bClass           | number | 是   | 类型代码。  |
| bSubClass        | number | 是   | 子类型代码。 |
| bProtocol        | number | 是   | 协议代码。  |

## <text id="driverInfo">DriverInfo<sup>12+</sup></text>

驱动详细信息

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称            | 类型                  | 必填  | 说明     |
|---------------|---------------------|-----|--------|
| busType       | [BusType](#bustype) | 是   | 总线类型。  |
| driverUid     | string              | 是   | 驱动Uid。 |
| driverName    | string              | 是   | 驱动名称。  |
| driverVersion | string              | 是   | 驱动版本。  |
| description   | string              | 是   | 驱动描述。  |

## USBDriverInfo<sup>12+</sup>

USB设备驱动详细信息

**系统能力：** SystemCapability.Driver.ExternalDevice

| 名称            | 类型                  | 必填  | 说明                |
|---------------|---------------------|-----|-------------------|
| productIdList | Array&lt;number&gt; | 是   | 驱动支持的USB设备产品ID列表。 |
| vendorIdList  | Array&lt;number&gt; | 是   | 驱动支持的USB设备厂商ID列表。 |