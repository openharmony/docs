# ArkCompiler子系统变更说明

## cl.arkcompiler.1 TS编译的目标EcmaScript版本由ES2017切换至ES2021

**访问级别**

其他

**变更原因**

OpenHarmony SDK中TypeScript Compiler的target选项配置由ES2017切换至ES2021。

**变更影响**

对于极少数使用了部分ES2018-ES2021语法特性，但存在语法错误并添加`@ts-nocheck`或`@ts-ignore`注释的场景：

变更前，可以通过注释屏蔽语法错误，编译通过；

变更后，由于对这部分语法的检查校验增强，可能存在不兼容编译报错。


**起始 API Level**

9

**变更发生版本**

OpenHarmony SDK 5.0.0.19

**变更的接口/组件**

不涉及

**适配指导**

推荐删除`@ts-nocheck`和`@ts-ignore`注释，根据编译报错提示进行适配，例如：

1. ES2018特性：Rest属性
    ```
    // @ts-ignore
    const {a, ...remaning, b} = {a: 1, b: 2, c: 3, d: 4};
    //           ~~~~~~~~
    // 被注释屏蔽的报错：A rest element must be last in a destructuring pattern.
    ```
    适配建议：删除`@ts-ignore`注释，将rest属性放在最后。
    ```
    const {a, b, ...remaning} = {a: 1, b: 2, c: 3, d: 4};
    ```

2. ES2020特性：可选链式调用
    ```
    const object = { property: "hi" };
    // @ts-ignore
    object?.property = "hello";
    // ~~~~~~~~~~~~~ 
    // 被屏蔽的报错：The left-hand side of an assignment expression may not be an optional property access.
    ```
    适配建议：删除`@ts-ignore`注释，先对`object`进行判空，再进行赋值操作。
    ```
    const object = { property: "hi" };
    if (object !== undefined) {
        object.property = "hello";
    }
    ```

3. ES2020特性：空值合并操作符
    ```
    // @ts-nocheck
    let a = null || undefined ?? "foo";
    //      ~~~~~~~~~~~~~~~~~
    // 被屏蔽的报错：'||' and '??' operations cannot be mixed without parentheses.
    let b = true && undefined ?? "foo";
    //      ~~~~~~~~~~~~~~~~~
    // 被屏蔽的报错：'&&' and '??' operations cannot be mixed without parentheses.
    ```
    适配建议：删除`@ts-nocheck`注释，加上括号以确保运算顺序符合预期。
    ```
    let a = (null || undefined) ?? "foo";
    let b = (true && undefined) ?? "foo";
    ```
其他可能不兼容的场景同理，删除`@ts-nocheck`和`@ts-ignore`注释后根据编译报错提示修复即可。

开发者也可在工程级别的build-profile.json5文件中配置targetESVersion为ES2017，来保持与变更前一致。