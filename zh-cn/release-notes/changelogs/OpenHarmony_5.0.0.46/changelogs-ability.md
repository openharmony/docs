# 方舟编译运行时子系统删除说明
## cl.arkcompiler.1 /dev/ubsan/ 路径删除

**访问级别**

其他。

**删除原因**

1. 设备侧的 /dev/ubsan 路径用来落盘 ubsan 日志，dfx 接入之后日志保存到 /data/log/faultlog/faultlogger 路径下，/dev/ubsan 路径被废弃。
2. /dev/ubsan 路径无法对多用户的读写权限进行隔离，存在安全隐患。

**删除影响**

该变更为不兼容变更。

删除后开发者无法读写 /dev/ubsan 路径。

**删除发生版本**

从OpenHarmony 5.0.0.46开始。

**删除的接口/组件**

删除前：可读写 /dev/ubsan/ 路径。

删除后：无法读写 /dev/ubsan/ 路径。

**适配指导**

不涉及。