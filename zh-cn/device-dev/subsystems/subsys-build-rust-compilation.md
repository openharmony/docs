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




## Bindgen、CXX工具使用指导

![Bindgen和CXX工具](./figures/bindgen_and_cxx_tools.png "屏幕截图")

Bindgen和CXX工具的主要功能是为了实现Rust和C/C++之间的交互，其中，Bindgen能够实现将C接口转换成Rust接口从而实现Rust调用C接口，CXX可以通过在ffi里extern的方式实现实现C++和rust的互相调用。Bindgen的功能属于单向的，CXX的功能是双向的。

### Bindgen工具使用指导

#### 使用Bindgen实现Rust调用C接口例子

头文件lib.h定义C接口，下面定义了两个C接口，FuncAAddB用来实现两数求和，SayHello用来打印字符串

lib.h

```c
#ifndef BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_
#define BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_
#include <stdint.h>
#include "build/rust/tests/test_bindgen_test/test_for_hello_world/lib2.h"

uint32_t FuncAAddB(uint32_t a, uint32_t b);
void SayHello(const char *message);

#endif  //  BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_
```

C文件lib.c具体写清楚了lib.h头文件中的接口实现

lib.c

```c
#include "build/rust/tests/test_bindgen_test/test_for_hello_world/lib.h"
#include <stdint.h>
#include <stdio.h>

void SayHello(const char *message)
{
    printf("This is a test for bindgen hello world:\n");
    printf("%s\n", message);
}

uint32_t FuncAAddB(uint32_t a, uint32_t b)
{
    printf("This is a test for bindgen of a + b:\n");
    return a + b;
}
```

Rust侧调用C接口，在c_ffi里面加上include!(env!("BINDGEN_RS_FILE"))，这样就能将bindgen转换出来的.rs文件导入到Rust侧，通过c_ffi的方式就能使用C的接口，注意Rust侧调用的不安全接口需要实现unsafe包起来。

```rust
//!  bindgen test for hello world
#![allow(clippy::approx_constant)]
mod c_ffi {
    #![allow(dead_code)]
    #![allow(non_upper_case_globals)]
    #![allow(non_camel_case_types)]
    include!(env!("BINDGEN_RS_FILE"));
}
/// pub fn add_two_numbers_in_c
pub fn add_two_numbers_in_c(a: u32, b: u32) -> u32 {
    unsafe { c_ffi::FuncAAddB(a, b) }
}

use std::ffi::c_char;
use std::ffi::CString;

/// fn main()
fn main() {
    println!("{} + {} = {}", 3, 7, add_two_numbers_in_c(3, 7));
    let c_str = CString::new("This is a message from C").unwrap();
    let c_world: *const c_char = c_str.as_ptr() as *const c_char;
    unsafe {
        c_ffi::SayHello(c_world);
    }
}

```

编写BUILD.gn实现依赖关系构建

ohos_shared_library将lib.c编译成so，rust_bindgen将lib.h转换成rust侧的.rs文件，ohos_rust_executable实现rust侧代码main.rs的编译，同时在deps里面需要将c_lib和c_lib_bindgen两个依赖进来，依赖c_lib的目的是为了识别到具体的C接口的实现，依赖c_lib_bindgen的目的是为了将转换出来的.rs作为输入，同时将文件的路径写到rustenv，从而rust侧能够识别到转换出来的.rs文件。

```GN
import("//build/ohos.gni")

ohos_shared_library("c_lib") {
  sources = [ "lib.c" ]
  defines = [ "COMPONENT_IMPLEMENTATION" ]
}

rust_bindgen("c_lib_bindgen") {
  header = "lib.h"
}

ohos_rust_executable("bindgen_test") {
  deps = [ ":c_lib" ]
  deps += [ ":c_lib_bindgen" ]
  sources = [ "main.rs" ]
  bindgen_output = get_target_outputs(":c_lib_bindgen")
  inputs = bindgen_output
  rustenv = [ "BINDGEN_RS_FILE=" + rebase_path(bindgen_output[0]) ]
  crate_root = "main.rs"
}
```

