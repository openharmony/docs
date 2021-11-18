# 开发准备<a name="ZH-CN_TOPIC_0000001055087693"></a>

-   [准备开发环境](#section1912530122716)
-   [创建项目](#section1456035192720)

## 准备开发环境<a name="section1912530122716"></a>

首先需要下载和配置DevEco Studio，具体操作请参考[《DevEco Studio使用指南》](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/software_install-0000001053582415)。

## 创建项目<a name="section1456035192720"></a>

1.  通过如下两种方式，打开工程创建向导界面。
    -   如果当前未打开任何工程，可以在DevEco Studio的欢迎页，选择**Create HarmonyOS Project**开始创建一个新工程。
    -   如果已经打开了工程，可以在菜单栏选择**File \> New \> New Project**来创建一个新工程。

2.  选择“Smart Vision”下的“Empty Feature Ability”模板。

    ![](figures/empty-feature-ability.png)

3.  点击**Next**，进入到工程配置阶段，需要根据向导配置工程的基本信息。
    -   **Project Name**：工程的名称，可以自定义。
    -   **Package Name**：软件包名称，默认情况下，应用ID也会使用该名称，应用发布时，应用ID需要唯一。
    -   **Save Location**：工程文件本地存储路径，存储路径中不能包含中文字符和空格。
    -   **Compatible API Version**：兼容的SDK版本。

4.  点击**Finish**，工具会自动生成示例代码和相关资源，等待工程创建完成。

