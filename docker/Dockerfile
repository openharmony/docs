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


FROM ubuntu:20.04
MAINTAINER dongjinguang@huawei.com
WORKDIR /home/openharmony

RUN apt-get update -y \
	&& apt-get install curl wget -y \
	&& apt-get install python3.8 -y \
	&& apt-get install python3-pip -y \
	&& apt-get install dosfstools -y \
	&& apt-get install mtools -y \
	&& apt-get install scons -y \
	&& apt-get install make -y \
	&& apt-get install libffi-dev -y \
	&& apt-get install zip -y \
	&& apt-get install python3-distutils -y \
	&& apt-get install binutils -y \
	&& apt-get install mtd-utils -y \
	&& apt-get install libc6-dev-x32 -y \
	&& rm -rf /bin/sh /usr/bin/python /usr/bin/python3 \
	&& ln -s /bin/bash /bin/sh \
	&& ln -s /usr/bin/python3.8 /usr/bin/python3 \
	&& ln -s /usr/bin/python3.8 /usr/bin/python \
	&& pip3 install --trusted-host mirrors.aliyun.com -i https://mirrors.aliyun.com/pypi/simple setuptools \
	&& pip3 install --trusted-host mirrors.aliyun.com -i https://mirrors.aliyun.com/pypi/simple kconfiglib \
	&& pip3 install --trusted-host mirrors.aliyun.com -i http://mirrors.aliyun.com/pypi/simple pycryptodome \
	&& pip3 install --trusted-host mirrors.aliyun.com -i https://mirrors.aliyun.com/pypi/simple ecdsa \
	&& mkdir -p /home/tools \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/clang/9.0.0-34042/linux/llvm-linux-9.0.0-34042.tar \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/hc-gen/0.65/linux/hc-gen-0.65-linux.tar \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/gcc_riscv32/7.3.0/linux/gcc_riscv32-linux-7.3.0.tar.gz \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/ninja/1.9.0/linux/ninja.1.9.0.tar \
	&& wget -P /home/tools https://repo.huaweicloud.com/harmonyos/compiler/gn/1523/linux/gn.1523.tar \
	&& tar xvf /home/tools/llvm-linux-9.0.0-34042.tar -C /home/tools \
	&& tar xvf /home/tools/hc-gen-0.65-linux.tar -C /home/tools \
	&& tar xvf /home/tools/gcc_riscv32-linux-7.3.0.tar.gz -C /home/tools \
	&& tar xvf /home/tools/ninja.1.9.0.tar -C /home/tools \
	&& tar xvf /home/tools/gn.1523.tar -C /home/tools \
	&& sed -i '$aexport PATH=/home/tools/llvm/bin:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/hc-gen:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/gcc_riscv32/bin:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/ninja:$PATH' /root/.bashrc \
	&& sed -i '$aexport PATH=/home/tools/gn:$PATH' /root/.bashrc \
	&& export PATH=/home/tools/llvm/bin:$PATH \
	&& export PATH=/home/tools/hc-gen:$PATH \
	&& export PATH=/home/tools/gcc_riscv32/bin:$PATH \
	&& export PATH=/home/tools/ninja:$PATH \
	&& export PATH=/home/tools/gn:$PATH \
	&& rm -rf /home/tools/*.tar \
	&& rm -rf /home/tools/*.gz