编译验证

![bindgen_test](./figures/bindgen_test.png "屏幕截图")

#### bindgen官网用例的验证

官网的头文件

[rust-bindgen/bindgen-tests/tests/headers at main · rust-lang/rust-bindgen · GitHub](https://github.com/rust-lang/rust-bindgen/tree/main/bindgen-tests/tests/headers)

官网的转换文件，转换文件和头文件是一一对应的关系

[rust-bindgen/bindgen-tests/tests/expectations/tests at main · rust-lang/rust-bindgen · GitHub](https://github.com/rust-lang/rust-bindgen/tree/main/bindgen-tests/tests/expectations/tests)

bindgen主要用来实现C接口的转换，当需要转换C++接口的时候，可以将.h文件写成.hpp文件，当然，也可以将clang的参数-x c++传递给clang，从而bindgen能够检测出需要转换C++相关文件。具体bindgen能够支持哪些C++特性的转换可参考：

[Generating Bindings to C++ - The `bindgen` User Guide (rust-lang.github.io)](https://rust-lang.github.io/rust-bindgen/cpp.html)

- bindgen官网C转换例子

lib.h

```c
#ifndef BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_
#define BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_
// A few tests for enum-related issues that should be tested with all the enum
// representations.

enum Foo1 {
    BAR = 0,
    QUX
};

struct Foo2 {
    enum {
        FOOFIRST,
        FOOSECOND,
    } member;
};

/** <div rustbindgen nodebug></div> */
enum NoDebug {
    NODEBUG1,
    NODEBUG2,
};

/** <div rustbindgen derive="Debug"></div> */
enum Debug {
    DEBUG1,
    DEBUG2,
};

enum Neg {
    MINUSONE = -1,
    ONE = 1,
};

#endif  //  BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_
```

main.rs

```rust
//!  bindgen test for .h file
#![allow(clippy::approx_constant)]
#![allow(clippy::eq_op)]
mod c_ffi {
    #![allow(dead_code)]
    #![allow(non_upper_case_globals)]
    #![allow(non_camel_case_types)]
    include!(env!("BINDGEN_RS_FILE"));
}

fn bindgen_test_layout_foo() {
    const UNINIT: ::std::mem::MaybeUninit<c_ffi::Foo2> = ::std::mem::MaybeUninit::uninit();
    let ptr = UNINIT.as_ptr();
    println!(
        "The mem size of c_ffi::Foo2 is {} usize",
        ::std::mem::size_of::<c_ffi::Foo2>()
    );
    println!(
        "The align_of size of c_ffi::Foo2 is {} usize",
        ::std::mem::align_of::<c_ffi::Foo2>()
    );
    println!(
        "The ptr addr of!((*ptr).member) as usize - ptr as usize is {} usize",
        unsafe { ::std::ptr::addr_of!((*ptr).member) as usize - ptr as usize }
    );
}
impl Default for c_ffi::Foo2 {
    fn default() -> Self {
        let mut s = ::std::mem::MaybeUninit::<Self>::uninit();
        unsafe {
            ::std::ptr::write_bytes(s.as_mut_ptr(), 0, 1);
            s.assume_init()
        }
    }
}

/// fn main()
fn main() {
    bindgen_test_layout_foo();
}
```

BUILD.gn

```
import("//build/ohos.gni")
import("//build/templates/rust/rust_bindgen.gni")
import("//build/templates/rust/rust_template.gni")

rust_bindgen("c_lib_bindgen_h") {
  header = "lib.h"
}

ohos_rust_executable("bindgen_test_for_h") {
  deps = [ ":c_lib_bindgen_h" ]
  sources = [ "main.rs" ]
  bindgen_output = get_target_outputs(":c_lib_bindgen_h")
  inputs = bindgen_output
  rustenv = [ "BINDGEN_RS_FILE=" + rebase_path(bindgen_output[0]) ]
  crate_root = "main.rs"
}
```

- bindgen官网转换C++的例子

lib.h

```c++
#ifndef BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_
#define BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_

// bindgen-flags: --with-derive-hash --with-derive-partialeq --with-derive-eq
typedef int SecondInt;

class C {
public:
    typedef int FirstInt;
    typedef const char* Lookup;
    FirstInt c;
    FirstInt* ptr;
    FirstInt arr[10];
    SecondInt d;
    SecondInt* other_ptr;

    void method(FirstInt c);
    void methodRef(FirstInt& c);
    void complexMethodRef(Lookup& c);
    void anotherMethod(SecondInt c);
};

class D : public C {
public:
    FirstInt* ptr;
};

#endif  //  BUILD_RUST_TESTS_BINDGEN_TEST_LIB_H_
```

main.rs

```rust
//!  bindgen test for hpp
#![allow(clippy::approx_constant)]
#![allow(non_snake_case)]
mod c_ffi {
    #![allow(dead_code)]
    #![allow(non_upper_case_globals)]
    #![allow(non_camel_case_types)]
    include!(env!("BINDGEN_RS_FILE"));
}


fn bindgen_test_layout_C() {
    const UNINIT: ::std::mem::MaybeUninit<c_ffi::C> =
        ::std::mem::MaybeUninit::uninit();
    let ptr = UNINIT.as_ptr();
    println!(
        "The mem size of c_ffi::C is {} usize",
        ::std::mem::size_of::<c_ffi::C>()
    );
    println!(
        "The align_of size of c_ffi::C is {} usize",
        ::std::mem::align_of::<c_ffi::C>()
    );
    println!(
        "The addr_of!((*ptr).c) as usize - ptr as usize is {} usize",
        unsafe { ::std::ptr::addr_of!((*ptr).c) as usize - ptr as usize }
    );
    println!(
        "The addr_of!((*ptr).ptr) as usize - ptr as usize is {} usize",
        unsafe { ::std::ptr::addr_of!((*ptr).ptr) as usize - ptr as usize }
    );
    println!(
        "The addr_of!((*ptr).arr) as usize - ptr as usize is {} usize",
        unsafe { ::std::ptr::addr_of!((*ptr).arr) as usize - ptr as usize }
    );
    println!(
        "The addr_of!((*ptr).d) as usize - ptr as usize is {} usize",
        unsafe { ::std::ptr::addr_of!((*ptr).d) as usize - ptr as usize }
    );
    println!(
        "The addr_of!((*ptr).other_ptr) as usize - ptr as usize is {} usize",
        unsafe {
            ::std::ptr::addr_of!((*ptr).other_ptr) as usize - ptr as usize
        }
    );
}


fn bindgen_test_layout_D() {
    const UNINIT: ::std::mem::MaybeUninit<c_ffi::D> =
        ::std::mem::MaybeUninit::uninit();
    let ptr = UNINIT.as_ptr();
    println!(
        "The mem size of c_ffi::D is {} usize",
        ::std::mem::size_of::<c_ffi::D>()
    );
    println!(
        "The align_of size of c_ffi::D is {} usize",
        ::std::mem::align_of::<c_ffi::D>()
    );
    println!(
        "The addr_of!((*ptr).ptr) as usize - ptr as usize is {} usize",
        unsafe { ::std::ptr::addr_of!((*ptr).ptr) as usize - ptr as usize }
    );
}
impl Default for c_ffi::D {
    fn default() -> Self {
        let mut r = ::std::mem::MaybeUninit::<Self>::uninit();
        unsafe {
            ::std::ptr::write_bytes(r.as_mut_ptr(), 0, 1);
            r.assume_init()
        }
    }
}

/// fn main()
fn main() {
    bindgen_test_layout_C();
    bindgen_test_layout_D()
}

```

BUILD.gn

```
import("//build/ohos.gni")

rust_bindgen("c_lib_bindgen_hpp") {
  header = "lib.h"
  enable_c_plus_plus = true
}

ohos_rust_executable("bindgen_test_hpp") {
  deps = [ ":c_lib_bindgen_hpp" ]
  sources = [ "main.rs" ]
  bindgen_output = get_target_outputs(":c_lib_bindgen_hpp")
  inputs = bindgen_output
  rustenv = [ "BINDGEN_RS_FILE=" + rebase_path(bindgen_output[0]) ]
  crate_root = "main.rs"
}

```

#### 使用extern C的方式实现Rust调用C接口

test_extern_c.rs

```rust
//! test for extern "C"
#![allow(clippy::approx_constant)]
use std::os::raw::c_double;
use std::os::raw::c_int;

extern "C" {
    fn abs(num: c_int) -> c_int;
    fn sqrt(num: c_double) -> c_double;
    fn pow(num: c_double, power: c_double) -> c_double;
}

/// fn main()
fn main() {
    let x: i32 = -123;
    println!("This is an example of calling a C library function from Rust:");
    println!("The absolute value of {x} is: {}.", unsafe { abs(x) });
    let n: f64 = 9.0;
    let p: f64 = 3.0;
    println!("The {n}th power of {p} is: {}.", unsafe { pow(n, p) });
    let mut y: f64 = 64.0;
    println!("The square root of {y} is: {}.", unsafe { sqrt(y) });
    y = -3.14;
    println!("The square root of {y} is: {}.", unsafe { sqrt(y) });
}

```

BUILD.gn

```
import("//build/ohos.gni")

ohos_rust_executable("test_extern_c") {
  sources = [ "test_extern_c.rs" ]
}

```



### CXX工具使用指导

#### C++调用Rust接口

在Rust侧文件lib.rs里mod ffi写清楚需要调用的C++接口，并将接口包含在extern "Rust"里面，暴露给C++侧使用

```rust
//! #[cxx::bridge]
#[cxx::bridge]
mod ffi{
    #![allow(dead_code)]
    #[derive(Clone, Debug, PartialEq, Eq, PartialOrd, Ord)]
    struct Shared {
        z: usize,
    }
    extern "Rust"{
        fn print_message_in_rust();
        fn r_return_primitive() -> usize;
        fn r_return_shared() -> Shared;
        fn r_return_rust_string() -> String;
        fn r_return_sum(_: usize, _: usize) -> usize;
    }
}

fn print_message_in_rust(){
    println!("Here is a test for cpp call Rust.");
}
fn r_return_shared() -> ffi::Shared {
    println!("Here is a message from Rust,test for ffi::Shared:");
    ffi::Shared { z: 1996 }
}
fn r_return_primitive() -> usize {
    println!("Here is a message from Rust,test for usize:");
    1997
}
fn r_return_rust_string() -> String {
    println!("Here is a message from Rust,test for String");
    "Hello World!".to_owned()
}
fn r_return_sum(n1: usize, n2: usize) -> usize {
    println!("Here is a message from Rust,test for {} + {} is:",n1 ,n2);
    n1 + n2
}

```

C++侧将cxx工具转换出来的lib.rs.h包含进来，就可以使用C++侧的接口

```c++
#include <iostream>
#include "build/rust/tests/test_cxx/src/lib.rs.h"

int main(int argc, const char* argv[])
{
    int a = 2021;
    int b = 4;
    print_message_in_rust();
    std::cout << r_return_primitive() << std::endl;
    std::cout << r_return_shared().z << std::endl;
    std::cout << std::string(r_return_rust_string()) << std::endl;
    std::cout << r_return_sum(a, b) << std::endl;
    return 0;
}
```

BUILD.gn构建依赖关系

rust_cxx底层调用CXX工具将lib.rs文件转换成lib.rs.h和lib.rs.cc文件，ohos_rust_static_ffi实现Rust侧源码的编译，ohos_executable实现C++侧代码的编译

```
import("//build/ohos.gni")
import("//build/templates/rust/rust_cxx.gni")

rust_cxx("test_cxx_exe_gen") {
    sources = [ "src/lib.rs" ]
}

ohos_rust_static_ffi("test_cxx_examp_rust") {
    sources = [ "src/lib.rs" ]
    deps = [ "//build/rust:cxx_rustdeps" ]
}

ohos_executable("test_cxx_exe") {
    sources = [ "main.cpp" ]
    sources += get_target_outputs(":test_cxx_exe_gen")

    include_dirs = [ "${target_gen_dir}" ]
    deps = [
    ":test_cxx_examp_rust",
    ":test_cxx_exe_gen",
    "//build/rust:cxx_cppdeps",
    ]
}
```

ohos_rust_static_ffi需要依赖cxx的rlib

```
group("cxx_rustdeps") {
  public_deps = [ "//third_party/rust/cxx:lib" ]
}
```

ohos_executable需要依赖cxx侧的cxx.h和cxx.cc文件

```
static_library("cxx_cppdeps") {
  defines = [ "RUST_CXX_NO_EXCEPTIONS" ]
  sources = [
    "//third_party/rust/cxx/include/cxx.h",
    "//third_party/rust/cxx/src/cxx.cc",
  ]
  deps = [ ":cxx_rustdeps" ]
  if (is_win) {
    defines += [ "CXX_RS_EXPORT=__declspec(dllexport)" ]
  } else {
    defines += [ "CXX_RS_EXPORT=__attribute__((visibility(\"default\")))" ]
  }
}
```

同时依赖上test_cxx_exe_gen和test_cxx_examp_rust文件

编译验证
![cpp_call_rust](./figures/cpp_call_rust.png "屏幕截图")


#### 实现Rust调用C++

头文件client_blobstore.h

```c++
#ifndef BUILD_RUST_TESTS_CLIENT_BLOBSTORE_H
#define BUILD_RUST_TESTS_CLIENT_BLOBSTORE_H
#include <memory>
#include "third_party/rust/cxx/include/cxx.h"

namespace nsp_org {
namespace nsp_blobstore {
struct MultiBufs;
struct Metadata_Blob;

class client_blobstore {
public:
    client_blobstore();
    uint64_t put_buf(MultiBufs &buf) const;
    void add_tag(uint64_t blobid, rust::Str add_tag) const;
    Metadata_Blob get_metadata(uint64_t blobid) const;

private:
    class impl;
    std::shared_ptr<impl> impl;
};

std::unique_ptr<client_blobstore> blobstore_client_new();
} // namespace nsp_blobstore
} // namespace nsp_org
#endif
```

cpp文件client_blobstore.cpp

```c++
#include <algorithm>
#include <functional>
#include <set>
#include <string>
#include <unordered_map>
#include "src/main.rs.h"
#include "build/rust/tests/test_cxx_rust/include/client_blobstore.h"

namespace nsp_org {
namespace nsp_blobstore {
// Toy implementation of an in-memory nsp_blobstore.
//
// In reality the implementation of client_blobstore could be a large complex C++
// library.
class client_blobstore::impl {
    friend client_blobstore;
    using Blob = struct {
        std::string data;
        std::set<std::string> tags;
    };
    std::unordered_map<uint64_t, Blob> blobs;
};

client_blobstore::client_blobstore() : impl(new class client_blobstore::impl) {}

// Upload a new blob and return a blobid that serves as a handle to the blob.
uint64_t client_blobstore::put_buf(MultiBufs &buf) const
{
    std::string contents;

    // Traverse the caller's res_chunk iterator.
    //
    // In reality there might be sophisticated batching of chunks and/or parallel
    // upload implemented by the nsp_blobstore's C++ client.
    while (true) {
        auto res_chunk = next_chunk(buf);
        if (res_chunk.size() == 0) {
        break;
        }
        contents.append(reinterpret_cast<const char *>(res_chunk.data()), res_chunk.size());
    }

    // Insert into map and provide caller the handle.
    auto res = std::hash<std::string> {} (contents);
    impl->blobs[res] = {std::move(contents), {}};
    return res;
}

// Add add_tag to an existing blob.
void client_blobstore::add_tag(uint64_t blobid, rust::Str add_tag) const
{
    impl->blobs[blobid].tags.emplace(add_tag);
}

// Retrieve get_metadata about a blob.
Metadata_Blob client_blobstore::get_metadata(uint64_t blobid) const
{
    Metadata_Blob get_metadata {};
    auto blob = impl->blobs.find(blobid);
    if (blob != impl->blobs.end()) {
        get_metadata.size = blob->second.data.size();
        std::for_each(blob->second.tags.cbegin(), blob->second.tags.cend(),
            [&](auto &t) { get_metadata.tags.emplace_back(t); });
    }
    return get_metadata;
}

std::unique_ptr<client_blobstore> blobstore_client_new()
{
    return std::make_unique<client_blobstore>();
}
} // namespace nsp_blobstore
} // namespace nsp_org

```

main.rs文件，在main.rs文件的ffi里面，通过宏include!将头文件client_blobstore.h引入进来，从而在rust的main函数里面就可以通过ffi的方式调用C++的接口

```rust
//! test_cxx_rust
#[cxx::bridge(namespace = "nsp_org::nsp_blobstore")]
mod ffi {
    // Shared structs with fields visible to both languages.
    struct Metadata_Blob {
        size: usize,
        tags: Vec<String>,
    }

    // Rust types and signatures exposed to C++.
    extern "Rust" {
        type MultiBufs;

        fn next_chunk(buf: &mut MultiBufs) -> &[u8];
    }

    // C++ types and signatures exposed to Rust.
    unsafe extern "C++" {
        include!("build/rust/tests/test_cxx_rust/include/client_blobstore.h");

        type client_blobstore;

        fn blobstore_client_new() -> UniquePtr<client_blobstore>;
        fn put_buf(&self, parts: &mut MultiBufs) -> u64;
        fn add_tag(&self, blobid: u64, add_tag: &str);
        fn get_metadata(&self, blobid: u64) -> Metadata_Blob;
    }
}

// An iterator over contiguous chunks of a discontiguous file object.
//
// Toy implementation uses a Vec<Vec<u8>> but in reality this might be iterating
// over some more complex Rust data structure like a rope, or maybe loading
// chunks lazily from somewhere.
/// pub struct MultiBufs
pub struct MultiBufs {
    chunks: Vec<Vec<u8>>,
    pos: usize,
}
/// pub fn next_chunk
pub fn next_chunk(buf: &mut MultiBufs) -> &[u8] {
    let next = buf.chunks.get(buf.pos);
    buf.pos += 1;
    next.map_or(&[], Vec::as_slice)
}

/// fn main()
fn main() {
    let client = ffi::blobstore_client_new();

    // Upload a blob.
    let chunks = vec![b"fearless".to_vec(), b"concurrency".to_vec()];
    let mut buf = MultiBufs { chunks, pos: 0 };
    let blobid = client.put_buf(&mut buf);
    println!("This is a test for Rust call cpp:");
    println!("blobid = {}", blobid);

    // Add a add_tag.
    client.add_tag(blobid, "rust");

    // Read back the tags.
    let get_metadata = client.get_metadata(blobid);
    println!("tags = {:?}", get_metadata.tags);
}
```

BUILD.gn里面写清楚依赖关系

使用CXX将main.rs转换成lib.rs.h和lib.rs.cc，同时将产物作为test_cxx_rust_staticlib的源码，编译rust源码main.rs并将test_cxx_rust_staticlib依赖进来。

```
import("//build/ohos.gni")

rust_cxx("test_cxx_rust_gen") {
  sources = [ "src/main.rs" ]
}

ohos_static_library("test_cxx_rust_staticlib") {
  sources = [ "src/client_blobstore.cpp" ]
  sources += get_target_outputs(":test_cxx_rust_gen")
  include_dirs = [
    "${target_gen_dir}",
    "//third_party/rust/cxx/v1/crate/include",
    "include",
  ]
  deps = [
    ":test_cxx_rust_gen",
    "//build/rust:cxx_cppdeps",
  ]
}

ohos_rust_executable("test_cxx_rust") {
  sources = [ "src/main.rs" ]
  deps = [
    ":test_cxx_rust_staticlib",
    "//build/rust:cxx_rustdeps",
  ]
}
```

编译验证
![rust_call_cpp](./figures/rust_call_cpp.png "屏幕截图")


