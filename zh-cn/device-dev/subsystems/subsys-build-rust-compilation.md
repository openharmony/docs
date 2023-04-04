# Rust模块配置规则和指导

## 概述

Rust是一门静态和强类型语言，具有更安全的内存管理、更好的运行性能、原生支持多线程开发等优势。

Rust官方使用了cargo工具创建工程和构建编译，在OpenHarmony中希望通过gn构建Rust源码文件(xxx.rs)，增加与C/C++互操作、编译时lint、测试、IDL转换、三方库集成、IDE等功能，扩展gn框架，并增加接口自动化转换，最大程度简化开发。

OpenHarmony拥有集成Rust的先决条件：为了集成OpenHarmony中的C/C++代码，提升编译速度使用了gn+ninja的编译构建系统。gn的构建语言简洁易读，ninja的汇编级编译规则直接高效。

### 基本概念

| 术语  | 描述                                                         |
| ----- | ------------------------------------------------------------ |
| Cargo | Cargo是一个工具,允许Rust 项目声明其各种依赖项，并确保您始终获得可重复的构建。 |
| crate | crate是一个独立的可编译单元。                                |
| lints | lints 是指出常见编程错误、错误、样式错误和可疑结构的工具。可以对程序进行更加广泛的错误分析。 |



## 配置规则
当前OpenHarmony提供了用于Rust代码编译构建的各类型gn模板。包含如下模板：

| gn模板                   | 功能              | 输出                                            |
| ------------------------ | ----------------- | ----------------------------------------------- |
| ohos_rust_executable     | rust可执行文件    | rust可执行文件，不带后缀                        |
| ohos_rust_shared_library | rust动态库        | rust dylib动态库，默认后缀.dylib.so             |
| ohos_rust_static_library | rust静态库        | rust rlib静态库，默认后缀.rlib                  |
| ohos_rust_proc_macro     | rust proc_macro   | rust proc_macro库， 默认后缀.so                 |
| ohos_rust_shared_ffi     | rust FFI动态库    | rust cdylib动态库，给C/C++模块调用，默认后缀.so |
| ohos_rust_static_ffi     | rust FFI静态库    | rust staticlib库，给C/C++模块调用，默认后缀.a   |
| ohos_rust_cargo_crate    | 三方包Cargo crate | rust三方crate，支持rlib、dylib、bin             |
| ohos_rust_systemtest     | rust系统测试用例  | rust可执行系统测试用例，不带后缀                |
| ohos_rust_unittest       | rust单元测试用例  | rust可执行单元测试用例，不带后缀                |



## 配置指导
### test_rlib_crate示例

test_rlib_crate是测试对Rust可执行bin文件和静态库rlib文件的编译，以及可执行文件对静态库的依赖。

1. 创建build/rust/tests/test_rlib_crate/src/simple_printer.rs，示例如下：

   ```rust
   //! simple_printer
   
   /// struct RustLogMessage
   
   pub struct RustLogMessage {
       /// i32: id
       pub id: i32,
       /// String: msg
       pub msg: String,
   }
   
   /// function rust_log_rlib
   pub fn rust_log_rlib(msg: RustLogMessage) {
       println!("id:{} message:{:?}", msg.id, msg.msg)
   }
   ```

2. 创建build/rust/tests/test_rlib_crate/src/main.rs，示例如下：

   ```rust
   //! rlib_crate example for Rust.
   
   extern crate simple_printer_rlib;
   
   use simple_printer_rlib::rust_log_rlib;
   use simple_printer_rlib::RustLogMessage;
   
   fn main() {
       let msg: RustLogMessage = RustLogMessage {
           id: 0,
           msg: "string in rlib crate".to_string(),
       };
       rust_log_rlib(msg);
   }
   ```

