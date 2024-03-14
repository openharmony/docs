# DFX子系统变更说明

## HiDumper组件的图形内存统计方式变更

**访问级别**

其他

**变更原因**

hidumper --mem pid中原始Graph的值为调用RenderService提供的接口所得，无法获取到对应的ION/DMA内存，现在变更为Graph值从/proc/process_dmabuf_info节点中获取。

**变更影响**

执行hidumper --mem pid查看指定进程的Pss内存时，会多出一部分Graph的值。

**变更发生版本**

从OpenHarmony SDK 4.1.6.7 开始。

**变更的接口/组件**

受影响的组件：HiDumper
变更前：执行hidumper --mem pid命令，内存信息中Graph的统计方式为调用RenderService提供的接口所得
变更后：执行hidumper --mem pid命令，内存信息中Graph的统计方式变更为读取/proc/process_dmabuf_info节点。

**适配指导**

无需适配
