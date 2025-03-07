# Attribute Updater (AttributeUpdater)

## Overview

When dealing with frequent updates to a large number of attributes, using state variables can lead to significant computational overhead in frontend state management. This is because it requires full updates of all attributes for individual components. Although the [AttributeModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md) mechanism allows for selective updates based on specific needs, the frontend still applies some default strategies for differentiation (diffing) and resetting attributes.

This is where **AttributeUpdater** comes into the picture. As a special type of **AttributeModifier**, **AttributeUpdater** not only inherits all the functionality of **AttributeModifier** but also extends its capabilities by allowing access to the attribute object. By using the attribute object, you can update specific attributes without relying on state variables. With **AttributeUpdater**, you can implement custom update strategies, further improving the performance of attribute updates.

This flexibility, however, comes with a trade-off: It does not enforce the "single source of truth" rule, which means that there is a risk of conflicts when the same attributes are updated through both **AttributeUpdater** and state variables. To avoid such conflicts, you need to ensure that attribute settings are applied logically and consistently.

## API Definition

```ts
export declare class AttributeUpdater<T, C = Initializer<T>> implements AttributeModifier<T> {

  applyNormalAttribute?(instance: T): void;

  initializeModifier(instance: T): void;

  get attribute(): T | undefined;

  updateConstructorParams: C;
}
```

**AttributeUpdater** enhances the **AttributeModifier** API by offering additional features. It provides **initializeModifier** for initializing a component's attributes, **attribute** for obtaining the attribute object (which enables direct updates to the component's attributes), and **updateConstructorParams** for directly updating the component's constructor parameters.

## How to Use

- You can extend the **AttributeUpdater\<T>** class and set it up through the universal method **AttributeModifier** of the component. When the binding is first established, the **initializeModifier** API is triggered to initialize attributes. This is followed by a series of lifecycle events that are consistent with those of **AttributeModifier**.
- After the component is initialized, you can obtain the attribute object through the **attribute** method of the **AttributeUpdater** instance. If the component is not initialized, the method will return **undefined**.
- Modifying attributes through **attribute** will store the latest settings within the current object and immediately trigger an update of the component's attributes.
- Designating an **AttributeUpdater** instance as a mutable state variable, or updating the attributes of the corresponding component through other state variables, will trigger **applyNormalAttribute**. If you do not override this logic, by default, all attributes obtained by the **attribute** object will be updated in batch.
- If you override the **applyNormalAttribute** API without calling **super**, you will not be able to obtain the attribute object, and the **initializeModifier** method will not be executed.
- A single **AttributeUpdater** object can be associated with only one component. If it is associated with multiple components, attribute settings will be applied to only one of these components.

## Directly Modifying Attributes Through Modifier

After a component is initialized, you can use the **attribute** method of the **AttributeUpdater** instance to obtain the attribute object. Modifying attributes directly through this object will immediately trigger an update to the component's attributes.

```ts
import { AttributeUpdater } from '@ohos.arkui.modifier'

class MyButtonModifier extends AttributeUpdater<ButtonAttribute> {
  // The initializeModifier method is triggered upon the first binding, initializing the attributes.
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
            // Directly modify the component's attributes through attribute, which will trigger an immediate update.
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


## Updating Component Constructor Parameters Through Modifier

You can directly update the constructor parameters of a component using the **updateConstructorParams** method of an **AttributeUpdater** instance.

```ts
import { AttributeUpdater } from '@ohos.arkui.modifier'

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
            // Call the updateConstructorParams method to directly update the component's constructor parameters.
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
