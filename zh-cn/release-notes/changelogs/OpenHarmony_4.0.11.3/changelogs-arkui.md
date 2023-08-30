# arkui子系统ChangeLog

## cl.arkui.1 button组件对fontSize设置为负数（即异常值）时的处理规则进行细化，保证取值合理性。

**变更影响**

变更前，开发者设置负数时，fontSize为开发者设置的负数值，即最终效果与fontSize=0的效果一致，文字内容不显示<br>
变更后，开发者设置负数时，fontSize为默认值16fp。<br>
说明：fontSize=0的效果未变更，都是文字不显示的效果，以上变更仅涉及开发者设置fontSize<0的异常场景

## cl.arkui.2 Search组件动态改变属性时，输入框内容变化情况变更，保证输入框内容的正确性。

**变更影响**

变更前，开发者在Search组件接口中只设置placeholder不设置value时，动态改变Search的属性，Search中的内容会被清空。<br>
变更后，开发者在Search组件接口中只设置placeholder不设置value时，动态改变Search的属性，Search中的内容会保持不变。
说明：变更后为正常使用search的期望行为。