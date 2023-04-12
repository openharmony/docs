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


FROM ubuntu:18.04
WORKDIR /home/openharmony

RUN sed -i "s@http://.*archive.ubuntu.com@http://repo.huaweicloud.com@g" /etc/apt/sources.list \
	&& sed -i "s@http://.*security.ubuntu.com@http://repo.huaweicloud.com@g" /etc/apt/sources.list \
	&& apt-get update -y \
	&& apt-get install -y apt-utils binutils bison flex bc build-essential make mtd-utils gcc-arm-linux-gnueabi u-boot-tools python3.8 python3-pip git zip unzip curl wget gcc g++ ruby=1:2.5.1 dosfstools mtools default-jre default-jdk scons python3.8-distutils perl openssl libssl-dev cpio git-lfs m4 ccache zlib1g-dev tar rsync liblz4-tool genext2fs binutils-dev device-tree-compiler e2fsprogs git-core gnupg gnutls-bin gperf lib32ncurses5-dev libffi-dev zlib* libelf-dev libx11-dev libgl1-mesa-dev lib32z1-dev xsltproc x11proto-core-dev libc6-dev-i386 libxml2-dev lib32z-dev libdwarf-dev \
	&& apt-get install -y grsync xxd libglib2.0-dev libpixman-1-dev kmod jfsutils reiserfsprogs xfsprogs squashfs-tools  pcmciautils quota ppp libtinfo-dev libtinfo5 libncurses5 libncurses5-dev libncursesw5 libstdc++6 python2.7 gcc-arm-none-eabi \
	&& apt-get install -y vim ssh locales \
	&& apt-get install -y doxygen \
	&& locale-gen "en_US.UTF-8" \
	&& rm -rf /bin/sh /usr/bin/python /usr/bin/python3 /usr/bin/python3m \
	&& ln -s /bin/bash /bin/sh \
	&& ln -s /usr/bin/python3.8 /usr/bin/python3 \
	&& ln -s /usr/bin/python3.8 /usr/bin/python3m \
	&& ln -s /usr/bin/python3.8 /usr/bin/python \
	&& curl https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/bin/repo \
	&& chmod +x /usr/bin/repo \
	&& pip3 install --trusted-host https://repo.huaweicloud.com -i https://repo.huaweicloud.com/repository/pypi/simple requests setuptools pymongo kconfiglib pycryptodome ecdsa ohos-build pyyaml prompt_toolkit==1.0.14 redis json2html yagmail python-jenkins \
	&& pip3 install esdk-obs-python --trusted-host pypi.org \
	&& pip3 install six --upgrade --ignore-installed six \
	&& mkdir -p /home/tools \
	&& mkdir -p /home/tools/gn \
	&& wget -P /home/tools https://repo.huaweicloud.com/openharmony/compiler/clang/12.0.1-530132/linux/clang-530132-linux-x86_64.tar.bz2 \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/gcc_riscv32/7.3.0/linux/gcc_riscv32-linux-7.3.0.tar.gz \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/gn/1717/linux/gn-linux-x86-1717.tar.gz \
	&& wget -P /home/tools https://mirrors.huaweicloud.com/nodejs/v14.15.4/node-v14.15.4-linux-x64.tar.xz \
	&& wget -P /home/tools https://hm-verify.obs.cn-north-4.myhuaweicloud.com/qemu-5.2.0.tar.xz \
    	&& tar -jxvf /home/tools/clang-530132-linux-x86_64.tar.bz2 -C /home/tools \
		&& mv /home/tools/clang-530132 /home/tools/llvm \
	&& tar -xvf /home/tools/hc-gen-0.65-linux.tar -C /home/tools \
	&& tar -xvf /home/tools/gcc_riscv32-linux-7.3.0.tar.gz -C /home/tools \
	&& tar -xvf /home/tools/ninja.1.9.0.tar -C /home/tools \
	&& tar -xvf /home/tools/gn-linux-x86-1717.tar.gz -C /home/tools/gn \
	&& tar -xJf /home/tools/node-v14.15.4-linux-x64.tar.xz -C /home/tools \
	&& cp /home/tools/node-v14.15.4-linux-x64/bin/node /usr/local/bin \
	&& ln -s /home/tools/node-v14.15.4-linux-x64/lib/node_modules/npm/bin/npm-cli.js /usr/local/bin/npm \
	&& ln -s /home/tools/node-v14.15.4-linux-x64/lib/node_modules/npm/bin/npx-cli.js /usr/local/bin/npx \
	&& tar -xJf /home/tools/qemu-5.2.0.tar.xz -C /home/tools \
	&& sed -i '$aexport PATH=/home/tools/llvm/bin:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/hc-gen:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/gcc_riscv32/bin:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/ninja:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/node-v14.15.4-linux-x64/bin:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/gn:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/root/.local/bin:$PATH' /root/.bashrc \
	&& export PATH=/home/tools/llvm/bin:$PATH \
	&& export PATH=/home/tools/hc-gen:$PATH \
	&& export PATH=/home/tools/gcc_riscv32/bin:$PATH \
	&& export PATH=/home/tools/ninja:$PATH \
	&& export PATH=/home/tools/node-v12.20.0-linux-x64/bin:$PATH \
	&& export PATH=/home/tools/gn:$PATH \
	&& export PATH=/root/.local/bin:$PATH \
	&& cd /home/tools/qemu-5.2.0 \
	&& mkdir build \
	&& cd build \
	&& ../configure --target-list=arm-softmmu \
	&& make -j \
	&& make install \
	&& cd /home/openharmony \
	&& rm -rf /home/tools/*.tar \
	&& rm -rf /home/tools/*.gz \
	&& rm -rf /home/tools/*.xz \
	&& rm -rf /home/tools/qemu-5.2.0 \
	&& npm install -g @ohos/hpm-cli --registry https://mirrors.huaweicloud.com/repository/npm/

ENV LANG=en_US.UTF-8 LANGUAGE=en_US.UTF-8 LC_ALL=en_US.UTF-8
