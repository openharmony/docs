# @ohos.inputMethod (输入法框架)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

本模块主要面向普通前台应用（备忘录、信息、设置等系统应用与三方应用），提供对输入法（输入法应用）的控制、管理能力，包括显示/隐藏输入法软键盘、切换输入法、获取所有输入法列表等等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { inputMethod } from '@kit.IMEKit';
```

## 常量

常量值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 参数名 | 类型 | 常量值 | 说明 |
| -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM<sup>8+</sup> | number | 128 | 可支持的最大输入法个数。 |

## InputMethodProperty<sup>8+</sup>

输入法应用属性。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| name<sup>9+</sup>  | string | 是 | 否 | 必填。输入法包名。|
| id<sup>9+</sup>    | string | 是 | 否 | 必填。输入法扩展在应用内唯一标识，与name一起组成输入法扩展的全局唯一标识。|
| label<sup>9+</sup>    | string | 是 | 是 | 非必填。<br>- 当InputMethodProperty用于切换、查询等接口的入参时，开发者可不填写此字段，通过name和id即可唯一指定一个输入法扩展。<br>- 当InputMethodProperty作为查询接口的返回值时（如[getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)），此字段表示输入法扩展对外显示的名称，优先使用InputMethodExtensionAbility中配置的label，若未配置，自动使用应用入口ability的label；当应用入口ability未配置label时，自动使用应用AppScope中配置的label。|
| labelId<sup>10+</sup>    | number | 是 | 是 | 非必填。<br>- 当InputMethodProperty用于切换、查询等接口的入参时，开发者可不填写此字段，通过name和id即可唯一指定一个输入法扩展。<br>- 当InputMethodProperty作为查询接口的返回值时（如[getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)），此字段表示label字段的资源号。|
| icon<sup>9+</sup>    | string | 是 | 是 | 非必填。<br>- 当InputMethodProperty用于切换、查询等接口的入参时，开发者可不填写此字段，通过name和id即可唯一指定一个输入法扩展。<br>- 当InputMethodProperty作为查询接口的返回值时（如[getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)），此字段表示输入法图标数据，可以通过iconId查询获取。|
| iconId<sup>9+</sup>    | number | 是 | 是 | 非必填。<br>- 当InputMethodProperty用于切换、查询等接口的入参时，开发者可不填写此字段，通过name和id即可唯一指定一个输入法扩展。<br>- 当InputMethodProperty作为查询接口的返回值时（如[getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)），此字段表示icon字段的资源号。|
| enabledState<sup>20+</sup>    | [EnabledState](js-apis-inputmethod.md#enabledstate15) | 是 | 是 | 非必填。<br>- 当InputMethodProperty用于切换、查询等接口的入参时，开发者可不填写此字段，通过name和id即可唯一指定一个输入法扩展<br>- 当InputMethodProperty作为查询接口的返回值时（如[getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)），此字段表示该输入法启用状态。|
| extra<sup>9+</sup>    | object | 否 | 是 | 输入法扩展信息。预留字段，当前无具体含义，暂不支持使用。<br/>- API version 10起：非必填；<br/>- API version 9：必填。|
| packageName<sup>(deprecated)</sup> | string | 是 | 否 | 输入法包名。必填。<br/>说明：从API version 8开始支持，从API version 9开始废弃，建议使用name替代。 |
| methodId<sup>(deprecated)</sup> | string | 是 | 否 | 输入法唯一标识。必填。<br/>说明：从API version 8开始支持，从API version 9开始废弃，建议使用id替代。 |

## CapitalizeMode<sup>20+</sup>

枚举，定义了文本首字母大写的不同模式。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 | 说明 |
| -------- | -- | -------- |
| NONE | 0 | 不进行任何首字母大写处理。|
| SENTENCES | 1 | 每个句子的首字母大写。|
| WORDS | 2 | 每个单词首字母大写。|
| CHARACTERS | 3 | 每个字母都大写。|

## inputMethod.getController<sup>9+</sup>

getController(): InputMethodController

获取客户端实例[InputMethodController](#inputmethodcontroller)。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                            | 说明                   |
| ----------------------------------------------- | ---------------------- |
| [InputMethodController](#inputmethodcontroller) | 返回当前客户端实例。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**示例：**

```ts
let inputMethodController = inputMethod.getController();
```

## inputMethod.getDefaultInputMethod<sup>11+</sup>

getDefaultInputMethod(): InputMethodProperty

获取默认输入法。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](#inputmethodproperty8) | 返回默认输入法属性对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
try {
  let defaultIme = inputMethod.getDefaultInputMethod();
} catch(err) {
  console.error(`Failed to getDefaultInputMethod: ${JSON.stringify(err)}`);
}
```

## inputMethod.getSystemInputMethodConfigAbility<sup>11+</sup>

getSystemInputMethodConfigAbility(): ElementName

获取系统输入法设置界面Ability信息。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md) | 系统输入法设置界面Ability的ElementName。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
try {
  let inputMethodConfig = inputMethod.getSystemInputMethodConfigAbility();
} catch(err) {
  console.error(`Failed to get getSystemInputMethodConfigAbility: ${JSON.stringify(err)}`);
}
```

## inputMethod.getSetting<sup>9+</sup>

getSetting(): InputMethodSetting

获取客户端设置实例[InputMethodSetting](#inputmethodsetting8)。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明                       |
| ----------------------------------------- | -------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | 返回当前客户端设置实例。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800007 |  input method setter error. Possible cause: create InputMethodSetting object failed. |

**示例：**

```ts
let inputMethodSetting = inputMethod.getSetting();
```

## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty, callback: AsyncCallback&lt;boolean&gt;): void

切换输入法，使用callback异步回调。
> **说明：**
>
>  - 在API version 9-10版本，仅支持系统应用调用且需要权限ohos.permission.CONNECT_IME_ABILITY。
>  - 在API version 11版本起，仅支持当前输入法应用调用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | [InputMethodProperty](#inputmethodproperty8) | 是 | 目标输入法。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法切换成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
try{
  inputMethod.switchInputMethod(currentIme, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in switching input method.');
    } else {
      console.error('Failed to switch input method.');
    }
  });
} catch(err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
}
```

> **说明：**
>
> 在 api11 中 ` 201 permissions check fails.` 这个错误码被移除。

## inputMethod.switchInputMethod<sup>9+</sup>
switchInputMethod(target: InputMethodProperty): Promise&lt;boolean&gt;

