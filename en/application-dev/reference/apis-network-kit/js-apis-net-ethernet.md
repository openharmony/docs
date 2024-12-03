# # @ohos.net.ethernet (Ethernet Connection Management)

The **ethernet** module provides Ethernet management functions such as obtaining the network IP address.

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { ethernet } from '@kit.NetworkKit';
```

## HttpProxy

type HttpProxy = connection.HttpProxy;

Defines the network proxy configuration.

**System capability**: SystemCapability.Communication.NetManager.Ethernet

| Type| Description                                      |
| ------- | ----------------------------------------|
| connection.HttpProxy     | Network proxy configuration.     |


## ethernet.getMacAddress<sup>14+</sup>

getMacAddress(): Promise\<Array\<MacAddressInfo>>

Obtains the names and MAC addresses of all Ethernet NICs. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_ETHERNET_LOCAL_MAC

**System capability**: SystemCapability.Communication.NetManager.Ethernet

**Return value**

| Type                                                   | Description                              |
|-------------------------------------------------------| ---------------------------------- |
| Promise\<Array[\<MacAddressInfo>](#macaddressinfo14)> | Promise used to return the result.       |

**Error codes**

| ID| Error Message                                |
| ------- | ----------------------------------------|
| 201     | Permission denied.                      |
| 2200002 | Failed to connect to the service.       |
| 2201005 | Device information does not exist.  |

**Example**

```ts
import { ethernet } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

ethernet.getMacAddress().then((data: Array<ethernet.MacAddressInfo>) => {
  console.info("getMacAddress promise data = " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error("getMacAddress promise error = " + JSON.stringify(error));
});
```

## MacAddressInfo<sup>14+</sup>
Defines the name and MAC address of an Ethernet NIC.

**System capability**: SystemCapability.Communication.NetManager.Ethernet

| Name        | Type                   | Mandatory| Description                                                |
| ------------ | ----------------------- | --- | ---------------------------------------------------- |
| iface        | string                  |  Yes| Name of the Ethernet NIC.                                       |
| macAddress       | string                |  Yes| MAC address of the Ethernet NIC.|
