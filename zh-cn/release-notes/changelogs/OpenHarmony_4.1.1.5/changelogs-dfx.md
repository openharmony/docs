# DFX子系统ChangeLog

## cl.hiviewdfx.1 HiSysEvent模块write接口对系统事件打点频率管控规格变更

hiSysEvent模块write接口对系统事件打点频率的管控规格不能满足部分高频业务场景，故需要对此规格进行调整：

  - 由5秒周期内10次系统事件打点限制，变更为5秒周期内100次系统事件打点限制。

**变更影响**

hiSysEvent模块的write接口对系统事件打点频率的管控规格能够满足更高频的打点业务场景。

**关键的接口/组件变更**

涉及接口
  - Rust接口：hisysevent::write；
  - JS接口：hiSysEvent.write；
  - C++接口：HiSysEventWrite；
  - C接口：HiSysEvent_Write；

**适配指导**

内部管控逻辑参数调整，无需额外适配。
