# arkui子系统ChangeLog

## cl.arkui.1 状态变量数据类型声明使用限制。

所有的状态装饰器变量需要显式声明变量类型，不允许声明any。

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct DatePickerExample {
  // 错误写法: @State isLunar: any = false
  @State isLunar: boolean = false

  build() {
   ...
  }
}
```

**变更影响**

如果状态装饰器变量没有显式声明变量类型，声明any，编译拦截报错。

```ts
// ArkTS:ERROR Please define an explicit type, not any.
@State isLunar: any = false
```

**关键的接口/组件变更**

不涉及。

**适配指导**

状态装饰器变量声明具体的变量类型替代any。

## cl.arkui.2 自定义组件成员变量初始化的规则与约束。

不允许从父组件初始化`@LocalStorageLink`, `@LocalStorageProp`修饰的变量。

**示例：**

```ts
@Entry
@Component
struct LocalStorageComponent {
    build() {
        Column() {
            Child({
              /* ArkTS:ERROR Property 'simpleVarName' in the custom component 'Child' cannot
                initialize here (forbidden to specify). */
              simpleVarName: 1,
              /* ArkTS:ERROR Property 'objectName' in the custom component 'Child' cannot
                initialize here (forbidden to specify). */
              objectName: new ClassA("x")
            })
        }
    }
}
@Component
struct Child {
    @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0;
    @LocalStorageProp("storageObjectProp") objectName: ClassA = new ClassA("x");
    build() {}
}
```

**关键的接口/组件变更**

不涉及。

**适配指导**

构造子组件时，不对子组件的`@LocalStorageLink`, `@LocalStorageProp`修饰的变量进行赋值。

如果需要在父组件中修改子组件的`@LocalStorageLink`, `@LocalStorageProp`修饰的变量，则使用LocalStorage提供的API接口方法(比如set方法)赋值。