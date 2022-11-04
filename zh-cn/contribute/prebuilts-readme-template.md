OpenHarmony中的Clang/LLVM-based预编译工具 说明
====================================================

1. 获取最新版本的说明文档，请参考如下：
[基于Clang/LLVM-based OpenHarmony工具说明文档](https://gitee.com/openharmony/third_party_llvm-project/blob/master/llvm-build/README.md)

2. 构建指导
------------------

```
# 获取代码
repo init -u https://gitee.com/openharmony/manifest.git -b llvm_toolchain-dev
repo sync -c 
repo forall -c 'git lfs pull'
cp -r toolchain/llvm-project/llvm-build toolchain

# 编译基于Clang/LLVM的 prebuilts工具
./toolchain/llvm-project/llvm-build/env_prepare.sh
python3 ./toolchain/llvm-build/build.py
```

3. 更新预编译工具
----------------
在OpenHarmony项目中运行脚本:

```
$ ./build/prebuilts_download.sh
```
