# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 ArkTS Linter Rules Changed

**Access Level**

other

**Change Reason**

For the convenience of developers, these two rules arkts-no-generic-lambdas and arkts-no-import-default-as need to be deleted in the ArkTS language.

**Change Impact**

This change is a compatibility change, which is a relaxation of these rules and does not introduce compatibility problems.

**API Level**

10

**Changed Since**

Start with OpenHarmony SDK version 5.0.0.25.

**Changed Interface or Component**

Before the change, Linter will report errors about these two rules; After the change, Linter will not report errors about these two rules.

- (Deleted) Rule 1: Use Generic Functions Instead of Generic Arrow Functions

    Rule: `arkts-no-generic-lambdas`

    Severity: error

    Rule Description：ArkTS does not support generic arrow functions. Use normal generic functions instead.

    TypeScript grammar：

    ```typescript
    let generic_arrow_func = <T extends String> (x: T) => { return x }

    generic_arrow_func('string')
    ```

    ArkTS grammar：

    ```typescript
    function generic_func<T extends String>(x: T): T {
    return x
    }

    generic_func<String>('string')
    ```

- (Deleted) Rule 2: `import default as ...` Is Not Supported

    Rule: `arkts-no-import-default-as`

    Severity: error

    Rule Description：ArkTS does not support the `import default as ...` syntax. Use explicit `import ... from ...` instead.

    TypeScript grammar：

    ```typescript
    import { default as d } from 'mod'
    ```

    ArkTS grammar：

    ```typescript
    import d from 'mod'
    ```

**Adaptation Guide**

If the ArkTS Linter rule is deleted, the original Linter error reporting behavior will be changed to no error reporting, and no adaptation is required.