3. 配置gn脚本build/rust/tests/test_rlib_crate/BUILD.gn，示例如下：

   ```
   import("//build/ohos.gni")
   
   ohos_rust_executable("test_rlib_crate") {
     sources = [ "src/main.rs" ]
     deps = [ ":simple_printer_rlib" ]
   }
   
   ohos_rust_static_library("simple_printer_rlib") {
     sources = [ "src/simple_printer.rs" ]
     crate_name = "simple_printer_rlib"
     crate_type = "rlib"
     features = [ "std" ]
   }
   ```
   
4. 运行结果如下：

   ![test_rlib_crate](./figures/test_rlib_crate.png)

### test_rlib_cargo_crate示例

test_rlib_cargo_crate是测试包含预编译文件build.rs的静态库rlib文件的编译。

1. 创建build/rust/tests/test_rlib_cargo_crate/crate/src/lib.rs，示例如下：

   ```rust
   include!(concat!(env!("OUT_DIR"), "/generated/generated.rs"));
   
   pub fn say_hello_from_crate() {
       assert_eq!(run_some_generated_code(), 45);
       #[cfg(is_new_rustc)]
       println!("Is new rustc");
       #[cfg(is_old_rustc)]
       println!("Is old rustc");
       #[cfg(is_ohos)]
       println!("Is ohos");
       #[cfg(is_mac)]
       println!("Is darwin");
       #[cfg(has_feature_a)]
       println!("Has feature_a");
       #[cfg(not(has_feature_a))]
       panic!("Wasn't passed feature_a");
       #[cfg(not(has_feature_b))]
       #[cfg(test_a_and_b)]
       panic!("feature_b wasn't passed");
       #[cfg(has_feature_b)]
       #[cfg(not(test_a_and_b))]
       panic!("feature_b was passed");
   }
   
   #[cfg(test)]
   mod tests {
       /// Test features are passed through from BUILD.gn correctly. This test is the target configuration.
       #[test]
       #[cfg(test_a_and_b)]
       fn test_features_passed_target1() {
           #[cfg(not(has_feature_a))]
           panic!("feature a was not passed");
           #[cfg(not(has_feature_b))]
           panic!("feature b was not passed");
       }
   
       #[test]
       fn test_generated_code_works() {
           assert_eq!(crate::run_some_generated_code(), 45);
       }
   }
   ```

2. 创建build/rust/tests/test_rlib_cargo_crate/crate/src/main.rs，示例如下：

   ```rust
   pub fn main() {
       test_rlib_crate::say_hello_from_crate();
   }
   ```

3. 创建build/rust/tests/test_rlib_cargo_crate/crate/build.rs，示例如下：

   ```rust
   use std::env;
   use std::path::Path;
   use std::io::Write;
   use std::process::Command;
   use std::str::{self, FromStr};
   
   fn main() {
       println!("cargo:rustc-cfg=build_script_ran");
       let my_minor = match rustc_minor_version() {
           Some(my_minor) => my_minor,
           None => return,
       };
   
       if my_minor >= 34 {
           println!("cargo:rustc-cfg=is_new_rustc");
       } else {
           println!("cargo:rustc-cfg=is_old_rustc");
       }
   
       let target = env::var("TARGET").unwrap();
   
       if target.contains("ohos") {
           println!("cargo:rustc-cfg=is_ohos");
       }
       if target.contains("darwin") {
           println!("cargo:rustc-cfg=is_mac");
       }
   
       let feature_a = env::var_os("CARGO_FEATURE_MY_FEATURE_A").is_some();
       if feature_a {
           println!("cargo:rustc-cfg=has_feature_a");
       }
       let feature_b = env::var_os("CARGO_FEATURE_MY_FEATURE_B").is_some();
       if feature_b {
           println!("cargo:rustc-cfg=has_feature_b");
       }
   
       // Some tests as to whether we're properly emulating various cargo features.
       assert!(Path::new("build.rs").exists());
       assert!(Path::new(&env::var_os("CARGO_MANIFEST_DIR").unwrap()).join("build.rs").exists());
       assert!(Path::new(&env::var_os("OUT_DIR").unwrap()).exists());
   
       // Confirm the following env var is set
       env::var_os("CARGO_CFG_TARGET_ARCH").unwrap();
   
       generate_some_code().unwrap();
   }
   
   fn generate_some_code() -> std::io::Result<()> {
       let test_output_dir = Path::new(&env::var_os("OUT_DIR").unwrap()).join("generated");
       let _ = std::fs::create_dir_all(&test_output_dir);
       // Test that environment variables from .gn files are passed to build scripts
       let preferred_number = env::var("ENV_VAR_FOR_BUILD_SCRIPT").unwrap();
       let mut file = std::fs::File::create(test_output_dir.join("generated.rs"))?;
       write!(file, "fn run_some_generated_code() -> u32 {{ {} }}", preferred_number)?;
       Ok(())
   }
   
   fn rustc_minor_version() -> Option<u32> {
       let rustc_bin = match env::var_os("RUSTC") {
           Some(rustc_bin) => rustc_bin,
           None => return None,
       };
   
       let output = match Command::new(rustc_bin).arg("--version").output() {
           Ok(output) => output,
           Err(_) => return None,
       };
   
       let rustc_version = match str::from_utf8(&output.stdout) {
           Ok(rustc_version) => rustc_version,
           Err(_) => return None,
       };
   
       let mut pieces = rustc_version.split('.');
       if pieces.next() != Some("rustc 1") {
           return None;
       }
   
       let next_var = match pieces.next() {
           Some(next_var) => next_var,
           None => return None,
       };
   
       u32::from_str(next_var).ok()
   }
   ```

