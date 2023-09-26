# Multi-language Runtime Subsystem Changelog
## cl.arkcompiler.1 New Alarms and Existing Alarm Enhancements for LLVM

**Change Impact**

By default, the **-Werror** option is disabled for the OpenHarmony NDK. If you have enabled the **-Werror** option, you are advised to correct the code based on the suggestions in the check result or mask the errors.

 **Changes in Key Compilation Check Rules**

| New Check Item| Description| Suggestion|
| --- | --- | --- |
| Wunused-but-set-variable | An alarm is generated when the code contains unused variables (including the ++ operator).| Add the **maybe_unused** attribute when defining variables or use macros to distinguish variables.|
| Wdeprecated-non-prototype | An alarm is generated when a function without a prototype exists in the code.| Add a function prototype and specify the parameters.|
| Wunqualified-std-cast-call | An alarm is generated when **std::move** is incorrectly used in code.| Specify the use case of **std::move** and check the code.|
| Wdeprecated-builtins | An alarm is generated when a deprecated built-in function is used in the code.| Use the substitute function.|
| Warray-parameter | An alarm is generated when a function parameter contains an array that uses inconsistent forms.| Ensure the consistency of the function parameter.|
| Wbitwise-instead-of-logical | An alarm is generated when bitwise OR is used in Boolean operations.| Use logical OR in Boolean operations.|
| Wint-conversion | An alarm is generated when an int variable is converted to a pointer in the code.| Use a new implementation mode in the code.|
| Wdeprecated-declarations | An alarm is generated when a deprecated definition (including functions and variables) is used in code.| Use a new implementation mode in the code.|
| Wnull-pointer-subtraction | An alarm is generated when a null pointer is used in the subtraction operation.| Do not a null pointer in the subtraction operation.|
| Wunused-but-set-parameter | An alarm is generated when a function contains unused parameters.| Delete unused parameters.|
| Warray-bounds | An alarm is generated when out-of-bounds access to an array occurs in the code.| Modify the out-of-bounds access.|
| Wdeprecated-pragma | An alarm is generated when a deprecated macro is used in the code.| Delete the deprecated macro.|
| Wreserved-identifier | An alarm is generated when a variable starting with __ is used in the code.| Check the code to prevent variables starting with underscores (_) from being used externally.|

 **Adaptation Guide**

1. For issues in the code that are not detected by LLVM 12, check and update the code.
2. Some old implementations are discarded during LLVM update. Adapt to the new rules and update the code.
3. If you believe a certain type of error can be masked, use the **-Wno-xxx** option to mask the error.

Defective code example

```
void Heap::Resume(TriggerGCType gcType)
{
    if (mode_ != HeapMode::SPAWN &&
        activeSemiSpace_->AdjustCapacity(inactiveSemiSpace_->GetAllocatedSizeSinceGC())) {
        // If activeSpace capacity changes, oldSpace maximumCapacity should change too.
        size_t multiple = 2;
        // oldSpaceMaxLimit is assigned a value but is not used.
        size_t oldSpaceMaxLimit = 0;
        if (activeSemiSpace_->GetInitialCapacity() >= inactiveSemiSpace_->GetInitialCapacity()) {
            size_t delta = activeSemiSpace_->GetInitialCapacity() - inactiveSemiSpace_->GetInitialCapacity();
            oldSpaceMaxLimit = oldSpace_->GetMaximumCapacity() - delta * multiple;
        } else {
            size_t delta = inactiveSemiSpace_->GetInitialCapacity() - activeSemiSpace_->GetInitialCapacity();
            oldSpaceMaxLimit = oldSpace_->GetMaximumCapacity() + delta * multiple;
        }
        inactiveSemiSpace_->SetInitialCapacity(activeSemiSpace_->GetInitialCapacity());
    }
    // irrelated code ...
}
```

The oldSpaceMaxLimit variable is not used, and the compiler reports an alarm.

```
../../arkcompiler/ets_runtime/ecmascript/mem/heap.cpp:247:16: error: variable 'oldSpaceMaxLimit' set but not used [-Werror,-Wunused-but-set-variable]
        size_t oldSpaceMaxLimit = 0;
```

