# 进程线程通信<!--app-events-->
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

- 使用公共事件进行进程间通信<!--common-event-communication-->
    - [公共事件简介](common-event-overview.md)
    - [动态订阅公共事件](common-event-subscription.md)
    <!--Del-->
    - [静态订阅公共事件（仅对系统应用开放）](common-event-static-subscription-sys.md)
    <!--DelEnd-->
    - [取消动态订阅公共事件](common-event-unsubscription.md)
    - [发布公共事件](common-event-publish.md)
    <!--Del-->
    - [移除粘性公共事件（仅对系统应用开放）](common-event-remove-sticky-sys.md)
    <!--DelEnd-->
    - [订阅公共事件（C/C++）](native-common-event-subscription.md)
    - [取消订阅公共事件（C/C++）](native-common-event-unsubscription.md)
    - [发布公共事件（C/C++）](native-common-event-publish.md)
    - [Common Event Service术语](common-event-glossary.md)
- [使用Emitter进行线程间通信](itc-with-emitter.md)