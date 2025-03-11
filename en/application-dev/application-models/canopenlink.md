# (Optional) Using canOpenLink to Check Application Accessibility
## When to Use
Before starting application B, application A can call **canOpenLink** to check whether application B is accessible.
## Constraints
A maximum of 50 URL schemes can be configured in the [querySchemes](../quick-start/module-configuration-file.md) field in the **module.json5** file of the entry module.
## Available APIs
**canOpenLink** is provided by the [bundleManager](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagercanopenlink12) module to check whether a target application is accessible.

For details about the matching rules, see [Matching Rules of Explicit Want and Implicit Want](explicit-implicit-want-mappings.md).

## How to Develop
### Procedure for the Caller Application

1. Configure the [querySchemes](../quick-start/module-configuration-file.md) field in the **module.json5** file of the entry module to declare the URL schemes.

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

2. Import the **ohos.bundle.bundleManager** module.
3. Call **canOpenLink**.

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

### Procedure for the Target Application
Configure the [uris](../quick-start/module-configuration-file.md#skills) field in the **module.json5** file.

```json
{
  "module": {
    //...
    "abilities": [
      {
        //...
        "skills": [
          {
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
