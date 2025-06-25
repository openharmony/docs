# 自定义扩展能力概述

ArkUI框架提供一系列基于Modifier的自定义扩展能力，通过与UI分离的方式，对已有UI组件的属性、手势、内容进行扩展修改，以满足开发者在不改变UI组件底层实现的情况下，快速调整UI组件外观、行为等需求。自定义扩展包括[AttributeModifier](arkts-user-defined-extension-attributeModifier.md)、[GestureModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-gesture-modifier.md#gesturemodifier-1)、[DrawModifier](arkts-user-defined-extension-drawModifier.md)等。其中[AttributeModifier](arkts-user-defined-extension-attributeModifier.md)和[AttributeUpdater](arkts-user-defined-extension-attributeUpdater.md)允许开发者通过自定义类设置属性，扩展了属性设置的实现方式，能够与组件属性设置方式混合使用。例如，使用自定义扩展处理特定的逻辑或复杂交互，使用组件设置方式处理简单静态属性等。

## AttributeModifier
声明式语法引入的[@Styles](../ui/state-management/arkts-style.md)和[@Extend](../ui/state-management/arkts-extend.md)两个装饰器，虽然可以解决复用相同自定义样式的问题，但是使用场景存在一定局限性，如无法跨文件导出等。为此，ArkUI引入了`AttributeModifier`机制，可以通过Modifier对象动态修改属性。与@Styles和@Extend相比，AttributeModifier提供了更强的能力和灵活性，且在持续完善全量的属性和事件设置能力，因此推荐优先使用AttributeModifier。

## AttributeUpdater
`AttributeUpdater`是一个特殊的`AttributeModifier`，除了继承`AttributeModifier`的能力，还提供了获取属性对象的能力。通过属性对象可以不经过状态变量，直接更新对应属性。开发者可以通过`AttributeUpdater`实现自定义的更新策略，进一步提高属性更新的性能。

## DrawModifier
`DrawModifier`提供自定义绘制能力。当某些组件本身的绘制内容不满足需求时，开发者可以使用`DrawModifier`在原有组件基础上部分绘制、或者全部自行绘制，以达到预期效果。