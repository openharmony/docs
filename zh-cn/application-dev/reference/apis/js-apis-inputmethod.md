# @ohos.inputMethod (输入法框架)

本模块主要面向普通前台应用（备忘录、信息、设置等系统应用与三方应用），提供对输入法的控制、管理能力，包括显示/隐藏输入法软键盘、切换输入法、获取所有输入法列表等。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import inputMethod from '@ohos.inputMethod';
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
| name<sup>9+</sup>  | string | 是 | 否 | 必填。输入法内部名称。|
| id<sup>9+</sup>    | string | 是 | 否 | 必填。输入法唯一标识。|
| label<sup>9+</sup>    | string | 是 | 否 | 非必填。输入法对外显示名称。|
| labelId<sup>10+</sup>    | string | 是 | 否 | 非必填。输入法对外显示名称资源号。|
| icon<sup>9+</sup>    | string | 是 | 否 | 非必填。输入法图标数据，可以通过iconId查询获取。预留字段，暂不支持使用。|
| iconId<sup>9+</sup>    | number | 是 | 否 | 非必填。输入法图标资源号。 |
| extra<sup>9+</sup>    | object | 是 | 是 | 输入法扩展信息。预留字段，当前无具体含义，暂不支持使用。<br/>- API version 10起：非必填；<br/>- API version 9：必填。|
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
| 12800006 | input method controller error. |

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
| 12800007 |  settings extension error. |

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
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**示例：**

