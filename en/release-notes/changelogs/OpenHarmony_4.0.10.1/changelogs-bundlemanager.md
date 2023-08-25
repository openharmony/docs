# Bundle Management Subsystem Changelog
## cl.bundlemanager.1 APP_ACCOUNT_AUTHORIZATION Deleted from ExtensionAbilityType

**APP_ACCOUNT_AUTHORIZATION** is deleted from this version.

You need to adapt your application.

**Change Impact**

The API can no longer be used after being deleted.

- Involved API:

```js
  export enum ExtensionAbilityType
```

- Before change:

```js
  export enum ExtensionAbilityType {
    FORM = 0,
    WORK_SCHEDULER = 1,
    INPUT_METHOD = 2,
    SERVICE = 3,
    ACCESSIBILITY = 4,
    DATA_SHARE = 5,
    FILE_SHARE = 6,
    STATIC_SUBSCRIBER = 7,
    WALLPAPER = 8,
    BACKUP = 9,
    WINDOW = 10,
    ENTERPRISE_ADMIN = 11,
    THUMBNAIL = 13,
    PREVIEW = 14,
    PRINT = 15,
    PUSH = 17,
    DRIVER = 18,
    APP_ACCOUNT_AUTHORIZATION = 19,
    UNSPECIFIED = 255
  }
```

- After change:
```js
  export enum ExtensionAbilityType {
    FORM = 0,
    WORK_SCHEDULER = 1,
    INPUT_METHOD = 2,
    SERVICE = 3,
    ACCESSIBILITY = 4,
    DATA_SHARE = 5,
    FILE_SHARE = 6,
    STATIC_SUBSCRIBER = 7,
    WALLPAPER = 8,
    BACKUP = 9,
    WINDOW = 10,
    ENTERPRISE_ADMIN = 11,
    THUMBNAIL = 13,
    PREVIEW = 14,
    PRINT = 15,
    PUSH = 17,
    DRIVER = 18,
    UNSPECIFIED = 255
  }
```
The definition of **APP_ACCOUNT_AUTHORIZATION** is deleted.


**Adaptation Guide**

Update the code so that the deprecated API is not used.
