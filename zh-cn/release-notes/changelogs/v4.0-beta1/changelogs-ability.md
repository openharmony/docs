# 元能力子系统ChangeLog


## cl.ability.1 appRecovery接口中RestartFlag属性名称变更，删除了未支持的属性

appRecovery接口中RestartFlag枚举命名从特定故障发生后**不重启**改成了特定故障发生后**重启**。  
删除了CPP_CRASH_NO_RESTART。

**变更影响**

4.0.2.3版本之前使用CPP_CRASH_NO_RESTART/JS_CRASH_NO_RESTART/APP_FREEZE_NO_RESTART类型开发的应用，在4.0.2.3版本之后行为会发生变化。

**关键接口/组件变更**

**RestartFlag** <sup>9+</sup>

变更前：
| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALWAYS_RESTART           | 0    | 总是重启应用。 |
| CPP_CRASH_NO_RESTART           | 0x0001    | 发生CPP_CRASH时**不重启**应用。 |
| JS_CRASH_NO_RESTART           | 0x0002    | 发生JS_CRASH时**不重启**应用。 |
| APP_FREEZE_NO_RESTART           | 0x0004    | 发生APP_FREEZE时**不重启**应用。 |
| NO_RESTART           | 0xFFFF    | 总是不重启应用。 |

变更后：
| 名称       | 值   | 说明       |
| ---------- | ---- | ---------- |
| ALWAYS_RESTART   | 0    | 总是重启应用。 |
| CPP_CRASH_NO_RESTART   | NA    | **删除**，不支持该场景的重启。 |
| RESTART_WHEN_JS_CRASH   | 0x0001    | 发生JS_CRASH时**重启**应用。 |
| RESTART_WHEN_APP_FREEZE   | 0x0002    | 发生APP_FREEZE时**重启**应用。 |
| NO_RESTART           | 0xFFFF    | 总是不重启应用。 |

**适配指导**

按新的语义进行适配。
