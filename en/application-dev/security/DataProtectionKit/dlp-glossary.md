# Data Protection Kit Glossary

<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--Designer: @QRF-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=7f9c725959b4976deb309db020b89c3bd15579ab translatedAt=2026-08-11T01:56:42.119Z pushedAt=2026-08-11T02:21:34.308Z -->

## D

### Data Loss Prevention (DLP)

A system-level data loss prevention solution that provides capabilities such as cross-device file permission management, encrypted storage, and authorized access. DLP technology helps protect the security of sensitive files and prevent data leakage.

### DLP File

A permission-controlled file encrypted with DLP, with the .dlp extension. Only users in the authorized list can open it. Authorization is classified into full control permission and read-only permission. The system restricts user operations on the file based on the authorization policy.

### DLP Sandbox

An isolated runtime environment used for opening DLP files. The sandbox is automatically installed when a DLP file is opened and automatically uninstalled when the DLP file is closed. The sandbox environment provides app isolation and data protection, preventing sensitive data in DLP files from leaking into uncontrolled environments.

## F

### Filesystem in Userspace (FUSE)

A virtual file system used to manage DLP files. Link files are created through FUSE technology to enable transparent access to and management of DLP files. Read and write operations on link files are synchronized to the corresponding DLP files, providing a convenient file operation API.