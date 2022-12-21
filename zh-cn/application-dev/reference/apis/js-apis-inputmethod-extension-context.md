# @ohos.inputmethodextensioncontext (InputMethodExtensionContext)

InputMethodExtensionContext模块是InputMethodExtensionAbility的上下文环境，继承自ExtensionContext。

InputMethodExtensionContext模块提供InputMethodExtensionAbility具有的能力和接口，包括启动、停止、绑定、解绑Ability。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```
import InputMethodExtensionContext from '@ohos.inputmethodextensioncontext';
```

## 使用说明

在使用InputMethodExtensionContext的功能前，需要通过InputMethodExtensionAbility子类实例获取。

```js
import InputMethodExtensionAbility from '@ohos.inputmethodextensionability';
class MainAbility extends InputMethodExtensionAbility {
    onCreate() {
        let context = this.context;
    }
}
```

## InputMethodExtensionContext.destroy

destroy(callback: AsyncCallback\<void>): void

停止输入法应用自身。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当停止输入法应用自身成功时，err为undefined；否则为错误对象。 |

**示例：**

```js
this.context.destroy((err) => {
    console.log('destroy result:' + JSON.stringify(err));
});
```

## InputMethodExtensionContext.destroy

destroy(): Promise<void&gt;

停止输入法应用自身。通过Promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
this.context.destroy().then((data) => {
    console.log('success:' + JSON.stringify(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringify(error));
});
```