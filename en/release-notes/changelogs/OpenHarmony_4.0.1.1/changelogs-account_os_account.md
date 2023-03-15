# Account Subsystem ChangeLog

## cl.account_os_account.1 Expansion of Distributed Account Nickname and Profile Picture Specifications

The existing distributed account nickname and profile picture specifications cannot meet requirements in scenarios where the nickname is long and profile picture is large.

Therefore, the distributed account nickname and profile picture specifications are expanded.

**Change Impacts**

The API change is forward compatible. Applications developed based on earlier versions can use the APIs in accordance with the new specifications, without affecting the original logic.

**Key API/Component Changes**

Before change:
  - The nickname cannot exceed 20 characters, and the profile picture size cannot exceed 3 MB.

After change:
  - The nickname cannot exceed 1024 characters, and the profile picture size cannot exceed 10 MB.
