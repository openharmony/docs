# DataAbility组件概述
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


DataAbility，即"使用Data模板的Ability"，主要用于对外部提供统一的数据访问抽象，不提供用户交互界面。DataAbility可由PageAbility、ServiceAbility或其他应用启动，即使用户切换到其他应用，DataAbility仍将在后台继续运行。


使用DataAbility有助于应用管理其自身和其他应用存储数据的访问，并提供与其他应用共享数据的方法。DataAbility既可用于同设备不同应用的数据共享，也支持跨设备不同应用的数据共享。


数据的存放形式多样，可以是数据库，也可以是磁盘上的文件。DataAbility对外提供对数据的增、删、改、查，以及打开文件等接口，这些接口的具体实现由开发者提供。
