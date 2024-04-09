# OpenHarmony SELinux Policy Checklist

## Introduction

Not all the SELinux policies converted from AVC logs are appropriate for use. You need to review and modify them. This topic provides the SELinux policy checklist for your reference.

## SELinux Policies for Applications

The attributes corresponding to the SELinux types of application processes and application data are classified based on the Ability Privilege Levels (APLs) of applications. The following table lists the mappings between them.

| APL| Application Process Attribute| Application Directory Attribute|
| -------- | -------- | -------- |
| normal | normal_hap_attr | normal_hap_data_file_attr |
| system_basic | system_basic_hap_attr | system_basic_hap_data_file_attr |
| system_core | system_core_hap_attr | system_core_hap_data_file_attr |

For details about the APLs, see [Application APL](../../application-dev/security/AccessToken/app-permission-mgmt-overview.md#application-apl).

In addition, the **hap_domain** attribute indicates all application processes.

You need to modify the application SELinux type based on the application APL. For example, the policy configured based on the AVC log is as follows:
```text
allow normal_hap huks_service:binder { call };
```
This policy allows binder communication between the application process labeled **normal_hap** and huks_service. Considering huks_service provides the HUKS capability for all applications, you need to change **normal_hap** to **hap_domain**.
```text
allow hap_domain huks_service:binder { call };
```

The following table lists the attributes for applications of different APIs and their directories.

| Application| Attribute|
| -------- | -------- |
| normal applications| normal_hap_attr |
| system_basic applications| system_basic_hap_attr |
| system_core applications| system_core_hap_attr |
| All applications| hap_domain |

| Application Directory| Attribute|
| -------- | -------- |
| Directories of normal applications| normal_hap_data_file_attr |
| Directories of system_basic applications| system_basic_hap_data_file_attr |
| Directories of system_core applications| system_core_hap_data_file_attr |
| All application directories| normal_hap_data_file_attr & system_basic_hap_data_file_attr & system_core_hap_data_file_attr |

## New SELinux Policies for ioctl

For ioctl, you need to restrict **ioctlcmd** based on AVC logs in addition to configuring **allow** rules. Otherwise, all **ioctlcmd** permissions are granted, which violates the least privilege principle. For example, the AVC log is as follows:
```text
#avc:  denied  { ioctl } for  pid=1 comm="init" path="/data/app/el1/bundle/public" dev="mmcblk0p11" ino=652804 ioctlcmd=0x6613 scontext=u:r:init:s0 tcontext=u:object_r:data_app_el1_file:s0 tclass=dir permissive=0
```
The SELinux policy that allows ioctl is configured based on the AVC log as follows:
```text
allow init data_app_el1_file:dir { ioctl };
```
You need to further restrict **ioctlcmd** based on "ioctlcmd=0x6613" in the AVC log.
```text
allowxperm init data_app_el1_file:dir ioctl { 0x6613 };
```

## Using neverallow to Protect Services

You can use **neverallow** rules to prevent improper policy configuration and protect services.

For example, the SELinux type of the database file of the subject process accesstoken_service is **accesstoken_data_file**. For security purposes, the database file can be read and written only by the accesstoken_service process only. In this case, you can configure a **neverallow** rule to achieve this purpose.
```text
neverallow { domain -accesstoken_service } accesstoken_data_file:file *;
```
This rule prevents all the other processes except accesstoken_service from accessing accesstoken_data_file.
