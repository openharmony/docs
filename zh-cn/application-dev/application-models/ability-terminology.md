# Ability Kit术语

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @ccllee1-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## A

### AbilityStage

[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)是一个[Module](../quick-start/application-package-overview.md#应用的多module设计机制)级别的组件管理器。

### ArkTS子进程

ArkTS子进程是指启动后系统默认创建ArkTS运行时环境的应用子进程。


## C

### CandidateMasterProcess（备选主控进程）

当应用存在多个进程时，系统会在应用启动时自动指定主控进程。如果开发者希望当前进程被选为主控进程，可以将其放入备选主控进程列表中，该列表中的进程即为备选主控进程。当现在的主控进程销毁后，系统会将位于链表首节点的备选主控进程设置为主控进程。


## M

### MasterProcess（主控进程）

当应用存在多个进程时，如果开发者需要将不同的Ability实例动态分配给指定进程，系统会在应用启动时自动指定一个进程来负责总体的协调分配工作，该进程即为主控进程。默认情况下，系统指定应用启动的第一个进程为主控进程。

开发者可以设置[onNewProcessRequest](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onnewprocessrequest11)的返回值，让主控进程通过接收该接口的回调信息，决定新的Ability实例运行在哪个进程中。


## N

### Native子进程

Native子进程是指启动后只有C/C++代码运行环境的应用子进程，针对这种类型的子进程系统默认不会创建ArkTS运行时环境。