4. 配置gn脚本build/rust/tests/test_rlib_cargo_crate/BUILD.gn，示例如下：

   ```
   import("//build/templates/rust/ohos_cargo_crate.gni")
   
   ohos_cargo_crate("target") {
     crate_name = "test_rlib_crate"
     crate_root = "crate/src/lib.rs"
     sources = [ "crate/src/lib.rs" ]
   
     #To generate the build_script binary
     build_root = "crate/build.rs"
     build_sources = [ "crate/build.rs" ]
     build_script_outputs = [ "generated/generated.rs" ]
   
     features = [
       "my-feature_a",
       "my-feature_b",
       "std",
     ]
     rustflags = [
       "--cfg",
       "test_a_and_b",
     ]
     rustenv = [ "ENV_VAR_FOR_BUILD_SCRIPT=45" ]
   }
   
   # Exists to test the case that a single crate has both a library and a binary
   ohos_cargo_crate("test_rlib_crate_associated_bin") {
     crate_root = "crate/src/main.rs"
     crate_type = "bin"
     sources = [ "crate/src/main.rs" ]
   
     #To generate the build_script binary
     build_root = "crate/build.rs"
     build_sources = [ "crate/build.rs" ]
     features = [
       "my-feature_a",
       "my-feature_b",
       "std",
     ]
     rustenv = [ "ENV_VAR_FOR_BUILD_SCRIPT=45" ]
     deps = [ ":target" ]
   }
   ```

5. 运行结果如下：

   ![test_rlib_cargo_crate](./figures/test_rlib_cargo_crate.png)

