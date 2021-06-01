# OpenHarmony开发板Patch使用指导<a name="ZH-CN_TOPIC_0000001081980461"></a>

Patch文件位于工程项目源码路径：kernel/linux/patches/linux-4.19，存放特定芯片架构驱动补丁。

如需使用特定芯片平台驱动的Patch，需要在内核仓代码完成对芯片平台驱动补丁合入。

合入芯片平台驱动补丁，针对不同芯片平台合入对应的patch：

以Hi3516dv300为例：

```
patch -p1 < device/hisilicon/hi3516dv300/sdk_linux/open_source/linux/hisi_linux-4.19_hos_l2.patch 
```

>![](public_sys-resources/icon-notice.gif) **须知：** 
>由于OpenHarmony的编译构建流程中会拷贝kernel/linux-4.19的代码环境后进行打补丁动作，在使用OpenHarmony的版本级编译命令前，需要kernel/linux-4.19保持原代码环境。

