# Custom Extension Capability Overview

The ArkUI framework offers a range of custom extension capabilities based on modifiers, allowing for the extension and modification of existing UI component attributes, gestures, and content in a way that is decoupled from the UI. This includes modifiers such as **AttributeModifier**, **GestureModifier**, and **DrawModifier**. [AttributeModifier](arkts-user-defined-extension-attributeModifier.md) and [AttributeUpdater](arkts-user-defined-extension-attributeUpdater.md), in particular, enable you to set attributes through custom classes, thereby expanding the ways in which attribute settings can be implemented and allowing them to be mixed with native attribute setting methods.

## AttributeModifier
**AttributeModifier** allows dynamic attribute modification through **Modifier** objects, overcoming the limited use cases of the @Styles and @Extend decorators in declarative syntax. It surpasses @Styles and @Extend in capability and flexibility. In light of its superior adaptability and the ongoing development to cover all aspects of attribute and event settings, it is a recommended choice.

## AttributeUpdater
As a special type of **AttributeModifier**, **AttributeUpdater** not only inherits the capabilities of **AttributeModifier** but also provides the capability to obtain the attribute object. By using the attribute object, you can update specific attributes without relying on state variables. With **AttributeUpdater**, you can implement custom update strategies, further improving the performance of attribute updates.
