# @ohos.sendableResourceManager (Resource Manager)

The **sendableResourceManager** module provides the [resourceToSendableResource](#sendableresourcemanagerresourcetosendableresource) and [sendableResourceToResource](#sendableresourcemanagersendableresourcetoresource) APIs to implement conversion between [Resource](#resource) and [SendableResource](#sendableresource) objects.

A **Resource** object can be held by the [Sendable](../../arkts-utils/arkts-sendable.md) class after being converted into a **SendableResource** object. After cross-thread transmission, the **Sendable** class converts the **SendableResource** object into a **Resource** object and uses it as an input parameter for the API used to obtain resources.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import sendableResourceManager from '@ohos.sendableResourceManager';
```

## sendableResourceManager.resourceToSendableResource

resourceToSendableResource(resource: Resource): SendableResource

Converts a **Resource** object to a **SendableResource** object.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                           |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| resource | [Resource](#resource) | Yes   | **Resource** object.|

**Return value**

| Type    | Description         |
| ------ | ---------------------------- |
| [SendableResource](#sendableresource)  | **SendableResource** object after conversion.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: <br>1.Incorrect parameter types; <br>2.Parameter verification failed.                 |

**Example**
  ```js
import sendableResourceManager from '@ohos.sendableResourceManager';
import { BusinessError } from '@ohos.base';

try {
    let sendableResource: sendableResourceManager.SendableResource = sendableResourceManager.resourceToSendableResource($r('app.string.test'));
} catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`resourceToSendableResource failed, error code: ${code}, message: ${message}.`);
}
  ```

## sendableResourceManager.sendableResourceToResource

sendableResourceToResource(sendableResource: SendableResource): Resource

Converts a **SendableResource** object to a **Resource** object.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                           |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| sendableResource | [SendableResource](#sendableresource) | Yes   | **SendableResource** object.|

**Return value**

| Type    | Description         |
| ------ | ---------------------------- |
| [Resource](#resource) | **Resource** object after conversion.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: <br>1.Incorrect parameter types; <br>2.Parameter verification failed.                 |

**Example**
  ```js
import sendableResourceManager from '@ohos.sendableResourceManager';
import { BusinessError } from '@ohos.base';

try {
    let resource: sendableResourceManager.Resource = sendableResourceManager.sendableResourceToResource(sendableResourceManager.resourceToSendableResource($r('app.string.test')));
} catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`resourceToSendableResource failed, error code: ${code}, message: ${message}.`);
}
  ```

## Resource

Defines a **Resource** object.

**System capability**: SystemCapability.Global.ResourceManager

**Parameters**

| Name        | Type    | Read-Only  | Optional |Description         |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | No   | No| Bundle name of the application.|
| moduleName | string | No   | No| Module name of the application.|
| id         | number | No   | No| Resource ID.     |
| params     | any[] | No   | Yes| Other resource parameters, including the resource name, substitution value for the formatting API, and quantifier for the singular-plural formatting API.     |
| type       | number | No   | Yes| Resource type.     |

## SendableResource

type SendableResource = _SendableResource

**System capability**: SystemCapability.Global.ResourceManager

| Type        | Description    |
| ---------- | ------ | 
| [_SendableResource](sendableResource.md#sendableresource-1)|Defines a **SendableResource** object.|
