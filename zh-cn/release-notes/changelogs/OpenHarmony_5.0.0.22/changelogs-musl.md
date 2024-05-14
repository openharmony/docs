# 方舟编译运行时子系统变更说明

## cl.arkcompiler.1 stat/shminfo/msqid_ds/icmphdr/mq_attr/utmpx的__unused字段更名为__unused1

**访问级别**

公开接口

**变更原因**

结构体stat, shminfo, msqid_ds, icmphdr, mq_attr, utmpx 中的`__unused`字段会和`sys/cdefs.h`中的`__unused`宏定义发生冲突，开发者同时引入时会造成编译报错。

**变更影响**

该变更为非兼容性变更。

API version 11及之前，可正常使用上述结构体的`__unused`字段。

API version 12及以后，使用到上述结构体的`__unused`字段时，会发生编译报错，需要开发者将上述用到的`__unused`字段修改为`__unused1`。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.22 版本开始。

**变更的接口/组件**

结构体 stat, shminfo, msqid_ds, icmphdr, mq_attr, utmpx。

**适配指导**

如果之前用到了上述结构体的`__unused`字段，需要修改为`__unused1`。

如果没有用到，则无需适配，按原方式继续使用即可。

`cdefs.h` 中 `__unused` 宏定义使用不受影响。