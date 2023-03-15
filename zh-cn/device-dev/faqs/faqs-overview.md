# 常见问题概述


常见问题主要用于帮助开发者解决在开发过程中经常出现的一类问题。当前提供了如下常见问题供开发者进行查询。


## 环境搭建


### 轻量和小型系统

- 安装hb

  - [hb安装过程中出现乱码、段错误](../faqs/faqs-environment-setup.md)

  - [hb安装过程中提示"cannot import 'sysconfig' from 'distutils'"](../faqs/faqs-environment-setup.md)

  - [hb安装过程中提示"module 'platform' has no attribute 'linux_distribution'"](../faqs/faqs-environment-setup.md)

  - [hb安装过程中提示"Could not find a version that satisfies the requirement ohos-build"](../faqs/faqs-environment-setup.md)
- 安装python3

  - [提示“configure: error: no acceptable C compiler found in $PATH”](../faqs/faqs-environment-setup.md)

  - [提示“-bash: make: command not found”](../faqs/faqs-environment-setup.md)

  - [提示“zlib not available”](../faqs/faqs-environment-setup.md)

  - [提示“No module named 'Crypto'”](../faqs/faqs-environment-setup.md)

- [安装kconfiglib时，遇到lsb_release错误](../faqs/faqs-environment-setup.md)
- [Linux编译服务器终端输入不识别的命令时提示“ImportError: No module named apt_pkg”](../faqs/faqs-environment-setup.md)


## 编译构建子系统


### 轻量和小型系统

- [提示“usr/sbin/ninja: invalid option -- w”](../faqs/faqs-building.md)

- [提示“/usr/bin/ld: cannot find -lncurses”](../faqs/faqs-building.md)

- [提示“line 77: mcopy: command not found”](../faqs/faqs-building.md)

- [提示“riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory”](../faqs/faqs-building.md)

- [提示“No module named 'Crypto'”](../faqs/faqs-building.md)

- [提示“xx.sh : xx unexpected operator”](../faqs/faqs-building.md)

- [提示“Could not find a version that satisfies the requirement six>=1.9.0”](../faqs/faqs-building.md)

- [提示找不到“-lgcc”](../faqs/faqs-building.md)

- [提示找不到“python”](../faqs/faqs-building.md)

- [提示找不到“python3”](../faqs/faqs-building.md)


## 烧录


### 轻量和小型系统

- [烧写选择串口后提示“Error: Opening COMxx: Access denied”](../faqs/faqs-burning.md)

- [烧写失败](../faqs/faqs-burning.md)

- [串口无回显](../faqs/faqs-burning.md)

- [Windows电脑与单板网络连接失败](../faqs/faqs-burning.md)


## 内核


### 基础内核

- [LiteOS-A和LiteOS-M内核对外API的差异](../faqs/faqs-kernel.md)

- [如何分析线程栈溢出](../faqs/faqs-kernel.md)


### 文件系统

- [Hi3516开源板以写的模式打开同一个文件失败（LiteOS-A）](../faqs/faqs-kernel.md)


### 芯片适配

- [LiteOS内核已支持哪些硬件平台](../faqs/faqs-kernel.md)

- [LiteOS内核已支持哪几款芯片架构](../faqs/faqs-kernel.md)


### 三方组件

- [OpenHarmony已支持哪些三方组件](../faqs/faqs-kernel.md)

- [在OpenHarmony上使用OpenSSL，出现秘钥长度校验不正确](../faqs/faqs-kernel.md)

- [setsockopt是否支持SO_RCVBUF和SO_SNDBUF选项](../faqs/faqs-kernel.md)


### 编译链接

- [Arm Linux开发的应用程序，OpenHarmony如何在LiteOS-A上运行](../faqs/faqs-kernel.md)

- [OpenHarmony在什么系统下编译，使用什么编译器](../faqs/faqs-kernel.md)

- [LiteOS-M上使用单独编译成静态库的三方组件，出现三方组件中的全局变量值不正确，或调用三方组件的函数后系统卡死](../faqs/faqs-kernel.md)

- [LiteOS-A生成目标可执行文件时，提示 use  VFP register arguments，xxx.o does not](../faqs/faqs-kernel.md)

- [clock_gettime接口获取的时间打印不对](../faqs/faqs-kernel.md)


## 移植

- [如何将用户的堆内存挂载进内核](../faqs/faqs-porting.md)


## 启动恢复

- [系统启动过程中打印“parse failed!”错误后停止启动](../faqs/faqs-startup.md)

- [系统启动过程未结束就自动重启，如此反复持续](../faqs/faqs-startup.md)

- [参数正确的情况下调用SetParameter/GetParameter返回失败](../faqs/faqs-startup.md)


## 系统服务


### 公共基础库

- [1.LiteOS-A内核(Hi3516、Hi3518平台)KV存储路径设置错误，导致KV存储运行失败](../faqs/faqs-system-applications.md)


### 视觉应用常见问题

- [是否存在一个全局变量，所有的页面都可以访问？](../faqs/faqs-system-applications.md)

- [如何获取dom中的元素](../faqs/faqs-system-applications.md)

- [如何在页面间传值？](../faqs/faqs-system-applications.md)

- [list如何滚动到某个item？](../faqs/faqs-system-applications.md)

- [text支持多行吗？](../faqs/faqs-system-applications.md)

- [为什么控件不显示？](../faqs/faqs-system-applications.md)

- [如何实现页面滑动？](../faqs/faqs-system-applications.md)

- [Left、Top为什么不生效？](../faqs/faqs-system-applications.md)

- [动态绑定为什么不生效？](../faqs/faqs-system-applications.md)

- [如何实现相对定位和绝对定位？](../faqs/faqs-system-applications.md)

- [如何控制控件的显示与隐藏？](../faqs/faqs-system-applications.md)

- [使用Margin时，有什么注意事项？](../faqs/faqs-system-applications.md)

- [使用事件订阅时，有什么注意事项？](../faqs/faqs-system-applications.md)

- [使用动态绑定时，有什么注意事项？](../faqs/faqs-system-applications.md)

- [swiper loop属性如何生效？](../faqs/faqs-system-applications.md)

- [使用数组时，有什么注意事项？](../faqs/faqs-system-applications.md)


### hdc

- [hdc_std连接不到设备](../faqs/faqs-system-applications.md)

- [hdc_std运行不了](../faqs/faqs-system-applications.md)
