# HAR转HSP指导
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

目前HAR的使用存在打包多份，包膨胀的问题，导致整体应用包的体积很大，HSP可以很好地解决该问题，本文介绍如何通过配置项的变更将HAR工程转换为HSP工程。
## HAR转HSP的操作步骤

1. 修改HAR模块下的module.json5文件，将type字段设置为shared，并新增deliveryWithInstall和pages字段。
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

2. 在resources\base下新增profile文件夹，在profile下新增一个main_pages.json文件，并配置如下内容。
    ```json
    // MyApplication\library\src\main\resources\base\profile\main_pages.json
    {
      "src": [
        "pages/PageIndex"
      ]
    }
    ```

3. 在ets目录下新增pages目录，并在pages目录下新增PageIndex.ets文件，配置如下内容。
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

4. 删除HAR模块的build-profile.json5文件中的consumerFiles字段配置。

5. 修改HAR模块的hvigorfile.ts文件，将以下内容替换文件内容。
    ```ts
    // MyApplication\library\hvigorfile.ts
    import { hspTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
      system: hspTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
      plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

6. 修改oh-package.json5文件，新增packageType配置。
    ```json
    // MyApplication\library\oh-package.json5
    {
      "packageType": "InterfaceHar"
    }
    ```

7. 修改项目根目录下的build-profile.json5文件，在modules标签下找到library的配置，新增targets标签。

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
