# Introduction to Asset Store Kit

Asset Store Kit (ASSET for short) provides a series of open APIs to securely store and manage short sensitive data, including but not limited to passwords (accounts/passwords), tokens (application credentials), and important plaintext (such as bank card numbers).

## Basic Concepts

The secure storage of assets depends on the underlying universal keystore. Specifically, the universal keystore implements the asset encryption, decryption, and access control in a secure environment (such as a TEE). The sensitive user data will never be disclosed even if the system is attacked.

The AES256-GCM algorithm is used to encrypt and decrypt assets. The following access control mechanisms are used to protect assets against unauthorized access:

* Owner-based access control: All assets are protected by this mechanism by default.
  * An asset can be accessed only by its owner (service that writes the asset).
  * ASSET obtains the asset owner identity from the system service. Even if the service identity is spoofed, the spoofer cannot obtain the data of other services.
  * The asset encryption/decryption also protects the integrity of the asset owner identity. Even if the owner of the asset is tampered with, attackers cannot obtain data of other services.

* Group-based access control:
  * You can add multiple applications of the same developer to a group and set the ground ID when adding assets. The applications in the same group can access data with each other.
  * The group information consists of the developer ID and group ID. The developer ID does not need to be configured. The group ID is configured during application development. For details, see [Tags in the Configuration File](../../quick-start/app-configuration-file.md#tags-in-the-configuration-file). When an application is released, it is signed by a private key to ensure the group ID integrity.
  * You can configure multiple groups for an application and allocate assets to different groups based on their sharing scope. This allows fine-grained group-based access control.

* Access control based on the lock screen status: This mechanism provides the following protection levels in ascending order of security. You can set it based on site requirements. If no protection level is set, assets are accessible only after the device is unlocked for the first time.
  * **DEVICE_POWERED_ON**: allows access to assets after the device is powered on.
  * **DEVICE_FIRST_UNLOCKED**: allows access to assets after the device is unlocked for the first time after power-on.
  * **DEVICE_UNLOCKED**: allows access to assets only when the device is unlocked.

* Access control based on the setting of the lock screen password: This mechanism allows assets to be accessed only after a lock screen password is set. By default, it is disabled.
  * If this mechanism is enabled, assets can be accessed only after the user sets a screen lock password.

* Access control based on user authentication: This mechanism allows assets to be accessed only after a successful user identity authentication. By default, it is disabled.
  * If this mechanism is enabled, assets can be accessed only after a successful user identity authentication.
  * The user authentication can be fingerprint, facial, or PIN authentication.
  * You can set an authentication validity period, which allows access to multiple assets within the validity period. The maximum authentication validity period is 10 minutes.

## Constraints

* Device limitations

  This kit is not supported on lite wearables.

* Alias-based access

  Assets are stored in the ASSET database in ciphertext and uniquely identified by the service identity and alias. The alias of each asset must be unique.

* Batch asset query

  The assets queried are transmitted to the service through an IPC channel. Due to the limitation of the IPC buffer size, the maximum number of assets to be queried at a time cannot exceed 40.

* Custom service data storage

  ASSET provides 12 custom asset attributes starting with **DATA_LABEL** for services. If the 12 custom attributes are used, you can combine multiple data segments in a certain format (for example, JSON) into an ASSET attribute.

  ASSET protects the integrity of the attributes starting with **DATA_LABEL_CRITICAL**. These attributes cannot be changed once written.

* Group-based access control

  Asset Store Kit does not support sandbox applications, dual application storage, or data access across groups.

  The assets with [IS_PERSISTENT](../../reference/apis-asset-store-kit/js-apis-asset.md#tag) set to **True** cannot be shared in a group.

* Asset deletion
  1. The asset data that meets the specified conditions is deleted when **remove()** is called. For details, see [Removing Assets (ArkTS)](asset-js-remove.md) and [Removing Assets (C/C++)](asset-native-remove.md).
  2. When an application is uninstalled, the asset data of the application will be deleted. However, if [IS_PERSISTENT](../../reference/apis-asset-store-kit/js-apis-asset.md#tag) is **true**, the asset data will be retained.
  3. When a user is deleted, the asset data of the user will be deleted.
  4. When a device is reset to restore factory settings, the asset data will be deleted.

## Relationship with Other Kits

Asset Store Kit provides secure storage of sensitive data less than 1 KB in size. To protect data greater than 1 KB, use [Universal Keystore Kit](../UniversalKeystoreKit/huks-overview.md) or [Crypto Architecture Kit](../CryptoArchitectureKit/crypto-architecture-kit-intro.md).
