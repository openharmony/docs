# 自定义扩展能力概述

ArkUI框架提供一系列基于Modifier的自定义扩展能力，通过与UI分离的方式，对已有UI组件的属性、手势、内容进行扩展修改。包括[AttributeModifier](arkts-user-defined-extension-attributeModifier.md)、[GestureModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-gesture-modifier.md#gesturemodifier-1)、[DrawModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-draw-modifier.md#drawmodifier-1)等。其中AttributeModifier和[AttributeUpdater](arkts-user-defined-extension-attributeUpdater.md)允许开发者通过自定义类设置属性，扩展了属性设置的实现方式，能够与原生属性设置方式混合使用。

## AttributeModifier
声明式语法引入的[@Styles](../quick-start/arkts-style.md)和[@Extend](../quick-start/arkts-extend.md)两个装饰器，虽然可以解决部分复用的问题，但是使用场景十分受限。为此，ArkUI引入了`AttributeModifier`的机制，可以通过Modifier对象动态修改属性。与@Styles和@Extend相比，AttributeModifier的能力和灵活性更好。当前持续在构建全量的属性、事件设置能力，推荐使用。

## AttributeUpdater
`AttributeUpdater`是一个特殊的`AttributeModifier`，除了继承`AttributeModifier`的能力，还提供了获取属性对象的能力。通过属性对象可以不经过状态变量，直接更新对应属性。开发者可以通过`AttributeUpdater`实现自定义的更新策略，进一步提高属性更新的性能。