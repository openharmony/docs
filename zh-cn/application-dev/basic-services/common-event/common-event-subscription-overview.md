# 公共事件订阅概述

公共事件服务提供了动态订阅和静态订阅两种订阅方式。动态订阅与静态订阅最大的区别在于，动态订阅是应用运行时的行为，而静态订阅是后台服务，无需处于运行状态。

- 动态订阅：指订阅方在运行时调用公共事件订阅的API实现对公共事件的订阅，详细请参见[动态订阅公共事件](common-event-subscription.md)。

- 静态订阅：订阅方通过配置文件声明和实现继承自StaticSubscriberExtensionAbility的类实现对公共事件的订阅，详细请参见[静态订阅公共事件](common-event-static-subscription.md)。