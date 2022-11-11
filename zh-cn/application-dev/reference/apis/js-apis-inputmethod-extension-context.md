# InputMethodExtensionContext

InputMethodExtensionContext模块是InputMethodExtensionAbility的上下文环境，继承自ExtensionContext。

InputMethodExtensionContext模块提供InputMethodExtensionAbility具有的能力和接口，包括启动、停止、绑定、解绑Ability。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import InputMethodExtensionContext from '@ohos.inputmethodextensioncontext';
```

## 使用说明

在使用InputMethodExtensionContext的功能前，需要通过InputMethodExtensionAbility子类实例获取。

```ts
import InputMethodExtensionAbility from '@ohos.inputmethodextensionability';
class MainAbility extends InputMethodExtensionAbility {
    onCreate() {
        let context = this.context;
    }
}
```

## InputMethodExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

```ts
let want = {
    'bundleName': 'com.example.myapp',
    'abilityName': 'MyAbility'
};
this.context.startAbility(want, (err) => {
    console.log('startAbility result:' + JSON.stringify(err));
});
```

## InputMethodExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

启动Ability。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | 是 | 启动Ability的want信息。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 是 | 启动Ability所携带的参数。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

```ts
let want = {
    'deviceId': '',
  	'bundleName': 'com.extreme.test',
  	'abilityName': 'MainAbility'
};
let options = {
    windowMode: 0,
};
this.context.startAbility(want, options, (error) => {
    console.log('error.code = ' + error.code)
})
```

## InputMethodExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>

启动Ability。使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 |
| options | [StartOptions](js-apis-application-StartOptions.md) | 否 | 启动Ability所携带的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无结果的Promise对象。 |

**示例：**

```ts
let want = {
    'bundleName': 'com.example.myapp',
    'abilityName': 'MyAbility'
};
this.context.startAbility(want).then((data) => {
    console.log('success:' + JSON.stringify(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringify(error));
});
```

## InputMethodExtensionContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void

停止输入法应用自身。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```ts
this.context.terminateSelf((err) => {
    console.log('terminateSelf result:' + JSON.stringify(err));
});
```

## InputMethodExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;

停止输入法应用自身。使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
this.context.terminateSelf().then((data) => {
    console.log('success:' + JSON.stringify(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringify(error));
});
```