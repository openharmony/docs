# 踩内存事件介绍

HiAppEvent提供接口用于订阅系统踩内存事件。

- [订阅踩内存事件（ArkTS）](hiappevent-watcher-address-sanitizer-events-arkts.md)
- [订阅踩内存事件（C/C++）](hiappevent-watcher-address-sanitizer-events-ndk.md)

踩内存事件信息中params属性的详细描述如下：

**params属性：**

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为毫秒。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程id。|
| uid | number | 应用的用户id。 |
| type | string | 地址越界错误类型，取值范围详见type属性。 |
| external_log | string[] | 故障日志文件路径。**为避免目录空间超限（限制参考log_over_limit），导致新生成的日志文件写入失败，日志文件处理完后请及时删除。** |
| log_over_limit | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5M上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

**type属性：**

| 取值    | 说明                       |
| ------- | ------------------------- |
| FDSAN | 由fdsan触发的错误的错误类型。[开发者可以查看FDSAN使用指导获取帮助](../napi/fdsan.md)。 |
| alloc-dealloc-mismatch | 内存分配和释放方式不匹配。 |
| allocation-size-too-big | 当分配对堆来说太大时发现的错误。 |
| calloc-overflow | calloc分配内存错误。 |
| container-overflow | 容器溢出。 |
| double-free | 释放已释放的内存。 |
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
| use-after-poison | 使用已中毒的内存。 |
