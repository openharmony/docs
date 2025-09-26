#  @ohos.multimodalInput.shortKey (Preset Global Shortcut Keys) (System API)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

The **shortKey** module provides APIs to set the delay for starting an ability using a shortcut key. For example, you can set the delay to 3 seconds so that a screenshot is taken when you press and hold the shortcut key for 3 seconds.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.


##  Modules to Import

```js
import { shortKey } from '@kit.InputKit';
```

##  shortKey.setKeyDownDuration

setKeyDownDuration(businessKey: string, delay: number, callback: AsyncCallback&lt;void&gt;): void

Sets the delay for starting an ability using shortcut keys. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.ShortKey

**Parameters**

| Name    | Type               | Mandatory| Description                                                        |
| ---------- | ------------------- | ---- | ------------------------------------------------------------ |
| businessKey| string              | Yes  | Unique service ID registered on the multimodal side. It corresponds to **businessId** in the **ability_launch_config.json** file. You need to query this parameter on your own before calling the API.|
| delay      | number              | Yes  | Delay for starting an ability using shortcut keys, in milliseconds. This field is invalid only when shortcut keys are used.|
| callback   | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { shortKey } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            shortKey.setKeyDownDuration("businessId", 500, (error) => {
              if (error) {
                console.error(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
                return;
              }
              console.info(`Set key down duration success`);
            });
          } catch (error) {
            console.error(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## shortKey.setKeyDownDuration

setKeyDownDuration(businessKey: string, delay: number): Promise&lt;void&gt;

Sets the delay for starting an ability using shortcut keys. This API uses a promise to return the result.

**System capability**: SystemCapability.MultimodalInput.Input.ShortKey

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| businessKey| string | Yes  | Unique service ID registered on the multimodal side. It corresponds to **businessId** in the **ability_launch_config.json** file. You need to query this parameter on your own before calling the API.|
| delay      | number | Yes  | Delay for starting an ability using shortcut keys, in milliseconds. This field is invalid only when shortcut keys are used.|

**Return value**

| Type         | Description         |
| ------------- | ------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | SystemAPI permission error.  |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { shortKey } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            shortKey.setKeyDownDuration("businessId", 500).then(() => {
              console.info(`Set key down duration success`);
            });
          } catch (error) {
            console.error(`Set key down duration failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## FingerprintAction<sup>12+</sup>

Enumerates key event types.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name                | Value         | Description               |
| ---------------------| ---------- | --------------------|
| DOWN                 | 0 | Pressing down          |
| UP                   | 1 | Lifting up          |
| SLIDE                | 2 | Sliding          |
| RETOUCH              | 3 | Retouching          |
| CLICK                | 4 | Clicking          |

## FingerprintEvent<sup>12+</sup>

Defines the key event type and the offset position relative to the key.

**System capability**: SystemCapability.MultimodalInput.Input.Core

| Name     | Type                                      |Read Only  | Optional |Description                   |
| --------  | ------------------------                  |-------|------ |--------               |
| action    | [FingerprintAction](#fingerprintaction12)   | No   |  No  |Enumerates key event types.          |
| distanceX | number                                    | No   |  No  |Offset position on the X axis. A positive number indicates that the pointer moves rightward, and a negative number indicates that the cursor moves leftward.|
| distanceY | number                                    | No   |  No  |Offset position on the Y axis. A positive number indicates that the pointer moves upward, and a negative number indicates that the cursor moves downward.|
