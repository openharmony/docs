# Account Subsystem Changelog

## cl.account_os_account.1 Change of .onAcquireInfo Parameters

**Access Level**

System API

**Reason for Change**

The ArkTS syntax does not support the any type.

**Change Impact**

This change is a non-compatible change. Compilation problems may occur if you do not use the new API.

**API Level**

8

**Change Since**

OpenHarmony SDK OpenHarmony_4.1.6.2

**Key API/Component Changes**

Before the change:

```js
    interface IUserAuthCallback  {
        ...
        onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;
        ...
    }

    interface IIdmCallback   {
        ...
        onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;
        ...
    }
```

After the change:

```js
    interface IUserAuthCallback  {
        ...
        onAcquireInfo?: (module: number, acquire: number, extraInfo: Uint8Array) => void;
        ...
    }

    interface IIdmCallback   {
        ...
        onAcquireInfo?: (module: number, acquire: number, extraInfo: Uint8Array) => void;
        ...
    }
```

**Adaptation Guide**

Define the **onAcquireInfo** callback based on the new interface prototype.
