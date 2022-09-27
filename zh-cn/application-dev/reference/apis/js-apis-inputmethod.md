# 输入法框架

本模块提供对输入法框架的管理，包括隐藏输入法、查询已安装的输入法列表和显示输入法选择对话框。

>  **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import inputMethod from '@ohos.inputmethod';
```

## inputMethod<sup>8+</sup>

常量值。

**系统能力**：以下各项对应的系统能力均为SystemCapability.MiscServices.InputMethodFramework

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM | number | 是 | 否 | 可支持的最大输入法个数。 |


## InputMethodProperty<sup>8+</sup>

输入法应用属性。

**系统能力**：以下各项对应的系统能力均为SystemCapability.MiscServices.InputMethodFramework

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| packageName | string | 是 | 否 | 包名。 |
| methodId | string | 是 | 否 | Ability名。 |

## inputMethod.getInputMethodController

getInputMethodController(): InputMethodController

获取客户端实例[InputMethodController](#inputmethodcontroller)。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                            | 说明                     |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | 回调返回当前客户端实例。 |

**示例：**

```js
  var InputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting<sup>8+</sup>

getInputMethodSetting(): InputMethodSetting

获取客户端设置实例[InputMethodSetting](#inputmethodsetting8)。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明                         |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | 回调返回当前客户端设置实例。 |


**示例：**

```js
  var InputMethodSetting = inputMethod.getInputMethodSetting();
```
## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty, callback: AsyncCallback&lt;boolean&gt;): void

切换输入法。此接口仅可在Stage模型下使用。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  |target | [InputmethodProperty](#inputmethodproperty8) | 是 | 传入要切换的目标输入法。 |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 返回输入法切换是否成功。 |


**示例：**

```js
inputMethod.switchInputMethod({packageName:'com.example.kikakeyboard', methodId:'com.example.kikakeyboard'} ,(err,result) => {
    if (err) {
        console.error('switchInputMethod err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to switchInputMethod.(callback)');
    } else {
        console.error('Failed to switchInputMethod.(callback)');
    }
});
```
## inputMethod.switchInputMethod<sup>9+</sup>
switchInputMethod(target: InputMethodProperty): Promise&lt;boolean&gt;

切换输入法。此接口仅可在Stage模型下使用。使用promise形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  |target |  [InputmethodProperty](#inputmethodproperty8)| 是 | 传入要切换的目标输入法。 |

**返回值：**

  | 类型                                      | 说明                         |
  | ----------------------------------------- | ---------------------------- |
  | Promise\<boolean> | 回调返回切换后的输入法。 |

**示例：**


```js
inputMethod.switchInputMethod({packageName:'com.example.kikakeyboard', methodId:'com.example.kikakeyboard'}).then((result) => {
    if (result) {
        console.info('Success to switchInputMethod.(promise)');
    } else {
        console.error('Failed to switchInputMethod.(promise)');
    }
}).catch((err) => {
    console.error('switchInputMethod promise err: ' + err);
})
```
## inputMethod.getCurrentInputMethod<sup>9+</sup>

getCurrentInputMethod(): InputMethodProperty

获取当前输入法扩展应用，提供同步接口，返回当前输入法属性对象。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                         | 说明                     |
| -------------------------------------------- | ------------------------ |
| [InputmethodProperty](#inputmethodproperty8) | 返回当前输入法属性对象。 |

**示例：**


```js
var currentIme = inputMethod.getCurrentInputMethod();
```

## InputMethodController

下列API示例中都需使用[getInputMethodController](#inputmethodgetinputmethodcontroller)回调获取到InputMethodController实例，再通过此实例调用对应方法。

### stopInput

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

隐藏输入法。使用callback形式返回结果。参数个数为1，否则抛出异常。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 返回输入法隐藏是否成功。 |

**示例：**

```js
InputMethodController.stopInput((error, result) => {
    if (error) {
        console.error('failed to stopInput because: ' + JSON.stringify(error));
        return;
    }
    if (result) {
        console.info('Success to stopInput.(callback)');
    } else {
        console.error('Failed to stopInput.(callback)');
    }
});
```

### stopInput

stopInput(): Promise&lt;boolean&gt;

隐藏输入法。使用promise形式返回结果。参数个数为0，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | 返回输入法隐藏是否成功。 |

**示例：**


```js
InputMethodController.stopInput().then((result) => {
    if (result) {
        console.info('Success to stopInput.(promise)');
    } else {
        console.error('Failed to stopInput.(promise)');
    }
}).catch((err) => {
    console.error('stopInput promise err: ' + err);
})
```

### showSoftKeyboard<sup>9+</sup> ###

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

显示软键盘，使用callback异步回调。参数个数为1，否则抛出异常。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 参数类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
InputMethodController.showSoftKeyboard((err) => {
    if (err === undefined) {
        console.info('showSoftKeyboard success');
    } else {
        console.error('showSoftKeyboard failed because : ' + JSON.stringify(err));
    }
})
```


### showSoftKeyboard<sup>9+</sup> ###

showSoftKeyboard(): Promise&lt;void&gt;

显示软键盘，使用Promise异步回调。参数个数为0，否则抛出异常。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
InputMethodController.showSoftKeyboard().then(async (err) => {
    console.log('showSoftKeyboard success');
}).catch((err) => {
    console.error('showSoftKeyboard promise err: ' + JSON.stringify(err));
});
```

### hideSoftKeyboard<sup>9+</sup> ###

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏软键盘，使用callback异步回调。参数个数为1，否则抛出异常。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 参数类型                  | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
InputMethodController.hideSoftKeyboard((err) => {
    if (err === undefined) {
        console.info('hideSoftKeyboard success');
    } else {
        console.error('hideSoftKeyboard failed because : ' + JSON.stringify(err));
    }
})
```


### hideSoftKeyboard<sup>9+</sup> ###

hideSoftKeyboard(): Promise&lt;void&gt;

隐藏软键盘，使用Promise异步回调。参数个数为0，否则抛出异常。

**系统能力：**  SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
InputMethodController.hideSoftKeyboard().then(async (err) => {
    console.log('hideSoftKeyboard success');
}).catch((err) => {
    console.error('hideSoftKeyboard promise err: ' + JSON.stringify(err));
});
```

## InputMethodSetting<sup>8+</sup>

下列API示例中都需使用[getInputMethodSetting](#inputmethodgetinputmethodcontroller)回调获取到InputMethodSetting实例，再通过此实例调用对应方法。

### listInputMethod<sup>9+</sup>

listInputMethod(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

获取已激活/未激活输入法列表。参数enable取true，返回已激活输入法列表，取false返回未激活输入法列表。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                          |
| -------- | --------------------------------------------------- | ---- | ----------------------------- |
| enable   | boolean                                             | 是   | 指定返回已激活/未激活。       |
| callback | Array<[InputMethodProperty](#inputmethodproperty8)> | 是   | 返回已激活/未激活输入法列表。 |

**示例：**

```js
imeList: Array<inputMethod.InputMethodProperty> = null
InputMethodSetting.listInputMethod(true, (err,data) => {
    if (err) {
        console.error('listInputMethod failed because: ' + JSON.stringify(err));
        return;
    }
    console.log('listInputMethod success');
    this.imeList = data;
 });
```

### listInputMethod<sup>9+</sup>

listInputMethod(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

获取已激活/未激活输入法列表。参数enable取true返回已激活输入法列表，取false返回未激活输入法列表。使用promise形式返回结果。参数个数为0，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型    | 必填 | 说明                    |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | 是   | 指定返回已激活/未激活。 |

**返回值：**

| 类型                                                         | 说明                          |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | 返回已激活/未激活输入法列表。 |

**示例：**

```js
imeList: Array<inputMethod.InputMethodProperty> = null
InputMethodSetting.listInputMethod(true).then((data) => {
    console.info('listInputMethod success');
    this.imeList = data;
}).catch((err) => {
    console.error('listInputMethod promise err: ' + err);
})
```

### listInputMethod

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

查询已安装的输入法列表。使用callback形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | Array<[InputMethodProperty](#inputmethodproperty8)> | 是   | 返回已安装输入法列表。 |

**示例：**

```js
imeList: Array<inputMethod.InputMethodProperty> = null
InputMethodSetting.listInputMethod((err,data) => {
    if (err) {
        console.error('listInputMethod failed because: ' + JSON.stringify(err));
        return;
    }
    console.log('listInputMethod success');
    this.imeList = data;
 });
```

### listInputMethod

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

查询已安装的输入法列表。使用promise形式返回结果。参数个数为0，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | 返回已安装输入法列表。 |

**示例：**

```js
imeList: Array<inputMethod.InputMethodProperty> = null
InputMethodSetting.listInputMethod().then((data) => {
    console.info('listInputMethod success');
    this.imeList = data;
}).catch((err) => {
    console.error('listInputMethod promise err: ' + err);
})
```

### displayOptionalInputMethod

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

显示输入法选择对话框。使用callback形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

```js
InputMethodSetting.displayOptionalInputMethod((err) => {
    if (err) {
        console.error('displayOptionalInputMethod failed because: ' + JSON.stringify(err));
        return;
    }
    console.info('displayOptionalInputMethod success');
});
```

### displayOptionalInputMethod

  displayOptionalInputMethod(): Promise&lt;void&gt;

  显示输入法选择对话框。使用promise形式返回结果。参数个数为0，否则抛出异常。

  **系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
InputMethodSetting.displayOptionalInputMethod().then(() => {
    console.info('displayOptionalInputMethod success.(promise)');
}).catch((err) => {
    console.error('displayOptionalInputMethod promise err: ' + err);
})
```