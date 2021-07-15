# Setting Up Ubuntu Development Environment in Docker Mode and Building Source Code<a name="EN-US_TOPIC_0000001119805112"></a>

-   [Obtaining Standard-System Source Code](#section8761819202511)
    -   [Prerequisites](#section102871547153314)
    -   [Procedure](#section429012478331)

-   [Obtaining the Docker Environment](#section181431248132513)
-   [Building Source Code](#section92391739152318)

The standard OpenHarmony system provides a Docker environment which encapsulates build tools.

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>-   Before using Docker, install it by following instructions in  [Install Docker Engine on Ubuntu](https://docs.docker.com/engine/install/ubuntu/).
>-   You can also use the  [installation package](setting-up-ubuntu-development-environment-with-installation-package-and-building-source-code.md)  to set up the Ubuntu development environment.

## Obtaining Standard-System Source Code<a name="section8761819202511"></a>

### Prerequisites<a name="section102871547153314"></a>

1.  Register your account with Gitee.
2.  Register an SSH public key for access to Gitee.
3.  Install the  [git client](http://git-scm.com/book/en/v2/Getting-Started-Installing-Git)  and  [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading)), and configure basic user information.

    ```
    git config --global user.name "yourname"
    git config --global user.email "your-email-address"
    git config --global credential.helper store
    ```

4.  Run the following commands to install the  **repo**  tool:

    ```
    curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the access permission to this directory, download the tool to any other accessible directory and configure the directory to the environment variable.
    chmod a+x /usr/local/bin/repo
    pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
    ```


### Procedure<a name="section429012478331"></a>

Method 1 \(recommended\): Use the  **repo**  tool to download the source code over SSH. \(You must have registered an SSH public key for access to Gitee.\)

```
repo init -u git@gitee.com:openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

Method 2: Use the  **repo**  tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## Obtaining the Docker Environment<a name="section181431248132513"></a>

**Method 1: Obtaining the Docker image from HUAWEI CLOUD SWR**

1.  Obtain the Docker image.

    ```
    docker pull swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.1
    ```

2.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony swr.cn-south-1.myhuaweicloud.com/openharmony-docker/openharmony-docker-standard:0.0.1
    ```


**Method 2: Using the Dockerfile to build a local docker image**

1.  Obtain the Dockerfile script for a local Docker image.

    ```
    git clone https://gitee.com/openharmony/docs.git
    ```

2.  Go to the directory of the Dockerfile code and run the following command to build the Docker image:

    ```
    cd docs/docker/standard
    ./build.sh
    ```

3.  Go to the root directory of OpenHarmony code and run the following command to access the Docker build environment:

    ```
    docker run -it -v $(pwd):/home/openharmony openharmony-docker-standard:0.0.1
    ```


## Building Source Code<a name="section92391739152318"></a>

1.  Run the preprocessing script in the root directory of the source code.

    ```
    ../scripts/prepare.sh
    ```

2.  Run the following script to start building for Standard-System Devices \(reference memory ≥ 128 MB\):

    ```
    ./build.sh --product-name {product_name}
    ```

    **product\_name**  indicates the product supported by the current distribution, for example,  **Hi3516DV300**.

    Files generated during the build are stored in the  **out/ohos-arm-release/**  directory, and the generated image is stored in the  **out/ohos-arm-release/packages/phone/images/**  directory.

3.  Burn the image. For details, see  [Burning Images](burning-images.md).

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>You can exit Docker by simply running the  **exit**  command.

