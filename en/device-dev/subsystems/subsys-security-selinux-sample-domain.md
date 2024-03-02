# Configuring an OpenHarmony SELinux Policy for a Process

## Native Process

**Scenario**

Configure a policy for a native process incubated by **init** or **chipset_init** through the configuration file, for example, **ueventd** and **installs**.

**Procedure**

1. In the configuration file of the process, add the **secon** field to configure the mapping between the process and the label. If the **secon** field is not configured, the process will be intercepted when SELinux is enabled.
    ```json
    {
        "services" : [{
                "name" : "demo",
                "path" : ["/system/bin/demo"],
                "uid" : "demo",
                "gid" : ["demo"],
                "secon" : "u:r:demo:s0"
            }
        ]
    }
    ```
2. In the **type.te** file, define the SELinux type **demo** in **SELinux tag u:r:demo:s0** to make **u:r:demo:s0** valid.

    If **demo** is incubated by **init**, set it as follows:
    ```text
    type demo, native_system_domain, domain;
    ```
    If **demo** is incubated by **chipset_init**, set it as follows:
    ```text
    type demo, native_chipset_domain, domain;
    ```

## SA Process

**Scenario**

Configure a policy for an SA process incubated by **init** through the configuration file, for example, **accountmgr** and **foundation**.

**Procedure**

1. In the configuration file of the process, add the **secon** field to configure the mapping between the process and the label. If the **secon** field is not configured, the process will be intercepted when SELinux is enabled.
    ```json
    {
        "services" : [{
                "name" : "demo",
                "path" : ["/system/bin/sa_main", "/system/profile/demo.json"],
                "uid" : "demo",
                "gid" : ["demo"],
                "secon" : "u:r:demo:s0"
            }
        ]
    }
    ```
2. In the **type.te** file, define the SELinux type **demo** in **SELinux tag u:r:demo:s0** to make **u:r:demo:s0** valid.
    ```text
    type demo, sadomain, domain;
    ```

## HDF Service Process

**Scenario**

Configure a policy for an HDF service process incubated by **init** or **chipset_init** through the configuration file, for example, **wifi_host** and **camera_host**.

**Procedure**

1. In the configuration file of the process, add the **secon** field to configure the mapping between the process and the label. If the **secon** field is not configured, the process will be intercepted when SELinux is enabled.
    ```json
    {
        "services" : [{
                "name" : "demo",
                "path" : ["/vendor/bin/hdf_devhost", "0", "demo"],
                "uid" : "demo",
                "gid" : ["demo"],
                "secon" : "u:r:demo:s0"
            }
        ]
    }
    ```

2. In the **type.te** file, define the SELinux type **demo** in **SELinux tag u:r:demo:s0** to make **u:r:demo:s0** valid.
    ```text
    type demo, hdfdomain, domain;
    ```

## Application Process

**Scenario**

Configure a policy for a system application process incubated by **appspawn**, for example, **com.ohos.permissionmanager**, to make it run with an independent label.

**Procedure**

1. In the **sehap_contexts** file, define the mappings between the application APL, bundle name and application process label, and data directory label. 
   
    For example, the application APL is **normal**, and the bundle name is **com.ohos.permissionmanager**. Then, the data directory label of the application is **u:object_r:permissionmanager_hap_data_file:s0**, and the process label of the application in running is **u:r:permissionmanager_hap:s0**.
    
    ```text
    apl=normal name=com.ohos.permissionmanager domain=permissionmanager_hap type=permissionmanager_hap_data_file
    ```
    For details about the APL, see [Application APL](../../application-dev/security/AccessToken/app-permission-mgmt-overview.md#application-apl).
    
2. Define **permissionmanager_hap** and **permissionmanager_hap_data_file** in **type.te** to make **u:r:permissionmanager_hap:s0** and **u:object_r:permissionmanager_hap_data_file:s0** valid.
    ```text
    type permissionmanager_hap, normal_hap_attr, hap_domain, domain;
    type permissionmanager_hap_data_file, normal_hap_data_file_attr, hap_file_attr, data_file_attr, file_attr;
    ```
    In this example, the application APL is **normal**. The following table lists the reference configuration for applications of different APLs.

    **Table 1** Mappings between APLs and application attributes
    | APL| Application Process Attribute| Application Data Directory Attribute|
    | -------- | -------- | -------- |
    | normal | normal_hap_attr | normal_hap_data_file_attr |
    | system_basic | system_basic_hap_attr | system_basic_hap_data_file_attr |
    | system_core | system_core_hap_attr | system_core_hap_data_file_attr |
