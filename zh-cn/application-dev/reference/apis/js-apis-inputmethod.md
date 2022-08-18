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

switchInputMethod(target: InputmethodProperty, callback: AsyncCallback&lt;boolean&gt;): void;

切换输入法。此接口仅可在Stage模型下使用。使用callback形式返回结果。参数个数为2，否则抛出异常。


**系统能力**：SystemCapability.Miscservices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  |target | [InputmethodProperty](#inputmethodproperty8) | 是 | 传入要切换的目标输入法。 |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 返回输入法切换是否成功。 |


**示例：**

```js
  inputMethod.switchInputMethod({packageName:"com.ohos.inputApp", methodId:"InputDemoService"}).then(res => {
     prompt.showToast({message:"切换输入法成功" + this.imeList[this.flag].packageName, duration: 200});
 });
```
## inputMethod.switchInputMethod<sup>9+</sup>
switchInputMethod(target: InputmethodProperty): Promise&lt;boolean&gt;

切换输入法。此接口仅可在Stage模型下使用。使用promise形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

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
  inputMethod.switchInputMethod({packageName:"com.ohos.inputApp", methodId:"InputDemoService"}).then(res => {
     prompt.showToast({message:"切换输入法成功" + this.imeList[this.flag].packageName, duration: 200});
 });
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
inputMethodController.stopInput((err, result) => {
    if (err == undefined) {
        console.error("stopInput callback result---err: " + err.msg);
        return;
    }
    if (result) {
        console.info("Success to stopInput.(callback)");
    } else {
        console.info("Failed to stopInput.(callback)");
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
await inputMethodController.stopInput().then((result)=>{
    if (result) {
        console.info("Success to stopInput.(promise)");
    } else {
        console.info("Failed to stopInput.(promise)");
    }
}).catch((err) => {
    console.error("stopInput promise err: " + err.msg);
});
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
    if (err == undefined) {
        console.error('showSoftKeyboard success');
    } else {
        console.info('showSoftKeyboard failed : ' + JSON.stringify(err));
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
    console.log('showSoftKeyboard fail ' + JSON.stringify(err));
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
    if (err == undefined) {
        console.error('hideSoftKeyboard success');
    } else {
        console.info('hideSoftKeyboard failed : ' + JSON.stringify(err));
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
    console.log('hideSoftKeyboard fail ' + JSON.stringify(err));
});
```

## InputMethodSetting<sup>8+</sup>

下列API示例中都需使用[getInputMethodSetting](#inputmethodgetinputmethodcontroller)回调获取到InputMethodSetting实例，再通过此实例调用对应方法。

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
inputMethodSetting.listInputMethod((err,data) => {
    if (err == undefined) {
        console.error("listInputMethod callback result---err: " + err.msg);
        return;
    }
    console.info("listInputMethod callback result---data: " + JSON.stringify(data));
 });
```

### listInputMethod

listInputMethod(): Promise<Array<InputMethodProperty>>;

查询已安装的输入法列表。使用promise形式返回结果。参数个数为0，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**
| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | 返回已安装输入法列表。 |

**示例：**

```js
await inputMethodSetting.listInputMethod().then((data)=>{
    console.info("listInputMethod promise result---data: " + JSON.stringify(data));
}).catch((err) => {
    console.info("listInputMethod promise err:" + err.msg);
});
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
inputMethodSetting.displayOptionalInputMethod((err) => {
    if (err == undefined) {
        console.error("displayOptionalInputMethod callback---err: " + err.msg);
        return;
    }
    console.info("displayOptionalInputMethod callback");
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
await inputMethodSetting.displayOptionalInputMethod().then(()=>{
    console.info("displayOptionalInputMethod promise");
}).catch((err) => {
    console.info("listInputMethod promise err: " + err.msg);
});
```