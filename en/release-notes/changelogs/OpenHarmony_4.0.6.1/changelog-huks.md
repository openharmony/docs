# HUKS Changelog

## cl.huks.1 Change of the Permission for Using attestKeyItem

The **attestKeyItem** interface attests a key using a public key encapsulated based on the device certificate chain. Any arbitrary export of the device certificate increases the risks on user privacy. Therefore, certain permissions are required for using this interface.

**Change Impact**

Applications without the **ohos.permission.ACCESS_IDS** permission or the system_basic or system_core permission cannot call **attestKeyItem()**.

**Key API/Component Changes**

- Involved APIs:

  attestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult\>): void;
  attestKeyItem(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult\>;

- Before change:

  The AccessToken permission is verified only for the applications that pass in a tag related to **ATTESTATION_ID**.


- After change:

  **attestKeyItem()** can be called only by a system application with the system_basic or system_core permission or an application with the **ohos.permission.ACCESS_IDS** permission.

**Adaptation Guide**

Applications with the system_basic or system_core permission can call **attestKeyItem()**. If an application with the normal permission needs to call **attestKeyItem()**, it must have the **ohos.permission.ACCESS_IDS** permission. For details about how to apply for the permission, see [ACL](../../../application-dev/security/accesstoken-overview.md#acl).

