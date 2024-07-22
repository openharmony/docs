# ArkUI子系统Changelog

## cl.arkui.1 MenuItem设置enable为false时字体颜色变更

**访问级别**

公开接口

**变更原因**

MenuItem设置enable为false时，无法自适应自定义字体颜色

**变更影响**

该变更为不兼容性变更。

变更前：MenuItem设置enable为false时，字体颜色为默认字体颜色 * 不透明度40%

变更后：MenuItem设置enable为false时，字体颜色为自定义字体颜色或默认字体颜色 * 不透明度40%

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.34开始。

**变更的接口/组件**

MenuIten组件。

**适配指导**

默认行为变更，无需适配。

## cl.arkui.2  使用局部@Builder方法引用传参时，使用bind(this)后，状态管理的父子关系和组件的父子关系不一致，比如使用@ohos.arkui.advanced.ChipGroup高级组件崩溃解决方法

**访问级别**

公开接口

**变更原因**

开发者使用局部@Builder方法引用传参时，使用bind(this)后，在使用 @Provide和@Consume时状态管理的父子关系和组件的父子关系不一致。运行时报错：

```
@Component 'MyComponent2'[11] missing @Provide property with name value.Fail to resolve @Consume(value).
```

**变更影响**

该变更为不兼容性变更。开发者使用局部@Builder方法引用传参时，使用bind(this)后，状态管理的父子关系和组件的父子关系不一致，目前排查出涉及高级组件[@ohos.arkui.advanced.ChipGroup (操作块组组件)](../../../application-dev/reference/apis-arkui/arkui-ts/ohos-arkui-advanced-ChipGroup.md)。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.34开始。

**变更的接口/组件**

无

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