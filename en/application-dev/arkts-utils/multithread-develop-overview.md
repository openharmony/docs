# Multithreaded Development Overview

During ArkTS application development, the concurrency capability is required in many service scenarios. Different service scenarios require different concurrency capabilities and correspond to different task types.

For common service scenarios, there are three types of concurrent tasks: [time-consuming task](time-consuming-task-overview.md), [continuous task](long-time-task-overview.md), and [resident task](resident-task-overview.md).

Different types of tasks can be further divided. For example, typical time-consuming tasks include CPU-intensive tasks, I/O-intensive tasks, and synchronization tasks, which correspond to different typical service scenarios. Select the concurrency capability based on the scenario-based task type.

The following sections describe some common scenarios during multi-thread development of applications.
