# 程序访问控制子系统ChangeLog

OpenHarmony 4.0.3.2 版本相较于OpenHarmony 之前的版本，程序访问控制子系统的API变更如下。

## cl.access_token.1 getPermissionUsedRecords命名变更

接口getPermissionUsedRecords由于命名规范问题，名称变更为getPermissionUsedRecord。

**变更影响**

接口getPermissionUsedRecords，在4.0.3.3版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  function getPermissionUsedRecords

- 变更前：

  ```ts
  function getPermissionUsedRecords
  ```

- 变更后：

  ```ts
  function getPermissionUsedRecord
  ```

**适配指导**

请使用getPermissionUsedRecord替换getPermissionUsedRecords