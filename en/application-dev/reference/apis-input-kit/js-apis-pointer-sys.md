# @ohos.multimodalInput.pointer (Mouse Pointer) (System API)

The **pointer** module provides APIs related to pointer attribute management.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.multimodalInput.pointer (Mouse Pointer)](js-apis-pointer.md).

## Modules to Import

```js
import { pointer } from '@kit.InputKit';
```

## pointer.setPointerSpeed

setPointerSpeed(speed: number, callback: AsyncCallback&lt;void&gt;): void

Sets the moving speed of the mouse pointer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| speed    | number                    | Yes   | Moving speed of the mouse pointer. The value ranges from **1** to **20**. The default value is **10**.  |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |


**Example**

```js
try {
  pointer.setPointerSpeed(5, (error: Error) => {
    if (error) {
      console.error(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set pointer speed success`);
  });
} catch (error) {
  console.error(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerSpeed

setPointerSpeed(speed: number): Promise&lt;void&gt;

Sets the moving speed of the mouse pointer. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| speed | number | Yes   | Moving speed of the mouse pointer. The value ranges from **1** to **20**. The default value is **10**.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Screen Hopping Error Codes](../apis-distributedservice-kit/errorcode-devicestatus.md).

| ID| Error Message         |
| -------- | ----------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |


**Example**

```js
try {
  pointer.setPointerSpeed(5).then(() => {
    console.log(`Set pointer speed success`);
  });
} catch (error) {
  console.error(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerSpeedSync<sup>10+</sup>

setPointerSpeedSync(speed: number): void

Sets the moving speed of the mouse pointer. This API returns the result synchronously.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| speed | number | Yes   | Moving speed of the mouse pointer. The value ranges from **1** to **20**. The default value is **10**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  let speed = pointer.setPointerSpeedSync(5);
  console.log(`Set pointer speed success`);
} catch (error) {
  console.error(`Set pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerSpeed

getPointerSpeed(callback: AsyncCallback&lt;number&gt;): void

Obtains the moving speed of the mouse pointer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |


**Example**

```js
try {
  pointer.getPointerSpeed((error: Error, speed: number) => {
    if (error) {
      console.error(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Get pointer speed success, speed: ${JSON.stringify(speed)}`);
  });
} catch (error) {
  console.error(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerSpeed

getPointerSpeed(): Promise&lt;number&gt;

Obtains the moving speed of the mouse pointer. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```js
try {
  pointer.getPointerSpeed().then(speed => {
    console.log(`Get pointer speed success, speed: ${JSON.stringify(speed)}`);
  });
} catch (error) {
  console.error(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerSpeedSync<sup>10+</sup>

getPointerSpeedSync(): number

Obtains the moving speed of the mouse pointer. This API returns the result synchronously.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| number | Moving speed of the mouse pointer.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  let speed = pointer.getPointerSpeedSync();
  console.log(`Get pointer speed success, speed: ${JSON.stringify(speed)}`);
} catch (error) {
  console.error(`Get pointer speed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setHoverScrollState<sup>10+</sup>

setHoverScrollState(state: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the status of the mouse hover scroll switch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state    | boolean                    | Yes   | Status of the mouse hover scroll switch. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite.  |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setHoverScrollState(true, (error: Error) => {
    if (error) {
      console.error(`Set the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set the mouse hover scroll success`);
  });
} catch (error) {
  console.error(`Set the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setHoverScrollState<sup>10+</sup>

setHoverScrollState(state: boolean): Promise&lt;void&gt;

Sets the status of the mouse hover scroll switch. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| state | boolean | Yes   | Status of the mouse hover scroll switch. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setHoverScrollState(true).then(() => {
    console.log(`Set the mouse hover scroll success`);
  });
} catch (error) {
  console.error(`Set the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getHoverScrollState<sup>10+</sup>

getHoverScrollState(callback: AsyncCallback&lt;boolean&gt;): void

Obtains the status of the mouse hover scroll switch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getHoverScrollState((error: Error, state: boolean) => {
    console.log(`Get the mouse hover scroll success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`Get the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getHoverScrollState<sup>10+</sup>

getHoverScrollState(): Promise&lt;boolean&gt;

Obtains the status of the mouse hover scroll switch. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getHoverScrollState().then((state: boolean) => {
    console.log(`Get the mouse hover scroll success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`Get the mouse hover scroll failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setMousePrimaryButton<sup>10+</sup>

setMousePrimaryButton(primary: PrimaryButton, callback: AsyncCallback&lt;void&gt;): void

Sets the primary button of the mouse. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type                     | Mandatory | Description                                   |
| -------- | ------------------------- | ----  | ------------------------------------- |
| primary  | [PrimaryButton](js-apis-pointer.md#primarybutton10)   | Yes   | ID of the primary mouse button.  |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setMousePrimaryButton(pointer.PrimaryButton.RIGHT, (error: Error) => {
    if (error) {
      console.error(`Set mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`Set mouse primary button success`);
  });
} catch (error) {
  console.error(`Set mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setMousePrimaryButton<sup>10+</sup>

setMousePrimaryButton(primary: PrimaryButton): Promise&lt;void&gt;

Sets the primary button of the mouse. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| primary | [PrimaryButton](js-apis-pointer.md#primarybutton10) | Yes   | ID of the primary mouse button.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setMousePrimaryButton(pointer.PrimaryButton.RIGHT).then(() => {
    console.log(`Set mouse primary button success`);
  });
} catch (error) {
  console.error(`Set mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getMousePrimaryButton<sup>10+</sup>

getMousePrimaryButton(callback: AsyncCallback&lt;PrimaryButton&gt;): void

Obtains the primary button of the mouse. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;[PrimaryButton](js-apis-pointer.md#primarybutton10)&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getMousePrimaryButton((error: Error, primary: pointer.PrimaryButton) => {
    console.log(`Get mouse primary button success, primary: ${JSON.stringify(primary)}`);
  });
} catch (error) {
  console.error(`Get mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getMousePrimaryButton<sup>10+</sup>

getMousePrimaryButton(): Promise&lt;PrimaryButton&gt;

Obtains the primary button of the mouse. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;[PrimaryButton](js-apis-pointer.md#primarybutton10)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getMousePrimaryButton().then((primary: pointer.PrimaryButton) => {
    console.log(`Get mouse primary button success, primary: ${JSON.stringify(primary)}`);
  });
} catch (error) {
  console.error(`Get mouse primary button failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setMouseScrollRows<sup>10+</sup>

setMouseScrollRows(rows: number, callback: AsyncCallback&lt;void&gt;): void

Sets the number of mouse scroll rows. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| rows     | number                    | Yes   | Number of mouse scroll rows. The value ranges from 1 to 100. The default value is **3**.  |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setMouseScrollRows(1, (error: Error) => {
    if (error) {
      console.error(`setMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setMouseScrollRows success`);
  });
} catch (error) {
  console.error(`setMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setMouseScrollRows<sup>10+</sup>

setMouseScrollRows(rows: number): Promise&lt;void&gt;

Sets the number of mouse scroll rows. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| rows  | number | Yes   | Number of mouse scroll rows. The value ranges from 1 to 100. The default value is **3**.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setMouseScrollRows(20).then(() => {
    console.log(`setMouseScrollRows success`);
  });
} catch (error) {
  console.error(`setMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getMouseScrollRows<sup>10+</sup>

getMouseScrollRows(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of mouse scroll rows. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getMouseScrollRows((error: Error, rows: number) => {
    console.log(`getMouseScrollRows success, rows: ${JSON.stringify(rows)}`);
  });
} catch (error) {
  console.error(`getMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getMouseScrollRows<sup>10+</sup>

getMouseScrollRows(): Promise&lt;number&gt;

Obtains the moving speed of the mouse pointer. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getMouseScrollRows().then((rows: number) => {
    console.log(`getMouseScrollRows success, rows: ${JSON.stringify(rows)}`);
  });
} catch (error) {
  console.error(`getMouseScrollRows failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadScrollSwitch<sup>10+</sup>

setTouchpadScrollSwitch(state: boolean, callback: AsyncCallback\<void>): void

Sets the scroll switch of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state | boolean | Yes   | Scroll switch status. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.  |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadScrollSwitch(true, (error: Error) => {
    if (error) {
      console.error(`setTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setTouchpadScrollSwitch success`);
  });
} catch (error) {
  console.error(`setTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadScrollSwitch<sup>10+</sup>

setTouchpadScrollSwitch(state: boolean): Promise\<void>

Sets the scroll switch of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| state | boolean| Yes   |  Scroll switch status. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadScrollSwitch(false).then(() => {
    console.log(`setTouchpadScrollSwitch success`);
  });
} catch (error) {
  console.error(`setTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadScrollSwitch<sup>10+</sup>

getTouchpadScrollSwitch(callback:  AsyncCallback\<boolean>): void

Obtains the scroll switch status of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadScrollSwitch((error: Error, state: boolean) => {
    console.log(`getTouchpadScrollSwitch success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadScrollSwitch<sup>10+</sup>

getTouchpadScrollSwitch(): Promise\<boolean>

Obtains the scroll switch status of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadScrollSwitch().then((state) => {
    console.log(`getTouchpadScrollSwitch success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadScrollSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadScrollDirection<sup>10+</sup>

setTouchpadScrollDirection(state: boolean, callback: AsyncCallback\<void>): void

Sets the scroll direction of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state | boolean | Yes   | Scroll direction of the touchpad.<br>The value **true** indicates that the scroll direction is the same as the finger moving direction, and the value **false** indicates the opposite.<br>The default value is **true**.  |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadScrollDirection(true, (error: Error) => {
    if (error) {
      console.error(`setTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setTouchpadScrollDirection success`);
  });
} catch (error) {
  console.error(`setTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadScrollDirection<sup>10+</sup>

setTouchpadScrollDirection(state: boolean): Promise\<void>

Sets the scroll direction of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| state | boolean| Yes   |  Scroll direction of the touchpad.<br>The value **true** indicates that the scroll direction is the same as the finger moving direction, and the value **false** indicates the opposite.<br>The default value is **true**.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadScrollDirection (false).then(() => {
    console.log(`setTouchpadScrollDirection success`);
  });
} catch (error) {
  console.error(`setTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadScrollDirection<sup>10+</sup>

getTouchpadScrollDirection(callback:  AsyncCallback\<boolean>): void

Obtains the scroll direction of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result.<br>The value **true** indicates that the scroll direction is the same as the finger moving direction, and the value **false** indicates the opposite.<br>The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadScrollDirection ((error: Error, state: boolean) => {
    console.log(`getTouchpadScrollDirection success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadScrollDirection<sup>10+</sup>

getTouchpadScrollDirection(): Promise\<boolean>

Obtains the scroll direction of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result.<br>The value **true** indicates that the scroll direction is the same as the finger moving direction, and the value **false** indicates the opposite.<br>The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadScrollDirection().then((state: boolean) => {
    console.log(`getTouchpadScrollDirection success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadScrollDirection failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadTapSwitch<sup>10+</sup>

setTouchpadTapSwitch(state: boolean, callback: AsyncCallback\<void>): void

Sets the tap switch of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state | boolean | Yes   |Tap switch status of the touchpad The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.  |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadTapSwitch(true, (error: Error) => {
    if (error) {
      console.error(`setTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setTouchpadTapSwitch success`);
  });
} catch (error) {
  console.error(`setTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadTapSwitch <sup>10+</sup>

setTouchpadTapSwitch(state: boolean): Promise\<void>

Sets the tap switch of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| state | boolean| Yes   |  Tap switch status of the touchpad. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**. |

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadTapSwitch(false).then(() => {
    console.log(`setTouchpadTapSwitch success`);
  });
} catch (error) {
  console.error(`setTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadTapSwitch<sup>10+</sup>

getTouchpadTapSwitch(callback:  AsyncCallback\<boolean>): void

Obtains the tap switch status of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadTapSwitch((error: Error, state: boolean) => {
    console.log(`getTouchpadTapSwitch success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadTapSwitch<sup>10+</sup>

getTouchpadTapSwitch(): Promise\<boolean>

Obtains the tap switch status of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadTapSwitch().then((state: boolean) => {
    console.log(`getTouchpadTapSwitch success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadTapSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadPointerSpeed<sup>10+</sup>

setTouchpadPointerSpeed(speed: number, callback: AsyncCallback\<void>): void

Sets the mouse pointer moving speed of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| speed | number                    | Yes   |Mouse pointer moving speed of the touchpad. The value range is [1,11]. The default value is **6**. |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadPointerSpeed(1, (error: Error) => {
    if (error) {
      console.error(`setTouchpadPointerSpeedfailed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setTouchpadPointerSpeed success`);
  });
} catch (error) {
  console.error(`setTouchpadPointerSpeed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadPointerSpeed<sup>10+</sup>

setTouchpadPointerSpeed(speed: number): Promise\<void>

Sets the mouse pointer moving speed of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| speed| number | Yes   | Mouse pointer moving speed of the touchpad. The value range is [1,11]. The default value is **6**.   |

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadPointerSpeed(10).then(() => {
    console.log(`setTouchpadPointerSpeed success`);
  });
} catch (error) {
  console.error(`setTouchpadPointerSpeed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadPointerSpeed<sup>10+</sup>

getTouchpadPointerSpeed(callback: AsyncCallback\<number>): void

Obtains the mouse pointer moving speed of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback\<number> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadPointerSpeed((error: Error, speed: number) => {
    console.log(`getTouchpadPointerSpeed success, speed: ${JSON.stringify(speed)}`);
  });
} catch (error) {
  console.error(`getTouchpadPointerSpeed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadPointerSpeed<sup>10+</sup>

getTouchpadPointerSpeed(): Promise\<number>

Obtains the mouse pointer moving speed of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise\<number> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadPointerSpeed().then((speed: number) => {
    console.log(`getTouchpadPointerSpeed success, speed: ${JSON.stringify(speed)}`);
  });
} catch (error) {
  console.error(`getTouchpadPointerSpeed failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadPinchSwitch<sup>10+</sup>

setTouchpadPinchSwitch(state: boolean, callback: AsyncCallback\<void>): void

Sets the pinch switch of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state | boolean | Yes   |Pinch switch status of the touchpad. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.  |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadTapSwitch(true, (error: Error) => {
    if (error) {
      console.error(`setTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setTouchpadPinchSwitch success`);
  });
} catch (error) {
  console.error(`setTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadPinchSwitch<sup>10+</sup>

setTouchpadPinchSwitch(state: boolean): Promise\<void>

Sets the pinch switch of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| state | boolean| Yes   |  Pinch switch status of the touchpad. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**. |

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadPinchSwitch(false).then(() => {
    console.log(`setTouchpadPinchSwitch success`);
  });
} catch (error) {
  console.error(`setTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadPinchSwitch<sup>10+</sup>

getTouchpadPinchSwitch(callback:  AsyncCallback\<boolean>): void

Obtains the pinch switch status of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadPinchSwitch((error: Error, state: boolean) => {
    console.log(`getTouchpadPinchSwitch success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadPinchSwitch<sup>10+</sup>

getTouchpadPinchSwitch(): Promise\<boolean>

Obtains the pinch switch status of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadPinchSwitch().then((state: boolean) => {
    console.log(`getTouchpadPinchSwitch success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadPinchSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadSwipeSwitch<sup>10+</sup>

setTouchpadSwipeSwitch(state: boolean, callback: AsyncCallback\<void>): void

Sets the multi-finger swipe switch of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state | boolean | Yes   |Swipe switch status of the touchpad. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.  |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadSwipeSwitch(true, (error: Error) => {
    if (error) {
      console.error(`setTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setTouchpadSwipeSwitch success`);
  });
} catch (error) {
  console.error(`setTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadSwipeSwitch<sup>10+</sup>

setTouchpadSwipeSwitch(state: boolean): Promise\<void>

Sets the swipe switch of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| state | boolean| Yes   |  Swipe switch status of the touchpad. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**. |

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadSwipeSwitch(false).then(() => {
    console.log(`setTouchpadSwipeSwitch success`);
  });
} catch (error) {
  console.error(`setTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadSwipeSwitch<sup>10+</sup>

getTouchpadSwipeSwitch(callback:  AsyncCallback\<boolean>): void

Obtains the multi-finger swipe switch status of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadSwipeSwitch((error: Error, state: boolean) => {
    console.log(`getTouchpadSwipeSwitch success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadSwipeSwitch<sup>10+</sup>

getTouchpadSwipeSwitch(): Promise\<boolean>

Obtains the multi-finger swipe switch status of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite. The default value is **true**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadSwipeSwitch().then((state: boolean) => {
    console.log(`getTouchpadSwipeSwitch success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadSwipeSwitch failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadRightClickType<sup>10+</sup>

setTouchpadRightClickType(type: RightClickType, callback: AsyncCallback\<void>): void

Sets the shortcut menu type of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| type| [RightClickType](js-apis-pointer.md#rightclicktype10)| Yes   |Shortcut menu type of the touchpad.<br>- TOUCHPAD_RIGHT_BUTTON: Tapping the right-button area of the touchpad.<br>- TOUCHPAD_LEFT_BUTTON: Tapping the left-button area of the touchpad.<br>- TOUCHPAD_TWO_FINGER_TAP: Tapping or pressing the touchpad with two fingers.<br>- TOUCHPAD_TWO_FINGER_TAP_OR_RIGHT_BUTTON<sup>20+</sup>: Tapping or pressing the touchpad with two fingers, or tapping the right-button area of the touchpad.<br>- TOUCHPAD_TWO_FINGER_TAP_OR_LEFT_BUTTON<sup>20+</sup>: Tapping or pressing the touchpad with two fingers, or tapping the left-button area of the touchpad.<br>The default value is **TOUCHPAD_TWO_FINGER_TAP_OR_RIGHT_BUTTON**.|
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadRightClickType(pointer.RightClickType.TOUCHPAD_RIGHT_BUTTON , (error: Error) => {
    if (error) {
      console.error(`setTouchpadRightClickType, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setTouchpadRightClickType success`);
  });
} catch (error) {
  console.error(`setTouchpadRightClickType failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadRightClickType<sup>10+</sup>

setTouchpadRightClickType(type: RightClickType): Promise\<void>

Sets the shortcut menu type of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| type| [RightClickType](js-apis-pointer.md#rightclicktype10)| Yes   |Shortcut menu type of the touchpad.<br>- TOUCHPAD_RIGHT_BUTTON: Tapping the right-button area of the touchpad.<br>- TOUCHPAD_LEFT_BUTTON: Tapping the left-button area of the touchpad.<br>- TOUCHPAD_TWO_FINGER_TAP: Tapping or pressing the touchpad with two fingers.<br>- TOUCHPAD_TWO_FINGER_TAP_OR_RIGHT_BUTTON<sup>20+</sup>: Tapping or pressing the touchpad with two fingers, or tapping the right-button area of the touchpad.<br>- TOUCHPAD_TWO_FINGER_TAP_OR_LEFT_BUTTON<sup>20+</sup>: Tapping or pressing the touchpad with two fingers, or tapping the left-button area of the touchpad.<br>The default value is **TOUCHPAD_TWO_FINGER_TAP_OR_RIGHT_BUTTON**.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadRightClickType(pointer.RightClickType.TOUCHPAD_RIGHT_BUTTON).then(() => {
    console.log(`setTouchpadRightClickType success`);
  });
} catch (error) {
  console.error(`setTouchpadRightClickType failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadRightClickType<sup>10+</sup>

getTouchpadRightClickType(callback: AsyncCallback\<RightClickType>): void

Obtains the shortcut menu type of the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback\<[RightClickType](js-apis-pointer.md#rightclicktype10)> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadRightClickType((error: Error, type: pointer.RightClickType) => {
    console.log(`getTouchpadRightClickType success, type: ${JSON.stringify(type)}`);
  });
} catch (error) {
  console.error(`getTouchpadRightClickType failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadRightClickType<sup>10+</sup>

getTouchpadRightClickType(): Promise\<RightClickType>

Obtains the shortcut menu type of the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise\<[RightClickType](js-apis-pointer.md#rightclicktype10) > | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadRightClickType().then((type: pointer.RightClickType) => {
    console.log(`getTouchpadRightClickType success, typeed: ${JSON.stringify(type)}`);
  });
} catch (error) {
  console.error(`getTouchpadRightClickType failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerSize<sup>10+</sup>

setPointerSize(size: number, callback: AsyncCallback&lt;void&gt;): void

Sets the pointer size. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| size     | number                    | Yes   | Pointer size. The value ranges from **1** to **7**. The default value is **1**.  |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setPointerSize(1, (error: Error) => {
    if (error) {
      console.error(`setPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setPointerSize success`);
  });
} catch (error) {
  console.error(`setPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerSize<sup>10+</sup>

setPointerSize(size: number): Promise&lt;void&gt;

Sets the pointer size. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| size  | number | Yes   | Pointer size. The value ranges from **1** to **7**. The default value is **1**.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setPointerSize(3).then(() => {
    console.log(`setPointerSize success`);
  });
} catch (error) {
  console.error(`setPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerSizeSync<sup>10+</sup>

setPointerSizeSync(size: number): void

Sets the pointer size. This API returns the result synchronously.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| size  | number | Yes   | Pointer size. The value ranges from **1** to **7**. The default value is **1**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setPointerSizeSync(5);
  console.log(`setPointerSizeSync success`);
} catch (error) {
  console.error(`setPointerSizeSync failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerSize<sup>10+</sup>

getPointerSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the pointer size. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getPointerSize((error: Error, size: number) => {
    console.log(`getPointerSize success, size: ${JSON.stringify(size)}`);
  });
} catch (error) {
  console.error(`getPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerSize<sup>10+</sup>

getPointerSize(): Promise&lt;number&gt;

Obtains the pointer size. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |


**Example**

```js
try {
  pointer.getPointerSize().then((size: number) => {
    console.log(`getPointerSize success, size: ${JSON.stringify(size)}`);
  });
} catch (error) {
  console.error(`getPointerSize failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerSizeSync<sup>10+</sup>

getPointerSizeSync(): number

Obtains the pointer size. This API returns the result synchronously.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| number | Pointer size. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |


**Example**

```js
try {
  let pointerSize = pointer.getPointerSizeSync();
  console.log(`getPointerSizeSync success, pointerSize: ${JSON.stringify(pointerSize)}`);
} catch (error) {
  console.error(`getPointerSizeSync failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerColor<sup>10+</sup>

setPointerColor(color: number, callback: AsyncCallback&lt;void&gt;): void

Sets the pointer color. This API uses an asynchronous callback to return the result.

**NOTE**
>
> When performing this operation, you need to connect an external device, such as a mouse or Bluetooth device.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| color     | number                    | Yes   | Pointer color. The default value is **black** (0x000000).  |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setPointerColor(0xF6C800, (error: Error) => {
    if (error) {
      console.error(`setPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setPointerColor success`);
  });
} catch (error) {
  console.error(`setPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerColor<sup>10+</sup>

setPointerColor(color: number): Promise&lt;void&gt;

Sets the pointer color. This API uses a promise to return the result.

**NOTE**
>
> When performing this operation, you need to connect an external device, such as a mouse or Bluetooth device.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| color  | number | Yes   | Pointer color. The default value is **black** (0x000000).|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setPointerColor(0xF6C800).then(() => {
    console.log(`setPointerColor success`);
  });
} catch (error) {
  console.error(`setPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setPointerColorSync<sup>10+</sup>

setPointerColorSync(color: number): void

Sets the pointer color. This API returns the result synchronously.

**NOTE**
>
> When performing this operation, you need to connect an external device, such as a mouse or Bluetooth device.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| color  | number | Yes   | Pointer color. The default value is **black** (0x000000).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setPointerColorSync(0xF6C800);
  console.log(`setPointerColorSync success`);
} catch (error) {
  console.error(`setPointerColorSync failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerColor<sup>10+</sup>

getPointerColor(callback: AsyncCallback&lt;number&gt;): void

Obtains the pointer color. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getPointerColor((error: Error, color: number) => {
    console.log(`getPointerColor success, color: ${JSON.stringify(color)}`);
  });
} catch (error) {
  console.error(`getPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerColor<sup>10+</sup>

getPointerColor(): Promise&lt;number&gt;

Obtains the pointer color. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |


**Example**

```js
try {
  pointer.getPointerColor().then((color: number) => {
    console.log(`getPointerColor success, color: ${JSON.stringify(color)}`);
  });
} catch (error) {
  console.error(`getPointerColor failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getPointerColorSync<sup>10+</sup>

getPointerColorSync(): number

Obtains the pointer color. This API returns the result synchronously.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| number | Pointer color.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |


**Example**

```js
try {
  let pointerColor = pointer.getPointerColorSync();
  console.log(`getPointerColorSync success, pointerColor: ${JSON.stringify(pointerColor)}`);
} catch (error) {
  console.error(`getPointerColorSync failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadDoubleTapAndDragState<sup>14+</sup>

setTouchpadDoubleTapAndDragState(isOpen: boolean, callback: AsyncCallback\<void>): void

Sets the double-tap and drag switch for the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                       | Mandatory  | Description                                   |
| -------- | ------------------------- | ---- | ------------------------------------- |
| isOpen | boolean | Yes   | Status of the double-tap and drag switch. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite.|
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadDoubleTapAndDragState(true, (error: Error) => {
    if (error) {
      console.error(`setTouchpadDoubleTapAndDragState failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
      return;
    }
    console.log(`setTouchpadDoubleTapAndDragState success`);
  });
} catch (error) {
  console.error(`setTouchpadDoubleTapAndDragState failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.setTouchpadDoubleTapAndDragState<sup>14+</sup>

setTouchpadDoubleTapAndDragState(isOpen: boolean): Promise\<void>

Sets the double-tap and drag switch for the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                 |
| ----- | ------ | ---- | ----------------------------------- |
| state | boolean| Yes   |  Status of the double-tap and drag switch. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite.|

**Return value**

| Name                 | Description              |
| ------------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.setTouchpadDoubleTapAndDragState(false).then(() => {
    console.log(`setTouchpadDoubleTapAndDragState success`);
  });
} catch (error) {
  console.error(`setTouchpadDoubleTapAndDragState failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadDoubleTapAndDragState<sup>14+</sup>

getTouchpadDoubleTapAndDragState(callback: AsyncCallback\<boolean>): void

Obtains the status of the double-tap and drag switch for the touchpad. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Parameters**

| Name      | Type                         | Mandatory  | Description            |
| -------- | --------------------------- | ---- | -------------- |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the status of the double-tap drag switch. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
try {
  pointer.getTouchpadDoubleTapAndDragState((error: Error, state: boolean) => {
    console.log(`getTouchpadDoubleTapAndDragState success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadDoubleTapAndDragState failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## pointer.getTouchpadDoubleTapAndDragState<sup>14+</sup>

getTouchpadDoubleTapAndDragState(): Promise\<boolean>

Obtains the status of the double-tap and drag switch for the touchpad. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

**System API**: This is a system API.

**Return value**

| Name                   | Description                 |
| --------------------- | ------------------- |
| Promise\<boolean> | Promise used to return the status of the touchpad double-tap drag switch. The value **true** indicates that the switch is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |

**Example**

```js
try {
  pointer.getTouchpadDoubleTapAndDragState().then((state) => {
    console.log(`getTouchpadDoubleTapAndDragState success, state: ${JSON.stringify(state)}`);
  });
} catch (error) {
  console.error(`getTouchpadDoubleTapAndDragState failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```
