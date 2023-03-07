# Account Subsystem Changelog

OpenHarmony 4.0.3.2 has the following changes in account module APIs:

## cl.account_os_account.1 App Account API isAccountRemovable Renamed

Changed **isAccountRemovable** in the **Authenticator** class to **checkAccountRemovable**.

**Change Impact**

The **isAccountRemovable** API in the **Authenticator** class cannot be used from 4.0.3.2. Use **checkAccountRemovable** instead.

**Key API/Component Changes**

- Involved APIs:
  ```ts
  class Authenticator {
    ...
    isAccountRemovable
    ...
  }
  ```
- Before change:

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

- After change:

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

## cl.account_os_account.2 OS Account API checkConstraintEnabled Renamed

Changed **checkConstraintEnabled** to **checkOsAccountConstraintEnabled**.

**Change Impact**

The **checkConstraintEnabled** API cannot be used from 4.0.3.2. Use **checkOsAccountConstraintEnabled** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  checkConstraintEnabled
  ...
}
```

- Before change:

  ```ts
  checkConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
  checkConstraintEnabled(localId: number, constraint: string): Promise<boolean>;
  ```

- After change:

  ```ts
  checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
  checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise<boolean>;
  ```

## cl.account_os_account.3 OS Account API **checkOsAccountConstraintEnabled** Permission Scenario Change

Added an optional permission **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** to the **checkOsAccountConstraintEnabled** API.

**Change Impact**

In 4.0.3.2 and later versions, an app with the **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS** permission can also call **checkOsAccountConstraintEnabled**.
The use of **ohos.permission.MANAGE_LOCAL_ACCOUNTS** is not affected.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  checkOsAccountConstraintEnabled
  ...
}
```

- Before change:

  ```ts
  ...
  * @permission ohos.permission.MANAGE_LOCAL_ACCOUNTS
  ...
  checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
  checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise<boolean>;
  ```

- After change:

  ```ts
  ...
  * @permission ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS
  ...
  checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback<boolean>): void;
  checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise<boolean>;
  ```

## cl.account_os_account.4 OS Account API queryOsAccountLocalIdFromProcessd Renamed

Changed **queryOsAccountLocalIdFromProcess** to **getOsAccountLocalId**.

**Change Impact**

The **queryOsAccountLocalIdFromProcess** API cannot be used from 4.0.3.2. Use **getOsAccountLocalId** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  queryOsAccountLocalIdFromProcess
  ...
}
```
- Before change:

  ```ts
  queryOsAccountLocalIdFromProcess(callback: AsyncCallback<number>): void;
  queryOsAccountLocalIdFromProcess(): Promise<number>;
  ```

- After change:

  ```ts
  getOsAccountLocalId(callback: AsyncCallback<number>): void;
  getOsAccountLocalId(): Promise<number>;
  ```

## cl.account_os_account.5 OS Account API queryOsAccountLocalIdFromUid Renamed

Changed **queryOsAccountLocalIdFromUid** to **getOsAccountLocalIdForUid**.

**Change Impact**

The **queryOsAccountLocalIdFromUid** API cannot be used from 4.0.3.2. Use **getOsAccountLocalIdForUid** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  queryOsAccountLocalIdFromUid
  ...
}
```

- Before change:

  ```ts
  queryOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback<number>): void;
  queryOsAccountLocalIdFromUid(uid: number): Promise<number>;
  ```

- After change:

  ```ts
  getOsAccountLocalIdForUid(uid: number, callback: AsyncCallback<number>): void;
  getOsAccountLocalIdForUid(uid: number): Promise<number>;
  ```

## cl.account_os_account.6 OS Account API queryOsAccountLocalIdFromDomain Renamed

Changed **queryOsAccountLocalIdFromDomain** to **getOsAccountLocalIdForDomain**.

**Change Impact**

