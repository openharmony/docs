# App Access Control Subsystem ChangeLog

OpenHarmony 4.0.3.2 has the following changes in the APIs of the app access control subsystem:

## cl.access_token.1 getPermissionUsedRecords Name Change

Changed **getPermissionUsedRecords** to **getPermissionUsedRecord**.

**Change Impact**

The **getPermissionUsedRecords()** API cannot be used in OpenHarmony 4.0.3.3 and later versions.

**Key API/Component Changes**

- Involved APIs:

  function getPermissionUsedRecords

- Before change:

  ```ts
  function getPermissionUsedRecords
  ```

- After change:

  ```ts
  function getPermissionUsedRecord
  ```

**Adaptation Guide**

Use **getPermissionUsedRecord()**.
