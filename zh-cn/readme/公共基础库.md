# 公共基础库<a name="ZH-CN_TOPIC_0000001092539399"></a>

-   [简介](#section11660541593)
-   [目录](#section17271017133915)
-   [相关仓](#section1249817110914)

## 简介<a name="section11660541593"></a>

公共基础类库提供了一些常用的C、C++开发增强API。包括如下部分：

**C++部分：**

-   文件、路径、字符串相关操作的能力增强接口；
-   读写锁、信号量、定时器、线程增强及线程池等接口；
-   安全数据容器、数据序列化等接口；
-   各子系统的错误码相关定义；
-   C语言安全函数接口。

**C部分：**

-   简易的数据存取接口kv\_store；
-   标准文件相关操作HAL接口；
-   其它一些内部功能，如定时器等。

## 目录<a name="section17271017133915"></a>

```
/utils
    ├── native                  # 工具类的native层实现
    ├── ndk_libraries_config    # ndk库的配置目录
    └── system                  # 系统相关的预定义值和安全策略配
```

## 相关仓<a name="section1249817110914"></a>

**公共基础库子系统**

utils

utils\_native

[utils\_native\_lite](https://gitee.com/openharmony/utils_native_lite)

