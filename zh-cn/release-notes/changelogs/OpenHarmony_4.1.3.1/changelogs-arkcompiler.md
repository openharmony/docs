# ArkCompiler子系统Changelog

## cl.ArkCompiler.1 TS语法检查变更

**访问级别**  
其它

**变更原因**  
OpenHarmony SDK中TypeScript版本从4.2.3升级至4.9.5版本，支持TS语言的新语法特性以及提供更强的类型检查能力，但存在少数与之前版本不兼容的语法特性。

**变更发生版本**  
OpenHarmony SDK 4.1.3.1

**变更影响**  
TypeScript版本升级之后，TS类语法检查更加严格，有10类与现有语法不兼容的语法特性，下面进行具体介绍并给出简单的示例

**变更语法特性与适配指导**

1. 不能将联合枚举类型的值与恒不等于的数字进行比较  
联合枚举类型：枚举的成员自动填充或简单写入，则视为联合枚举类型，这种情况下可以调用枚举可能表示的每个值  
下面为错误示例：

    ```
    enum E {
      A = 0,
      B = 1,
    }
    function doSomething(x: E) {
      // Error! This condition will always return 'false' since the types 'E' and '-1' have no overlap.
      if (x === -1) {
        // ...
      }
    }
    ```
    适配建议：通过toString()方法将数字转换为字符串进行比较

2. 对导入函数的更合规的间接调用  
   非esmodule(如FA模型下为commonjs模块)模块import场景下会丢弃this值，与esmodule模块的import行为一致  
   下面示例为调用行为的变化：
   ```
    // 假设这是我们导入的模块，它有一个'foo'以及'feature'的导出
    let fooModule = {
      foo() {
        console.log(this);
      },
      feature: 'oh'
    };

    // 以前的调用方式如下：
    fooModule.foo();  // 输出结果： { "feature": "oh" } 
  
    // 现在的调用方式如下(实际上是在调用 '(0, fooModule.foo), 与上面有细微的不同)：
    (0, fooModule.foo)();  // 输出结果： undefined
   ```
3. 抽象属性不允许初始化  
抽象属性不允许初始化，以下代码现在是错误的
    ```
    abstract class C {
      abstract prop = 1;
      //       ~~~~
      // Property 'prop' cannot have an initializer because it is marked abstract.
    }
    ```
    适配建议：删除初始化值
4. Rest参数语法会删除来自泛型对象中不可展开的成员  
从泛型对象中解构属性时，以前会假定所有属性都是可解构的，现在会严格分析属性是否可以被解构。不应该被解构的属性如：私有属性、私有方法、静态属性等。 下面为报错示例：
    ```
    class Thing {
      someProperty = 42;
      someMethod() {
        // ...
      }
    }
    function foo<T extends Thing>(x: T) {
      let { someProperty, ...rest } = x;
      // Used to work, is now an error!
      // Property 'someMethod' does not exist on type 'Omit<T, "someProperty" | "someMethod">'.
      rest.someMethod();
    }
    ```
    适配建议：从泛型对象中解构属性时，确保属性属于可结构类型
5. 对模板字符串表达式进行更严格的检查  
当在模板字符串中使用Symbol时，在JavaScript会报运行时错误，现在TS文件中，TS语法检查会报错，与之同时也会检查模板字符串中是否使用了某种方式来约束符号的泛型值。  
    ```
    function logKey<S extends string | symbol>(key: S): S {
        // Implicit conversion of a 'symbol' to a 'string' will fail at runtime. Consider wrapping this expression in 'String(...)'.
        console.log(`${key} is the key`);
        return key;
    }
    ```
    适配建议：通过String包装表达式
6. Tuple元组有readonly属性时长度属性视为只读  
    只读Tuple元组现在将其长度属性（length）视为只读。
    ```
    function overwriteLength(tuple: readonly [string, string, string]) {
        // Now errors.
        tuple.length = 7;
    }
    ```
7. 对象与Array Literal不允许比较  
JavaScript中对象（以及数组）之间的'==' 和 '===' 检查两个引用是否指向相同的值，现在会禁止下面的代码：
    ```
    if (peopleAtHome === []) {
    //  ~~~~~~~~~~~~~~~~~~~
    // This condition will always return 'false' since JavaScript compares objects by reference, not value.
        console.log("here's where I lie, broken inside. </3")
        adoptAnimals();
    }
    ```
8. 不允许在类型签名中写未使用的重命名  
在TS文件中，开发者一般会认为下面示例中makePerson的入参是一个对象，其有name和age两个属性，string与number为两个属性的类型。然而此对象实际是一个析构语法，string与number是name与age的重命名。
    ```
    declare function makePerson({ name: string, age: number }): Person;
    ```
    正确的写法如下：  
    ```
    declare function makePerson(options: { name: string, age: number }): Person;
    // or
    declare function makePerson({ name, age }: { name: string, age: number }): Person;
    ```    
9. 检查NaN相等  
现在直接与NaN进行比较时会出错
    ```
    function validate(someValue: number) {
        return someValue !== NaN;
        //     ~~~~~~~~~~~~~~~~~
        // error: This condition will always return 'true'. Did you mean '!Number.isNaN(someValue)'?
    }
    ```
    适配建议：建议使用Number.isNaN来代替
10. 类型推导与检查能力增强引发的报错  
TypeScript升级至4.9.5版本，其类型推导与检查能力增强，可能会检查出除上文介绍之外的语法错误。语法错误修正以后是有益处的，可提前发现运行时错误并帮助提高运行时性能。
