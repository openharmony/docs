# FormEditExtensionContext

**FormEditExtensionContext**, inherited from [UIExtensionContext](../apis-ability-kit/js-apis-inner-application-uiExtensionContext.md), is the context of [FormEditExtensionAbility](./js-apis-app-form-formEditExtensionAbility.md).

You can use **FormEditExtensionContext** to access specific **FormEditExtensionAbility** resources.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import
```ts
import { FormEditExtensionAbility } from '@kit.FormKit';
```
## startSecondPage

startSecondPage(want: Want): Promise<[AbilityResult](../apis-ability-kit/js-apis-inner-ability-abilityResult.md)>

Starts the widget provider page to be edited.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.Form

**Parameters**

  | Name| Type   | Mandatory| Description                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | want  |  [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | Yes  | Information about the editing page that needs to be started by the home screen of a third-party application.|

**Return value** 
  | Type| Description   | 
  | ------ | ------ |
  | Promise<[AbilityResult](../apis-ability-kit/js-apis-inner-ability-abilityResult.md)>  |  Promise used to return the ability result. | 

**Error codes**

For details about the error codes, see [Form Error Codes](errorcode-form.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | The application is not a system application.                 |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16500050 | An IPC connection error happened.                            |
| 16501000 | An internal functional error occurred.                       |
| 16500100 | Failed to obtain the configuration information.                        |

**Example**

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
