# OH_PasteboardObserver
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @zhusiyuan2-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->

```c
typedef struct OH_PasteboardObserver OH_PasteboardObserver
```

## 概述

定义剪贴板数据变更观察者。用于监听系统剪贴板数据的变化事件，当剪贴板内容发生更新时，通过回调通知应用。典型使用场景：需要响应剪贴板内容变化的应用。

**起始版本：** 13

**相关模块：** [Pasteboard](capi-pasteboard.md)

**所在头文件：** [oh_pasteboard.h](capi-oh-pasteboard-h.md)

