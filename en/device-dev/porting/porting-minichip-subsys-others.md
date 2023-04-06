# Configuring Other Subsystems


In addition to the preceding subsystems, there are some subsystems that are necessary but do not need to be ported, such as the distributed scheduler and DFX subsystems.


To add these subsystems, perform the following operations in the **vendor/MyVendorCompany/MyProduct/config.json** file:

```
{
  "subsystem": "distributed_schedule",
  "components": [
    { "component": "system_ability_manager", "features":[] } # The component name varies according to the version.
  ]
},
{
  "subsystem": "hiviewdfx",
  "components": [
    { "component": "hilog_lite", "features":[] },
    { "component": "hievent_lite", "features":[] }
  ]
},
```
