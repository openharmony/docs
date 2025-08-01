# 事件订阅简介

## 事件介绍

HiAppEvent可以订阅应用事件、系统事件。

### 应用事件

应用事件是应用开发者自己定义的事件，比如点击按钮等。应用事件的事件参数对象params包含的字段来源于应用，由开发者自定义后通过打点接口write()进行配置设定，具体字段含义可结合开发者需求展开。

### 系统事件

系统事件是指应用运行期间，应用进程发生的性能、功耗、稳定性等故障。系统事件的事件参数对象params包含的字段来源于系统服务，已有定义。此外，系统事件中的崩溃事件、应用冻屏事件还支持开发者通过接口setEventParam()向事件参数对象params中添加自定义的参数。

已支持的各种系统事件介绍、检测原理、事件参数对象params包含的字段说明，具体请查阅各个系统事件介绍。

[崩溃事件介绍](hiappevent-watcher-crash-events.md)

[应用冻屏事件介绍](hiappevent-watcher-freeze-events.md)

[资源泄漏事件介绍](hiappevent-watcher-resourceleak-events.md)

[地址越界事件介绍](hiappevent-watcher-address-sanitizer-events.md)

[主线程超时事件介绍](hiappevent-watcher-mainthreadjank-events.md)

[任务执行超时事件介绍](hiappevent-watcher-apphicollie-events.md)

<!--RP1-->
<!--RP1End-->

## 事件订阅的三种方式

HiAppEvent提供addWatcher()接口可以订阅系统事件，支持三种订阅方式。

方式一：未设置回调条件参数，使用事件订阅返回的holder对象主动获取监听的事件。

> **说明：**
>
> 主动获取监听的事件，由于事件可能未生成或者日志信息未抓取完成，可能查询为空，可以尝试多次调用查询接口。

方式二：设置回调条件triggerCondition，实现onTrigger()回调，满足回调条件自动触发回调。

方式三：实现onReceive()回调，监听的事件生成后实时回调。

ArkTS接口参考[hiAppEvent.addWatcher](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddwatcher)，C/C++接口参考[OH_HiAppEvent_AddWatcher()](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md#oh_hiappevent_addwatcher)。
