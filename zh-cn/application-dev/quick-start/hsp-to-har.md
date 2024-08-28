# HSP转HAR指导
HSP存在bundlename和签名的一致性要求，而且在调试阶段需要先安装HSP包，导致多模块集成开发存在很多集成的问题，在此场景下推荐使用HAR包的方式提供能力。
## HAR转HSP的操作步骤

1. 修改HSP模块下的module.json5文件。
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

3. 修改hvigorfile.ts文件。
    ```ts
    // MyApplication\library\hvigorfile.ts
    import { harTasks } from '@ohos/hvigor-ohos-plugin';

    export default {
        system: harTasks,  /* Built-in plugin of Hvigor. It cannot be modified. */
        plugins:[]         /* Custom plugin to extend the functionality of Hvigor. */
    }
    ```

4. 修改oh-package.json5文件，删除packageType配置。

5. 修改项目级的配置文件build-profile.json5，在'modules'模块下找到HSP的配置信息，删除HSP配置下'targets'。