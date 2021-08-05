# 概述<a name="ZH-CN_TOPIC_0000001051452100"></a>

-   [Bundle](#section196713235514)
-   [Distribution](#section155387501033)

本章节将介绍HarmonyOS中的Bundle相关概念以及如何定义Bundle，并以一个示例说明如何使用hpm命令行工具完成Bundle的创建、开发、编译、发布、安装使用的全过程。

## Bundle<a name="section196713235514"></a>

Bundle是HarmonyOS中一个用来表示分发单元的术语，等同于包，一个Bundle中通常包含以下内容：

-   被分发的二进制文件（二进制类型）
-   被分发的源代码文件（源代码/代码片段类型）
-   编译脚本（发行版类型需要）
-   自身的说明文件
    -   bundle.json：元数据声明（名称，版本，依赖等）
    -   LICENSE：许可协议文本
    -   README.md：自述文件
    -   CHANGELOG.md：变更日志（可选）


>![](../public_sys-resources/icon-note.gif) **说明：** 
>Bundle的类型可以分为二进制，源代码，代码片段，模板，插件，发行版等。一个Bundle可以依赖其他的Bundles，依赖关系为有向无环图

一个Bundle被发布到HPM服务器（https://hpm.harmonyos.com）后，另外一些开发者就可以通过hpm包管理器下载安装使用 。

一个Bundle在命名空间内拥有唯一的名称（命名格式为：@scope/name），可以进行独立的版本演进。

## Distribution<a name="section155387501033"></a>

Distribution是HarmonyOS的发行版，是一个完整的操作系统版本，集合了各种Bundle（驱动，内核，框架，应用等），也通过Bundle在HPM平台分发。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>发行版的元数据中仅描述了依赖的Bundles以及如何编译该发行版的编译脚本，并不包含发行版的二进制镜像。下载发行版后，需要在本地将依赖的Bundles下载下来，安装编译后才能得到可用于烧录的系统镜像文件。
>发行版可以继承，即在一个既有的发行版的基础上，通过增加/删除Bundle形成新的发行版，以实现发行版的定制。

**图 1**  组Bundle和Distribution的关系<a name="fig85033524124"></a>  


![](figure/组件和发行版的构成-英文.png)

