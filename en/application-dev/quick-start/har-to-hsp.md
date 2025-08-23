# Converting HAR to HSP
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

Currently, the HAR has a problem with duplicate packaging, leading an oversize application package. To fix this problem, you can convert the HAR to the HSP by changing the configuration items.
## How to Convert

1. Set **type** to **shared** and add the **deliveryWithInstall** and **pages** fields in the **module.json5** file of the HAR module.
    ```json
    // MyApplication\library\src\main\module.json5
    {
      "module": {
        "type": "shared",
        "deliveryWithInstall": true,
        "pages": "$profile:main_pages"
        // ...
      }
    }
    ```

2. Create a **profile** folder in the **resources\base** directory. Then add the **main_pages.json** file to the created folder and configure it as follows:
    ```json
    // MyApplication\library\src\main\resources\base\profile\main_pages.json
    {
      "src": [
        "pages/PageIndex"
      ]
    }
    ```

3. Create a **pages** folder in the **ets** directory. Then add the **PageIndex.ets** file to the created folder and configure it as follows:
    ```ts
    // MyApplication\library\src\main\ets\pages\PageIndex.ets
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
    ```ts
    // MyApplication\library\hvigorfile.ts
    import { hspTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
      system: hspTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
      plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

6. Add the **packageType** field in the **oh-package.json5** file.
    ```json
    // MyApplication\library\oh-package.json5
    {
      "packageType": "InterfaceHar"
    }
    ```

7. Add the **targets** tag to **build-profile.json5** > **modules** > **library** in the root directory of the project.

    ```json
    // MyApplication\build-profile.json5
    "modules": [
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
    ]
