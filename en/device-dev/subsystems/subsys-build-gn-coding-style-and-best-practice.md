# Build System Coding Specifications and Best Practices

## Overview

Generate Ninja (GN) a meta-build system that generates build files for Ninja, which allows you to build your OpenHarmony projects with Ninja.

### Introduction to GN

- GN is currently used in several popular systems, including Chromium, Fuchsia, and OpenHarmony.
- The GN syntax has limitations rooted in its design philosophy. For example, there is no way to get the length of a list and wildcards are not supported. To learn about the GN design philosophy, see https://gn.googlesource.com/gn/+/main/docs/language.md#Design-philosophy. Therefore, if you find that it is complex to implement something using GN, look it over and think about whether it is really necessary.
- For details about GN, see the official GN document at https://gn.googlesource.com/gn/+/main/docs/.

### Intended Audience and Scope

This document is intended for OpenHarmony developers. Its focus is on the GN coding style and issues that may occur during the use of GN. The GN syntax is not covered here. For details about the basics of GN, see the GN reference document at https://gn.googlesource.com/gn/+/main/docs/reference.md.

### General Principles

On the premise that functions are available, scripts must be easy to read, easy to maintain, and exhibit good scalability and performance.

## Coding Style

### Naming

In general cases, the naming follows the Linux kernel coding style, that is, **lowercase letters+underscore**.

#### Local Variables

For the purpose of this document, a local variable refers to a variable that is restricted to use in a certain scope and not passed down.

To better distinguish local variables from global variables, local variables start with an underscore (**_**).

```
# Example 1
action("some_action") {
  ...
  # _output is a local variable. Hence, it starts with an underscore (_).
  _output = "${target_out_dir}/${target_name}.out"
  outputs = [ _output ]
  args = [
    ...
  	"--output",
  	rebase_path(_output, root_build_dir),
  	...
  ]
  ...
}
```

#### Global Variables

A global variable starts with a **lowercase letter**.

If you want a variable value to be modified by **gn args**, use **declare\_args**. Otherwise, do not use **declare\_args**.

```
# Example 2
declare_args() {
  # You can use gn args to change the value of some_feature.
  some_feature = false
}
```

#### Targets

The target is named in the format of **lowercase letters+underscore**.

A subtarget in the template is named in the ${*target\_name*}\__*suffix* format. This naming convention has the following advantages:

- The ${*target\_name*} part can prevent duplicate subtarget names.

- The double underscores (\__) can help identify the module to which the subtarget belongs, thereby facilitating fault locating.

  ```
  # Example 3
  template("ohos_shared_library") {
    # "{target_name}" (primary target name) + "__" (double underscores) + "notice" (suffix)
    _notice_target = "${target_name}__notice"
    collect_notice(_notice_target) {
      ...
    }
    shared_library(target_name) {
      ...
    }
  }
  ```

#### Custom Templates

Whenever possible, **use verbs** for template names.

```
# Example 4
# Good
template("compile_resources") {
  ...
}
```

### Formatting

To maintain consistency in styles such as code alignment and line feed, a GN script needs to be formatted before being submitted. Use the format tool provided by GN to format your script. The command is as follows:

```shell
$ gn format path-to-BUILD.gn
```

**gn format** sorts imports in alphabetical order. To maintain the original sequence, you can add an empty comment line.

Assume that the original import sequence is as follows:

```
# Example 5
import("//b.gni")
import("//a.gni")
```

After the format command is executed, the import sequence is changed as follows:

```
import("//a.gni")
import("//b.gni")
```

To maintain the original import sequence, add an empty comment line.

```
import("//b.gni")
# Comment to maintain the original import sequence.
import("//a.gni")
```

## Coding Practice

### Principles of Practice

The build script completes the following two tasks:

1. **Describe the dependency between modules (deps).**

   In practice, the most frequent problem is **lack of dependency**.

2. **Describe the module compilation rules (rule).**

   In practice, common problems are **unclear input** and **unclear output**.

Lack of dependency can result in the following:

- **Possible compilation error**

  ```
  # Example 6
  # The compilation is prone to errors as a result of lack of dependency.
  shared_library("a") {
    ...
  }
  shared_library("b") {
    ...
    ldflags = [ "-la" ]
    deps = []
    ...
  }
  group("images") {
    deps = [ ":b" ]
  }
  ```

  In the preceding example, **liba.so** is linked to **libb.so** when being linked. This means that **b** depends on **a**. However, the dependency list (**deps**) of **b** does not declare its dependency on **a**. As compilation is performed concurrently, a compilation error will occur if compilation of **liba.so** is not yet complete when **libb.so** is being linked.

  From this example we can see that lack of dependency does not necessarily lead to a compilation error. It poses a possibility of errors.

