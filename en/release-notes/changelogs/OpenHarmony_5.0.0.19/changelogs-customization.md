# Customization Subsystem Changelog

## cl.customization.1 Change in the Kit to Which configPolicy Belongs

**Access Level**

System API

**Reason for Change**

The kit to which the **configPolicy** API belongs is changed from MDM Kit to Basic Services Kit.

**Change Impact**

This change is a non-compatible change.

Before the change: Use `import MDMKit from '@kit.MDMKit';` or `import configPolicy form '@ohos.configPolicy';` to import **configPolicy**.

After the change: Use `import BasicServicesKit from '@kit.MBasicServicesKit';` or `import configPolicy form '@ohos.configPolicy';` to import **configPolicy**.

**Change Since**

OpenHarmony SDK 5.0.0.19

**Adaptation Guide**

Use `import BasicServicesKit from '@kit.BasicServicesKit';` instead of `import MDMKit from '@kit.MDMKit';` to import **configPolicy**.

