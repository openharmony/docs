# ArkCompiler开发指导

## 概述
ArkCompiler是一种统一编程平台，包含编译器、工具链、运行时等关键部件，支持高级语言在多种芯片的编译与运行，并支撑应用和服务运行在手机、个人电脑、平板、电视、汽车和智能穿戴等多种设备上的需求。

## 编译环境配置
推荐操作系统：Ubuntu18.04及以上版本。

1. 安装依赖工具。
   ```shell
   sudo apt-get update && sudo apt-get install python ruby python3-pip git-lfs gcc-multilib g++-multilib zlib1g-dev libc++1 curl nodejs
   ```
2. 安装repo工具。
    ```shell
    mkdir ~/bin
    curl https://raw.gitcode.com/gitcode-dev/repo/raw/main/repo-py3 -o ~/bin/repo
    chmod a+x ~/bin/repo
    pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
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

1. 生成编译产物ark_js_vm及es2abc。
    ```shell
    python ark.py x64.release
    ```
    - ark_js_vm：运行abc文件的可执行程序。
    - es2abc：将ArkTS文件转换生成abc（方舟字节码）文件的工具。

2. 使用es2abc将TypeScript文件转换为abc文件。
    ```shell
    out/x64.release/arkcompiler/ets_frontend/es2abc helloworld.ts
    ```
    在项目根目录下创建`helloworld.ts`文件，源码如下：
    ```TypeScript
    declare function print(message: string):string;
    print('Hello world!');
    ```

3. 执行生成的abc文件。
    ```shell
    out/x64.release/arkcompiler/ets_runtime/ark_js_vm helloworld.abc
    ```
    abc文件：ArkCompiler字节码文件。
    
    执行结果：
    ```text
    Hello world!
    ```

## 执行Test262测试套
```shell
python ark.py x64.release test262
```

## 编译选项

可切换编译模式，例如在x64平台构建debug版本。
```shell
python ark.py x64.debug
```
获取更多编译说明。
```shell
python ark.py --help
```
