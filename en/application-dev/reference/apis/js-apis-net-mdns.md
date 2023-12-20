# @ohos.net.mdns (mDNS Management)

Multicast DNS (mDNS) provides functions such as adding, removing, discovering, and resolving local services on a LAN.

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import mdns from '@ohos.net.mdns'
```

## mdns.addLocalService

addLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Adds an mDNS service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the mDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

> **NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

Stage model:

```ts
// Obtain the context.
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.addLocalService(context as Context, localServiceInfo, (error:BusinessError, data:mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.addLocalService

addLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Adds an mDNS service. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204003 | Callback duplicated. |
| 2204008 | Service instance duplicated. |
| 2204010 | Send packet failed. |

> **NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

Stage model:

```ts
// Obtain the context.
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
    address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.addLocalService(context as Context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## mdns.removeLocalService

removeLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Removes an mDNS service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the mDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Service instance not found. |
| 2204010 | Send packet failed. |

> **NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

Stage model:

```ts
// Obtain the context.
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.removeLocalService(context as Context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.removeLocalService

removeLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Removes an mDNS service. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error. |
| 2204002 | Callback not found. |
| 2204008 | Service instance not found. |
| 2204010 | Send packet failed. |

> **NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

Stage model:

```ts
import mdns from '@ohos.net.mdns'
// Obtain the context.
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.removeLocalService(context as Context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

## mdns.createDiscoveryService

createDiscoveryService(context: Context, serviceType: string): DiscoveryService

Creates a **DiscoveryService** object, which is used to discover mDNS services of the specified type.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|---------|-----------| ------------------------------------------------------------ |
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-app-ability-uiAbility.md).|
| serviceType | string  | Yes      | Type of the mDNS services to be discovered.|

**Return value**

| Type                         | Description                     |
| ----------------------------- |---------------------------------|
| DiscoveryService | **DiscoveryService** object used to discover mDNS services based on the specified **serviceType** and **Context**.|

**Error codes**

| ID     | Error Message|
|---------|---|
| 401     | Parameter error. |

**Example**

Stage model:

```ts
// Obtain the context.
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let serviceType = "_print._tcp";
let discoveryService : Object = mdns.createDiscoveryService(context as Context, serviceType);
```

## mdns.resolveLocalService

resolveLocalService(context: Context, serviceInfo: LocalServiceInfo, callback: AsyncCallback\<LocalServiceInfo>): void

Resolves an mDNS service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|----------------------------------|-----------|-------------------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |
| callback | AsyncCallback\<[LocalServiceInfo](#localserviceinfo)> | Yes       |   Callback used to return the result. If the operation is successful, **error** is **undefined** and **data** is the mDNS service information.     |

**Error codes**

| ID     | Error Message|
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Send packet failed.                          |

> **NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

Stage model:

```ts
// Obtain the context.
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.resolveLocalService(context as Context, localServiceInfo, (error: BusinessError, data: mdns.LocalServiceInfo) =>  {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## mdns.resolveLocalService

resolveLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>

Resolves an mDNS service. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| context     | Context                          | Yes      | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-app-ability-uiAbility.md).|
| serviceInfo | [LocalServiceInfo](#localserviceinfo)                 | Yes       |   mDNS service information.     |

**Return value**

| Type                             | Description                                 |
|----------------------------| ------------------------------------- |
| Promise\<[LocalServiceInfo](#localserviceinfo)> | Promise used to return the result.|

**Error codes**

| ID     | Error Message|
|---------|----------------------------------------------|
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service. |
| 2100003 | System internal error.                       |
| 2204003 | Callback duplicated.                         |
| 2204006 | Request timeout.                |
| 2204010 | Send packet failed.                          |

> **NOTE**
> For details about the error codes, see [mDNS Error Codes](../errorcodes/errorcode-net-mdns.md).

**Example**

Stage model:

```ts
// Obtain the context.
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");

let localServiceInfo: mdns.LocalServiceInfo = {
  serviceType: "_print._tcp",
  serviceName: "servicename",
  port: 5555,
  host: {
  address: "10.14.**.***",
  },
  serviceAttribute: [{key: "111", value: [1]}]
}

mdns.resolveLocalService(context as Context, localServiceInfo).then((data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```
## DiscoveryService

Defines a **DiscoveryService** object for discovering mDNS services of the specified type.

### startSearchingMDNS

startSearchingMDNS(): void

Searches for mDNS services on the LAN.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Example**

Stage model:

```ts
// Obtain the context.
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();
```

### stopSearchingMDNS

stopSearchingMDNS(): void

Stops searching for mDNS services on the LAN.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Example**

Stage model:

```ts
// Obtain the context.
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.stopSearchingMDNS();
```

### on('discoveryStart')

on(type: 'discoveryStart', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void

Enables listening for **discoveryStart** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStart**.<br>**discoveryStart**: event of starting discovery of mDNS services on the LAN.|
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MdnsError](#mdnserror)}>                  | Yes       |   Callback used to return the mDNS service and error information.     |

**Example**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}

// See mdns.createDiscoveryService.
class DataServiceInfo{
  serviceInfo: mdns.LocalServiceInfo|null = null
  errorCode?: mdns.MdnsError = 0
}
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('discoveryStart', (data: DataServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('discoveryStart')

off(type: 'discoveryStart', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void

Disables listening for **discoveryStart** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStart**.<br>**discoveryStart**: event of starting discovery of mDNS services on the LAN.|
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MdnsError](#mdnserror)}>                  | No       |   Callback used to return the mDNS service and error information.     |

**Example**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// See mdns.createDiscoveryService.
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

interface Data {
  serviceInfo: mdns.LocalServiceInfo,
  errorCode?: mdns.MdnsError
}
discoveryService.on('discoveryStart', (data: Data) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('discoveryStart', (data: Data) => {
  console.log(JSON.stringify(data));
});
```

### on('discoveryStop')

on(type: 'discoveryStop', callback: Callback<{serviceInfo: LocalServiceInfo, errorCode?: MdnsError}>): void

Enables listening for **discoveryStop** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStop**.<br>**discoveryStop**: event of stopping discovery of mDNS services on the LAN.|
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MdnsError](#mdnserror)}>                 | Yes       |   Callback used to return the mDNS service and error information.     |

**Example**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// See mdns.createDiscoveryService.
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

interface Data {
  serviceInfo: mdns.LocalServiceInfo,
  errorCode?: mdns.MdnsError
}
discoveryService.on('discoveryStop', (data: Data) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('discoveryStop')

off(type: 'discoveryStop', callback?: Callback<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void

Disables listening for **discoveryStop** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **discoveryStop**.<br>**discoveryStop**: event of stopping discovery of mDNS services on the LAN.|
| callback | Callback<{serviceInfo: [LocalServiceInfo](#localserviceinfo), errorCode?: [MdnsError](#mdnserror)}>                 | No       |   Callback used to return the mDNS service and error information.     |

**Example**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// See mdns.createDiscoveryService.
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

interface Data {
  serviceInfo: mdns.LocalServiceInfo,
  errorCode?: mdns.MdnsError
}
discoveryService.on('discoveryStop', (data: Data) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('discoveryStop', (data: Data) => {
  console.log(JSON.stringify(data));
});
```

### on('serviceFound')

on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void

Enables listening for **serviceFound** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceFound**.<br>**serviceFound**: event indicating an mDNS service is found.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>                 | Yes       |   mDNS service information.     |

**Example**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// See mdns.createDiscoveryService.
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('serviceFound')

off(type: 'serviceFound', callback?: Callback\<LocalServiceInfo>): void

Disables listening for **serviceFound** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceFound**.<br>**serviceFound**: event indicating an mDNS service is found.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>                 | No       |   mDNS service information.     |

**Example**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// See mdns.createDiscoveryService.
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();

discoveryService.off('serviceFound', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});
```

### on('serviceLost')

on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void

Enables listening for **serviceLost** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceLost**.<br>serviceLost: event indicating that an mDNS service is removed.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>   | Yes       |   mDNS service information.     |

**Example**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// See mdns.createDiscoveryService.
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
discoveryService.startSearchingMDNS();

discoveryService.on('serviceLost', (data: mdns.LocalServiceInfo) => {
  console.log(JSON.stringify(data));
});

discoveryService.stopSearchingMDNS();
```

### off('serviceLost')

off(type: 'serviceLost', callback?: Callback\<LocalServiceInfo>): void

Disables listening for **serviceLost** events.

**System capability**: SystemCapability.Communication.NetManager.MDNS

**Parameters**

| Name       | Type                            | Mandatory| Description                                    |
|-------------|--------------|-----------|-----------------------------------------------------|
| type     | string                          | Yes      |Event type. This field has a fixed value of **serviceLost**.<br>serviceLost: event indicating that an mDNS service is removed.|
| callback | Callback<[LocalServiceInfo](#localserviceinfo)>   | No       |   mDNS service information.     |

**Example**

```ts
import mdns from '@ohos.net.mdns'
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}

class EntryAbility extends UIAbility {
  value:number = 0;
  onWindowStageCreate(windowStage:window.WindowStage): void{
    GlobalContext.getContext().setObject("value", this.value);
  }
}
// See mdns.createDiscoveryService.
let context = GlobalContext.getContext().getObject("value");
let serviceType = "_print._tcp";
let discoveryService = mdns.createDiscoveryService(context as Context, serviceType);
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

Defines the mDNS service information.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name                 | Type                               | Mandatory| Description                    |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| serviceType   | string                             |  Yes|  Type of the mDNS service. The value is in the format of **\_\<name>.<_tcp/_udp>**, where **name** contains a maximum of 63 characters excluding periods (.). |
| serviceName | string                             |  Yes|  Name of the mDNS service.  |
| port            | number           |  No|  Port number of the mDNS server.          |
| host           |  [NetAddress](js-apis-net-connection.md#netaddress) |  No|  IP address of the device that provides the mDNS service. The IP address is not effective when an mDNS service is added or removed.              |
| serviceAttribute     | serviceAttribute\<[ServiceAttribute](#serviceattribute)> |  No|  mDNS service attribute information.              |

## ServiceAttribute

Defines the mDNS service attribute information.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name                 | Type                               | Mandatory| Description                    |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| key   | string                             |  Yes|  mDNS service attribute key. The value contains a maximum of 9 characters. |
| value | Array\<number>                             |  Yes|  mDNS service attribute value.  |

## MdnsError

Defines the mDNS error information.

**System capability**: SystemCapability.Communication.NetManager.MDNS

| Name        | Value  | Description       |
| --------------- | ---- | ----------- |
| INTERNAL_ERROR  | 0    | Operation failed because of an internal error. (not supported currently) |
| ALREADY_ACTIVE      | 1    | Operation failed because the service already exists. (not supported currently)|
| MAX_LIMIT  | 2 | Operation failed because the number of requests exceeds the maximum value. (not supported currently)|
