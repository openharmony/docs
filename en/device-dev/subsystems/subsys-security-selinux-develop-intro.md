# OpenHarmony SELinux Development

## Policy Directory Structure

The OpenHarmony SELinux policy files are located in the **//base/security/selinux_adapter/sepolicy/ohos_policy** directory. The directory structure is as follows:
```text
├── Subsystem
│   └── Component
│       ├── public
│       │   └── type1.te
│       ├── vendor
│       │   └── type2.te
│       └── system
│           └── type3.te
```
The system-related policy files are located in the **system** directory, the chipset-related policy files are located in the **vendor** directory, and the policy files for both the system and chipsets are located in the **public** directory.

## Universal Policy and Context Files

The universal policy and context files contain SELinux policies to be configured during the development.

| File Name| Description|
| -------- | -------- |
| *.te | SELinux policy source file, which defines the types and **allow** and **neverallow** rules.|
| file_contexts | Defines the mappings between the paths of physical files and labels (contexts).|
| virtfs_contexts | Defines the mappings between the paths of virtual files and labels.|
| sehap_contexts | Defines the mappings between key application information, labels of application processes, and labels of application data directories.|
| parameter_contexts | Defines the mappings between parameters and labels.|
| sevice_contexts | Defines the mappings between SAs and labels.|
| hdf_service_contexts | Defines the mappings between HDF services and labels.|

## SELinux Framework Policy Files

The following table lists the SELinux framework policy files, which should not be modified generally.

| File Name| Description|
| -------- | -------- |
| security_classes | Defines the classes.|
| initial_sids | Defines the SIDs.|
| access_vectors | Defines the permissions supported by classes.|
| glb_perm_def.spt | Defines the global macros for classes and permissions. Global macros help simplify policy statements.|
| glb_never_def.spt | Defines global macros for **neverallow** rules.|
| mls | Defines the multi-level security (MLS) levels.|
| glb_te_def.spt | Defines global macros for TE rules.|
| attributes | Defines universal sets of attributes (access control rules). When defining a policy type, you can specify attributes. Then, the policy type inherits the permissions of the attributes.|
| glb_roles.spt | Defines roles.|
| users | Defines users.|
| initial_sid_contexts | Defines the initial SID contexts.|
| fs_use | Defines the default labels for different file systems.|

## AVC Log Information

When a system behavior is denied by SELinux, a log in the following format will be generated in the kernel log and hilog.
```text
audit: type=1400 audit(1502458430.566:4): avc:  denied  { open } for  pid=1658 comm="setenforce" path="/sys/fs/selinux/enforce" dev="selinuxfs" ino=4 scontext=u:r:hdcd:s0 tcontext=u:object_r:selinuxfs:s0 tclass=file permissive=1
```

In the log:
  - **open** indicates the operation denied.
  - **pid=1658** indicates that the PID of the subject process is **1658**.
  - **comm="setenforce"** indicates that the subject process is **setenforce**.
  - **path="/sys/fs/selinux/enforce"** indicates that the object to be accessed is **/sys/fs/selinux/enforce**.
  - **dev="selinuxfs"** indicates that the object belongs to the SELinux filesystem (selinuxfs).
  - **ino=4** indicates that the file node ID is **4**.
  - **scontext=u:r:hdcd:s0** indicates that the SELinux label of the subject is **u:r:hdcd:s0**.
  - **tcontext=u:object_r:selinuxfs:s0** indicating that the SELinux label of the object is **u:object_r:selinuxfs:s0**.
  - **tclass=file** indicates the type of the object to be accessed by the subject.
  - **permissive=1** indicates that SELinux runs in permissive mode, where violations are logged but allowed. If **permissive** is set to **0**, SELinux runs in enforcing mode, where violations are denied and logged.

You can use the keyword "avc denied" to search for access denial logs, and configure SELinux policies based on the AVC alarms that affect services. For example, if the log information is as follows:
```text
audit: type=1400 audit(1502458430.566:4): avc:  denied  { open } for  pid=1658 comm="setenforce" path="/sys/fs/selinux/enforce" dev="selinuxfs" ino=4 scontext=u:r:hdcd:s0 tcontext=u:object_r:selinuxfs:s0 tclass=file permissive=1
```

Write the TE rule as follows:
```text
allow hdcd selinuxfs:file open;
```

## Policy Format

An SELinux policy, also called an SELinux rule, usually starts with **allow** or **neverallow** to define a behavior allowed or prohibited. If SELinux is enabled on a device, SELinux denies all behaviors that are not allowed. You can configure **allow** rules to allow behaviors and **neverallow** rules to prohibit risky behaviors. The following is an example of an **allow** rule:
```text
allow subject object:class permissions;
```
  This rule allows the subject to perform the **permissions** operation on the class of the object. In the rule:
  - **subject** indicates the subject, which is usually the SELinux type of the process, for example, **init**.
  - **object** indicates the object, which is usually the SELinux type of a system resource, for example, **data_file**.
  - **class** indicates the type of the object to access. For example, **file** indicates a file, **dir** indicates a directory, and **socket** indicates a socket.
  - **permissions** indicates the specific operation to perform, for example, to open, read, or write a file.

Likewise:
```text
neverallow subject object:class permissions;
```
This rule prohibits the subject from performing the **permissions** operation on the class of the object.

## Policy Macros

To facilitate your app experience without compromising device security, OpenHarmony SELinux provides macros to apply security policies on different versions. You can use the macro **debug_only** to apply the policies customized for the root version for debugging. To enable this macro, specify **--build-variant root** in the version build command. In the user version for commercial release, specify **--build-variant user** in the version build command to disable this macro. To use this macro, do as follows:
```text
debug_only(`
    allow ueventd init:fd use;
')
```

In addition, you can use the **developer_only** macro to apply the policies customized for the developer mode. These policies are used for debugging of the user version. This macro is enabled by default. To use the **developer_only** macro, do as follows:
```text
developer_only(`
    allow sh init:fd use;
')
```

| Macro| Root Version| Root Version Developer Mode| User Version| User Version Developer Mode|
| -------- | -------- | -------- | -------- | -------- |
| Other policies| Valid| Valid| Valid| Valid|
| Policies controlled by **debug_only**| Valid|Valid| Invalid| Invalid|
| Policies controlled by **developer_only**| Invalid| Valid| Invalid| Valid|
