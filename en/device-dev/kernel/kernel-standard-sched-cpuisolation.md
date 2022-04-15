# Lightweight CPU Isolation


## Basic Concepts

Lightweight CPU isolation enables dynamic CPU isolation based on the system load and user configuration. The kernel migrates the tasks and interrupts from the isolated CPU to other CPUs for execution. The isolated CPU enters the idle state, which reduces the power consumption. In addition, user-mode configuration and query APIs are provided for better system optimization.


## Configuration

### Enabling Lightweight CPU Isolation
Enable related configuration items and dependencies.

To enable lightweight CPU isolation, you need to enable the corresponding configuration items and dependencies during kernel compilation. The related configuration items are as follows:

```
CONFIG_CPU_ISOLATION_OPT=y
CONFIG_SCHED_CORE_CTRL=y
```

Enable the following dependencies:

```
CONFIG_SMP=y
CONFIG_SCHED_WALT=y
```
## Available APIs

APIs are provided to set the number of isolated CPU cores and record the current status. Configurations can be performed based on CPU clusters. These APIs are located in the first CPU device directory of each CPU cluster, for example, `/sys/devices/system/cpu/cpu0/core_ctl`.

| Category| API         | Description                                      |
| ---- | ------------ | ---------------------------------------- |
| Control API| enable       | Enables or disables the lightweight CPU isolation. The value **1** means enable, and **0** means disable.                        |
|      | min_cpus     | Sets the minimum number of active (not isolated) CPUs.                       |
|      | max_cpus     | Sets the maximum number of active (not isolated) CPUs. The maximum value is the number of CPUs in a CPU cluster.|
| Status API| active_cpus  | Obtains the number of active (not isolated) CPUs.                       |
|      | need_cpus    | Obtains the number of CPUs to de-isolate.                         |
|      | global_state | Records the status of all CPU clusters in the system, including the CPU isolation status, online status, and load information.|
