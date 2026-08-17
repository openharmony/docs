# @ohos.multimodalInput.inputDeviceCooperate (Screen Hopping) (System API)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=574e1b97c419a831e3ff5b620b1254fe667a5306 translatedAt=2026-06-12T02:22:15.060Z pushedAt=2026-06-12T06:53:06.211Z -->

The **inputDeviceCooperate** module implements screen hopping for two or more networked devices to share the keyboard and mouse for collaborative operations.

> **NOTE**
>
>- The APIs of this module are no longer maintained since API version 10 and will be deprecated since API version 23. You are advised to use the APIs of [@ohos.cooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md) (Screen Hopping) instead.
> 
>- The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>- The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
```

## inputDeviceCooperate.enable<sup>(deprecated)</sup>

enable(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Enables or disables screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [cooperate.prepareCooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperatepreparecooperate11) and [cooperate.unprepareCooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperateunpreparecooperate11) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name   | Type     | Mandatory | Description   |
| -------- | ------------------------- | ---- | --------------------------- |
| enable   | boolean                   | Yes  | Whether to enable screen hopping.|
| callback | AsyncCallback&lt;void&gt;  | Yes  | Callback. If the operation is successful, **err** is **undefined**. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | -----------------|
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
           inputDeviceCooperate.enable(true, (error: BusinessError) => {
              if (error) {
                console.error(`Failed to enable keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
                return;
              }
              console.info(`Succeeded in enabling keyboard mouse crossing.`);
            });
          } catch (error) {
            console.error(`Failed to enable keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputDeviceCooperate.enable<sup>(deprecated)</sup>

enable(enable: boolean): Promise&lt;void&gt;

Specifies whether to enable screen hopping. This API uses a promise to return the result.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [cooperate.prepareCooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperatepreparecooperate11-1) and [cooperate.unprepareCooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperateunpreparecooperate11-1) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name    | Type    | Mandatory | Description                                                                                |
| --------- | ------- | ---- | -------------------------------------------------------------------                 |
| enable    | boolean | Yes  | Whether to enable screen hopping.                  |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt;      | Promise that returns no value.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | -----------------|
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputDeviceCooperate.enable(true).then(() => {
            console.info(`Succeeded in enabling keyboard mouse crossing.`);
          }).catch((error: BusinessError) => {
            console.error(`Failed to enable keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          });
        })
    }
  }
}
```

## inputDeviceCooperate.start<sup>(deprecated)</sup>

start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback\<void>): void

Starts screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [cooperate.activateCooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperateactivatecooperate11) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| sinkDeviceDescriptor | string                       |  Yes  | Descriptor of the target device for screen hopping.            |
| srcInputDeviceId     | number                       |  Yes  | ID of the target device for screen hopping.          |
| callback             | AsyncCallback\<void>         |  Yes    | Callback. If the operation is successful, **err** is **undefined**. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Hopping Error Codes](errorcode-cooperator.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 4400001  | Incorrect descriptor for the target device.                |
| 4400002  | Screen hop failed.   |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          const sinkDeviceDescriptor = "descriptor";
          let srcInputDeviceId = 0;
          try {
            inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId, (error: BusinessError) => {
              if (error) {
                console.error(`Failed to start keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
                return;
              }
              console.info(`Succeeded in starting keyboard mouse crossing.`);
            });
          } catch (error) {
            console.error(`Failed to start keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputDeviceCooperate.start<sup>(deprecated)</sup>

start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise\<void>

Starts screen hopping. This API uses a promise to return the result.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [cooperate.activateCooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperateactivatecooperate11-1) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| sinkDeviceDescriptor | string                       |  Yes  | Descriptor of the target device for screen hopping.            |
| srcInputDeviceId     | number                       |  Yes  | ID of the target device for screen hopping.          |

**Return value**

| Type                 | Description                            |
| ---------------------- | ------------------------------- |
| Promise\<void>         | Promise that returns no value.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Screen Hopping Error Codes](errorcode-cooperator.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 4400001  | Incorrect descriptor for the target device.          |
| 4400002  | Screen hop failed.              |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          const sinkDeviceDescriptor = "descriptor";
          const srcInputDeviceId = 0;
          inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId).then(() => {
            console.info(`Succeeded in starting keyboard mouse crossing.`);
          }).catch((error: BusinessError) => {
            console.error(`Failed to start keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          });
        })
    }
  }
}
```

## inputDeviceCooperate.stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void>): void

Stops screen hopping. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [cooperate.deactivateCooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperatedeactivatecooperate11) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name               | Type                         | Mandatory | Description                           |
| --------             | ---------------------------- | ----  | ----------------------------   |
| callback             | AsyncCallback\<void>         |  Yes  | Callback. If the operation is successful, **err** is **undefined**. Otherwise, **error** is an error object.         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            inputDeviceCooperate.stop((error: BusinessError) => {
              if (error) {
                console.error(`Failed to stop keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
                return;
              }
              console.info(`Succeeded in stopping keyboard mouse crossing.`);
            });
          } catch (error) {
            console.error(`Failed to stop keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputDeviceCooperate.stop<sup>(deprecated)</sup>

stop(): Promise\<void>

Stops screen hopping. This API uses a promise to return the result.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [cooperate.deactivateCooperate](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperatedeactivatecooperate11-1) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Return value**

| Type               | Description                           |
| --------             | ----------------------------   |
| Promise\<void>       | Promise that returns no value.     |

**Error Code**:

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID | Error Message |
| -------- | -------- |
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          inputDeviceCooperate.stop().then(() => {
            console.info(`Succeeded in stopping keyboard mouse crossing.`);
          }).catch((error: BusinessError) => {
            console.error(`Failed to stop keyboard mouse crossing, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          });
        })
    }
  }
}
```

## inputDeviceCooperate.getState<sup>(deprecated)</sup>

getState(deviceDescriptor: string, callback: AsyncCallback<{ state: boolean }>): void

Obtains the state of the screen hopping switch. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [cooperate.getCooperateSwitchState](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperategetcooperateswitchstate11) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name               | Type                         | Mandatory  | Description                           |
| --------             | ---------                    | ----  | ----------------------------    |
| deviceDescriptor     | string                       |  Yes   | Descriptor of the target device for screen hopping.            |
| callback             | AsyncCallback<{ state: boolean }> |  Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**, **data** is the state of the screen hopping switch (**true** if enabled and **false** if disabled). Otherwise, **error** is an error object.        |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let deviceDescriptor = "descriptor";
          try {
            inputDeviceCooperate.getState(deviceDescriptor, (error: BusinessError, data: object) => {
              if (error) {
                console.error(`Failed to get status, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
                return;
              }
              console.info(`Succeeded in getting status, data: ${JSON.stringify(data)}.`);
            });
          } catch (error) {
            console.error(`Failed to get status, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputDeviceCooperate.getState<sup>(deprecated)</sup>

getState(deviceDescriptor: string): Promise<{ state: boolean }>

Checks whether screen hopping is enabled. This API uses a promise to return the result.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [cooperate.getCooperateSwitchState](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperategetcooperateswitchstate11-1) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name               | Type                         | Mandatory  | Description                           |
| --------             | ---------                    | ----  | ----------------------------    |
| deviceDescriptor     | string                       |  Yes   | Descriptor of the target device for screen hopping.           |

**Return value**

| Type                       | Description                    |
| -------------------        | ------------------------------- |
| Promise<{ state: boolean }>| Promise used to return the state of the screen hopping switch. **true** if enabled and **false** if disabled.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let deviceDescriptor = "descriptor";
          inputDeviceCooperate.getState(deviceDescriptor).then((data: object) => {
            console.info(`Succeeded in getting the status, data: ${JSON.stringify(data)}.`);
          }).catch((error: BusinessError) => {
            console.error(`Failed to get the status, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          });
        })
    }
  }
}
```

## inputDeviceCooperate.on('cooperation')<sup>(deprecated)</sup>

on(type: 'cooperation', callback: AsyncCallback<{ deviceDescriptor: string, eventMsg: EventMsg }>): void

Registers a listener for screen hopping state changes. This API uses an asynchronous callback to return the result.

> **Note:**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use cooperate.on instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name               | Type                                                            | Mandatory| Description                           |
| --------             | ----------------------------                                    | ---- | ----------------------------   |
| type                 | string                                                          |  Yes | Event type. The value is **cooperation**.        |
| callback             | AsyncCallback<{ deviceDescriptor: string, eventMsg: [EventMsg](#eventmsgdeprecated) }> |  Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**, **data** is the screen hopping event information. Otherwise, **err** is undefined.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let callback = (msg: object) => {
            console.info(`Succeeded in monitoring cooperation, msg: ${JSON.stringify(msg)}.`);
            return false;
          }
          try {
            inputDeviceCooperate.on('cooperation', callback);
          } catch (error) {
            console.error(`Failed to register keyboard and mouse traversal status, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## inputDeviceCooperate.off('cooperation')<sup>(deprecated)</sup>

