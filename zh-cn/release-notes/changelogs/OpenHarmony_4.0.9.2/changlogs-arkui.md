#  arkui子系统ChangeLog

## ArkUI系统组件使用限制

 ArkUI系统组件必须在struct的build方法，pageTransition方法，@Builder修饰的函数内使用。

**示例：**

```
@Entry
@Component
struct Index {
  build() {
    Row() {
    }

  }
}
// ERROR:UI component 'Text' cannot be used in this place.
Text('Hello World')
```

**变更影响**

 如果ArkUI系统组件不在struct的build方法，pageTransition方法，@Builder修饰的函数内使用，编译报错。

**关键的接口/组件变更**

不涉及。

**适配指导**

 ArkUI系统组件必须在struct的build方法，pageTransition方法，@Builder修饰的函数内使用。
