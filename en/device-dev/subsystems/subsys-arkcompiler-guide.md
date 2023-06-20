# ArkCompiler Development

## Introduction
ArkCompiler is a unified programming platform. Its key components include a compiler, toolchain, and runtime. ArkCompiler supports compilation and running of high-level programming languages on the multi-chip platform and accelerates the running of applications and services on mobile phones, PCs, tablets, TVs, automobiles, and smart wearables.

## Environment Setup
Ubuntu 18.04 or later is recommended.

1. Install dependent tools.
   ```shell
   sudo apt-get update && sudo apt-get install python ruby python3-pip git-lfs gcc-multilib g++-multilib zlib1g-dev libc++1 curl nodejs
   ```
2. Install the **repo** tool.
    ```shell
    mkdir ~/bin/
    curl https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > ~/bin/repo
    chmod a+x ~/bin/repo
    export PATH=~/bin:$PATH
    pip3 install -i https://pypi.tuna.tsinghua.edu.cn/simple requests
    ```
3. Download source code.
    ```shell
    repo init -u https://gitee.com/ark-standalone-build/manifest.git -b master
    repo sync -c -j8
    repo forall -c 'git lfs pull'
    ```

4. Install the compiler and binary tool.
    ```shell
    ./prebuilts_download.sh
    ```

## How to Develop

1. Create the build products **ark_js_vm** and **es2panda**.
    ```shell
    python ark.py x64.release
    ```
    - **ark_js_vm**: executable program for running .abc files.
    - **es2panda**: tool that converts ArkTS files into ArkCompiler bytecode files.

2. Use **es2panda** to convert a TypeScript file to an .abc file.
    ```shell
    out/x64.release/arkcompiler/ets_frontend/es2abc helloworld.ts
    ```
    Code snippet of the TypeScript case file **helloworld.ts**:
    ```JavaScript
    declare function print(arg:string):string;
    print('Hello world!');
    ```

3. Run the generated .abc file.
    ```shell
    out/x64.release/arkcompiler/ets_runtime/ark_js_vm helloworld.abc
    ```
    .abc file: ArkCompiler bytecode file.
    
    The execution output is as follows:
    ```
    Hello world!
    ```

## Running the Test262 Test Suite
```
python ark.py x64.release test262
```

## Build Options

Select a build mode, for example, mode for building a debug version on an x64 platform.
```
python ark.py x64.debug
```
Obtain help information.
```
python ark.py --help
```
