# HAP转HAR指导
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

HAP不支持导出接口或ArkUI组件给其他模块或应用使用，如果需要导出模块中的接口或ArkUI组件，并将模块作为二方库、三方库共享给其他模块或应用，可以使用HAR。本文介绍如何通过配置项的变更将HAP工程变成HAR工程。

>
> **说明：**
>
> 部分组件和模块在HAP、HSP、HAR中集成使用时存在差异，例如[加载HAR中Worker线程文件相比HSP存在单独的使用约束](../arkts-utils/worker-introduction.md#文件路径注意事项)，因此按照如下步骤完成HAP转HAR后，请关注对应组件和模块介绍并进行适配。
>

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

4. 在HAP模块的根目录下创建名为Index.ets的文件，并在模块的oh-package.json5文件中的main标签配置该文件。Index.ets文件用于导出ArkUI组件或接口，详细导出方法参见[HAR-开发](./har-package.md#开发)。
    ```json
    {
        "main": "Index.ets"
    }
    ```

5. 修改项目级的配置文件[build-profile.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile-app)，在 `modules` 标签下找到HAP的配置信息，并删除HAP配置下的 `targets`。
