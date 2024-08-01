# ArkUI子系统Changelog

## cl.arkui.1 使用局部@Builder方法引用传参时，使用bind(this)后，状态管理的父子关系和组件的父子关系不一致，比如使用@ohos.arkui.advanced.ChipGroup高级组件崩溃解决方法

**访问级别**

公开接口

**变更原因**

开发者使用局部@Builder方法引用传参时，使用bind(this)后，在使用 @Provide和@Consume时状态管理的父子关系和组件的父子关系不一致。运行时报错：

```
@Component 'MyComponent2'[11] missing @Provide property with name value.Fail to resolve @Consume(value).
```

**变更影响**

该变更为不兼容性变更。开发者使用局部@Builder方法引用传参时，使用bind(this)后，状态管理的父子关系和组件的父子关系不一致，涉及高级组件[@ohos.arkui.advanced.ChipGroup (操作块组组件)](../../../application-dev/reference/apis-arkui/arkui-ts/ohos-arkui-advanced-ChipGroup.md)在内的使用局部@Builder且使用@Builder函数处使用bind(this)的一些自定义组件。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.34开始。

**变更的接口/组件**

[@ohos.arkui.advanced.ChipGroup (操作块组组件)](../../../application-dev/reference/apis-arkui/arkui-ts/ohos-arkui-advanced-ChipGroup.md)

**适配指导**

将原来的局部@Builder变成@LocalBuilder。

变更前： 

```ts
@Component
struct MyComponent {
  @Provide("value") value: number = 10;
  @BuilderParam content: () => void;

  build() {
    Column() {
      this.content();
    }
  }
}

@Component
struct MyComponent2 {
  @Consume("value") value: number;

  build() {
    Text(`${this.value}`)
  }
}

@Entry
@Component
struct Index {
  @State stateValue: string = '';

  @Builder
  content() {
    MyComponent2()
  }

  build() {
    Column() {
      MyComponent({
        content: this.content.bind(this)
      })
    }
  }
}
```

变更后：

```   ts
@Component
struct MyComponent {
  @Provide("value") value: number = 10;
  @BuilderParam content: () => void;

  build() {
    Column() {
      this.content();
    }
  }
}

@Component
struct MyComponent2 {
  @Consume("value") value: number;

  build() {
    Text(`${this.value}`)
  }
}

@Entry
@Component
struct Index {
  @State stateValue: string = '';
// 将 @Builder 改成@LocalBuilder
  @LocalBuilder
  content() {
    MyComponent2()
  }

  build() {
    Column() {
      // 去掉bind(this)
      MyComponent({
        content: this.content
      })
    }
  }
}
```

## cl.arkui.3  半模态挡位内容经过开发者动态改变后，挡位索引默认为0

**访问级别**

公开接口

**变更原因**

为解决半模态拖动到悬浮窗时半模态需保持拖拽后的挡位，引入该体验问题，需要修复引入的问题。

**变更影响**

该变更为不兼容变更。

变更前：半模态经过手指拖拽并且在开发者动态改变挡位后，因挡位索引保持为手指拖拽的索引，半模态刷新成新挡位数组对应索引的高度。

变更后：半模态挡位内容在开发者动态改变后，挡位索引标记为0，半模态刷新成开发者设的新挡位数组第一位的高度。

| 变更前(点击Button) | 变更后(点击Button) |
|---------|---------|
| ![pre](sheetDetentsBefore.gif)| ![current](sheetDetentsAfter.gif)|

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.34开始。

**变更的接口/组件**

detents接口/BindSheet组件

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。