off(type: 'cooperation', callback?: AsyncCallback\<void>): void

Deregisters the listener for screen hopping status changes. This API uses an asynchronous callback to return the result.

> **Note:**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use cooperate.off instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

**Parameters**

| Name               | Type                                                             | Mandatory   | Description                          |
| --------             | ----------------------------                                     | ----   | ----------------------------   |
| type                 | string                                                           |  Yes   | Event type. The value is **cooperation**.        |
| callback             | AsyncCallback\<void> |  No  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is undefined. If this parameter is not specified, all callbacks registered by the current application are unregistered. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 202      | SystemAPI permit error.<br/>Supported version: 12+ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { inputDeviceCooperate } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // Unregister a single callback.
          let callbackOn = (msg: object) => {
            console.info(`Succeeded in monitoring cooperation, msg: ${JSON.stringify(msg)}.`);
            return false;
          }
          try {
            inputDeviceCooperate.on('cooperation', callbackOn);
            inputDeviceCooperate.off("cooperation", callbackOn);
          } catch (error) {
            console.error(`Failed to unregister callback function, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

```ts
import { inputDeviceCooperate } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          // Unregister all callbacks.
          let callback = (msg: object) => {
            console.info(`Succeeded in monitoring cooperation, msg: ${JSON.stringify(msg)}.`);
            return false;
          }
          try {
            inputDeviceCooperate.on('cooperation', callback);
            inputDeviceCooperate.off("cooperation");
          } catch (error) {
            console.error(`Failed to unregister callback function, Code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}.`);
          }
        })
    }
  }
}
```

## EventMsg<sup>(deprecated)</sup>

Enumerates screen hopping events.

> **NOTE**
>
>This API is supported since API version 9 and deprecated since API version 23. You are advised to use [CooperateMessage](../apis-distributedservice-kit/js-apis-devicestatus-cooperate-sys.md#cooperatemessage11) instead.

**System capability**: SystemCapability.MultimodalInput.Input.Cooperator

| Name                      | Value       | Description                             |
| --------                     | --------- |  -----------------               |
| MSG_COOPERATE_INFO_START     | 200       |  Screen hopping starts.      |
| MSG_COOPERATE_INFO_SUCCESS   | 201       |  Screen hopping succeeds.     |
| MSG_COOPERATE_INFO_FAIL      | 202       |  Screen hopping fails.     |
| MSG_COOPERATE_STATE_ON       | 500       |  Screen hopping is enabled.  |
| MSG_COOPERATE_STATE_OFF      | 501       |  Screen hopping is disabled.  |
<!--no_check-->