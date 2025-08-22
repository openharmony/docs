# HAP转HAR指导
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->
本文通过配置项的变更将HAP工程变成HAR工程。
## HAP转HAR的操作步骤

1. 修改HAP模块下的module.json5文件，将type字段值改为har，删除mainElement、deliveryWithInstall、installationFree和pages字段。由于HAR模块不支持ExtensionAbility，需要删除extensionAbilities字段，并将关联的ExtensionAbility组件删除或者迁移到其他HAP模块中。由于HAR模块在API version 13及以下不支持UIAbility，如果当前的API version等于或低于13，需要删除abilities字段，并将关联的UIAbility组件删除或者迁移到其他HAP模块中。
    ```json
    // MyApplication\library\src\main\module.json5
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
2. 在resource\base\profile文件夹下，删除main_pages.json文件。

3. 修改HAP模块的hvigorfile.ts文件，将内容替换为以下内容：
    ```ts
    // MyApplication\library\hvigorfile.ts
    import { harTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
        system: harTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
        plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

4. 修改项目级的配置文件 `build-profile.json5`，在 `modules` 模块下找到 HAP 的配置信息，删除 HAP 配置下的 `targets`。

5. HAP转换为HAR后，支持导出HAR模块中的ArkUI组件、接口、资源，供其他应用或当前应用的其他模块引用。在模块的根目录下创建名为Index.ets的文件用于导出组件和接口，并在模块的oh-package.json5文件中的main字段配置该文件，见下方的示例。详细导出方法参见[HAR-开发](./har-package.md#开发)。
    ```json
    // MyApplication\library\oh-package.json5
    {
        "main": "Index.ets" // Index.ets文件的详细路径为：MyApplication\library\Index.ets
    }
    ```