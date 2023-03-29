# 关联线程组调度特性介绍


## 基本概念

关联线程组(related thread group)提供了对一组关键线程调度优化的能力，支持对关键线程组单独进行负载统计和预测，并且设置优选CPU cluster功能，从而达到为组内线程选择最优CPU运行并且根据分组负载选择合适的CPU调频点运行。


## 配置指导

### 使能关联线程组
打开相关配置项及依赖。启用关联线程组功能，需要通过编译内核时打开相应的配置项及依赖，相关CONFIG如下：

```
CONFIG_SCHED_RTG=y
CONFIG_SCHED_RTG_DEBUG=y
CONFIG_SCHED_RTG_FRAME=y
CONFIG_SCHED_RTG_RT_THREAD_LIMIT=y
```

另有部分CONFIG被依赖：

```
CONFIG_SCHED_WALT=y
```
### 添加进程/线程到关联线程组中

内核中默认创建出20个可用的关联线程组，其中group id=1的分组为预留分组，不支持添加进程/线程：

```Bash
// 将指定pid的进程添加到group id为2的关联线程组中
echo 2 > /proc/<pid>/sched_group_id
// 将指定pid的进程从group id为2的关联线程组中移出，其中group id=0表示非关联线程组
echo 0 > /proc/<pid>/sched_group_id
```
### 查看关联线程组信息

关联线程组信息包含group id，分组优选CPU cluster id，分组内线程信息等。

  ```Bash
cat /proc/sched_rtg_debug
// 例如执行后显示如下：
RTG_ID          : 2                          // 分组id
RTG_INTERVAL    : UPDATE:8ms\#INVALID:4294ms // CPU调频间隔和负载有效时长
RTG_CLUSTER     : -1                         // CPU cluster id，其中-1表示未设置优选cluster
RTG_THREADS   : 0/1                          // 分组包含的线程总数
STATE           COMM       PID  PRIO    CPU  // 线程信息（状态/名称/pid/优先级/所在CPU编号）
---------------------------------------------------------
    S            bash   436   120     1(0-3)
  ```