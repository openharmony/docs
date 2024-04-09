# Configuring an OpenHarmony SELinux Policy for an SA or HDF Service

## SA

**Scenario**

After a process registers an SA with Samgr, other processes need to obtain the SA before starting IPC with the process. If the SA provider does not assign an SELinux label for the SA, SELinux will assign the **u:object_r:default_service:s0** label to the SA. The access to default_service will be denied by the **neverallow** rule.

**Procedure**

1. In the **service_contexts** file, add the mapping between the SAID and the SA label.
    ```text
    10      u:object_r:sa_render_service:s0
    ```

2. In the **type.te** file, add the type, for example, **isa_render_service**, to make the label valid.
    ```text
    type sa_render_service, sa_service_attr
    ```

## HDF Service

**Scenario**

After a process registers an HDF service with hdf_devmgr, other processes need to obtain the HDF service before starting IPC with the process. If the HDF provider does not assign an SELinux label for the HDF service, SELinux will assign the **u:object_r:hdf_default_service:s0** label for the HDF service. The access to hdf_default_service will be denied by the **neverallow** rule.


**Procedure**

1. In the **service_contexts** file, add the mapping between the HDF service name and the HDF label.
    ```text
    thermal_interface_service  u:object_r:hdf_thermal_interface_service:s0
    ```

2. In the **type.te** file, add the type, for example, **hdf_thermal_interface_service**, to make the label valid.
    ```text
    type hdf_thermal_interface_service, hdf_service_attr
    ```
