# Component Building Specifications

## About This Document

### Purpose

Compilation and building is an important part for implementing the component-based design. A component in the compiled state should be maintainable, portable, and loosely coupled. This document provides guidelines for writing build scripts so that the components to build are configurable, reusable, and tailorable, with reasonable dependencies.

### Basic Concepts

**Component**

A component is a basic unit that constitutes OpenHarmony system capabilities. It contains the minimum required source code and has independent repositories and directories. It can be instantiated into different libraries or binary files on different devices.

**Feature**

Component features are configurable options in the build of a product. A component can be configured with different features to adapt to different product form factors. The configuration of component features affects only the implementations of component internal functions. It does not affect the public APIs (APIs provided by the component for applications) or inner APIs (APIs between components).

**Dependency**

A component in the compiled state has the following dependencies:

- Conditional dependency: The dependency can be tailored in specific scenarios, and the removal of the dependency does not affect the public or inner APIs of the component. For example, audio has conditional dependency on Bluetooth.
- Strong dependency: The dependency between components cannot be tailored. For example, the syscap component has strong dependency on the security library functions.

### General Principles

The compilation and building of components must comply with the following:

**Independent and Autonomous**

The component in the compiled state must be highly cohesive. Exercise caution when adding external dependencies, and minimize static dependencies in build.

**Reasonable Dependency**

Set up inter-component dependency based on the interfaces between components. Avoid the dependency on the modules or header files of other components.

**Product Independent**

The component in the compiled state should be applicable to multiple products. Do not use product names in build scripts.

### Conventions

**Rule**: a convention that must be complied with

**Suggestion**: a convention that must be taken into consideration

### Guarding Method

The gated check-in conducts the following checks on the build configuration files:

Prebuild check: The files are checked in the prebuild phase. If an error is detected, the build stops.

Static check: The check tool scans and checks configuration files for errors.

### Exception

An exception is allowed only with sufficient reasons as long as the general principles are not violated.

However, exceptions compromise code consistency and should be avoided as far as possible. Exceptions to the "rules" should be rare.

## Naming

The names of variables and build targets in build scripts, templates, gni files, and objects and data in component description files must be in the kernel style (unix_like). That is, the words are in lowercase and separated by underscores (_). For example, **startup_init**.

### Rule 1.1 Use consistent format for component names.
- The component name must reflect the functions of the component.
- The component name must be globally unique in the system.
- The component name cannot exceed 63 valid characters.
- The component name consists of lowercase letters and underscores (_), for example, **unix_like**.

> **Exception**: Third-party open-source software can use the native naming format, for example, **cJson**.

### Rule 1.2 Name features in the *component name*_*feature name* format.

A feature is a configurable option declared by a component. Adding a component name prefix can prevent duplicate feature names. 

Example:

```py
declare_args() {
  dsoftbus_conn_p2p = true # dsoftbus is the component name, and conn_p2p is the feature name.
  dsoftbus_conn_ble = false # dsoftbus is the component name, and conn_ble is the feature name.
}
```

Guarding method: prebuild check

### Suggestion 1.1: Name build targets in the *component name*_*module name* format.

A component may have multiple build targets (modules). The component and module names help you quickly locate the component based on the output (library or executable file) and prevents duplicate names.

Example:
```py
ohos_shared_library("data") # Inaccurate, too general, and easy to duplicate
```
Example: 
```py
ohos_shared_library("cellular_data_napi") # Good example
```

## Description File

The **bundle.json** file defines a component. It contains information, such as the root directory, name, function description, version number, interface definition, and build entry of a component. The information in **bundle.json** file must be correct.

### Rule 2.1 Ensure correct component information in the file.

| Field| Type| Mandatory| Description| Guarding Method|
|---|---|---|---|---|
|name|String|Yes|OpenHarmony package manager (HPM) package name of the component.<br>Naming rule: @{organization}/{component_name}<br>{component_name} must comply with **Rule 1.1**.|Static check|
|version|String|Yes|Component version number, which must be consistent with that of OpenHarmony.|Static check|
|destPath|String|Yes|Root directory of the component source code.<br>The root directory of each component must be unique.|Static check|
|component:name|String|Yes|Component name, which must comply with **Rule 1.1**.|Static check|
|component:subsystem|String|Yes|Subsystem to which the component belongs. The subsystem name consists of lowercase letters and cannot contain underscores (_).|Static check|
|component:syscap|String list|No|System capabilities.<br>Naming rule: **SystemCapability**.*Subsystem*.*Component capability*.*Sub-capability* (optional) in upper camel case<br/>Example: **SystemCapability.Media.Camera,SystemCapability.Media.Camera.Front**|Static check|
|component:features|String list|No|Features that can be configured for the component. The feature names must comply with **Rule 1.2**.|Static check|
|component:adapted_system_type|String list|Yes|Type of the system to which the component applies. The value can be **mini**, **small**, **standard**,or their combination.|Static check|
|component:rom|String|Yes|ROM size, in KB.|Static check|
|component:ram|String|Yes|RAM size, in KB.|Static check|
|component:deps|String list|Yes|Dependencies of the component, including other components and third-party open-source software. The dependencies must be the same as that in the component build script.|Prebuild check|


