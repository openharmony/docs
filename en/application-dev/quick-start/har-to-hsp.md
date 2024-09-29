# Converting HAR to HSP
Currently, the HAR has a problem with duplicate packaging, leading an oversize application package. To fix this problem, the HSP is an ideal choice. This topic describes how to convert the HAR to the HSP.
## How to Convert

1. Modify the **module.json5** file of the HAR module.
    ```json
    // MyApplication\library\src\main\module.json5
    {
      "module": {
        "name": "library",
        "type": "shared",
        "description": "$string:shared_desc",
        "deliveryWithInstall": true,
        "pages": "$profile:main_pages"
      }
    }
    ```

2. Add a string field **shared_desc** in **resources** > **base** > **element** of **en\_US** and **zh\_CN** qualifiers directories.
    ```json
    // MyApplication\library\src\main\resources\base\element\string.json
    {
      "string": [
        {
          "name": "shared_desc",
          "value": "description"
        }
      ]
    }
    ```

3. Add a **profile** folder in **resources** > **base**. Then add a **main_pages.json** file to the **profile** folder and configure the file.
    ```json
    // MyApplication\library\src\main\resources\base\profile\main_pages.json
    {
      "src": [
        "pages/PageIndex"
      ]
    }
    ```

4. Add a **pages** directory in the **ets** directory. Then add a **PageIndex.ets** file in the **pages** directory.
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

5. Delete the **consumerFiles** field from **MyApplication** > **library** > **build-profile.json5** file.

6. Modify the **hvigorfile.ts** file.
    ```ts
    // MyApplication\library\hvigorfile.ts
    import { hspTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
      system: hspTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
      plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

7. Modify the **oh-package.json5** file and configure the **packageType** field.
    ```json
    // MyApplication\library\oh-package.json5
    {
      "packageType": "InterfaceHar"
    }
    ```

8. Modify the **build-profile.json5** configuration file in the root directory.
![har-to-hsp-8-1.png](figures/har-to-hsp-8-1.png)
After modification
![har-to-hsp-8-2.png](figures/har-to-hsp-8-2.png)
