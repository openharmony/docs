# OpenHarmony文档共建计划--内核文档共建



| 2021-06-28-2021-07-30             | 2021-07-05                       | 2021-07-05-2021-07-30      | 2021-08-01-2021-08-31 |
| --------------------------------- | -------------------------------- | -------------------------- | --------------------- |
| **任务招募**                      | **线上会议**                     | **文档共建**               | **结项发布**          |
| ToDo List、文档模板、共建手册大纲 | 文档共建介绍、写作规范、常见操作 | 小组周进展跟踪、导师辅导制 | 发布共建后内核文档    |

- [如何参与](#section_register)
- [文档共建范围](#section_outline_summary)
- [文档大纲及认领明细](section_outline_detail)

## 共建活动ToDoList

OpenHarmony文档共建活动是由OpenHarmony社区举办，旨在进一步丰富和完善现有文档，提升文档体验**，**更好地服务于广大开发者。本次文档共建活动有共建移植文档、内核文档、Qemu仿真文档。详情请参考共建手册大纲：《基于Qemu运行OpenHarmony》、  《小型系统三方芯片移植指南》、《OpenHarmony内核开发指南》。

即日起开发者可自主选择并认领感兴趣的任务，获得社区资深**技术导师**和**文档导师**的指导。根据项目的难易程度和完成情况，参与者还将获得"**OpenHarmony 文档共建贡献者** " 荣誉及周边纪念品。

1. **活动时间：** 2021-06-28~2021-07-30

2. **招募对象：**

   - 技术写作者

   - 文档验证/审核者

   - 小组组织人员

3. **招募要求：**
- 熟悉嵌入式、物联网等OS开发相关知识
  
- 有扎实的C语言编程经验
  
- 有较强的文字写作能力、逻辑思维能力
  
4. **参与方式：**

   - Gitee社区内认领任务反馈
   - 开发者加入内核文档共建招募活动微信群
5. 共建激励规则

**卓越贡献奖**

- **奖励对象：**审核通过&内容被采纳的contributor。

- **奖励礼品：**OpenHarmonyT恤、帽子等周边纪念品。

  

## 如何参与<a name='section_register'></a>
- 方式1 [Issue回帖](https://gitee.com/openharmony/docs/issues/I3Y9MU?from=project-issue)
- 方式2 微信交流群报名
- 方式3 邮件反馈 @neeen @rtos_yuan ，邮件主题：OpenHarmony轻内核文档共建报名
3种方式均可报名，建议同时提供邮箱，方便后续发送线上会议交流通知。


## 文档共建范围 <a name='section_outline_summary'></a>

### 1、基于Qemu运行OpenHarmony---招募内容写作<a name='section_outline_qemu'></a>

- 背景

  - 对于想体验OpenHarmony的开发者，手头不一定有现成的开发板，基于Qemu可以降低入门体验门槛。

  - 已经支持Qemu，但是没有对应的文档, 快速入门只有3861、3516、3518等板子。

- 文档计划

  LiteOS-A、LiteOS-M Qemu使用教程第一时间上社区，社区化运作文档，降低社区开发者体验OpenHarmony开发的门槛。

-  **访问[《基于Qemu运行OpenHarmony 文档大纲》](#section_qemu_outline_detail)。**

### 2、小型系统三方芯片移植指南---招募内容体验&验证<a name='section_outline_porting'></a>

社区支持的开发板有限，三方芯片、开发板移植需要更丰富的开发板场景案例。 
- 文档计划

  - 鼓励开发者完善移植文档，支持社区开发者移植支持更多的开发板、支持手头的开发板能运行起来。
  - 鼓励移植经验文档回馈社区。

-  **访问[《小型系统三方芯片移植指南  文档大纲》](#porting_tutorial_outline_detail)。**

### 3、小型系统内核开发指南（LiteOS-A核）---招募内容体验&验证<a name='section_outline_kernel_tutorial'></a>

- 文档计划

  - 优化后内核文档初稿完成，鼓励开发者体验新内容，验证内容。
  - 社区化文档运作，鼓励社区开发者参与文档的优化编写，文档问题反馈。

-  **访问[《OpenHarmony 内核开发指南（LiteOS-A核） 文档大纲》](#kernel_a_tutorial_outline_detail)。**




##  文档大纲及认领明细<a name='section_outline_detail'></a>

✨**文档大纲用于维护文档的组成章节、章节意图，编写责任人，及PR合入状态**。

✨**使用对号[✔]表示文档的完成状态，第一个对号表示文档开发完成，第二个对号表示文档开发完成**。

### 一、基于Qemu运行OpenHarmony 文档大纲 <a name='section_qemu_outline_detail'></a>

#### 1 Qemu简介  [@rtos_yuan](https://gitee.com/rtos_yuan) [✔]  [@mgy917](https://gitee.com/mgy917) [✔]

   <!-- 简介Qemu用途，对社区开发者价值。 -->

#### 2 开发环境准备  [@mgy917](https://gitee.com/mgy917) [✔]  [@rtos_yuan](https://gitee.com/rtos_yuan) [✔]

- 2.1 OpenHarmony开发环境准备

  - 环境搭建  <!-- 介绍需要什么样的环境，可以链接跳转到相应章节 -->
  - 获取OpenHarmony源码

- 2.2 Qemu软件安装

   开发者根据需求，选择运行LiteOS-A、LiteOS-M的Qemu软件。

  - Qemu软件编译安装
  - Qemu-Virt软件
  - Qemu-Riscv32软件 [@zhushengle](https://gitee.com/zhushengle)  [✔]

<!-- 介绍如何搭建开发环境，如何获取Qemu工程源码，安装Qemu软件。环境准备等可以链接跳转 -->

####  3  Qemu工程源码介绍 [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

* 3.1 Qemu工程源码介绍

####  4 编译运行LiteOS-A Qemu Virt工程 [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

- 4.1 编译构建LiteOS-A <!--演示编译构建。 -->
- 4.2 运行镜像 <!-- 介绍如何准备镜像、如何配置、如何运行程序。 -->
  - 准备Flash镜像
  - 配置主机网桥
  - 运行程序

####  5 编译运行LiteOS-M Qemu Riscv工程 [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

- 4.1 编译构建LiteOS-M <!--演示编译构建。 -->
- 4.2 运行程序

### 二、小型系统三方芯片移植指南 <a name='porting_tutorial_outline_detail'></a>---招募内容体验&验证

#### 1 移植准备  [@arvinzzz](https://gitee.com/arvinzzz) [✔]  [@rtos_yuan](https://gitee.com/rtos_yuan) [✔]

   <!-- 简介移植须知和编译构建知识：流程、编译脚本、目录规则等 -->

##### 1.1 移植须知

##### 1.2 编译构建

#### 2 内核移植  [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

- 2.1 LiteOS-A内核

  <!-- 详细介绍如何移植OpenHarmony LiteOS-A内核 -->

  - 2.1.1 移植概述  <!-- 介绍移植场景、目录规范等 -->
  - 2.1.2 内核基础适配 <!-- 移植适配的具体步骤 -->
  - 2.1.3 内核移植验证  <!-- 验证移植是否成功 -->

- 2.2 Linux内核

  <!-- 详细介绍如何移植OpenHarmony Linux内核 -->

#### 3 板级移植  [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

<!-- 详细介绍如何移植驱动、HDI移植等 -->

###  三、小型系统内核开发指南（LiteOS-A核）<a name='kernel_a_tutorial_outline_detail'></a>---招募内容体验&验证

#### 1   认识LiteOS-A内核 [@kkup180](https://gitee.com/kkup180) [✔]  [@mgy917](https://gitee.com/mgy917) [✔]

 <!-- 介绍OpenHarmony LiteOS-A内核的内核架构、CPU体系支持与体系架构扩展 -->

- 1.1   简介
- 1.2   内核架构
- 1.3   CPU体系架构支持

#### 2   基础内核  [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

 <!-- OpenHarmony LiteOS-A 基础内核的概念、运行机制、开发指导、编程实例 -->

- 2.1   中断及异常处理
- 2.2   进程管理
- 2.3   线程管理
- 2.4   调度
- 2.5   内存管理
  - 2.5.1   堆内存管理
  - 2.5.2   虚拟内存管理
  - 2.5.3   物理内存管理
  - 2.5.4   虚实映射
- 2.6   IPC
  - 2.6.1   事件
  - 2.6.2   信号量
  - 2.6.3   互斥锁
  - 2.6.4   消息队列
  - 2.6.5   读写锁
  - 2.6.6   futex
  - 2.6.7   信号
- 2.7   系统调用
- 2.8   时间管理
- 2.9   软件定时器
- 2.10   原子操作
#### 3   扩展组件  [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

 <!-- OpenHarmony LiteOS-A 扩展组件的概念、运行机制、开发指导、编程实例 -->

- 3.1   ELF内核加载器
- 3.2   VDSO
- 3.3   LiteIPC
- 3.4   CPUP
- 3.5   C++支持
#### 4   文件系统  [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

 <!-- OpenHarmony LiteOS-A 文件系统的概念、运行机制、开发指导、编程实例 -->

- 4.1   vfs

- 4.2   支持的文件系统
  - 4.2.1   FAT
  - 4.2.2   jffs2
  - 4.2.3   nfs
  - 4.2.4   ramfs
  - 4.2.5   procfs
- 4.3   适配新的文件系统
#### 5   内核启动  [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]
- 5.1   运行机制
#### 6   用户态启动  [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]
- 6.1   用户态根进程启动
- 6.2   用户态程序运行
#### 7   调测  [@waitForContributor](https://gitee.com/openharmony/docs/issues)[ ？]

 <!-- OpenHarmony LiteOS-A 调测能力的概念、运行机制、开发指导、编程实例 -->

- 7.1   内存调测
- 7.2   Trace
- 7.3   魔法键
- 7.4   Dying gasp
- 7.5   常见问题定位方法
#### 8   附录  [@rtos_yuan](https://gitee.com/rtos_yuan) [✔]   [@harylee](https://gitee.com/harylee)[✔]
- 8.1   基本数据结构 <!-- 介绍下是数据结构的概念、功能接口说明、开发流程和编程实例。 -->
  - 8.1.1   双向链表
  - 8.1.2   位操作

