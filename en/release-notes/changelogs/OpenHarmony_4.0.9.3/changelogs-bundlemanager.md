# Bundle Management Subsystem Changelog
## cl.bundlemanager.1 schema in the module.json File Changed

In the **module.json** file, the **name** attributes of the **module**, **ability**, and **extensionAbility** fields must start with a letter and contain only letters, digits, underscores (_), and dots (.).

**Change Impact**

After an update to the new SDK version, the build fails if the **name** attributes of these fields do not meet the preceding requirements.

**Key API/Component Changes**

In the **module.json** file, the **name** attributes of the **module**, **ability**, and **extensionAbility** fields must start with a letter and contain only letters, digits, underscores (_), and dots (.).

**Adaptation Guide**

Modify the **name** attributes for these fields accordingly to the new requirements.