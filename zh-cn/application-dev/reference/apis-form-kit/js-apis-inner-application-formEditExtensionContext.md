# FormEditExtensionContext

FormEditExtensionContext是[FormEditExtensionAbility](./js-apis-app-form-formEditExtensionAbility.md)的上下文，继承自[UIExtensionContext](../apis-ability-kit/js-apis-inner-application-uiExtensionContext.md)。

FormEditExtensionContext提供允许访问特定于FormEditExtensionAbility资源的能力。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块
```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
```
## FormEditExtensionContext.startSecondPage

startSecondPage(want: Want): Promise<[AbilityResult](../apis-ability-kit/js-apis-inner-ability-abilityResult.md)>

拉起需要被编辑的卡片提供方页面。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | want  |  [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | 是   | 第三方应用需要被桌面拉起的编辑页面信息。|

**返回值：**  
  | 类型 | 说明    | 
  | ------ | ------ |
  | Promise<[AbilityResult](../apis-ability-kit/js-apis-inner-ability-abilityResult.md)>  |  Promise对象，返回AbilityResult。  | 

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | An IPC connection error happened.                            |
| 16501000 | An internal functional error occurred.                       |
| 16500100 | Failed to obtain the configuration information.                        |

**示例：**

```ts
import { FormEditExtensionAbility } from '@kit.FormKit'
import { Want,UIExtensionContentSession } from '@kit.AbilityKit';

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
        console.log(TAG, `startSecondPage result want: ${JSON.stringify(data)}`)
      });
    } catch (e) {
      console.error(TAG, `startSecondPage failed:${e}`)
      return
    }
  }
}

```