# 常见问题概述<a name="ZH-CN_TOPIC_0000001169691604"></a>

-   [环境搭建](#section93289248249)
    -   [轻量和小型系统](#section197234983111)

-   [编译构建子系统](#section18826114693810)
    -   [轻量和小型系统](#section693410399)

-   [烧录](#section6556741113712)
    -   [轻量和小型系统](#section1029933713812)

-   [内核](#section13741125564211)
    -   [基础内核](#section1723365191114)
    -   [文件系统](#section14523145918136)
    -   [芯片适配](#section141541939159)
    -   [三方组件](#section4988163321816)
    -   [编译链接](#section080219574225)

-   [移植](#section129331824154313)
-   [启动恢复](#section83501764443)
-   [系统服务](#section19567132114455)
    -   [公共基础库](#section3214181711465)
    -   [视觉应用常见问题](#section295651815466)
    -   [hdc](#section178081876506)


常见问题主要用于帮助开发者解决在开发过程中经常出现的一类问题问题。当前提供了如下常见问题供开发者进行查询。

## 环境搭建<a name="section93289248249"></a>

### 轻量和小型系统<a name="section197234983111"></a>

-   [安装hb过程中出现乱码、段错误](faqs-environment-building.md#section36351051193919)
-   [安装hb过程中，提示"cannot import 'sysconfig' from 'distutils'"](faqs-environment-building.md#section48221013144011)
-   [安装hb过程中，提示"module 'platform' has no attribute 'linux\_distribution'"](faqs-environment-building.md#section8692735427)
-   [安装hb过程中，提示"Could not find a version that satisfies the requirement ohos-build"](faqs-environment-building.md#section8692735427)
-   [安装python3过程中，提示“configure: error: no acceptable C compiler found in $PATH”](faqs-environment-building.md#section870082884217)
-   [安装python3过程中，提示“-bash: make: command not found”](faqs-environment-building.md#section198707170455)
-   [安装python3过程中，提示“zlib not available”](faqs-environment-building.md#section85401445204518)
-   [安装python3过程中，提示“No module named '\_ctypes'”](faqs-environment-building.md#section12202694460)
-   [安装 kconfiglib时，遇到lsb\_release错误](faqs-environment-building.md#section5803174135115)
-   [Linux编译服务器终端输入不识别的命令时提示“ImportError: No module named apt\_pkg”](faqs-environment-building.md#section510820516515)

## 编译构建子系统<a name="section18826114693810"></a>

### 轻量和小型系统<a name="section693410399"></a>

-   [编译构建过程中，提示“usr/sbin/ninja: invalid option -- w”](faqs-building.md#section67961431372)
-   [编译构建过程中，提示“/usr/bin/ld: cannot find -lncurses”](faqs-building.md#section199631617371)
-   [编译构建过程中，提示“line 77: mcopy: command not found”](faqs-building.md#section937435175)
-   [编译构建过程中，提示“riscv32-unknown-elf-gcc: error trying to exec 'cc1': execvp: No such file or directory”](faqs-building.md#section1115535018713)
-   [编译构建过程中，提示“No module named 'Crypto'”](faqs-building.md#section17982573813)
-   [编译构建过程中，提示“Could not find a version that satisfies the requirement six\>=1.9.0”](faqs-building.md#section1917790845)
-   [编译构建过程中，提示“Could not find a version that satisfies the requirement six\>=1.9.0”](faqs-building.md#section1917790845)”
-   [编译构建过程中，提示找不到“-lgcc”](faqs-building.md#section141771701647)
-   [编译构建过程中，提示找不到“python”](faqs-building.md#section51781202415)
-   [编译构建过程中，提示找不到“python3”](faqs-building.md#section1917950148)

## 烧录<a name="section6556741113712"></a>

### 轻量和小型系统<a name="section1029933713812"></a>

-   [烧写选择串口后，提示“Error: Opening COMxx: Access denied”](faqs-burning.md#section18988185615914)

-   [烧写失败](faqs-burning.md#section1370982513317)
-   [串口无回显](faqs-burning.md#section183421944953)
-   [Windows电脑与单板网络连接失败](faqs-burning.md#section1215410450215)

## 内核<a name="section13741125564211"></a>

### 基础内核<a name="section1723365191114"></a>

-   [LiteOS-A和LiteOS-M内核对外API的差异](faqs-kernel.md#section447571122918)
-   [如何分析线程栈溢出](faqs-kernel.md#section8623141711293)

### 文件系统<a name="section14523145918136"></a>

-   [Hi3516开源板以写的模式打开同一个文件失败（LiteOS-A）](faqs-kernel.md#section517972255311)

### 芯片适配<a name="section141541939159"></a>

-   [LiteOS内核已支持哪些硬件平台](faqs-kernel.md#section868413518533)
-   [LiteOS内核已支持哪几款芯片架构](faqs-kernel.md#section1131661465417)

### 三方组件<a name="section4988163321816"></a>

-   [OpenHarmony已支持哪些三方组件](faqs-kernel.md#section74138185411)
-   [在OpenHarmony上使用OpenSSL，出现秘钥长度校验不正确](faqs-kernel.md#section10564614135516)
-   [setsockopt是否支持SO\_RCVBUF和SO\_SNDBUF选项](faqs-kernel.md#section2093373215556)

### 编译链接<a name="section080219574225"></a>

-   [Arm Linux开发的应用程序，如何在LiteOS-A上运行](faqs-kernel.md#section1164175713557)
-   [OpenHarmony在什么系统下编译，使用什么编译器](faqs-kernel.md#section132287223567)
-   [LiteOS-M上使用单独编译成静态库的三方组件，出现三方组件中的全局变量值不正确，或调用三方组件的函数后系统卡死](faqs-kernel.md#section15189154225619)
-   [LiteOS-A生成目标可执行文件，提示 use  VFP register arguments，xxx.o does not](faqs-kernel.md#section193571012578)
-   [clock\_gettime接口获取的时间打印不对](faqs-kernel.md#section8973152015717)

## 移植<a name="section129331824154313"></a>

-   [如何将用户的堆内存挂载进内核](faqs-transplant.md#section21471536184914)

## 启动恢复<a name="section83501764443"></a>

-   [系统启动过程中打印“parse failed!”错误后停止启动](faqs-init.md#section835662214302)
-   [系统启动过程未结束就自动重启，如此反复持续](faqs-init.md#section3857921143117)
-   [参数正确的情况下调用SetParameter/GetParameter返回失败](faqs-init.md#section548818116328)

## 系统服务<a name="section19567132114455"></a>

### 公共基础库<a name="section3214181711465"></a>

-   [LiteOS-A内核\(Hi3516、Hi3518平台\)KV存储路径设置错误，导致KV存储运行失败](faqs-system-using.md#section16520347131511)

### 视觉应用常见问题<a name="section295651815466"></a>

-   [是否存在一个全局变量，所有的页面都可以访问？](faqs-system-using.md#section187297991718)
-   [如何获取dom中的元素](faqs-system-using.md#section1833493719175)
-   [如何在页面间传值？](faqs-system-using.md#section184283812183)
-   [list如何滚动到某个item？](faqs-system-using.md#section11897734131811)
-   [text支持多行吗？](faqs-system-using.md#section5872656121814)
-   [为什么控件不显示？](faqs-system-using.md#section7397125317107)
-   [如何实现页面滑动？](faqs-system-using.md#section338794422010)
-   [Left、Top为什么不生效？](faqs-system-using.md#section2597193611217)
-   [动态绑定为什么不生效？](faqs-system-using.md#section6939050172115)
-   [如何实现相对定位和绝对定位？](faqs-system-using.md#section5547311192215)
-   [如何控制控件的显示与隐藏？](faqs-system-using.md#section16107113352213)
-   [使用Margin时，有什么注意事项？](faqs-system-using.md#section1524910142314)
-   [使用事件订阅时，有什么注意事项？](faqs-system-using.md#section1537132012231)
-   [使用动态绑定时，有什么注意事项？](faqs-system-using.md#section96561452236)
-   [swiper loop属性如何生效？](faqs-system-using.md#section690166112414)
-   [使用数组时，有什么注意事项？](faqs-system-using.md#section1554552822414)

### hdc<a name="section178081876506"></a>

-   [hdc\_std连接不到设备](faqs-system-using.md#section1965012223257)
-   [hdc\_std运行不了](faqs-system-using.md#section1157575212515)

