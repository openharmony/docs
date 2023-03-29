# Related Thread Group


## Basic Concepts

The Related Thread Group (RTG) provides optimized scheduling of a group of important threads. The load of an RTG can be collected and predicted separately and the preferred CPU cluster can be set to allow the important threads to run on the optimal CPU and the kernel to select a proper CPU frequency based on the group loads.


## Configuration

### Enabling RTG
To enable RTG, you need to enable the related configuration items and dependencies during kernel compilation. The related configuration items are as follows:

```
CONFIG_SCHED_RTG=y
CONFIG_SCHED_RTG_DEBUG=y
CONFIG_SCHED_RTG_FRAME=y
CONFIG_SCHED_RTG_RT_THREAD_LIMIT=y
```

Enable the following dependencies:

```
CONFIG_SCHED_WALT=y
```
### Adding a Process or Thread to an RTG

By default, 20 RTGs are created in the kernel. The group with ID of 1 is reserved and cannot be added with any process or thread.

```Bash
// Add a process to an RTG.
echo 2 > /proc/<pid>/sched_group_id
// Remove a process from an RTG. The group with ID of 0 is not an RTG.
echo 0 > /proc/<pid>/sched_group_id
```
### Obtaining RTG Information

The RTG information includes group ID, preferred CPU cluster ID, and thread information.

  ```Bash
cat /proc/sched_rtg_debug
// The following information is displayed:
RTG_ID          : 2                          // RTG ID.
RTG_INTERVAL    : UPDATE:8ms\#INVALID:4294ms // CPU frequency modulation interval and valid load duration.
RTG_CLUSTER     : -1                        // CPU cluster ID. The value **-1** means that the preferred cluster is not set.
RTG_THREADS: 0/1                          // Total number of threads in the group.
STATE           COMM       PID  PRIO    CPU  // Thread information, including the status, name, PID, priority, and CPU ID.
---------------------------------------------------------
    S            bash   436   120     1(0-3)
  ```
