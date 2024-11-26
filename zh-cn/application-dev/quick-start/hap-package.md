# HAP

HAP（Harmony Ability Package）是应用安装和运行的基本单元。HAP包是由代码、资源、第三方库、配置文件等打包生成的模块包，其主要分为两种类型：entry和feature。

- entry：应用的主模块，作为应用的入口，提供了应用的基础功能。
- feature：应用的动态特性模块，作为应用能力的扩展，可以根据用户的需求和设备类型进行选择性安装。

应用程序包可以只包含一个基础的entry包，也可以包含一个基础的entry包和多个功能性的feature包。

## 使用场景

- 单HAP场景：如果只包含UIAbility组件，无需使用ExtensionAbility组件，优先采用单HAP（即一个entry包）来实现应用开发。虽然一个HAP中可以包含一个或多个UIAbility组件，为了避免不必要的资源加载，推荐采用“一个UIAbility+多个页面”的方式。

- 多HAP场景：如果应用的功能比较复杂，需要使用ExtensionAbility组件，可以采用多HAP（即一个entry包+多个feature包）来实现应用开发，每个HAP中包含一个UIAbility组件或者一个ExtensionAbility组件。在这种场景下，可能会存在多个HAP引用相同的库文件，导致重复打包的问题。


## 约束限制

- 不支持导出接口和ArkUI组件，给其他模块使用。

- 多HAP场景下，App Pack包中同一设备类型的所有HAP中必须有且只有一个Entry类型的HAP，Feature类型的HAP可以有一个或者多个，也可以没有。

- 多HAP场景下，同一应用中的所有HAP的配置文件中的bundleName、versionCode、versionName、minCompatibleVersionCode、debug、minAPIVersion、targetAPIVersion、apiReleaseType相同，同一设备类型的所有HAP对应的moduleName标签必须唯一。HAP打包生成App Pack包时，会对上述参数配置进行校验。

- 多HAP场景下，同一应用的所有HAP、HSP的签名证书要保持一致。上架应用市场是以App Pack形式上架，应用市场分发时会将所有HAP从App Pack中拆分出来，同时对其中的所有HAP进行重签名，这样保证了所有HAP签名证书的一致性。在调试阶段，开发者通过命令行或DevEco Studio将HAP安装到设备上时，要保证所有HAP签名证书一致，否则会出现安装失败的问题。

## 创建

下面简要介绍如何通过DevEco Studio新建一个HAP模块。

1. 创建工程，构建第一个ArkTS应用。
2. 在工程目录上单击右键，选择**New > Module**。
3. 在弹出的对话框中选择**Empty Ability**模板，单击**Next**。
   
4. 在Module配置界面，配置**Module name**，选择**Module Type**和**Device Type**，然后单击**Next**。

5. 在Ability配置界面，配置**Ability name**，然后单击**Finish**完成创建。

## 开发

- HAP中支持添加UIAbility组件或ExtensionAbility组件，添加pages页面。具体操作可参考[应用/服务开发](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-add-new-ability-V13)。

- HAP中支持引用HAR或HSP共享包，详见[HAR的使用](./har-package.md#使用)、[HSP的使用](./in-app-hsp.md#使用)。

## 调试

通过DevEco Studio编译打包，生成单个或者多个HAP，即可基于HAP进行调试。如需根据不同的部署环境、目标人群、运行环境等，将同一个HAP定制编译为不同版本，请参见[定制编译指导](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-customized-multi-targets-and-products-guides-V13)。

开发者可以采用DevEco Studio或者hdc工具进行调试：

- **方法一：** 使用DevEco Studio进行调试，详见[应用程序包调试方法](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-run-debug-configurations-V13)。

- **方法二：** 使用<!--Del-->[<!--DelEnd-->hdc工具<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd-->(可通过OpenHarmony SDK获取，在SDK的toolchains目录下)进行调试。

   在调试前，需要先安装或更新HAP，此处有两种方式：

   - 直接使用hdc安装、更新HAP。

      HAP的路径为开发平台上的文件路径，以Windows开发平台为例，命令参考如下：

      ```shell
      // 安装、更新，多HAP可以指定多个文件路径
      hdc install entry.hap feature.hap
      // 执行结果
      install bundle successfully.
      // 卸载
      hdc uninstall com.example.myapplication
      // 执行结果
      uninstall bundle successfully.
      ```

   - 先执行hdc shell，再使用bm工具安装、更新HAP。

      HAP的文件路径为真机上的文件路径，命令参考如下：

      ```shell
      // 先执行hdc shell才能使用bm工具
      hdc shell
      // 安装、更新，多HAP可以指定多个文件路径
      bm install -p /data/app/entry.hap /data/app/feature.hap
      // 执行结果
      install bundle successfully.
      // 卸载
      bm uninstall -n com.example.myapplication
      // 执行结果
      uninstall bundle successfully.
      ```

   完成HAP安装或更新后，即可参考相关调试命令进行[调试](../tools/aa-tool.md)。

<!--RP4-->
<!--RP4End-->
