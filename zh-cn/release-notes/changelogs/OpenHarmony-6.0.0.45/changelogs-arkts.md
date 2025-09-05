# ArkTS方舟编程语言Changelog

## cl.arkcompiler.1 hot reload不再支持修改箭头函数内this变量的首次新增或彻底删除

升级到DevEco Stidio 6.0.0 Beta3及以上版本，在hot reload模式下对箭头函数内this变量的首次新增或彻底删除会报错。

**变更影响**

hot reload不再支持修改箭头函数内this变量的首次新增或彻底删除。
如用户编写如下代码：

```
// test.ets
class Foo {
  str: string = "this is string"
  test() {
    let a = () => {
      console.log(this.str)
    }
    a()
  }
}
let foo = new Foo()
```
使用hot reload模式进行调试。调试时，修改代码为：
```
class Foo {
  str: string = "this is string"
  test() {
    let a = () => {
      console.log("this is change")
    }
    a()
  }
}
let foo = new Foo()
```
进行hot reload则会报错，报错内容如下：
```
compile error: 10706001 Unsupported Change in Hot Reload
compile error: Error Message: Found lexical variable added or removed in 'xxxxx', not supported!
compile error: [Patch] Found unspported change in file, will not generate patch!
```

**适配指导**

若需要在hot reload时对箭头函数内this变量进行首次新增或彻底删除，则需要重新编译并调试。