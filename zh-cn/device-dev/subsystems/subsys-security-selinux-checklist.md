# OpenHarmony SELinux策略自检

## 概述

根据avc日志转换出来的SELinux策略，不一定都是合理的，需要重新审视配置的SELinux策略，这里提供一些SELinux策略自检建议。

## 涉及应用的SELinux策略自检

目前OpenHarmony SELinux根据应用的三个APL等级，将应用进程的SELinux类型分为对应的三个attribute，将应用数据目录的SELinux类型也分为对应的三个attribute，如下：

| APL等级 | 应用进程归属的attribute | 应用数据目录归属的attribute |
| -------- | -------- | -------- |
| normal | normal_hap_attr | normal_hap_data_file_attr |
| system_basic | system_basic_hap_attr | system_basic_hap_data_file_attr |
| system_core | system_core_hap_attr | system_core_hap_data_file_attr |

APL说明参考[权限等级说明](../../application-dev/security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)中的`权限APL等级`。

另外还有一个attribute表示所有应用进程，为hap_domain。

当配置的SELinux策略涉及应用SELinux类型时，需要根据实际的开放范围做对应的修改，比如根据avc日志配置的策略是：
```text
allow normal_hap huks_service:binder { call };
```
表示允许以normal_hap为标签的应用进程和huks_service进行binder通信。考虑实际情况，huks_service会为所有应用提供huks能力，那么这里的normal_hap应该改为hap_domain，即
```text
allow hap_domain huks_service:binder { call };
```

策略开放范围详细的对应关系，参考下表：

| 面向应用进程的开放范围 | 替换为attribute |
| -------- | -------- |
| 所有normal等级的应用 | normal_hap_attr |
| 所有system_basic等级的应用 | system_basic_hap_attr |
| 所有system_core等级的应用 | system_core_hap_attr |
| 所有应用 | hap_domain |

| 面向应用数据目录的开放范围 | 替换为attribute |
| -------- | -------- |
| 所有normal等级的应用数据目录 | normal_hap_data_file_attr |
| 所有system_basic等级的应用数据目录 | system_basic_hap_data_file_attr |
| 所有system_core等级的应用数据目录 | system_core_hap_data_file_attr |
| 所有应用的数据目录 | normal_hap_data_file_attr & system_basic_hap_data_file_attr & system_core_hap_data_file_attr |

## 涉及新增ioctl的SELinux策略自检

涉及配置ioctl相关的SELinux策略时，除了配置allow规则以外，还需要根据avc日志对ioctl的ioctlcmd进行限制，否则会导致所有的ioctlcmd权限都被开放，不满足权限最小化原则。例如，有下面的avc日志：
```text
#avc:  denied  { ioctl } for  pid=1 comm="init" path="/data/app/el1/bundle/public" dev="mmcblk0p11" ino=652804 ioctlcmd=0x6613 scontext=u:r:init:s0 tcontext=u:object_r:data_app_el1_file:s0 tclass=dir permissive=0
```
根据该avc日志配置了允许ioctl的SELinux策略：
```text
allow init data_app_el1_file:dir { ioctl };
```
同时，还需要根据avc日志中的`ioctlcmd=0x6613`字段，进一步限制ioctl的开放范围：
```text
allowxperm init data_app_el1_file:dir ioctl { 0x6613 };
```

## 使用neverallow对业务做安全防护

neverallow可以阻止不合理的策略配置，因此可以作为安全防护手段，避免本业务的SELinux策略被恶意修改。

例如，主体进程accesstoken_service的数据库文件SELinux类型为accesstoken_data_file。按业务安全需要，该数据库文件理论上只允许本进程读写，那么可以通过neverallow进行限制：
```text
neverallow { domain -accesstoken_service } accesstoken_data_file:file *;
```
表示不允许除了accesstoken_service以外的其他进程对accesstoken_data_file进行文件操作。