The **queryOsAccountLocalIdFromDomain** API cannot be used from 4.0.3.2. Use **getOsAccountLocalIdForDomain** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  queryOsAccountLocalIdFromDomain
  ...
}
```

- Before change:

  ```ts
  queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback<number>): void;
  queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise<number>;
  ```

- After change:

  ```ts
  getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback<number>): void;
  getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo): Promise<number>;
  ```

## cl.account_os_account.7 OS Account API getActivatedOsAccountIds Renamed

Changed **getActivatedOsAccountIds** to **getActivatedOsAccountLocalIds**.

**Change Impact**

The **getActivatedOsAccountIds** API cannot be used from 4.0.3.2. Use **getActivatedOsAccountLocalIds** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  getActivatedOsAccountIds
  ...
}
```

- Before change:

  ```ts
  getActivatedOsAccountIds(callback: AsyncCallback<Array<number>>): void;
  getActivatedOsAccountIds(): Promise<Array<number>>;
  ```

- After change:

  ```ts
  getActivatedOsAccountLocalIds(callback: AsyncCallback<Array<number>>): void;
  getActivatedOsAccountLocalIds(): Promise<Array<number>>;
  ```

## cl.account_os_account.8 OS Account API queryOsAccountLocalIdBySerialNumber Renamed

Changed **queryOsAccountLocalIdBySerialNumber** to **getOsAccountLocalIdForSerialNumber**.

**Change Impact**

The **queryOsAccountLocalIdBySerialNumber** API cannot be used from 4.0.3.2. Use **getOsAccountLocalIdForSerialNumber** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  queryOsAccountLocalIdBySerialNumber
  ...
}
```

- Before change:

  ```ts
  queryOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback<number>): void;
  queryOsAccountLocalIdBySerialNumber(serialNumber: number): Promise<number>;
  ```

- After change:

  ```ts
  getOsAccountLocalIdForSerialNumber(serialNumber: number, callback: AsyncCallback<number>): void;
  getOsAccountLocalIdForSerialNumber(serialNumber: number): Promise<number>;
  ```

## cl.account_os_account.9 OS Account API querySerialNumberByOsAccountLocalId Renamed

Changed **querySerialNumberByOsAccountLocalId** to **getSerialNumberForOsAccountLocalId**.

**Change Impact**

The **querySerialNumberByOsAccountLocalId** API cannot be used from 4.0.3.2. Use **getSerialNumberForOsAccountLocalId** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  querySerialNumberByOsAccountLocalId
  ...
}
```

- Before change:

  ```ts
  querySerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback<number>): void;
  querySerialNumberByOsAccountLocalId(localId: number): Promise<number>;
  ```

- After change:

  ```ts
  getSerialNumberForOsAccountLocalId(localId: number, callback: AsyncCallback<number>): void;
  getSerialNumberForOsAccountLocalId(localId: number): Promise<number>;
  ```

## cl.account_os_account.10 OS Account API getBundleIdFromUid Renamed

Changed **getBundleIdFromUid** to **getBundleIdForUid**.

**Change Impact**

The **getBundleIdFromUid** API cannot be used from 4.0.3.2. Use **getBundleIdForUid** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  getBundleIdFromUid
  ...
}
```

- Before change:

  ```ts
  getBundleIdFromUid(uid: number, callback: AsyncCallback<number>): void;
  getBundleIdFromUid(uid: number): Promise<number>;
  ```

- After change:

  ```ts
  getBundleIdForUid(uid: number, callback: AsyncCallback<number>): void;
  getBundleIdForUid(uid: number): Promise<number>;
  ```

## cl.account_os_account.11 OS Account API queryOsAccountConstraintSourceTypes Renamed

Changed **queryOsAccountConstraintSourceTypes** to **getOsAccountConstraintSourceTypes**.

**Change Impact**

The **queryOsAccountConstraintSourceTypes** API cannot be used from 4.0.3.2. Use **getOsAccountConstraintSourceTypes** instead.

**Key API/Component Changes**

- Involved APIs:
```
interface AccountManager {
  ...
  queryOsAccountConstraintSourceTypes
  ...
}
```

- Before change:

  ```ts
  queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback<Array<ConstraintSourceTypeInfo>>): void;
  queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise<Array<ConstraintSourceTypeInfo>>;
  ```

- After change:

  ```ts
  getOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback<Array<ConstraintSourceTypeInfo>>): void;
  getOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise<Array<ConstraintSourceTypeInfo>>;
  ```
