# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 ArkTS Linter Rules Changed

**Access Level**

Others

**Reason for Change**

For ease of use, the linter rules **arkts-no-generic-lambdas** and **arkts-no-import-default-as** are deleted from ArkTS.

**Change Impact**

This change is a compatibility change.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.25

**Key API/Component Changes**

Before the change, a linter error is reported for the following two rules. After the change, no linter error is reported for the two rules.

- (Deleted) Rule 1: Use Generic Functions Instead of Generic Arrow Functions

    Rule: arkts-no-generic-lambdas

    Severity: error

    Rule description: ArkTS does not support generic arrow functions.

    TypeScript syntax:

    ```typescript
    let generic_arrow_func = <T extends String> (x: T) => { return x; };

    generic_arrow_func('string');
    ```

    ArkTS syntax:

    ```typescript
    function generic_func<T extends String>(x: T): T {
    return x;
    }

    generic_func<String>('string');
    ```

- (Deleted) Rule 2: Import default as... Is Not Supported

    Rule: arkts-no-import-default-as

    Severity: error

    Rule description: ArkTS does not support the **import default as...** syntax. Use explicit **import... from...** instead.

    TypeScript syntax:

    ```typescript
    import { default as d } from 'mod'
    ```

    ArkTS syntax:

    ```typescript
    import d from 'mod'
    ```

**Adaptation Guide**

No adaptation is required.
