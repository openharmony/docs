# 应用内拉起卡片管理加桌
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--Designer: @xueyulong-->
<!--Tester: @chenmingze-->
<!--Adviser: @Brilliantry_Rui-->

从API version 18开始，卡片开发服务支持将应用的ArkTS卡片添加到桌面。

桌面提供统一的卡片管理页面。应用通过[formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md)模块提供的[openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18)接口，能够拉起卡片管理页面，触发卡片添加至桌面操作，点击“添加至桌面”，实现卡片添加至桌面的功能。

## 开发步骤

实现[formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md)接口提供的[openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18)方法。

```ts
// entry/src/main/ets/pages/Index.ets

import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
        //添加拉起卡片管理页面按钮，点击按钮后调用openFormManager方法，拉起卡片管理页面
        Button('拉起卡片管理页面')
          .onClick(() => {
            const want: Want = {
              bundleName: 'com.example.formbutton',
              abilityName: 'EntryFormAbility',
              parameters: {
                'ohos.extra.param.key.form_dimension': 2,
                'ohos.extra.param.key.form_name': 'widget',
                'ohos.extra.param.key.module_name': 'entry'
              },
            };
            try {
              formProvider.openFormManager(want);
            } catch (error) {
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
