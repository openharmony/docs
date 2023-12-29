# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Changed distroFilter to distributionFilter in the module.json File
The [distroFilter](../../../application-dev/quick-start/module-configuration-file.md) tag in the **module.json** file is changed to **distributionFilter**.

**Change Impact**

This change is a compatible change. If the **distroFilter** tag is used, no error is reported during compilation on DevEco Studio, but a wavy line is displayed in the editor.

**Adaptation Guide**

Replace **distroFilter** with **distributionFilter** in the configuration file.
