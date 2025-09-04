# （可选）使用canOpenLink判断应用是否可访问
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## 使用场景
在应用A想要拉起应用B的场景中，应用A可先调用canOpenLink接口判断应用B是否可访问，如果可访问，再拉起应用B。

> **说明：**
> 
> canOpenLink接口不支持判断以App Linking方式跳转的目标应用是否安装。

## 约束限制
在entry模块的module.json5文件中的[querySchemes](../quick-start/module-configuration-file.md)字段中，从API version 21开始，最多允许配置200个URL scheme。API version 20及之前的版本，最多允许配置50个URL scheme。
## 接口说明
canOpenLink是[bundleManager](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagercanopenlink12)提供的支持判断目标应用是否可访问的接口。
匹配规则请参考[显式Want与隐式Want匹配规则](explicit-implicit-want-mappings.md)。
## 操作步骤
### 调用方操作步骤

1. 在entry模块的module.json5文件中配置[querySchemes](../quick-start/module-configuration-file.md)属性，声明想要查询的URL scheme。

    ```json
    {
      "module": {
        //...
        "querySchemes": [
          "app1Scheme"
        ]
      }
    }
    ```

2. 导入ohos.bundle.bundleManager模块。 
3. 调用canOpenLink接口。

    ```ts
    import { bundleManager } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    try {
      let link = 'app1Scheme://test.example.com/home';
      let canOpen = bundleManager.canOpenLink(link);
      hilog.info(0x0000, 'testTag', 'canOpenLink successfully: %{public}s', JSON.stringify(canOpen));
    } catch (err) {
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', 'canOpenLink failed: %{public}s', message);
    }
    ```

### 目标方操作步骤
在module.json5文件中配置[uris](../quick-start/module-configuration-file.md#skills标签)属性。

```json
{
  "module": {
    //...
    "abilities": [
      {
        //...
        "skills": [
          {
            // actions不能为空，actions为空会造成目标方匹配失败
            "actions": ["ohos.want.action.home"],
            "uris": [
              {
                "scheme": "app1Scheme",
                "host": "test.example.com",
                "pathStartWith": "home"
              }
            ]
          }
        ]
      }
    ]
  } 
}
```

## FAQ
1. 为什么限制querySchemes中配置的URL scheme个数？

   canOpenLink()接口提供了判断应用是否可以访问的能力。通过该能力，应用可以间接获取到指定应用是否安装等信息。

   为了保护系统安全和用户隐私，避免恶意应用扫描应用安装列表等行为，要求开发者在使用canOpenLink()接口时必须配置querySchemes属性，从API version 21开始，最多允许配置200个URL scheme。API version 20及之前的版本，最多允许配置50个URL scheme。