The error is rectified after the attribute is added.

```
void Heap::Resume(TriggerGCType gcType)
{
    if (mode_ != HeapMode::SPAWN &&
        activeSemiSpace_->AdjustCapacity(inactiveSemiSpace_->GetAllocatedSizeSinceGC())) {
        // If activeSpace capacity changes, oldSpace maximumCapacity should change too.
        size_t multiple = 2;
        // Add the maybe_unused attribute and declare that the variable oldSpaceMaxLimit may not be used.
        [[maybe_unused]] size_t oldSpaceMaxLimit = 0;
        if (activeSemiSpace_->GetInitialCapacity() >= inactiveSemiSpace_->GetInitialCapacity()) {
            size_t delta = activeSemiSpace_->GetInitialCapacity() - inactiveSemiSpace_->GetInitialCapacity();
            oldSpaceMaxLimit = oldSpace_->GetMaximumCapacity() - delta * multiple;
        } else {
            size_t delta = inactiveSemiSpace_->GetInitialCapacity() - activeSemiSpace_->GetInitialCapacity();
            oldSpaceMaxLimit = oldSpace_->GetMaximumCapacity() + delta * multiple;
        }
        inactiveSemiSpace_->SetInitialCapacity(activeSemiSpace_->GetInitialCapacity());
    }
    // irrelated code ...
}
```

## cl.arkcompiler.2 LLVM Parsing Format Changed

**Change Impact**

When your code depends on the **version-script** or **-gcc-toolchain** option, parsing may fail if you continue to use the original LLVM 12 configuration file or options.

**Changes in Key Compilation Rules**

1. The symbol representation is changed. In the new version, consecutive greater signs (>) are represented as ">>", which was represented as "> >" in the old version.
2. The -xx options are deprecated. For example, the **-gcc-toolchain** option is replaced by the **--gcc-toolchain** option. (This option has been marked as deprecated in versions later than Clang 3.4 and is officially deprecated in LLVM15.)

**Adaptation Guide**

If two consecutive greater signs (>) exist in the code (without considering the number of spaces in the middle), they will be parsed as "> >" in the older version and ">>" in the new version in version-script (due to mangling differences). In LLVM15, ">>" must be used.

Original configuration file

```
{
  global:
  extern "C++" {
    "google::protobuf::TextFormat::ParseFromString(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, google::protobuf::Message*)";
    // In LLVM 12, "> >" can be parsed, but ">>" cannot.
    "google::protobuf::TextFormat::PrintToString(google::protobuf::Message const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*)";
  };
  local:
    *;
}
```

Modified configuration file

```
{
  global:
  extern "C++" {
    "google::protobuf::TextFormat::ParseFromString(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, google::protobuf::Message*)";
    // In LLVM 15, ">>" can be parsed.
    "google::protobuf::TextFormat::PrintToString(google::protobuf::Message const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>*)";
  };
  local:
    *;
}
```

## cl.arkcompiler.3 LLVM emu-tls Changed

**Change Impact**

If you use both LLVM 12 and LLVM 15 (this behavior is prohibited) for your code, the emu-tls symbol cannot be found in libc++.so.

**Key Library Dependency Changes**

In LLVM 15, the emu-tls symbol is extracted from the target binary file to libc++.so. That is, the __emutls_get_address attribute changes from an internal symbol to an externally visible symbol, which is included in libc++.so. As a result, the compiled dynamic library may depend on libc++.so.

**Adaptation Guide**

This symbol is also in libclang_rt.builtin.a. If you do not want the compiled dynamic library to depend on libc++.so, statically link the libclang_rt.builtin.a library.

## cl.arkcompiler.4 LLVM Official Release Notes

**Change Impact**

New features are added and internal interfaces are changed (such as IR in LLVM and compiler front-end modification). For details, see the official release notes.

**Key Documents**

https://releases.llvm.org/13.0.0/docs/ReleaseNotes.html
https://releases.llvm.org/14.0.0/docs/ReleaseNotes.html
https://releases.llvm.org/15.0.0/docs/ReleaseNotes.html

**Adaptation Guide**

For details about the updates and adaptation guide, see the official documents.
