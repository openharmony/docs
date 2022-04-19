# Reference


## Using the build.sh Script to Build Source Code


1. Go to the root directory of the source code and run the build command.
   
   ```
   ./build.sh --product-name name --ccache
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > _name_ indicates the product name, for example, **Hi3516D V300** and **rk3568**.

2. Check the build result. After the build is complete, the following information is displayed in the log:
   
   ```
   post_process
   =====build name successful.
   ```

     Files generated during the build are stored in the **out/{device_name}/** directory, and the generated image is stored in the **out/{device_name}/packages/phone/images/** directory.
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   > For details about other modular compilation operations, see [Building a Standard System](../subsystems/subsys-build-standard-large.md).


## Configuring the Proxy<a name="section6204129143010"></a>


### Setting Up the Python Proxy

1. Create a proxy configuration file.
   
   ```
   mkdir ~/.pipvim ~/.pip/pip.conf
   ```

2. Add the following proxy information to the file, save the file, and exit:
   
   ```
   [global]
   index-url = http:// Proxy URL
   trusted-host = Trusted image path
   timeout = 120
   ```


### Setting Up the npm Proxy

1. Create a proxy configuration file.
   
   ```
   vim ~/.npmrc
   ```

2. Add the following proxy information to the file, save the file, and exit:
   
   ```
   Registry=http:// Proxy URL
   strict-ssl=false
   ```

3. Add the following content to the **.bashrc** file, save the file, and exit:
   
   ```
   export NPM_REGISTRY=http:// Proxy URL
   source .bashrc
   ```