```js
let currentIme = inputMethod.getCurrentInputMethod();
try{
  inputMethod.switchInputMethod(currentIme, (err, result) => {
    if (err) {
      console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in switching inputmethod.');
    } else {
      console.error('Failed to switchInputMethod.');
    }
  });
} catch(err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
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
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**示例：**

```js
let currentIme = inputMethod.getCurrentInputMethod();
try {
  inputMethod.switchInputMethod(currentIme).then((result) => {
    if (result) {
      console.log('Succeeded in switching inputmethod.');
    } else {
      console.error('Failed to switchInputMethod.');
    }
  }).catch((err) => {
    console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
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

**需要权限：** ohos.permission.CONNECT_IME_ABILITY<br/>**说明：** <br/>- API version 10起，允许系统应用及当前输入法应用调用；<br/>- API version 9，仅系统应用可用。

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
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  inputMethod.switchCurrentInputMethodSubtype({
    id: "ServiceExtAbility",
    label: "",
    name: "com.example.kikakeyboard",
    mode: "upper",
    locale: "",
    language: "",
    icon: "",
    iconId: 0,
    extra: {}
  }, (err, result) => {
    if (err) {
      console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in switching currentInputMethodSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodSubtype');
    }
  });
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise&lt;boolean&gt;

在当前输入法应用内切换子类型。使用promise异步回调。

**需要权限：** ohos.permission.CONNECT_IME_ABILITY<br/>**说明：** <br/>- API version 10起，允许系统应用及当前输入法应用调用；<br/>- API version 9，仅系统应用可用。

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
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  inputMethod.switchCurrentInputMethodSubtype({
    id: "ServiceExtAbility",
    label: "",
    name: "com.example.kikakeyboard",
    mode: "upper",
    locale: "",
    language: "",
    icon: "",
    iconId: 0,
    extra: {}
  }).then((result) => {
    if (result) {
      console.log('Succeeded in switching currentInputMethodSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodSubtype.');
    }
  }).catch((err) => {
    console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
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
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**示例：**

```js
let currentIme = inputMethod.getCurrentInputMethod();
let imSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType, (err,result) => {
    if (err) {
      console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in switching currentInputMethodAndSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodAndSubtype.');
    }
  });
} catch (err) {
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
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
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**示例：**

```js
let currentIme = inputMethod.getCurrentInputMethod();
let imSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType).then((result) => {
    if (result) {
      console.log('Succeeded in switching currentInputMethodAndSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodAndSubtype.');
    }
  }).catch((err) => {
    console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
}
```

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

```js
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

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | 回调返回当前客户端设置实例。 |

**示例：**

```js
let inputMethodSetting = inputMethod.getInputMethodSetting();
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

## EnterKeyType<sup>10+</sup>

输入法Enter键所代表的功能类型。

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

对编辑框中文本的扩展编辑操作类型。

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

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| enterKeyType<sup>10+</sup>  | [EnterKeyType](#enterkeytype10) | 是 | 是 | 输入法enter键类型。|

## InputAttribute<sup>10+</sup>

编辑框属性，包含文本输入类型，Enter键功能类型。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| textInputType<sup>10+</sup>  | [TextInputType](#textinputtype10) | 是 | 是 | 文本输入类型。|
| enterKeyType<sup>10+</sup>  | [EnterKeyType](#enterkeytype10) | 是 | 是 | Enter键功能类型。|

## TextConfig<sup>10+</sup>

编辑控件配置信息。编辑控件请求绑定输入法应用时传入，将编辑控件相关属性配置信息保存到输入法框架内。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| inputAttribute<sup>10+</sup>  | [InputAttribute](#inputattribute10) | 否 | 是 | 编辑框属性。|
| cursorInfo<sup>10+</sup>  | [CursorInfo](#cursorinfo10) | 否 | 否 | 光标信息。|
| selection<sup>10+</sup>  | [Range](#range10) | 否 | 否 | 文本选区范围。|
| windowId<sup>10+</sup>  | number | 否 | 否 | 编辑控件所在的窗口Id。|

## CursorInfo<sup>10+</sup>

光标信息。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| left  | number | 是 | 是 | 光标的left坐标。|
| top  | number | 是 | 是 | 光标的top坐标。|
| width  | number | 是 | 是 | 光标的宽度。|
| height  | number | 是 | 是 | 光标的高度。|

## Range<sup>10+</sup>

描述选中文本的范围。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| start  | number | 是 | 是 | 选中文本的首字符在编辑框的索引值。|
| end  | number | 是 | 是 | 选中文本的末字符在编辑框的索引值。|

## Movement<sup>10+</sup>

描述进行选中文本动作时光标移动的方向。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| direction  | [Direction](#direction10) | 是 | 是 | 进行选中文本动作时光标移动的方向。|

## InputWindowInfo<sup>10+</sup>

输入法软键盘的窗口信息。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| name  | string | 是 | 是 | 输入法窗口的名称。|
| left  | number | 是 | 是 | 输入法窗口左上顶点的横坐标，单位为px。|
| top  | number | 是 | 是 | 输入法窗口左上顶点的纵坐标，单位为px。|
| width  | number | 是 | 是 | 输入法窗口的宽度，单位为px。|
| height  | number | 是 | 是 | 输入法窗口的高度，单位为px。|

## InputMethodController

下列API示例中都需使用[getController](#inputmethodgetcontroller9)获取到InputMethodController实例，再通过此实例调用对应方法。

### attach<sup>10+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig, callback: AsyncCallback&lt;void&gt;): void

用于自绘控件绑定输入法应用。使用callback异步回调。

必须先调用此接口完成自绘控件与输入法应用的绑定，才可以使用输入法框架的以下功能：显示、隐藏键盘；更新光标信息；更改编辑框选中范围；保存配置信息；监听处理由输入法应用发送的信息或命令等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | 是 | 绑定输入法成功后是否拉起输入法键盘。 |
| textConfig | [TextConfig](#textconfig10) | 是 | 编辑控件配置信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当绑定输入法成功后，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };
  inputMethodController.attach(true, textConfig, (err) => {
    if (err) {
      console.error(`Failed to attach: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in attaching the inputMethod.');
  });
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### attach<sup>10+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig): Promise&lt;void&gt;

用于自绘控件绑定输入法应用。使用promise异步回调。

必须先调用此接口完成自绘控件与输入法应用的绑定，才可以使用输入法框架的以下功能：显示、隐藏键盘；更新光标信息；更改编辑框选中范围；保存配置信息；监听处理由输入法应用发送的信息或命令等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | 是 | 绑定输入法成功后是否拉起输入法键盘。 |
| textConfig | [TextConfig](#textconfig10) | 是 | 编辑框属性。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };
  inputMethodController.attach(true, textConfig).then(() => {
    console.log('Succeeded in attaching inputMethod.');
  }).catch((err) => {
    console.error(`Failed to attach: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### showTextInput<sup>10+</sup>

showTextInput(callback: AsyncCallback&lt;void&gt;): void

进入文本编辑状态。使用callback异步回调。

编辑控件与输入法应用绑定成功后，可调用该接口去拉起软键盘。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。若成功进入编辑状态，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**示例：**

```js
inputMethodController.showTextInput((err) => {
  if (err) {
    console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in showing the inputMethod.');
});
```

### showTextInput<sup>10+</sup>

showTextInput(): Promise&lt;void&gt;

进入文本编辑状态。使用promise异步回调。

编辑控件与输入法应用绑定成功后，可调用该接口去拉起软键盘。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**示例：**

```js
inputMethodController.showTextInput().then(() => {
  console.log('Succeeded in showing text input.');
}).catch((err) => {
  console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
});
```

### hideTextInput<sup>10+</sup>

hideTextInput(callback: AsyncCallback&lt;void&gt;): void

退出文本编辑状态。使用callback异步回调。

编辑控件可调用该接口退出编辑状态。若调用该接口时当前软键盘处于显示状态，则调用该接口后软键盘会被隐藏。

调用该接口不解除与输入法应用的绑定，再次调用[showTextInput](#showtextinput10)时，可重新进入编辑状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当成功退出编辑状态时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**示例：**

```js
inputMethodController.hideTextInput((err) => {
  if (err) {
    console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in hiding text input.');
});
```

### hideTextInput<sup>10+</sup>

hideTextInput(): Promise&lt;void&gt;

退出文本编辑状态。使用promise异步回调。

编辑控件可调用该接口退出编辑状态。若调用该接口时当前软键盘处于显示状态，则调用该接口后软键盘会被隐藏。

调用该接口不解除与输入法应用的绑定，再次调用[showTextInput](#showtextinput10)时，可重新进入编辑状态。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**示例：**

```js
inputMethodController.hideTextInput().then(() => {
  console.log('Succeeded in hiding inputMethod.');
}).catch((err) => {
  console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);
})
```

### detach<sup>10+</sup>

detach(callback: AsyncCallback&lt;void&gt;): void

解除与输入法应用的绑定。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当解绑定输入法成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
inputMethodController.detach((err) => {
  if (err) {
    console.error(`Failed to detach: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in detaching inputMethod.');
});
```

### detach<sup>10+</sup>

detach(): Promise&lt;void&gt;

解除与输入法应用的绑定。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
inputMethodController.detach().then(() => {
  console.log('Succeeded in detaching inputMethod.');
}).catch((err) => {
  console.error(`Failed to detach: ${JSON.stringify(err)}`);
});
```

### setCallingWindow<sup>10+</sup>

setCallingWindow(windowId: number, callback: AsyncCallback&lt;void&gt;): void

设置要避让的窗口。使用callback异步回调。

比如：将当前绑定到输入法的应用程序的窗口ID通知系统，正确设置后，客户端所在的窗口可以避开输入法窗口。预留能力，当前暂不支持获取windowId。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 要避让的窗口id。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当设置成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**示例：**

```js
try {
  let windowId: number = 2000;
  inputMethodController.setCallingWindow(windowId, (err) => {
    if (err) {
      console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in setting callingWindow.');
  });
} catch(err) {
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### setCallingWindow<sup>10+</sup>

setCallingWindow(windowId: number): Promise&lt;void&gt;

设置要避让的窗口。使用promise异步回调。

比如：将当前绑定到输入法的应用程序的窗口ID通知系统，正确设置后，客户端所在的窗口可以避开输入法窗口。预留能力，当前暂不支持获取windowId。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| windowId | number | 是 | 要避让的窗口id。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  let windowId: number = 2000;
  inputMethodController.setCallingWindow(windowId).then(() => {
    console.log('Succeeded in setting callingWindow.');
  }).catch((err) => {
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### updateCursor<sup>10+</sup>

updateCursor(cursorInfo: CursorInfo, callback: AsyncCallback&lt;void&gt;): void

更新当前编辑框内光标信息。使用callback异步回调。

当光标信息发生变化时，可调用该接口更新光标信息，从而被输入法应用感知到光标变化。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| cursorInfo | [CursorInfo](#cursorinfo10) | 是 | 光标信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当光标信息更新成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**示例：**

```js
try {
  inputMethodController.updateCursor({left: 0, top: 0, width: 600, height: 800}, (err) => {
    if (err) {
      console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in updating cursorInfo.');
  });
} catch(err) {
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
}
```

### updateCursor<sup>10+</sup>

updateCursor(cursorInfo: CursorInfo): Promise&lt;void&gt;

更新当前编辑控件内的光标信息。使用promise异步回调。

当光标信息发生变化时，编辑控件可调用该接口更新光标信息，从而被输入法应用感知到光标变化。

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

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.updateCursor({left: 0, top: 0, width: 600, height: 800}).then(() => {
    console.log('Succeeded in updating cursorInfo.');
  }).catch((err) => {
    console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
}
```

### changeSelection<sup>10+</sup>

changeSelection(text: string, start: number, end: number, callback: AsyncCallback&lt;void&gt;): void

向输入法应用更新当前编辑框内被选中的文本信息，当选中的文本内容或文本范围发生变化时，可调用该接口更新文本信息。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 整个输入文本。 |
| start | number | 是 | 所选文本的起始位置。 |
| end | number | 是 | 所选文本的结束位置。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当隐藏输入法成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**示例：**

```js
try {
  inputMethodController.changeSelection('text', 0, 5, (err) => {
    if (err) {
      console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in changing selection.');
  });
} catch(err) {
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
}
```

### changeSelection<sup>10+</sup>

changeSelection(text: string, start: number, end: number): Promise&lt;void&gt;

向输入法应用更新当前编辑框内被选中的文本信息，当选中的文本内容或文本范围发生变化时，可调用该接口更新文本信息。使用promise异步回调。

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

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.changeSelection('test', 0, 5).then(() => {
    console.log('Succeeded in changing selection.');
  }).catch((err) => {
    console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
}
```

### updateAttribute<sup>10+</sup>

updateAttribute(attribute: InputAttribute, callback: AsyncCallback&lt;void&gt;): void

更新编辑框属性配置信息。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| attribute | [InputAttribute](#inputattribute10) | 是 | InputAttribute对象，包含的额外信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当隐藏输入法成功时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**示例：**

```js
try {
  inputMethodController.updateAttribute({textInputType: 0, enterKeyType: 1}, (err) => {
    if (err) {
      console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in updating attribute.');
  });
} catch(err) {
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
}
```

### updateAttribute<sup>10+</sup>

updateAttribute(attribute: InputAttribute): Promise&lt;void&gt;

更新编辑框属性配置信息。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| attribute | [InputAttribute](#inputattribute10) | 是 | InputAttribute对象，包含的额外信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.updateAttribute({textInputType: 0, enterKeyType: 1}).then(() => {
    console.log('Succeeded in updating attribute.');
  }).catch((err) => {
    console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
}
```

### stopInputSession<sup>9+</sup>

stopInputSession(callback: AsyncCallback&lt;boolean&gt;): void

结束输入会话。使用callback异步回调。

需要与编辑控件（如：输入框）绑定使用。当点击编辑控件后，才可通过调用该接口结束输入会话。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当结束输入会话成功时，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  inputMethodController.stopInputSession((err, result) => {
    if (err) {
      console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in stopping inputSession.');
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

需要与编辑控件（如：输入框）绑定使用。当点击编辑控件后，才可通过调用该接口结束输入会话。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示结束输入会话成功；返回false表示结束输入会话失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  inputMethodController.stopInputSession().then((result) => {
    if (result) {
      console.log('Succeeded in stopping inputSession.');
    } else {
      console.error('Failed to stopInputSession.');
    }
  }).catch((err) => {
    console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
}
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

显示软键盘。使用callback异步回调。

需要与编辑控件（如：输入框）绑定使用。当点击编辑控件后，才可通过该接口的调用显示出当前输入法的软键盘。

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
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
inputMethodController.showSoftKeyboard((err) => {
  if (!err) {
    console.log('Succeeded in showing softKeyboard.');
  } else {
    console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);
  }
})
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(): Promise&lt;void&gt;

显示软键盘。使用Promise异步回调。

需要与编辑控件（如：输入框）绑定使用。当点击编辑控件后，才可通过该接口的调用显示出当前输入法的软键盘。

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
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
inputMethodController.showSoftKeyboard().then(() => {
  console.log('Succeeded in showing softKeyboard.');
}).catch((err) => {
  console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);
});
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏软键盘。使用callback异步回调。

需要与编辑控件（如：输入框）绑定使用。当点击编辑控件后，才可通过调用该接口隐藏当前输入法的软键盘。

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
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
inputMethodController.hideSoftKeyboard((err) => {
  if (!err) {
    console.log('Succeeded in hiding softKeyboard.');
  } else {
    console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);
  }
})
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(): Promise&lt;void&gt;

隐藏软键盘。使用Promise异步回调。

需要与编辑控件（如：输入框）绑定使用。当点击编辑控件后，才可通过调用该接口隐藏当前输入法的软键盘。

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
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**示例：**

```js
inputMethodController.hideSoftKeyboard().then(() => {
  console.log('Succeeded in hiding softKeyboard.');
}).catch((err) => {
  console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);
});
```

### stopInput<sup>(deprecated)</sup>

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

结束输入会话。使用callback异步回调。

需要与编辑控件（如：输入框）绑定使用。当点击编辑控件后，才可通过调用该接口结束输入会话。

> **说明：** 
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[stopInputSession()](#stopinputsession9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法隐藏成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
inputMethodController.stopInput((err, result) => {
  if (err) {
    console.error(`Failed to stopInput: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.log('Succeeded in stopping input.');
  } else {
    console.error('Failed to stopInput.');
  }
});
```

### stopInput<sup>(deprecated)</sup>

stopInput(): Promise&lt;boolean&gt;

结束输入会话。使用promise异步回调。

需要与编辑控件（如：输入框）绑定使用。当点击编辑控件后，才可通过调用该接口结束输入会话。

> **说明：** 
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[stopInputSession()](#stopinputsession9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示输入法隐藏成功；返回false表示输入法隐藏失败。 |

**示例：**

```js
inputMethodController.stopInput().then((result) => {
  if (result) {
    console.log('Succeeded in stopping input.');
  } else {
    console.error('Failed to stopInput.');
  }
}).catch((err) => {
  console.error(`Failed to stopInput: ${JSON.stringify(err)}`);
})
```

### on('insertText')<sup>10+</sup>

on(type: 'insertText', callback: (text: string) => void): void;

订阅输入法应用插入文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 设置监听类型。<br/>- type为‘insertText’时表示订阅输入法应用插入文本事件监听。 |
| callback | (text: string) => void | 是   | 回调函数，返回需要插入的文本内容。<br/>开发者需要在回调函数中根据传入的文本内容操作编辑框中的内容。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('insertText', (text) => {
    console.log(`Succeeded in subscribing insertText: ${text}`);
  });
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
| type     | string                 | 是   | 设置监听类型。<br/>- type为‘insertText’时表示取消订阅输入法应用插入文本事件监听。 |
| callback | (text: string) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onInsertTextCallback = (text: string) => {
    console.log(`Succeeded in subscribing insertText: ${text}`);
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
| type     | string  | 是   | 设置监听类型。<br/>- type为`deleteLeft`表示订阅输入法应用向左删除事件监听。 |
| callback | (length: number) => void | 是   | 回调函数，返回需要向左删除的文本的长度。<br/>开发者需要在回调函数中根据传入的删除长度操作编辑框中相应文本。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('deleteLeft', (length) => {
    console.log(`Succeeded in subscribing deleteLeft, length: ${length}`);
  });
} catch(err) {
  console.error(`Failed to subscribe deleteLeft: ${JSON.stringify(err)}`);
}
```

### on('deleteRight')<sup>10+</sup>

on(type: 'deleteRight', callback: (length: number) => void): void

订阅输入法应用向右删除事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明 |
| -------- | ----- | ---- | ----- |
| type     | string  | 是   | 设置监听类型。<br/>- type为`deleteRight`表示订阅输入法应用向右删除事件监听。|
| callback | (length: number) => void | 是   | 回调函数，返回需要向右删除的文本的长度。<br/>开发者需要在回调函数中根据传入的删除长度操作编辑框中相应文本。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('deleteRight', (length) => {
    console.log(`Succeeded in subscribing deleteRight, length: ${length}`);
  });
} catch(err) {
  console.error(`Failed to subscribe deleteRight: ${JSON.stringify(err)}`);
}
```
### off('deleteLeft')<sup>10+</sup>

off(type: 'deleteLeft', callback?: (length: number) => void): void

取消订阅输入法应用向左删除文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                   | 是   | 设置监听类型。<br/>- type为`deleteLeft`表示取消订阅输入法应用向左删除的事件监听。 |
| callback | (length: number) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onDeleteLeftCallback = (length: number) => {
    console.log(`Succeeded in subscribing deleteLeft, length: ${length}`);
};
inputMethodController.off('deleteLeft', onDeleteLeftCallback);
inputMethodController.off('deleteLeft');
```

### off('deleteRight')<sup>10+</sup>

off(type: 'deleteRight', callback?: (length: number) => void): void

取消订阅输入法应用向右删除文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                   | 是   | 设置监听类型。<br/>- type为`deleteRight`表示取消订阅输入法应用向右删除的事件监听。 |
| callback | (length: number) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onDeleteRightCallback = (length: number) => {
    console.log(`Succeeded in subscribing deleteRight, length: ${length}`);
};
inputMethodController.off('deleteRight', onDeleteRightCallback);
inputMethodController.off('deleteRight');
```

### on('sendKeyboardStatus')<sup>10+</sup>

on(type: 'sendKeyboardStatus', callback: (keyBoardStatus: KeyboardStatus) => void): void

订阅输入法应用发送键盘状态事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明    |
| -------- | ------ | ---- | ---- |
| type     | string  | 是   | 设置监听类型。<br/>- type为‘sendKeyboardStatus’时表示订阅输入法应用发送键盘状态事件监听。 |
| callback | (keyBoardStatus: [KeyboardStatus](#keyboardstatus10)) => void | 是   | 回调函数，返回键盘状态。<br/>开发者需要在回调函数中根据传入的键盘状态做相应动作。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('sendKeyboardStatus', (keyBoardStatus) => {
    console.log(`Succeeded in subscribing sendKeyboardStatus, keyBoardStatus: ${keyBoardStatus}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sendKeyboardStatus: ${JSON.stringify(err)}`);
}
```

### off('sendKeyboardStatus')<sup>10+</sup>

off(type: 'sendKeyboardStatus', callback?: (keyBoardStatus: KeyboardStatus) => void): void

取消订阅输入法应用发送键盘状态事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 设置监听类型。<br/>- type为‘sendKeyboardStatus’时表示取消订阅输入法应用发送键盘状态事件监听。 |
| callback | (keyBoardStatus: [KeyboardStatus](#keyboardstatus10)) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onSendKeyboardStatus = (keyBoardStatus: KeyboardStatus) => {
    console.log(`Succeeded in subscribing sendKeyboardStatus, keyBoardStatus: ${keyBoardStatus}`);
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
| type     | string  | 是   | 设置监听类型。<br/>- type为‘sendFunctionKey’时表示订阅输入法应用发送功能键事件监听。 |
| callback | (functionKey: [FunctionKey](#functionkey10)) => void | 是   | 回调函数，返回输入法应用发送的功能键信息。<br/>开发者需要根据返回的功能键做相应的操作。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('sendFunctionKey', (functionKey) => {
    console.log(`Succeeded in subscribing sendFunctionKey, functionKey.enterKeyType: ${functionKey.enterKeyType}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sendFunctionKey: ${JSON.stringify(err)}`);
}
```

### off('sendFunctionKey')<sup>10+</sup>

off(type: 'sendFunctionKey', callback?: (functionKey: FunctionKey) => void): void

取消订阅输入法应用发送FunctionKey事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                               | 是   | 设置监听类型。<br/>- type为‘sendFunctionKey’时表示取消订阅输入法应用发送FunctionKey事件监听。 |
| callback | (functionKey: [FunctionKey](#functionkey10)) => void | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onSendFunctionKey = (functionKey: FunctionKey) => {
    console.log(`Succeeded in subscribing sendFunctionKey, functionKey: ${functionKey.enterKeyType}`);
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
| type     | string | 是   | 设置监听类型。<br/>- type为‘moveCursor’时表示订阅输入法应用移动光标事件监听。 |
| callback | callback: (direction: [Direction<sup>10+</sup>](#direction10)) => void | 是   | 回调函数，返回光标信息。<br/>开发者需要根据返回的光标移动方向改变光标位置。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                           |
| -------- | -------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('moveCursor', (direction) => {
    console.log(`Succeeded in subscribing moveCursor, direction: ${direction}`);
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
| type   | string | 是   | 设置监听类型。<br/>- type为‘moveCursor’时表示取消订阅输入法应用发送移动光标事件监听。 |
| callback | (direction: [Direction<sup>10+</sup>](#direction10)) => void | 否 | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onMoveCursorCallback = (direction: Direction) => {
    console.log(`Succeeded in subscribing moveCursor, direction: ${direction}`);
};
inputMethodController.off('moveCursor', onMoveCursorCallback);
inputMethodController.off('moveCursor');
```

### on('handleExtendAction')<sup>10+</sup>

on(type: 'handleExtendAction', callback: (action: ExtendAction) => void): void

订阅输入法应用发送扩展操作事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明   |
| -------- | ------ | ---- | -------- |
| type     | string    | 是   | 设置监听类型。<br/>- type为‘handleExtendAction’时表示订阅输入法应用发送扩展操作代码事件监听。 |
| callback | callback: (action: [ExtendAction](#extendaction10)) => void | 是   | 回调函数，返回扩展操作类型。<br/>开发者需要在回调函数中根据传入的扩展操作类型做相应的操作。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('handleExtendAction', (action) => {
    console.log(`Succeeded in subscribing handleExtendAction, action: ${action}`);
  });
} catch(err) {
  console.error(`Failed to subscribe handleExtendAction: ${JSON.stringify(err)}`);
}
```

### off('handleExtendAction')<sup>10+</sup>

off(type: 'handleExtendAction', callback?: (action: ExtendAction) => void): void

取消订阅输入法应用发送扩展操作事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ------ | ---- | ------- |
| type   | string | 是   | 设置监听类型。<br/>- type为‘handleExtendAction’时表示取消订阅输入法应用发送扩展代码事件监听。 |
| callback | (action: [ExtendAction](#extendaction10)) => void | 否 | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onHandleExtendActionCallback = (action: ExtendAction) => {
    console.log(`Succeeded in subscribing handleExtendAction, action: ${action}`);
};
inputMethodController.off('handleExtendAction', onHandleExtendActionCallback);
inputMethodController.off('handleExtendAction');
```

### on('selectByRange')<sup>10+</sup>

on(type: 'selectByRange', callback: Callback&lt;Range&gt;): void

订阅输入法应用按范围选中文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型     | 必填 | 说明     |
| -------- | ---- | ---- | ------- |
| type     | string  | 是   | 设置监听类型。<br/>- type为‘selectByRange’时表示订阅输入法应用按范围选中文本事件监听。 |
| callback | Callback&lt;[Range](#range10)&gt; | 是   | 回调函数，返回需要选中的文本的范围。<br/>开发者需要在回调函数中根据传入的范围选中编辑框中相应文本。 |

**示例：**

```js
inputMethodController.on('selectByRange', (range) => {
  console.log(`Succeeded in subscribing selectByRange: start: ${range.start} , end: ${range.end}`);
});
```

### off('selectByRange')<sup>10+</sup>

off(type: 'selectByRange', callback?:  Callback&lt;Range&gt;): void

取消订阅输入法应用按范围选中文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                            | 是   | 设置监听类型。<br/>- type为‘selectByRange’时表示取消订阅输入法应用按范围选中文本事件监听。 |
| callback | Callback&lt;[Range](#range10)&gt; | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onSelectByRangeCallback = (range: Range) => {
    console.log(`Succeeded in subscribing selectByRange, range: ${JSON.stringify(range)}`);
};
inputMethodController.off('selectByRange', onSelectByRangeCallback);
inputMethodController.off('selectByRange');
```

### on('selectByMovement')<sup>10+</sup>

on(type: 'selectByMovement', callback: Callback&lt;Movement&gt;): void

订阅输入法应用按光标动作选中文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型。<br/>- type为‘selectByMovement’时表示订阅输入法应用按光标移动动作选中文本事件监听。 |
| callback | Callback&lt;[Movement](#movement10)&gt; | 是   | 回调函数，返回需要选中的文本的范围。<br/>开发者需要在回调函数中根据传入的光标动作选中编辑框中相应文本。 |

**示例：**

```js
inputMethodController.on('selectByMovement', (movement) => {
  console.log('Succeeded in subscribing selectByMovement: direction: ' + movement.direction);
});
```

### off('selectByMovement')<sup>10+</sup>

off(type: 'selectByMovement', callback?: Callback&lt;Movement&gt;): void

取消订阅输入法应用按光标动作选中文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                               | 是   | 设置监听类型。<br/>- type为‘selectByMovement’时表示取消订阅输入法应用按范围选中文本事件监听。 |
| callback | Callback&lt;[Movement](#movement10)> | 否   | 取消订阅的回调函数，需要与on接口传入的保持一致。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
let onSelectByMovementCallback = (movement: Movement) => {
    console.log(`Succeeded in subscribing selectByMovement, movement.direction: ${movement.direction}`);
};
inputMethodController.off('selectByMovement', onSelectByMovementCallback);
inputMethodController.off('selectByMovement');
```

### on('getLeftTextOfCursor')<sup>10+</sup>

on(type: 'getLeftTextOfCursor', callback: (length: number) => string): void;

订阅输入法应用获取光标左侧指定长度文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型。<br/>- type为‘getLeftTextOfCursor’时表示订阅输入法应用获取光标左侧指定长度文本事件监听。 |
| callback | (length: number) => string | 是   | 回调函数，获取光标左侧指定长度文本内容。<br/>开发者需要在该函数中，获取编辑框最新状态下光标左侧指定length长度的文本内容并返回。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('getLeftTextOfCursor', (length) => {
    console.info(`Succeeded in subscribing getLeftTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to subscribe getLeftTextOfCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### off('getLeftTextOfCursor')<sup>10+</sup>

off(type: 'getLeftTextOfCursor', callback?: (length: number) => string): void;

取消订阅输入法应用获取光标左侧指定长度文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 设置监听类型。<br/>- type为‘getLeftTextOfCursor’时表示取消订阅输入法应用获取光标左侧指定长度文本事件监听。 |
| callback | (length: number) => string | 否  | 回调函数，获取光标左侧指定长度文本内容。需要与on接口传入的保持一致。|

**示例：**

```js
try {
  inputMethodController.off('getLeftTextOfCursor', (length) => {
    console.info(`Succeeded in unsubscribing getLeftTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to unsubscribing getLeftTextOfCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### on('getRightTextOfCursor')<sup>10+</sup>

on(type: 'getRightTextOfCursor', callback: (length: number) => string): void;

订阅输入法应用获取光标右侧指定长度文本事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型。<br/>- type为‘getRightTextOfCursor’时表示订阅输入法应用获取光标右侧指定长度文本事件监听。 |
| callback | (length: number) => string | 是   | 回调函数，获取光标右侧指定长度文本内容。<br/>开发者需要在该函数中，获取编辑框最新状态下光标右侧指定length长度的文本内容并返回。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('getRightTextOfCursor', (length) => {
    console.info(`Succeeded in subscribing getRightTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to subscribe getRightTextOfCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### off('getRightTextOfCursor')<sup>10+</sup>

off(type: 'getRightTextOfCursor', callback?: (length: number) => string): void;

取消订阅输入法应用获取光标右侧指定长度文本事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 设置监听类型。<br/>- type为‘getRightTextOfCursor’时表示取消订阅输入法应用获取光标右侧指定长度文本事件监听。 |
| callback | (length: number) => string | 否  | 回调函数，获取光标右侧指定长度文本内容。需要与on接口传入的保持一致。|

**示例：**

```js
try {
  inputMethodController.off('getRightTextOfCursor', (length) => {
    console.info(`Succeeded in unsubscribing getRightTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to unsubscribing getRightTextOfCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### on('getTextIndexAtCursor')<sup>10+</sup>

on(type: 'getTextIndexAtCursor', callback: () => number): void;

订阅输入法应用获取光标处文本索引事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明     |
| -------- | ----- | ---- | ------ |
| type     | string  | 是   | 设置监听类型。<br/>- type为‘getTextIndexAtCursor’时表示订阅输入法应用获取光标处文本索引事件监听。 |
| callback | () => number | 是   | 回调函数，获取光标处文本索引。<br/>开发者需要在该函数中，获取编辑框最新状态下光标处文本索引并返回。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**示例：**

```js
try {
  inputMethodController.on('getTextIndexAtCursor', () => {
    console.info(`Succeeded in subscribing getTextIndexAtCursor.`);
    let index:number = 0;
    return index;
  });
} catch(err) {
  console.error(`Failed to subscribe getTextIndexAtCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### off('getTextIndexAtCursor')<sup>10+</sup>

off(type: 'getTextIndexAtCursor', callback?: () => number): void;

取消订阅输入法应用获取光标处文本索引事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 设置监听类型。<br/>- type为‘getTextIndexAtCursor’时表示取消订阅输入法应用获取光标处文本索引事件监听。 |
| callback | () => number | 否  | 回调函数，获取光标处文本索引。需要与on接口传入的保持一致。|

**示例：**

```js
try {
  inputMethodController.off('getTextIndexAtCursor', () => {
    console.info(`Succeeded in unsubscribing getTextIndexAtCursor.`);
    let index:number = 0;
    return index;
  });
} catch(err) {
  console.error(`Failed to unsubscribing getTextIndexAtCursor. Code: ${err.code}, message: ${err.message}`);
}
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
| type     | string                        | 是   | 设置监听类型。<br/>- type为‘imeChange’时表示订阅输入法及子类型变化监听事件。 |
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | 是 | 回调函数，返回输入法属性对象及输入法子类型对象。 |

**示例：**

```js
inputMethodSetting.on('imeChange', (inputMethodProperty, inputMethodSubtype) => {
  console.log('Succeeded in subscribing imeChange: inputMethodProperty: ' + JSON.stringify(inputMethodProperty) + " , inputMethodSubtype: " + JSON.stringify(inputMethodSubtype));
});
```

### off('imeChange')<sup>9+</sup>

off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

取消订阅输入法及子类型变化监听事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型    | 必填 | 说明          |
| -------- | --------- | ---- | --------------- |
| type     | string    | 是   | 设置监听类型。<br/>- type为‘imeChange’时表示取消订阅输入法及子类型变化监听事件。 |
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | 否 | 回调函数，返回取消订阅的输入法属性对象及输入法子类型对象。 |

**示例：**

```js
inputMethodSetting.off('imeChange');
```

### on('imeShow')<sup>10+</sup>

on(type: 'imeShow', callback: (info: Array\<InputWindowInfo>) => void): void

订阅输入法软键盘显示事件。使用callback异步回调。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明 |
| -------- | ---- | ---- | ---- |
| type     | string | 是 | 设置监听类型。<br/>- type为`imeShow`表示订阅输入法软键盘显示事件。 |
| callback | (info: Array\<InputWindowInfo>) => void | 是 | 回调函数，返回输入法软键盘信息。 |

**示例：**

```js
inputMethodSetting.on('imeShow', (info) => {
    console.info('Succeeded in subscribing imeShow event.');
});
```

### on('imeHide')<sup>10+</sup>

on(type: 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void

订阅输入法软键盘隐藏事件。使用callback异步回调。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明 |
| -------- | ---- | ---- | ---- |
| type     | string | 是 | 设置监听类型。<br/>- type为`imeHide`表示订阅输入法软键盘隐藏事件。 |
| callback | (info: Array\<InputWindowInfo>) => void | 是 | 回调函数，返回输入法软键盘信息。 |

**示例：**

```js
inputMethodSetting.on('imeHide', (info) => {
    console.info('Succeeded in subscribing imeHide event.');
});
```

### off('imeShow')<sup>10+</sup>

off(type: 'imeShow', callback?: (info: Array\<InputWindowInfo>) => void): void

取消订阅输入法软键盘显示事件。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明   |
| -------- | ---- | ---- | ------ |
| type     | string | 是 | 设置监听类型。<br/>- type为`imeShow`表示取消订阅输入法软键盘显示事件。 |
| callback | (info: Array\<InputWindowInfo>) => void  | 否 | 取消订阅的回调函数。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
inputMethodSetting.off('imeShow');
```

### off('imeHide')<sup>10+</sup>

off(type: 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void

取消订阅输入法软键盘隐藏事件。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型 | 必填 | 说明   |
| -------- | ---- | ---- | ------ |
| type     | string | 是 | 设置监听类型。<br/>- type为`imeHide`表示取消订阅输入法软键盘隐藏事件。 |
| callback | (info: Array\<InputWindowInfo>) => void  | 否 | 取消订阅的回调函数。当该参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```js
inputMethodSetting.off('imeHide');
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

获取指定输入法应用的所有子类型。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | [InputMethodProperty](#inputmethodproperty8)| 是 | 子类型所属的输入法应用。 |
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>&gt; | 是 | 回调函数，返回指定输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**示例：**

```js
let inputMethodProperty = {
  name: 'com.example.kikakeyboard',
  id: 'propertyId',
}
try {
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty, (err, data) => {
    if (err) {
      console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in listing inputMethodSubtype.');
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
| inputMethodProperty | [InputMethodProperty](#inputmethodproperty8)| 是 | 子类型所属的输入法应用。 |

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise对象，返回指定输入法应用的所有子类型。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**示例：**

```js
let inputMethodProperty = {
  name: 'com.example.kikakeyboard',
  id: 'propertyId',
}
try {
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty).then((data) => {
    console.log('Succeeded in listing inputMethodSubtype.');
  }).catch((err) => {
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

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  inputMethodSetting.listCurrentInputMethodSubtype((err, data) => {
    if (err) {
      console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in listing currentInputMethodSubtype.');
  });
} catch(err) {
  console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
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
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  inputMethodSetting.listCurrentInputMethodSubtype().then((data) => {
    console.log('Succeeded in listing currentInputMethodSubtype.');
  }).catch((err) => {
    console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

获取已激活/未激活输入法列表。使用callback异步回调。

参数enable取true，返回已激活输入法列表；取false返回未激活输入法列表。已激活/未激活为预留概念，当前暂未支持。当前版本中，已激活输入法包括当前使用的输入法，未激活输入法包括当前输入法以外的其他已安装的输入法。

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
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  inputMethodSetting.getInputMethods(true, (err, data) => {
    if (err) {
      console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in getting inputMethods.');
  });
} catch (err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

获取已激活/未激活输入法列表。使用promise异步回调。

参数enable取true，返回已激活输入法列表；取false返回未激活输入法列表。已激活/未激活为预留概念，当前暂未支持。当前版本中，已激活输入法包括当前使用的输入法，未激活输入法包括当前输入法以外的其他已安装的输入法。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型    | 必填 | 说明                    |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | 是   | 指定返回已激活/未激活。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 |input method manager service error. |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回已激活/未激活输入法列表。 |

**示例：**

```js
try {
  inputMethodSetting.getInputMethods(true).then((data) => {
    console.log('Succeeded in getting inputMethods.');
  }).catch((err) => {
    console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### showOptionalInputMethods<sup>9+</sup>

showOptionalInputMethods(callback: AsyncCallback&lt;boolean&gt;): void

显示输入法选择对话框。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法选择对话框显示成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. |

**示例：**

```js
try {
  inputMethodSetting.showOptionalInputMethods((err, data) => {
    if (err) {
      console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in showing optionalInputMethods.');
  });
} catch (err) {
  console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
}
```

### showOptionalInputMethods<sup>9+</sup>

showOptionalInputMethods(): Promise&lt;boolean&gt;

显示输入法选择对话框。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示输入法选择对话框显示成功；返回false表示输入法选择对话框显示失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. |

**示例：**

```js
inputMethodSetting.showOptionalInputMethods().then((data) => {
  console.log('Succeeded in showing optionalInputMethods.');
}).catch((err) => {
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

```js
inputMethodSetting.listInputMethod((err, data) => {
  if (err) {
    console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);
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
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getInputMethods](#getinputmethods9-1)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回已安装输入法列表。 |

**示例：**

```js
inputMethodSetting.listInputMethod().then((data) => {
  console.log('Succeeded in listing inputMethod.');
}).catch((err) => {
  console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);
})
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

显示输入法选择对话框。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[showOptionalInputMethods()](#showoptionalinputmethods9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当输入法选择对话框显示成功。err为undefined，否则为错误对象。 |

**示例：**

```js
inputMethodSetting.displayOptionalInputMethod((err) => {
  if (err) {
    console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in displaying optionalInputMethod.');
});
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(): Promise&lt;void&gt;

显示输入法选择对话框。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[showOptionalInputMethods()](#showoptionalinputmethods9-1)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
inputMethodSetting.displayOptionalInputMethod().then(() => {
  console.log('Succeeded in displaying optionalInputMethod.');
}).catch((err) => {
  console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);
})
```
