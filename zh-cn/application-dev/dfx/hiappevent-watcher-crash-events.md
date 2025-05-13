# 崩溃事件介绍

## 概述

本文主要面向开发者介绍崩溃事件各个字段的含义以及规格，开发者如果想了解如何使用HiAppEvent提供接口订阅系统崩溃事件，请参考以下两篇文档，目前已提供ArkTs和C/C++两种接口，开发者按需使用。

- [订阅崩溃事件（ArkTS）](hiappevent-watcher-crash-events-arkts.md)
- [订阅崩溃事件（C/C++）](hiappevent-watcher-crash-events-ndk.md)

## 事件字段说明

### params字段说明

崩溃事件信息中params属性的详细描述如下：

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| time     | number | 事件触发时间，单位为毫秒。 |
| crash_type | string | 崩溃类型。支持JsError和NativeCrash两种崩溃类型。 |
| foreground | boolean | 应用是否处于前台状态。true表示处于前台状态；false表示处于后台状态。 |
| bundle_version | string | 应用版本。 |
| bundle_name | string | 应用名称。 |
| pid | number | 应用的进程id。|
| uid | number | 应用的用户id。 |
| uuid | string | 故障id。 |
| exception | object | 异常信息, 详见[exception字段说明](#exception字段说明)。包含故障简要信息，全量故障信息见external_log文件。 |
| hilog | string[] | 日志信息，最多显示100行hilog日志，更多hilog日志请查看故障日志文件。|
| threads | object[] | 全量线程调用栈，详见[thread字段说明](#thread字段说明)。仅NativeCrash类型的崩溃事件提供。 |
| external_log<sup>12+</sup> | string[] | 故障日志文件路径。故障日志文件包括cppcrash，jscrash。分析问题请参考[CppCrash分析指南](cppcrash-guidelines.md)和[JSCrash分析指南](jscrash-guidelines.md)。**为避免目录空间超限导致新生成的日志文件写入失败，日志文件处理完后请及时删除，超限规格请参考log_over_limit字段** |
| log_over_limit<sup>12+</sup> | boolean | 生成的故障日志文件与已存在的日志文件总大小是否超过5MB上限。true表示超过上限，日志写入失败；false表示未超过上限。 |

### exception字段说明

#### JsError类型exception字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| name | string | 异常类型。 |
| message | string | 异常原因。 |
| stack | string | 异常调用栈。 |

#### NativeCrash类型exception字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| message | string | 异常原因。 |
| signal | object | 信号信息，详见[signal字段说明](#signal字段说明)。 |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见[frame字段说明](#frame字段说明)。 |

### signal字段说明

信号详细介绍请参考[CppCrash分析指南崩溃信号说明](cppcrash-guidelines.md#哪些信号会生成cppcrash日志)

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| signo | number | 信号值 |
| code | number | 信号值二级分类 |
| address | string | 信号错误地址 |

### thread字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| thread_name | string | 线程名。 |
| tid | number | 线程id。 |
| frames | object[] | 线程调用栈，详见[frame字段说明](#frame字段说明)。 |

### frame字段说明

#### Native帧frame字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| file | string | 文件名称。也有可能是匿名内存映射，比如[heap]、[stack]等 |
| symbol | string | 函数名称。**名称长度超过256字节时会被删除掉，防止超长字符串引起未知问题。** |
| buildId | string | 文件唯一标识。**文件可能没有buildId，请参考[CppCrash分析指南崩溃日志内容说明](cppcrash-guidelines.md#崩溃日志内容说明)** |
| pc | string | 在文件内的偏移字节数。 |
| offset | number | 在函数内偏移字节数。 |

#### Js帧frame字段说明

| 名称    | 类型   | 说明                       |
| ------- | ------ | ------------------------- |
| file | string | 文件名。 |
| packageName | string | 模块的包名。 |
| symbol | string | 函数名称。 |
| column | number | 异常所在行。 |
| line | number | 异常所在列。 |

## 崩溃日志配置参数设置介绍

系统提供了通用的NativeCrash崩溃日志生成功能，但一些应用对崩溃日志打印内容有个性化的需求，因此从**API version 20**开始支持设置崩溃日志配置参数。

| 接口名                                              | 描述                                         |
| --------------------------------------------------- | -------------------------------------------- |
| setEventConfig(name: string, config: Record<string, ParamType>): Promise\<void> | 从API version 20开始，支持设置崩溃日志配置参数，name为APP_CRASH。**仅支持NativeCrash类型崩溃。** |

### 参数设置说明

开发者可以使用上述hiappevent提供的接口，在Record<string, ParamType>中配置崩溃日志打印规格的参数。具体参数说明如下：

| 参数名 | 类型 | 必填 | 说明 |
| -----| ----- | ----- |----- |
| extend_pc_lr_printing | boolean | 否 | true：64位系统打印pc和lr寄存器地址向前248字节、向后256字节范围内的内存值。32位系统打印pc和lr寄存器地址向前124字节、向后128字节范围内的内存值。<br/>false：64位系统打印pc和lr寄存器地址向前16字节、向后240字节范围内的内存值。32位系统化打印pc和lr寄存器地址向前8字节、向后120字节范围内的内存值。<br/>缺省时默认为false。<br/>**说明**：从API version 20开始，支持该字段。|
| log_file_cutoff_sz_bytes | number | 否 | 单位为byte，取值范围为[0-5242880]。<br/>如果设置，按设置的参数值截断崩溃日志大小。<br/> 如果不设置，默认值取0表示不截断崩溃日志。<br/>**说明**：从API version 20开始，支持该字段。|
| simplify_vma_printing | boolean | 否 | true：只打印崩溃日志中出现的地址所属的VMA（Virtual Memory Area，进程地址空间中的区域）映射信息，减小日志大小。<br/>false：打印所有VMA映射信息。<br/>缺省时默认为false。<br/>**说明**：从API version 20开始，支持该字段。|

> **说明**
>
> 开发者可通过[external_log](hiappevent-watcher-crash-events.md#params字段说明)字段获取崩溃日志内容，日志内容介绍详见[崩溃日志内容说明](cppcrash-guidelines.md#崩溃日志内容说明)。

参数配置示例如下:

```text
let configParams: Record<string, hiAppEvent.ParamType> = {
    "extend_pc_lr_printing": true, // 使能扩展打印pc和lr寄存器附近的内存值
    "log_file_cutoff_sz_bytes": 102400, // 截断崩溃日志到100KB
    "simplify_vma_printing": true // 使能精简打印maps
};
```

以32位系统为例，参考[订阅崩溃事件（ArkTS）接口使用示例](hiappevent-watcher-crash-events-arkts.md#接口使用示例)开发完成崩溃事件订阅和日志配置参数设置，在应用发生NativeCrash类型崩溃后故障日志中打印如下内容：

``` text
...
Build info:xxx
Enabled app log configs:    <- 使能的配置参数列表，只打印不是默认值的配置参数
Extend pc lr printing:true  <- extend_pc_lr_printing参数设置为true
Log cut off size:102400B    <- 崩溃日志大小截断到100kb
Simplify maps printing:true <- simplify_vma_printing参数设置为true
Timestamp:xxx
...
Memory Near Register: <-  故障现场寄存器的地址（地址必须在有效内存中）附近内存值，括号表示寄存器里地址的所属内存
...
lr(/system/lib/ld-musl-arm.so.1): <- 打印256字节长度lr寄存器地址附近的内存值
    f7998dd4 e0824000
    f7998dd8 e3510000
    f7998ddc 0a000003
    f7998de0 e8910003
    f7998de4 e1a02004
    f7998de8 eb0030ec
    f7998dec ea000000
    f7998df0 e3a00000
    f7998df4 e3500000
    f7998df8 11a04000
    f7998dfc e1a00004
    f7998e00 e8bd8c10
    f7998e04 fff98074
    f7998e08 fff978ee
    f7998e0c e92d4c80
    f7998e10 e28db008
    f7998e14 e3a070f8
    f7998e18 e1a01000
    f7998e1c ef000000
    f7998e20 e3a07001
    f7998e24 e1a00001
    f7998e28 ef000000
    f7998e2c eafffffc
    f7998e30 e92d4800
    f7998e34 e1a0b00d
    f7998e38 ebffffff
    f7998e3c e92d4890
    f7998e40 e28db008
    f7998e44 e24dd020
    f7998e48 e3a00006
    f7998e4c eb012ae8
    f7998e50 e59f10b0
    f7998e54 e3a00000
    f7998e58 e59fc0ac
    f7998e5c e3a070af
    f7998e60 e08f1001
    f7998e64 e3a02000
    f7998e68 e08fc00c
    f7998e6c e3a03008
    f7998e70 ef000000
    f7998e74 e3a04000
    f7998e78 e1a0000c
    f7998e7c eb018f61
    f7998e80 e28d1008
    f7998e84 f2c00050
    f7998e88 e3a070ae
    f7998e8c e3a02000
    f7998e90 e1a00001
    f7998e94 e3a03008
    f7998e98 f4400acd
    f7998e9c e5804000
    f7998ea0 e3a00006
    f7998ea4 ef000000
    f7998ea8 e3a070ee
    f7998eac e3a01006
    f7998eb0 ee1d0f70
    f7998eb4 e3a02000
    f7998eb8 e3a03008
    f7998ebc e51000b0
    f7998ec0 ef000000
    f7998ec4 e58d4004
    f7998ec8 e1a0100d
    f7998ecc e3a00020
    f7998ed0 e3a070af
pc(/system/lib/ld-musl-arm.so.1): <- 打印256字节长度pc寄存器地址附近的内存值
    f79e3a14 e1a0200d
    f79e3a18 e3a070af
    f79e3a1c e3a03008
    f79e3a20 ef000000
    f79e3a24 e3a07014
    f79e3a28 e34f5fff
    f79e3a2c ef000000
    f79e3a30 e3700a01
    f79e3a34 9a000003
    f79e3a38 e2606000
    f79e3a3c ebfed4bb
    f79e3a40 e5806000
    f79e3a44 e3e00000
    f79e3a48 ee1d1f70
    f79e3a4c e3a07f43
    f79e3a50 e1a02004
    f79e3a54 e51110b0
    f79e3a58 ef000000
    f79e3a5c e1a04000
    f79e3a60 e1500005
    f79e3a64 9a000003
    f79e3a68 e2644000
    f79e3a6c ebfed4af
    f79e3a70 e5804000
    f79e3a74 e3e04000
    f79e3a78 e3a00002
    f79e3a7c e1a0100d
    f79e3a80 e3a070af
    f79e3a84 e3a02000
    f79e3a88 e3a03008
    f79e3a8c ef000000
    f79e3a90 e1a00004
    f79e3a94 e24bd010
    f79e3a98 e8bd88f0
    f79e3a9c fff71854
    f79e3aa0 e92d48f0
    f79e3aa4 e28db010
    f79e3aa8 e24dd020
    f79e3aac e5914010
    f79e3ab0 e1a0c002
    f79e3ab4 e5916000
    f79e3ab8 e5913014
    f79e3abc e2942102
    f79e3ac0 e5915004
    f79e3ac4 e2a33000
    f79e3ac8 e2962102
    f79e3acc e2b52000
    f79e3ad0 03530000
    f79e3ad4 0a000003
    f79e3ad8 ebfed494
    f79e3adc e3a0105f
    f79e3ae0 e5801000
    f79e3ae4 ea00001e
    f79e3ae8 e2812008
    f79e3aec e2811018
    f79e3af0 e58d4008
    f79e3af4 e35c0000
    f79e3af8 e5922000
    f79e3afc e3a07068
    f79e3b00 e5911000
    f79e3b04 e58d2004
    f79e3b08 e28d2010
    f79e3b0c e58d100c
    f79e3b10 e1a0100d
...
Maps:                     <- simplify_vma_printing设置为true时与设置为false对比，打印Maps行数减少很多
ba0000-ba9000 r--p 00000000 /data/test/test_signalhandler
ba9000-bd8000 r-xp 00008000 /data/test/test_signalhandler
bd8000-bdb000 r--p 00036000 /data/test/test_signalhandler
bdb000-bdc000 rw-p 00038000 /data/test/test_signalhandler
f7480000-f74e9000 r--p 00000000 /system/lib/libc++.so
f74e9000-f758b000 r-xp 00068000 /system/lib/libc++.so
f758b000-f7591000 r--p 00109000 /system/lib/libc++.so
f7591000-f7592000 rw-p 0010e000 /system/lib/libc++.so
f7592000-f7598000 rw-p 00000000 [anon:libc++.so.bss]
f75c0000-f75c3000 r--p 00000000 /system/lib/chipset-pub-sdk/libsec_shared.z.so
f75c3000-f75d1000 r-xp 00002000 /system/lib/chipset-pub-sdk/libsec_shared.z.so
f75d1000-f75d2000 r--p 0000f000 /system/lib/chipset-pub-sdk/libsec_shared.z.so
f75d2000-f75d3000 rw-p 0000f000 /system/lib/chipset-pub-sdk/libsec_shared.z.so
f769b000-f769e000 rw-p 00000000 [anon:native_heap:brk]
f76d3000-f76d4000 rw-p 00000000 [anon:native_heap:brk]
f78d8000-f78e7000 rw-p 00000000 [anon:native_heap:brk]
f78ff000-f7900000 r-xp 00000000 [vdso]
f7900000-f795a000 r--p 00000000 /system/lib/ld-musl-arm.so.1
f795a000-f7a1d000 r-xp 00059000 /system/lib/ld-musl-arm.so.1
f7a1d000-f7a1e000 r--p 0011b000 /system/lib/ld-musl-arm.so.1
f7a1e000-f7a20000 rw-p 0011b000 /system/lib/ld-musl-arm.so.1
f7a20000-f7a30000 rw-p 00000000 [anon:ld-musl-arm.so.1.bss]
ffa53000-ffa74000 rw-p 00000000 [stack]
OpenFiles:
...
[truncated]  <- 日志截断的标志符，如果有打印说明日志被截断了
```
