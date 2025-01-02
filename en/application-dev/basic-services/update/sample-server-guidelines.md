# Sample Server Development

## How to Develop

1. Generate an SSL certificate.

	Generate the **serverKey.pem** and **serverCert.cer** files for SSL communication of the sample server.

	```
	openssl req -newkey rsa:2048 -nodes -keyout serverKey.pem -x509 -days 365 -out serverCert.cer -subj "/C=CN/ST=GD/L=GZ/O=abc/OU=defg/CN=hijk/emailAddress=test.com"
	```



2. Modify the **bundle.json** file.

	Add **sub_component** to the **build** field.

	```
	"sub_component": [
		"//base/update/updateservice/server_sample:testserver",
		...
	],
	```

3. Create a code directory.

	Go to the **update_updateservice** directory and run the following commands to create a code directory:

	```
	mkdir server_sample                            // Create the server_sample folder.
	touch server_sample/BUILD.gn                   // Create the BUILD.gn file.
	mkdir server_sample/include                    // Create the include folder to store the header file of the sample server.
	touch server_process.h                         // Create the server_process.h header file.
	mkdir server_sample/src                        // Create the src folder to store the C/C++ files of the sample server.
	touch server_sample/src/server_process.c       // Create the server_process.c file.
	touch server_sample/src/main.cpp               // Create the main.cpp file.
	```

4. Write the **BUILD.gn** file.

	The **BUILD.gn** file contains two **ohos** components: **ohos_shared_library** file named **libserver_process.z.so** and **ohos_executable** file named **testserver**.

	```
	import("//build/ohos.gni")

	ohos_shared_library("server_process") {
		sources = [
			"//base/update/updateservice/server_sample/src/server_process.c",
		]

		include_dirs = [
			"//base/update/updateservice/server_sample/include",
			"//third_party/openssl/include",
		]

		deps = [
			"//base/update/updater/services/log:libupdaterlog",
			"//third_party/bounds_checking_function:libsec_static",
			"//third_party/openssl:crypto_source",
			"//third_party/openssl:ssl_source",
			"//utils/native/base:utils",
		]

		part_name = "update_service"
	}

	ohos_executable("testserver") {
		sources = [
			"//base/update/updateservice/server_sample/src/main.cpp",
		]

		include_dirs = [
			"//base/update/updateservice/server_sample/include",
		]

		deps = [
			"//base/update/updateservice/server_sample:server_process",
		]

		part_name = "update_service"
	}
	```

5. Write the **server_process.h** file.

	Declare the sample server APIs in the **server_process.h** file.

	```c++
	#ifndef __SERVER_PROCESS_H__
	#define __SERVER_PROCESS_H__

	/*
	Init: creates a socket environment and presets certain attributes.
	*/
	int Init();

	/*
	SetParam: sets all plug-in parameters.
	*/
	int SetParam(const char *key, const char *value);

	/*
	GetParam: obtains all plug-in parameters.
	*/
	int GetParam(const char *key, char *value);

	/*
	ReverseSetParamCallback: callback.
	*/
	int ReverseSetParamCallback(int(*setParam)(const char *key, const char *value));

	/*
	Open: starts the service.
	*/
	int Open();

	/*
	MainLoop: invoked every 100 ms.
	*/
	int MainLoop();

	/*
	Close: stops the service and releases related resources.
	*/
	int Close();

	#endif //__SERVER_PROCESS_H__
	```

6. Write the **server_process.c** and **main.cpp** files.

	In the **server_process.c** file, mainly declare **respondContent**, the format of the response message returned by the server. Write the **main.cpp** file based on instructions for the common SSL protocol server. Be sure to include related header files and load the **serverKey.pem** and **serverCert.cer** files.

	```c
	#include "server_process.h"

	#include <netinet/in.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>

	#include "openssl/err.h"
	#include "openssl/ssl.h"

	#define SERVER_PEM "/data/sdcard/serverKey.pem"  // Use an absolute path.
	#define SERVER_CER "/data/sdcard/serverCert.cer" // Use an absolute path.

	#define LOG_PRINT(fmt, ...) printf("[ServerProcess][%s:%d] " fmt "\n", __func__, __LINE__, ##__VA_ARGS__)
	#define DO_CHECK(cond, log, ...) \
		if (!(cond)) {\
			LOG_PRINT(log);\
			__VA_ARGS__;\
			return -1;\
		}

	// Implement the function by referring to the APIs in the server_process.h file. Pay attention to the format of the response message from the server.
	respondContent = "{"
		"\"searchStatus\": 0,"
		"\"errMsg\": \"success\","
		"\"checkResults\": [{"
			"\"versionName\": \"sampleVersionName\","
			"\"versionCode\": \"sampleVersionCode\","
			"\"verifyInfo\": \"sampleVerifyInfoSha256Value\","
			"\"size\": 1234567,"
			"\"packageType\": 1,"
			"\"descriptPackageId\": \"abcdefg1234567ABCDEFG\","
		"}],"
		"\"descriptInfo\": [{"
			"\"descriptionType\": 0,"
			"\"content\": \"This package message is used for sampleContent\""
		"}]"
	"}";
	```

7. Start building.

	The **testserver** and **libserver_process.z.so** files are added to the build output directory.

8. Develop an update package.

	For details, see the [update_packaging_tools repository](https://gitee.com/openharmony/update_packaging_tools).

9. Start the package search server.

	Create a directory that contains only English characters on the development board. Place the **testserver**, **libserver_process.z.so**, **serverCert.cer**, and **serverKey.pem** files in the directory, go to the directory, and run the following command to start the package search server:

	```
	./testserver ./libserver_process.z.so &
	```