- **Missing involvement of dependent modules**

  In the preceding example, because **images** depends on **b** only, **a** does not participate in the compilation of **images** using Ninja. However, as **b** depends on **a**, an error occurs when **b** is linked.

One less common problem is **too many dependencies**. **Too many dependencies can reduce concurrency and slow down compilation**.

In the example below, adding the unwanted **_compile\_resource\_target** dependency to **_compile\_js_target** means that **_compile\_js_target** can be compiled only after compilation of **_compile\_resource\_target** is complete.

```
# Example 7
# Too many dependencies slow down compilation.
template("too_much_deps") {
  ...
  _gen_resource_target = "${target_name}__res"
  action(_gen_resource_target) {
    ...
  }
  
  _compile_resouce_target = "${target_name}__compile_res"
  action(_compile_resource_target) {
    deps = [":$_gen_resource_target"]
    ...
  }
  
  _compile_js_target = "${target_name}__js"
  action(_compile_js_target) {
    # This deps is not required.
    deps = [":$_compile_resource_target"]
  }
}
```

Unclear input can result in the following:

- **Modified code is not compiled during the incremental compilation.**
- **After code changes, the cache being used is still hit.**

In the following example, **foo.py** references functions in **bar.py**. This means that **bar.py** is the input of **foo.py** and must be added to the **input** or **depfile** of **implict_input_action**. Otherwise, if **bar.py** is modified, the **implict_input_action** module will not be recompiled.

```
# Example 8
action("implict_input_action") {
  script = "//path-to-foo.py"
  ...
}
```

```
#!/usr/bin/env
# Contents of foo.py
import bar
...
bar.some_function()
...
```

Unclear output can result in the following:

- **The output is implicit.**
- **When the cache is used, implicit output cannot be obtained from the cache.**

In the following example, **foo.py** generates two files: **a.out** and **b.out**; the output of **implict_output_action** declares only **a.out**. In this case, **b.out** is an implicit output, and the cache stores **a.out** but not **b.out**. When the cache is hit, **b.out** cannot be compiled.

```
# Example 9
action("implict_output_action") {
  outputs = ["${target_out_dir}/a.out"]
  script = "//path-to-foo.py"
  ...
}
```

```
#!/usr/bin/env
# Contents of foo.py
...
write_file("b.out")
write_file("a.out")
...
```

### Templates

**Do not use the GN native templates. Use the templates provided by the compilation system.**

The GN native templates are **source_set**, **shared_library**, **static_library**, **action**, **executable**, and **group**.

These native templates are discouraged due to the following reasons:

- **The native templates only provide minimum functions**. They do not provide extra functions such as external_deps parsing, notice collection, and installation information generation. These extra functions are generated during module compilation. Therefore, the native templates must be extended.

- When the file on which the input file depends changes, the native template **action** cannot automatically detect the change and cannot be recompiled. See Example 8.
  
  
  
  Mapping between native templates and templates provided by the compilation system:
  
  | Template Provided by the Compilation System | Native Template |
  | :------------------------------------------ | --------------- |
  | ohos_shared_library                         | shared_library  |
  | ohos_source_set                             | source_set      |
  | ohos_executable                             | executable      |
  | ohos_static_library                         | static_library  |
  | action_with_pydeps                          | action          |
  | ohos_group                                  | group           |
  

### Using Python Scripts

Prioritize the Python script over the shell script in **action**. The Python script has the following advantages over the shell script:

- More user-friendly syntax: It will not generate strange errors just because a space is missing.
- More readable.
- Higher maintainability and debugability.
- Faster compilation: thanks to Python task caching by OpenHarmony.

### rebase_path

- Call **rebase_path** only in the **args** list of **action**.

  ```
  # Example 10
  template("foo") {
    action(target_name) {
      ...
      args = [
        # Call rebase_path only in args.
        "--bar=" + rebase_path(invoker.bar, root_build_dir),
        ...
      ]
      ...
    }
  }
  
  foo("good") {
    bar = something
    ...
  }
  ```

- If **rebase_path** is executed twice for the same variable, unexpected results may occur.

  ```
  # Example 11
  template("foo") {
    action(target_name) {
      ...
      args = [
        # rebase_path is executed twice for bar, and the passed bar value is incorrect.
        "--bar=" + rebase_path(invoker.bar, root_build_dir),
        ...
      ]
      ...
    }
  }
  
  foo("bad") {
    # Do not call rebase_path here.
    bar = rebase_path(some_value, root_build_dir)
    ...
  }
  ```

### Sharing Data Between Modules

Data sharing between modules is common. For example, a module may want to know the **outputs** and **deps** of another module.

