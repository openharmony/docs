# 帐号子系统系统账号模块ChangeLog

## cl.account_os_account.1 废弃系统帐号信息的部分查询接口

**接口层级**

公开接口

**废弃原因**

接口权限仅对系统应用开放，三方应用无法申请。

**变更影响**

对系统应用无影响；对于三方应用，在旧版本上调用该接口会报201错误码，在新版本上会报202错误码；

**API Level**

9

**废弃发生版本**

从OpenHarmony SDK OpenHarmony_4.1.3.5开始。

**废弃接口/组件**

涉及接口：

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

变更后：

涉及接口全部废弃，不涉及替代接口。

**适配指导**

系统应用无需适配；三方应用在新版本上调用该接口需适配处理202错误码


## cl.account_os_account.2 废弃系统帐号信息的部分查询接口

**接口层级**

公开接口

**废弃原因**

1.拼写错误；

2.接口命名与公共事件命名不统一；

**废弃影响**

废弃接口在5个版本后不再维护，应用开发者需使用替代接口。

**API Level**

checkOsAccountVerified(9)

isVerified(8)

isActived(8)

**废弃发生版本**

从OpenHarmony SDK OpenHarmony_4.1.3.5开始。

**废弃接口/组件**

废弃前接口：

interface/sdk-js/api/@ohos.account.osAccount.d.ts:

```js
    checkOsAccountVerified(callback: AsyncCallback<boolean>): void;
    checkOsAccountVerified(): Promise<boolean>;
```
替代接口：
```js
    isOsAccountUnlocked(): Promise<boolean>;
```

废弃前接口：
```js
    interface OsAccountInfo {
        ...
        isVerified: boolean;
        isActived: boolean;
        ...
    }
```
替代接口：
```js
    interface OsAccountInfo {
        ...
        isUnlocked: boolean;
        isActivated: boolean;
        ...
    }
```

**适配指导**

从API11版本开始，应用开发者应使用上述新增接口替代废弃接口。