切换输入法，使用promise异步回调。
> **说明：**
>
>  - 在API version 9-10版本，仅支持系统应用调用且需要权限ohos.permission.CONNECT_IME_ABILITY。
>  - 在API version 11版本起，仅支持当前输入法应用调用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  |target |  [InputMethodProperty](#inputmethodproperty8)| 是 | 目标输入法。 |

**返回值：**

  | 类型                                      | 说明                         |
  | ----------------------------------------- | ---------------------------- |
  | Promise\<boolean> | Promise对象。返回true表示切换输入法成功，返回false表示切换输入法失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
try {
  inputMethod.switchInputMethod(currentIme).then((result: boolean) => {
    if (result) {
      console.info('Succeeded in switching input method.');
    } else {
      console.error('Failed to switch input method.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
  })
} catch (err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
}
```

> **说明：**
>
> 在 api11 中 ` 201 permissions check fails.` 这个错误码被移除。

## inputMethod.getCurrentInputMethod<sup>9+</sup>

getCurrentInputMethod(): InputMethodProperty

使用同步方法获取当前输入法。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](#inputmethodproperty8) | 返回当前输入法属性对象。 |

**示例：**

```ts
let currentIme = inputMethod.getCurrentInputMethod();
```

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

切换当前输入法的子类型。使用callback异步回调。

> **说明：**
>
>  - 在API version 9版本，仅支持系统应用调用且需要权限ohos.permission.CONNECT_IME_ABILITY。
>  - 在API version 10版本，支持系统应用和当前输入法应用调用；需要权限ohos.permission.CONNECT_IME_ABILITY。
>  - 在API version 11版本起，仅支持当前输入法调用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| 是 | 目标输入法子类型。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法子类型切换成功，err为undefined，data为true；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let extra: Record<string, string> = {}
  inputMethod.switchCurrentInputMethodSubtype({
    id: "ServiceExtAbility",
    label: "",
    name: "com.example.kikakeyboard",
    mode: "upper",
    locale: "",
    language: "",
    icon: "",
    iconId: 0,
    extra: extra
  }, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in switching currentInputMethodSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodSubtype');
    }
  });
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

> **说明：**
>
> 在 api11 中 ` 201 permissions check fails.` 这个错误码被移除。

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise&lt;boolean&gt;

切换当前输入法的子类型。使用promise异步回调。

> **说明：**
>
>  - 在API version 9版本，仅支持系统应用调用且需要权限ohos.permission.CONNECT_IME_ABILITY。
>  - 在API version 10版本，支持系统应用和当前输入法应用调用；需要权限ohos.permission.CONNECT_IME_ABILITY。
>  - 在API version 11版本起，仅支持当前输入法调用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| 是 | 目标输入法子类型。 |

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise对象。返回true表示当前输入法切换子类型成功，返回false表示当前输入法切换子类型成功失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let extra: Record<string, string> = {}
  inputMethod.switchCurrentInputMethodSubtype({
    id: "ServiceExtAbility",
    label: "",
    name: "com.example.kikakeyboard",
    mode: "upper",
    locale: "",
    language: "",
    icon: "",
    iconId: 0,
    extra: extra
  }).then((result: boolean) => {
    if (result) {
      console.info('Succeeded in switching currentInputMethodSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodSubtype.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

> **说明：**
>
> 在 api11 中 ` 201 permissions check fails.` 这个错误码被移除。

## inputMethod.getCurrentInputMethodSubtype<sup>9+</sup>

getCurrentInputMethodSubtype(): InputMethodSubtype

获取当前输入法的子类型。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype) | 返回当前输入法子类型对象。 |

**示例：**

```ts
let currentImeSubType = inputMethod.getCurrentInputMethodSubtype();
```

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

切换至指定输入法的指定子类型，适用于跨输入法切换子类型。使用callback异步回调。

> **说明：**
>
>  - 在API version 9-10版本，仅支持系统应用调用且需要权限ohos.permission.CONNECT_IME_ABILITY。
>  - 在API version 11版本起，仅支持当前输入法调用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| 是 | 目标输入法。 |
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| 是 | 目标输入法子类型。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法和子类型切换成功，err为undefined，data为获取到的切换子类型结果true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
let imSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in switching currentInputMethodAndSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodAndSubtype.');
    }
  });
} catch (err) {
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
}
```

> **说明：**
>
> 在 api11 中 ` 201 permissions check fails.` 这个错误码被移除。

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise&lt;boolean&gt;

切换至指定输入法的指定子类型，适用于跨输入法切换子类型。使用promise异步回调。

> **说明：**
>
>  - 在API version 9-10版本，仅支持系统应用调用且需要权限ohos.permission.CONNECT_IME_ABILITY。
>  - 在API version 11版本起，仅支持当前输入法调用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| 是 | 目标输入法。 |
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| 是 | 目标输入法子类型。 |

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise对象。返回true表示切换至指定输入法的指定子类型成功，返回false表示切换至指定输入法的指定子类型失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
let imSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType).then((result: boolean) => {
    if (result) {
      console.info('Succeeded in switching currentInputMethodAndSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodAndSubtype.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
}
```

> **说明：**
>
> 在 api11 中 ` 201 permissions check fails.` 这个错误码被移除。

## inputMethod.getInputMethodController<sup>(deprecated)</sup>

getInputMethodController(): InputMethodController

获取客户端实例[InputMethodController](#inputmethodcontroller)。

> **说明：** 
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getController()](#inputmethodgetcontroller9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                            | 说明                     |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | 回调返回当前客户端实例。 |

**示例：**

```ts
let inputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting<sup>(deprecated)</sup>

getInputMethodSetting(): InputMethodSetting

获取客户端设置实例[InputMethodSetting](#inputmethodsetting8)。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getSetting()](#inputmethodgetsetting9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明                       |
| ----------------------------------------- | -------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | 返回当前客户端设置实例。 |

**示例：**

```ts
let inputMethodSetting = inputMethod.getInputMethodSetting();
```

## inputMethod.setSimpleKeyboardEnabled<sup>20+</sup>

setSimpleKeyboardEnabled(enable: boolean): void

编辑框应用设置简单键盘标志。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| enable | boolean | 是 | 简单键盘是否使能标志，true标识简单键盘使能，false标识简单键盘去使能。<br/> 原生编辑框组件在下一次点击获焦时生效；自绘控件在下一次调用[attach](#attach10)绑定输入法时生效。 |

**示例：**

```ts
  let enable = false;
  inputMethod.setSimpleKeyboardEnabled(enable);
```

## TextInputType<sup>10+</sup>

文本输入类型。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| NONE  | -1 |NONE。 |
| TEXT  | 0 |文本类型。 |
| MULTILINE  | 1 |多行类型。 |
| NUMBER  | 2 |数字类型。 |
| PHONE  | 3 |电话号码类型。 |
| DATETIME  | 4 |日期类型。 |
| EMAIL_ADDRESS  | 5 |邮箱地址类型。 |
| URL  | 6 |链接类型。 |
| VISIBLE_PASSWORD  | 7 |密码类型。 |
| NUMBER_PASSWORD<sup>11+</sup> | 8 |数字密码类型。 |
| SCREEN_LOCK_PASSWORD<sup>20+</sup> | 9 |锁屏密码类型。 |
| USER_NAME<sup>20+</sup> | 10 |用户名类型。 |
| NEW_PASSWORD<sup>20+</sup> | 11 |新密码类型。 |
| NUMBER_DECIMAL<sup>20+</sup> | 12 |带小数点的数字类型。 |
| ONE_TIME_CODE<sup>20+</sup> | 13 |验证码类型。 |

## EnterKeyType<sup>10+</sup>

Enter键的功能类型。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| UNSPECIFIED  | 0 |未指定。 |
| NONE  | 1 |NONE。 |
| GO  | 2 |前往。 |
| SEARCH  | 3 |查找。 |
| SEND  | 4 |发送。 |
| NEXT  | 5 |下一步。 |
| DONE  | 6 |完成。 |
| PREVIOUS  | 7 |上一步。 |
| NEWLINE<sup>12+</sup>  | 8 | 换行。|

## KeyboardStatus<sup>10+</sup>

输入法软键盘状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| NONE  | 0 |NONE。 |
| HIDE  | 1 |隐藏状态。 |
| SHOW  | 2 |显示状态。 |

## Direction<sup>10+</sup>

光标移动方向。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| CURSOR_UP  | 1 |向上。 |
| CURSOR_DOWN  | 2 |向下。 |
| CURSOR_LEFT  | 3 |向左。 |
| CURSOR_RIGHT  | 4 |向右。 |

## ExtendAction<sup>10+</sup>

编辑框中文本的扩展编辑操作类型，如剪切、复制等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| SELECT_ALL  | 0 |全选。 |
| CUT  | 3 |剪切。 |
| COPY  | 4 |复制。 |
| PASTE  | 5 |粘贴。 |

## FunctionKey<sup>10+</sup>

输入法功能键类型。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| enterKeyType<sup>10+</sup>  | [EnterKeyType](#enterkeytype10) | 否 | 否 | 输入法enter键类型。|

## InputAttribute<sup>10+</sup>

编辑框属性，包含文本输入类型和Enter键功能类型。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| textInputType<sup>10+</sup>  | [TextInputType](#textinputtype10) | 否 | 否 | 文本输入类型。|
| enterKeyType<sup>10+</sup>  | [EnterKeyType](#enterkeytype10) | 否 | 否 | Enter键功能类型。|
| placeholder<sup>20+</sup> | string | 否 | 是 | 编辑框设置的占位符信息。 <br/>- 编辑框设置占位符信息时，长度不超过255个字符（如果超出将会自动截断为255个字符），用于提示或引导用户输入临时性文本或符号。（例如：提示输入项为"必填"或"非必填"的输入结果反馈。）<br/>- 编辑框没有设置占位符信息时，默认为空字符串。<br/>- 该字段在调用[attach](#attach10)时提供给输入法应用。|
| abilityName<sup>20+</sup> | string | 否 | 是 | 编辑框设置的ability名称。<br/>- 编辑框设置ability名称时，长度不超过127个字符（如果超出将会自动截断为127个字符）。<br/>- 编辑框未设置ability名称时，默认为空字符串。<br/>- 该字段在调用绑定[attach](#attach10)时提供给输入法应用。|

## TextConfig<sup>10+</sup>

编辑框的配置信息。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| inputAttribute<sup>10+</sup>  | [InputAttribute](#inputattribute10) | 否 | 否 | 编辑框属性。|
| cursorInfo<sup>10+</sup>  | [CursorInfo](#cursorinfo10) | 否 | 是 | 光标信息。|
| selection<sup>10+</sup>  | [Range](#range10) | 否 | 是 | 文本选中的范围。|
| windowId<sup>10+</sup>  | number | 否 | 是 | 编辑框所在的窗口Id。|
| newEditBox<sup>20+</sup> | boolean | 否 | 是 | 表示是否为新编辑框。true表示新编辑框，false表示非新编辑框。 |
| capitalizeMode<sup>20+</sup> | [CapitalizeMode](#capitalizemode20) | 否 | 是 | 编辑框设置大小写模式。如果没有设置或设置非法值，默认不进行任何首字母大写处理。|

## CursorInfo<sup>10+</sup>

光标信息。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| left  | number | 否 | 否 | 光标的left坐标。|
| top  | number | 否 | 否 | 光标的top坐标。|
| width  | number | 否 | 否 | 光标的宽度。|
| height  | number | 否 | 否 | 光标的高度。|

## Range<sup>10+</sup>

文本的选中范围。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| start  | number | 否 | 否 | 选中文本的首字符在编辑框的索引值。|
| end  | number | 否 | 否 | 选中文本的末字符在编辑框的索引值。|

## Movement<sup>10+</sup>

选中文本时，光标移动的方向。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| direction  | [Direction](#direction10) | 否 | 否 | 选中文本时，光标的移动方向。|

## InputWindowInfo<sup>10+</sup>

输入法软键盘的窗口信息。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| name  | string | 否 | 否 | 输入法窗口的名称。|
| left  | number | 否 | 否 | 输入法窗口左上顶点的横坐标，单位为px。|
| top  | number | 否 | 否 | 输入法窗口左上顶点的纵坐标，单位为px。|
| width  | number | 否 | 否 | 输入法窗口的宽度，单位为px。|
| height  | number | 否 | 否 | 输入法窗口的高度，单位为px。|

## EnabledState<sup>15+</sup>

输入法启用状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| DISABLED   | 0 |未启用。 |
| BASIC_MODE  | 1 |基础模式。 |
| FULL_EXPERIENCE_MODE  | 2 |完整体验模式。 |

## RequestKeyboardReason<sup>15+</sup>

请求键盘输入原因。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| NONE   | 0 |表示没有特定的原因触发键盘请求。 |
| MOUSE  | 1 |表示键盘请求是由鼠标操作触发的。 |
| TOUCH  | 2 |表示键盘请求是由触摸操作触发的。 |
| OTHER  | 20 |表示键盘请求是由其他原因触发的。 |

## MessageHandler<sup>15+</sup>

自定义通信对象。

> **说明：**
>
> 开发者可通过注册此对象来接收输入法应用发送的自定义通信数据，接收到自定义通信数据时会触发此对象中[onMessage](#onmessage15)回调函数。
>
> 此对象全局唯一，多次注册仅保留最后一次注册的对象及有效性，并触发上一个已注册对象的[onTerminated](#onterminated15)回调函数。
>
> 若取消注册全局已注册的对象时，会触发被取消对象中[onTerminated](#onterminated15)回调函数。

### onMessage<sup>15+</sup>

onMessage(msgId: string, msgParam?: ArrayBuffer): void

接收输入法应用发送的自定义数据回调函数。

> **说明：**
>
> 当已注册的MessageHandler接收到来自输入法应用发送的自定义通信数据时，会触发该回调函数。
>
> msgId为必选参数，msgParam为可选参数。存在收到仅有msgId自定义数据的可能，需与数据发送方确认自定义数据。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                             |
| -------- | ----------- | ---- | -------------------------------- |
| msgId    | string      | 是   | 接收到的自定义通信数据的标识符。 |
| msgParam | ArrayBuffer | 否   | 接收到的自定义通信数据的消息体。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodController = inputMethod.getController();
try {
    let messageHandler: inputMethod.MessageHandler = {
        onTerminated(): void {
            console.info('OnTerminated.');
        },
        onMessage(msgId: string, msgParam?:ArrayBuffer): void {
            console.info('recv message.');
        }
    }
    inputMethodController.recvMessage(messageHandler);
} catch(err) {
  console.error(`Failed to recvMessage: ${JSON.stringify(err)}`);
}
```

### onTerminated<sup>15+</sup>

onTerminated(): void

监听对象终止回调函数。

> **说明：**
>
> 当应用注册新的MessageHandler对象时，会触发上一个已注册MessageHandler对象的OnTerminated回调函数。
>
> 当应用取消注册时，会触发当前已注册MessageHandler对象的OnTerminated回调函数。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodController = inputMethod.getController();
try {
    let messageHandler: inputMethod.MessageHandler = {
        onTerminated(): void {
            console.info('OnTerminated.');
        },
        onMessage(msgId: string, msgParam?:ArrayBuffer): void {
            console.info('recv message.');
        }
    }
    inputMethodController.recvMessage(messageHandler);
} catch(err) {
  console.error(`Failed to recvMessage: ${JSON.stringify(err)}`);
}
```

## SetPreviewTextCallback<sup>17+</sup>

type SetPreviewTextCallback = (text: string, range: Range) => void

当输入法框架需要显示预览文本时触发的回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 参数名       | 类型          | 必填 | 说明                          |
| ------- | ----------------- | ---- | ----------------------------- |
| text    | string            | 是   | 预览文本内容。                 |
| range   | [Range](#range10) | 是   | 文本的选中范围。 |

## InputMethodController

下列API示例中都需使用[getController](#inputmethodgetcontroller9)获取到InputMethodController实例，再通过实例调用对应方法。

### attach<sup>10+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig, callback: AsyncCallback&lt;void&gt;): void

自绘控件绑定输入法。使用callback异步回调。

> **说明**
>
> 需要先调用此接口，完成自绘控件与输入法的绑定，才能使用以下功能：显示/隐藏键盘、更新光标信息、更改编辑框选中范围、保存配置信息、监听处理由输入法应用发送的信息或命令等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | 是 | 绑定输入法成功后，是否拉起输入法键盘。<br>- true表示拉起。<br>- false表示不拉起。 |
| textConfig | [TextConfig](#textconfig10) | 是 | 编辑框的配置信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当绑定输入法成功后，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };
  inputMethodController.attach(true, textConfig, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to attach: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in attaching the inputMethod.');
  });
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### attach<sup>10+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig): Promise&lt;void&gt;

自绘控件绑定输入法。使用promise异步回调。

> **说明**
>
> 需要先调用此接口，完成自绘控件与输入法的绑定，才能使用以下功能：显示/隐藏键盘、更新光标信息、更改编辑框选中范围、保存配置信息、监听处理由输入法应用发送的信息或命令等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | 是 | 绑定输入法成功后，是否拉起输入法键盘。<br>- true表示拉起。<br>- false表示不拉起。|
| textConfig | [TextConfig](#textconfig10) | 是 | 编辑框的配置信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };
  inputMethodController.attach(true, textConfig).then(() => {
    console.info('Succeeded in attaching inputMethod.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to attach: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### attach<sup>15+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig, requestKeyboardReason: RequestKeyboardReason): Promise&lt;void&gt;

自绘控件绑定输入法。使用promise异步回调。

> **说明：**
>
> 需要先调用此接口，完成自绘控件与输入法的绑定，才能使用以下功能：显示/隐藏键盘、更新光标信息、更改编辑框选中范围、保存配置信息、监听处理由输入法应用发送的信息或命令等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | 是 | 绑定输入法成功后，是否拉起输入法键盘。<br>- true表示拉起。<br>- false表示不拉起。|
| textConfig | [TextConfig](#textconfig10) | 是 | 编辑框的配置信息。 |
| requestKeyboardReason | [RequestKeyboardReason](#requestkeyboardreason15) | 是 | 请求键盘输入原因。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)和[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };

  let requestKeyboardReason: inputMethod.RequestKeyboardReason = inputMethod.RequestKeyboardReason.MOUSE;

  inputMethodController.attach(true, textConfig, requestKeyboardReason).then(() => {
    console.info('Succeeded in attaching inputMethod.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to attach: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### discardTypingText<sup>20+</sup>

discardTypingText(): Promise&lt;void&gt;

编辑框应用发送“清空正在输入的文字”命令到输入法。使用promise异步回调。

> **说明：**
>
> 当编辑框应用与输入法绑定成功后，才可调用该接口实现此功能。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800009 | input method client detached. |
| 12800015 | the other side does not accept the request. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethod } from '@kit.IMEKit';

inputMethod.getController().discardTypingText().then(() => {
  console.info('Succeeded discardTypingText.');
}).catch((err: BusinessError) => {
  console.error(`Failed to discardTypingText errCode:${err.code}, errMsg:${err.message}`);
});
```

### showTextInput<sup>10+</sup>

showTextInput(callback: AsyncCallback&lt;void&gt;): void

进入文本编辑状态。使用callback异步回调。

> **说明**
>
> 编辑框与输入法绑定成功后，可调用该接口拉起软键盘，进入文本编辑状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。若成功进入编辑状态，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.showTextInput((err: BusinessError) => {
  if (err) {
    console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in showing the inputMethod.');
});
```

### showTextInput<sup>10+</sup>

showTextInput(): Promise&lt;void&gt;

进入文本编辑状态。使用promise异步回调。

> **说明**
>
> 编辑框与输入法绑定成功后，可调用该接口拉起软键盘，进入文本编辑状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.showTextInput().then(() => {
  console.info('Succeeded in showing text input.');
}).catch((err: BusinessError) => {
  console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
});
```

### showTextInput<sup>15+</sup>

showTextInput(requestKeyboardReason: RequestKeyboardReason): Promise&lt;void&gt;

进入文本编辑状态。使用promise异步回调。

> **说明：**
>
> 编辑框与输入法绑定成功后，可调用该接口拉起软键盘，进入文本编辑状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| requestKeyboardReason | [RequestKeyboardReason](#requestkeyboardreason15) | 是 | 请求键盘输入原因。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let requestKeyboardReason = inputMethod.RequestKeyboardReason.MOUSE;

inputMethodController.showTextInput(requestKeyboardReason).then(() => {
  console.info('Succeeded in showing text input.');
}).catch((err: BusinessError) => {
  console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
});
```

### hideTextInput<sup>10+</sup>

hideTextInput(callback: AsyncCallback&lt;void&gt;): void

退出文本编辑状态。使用callback异步回调。

> **说明**
>
> 调用接口时，若软键盘处于显示状态，调用接口后软键盘会被隐藏。
>
> 调用该接口不会解除与输入法的绑定，再次调用[showTextInput](#showtextinput10)时，可重新进入文本编辑状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当成功退出编辑状态时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.hideTextInput((err: BusinessError) => {
  if (err) {
    console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in hiding text input.');
});
```

### hideTextInput<sup>10+</sup>

hideTextInput(): Promise&lt;void&gt;

退出文本编辑状态。使用promise异步回调。

> **说明**
>
> 调用接口时，若软键盘处于显示状态，调用接口后软键盘会被隐藏。
>
> 调用该接口不会解除与输入法的绑定，再次调用[showTextInput](#showtextinput10)时，可重新进入文本编辑状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.hideTextInput().then(() => {
  console.info('Succeeded in hiding inputMethod.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);
})
```

### detach<sup>10+</sup>

detach(callback: AsyncCallback&lt;void&gt;): void

自绘控件解除与输入法的绑定。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当解绑定输入法成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.detach((err: BusinessError) => {
  if (err) {
    console.error(`Failed to detach: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in detaching inputMethod.');
});
```

### detach<sup>10+</sup>

detach(): Promise&lt;void&gt;

自绘控件解除与输入法的绑定。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.detach().then(() => {
  console.info('Succeeded in detaching inputMethod.');
}).catch((err: BusinessError) => {
  console.error(`Failed to detach: ${JSON.stringify(err)}`);
});
```

### setCallingWindow<sup>10+</sup>

setCallingWindow(windowId: number, callback: AsyncCallback&lt;void&gt;): void

设置要避让软键盘的窗口。使用callback异步回调。

> **说明**
>
> 将绑定到输入法的应用程序所在的窗口Id传入，此窗口可以避让输入法窗口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 绑定输入法应用的应用程序所在的窗口Id。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当设置成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowId: number = 2000;
  inputMethodController.setCallingWindow(windowId, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in setting callingWindow.');
  });
} catch(err) {
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### setCallingWindow<sup>10+</sup>

setCallingWindow(windowId: number): Promise&lt;void&gt;

设置要避让软键盘的窗口。使用promise异步回调。

> **说明**
>
> 将绑定到输入法的应用程序所在的窗口Id传入，此窗口可以避让输入法窗口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 绑定输入法应用的应用程序所在的窗口Id。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowId: number = 2000;
  inputMethodController.setCallingWindow(windowId).then(() => {
    console.info('Succeeded in setting callingWindow.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### updateCursor<sup>10+</sup>

updateCursor(cursorInfo: CursorInfo, callback: AsyncCallback&lt;void&gt;): void

当编辑框内的光标信息发生变化时，调用该接口使输入法感知到光标变化。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| cursorInfo | [CursorInfo](#cursorinfo10) | 是 | 光标信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当光标信息更新成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let cursorInfo: inputMethod.CursorInfo = { left: 0, top: 0, width: 600, height: 800 };
  inputMethodController.updateCursor(cursorInfo, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in updating cursorInfo.');
  });
} catch(err) {
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
}
```

### updateCursor<sup>10+</sup>

updateCursor(cursorInfo: CursorInfo): Promise&lt;void&gt;

当编辑框内的光标信息发生变化时，调用该接口使输入法感知到光标变化。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| cursorInfo | [CursorInfo](#cursorinfo10) | 是 | 光标信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let cursorInfo: inputMethod.CursorInfo = { left: 0, top: 0, width: 600, height: 800 };
  inputMethodController.updateCursor(cursorInfo).then(() => {
    console.info('Succeeded in updating cursorInfo.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
}
```

### changeSelection<sup>10+</sup>

changeSelection(text: string, start: number, end: number, callback: AsyncCallback&lt;void&gt;): void

当编辑框内被选中的文本信息内容或文本范围发生变化时，可调用该接口更新文本信息，使输入法应用感知到变化。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 整个输入文本。 |
| start | number | 是 | 所选文本的起始位置。 |
| end | number | 是 | 所选文本的结束位置。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当文本信息更新成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodController.changeSelection('text', 0, 5, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in changing selection.');
  });
} catch(err) {
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
}
```

### changeSelection<sup>10+</sup>

changeSelection(text: string, start: number, end: number): Promise&lt;void&gt;

当编辑框内被选中的文本信息内容或文本范围发生变化时，可调用该接口更新文本信息，使输入法应用感知到变化。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 整个输入文本。 |
| start | number | 是 | 所选文本的起始位置。 |
| end | number | 是 | 所选文本的结束位置。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodController.changeSelection('test', 0, 5).then(() => {
    console.info('Succeeded in changing selection.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
}
```

### updateAttribute<sup>10+</sup>

updateAttribute(attribute: InputAttribute, callback: AsyncCallback&lt;void&gt;): void

更新编辑框属性信息。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| attribute | [InputAttribute](#inputattribute10) | 是 | 编辑框属性对象。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当编辑框属性信息更新成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let inputAttribute: inputMethod.InputAttribute = { textInputType: 0, enterKeyType: 1 };
  inputMethodController.updateAttribute(inputAttribute, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in updating attribute.');
  });
} catch(err) {
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
}
```

### updateAttribute<sup>10+</sup>

updateAttribute(attribute: InputAttribute): Promise&lt;void&gt;

更新编辑框属性信息。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| attribute | [InputAttribute](#inputattribute10) | 是 |  编辑框属性对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let inputAttribute: inputMethod.InputAttribute = { textInputType: 0, enterKeyType: 1 };
  inputMethodController.updateAttribute(inputAttribute).then(() => {
    console.info('Succeeded in updating attribute.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
}
```

### stopInputSession<sup>9+</sup>

stopInputSession(callback: AsyncCallback&lt;boolean&gt;): void

结束输入会话。使用callback异步回调。

> **说明：**
>
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用该接口结束输入会话。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当结束输入会话成功时，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodController.stopInputSession((err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in stopping inputSession.');
    } else {
      console.error('Failed to stopInputSession.');
    }
  });
} catch(err) {
  console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
}
```

### stopInputSession<sup>9+</sup>

stopInputSession(): Promise&lt;boolean&gt;

结束输入会话。使用promise异步回调。

> **说明：**
>
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用该接口结束输入会话。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示结束输入会话成功，返回false表示结束输入会话失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodController.stopInputSession().then((result: boolean) => {
    if (result) {
      console.info('Succeeded in stopping inputSession.');
    } else {
      console.error('Failed to stopInputSession.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
}
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

显示输入法软键盘。使用callback异步回调。

> **说明：**
>
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用显示当前输入法的软键盘。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当软键盘显示成功。err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.showSoftKeyboard((err: BusinessError) => {
  if (!err) {
    console.info('Succeeded in showing softKeyboard.');
  } else {
    console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);
  }
})
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(): Promise&lt;void&gt;

显示输入法软键盘。使用Promise异步回调。

> **说明：**
>
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用显示当前输入法的软键盘。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.showSoftKeyboard().then(() => {
  console.info('Succeeded in showing softKeyboard.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);
});
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏输入法软键盘。使用callback异步回调。

> **说明：**
>
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用隐藏当前输入法的软键盘。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当软键盘隐藏成功。err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.hideSoftKeyboard((err: BusinessError) => {
  if (!err) {
    console.info('Succeeded in hiding softKeyboard.');
  } else {
    console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);
  }
})
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(): Promise&lt;void&gt;

隐藏输入法软键盘。使用Promise异步回调。

> **说明：**
>
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用隐藏当前输入法的软键盘。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.hideSoftKeyboard().then(() => {
  console.info('Succeeded in hiding softKeyboard.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);
});
```

### sendMessage<sup>15+</sup>

sendMessage(msgId: string, msgParam?: ArrayBuffer): Promise<void&gt;

发送自定义通信至输入法应用。使用Promise异步回调。

> **说明：**
>
> 该接口需要编辑框与输入法绑定并进入编辑状态，且输入法应用处于完整体验模式时才能调用。
>
> msgId最大限制256B，msgParam最大限制128KB。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                                       |
| -------- | ----------- | ---- | ------------------------------------------ |
| msgId    | string      | 是   | 需要发送至输入法应用的自定义数据的标识符。 |
| msgParam | ArrayBuffer | 否   | 需要发送至输入法应用的自定义数据的消息体。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Incorrect parameter types. 2. Incorrect parameter length.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800009 | input method client detached.               |
| 12800014 | the input method is in basic mode.          |
| 12800015 | the other side does not accept the request. |
| 12800016 | input method client is not editable.        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let msgId: string = "testMsgId";
let msgParam: ArrayBuffer = new ArrayBuffer(128);
inputMethodController.sendMessage(msgId, msgParam).then(() => {
  console.info('Succeeded send message.');
}).catch((err: BusinessError) => {
  console.error(`Failed to send message: ${JSON.stringify(err)}`);
});
```

### recvMessage<sup>15+</sup>

recvMessage(msgHandler?: MessageHandler): void

注册或取消注册MessageHandler。

> **说明：**
>
> [MessageHandler](#messagehandler15)对象全局唯一，多次注册仅保留最后一次注册的对象及有效性，并触发上一个已注册对象的[onTerminated](#onterminated15)回调函数。
>
> 未填写参数，则取消全局已注册的[MessageHandler](#messagehandler15)，并触发被取消注册对象中[onTerminated](#onterminated15)回调函数。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                         |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| msgHandler | [MessageHandler](#messagehandler15) | 否   | 该对象通过[onMessage](#onmessage15)接收来自输入法应用所发送的自定义通信数据，并通过[onTerminated](#onterminated15)接收终止此对象订阅的消息。<br>若不填写此参数，则取消全局已注册的[MessageHandler](#messagehandler15)对象，同时触发其[onTerminated](#onterminated15)回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | parameter error. Possible causes: 1. Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let messageHandler: inputMethod.MessageHandler = {
    onTerminated(): void {
        console.info('OnTerminated.');
    },
    onMessage(msgId: string, msgParam?:ArrayBuffer): void {
        console.info('recv message.');
    }
}
inputMethodController.recvMessage(messageHandler);
inputMethodController.recvMessage();
```

### stopInput<sup>(deprecated)</sup>

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

结束输入会话。使用callback异步回调。

> **说明：** 
> 
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用该接口结束输入会话。
> 
> 从API version 6开始支持，从API version 9开始废弃，建议使用[stopInputSession()](#stopinputsession9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当会话结束成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.stopInput((err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to stopInput: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.info('Succeeded in stopping input.');
  } else {
    console.error('Failed to stopInput.');
  }
});
```

### stopInput<sup>(deprecated)</sup>

stopInput(): Promise&lt;boolean&gt;

结束输入会话。使用promise异步回调。

> **说明：** 
> 
> 该接口需要编辑框与输入法绑定时才能调用，即点击编辑控件后，才可调用该接口结束输入会话。
> 
> 从API version 6开始支持，从API version 9开始废弃，建议使用[stopInputSession()](#stopinputsession9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示会话结束成功；返回false表示会话结束失败。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.stopInput().then((result: boolean) => {
  if (result) {
    console.info('Succeeded in stopping input.');
  } else {
    console.error('Failed to stopInput.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to stopInput: ${JSON.stringify(err)}`);
})
```

### on('insertText')<sup>10+</sup>

on(type: 'insertText', callback: (text: string) => void): void

订阅输入法应用插入文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 设置监听类型，固定取值为'insertText'。 |
| callback | (text: string) => void | 是   | 回调函数，返回需要插入的文本内容。<br/>根据传入的文本，在回调函数中操作编辑框中的内容。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
function callback1(text: string) {
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(text));
}

function callback2(text: string) {
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(text));
}

try {
  inputMethodController.on('insertText', callback1);
  inputMethodController.on('insertText', callback2);
  //仅取消insertText的callback1的回调
  inputMethodController.off('insertText', callback1);
  //取消insertText的所有回调
  inputMethodController.off('insertText');
} catch(err) {
  console.error(`Failed to subscribe insertText: ${JSON.stringify(err)}`);
}
```

### off('insertText')<sup>10+</sup>

off(type: 'insertText', callback?: (text: string) => void): void

取消订阅输入法应用插入文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 设置监听类型，固定取值为'insertText'。 |
| callback | (text: string) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。<br/>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
let onInsertTextCallback = (text: string) => {
    console.info(`Succeeded in subscribing insertText: ${text}`);
};
inputMethodController.off('insertText', onInsertTextCallback);
inputMethodController.off('insertText');
```

### on('deleteLeft')<sup>10+</sup>

on(type: 'deleteLeft', callback: (length: number) => void): void

订阅输入法应用向左删除事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明 |
| -------- | ----- | ---- | ----- |
| type     | string  | 是   | 设置监听类型，固定取值为'deleteLeft'。|
| callback | (length: number) => void | 是   | 回调函数，返回需要向左删除的文本长度。<br/>根据传入的删除长度，在回调函数中操作编辑框中的文本。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('deleteLeft', (length: number) => {
    console.info(`Succeeded in subscribing deleteLeft, length: ${length}`);
  });
} catch(err) {
  console.error(`Failed to subscribe deleteLeft: ${JSON.stringify(err)}`);
}
```

### off('deleteLeft')<sup>10+</sup>

off(type: 'deleteLeft', callback?: (length: number) => void): void

取消订阅输入法应用向左删除文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                   | 是   | 设置监听，固定取值为'deleteLeft'。 |
| callback | (length: number) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
let onDeleteLeftCallback = (length: number) => {
    console.info(`Succeeded in subscribing deleteLeft, length: ${length}`);
};
inputMethodController.off('deleteLeft', onDeleteLeftCallback);
inputMethodController.off('deleteLeft');
```

### on('deleteRight')<sup>10+</sup>

on(type: 'deleteRight', callback: (length: number) => void): void

订阅输入法应用向右删除事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明 |
| -------- | ----- | ---- | ----- |
| type     | string  | 是   | 设置监听类型，固定取值为'deleteRight'。|
| callback | (length: number) => void | 是   | 回调函数，返回需要向右删除的文本长度。<br/>根据传入的删除长度，在回调函数中操作编辑框中的文本。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('deleteRight', (length: number) => {
    console.info(`Succeeded in subscribing deleteRight, length: ${length}`);
  });
} catch(err) {
  console.error(`Failed to subscribe deleteRight: ${JSON.stringify(err)}`);
}
```

### off('deleteRight')<sup>10+</sup>

off(type: 'deleteRight', callback?: (length: number) => void): void

取消订阅输入法应用向右删除文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                   | 是   | 设置监听类型，固定取值为`deleteRight`。 |
| callback | (length: number) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
let onDeleteRightCallback = (length: number) => {
    console.info(`Succeeded in subscribing deleteRight, length: ${length}`);
};
inputMethodController.off('deleteRight', onDeleteRightCallback);
inputMethodController.off('deleteRight');
```

### on('sendKeyboardStatus')<sup>10+</sup>

on(type: 'sendKeyboardStatus', callback: (keyboardStatus: KeyboardStatus) => void): void

订阅输入法应用发送输入法软键盘状态事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明    |
| -------- | ------ | ---- | ---- |
| type     | string  | 是   | 设置监听类型，固定取值为'sendKeyboardStatus'。 |
| callback | (keyboardStatus: [KeyboardStatus](#keyboardstatus10)) => void | 是   | 回调函数，返回软键盘状态。<br/>根据传入的软键盘状态，在回调函数中做相应操作。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('sendKeyboardStatus', (keyboardStatus: inputMethod.KeyboardStatus) => {
    console.info(`Succeeded in subscribing sendKeyboardStatus, keyboardStatus: ${keyboardStatus}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sendKeyboardStatus: ${JSON.stringify(err)}`);
}
```

### off('sendKeyboardStatus')<sup>10+</sup>

off(type: 'sendKeyboardStatus', callback?: (keyboardStatus: KeyboardStatus) => void): void

取消订阅输入法应用发送软键盘状态事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 设置监听类型，固定取值为'sendKeyboardStatus'。 |
| callback | (keyboardStatus: [KeyboardStatus](#keyboardstatus10)) => void | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
let onSendKeyboardStatus = (keyboardStatus: inputMethod.KeyboardStatus) => {
    console.info(`Succeeded in subscribing sendKeyboardStatus, keyboardStatus: ${keyboardStatus}`);
};
inputMethodController.off('sendKeyboardStatus', onSendKeyboardStatus);
inputMethodController.off('sendKeyboardStatus');
```

### on('sendFunctionKey')<sup>10+</sup>

on(type: 'sendFunctionKey', callback: (functionKey: FunctionKey) => void): void

订阅输入法应用发送功能键事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明     |
| -------- | -------- | ---- | ----- |
| type     | string  | 是   | 设置监听类型，固定取值为'sendFunctionKey'。|
| callback | (functionKey: [FunctionKey](#functionkey10)) => void | 是   | 回调函数，返回输入法应用发送的功能键信息。<br/>根据返回的功能键信息，做相应操作。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('sendFunctionKey', (functionKey: inputMethod.FunctionKey) => {
    console.info(`Succeeded in subscribing sendFunctionKey, functionKey.enterKeyType: ${functionKey.enterKeyType}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sendFunctionKey: ${JSON.stringify(err)}`);
}
```

### off('sendFunctionKey')<sup>10+</sup>

off(type: 'sendFunctionKey', callback?: (functionKey: FunctionKey) => void): void

取消订阅输入法应用发送功能键事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                               | 是   | 设置监听类型，固定取值为'sendFunctionKey'。 |
| callback | (functionKey: [FunctionKey](#functionkey10)) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
let onSendFunctionKey = (functionKey: inputMethod.FunctionKey) => {
    console.info(`Succeeded in subscribing sendFunctionKey, functionKey: ${functionKey.enterKeyType}`);
};
inputMethodController.off('sendFunctionKey', onSendFunctionKey);
inputMethodController.off('sendFunctionKey');
```

### on('moveCursor')<sup>10+</sup>

on(type: 'moveCursor', callback: (direction: Direction) => void): void

订阅输入法应用移动光标事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明   |
| -------- | ------ | ---- | ------ |
| type     | string | 是   | 设置监听类型，固定取值为'moveCursor'。 |
| callback | (direction: [Direction](#direction10)) => void | 是   | 回调函数，返回光标信息。<br/>根据返回的光标移动方向，改变光标位置，如光标向上或向下。  |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                           |
| -------- | -------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('moveCursor', (direction: inputMethod.Direction) => {
    console.info(`Succeeded in subscribing moveCursor, direction: ${direction}`);
  });
} catch(err) {
  console.error(`Failed to subscribe moveCursor: ${JSON.stringify(err)}`);
}
```

### off('moveCursor')<sup>10+</sup>

off(type: 'moveCursor', callback?: (direction: Direction) => void): void

取消订阅输入法应用移动光标事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名  | 类型    | 必填 | 说明  |
| ------ | ------ | ---- | ---- |
| type   | string | 是   | 设置监听类型，固定取值为'moveCursor'。 |
| callback | (direction: [Direction<sup>10+</sup>](#direction10)) => void | 否 | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
let onMoveCursorCallback = (direction: inputMethod.Direction) => {
    console.info(`Succeeded in subscribing moveCursor, direction: ${direction}`);
};
inputMethodController.off('moveCursor', onMoveCursorCallback);
inputMethodController.off('moveCursor');
```

### on('handleExtendAction')<sup>10+</sup>

on(type: 'handleExtendAction', callback: (action: ExtendAction) => void): void

订阅输入法应用发送扩展编辑操作事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明   |
| -------- | ------ | ---- | -------- |
| type     | string    | 是   | 设置监听类型，固定取值为'handleExtendAction'。 |
| callback | (action: [ExtendAction](#extendaction10)) => void | 是   | 回调函数，返回扩展编辑操作类型。<br/>根据传入的扩展编辑操作类型，做相应的操作，如剪切、复制等。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('handleExtendAction', (action: inputMethod.ExtendAction) => {
    console.info(`Succeeded in subscribing handleExtendAction, action: ${action}`);
  });
} catch(err) {
  console.error(`Failed to subscribe handleExtendAction: ${JSON.stringify(err)}`);
}
```

### off('handleExtendAction')<sup>10+</sup>

off(type: 'handleExtendAction', callback?: (action: ExtendAction) => void): void

取消订阅输入法应用发送扩展编辑操作事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ------ | ---- | ------- |
| type   | string | 是   | 设置监听类型，固定取值为'handleExtendAction'。 |
| callback | (action: [ExtendAction](#extendaction10)) => void | 否 | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
try {
  let onHandleExtendActionCallback = (action: inputMethod.ExtendAction) => {
    console.info(`Succeeded in subscribing handleExtendAction, action: ${action}`);
  };
  inputMethodController.off('handleExtendAction', onHandleExtendActionCallback);
  inputMethodController.off('handleExtendAction');
} catch(err) {
  console.error(`Failed to subscribe handleExtendAction: ${JSON.stringify(err)}`);
}
```

### on('selectByRange')<sup>10+</sup>

on(type: 'selectByRange', callback: Callback&lt;Range&gt;): void

订阅输入法应用按范围选中文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型     | 必填 | 说明     |
| -------- | ---- | ---- | ------- |
| type     | string  | 是   | 设置监听类型，固定取值为'selectByRange'。 |
| callback | Callback&lt;[Range](#range10)&gt; | 是   | 回调函数，返回需要选中的文本范围。<br/>根据传入的文本范围，开发者在回调函数中编辑框中相应文本。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
try {
  inputMethodController.on('selectByRange', (range: inputMethod.Range) => {
    console.info(`Succeeded in subscribing selectByRange: start: ${range.start} , end: ${range.end}`);
  });
} catch(err) {
  console.error(`Failed to subscribe selectByRange: ${JSON.stringify(err)}`);
}
```

### off('selectByRange')<sup>10+</sup>

off(type: 'selectByRange', callback?:  Callback&lt;Range&gt;): void

取消订阅输入法应用按范围选中文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                            | 是   | 设置监听类型，固定取值为'selectByRange'。 |
| callback | Callback&lt;[Range](#range10)&gt; | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
try {
  let onSelectByRangeCallback = (range: inputMethod.Range) => {
    console.info(`Succeeded in subscribing selectByRange, start: ${range.start} , end: ${range.end}`);
  };
  inputMethodController.off('selectByRange', onSelectByRangeCallback);
  inputMethodController.off('selectByRange');
} catch(err) {
  console.error(`Failed to subscribe selectByRange: ${JSON.stringify(err)}`);
}
```

### on('selectByMovement')<sup>10+</sup>

on(type: 'selectByMovement', callback: Callback&lt;Movement&gt;): void

订阅输入法应用按光标移动方向，选中文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型，固定取值为'selectByMovement'。 |
| callback | Callback&lt;[Movement](#movement10)&gt; | 是   | 回调函数，返回光标移动的方向。<br/>根据传入的光标移动方向，选中编辑框中相应文本。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
try {
  inputMethodController.on('selectByMovement', (movement: inputMethod.Movement) => {
    console.info('Succeeded in subscribing selectByMovement: direction: ' + movement.direction);
  });
} catch(err) {
  console.error(`Failed to subscribe selectByMovement: ${JSON.stringify(err)}`);
}
```

### off('selectByMovement')<sup>10+</sup>

off(type: 'selectByMovement', callback?: Callback&lt;Movement&gt;): void

取消订阅输入法应用按光标移动方向，选中文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                               | 是   | 设置监听类型，固定取值为'selectByMovement'。 |
| callback | Callback&lt;[Movement](#movement10)> | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
try {
  let onSelectByMovementCallback = (movement: inputMethod.Movement) => {
    console.info(`Succeeded in subscribing selectByMovement, movement.direction: ${movement.direction}`);
  };
  inputMethodController.off('selectByMovement', onSelectByMovementCallback);
  inputMethodController.off('selectByMovement');
} catch(err) {
  console.error(`Failed to unsubscribing selectByMovement: ${JSON.stringify(err)}`);
}
```

### on('getLeftTextOfCursor')<sup>10+</sup>

on(type: 'getLeftTextOfCursor', callback: (length: number) => string): void

订阅输入法应用获取光标左侧指定长度文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型，固定取值为'getLeftTextOfCursor'。 |
| callback | (length: number) => string | 是   | 回调函数，获取编辑框最新状态下光标左侧指定长度的文本内容并返回。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('getLeftTextOfCursor', (length: number) => {
    console.info(`Succeeded in subscribing getLeftTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to unsubscribing getLeftTextOfCursor. err: ${JSON.stringify(err)}`);
}
```

### off('getLeftTextOfCursor')<sup>10+</sup>

off(type: 'getLeftTextOfCursor', callback?: (length: number) => string): void

取消订阅输入法应用获取光标左侧指定长度文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 设置监听类型，固定取值为'getLeftTextOfCursor'。 |
| callback | (length: number) => string | 否  | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
try {
  let getLeftTextOfCursorCallback = (length: number) => {
    console.info(`Succeeded in unsubscribing getLeftTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  };
  inputMethodController.off('getLeftTextOfCursor', getLeftTextOfCursorCallback);
  inputMethodController.off('getLeftTextOfCursor');
} catch(err) {
  console.error(`Failed to unsubscribing getLeftTextOfCursor. err: ${JSON.stringify(err)}`);
}
```

### on('getRightTextOfCursor')<sup>10+</sup>

on(type: 'getRightTextOfCursor', callback: (length: number) => string): void

订阅输入法应用获取光标右侧指定长度文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型，固定取值为'getRightTextOfCursor'。 |
| callback | (length: number) => string | 是   | 回调函数，获取编辑框最新状态下光标右侧指定长度的文本内容并返回。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('getRightTextOfCursor', (length: number) => {
    console.info(`Succeeded in subscribing getRightTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to subscribe getRightTextOfCursor. err: ${JSON.stringify(err)}`);
}
```

### off('getRightTextOfCursor')<sup>10+</sup>

off(type: 'getRightTextOfCursor', callback?: (length: number) => string): void

取消订阅输入法应用获取光标右侧指定长度文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 设置监听类型，固定取值为'getRightTextOfCursor'。 |
| callback | (length: number) => string | 否  |取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
try {
  let getRightTextOfCursorCallback = (length: number) => {
    console.info(`Succeeded in unsubscribing getRightTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  };
  inputMethodController.off('getRightTextOfCursor', getRightTextOfCursorCallback);
  inputMethodController.off('getRightTextOfCursor');
} catch(err) {
  console.error(`Failed to unsubscribing getRightTextOfCursor. err: ${JSON.stringify(err)}`);
}
```

### on('getTextIndexAtCursor')<sup>10+</sup>

on(type: 'getTextIndexAtCursor', callback: () => number): void

订阅输入法应用获取光标处文本索引事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型，固定取值为'getTextIndexAtCursor'。 |
| callback | () => number | 是   | 回调函数，获取编辑框最新状态下光标处文本索引并返回。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**示例：**

```ts
try {
  inputMethodController.on('getTextIndexAtCursor', () => {
    console.info(`Succeeded in subscribing getTextIndexAtCursor.`);
    let index:number = 0;
    return index;
  });
} catch(err) {
  console.error(`Failed to subscribe getTextIndexAtCursor. err: ${JSON.stringify(err)}`);
}
```

### off('getTextIndexAtCursor')<sup>10+</sup>

off(type: 'getTextIndexAtCursor', callback?: () => number): void

取消订阅输入法应用获取光标处文本索引事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 设置监听类型，固定取值为'getTextIndexAtCursor'。 |
| callback | () => number | 否  | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
try {
  let getTextIndexAtCursorCallback = () => {
    console.info(`Succeeded in unsubscribing getTextIndexAtCursor.`);
    let index:number = 0;
    return index;
  };
  inputMethodController.off('getTextIndexAtCursor', getTextIndexAtCursorCallback);
  inputMethodController.off('getTextIndexAtCursor');
} catch(err) {
  console.error(`Failed to unsubscribing getTextIndexAtCursor. err: ${JSON.stringify(err)}`);
}
```

### on('setPreviewText')<sup>17+</sup>

on(type: 'setPreviewText', callback: SetPreviewTextCallback): void

订阅输入法应用操作文本预览内容的事件。使用callback异步回调。

> **说明：**
> 
> 使用预览文本功能，需在调用[attach](#attach10)前订阅此事件，并和[on('finishTextPreview')](#onfinishtextpreview17)一起订阅。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型，固定取值为'setPreviewText'。 |
| callback | [SetPreviewTextCallback](#setpreviewtextcallback17) | 是   | 回调函数。用于接收文本预览的内容并返回。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
let setPreviewTextCallback1: inputMethod.SetPreviewTextCallback = (text: string, range: inputMethod.Range) => {
  console.info(`SetPreviewTextCallback1: Received text - ${text}, Received range - start: ${range.start}, end: ${range.end}`);
};

let setPreviewTextCallback2: inputMethod.SetPreviewTextCallback = (text: string, range: inputMethod.Range) => {
  console.info(`setPreviewTextCallback2: Received text - ${text}, Received range - start: ${range.start}, end: ${range.end}`);
};

try {
  inputMethodController.on('setPreviewText', setPreviewTextCallback1);
  console.info(`SetPreviewTextCallback1 subscribed to setPreviewText`);
  inputMethodController.on('setPreviewText', setPreviewTextCallback2);
  console.info(`SetPreviewTextCallback2 subscribed to setPreviewText`);
  // 仅取消setPreviewText的callback1的回调。
  inputMethodController.off('setPreviewText', setPreviewTextCallback1);
  console.info(`SetPreviewTextCallback1 unsubscribed from setPreviewText`);
  // 取消setPreviewText的所有回调。
  inputMethodController.off('setPreviewText');
  console.info(`All callbacks unsubscribed from setPreviewText`);
} catch(err) {
  console.error(`Failed to operate on setPreviewText: ${JSON.stringify(err)}`);
}
```

### off('setPreviewText')<sup>17+</sup>

off(type: 'setPreviewText', callback?: SetPreviewTextCallback): void

取消订阅输入法应用操作文本预览内容的事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 设置监听类型，固定取值为'setPreviewText'。 |
| callback | [SetPreviewTextCallback](#setpreviewtextcallback17) | 否  | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
let setPreviewTextCallback1: inputMethod.SetPreviewTextCallback = (text: string, range: inputMethod.Range) => {
  console.info(`SetPreviewTextCallback1: Received text - ${text}, Received range - start: ${range.start}, end: ${range.end}`);
};

let setPreviewTextCallback2: inputMethod.SetPreviewTextCallback = (text: string, range: inputMethod.Range) => {
  console.info(`setPreviewTextCallback2: Received text - ${text}, Received range - start: ${range.start}, end: ${range.end}`);
};

try {
  inputMethodController.on('setPreviewText', setPreviewTextCallback1);
  console.info(`SetPreviewTextCallback1 subscribed to setPreviewText`);
  inputMethodController.on('setPreviewText', setPreviewTextCallback2);
  console.info(`SetPreviewTextCallback2 subscribed to setPreviewText`);
  // 仅取消setPreviewText的callback1的回调。
  inputMethodController.off('setPreviewText', setPreviewTextCallback1);
  console.info(`SetPreviewTextCallback1 unsubscribed from setPreviewText`);
  // 取消setPreviewText的所有回调。
  inputMethodController.off('setPreviewText');
  console.info(`All callbacks unsubscribed from setPreviewText`);
} catch(err) {
  console.error(`Failed to operate on setPreviewText: ${JSON.stringify(err)}`);
}
```

### on('finishTextPreview')<sup>17+</sup>

on(type: 'finishTextPreview', callback: Callback&lt;void&gt;): void

订阅结束文本预览事件。使用callback异步回调。

> **说明：**
> 
> 使用预览文本功能，需在调用[attach](#attach10)前订阅此事件，并和[on('setPreviewText')](#onsetpreviewtext17)一起订阅。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型，固定取值为'finishTextPreview'。 |
| callback | Callback&lt;void&gt; | 是   | 回调函数。用于处理预览文本结束的逻辑，类型为void。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
let finishTextPreviewCallback1 = () => {
  console.info(`FinishTextPreviewCallback1: finishTextPreview event triggered`);
};
let finishTextPreviewCallback2 = () => {
  console.info(`FinishTextPreviewCallback2: finishTextPreview event triggered`);
};

try {
  inputMethodController.on('finishTextPreview', finishTextPreviewCallback1);
  console.info(`FinishTextPreviewCallback1 subscribed to finishTextPreview`);
  inputMethodController.on('finishTextPreview', finishTextPreviewCallback2);
  console.info(`FinishTextPreviewCallback2 subscribed to finishTextPreview`);
  // 仅取消finishTextPreview的callback1的回调。
  inputMethodController.off('finishTextPreview', finishTextPreviewCallback1);
  console.info(`FinishTextPreviewCallback1 unsubscribed from finishTextPreview`);
  // 取消finishTextPreview的所有回调。
  inputMethodController.off('finishTextPreview');
  console.info(`All callbacks unsubscribed from finishTextPreview`);
} catch(err) {
  console.error(`Failed to operate on finishTextPreview (subscribe/off): ${JSON.stringify(err)}`);
}
```

### off('finishTextPreview')<sup>17+</sup>

off(type: 'finishTextPreview', callback?: Callback&lt;void&gt;): void

取消订阅结束文本预览事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 设置监听类型，固定取值为'finishTextPreview'。 |
| callback | Callback&lt;void&gt; | 否  | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
let finishTextPreviewCallback1 = () => {
  console.info(`FinishTextPreviewCallback1: finishTextPreview event triggered`);
};
let finishTextPreviewCallback2 = () => {
  console.info(`FinishTextPreviewCallback2: finishTextPreview event triggered`);
};

try {
  inputMethodController.on('finishTextPreview', finishTextPreviewCallback1);
  console.info(`FinishTextPreviewCallback1 subscribed to finishTextPreview`);
  inputMethodController.on('finishTextPreview', finishTextPreviewCallback2);
  console.info(`FinishTextPreviewCallback2 subscribed to finishTextPreview`);
  // 仅取消finishTextPreview的callback1的回调。
  inputMethodController.off('finishTextPreview', finishTextPreviewCallback1);
  console.info(`FinishTextPreviewCallback1 unsubscribed from finishTextPreview`);
  // 取消finishTextPreview的所有回调。
  inputMethodController.off('finishTextPreview');
  console.info(`All callbacks unsubscribed from finishTextPreview`);
} catch(err) {
  console.error(`Failed to operate on finishTextPreview (subscribe/off): ${JSON.stringify(err)}`);
}
```

## InputMethodSetting<sup>8+</sup>

下列API均需使用[getSetting](#inputmethodgetsetting9)获取到InputMethodSetting实例后，通过实例调用。

### on('imeChange')<sup>9+</sup>

on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

订阅输入法及子类型变化监听事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型，固定取值为'imeChange'。 |
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | 是 | 回调函数，返回输入法属性对象及子类型对象。 |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
try {
  inputMethodSetting.on('imeChange', (inputMethodProperty: inputMethod.InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => {
    console.info('Succeeded in subscribing imeChange: inputMethodProperty: ' + JSON.stringify(inputMethodProperty) + " , inputMethodSubtype: " + JSON.stringify(inputMethodSubtype));
  });
} catch(err) {
  console.error(`Failed to subscribing imeChange. Code: ${err.code}, Message: ${err.message}`);
}
```

### off('imeChange')<sup>9+</sup>

off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

取消订阅输入法及子类型变化监听事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型    | 必填 | 说明          |
| -------- | --------- | ---- | --------------- |
| type     | string    | 是   | 设置监听类型，固定取值为'imeChange'。 |
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | 否 | 回调函数，返回取消订阅的输入法属性对象及子类型对象。 |

**示例：**

```ts
inputMethodSetting.off('imeChange');
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

获取指定输入法应用的所有子类型。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | [InputMethodProperty](#inputmethodproperty8)| 是 | 输入法应用。 |
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>&gt; | 是 | 回调函数，返回指定输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodProperty: inputMethod.InputMethodProperty = {
  name: 'com.example.kikakeyboard',
  id: 'propertyId',
  packageName: 'com.example.kikakeyboard',
  methodId: 'propertyId',
}
let inputMethodSetting = inputMethod.getSetting();
try {
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty, (err: BusinessError, data: Array<InputMethodSubtype>) => {
    if (err) {
      console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in listing inputMethodSubtype.');
  });
} catch (err) {
  console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise&lt;Array&lt;InputMethodSubtype&gt;&gt;

获取指定输入法应用的所有子类型。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | [InputMethodProperty](#inputmethodproperty8)| 是 | 输入法应用。 |

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise对象，返回指定输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodProperty: inputMethod.InputMethodProperty = {
  name: 'com.example.kikakeyboard',
  id: 'propertyId',
  packageName: 'com.example.kikakeyboard',
  methodId: 'propertyId',
}
let inputMethodSetting = inputMethod.getSetting();
try {
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty).then((data: Array<InputMethodSubtype>) => {
    console.info('Succeeded in listing inputMethodSubtype.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### listCurrentInputMethodSubtype<sup>9+</sup>

listCurrentInputMethodSubtype(callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

查询当前输入法应用的所有子类型。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>&gt; | 是   | 回调函数，返回当前输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodSetting = inputMethod.getSetting();
try {
  inputMethodSetting.listCurrentInputMethodSubtype((err: BusinessError, data: Array<InputMethodSubtype>) => {
    if (err) {
      console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in listing currentInputMethodSubtype.');
  });
} catch(err) {
  console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### listCurrentInputMethodSubtype<sup>9+</sup>

listCurrentInputMethodSubtype(): Promise&lt;Array&lt;InputMethodSubtype&gt;&gt;

查询当前输入法应用的所有子类型。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise对象，返回当前输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodSetting = inputMethod.getSetting();
try {
  inputMethodSetting.listCurrentInputMethodSubtype().then((data: Array<InputMethodSubtype>) => {
    console.info('Succeeded in listing currentInputMethodSubtype.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

获取已激活/未激活的输入法应用列表。使用callback异步回调。

> **说明：**
> 
> 已激活输入法为使能的输入法应用。默认输入法默认使能，其他输入法可被设置为使能或非使能。
> 
> 已激活输入法列表包括默认输入法和已被设置为使能的输入法应用，未激活输入法列表包括除使能输入法以外的其他已安装的输入法。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                          |
| -------- | --------------------------------------------------- | ---- | ----------------------------- |
| enable   | boolean                                             | 是   |true表示返回已激活输入法列表，false表示返回未激活输入法列表。 |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; |  是  | 回调函数，返回已激活/未激活输入法列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800001 | bundle manager error.               |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodSetting.getInputMethods(true, (err: BusinessError, data: Array<inputMethod.InputMethodProperty>) => {
    if (err) {
      console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in getting inputMethods.');
  });
} catch (err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

获取已激活/未激活的输入法应用列表。使用promise异步回调。

> **说明：**
> 
> 已激活输入法为使能的输入法应用。默认输入法默认使能，其他输入法可被设置为使能或非使能。
> 
> 已激活输入法列表包括默认输入法和已被设置为使能的输入法应用，未激活输入法列表包括除使能输入法以外的其他已安装的输入法。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型    | 必填 | 说明                    |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | 是   |- true表示返回已激活输入法列表，false表示返回未激活输入法列表。 |

**返回值：**

| 类型                                                         | 说明                                       |
| ------------------------------------------------------------ | ------------------------------------------ |
| Promise\<Array\<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回已激活/未激活输入法列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800001 | bundle manager error.               |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodSetting.getInputMethods(true).then((data: Array<inputMethod.InputMethodProperty>) => {
    console.info('Succeeded in getting inputMethods.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### getInputMethodsSync<sup>11+</sup>

getInputMethodsSync(enable: boolean): Array&lt;InputMethodProperty&gt;

获取已激活/未激活的输入法应用列表。同步接口。

> **说明：**
>
> 已激活输入法为使能的输入法应用。默认输入法默认使能，其他输入法可被设置为使能或非使能。
>
> 已激活输入法列表包括默认输入法和已被设置为使能的输入法应用，未激活输入法列表包括除使能输入法以外的其他已安装的输入法。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型    | 必填 | 说明                    |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | 是   |- true表示返回已激活输入法列表，false表示返回未激活输入法列表。 |

**返回值：**

| 类型                                                 | 说明                          |
| ---------------------------------------------------- | ----------------------------- |
| Array\<[InputMethodProperty](#inputmethodproperty8)> | 返回已激活/未激活输入法列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
try {
  let imeProperty = inputMethodSetting.getInputMethodsSync(true);
} catch(err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### getAllInputMethods<sup>11+</sup>

getAllInputMethods(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

获取所有输入法应用列表。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | 是   | 回调函数，返回所有输入法列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 12800001 | bundle manager error.               |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodSetting.getAllInputMethods((err: BusinessError, data: Array<inputMethod.InputMethodProperty>) => {
    if (err) {
      console.error(`Failed to getAllInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in getting all inputMethods.');
  });
} catch (err) {
  console.error(`Failed to getAllInputMethods: ${JSON.stringify(err)}`);
}
```

### getAllInputMethods<sup>11+</sup>

getAllInputMethods(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

获取所有输入法应用列表。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<Array\<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回所有输入法列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 12800001 | bundle manager error.              |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.getAllInputMethods().then((data: Array<inputMethod.InputMethodProperty>) => {
  console.info('Succeeded in getting all inputMethods.');
}).catch((err: BusinessError) => {
  console.error(`Failed to getAllInputMethods: ${JSON.stringify(err)}`);
})
```

### getAllInputMethodsSync<sup>11+</sup>

getAllInputMethodsSync(): Array&lt;InputMethodProperty&gt;

获取所有输入法应用列表。同步接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                 | 说明               |
| ---------------------------------------------------- | ------------------ |
| Array\<[InputMethodProperty](#inputmethodproperty8)> | 返回所有输入法列表 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 12800001 | bundle manager error.              |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
try {
  let imeProperty = inputMethodSetting.getAllInputMethodsSync();
} catch(err) {
  console.error(`Failed to getAllInputMethodsSync: ${JSON.stringify(err)}`);
}
```

### showOptionalInputMethods<sup>(deprecated)</sup>

showOptionalInputMethods(callback: AsyncCallback&lt;boolean&gt;): void

显示输入法选择对话框。使用callback异步回调。
> **说明：**
>
> 从API version 9开始支持，从API version 18开始废弃。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法选择对话框显示成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodSetting.showOptionalInputMethods((err: BusinessError, data: boolean) => {
    if (err) {
      console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in showing optionalInputMethods.');
  });
} catch (err) {
  console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
}
```

### showOptionalInputMethods<sup>(deprecated)</sup>

showOptionalInputMethods(): Promise&lt;boolean&gt;

显示输入法选择对话框。使用promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 18开始废弃。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。当输入法选择对话框显示成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.showOptionalInputMethods().then((data: boolean) => {
  console.info('Succeeded in showing optionalInputMethods.');
}).catch((err: BusinessError) => {
  console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
})
```

### listInputMethod<sup>(deprecated)</sup>

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

查询已安装的输入法列表。使用callback异步回调。

> **说明：** 
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getInputMethods](#getinputmethods9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | 是   | 回调函数，返回已安装的输入法列表。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.listInputMethod((err: BusinessError, data: Array<inputMethod.InputMethodProperty>) => {
  if (err) {
    console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in listing inputMethod.');
 });
```

### listInputMethod<sup>(deprecated)</sup>

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

查询已安装的输入法列表。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getInputMethods](#getinputmethods9-1)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回已安装输入法列表。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.listInputMethod().then((data: Array<inputMethod.InputMethodProperty>) => {
  console.info('Succeeded in listing inputMethod.');
}).catch((err: BusinessError) => {
  console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);
})
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

显示输入法选择对话框。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当输入法选择对话框显示成功。err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.displayOptionalInputMethod((err: BusinessError) => {
  if (err) {
    console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in displaying optionalInputMethod.');
});
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(): Promise&lt;void&gt;

显示输入法选择对话框。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.displayOptionalInputMethod().then(() => {
  console.info('Succeeded in displaying optionalInputMethod.');
}).catch((err: BusinessError) => {
  console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);
})
```

### getInputMethodState<sup>15+</sup>

getInputMethodState(): Promise&lt;EnabledState&gt;

查询输入法的启用状态。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                    | 说明                                                         |
| --------------------------------------- | ------------------------------------------------------------ |
| Promise\<[EnabledState](#enabledstate15)> | Promise对象，返回EnabledState.DISABLED表示未启用; 返回EnabledState.BASIC_MODE表示基础模式; 返回EnabledState.FULL_EXPERIENCE_MODE表示完整体验模式。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 12800004 | not an input method application.    |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.getInputMethodState().then((status: inputMethod.EnabledState) => {
  console.info(`Succeeded in getInputMethodState, status: ${status}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to getInputMethodState: ${JSON.stringify(err)}`);
})
```