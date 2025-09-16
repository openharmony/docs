# Address Sanitizer Detection
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @mlkgeek-->
<!--SE: @StevenLai1994-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Out-of-bounds address access refers to the access to an invalid address. As a result, the program runs abnormally and the application may crash. Common causes include use after free, double-free, stack-overflow, and heap-overflow. As application crash logs are limited and not the first crash site, it is difficult to locate out-of-bounds address access issues. Typically, you can use detection tools such as Asan, HWAsan, and GWP-Asan to obtain more memory operation information. Since API 13, you are advised to use [HWAsan](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-hwasan-detection#section20672194985111) to analyze out-of-bounds address access issues.

## Common Out-of-bounds Types and Impacts

For details, see [Typical Types of Out-of-bounds Address Access](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-address-sanitizer-catagory).

## Principle of Address Sanitizer Detection

For details, see [Address Sanitizer Detection](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-ram-detection#title53131231).

## How to Obtain Logs

Both address sanitizer logs and process crash logs are managed by the FaultLogger module and can be obtained using any of the following methods:

**Method 1: DevEco Studio**

DevEco Studio collects process crash logs from **/data/log/faultlog/faultlogger/** to FaultLog, where logs are displayed by process name, fault, and time. For details about how to obtain logs, see [Fault Log](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-fault-log).

**Method 2: HiAppEvent APIs**

HiAppEvent provides APIs for subscribing to faults. For details, see [Introduction to HiAppEvent](hiappevent-intro.md). You can subscribe to the address sanitizer event by referring to [Subscribing to Address Sanitizer Events (ArkTS)](hiappevent-watcher-address-sanitizer-events-arkts.md) or [Subscribing to Address Sanitizer Events (C/C++)](hiappevent-watcher-address-sanitizer-events-ndk.md), and read the fault log file using the [external_log](hiappevent-watcher-address-sanitizer-events.md#params) field in the event.

**Method 3: hdc**

In the running state, logs are flushed to **/data/log/faultlog/faultlogger** by default. When **Developer options** is enabled, you can run the **hdc file recv /data/log/faultlog/faultlogger D:\** command to export fault logs to the local host. The fault log file name is in the format of **[Detector type]-[bundleName]-[uid]-[happenedTime].log**.

## Log Specifications

### ASan

In ASan logs, the title contains the device information, fault occurrence time, faulty process, and fault cause. The log content details the out-of-bounds address (**0x007fffd59768**), access size (**WRITE of size 4**), and thread and process information. The call stack displays the function call path that causes the out-of-bounds error, and lists the address, module, and offset of each call layer, helping you quickly locate the code. The log also provides shadow bytes to trace the memory status, helping you determine whether the access is valid. In addition, the log lists the memory space mapping of the process, which helps pinpoint the exact memory region containing the out-of-bounds address.

Example:

```
Device info:XXX <- Device information
Build info:XXX-XXXX x.x.x.xx(xxxxxxx) <- Version information
Fingerprint:77cdc69cef714391a08c7cb1ceec8b8f9b02900fc6588e4231c2f8750b2bf330 <- Feature information
Timestamp:xxxx-xx-xx xx:xx:xx.xxx <- Timestamp
Module name:com.example.sampleapplication <- Module name
Version:1.0.0 <- Version number
Pid:62642 <- Process ID
Uid:20020185 <- User ID
Reason:stack-buffer-overflow <- Trigger cause

==appspawn==11766==AddressSanitizer: WARNING: unexpected format specifier in printf interceptor: %{ (reported once per process)
=================================================================
==appspawn==11766==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x007fffd59768 at pc 0x007c7e718f54 bp 0x007fffd59710 sp 0x007fffd59708 <- Problem overview
WRITE of size 4 at 0x007fffd59768 thread T0 (e.myapplication) <- Out-of-bounds write size 
    #0 0x7c7e718f50 (/data/storage/el1/bundle/libs/arm64/libentry.so+0x58f50) (BuildId: 5e1d4fe4b589921373e51615051105e455462c5f) <- Call stack information
    #1 0x7b5710235c  (/system/lib64/platformsdk/libace_napi.z.so+0x4235c) (BuildId: e6ee1d59b23d2b0d1e746549da572967)
    #2 0x7b74ee79a4  (/system/lib64/module/arkcompiler/stub.an+0x4f89a4)
    #3 0x7b749fa8c0  (/system/lib64/module/arkcompiler/stub.an+0xb8c0)

Address 0x007fffd59768 is located in stack of thread T0 (e.myapplication) at offset 72 in frame
    #0 0x7c7e718de4  (/data/storage/el1/bundle/libs/arm64/libentry.so+0x58de4) (BuildId: 5e1d4fe4b589921373e51615051105e455462c5f)

  This frame has 1 object(s):
    [32, 72) 'a' (line 66) <== Memory access at offset 72 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow (/data/storage/el1/bundle/libs/arm64/libentry.so+0x58f50) (BuildId: 5e1d4fe4b589921373e51615051105e455462c5f) 

Shadow bytes around the buggy address: <- Shadow memory information
  0x001ffffab290: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x001ffffab2a0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x001ffffab2b0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x001ffffab2c0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x001ffffab2d0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x001ffffab2e0: 00 00 00 00 f1 f1 f1 f1 00 00 00 00 00[f3]f3 f3
  0x001ffffab2f0: f3 f3 f3 f3 00 00 00 00 00 00 00 00 00 00 00 00
  0x001ffffab300: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x001ffffab310: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x001ffffab320: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x001ffffab330: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==appspawn==11766==ABORTING

==appspawn==11766==Process memory map follows: <- Memory space of the process when the fault occurs
 0x000ffffff000-0x001200000000 [anon:low shadow]
 0x001200000000-0x001400000000 [anon:shadow gap]
 0x001400000000-0x001f6ccb1000 [anon:high shadow]
 0x001f6ccb1000-0x001f6cd28000 
 0x001f6cd28000-0x001f6e87c000 [anon:high shadow]
 0x001f6e87c000-0x001f6e89c000 
 0x001f6e89c000-0x001f6e89d000 [anon:high shadow]
```

### HWAsan

HWAsan logs are similar to ASan logs. Its title also displays key information such as device information, fault occurrence time, faulty process, and trigger cause. The log content includes the out-of-bounds address (for example, **0x0002013c0100**), access size (for example, **WRITE of size 4**), and thread and process information. In addition, the call stack displays the execution path of the function that triggers the out-of-bounds error, and lists the address, module, and offset of each layer to help you quickly locate the code. Unlike ASan, HWAsan also outputs the tags of pointers and memory blocks, and compares the tags to determine whether an invalid access exists.

```
Device info:XXX <- Device information
Build info:XXX-XXXX x.x.x.xx(xxxxxxx) <- Version information
Fingerprint:77cdc69cef714391a08c7cb1ceec8b8f9b02900fc6588e4231c2f8750b2bf330 <- Feature information
Timestamp:xxxx-xx-xx xx:xx:xx.xxx <- Timestamp
Module name:com.example.sampleapplication <- Module name
Version:1.0.0 <- Version number
Pid:62642 <- Process ID
Uid:20020185 <- User ID
Reason:use-after-free <- Trigger Cause

==appspawn==62642==ERROR: HWAddressSanitizer: tag-mismatch on address 0x0002013c0100 at pc 0x00651a5c0fa0 <- Problem overview
WRITE of size 4 at 0x0002013c0100 tags: d2/11 (ptr/mem) in thread T240 <- Out-of-bounds write size
    #0 0x651a5c0fa0 (/data/storage/el1/bundle/libs/arm64/libijk.so+0x2c0fa0) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5) <- Call stack information 
    #1 0x651a49bfb0  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x19bfb0) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #2 0x651a49beb8  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x19beb8) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #3 0x651a5c100c  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x2c100c) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #4 0x651a4eeb60  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x1eeb60) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #5 0x651a4ed864  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x1ed864) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #6 0x651a5c81f8  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x2c81f8) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #7 0x651a5cc450  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x2cc450) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #8 0x651a5c4708  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x2c4708) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #9 0x651a5c48e8  (/data/storage/el1/bundle/libs/arm64/libijk.so+0x2c48e8) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5)
    #10 0x5a3e8d0d98  (/lib/ld-musl-aarch64-asan.so.1+0x10ed98) (BuildId: bac03842ac83e537d217a027e9584250)

[0x0002013c0100,0x0002013c0140) is a small allocated heap chunk; size: 64 offset: 0 <- Corrupted memory information

Potential Cause: use-after-free <- Possible cause 1
0x0002013c0100 (old ptr tags: 5d) is located 0 bytes inside of 48-byte region [0x0002013c0100,0x0002013c0130)
freed by thread T0 here: <- Released stack
    #0 0x5a3f868f98 (/system/asan/lib64/libclang_rt.hwasan.so+0x28f98) (BuildId: a6c55e97d9dbc519020b7732890fe5143f80d175) <- Call stack information
    #1 0x650009d6b4  (/system/asan/lib64/module/file/libfileuri.z.so+0x1d6b4) (BuildId: 7f492df25ba1291065c3cf49b731c56a)
    #2 0x65000a09ec  (/system/asan/lib64/module/file/libfileuri.z.so+0x209ec) (BuildId: 7f492df25ba1291065c3cf49b731c56a)
    #3 0x5a3e855790  (/lib/ld-musl-aarch64-asan.so.1+0x93790) (BuildId: bac03842ac83e537d217a027e9584250)
    #4 0x5a3e85801c  (/lib/ld-musl-aarch64-asan.so.1+0x9601c) (BuildId: bac03842ac83e537d217a027e9584250)
    #5 0x5ad738d43c  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4d43c) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #6 0x5ad738c2d0  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4c2d0) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #7 0x5ad738b9c0  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4b9c0) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #8 0x5ad73a3b30  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x63b30) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #9 0x5ad6e75f1c  (/system/asan/lib64/platformsdk/libark_jsruntime.so+0x8b5f1c) (BuildId: a2f4a88f26244f527994da0cefbab138)
    #10 0x5af39b2130  (/system/lib64/module/arkcompiler/stub.an+0x332130)
    #11 0x5af36897d0  (/system/lib64/module/arkcompiler/stub.an+0x97d0)
    #12 0x212092dc04  ([anon:ArkTS Heap5576local space]+0x2dc04)

previously allocated here: <- Allocation stack
    #0 0x5a3f868ce8  (/system/asan/lib64/libclang_rt.hwasan.so+0x28ce8) (BuildId: a6c55e97d9dbc519020b7732890fe5143f80d175)
    #1 0x650009a840  (/system/asan/lib64/module/file/libfileuri.z.so+0x1a840) (BuildId: 7f492df25ba1291065c3cf49b731c56a)
    #2 0x65000a09ec  (/system/asan/lib64/module/file/libfileuri.z.so+0x209ec) (BuildId: 7f492df25ba1291065c3cf49b731c56a)
    #3 0x5a3e855790  (/lib/ld-musl-aarch64-asan.so.1+0x93790) (BuildId: bac03842ac83e537d217a027e9584250)
    #4 0x5a3e85801c  (/lib/ld-musl-aarch64-asan.so.1+0x9601c) (BuildId: bac03842ac83e537d217a027e9584250)
    #5 0x5ad738d43c  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4d43c) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #6 0x5ad738c2d0  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4c2d0) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #7 0x5ad738b9c0  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4b9c0) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #8 0x5ad73a3b30  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x63b30) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #9 0x5ad6e75f1c  (/system/asan/lib64/platformsdk/libark_jsruntime.so+0x8b5f1c) (BuildId: a2f4a88f26244f527994da0cefbab138)
    #10 0x5af39b2130  (/system/lib64/module/arkcompiler/stub.an+0x332130)
    #11 0x5af36897d0  (/system/lib64/module/arkcompiler/stub.an+0x97d0)
    #12 0x212092dc04  ([anon:ArkTS Heap5576local space]+0x2dc04)

Cause: heap-buffer-overflow <- Possible cause 2
0x0002013c0100 is located 3352 bytes to the right of 40-byte region [0x0002013bf3c0,0x0002013bf3e8)
allocated here:
    #0 0x5a3f868ce8  (/system/asan/lib64/libclang_rt.hwasan.so+0x28ce8) (BuildId: a6c55e97d9dbc519020b7732890fe5143f80d175)
    #1 0x65000a85b8  (/system/asan/lib64/module/file/libfileuri.z.so+0x285b8) (BuildId: 7f492df25ba1291065c3cf49b731c56a)
    #2 0x65000a09b4  (/system/asan/lib64/module/file/libfileuri.z.so+0x209b4) (BuildId: 7f492df25ba1291065c3cf49b731c56a)
    #3 0x5a3e855790  (/lib/ld-musl-aarch64-asan.so.1+0x93790) (BuildId: bac03842ac83e537d217a027e9584250)
    #4 0x5a3e85801c  (/lib/ld-musl-aarch64-asan.so.1+0x9601c) (BuildId: bac03842ac83e537d217a027e9584250)
    #5 0x5ad738d43c  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4d43c) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #6 0x5ad738c2d0  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4c2d0) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #7 0x5ad738b9c0  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x4b9c0) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #8 0x5ad73a3b30  (/system/asan/lib64/platformsdk/libace_napi.z.so+0x63b30) (BuildId: 90a9e7b85b14f6c805a699672bf8db4a)
    #9 0x5ad6e75f1c  (/system/asan/lib64/platformsdk/libark_jsruntime.so+0x8b5f1c) (BuildId: a2f4a88f26244f527994da0cefbab138)
    #10 0x5af39b2130  (/system/lib64/module/arkcompiler/stub.an+0x332130)
    #11 0x5af36897d0  (/system/lib64/module/arkcompiler/stub.an+0x97d0)
    #12 0x212092dc04  ([anon:ArkTS Heap5576local space]+0x2dc04)

Memory tags around the buggy address (one tag corresponds to 16 bytes): <- Tags stored in the shadow memory for comparison with the pointer tags
  0x005c2013bf90: b6  b6  08  00  1f  1f  08  00  5a  5a  08  00  45  45  08  00 
  0x005c2013bfa0: bc  bc  08  00  3b  3b  08  00  35  35  08  00  9c  9c  08  00 
  0x005c2013bfb0: 9e  9e  08  00  d4  d4  08  00  14  14  08  00  ff  ff  08  00 
  0x005c2013bfc0: fe  fe  08  00  ec  ec  08  00  67  67  08  00  26  26  08  00 
  0x005c2013bfd0: 3e  3e  08  00  5f  5f  08  00  fe  fe  08  00  8b  8b  08  00 
  0x005c2013bfe0: 98  98  08  00  c3  c3  08  00  37  37  08  00  87  87  08  00 
  0x005c2013bff0: 3f  3f  08  00  02  02  08  00  b3  b3  08  00  fb  fb  08  00 
  0x005c2013c000: 56  56  08  00  ad  ad  08  00  02  02  08  00  94  94  08  00 
=>0x005c2013c010:[11] 11  08  00  a5  a5  08  00  13  13  08  00  2e  2e  08  00 
  0x005c2013c020: 09  09  08  00  68  68  08  00  df  df  08  00  17  17  08  00 
  0x005c2013c030: 24  24  08  00  5f  5f  08  00  f9  f9  08  00  05  05  08  00 
  0x005c2013c040: 02  02  08  00  78  78  08  00  50  50  08  00  33  33  08  00 
  0x005c2013c050: 57  57  08  63  4a  4a  08  4b  a8  a8  08  00  cd  cd  08  00 
  0x005c2013c060: e6  e6  08  00  0d  0d  08  00  3c  3c  3c  08  83  83  83  08 
  0x005c2013c070: 62  62  62  08  08  08  08  08  35  35  35  08  b5  b5  b5  08 
  0x005c2013c080: 87  87  87  08  4d  4d  4d  08  46  46  46  08  0e  0e  0e  08 
  0x005c2013c090: 6d  6d  6d  08  7a  7a  7a  08  11  11  11  08  af  af  af  08 
Tags for short granules around the buggy address (one tag corresponds to 16 bytes):
  0x005c2013c000: ..  ..  56  ..  ..  ..  ad  ..  97  00  02  ..  ..  ..  94  .. 
=>0x005c2013c010:[..] ..  11  ..  ..  ..  a5  ..  ..  ..  13  ..  ..  ..  2e  .. 
  0x005c2013c020: 13  00  09  ..  ..  ..  68  ..  ..  ..  df  ..  ..  ..  17  .. 
See https://clang.llvm.org/docs/HardwareAssistedAddressSanitizerDesign.html#short-granules for a description of short granule tags
Registers where the failure occurred (pc 0x00651a5c0fa0):
    x0  ec00000201e4ee88  x1  3c000004004c6b38  x2  0000000000000000  x3  0000000000000000
    x4  6e0000652737ff79  x5  e600000201f631b9  x6  3e000002016b0d10  x7  0000056d1a495b07
    x8  0200005bffffffff  x9  0000006527380ff0  x10 0000006527380f18  x11 0000000000000000
    x12 073e000002016b0d  x13 000000056d1a495b  x14 000000000000006e  x15 0000000000000000
    x16 0000005a3f867ef0  x17 000000651a5c0f64  x18 0000000000000005  x19 d2000002013c0100
    x20 0200005c00000000  x21 3c000004004c6b38  x22 ec00000201e4ee80  x23 0000000000000000
    x24 b800000000000000  x25 c8000065273804b0  x26 3e000002016b0d08  x27 b8000065273803a0
    x28 1700000400263f80  x29 000000652737ffa0  x30 000000651a5c0fa4   sp 000000652737ffa0

SUMMARY: HWAddressSanitizer: tag-mismatch (/data/storage/el1/bundle/libs/arm64/libijk.so+0x2c0fa0) (BuildId: 84383086df874d94fa191ddbbc25091cc14992c5) 

Memory near registers: <- Memory near registers
x0([anon:native_heap:jemalloc]):
    0000005a2be445f0 0000000000000000
    0000005a2be445f8 0000000000000000
    0000005a2be44600 000000599a8d0208
    0000005a2be44608 0000005a2be44600
    0000005a2be44610 0000005a2beee520
    0000005a2be44618 0000000000000021
    0000005a2be44620 0000005a2be51800
    0000005a2be44628 0000005a2be48080
    0000005a2be44630 00004c94000000fc
    0000005a2be44638 ffffffffffffffff
    0000005a2be44640 ffffffffffffffff
    0000005a2be44648 ffffffffffffffff
    0000005a2be44650 0000ffffffffffff
    0000005a2be44658 0000005a2be33600

Process memory map follows: <- Process memory space when the fault occurs
 0x000000010000-0x000100020000 rw-p 00000000 [anon:SizeClassAllocator]
 0x000100020000-0x000101490000 rw-p 00000000 [anon:SizeClassAllocator: region data]
 0x000101490000-0x0001df870000 rw-p 00000000 [anon:SizeClassAllocator]
 0x0001df870000-0x0001e0020000 rw-p 00000000 [anon:SizeClassAllocator: region metadata]
 0x0001e0020000-0x0001e0140000 rw-p 00000000 [anon:SizeClassAllocator: freearray]
 0x0001e0140000-0x000200020000 rw-p 00000000 [anon:SizeClassAllocator]
 0x000200020000-0x000201fd0000 rw-p 00000000 [anon:SizeClassAllocator: region data]
 0x000201fd0000-0x0002dfa20000 rw-p 00000000 [anon:SizeClassAllocator]
 0x0002dfa20000-0x0002e0020000 rw-p 00000000 [anon:SizeClassAllocator: region metadata]
 0x0002e0020000-0x0002e0040000 rw-p 00000000 [anon:SizeClassAllocator: freearray]
```

### MemDebug

MemDebug employs an isolation area combined with a poison-fill mechanism and reuses HWAsan's tag-verification detector. Its log format for double-free errors is identical to HWAsan's.

```
Device info:XXX <- Device information
Build info:XXX-XXXX x.x.x.xx(xxxxxxx) <- Version information
Fingerprint:77cdc69cef714391a08c7cb1ceec8b8f9b02900fc6588e4231c2f8750b2bf330 <- Feature information
Timestamp:xxxx-xx-xx xx:xx:xx.xxx <- Timestamp
Module name:com.example.sampleapplication <- Module name
Version:1.0.0 <- Version number
Pid:62642 <- Process ID
Uid:20020185 <- User ID
Reason:use-after-free <- Trigger Cause

==appspawn==62642==ERROR: HWAddressSanitizer: invalid-free on address 0x000100945e20 at pc 0x005a16a634fc on thread 62642 <- Problem Overview
tags: 57/e9 (ptr/mem) 
    #0 0x5a16a634fc  (/system/lib64/xxxxxxxxx.so+0xxxxxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxxxx) <- Callstack information
    #1 0x5ac1f47c94  (/data/storage/xxxxxxx.so+0xxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxxxxxxx)
    ...

[0x000100945e20,0x000100945e40) is a small unallocated heap chunk; size: 32 offset: 0, Allocated By 62642 <- Memory block information overview

Potential Cause: use-after-free <- Possible cause 1
0x000100945e20 (rb[50] tags:57) is located 0 bytes inside of 16-byte region [0x000100945e20,0x000100945e30) 
freed by thread 62642 here: <- Call stack information
    #0 0x5a16a6b070  (/system/lib64/xxxxxx.so+0xxxxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxx)
    #1 0x5ac2fce684  (/system/lib64/xxxxxxxx.so+0xxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxx)
    ...

previously allocated by thread 62642 here:
    #0 0x5a16a6b070  (/system/lib64/xxxxxx.so+0xxxxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxx)
    #1 0x5ac2fce684  (/system/lib64/xxxxxxxx.so+0xxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxx)
    ...

hwasan_dev_note_heap_rb_distance: 51 1023000
Thread: T0 0x005b00002000 stack: [0x007fb3025000,0x007fb3824000) sz: 8384512 tls: [0x005a16107a98,0x005a16108279) rb:(1023000/1023000) records(1301994/o:0) tid: 62642
Searched 1028682 records, find 1 with same addr 0x000100945e20


Cause: heap-buffer-overflow <- Possible cause 2
0x000100945e20 is located 2400 bytes to the left of 24-byte region [0x000100946780,0x000100946798)
allocated here:
    #0 0x5a16a6b070  (/system/lib64/xxxxxx.so+0xxxxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxx)
    #1 0x5ac2fce684  (/system/lib64/xxxxxxxx.so+0xxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxx)
    ...

Ring-buffer information of each thread
Thread: T0 0x005b00002000 stack: [0x007fb3025000,0x007fb3824000) sz: 8384512 tls: [0x005a16107a98,0x005a16108279) rb:(1023000/1023000) records(1301994/o:0) tid: 62642
Thread: T6 0x005b0000a000 stack: [0x005ab7b64000,0x005ab7c64978) sz: 1051000 tls: [0x005ab7c64978,0x005ab7c64bc2) rb:(2/1023) records(2/o:0) tid: 62702
Thread: T7 0x005b00016000 stack: [0x005abf7b4000,0x005abf8b4978) sz: 1051000 tls: [0x005abf8b4978,0x005abf8b4bc2) rb:(1023/1023) records(1133/o:0) tid: 62703
Thread: T8 0x005b0000e000 stack: [0x005abf8b7000,0x005abf9b7978) sz: 1051000 tls: [0x005abf9b7978,0x005abf9b7bc2) rb:(123/1023) records(123/o:0) tid: 62704
...

Tag information
Memory tags around the buggy address (one tag corresponds to 16 bytes):
  ...
  0x005c100945d0: ea  08  fa  fa  ab  ab  cb  08  32  c6  64  08  f7  f7  68  68
=>0x005c100945e0: 96  08 [e9] e7  c9  c9  36  36  18  08  ef  d9  80  08  8e  08
  0x005c100945f0: ba  08  98  98  b6  1b  63  63  08  00  bb  52  74  08  84  08
  ...
Tags for short granules around the buggy address (one tag corresponds to 16 bytes):
  0x005c100945d0: ..  ea  ..  ..  ..  ..  ..  cb  ..  ..  ..  64  ..  ..  ..  ..
=>0x005c100945e0: ..  96 [..] ..  ..  ..  ..  ..  ..  18  ..  ..  ..  80  ..  8e
  0x005c100945f0: ..  ba  ..  ..  ..  ..  ..  ..  64  ..  ..  ..  ..  74  ..  84
See https://clang.llvm.org/docs/HardwareAssistedAddressSanitizerDesign.html#short-granules for a description of short granule tags
SUMMARY: HWAddressSanitizer: invalid-free (/system/lib64/xxxxxx.xxxxx.so+0xxxxxx) (BuildId: xxxxxxxxxxxxxxxxxxxxxxxxxxx)

Process maps information
==appspawn==62642==Process memory map follows:
        0x000000010000-0x000100020000
        0x000100020000-0x000100030000   [anon:SizeClassAllocator: region data]
        0x000100030000-0x000100040000   [anon:SizeClassAllocator: region data]
        ...
```

For Use-After-Free (Write) problems, the logs are different in the problem overview. The following is an example output:

```
ptrBeg was re-written after free 0x000100946540[1], 0x000100946548 5555555500000009:5555555555555555
```

**0x000100946540** is the start address of the problematic memory block, **[1]** is the 8-byte offset of the detected problematic memory based on the start address, **0x000100946548** is the actual modified address, and **5555555500000009:5555555555555555** indicates the comparison between the actual value and expected value after the memory content is modified. After this line, the log also prints the allocation call stack and the deallocation call stack for the affected memory block. The stack format is identical to that used in HWAsan logs and is therefore omitted here.

### GWP-Asan

GWP-ASan logs are relatively simple. The following is a typical Use-After-Free log, which contains the allocation, release, and violation call stacks of the affected memory block.

```
Device info:XXX <- Device information
Build info:XXX-XXXX x.x.x.xx(xxxxxxx) <- Version information
Fingerprint:c41391f9c18acc1121ea519ffdba5698bfb5342ae7125e20ebf2865e31249f1a<- Feature information
Timestamp:xxxx-xx-xx xx:xx:xx.xxx <- Timestamp
Module name:com.example.sampleapplication <- Module name
Version:1.0.0 <- Version number
Pid:13305 <- Process ID
Uid:20020181 <- User ID
Reason:GWP-ASAN <- The value of Reason is fixed to GWP-ASAN
*** GWP-ASan detected a memory error ***
Use After Free at 0x5b46ddaff0 (0 bytes into a 16-byte allocation at 0x5b46ddaff0) by thread 13305 here: <- Problem overview, which describes a UAF problem
  #0 0x5c474f049c (/data/storage/xxxxxx.so+0x3049c) <- Call stack information
  #1 0x5c474fa8c0 (/data/storage/xxxxxx.so+0x3a8c0)
  #2 0x5c474fa870 (/data/storage/xxxxxx.so+0x3a870)
  #3 0x5c474fa834 (/data/storage/xxxxxx.so+0x3a834)
  #4 0x5c474fa7d4 (/data/storage/xxxxxx.so+0x3a7d4)
  #5 0x5c474fa4a0 (/data/storage/xxxxxx.so+0x3a4a0)
  #6 0x5b2d444c04 (/system/lib64/platformsdk/libace_napi.z.so+0x44c04)
  #7 0x5b401d484c
  #8 0x5b3fc11d7c
  #9 0xfffffffffffffffe
0x5b46ddaff0 was deallocated by thread 13305 here: <- Problem overview, which is the deallocation stack
  #0 0x5aa0c0be2c (/lib/ld-musl-aarch64.so.1+0x13de2c) <- Call stack information
  #1 0x5aa0c0b97c (/lib/ld-musl-aarch64.so.1+0x13d97c)
  #2 0x5c474f0494 (/data/storage/xxxxxx.so+0x30494)
  #3 0x5c474fa8c0 (/data/storage/xxxxxx.so+0x3a8c0)
  #4 0x5c474fa870 (/data/storage/xxxxxx.so+0x3a870)
  #5 0x5c474fa834 (/data/storage/xxxxxx.so+0x3a834)
  #6 0x5c474fa7d4 (/data/storage/xxxxxx.so+0x3a7d4)
  #7 0x5c474fa4a0 (/data/storage/xxxxxx.so+0x3a4a0)
  #8 0x5b2d444c04 (/system/lib64/xxxxxx.so+0x44c04)
  #9 0x5b401d484c
  #10 0x5b3fc11d7c
  #11 0xfffffffffffffffe
0x5b46ddaff0 was allocated by thread 13305 here: <- Problem overview, which is the allocation stack
  #0 0x5aa0c0be2c (/lib/ld-musl-aarch64.so.1+0x13de2c) <- Call stack information
  #1 0x5aa0c0b77c (/lib/ld-musl-aarch64.so.1+0x13d77c)
  #2 0x5aa0c22e5c (/lib/ld-musl-aarch64.so.1+0x154e5c)
  #3 0x5c474f047c (/data/storage/xxxxxx.so+0x3047c)
  #4 0x5c474fa8c0 (/data/storage/xxxxxx.so+0x3a8c0)
  #5 0x5c474fa870 (/data/storage/xxxxxx.so+0x3a870)
  #6 0x5c474fa834 (/data/storage/xxxxxx.so+0x3a834)
  #7 0x5c474fa7d4 (/data/storage/xxxxxx.so+0x3a7d4)
  #8 0x5c474fa4a0 (/data/storage/xxxxxx.so+0x3a4a0)
  #9 0x5b2d444c04 (/system/lib64/xxxxxx.so+0x44c04)
  #10 0x5b401d484c
  #11 0x5b3fc11d7c
  #12 0xfffffffffffffffe
* End GWP-ASan report *
```
