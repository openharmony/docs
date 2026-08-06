# Glossary<!--kernel-enhance-kit-->

<!--Kit: Kernel Enhance Kit-->
<!--Subsystem: Kernel-->
<!--Owner: @yzl-kongzhenhua; @Leibobo-->
<!--Designer: @wangxiayang-->
<!--Tester: @lianxuanself; @laonie666; @panny060-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=c797f7f528e04799a6c5b9690344c26ba3c1d450 translatedAt=2026-08-04T13:30:29.328Z pushedAt=2026-08-05T08:10:40.037Z -->

## G

### Gewu

A QoS-aware inference acceleration and resource management optimization service for on-device inference scenarios. It dynamically loads inference model resources on demand and optimizes scheduling based on QoS levels, enabling efficient on-device inference while keeping the user experience smooth. Gewu helps address challenges such as limited memory, limited compute resources, and power sensitivity on end-side devices. This capability is available from API version 20.

### Gewu Request

An on-device inference task submitted to a Gewu session. A Gewu request is executed asynchronously. The API only initiates the request and does not directly return the result. After inference is complete, the result is returned through the callback registered by the user. Both streaming and non-streaming inference modes are supported, and a request can be terminated early through the abort API.

### Gewu Session

The basic unit in the Gewu service for managing inference resources and processing requests. Attributes such as the model path are specified when a session is created. Resources are loaded asynchronously. The session lifecycle starts when the session is created successfully and ends when the destroy API is called. Multiple inference requests can be submitted within a session.

## K

### Kernel Enhance Kit

A kernel enhancement development kit provided by OpenHarmony. It includes QoS scheduling, Purgeable Memory management, and Gewu on-device inference services, and is used to optimize application performance, resource management, and user experience.

## P

### Purgeable Memory

    A memory management mechanism that allows memory to be discarded at any time. It is used to store data that can be easily rebuilt by recalculation. When the system is under memory pressure, this type of anonymous-page memory is preferentially reclaimed by dropping it directly instead of compressing it. When users access it again, they need to restore the data by using a rebuild function. Purgeable Memory is suitable for managing large data blocks of at least 4 KiB when the rebuild cost is low.

## Q

### Quality of Service (QoS)

A priority scheduling attribute of tasks in OpenHarmony. Developers classify tasks based on how closely they are related to user interaction. The system then arranges CPU time allocation and scheduling order, improving application responsiveness and resource utilization.

## S

### Streaming Inference

One of the inference modes supported by the Gewu service. After streaming inference is enabled, inference results are returned progressively through multiple callbacks. Each callback returns partial content, and only the final callback carries a non-empty stop reason. This mode is suitable for scenarios where the generation process needs to be displayed in real time. When streaming is disabled, non-streaming inference is used and the complete result is returned at one time.