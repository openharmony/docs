# About This Kit

<!--Kit: Kernel Enhance Kit-->
<!--Subsystem: Kernel-->
<!--Owner: @gatieme; @fang-jinxu; @yzl-kongzhenhua-->
<!--Designer: @tanyihua; @lingminghw; @wangxiayang-->
<!--Tester: @panny060; @RayShih; @lianxuanself-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=84e5c687623c619df721fa927b62d6782396d98d translatedAt=2026-08-04T13:30:04.807Z pushedAt=2026-08-05T08:14:48.417Z -->

## Function Description

Kernel Enhance Kit provides kernel enhancement capabilities, including Quality of Service (QoS) scheduling, Purgeable Memory management, and the Gewu service. These capabilities help you optimize application performance, resource management, and user experience.

- **QoS**: Provides task priority scheduling. You can set different QoS levels for tasks based on task importance and the degree of association with user interaction. The system allocates CPU time and determines the scheduling order based on QoS levels to optimize application responsiveness and resource utilization.

- **Purgeable Memory**: Provides a memory management mechanism that allows memory to be discarded at any time. It is used to store data that can be easily rebuilt by recalculation. When system memory is low, this mechanism can directly release the memory and rebuild the data when users access it again. It is suitable for storing large data blocks with low rebuild cost.

- **Gewu service**: Provides QoS-aware on-device inference acceleration and resource management optimization. To address challenges in on-device inference, such as limited memory, limited compute resources, and power sensitivity, the Gewu service provides capabilities such as dynamic on-demand resource loading and inference acceleration. It enables efficient inference while maintaining a smooth user experience.

## Basic Concepts

### QoS

QoS refers mainly to the priority scheduling attribute of tasks in OpenHarmony. Developers can use QoS to classify work to be executed and indicate how closely it is related to user interaction. The system arranges the runtime and execution order of tasks based on the QoS settings.

OpenHarmony defines six QoS levels. From low to high, the degree of association with user interaction increases. The `QOS_*` items in the following table are API enum names.

| QoS Level | Scenario | Load Characteristics |
| -------- | -------- | -------- |
| QOS_BACKGROUND | Background tasks invisible to users, such as data synchronization and backup. | The task takes minutes to hours to complete. |
| QOS_UTILITY | Tasks that do not require an immediate visible response, such as downloading or importing data. | The task takes seconds to minutes to complete. |
| QOS_DEFAULT | Default. | The task takes a few seconds to complete. |
| QOS_USER_INITIATED | User-initiated tasks with visible progress, such as opening a document. | The task completes within a few seconds. |
| QOS_DEADLINE_REQUEST | Time-critical tasks where faster is better, such as page loading. | The task completes almost instantly. |
| QOS_USER_INTERACTIVE | User interaction tasks (UI thread, screen refresh, animations). | The task is instantaneous. |

### Purgeable Memory

Purgeable Memory refers to memory areas that can be discarded at any time. It is used to store data that can be easily rebuilt by recalculation. When system memory is low, this data can be released directly and rebuilt when users access it again. Purgeable Memory is suitable for storing large data blocks of at least 4 KiB when the rebuild cost is low. When the system is under pressure, Purgeable Memory is preferentially reclaimed. Anonymous pages are dropped in a way similar to file pages instead of being compressed. Before the data is used again, users need to restore it by themselves.

### Gewu Service

The Gewu service is a QoS-aware inference acceleration and resource management optimization service for on-device inference scenarios. On-device inference helps protect user data privacy, lowers deployment costs, reduces latency, and provides high availability without relying on network connections. However, it also faces challenges such as limited memory, limited compute resources, and power sensitivity. Through optimization methods such as dynamic on-demand resource loading and QoS-aware scheduling, the Gewu service enables efficient inference while maintaining a smooth user experience.

## Benefits

### QoS Optimization

Proper use of QoS can significantly improve app performance:

- **Thread execution optimization**: By setting appropriate QoS levels for key threads, you can reduce thread wait time, increase the proportion of runtime, and reduce the proportion of time spent preempted.

- **React Native (RN) framework optimization**: After key threads in the RN framework are properly marked with QoS levels, performance in open-source benchmark tests improves by about 13%.

### Purgeable Memory Optimization

Purgeable Memory is preferentially reclaimed when the system is under pressure, which can effectively relieve memory pressure.

- It is suitable for storing large data blocks of at least 4 KiB when the rebuild cost is low.

- It is released directly instead of being compressed when system memory is low.

- Users rebuild the data when it is used again.

### Gewu Service Optimization

The Gewu service provides the following optimizations for on-device inference scenarios:

- **Resource management optimization**: Dynamically loads resources on demand to avoid resource waste.

- **QoS-aware scheduling**: Schedules inference tasks based on their importance to maintain a smooth user experience.

- **Inference acceleration**: Improves inference efficiency by optimizing resource management and scheduling.

## Constraints

### QoS Constraints

- QoS APIs can set only the QoS level of the current task, not the QoS level of other tasks.

### Purgeable Memory Constraints

- It is suitable for storing large data blocks of at least 4 KiB when the rebuild cost is low.

- Users need to restore the data by themselves before using it again.

### Gewu Service Constraints

- The Gewu service is supported since API version 20.

- The related dynamic library `libqos.so` is required.

## References

- [QoS Development](qos-guidelines.md)

- [Purgeable Memory Development](purgeable-memory-guidelines.md)

- [Gewu Service Development](gewu-ndk-api-guidelines.md)