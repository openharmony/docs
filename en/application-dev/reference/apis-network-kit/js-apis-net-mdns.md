# @ohos.net.mdns (MDNS Management)

Multicast DNS (MDNS) provides functions such as adding, removing, discovering, and resolving local services on a LAN.

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { mdns } from '@kit.NetworkKit';
```

## mdns.addLocalService

addLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Adds an MDNS service. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For the application context of the stage model, see [Context](../apis-ability-kit/js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   MDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the MDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Failed to delete the service instance. |
| 2204010 | Failed to send the message. |

> **NOTE**
> For details about the error codes, see [MDNS Error Codes](errorcode-net-mdns.md).

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context.
let context = getContext(this) as Context;

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.addLocalService(context, localServiceInfo, (error:BusinessError, data:mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.addLocalService

addLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Adds an MDNS service. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For the application context of the stage model, see [Context](../apis-ability-kit/js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   MDNS service information.     |

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Failed to delete the service instance. |
| 2204010 | Failed to send the message. |

> **NOTE**
> For details about the error codes, see [MDNS Error Codes](errorcode-net-mdns.md).

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context.
let context = getContext(this) as Context;

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
    address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.addLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## mdns.removeLocalService

removeLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Removes an MDNS service. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For the application context of the stage model, see [Context](../apis-ability-kit/js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   MDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the MDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Failed to delete the service instance. |
| 2204010 | Failed to send the message. |

> **NOTE**
> For details about the error codes, see [MDNS Error Codes](errorcode-net-mdns.md).

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context.
let context = getContext(this) as Context;

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.removeLocalService(context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.removeLocalService

removeLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Removes an MDNS service. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For the application context of the stage model, see [Context](../apis-ability-kit/js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   MDNS service information.     |

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Failed to delete the service instance. |
| 2204010 | Failed to send the message. |

> **NOTE**
> For details about the error codes, see [MDNS Error Codes](errorcode-net-mdns.md).

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context = getContext(this) as Context;

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.removeLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## mdns.createDiscoveryService

createDiscoveryService(context: Context, serviceType: string): DiscoveryService

Creates a **DiscoveryService** object, which is used to discover MDNS services of the specified type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|---------|-----------| ------------------------------------------------------------ |
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For the application context of the stage model, see [Context](../apis-ability-kit/js-apis-app-ability-uiAbility.md).|
| serviceType | string  | Yes      | Type of the MDNS services to be discovered.|

**Return value**

| Type                         | Description                     |
| ----------------------------- |---------------------------------|
| DiscoveryService | **DiscoveryService** object used to discover MDNS services based on the specified **serviceType** and **Context**.|

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context.
let context = getContext(this) as Context;

let serviceType = "_print._tcp";
let discoveryService : Object = mdns.createDiscoveryService(context, serviceType);
```

## mdns.resolveLocalService

resolveLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Resolves an MDNS service. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For the application context of the stage model, see [Context](../apis-ability-kit/js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   MDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the MDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Failed to connect to the service.            |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Failed to send the message.                  |

> **NOTE**
> For details about the error codes, see [MDNS Error Codes](errorcode-net-mdns.md).

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context.
let context = getContext(this) as Context;

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.resolveLocalService(context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.resolveLocalService

resolveLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Resolves an MDNS service. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For the application context of the stage model, see [Context](../apis-ability-kit/js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   MDNS service information.     |

**Return value**

| Type                             | Description                                 |
|----------------------------| ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Failed to connect to the service.            |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Failed to send the message.                  |

> **NOTE**
> For details about the error codes, see [MDNS Error Codes](errorcode-net-mdns.md).

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context.
let context = getContext(this) as Context;

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.resolveLocalService(context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```
## DiscoveryService

Defines a **DiscoveryService** object for discovering MDNS services of the specified type.

### startSearchingMDNS

startSearchingMDNS(): void

Searches for MDNS services on the LAN.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();
```

### stopSearchingMDNS

stopSearchingMDNS(): void

Stops searching for MDNS services on the LAN.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Example**

Stage model:

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the context.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.stopSearchingMDNS();
```

### on('discoveryStart')

on(type: 'discoveryStart', callback: Callback\<DiscoveryEventInfo\>): void

Enables listening for **discoveryStart** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name     | Type                            | Mandatory| Description                                                  |
|-------------|---------------------------------|------|--------------------------------------------------------|
| type        | string                          | Yes  | Event type. This field has a fixed value of **discoveryStart**.<br>**discoveryStart**: event of starting discovery of MDNS services on the LAN.|
| callback    | Callback\<DiscoveryEventInfo\>  | Yes  | Callback used to return the MDNS service and error information.                          |

**Example**

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// See mdns.createDiscoveryService.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('discoveryStart')

off(type: 'discoveryStart', callback?: Callback\<DiscoveryEventInfo\>): void

Disables listening for **discoveryStart** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStart**.<br>**discoveryStart**: event of starting discovery of MDNS services on the LAN.|
| callback | Callback\<DiscoveryEventInfo\>  | No      |Callback used to return the MDNS service and error information.         |

**Example**

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// See mdns.createDiscoveryService.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('discoveryStart', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
```

### on('discoveryStop')

on(type: 'discoveryStop', callback: Callback\<DiscoveryEventInfo\>): void

Enables listening for **discoveryStop** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStop**.<br>**discoveryStop**: event of stopping discovery of MDNS services on the LAN.|
| callback | Callback\<DiscoveryEventInfo\>  | Yes      |Callback used to return the MDNS service and error information.     |

**Example**

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// See mdns.createDiscoveryService.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('discoveryStop')

off(type: 'discoveryStop', callback?: Callback\<DiscoveryEventInfo\>): void

Disables listening for **discoveryStop** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStop**.<br>**discoveryStop**: event of stopping discovery of MDNS services on the LAN.|
| callback | Callback\<DiscoveryEventInfo\>  | No      |Callback used to return the MDNS service and error information.     |

**Example**

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// See mdns.createDiscoveryService.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('discoveryStop', (data: mdns.DiscoveryEventInfo) => {
  console.log(JSON.stringify(data));
});
```

### on('serviceFound')

on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void

Enables listening for **serviceFound** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceFound**.<br>**serviceFound**: event indicating an MDNS service is found.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>                 | Yes       |   Callback used to return the MDNS service information. You need to call **resolveLocalService** to parse the information.     |

**Example**

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// See mdns.createDiscoveryService.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.info('serviceFound', JSON.stringify(data));
  mdns.resolveLocalService(context, data, (error: BusinessError, resolveData: mdns.LocalServiceInfo) =>  {
    console.info('serviceFound', JSON.stringify(resolveData));
  });
});

discoveryService.stopSearchingMDNS();
```

### off('serviceFound')

off(type: 'serviceFound', callback?: Callback\<LocalServiceInfo>): void

Disables listening for **serviceFound** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceFound**.<br>**serviceFound**: event indicating an MDNS service is found.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>                 | No       |   MDNS service information.     |

**Example**

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// See mdns.createDiscoveryService.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.info('serviceFound', JSON.stringify(data));
  mdns.resolveLocalService(context, data, (error: BusinessError, resolveData: mdns.LocalServiceInfo) =>  {
    console.info('serviceFound', JSON.stringify(resolveData));
  });
});

discoveryService.stopSearchingMDNS();

discoveryService.off('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

### on('serviceLost')

on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void

Enables listening for **serviceLost** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceLost**.<br>serviceLost: event indicating that an MDNS service is removed.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>   | Yes       |   MDNS service information.     |

**Example**

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// See mdns.createDiscoveryService.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('serviceLost')

off(type: 'serviceLost', callback?: Callback\<LocalServiceInfo>): void

Disables listening for **serviceLost** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceLost**.<br>serviceLost: event indicating that an MDNS service is removed.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>   | No       |   MDNS service information.     |

**Example**

```ts
import { mdns } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// See mdns.createDiscoveryService.
let context = getContext(this) as Context;
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## LocalServiceInfo

Defines the MDNS service information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name                 | Type                               | Mandatory| Description                    |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| serviceType   | string                             |  Yes|  Type of the MDNS service. The value is in the format of **\_\<name>.<_tcp/_udp>**, where **name** contains a maximum of 63 characters excluding periods (.). |
| serviceName | string                             |  Yes|  Name of the MDNS service.  |
| port            | number           |  No|  Port number of the MDNS server.          |
| host           |  [NetAddress](js-apis-net-connection.md#netaddress) |  No|  IP address of the device that provides the MDNS service. The IP address is not effective when an MDNS service is added or removed.              |
| serviceAttribute     | Array\<[ServiceAttribute](#serviceattribute)> |  No|  MDNS service attribute information.              |

## ServiceAttribute

Defines the MDNS service attribute information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name                 | Type                               | Mandatory| Description                    |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| key   | string                             |  Yes|  MDNS service attribute key. The value contains a maximum of 9 characters. |
| value | Array\<number>                             |  Yes|  MDNS service attribute value.  |

## DiscoveryEventInfo<sup>11+</sup>

Defines the MDNS service event information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

|    Name    |            Type                    | Mandatory| Description                 |
| ----------- | ----------------------------------- | --- | --------------------- |
| serviceInfo | LocalServiceInfo                    |  Yes|  MDNS service information.       |
| errorCode   | MdnsError                           |  No|  Defines the MDNS error information.       |

## MdnsError

Defines the MDNS error information.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name        | Value  | Description       |
| --------------- | ---- | ----------- |
| INTERNAL_ERROR  | 0    | Operation failed because of an internal error. |
| ALREADY_ACTIVE      | 1    | Operation failed because the service already exists.|
| MAX_LIMIT  | 2 | Operation failed because the number of requests exceeds the maximum value.|

## NetAddress

type NetAddress = connection.NetAddress

Obtains the network address.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.NetManager

|       Type      |            Description            |
| ---------------- | --------------------------- |
| connection.NetAddress | Network address.    |
