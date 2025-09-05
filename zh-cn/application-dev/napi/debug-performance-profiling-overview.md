# 调试和性能分析概述
<!--Kit: Common-->
<!--Subsystem: Common-->
<!--Owner: @fang-jinxu-->
<!--Designer: @lingminghw-->
<!--Tester: @RayShih-->
<!--Adviser: @fang-jinxu-->

通过NDK开发C/C++程序不可避免会遇到Native程序常见的异常、性能等问题，NDK随包提供了常用的调试调优工具，方便开发者定位问题。

- 已提供如下方式进行调试和性能分析：

  - [C/C++内存错误检测](debug-asan.md)
  - 通过DevEco Studio调试
    - [1.C/C++反向调试](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-debug-native-reverse)
    - [2.使用真机进行调试](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-debug-device)
    >**注意**：在[使用真机进行调试](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-debug-device)中，如果本地编译设备so文件的源码路径和当前配置的C++源码路径不一致，可以参考[三方源码调试](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-source-code-debugging)
