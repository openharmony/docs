# Configuring an OpenHarmony SELinux Policy for a Parameter

## Scenario

To implement access control for a system parameter, you can configure an SELinux label for the parameter. For details about the parameter definition, see [Parameter Management](subsys-boot-init-sysparam.md).

## Procedure

Define the mappings between parameters and labels in the **parameter_contexts** file. If a parameter name ends with a dot (.), the parameter is a wildcard parameter. Otherwise, the parameter is a fixed parameter.

The following is an example of the mapping between a label and a wildcard parameter. The label for parameters starting with **init.svc.** is **u:object_r:init_svc_param:s0**.
```text
init.svc. u:object_r:init_svc_param:s0
```
The following is an example of the mapping between a label and a fixed parameter. The label for the parameter **const.secure** is **u:object_r:secure_param:s0**.
```text
const.secure u:object_r:secure_param:s0
```

The wildcard parameters are labelled by the best match prefix. For example, the **paramter_contexts** file contains the following mappings:
```text
init. u:object_r:init_param:s0
init.svc. u:object_r:init_svc_param:s0
```
Then,
- The label of the **init.a** parameter is **u:object_r:init_param:s0**.
- The label of the **init.svc** parameter is **u:object_r:init_param:s0**.
- The label of the **init.svc.a** parameter is **u:object_r:init_svc_param:s0**.


For example, to assign the label **init_svc_param** for parameters prefixed with **init.svc.**, do as follows:

1. Add the parameter-label mapping in the **parameter_contexts** file.
    ```text
    init.svc. u:object_r:init_svc_param:s0
    ```

2. Add **init_svc_param** in **type.te** to make the label valid.
    ```text
    type init_svc_param, parameter_attr;
    ```
