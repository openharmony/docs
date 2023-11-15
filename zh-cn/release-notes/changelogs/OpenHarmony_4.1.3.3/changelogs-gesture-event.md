# ArkUI子系统变更说明
## 手势事件出参中的控件坐标系数据规格明确
**访问级别**
公开接口
**变更原因**
以往规格不明确，仿射变换后，事件响应的控件坐标是错误的，不对应到控件坐标系
**变更影响**
此次变更，会返回开发者准确的控件坐标系下的数据
**变更发生版本**
从OpenHarmony SDK 4.1.3.3开始
**变更的接口/组件**
GestureEvent中的offsetX、offsetY、pinchCenterX、pinchCenterY、speed
FingerInfo中的localX、localY
ClickEvent中的x、y
TouchObject中的x、y
**适配指导**
此次变更，会返回开发者准确的控件坐标下的数据