# 方舟编译运行时子系统变更说明
## cl.arkcompiler.1 __assert_fail变更

**访问级别**

公开接口

**变更原因**

在debug模式下，断言失败后提供了新的操作功能，在assert窗口上，点击“继续”按钮，出现窗口页面卡死；需要移除__assert_fail函数上的_Noreturn标记。

**变更影响**

该变更为非兼容性变更。

API version 11及之前，对已经编译出来的存量应用不受影响。

API version 12及以后，当使用assert(0)进行断言时，因为0是一个false值常量，所以编译器不会对assert(0)之后的代码进行汇编优化，即assert函数之后的代码会被编译出来，程序体积可能会增大；断言失败后，如果选择“继续”执行，被额外编译出来的代码将会被执行。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.26 版本开始。

**变更的接口/组件**

变更前：_Noreturn void __assert_fail (const char *, const char *, int, const char *);
变更后：void __assert_fail(const char *, const char *, int, const char *);

**适配指导**

asert使用方式不变，不需要适配。