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
# 代码下载目录
code_dir=/home/prebuilts
# 二进制所在目录,用于临时存放二进制,二进制整个大小约10G,请确保有足够的空间
bin_dir=/tmp/prebuilts
# 二进制关系
copy_config="""
prebuilts/cmake,https://repo.huaweicloud.com/harmonyos/compiler/cmake/3.16.5/darwin/cmake-darwin-x86-3.16.5.tar.gz
prebuilts/cmake,https://repo.huaweicloud.com/harmonyos/compiler/cmake/3.16.5/linux/cmake-linux-x86-3.16.5.tar.gz
prebuilts/cmake,https://repo.huaweicloud.com/harmonyos/compiler/cmake/3.16.5/windows/cmake-windows-x86-3.16.5.tar.gz
prebuilts/build-tools/darwin-x86/bin,https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/darwin/gn-darwin-x86-1717.tar.gz
prebuilts/build-tools/linux-x86/bin,https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/linux/gn-linux-x86-1717.tar.gz
prebuilts/build-tools/darwin-x86/bin,https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.10.1/darwin/ninja-darwin-x86-1.10.1.tar.gz
prebuilts/build-tools/linux-x86/bin,https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.10.1/linux/ninja-linux-x86-1.10.1.tar.gz
prebuilts/python,https://repo.huaweicloud.com/harmonyos/compiler/python/3.8.5/darwin/python-darwin-x86-3.8.5.tar.gz
prebuilts/python,https://repo.huaweicloud.com/harmonyos/compiler/python/3.8.5/linux/python-linux-x86-3.8.5.tar.gz
prebuilts/mingw-w64/ohos/linux-x86_64,https://repo.huaweicloud.com/harmonyos/compiler/mingw-w64/7.0.0/clang-mingw.tar.gz
prebuilts,https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar
prebuilts/gcc/linux-x86/arm,https://repo.huaweicloud.com/harmonyos/compiler/prebuilts_gcc_linux-x86_arm_gcc-linaro-7.5.0-arm-linux-gnueabi/1.0/prebuilts_gcc_linux-x86_arm_gcc-linaro-7.5.0-arm-linux-gnueabi.tar.gz
prebuilts/clang/host,https://repo.huaweicloud.com/harmonyos/compiler/prebuilts_clang_aosp_linux-x86_64/1.0/prebuilts_clang_aosp_linux-x86_64.tar.gz
prebuilts/sdk/js-loader/build-tools,https://repo.huaweicloud.com/harmonyos/compiler/ace-loader/1.0/ace-loader.tar.gz
"""
if [ ! -d "${bin_dir}" ];then
    mkdir -p "${bin_dir}"
fi

for i in `echo ${copy_config}`
do
    unzip_dir=`echo $i|awk -F ',' '{print $1}'`
    huaweicloud_url=`echo $i|awk -F ',' '{print $2}'`
    md5_huaweicloud_url=`echo ${huaweicloud_url}|md5sum|awk '{print $1}'`
    bin_file=`basename ${huaweicloud_url}`
    bin_file_suffix=${bin_file#*.}
    #huaweicloud_file_name=`echo ${huaweicloud_url}|awk -F '/' '{print $NF}'`

    if [ ! -d "${code_dir}/${unzip_dir}" ];then
        mkdir -p "${code_dir}/${unzip_dir}"
    fi
    if [ ! -f "${bin_dir}/${md5_huaweicloud_url}.${bin_file_suffix}" ];then
        # 代理不需要鉴权: wget -P ${bin_dir} -e "https_proxy=http://domain.com:port" ${huaweicloud_url}
        # 代理需要鉴权(账号密码特殊字符均需要URL转义): wget -P ${bin_dir} -e "https_proxy=http://username:password@domain.com:port" ${huaweicloud_url}
        # 不需要代理
        wget -O ${bin_dir}/${md5_huaweicloud_url}.${bin_file_suffix}  ${huaweicloud_url}
    fi
    if [ "X${bin_file_suffix:0-3}" = "Xzip" ];then
        unzip "${bin_dir}/${md5_huaweicloud_url}.${bin_file_suffix}" -d "${code_dir}/${unzip_dir}/"
    elif [ "X${bin_file_suffix:0-6}" = "Xtar.gz" ];then
        tar -xvzf "${bin_dir}/${md5_huaweicloud_url}.${bin_file_suffix}"  -C  "${code_dir}/${unzip_dir}"
    else
        tar -xvf "${bin_dir}/${md5_huaweicloud_url}.${bin_file_suffix}"  -C  "${code_dir}/${unzip_dir}"
    fi
done
