# 属性更新器 (AttributeUpdater)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

## 概述

在大量属性频繁更新的场景下，使用状态变量可能导致前端状态管理的计算量过大，并且需要对单个组件进行全量属性更新。尽管可以通过[AttributeModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md)机制实现按需更新属性，但前端仍会采用一定的diff和reset策略，这可能带来性能问题。

`AttributeUpdater`作为一个特殊的`AttributeModifier`，不仅继承了`AttributeModifier`的功能，还提供了直接获取属性对象的能力。通过属性对象，开发者能够直接更新对应属性，无需经过状态变量。开发者可以利用`AttributeUpdater`实现自定义的更新策略，从而进一步提升属性更新的性能。

由于`AttributeUpdater`提供了较高的灵活性，无法限制“单一数据源”的规则，因此在与状态变量同时更新同一属性时，存在相互覆盖的情况。这要求开发者必须确保属性设置的合理性。

## 接口定义

```ts
export declare class AttributeUpdater<T, C = Initializer<T>> implements AttributeModifier<T> {

  applyNormalAttribute?(instance: T): void;

  initializeModifier(instance: T): void;

  get attribute(): T | undefined;

  updateConstructorParams: C;
}
```

`AttributeUpdater`实现了`AttributeModifier`接口，并额外提供了`initializeModifier`，可以对组件的属性进行初始化。通过`attribute`属性方法可以获取属性对象，直接更新对应组件的属性。另外也可以直接通过`updateConstructorParams`更新组件的构造参数。

## 使用说明

- 开发者可以继承`AttributeUpdater<T>`类，并通过组件的通用方法`attributeModifier`设置，首次绑定时会触发`initializeModifier`方法，进行属性的初始化，后续其它的生命周期和`AttributeModifier`保持一致。
- 组件初始化完成之后，开发者可以通过`AttributeUpdater`实例的`attribute`属性方法，获取到属性对象，若获取不到则为undefined。
- 通过`attribute`属性对象直接修改属性，会将最新设置的属性记录在当前对象中，并立即触发组件属性的更新。
- 如果将`AttributeUpdater`实例标记为状态变量进行修改，或者通过其它状态变量更新对应组件的属性，会触发`applyNormalAttribute`的流程，如果开发者没有复写该逻辑，默认会将属性对象记录的所有属性，进行一次批量更新。
- 如果开发者复写`applyNormalAttribute`的逻辑，并且不调用super的该方法，将会失去获取`attribute`属性对象的能力，不会调用`initializeModifier`方法。
- 一个`AttributeUpdater`对象只能同时关联一个组件，否则只会有一个组件的属性设置生效。

## 通过modifier直接修改属性

组件初始化完成之后，开发者可以通过`AttributeUpdater`实例的`attribute`属性方法，获取到属性对象。通过属性对象直接修改属性，会立即触发组件属性的更新。

```ts
import { AttributeUpdater } from '@kit.ArkUI';

class MyButtonModifier extends AttributeUpdater<ButtonAttribute> {
  // 首次绑定时触发initializeModifier方法，进行属性初始化
  initializeModifier(instance: ButtonAttribute): void {
    instance.backgroundColor('#2787D9')
      .width('50%')
      .height(30)
  }
}

@Entry
@Component
struct updaterDemo {
  modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Button("Button")
          .attributeModifier(this.modifier)
          .onClick(() => {
            // 通过attribute，直接修改组件属性，并立即触发组件属性更新
            this.modifier.attribute?.backgroundColor('#17A98D').width('30%')
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![AttributeUpdater](figures/AttributeUpdater.gif)


## 通过modifier更新组件的构造参数

可以通过`AttributeUpdater`实例的`updateConstructorParams`方法，直接更新组件的构造参数。

```ts
import { AttributeUpdater } from '@kit.ArkUI';

class MyTextModifier extends AttributeUpdater<TextAttribute, TextInterface> {
  initializeModifier(instance: TextAttribute): void {
  }
}

@Entry
@Component
struct updaterDemo {
  modifier: MyTextModifier = new MyTextModifier()

  build() {
    Row() {
      Column() {
        Text("Text")
          .attributeModifier(this.modifier)
          .fontColor(Color.White)
          .fontSize(14)
          .border({ width: 1 })
          .textAlign(TextAlign.Center)
          .lineHeight(20)
          .width(200)
          .height(50)
          .backgroundColor('#2787D9')
          .onClick(() => {
            // 调用updateConstructorParams方法，直接更新组件的构造参数
            this.modifier.updateConstructorParams('Update');
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![AttributeUpdater](figures/AttributeUpdater2.gif)