# 公共基础类库开发指导
## 概述
公共基础类库存放OpenHarmony通用的基础组件。这些基础组件包括一些常用的C、C++、JS开发增强API，可被OpenHarmony各业务子系统及上层应用所使用。公共基础类库子系统包含如下代码仓库：
```
/commonlibrary
    ├── c_utils                  # c/c++标准库之外方便开发者开发的基础工具库
    ├── ets_utils                # js标准库之外的与语言强相关的基础库
    └── utils_lite               # lite上使用的工具函数，涉及c和js语言
```
各仓库提供的功能列表如下：

**c_utils**

-   文件、路径、字符串相关操作的能力增强接口；
-   读写锁、信号量、定时器、线程增强及线程池等接口；
-   安全数据容器、数据序列化等接口；
-   各子系统的错误码相关定义。

**ets_utils**

-   JS中URI、URL、xml相关操作接口；
-   JS中字符编解码接口；
-   JS中进程相关操作接口；
-   JS中多线程能力。

**utils_lite**

-   标准文件相关操作HAL接口；
-   其它一些内部功能，如定时器等。

## 各仓库开发指导
[C++公共基础库(c_utils)说明文档](https://gitee.com/openharmony/commonlibrary_c_utils/blob/master/README_zh.md)

## 公共基础类库常见问题
### c_utils常见问题
具体各应用场景常见问题，参见[C++公共基础库(c_utils)说明文档](https://gitee.com/openharmony/commonlibrary_c_utils/blob/master/README_zh.md)。