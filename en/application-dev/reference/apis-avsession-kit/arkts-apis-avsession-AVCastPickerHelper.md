# Class (AVCastPickerHelper)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--SE: @ccfriend-->
<!--TSE: @chenmingxi1_huawei-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this class are supported since API version 14.

AVCastPickerHelper implements a semi-modal object used for casting. It displays a semi-modal window for users to select a target cast device. Before using the APIs of this class, you need to create an AVCastPickerHelper instance.

## Modules to Import

```ts
import { avSession } from '@kit.AVSessionKit';
```

## constructor<sup>14+</sup>

constructor(context: Context)

Creates an AVCastPickerHelper instance. For details about how to obtain the context, see [getContext](../apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12).

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name   | Type                                                       | Mandatory| Description                                                        |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context | Yes  | Application context. (Only [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) is supported.)|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(40)
          .fontWeight(FontWeight.Bold)
          .onClick(()=>{
            let context = this.getUIContext().getHostContext() as Context;
            let avCastPicker = new avSession.AVCastPickerHelper(context);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## select<sup>14+</sup>

select(options?: AVCastPickerOptions): Promise\<void>

Starts the AVCastPicker dialog box, where users can select the target cast device. This API uses a promise to return the result. You can pass in **AVCastPickerOptions** to specify the properties for selection.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name   | Type                                                       | Mandatory| Description                                                        |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [AVCastPickerOptions](arkts-apis-avsession-i.md#avcastpickeroptions14) | No  | AVCastPicker selection options. If this parameter is not specified, the default value of **AVCastPickerOptions** is used.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function avCastPicker(context: common.Context) {
  let avCastPickerOptions : avSession.AVCastPickerOptions = {
    sessionType : 'video',
  }
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.select(avCastPickerOptions).then(() => {
    console.info('select successfully');
  }).catch((err: BusinessError) => {
    console.error(`AVCastPicker.select failed with err: ${err.code}, ${err.message}`);
  });
}
```

## on('pickerStateChange')<sup>14+</sup>

on(type: 'pickerStateChange', callback: Callback<AVCastPickerState\>) : void

Subscribes to semi-modal window change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type      | Mandatory| Description     |
| --------| -----------|-----|------------|
| type     | string    | Yes  | Event type. The event **'pickerStateChange'** is triggered when the semi-modal window changes.|
| callback | Callback\<[AVCastPickerState](js-apis-avCastPickerParam.md#avcastpickerstate11)>       | Yes  | Callback function, where the **state** parameter indicates the new state of the semi-modal window.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { AVCastPickerState } from '@kit.AVSessionKit';

async function onPickerStateChange(context: common.Context) {
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.on('pickerStateChange', (state: AVCastPickerState) => {
    console.info(`picker state change : ${state}`);
  });
}
```

## off('pickerStateChange')<sup>14+</sup>

off(type: 'pickerStateChange', callback?: Callback<AVCastPickerState\>) : void

Unsubscribes from semi-modal window change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                                              | Mandatory| Description                                                   |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | Yes  | Event type, which is **'pickerStateChange'** in this case.        |
| callback | Callback\<[AVCastPickerState](js-apis-avCastPickerParam.md#avcastpickerstate11)> | No  | Callback function, where the **state** parameter indicates the new state of the semi-modal window.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                          |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**Example**

```ts
import { common } from '@kit.AbilityKit';

async function onPickerStateChange(context: common.Context) {
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.off('pickerStateChange');
}
```
