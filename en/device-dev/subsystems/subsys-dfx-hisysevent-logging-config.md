# HiSysEvent Logging Configuration


## Overview


### Function Introduction

If HiSysEvent logging is required for a component, you need to define a YAML file and [configure the YAML file path](#verifying-the-yaml-file) in the **bundle.json** file. During compilation, the OpenHarmony compilation framework will use the Python compilation script to parse and verify all the YAML files configured in the **bundle.json** file. On completion, the compilation framework will summarize the configuration information in the YAML files and convert the information into a zip file named **hisysevent.zip**. After that, the compilation framework will put the zip file to a specified path as the basis for the system to determine whether to log system events.


### Basic Concepts

Understanding the following concepts would be helpful for you in configuring HiSysEvent logging.

- Event domain<br>Represents the domain to which an event belongs. It is specified by the **domain** field in the YAML file. For details, see [domain](#writing-a-yaml-file) in the example YAML file.

- Event name<br>Indicates the events in an event domain. For details, see [EVENT\_NAMEA/EVENT\_NAMEB](#writing-a-yaml-file) in the example YAML file.

- Parameter<br>Defines the key values in an event name. For details, see [__BASE/NAME1/NAME2](#writing-a-yaml-file) in the example YAML file.


### Constraints

Constraints on the event domain, event name, and parameter

- Each YAML file can contain only one event domain, and the domain name cannot be the same as that defined in other YAML files.

- Zero or more event names can be defined for one event domain. The event names in the same event domain must be unique.

- Multiple parameters can be defined for one event name. The parameters in the same event name must be unique. There must be only one parameter named **\__BASE** in each event name. See Table 1 for the fields of this parameter and Table 2 for the fields of other custom parameters.
    **Table 1** Fields in the \__BASE parameter
  
  | Field| Description|
  | -------- | -------- |
  | type | Event type. This field is mandatory.<br>Value:<br>- **FAULT**: fault<br>- STATISTIC: statistics<br>- **SECURITY**: security<br>- **BEHAVIOR**: behavior|
  | level | Event level. This field is mandatory.<br>Value:<br>- CRITICAL: critical<br>- MINOR: minor|
  | tag | Event tag. This field is mandatory.<br>Rule:<br>- You can define a maximum of five tags, separated with a space.<br>- A single tag can contain a maximum of 16 characters, including a to z, A to Z, and 0 to 9.|
  | desc | Event name. This field is mandatory.<br>Rule:<br>-  A string of 3 to 128 characters.|
  | preserve | Whether events need to be logged in the event file. This field is optional. The default value is **true**.<br>Value:<br>- **true**: Events need to be logged in the event file.<br>- **false**: Events do not need to be logged in the event file.|

    **Table 2** Description of custom parameters
  
  | Field| Description|
  | -------- | -------- |
  | type | Parameter type. This field is mandatory.<br>Value:<br>- BOOL<br>- INT8<br>- UINT8<br>- INT16<br>- UINT16<br>- INT32<br>- UINT32<br>- INT64<br>- UINT64<br>- FLOAT<br>- DOUBLE<br>- STRING |
  | arrsize | Length of the parameter of the array type. This field is optional.<br>Value:<br>1-100|
  | desc | Parameter description. This field is mandatory.<br>Rule:<br>-  A string of 3 to 128 characters.|


## How to Develop


### Writing a YAML File


**Writing Rules**

- Event domain naming rules:
  - The name must start with a letter and can contain only uppercase letters, digits, and underscores (&#95;).
  - The name contains 1 to 16 characters.

- Event naming rules:
  - The name must start with a letter and can contain only uppercase letters, digits, and underscores (&#95;).
  - The name contains 1 to 32 characters.
  - The number of internal event names in an event domain cannot exceed 4096.

- Parameter naming rules:
  - The name must start with a letter and can contain only uppercase letters, digits, and underscores (&#95;).
  - The name contains 1 to 48 characters.
  - The number of parameters in an event domain cannot exceed 128.


**Example**

- In the example YAML file, the event domain name is **MODULEA**. The event domain contains two events named **EVENT_NAMEA** and **EVENT_NAMEB**.

- **EVENT\_NAMEA** is defined as a critical event of the fault type. The event contains the **NAME1** parameter of the string type, the **NAME2** parameter of the string type, and the **NAME3** parameter of the unsigned short integer type. Therefore, you can perform [real-time subscription](../subsystems/subsys-dfx-hisysevent-listening.md) to the event based on the event domain **MODULEA** and event name **EVENT\_NAMEA**.

- **EVENT\_NAMEB** is defined as a general event of the statistics type. The event contains the **NAME1** parameter of the unsigned short integer type and the **NAME2** parameter of the integer type. Because two event tags named **tag1** and **tag2** are defined for **EVENT\_NAMEB** in the **\__BASE** parameter, you can perform [real-time subscription](../subsystems/subsys-dfx-hisysevent-listening.md) to the event based on the event domain **MODULEA** and event name **EVENT\_NAMEB**, or based on the event tag.
  
  ```
  ##########################################
  # the hisysevent definition for module a #
  ##########################################
  
  domain: MODULEA
  
  EVENT_NAMEA:
      __BASE: {type: FAULT, level: CRITICAL, desc: event name a}
      NAME1: {type: STRING, desc: name1}
      NAME2: {type: STRING, desc: name2}
      NAME3: {type: UINT16, desc: name3}
  
  EVENT_NAMEB:
      __BASE: {type: STATISTIC, level: MINOR, tag: tag1 tag2, desc: event name b}
      NAME1: {type: UINT16, desc: name1}
      NAME2: {type: INT32, desc: name2}
  ```


### Verifying the YAML File


**Configuring the YAML File Path**

In the **bundle.json** file, use the **hisysevent_config** attribute to specify the YAML file path.


```
{
    "name": "@ohos/moduel_a",
    "description": "module a",
    "version": "3.1",
    "license": "Apache License 2.0",
    "publishAs": "code-segment",
    "segment": {
        "destPath": "moduel_a_path"
    },
    "dirs": {},
    "scripts": {},
    "component": {
        "name": "hisysevent_native",
        "subsystem": "hiviewdfx",
        "adapted_system_type": [
            "standard"
        ],
        "rom": "",
        "ram": "",
        "hisysevent_config": [
            "//moduel_a_path/yaml_file1.yaml",
            "//moduel_a_path/yaml_file2.yaml"
        ],
        "deps": {
            "components": [
                "hilog_native",
                "hitrace_native",
                "ipc",
                "safwk",
                "samgr",
                "utils_base"
            ],
            "third_party": []
        },
        "build": {
        }
    }
}
```


> **NOTE**<br>
> The YAML file can be placed in any directory of the component project as needed. You only need to specify the path in the **bundle.json** file.


**Compiling YAML Files**

- Perform full compilation.
  - During full compilation of the system, the configurations in the YAML files of all components are summarized. After the compilation is complete, the **hisysevent.zip** file will be generated in the specified directory.
    
     ```
     cd *absolute path of the project's root directory*
     ./build --product-name <product name>
     ```

  - To obtain the **hisysevent.zip** file generated after full compilation, run the following commands:
    
     ```
     cd *absolute path of the project's root directory*
     find out -name hisysevent.zip -type f
     ```

- Single-file compilation:
  You can also compile the YAML file of a single component by running the following commands:

  
  ```
  cd absolute path of the project's root directory
  ./build/ohos/hisysevent/gen_def_from_all_yaml.py --yaml-list <yaml file list> --def-path <file store directory>
  ```

    **Table 3** Parameters for single-file compilation
  
  | Option| Description|
  | -------- | -------- |
  | --yaml-list | Paths of the YAML files to be compiled. If there are multiple YAML file paths, separate each of them with a space.|
  | --def-path | Path of the **hisysevent.zip** file generated after compilation.|


### Logging and Querying Events

1. Decompress the **hisysevent.zip** file to obtain the **hisysevent.def** file, and then use the [hdc_std tool](../subsystems/subsys-toolchain-hdc-guide.md) to push the file to the **/data/system/hiview/unzip_configs/sys_event_def/** directory of the device.

2. Trigger logging of the custom system events in the YAML file. Then, run [hisysevent -l](../subsystems/subsys-dfx-hisysevent-tool.md) to query historical system events to find out if the logging of the custom system events is successful.
