# 帐号子系统ChangeLog

OpenHarmony4.0.3.2版本相较于OpenHarmony之前的版本，帐号模块的API变更如下。

## cl.account_os_account.1 应用帐号isAccountRemovable命名变更

类Authenticator中的成员函数isAccountRemovable由于命名不统一问题，名称变更为checkAccountRemovable。

**变更影响**

类Authenticator中的成员函数isAccountRemovable，在4.0.3.2版本及后续版本中无法继续正常使用，由checkAccountRemovable代替。

**关键的接口/组件变更**

- 涉及接口
  ```ts
  class Authenticator {
    ...
    isAccountRemovable
    ...
  }
  ```
- 变更前：

  ```ts
  class Authenticator {
    ...
    /**
    * Checks whether the specified account can be removed.
    * @param name Indicates the account name.
    * @param callback Indicates the authenticator callback.
    * @returns void.
    * @since 9
    */
    isAccountRemovable(name: string, callback: AuthCallback): void;
    ...
  }
  ```

- 变更后：

  ```ts
  class Authenticator {
    ...
    /**
    * Checks whether the specified account can be removed.
    * @param name Indicates the account name.
    * @param callback Indicates the authenticator callback.
    * @returns void.
    * @since 9
    */
    checkAccountRemovable(name: string, callback: AuthCallback): void;
    ...
  }
  ```

## cl.account_os_account.2 系统帐号checkConstraintEnabled命名变更

checkConstraintEnabled由于命名不统一问题，名称变更为checkOsAccountConstraintEnabled。

**变更影响**

checkConstraintEnabled接口，在4.0.3.2版本及后续版本中无法继续正常使用，由checkOsAccountConstraintEnabled代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  checkConstraintEnabled
  ...
}
```

- 变更前：

  ```ts
  checkConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
  checkConstraintEnabled(localId: number, constraint: string): Promise<boolean>;
  ```

- 变更后：

  ```ts
  checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
  checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise<boolean>;
  ```

## cl.account_os_account.3 系统帐号checkOsAccountConstraintEnabled权限场景变更

checkOsAccountConstraintEnabled接口的权限管控新增可选权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS。

**变更影响**

在4.0.3.2版本及后续版本中，应用申请ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限亦可调用checkOsAccountConstraintEnabled，
切此前版本申请ohos.permission.MANAGE_LOCAL_ACCOUNTS权限的不影响使用

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  checkOsAccountConstraintEnabled
  ...
}
```

- 变更前：

  ```ts
  ...
  * @permission ohos.permission.MANAGE_LOCAL_ACCOUNTS
  ...
  checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
  checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise<boolean>;
  ```

- 变更后：

  ```ts
  ...
  * @permission ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS
  ...
  checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
  checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise<boolean>;
  ```

## cl.account_os_account.4 系统帐号queryOsAccountLocalIdFromProcessd命名变更

queryOsAccountLocalIdFromProcess由于命名不统一问题，名称变更为getOsAccountLocalId。

**变更影响**

queryOsAccountLocalIdFromProcess接口，在4.0.3.2版本及后续版本中无法继续正常使用，由getOsAccountLocalId代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  queryOsAccountLocalIdFromProcess
  ...
}
```
- 变更前：

  ```ts
  queryOsAccountLocalIdFromProcess(callback: AsyncCallback<number>): void;
  queryOsAccountLocalIdFromProcess(): Promise<number>;
  ```

- 变更后：

  ```ts
  getOsAccountLocalId(callback: AsyncCallback<number>): void;
  getOsAccountLocalId(): Promise<number>;
  ```

## cl.account_os_account.5 系统帐号queryOsAccountLocalIdFromUid命名变更

queryOsAccountLocalIdFromUid由于命名不统一问题，名称变更为getOsAccountLocalIdForUid。

**变更影响**

queryOsAccountLocalIdFromUid接口，在4.0.3.2版本及后续版本中无法继续正常使用，由getOsAccountLocalIdForUid代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  queryOsAccountLocalIdFromUid
  ...
}
```

- 变更前：

  ```ts
  queryOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback<number>): void;
  queryOsAccountLocalIdFromUid(uid: number): Promise<number>;
  ```

- 变更后：

  ```ts
  getOsAccountLocalIdForUid(uid: number, callback: AsyncCallback<number>): void;
  getOsAccountLocalIdForUid(uid: number): Promise<number>;
  ```

## cl.account_os_account.6 系统帐号queryOsAccountLocalIdFromDomain命名变更

queryOsAccountLocalIdFromDomain由于命名不统一问题，名称变更为getOsAccountLocalIdForDomain。

**变更影响**

