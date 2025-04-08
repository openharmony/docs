# （可选）使用canOpenLink判断应用是否可访问
## 使用场景
在应用A想要拉起应用B的场景中，应用A可先调用canOpenLink接口判断应用B是否可访问，如果可访问，再拉起应用B。

> **说明：**
> 
> canOpenLink接口不支持判断以App Linking方式跳转的目标应用是否安装。

## 约束限制
在entry模块的module.json5文件中的[querySchemes](../quick-start/module-configuration-file.md)字段中，最多允许配置50个URL scheme。
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
            // actions不能为空，actions为空会造成目标方匹配失败。
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
