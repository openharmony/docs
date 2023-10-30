# arkui子系统ChangeLog

## cl.arkui.1 List中的滚动条边距由跟随padding变更为不跟随padding

**变更影响**

API10之前，List的滚动条边距会受到padding的影响，滚动条在List设置了padding时，位置会被向内挤压。

API10之后，List的滚动条边距不会受到padding的影响，距离List的边距为固定的4vp。

## cl.arkui.2 滚动条底部和顶部预留距离由固定值变更为根据滑动组件的圆角值动态计算。

**变更影响**

变更前，滚动条底部和顶部预留距离是固定值（横向滚动条则为左边和右边预留距离），不会随滑动组件的圆角变化而动态变化。

变更后，滚动条底部和顶部预留距离会根据滑动组件的圆角值动态计算，避免被圆角截断。例如，当Scroll组件的圆角值为0时，滚动条的底部预留距离为0，滚动条可以滑动Scroll的底部。

## cl.arkui.3 通用属性position设置在宽高为0的组件上时由不生效变更为生效

**变更影响**

API version 10之前，如果一个组件的宽或高设置为0，则该组件所设置的通用属性position不生效。

API version 10之后，如果一个组件的宽或高设置为0，则该组件所设置的通用属性position生效。

**适配方法**
如果宽或高为0的组件因设置了position而发生了布局上的变化，可以将设置的position属性取消来与变更前保持一致。

## cl.arkui.4 Flex上设置的itemAlign.Auto相当于itemAlign.Start

**变更影响**

4.1.1.1之前，Flex设置itemAlign.Auto时，设置itemAlign.Auto在交叉轴上会跟随其他组件。

4.1.1.1之后，Flex设置itemAlign.Auto时，相当于设置了itemAlign.Start。