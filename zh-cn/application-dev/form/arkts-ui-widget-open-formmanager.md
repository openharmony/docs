# 应用内拉起卡片管理加桌概述

卡片开发服务支持将应用的ArkTS卡片添加到桌面。

桌面提供统一的卡片管理页。应用通过[formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md)模块提供的[openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18)接口，能够拉起桌面卡片管理页，实现卡片添加至桌面的功能。

1. 用户在应用内触发[openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18)方法。

2. 卡片提供方将拉起桌面卡片管理页。

3. 用户在桌面卡片管理页，添加到桌面。


# 应用内拉起卡片管理加桌

卡片开发服务支持将应用的ArkTS卡片添加到桌面。桌面提供统一的卡片管理页，应用通过[formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md)模块提供的[openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18)接口，能够拉起桌面卡片管理页，实现卡片添加到桌面的功能。

## 开发步骤

1. 在工程的entry模块中，新建名为Index的代码文件。在Index文件中，实现[formProvider](../reference/apis-form-kit/js-apis-app-form-formProvider.md)接口提供的[openFormManager](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovideropenformmanager18)方法。

```ts
// entry\src\main\ets\pages\Index.ets

import { formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
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
              formProvider.openFormManager(this.want);
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

2. 在应用的[app.json5](../quick-start/app-configuration-file.md)配置文件中添加卡片编辑配置信息。
```json
{
  "app": {
    "bundleName": "com.example.formbutton",
    "vendor": "example",
    "versionCode": 1000000,
    "versionName": "1.0.0",
    "icon": "$media:app_icon",
    "label": "$string:app_name"
  }
}
```
