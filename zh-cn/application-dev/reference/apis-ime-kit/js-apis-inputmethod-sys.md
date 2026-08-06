# @ohos.inputMethod (输入法框架)(系统接口)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

本模块主要面向普通前台应用（备忘录、信息、设置等系统应用），提供对输入法（输入法应用）的控制、管理能力，包括显示/隐藏输入法软键盘、切换输入法、获取所有输入法列表等等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { inputMethod } from '@kit.IMEKit';
```

## inputMethod.switchInputMethod<sup>11+</sup>
switchInputMethod(bundleName: string, subtypeId?: string): Promise&lt;void&gt;

切换输入法，使用promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|bundleName |  string| 是 | 目标输入法包名。 |
|subtypeId |  string| 否 | 输入法子类型。 |

**返回值：**

| 类型           | 说明                     |
| -------------- | ----------------------- |
| Promise&lt;void&gt;  | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 202      | not system application.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';

async function switchInputMethodWithSubtype() {
  // 1. 获取当前输入法
  const currentIme: inputMethod.InputMethodProperty | undefined = inputMethod.getCurrentInputMethod();
  if (!currentIme) {
    console.error("Failed to get current input method");
    return;
  }
  try {
    // 2. 切换输入法
    await inputMethod.switchInputMethod(currentIme.name);
    console.info('Succeeded in switching inputMethod.');
  } catch (err) {
    console.error(`Failed to switchInputMethod. Code: ${err.code}, message: ${err.message}`);
  }
  // 3. 获取当前输入法子类型
  const currentSubtype: InputMethodSubtype | undefined = inputMethod.getCurrentInputMethodSubtype();
  if (!currentSubtype) {
    console.error("Failed to get current input subtype");
    return;
  }
  try {
    // 4. 切换输入法子类型
    await inputMethod.switchInputMethod(currentIme.name, currentSubtype.id);
    console.info('Succeeded in switching inputMethod.');
  } catch (err) {
    console.error(`Failed to switchInputMethod. Code: ${err.code}, message: ${err.message}`);
  }
}

switchInputMethodWithSubtype();
```

## InputMethodSetting<sup>9+</sup>

