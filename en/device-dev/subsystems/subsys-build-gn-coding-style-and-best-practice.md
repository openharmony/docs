# Build System Coding Specifications and Best Practices

## Overview

Generate Ninja (GN) is a meta-build system that generates build files for Ninja. It is the front end of Ninja. GN and Ninja together complete OpenHarmony build tasks.

### GN

GN is used in large software systems such as Chromium, Fuchsia, and OpenHarmony. However, the GN syntax has limitations rooted in its design philosophy. For details, see https://gn.googlesource.com/gn/+/main/docs/language.md#Design-philosophy. For example, GN does not support wildcards and cannot get the length of a list. If you find it complex to implement something with GN, stop and consider whether it is necessary to do it. For more details about GN, see https://gn.googlesource.com/gn/+/main/docs/.

### Intended Audience and Purpose

This document is intended for OpenHarmony developers. It describes the GN coding style and practices, but does not cover the GN syntax. For details about the GN basics, see https://gn.googlesource.com/gn/+/main/docs/reference.md.

### General Principles

Scripts must be easy to read and maintain, and have good scalability and performance while functioning well.

## Coding Style

### Naming

Follow the Linux kernel naming style, that is, lowercase letters + underscores (_).

#### Local Variables

A local variable is a variable restricted to use in a certain scope and cannot be passed down.

Different from global variables, local variables start with an underscore (_).

