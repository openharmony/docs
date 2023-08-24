# arkui子系统ChangeLog

## cl.arkui.1 PanelHeight枚举的WRAP_CONTENT值从0变更为'wrapContent'

**变更影响**

变更前，开发者设置customHeight(0)和customHeight(PanelHeight.WRAP_CONTENT)都会自适应内容高度。</br>
变更后，开发者设置customHeight(0)将内容高度设置为0，customHeight(PanelHeight.WRAP_CONTENT)自适应内容高度。

**关键的接口变更**

PanelHeight枚举的WRAP_CONTENT值从0变为'wrapContent'，接口行为变更对开发者无影响。

## cl.arkui.2 aspectRatio设置非法值和undefined时，默认值从1.0变为null。

**变更影响**

变更前，开发者设置负数和undefined，aspectRatio = 1.0

变更后，开发者设置负数和undefined，aspectRatio为null。例如，Row只设置宽度且没有子组件，aspectRatio不设置值或者设置成负数时，此时Row高度为0。