### 源码实例 
在build/rust/tests目录下有Rust各类型模块的配置实例可供参考：
| 用例目录                                     | 测试功能                                                     |
| -------------------------------------------- | ------------------------------------------------------------ |
| build/rust/tests/test_bin_crate              | 测试ohos_rust_executable的host和target编译链接及运行         |
| build/rust/tests/test_static_link            | 测试ohos_rust_executable对libstd.rlib进行静态链接            |
| build/rust/tests/test_dylib_crate            | 测试ohos_rust_executable对ohos_rust_shared_library的编译依赖和运行 |
| build/rust/tests/test_rlib_crate             | 测试ohos_rust_executable对ohos_rust_static_library的编译依赖和运行 |
| build/rust/tests/test_proc_macro_crate       | 测试ohos_rust_executable对ohos_rust_proc_macro的编译依赖和运行，对不同类型都有用例覆盖 |
| build/rust/tests/test_cdylib_crate           | 测试ohos_rust_executable对ohos_rust_shared_ffi的编译依赖和运行 |
| build/rust/tests/test_staticlib_crate        | 测试ohos_rust_executable对ohos_rust_static_ffi的编译依赖和运行 |
| build/rust/tests/test_rust_ut                | 测试ohos_rust_unittest，用例代码与特性代码在同一个文件中     |
| build/rust/tests/test_rust_st                | 测试ohos_rust_systemtest，用例代码在独立的test目录中         |
| build/rust/tests/test_bin_cargo_crate        | 测试ohos_cargo_crate对拥有build.rs预编译的可执行文件编译链接和运行，适用于rust三方crate编译依赖 |
| build/rust/tests/test_rlib_cargo_crate       | 测试ohos_cargo_crate对拥有build.rs预编译的静态库文件编译链接和运行，适用于rust三方crate编译依赖 |
| build/rust/tests/test_proc_macro_cargo_crate | 测试ohos_cargo_crate对拥有build.rs预编译的过程宏编译链接和运行，适用于rust三方crate编译依赖 |
### 运行验证

当前支持target ohos arm和ohos arm64架构。arm64模拟器编译启动方法：

```shell
./build.sh --product-name qemu-arm64-linux-min
./vendor/ohemu/qemu_arm64_linux_min/qemu_run.sh -e out/qemu-arm-linux/packages/phone/images/
```



## 注意事项

### 特性点实例

#### Rust源码依赖调用C/C++库
OpenHarmony上C/C++模块动态库默认用.z.so后缀，但是被Rust依赖部分会转成-l链接，默认只会链接.so后缀的动态库。因此被依赖的C/C++动态库要加上output_externsion = "so"。同理，在Rust源码中如果直接链接动态库，后缀也需要使用".so"，使用动态库的中间名，不需要添加lib前缀，例如链接libhilog.so:
```rust
#[link(name = "hilog")]
```
#### externs使用
某个模块如果依赖二进制的rlib库，可以使用externs属性：
```
executable("foo") {
    sources = [ "main.rs" ]
    externs = [{                    # 编译时会转成`--extern bar=path/to/bar.rlib`
        crate_name = "bar"
        path = "path/to/bar.rlib"
    }]
}
```
#### IDE的Rust-project.json编译
```shell
./build.sh --product-name rk3568 --build-target=build/rust:default --export-rust-project
```
### lints规则
OpenHarmony框架支持rustc lints和clippy lints两级lints，分别由模块属性rustc_lints和clippy_lints标识；同时支持三个等级的标准："openharmony"、"vendor"和"none"，"openharmony"是系统配置，最为严格。模块无配置时按照路径匹配等级。
#### rustc lints和clippy lints的各等级标志
| **lints类型** | **模块属性** | **lints等级** | **lints等级标志** | **lints内容**                                                |
| ------------- | ------------ | ------------- | ----------------- | ------------------------------------------------------------ |
| rustc_lints   | rustc_lints  | openharmony   | RustOhosLints     | "-A deprecated", "-D missing-docs", "-D warnigngs"           |
| rustc_lints   | rustc_lints  | vendor        | RustcVendorLints  | "-A deprecated", "-D warnigs"                                |
| rustc_lints   | rustc_lints  | none          | allowAllLints     | "-cap-lints allow"                                           |
| clippy lints  | clippy lints | openharmony   | ClippyOhosLints   | "-A clippy::type-complexity", "-A clippy::unnecessary-wraps", "-A clippy::unusual-byte-groupings", "-A clippy::upper-case-acronyms" |
| clippy lints  | clippy lints | vendor        | ClippyVendorLints | "-A clippy::complexity", "-A Clippy::perf", "-A clippy::style" |
| clippy lints  | clippy lints | none          | allowAllLints     | "--cap-lints allow"                                          |

#### 代码路径与lints等级的对应关系
| 路径       | Lints等级   |
| ---------- | ----------- |
| thirdparty | none        |
| prebuilts  | none        |
| vendor     | vendor      |
| device     | vendor      |
| others     | openharmony |

