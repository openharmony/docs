# arkui子系统ChangeLog

## cl.arkui.1 List组件滚动条状态设置undefined或非法值处理变更

**变更影响**

OpenHarmony_4.0.10.1之前，开发者设置scrollBar(undefined), scrollBar('aaa'), scrollBar(-1)会处理成BarState.Off状态。</br>
OpenHarmony_4.0.10.2及之后，开发者设置scrollBar(undefined), scrollBar('aaa'), scrollBar(-1)会处理成默认值BarState.Auto状态。

**关键的接口变更**

List组件scrollBar接口设置undefined或非法值的处理方式由BarState.Off变更为BarState.Auto。

## cl.arkui.2 Grid组件滚动条状态设置undefined或非法值处理变更

**变更影响**

OpenHarmony_4.0.10.1之前，开发者设置scrollBar(undefined), scrollBar('aaa'), scrollBar(-1)会处理成BarState.Off状态。</br>
OpenHarmony_4.0.10.2及之后，开发者设置scrollBar(undefined), scrollBar('aaa'), scrollBar(-1)会处理成默认值BarState.Auto状态。

**关键的接口变更**

Grid组件scrollBar接口设置undefined或非法值的处理方式由BarState.Off变更为BarState.Auto。