# arkui子系统ChangeLog

## cl.arkui.1 TextInput、TextArea、Search组件行为变更

arkui子系统TextInput、TextArea、Search组件行为存在变更：

 - 获焦默认拉起输入法

开发者需要根据以下说明对应用进行适配。


**变更影响**

影响Api version 10的TextInput、TextArea、Search组件

**关键的接口/组件变更**

 - TextInput、TextArea、Search组件获焦会拉起输入法

**适配指导**

不同场景下的启动规则说明如下：
开发者适配内容：

  - TextInput、TextArea、Search组件获焦会拉起输入法
    - 通过接口enableKeyboardOnFocus(bool)控制是否获焦拉起输入法，此接口参数默认值为true。
        
