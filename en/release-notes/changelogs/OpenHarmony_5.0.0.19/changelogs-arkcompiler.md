# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 TS Compiler Targets ECMAScript 2021, Upgrading from ECMAScript 2017

**Access Level**

Other

**Reason for Change**

In the OpenHarmony SDK, the **target** option of the TypeScript compiler is changed from ES2017 to ES2021.

**Change Impact**

In rare scenarios where the code uses ES2018-ES2021 syntax features with syntax errors, which are masked using the @ts-nocheck or @ts-ignore comment:

Before the change, these syntax errors are masked using comments, and the compilation is successful.

After the change, the check rules for these syntaxes are enhanced, and a compilation error may be reported.


**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.19

**Key API/Component Changes**

N/A

**Adaptation Guide**

Delete the @ts-nocheck and @ts-ignore comments and perform adaptation based on the compilation error messages. Refer to the examples below.

1. ES2018 Feature: **rest** Property
    ```
    // @ts-ignore
    const {a, ...remaning, b} = {a: 1, b: 2, c: 3, d: 4};
    //           ~~~~~~~~
    // Masked error: A rest element must be last in a destructuring pattern.
    ```
    Suggestion: Delete the @ts-ignore comment and place the **rest** property at the end.
    ```
    const {a, b, ...remaning} = {a: 1, b: 2, c: 3, d: 4};
    ```

2. ES2020 Feature: Optional Chaining Operator
    ```
    const object = { property: "hi" };
    // @ts-ignore
    object?.property = "hello";
    // ~~~~~~~~~~~~~ 
    // Masked error: The left-hand side of an assignment expression may not be an optional property access.
    ```
    Suggestion: Delete the @ts-ignore comment, check whether the object is null, and then assign a value.
    ```
    const object = { property: "hi" };
    if (object !== undefined) {
        object.property = "hello";
    }
    ```

3. ES2020 Feature: Nullish Coalescing Operator
    ```
    // @ts-nocheck
    let a = null || undefined ?? "foo";
    //      ~~~~~~~~~~~~~~~~~
    // Masked error: '||' and '??' operations cannot be mixed without parentheses.
    let b = true && undefined ?? "foo";
    //      ~~~~~~~~~~~~~~~~~
    // Masked error: '&&' and '??' operations cannot be mixed without parentheses.
    ```
    Suggestion: Delete the @ts-nocheck comment and add parentheses to ensure that the operation sequence meets the expectation.
    ```
    let a = (null || undefined) ?? "foo";
    let b = (true && undefined) ?? "foo";
    ```
For other scenarios with incompatible changes, delete the @ts-nocheck and @ts-ignore comments and rectify the fault based on the compilation error messages.

You can also set **targetESVersion** to **ES2017** in the project-level **build-profile.json5** file to continue using ECMAScript 2017.
