# Converting HAR to HSP

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e614db0ed9ef9e65ff9f340640f4a0fd5317e78d translatedAt=2026-08-13T09:05:15.866Z pushedAt=2026-08-13T13:52:44.319Z -->

Currently, the HAR has a problem with duplicate packaging, leading an oversize application package. To fix this problem, you can convert the HAR to the HSP by changing the configuration items.

>
> **NOTE**
>
> There are differences when some components and modules are integrated and used in the HAP, HSP, and HAR. For example, separate constraints are provided on loading the Worker thread file in the HAR compared with that in the HSP. For details, see [Precautions for File URLs](../arkts-utils/worker-introduction.md#precautions-for-file-urls). Therefore, after HAR is converted to HSP by performing the following steps, pay attention to the corresponding components and modules and perform adaptation.
>

## How to Convert

1. Set **type** to **shared** and add the **deliveryWithInstall** and **pages** fields in the **module.json5** file of the HAR module.

    <!-- @[har_to_hsp_001](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HarToHsp/library/src/main/module.json5) -->

    ``` JSON5
    {
      "module": {
        // ...
        "type": "shared",
        "deliveryWithInstall": true,
        "pages": "$profile:main_pages",
        // ...
      }
    }
    ```

2. Create a **profile** folder in the **resources\base** directory. Then add the **main_pages.json** file to the created folder and configure it as follows:

    ```json
    {
      "src": [
        "pages/PageIndex"
      ]
    }
    ```

3. Create a **pages** folder in the **ets** directory. Then add the **PageIndex.ets** file to the created folder and configure it as follows:

    <!-- @[har_to_hsp_002](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HarToHsp/library/src/main/ets/pages/PageIndex.ets) -->

    ``` TypeScript
    @Entry
    @Component
    struct PageIndex {
      @State message: string = 'hello world';
    
      build() {
        Row() {
          Column() {
            Text(this.message)
              .fontSize(50)
              .fontWeight(FontWeight.Bold)
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

4. Delete the **consumerFiles** field from the **build-profile.json5** file of the HAR module.

5. Replace the content in the **hvigorfile.ts** file of the HAR module with the following content:

    <!-- @[har_to_hsp_003](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HarToHsp/library/hvigorfile.ts) -->

    ``` TypeScript
    // library\hvigorfile.ts
    import { hspTasks } from '@ohos/hvigor-ohos-plugin';
    
    export default {
      system: hspTasks,  // Change the value to the HSP task.
      plugins:[]
    }
    ```

6. Add the **packageType** field in the **oh-package.json5** file.

    <!-- @[har_to_hsp_004](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HarToHsp/library/oh-package.json5) -->

    ``` JSON5
    {
      // ...
      "packageType": "InterfaceHar"
    }
    ```

7. Add the **targets** tag to **build-profile.json5** > **modules** > **library** in the root directory of the project.

    <!-- @[har_to_hsp_005](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/HarToHsp/build-profile.json5) -->

    ``` JSON5
    "modules": [
      // ...
      {
        "name": "library",
        "srcPath": "./library",
        "targets": [
          {
            "name": "default",
            "applyToProducts": [
              "default"
            ]
          }
        ]
      }
    ],
    ```