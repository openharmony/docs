# Converting HAP to HAR
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

HAR allows you to export APIs or ArkUI components from a module and share the module as a second-party or third-party library with other modules or applications, while HAP does not. This topic will walk you through how to convert a HAP project to a HAR project by modifying configuration items.
## How to Convert

1. Modify the [module.json5](./module-configuration-file.md) file in the HAP module as follows:
    - Change the value of **type** to **har**, and delete the **mainElement**, **deliveryWithInstall**, **installationFree**, and **pages** tags.
    - ExtensionAbility is not supported by the HAR module. Therefore, you need to delete the **extensionAbilities** tag and delete the associated ExtensionAbility component or migrate it to the HAP module.
    - UIAbility is not supported by the HAR module in API version 13 or earlier. Therefore, you need to delete the **abilities** tag and delete the associated UIAbility component or migrate it to the HAP module.
    ```json
    {
        "module": {
            "name": "har",
            "type": "har",
            "deviceTypes": [
                "phone",
                "tablet",
                "2in1"
            ]
        }
    }
    ```

2. Delete the **main_pages.json** file from the **src\main\resource\base\profile** folder of the HAP module.

3. Replace the content in the **hvigorfile.ts** file of the HAP module with the following:
    ```ts
    import { harTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
        system: harTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
        plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

4. Create an **Index.ets** file in the root directory of the HAP module, and set the file in the **main** tag of the **oh-package.json5** file. The **Index.ets** file is used to export ArkUI components or APIs. For details, see [Developing a HAR](./har-package.md#developing-a-har).
    ```json
    {
        "main": "Index.ets"
    }
    ```

5. In the project-level configuration file [build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile-app), delete **targets** of the HAP under the **modules** tag.
