# 输入法框架

本模块提供对输入法框架的管理，包括隐藏输入法、查询已安装的输入法列表和显示输入法选择对话框。

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import inputMethod from '@ohos.inputmethod';
```

## 常量<sup>8+</sup>

常量值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 参数名 | 类型 | 常量值 | 说明 |
| -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM | number | 128 | 可支持的最大输入法个数。 |

## InputMethodProperty<sup>8+</sup>

输入法应用属性。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| name<sup>9+</sup>  | string | 是 | 否 | 输入法内部名称。必填。|
| id<sup>9+</sup>    | string | 是 | 否 | 输入法唯一标识。必填。|
| label<sup>9+</sup>    | string | 是 | 否 | 输入法对外显示名称。 非必填。|
| icon<sup>9+</sup>    | string | 是 | 否 | 输入法图标数据。非必填。 |
| iconId<sup>9+</sup>    | number | 是 | 否 | 输入法图标资源号。非必填。 |
| extra<sup>9+</sup>    | object | 是 | 是 | 输入法扩展信息。 必填。|
| packageName<sup>(deprecated)</sup> | string | 是 | 否 | 输入法包名。必填。<br/>**说明：** 从API version 8开始支持，从API version 9开始废弃，建议使用name替代。 |
| methodId<sup>(deprecated)</sup> | string | 是 | 否 | 输入法唯一标识。必填。<br/>**说明：** 从API version 8开始支持，从API version 9开始废弃，建议使用id替代。 |

## inputMethod.getController<sup>9+</sup>

getController(): InputMethodController

获取客户端实例[InputMethodController](#inputmethodcontroller)。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                            | 说明                     |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | 回调返回当前客户端实例。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 12800006 | Input method controller error. |

**示例：**

```js
let inputMethodController = inputMethod.getController();
```

## inputMethod.getSetting<sup>9+</sup>

getSetting(): InputMethodSetting

获取客户端设置实例[InputMethodSetting](#inputmethodsetting8)。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | 回调返回当前客户端设置实例。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800007 | Input method settings extension error. |

**示例：**

```js
let inputMethodSetting = inputMethod.getSetting();
```

## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty, callback: AsyncCallback&lt;boolean&gt;): void

切换输入法。使用callback异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | [InputMethodProperty](#inputmethodproperty8) | 是 | 传入要切换的目标输入法。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法切换成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**示例：**

```js
let im = inputMethod.getCurrentInputMethod();
let prop = {
    packageName: im.packageName,
    methodId: im.methodId,
    name: im.packageName,
    id: im.methodId,
    extra: {}
}
try{
    inputMethod.switchInputMethod(prop, (err, result) => {
        if (err !== undefined) {
            console.error('Failed to switchInputMethod: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in switching inputmethod.');
        } else {
            console.error('Failed to switchInputMethod.');
        }
    });
} catch(err) {
    console.error('Failed to switchInputMethod: ' + JSON.stringify(err));
}
```
## inputMethod.switchInputMethod<sup>9+</sup>
switchInputMethod(target: InputMethodProperty): Promise&lt;boolean&gt;

切换输入法。使用promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  |target |  [InputMethodProperty](#inputmethodproperty8)| 是 | 传入要切换的目标输入法。 |

**返回值：**

  | 类型                                      | 说明                         |
  | ----------------------------------------- | ---------------------------- |
  | Promise\<boolean> | Promise对象。返回true表示切换输入法成功；返回false表示切换输入法失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**示例：**

```js
let im = inputMethod.getCurrentInputMethod();
let prop = {
    packageName: im.packageName,
    methodId: im.methodId,
    name: im.packageName,
    id: im.methodId,
    extra: {}
}
try {
    inputMethod.switchInputMethod(prop).then((result) => {
        if (result) {
            console.info('Succeeded in switching inputmethod.');
        } else {
            console.error('Failed to switchInputMethod.');
        }
    }).catch((err) => {
        console.error('Failed to switchInputMethod: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to switchInputMethod: ' + JSON.stringify(err));
}
```

## inputMethod.getCurrentInputMethod<sup>9+</sup>

getCurrentInputMethod(): InputMethodProperty

获取当前输入法扩展应用，提供同步接口，返回当前输入法属性。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](#inputmethodproperty8) | 返回当前输入法属性对象。 |

**示例：**

```js
let currentIme = inputMethod.getCurrentInputMethod();
```

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

在当前输入法应用内切换子类型。使用callback异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| 是 | 传入要切换的目标输入法子类型。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法子类型切换成功，err为undefined，data为true；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**示例：**

```js
try {
    inputMethod.switchCurrentInputMethodSubtype({
      id: "com.example.kikakeyboard",
      label: "ServiceExtAbility",
      name: "",
      mode: "upper",
      locale: "",
      language: "",
      icon: "",
      iconId: 0,
      extra: {}
    }, (err, result) => {
        if (err !== undefined) {
            console.error('Failed to switchCurrentInputMethodSubtype: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in switching currentInputMethodSubtype.');
        } else {
            console.error('Failed to switchCurrentInputMethodSubtype');
        }
    });
} catch(err) {
    console.error('Failed to switchCurrentInputMethodSubtype: ' + JSON.stringify(err));
}
```

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise&lt;boolean&gt;

在当前输入法应用内切换子类型。使用promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| 是 | 传入要切换的目标输入法子类型。 |

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise对象。返回true表示在当前输入法应用内切换子类型成功；返回false表示在当前输入法应用内切换子类型失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**示例：**

```js
try {
    inputMethod.switchCurrentInputMethodSubtype({
      id: "com.example.kikakeyboard",
      label: "ServiceExtAbility",
      name: "",
      mode: "upper",
      locale: "",
      language: "",
      icon: "",
      iconId: 0,
      extra: {}
    }).then((result) => {
        if (result) {
            console.info('Succeeded in switching currentInputMethodSubtype.');
        } else {
            console.error('Failed to switchCurrentInputMethodSubtype.');
        }
    }).catch((err) => {
        console.error('Failed to switchCurrentInputMethodSubtype: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to switchCurrentInputMethodSubtype: ' + JSON.stringify(err));
}
```

## inputMethod.getCurrentInputMethodSubtype<sup>9+</sup>

getCurrentInputMethodSubtype(): InputMethodSubtype

获取当前输入法子类型。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype) | 返回当前输入法子类型对象。 |

**示例：**

```js
let currentImeSubType = inputMethod.getCurrentInputMethodSubtype();
```

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

切换至指定输入法应用的指定子类型，用于跨输入法应用切换子类型。使用callback异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| 是 | 传入要切换的目标输入法。 |
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| 是 | 传入要切换的目标输入法子类型。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法和子类型切换成功，err为undefined，data为获取到的切换子类型结果true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**示例：**

```js
let im = inputMethod.getCurrentInputMethod();
let inputMethodProperty = {
    packageName: im.packageName,
    methodId: im.methodId,
    name: im.packageName,
    id: im.methodId,
    extra: {}
}
try {
    inputMethod.switchCurrentInputMethodAndSubtype(inputMethodProperty, {
      id: "com.example.kikakeyboard",
      label: "ServiceExtAbility",
      name: "",
      mode: "upper",
      locale: "",
      language: "",
      icon: "",
      iconId: 0,
      extra: {}
    }, (err,result) => {
        if (err !== undefined) {
            console.error('Failed to switchCurrentInputMethodAndSubtype: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in switching currentInputMethodAndSubtype.');
        } else {
            console.error('Failed to switchCurrentInputMethodAndSubtype.');
        }
    });
} catch (err) {
    console.error('Failed to switchCurrentInputMethodAndSubtype: ' + JSON.stringify(err));
}
```

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise&lt;boolean&gt;

切换至指定输入法应用的指定子类型，用于跨输入法应用切换子类型。使用promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| 是 | 传入要切换的目标输入法。 |
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| 是 | 传入要切换的目标输入法子类型。 |

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise对象。返回true表示切换至指定输入法应用的指定子类型成功；返回false表示切换至指定输入法应用的指定子类型失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**示例：**

```js
let im = inputMethod.getCurrentInputMethod();
let inputMethodProperty = {
    packageName: im.packageName,
    methodId: im.methodId,
    name: im.packageName,
    id: im.methodId,
    extra: {}
}
try {
    inputMethod.switchCurrentInputMethodAndSubtype(inputMethodProperty, {
      id: im.packageName,
      label: im.methodId,
      name: "",
      mode: "upper",
      locale: "",
      language: "",
      icon: "",
      iconId: 0,
      extra: {}
    }).then((result) => {
        if (result) {
            console.info('Succeeded in switching currentInputMethodAndSubtype.');
        } else {
            console.error('Failed to switchCurrentInputMethodAndSubtype.');
        }
    }).catch((err) => {
        console.error('Failed to switchCurrentInputMethodAndSubtype: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to switchCurrentInputMethodAndSubtype: ' + JSON.stringify(err));
}
```

## inputMethod.getInputMethodController<sup>(deprecated)</sup>

getInputMethodController(): InputMethodController

获取客户端实例[InputMethodController](#inputmethodcontroller)。

> **说明：** 
>
> 从API version 6开始支持，从API version 9开始废弃, 建议使用[getController()](#inputmethodgetcontroller9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                            | 说明                     |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | 回调返回当前客户端实例。 |

**示例：**

```js
let inputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting<sup>(deprecated)</sup>

getInputMethodSetting(): InputMethodSetting

获取客户端设置实例[InputMethodSetting](#inputmethodsetting8)。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃, 建议使用[getSetting()](#inputmethodgetsetting9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | 回调返回当前客户端设置实例。 |

**示例：**

```js
let inputMethodSetting = inputMethod.getInputMethodSetting();
```

## InputMethodController

下列API示例中都需使用[getController](#inputmethodgetcontroller9)获取到InputMethodController实例，再通过此实例调用对应方法。

### stopInputSession<sup>9+</sup>

stopInputSession(callback: AsyncCallback&lt;boolean&gt;): void

结束输入会话。通过点击输入框实现输入会话的开启之后该接口的调用才可生效。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当结束输入会话成功时，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**示例：**

```js
try {
    inputMethodController.stopInputSession((error, result) => {
        if (error !== undefined) {
            console.error('Failed to stopInputSession: ' + JSON.stringify(error));
            return;
        }
        if (result) {
            console.info('Succeeded in stopping inputSession.');
        } else {
            console.error('Failed to stopInputSession.');
        }
    });
} catch(error) {
    console.error('Failed to stopInputSession: ' + JSON.stringify(error));
}
```

### stopInputSession<sup>9+</sup>

stopInputSession(): Promise&lt;boolean&gt;

结束输入会话。通过点击输入框实现输入会话的开启之后此接口才可生效。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示结束输入会话成功；返回false表示结束输入会话失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**示例：**

```js
try {
    inputMethodController.stopInputSession().then((result) => {
        if (result) {
            console.info('Succeeded in stopping inputSession.');
        } else {
            console.error('Failed to stopInputSession.');
        }
    }).catch((err) => {
        console.error('Failed to stopInputSession: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to stopInputSession: ' + JSON.stringify(err));
}
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

显示软键盘。需要与输入框绑定使用。当点击输入框后，才可通过该接口的调用显示出当前输入法的软键盘。使用callback异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当软键盘显示成功。err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**示例：**

```js
inputMethodController.showSoftKeyboard((err) => {
    if (err === undefined) {
        console.info('Succeeded in showing softKeyboard.');
    } else {
        console.error('Failed to showSoftKeyboard: ' + JSON.stringify(err));
    }
})
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(): Promise&lt;void&gt;

显示软键盘。需要与输入框绑定使用。当点击输入框后，才可通过该接口的调用显示出当前输入法的软键盘。使用Promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**示例：**

```js
inputMethodController.showSoftKeyboard().then(() => {
    console.log('Succeeded in showing softKeyboard.');
}).catch((err) => {
    console.error('Failed to showSoftKeyboard: ' + JSON.stringify(err));
});
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏软键盘。需要与输入框绑定使用。点击输入框后，才可以使用该接口的调用隐藏软键盘。使用callback异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当软键盘隐藏成功。err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**示例：**

```js
inputMethodController.hideSoftKeyboard((err) => {
    if (err === undefined) {
        console.info('Succeeded in hiding softKeyboard.');
    } else {
        console.error('Failed to hideSoftKeyboard: ' + JSON.stringify(err));
    }
})
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(): Promise&lt;void&gt;

隐藏软键盘。需要与输入框绑定使用。点击输入框后，才可以使用该接口的调用隐藏软键盘。使用Promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**示例：**

```js
inputMethodController.hideSoftKeyboard().then(() => {
    console.log('Succeeded in hiding softKeyboard.');
}).catch((err) => {
    console.error('Failed to hideSoftKeyboard: ' + JSON.stringify(err));
});
```

### stopInput<sup>(deprecated)</sup>

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

结束输入会话。通过点击输入框实现输入会话的开启之后该接口的调用才可生效。使用callback异步回调。

> **说明：** 
>
> 从API version 6开始支持，从API version 9开始废弃, 建议使用[stopInputSession()](#stopinputsession9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法隐藏成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
inputMethodController.stopInput((error, result) => {
    if (error !== undefined) {
        console.error('Failed to stopInput: ' + JSON.stringify(error));
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

结束输入会话。通过点击输入框实现输入会话的开启之后该接口的调用才可生效。使用promise异步回调。

> **说明：** 
>
> 从API version 6开始支持，从API version 9开始废弃, 建议使用[stopInputSession()](#stopinputsession9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示输入法隐藏成功；返回false表示输入法隐藏失败。 |

**示例：**

```js
inputMethodController.stopInput().then((result) => {
    if (result) {
        console.info('Succeeded in stopping input.');
    } else {
        console.error('Failed to stopInput.');
    }
}).catch((err) => {
    console.error('Failed to stopInput: ' + err);
})
```

## InputMethodSetting<sup>8+</sup>

下列API示例中都需使用[getSetting](#inputmethodgetsetting9)获取到InputMethodSetting实例，再通过此实例调用对应方法。

### on('imeChange')<sup>9+</sup>

on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

订阅输入法及子类型变化监听事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型。<br/>-type为‘imeChange’时表示订阅输入法及子类型变化监听事件。 |
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | 是 | 回调函数，返回输入法属性对象及输入法子类型对象。 |

**示例：**

```js
inputMethodSetting.on('imeChange', (inputMethodProperty, inputMethodSubtype) => {
    console.info('Succeeded in subscribing imeChange: inputMethodProperty: ' + JSON.stringify(inputMethodProperty) + " , inputMethodSubtype: " + JSON.stringify(inputMethodSubtype));
});
```

### off('imeChange')<sup>9+</sup>

off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

取消订阅输入法及子类型变化监听事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型。<br/>-type为‘imeChange’时表示取消订阅输入法及子类型变化监听事件。 |
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | 否 | 回调函数，返回取消订阅的输入法属性对象及输入法子类型对象。 |

**示例：**

```js
inputMethodSetting.off('imeChange');
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

获取指定输入法应用的所有子类型。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | InputMethodProperty| 是 | 子类型所属的输入法应用。 |
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>&gt; | 是 | 回调函数，返回指定输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**示例：**

```js
let inputMethodProperty = {
    packageName: 'com.example.kikakeyboard',
    methodId: 'com.example.kikakeyboard',
    name: 'com.example.kikakeyboard',
    id: 'com.example.kikakeyboard',
    extra:{}
}
try {
    inputMethodSetting.listInputMethodSubtype(inputMethodProperty, (err,data) => {
        if (err !== undefined) {
            console.error('Failed to listInputMethodSubtype: ' + JSON.stringify(err));
            return;
        }
        console.log('Succeeded in listing inputMethodSubtype.');
    });
} catch (err) {
    console.error('Failed to listInputMethodSubtype: ' + JSON.stringify(err));
}
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise&lt;Array&lt;InputMethodSubtype&gt;&gt;

获取指定输入法应用的所有子类型。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | InputMethodProperty| 是 | 子类型所属的输入法应用。 |

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise对象，返回指定输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**示例：**

```js
let inputMethodProperty = {
    packageName: 'com.example.kikakeyboard',
    methodId: 'com.example.kikakeyboard',
    name: 'com.example.kikakeyboard',
    id: 'com.example.kikakeyboard',
    extra:{}
}
try {
    inputMethodSetting.listInputMethodSubtype(inputMethodProperty).then((data) => {
        console.info('Succeeded in listing inputMethodSubtype.');
    }).catch((err) => {
        console.error('Failed to listInputMethodSubtype: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to listInputMethodSubtype: ' + JSON.stringify(err));
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

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**示例：**

```js
try {
    inputMethodSetting.listCurrentInputMethodSubtype((err, data) => {
        if (err !== undefined) {
            console.error('Failed to listCurrentInputMethodSubtype: ' + JSON.stringify(err));
            return;
        }
        console.log('Succeeded in listing currentInputMethodSubtype.');
    });
} catch(err) {
    console.error('Failed to listCurrentInputMethodSubtype: ' + JSON.stringify(err));
}
```

### listCurrentInputMethodSubtype<sup>9+</sup>

listCurrentInputMethodSubtype(): Promise&lt;Array&lt;InputMethodSubtype&gt;&gt;

查询当前输入法的子类型列表。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise对象，返回当前输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**示例：**

```js
try {
    inputMethodSetting.listCurrentInputMethodSubtype().then((data) => {
        console.info('Succeeded in listing currentInputMethodSubtype.');
    }).catch((err) => {
        console.error('Failed to listCurrentInputMethodSubtype: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to listCurrentInputMethodSubtype: ' + JSON.stringify(err));
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

获取已激活/未激活输入法列表。参数enable取true，返回已激活输入法列表，取false返回未激活输入法列表。已激活/未激活输入法的确切功能当前版本未支持。当前版本中，已激活输入法包括当前使用的输入法，未激活输入法包括当前输入法以外的其他已安装的输入法。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                          |
| -------- | --------------------------------------------------- | ---- | ----------------------------- |
| enable   | boolean                                             | 是   | 指定返回已激活/未激活。       |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | 是   | 回调函数，返回已激活/未激活输入法列表。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**示例：**

```js
try {
    inputMethodSetting.getInputMethods(true, (err,data) => {
        if (err !== undefined) {
            console.error('Failed to getInputMethods: ' + JSON.stringify(err));
            return;
        }
        console.log('Succeeded in getting inputMethods.');
    });
} catch (err) {
    console.error('Failed to getInputMethods: ' + JSON.stringify(err));
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

获取已激活/未激活输入法列表。参数enable取true，返回已激活输入法列表，取false返回未激活输入法列表。已激活/未激活输入法的确切功能当前版本未支持。当前版本中，已激活输入法包括当前使用的输入法，未激活输入法包括当前输入法以外的其他已安装的输入法。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型    | 必填 | 说明                    |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | 是   | 指定返回已激活/未激活。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回已激活/未激活输入法列表。 |

**示例：**

```js
try {
    inputMethodSetting.getInputMethods(true).then((data) => {
        console.info('Succeeded in getting inputMethods.');
    }).catch((err) => {
        console.error('Failed to getInputMethods: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to getInputMethods: ' + JSON.stringify(err));
}
```

### showOptionalInputMethods<sup>9+</sup>

showOptionalInputMethods(callback: AsyncCallback&lt;boolean&gt;): void

显示输入法选择对话框。使用callback异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法选择对话框显示成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800008 | Input method manager service error. |

**示例：**

```js
try {
    inputMethodSetting.showOptionalInputMethods((err, data) => {
        if (err !== undefined) {
            console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in showing optionalInputMethods.');
    });
} catch (err) {
    console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
}
```

### showOptionalInputMethods<sup>9+</sup>

showOptionalInputMethods(): Promise&lt;boolean&gt;

显示输入法选择对话框。使用promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY，仅系统应用可用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示输入法选择对话框显示成功；返回false表示输入法选择对话框显示失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800008 | Input method manager service error. |

**示例：**

```js
inputMethodSetting.showOptionalInputMethods().then((data) => {
    console.info('Succeeded in showing optionalInputMethods.');
}).catch((err) => {
    console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
})
```

### listInputMethod<sup>(deprecated)</sup>

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

查询已安装的输入法列表。使用callback异步回调。

> **说明：** 
>
> 从API version 8开始支持，从API version 9开始废弃, 建议使用[getInputMethods](#getinputmethods9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | 是   | 回调函数，返回已安装的输入法列表。 |

**示例：**

```js
inputMethodSetting.listInputMethod((err,data) => {
    if (err !== undefined) {
        console.error('Failed to listInputMethod: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in listing inputMethod.');
 });
```

### listInputMethod<sup>(deprecated)</sup>

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

查询已安装的输入法列表。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃, 建议使用[getInputMethods](#getinputmethods9-1)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回已安装输入法列表。 |

**示例：**

```js
inputMethodSetting.listInputMethod().then((data) => {
    console.info('Succeeded in listing inputMethod.');
}).catch((err) => {
    console.error('Failed to listInputMethod: ' + JSON.stringify(err));
})
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

显示输入法选择对话框。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃, 建议使用[showOptionalInputMethods()](#showoptionalinputmethods9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当输入法选择对话框显示成功。err为undefined，否则为错误对象。 |

**示例：**

```js
inputMethodSetting.displayOptionalInputMethod((err) => {
    if (err !== undefined) {
        console.error('Failed to displayOptionalInputMethod: ' + JSON.stringify(err));
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
> 从API version 8开始支持，从API version 9开始废弃, 建议使用[showOptionalInputMethods()](#showoptionalinputmethods9-1)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
inputMethodSetting.displayOptionalInputMethod().then(() => {
    console.info('Succeeded in displaying optionalInputMethod.');
}).catch((err) => {
    console.error('Failed to displayOptionalInputMethod: ' + JSON.stringify(err));
})
```
