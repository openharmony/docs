# 菜单概述

菜单是一种用于给用户提供可执行的操作的弹窗，一般用于鼠标右键弹窗、点击弹窗等。

## 使用场景

| 接口|使用场景  |
| ----------| ----------------------------------- |
| [菜单控制 (Menu)](arkts-popup-and-menu-components-menu.md) | 用于需要给指定的组件绑定用户可执行的操作时，例如长按图标展示操作选项等。 |
| [不依赖UI组件的全局菜单 (openMenu)](arkts-popup-and-menu-components-uicontext-menu.md) | 用于需要在无法直接访问UI组件的场景中给用户可执行的操作时，例如在事件回调中展示操作选项等。 |

## 规格约束

* Menu通过调用[show](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11)参数弹出时，需要等待页面全部构建完成才能展示，因此show不能在页面构建中设置为true，否则会导致menu弹窗显示位置及形状错误。
* openMenu的弹出需要传入有效的[TargetInfo](../reference/apis-arkui/js-apis-arkui-UIContext.md#targetinfo18)，否则无法弹出气泡。
* 其他规格约束，具体可参考[菜单控制](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md)、[openMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#openmenu18) 说明。