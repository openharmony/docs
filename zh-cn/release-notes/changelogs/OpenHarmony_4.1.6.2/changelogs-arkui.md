# ArkUI子系统ChangeLog

OpenHarmony 4.1.6.2 版本相较于OpenHarmony 之前的版本，dialog组件默认行为变更如下。

## cl.arkui.1 AlertDialog、ActionSheet设置主标题、副标题超长文本显示效果变更

**访问级别**

公开接口

**变更原因**

规格优化。

**变更影响**

该变更为兼容性变更。

AlertDialog、ActionSheet支持通过设置title、subtitle参数显示主标题、副标题：

a) 设置title为超长文本显示

变更前：文本最多显示一行，超长时'...'截断

变更后：文本先逐级缩小字号到16fp，继续超长，换行处理，支持换一行，仍然超长'...'截断。

b) 设置subtitle为超长文本显示

变更前：文本最多显示一行，超长时'...'截断

变更后：文本先逐级缩小字号到12fp，继续超长，换行处理，支持换一行，仍然超长'...'截断。

**API Level** 

AlertDialog的title从API Version 7开始支持，subtitle从API Version 10开始支持。

ActionSheet的title从API Version 8开始支持，subtitle从API Version 10开始支持。

**变更发生版本**

从OpenHarmony SDK 4.1.6.2开始。

**变更的接口/组件**

警告弹窗（AlertDialog）、列表选择弹窗（ActionSheet）

**适配指导**

默认行为变更，不涉及适配。

## cl.arkui.2 promptAction.showDialog设置主标题超长文本显示效果变更

**访问级别**

公开接口

**变更原因** 

规格优化。

**变更影响**

该变更为兼容性变更。

promptAction.showDialog支持通过设置title参数显示主标题：

设置title为超长文本显示

变更前：文本最多显示一行，超长时'...'截断

变更后：文本先逐级缩小字号到16fp，继续超长，换行处理，支持换一行，仍然超长'...'截断。

**API Level** 

9

**变更发生版本**

从OpenHarmony SDK 4.1.6.2开始。

**变更的接口/组件**

对话框弹窗（promptAction.showDialog）

**适配指导**

默认行为变更，不涉及适配。