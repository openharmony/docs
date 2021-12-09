# 开发准备

## 任务说明

本文档适用于OpenHarmony应用开发的初学者。通过构建一个简单的具有页面跳转功能的应用（如下图[预览器](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/previewer-0000001054328973#ZH-CN_TOPIC_0000001056725592__section16523172216252)运行效果所示），熟悉OpenHarmony应用开发流程。

为确保运行效果，本文以使用**DevEco Studio 3.0.0.601 Beta1**版本为例，点击[此处](https://developer.harmonyos.com/cn/develop/deveco-studio#download_beta)获取下载链接。

![zh-cn_image_0000001172442490](figures/zh-cn_image_0000001172442490.png)

**表1** 方舟开发框架的对比

| 比较项 | 基于JS扩展的类Web开发范式 | 基于TS扩展的声明式开发范式 |
| -------- | -------- | -------- |
| 语言生态 | JS | eTS |
| 接口方式 | 类Web范式 | 声明式 |
| 执行方式 | 框架层处理，基于数据驱动的UI自动变更 | 框架层处理，基于数据驱动的UI自动变更 |
| 相对优势 | 轻量化，开发更简便 | 极简开发，内存占用更少、运行性能更高 |

接下来，分别使用JS语言、eTS语言实现上述两个页面跳转的功能。


## 开发准备

1. 开始前请参考[配置OpenHarmony SDK](../quick-start/configuring-openharmony-sdk.md)，完成**DevEco Studio**的安装和开发环境配置。

2. 开发环境配置完成后，请参考[创建OpenHarmony工程](../quick-start/use-wizard-to-create-project.md)创建工程。
   - 使用JS语言开发，模板选择Empty Ability，Language选择JS。
   - 使用eTS语言开发，模板选择Empty Ability，Language选择eTS。

3. 工程创建完成后，使用[预览器](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/previewer-0000001054328973#ZH-CN_TOPIC_0000001056725592__section16523172216252)运行该工程。

完成上述操作后，请参考[使用JS语言开发](../quick-start/start-with-js.md)、[使用eTS语言开发](../quick-start/start-with-ets.md)继续下一步的学习。
