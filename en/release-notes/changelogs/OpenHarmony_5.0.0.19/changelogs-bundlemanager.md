# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Rule Changed for Verifying Mandatory Fields Under abilities

**Access Level**

Other

**Change Reason**

The **srcEntrance** field under **abilities** has been replaced by **srcEntry** in API version 9. However, the verification rule still uses **srcEntrance**. Error messages containing the **srcEntrance** field are generated in some cases.

**Change Impact**

This change is a non-compatible change.

After the change, if the **srcEntrance** field is used in the project, the following error information is displayed during the build of the SDK of the new version:
```
> hvigor ERROR: Failed :entry:default@PreBuild... 
> hvigor ERROR: Schema validate failed.
{
  instancePath: 'module.abilities[0]',
  keyword: 'required',
  params: { missingProperty: 'srcEntry' },
  message: "must have required property 'srcEntry'",
  location: 'C:/.../Projects/MyApp/entry/src/main/module.json5:15:8'
} 
```

**API Level**

12

**Change Since**

OpenHarmony 5.0.0.19

**Adaptation Guide**

Change the name of the **srcEntrance** field in the project to **srcEntry**.
