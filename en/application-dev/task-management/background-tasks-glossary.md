# Glossary

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=bcba4eb6a82c6ebe8d0c3166f67d73fa0ca90c14 translatedAt=2026-08-17T10:41:33.863Z pushedAt=2026-08-17T10:46:40.688Z -->

## C

### ContinuousTask

A type of long-running, user-perceptible background tasks, such as background music playback, navigation, and device connection. Use a continuous task to prevent the app process from being suspended.

## T

### Transient Task

A type of tasks that require high real-time performance and are not time-consuming, such as state saving and message sending. A transient task can be requested to extend the running time of an app in the background.

### Transparency Quota

A time quota management mechanism for transient tasks. An app is allocated a certain transient task quota, and once the quota is exhausted, no further transient task requests are allowed.

## W

### WorkScheduler

A deferred task scheduling mechanism provided by the system for tasks that do not require high real-time performance and can be executed with a delay. When conditions are met, the system schedules and launches the app based on factors such as memory and power consumption.

### WorkSchedulerExtensionAbility

The callback extension capability for deferred tasks, which implements the [onWorkStart](../reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md#onworkstart) and [onWorkStop](../reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md#onworkstop) methods to handle the start and end callbacks of deferred tasks.