- Data sharing within the same **BUILD.gn** file

  Data in the same **BUILD.gn** file can be shared by defining global variables.

  In the following example, the output of module **a** is the input of module **b**. Module **a** shares data with module **b** by defining global variables.

  ```
  # Example 12
  _output_a = get_label_info(":a", "out_dir") + "/a.out"
  action("a") {
    outputs = _output_a
    ...
  }
  action("b") {
    inputs = [_output_a]
    ...
  }
  ```

- Data sharing between different **BUILD.gn** files

  The best way to share data between different **BUILD.gn** files is to save the data as files and then transfer the files between modules. This scenario is complex. For details, see **write_meta_data** in the OpenHarmony HAP compilation process.

### forward_variable_from

- To customize a template, you need to forward **testonly** first, since the target of the template may be depended on by that of **testonly**.

  ```
  # Example 13
  # Forward testonly for a custom template.
  template("foo") {
    forward_variable_from(invoker, ["testonly"])
    ...
  }
  ```

- Do not use asterisks (*) to forward variables. Required variables should be explicitly forwarded one by one.

  ```
  # Example 14
  # Bad. The asterisk (*) is used to forward the variable.
  template("foo") {
    forward_variable_from(invoker, "*")
    ...
  }
  
  # Good. Variables are explicitly forward one by one.
  template("bar") {
    # 
    forward_variable_from(invoker, [
    								   "testonly",
    								   "deps",
    								   ...
    								 ])
    ...
  }
  ```

### target_name

The value of **target_name** varies according to the scope.

```
# Example 15
# The value of target_name varies according to the scope.
template("foo") {
  # The displayed target_name is "${target_name}".
  print(target_name)
  _code_gen_target = "${target_name}__gen"
  code_gen(_code_gen_target) {
    # The displayed target_name is "${target_name}__gen".
    print(target_name)
    ...
  }
  _compile_gen_target = "${target_name}__compile"
  compile(_compile_gen_target) {
    # The displayed target_name is "${target_name}__compile".
    print(target_name)
    ...
  }
  ...
}
```

### public_configs

To export header files from a module, use **public_configs**.

```
# Example 16
# b depends on a and inherits the headers of a.
config("headers") {
  include_dirs = ["//path-to-headers"]
  ...
}
shared_library("a") {
  public_configs = [":headers"]
  ...
}
executable("b") {
  deps = [":a"]
  ...
}
```

### template

A custom template must contain a subtarget named *target_name*. This subtarget is used as the main target of the template. It should depend on other subtargets so that the subtargets can be compiled.

```
# Example 17
# A custom template must contain a subtarget named target_name.
template("foo") {
  _code_gen_target = "${target_name}__gen"
  code_gen(_code_gen_target) {
    ...
  }
  _compile_gen_target = "${target_name}__compile"
  compile(_compile_gen_target) {
    # The displayed target_name is "${target_name}__compile".
    print(target_name)
    ...
  }
  ...
  group(target_name) {
    deps = [
    # Since _compile_gen_target depends on _code_gen_target, the main target only needs to depend on _compile_gen_target.
      ":$_compile_gen_target"
    ]
  }
}
```

### set_source_assignment_filter

In addition to filtering **sources**, **set_source_assignment_filter** can also be used to filter other variables. After the filtering is complete, clear the filter and **sources** list.

```
# Example 18
# Use set_source_assignment_filter to filter dependencies and add the dependencies whose label matches *:*_res to the dependency list.
_deps = []
foreach(_possible_dep, invoker.deps) {
  set_source_assignment_filter(["*:*_res"])
  _label = get_label_info(_possible_dep, "label_no_toolchain")
  sources = []
  sources = [ _label ]
  if (sources = []) {
    _deps += _sources
  }
}
sources = []
set_source_assignment_filter([])
```

In the latest version, **set_source_assignment_filter** is replaced by **filter_include** and **filter_exclude**.

### Using **deps** for Intra-part Dependencies and **external_deps** for Cross-part Dependencies

- In OpenHarmony, a part is a group of modules that can provide a certain capability.
- When defining a module, you can declare the **part_name** to signify the part to which the module belongs.

- Each part declares its inner-kit for other parts to invoke. For details about the declaration of inner-kit, see **ohos.build** in the source code.
- Inter-part dependencies can only be inner-kit modules.

- If the values of **part_name** of modules **a** and **b** are the same, the two modules belong to the same part. In this case, the dependency between the modules can be declared using **deps**.

- If the values of **part_name** of modules **a** and **b** are different, the two modules belong to different parts. In this case, the dependency between the modules must be declared using **external_deps** in the format of *componentName:moduleName*. See Example 19.

  ```
  # Example 19
  shared_library("a") {
    ...
    external_deps = ["part_name_of_b:b"]
    ...
  }
  ```

  

  

  

  
