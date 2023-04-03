# OpenHarmony rust module configuration rules and guidance
## Configuration rules for various types of rust
Currently, OpenHarmony provides various types of gn templates for compiling and building rust code,include ohos_rust_executable、ohos_rust_static_library、ohos_rust_proc_macro、ohos_rust_shared_ffi、ohos_rust_static_ffi、ohos_rust_cargo_crate、ohos_rust_systemtest、ohos_rust_unittest.
## Guide for configuring various types of rust
### GN template
To use the rust rule, you need to first import "//build/ohos. gni", which is a shared external interface with C/C++
```
import("//build/ohos.gni")
```
To use the rust rule, you need to first import "//build/test. gni", which is a shared external interface with C/C++
```
import("//build/test.gni")
```
### Example
Currently, 'host x86_64', 'target arm64', and 'target arm' architectures have been supported for rust compilation and construction
#### Example reference
There are configuration examples of various types of rust modules available for reference in the build/rust/tests directory:
| test directory | test function |
| ---- | ---- |
| test_bin_crate | Test the host and target compilation links and running of 'ohos_rust_executable' |
| test_static_link | Testing static link from "ohos_rust_executable" to libstd.rlib |
| test_dylib_crate | Test the compilation dependency and running of 'ohos_rust_executable' on 'ohos_rust_shared_library' |
| test_rlib_crate | Test the compilation dependency and running of 'ohos_rust_executable' on 'ohos_rust_static_library' |
| test_proc_macro_crate | Test the compilation dependency and running of 'ohos_rust_executable' on 'ohos_rust_proc_macro' |
| test_cdylib_crate | Test the compilation dependency and running of 'ohos_rust_executable' on 'ohos_rust_shared_ffi' |
| test_staticlib_crate | Test the compilation dependency and running of 'ohos_rust_executable' on 'ohos_rust_static_ffi' |
| test_rust_ut | Test 'ohos_rust_unittest', with the use case code and feature code in the same file |
| test_rust_st | Test 'ohos_rust_systemtest', with the use case code and feature code in the same file |
| test_bin_cargo_crate | Test executable file which using 'ohos_cargo_crate' |
| test_rlib_cargo_crate | Test static library file which using 'ohos_cargo_crate' |
| test_proc_macro_cargo_crate | Test proc_macro which using 'ohos_cargo_crate' |
#### Example of characteristic points
##### Rust source code relies on calling C/C++ libraries
By default, C/C++ modules in a dynamic library on OH use the .z.so suffix, but when they are depended on by Rust, they are converted to -l links, which will only link dynamic libraries with the .so suffix. Therefore, C/C++ dynamic libraries that are dependent on need to add output_externsion = "so". Similarly, if linking to a dynamic library in Rust source code, the suffix also needs to use ".so", and the middle name of the dynamic library does not need to add the "lib" prefix. For example, linking to libhilog.so:
```
#[link(name = "hilog")]
```
##### externs
If a module relies on a binary rlib library, the externs attribute can be used:
```
executable("foo") {
    sources = [ "main.rs" ]
    externs = [{                    # `--extern bar=path/to/bar.rlib`
        crate_name = "bar"
        path = "path/to/bar.rlib"
    }]
}
```
##### rust-project.json for IDE
```
./build.sh --product-name rk3568 --build-target=build/rust:default --export-rust-project
```
#### Verification
Currently target ohos arm and ohos arm64 architectures are supported. Arm64 simulator compilation startup method:
```
./build.sh --product-name qemu-arm64-linux-min
./vendor/ohemu/qemu_arm64_linux_min/qemu_run.sh -e out/qemu-arm-linux/packages/phone/images/
```
### Lints rules
The OH framework supports two levels of lints: rustc lints and clippy lints, identified by the module attributes rustc_lints and clippy_lints respectively. It also supports three standard levels: "openharmony", "vendor", and "none", with "openharmony" being the strictest and system-configured. When a module has no configuration, the level is determined based on path matching.
#### The various level markers for rustc lints and clippy lints.
| **lints type** | **module attribute** | **lints level** | **lints level flags** | **lints content** |
| ---- | ---- | ---- | ---- | ---- |
| rustc_lints | rustc_lints | openharmony | RustOhosLints | "-A deprecated", "-D missing-docs", "-D warnigngs" |
| rustc_lints  |  rustc_lints | vendor | RustcVendorLints | "-A deprecated", "-D warnigs" |
| rustc_lints  | rustc_lints  | none | allowAllLints | "-cap-lints allow" |
| clippy lints | clippy lints | openharmony | ClippyOhosLints | "-A clippy::type-complexity", "-A clippy::unnecessary-wraps", "-A clippy::unusual-byte-groupings", "-A clippy::upper-case-acronyms" |
| clippy lints | clippy lints | vendor | ClippyVendorLints | "-A clippy::complexity", "-A Clippy::perf", "-A clippy::style" |
| clippy lints | clippy lints | none | allowAllLints | "--cap-lints allow" |

#### The correspondence between code paths and lint levels.
| path | Lints level | Note |
| ---- | ---- | ---- |
| thirdparty | none |  |
| prebuilts | none |  |
| vendor | vendor |  |
| device | vendor |  |
| others | openharmony |

