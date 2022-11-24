# 输入法框架

本模块提供对输入法框架的管理，包括隐藏输入法、查询已安装的输入法列表和拉起选择输入法弹窗。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import inputMethod from '@ohos.inputmethod';
```

## 常量

常量值。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

| 名称 | 参数类型 | 常量值 | 说明 |
| -------- | -------- | ---------- | -------- |
| MAX_TYPE_NUM | number | 128 | 可支持的最大输入法个数。 |

## InputMethodProperty

输入法应用属性。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| packageName | string | 是 | 否 | 输入法包名。 |
| methodId | string | 是 | 否 | 输入法唯一标识。 |

## inputMethod.getInputMethodController

getInputMethodController(): InputMethodController

获取客户端实例[InputMethodController](#inputmethodcontroller)。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [InputMethodController](#inputmethodcontroller) | 返回当前客户端实例。 |

**示例：**

```js
let inputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting

getInputMethodSetting(): InputMethodSetting

获取客户端设置实例[InputMethodSetting](#inputmethodsetting)。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型                                      | 说明                     |
| ----------------------------------------- | ------------------------ |
| [InputMethodSetting](#inputmethodsetting) | 返回当前客户端设置实例。 |

**示例：**

```js
let inputMethodSetting = inputMethod.getInputMethodSetting();
```

## InputMethodController

下列API示例中都需使用[getInputMethodController](#inputmethodgetinputmethodcontroller)回调获取到InputMethodController实例，再通过此实例调用对应方法。

### stopInput

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

结束输入法会话。使用callback异步回调。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，返回结束输入法会话是否成功的结果。true表示结束输入法会话成功；false表示结束输入法会话失败。 |

**示例：**

```js
inputMethodController.stopInput((error, result) => {
    if (error) {
        console.error('Failed to stop inputmethod session: ' + JSON.stringify(error));
        return;
    }
    if (result) {
        console.info('Succeeded in stopping inputmethod session.');
    } else {
        console.error('Failed to stop inputmethod session.');
    }
});
```

### stopInput

stopInput(): Promise&lt;boolean&gt;

结束输入法会话。使用Promise异步回调。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象，返回结束输入法会话是否成功的结果。true表示结束输入法会话成功；false表示结束输入法会话失败。 |

**示例：**

```js
inputMethodController.stopInput().then((result) => {
    if (result) {
        console.info('Succeeded in stopping inputmethod session.');
    } else {
        console.error('Failed to stop inputmethod session');
    }
})
```

## InputMethodSetting

下列API示例中都需使用[getInputMethodSetting](#inputmethodgetinputmethodsetting)回调获取到InputMethodSetting实例，再通过此实例调用对应方法。

### listInputMethod

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

查询已安装的输入法列表。使用callback异步回调。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                   |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | Array<[InputMethodProperty](#inputmethodproperty)> | 是   | 回调函数，返回已安装的输入法列表。 |

**示例：**

```js
inputMethodSetting.listInputMethod((err, data) => {
    if(err) {
        console.error('Failed to list inputmethods: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in listing inputmethods, data: ' + JSON.stringify(data));
 });
```

### listInputMethod

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

查询已安装的输入法列表。使用Promise异步回调。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型                                                        | 说明                   |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty)>> | Promise对象，返回已安装的输入法列表。|

**示例：**

```js
inputMethodSetting.listInputMethod().then((data) => {
    console.info('Succeeded in listing inputMethod.');
}).catch((err) => {
    console.error('Failed to list inputMethod: ' + JSON.stringify(err));
})
```

### displayOptionalInputMethod

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

显示选择输入法弹窗。使用callback异步回调。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当选择输入法弹窗显示成功。err为undefined，否则为错误对象。 |

**示例：**

```js
inputMethodSetting.displayOptionalInputMethod((err) => {
    if (err) {
        console.error('Failed to display optionalInputMethod:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in displaying optionalInputMethod.');
});
```

### displayOptionalInputMethod

displayOptionalInputMethod(): Promise&lt;void&gt;

显示选择输入法弹窗。使用Promise异步回调。

**系统能力：** SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
inputMethodSetting.displayOptionalInputMethod().then(() => {
    console.info('Succeeded in displaying optionalInputMethod.');
}).catch((err) => {
    console.error('Failed to display optionalInputMethod: ' + JSON.stringify(err));
})
```