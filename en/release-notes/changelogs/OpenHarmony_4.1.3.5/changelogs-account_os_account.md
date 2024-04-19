# Account Subsystem Changelog

## cl.account_os_account.1 Deprecation of Some osAccount APIs

**Access Level**

Public APIs

**Reason for Change**

The APIs can be called only by system applications.

**Change Impact**

This change has no impact on system applications. For third-party applications, error code 202 will be thrown if the deprecated APIs are called in OpenHarmony_4.1.3.5 or later; error code 201 will be thrown if the deprecated APIs are called in an earlier version.

**API Level**

9

**Change Since**

OpenHarmony SDK OpenHarmony_4.1.3.5

**Deprecated APIs/Components**

Involved APIs:

interface/sdk-js/api/@ohos.account.osAccount.d.ts:

```js
    checkOsAccountActivated(localId: number, callback: AsyncCallback<boolean>): void;
    checkOsAccountActivated(localId: number): Promise<boolean>;

    checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
    checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise<boolean>;

    checkOsAccountVerified(localId: number, callback: AsyncCallback<boolean>): void;
    checkOsAccountVerified(localId: number): Promise<boolean>;

    getOsAccountConstraints(localId: number, callback: AsyncCallback<Array<string>>): void;
    getOsAccountConstraints(localId: number): Promise<Array<string>>;

    getCurrentOsAccount(callback: AsyncCallback<OsAccountInfo>): void;
    getCurrentOsAccount(): Promise<OsAccountInfo>;
```

After the change:

All the above APIs are deprecated, without substitute APIs.

**Adaptation Guide**

No adaptation is required for system applications. If a third-party application calls the deprecated APIs, error code 202 and related processing logic need to be provided.


## cl.account_os_account.2 Deprecation of Some osAccount APIs

**Access Level**

Public APIs

**Reason for Change**

- The APIs have spelling errors.

- Similar APIs are defined in different formats.

**Change Impact**

The deprecated APIs will not be maintained after five versions. Use substitute APIs.

**API Level**

checkOsAccountVerified (9)

isVerified (8)

isActived (8)

**Change Since**

OpenHarmony SDK OpenHarmony_4.1.3.5

**Deprecated APIs/Components**

Deprecated APIs:

interface/sdk-js/api/@ohos.account.osAccount.d.ts:

```js
    checkOsAccountVerified(callback: AsyncCallback<boolean>): void;
    checkOsAccountVerified(): Promise<boolean>;
```
Substitute API:
```js
    isOsAccountUnlocked(): Promise<boolean>;
```

Deprecated APIs:
```js
    interface OsAccountInfo {
        ...
        isVerified: boolean;
        isActived: boolean;
        ...
    }
```
Substitute APIs:
```js
    interface OsAccountInfo {
        ...
        isUnlocked: boolean;
        isActivated: boolean;
        ...
    }
```

**Adaptation Guide**

Since API version 11, use the substitute APIs.
