# Configuring an OpenHarmony SELinux Policy for a File

## File in a Read-Only Partition

**Scenario**

In OpenHarmony, some image files, such as **system.img** and **vendor.img**, are mounted as read-only to prevent them from being corrupted. Generally, these files are assigned with an SELinux label in the compilation process.

**Procedure**
1. In **file_contexts**, define the mapping between the absolute path of the file and the label. Regular expressions can be used.
    ```text
    /system/lib(/.*)?    u:object_r:system_lib_file:s0
    ```
2. Define **system_lib_file** in **type.te** to make **u:object_r:system_lib_file:s0** valid.
    ```text
    type system_lib_file, system_file_attr, file_attr;
    ```

## File in a Read/Write Partition

**Scenario**

The read/write partitions in OpenHarmony store the files generated dynamically and accessed by applications. For example, the **/data** directory holds user data and data generated and accessed by applications. By default, these files inherit the label of their parent directory. For security purposes, you can configure a label after the file is generated.


**Procedure**
1. In **file_contexts**, define the mapping between the absolute path of the file and the label. Regular expressions can be used.
    ```text
    /data/service/el0(/.*)?    u:object_r:data_service_el0_file:s0
    ```
    
2. Define **data_service_el0_file** in **type.te** to make **u:object_r:data_service_el0_file:s0** valid.
    ```text
    type data_service_el0_file, file_attr, data_file_attr;
    ```
    
  3. Make the label take effect. 
      
      The **file_contexts** file only defines the mapping between the file path and the label. The label cannot be automatically assigned to the file. The process needs to proactively trigger the label update. The label update operation varies depending on how the file is generated.
      
      | Scenario| Label Update|
      | -------- | -------- |
| The directory or file is created by **mkdir** in the .cfg file after the process is started by **init** from .cfg.| The **init** used to parse the **mkdir** command in the .cfg file has integrated the **Restorecon** API. Therefore, **mkdir** updates the file label.|
      | The directory or file is created by **mkdir** in the .cfg file during the startup process.| The **init** used to parse the **mkdir** command in the .cfg file has integrated the **Restorecon** API. Therefore, **mkdir** updates the file label.|
      | The directory or file is created by a process in running.| Use **Restorecon** to update the label after the directory or file is created.|
      
      For details about the APIs, see [OpenHarmony SELinux APIs](subsys-security-selinux-func.md).

## File in a Virtual File System

**Scenario**

For the files in a virtual file system, for example, the files in **/proc** and **/sys**, you can configure labels in the **virtfs_contexts** file.


**Procedure**
1. In **virtfs_contexts**, configure the file-label mapping using the **genfscon** syntax.
    ```text
    genfscon  proc /iomem  u:object_r:proc_iomem_file:s0
    ```
2. Define **proc_iomem_file** in **type.te** to make **u:object_r:proc_iomem_file:s0** valid.
    ```text
    type proc_iomem_file, fs_attr, proc_attr;
    ```
