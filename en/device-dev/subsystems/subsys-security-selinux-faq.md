# OpenHarmony SELinux FAQs

## Error "neverallow check failed"
**Symptom**

"neverallow check failed" is reported during the SELinux compilation process.

```
neverallow check failed at obj/base/security/selinux_adapter/updater/system.cil:3887 from ../../base/security/selinux_adapter/sepolicy/base/public/domain.te:96
  (neverallow domain dev_parameters_file (file (write)))
    <root>
    allow at obj/base/security/selinux_adapter/updater/system.cil:14124
      (allow init dev_parameters_file (file (write create relabelfrom relabelto)))
```

**Possible Causes**

The rule configured violates the existing **neverallow** rules.

**Solution**

Check and modify the rule to avoid **neverallow** violation. If the rule must be configured based on service requirements, exempt the SELinux type of the rule in the **neverallow** rule. 

Example:

Rule violating **neverallow**:

```text
allow init dev_parameters_file:file { write };
```

Modify:

```text
neverallow domain dev_parameters_file:file
```

To:

```text
neverallow { domain -init } dev_parameters_file:file write;
```

## Error "unrecognized character"

**Symptom**

"unrecognized character" is reported during the SELinux compilation process.

```
' on line 3350:rity/selinux_adapter/sepolicy/base/public/domain.te:16:ERROR 'unrecognized character' at token '
allow domain init:process sigchld;
```

**Possible Causes**

The policy file is in DOS format.

**Solution**

Run the **dos2unix** command to convert the file into the correct format.
```text
dos2unix ./sepolicy/base/public/domain.te
```

## Error "unknown type" 
**Symptom**

 "unknown type" is reported during the SELinux compilation process.
```
../../base/security/selinux_adapter/sepolicy/ohos_policy/security/access_token/vendor/access_token.te:2:ERROR 'unknown type accesstoken_data_file' at token ';' on line 10334:
allow accesstoken_service accesstoken_data_file:dir { search add_name open read write remove_name };
#line 1 "../../base/security/selinux_adapter/sepolicy/ohos_policy/security/access_token/vendor/access_token.te"
checkpolicy:  error(s) encountered while parsing configuration
```

**Possible Causes**

1. The SELinux type is not defined.
2. The SELinux type is invisible when the current rule is complied. For example, an SELinux type defined for a directory in **/system** is used by a directory in **/vendor**. When the chipset-related rules (in **/vendor**) are complied, only the rules in the **/vendor** and **/public** directories are traversed. Because the SELinux type is defined for a directory in the **/system** directory, "unknown type" is reported.

**Solution**

1. Check whether the SELinux type is defined. If not, define **type** in the following format:

```text
type init, xxx
```

2. Check whether the SELinux type is invisible to the rule compiled. If yes, move the SELinux type to a directory visible to the rule. You are advised to define the SELinux types in a file named **type.te** in the **/public** directory.