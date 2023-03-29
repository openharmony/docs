# 3.1 release相对于3.1 beta变更详细说明

### 针对color.json中颜色值，增加合法性校验

针对color.json中颜色值，增加合法性校验，其校验规则如下：

- 使用十六进制颜色码，格式如下：
    - #rgb：red(0-f) green(0-f) blue(0-f)
    - #argb：transparency(0-f) red(0-f) green(0-f) blue(0-f)
    - #rrggbb： red(00-ff) green(00-ff) blue(00-ff)
    - #aarrggbb： transparency(00-ff) red(00-ff) green(00-ff) blue(00-ff)
- 使用$引用应用中已定义的资源，格式如下：
    - $color:xxx

**变更影响**

不符合上述校验规则，将在编译时报错。

**关键的接口/组件变更**

无

### 状态变量多种数据类型声明使用限制。

状态变量比如@State、@Provide、 @Link和@Consume等，定义数据类型时，只能同时由简单数据类型或对象引用数据类型其中一种构成。

示例：

```ts
@Entry
@Component
struct Index {
  //错误写法: @State message: string | Resource = 'Hello World'
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(`${ this.message }`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**变更影响**

当定义的状态变量类型中同时包含简单类型和对象引用数据类型时，编译报错提示不支持。

**关键的接口/组件变更**

当定义的状态变量类型中同时包含简单类型和对象引用数据类型时，需修改为只含有其中一种，如上述示例代码所示。