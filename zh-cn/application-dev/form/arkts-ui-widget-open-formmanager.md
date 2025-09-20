# 应用内拉起卡片管理加桌
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--Designer: @xueyulong-->
<!--Tester: @chenmingze-->
<!--Adviser: @Brilliantry_Rui-->

从API version 18开始，Form Kit提供在应用内将ArkTS卡片添加到桌面的能力，以方便用户后续便捷查看信息或快速进入应用。

## 开发步骤
下面给出示例，实现如下功能：在应用内点击“添加卡片到桌面”按钮，拉起卡片管理页面。用户可在卡片管理页面，点击“添加至桌面”按钮，此时在桌面即可看到新添加的卡片。
1. [创建卡片](./arkts-ui-widget-creation.md)。
2. 通过[openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18)方法在应用内添加拉起卡片管理页面入口。
```ts
// entry/src/main/ets/pages/Index.ets
import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';
import { promptAction } from '@kit.ArkUI';

@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
        // 添加拉起卡片管理页面按钮
        Button($r('app.string.open_form_manager_button'))
          .onClick(() => {
            const want: Want = {
              bundleName: "com.example.openmanager",
              abilityName: 'EntryFormAbility',
              parameters: {
                'ohos.extra.param.key.form_dimension': 2,
                'ohos.extra.param.key.form_name': 'widget',
                'ohos.extra.param.key.module_name': 'entry'
              },
            };
            try {
              // 点击按钮后调用openFormManager方法，拉起卡片管理页面
              formProvider.openFormManager(want);
            } catch (error) {
              promptAction.openToast({message: (error as BusinessError).message});
              console.error(`catch error, code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message})`);
            }
          })
          .margin({ top: 10, bottom: 10 })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
资源文件如下：
```json
// entry/src/main/resources/base/element/string.json
{
  "string": [
    {
      "name": "open_form_manager_button",
      "value": "添加应用卡片到桌面"
    }
  ]
}
```
3. 用户可在卡片管理页面，点击“添加至桌面”，此时在桌面即可看到新添加的卡片。结果示例如下。<br>
![WidgetPrinciple](figures/应用内加卡.gif)
