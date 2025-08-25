# HAP转HAR指导
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

HAP不支持导出接口或ArkUI组件给其他模块或应用使用。若需导出模块中的接口或ArkUI组件，并将模块作为二方库、三方库共享给其他模块或应用，可以使用HAR。需要注意，HAR不具有独立安装和运行的能力，其作为静态共享包会打包到依赖方的HAP或HSP中。本文通过配置项的变更将HAP工程变成HAR工程。
## HAP转HAR的操作步骤

1. 修改HAP模块下的[module.json5](./module-configuration-file.md)文件，具体操作如下：
    - 将type字段值改为har，删除mainElement、deliveryWithInstall、installationFree和pages字段。
    - 由于HAR模块不支持ExtensionAbility，需要删除extensionAbilities字段，并将关联的ExtensionAbility组件删除或迁移到其他HAP模块中。
    - 由于HAR模块在API version 13及以下不支持UIAbility，如果当前的API version低于或等于13，需要删除abilities字段，并将关联的UIAbility组件删除或迁移到其他HAP模块中。
    ```json
    // your_hap_module\src\main\module.json5
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

2. 在HAP模块的src\main\resource\base\profile文件夹下，删除main_pages.json文件。

3. 修改HAP模块的hvigorfile.ts文件，将内容替换为以下内容：
    ```ts
    // your_hap_module\hvigorfile.ts
    import { harTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
        system: harTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
        plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

4. 修改项目级的配置文件[build-profile.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile-app)，在 `modules` 字段下找到 HAP 的配置信息，并删除 HAP 配置下的 `targets`。

5. HAP转换为HAR后，如果需要导出ArkUI组件或接口，需要在模块的根目录下创建名为Index.ets的文件，并在模块的oh-package.json5文件中的main字段配置该文件。详细导出方法参见[HAR-开发](./har-package.md#开发)。
    ```json
    // your_hap_module\oh-package.json5
    {
        "main": "Index.ets" // Index.ets文件的路径为：your_hap_module\Index.ets
    }
    ```