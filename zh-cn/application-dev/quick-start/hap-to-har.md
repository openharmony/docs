# HAP转HAR指导
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

HAP不支持导出接口或ArkUI组件给其他模块或应用使用，如果需要导出模块中的接口或ArkUI组件，并将模块作为二方库、三方库共享给其他模块或应用，可以使用HAR。本文介绍如何通过配置项的变更将HAP工程变成HAR工程。
## HAP转HAR的操作步骤

1. 修改HAP模块下的[module.json5](./module-configuration-file.md)文件，具体操作如下：
    - 将type标签值改为har，删除mainElement、deliveryWithInstall、installationFree和pages标签。
    - 由于HAR模块不支持ExtensionAbility，需要删除extensionAbilities标签，并将关联的ExtensionAbility组件删除或迁移到其他HAP模块中。
    - 由于HAR模块在API version 13及以下不支持UIAbility，因此在API version 13及以前的版本，需要删除abilities标签，并将关联的UIAbility组件删除或迁移到其他HAP模块中。
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

2. 在HAP模块的src\main\resource\base\profile文件夹下，删除main_pages.json文件。

3. 修改HAP模块的hvigorfile.ts文件，将内容替换为以下内容：
    ```ts
    import { harTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
        system: harTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
        plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

4. 修改项目级的配置文件[build-profile.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile-app)，在 `modules` 标签下找到HAP的配置信息，并删除HAP配置下的 `targets`。

5. HAP转换为HAR后，如果需要导出ArkUI组件或接口，需要在模块的根目录下创建名为Index.ets的文件，并在模块的oh-package.json5文件中的main标签配置该文件。详细导出方法参见[HAR-开发](./har-package.md#开发)。
    ```json
    {
        "main": "Index.ets"
    }
    ```