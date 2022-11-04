# ArkCompiler开发指导

## 概述
ArkCompiler是一种统一编程平台，包含编译器、工具链、运行时等关键部件，支持高级语言在多种芯片的编译与运行，并支撑应用和服务运行在手机、个人电脑、平板、电视、汽车和智能穿戴等多种设备上的需求。

## 编译环境配置
推荐操作系统Ubuntu18.04及以上。

1. 安装依赖工具。
   ```shell
   sudo apt-get update && sudo apt-get install python ruby python3-pip git-lfs gcc-multilib g++-multilib zlib1g-dev libc++1 curl nodejs
   ```
2. 安装repo工具。
    ```shell
    mkdir ~/bin/
    curl https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > ~/bin/repo
    chmod a+x ~/bin/repo
    export PATH=~/bin:$PATH
    pip3 install -i https://pypi.tuna.tsinghua.edu.cn/simple requests
    ```
3. 下载源码。
    ```shell
    repo init -u https://gitee.com/ark-standalone-build/manifest.git -b master
    repo sync -c -j8
    repo forall -c 'git lfs pull'
    ```

4. 安装编译器及二进制工具。
    ```shell
    ./prebuilts_download.sh
    ```

## 开发步骤

1. 生成编译产物ark_js_vm及js2abc。
    ```shell
    python ark.py x64.release
    ```
    - ark_js_vm：运行abc文件的可执行程序。
    - js2abc：将ArkTS文件转换生成ArkCompiler字节码文件的工具。

2. 将TypeScript文件转换为abc文件。
    ```shell
    prebuilts/build-tools/common/nodejs/node-v12.18.4-linux-x64/bin/node --expose-gc out/x64.release/clang_x64/obj/arkcompiler/ets_frontend/ts2panda/build/src/index.js helloworld.ts --opt-level 0
    ```
    TypeScript用例文件helloworld.ts源码。
    ```JavaScript
    declare function print(arg:any):string;
    print("Hello world!");
    ```

3. 执行生成的abc文件。
    ```shell
    out/x64.release/clang_x64/arkcompiler/ets_runtime/ark_js_vm helloworld.abc
    ```
    abc文件：ArkCompiler字节码文件。
    
    执行结果：
    ```
    Hello world!
    ```

### 执行Test262测试套
```
python ark.py x64.release test262
```

## 编译选项

交叉编译可根据目标选择不同平台，如在x64平台构建arm64目标平台，更多平台选择可参考下方获取更多编译说明。
```
python ark.py arm64.release
```
编译模式选择，如在x64平台构建debug版本。
```
python ark.py x64.debug
```
获取更多编译说明。
```
python ark.py --help
```

