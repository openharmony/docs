# 地址越界事件介绍
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mlkgeek-->
<!--Designer: @StevenLai1994-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 概述

地址越界问题是指访问了不合法的地址，导致程序运行出现异常，通常表现为应用崩溃。

开发者可通过HiAppEvent接口订阅地址越界事件，请参考以下文档。目前提供ArkTS和C/C++两种接口，按需选择。

- [订阅地址越界事件（ArkTS）](hiappevent-watcher-address-sanitizer-events-arkts.md)

- [订阅地址越界事件（C/C++）](hiappevent-watcher-address-sanitizer-events-ndk.md)

> **说明：**
>
> 地址越界事件支持在[应用分身](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/app-clone)场景下使用 HiAppEvent 进行订阅，从 API version 22 开始支持在[输入法应用](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/inputmethod-application-guide)场景下使用 HiAppEvent 进行订阅。不支持在原子化服务场景下使用 HiAppEvent 进行订阅。

## 检测原理

详见[地址越界类问题检测](address-sanitizer-guidelines.md)。

## 页面切换日志规格自定义参数

从**API version 24**开始支持页面切换日志配置。当应用发生地址越界故障时，系统可以收集并上报页面切换日志，帮助开发者定位问题。

### configEventPolicy接口说明

| 接口名 | 描述 |
| -------- | -------- |
| [configEventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventconfigeventpolicy22) (policy: EventPolicy): Promise&lt;void>| 设置地址越界事件策略参数接口，支持开启地址越界事件的页面切换日志采集。 |

### configEventPolicy接口参数设置说明

开发者可以通过设置[EventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#eventpolicy22) 的参数来开启地址越界事件的页面切换日志采集。

| 名称       | 类型    | 只读 | 可选 | 说明                                         |
| ---------- | ------- | ---- | ---- | ------------------------------------------ |
| addressSanitizerPolicy | [AddressSanitizerPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#addresssanitizerpolicy24) | 否 | 是   | 地址越界事件配置策略。 |


参数配置示例：

```ts
import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';
import { deviceInfo, BusinessError } from '@kit.BasicServicesKit';

let policy: hiAppEvent.EventPolicy = {
    "addressSanitizerPolicy": {
        "pageSwitchLogEnable": true // 启用页面切换日志
    }
};
hiAppEvent.configEventPolicy(policy).then(() => {
    hilog.info(0x0000, 'hiAppEvent', `Set addressSanitizer config policy successfully.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'hiAppEvent', `Failed to set addressSanitizer config policy. code: ${err.code}, message: ${err.message}`);
});
```

## 事件字段说明

### params字段说明

地址越界事件信息中params属性的详细描述如下：

| 名称 | 类型 | 说明 |
| -------- | -------- | -------- |
| time | number | 事件触发时间，单位：ms。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程id。 |
| uid | number | 应用的用户id。 |
| type | string | 地址越界错误类型，取值范围详见[type字段说明](#type字段说明)。 |
| external_log | string[] | 故障日志文件路径。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，日志文件处理完后请及时删除。** |
| log_over_limit | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5MB上限。true表示超过上限，日志写入失败；false表示未超过上限。<br>启用[minidump](performance-analysis-kit-terminology.md#minidump)时，上限调整至35MB；关闭minidump时，上限恢复到5MB。 |
| page_switch_log | string | 页面切换日志路径，日志介绍详见[页面切换日志](pageswitch-log.md)。<br>**说明**：从API version 24开始支持。 |

### type字段说明

地址越界事件信息中type的详细描述如下：

| 取值 | 说明 |
| -------- | -------- |
| GWP-ASAN | 由[GWP-ASan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-gwpasan-detection)触发的错误类型。 |
| UBSAN | 由[UBSan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-ubsan-detection)触发的错误类型。 |
| TSAN | 由[TSan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-tsan-detection)触发的错误类型。 |
| FDSAN | 从API version 20开始，可以支持订阅由[fdsan](../napi/fdsan.md)触发的错误类型。 |
| ARKTS_ENVSAN | 从API版本26.0.0开始，支持订阅[方舟多线程检测](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-ark-runtime-detection#section75786272088)。 |
| stack tag-mismatch | [HWASan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-hwasan-detection)检测堆栈标记不匹配，可能是因为堆栈返回后使用、堆栈范围外使用或出界。 |
| alloc-dealloc-mismatch | 内存分配和释放方式不匹配。 |
| allocation-size-too-big | 分配过大的堆内存。 |
| calloc-overflow | calloc分配内存错误。 |
| container-overflow | 容器溢出。 |
| double-free | 重复释放的内存。 |
| dynamic-stack-buffer-overflow | 缓冲区访问超出堆栈分配对象的边界。 |
| global-buffer-overflow | 全局缓冲区溢出。 |
| heap-buffer-overflow | 堆缓冲区溢出。 |
| heap-use-after-free | 使用已释放的堆内存。 |
| invalid-allocation-alignment | 无效的内存分配对齐方式。 |
| memcpy-param-overlap | memcpy不支持重叠内存。 |
| new-delete-type-mismatch | 内存释放大小与分配大小不一致。 |
| stack-buffer-overflow | 堆栈缓冲区溢出。 |
| stack-buffer-underflow | 堆栈缓冲区下溢。 |
| stack-use-after-return | 在返回后使用堆栈内存。 |
| stack-use-after-scope | 使用超出范围的堆栈内存。 |
| strcat-param-overlap | 在重叠缓冲区中移动内存导致的错误。 |
| use-after-poison | 对内存地址投毒后被使用。 |
