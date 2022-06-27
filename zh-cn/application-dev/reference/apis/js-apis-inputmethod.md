# 输入法框架

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import inputMethod from '@ohos.inputMethod';
```

## inputMethod<sup>8+</sup>

常量值。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Miscservices.InputMethodFramework

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM | number | 是 | 否 | 可支持的最大输入法个数。 |


## InputMethodProperty<sup>8+</sup>

输入法应用属性。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Miscservices.InputMethodFramework

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| packageName | string | 是 | 否 | 包名。 |
| methodId | string | 是 | 否 | Ability名。 |

## inputMethod.getInputMethodController

getInputMethodController(): InputMethodController

获取客户端实例[InputMethodController](#InputMethodController)。

**系统能力**：SystemCapability.Miscservices.InputMethodFramework

**返回值：**

    | 类型 | 说明 |
    | -------- | -------- |
    | [InputMethodController](#InputMethodController) | 回调返回当前客户端实例。 |

**示例：**
  
```js
  var InputMethodController = inputMethod.getInputMethodController();
```
## inputMethod.getInputMethodSetting<sup>8+</sup>

getInputMethodSetting(): InputMethodSetting

获取客户端设置实例[InputMethodSetting](#InputMethodSetting)。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**返回值：**

  | 类型                                      | 说明                         |
  | ----------------------------------------- | ---------------------------- |
  | [InputMethodSetting](#InputMethodSetting) | 回调返回当前客户端设置实例。 |


**示例：**

```js
  var InputMethodSetting = inputMethod.getInputMethodSetting();
```

## InputMethodController

下列API示例中都需使用[getInputMethodController](#getInputMethodController)回调获取到InputMethodController实例，再通过此实例调用对应方法。

### stopInput

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

隐藏输入法。

**系统能力**：SystemCapability.Miscservices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 返回输入法隐藏是否成功。 |

**示例：**

```js
  InputMethodController.stopInput((error)=>{
     console.info('stopInput');
 });
```

### stopInput

stopInput(): Promise&lt;boolean&gt;

隐藏输入法。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回输入法隐藏是否成功。 |

**示例：**

```js
  var isSuccess = InputMethodController.stopInput();
  console.info('stopInput isSuccess = ' + isSuccess);
```

## InputMethodSetting<sup>8+</sup>

下列API示例中都需使用[getInputMethodSetting](#getInputMethodSetting)回调获取到InputMethodSetting实例，再通过此实例调用对应方法。

### listInputMethod

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

查询已安装的输入法列表。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**
  | 参数名   | 类型                                               | 必填 | 说明                   |
  | -------- | -------------------------------------------------- | ---- | ---------------------- |
  | callback | Array<[InputMethodProperty](#InputMethodProperty)> | 是   | 返回已安装输入法列表。 |

**示例：**

```js
  InputMethodSetting.listInputMethod((properties)=>{
    for (var i = 0;i < properties.length; i++) {
      var property = properties[i];
      console.info(property.packageName + "/" + property.methodId);
    }
 });
```

### listInputMethod

listInputMethod(): Array&lt;InputMethodProperty&gt;

查询已安装的输入法列表。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**返回值：**
  | 类型                                                        | 说明                   |
  | ----------------------------------------------------------- | ---------------------- |
  | Promise<Array<[InputMethodProperty](#InputMethodProperty)>> | 返回已安装输入法列表。 |

**示例：**
  
```js
   var properties = InputMethodSetting.listInputMethod();
   for (var i = 0;i < properties.length; i++) {
     var property = properties[i];
     console.info(property.packageName + "/" + property.methodId);
   }
```

### displayOptionalInputMethod

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

显示输入法选择对话框。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

```js
  InputMethodSetting.displayOptionalInputMethod(()=>{
    console.info('displayOptionalInputMethod is called');
  });
```

### displayOptionalInputMethod

  displayOptionalInputMethod(): Promise&lt;void&gt;

  显示输入法选择对话框。

  **系统能力**： SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 回调函数。 |

**示例：**
    
```js
  InputMethodSetting.displayOptionalInputMethod();
```