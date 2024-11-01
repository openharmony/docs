# 文件子系统变更说明
## cl.CoreFileKit.1 symlink、symlinkSync接口行为变更

**访问级别**

公开接口

**变更原因**

360加固强依赖/proc/{pid}/status节点st_blksize返回值，当前HM和Linux实现存在差异，导致使用了360加固的APP启动失败。

**变更影响**

该变更为不兼容变更。

变更前：通过stat获取/proc下的节点的st_blocksize为4096。

变更后：通过stat获取/proc下的节点的st_blocksize为1024。

**起始API Level**

API 14

**变更发生版本**

从OpenHarmony 5.0.2.1 版本开始。

**变更的接口/组件**
CoreFileKit： stat



stat接口

**适配指导**

排查应用实现中是否存在依赖此接口获取proc下节点的blocksize的场景。若涉及，需要适配该值为1024并处理。