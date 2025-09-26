# PageAbility组件配置

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @lidongrui-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


PageAbility的相关配置在config.json配置文件的"module"对象的"abilities"对象中，"icon"属性表示Ability图标资源文件的索引，"label"属性表示Ability对用户显示的名称，"skills"属性表示Ability能够接收的want的特征。


  **表1** PageAbility部分配置项说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 | 
| -------- | -------- | -------- | -------- |
| icon | 表示Ability图标资源文件的索引。取值示例：$media:ability_icon。如果在该Ability的skills属性中，actions的取值包含&nbsp;"action.system.home"，entities取值中包含"entity.system.home"，则该Ability的icon将同时作为应用的icon。如果存在多个符合条件的Ability，则取位置靠前的Ability的icon作为应用的icon。<br/>说明：应用的"icon"和"label"是用户可感知配置项，需要区别于当前所有已有的应用"icon"或"label"（至少有一个不同）。 | 字符串 | 可缺省，缺省值为空。 | 
| label | 表示Ability对用户显示的名称。取值可以是Ability名称，也可以是对该名称的资源索引，以支持多语言。如果在该Ability的skills属性中，actions的取值包含&nbsp;"action.system.home"，entities取值中包含"entity.system.home"，则该Ability的label将同时作为应用的label。如果存在多个符合条件的Ability，则取位置靠前的Ability的label作为应用的label。<br/>说明：&nbsp;应用的"icon"和"label"是用户可感知配置项，需要区别于当前所有已有的应用"icon"或"label"（至少有一个不同）。该标签为资源文件中定义的字符串的引用，或以"{}"包括的字符串。该标签最大长度为255字节。 | 字符串 | 可缺省，缺省值为空。 | 
| skills | 表示Ability能够接收的want的特征。 | 对象数组 | 可缺省，缺省值为空。 | 
