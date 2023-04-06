# Feature
### Configuration Rules

This document describes how to declare, define, and use features.

- Declare a feature

  Declare the features of a component in **feature_list** of the **bundle.json** file of the component. Each feature must start with the **{component_name}**. 

  The following is an example:

  ```
  {
    "name": "@ohos/xxx",
    "component": {
      "name": "partName",
      "subsystem": "subsystemName",
      "features": [
        "{partName}_feature_A"
      ]
    }
  }
  ```

   You can declare multiple features in **features** for a component.

- Define a feature

  You can define the default value of a feature as follows:

  ```
  declare_args() {
    {partName}_feature_A = true
  }
  ```

  The value defined is the default value of the feature for this component. The product can overload the feature default values in the component list.

  If a feature is used by multiple modules of a component, you are advised to define the feature in the global .gni file of the component and import the .gni file to the **BUILD.gn** file of each module.

- Use a feature

  In the **BUILD.gn** file, determine the code or modules to build based on features.

  ```
  if ({partName}_feature_A) {
      sources += [ "xxx.c" ]
  }
  
  # Dependency introduced by a feature can be isolated by feature.
  if ({partName}_feature_A) {
      deps += [ "xxx" ]
      external_deps += [ "xxx" ]
  }
  
  # The **bundle.json** file does not support the if statement. If the sub_component contained in the **bundle.json** file needs to be deleted, define group().
  group("testGroup") {
    deps = []
    if ({partName}_feature_A) {
      deps += [ "xxx" ]
    }
  }
  ```

  You can also define code macros for modules in the following way to implement differentiated configuration:

  ```
  if ({partName}_feature_A) {
      defines += ["FEATUREA_DEFINE"]
  }
  ```