```shell
# Example 1:
action("some_action") {
  ...
  # _output is a local variable.
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

A global variable starts with a lowercase letter.

Use **declare_args** to declare the variable value only if the variable value can be modified by **gn args**.

```shell
# Example 2
declare_args() {
  # The value of some_feature can be changed by gn args.
  some_feature = false
}
```

#### Targets

Name the targets in the lowercase letters + underscores (_) format.

Name the subtargets in templates in the ${target_name}+double underscores (__)+suffix format. This naming convention has the following advantages:

- ${target_name} prevents duplicate subtarget names.

- The double underscores (__) help locate the module to which a subtarget belongs.
  
  ```shell
  # Example 3
  template("ohos_shared_library") {
    # "{target_name}" (Target name) + "__" (double underscores) + "notice" (suffix)
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

Name templates in the verb+object format.

```shell
# Example 4
# Good
template("compile_resources") {
  ...
}
```

### Formatting

GN scripts must be formatted before being submitted. Formatting ensures consistency in style, such as code alignment and line feed. Use the format tool provided by GN to format your scripts. The command is as follows: 

```shell
$ gn format path-to-BUILD.gn
```

**gn format** sorts the imported files in alphabetical order. To maintain the original sequence, add an empty comment line.

For example, the original import sequence is as follows:

```shell
# Example 5
import("//b.gni")
import("//a.gni")
```

**gn format** sorts the files as follows:

```shell
import("//a.gni")
import("//b.gni")
```

To maintain the original sequence, add an empty comment line.

```shell
import("//b.gni")
# Comment to keep the original sequence
import("//a.gni")
```

## Coding Practices

### Guidelines

The build script completes the following tasks:

1. Describes the dependency (deps) between modules.
   
   In practice, the most common problem is lack of dependency.

2. Defines the module build rules (rule).
   
   In practice, unclear input and output are common problems.

Lack of dependency leads to the following problems:

- Unexpected compilation error
  
  ```shell
  # Example 6
  # Lack of dependency poses a possibility of compilation errors.
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
  
  In this example, **libb.so** is linked to **liba.so**, which means that **b** depends on **a**. However, the dependency of **b** on **a** is not declared in the dependency list (**deps**) of **b**. Compilation is performed concurrently. An error occurs if **liba.so** is not available when **libb.so** attempts to create a link to it.
  
  If **liba.so** is available, the compilation is successful. Therefore, lack of dependency poses a possibility of compilation errors.

- Missing compilation of modules
  
  In example 6, images are the target to build. Since images depend only on **b**, **a** will not be compiled. However, as **b** depends on **a**, an error occurs when **b** is linked.

Another problem is unnecessary dependencies. Unnecessary dependencies reduce concurrency and slow down compilation. The following is an example:

**_compile_js_target** does not necessarily depend on **_compile_resource_target**. If this dependency is added, **_compile_js_target** can be compiled only after **_compile_resource_target** is compiled.

```shell
# Example 7:
# Unnecessary dependencies slow down compilation.
template("too_much_deps") {
  ...
  _gen_resource_target = "${target_name}__res"
  action(_gen_resource_target) {
    ...
  }

  _compile_resource_target = "${target_name}__compile_res"
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

Unclear input leads to the following problems:

- Modified code is not compiled during incremental compilation.
- The cache being used is still hit after the code is changed.

In the following example, **foo.py** references the functions in **bar.py**. This means **bar.py** is the input of **foo.py**. You need to add **bar.py** to **input** or **depfile** of **implict_input_action**. Otherwise, if **bar.py** is modified, **implict_input_action** will not be recompiled.

```shell
# Example 8:
action("implict_input_action") {
  script = "//path-to-foo.py"
  ...
}
```

```shell
#!/usr/bin/env
# Content of foo.py
import bar
...
bar.some_function()
...
```

Unclear output leads to the following problems:

- Implicit output
- A failure to obtain the implicit output from the cache

In the following example, **foo.py** generates two files: **a.out** and **b.out**. However, the output of **implict_output_action** declares only **a.out**. In this case, **b.out** is an implicit output, and the cache stores only **a.out**. When the cache is hit, **b.out** cannot be compiled.

```shell
# Example 9
action("implict_output_action") {
  outputs = ["${target_out_dir}/a.out"]
  script = "//path-to-foo.py"
  ...
}
```

```shell
#!/usr/bin/env
# Content of foo.py
...
write_file("b.out")
write_file("a.out")
...
```

### Templates

**Do not use GN native templates. Use the templates provided by the build system.**

The GN native templates include **source_set**, **shared_library**, **static_library**, **action**, **executable** and **group**.

The native templates are not recommended due to the following reasons:

- The native templates provide only the minimal build configuration. They cannot provide functions, such as parsing **external_deps**, collecting notice, and generating installation information.

- The native **action** template cannot automatically detect the changes in the dependencies of the input file, and cannot start recompilation. See Example 8.

  The table below lists the mapping between the GN native templates and templates provided by OpenHarmony Compilation and Build subsystem.

| OpenHarmony Template  | GN Native Template      |
| :------------------ | -------------- |
| ohos_shared_library | shared_library |
| ohos_source_set     | source_set     |
| ohos_executable     | executable     |
| ohos_static_library | static_library |
| action_with_pydeps  | action         |
| ohos_group          | group          |

### Using Python Scripts

You are advised to use Python scripts instead of shell scripts in **action**. Compared with shell scripts, Python scripts feature:

- More user-friendly syntax, which eliminates errors caused by lack of a space
- Easier to read
- Easier to maintain and debug
- Faster compilation due to caching of Python tasks

### rebase_path

- Call **rebase_path** only in **args** of **action**.
  
  ```shell
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

- If rebase_path is called twice for the same variable, unexpected results occur.
  
  ```shell
  # Example 11
  template("foo") {
    action(target_name) {
      ...
      args = [
        # After rebase_path is called twice for bar, the bar value passed is incorrect.
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

It is common to share data between modules. For example, module A wants to know the output and **deps** of module B.

- Data sharing within the same **BUILD.gn**
  
  Data in the same **BUILD.gn** can be shared by defining global variables.
  
  In the following example, the output of module **a** is the input of module **b**, and can be shared with module **b** via global variables.
  
  ```shell
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

- Data sharing between different **BUILD.gn**s
  
  The best way to share data between different **BUILD.gn** is to save the data as files and transfer the files between modules. You can refer to **write_meta_data** in the OpenHarmony HAP build process.

### forward_variable_from

- To customize a template, pass (**forward**) **testonly** first because the **testonly** target may depend on the template target.
  
  ```shell
  # Example 13
  # For a customized template, pass testonly first.
  template("foo") {
    forward_variable_from(invoker, ["testonly"])
    ...
  }
  ```

- Do not use asterisks (*) to **forward** variables. Required variables must be explicitly forwarded one by one.
  
  ```shell
  # Example 14
  # Bad. The asterisk (*) is used to forward the variable.
  template("foo") {
    forward_variable_from(invoker, "*")
    ...
  }
  
  # Good. Variables are explicitly forwarded one by one.
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

The value of **target_name** varies with the scope.

```shell
# Example 15
# The value of target_name varies with the scope.
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

```shell
# Example 16
# b depends on a and inherits from the headers of a.
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

A custom template must contain a subtarget named **target_name**. This subtarget is used as the target of the template and depends on other subtargets. Otherwise, the subtargets will not be compiled.

```shell
# Example 17
# A custom template must have a subtarget named target_name.
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
    # _compile_gen_target depends on _code_gen_target. Therefore, target_name only needs to depend on _compile_gen_target.
      ":$_compile_gen_target"
    ]
  }
}
```

### set_source_assignment_filter

In addition to **sources**, **set_source_assignment_filter** can be used to filter other variables. After the filtering is complete, clear the filter and **sources**.

```shell
# Example 18
# Use set_source_assignment_filter to filter dependencies and add the dependencies with labels matching *:*_res to the dependency list.
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

### Setting deps and external_deps

An OpenHarmony component is a group of modules that can provide a capability. When defining a module, set **part_name** to specify the component to which the module belongs.

You must also declare **inner_kits** of a component for other components to call. For details, see **bundle.json** in the source code. **inner_kits** applies only to dependent modules in different components.

If modules **a** and **b** has the same **part_name**, modules **a** and **b** belong to the same component. In this case, declare the dependency between them using **deps**.

If modules **a** and **b** have different **part_name**, modules **a** and **b** belong to different components. In this case, declare the dependency between them using **external_deps** in the *Component name:Module name* format. See Example 19.

```shell
# Example 19
shared_library("a") {
  ...
  external_deps = ["part_name_of_b:b"]
  ...
}
```