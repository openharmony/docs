# Cargo2gn工具操作指导
## 概述

rust三方库使用cargo编译，配置为Cargo.toml。集成到OpenHarmony上需要转换成BUILD.gn规则。为了满足这个需求，需要提供一个cargo2gn转换工具。当需要引入rust三方crate时使用cargo2gn转换工具来把三方库的Cargo.toml转换成BUILD.gn规则。cargo2gn可以单个库进行转换，也可以多个库进行批量转换。

##  单个库转换操作步骤
1. 进入到需要转化的rust三方库的目录下，比如需要转化bindgen。

    ```
    cd openharmony/third_party/rust/bindgen
    ```
    
2. 创建配置文件cargo2gn.json，可以参考如下配置。

    ```json
    {
        "copy-out": true,
        "run": true,
        "add-workspace": true,
        "cargo-bin": "/mnt/xxx/openharmony/prebuilts/rustc/linux-x86_64/current/bin"
    }
    ```
    
3. 执行以下命令进行转换。
   
   ```
   python3 /mnt/xxx/openharmony/build/scripts/cargo2gn.py --config cargo2gn.json
   ```
   
   转换结果
   
   ```
   import("//build/templates/rust/ohos_cargo_crate.gni")
   
   ohos_cargo_crate("lib") {
       crate_name = "bindgen"
       crate_type = "rlib"
       crate_root = "./lib.rs"
   
       sources = ["./lib.rs"]
       edition = "2018"
       cargo_pkg_version = "0.64.0"
       cargo_pkg_authors = "Jyun-Yan You <jyyou.tw@gmail.com>,  Emilio Cobos Álvarez <emilio@crisal.io>,  Nick Fitzgerald <fitzgen@gmail.com>,  The Servo project developers"
       cargo_pkg_name = "bindgen"
       cargo_pkg_description = "Automatically generates Rust FFI bindings to C and C++ libraries."
       deps = [
           "//third_party/rust/bitflags:lib",
           "//third_party/rust/cexpr:lib",
           "//third_party/rust/clang-sys:lib",
           "//third_party/rust/lazy_static:lib",
           "//third_party/rust/lazycell:lib",
           "//third_party/rust/log:lib",
           "//third_party/rust/peeking_take_while:lib",
           "//third_party/rust/proc-macro2:lib",
           "//third_party/rust/quote:lib",
           "//third_party/rust/regex:lib",
           "//third_party/rust/rustc-hash:lib",
           "//third_party/rust/shlex:lib",
           "//third_party/rust/syn:lib",
           "//third_party/rust/which:lib",
       ]
       features = [
           "default",
           "log",
           "logging",
           "static",
           "which",
           "which-rustfmt",
       ]
       build_root = "build.rs"
       build_sources = ["build.rs"]
       build_script_outputs = ["host-target.txt"]
   }
   ```
   
   

##  多个库批量转换操作步骤
1. 进入到rust目录下。
   
   ```
   cd openharmony/third_party/rust
   ```
2. 把所有需要转换的rust三方库添加到rust目录下的Cargo.toml的[workspace]里，如下所示。

    ```toml
    [workspace]
    members = [
        "aho-corasick",
        "memchr",
    ]
    ```
3. 执行单个库转换操作步骤的2和3。

