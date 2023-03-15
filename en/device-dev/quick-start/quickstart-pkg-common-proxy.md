# Configuring the Proxy


### Configuring the Python Proxy

1. Create a proxy configuration file.
     
   ```
   mkdir ~/.pipvim ~/.pip/pip.conf
   ```

2. Add the following proxy information to the file, save the file, and exit:
     
   ```
   [global]
   index-url = http://Proxy URL
   trusted-host = Trusted image path
   timeout = 120
   ```


### Configuring the npm Proxy

1. Create a proxy configuration file.
     
   ```
   vim ~/.npmrc
   ```

2. Add the following proxy information to the file, save the file, and exit:
     
   ```
   Registry=http://Proxy URL
   strict-ssl=false
   ```

3. Add the following content to the **.bashrc** file, save the file, and exit:
     
   ```
   export NPM_REGISTRY=http://Proxy URL
   source .bashrc
   ```
