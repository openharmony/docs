Prebuilts for Clang/LLVM-based Tools Used in OpenHarmony
====================================================

1. For the latest version of this doc, please make sure to visit:
[OpenHarmony Clang/LLVM-based Tools Readme Doc](https://gitee.com/openharmony/third_party_llvm-project/blob/master/llvm-build/README.md)

2. Build instructions
------------------

```
# Get source code
repo init -u https://gitee.com/openharmony/manifest.git -b llvm_toolchain-dev
repo sync -c 
repo forall -c 'git lfs pull'
cp -r toolchain/llvm-project/llvm-build toolchain

# Build Clang/LLVM-based prebuilts tool
./toolchain/llvm-project/llvm-build/env_prepare.sh
python3 ./toolchain/llvm-build/build.py
```

3. Update prebuilts
----------------
From an OpenHarmony project, run:

```
$ ./build/prebuilts_download.sh
```
