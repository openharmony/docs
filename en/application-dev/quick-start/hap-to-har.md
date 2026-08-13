# Converting HAP to HAR

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e614db0ed9ef9e65ff9f340640f4a0fd5317e78d translatedAt=2026-08-13T09:04:57.061Z pushedAt=2026-08-13T13:50:15.527Z -->

HAR allows you to export APIs or ArkUI components from a module and share the module as a second-party or third-party library with other modules or applications, while HAP does not. This topic will walk you through how to convert a HAP project to a HAR project by modifying configuration items.

>
> **NOTE**
>
> There are differences when some components and modules are integrated and used in the HAP, HSP, and HAR. For example, separate constraints are provided on loading the Worker thread file in the HAR compared with that in the HSP. For details, see [Precautions for File URLs](../arkts-utils/worker-introduction.md#precautions-for-file-urls). Therefore, after HAP is converted to HAR by performing the following steps, pay attention to the corresponding components and modules and perform adaptation.
>

## How to Convert

1. Modify the [module.json5](./module-configuration-file.md) file in the HAP module as follows:

    - Change the value of **type** to **har**, and delete the **mainElement**, **deliveryWithInstall**, **installationFree**, and **pages** tags.

    - Prior to API version 17, HARs do not support the creation of any ExtensionAbility. Starting from API version 18, HARs support only [two specific types of ExtensionAbility](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-add-new-ability#section18891639459). Therefore, for HARs used in either API version 17 or earlier, or API version 18 or later without the two supported ExtensionAbilities configured, you should delete the **extensionAbilities** tag and either delete the associated ExtensionAbility components or migrate them to another HAP module. 

    - UIAbility is not supported by the HAR module in API version 13 or earlier. Therefore, you need to delete the **abilities** tag and delete the associated UIAbility component or migrate it to the HAP module.

    <!-- @[hap_to_har_001](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HapToHar/entry/src/main/module.json5) -->

    ``` JSON5
    {
      "module": {
        "name": "har",
        "type": "har",
        "deviceTypes": [
          "tablet",
          "2in1"
        ]
      }
    }
    ```

2. Delete the **main_pages.json** file from the **src\main\resource\base\profile** folder of the HAP module.

3. Replace the content in the **hvigorfile.ts** file of the HAP module with the following:

    <!-- @[hap_to_har_003](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HapToHar/entry/hvigorfile.ts) -->

    ``` TypeScript
    import { harTasks } from '@ohos/hvigor-ohos-plugin';
    
    export default {
      system: harTasks,  // Change the value to the HAR task.
      plugins:[]
    }
    ```

4. Create an **Index.ets** file in the root directory of the HAP module, and set the file in the **main** tag of the **oh-package.json5** file. The **Index.ets** file is used to export ArkUI components or APIs. For details, see [Developing a HAR](./har-package.md#developing-a-har).

    <!-- @[hap_to_har_002](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HapToHar/entry/oh-package.json5)  -->

    ``` JSON5
    {
      // ...
      "main": "Index.ets",
      // ...
    }
    ```

5. In the project-level configuration file [build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile-app), delete **targets** of the HAP under the **modules** tag.