# 资源泄漏事件介绍

HiAppEvent提供接口用于订阅系统资源泄漏事件。

- [订阅资源泄漏事件（ArkTS）](hiappevent-watcher-resourceleak-events-arkts.md)
- [订阅资源泄漏事件（C/C++）](hiappevent-watcher-resourceleak-events-ndk.md)

资源泄漏事件信息中params属性的详细描述如下：

**params属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为毫秒。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程id。|
| uid | number | 应用的用户id。 |
| resource_type | string | 资源类型，取值范围详见resource_type属性。 |
| memory | object | （resource_type为pss_memory或js_heap专有）内存信息，详见memory属性。 |
| fd | object | （resource_type为fd专有）文件描述符信息，详见fd属性。 |
| thread | object | （resource_type为thread专有）线程信息，详见thread属性。 |

**resource_type属性：**

| 取值    | 说明                       |
| ------- | ------------------------- |
| pss_memory | pss内存泄漏。 |
| js_heap | js内存泄漏。 |
| fd | fd资源泄漏。 |
| thread | 线程泄漏。 |

**memory属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| rss | number | （resource_type为pss_memory专有）进程实际占用内存大小，单位KB。 |
| vss | number | （resource_type为pss_memory专有）进程向系统申请的虚拟内存大小，单位KB。 |
| pss | number | （resource_type为pss_memory专有）进程实际使用的物理内存大小，单位KB。 |
| sys_free_mem | number | （resource_type为pss_memory专有）空闲内存大小，单位KB。 |
| sys_avail_mem | number | （resource_type为pss_memory专有）可用内存大小，单位KB。 |
| sys_total_mem | number | （resource_type为pss_memory专有）总内存大小，单位KB。 |
| limit_size | number | （resource_type为js_heap专有）基线大小，单位KB。 |
| live_object_size | number | （resource_type为js_heap专有）实际使用内存大小，单位KB。 |

**fd属性：**

| 名称        | 类型   | 说明                |
| ----------- | ------ | ------------------- |
| num         | number | fd总数量。          |
| top_fd_type | string | 数量最多的fd类型。  |
| top_fd_num  | number | top_fd_type的数量。 |

**thread属性：**

| 名称 | 类型   | 说明           |
| ---- | ------ | -------------- |
| num  | number | thread总数量。 |

