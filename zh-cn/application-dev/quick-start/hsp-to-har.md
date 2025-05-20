# HSP转HAR指导
HSP对bundleName和签名有一致性要求，在调试阶段需要先安装HSP包，这导致多模块集成开发场景下容易出现多种集成问题。在此场景下，建议使用HAR包来提供所需功能。本文通过配置项的变更将HSP工程变成HAR工程。
## HSP转HAR的操作步骤

1. 修改HSP模块下的module.json5文件，将type字段值改为har，删除deliveryWithInstall和pages字段。
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
2. 在resource\base\profile文件夹下，删除main_pages.json文件。

3. 修改HSP模块的hvigorfile.ts文件，将内容替换为以下内容。
    ```ts
    // MyApplication\library\hvigorfile.ts
    import { harTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
        system: harTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
        plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

4. 修改HSP模块的oh-package.json5文件，删除packageType配置。

5. 修改项目级的配置文件 `build-profile.json5`，在 `modules` 模块下找到 HSP 的配置信息，删除 HSP 配置下的 `targets`。