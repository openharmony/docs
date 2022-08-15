# FormExtensionContext

FormExtensionContext模块是FormExtension的上下文环境，继承自ExtensionContext。

FormExtensionContext模块提供FormExtension具有的接口和能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 使用说明

在使用FormExtensionContext的功能前，需要通过FormExtension获取。
```js
import FormExtension from '@ohos.application.FormExtension';
import formBindingData from '@ohos.application.formBindingData'
export default class MyFormExtension extends FormExtension {
    onCreate() {
        let dataObj1 = {
            temperature:"11c",
            "time":"11:00"
        };
        let obj1 = formBindingData.createFormBindingData(dataObj1);
        return obj1;
    }
}

```

## FormExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

拉起一个卡片所属应用的Ability。

**系统能力**：SystemCapability.Ability.Form

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 |                类型               | 必填 |              说明               |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-application-Want.md) | 是  | 包含bundleName，abilityName以及用户自定参数用于拉起Ability。 |
| callback| AsyncCallback&lt;void&gt;       | 是  | 回调函数，返回接口调用是否成功的结果。 |

**示例：**

```js
var want = {
    deviceId: "",
    bundleName: "com.example.formstartability",
    abilityName: "MainAbility",
    action: "action1",
    entities: ["entity1"],
    type: "MIMETYPE",
    uri: "key={true,true,false}",
    parameters: {}
}
this.context.startAbility(want, function(err) {
    console.info(err.code);
})
```

## FormExtensionContext.startAbility

startAbility(want: Want): Promise&lt;void&gt;

拉起一个卡片所属应用的Ability。

**系统能力**：SystemCapability.Ability.Form

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 |                类型               | 必填 |              说明               |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-application-Want.md) | 是  | 包含bundleName，abilityName以及用户自定参数用于拉起Ability。 |

**返回值：**

| 类型          | 说明                                |
| ------------ | ---------------------------------- |
| Promise&lt;void&lt; | Promise实例，返回接口调用是否成功的结果。 |

**示例：**

```js
var want = {
    deviceId: "",
    bundleName: "com.example.formstartability",
    abilityName: "MainAbility",
    action: "action1",
    entities: ["entity1"],
    type: "MIMETYPE",
    uri: "key={true,true,false}",
    parameters: {}
}
this.context.startAbility(want).then(() => {
    console.info("StartAbility Success");
}).catch((error) => {
    console.info("StartAbility failed");
});
```