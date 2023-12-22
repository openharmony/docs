# ArkUI子系统变更说明

## cl.arkui.1 Slider设置showTips方法显示效果变更

**访问级别**

公开接口

**变更原因**

该变更为兼容性变更，约束了Silder气泡的使用，优化了slider气泡的样式。

**变更影响**

Slider通过设置showTips方法，显示气泡。该方法有两个参数，参数1:boolean类型，表示是否显示气泡；参数2:ResourceStr类型，表示气泡中的文本内容。
具体受影响的场景见下文：

a) showTips 第一个参数设置为true显示气泡，气泡样式变化

变更前气泡样式：

![Alt text](oldVertical.png)![Alt text](oldHorizontal.png)

变更后气泡样式：

![Alt text](newVertical.png)![Alt text](newHorizontal.png)

b) showTips 第二个参数设置文本内容时，文本内容可能产生变化

变更前：根据栅格化宽度，可多行显示文本，全量显示文本。

变更后：单行显示文本，文本最大宽度36vp，即最大显示2个中文字符或4个数字。

**API Level**

7

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

滑动条（Slider）

**适配指导**

默认行为变更，不涉及适配。

## cl.Arkui.2 Progress组件的默认颜色变更

**访问级别**

公开接口

**变更原因**

当前Progress组件的默认进度条前景色、默认进度条底色和默认内描边颜色不符合UX规范，因此依照UX规范对相关默认颜色做出变更。

**变更影响**

该变更为兼容性变更，改变了组件默认情况下的显示颜色，提升了组件的默认显示效果。

**API Level**

8

**变更发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**变更的接口/组件**

API 11前，胶囊样式进度条默认前景色是系统资源中的`ohos_id_color_emphasize_contrary`，默认内描边颜色是系统资源中的`ohos_id_color_emphasize_contrary`，环形样式进度条默认进度条底色是系统资源中的`ohos_id_color_component_normal`。

API 11及以后，胶囊样式进度条默认前景色是系统资源中的`ohos_id_color_emphasize`，前景色不透明度为系统资源中的`ohos_id_alpha_highlight_bg`，默认内描边颜色是系统资源中的`ohos_id_color_emphasize`，内描边颜色不透明度为系统资源中的`ohos_id_alpha_highlight_bg`，环形样式进度条默认进度条底是系统资源中的`ohos_id_color_button_normal`。

**适配指导**

默认颜色变更，不涉及适配。