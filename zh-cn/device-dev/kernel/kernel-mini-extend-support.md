# C++支持


## 基本概念

C++作为目前使用最广泛的编程语言之一，支持类、封装、重载等特性，是在C语言基础上开发的一种面向对象的编程语言。


## 运行机制

C++代码的识别主要由编译器支持，系统主要对全局对象进行构造函数调用，进行初始化操作。


## 开发指导


### 接口说明

  **表1** C++支持接口

| 功能分类 | 接口名 | 描述 | 
| -------- | -------- | -------- |
| 使用C++特性的前置条件 | LOS_CppSystemInit | C++构造函数初始化 | 


### 开发流程

使用C++特性之前，需要调用函数LOS_CppSystemInit，实现C++构造函数初始化，其中被初始化的构造函数存在init_array这个段中，段区间通过变量__init_array_start__、__init_array_end__传递。

  **表2** 参数说明

| 参数 | 参数说明 | 
| -------- | -------- |
| __init_array_start__ | init_array段起始位置 | 
| __init_array_end__ | init_array段结束位置 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 调用该函数时，一定要在c++业务前。另外部分与系统资源强相关的类或接口，如std::thread，std::mutex等，在三方编译器使用的c库非musl c时，存在兼容性问题，不建议使用。


### 编程实例

  
```
void app_init(void)
{
......
/* 启动阶段C++初始化 */
LOS_CppSystemInit((UINTPTR)&__init_array_start__, (UINTPTR)&__init_array_end__);
/* C++业务 */
......
}
```
