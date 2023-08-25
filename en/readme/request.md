# Upload and Download Subsystem

## Introduction

The upload and download subsystem provides upload and download capabilities for applications, including creating, removing, suspending, and starting upload and download tasks, and subscribing to the task progress and result.


## System Architecture

**Figure 1** Architecture of the upload and download subsystem


![](figures /architecture-of-the-upload-and-download-subsystem.png "Architecture of the upload and download subsystem")

## Directory Structure

The source code of the upload and download subsystem is stored in the **/base/request** directory.

The directory structure is as follows:

```
/base/request/request
├── common                   # Common classes such as constants and logs
├── figures                  # Architecture diagram
├── framework                # Framework layer
│   └── js                      # JS APIs that are parsed to NAPIs
│   └── native                  # Client implementation
├── services                 # Upload and download service implementation.
│   └── sa_profile              # System service configuration files
│   └── etc                     # Process configuration files
└── test                     # Test cases
```

## Repositories Involved

[request_request](https://gitee.com/openharmony/request_request)
