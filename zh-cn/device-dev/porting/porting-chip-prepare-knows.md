# 移植须知


本文为OpenHarmony平台系统开发人员和芯片（或模组）制造商提供基础的开发移植指导，典型的芯片架构例如cortex-m系列、risc-v系列等都可以按照本文进行移植，暂时不支持蓝牙服务。OpenHarmony是个持续演进的复杂项目，随着版本和API的改变，本文将会不断更新。


本文要求读者具有一定的嵌入式系统开发经验，因此它的重点未放在基本的OS基础介绍，而更多地描述OpenHarmony平台移植过程中主要操作和所需要关注的方面。


## 移植目录

OpenHarmony整体工程较为复杂，目录及实现为系统本身功能，如果不涉及复杂的特性增强，不需要关注每一层实现，移植过程中重点关注如下目录即可：

  **表1** 移植过程中的重点目录

| 目录名称 | 描述 | 
| -------- | -------- |
| /build/lite | OpenHarmony基础编译构建框架 | 
| /kernel/liteos_m | 基础内核，其中芯片架构相关实现在arch目录下 | 
| /device | 板级相关实现，各个三方厂商按照OpenHarmony规范适配实现，device下具体目录结构及移植过程参见[板级系统移植](../porting/porting-chip-board-overview.md) | 
| /vendor | 产品级相关实现，主要由华为或者产品厂商贡献 | 

device目录规则：device/{芯片解决方案厂商}/{开发板}。以hisilicon的hispark_taurus为例：

  
```
device
└── hisilicon                      # 芯片解决方案厂商名
    ├── common                     # 芯片解决方案开发板公共部分
    └── hispark_taurus             # 开发板名称
        ├── BUILD.gn               # 开发板编译入口
        ├── hals                   # 芯片解决方案厂商OS硬件适配
        ├── linux                  # linux版本
        │   └── config.gni         # linux版本编译工具链和编译选项配置
        └── liteos_a               # liteos-a版本
            └── config.gni         # liteos-a版本编译工具链和编译选项配置
```


vendor目录规则：vendor/{产品解决方案厂商}/{产品名称}。以华为的wifiiot产品为例：


  
```
vendor                       # 产品解决方案厂商
└── example                  # 产品解决方案厂商名称
    └── wifiiot              # 产品名称
          ├── hals           # 产品解决方案厂商OS适配
          ├── BUILD.gn       # 产品编译脚本
          └── config.json    # 产品配置文件
```


## 移植流程

OpenHarmony的device目录是基础芯片的适配目录，如果在三方芯片应用过程中发现此目录下已经有完整的芯片适配，则不需要再额外移植，直接跳过移植过程进行系统应用开发即可，如果该目录下无对应的芯片移植实现，则根据本文完成移植过程。OpenHarmony三方芯片移植主要过程如下：

  **图1** 芯片移植关键步骤

  ![zh-cn_image_0000001200336823](figures/zh-cn_image_0000001200336823.png)


## 移植规范

- 满足OpenHarmony[开源贡献基本规范和准则](../../contribute/参与贡献.md)。

- 三方芯片适配所需要贡献的代码主要在device、vendor和arch三个目录，参照[内核目录规范](../porting/porting-chip-kernel-overview.md)和[板级目录规范](../porting/porting-chip-board-overview.md#板级目录规范)满足基本目录命名和使用规范。
