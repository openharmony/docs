# 地址越界事件介绍
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mlkgeek-->
<!--Designer: @StevenLai1994-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 概述

地址越界问题是指访问了不合法的地址，导致程序运行出现异常，通常表现为应用崩溃。

开发者可通过HiAppEvent接口订阅地址越界事件，请参考以下文档。目前提供ArkTs和C/C++两种接口，按需选择。

- [订阅踩内存事件（ArkTS）](hiappevent-watcher-address-sanitizer-events-arkts.md)

- [订阅踩内存事件（C/C++）](hiappevent-watcher-address-sanitizer-events-ndk.md)

## 检测原理

详见[地址越界类问题检测](address-sanitizer-guidelines.md)。

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
| type | string | 地址越界错误类型，取值范围详见type属性。 |
| external_log | string[] | 故障日志文件路径。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，日志文件处理完后请及时删除。** |
| log_over_limit | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

### type字段说明

地址越界事件信息中type的详细描述如下：

| 取值 | 说明 |
| -------- | -------- |
| GWP-ASAN | 由[GWP-ASan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-gwpasan-detection)触发的错误类型。 |
| UBSAN | 由[UBSan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-ubsan-detection)触发的错误类型。 |
| TSAN | 由[TSan](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-tsan-detection)触发的错误类型。 |
| FDSAN | 从API version 20开始，可以支持订阅由[fdsan](../napi/fdsan.md)触发的错误类型。 |
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
