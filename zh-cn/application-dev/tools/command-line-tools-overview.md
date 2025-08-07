# 命令行工具简介

<!--Kit: Common-->
<!--Subsystem: Common-->
<!--Owner: @foryourself-->
<!--SE: @lingminghw-->
<!--TSE: @RayShih-->

当前SDK中包含了开发者在开发应用过程中需要使用的多种工具，可以实现数据传输、日志查看、应用安装、系统打点等功能。

开发者可以直接从SDK中的toolchains文件夹下获取相关工具或通过[Command Line Tools](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-commandline-get)工具中的sdk文件夹中获取相关工具。

SDK已嵌入DevEco Studio中，无需额外下载配置。HarmonyOS SDK可以在DevEco Studio的安装位置下的`DevEco Studio\sdk`目录中查看。

> *说明：*
>
> 各工具存放位置有差异，详见各工具文档介绍。
>
> 部分工具能力依赖hdc shell能力，开发者在使用前请认真阅读文档中的环境要求，配置环境。

## 高频使用工具列表

| 命令 | 说明 |
| [hdc](../dfx/hdc.md) | 用于用于与设备进行交互调试、数据传输、查看日志等操作。
| [aa](aa-tool.md) | Ability助手，用于启动应用和启动测试用例，为开发者提供基本的应用调试和测试能力，例如启动应用组件、强制停止进程、打印应用组件相关信息等。 |
| [bm](bm-tool.md) | 包管理工具，实现应用安装、卸载、更新、查询等功能，为开发者提供基本的应用安装包的调试能力。 |
| [hilog](../dfx/hilog.md) | 用于打印日志，记录用户操作、系统运行状态。 |
| [打包工具](./packing-tool.md) | 用于在程序编译完成后，对编译出的文件等进行打包，以供安装发布。 |
| [拆包工具](./unpacking-tool.md) | 支持通过命令行方式将HAP、HSP、App等文件解压成文件夹，并且提供Java接口对HAP、HSP、App等文件进行解析。 |