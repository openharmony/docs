# Multithreaded Concurrency Overview (TaskPool and Worker)


## Overview

Concurrency models are used to implement concurrent tasks in different scenarios. Common concurrency models are classified into shared memory models and message passing models.

A typical message passing model is actor. It supports high-scale concurrency while eliminating a series of complex and occasional issues caused by locks.

Currently, ArkTS provides two concurrency capabilities: TaskPool and Worker, both of which are implemented based on the actor model.

[Comparison Between the Actor and Memory Sharing Models](actor-model-development-samples.md) provides an example of multithreaded concurrent programming based on the actor model.


## TaskPool and Worker

For details about the operation mechanisms and precautions, see [TaskPool Introduction](taskpool-introduction.md) and [Worker Introduction](worker-introduction.md). For details about their differences in the implementation features and use cases, see [Comparison Between TaskPool and Worker](taskpool-vs-worker.md).
