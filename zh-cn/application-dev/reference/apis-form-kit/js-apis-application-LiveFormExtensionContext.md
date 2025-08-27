# LiveFormExtensionContext
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--Designer: @xueyulong-->
<!--Tester: @chenmingze-->
<!--Adviser: @Brilliantry_Rui-->
LiveFormExtensionContext是[LiveFormExtensionAbility](./js-apis-app-form-LiveFormExtensionAbility.md)的上下文，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块
```ts
import { LiveFormExtensionAbility } from '@kit.FormKit';
```

## LiveFormExtensionContext

LiveFormExtensionContext提供允许访问特定于LiveFormExtensionAbility资源的能力，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。

### startAbilityByLiveForm

startAbilityByLiveForm(want: Want): Promise&lt;void&gt;

拉起互动卡片提供方（应用）的页面，使用Promise异步回调。

该接口仅支持拉起互动卡片提供方（应用）的页面，不支持拉起其他应用的页面，否则会抛出错误码16501011。

该接口建议在点击事件回调中调用，不建议在其他手势事件回调中调用，不支持非手势事件直接调用，否则会抛出错误码16501011。

另外，在点击事件回调中，支持直接调用，不支持延时后调用，否则会抛出错误码16501011。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

  | 参数名 | 类型    | 必填 | 说明                                   |
  | ------ | ------ | ---- | ------------------------------------- |
  | want  |  [Want](../apis-ability-kit/js-apis-app-ability-want.md)  | 是   | 需要被拉起的应用页面信息。[仅支持使用显式want。](../../../application-dev/application-models/ability-startup-with-explicit-want.md) |

**返回值：**  
  | 类型 | 说明    |
  | ------ | ------ |
  | Promise&lt;void&gt;  |  Promise对象，无返回结果。  | 

**错误码：**

以下错误码的详细介绍请参见[卡片错误码](errorcode-form.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported due to limited device capabilities.                 |
| 16500050 | An IPC connection error happened.                            |
| 16500100 | Failed to obtain the configuration information.                        |
| 16501000 | An internal functional error occurred.                       |
| 16501011 | The form can not support this operation.                       |

**示例：**

```ts
// MyLiveFormExtensionAbility.ets
import { formInfo, LiveFormInfo, LiveFormExtensionAbility } from '@kit.FormKit';
import { UIExtensionContentSession } from '@kit.AbilityKit';

export default class MyLiveFormExtensionAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession) {
    // 1.将LiveFormExtensionContext传给互动卡片的页面组件
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('context', this.context);
    session.loadContent('pages/MyLiveFormPage', storage);
  }
};
```
```ts
// pages/MyLiveFormPage.ets
import { BusinessError } from '@kit.BasicServicesKit';
import LiveFormExtensionContext from 'application/LiveFormExtensionContext';

@Entry
@Component
struct MyLiveFormPage {
  private storageForMyLiveFormPage: LocalStorage | undefined = undefined;
  private liveFormContext: LiveFormExtensionContext | undefined = undefined;

  aboutToAppear(): void {
    // 2.获取LiveFormExtensionContext
    this.storageForMyLiveFormPage = this.getUIContext().getSharedLocalStorage();
    this.liveFormContext = this.storageForMyLiveFormPage?.get<LiveFormExtensionContext>('context');
  }

   private startAbilityByLiveForm(): void {
    try {
      // 请开发者替换为实际的want信息
      this.liveFormContext?.startAbilityByLiveForm({
        bundleName: 'com.example.liveformdemo',
        abilityName: 'EntryAbility',
      })
        .then(() => {
          console.info('startAbilityByLiveForm succeed');
        })
        .catch((err: BusinessError) => {
          console.error(`startAbilityByLiveForm failed, code is ${err?.code}, message is ${err?.message}`);
        });
    } catch (e) {
      console.error(`startAbilityByLiveForm failed, code is ${e?.code}, message is ${e?.message}`);
    }
  }

  build() {
    Stack() {
      // 请开发者替换为实际的页面
    }
    .onClick(() => {
      // 3.在点击事件回调中直接使用该接口
      console.info('MyLiveFormPage click to start ability');
      if (!this.liveFormContext) {
        console.info('MyLiveFormPage liveFormContext is empty');
        return;
      }
      this.startAbilityByLiveForm();
    })
  }
}
```