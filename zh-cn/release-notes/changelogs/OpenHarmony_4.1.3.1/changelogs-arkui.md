#  arkui子系统ChangeLog

## cl.arkui.1 尺寸设置constraintSize minWidth接口变更

**访问级别**

公开接口

**变更原因**

在API version 10上使用constraintSize minWidth存在错误，因此需要限制constraintSize minWidth接口生效的API版本范围，使得minWidth在API version 10及以下的SDK中不生效。

**变更影响**

该变更为非兼容变更。

**变更发生版本**

从OpenHarmony SDK 4.1.3.1开始。

**flex组件**

变更前：API version 10使用constraintSize minWidth接口正常生效。

变更后：API version 11及更高的版本使用constraintSize minWidth接口正常生效。API version 10及更低的版本中constraintSize minWidth接口不再生效。

**适配指导**

若使用API version 10及以下的SDK时，通过constraintSize minWidth接口约束组件的最小宽度，需要修改代码。当宽度变化时，若当前宽度小于minWidth，则直接设置组件宽度的数值。
从API version 11开始，设置minWidth约束组件的最小宽度正常生效。