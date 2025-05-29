# CPU轻量级隔离特性介绍


## 基本概念

CPU轻量级隔离特性提供了根据系统负载和用户配置来选择合适的CPU进行动态隔离的能力。内核会将被隔离CPU上的任务和中断迁移到其他合适的CPU上执行，被隔离的CPU会进入ilde状态，以此来达到功耗优化的目标。同时提供用户态的配置和查询接口来实现更好的系统调优。


## 配置指导

### 使能CPU轻量级隔离特性
打开相关配置项及依赖。启用CPU轻量级隔离，需要通过编译内核时打开相应的配置项及依赖，相关CONFIG如下：

```
CONFIG_CPU_ISOLATION_OPT=y
CONFIG_SCHED_CORE_CTRL=y
```

另有部分CONFIG被依赖：

```
CONFIG_SMP=y
CONFIG_SCHED_WALT=y
```
## 相关接口

CPU轻量级隔离提供了一些接口用于控制CPU隔离核的个数以及记录当前状态，支持以CPU cluster层级进行配置，这些接口位于每个CPU cluster的首个CPU设备信息目录中，如`/sys/devices/system/cpu/cpu0/core_ctl`。

| 功能分类 | 接口名          | 描述                                       |
| ---- | ------------ | ---------------------------------------- |
| 控制接口 | enable       | 功能开关，1表示开启，0表示关闭。                         |
|      | min_cpus     | 设置活跃（未隔离）CPU最小值个数。                        |
|      | max_cpus     | 设置活跃（未隔离）CPU最大值个数，其中最大值为CPU cluster包含的CPU个数。 |
| 状态接口 | active_cpus  | 显示当前活跃（未隔离）的CPU个数。                        |
|      | need_cpus    | 显示当前需要解隔离的CPU个数。                          |
|      | global_state | 记录系统所有CPU cluster的状态信息，包含CPU 隔离状态，online状态以及负载信息等。 |
