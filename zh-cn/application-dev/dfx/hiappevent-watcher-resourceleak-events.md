# 资源泄漏事件介绍

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @xuxinao-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

资源泄漏是指句柄、线程或内存等资源在应用运行过程中未被正确释放，导致资源长期占用且无法被其他应用使用。如果某一类资源耗尽，系统可能出现卡死或重启等异常情况。

本文面向开发者介绍资源泄漏事件各字段的含义和规格。如需了解如何使用HiAppEvent接口订阅系统资源泄漏事件，请参考以下文档。目前提供ArkTs和C/C++两种接口。

- [订阅资源泄漏事件（ArkTS）](hiappevent-watcher-resourceleak-events-arkts.md)

- [订阅资源泄漏事件（C/C++）](hiappevent-watcher-resourceleak-events-ndk.md)

## 检测原理

检测原理详见[资源泄漏检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/resource-leak-guidelines)。

## 自定义规格设置

### 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| setEventConfig(name: string, config: Record<string, ParamType>): Promise&lt;void> | 设置资源泄漏日志规格参数，name应为资源泄漏事件名称常量hiappevent.event.RESOURCE_OVERLIMIT。**仅支持js内存泄漏类型。**<br />**说明**：从API version 20开始，支持该接口。 |

### 参数设置

开发者可以使用HiAppEvent提供的接口，在Record&lt;string, ParamType>中设置RESOURCE_OVERLIMIT的日志和回调事件规格。具体参数说明如下：

| 参数名          | 类型   | 必填 | 说明                                                         |
| --------------- | ------ | ---- | ------------------------------------------------------------ |
| js_heap_logtype | string | 否   | event：应用发生oom时，不传递堆快照。<br />event_rawheap：应用发生oom时，系统生成并传递堆快照<br />**注意：**当前仅接收以上二值，如果传入其他内容，方法将调用失败，不会产生任何效果。 |

> **注意：**
>
> 即使参数js_heap_logtype设置为是event_rawheap，也不能保证生成堆快照文件。这是因为生成堆快照时，应用可能因性能问题触发冻屏而提前退出。

参数配置示例：

```ts
let configParams: Record<string, hiAppEvent.ParamType> = {
    "js_heap_logtype": "event", // 仅获取事件
    // "js_heap_logtype": "event_rawheap", // 同时获取堆快照
};

hiAppEvent.setEventConfig(hiappEvent.event.RESOURCE_OVERLIMIT, configParams);
```

> **注意：**
>
> 应用调用setEventConfig接口时，每次调用的内容只会在当前应用生命周期内生效。应用重启后，需要重新通过setEventConfig接口设置。
>
> 在同一个应用生命周期内，可以多次调用setEventConfig，以最后一次成功调用的值为准。
>
> 开发者在调试以及自测试过程中，单日内触发oom次数过多，可能会遇到无法收到hiappevent回传js内存泄漏事件的情况，可以通过将系统时间往后调一天进行规避。

## params字段说明

资源泄漏事件信息中params属性的详细说明如下：

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| time | number | 事件触发时间，单位：ms。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程ID。 |
| uid | number | 应用的用户ID。 |
| resource_type | string | 资源类型，取值范围详见resource_type属性。 |
| memory | object | （resource_type为pss_memory或js_heap专有）内存信息，详见memory属性。 |
| fd | object | （resource_type为fd专有）文件描述符信息，详见fd属性。 |
| thread | object | （resource_type为thread专有）线程信息，详见thread属性。 |
| external_log | string[] | 故障日志文件路径。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，请在日志文件处理完后及时删除。** |
| log_over_limit | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过2GB上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

### resource_type字段说明

| 取值 | 说明 |
| -------- | -------- |
| pss_memory | pss内存泄漏。 |
| ion_memory | ion内存泄漏。<br />**说明**：从API version 20开始，支持该字段。 |
| gpu_memory | gpu内存泄漏。<br />**说明**：从API version 20开始，支持该字段。 |
| js_heap | js内存泄漏。 |
| fd | 句柄泄漏。 |
| thread | 线程泄漏。 |

### memory字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| rss | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程实际占用内存大小，单位：KB。 |
| vss | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程向系统申请的虚拟内存大小，单位：KB。 |
| pss | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程实际使用的物理内存大小，单位：KB。 |
| ion | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程实际使用的ION内存大小，单位：KB。<br />**说明**：从API version 20开始，支持该字段。 |
| gpu | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程实际使用的GPU内存大小，单位：KB。<br />**说明**：从API version 20开始，支持该字段。 |
| sys_free_mem | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）空闲内存大小，单位：KB。 |
| sys_avail_mem | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）可用内存大小，单位：KB。 |
| sys_total_mem | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）总内存大小，单位：KB。 |
| limit_size | number | （resource_type为js_heap专有）基线大小，单位：KB。 |
| live_object_size | number | （resource_type为js_heap专有）实际使用内存大小，单位：KB。 |

### fd字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| num | number | fd总数量。 |
| top_fd_type | string | 使用最多的fd类型。 |
| top_fd_num | number | 使用最多的fd类型的数量。 |

### thread字段说明

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| num | number | thread总数量。 |

## 自定义params参数

当前资源泄漏事件上报**js内存泄漏**事件信息，可能无法满足开发者的个性化需求，因此提供事件setEventParam方法，自定义事件上报信息。

### 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | 事件自定义参数设置方法。<br />**说明**：从API version 20开始，支持该接口。 |