下列API均需使用[getSetting](./js-apis-inputmethod.md#inputmethodgetsetting9)获取到InputMethodSetting实例后，通过实例调用。

### on('imeShow')<sup>10+</sup>

on(type: 'imeShow', callback: (info: Array\<InputWindowInfo>) => void): void

订阅输入法[Panel](js-apis-inputmethodengine.md#panel10)固定态软键盘显示事件。使用callback异步回调。

配对调用：
- 调用on('imeShow')订阅事件后，必须在使用完毕时调用对应的off('imeShow')取消订阅。
- 取消订阅时可以传入callback参数取消指定回调，或不传参数取消type对应的所有回调。
- 不取消订阅可能导致回调事件持续触发和内存泄漏。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明 |
| -------- | ---- | ---- | ---- |
| type     | string | 是 | 设置监听类型，固定取值为'imeShow'。 |
| callback | (info: Array<[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)>) => void | 是 | 回调函数，返回输入法固定态软键盘信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202      | not system application.  |

**示例：**

```ts
inputMethod.getSetting().on('imeShow', (info: Array<inputMethod.InputWindowInfo>) => {
  console.info('Succeeded in subscribing imeShow event.');
});
```

### on('imeHide')<sup>10+</sup>

on(type: 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void

订阅输入法[Panel](js-apis-inputmethodengine.md#panel10)固定态软键盘隐藏事件。使用callback异步回调。

配对调用：
- 调用on('imeHide')订阅事件后，必须在使用完毕时调用对应的off('imeHide')取消订阅。
- 取消订阅时可以传入callback参数取消指定回调，或不传参数取消type对应的所有回调。
- 不取消订阅可能导致回调事件持续触发和内存泄漏。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明 |
| -------- | ---- | ---- | ---- |
| type     | string | 是 | 设置监听类型，固定取值为'imeHide'。 |
| callback | (info: Array<[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)>) => void | 是 | 回调函数，返回输入法固定态软键盘信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202      | not system application.  |


**示例：**

```ts
inputMethod.getSetting().on('imeHide', (info: Array<inputMethod.InputWindowInfo>) => {
  console.info('Succeeded in subscribing imeHide event.');
});
```

### off('imeShow')<sup>10+</sup>

off(type: 'imeShow', callback?: (info: Array\<InputWindowInfo>) => void): void

取消订阅输入法[Panel](js-apis-inputmethodengine.md#panel10)固定态软键盘显示事件。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明   |
| -------- | ---- | ---- | ------ |
| type     | string | 是 | 设置监听类型，固定取值'imeShow'。 |
| callback | (info: Array<[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)>) => void  | 否 | 取消订阅的回调函数。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
inputMethod.getSetting().off('imeShow');
```

### off('imeHide')<sup>10+</sup>

off(type: 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void

取消订阅输入法[Panel](js-apis-inputmethodengine.md#panel10)固定态软键盘隐藏事件。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明   |
| -------- | ---- | ---- | ------ |
| type     | string | 是 | 设置监听类型，固定取值'imeHide'。 |
| callback | (info: Array<[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)>) => void  | 否 | 取消订阅的回调函数。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
inputMethod.getSetting().off('imeHide');
```

### isPanelShown<sup>11+</sup>

isPanelShown(panelInfo: PanelInfo): boolean

查询指定类型的输入法面板是否处于显示状态。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型                                                  | 必填 | 说明               |
| --------- | ----------------------------------------------------- | ---- | ------------------ |
| panelInfo | [PanelInfo](./js-apis-inputmethod-panel.md#panelinfo) | 是   | 输入法面板的属性。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 面板显隐状态查询结果。<br/>- true表示被查询的输入法面板处于显示状态。<br/>- false表示被查询的输入法面板处于隐藏状态。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | not system application.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { PanelInfo, PanelType, PanelFlag } from '@kit.IMEKit';

let info: PanelInfo = {
  type: PanelType.SOFT_KEYBOARD,
  flag: PanelFlag.FLAG_FIXED
}

try {
  let result: boolean = inputMethod.getSetting().isPanelShown(info);
  console.info('Succeeded in querying isPanelShown, result: ' + result);
} catch (err) {
  console.error(`Failed to query isPanelShown. Code: ${err.code}, message: ${err.message}`);
}
```

### isPanelShown<sup>23+</sup>

isPanelShown(panelInfo: PanelInfo, displayId: number): boolean

查询指定类型的输入法面板在指定屏幕上是否处于显示状态。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型                                                  | 必填 | 说明               |
| --------- | ----------------------------------------------------- | ---- | ------------------ |
| panelInfo | [PanelInfo](./js-apis-inputmethod-panel.md#panelinfo) |  是  | 输入法面板的属性。 |
| displayId | number | 是 | 屏幕ID。|

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 面板显隐状态查询结果。<br/>- true表示被查询的输入法面板处于显示状态。<br/>- false表示被查询的输入法面板处于隐藏状态。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | not system application.  |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { PanelInfo, PanelType, PanelFlag } from '@kit.IMEKit';

let displayId: number = 10;
let info: PanelInfo = {
  type: PanelType.SOFT_KEYBOARD,
  flag: PanelFlag.FLAG_FIXED
}

try {
  let result: boolean = inputMethod.getSetting().isPanelShown(info, displayId);
  console.info('Succeeded in querying isPanelShown, result: ' + result);
} catch (err) {
  console.error(`Failed to query isPanelShown. Code: ${err.code}, message: ${err.message}`);
}
```

### enableInputMethod<sup>20+</sup>

enableInputMethod(bundleName: string, extensionName: string, enabledState: EnabledState): Promise&lt;void&gt;

修改输入法的启用状态。使用promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName |  string | 是 | 输入法包名。 |
  | extensionName |  string | 是 | 输入法扩展名。 |
  | enabledState |  [EnabledState](js-apis-inputmethod.md#enabledstate15) | 是 | 输入法启用状态。设置为BASIC_MODE表示启用基础模式，设置为FULL_EXPERIENCE_MODE表示启用完整体验模式。 |

**返回值：**

  | 类型           | 说明                     |
  | -------------- | ----------------------- |
  | Promise&lt;void&gt;  | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201      | permissions check fails. |
| 202      | not system application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception.  |
| 12800018 | input method is not found. |
| 12800019 | current operation cannot be applied to the preconfigured default input method. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableInputMethodSafely() {
  const currentIme: inputMethod.InputMethodProperty = inputMethod.getCurrentInputMethod();
  if (!currentIme) {
    console.error("Failed to get current input method");
    return;
  }

  inputMethod.getSetting()
    .enableInputMethod(currentIme.name, currentIme.id, inputMethod.EnabledState.BASIC_MODE)
    .then(() => {
      console.info('Succeeded in enable inputmethod.');
    })
    .catch((err) => {
      if (err instanceof BusinessError) {
        console.error(`Failed to enableInputMethod. Code: ${err.code}, message: ${err.message}`);
      } else {
        console.error(`Failed to enableInputMethod. Error: ${err}`);
      }
    });
}

enableInputMethodSafely();
```

### getCursorInfo

getCursorInfo(userId?: number): CursorInfo

获取指定用户的光标信息。当编辑框未给输入法服务通知光标信息时，返回所有属性值都为0。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| userId |  number | 否 | 指定的用户ID。<br>如果调用者不是用户0应用，该值默认为调用者的用户ID。<br> 如果调用者是用户0应用，则该值默认为主屏幕的前台用户ID。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [CursorInfo](js-apis-inputmethod.md#cursorinfo10) | 指定用户下的光标信息。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------- |
| 202      | not system application. |
| 12800003 | input method client error. Possible causes: 1. No edit box is bound to the current input method application under the specified user. |
| 12800008 | input method manager service error. Possible causes: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let cursorInfo: inputMethod.CursorInfo = inputMethod.getSetting().getCursorInfo();
  console.info(`get cursorInfo success, left: ${cursorInfo.left}, top: ${cursorInfo.top}, width: ${cursorInfo.width}, height: ${cursorInfo.height}, displayId: ${cursorInfo.displayId}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get cursorInfo. Code: ${error.code}, message: ${error.message}`);
}
```

### getDefaultInputMethodAbility

getDefaultInputMethodAbility(): InputMethodProperty

获取默认输入法能力。为优化性能，返回的InputMethodProperty对象仅保证能够唯一标识输入法能力的`name`和`id`属性正确，其他属性可能为空。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [InputMethodProperty](js-apis-inputmethod.md#inputmethodproperty8) | 默认输入法属性，仅保证`name`和`id`属性正确，其他属性可能为空。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------- |
| 202      | not system application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const defaultAbility: inputMethod.InputMethodProperty = inputMethod.getSetting().getDefaultInputMethodAbility();
  console.info('Succeeded in getting default input method ability, name: ' + defaultAbility.name + ', id: ' + defaultAbility.id);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to getDefaultInputMethodAbility. Code: ${error.code}, message: ${error.message}`);
}
```

## InputMethodController

下列API示例中都需使用[getController](./js-apis-inputmethod.md#inputmethodgetcontroller9)获取到InputMethodController实例，再通过实例调用对应方法。

### showSoftKeyboard<sup>23+</sup>

showSoftKeyboard(displayId: number): Promise&lt;void&gt;

在指定屏幕上显示输入法软键盘。使用Promise异步回调。

配合使用：
- 此方法与hideSoftKeyboard配合使用，可实现对软键盘的显示和隐藏控制
- 通常在调用showSoftKeyboard显示软键盘后，可在需要时调用hideSoftKeyboard隐藏软键盘
- 需要编辑框与输入法绑定时才能调用

> **说明：**
>
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用显示当前输入法的软键盘。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| displayId | number | 是   | 屏幕ID。|

**返回值：**

| 类型           | 说明                     |
| -------------- | ----------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 202      | not system application.  |
| 12800003 | input method client error. Possible causes: 1. the edit box is not focused. 2. no edit box is bound to current input method application. 3. ipc failed due to the large amount of data transferred or other reasons.|
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayId: number = 20;
inputMethod.getController().showSoftKeyboard(displayId).then(() => {
  console.info('Succeeded in showing softKeyboard.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show softKeyboard, code: ${err.code}, message: ${err.message}`);
});
```

### hideSoftKeyboard<sup>23+</sup>

hideSoftKeyboard(displayId: number): Promise&lt;void&gt;

隐藏指定屏幕上的输入法软键盘。使用Promise异步回调。

> **说明：**
>
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用隐藏当前输入法的软键盘。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| displayId | number | 是   | 屏幕ID。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 202      | not system application.  |
| 12800003 | input method client error. Possible causes: 1. the edit box is not focused. 2. no edit box is bound to current input method application. 3. ipc failed due to the large amount of data transferred or other reasons.|
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayId: number = 30;
inputMethod.getController().hideSoftKeyboard(displayId).then(() => {
  console.info('Succeeded in hiding softKeyboard.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide softKeyboard, code: ${err.code}, message: ${err.message}`);
});
```

## inputMethod.getDefaultInputMethod

getDefaultInputMethod(userId?: number): InputMethodProperty

获取指定用户的默认输入法。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](js-apis-inputmethod.md#inputmethodproperty8) | 返回默认输入法属性对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | not system application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
try {
  let defaultIme: inputMethod.InputMethodProperty = inputMethod.getDefaultInputMethod(100);
  console.info('Succeeded in getting default input method, name: ' + defaultIme.name + ', id: ' + defaultIme.id);
} catch (err) {
  console.error(`Failed to getDefaultInputMethod. Code: ${err.code}, message: ${err.message}`);
}
```

## inputMethod.getSystemInputMethodConfigAbility

getSystemInputMethodConfigAbility(userId?: number): ElementName

获取指定用户的系统输入法设置界面Ability信息。用于启动系统输入法配置界面。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md) | 系统输入法设置界面Ability的ElementName。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | not system application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
import { bundleManager } from '@kit.AbilityKit';

try {
  let inputMethodConfig: bundleManager.ElementName = inputMethod.getSystemInputMethodConfigAbility(100);
  console.info('Succeeded in getting system input method config ability, bundleName: ' + inputMethodConfig.bundleName);
} catch (err) {
  console.error(`Failed to getSystemInputMethodConfigAbility. Code: ${err.code}, message: ${err.message}`);
}
```

## inputMethod.switchInputMethodWithUserId

switchInputMethodWithUserId(bundleName: string, subtypeId?: string, userId?: number): Promise&lt;void&gt;

切换输入法，使用promise异步回调。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.CONNECT_IME_ABILITY

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 目标输入法的包名。 |
| subtypeId | string | 否 | 输入法子类型的ID。如果不设置该参数，则切换到使用默认子类型的目标输入法。 |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| Promise&lt;void&gt;  | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | permissions check fails. |
| 202 | not system application. |
| 12800005 | configuration persistence error. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethod.switchInputMethodWithUserId('com.example.keyboard', 'subtype_001', 100).then(() => {
  console.info('Succeeded in switching input method.');
}).catch((err: BusinessError) => {
  console.error(`Failed to switchInputMethodWithUserId, code: ${err.code}, message: ${err.message}`);
});
```

## inputMethod.getCurrentInputMethod

getCurrentInputMethod(userId?: number): InputMethodProperty

获取指定用户的当前输入法。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](js-apis-inputmethod.md#inputmethodproperty8) | 返回当前输入法属性对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | not system application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
try {
  let currentIme: inputMethod.InputMethodProperty = inputMethod.getCurrentInputMethod(100);
  console.info('Succeeded in getting current input method, name: ' + currentIme.name + ', id: ' + currentIme.id);
} catch (err) {
  console.error(`Failed to getCurrentInputMethod. Code: ${err.code}, message: ${err.message}`);
}
```

## inputMethod.getCurrentInputMethodSubtype

getCurrentInputMethodSubtype(userId?: number): InputMethodSubtype

获取指定用户的当前输入法子类型。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype) | 返回当前输入法子类型对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | not system application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';

try {
  let currentImeSubType: InputMethodSubtype = inputMethod.getCurrentInputMethodSubtype(100);
  console.info('Succeeded in getting current input method subtype, id: ' + currentImeSubType.id);
} catch (err) {
  console.error(`Failed to getCurrentInputMethodSubtype. Code: ${err.code}, message: ${err.message}`);
}
```

### enableInputMethod

enableInputMethod(bundleName: string, extensionName: string, enabledState: EnabledState, userId?: number): Promise&lt;void&gt;

修改指定用户输入法的启用状态。

**起始版本：** 26.0.0

**需要权限：** ohos.permission.CONNECT_IME_ABILITY

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 输入法的包名。 |
| extensionName | string | 是 | 输入法的扩展名。 |
| enabledState | [EnabledState](js-apis-inputmethod.md#enabledstate15) | 是 | 要修改的启用状态。 |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201 | permissions check fails. |
| 202 | not system application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800018 | input method is not found. |
| 12800019 | current operation cannot be applied to the preconfigured default input method. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethod.getSetting().enableInputMethod('com.example.keyboard', 'InputMethodExtAbility', inputMethod.EnabledState.FULL_EXPERIENCE_MODE, 100).then(() => {
  console.info('Succeeded in enabling input method.');
}).catch((err: BusinessError) => {
  console.error(`Failed to enableInputMethod, code: ${err.code}, message: ${err.message}`);
});
```

### getAllInputMethodsSync

getAllInputMethodsSync(userId?: number): Array&lt;InputMethodProperty&gt;

获取指定用户的所有输入法应用列表。同步接口。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型    | 必填 | 说明                    |
| ------ | ------- | ---- | ----------------------- |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型                                                 | 说明               |
| ---------------------------------------------------- | ------------------ |
| Array\<[InputMethodProperty](js-apis-inputmethod.md#inputmethodproperty8)> | 返回所有输入法列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | not system application. |
| 12800001 | bundle manager error. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
try {
  let imeProperty: Array<inputMethod.InputMethodProperty> = inputMethod.getSetting().getAllInputMethodsSync(100);
  console.info('Succeeded in getting all input methods, count: ' + imeProperty.length);
} catch (err) {
  console.error(`Failed to getAllInputMethodsSync. Code: ${err.code}, message: ${err.message}`);
}
```

### getInputMethodSubtypes

getInputMethodSubtypes(bundleName: string, userId?: number): Array&lt;InputMethodSubtype&gt;

获取指定用户指定输入法的子类型列表。同步接口。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 指定输入法的包名。 |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)> | 返回指定输入法的子类型列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | not system application. |
| 12800001 | bundle manager error. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';

let inputMethodSetting: inputMethod.InputMethodSetting = inputMethod.getSetting();
try {
  let subtypes: Array<InputMethodSubtype> = inputMethodSetting.getInputMethodSubtypes('com.example.keyboard', 100);
  console.info('Succeeded in getting input method subtypes, count: ' + subtypes.length);
} catch (err) {
  console.error(`Failed to getInputMethodSubtypes. Code: ${err.code}, message: ${err.message}`);
}
```

### getInputMethodsSync

getInputMethodsSync(enable: boolean, userId?: number): Array&lt;InputMethodProperty&gt;

获取指定用户已激活/未激活的输入法应用列表。同步接口。

> **说明：**
>
> 已激活输入法为使能的输入法应用。默认输入法默认使能，其他输入法可被设置为使能或非使能。
>
> 已激活输入法列表包括默认输入法和已被设置为使能的输入法应用，未激活输入法列表包括除使能输入法以外的其他已安装的输入法。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型    | 必填 | 说明                    |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | 是   |是否激活输入法列表：<br>- true表示返回已激活输入法列表。<br>- false表示返回未激活输入法列表。 |
| userId | number | 否 | 用户ID。取值范围为有效用户的ID。如果不提供：<br>- 如果调用者不是用户0的应用，该值默认为调用者的用户ID。<br>- 如果调用者是用户0的应用，该值默认为主屏幕的前台用户ID。 |

**返回值：**

| 类型                                                 | 说明                          |
| ---------------------------------------------------- | ----------------------------- |
| Array\<[InputMethodProperty](js-apis-inputmethod.md#inputmethodproperty8)> | 返回已激活/未激活输入法列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202 | not system application. |
| 12800001 | bundle manager error. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800023 | the specified user does not exist. |
| 12800024 | the specified user is not in the foreground. |
| 12800025 | cross-user operation denied. Only user 0 applications are authorized for this operation. |

**示例：**

```ts
try {
  let imeProperty: Array<inputMethod.InputMethodProperty> = inputMethod.getSetting().getInputMethodsSync(true, 100);
  console.info('Succeeded in getting enabled input methods, count: ' + imeProperty.length);
} catch (err) {
  console.error(`Failed to getInputMethodsSync. Code: ${err.code}, message: ${err.message}`);
}
```

## ImeChangeWithUserIdCallback

type ImeChangeWithUserIdCallback = (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, userId: number) => void

输入法变更事件回调，携带发生输入法变更的用户ID。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名                    | 类型                                                         | 必填 | 说明             |
| ------------------------- | ------------------------------------------------------------ | ---- | ---------------- |
| inputMethodProperty | [InputMethodProperty](js-apis-inputmethod.md#inputmethodproperty8) | 是   | 当前输入法的属性。 |
| inputMethodSubtype | [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype) | 是   | 当前输入法的子类型。 |
| userId | number | 是 | 输入法发生变化的用户ID。 |

### onImeChangeWithUserId

onImeChangeWithUserId(callback: ImeChangeWithUserIdCallback): void

订阅输入法及子类型变化监听事件，携带发生输入法变更的用户ID。使用callback异步回调。

配对调用：
- 调用onImeChangeWithUserId订阅事件后，必须在使用完毕时调用offImeChangeWithUserId取消订阅。
- 取消订阅时可以传入callback参数取消指定回调，或不传参数取消所有监听事件。
- 不取消订阅可能导致回调事件持续触发和内存泄漏。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| callback | [ImeChangeWithUserIdCallback](#imechangewithuseridcallback)  | 是 | 回调函数，返回输入法属性对象、子类型对象及用户ID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202      | not system application.  |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';

inputMethod.getSetting()
  .onImeChangeWithUserId((inputMethodProperty: inputMethod.InputMethodProperty, inputMethodSubtype: InputMethodSubtype, userId: number) => {
    console.info(`Succeeded in subscribing imeChange: inputMethodProperty.name: ${inputMethodProperty.name}, inputMethodSubtype.id: ${inputMethodSubtype.id}, userId: ${userId}`);
  });
```

### offImeChangeWithUserId

offImeChangeWithUserId(callback?: ImeChangeWithUserIdCallback): void

取消订阅输入法及子类型变化监听事件，携带发生输入法变更的用户ID。使用callback异步回调。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| callback | [ImeChangeWithUserIdCallback](#imechangewithuseridcallback)  | 否 | 回调函数，返回取消订阅的输入法属性对象、子类型对象及用户ID。<br>参数不填写时，取消订阅所有的回调事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 202      | not system application.  |

**示例：**

```ts
inputMethod.getSetting().offImeChangeWithUserId();
```

## InputWindowInfo

输入法软键盘的窗口信息（系统接口扩展属性）。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

关于输入法软键盘窗口信息的更多属性，请参见[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| userId | number | 否 | 是 | 显示输入法窗口的用户ID。<br>该属性仅系统应用可以使用。|