### Suggestion 2.1 Place the component description file in the root directory of the component.

The component directory is independent. Place the **bundle.json** file in the root directory of the component.

## Variables

The built-in variable values of the build target determine the content to compile, dependencies, and data to package.

### Rule 3.1 Do not include the absolute or relative paths of other components in the build script of a component.

Use **external_deps** to include the dependency between components. The variables **sources**, **include_dirs**, **configs**, **public_configs**, **deps**, and **public_deps** of the component build target cannot reference the relative or absolute paths of other components.

- sources

  **Sources** can contain only the source code of a component. If **sources** contain the source code of other components, the independence of the component's source code directories will be violated.

- include_dirs

  **include_dirs** can contain only the header file paths of a component. The dependencies on other components are automatically imported through **external_deps**.

- configs

  **configs** can reference only the configuration paths of a component. Referencing the **configs** of other components may cause interface dependency.

- pulic_configs

  **public_configs** can reference only the configuration paths of a component. Referencing the **configs** of other components may cause interface dependency.

- deps

  **deps** can contain only dependencies between the modules in a component. Referencing a module in another component may cause dependency on the module and interfaces of the referenced component.

  Example:

  base/foos/foo_a/BUILD.gn

  ```py
  deps = [ "//base/foo/foo_b:b" ] # Not recommended. deps contains the absolute path of another component.
  deps = [ "../../foo_b:b" ] # Not recommended. deps contains the relative path of another component.
  deps = [ "a" ] # Recommended.
  ```

  > **Exception**: References to third-party open-source software are allowed.

- public_deps

  **Public_deps** can contain only dependencies between the modules in a component. Referencing a module in another component may cause dependency on the module and interfaces of the referenced component.

  > **Exception**: References to third-party open-source software are allowed.
  

Guarding method: static check

### Rule 3.2 The component name and subsystem name must be specified for the component build target.

**part_name** and **subsystem_name** are mandatory for **ohos_shared_library**, **ohos_static_library**, **ohos_executable_library**, and **ohos_source_set** of a component. 

The following uses **ohos_shared_library** in **developtools/syscap_codec/BUILD.gn** as an example.

```py
ohos_shared_library("syscap_interface_shared") {
  include_dirs = [
    "include",
    "src",
  ]
  public_configs = [ ":syscap_interface_public_config" ]
  sources = [
    "./interfaces/inner_api/syscap_interface.c",
    "./src/endian_internal.c",
    "./src/syscap_tool.c",
  ]
  deps = [
    "//third_party/bounds_checking_function:libsec_static",
    "//third_party/cJSON:cjson_static",
  ]

  subsystem_name = "developtools" # subsystem_name is mandatory.
  part_name = "syscap_codec" # part_name is mandatory.
}
```

Guarding method: static check

### Suggestion 3.1 Use relative paths for internal references of a component.

Using relative paths for references within a component can:

- Make the script simpler.

- Decouple the build script of a component from the root directory of the component.

Example:

base/foos/foo_a/BUILD.gn

```py
include_dirs = [
    "./include", # Recommended.
    "//base/foo/foo_a/include" # Not recommended.
]

deps = [
    "sub_module:foo", # Recommended.
    "base/foo/foo_a/sub_module:foo" # Not recommended.
]
```

Guarding method: static check

### Suggestion 3.2 Make the internal modules of a component only visible to the component.

Set **visibility** for the internal modules of a component to prevent them from being dependencies of other components. 

Example:

base/foos/foo_a/BUILD.gn

```py
ohos_shared_library("foo_a") {
    visibility = [ "./*" ] # foo_a is visible only to base/foo/foo_a and its subdirectories.
}

ohos_shared_library("foo_a") {
    visibility = [ ":*" ] # foo_a is visible only to this BUILD.gn.
}
```

## Others

### Rule 4.1 Do not use the product name variable in the component build script.

A component is a common system capability and is irrelevant to a specific product. If the product name is used in the build script, the component functions are bound to the product, which violates the commonality of the component. Abstract the differences between components in different product forms as features or runtime plug-ins.

> **Exception**: The build scripts of third-party components in the **vendor** and **device** directories are excluded.

Guarding method: static check

### Suggestion 4.1 Do not import .gni files in directories of other components.

The **.gni** file declares the internal build variables and templates of the component. Importing the **.gni** file of another component means to use the internal variables and templates of another component, which introduces the dependency on that component. The variables, args, and templates that affect multiple components should be defined in the **.gni** file of the build framework.

> **Exception**: The **.gni** file (containing global build options) of the build framework in the **build** directory can be imported by all components.

Guarding method: static check

### Suggestion 4.2 Use a unified template for component build units.

Use **ohos_** templates, such as **ohos_shared_library**, **ohos_static_library**, **ohos_executable**, and **ohos_source_set**, for the build units of mini, small, and standard systems.

Example:

```py
  executable ("foundation") {# The built-in template is not recommended.
    ...
  }

  ohos_executable("foundation") {# The ohos template is recommended.
    ...
  }
```
