# 文件系统


文件系统（File System，或者简称FS），是操作系统中输入输出的一种主要形式，主要负责和内外部的存储设备交互。


文件系统对上通过C库提供的POSIX标准的操作接口，具体可以参考C库的API文档说明。对下，通过内核态的VFS虚拟层，屏蔽了各个具体文件系统的差异。基本架构如下：


  **图1** 文件系统的总体结构

  ![zh-cn_image_0000001125101908](figures/zh-cn_image_0000001125101908.png)


- **[虚拟文件系统](kernel-small-bundles-fs-virtual.md)**

- **[支持的文件系统](kernel-small-bundles-fs-support.md)**

- **[适配新的文件系统](kernel-small-bundles-fs-new.md)**