# Obtaining Source Code<a name="EN-US_TOPIC_0000001150448437"></a>

## About OpenHarmony<a name="section6370143622110"></a>

OpenHarmony is an open-source project launched by the OpenAtom Foundation. The purpose of this project is to build an open, distributed operating system \(OS\) framework for smart IoT devices in the full-scenario, full-connectivity, and full-intelligence era. 

The open-source code repositories are available at [https://openharmony.gitee.com](https://openharmony.gitee.com).

## Overview of Source Code Acquisition<a name="section12763342204"></a>

You can use any of the following methods to acquire the OpenHarmony source code:

-   **Method 1**: Acquire the source code from the Gitee code repository. You can use the **repo** or **git** tool to download the latest code from the code repository.
-   **Method 2**: Acquire the source code from [DevEco Marketplace](https://repo.harmonyos.com/#/en/home). Visit [DevEco Marketplace](https://repo.harmonyos.com/#/en/home), search for your desired open-source distribution, and download the bundle list \(or customize bundles and download the bundle list\). Then use the **hpm-cli** tool to download and install the bundles and compilation toolchain on your local PC.
-   **Method 3**: Download the compressed file of a distribution from a mirror site. This method provides a fast download speed, so you can also use this method for obtaining the source code of an earlier version.
-   **Method 4**: Acquire the source code from the GitHub image repository. You can use the **repo** or **git** tool to download the latest code from the code repository.

## Method 1: Acquiring Source Code from the Gitee Code Repository<a name="section537312010229"></a>

### When to Use<a name="section10881513459"></a>

-   You want to establish a baseline based on stable OpenHarmony releases and distribute the baseline to your customers.

-   You have interconnected your software with OpenHarmony and need official certification from OpenHarmony.

-   You want to contribute code to the OpenHarmony community after obtaining official OpenHarmony certification for chips, modules, and applications.

-   You need to rectify OpenHarmony issues.

-   You want to learn OpenHarmony source code.


### Prerequisites<a name="section102871547153314"></a>

1.  Register your account with Gitee.
2.  Register an SSH public key for access to Gitee.
3.  Install the [git client](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) and [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading), and configure basic user information.

    ```
    git config --global user.name "yourname"
    git config --global user.email "your-email-address"
    git config --global credential.helper store
    ```

4.  Run the following commands to install the **repo** tool:

    ```
    curl https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 -o /usr/local/bin/repo  # If you do not have the access permission to this directory, download the tool to any other accessible directory and configure the directory to the environment variable.
    chmod a+x /usr/local/bin/repo
    pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
    ```


### How to Use<a name="section429012478331"></a>


>![](../public_sys-resources/icon-note.gif) **NOTE**<br>
>Download the master code if you want to get quick access to the latest features for your development. Download the release code, which is more stable, if you want to develop commercial functionalities.

-   **Obtaining OpenHarmony master code**

    Method 1 \(recommended\): Use the **repo** tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)

    ```
    repo init -u git@gitee.com:openharmony/manifest.git -b master --no-repo-verify
    repo sync -c
    repo forall -c 'git lfs pull'
    ```

    Method 2: Use the **repo** tool to download the source code over HTTPS.

    ```
    repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
    repo sync -c
    repo forall -c 'git lfs pull'
    ```

-   **Obtaining OpenHarmony release code**

    For details about how to obtain the source code of an OpenHarmony release, see the [Release-Notes](../../release-notes/Readme.md).


## Method 2: Acquiring Source Code from DevEco Marketplace<a name="section463013147412"></a>

### When to Use<a name="section26661067443"></a>

If OpenHarmony is new to you, sample solutions are helpful to your development. You can obtain an open-source distribution from [DevEco Marketplace](https://repo.harmonyos.com/#/en/home), or customize a distribution by adding or deleting bundles of an open-source distribution. Then use the **hpm-cli** tool to download and install the bundles and compilation toolchain on your local PC.

### Prerequisites<a name="section17544943123315"></a>

You must install **Node.js** and HPM on your local PC. The installation procedure is as follows:

1.  Install **Node.js**.

    Download **Node.js** from its official website and install it on your local PC.

    The [Node.js](https://nodejs.org/) version must be 12.x \(including npm 6.14.4\) or later. An LTS version is recommended.

2.  Install the **hpm-cli** tool using **npm** delivered with **Node.js**.

    Open the CMD window and run the following command:

    ```
    npm install -g @ohos/hpm-cli
    ```

3.  Run the following command to check whether the installation is successful. If the HPM version is displayed, the installation is successful.

    ```
    hpm -V or hpm --version
    ```

4.  Run the following command to upgrade the HPM version:

    ```
    npm update -g @ohos/hpm-cli
    ```


### How to Use<a name="section954619433333"></a>

1.  Search for distributions.
    1.  Access [DevEco Marketplace](https://repo.harmonyos.com/#/en/home), and click **Equipment Bundle**. Then go to the **Open Source Distribution** page.
    2.  Enter a keyword \(for example: **camera**\) in the search box. All matched distributions are found.
    3.  Specify filter criteria, such as the bundle type \(for example: **Board support** or **Kernel support**\), to further filter the distributions.
    4.  Find your desired distribution and click it to view details.

        **Figure 1**  HPM page<a name="fig349416264520"></a> 
        ![](figure/hpm-page.png "hpm-page")

2.  Learn more about the distribution.

    1.  Read carefully the information about the distribution to learn its application scenarios, features, bundles, usage, and customization methods, as shown in the following figure.
    2.  Click **Download** if you want to download the distribution to your local PC.
    3.  Click **Custom** if you want to add or delete bundles of the distribution.

        **Figure 2**  Example distribution<a name="fig142484411121"></a> 
        ![](figure/example-distribution.png "example-distribution")

3.  Customize bundles.
    1.  Access the **Custom solution** page, as shown in the following figure.
    2.  Set the toggle switch next to a specific optional bundle to delete it from the distribution, or click **Add bundle** to add new bundles.
    3.  Enter the basic information about your project, including the bundle name, version, and description, on the right pane.
    4.  Click **Download**. The system generates the OpenHarmony code structure file \(for example, **my\_cust\_dist.zip**\) and saves it to your local PC.

        **Figure 3**  Customizing bundles<a name="fig1256020372197"></a>  
        ![](figure/customizing-bundles.png "customizing-bundles")

4.  Install bundles.
    1.  Decompress the downloaded code structure file using CMD on Windows (or shell in Linux).
    2.  In the generated directory, run the **hpm install** command to download and install bundles. If the **Install successful** message is displayed, the command has been executed successfully.
    3.  Obtain the bundles. The downloaded bundles are stored in the **ohos\_bundles** folder under the project directory. \(The source code of some bundles will be copied to a specified directory after the bundles are installed.\)


## Method 3: Acquiring Source Code from a Mirror Site<a name="section1186691118430"></a>

To ensure the download performance, you are advised to download the source code or the corresponding solution from the image library of the respective site listed in the table below.

The table below provides only the sites for downloading the latest OpenHarmony LTS code. For details about how to obtain the source code of earlier versions, see the [Release-Notes](../../release-notes/Readme.md). 

**Table 1**  Sites for acquiring source code 

<a name="table17735923173912"></a>
<table><thead align="left"><tr id="row1073515237392"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p5109183611392"><a name="p5109183611392"></a><a name="p5109183611392"></a><strong id="b31091936183918"><a name="b31091936183918"></a><a name="b31091936183918"></a>LTS Code</strong></p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p13109436103916"><a name="p13109436103916"></a><a name="p13109436103916"></a><strong id="b191091936153912"><a name="b191091936153912"></a><a name="b191091936153912"></a>Version Information</strong></p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p610923616398"><a name="p610923616398"></a><a name="p610923616398"></a><strong id="b1210920365393"><a name="b1210920365393"></a><a name="b1210920365393"></a>Site</strong></p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p2109736133914"><a name="p2109736133914"></a><a name="p2109736133914"></a><strong id="b18109113613397"><a name="b18109113613397"></a><a name="b18109113613397"></a>SHA-256 Verification Code</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row17736152318398"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1110983610395"><a name="p1110983610395"></a><a name="p1110983610395"></a>Full code base (for mini, small, and standard systems)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p151091536143915"><a name="p151091536143915"></a><a name="p151091536143915"></a>3.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15931114016546"><a name="p15931114016546"></a><a name="p15931114016546"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/code-v3.0-LTS.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p3770144281415"><a name="p3770144281415"></a><a name="p3770144281415"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/code-v3.0-LTS.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row14814218214"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p2481132228"><a name="p2481132228"></a><a name="p2481132228"></a>Standard system solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p94811121629"><a name="p94811121629"></a><a name="p94811121629"></a>3.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1358555631"><a name="p1358555631"></a><a name="p1358555631"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/standard.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p10581551639"><a name="p10581551639"></a><a name="p10581551639"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/standard.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row473612318396"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p511014369394"><a name="p511014369394"></a><a name="p511014369394"></a>Hi3861 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p0110036193911"><a name="p0110036193911"></a><a name="p0110036193911"></a>3.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p29291940175415"><a name="p29291940175415"></a><a name="p29291940175415"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_pegasus.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p134864584147"><a name="p134864584147"></a><a name="p134864584147"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_pegasus.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row873614239395"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p11110113633913"><a name="p11110113633913"></a><a name="p11110113633913"></a>Hi3518 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p18110193613391"><a name="p18110193613391"></a><a name="p18110193613391"></a>3.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p125681045181518"><a name="p125681045181518"></a><a name="p125681045181518"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_aries.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p4607175915149"><a name="p4607175915149"></a><a name="p4607175915149"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_aries.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row1273682343914"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p15110123693919"><a name="p15110123693919"></a><a name="p15110123693919"></a>Hi3516 solution-LiteOS (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1211012362396"><a name="p1211012362396"></a><a name="p1211012362396"></a>3.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p10455184661518"><a name="p10455184661518"></a><a name="p10455184661518"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p84951102150"><a name="p84951102150"></a><a name="p84951102150"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row18945941460"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p12945204118618"><a name="p12945204118618"></a><a name="p12945204118618"></a>Hi3516 solution-Linux (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p7686415384"><a name="p7686415384"></a><a name="p7686415384"></a>3.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p156861155812"><a name="p156861155812"></a><a name="p156861155812"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus_linux.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p16686201510815"><a name="p16686201510815"></a><a name="p16686201510815"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.0/hispark_taurus_linux.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row167371123163914"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p10110143610393"><a name="p10110143610393"></a><a name="p10110143610393"></a>RELEASE-NOTES</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p141101436193911"><a name="p141101436193911"></a><a name="p141101436193911"></a>3.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p88931840195416"><a name="p88931840195416"></a><a name="p88931840195416"></a><a href="https://gitee.com/openharmony/docs/blob/OpenHarmony-3.0-LTS/zh-cn/release-notes/OpenHarmony-v3.0-LTS.md" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p039662242117"><a name="p039662242117"></a><a name="p039662242117"></a>-</p>
</td>
</tr>
<tr id="row573719239393"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p104146493390"><a name="p104146493390"></a><a name="p104146493390"></a><strong id="b12414104919398"><a name="b12414104919398"></a><a name="b12414104919398"></a>Latest Release Code</strong></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p194141849163919"><a name="p194141849163919"></a><a name="p194141849163919"></a><strong id="b441494913918"><a name="b441494913918"></a><a name="b441494913918"></a>Version Information</strong></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p8414649193919"><a name="p8414649193919"></a><a name="p8414649193919"></a><strong id="b341584914393"><a name="b341584914393"></a><a name="b341584914393"></a>Site</strong></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p13415149133914"><a name="p13415149133914"></a><a name="p13415149133914"></a><strong id="b8415114953915"><a name="b8415114953915"></a><a name="b8415114953915"></a>SHA-256 Verification Code</strong></p>
</td>
</tr>
<tr id="row18518114121312"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p4437184283419"><a name="p4437184283419"></a><a name="p4437184283419"></a>Full code base (for mini, small, and standard systems)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p15437144213345"><a name="p15437144213345"></a><a name="p15437144213345"></a>3.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p64379420343"><a name="p64379420343"></a><a name="p64379420343"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/code-v3.1-Release.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p13437842103414"><a name="p13437842103414"></a><a name="p13437842103414"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/code-v3.1-Release.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row461814235717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p0618124216579"><a name="p0618124216579"></a><a name="p0618124216579"></a>Hi3516 standard system solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p156181142145714"><a name="p156181142145714"></a><a name="p156181142145714"></a>3.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p16619174275717"><a name="p16619174275717"></a><a name="p16619174275717"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/standard_hi3516.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p79771324121813"><a name="p79771324121813"></a><a name="p79771324121813"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/standard_hi3516.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row162201392319"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p2220191315"><a name="p2220191315"></a><a name="p2220191315"></a>RK3568 standard system solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p6220191312"><a name="p6220191312"></a><a name="p6220191312"></a>3.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p522019916317"><a name="p522019916317"></a><a name="p522019916317"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/standard_rk3568.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p18742268187"><a name="p18742268187"></a><a name="p18742268187"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/standard_rk3568.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row148666201519"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p18867820165113"><a name="p18867820165113"></a><a name="p18867820165113"></a>Hi3861 solution (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p108671520115118"><a name="p108671520115118"></a><a name="p108671520115118"></a>3.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p19867202085113"><a name="p19867202085113"></a><a name="p19867202085113"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_pegasus.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p193613276183"><a name="p193613276183"></a><a name="p193613276183"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_pegasus.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row6114461545"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p630312351557"><a name="p630312351557"></a><a name="p630312351557"></a>Hi3516 solution-LiteOS (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1612646125413"><a name="p1612646125413"></a><a name="p1612646125413"></a>3.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p8123467546"><a name="p8123467546"></a><a name="p8123467546"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_taurus.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p197721270187"><a name="p197721270187"></a><a name="p197721270187"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_taurus.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row152143765612"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p530833917567"><a name="p530833917567"></a><a name="p530833917567"></a>Hi3516 solution-Linux (binary)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p19213372563"><a name="p19213372563"></a><a name="p19213372563"></a>3.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1921337205612"><a name="p1921337205612"></a><a name="p1921337205612"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_taurus_linux.tar.gz" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p14441122810188"><a name="p14441122810188"></a><a name="p14441122810188"></a><a href="https://repo.huaweicloud.com/harmonyos/os/3.1-Release/hispark_taurus_linux.tar.gz.sha256" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
</tr>
<tr id="row1663285502319"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1961810962416"><a name="p1961810962416"></a><a name="p1961810962416"></a>RELEASE-NOTES</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p146331255172318"><a name="p146331255172318"></a><a name="p146331255172318"></a>3.1 Release</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p18800131862419"><a name="p18800131862419"></a><a name="p18800131862419"></a><a href="https://gitee.com/openharmony/docs/blob/master/en/release-notes/OpenHarmony-v3.1-release.md" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p8633855132314"><a name="p8633855132314"></a><a name="p8633855132314"></a>-</p>
</td>
</tr>
<tr id="row19937626418"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1938221842"><a name="p1938221842"></a><a name="p1938221842"></a><strong id="b1393619251243"><a name="b1393619251243"></a><a name="b1393619251243"></a>Compiler Toolchain</strong></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1093810218417"><a name="p1093810218417"></a><a name="p1093810218417"></a><strong id="b1416114641015"><a name="b1416114641015"></a><a name="b1416114641015"></a>Version Information</strong></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p9938132648"><a name="p9938132648"></a><a name="p9938132648"></a><strong id="b14842143351015"><a name="b14842143351015"></a><a name="b14842143351015"></a>Site</strong></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p12520113711011"><a name="p12520113711011"></a><a name="p12520113711011"></a><strong id="b17520237181015"><a name="b17520237181015"></a><a name="b17520237181015"></a>SHA-256 Verification Code</strong></p>
</td>
</tr>
<tr id="row204197817410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p8419118242"><a name="p8419118242"></a><a name="p8419118242"></a>Compiler toolchain</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p10876124517162"><a name="p10876124517162"></a><a name="p10876124517162"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1542078742"><a name="p1542078742"></a><a name="p1542078742"></a><a href="https://repo.huaweicloud.com/harmonyos/os/2.0/tool_chain/" target="_blank" rel="noopener noreferrer">Download</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p134201881147"><a name="p134201881147"></a><a name="p134201881147"></a>-</p>
</td>
</tr>
</tbody>
</table>

## Method 4: Acquiring Source Code from the GitHub Image Repository<a name="section23448418360"></a>

>![](../public_sys-resources/icon-note.gif) **NOTE**<br>
> The image repository is synchronized at 23:00 (UTC +8:00) every day.

Method 1 \(recommended\): Use the **repo** tool to download the source code over SSH. \(You must have registered an SSH public key for access to GitHub. For details, see [Adding a new SSH key to your GitHub account](https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account).\)

```
repo init -u git@github.com:openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the **repo** tool to download the source code over HTTPS.

```
repo init -u https://github.com/openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## Source Code Directories<a name="section1072115612811"></a>

The following table describes the OpenHarmony source code directories.

**Table 2**  Source code directories

<a name="table3815144702820"></a>
<table><thead align="left"><tr id="row198162047192810"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p690319291299"><a name="p690319291299"></a><a name="p690319291299"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p5903122962918"><a name="p5903122962918"></a><a name="p5903122962918"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1981674719280"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p69031429162912"><a name="p69031429162912"></a><a name="p69031429162912"></a>applications</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p090352912914"><a name="p090352912914"></a><a name="p090352912914"></a>Application samples, for example, <strong id="b689814231158"><a name="b689814231158"></a><a name="b689814231158"></a>camera</strong></p>
</td>
</tr>
<tr id="row5816747132817"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p99031129112918"><a name="p99031129112918"></a><a name="p99031129112918"></a>base</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p790472962914"><a name="p790472962914"></a><a name="p790472962914"></a>Basic software service subsystem set and hardware service subsystem set</p>
</td>
</tr>
<tr id="row1134218692910"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p4904112910295"><a name="p4904112910295"></a><a name="p4904112910295"></a>build</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1090482942911"><a name="p1090482942911"></a><a name="p1090482942911"></a>Bundle-based compilation, build, and configuration scripts</p>
</td>
</tr>
<tr id="row8166154261316"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1216719425130"><a name="p1216719425130"></a><a name="p1216719425130"></a>docs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17167134217134"><a name="p17167134217134"></a><a name="p17167134217134"></a>Reference documents</p>
</td>
</tr>
<tr id="row1841618902919"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1390462902910"><a name="p1390462902910"></a><a name="p1390462902910"></a>domains</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1390432914296"><a name="p1390432914296"></a><a name="p1390432914296"></a>Enhanced software service subsystem set</p>
</td>
</tr>
<tr id="row841620912298"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p119041629182919"><a name="p119041629182919"></a><a name="p119041629182919"></a>drivers</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9904629132911"><a name="p9904629132911"></a><a name="p9904629132911"></a>Driver subsystem</p>
</td>
</tr>
<tr id="row164164992915"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p79042298298"><a name="p79042298298"></a><a name="p79042298298"></a>foundation</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18904132922915"><a name="p18904132922915"></a><a name="p18904132922915"></a>Basic system capability subsystem set</p>
</td>
</tr>
<tr id="row1441610922915"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p490402916299"><a name="p490402916299"></a><a name="p490402916299"></a>kernel</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1904112932912"><a name="p1904112932912"></a><a name="p1904112932912"></a>Kernel subsystem</p>
</td>
</tr>
<tr id="row194175972917"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1904132912910"><a name="p1904132912910"></a><a name="p1904132912910"></a>prebuilts</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p390492919296"><a name="p390492919296"></a><a name="p390492919296"></a>Compiler and toolchain subsystem</p>
</td>
</tr>
<tr id="row841718942913"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12904929202919"><a name="p12904929202919"></a><a name="p12904929202919"></a>test</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p4904152912297"><a name="p4904152912297"></a><a name="p4904152912297"></a>Testing subsystem</p>
</td>
</tr>
<tr id="row24175915294"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13904162992916"><a name="p13904162992916"></a><a name="p13904162992916"></a>third_party</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p6904829112917"><a name="p6904829112917"></a><a name="p6904829112917"></a>Open-source third-party software</p>
</td>
</tr>
<tr id="row334210652914"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1390442918299"><a name="p1390442918299"></a><a name="p1390442918299"></a>utils</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p690412296297"><a name="p690412296297"></a><a name="p690412296297"></a>Commonly used development tools</p>
</td>
</tr>
<tr id="row73421664298"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7905172920292"><a name="p7905172920292"></a><a name="p7905172920292"></a>vendor</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p290510290293"><a name="p290510290293"></a><a name="p290510290293"></a>Vendor-provided software</p>
</td>
</tr>
<tr id="row734319617292"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p09056291290"><a name="p09056291290"></a><a name="p09056291290"></a>build.py</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1790542912290"><a name="p1790542912290"></a><a name="p1790542912290"></a>Compilation script file</p>
</td>
</tr>
</tbody>
</table>
