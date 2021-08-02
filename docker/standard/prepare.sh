# Copyright (c) 2020 Huawei Device Co., Ltd.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#!/bin/bash

WORKDIR=/home/openharmony
TOOLSDIR=/home/prebuilts/prebuilts

rm -rf /usr/bin/python
ln -s /usr/bin/python2.7 /usr/bin/python

if [[ -d $WORKDIR/third_party/jsframework ]]; then
	echo copy jsframework node_modules
	cd $WORKDIR/third_party/jsframework
	npm install --registry https://registry.npm.taobao.org
fi

if [[ -d $TOOLSDIR/build-tools/common/js-framework ]]; then
	rm -rf $TOOLSDIR/build-tools/common/js-framework
fi
mkdir -p $TOOLSDIR/build-tools/common/js-framework
cp -r $WORKDIR/third_party/jsframework/node_modules $TOOLSDIR/build-tools/common/js-framework

if [[ -d $TOOLSDIR/build-tools/common/nodejs ]]; then
	rm -rf $TOOLSDIR/build-tools/common/nodejs
fi

mkdir -p $TOOLSDIR/build-tools/common/nodejs
cp -r $TOOLSDIR/node-v12.18.4-linux-x64 $TOOLSDIR/build-tools/common/nodejs
cp -r $TOOLSDIR/node-v12.18.4-darwin-x64 $TOOLSDIR/build-tools/common/nodejs

if [[ -h $WORKDIR/prebuilts/cmake ]]; then
	rm $WORKDIR/prebuilts/cmake
fi
echo link cmake
ln -s $TOOLSDIR/cmake $WORKDIR/prebuilts/cmake

if [[ -h $WORKDIR/prebuilts/build-tools ]]; then
	rm $WORKDIR/prebuilts/build-tools
fi
echo link build-tools
ln -s $TOOLSDIR/build-tools $WORKDIR/prebuilts/build-tools

if [[ -h $WORKDIR/prebuilts/python ]]; then
	rm $WORKDIR/prebuilts/python
fi
echo link python
ln -s $TOOLSDIR/python $WORKDIR/prebuilts/python

if [[ -h $WORKDIR/prebuilts/mingw-w64 ]]; then
	rm $WORKDIR/prebuilts/mingw-w64
fi
echo link mingw-w64
ln -s $TOOLSDIR/mingw-w64 $WORKDIR/prebuilts/mingw-w64

mv $TOOLSDIR/clang/host/prebuilts_clang_aosp_linux-x86_64 $TOOLSDIR/clang/host/linux-x86
if [[ -h $WORKDIR/prebuilts/clang ]]; then
	rm $WORKDIR/prebuilts/clang
fi
echo link clang
ln -s $TOOLSDIR/clang $WORKDIR/prebuilts/clang

mv $TOOLSDIR/gcc/linux-x86/arm/prebuilts_gcc_linux-x86_arm_gcc-linaro-7.5.0-arm-linux-gnueabi $TOOLSDIR/gcc/linux-x86/arm/gcc-linaro-7.5.0-arm-linux-gnueabi
if [[ -h $WORKDIR/prebuilts/gcc ]]; then
	rm $WORKDIR/prebuilts/gcc
fi
echo link gcc
ln -s $TOOLSDIR/gcc $WORKDIR/prebuilts/gcc

if [[ -h $WORKDIR/prebuilts/sdk ]]; then
	rm $WORKDIR/prebuilts/sdk
fi
echo link sdk
ln -s $TOOLSDIR/sdk $WORKDIR/prebuilts/sdk

