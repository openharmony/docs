# Mappings Between Label Versions and System Versions

A system version consists of the operating system name and software version number, separated by a hyphen (-). The software version number contains four digits, representing the major, minor, feature, and build versions in sequence. A system version can have a maximum of 64 characters (spaces not allowed) and can be obtained by running the API **GetOsFullName()**.

The label versions released in the OpenHarmony community, for example, 1.1.x, 3.0.x, and 3.1.x, use 3-digit version numbers. To avoid troubles, the following table lists the mappings between the label versions released in the community and their system versions.

## Mappings between label versions and system versions

| Label Version                      | Small/Mini System Version | Standard System Version      | Remarks                      |
| -------------------------- | -------------------- | -------------------- | -------------------------- |
| OpenHarmony_release_v1.1.0 | NA                   | NA                   | No system version is defined.          |
| OpenHarmony-v1.1.1-LTS     | NA                   | NA                   | No system version is defined.          |
| OpenHarmony-v1.1.2-LTS     | NA                   | NA                   | No system version is defined.          |
| OpenHarmony-v1.1.3-LTS     | NA                   | NA                   | No system version is defined.          |
| OpenHarmony-v1.1.4-LTS     | NA                   | NA                   | No system version is defined.          |
| OpenHarmony-v1.1.5-LTS     | NA                   | NA                   | No system version is defined.          |
| OpenHarmony-v3.0-LTS       | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.0.1-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.0.2-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.0.3-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.0.5-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.0.6-LTS     | OpenHarmony-3.0.0.0  | OpenHarmony-3.0.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.0.7-LTS     | OpenHarmony-3.0.7.2  | OpenHarmony-3.0.7.2  | NA                         |
| OpenHarmony-v3.1-Release   | OpenHarmony-1.0.1.0  | OpenHarmony-2.2.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.1.1-Release | OpenHarmony-1.0.1.0  | OpenHarmony-2.2.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.1.2-Release | OpenHarmony-1.0.1.0  | OpenHarmony-2.2.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.1.3-Release | OpenHarmony-3.1.8.5  | OpenHarmony-2.2.0.0  | The **OsFullName** field is not modified.|
| OpenHarmony-v3.1.4-Release | OpenHarmony-3.1.9.6  | OpenHarmony-3.1.9.6  | NA                         |
| OpenHarmony-v3.1.5-Release | OpenHarmony-3.1.11.5 | OpenHarmony-3.1.11.5 | NA                         |

## Changing System Versions

### For 1.0.x, 3.0.x, and 3.1.x

Integration configuration is unavailable for 1.0.x, 3.0.x, and 3.1.x in the community, so you need to modify the configuration in different files for small or mini systems and standard systems.

For the small or mini system, the **OsFullName** field is in the following file: startup_syspara_lite/ frameworks / parameter / src / parameter_common.c

For the standard system, the **OsFullName** field is in the following file: startup_syspara_lite/ interfaces / innerkits / native / syspara / src / sysversion.c

Change the **static const int MAJOR_VERSION**, **static const int SENIOR_VERSION**, **static const int FEATURE_VERSION**, and **static const int BUILD_VERSION** fields to the corresponding system versions.

### For 3.2.x and Later Versions

Change the **const.ohos.fullname** field in the file **startup_init_lite/ services / etc_lite / param / ohos_const / ohos.para**

to the corresponding system version.
