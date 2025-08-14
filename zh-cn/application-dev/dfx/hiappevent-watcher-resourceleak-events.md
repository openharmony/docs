# 资源泄漏事件介绍

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @xuxinao-->
<!--SE: @peterhuangyu-->
<!--TSE: @gcw_KuLfPSbe-->

## 简介

资源泄漏是指句柄、线程或内存等资源在应用运行过程中未被正确释放，导致资源长期占用且无法被其他应用使用。如果某一类资源耗尽，系统可能出现卡死或重启等异常情况。为应对资源泄漏，系统提供资源泄漏检测、判决、日志抓取及上报功能，帮助开发者获取详细日志以辅助故障定位。

## 事件检测原理

详见[资源泄漏检测](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/resource-leak-guidelines)。

## 接口说明

开发者可以通过HiAppEvent提供接口订阅系统资源泄漏事件“hiAppEvent.event.RESOURCE_OVERLIMIT”，系统检测到应用进程存在泄漏后，会抓取维测信息通过HiAppEvent将泄漏事件回调给应用进程。

- [订阅资源泄漏事件（ArkTS）](hiappevent-watcher-resourceleak-events-arkts.md)

- [订阅资源泄漏事件（C/C++）](hiappevent-watcher-resourceleak-events-ndk.md)

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

### **resource_type字段说明**

| 取值 | 说明 |
| -------- | -------- |
| pss_memory | pss内存泄漏。 |
| ion_memory | ion内存泄漏。 |
| gpu_memory | gpu内存泄漏。 |
| js_heap | js内存泄漏。 |
| fd | 句柄泄漏。 |
| thread | 线程泄漏。 |

### **memory字段说明**

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| rss | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程实际占用内存大小，单位：KB。 |
| vss | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程向系统申请的虚拟内存大小，单位：KB。 |
| pss | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程实际使用的物理内存大小，单位：KB。 |
| ion | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程实际使用的ION内存大小，单位：KB。 |
| gpu | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）进程实际使用的GPU内存大小，单位：KB。 |
| sys_free_mem | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）空闲内存大小，单位：KB。 |
| sys_avail_mem | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）可用内存大小，单位：KB。 |
| sys_total_mem | number | （resource_type为pss_memory、ion_memory、gpu_memory专有）总内存大小，单位：KB。 |
| limit_size | number | （resource_type为js_heap专有）基线大小，单位：KB。 |
| live_object_size | number | （resource_type为js_heap专有）实际使用内存大小，单位：KB。 |

### **fd字段说明**

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| num | number | fd总数量。 |
| top_fd_type | string | 使用最多的fd类型。 |
| top_fd_num | number | 使用最多的fd类型的数量。 |

### **thread字段说明**

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| num | number | thread总数量。 |

## 资源泄漏事件自定义参数设置

当前资源泄漏事件上报**js内存泄漏**事件信息，可能无法满足开发者的个性化需求，因此提供事件setEventParam方法，自定义事件上报信息。

### 自定义参数设置接口

| 接口名 | 描述 |
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | 事件自定义参数设置方法。<br />**说明**：从API version 20开始，支持该接口。 |
