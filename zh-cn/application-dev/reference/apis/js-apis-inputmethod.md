# 输入法框架

本模块提供对输入法框架的管理，包括隐藏输入法、查询已安装的输入法列表和拉起选择输入法弹窗。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import inputMethod from '@ohos.inputmethod';
```

## 常量<sup>8+</sup>

常量值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 参数名 | 参数 | 常量值 | 说明 |
| -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM | number | 128 | 可支持的最大输入法个数。 |

## InputMethodProperty<sup>8+</sup>

输入法应用属性。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 参数 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| packageName | string | 是 | 否 | 输入法包名。 |
| methodId | string | 是 | 否 | 输入法唯一标识。 |

## inputMethod.getInputMethodController

getInputMethodController(): InputMethodController

获取客户端实例[InputMethodController](#inputmethodcontroller)。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                            | 说明                     |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | 回调返回当前客户端实例。 |

**示例：**

```js
let inputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting<sup>8+</sup>

getInputMethodSetting(): InputMethodSetting

获取客户端设置实例[InputMethodSetting](#inputmethodsetting8)。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | 回调返回当前客户端设置实例。 |

**示例：**

```js
let inputMethodSetting = inputMethod.getInputMethodSetting();
```
## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty, callback: AsyncCallback&lt;boolean&gt;): void

切换输入法。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | [InputMethodProperty](#inputmethodproperty8) | 是 | 传入要切换的目标输入法。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当输入法切换成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
inputMethod.switchInputMethod({packageName:'com.example.kikakeyboard', methodId:'com.example.kikakeyboard'} ,(err,result) => {
    if (err) {
        console.error('Failed to switch inputmethod: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Succeeded in switching inputmethod.');
    } else {
        console.error('Failed to switch inputmethod.');
    }
});
```

## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty): Promise&lt;boolean&gt;

切换输入法。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
|target |  [InputMethodProperty](#inputmethodproperty8)| 是 | 传入要切换的目标输入法。 |

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise对象。返回true表示切换输入法成功；返回false表示切换输入法失败。 |

**示例：**

```js
inputMethod.switchInputMethod({packageName:'com.example.kikakeyboard', methodId:'com.example.kikakeyboard'}).then((result) => {
    if (result) {
        console.info('Succeeded in switching inputMethod.');
    } else {
        console.error('Failed to switch inputmethod.');
    }
}).catch((err) => {
    console.error('Failed to switch inputmethod: ' + JSON.stringify(err));
})
```

## inputMethod.getCurrentInputMethod<sup>9+</sup>

getCurrentInputMethod(): InputMethodProperty

获取当前输入法的属性对象。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](#inputmethodproperty8) | 返回当前输入法的属性对象。 |

**示例：**

```js
let currentIme = inputMethod.getCurrentInputMethod();
```

## InputMethodController

下列API示例中都需使用[getInputMethodController](#inputmethodgetinputmethodcontroller)回调获取到InputMethodController实例，再通过此实例调用对应方法。

### stopInput

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

结束输入会话。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当结束输入会话成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
inputMethodController.stopInput((error, result) => {
    if (error) {
        console.error('Failed to stop input method: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Succeeded in stoping input method.');
    } else {
        console.error('Failed to stop input method.');
    }
});
```

### stopInput

stopInput(): Promise&lt;boolean&gt;

结束输入会话。使用Promise异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示结束会话成功；返回false表示结束会话失败。 |

**示例：**

```js
inputMethodController.stopInput().then((result) => {
    if (result) {
        console.info('Succeeded in stoping input method.');
    } else {
        console.error('Failed to stop input method.');
    }
}).catch((err) => {
    console.error('Failed to stop input method: ' + JSON.stringify(err));
})
```

### showSoftKeyboard<sup>9+</sup> ###

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

显示软键盘，使用callback异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 参数                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当软键盘显示成功。err为undefined，否则为错误对象。 |

**示例：**

```js
inputMethodController.showSoftKeyboard((err) => {
    if (err) {
        console.info('Succeeded in showing softKeyboard.');
    } else {
        console.error('Failed to show softKeyboard: ' + JSON.stringify(err));
    }
})
```


### showSoftKeyboard<sup>9+</sup> ###

showSoftKeyboard(): Promise&lt;void&gt;

显示软键盘，使用Promise异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
inputMethodController.showSoftKeyboard().then(() => {
    console.log('Succeeded in showing softKeyboard.');
}).catch((err) => {
    console.error('Failed to show softKeyboard: ' + JSON.stringify(err));
});
```

### hideSoftKeyboard<sup>9+</sup> ###

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏软键盘，使用callback异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 参数                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当软键盘隐藏成功。err为undefined，否则为错误对象。 |

**示例：**

```js
inputMethodController.hideSoftKeyboard((err) => {
    if (err) {
        console.info('Failed to hide softKeyboard: ' + JSON.stringify(err));
    } else {
        console.error('Succeeded in hiding softKeyboard.');
    }
})
```

### hideSoftKeyboard<sup>9+</sup> ###

hideSoftKeyboard(): Promise&lt;void&gt;

隐藏软键盘，使用Promise异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
inputMethodController.hideSoftKeyboard().then((err) => {
    console.log('Succeeded in hiding softKeyboard.');
}).catch((err) => {
    console.error('Failed to hide softKeyboard: ' + JSON.stringify(err));
});
```

## InputMethodSetting<sup>8+</sup>

下列API示例中都需使用[getInputMethodSetting](#inputmethodgetinputmethodcontroller)回调获取到InputMethodSetting实例，再通过此实例调用对应方法。

### listInputMethod<sup>9+</sup>

listInputMethod(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

获取已激活/未激活输入法列表。使用callback异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                          |
| -------- | --------------------------------------------------- | ---- | ----------------------------- |
| enable   | boolean                                             | 是   | 值为true，表示获取已激活的输入法列表；值为false，表示获取未激活的输入法列表。 |
| callback | AsyncCallback&lt;Array&lt;[InputMethodProperty](#inputmethodproperty8)&gt;&gt; | 是   | 回调函数，返回已激活/未激活的输入法列表。 |

**示例：**

```js
inputMethodSetting.listInputMethod(true, (err,data) => {
    if (err) {
        console.error('Failed to list inputmethods: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in listing inputmethods.');
 });
```

### listInputMethod<sup>9+</sup>

listInputMethod(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

获取已激活/未激活输入法列表。使用Promise异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型    | 必填 | 说明                              |
| ------ | ------- | ---- | --------------------------------- |
| enable | boolean | 是   | 值为true，表示获取已激活的输入法列表；值为false，表示获取未激活的输入法列表。 |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回已激活/未激活的输入法列表。 |

**示例：**

```js
inputMethodSetting.listInputMethod(true).then((data) => {
    console.info('Succeeded in listing inputmethods.');
}).catch((err) => {
    console.error('Failed to list inputmethods: ' + JSON.stringify(err));
})
```

### listInputMethod

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

查询已安装的输入法列表。使用callback异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | 是   | 回调函数，返回已安装的输入法列表。 |

**示例：**

```js
inputMethodSetting.listInputMethod((err, data) => {
    if (err) {
        console.error('Failed to list inputmethods: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in listing inputmethods.');
 });
```

### listInputMethod

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

查询已安装的输入法列表。使用Promise异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise对象，返回已安装的输入法列表。 |

**示例：**

```js
inputMethodSetting.listInputMethod().then((data) => {
    console.info('Succeeded in listing inputmethod.');
}).catch((err) => {
    console.error('Failed to list inputmethod: ' + JSON.stringify(err));
})
```

### displayOptionalInputMethod

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

显示选择输入法弹窗。使用callback异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当选择输入法弹窗显示成功。err为undefined，否则为错误对象。 |

**示例：**

```js
inputMethodSetting.displayOptionalInputMethod((err) => {
    if (err) {
        console.error('Failed to display optional inputmethod: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in displaying optional inputmethod.');
});
```

### displayOptionalInputMethod

displayOptionalInputMethod(): Promise&lt;void&gt;

显示选择输入法弹窗。使用Promise异步回调。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
inputMethodSetting.displayOptionalInputMethod().then(() => {
    console.info('Succeeded in displaying optional inputmethod.');
}).catch((err) => {
    console.error('Failed to display optional inputmethod: ' + JSON.stringify(err));
})
```