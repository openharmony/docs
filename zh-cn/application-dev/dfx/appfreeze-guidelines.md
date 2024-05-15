# 分析AppFreeze（应用无响应）


用户在使用应用时会出现点击没反应、应用无响应等情况，其超过一定时间限制后即被定义为应用无响应(appfreeze)。系统提供了检测应用无响应的机制，并生成appfreeze日志供应用开发分析。


> **说明：**
> 本文仅适用于Stage模型下的应用使用。且在根据本文分析日志前，需要开发者对JS在系统中运行情况、C++程序堆栈信息有相关基础知识，并对应用相关的子系统有一定了解。

## 获取方式

应用无响应日志是一种故障日志，与Native进程崩溃、JS应用崩溃、系统进程异常等都由FaultLog模块管理，可通过以下方式获取日志：

- 方式一：通过DevEco Studio获取日志

    DevEco Studio会收集设备的故障日志并归档到FaultLog下。具体可参考[DevEco Studio使用指南-FaultLog](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V2/ide-debug-hilog-0000001172459337-V2#section974519209435)。

- 方式二：通过hiappevent获取

    hiappevent对外提供订阅系统卡死事件，可以查询卡死事件信息，详见[订阅系统事件（卡死事件）](hiappevent-watcher-freeze-events.md)。
<!--Del-->
- 方式三：通过shell获取日志

    应用无响应日志是以appfreeze-开头，生成在”设备/data/log/faultlog/faultlogger/”路径下。该日志文件名格式为“appfreeze-应用包名-应用UID-秒级时间”。

    ![appfreeze_20230308145160](figures/appfreeze_20230308145160.png)
<!--DelEnd-->
## 应用无响应检测能力点

目前应用无响应检测从以下维度检测，应用开发者了解其原理对定位和分析appfreeze故障非常有帮助。

| 故障类型 | 说明 |
| -------- | -------- |
| THREAD_BLOCK_6S | 应用主线程卡死超时 |
| APP_INPUT_BLOCK | 用户输入响应超时 |
| LIFECYCLE_TIMEOUT | Ability生命周期切换超时 |

### THREAD_BLOCK_6S 应用主线程卡死超时

该故障出现表示当前应用主线程有卡死或者执行任务过多的情况，影响任务执行的流畅度和体验。

该事件的检测原理是：应用的watchdog线程定期向主线程插入判活检测，并在自己线程插入超时上报机制。当判活检测超过3s没有被执行，会上报THREAD_BLOCK_3S警告事件；超过6s依然没有被执行，会上报THREAD_BLOCK_6S主线程卡死事件。两个事件匹配生成THREAD_BLOCK的应用无响应日志。

检测原理如下图：

![appfreeze_20230308145163](figures/appfreeze_20230308145163.png)

### APP_INPUT_BLOCK 用户输入响应超时

该故障是指用户的点击事件超过一定时间限制未得到响应，严重影响当前用户体验。

该事件的检测原理是：用户点击应用的按钮时，输入系统会向应用侧发送点击事件，但超时未收到应用侧的响应反馈回执，则上报该故障。

检测原理如下图：

![appfreeze_20230308145162](figures/appfreeze_20230308145162.png)

### 生命周期切换超时

生命周期切换超时分为Ability生命周期切换超时和App生命周期切换超时。

该故障出现在生命周期切换的过程中，影响当前应用内Ability的切换或者不同APP之间的切换。

该事件的检测原理是：通过获取不同生命周期切换的过程，在生命周期切换开始的位置向watchdog线程插入超时任务，在生命周期切换完成之后移除超时任务，固定时间内未成功移除将上报故障。

生命周期切换超时由LIFECYCLE_HALF_TIMEOUT和LIFECYCLE_TIMEOUT两个事件组合而成。LIFECYCLE_HALF_TIMEOUT作为LIFECYCLE_TIMEOUT的警告事件，抓取binder等信息。

![appfreeze_20230308145164](figures/appfreeze_20230308145164.png)

不同的生命周期，超时的时间不一样：

| 生命周期 | 超时时间 | 
| -------- | -------- |
| Load | 10s | 
| Terminate | 10s | 
| Connect | 3s | 
| Disconnect | 0.5s | 
| Foreground | 5s | 
| Background | 3s | 

## 应用无响应日志分析

应用无响应(appfreeze)故障需要结合应用无响应日志和流水hilog日志一起分析。

当前示例仅提供一个分析方法，请开发者根据具体问题具体分析。

应用无响应日志主要分以下几个模块信息：

### 日志头部信息

| 字段 | 说明 | 
| -------- | -------- |
| Reason | 应用无响应原因，与[应用无响应检测能力点](#应用无响应检测能力点)对应 | 
| PID | 发生故障时候的pid，可以用于在流水日志中搜索相关进程信息 | 
| PACKAGE_NAME | 应用进程包名 | 

![appfreeze_20230310105865](figures/appfreeze_20230310105865.png)

### 日志主干通用信息

以上三种日志都包含以下几部分信息，可以通过搜索“主要信息字段”在日志中找到对应的位置：

| 主要信息字段 | 说明 | 
| -------- | -------- |
| EVENTNAME | 应用无响应原因，或者组成卡死检测的不同事件 | 
| TIMESTAMP | 发生故障时上报时刻的事件，可以根据[应用无响应检测能力点](#应用无响应检测能力点)中说明的超时时间，在相应流水日志中缩小查看日志的时间范围 | 
| PID | 发生故障时候的pid，可以与发生时间和超时时间配合用于在流水日志中搜索相关进程信息 | 
| PACKAGE_NAME | 应用进程包名 | 
| MSG | 发生故障时dump信息或者说明信息，后面具体说明 | 
| BinderCatcher | 进程与其他系统进程间通信的调用信息，显示调用等待时间长的情况 | 
| PeerBinder Stacktrace | 跟当前进程相关的对端进程有卡死，会抓取对端的进程堆栈 | 
| cpuusage | 跟当前时间段整机CPU使用情况 | 
| memory | 跟当前时间当前进程的内存使用情况 | 

MSG字段信息主要包括卡死上报的原因，以及当前应用主线程的队列中任务堆积信息。

主线程队列中任务堆积信息包括：

- 当前正在运行的任务以及任务启动的时间：如果跟当前日志上报的时间相差很大，则当前运行的任务就是卡死的主要任务事件。

- 历史任务时间：可判断是否由于历史任务过多且每一个任务执行都占一定时间，导致当前的新任务运行时无法及时响应。

- 正在堆积还没有执行的任务。

**当前进程堆栈示例：**

通过搜索pid对应的数字找到应用栈信息。以下堆栈示例表明窗口通过IPC向系统发送事件时，停留在IPC通信阶段。

![appfreeze_20230310105869](figures/appfreeze_20230310105869.png)

**BinderCatcher信息示例：**

通过搜索pid对应的数字找到当前进程与哪个进程在通信，同步的通信等待的时长。

示例表明当前1561进程向685进程请求通信，等待超过10s没有得到响应。

![appfreeze_20230310105868](figures/appfreeze_20230310105868.png)

**PeerBinder Stacktrace信息示例：**

示例表明对端卡死进程685的堆栈信息。

![appfreeze_20230310105870](figures/appfreeze_20230310105870.png)

**cpuusage信息示例：**

整机CPU信息。

![appfreeze_20230310105871](figures/appfreeze_20230310105871.png)

**memory信息示例：**

当前进程内存信息。

![appfreeze_20230310105872](figures/appfreeze_20230310105872.png)

### 日志主干特异性信息(应用主线程卡死超时)

Reason是THREAD_BLOCK_6S的日志。根据前面的[应用主线程卡死超时](#thread_block_6s-应用主线程卡死超时)的原理可知，THREAD_BLOCK由THREAD_BLOCK_3S和THREAD_BLOCK_6S两部分组成。将两部分日志对比分析，可更准确的判断是卡死还是执行任务过多造成无法响应的情况。

THREAD_BLOCK_3S在日志的前部分，THREAD_BLOCK_6S在THREAD_BLOCK_3S后面写入。可以通过EVENTNAME字段搜索两个事件在日志中的位置。

两个事件中都包含MSG字段，该字段在应用主线程卡死超时故障中写入了当前主线程处理队列的信息，可查看在两个时间点中主线程事件处理队列排队情况。

示例日志显示了在Low priority的队列中05:06:18.145的事件一直在处理，THREAD_BLOCK_3S和THREAD_BLOCK_6S的队列都显示其存在。这说明主线程卡死不是任务过多情况。

由于THREAD_BLOCK_6S是主线程卡死，进程堆栈信息只需要关注主线程的堆栈(主线程线程号跟进程号相同)。当前示例日志主线程堆栈显示通过ArkUI控件到JS运行，说明卡死在Js代码中。3S和6S都是这个位置的堆栈，说明JS有卡死，但原因排除任务过多导致。

THREAD_BLOCK_3S：

![appfreeze_20230310105866](figures/appfreeze_20230310105866.png)

THREAD_BLOCK_6S：

![appfreeze_20230310105867](figures/appfreeze_20230310105867.png)

再结合流水日志查看当前应用侧是在执行哪块代码。

一般情况下可以查看以上[通用日志信息](#日志主干通用信息)内容，判断是否存在对端通信卡死，整机CPU消耗很高导致当前应用响应不过来，内存泄漏，内存非常多导致任务无法运行的情况。

### 日志主干特异性信息(用户输入响应超时)

Reason是APP_INPUT_BLOCK，表明用户点击事件超过5s没有得到反馈。

MSG信息是这个事件的说明：用户的输入没有得到响应。

APP_INPUT_BLOCK的日志信息可以参考[通用日志信息](#日志主干通用信息)进行分析。需特别说明的是，一般情况下用户输入无响应大概率主线程也会卡死。可以结合两个日志的三个堆栈、两个BinderCatcher信息，进行对比查看。如果没有主线程卡死的日志，说明有可能在输入事件之前有大量的细碎的其他事件，细碎的事件不足以卡死主线程，但是数量比较多导致用户的输入事件响应不过来。

### 日志主干特异性信息(生命周期切换超时)

Reason是LIFECYCLE_TIMEOUT的日志与上文THREAD_BLOCK_6S和THREAD_BLOCK_3S一样都是有两个事件。分别是LIFECYCLE_HALF_TIMEOUT和LIFECYCLE_TIMEOUT

MSG说明当前是什么生命周期的超时。

示例可以看出，LIFECYCLE_TIMEOUT的可以看出Ability在切换后台的时候超时，可以按照上面[生命周期切换超时](#生命周期切换超时)的超时时间来找流水日志等信息。

LIFECYCLE_TIMEOUT：

![appfreeze_20230310105873](figures/appfreeze_20230310105873.png)

其他的日志信息可以参考[通用日志信息](#日志主干通用信息)进行分析。需要特别说明的是，一般情况下生命周期切换大概率主线程也会卡死。可以结合两个日志的三个堆栈、两个BinderCatcher信息，进行对比查看。

## 应用退出

当应用发生以下故障时，为了保证可恢复，会杀死应用。

| 故障类型 | 说明 |
| -------- | -------- |
| THREAD_BLOCK_6S | 应用主线程卡死超时 |
| APP_INPUT_BLOCK | 用户输入响应超时 |
| LIFECYCLE_TIMEOUT | Ability生命周期切换超时 |
