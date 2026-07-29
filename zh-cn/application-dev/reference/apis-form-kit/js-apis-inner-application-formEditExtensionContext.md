# FormEditExtensionContext
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->

FormEditExtensionContext是[FormEditExtensionAbility](./js-apis-app-form-formEditExtensionAbility.md)的上下文，继承自[UIExtensionContext](../apis-ability-kit/js-apis-inner-application-uiExtensionContext.md)。用于管理卡片编辑场景的上下文环境，支持拉起卡片提供方页面和所属应用UIAbility，适用于卡片编辑流程中需要与卡片提供方交互的场景。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块
```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
```

## FormEditExtensionContext

FormEditExtensionContext提供允许访问特定于FormEditExtensionAbility资源的能力，

### startSecondPage

startSecondPage(want: Want): Promise&lt;[AbilityResult](../apis-ability-kit/js-apis-inner-ability-abilityResult.md)&gt;

拉起需要被编辑的卡片提供方页面。使用Promise异步回调。

**使用场景：**
- 用户在卡片编辑界面点击编辑按钮，需要打开卡片提供方的编辑页面
- 用户需要修改卡片配置或内容时，拉起卡片提供方应用进行编辑

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明                                   |
| ------ | ------ | ---- | ------------------------------------- |
| want  |  [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | 是   | 需要拉起的编辑页面信息。必须包含bundleName字段，且parameters中需包含secPageAbilityName。|

 **返回值：**

| 类型 | 说明    |
| ------ | ------ |
| Promise&lt;[AbilityResult](../apis-ability-kit/js-apis-inner-ability-abilityResult.md)&gt;  |  Promise对象，返回被启动方退出时的结果码和数据。  |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                 |
| 16500050 | An IPC connection error happened.                            |
| 16501000 | An internal functional error occurred.                       |
| 16500100 | Failed to obtain the configuration information.                        |

**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
import { UIExtensionContentSession, Want } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExampleFormEditExtensionAbility'

export default class ExampleFormEditAbility extends FormEditExtensionAbility {
  abilityName: string = 'FormEditSecPageAbility'

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    try {
      this.context.startSecondPage({
        bundleName: 'com.example.formEditDemo',
        parameters: {
          "secPageAbilityName": this.abilityName
        }

      }).then(data => {
        console.info(TAG, `startSecondPage result want: ${data.resultCode}`)
      });
    } catch (e) {
      console.error(TAG, `startSecondPage failed, code: ${e.code}, message: ${e.message}`)
      return
    }
  }
}
```

### startUIAbility<sup>23+</sup>

startUIAbility(want: Want): Promise&lt;void&gt;

拉起卡片所属应用的UIAbility。使用Promise异步回调。说明：需在卡片编辑页面处于前台时调用，页面不在前台时调用将返回错误码16501014。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型    | 必填 | 说明                                   |
| ------ | ------ | ---- | ------------------------------------- |
| want  |  [Want](../apis-ability-kit/js-apis-app-ability-want.md#want)  | 是   | 用于指定要拉起的UIAbility的Want信息。必须包含abilityName字段。|

**返回值：**

| 类型 | 说明    |
| ------ | ------ |
| Promise&lt;void&gt;   |  Promise对象，无返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 16500050 | An IPC connection error happened.                            |
| 16500100 | Failed to obtain the configuration information.                        |
| 16000130 | The target UIAbility does not belong to the caller.                       |
| 16501014 | The form edit page is not in the foreground. The current operation is not supported. |
| 16000121 | The target component type is not a UIAbility.                       |

**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit'
import { Want, UIExtensionContentSession } from '@kit.AbilityKit';

const TAG: string = '[testTag] ExampleFormEditExtensionAbility'

export default class ExampleFormEditAbility extends FormEditExtensionAbility {
  abilityName: string = 'FormEditSecPageAbility'

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    try {
      this.context.startUIAbility({
        abilityName: 'EntryAbility1',
      }).then(() => {
        console.info(TAG, `startUIAbility success`);
      });
    } catch (e) {
      console.error(TAG, `startUIAbility failed, code: ${e.code}, message: ${e.message}`);
      return
    }
  }
}
```