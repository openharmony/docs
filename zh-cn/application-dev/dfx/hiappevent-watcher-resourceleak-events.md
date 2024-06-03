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
| memory | object | 内存信息，详见memory属性。 |

**resource_type属性：**

| 取值    | 说明                       |
| ------- | ------------------------- |
| pss_memory | pss内存泄漏。 |
| js_memory | js内存泄漏。 |
| fd | fd资源泄漏。 |
| thread | 线程泄漏 |

**memory属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| rss | number | 进程实际占用内存大小，单位KB。 |
| vss | number | 进程向系统申请的虚拟内存大小，单位KB。 |
| pss | number | 进程实际使用的物理内存大小，单位KB。 |
| sys_free_mem | number | 空闲内存大小，单位KB。 |
| sys_avail_mem | number | 可用内存大小，单位KB。 |
| sys_total_mem | number | 总内存大小，单位KB。 |
