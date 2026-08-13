# Converting HSP to HAR

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e614db0ed9ef9e65ff9f340640f4a0fd5317e78d translatedAt=2026-08-13T09:05:27.181Z pushedAt=2026-08-13T13:52:49.402Z -->

The HSP has requirements on the consistency of bundle names and signatures. Installing an HSP file in the debugging phase may cause many integration issues during multi-module development. In this case, you are advised to use the HAR file instead. This topic describes how to convert an HSP project to an HAR project by changing the configuration items.

>
> **NOTE**
>
> Before reading this topic, you should learn the following concepts first: [HSP](in-app-hsp.md), [HAR](har-package.md), [module.json5](module-configuration-file.md), [hvigorfile.ts](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-config-ohos-guide), [oh-package.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-oh-package-json5), and [build-profile.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-profile-app).
>
> There are differences when some components and modules are integrated and used in the HAP, HSP, and HAR. For example, separate constraints are provided on loading the Worker thread file in the HAR compared with that in the HSP. For details, see [Precautions for File URLs](../arkts-utils/worker-introduction.md#precautions-for-file-urls). Therefore, after HSP is converted to HAR by performing the following steps, pay attention to the corresponding components and modules and perform adaptation.
>

## How to Convert

1. In the **module.json5** file of the HSP module, change the value of the **type** field to **har** and delete the **deliveryWithInstall** and **pages** fields.

    <!-- @[hsp_to_har_001](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HspToHar/library/src/main/module.json5) -->

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

2. Delete the **main_pages.json** file from the **resource\base\profile** folder.

3. Replace the content in the **hvigorfile.ts** file of the HSP module with the following:

    <!-- @[hsp_to_har_002](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HspToHar/library/hvigorfile.ts) -->

    ``` TypeScript
    // MyApplication\library\hvigorfile.ts
    import { harTasks } from '@ohos/hvigor-ohos-plugin';
    
    export default {
      system: harTasks,  // Change this field to harTasks.
      plugins:[]
    }
    ```

4. Delete the **packageType** configuration from the **oh-package.json5** file.

5. Delete **targets** from the HSP configuration of the **modules** module in the project-level **build-profile.json5** configuration file.