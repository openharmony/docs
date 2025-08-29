# Converting HSP to HAR
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The HSP has requirements on the consistency of bundle names and signatures. Installing an HSP file in the debugging phase may cause many integration issues during multi-module development. In this case, you are advised to use the HAR file instead. This topic describes how to convert an HSP project to an HAR project by changing the configuration items.
## How to Convert

1. In the **module.json5** file of the HSP module, change the value of the **type** field to **har** and delete the **deliveryWithInstall** and **pages** fields.
    ```json
    // MyApplication\library\src\main\module.json5
    {
        "module": {
            "name": "har",
            "type": "har",
            "deviceTypes": [
            "default",
            "tablet",
            "2in1"
            ]
        }
    }
    ```
2. Delete the **main_pages.json** file from the **resource\base\profile** folder.

3. Replace the content in the **hvigorfile.ts** file of the HSP module with the following:
    ```ts
    // MyApplication\library\hvigorfile.ts
    import { harTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
        system: harTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
        plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

4. Delete the **packageType** configuration from the **oh-package.json5** file.

5. Delete **targets** from the HSP configuration of the **modules** module in the project-level **build-profile.json5** configuration file.
