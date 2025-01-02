# 常见action与entities（不推荐使用）

> **说明：**
>
> 由于Action/Entity被泛化使用，系统对应用申明Action/Entity的行为缺少管控，恶意应用虚假申明，抢占流量，导致跳转后功能不可用。后续系统会逐步废弃非必要Action/Entity，建议通过[指定类型的方式拉起应用](./start-intent-panel.md)。

**action**：表示调用方要执行的通用操作（如查看、分享、应用详情）。在隐式[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)中，您可定义该字段，配合uri或parameters来表示对数据要执行的操作。如打开，查看该uri数据。例如，当uri为一段网址，action为`ACTION_VIEW_DATA`则表示匹配可访问该网址的应用组件。在Want内声明action字段表示希望被调用方应用支持声明的操作。在被调用方应用配置文件skills字段内声明actions表示该应用支持声明操作。

**常见action**


- ACTION_HOME：启动应用入口组件的动作，需要和ENTITY_HOME配合使用；系统桌面应用图标就是显式的入口组件，点击也是启动入口组件；入口组件可以配置多个。

- ACTION_CHOOSE：选择本地资源数据，例如联系人、相册等；系统一般对不同类型的数据有对应的Picker应用，例如联系人和图库。

- ACTION_VIEW_DATA：查看数据，当使用网址uri时，则表示显示该网址对应的内容。具体操作流程请见[通过startAbility拉起文件处理类应用](./file-processing-apps-startup.md)。

- ACTION_VIEW_MULTIPLE_DATA：发送多个数据记录的操作。

**entities**：表示目标应用组件的类别信息（如浏览器、视频播放器），在隐式[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)中是对action的补充。在隐式Want中，开发者可定义该字段，来过滤匹配应用的类别，例如必须是浏览器。在Want内声明entities字段表示希望被调用方应用属于声明的类别。在被调用方应用配置文件skills字段内声明entites表示该应用支持的类别。

**常见entities**


- ENTITY_DEFAULT：默认类别无实际意义。

- ENTITY_HOME：主屏幕有图标点击入口类别。

- ENTITY_BROWSABLE：指示浏览器类别。