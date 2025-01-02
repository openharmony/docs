# ArkCompiler子系统变更说明

## cl.ArkCompiler.1 ArkTS Linter规则变更

**访问级别**

其他

**变更原因**

基于开发者易用性考虑，ArkTS语言删除了arkts-no-generic-lambdas和arkts-no-import-default-as两条Linter规则。

**变更影响**

该变更为兼容性变更，属于规则的放宽，不会引入兼容性问题。

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.25版本开始。

**变更的接口/组件**

变更前，下面的两条规则会出现Linter报错；变更后，不会出现下面两条规则的Linter报错。

- （已删除）规则一：使用泛型函数而非泛型箭头函数

    规则：`arkts-no-generic-lambdas`

    级别：错误

    规则说明：ArkTS不支持泛型箭头函数。

    TypeScript语法：

    ```typescript
    let generic_arrow_func = <T extends String> (x: T) => { return x; };

    generic_arrow_func('string');
    ```

    ArkTS语法：

    ```typescript
    function generic_func<T extends String>(x: T): T {
    return x;
    }

    generic_func<String>('string');
    ```

- （已删除）规则二：不支持`import default as ...`

    规则：`arkts-no-import-default-as`

    级别：错误

    规则说明：ArkTS不支持`import default as ...`语法，使用显式的`import ... from ...`语法。

    TypeScript语法：

    ```typescript
    import { default as d } from 'mod'
    ```

    ArkTS语法：

    ```typescript
    import d from 'mod'
    ```

**适配指导**

属于ArkTS Linter规则删除，原有的Linter报错行为会改成不报错，不需要重新适配。
