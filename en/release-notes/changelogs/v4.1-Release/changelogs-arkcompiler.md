# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 ArkTS Syntax Rule Change

Since OpenHarmony SDK 4.1.5.5, the ArkTS syntax rules are changed as follows.

**Removed**

**arkts-no-decorators-except-arkui**, **arkts-no-side-effects-imports**, **arkts-no-regexp-literals**

**Downgraded**

The severity level of **rules arkts-no-globalthis** and **arkts-no-classes-as-obj** is lowered to warning, which means that they do not block project compilation.

Rule **arkts-no-func-apply-bind-call** is split into the following two rules:
1. **arkts-no-func-apply-call**, at error level
2. **arkts-no-func-bind**, at level warning

Compared with that in the earlier version, the quantity of highlighted code and total number of errors remain unchanged.

**Relaxed**

Rule **arkts-identifiers-as-prop-names** is relaxed. Attribute names can be string literals or string type enumeration constants.

No error is reported in the following code:

```
enum Test {
  A = 'aaa',
  B = 'bbb'
}

let obj: Record<string, number> = {
  [Test.A]: 1,   // String type enumeration constants
  [Test.B]: 2,   // String type enumeration constants
  ['value']: 3   // String literal
}
```

**Change Impact**

There is no compatibility impact. No code adaptation is required.

## cl.ArkCompiler.2 TS Check Change for Third-party Packages

**Access Level**

Other

**Reason for Change**

Code in third-party packages in the **oh_modules** directory must comply with the TS syntax specifications. In versions earlier than 4.0.10.3, an error is reported for any noncompliance. However, due to code implementation, no error is reported for such noncompliance since 4.0.10.3. This change is made to rectify the issue.

**Change Since**

OpenHarmony SDK 4.1.5.5

**Change Impact**

If code that does not comply with TS syntax specifications is contained in a third-party package, an error is reported during compilation.

For example, if a third-party package contains the following code:
```
let a: string = 1;
```

The following error is reported during compilation:

```
Type 'number' is not assignable to type 'string'.
```

**Adaptation Guide**

Make sure all code in the third-party package complies with the TS syntax specifications.

## cl.arkcompiler.3 Change in ArkCompiler Internal Implementation

Changed the internal implementation of ArkCompiler.

**Change Since**

OpenHarmony_4.1.6.1

**Reason for Change**

To implement the ECMAScript 2022 class and sendable class features, new bytecodes are required.

**Change Description**

The following bytecodes are added to the class feature:
1. `definefieldbyname`
2. `callruntime.definefieldbyvalue`
3. `callruntime.definefieldbyindex`
4. `callruntime.defineprivateproperty`
5. `callruntime.callinit`
6. `callruntime.createprivateproperty`
7. `callruntime.topropertykey`
8. `ldprivateproperty`
9. `stprivateproperty`
10. `testin`

The following bytecodes are added to the sendable class:
1. `callruntime.definesendableclass`
2. `callruntime.ldsendableclass`

**Change Impact**

The new bytecodes added in SDK OpenHarmony_4.1.6.1 require support from ROM in the same version. Therefore, earlier ROM in API version 11 cannot run the HAPs built by SDK OpenHarmony_4.1.6.1.

If you are using SDK OpenHarmony_4.1.6.1 and ROM in API version 10, you can set the **compatiableSdkVersion: 10** option from DevEco Studio to build a HAP that can run on the ROM.

**Symptom**

If the SDK and ROM do not match, the following errors may occur:

1. jsCrash: `Load file with filename '/data/storage/el1/bundle/entry/ets/module.abc' failed, recordName 'com.example.myapplication/entry/ets/entryability/EntryAbility' not exists` along with hilog: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 9.0.0.0. Please upgrade the runtime to supported version or generate byte code with former SDK tools`

2. cppCrash: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 11.0.1.0. Please upgrade the system image or use former version of SDK tools to generate abc files`

**Solution**

Update the ROM to OpenHarmony_4.1.6.1 or later.

## cl.arkcompiler.4 Change in ArkCompiler AOT Enabling Mode
**First Applicable Version**

OpenHarmony_4.1.6.2

**Reason for Change**

The change is made to enable the use of AOT in the user version.

**Change Impact**

This change is a compatible change.

- Before change: AOT is only available for ROM images of the root version.
- After change: AOT is also available for ROM images of the user version.

**API Level**

N/A

**Change Since**

OpenHarmony_4.1.6.2

**Key API/Component Changes**

ArkCompiler AOT enabling mode

**Adaptation Guide**

For details, see [AOT Guide](https://gitee.com/openharmony/arkcompiler_ets_runtime/blob/master/docs/aot-guide_zh.md).

## cl.arkcompiler.5 Enforcing Checks on Value Assignment of Sendable Classes in Hotspot Functions

**Reason for Change**

The change is intended to fix the issue where some restrictions on sendable classes in hotspot functions are bypassed.

**Change Impact**

This change is a non-compatible change.

- Sendable data is used to improve performance in cross-thread data transfer. For details, see [\@Sendable Decorator: Declaring and Verifying a Sendable Class](../../../application-dev/arkts-utils/arkts-sendable.md).
- After the change, restrictions on sendable classes cannot be bypassed.
- The following table lists the involved constraints.

    | \@Sendable Decorator        | Description                                                                  |
    | ------------------------- | ---------------------------------------------------------------------- |
    | Property type restrictions for decorated objects | <b>The object type can be string, number, boolean, or SendableClass. <b>Closure variables are not allowed. Private properties must be defined using **private**, rather than the number sign (#). Computed properties are not supported.          |


- In terms of property type restriction violations:
    - Before change: The program can run properly, and no error is reported for such violations.
    - After change: An exception is thrown at the point where the constraint is violated. In this case, you need to adapt your code based on the property type restrictions described in [\@Sendable Decorator: Declaring and Verifying a Sendable Class](../../../application-dev/arkts-utils/arkts-sendable.md).

**API Level**

API version 11

**Change Since**

OpenHarmony_4.1.6.5

**Key API/Component Changes**

@Sendable decorator

**Adaptation Guide**

If a type mismatch exception occurs during running, the restrictions involved in this change may have been violated. Verify the assigned value type. For details, see [\@Sendable Decorator: Declaring and Verifying a Sendable Class](../../../application-dev/arkts-utils/arkts-sendable.md).

## cl.arkcompiler.6 Removal of ark_asm from SDK

**Access Level**

Other

**Reason for Change**

The ark_asm tool was originally designed to compile and generate abc files with ts2abc. However, with the evolution of technology, on the one hand, this solution has been replaced by other solutions due to efficiency reasons; on the other hand, ts2abc has also been replaced and offline by es2abc, so the ark_asm tool has not been involved in the application compilation or development process. After the ark_asm tool is offline, developers can find the changes as shown in the figure below in the toolchains directory of the sdk.

![stack](figures/api11_sdk_toolchains_component_change.png)

**Change Impact**

This change is a compatible change. Since ark_asm does not participate in the application compilation or development process, upgrading this version of the SDK will not have any impact on developers.

**API Level**

11

**Change Since**

Openharmony SDK 4.1.5.5

**Change API/Component**

ark_asm tool

**Adaptation Guide**

No adaptation is required.