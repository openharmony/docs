# 简介


本章介绍如何使用方舟开发框架“一多”能力，开发出在多设备上正常显示的页面。方舟开发框架推荐开发者使用声明式开发范式开发应用，故本章的内容和示例都主要基于声明式开发范式。本章主要包含如下内容：


- [布局能力](adaptive-layout.md)
  
  布局决定了页面中的元素按照何种方式排布及显示，是页面设计及开发过程中首先需要考虑的问题。一般情况下，可以通过页面（或自定义组件）内的组件结构（组件个数、组件的父子/兄弟关系、组件类型、组件的相对位置）来判断使用何种布局能力。
  
  - 对于随尺寸变化组件结构相同的场景，可以在开发过程中灵活使用[自适应布局能力](adaptive-layout.md)来达到目标效果。
  - 对于随尺寸变化组件结构不同的场景，更适合使用[响应式布局能力](responsive-layout.md)来实现不同尺寸下的不同显示的效果。
  
- [交互归一](interaction-event-normalization.md)

- [多态组件](polymorphic-controls.md)

- [资源使用](resource-usage.md)


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 开发多设备上同一页面时，建议开发者多使用[自定义组件](../../ui/ts-component-based-component.md)，既可以增加代码的可读性和可维护性，同时也可以尽可能的实现代码复用。
> 
> - 本章中涉及的示例代码均可以在[OpenHarmony应用示例](https://gitee.com/openharmony/applications_app_samples/tree/master/MultiDeviceAppDev)中获取，感兴趣的开发者可以自行下载、运行及查看效果。
