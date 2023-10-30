# Bundle Manager Subsystem Changelog
## cl.bundlemanager.1 Schema Validation in modulecheck and configcheck Changed

In the schema validation files **app.json**, **module.json**, **configSchema_lite.json**, and **configSchema_rich.json**, the maximum number of characters allowed for **bundleName** is changed from 127 to 128.

**Change Impact**

Before the change, the maximum length allowed for **bundleName** is 127 characters. When the length of **bundleName** is greater than or equal to 128 characters, DevEco Studio cannot build or pack the project, and reports the error message "Schema validate failed."

After the change, the maximum length allowed for **bundleName** is 128 characters. When **bundleName** is set to 128 characters, DevEco Studio can build and pack the project. When the length of **bundleName** is greater than 128 characters, DevEco Studio cannot build or pack the project, and reports the error message "Schema validate failed."

**Key API/Component Changes**

N/A

**Adaptation Guide**

No adaptation is required. You only need to upgrade the SDK in use.