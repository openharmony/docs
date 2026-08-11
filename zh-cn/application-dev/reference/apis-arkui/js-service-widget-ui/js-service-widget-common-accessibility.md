# 无障碍
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyinhua-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

组件可以设置相应的无障碍属性和事件来更好地使用无障碍能力，支持配置无障碍分组、无障碍文本、无障碍说明和无障碍重要性等属性，并可通过无障碍事件接收无障碍辅助服务下发的事件以响应自定义无障碍交互，适用于需要为服务卡片提供屏幕朗读等无障碍辅助功能的场景，帮助视障等特殊人群清晰地了解当前选中组件及操作后果，提升应用的无障碍可达性。

> **说明：**
>
> 从API version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 无障碍属性

| 名称 | 类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| accessibilitygroup | boolean | false | 无障碍组，设置为true时表示该组件及其所有子组件为一个整体的可选中组件，无障碍辅助服务将不再关注其子组件内容；设置为false表示不启用无障碍分组。 |
| accessibilitytext | string | - | 无障碍文本，当组件不包含可被屏幕朗读的文本属性（如image等本身不直接显示文本的组件）时，屏幕朗读选中此组件时不播报，使用者无法清楚地知道当前选中了什么组件。为了解决此问题，开发人员可为不包含文本属性的组件设置无障碍文本，当屏幕朗读选中此组件时播报无障碍文本的内容。若组件既拥有文本属性，又拥有无障碍文本属性，则组件被选中时，以无障碍文本内容替代文本属性进行播报。 |
| accessibilitydescription | string | - | 无障碍说明，用于为用户进一步说明当前组件，尤其是当操作后果无法从组件本身属性与无障碍文本中了解到时。开发人员可为组件设置详细的解释文本，说明操作的预期后果。若组件设置了无障碍说明属性，则组件被选中时，先播报组件的文本属性（若已设置accessibilitytext则播报accessibilitytext的内容），再播报无障碍说明属性的内容。 |
| accessibilityimportance | string | auto | 无障碍重要性，用于控制某个组件是否可被无障碍辅助服务所识别。具体值可以设置为auto、yes、no和no-hide-descendants。若设置为auto，则由系统根据组件类型自动决定是否可被无障碍辅助服务识别；若设置为yes，则当前组件可被无障碍辅助服务选中；若设置为no，则当前组件不可被无障碍辅助服务选中；若设置为no-hide-descendants，则无障碍辅助服务忽略当前组件及其所有子组件。 |

- accessibilitygroup
  
  ```html
  <div accessibilitygroup="true">
    <text>text1</text>
    <text>text2</text>
  </div>
  ```

- accessibilitytext
  
  ```html
  <image src="common/image/barrierfree.jpg" accessibilitytext="这是一张风景图"></image>
  ```

- accessibilitydescription
  
  ```html
  <!-- showDialog为开发者自定义的事件处理函数，需在JS文件中定义 -->
  <button accessibilitydescription="点击此按键会弹出一个对话框" onclick="showDialog">按键</button>
  ```

- accessibilityimportance

  默认情况下（即accessibilityimportance为auto时），div、text等不具备交互语义的容器和文本类组件不会被无障碍辅助服务选中。如需使这些默认不会被选中的组件可被选中，则为该组件设置accessibilityimportance="yes"。以下示例展示了设置为no-hide-descendants时，当前组件及其子组件均被无障碍辅助服务忽略的效果：

  
  ```html
  <div accessibilityimportance="no-hide-descendants">
    <text>text</text>
  </div>
  ```


## 无障碍事件

| 名称 | 参数 | 描述 |
| -------- | -------- | -------- |
| accessibility | AbilityEvent | 无障碍服务下发的事件。当无障碍辅助服务（如屏幕朗读）与组件交互时触发，开发者可在回调中根据eventType参数处理无障碍焦点变化或响应自定义无障碍交互。 |

  **表1**AbilityEvent属性列表

| 属性 | 类型 | 说明 |
| -------- | -------- | -------- |
| eventType | number | 事件类型：<br/>-&nbsp;0：custom&nbsp;event<br/>-&nbsp;1：accessibility&nbsp;focus<br/>-&nbsp;2：clear&nbsp;accessibility&nbsp;focus<br/>无障碍服务下发的自定义事件为0，无障碍服务下发的获焦事件为1，无障碍服务下发的失焦事件为2。 |
| param | Object | 无障碍辅助应用发送自定义事件时需传入的参数对象，参数内容取决于自定义事件的具体业务场景，可包含与该事件相关的业务数据字段。 |
