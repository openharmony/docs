# FormExtensionContext

FormExtensionContext模块是FormExtension的上下文环境，继承自ExtensionContext。

FormExtensionContext模块提供FormExtension具有的接口和能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## 使用说明

在使用FormExtensionContext的功能前，需要通过FormExtension获取。

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import formBindingData from '@ohos.app.form.formBindingData';
export default class MyFormExtensionAbility extends FormExtensionAbility {
    onAddForm() {
        let formContext = this.context; // 获取FormExtensionContext
        // ...
        let dataObj1 = {
            temperature:'11c',
            'time':'11:00'
        };
        let obj1 = formBindingData.createFormBindingData(dataObj1);
        return obj1;
    }
}
```

## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

拉起一个卡片所属应用的Ability。使用callback异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.Form

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16500101 | The application is not a system application. |
| 16501000 | An internal functional error occurred. |
|以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。||

**参数：**

| 参数名 |                类型               | 必填 |              说明               |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-application-want.md) | 是  | 包含bundleName，abilityName以及用户自定参数用于拉起Ability。 |
| callback| AsyncCallback&lt;void&gt;       | 是  | 回调函数。当拉起一个卡片所属应用的Ability成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
let want = {
    deviceId: '',
    bundleName: 'com.example.formstartability',
    abilityName: 'MainAbility',
    action: 'action1',
    entities: ['entity1'],
    type: 'MIMETYPE',
    uri: 'key={true,true,false}',
    parameters: {}
};
this.context.startAbility(want, (error) => {
    if (error) {
      console.log('FormExtensionContext startAbility, error:' + JSON.stringify(error));
    } else {
      console.log(`FormExtensionContext startAbility success`);
    }
});
```

## startAbility

startAbility(want: Want): Promise&lt;void&gt;

拉起一个卡片所属应用的Ability。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 |                类型               | 必填 |              说明               |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-application-want.md) | 是  | 包含bundleName，abilityName以及用户自定参数用于拉起Ability。 |

**返回值：**

| 类型          | 说明                                |
| ------------ | ---------------------------------- |
| Promise&lt;void&lt; | 无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16500101 | The application is not a system application. |
| 16501000 | An internal functional error occurred. |
|以上错误码的详细介绍请参见[卡片错误码](../errorcodes/errorcode-form.md)。||

**示例：**

```ts
let want = {
    deviceId: '',
    bundleName: 'com.example.formstartability',
    abilityName: 'MainAbility',
    action: 'action1',
    entities: ['entity1'],
    type: 'MIMETYPE',
    uri: 'key={true,true,false}',
    parameters: {}
};
this.context.startAbility(want).then(() => {
    console.info('StartAbility Success');
}).catch((error) => {
    console.info('StartAbility failed');
});
```