queryOsAccountLocalIdFromDomain接口，在4.0.3.2版本及后续版本中无法继续正常使用，由getOsAccountLocalIdForDomain代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  queryOsAccountLocalIdFromDomain
  ...
}
```

- 变更前：

  ```ts
  queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback<number>): void;
  queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise<number>;
  ```

- 变更后：

  ```ts
  getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback<number>): void;
  getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo): Promise<number>;
  ```

## cl.account_os_account.7 系统帐号getActivatedOsAccountIds命名变更

getActivatedOsAccountIds由于命名不统一问题，名称变更为getActivatedOsAccountLocalIds。

**变更影响**

getActivatedOsAccountIds接口，在4.0.3.2版本及后续版本中无法继续正常使用，由getActivatedOsAccountLocalIds代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  getActivatedOsAccountIds
  ...
}
```

- 变更前：

  ```ts
  getActivatedOsAccountIds(callback: AsyncCallback<Array<number>>): void;
  getActivatedOsAccountIds(): Promise<Array<number>>;
  ```

- 变更后：

  ```ts
  getActivatedOsAccountLocalIds(callback: AsyncCallback<Array<number>>): void;
  getActivatedOsAccountLocalIds(): Promise<Array<number>>;
  ```

## cl.account_os_account.8 系统帐号queryOsAccountLocalIdBySerialNumber命名变更

queryOsAccountLocalIdBySerialNumber由于命名不统一问题，名称变更为getOsAccountLocalIdForSerialNumber。

**变更影响**

queryOsAccountLocalIdBySerialNumber接口，在4.0.3.2版本及后续版本中无法继续正常使用，由getOsAccountLocalIdForSerialNumber代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  queryOsAccountLocalIdBySerialNumber
  ...
}
```

- 变更前：

  ```ts
  queryOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback<number>): void;
  queryOsAccountLocalIdBySerialNumber(serialNumber: number): Promise<number>;
  ```

- 变更后：

  ```ts
  getOsAccountLocalIdForSerialNumber(serialNumber: number, callback: AsyncCallback<number>): void;
  getOsAccountLocalIdForSerialNumber(serialNumber: number): Promise<number>;
  ```

## cl.account_os_account.9 系统帐号querySerialNumberByOsAccountLocalId命名变更

querySerialNumberByOsAccountLocalId由于命名不统一问题，名称变更为getSerialNumberForOsAccountLocalId。

**变更影响**

querySerialNumberByOsAccountLocalId接口，在4.0.3.2版本及后续版本中无法继续正常使用，由getSerialNumberForOsAccountLocalId代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  querySerialNumberByOsAccountLocalId
  ...
}
```

- 变更前：

  ```ts
  querySerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback<number>): void;
  querySerialNumberByOsAccountLocalId(localId: number): Promise<number>;
  ```

- 变更后：

  ```ts
  getSerialNumberForOsAccountLocalId(localId: number, callback: AsyncCallback<number>): void;
  getSerialNumberForOsAccountLocalId(localId: number): Promise<number>;
  ```

## cl.account_os_account.10 系统帐号getBundleIdFromUid命名变更

getBundleIdFromUid由于命名不统一问题，名称变更为getBundleIdForUid。

**变更影响**

getBundleIdFromUid接口，在4.0.3.2版本及后续版本中无法继续正常使用，由getBundleIdForUid代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  getBundleIdFromUid
  ...
}
```

- 变更前：

  ```ts
  getBundleIdFromUid(uid: number, callback: AsyncCallback<number>): void;
  getBundleIdFromUid(uid: number): Promise<number>;
  ```

- 变更后：

  ```ts
  getBundleIdForUid(uid: number, callback: AsyncCallback<number>): void;
  getBundleIdForUid(uid: number): Promise<number>;
  ```

## cl.account_os_account.11 系统帐号queryOsAccountConstraintSourceTypes命名变更

queryOsAccountConstraintSourceTypes由于命名不统一问题，名称变更为getOsAccountConstraintSourceTypes。

**变更影响**

queryOsAccountConstraintSourceTypes接口，在4.0.3.2版本及后续版本中无法继续正常使用，由getOsAccountConstraintSourceTypes代替。

**关键的接口/组件变更**

- 涉及接口
```
interface AccountManager {
  ...
  queryOsAccountConstraintSourceTypes
  ...
}
```

- 变更前：

  ```ts
  queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback<Array<ConstraintSourceTypeInfo>>): void;
  queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise<Array<ConstraintSourceTypeInfo>>;
  ```

- 变更后：

  ```ts
  getOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback<Array<ConstraintSourceTypeInfo>>): void;
  getOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise<Array<ConstraintSourceTypeInfo>>;
  ```