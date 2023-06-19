# Using Cargo2gn
## Overview

Rust uses Cargo as its build system and package manager. **Cargo.toml** is the manifest file of Cargo. It contains metadata such as the name, version, and dependencies for crates (packages) in Rust. 

When used in OpenHarmony, **Cargo.toml** needs to be converted into **BUILD.gn** rules. cargo2gn is the tool that can achieve this purpose. It can convert one or more Rust libraries.

##  Converting a Single Library
1. Go to the directory of the rust library to be converted, for example, **bindgen**.

    ```
    cd openharmony/third_party/rust/bindgen
    ```
    
2. Create the configuration file **cargo2gn.json**.

    ```json
    {
        "copy-out": true,
        "run": true,
        "add-workspace": true,
        "cargo-bin": "/mnt/xxx/openharmony/prebuilts/rustc/linux-x86_64/current/bin"
    }
    ```
    
3. Run the following command to perform the conversion:
   
   ```
   python3 /mnt/xxx/openharmony/build/scripts/cargo2gn.py --config cargo2gn.json
   ```
   
   The conversion result is as follows:
   
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
   
   

##  Converting Multiple Libraries in Batches
1. Go to the **rust** directory.
   
   ```
   cd openharmony/third_party/rust
   ```
2. Add all the rust libraries to be converted to [workspace] in **Cargo.toml** in the **rust** directory.

    ```toml
    [workspace]
    members = [
        "aho-corasick",
        "memchr",
    ]
    ```
3. Perform steps 2 and 3 in section "Converting a Single Library".
