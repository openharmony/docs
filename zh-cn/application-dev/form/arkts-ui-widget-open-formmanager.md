# 应用内拉起卡片管理加桌

卡片开发服务支持将应用的ArkTS卡片添加到桌面。

桌面提供统一的卡片管理页面。应用通过[formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md)模块提供的[openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18)接口，能够拉起卡片管理页面，触发卡片添加至桌面操作，点击“添加至桌面”，实现卡片添加至桌面的功能。

## 开发步骤
下面给出示例，实现如下功能：在应用内点击按钮“添加卡片到桌面”，拉起卡片管理页面。
拉起后，用户可在卡片管理页面，点击“添加至桌面”，此时在桌面即可看到新添加的卡片。
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
// entry/src/main/ets/pages/Index.ets
{
  "string": [
    {
      "name": "module_desc",
      "value": "module description"
    },
    {
      "name": "EntryAbility_desc",
      "value": "description"
    },
    {
      "name": "EntryAbility_label",
      "value": "openFormManager"
    },
    {
      "name": "EntryFormAbility_desc",
      "value": "form_description"
    },
    {
      "name": "EntryFormAbility_label",
      "value": "form_label"
    },
    {
      "name": "OpenManagerDemo_desc",
      "value": "This is a service widget."
    },
    {
      "name": "OpenManagerDemo_display_name",
      "value": "OpenManagerDemo"
    },
    {
      "name": "open_form_manager_button",
      "value": "添加应用卡片到桌面"
    },
    {
      "name": "widget_desc",
      "value": "This is a service widget."
    },
    {
      "name": "widget_display_name",
      "value": "widget"
    }
  ]
}
```
3. 用户可在卡片管理页面，点击“添加至桌面”，此时在桌面即可看到新添加的卡片。结果示例如下。

