# (Optional) Using canOpenLink to Check Application Accessibility
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## When to Use
Before starting application B, application A can call **canOpenLink** to check whether application B is accessible.

> **NOTE**
> 
> The **canOpenLink** API cannot be used to determine whether the application navigated to via App Linking is installed.

## Constraints
Starting from API version 21, a maximum of 200 URL schemes can be configured in the [querySchemes](../quick-start/module-configuration-file.md) field in the **module.json5** file of the entry module. In API version 20 and earlier versions, a maximum of 50 URL schemes can be configured.
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
            // actions cannot be empty. Otherwise, matching the target application fails.
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
1. Why is the number of URL schemes configured in querySchemes limited?

   The **canOpenLink()** API is used to check whether an application is accessible. It indirectly reveals whether a specific application is installed.

   To protect system security and user privacy and to prevent malicious applications from scanning the list of installed applications, you must configure the **querySchemes** property when using the **canOpenLink()** API. Starting from API version 21, the maximum number of URL schemes that can be configured is 200. In API version 20 and earlier versions, a maximum of 50 URL schemes can be configured.
