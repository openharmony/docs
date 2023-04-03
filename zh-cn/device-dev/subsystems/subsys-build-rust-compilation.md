# OpenHarmony rust模块配置规则和指导
## rust各类型模块配置规则
当前OpenHarmony提供了用于rust代码编译构建的各类型gn模板。包含ohos_rust_executable、ohos_rust_static_library、ohos_rust_proc_macro、ohos_rust_shared_ffi、ohos_rust_static_ffi、ohos_rust_cargo_crate、ohos_rust_systemtest、ohos_rust_unittest.
## rust各类型模块配置指导
### 模板gni文件
使用rust规则需要先import导入"//build/ohos.gni"，与C/C++共用的对外接口
```
import("//build/ohos.gni")
```
使用rust测试用例规则需要先import导入"//build/test.gni"，与C/C++共用的对外接口
```
import("//build/test.gni")
```
### 实例参考
当前已经支持host x86_64和target arm64和target arm架构的rust相关编译构建
#### 源码实例 
在build/rust/tests目录下有rust各类型模块的配置实例可供参考：
| 用例目录 | 测试功能 |
| ---- | ---- |
| test_bin_crate | 测试ohos_rust_executable的host和target编译链接及运行 |
| test_static_link | 测试ohos_rust_executable对libstd.rlib进行静态链接 |
| test_dylib_crate | 测试ohos_rust_executable对ohos_rust_shared_library的编译依赖和运行 |
| test_rlib_crate | 测试ohos_rust_executable对ohos_rust_static_library的编译依赖和运行 |
| test_proc_macro_crate | 测试ohos_rust_executable对ohos_rust_proc_macro的编译依赖和运行,对不同类型都有用例覆盖 |
| test_cdylib_crate | 测试ohos_rust_executable对ohos_rust_shared_ffi的编译依赖和运行 |
| test_staticlib_crate | 测试ohos_rust_executable对ohos_rust_static_ffi的编译依赖和运行 |
| test_rust_ut | 测试ohos_rust_unittest，用例代码与特性代码在同一个文件中 |
| test_rust_st | 测试ohos_rust_systemtest，用例代码在独立的test目录中 |
| test_bin_cargo_crate | 测试ohos_cargo_crate对拥有build.rs预编译的可执行文件编译链接和运行，适用于rust三方crate编译依赖 |
| test_rlib_cargo_crate | 测试ohos_cargo_crate对拥有build.rs预编译的静态库文件编译链接和运行，适用于rust三方crate编译依赖 |
| test_proc_macro_cargo_crate | 测试ohos_cargo_crate对拥有build.rs预编译的过程宏编译链接和运行，适用于rust三方crate编译依赖 |
#### 特性点实例
##### rust源码依赖调用C/C++库
OH上C/C++模块动态库默认用.z.so后缀，但是被rust依赖部分会转成-l链接，默认只会链接.so后缀的动态库。因此被依赖的C/C++动态库要加上output_externsion = "so"。同理，在rust源码中如果直接链接动态库，后缀也需要使用".so"，使用动态库的中间名，不需要添加lib前缀，例如链接libhilog.so:
```
#[link(name = "hilog")]
```
##### externs使用
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
##### IDE的rust-project.json编译
```
./build.sh --product-name rk3568 --build-target=build/rust:default --export-rust-project
```
#### 运行验证
当前支持target ohos arm和ohos arm64架构。arm64模拟器编译启动方法：
```
./build.sh --product-name qemu-arm64-linux-min
./vendor/ohemu/qemu_arm64_linux_min/qemu_run.sh -e out/qemu-arm-linux/packages/phone/images/
```
### lints规则
OH框架支持rustc lints和clippy lints两级lints，分别由模块属性rustc_lints和clippy_lints标识；同时支持三个等级的标准："openharmony"、"vendor"和"none"，"openharmony"是系统配置，最为严格。模块无配置时按照路径匹配等级。
#### rustc lints和clippy lints的各等级标志
| **lints类型** | **模块属性** | **lints等级** | **lints等级标志** | **lints内容** |
| ---- | ---- | ---- | ---- | ---- |
| rustc_lints | rustc_lints | openharmony | RustOhosLints | "-A deprecated", "-D missing-docs", "-D warnigngs" |
| rustc_lints  |  rustc_lints | vendor | RustcVendorLints | "-A deprecated", "-D warnigs" |
| rustc_lints  | rustc_lints  | none | allowAllLints | "-cap-lints allow" |
| clippy lints | clippy lints | openharmony | ClippyOhosLints | "-A clippy::type-complexity", "-A clippy::unnecessary-wraps", "-A clippy::unusual-byte-groupings", "-A clippy::upper-case-acronyms" |
| clippy lints | clippy lints | vendor | ClippyVendorLints | "-A clippy::complexity", "-A Clippy::perf", "-A clippy::style" |
| clippy lints | clippy lints | none | allowAllLints | "--cap-lints allow" |

#### 代码路径与lints等级的对应关系
| 路径 | Lints等级 | 备注 |
| ---- | ---- | ---- |
| thirdparty | none |  |
| prebuilts | none |  |
| vendor | vendor |  |
| device | vendor |  |
| others | openharmony |

