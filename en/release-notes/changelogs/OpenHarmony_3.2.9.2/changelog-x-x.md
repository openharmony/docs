# *Example* Subsystem ChangeLog

Changes that affect contract compatibility of the last version should be described in the ChangeLog. The changes include but are not limited to those related to API names, parameters, return values, required permissions, call sequence, enumerated values, configuration parameters, and paths. The last version can be an LTS, release, beta, or monthly version, or the like. Contract compatibility, also called semantic compatibility, means that the original program behavior should remain consistent over versions.

## cl.subsystemname.x xxx Function Change (Example: DeviceType Attribute Change or Camera Permission Change. Use a short description.)

Add the number **cl.*subsystemname*.*x*** before each change title, where **cl** is the abbreviation of ChangeLog, *subsystemname* is the standard English name of the subsystem, and *x* indicates the change sequence number (starting from 1 in ascending order).

Describe the changes in terms of functions. Example: *n* and *m* of the *a* function are changed. Developers need to adapt their applications based on the change description.

If there is a requirement or design document corresponding to the change, attach the requirement number or design document number in the description.

**Change Impacts**

Describe whether released APIs (JS or native APIs) are affected or API behavior is changed.

Describe whether available applications are affected, that is, whether an adaptation is required for building the application code in the SDK environment of the new version.

**Key API/Component Changes**

List the API/component changes involved in the function change.

**Adaptation Guide (Optional)**

Provide guidance for developers on how to adapt their application to the changes to be compatible with the new version.

Example:

Change parameter *n* to *m* in the *a* file.

```
sample code
```
