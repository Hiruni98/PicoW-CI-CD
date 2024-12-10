# CHANGELOG.md

## [v0.0.5] - 2024-12-10
### Fixes:
- Fixed bug where LED blink rate was inconsistent under certain conditions.
- Corrected path issue in Dockerfile that caused build failures on macOS M3.

### Features:
- Improved LED control function to allow customizable blink patterns.
- Added new test cases to validate the LED functionality in different scenarios.

### CI/CD:
- Enhanced GitHub Actions workflow to automatically build and test on push to `main` and tag-based releases.

## v0.0.4
Fixes:
 - fixed LED test
 - updated actions/checkout@v3 to actions/checkout@v4

Features:
 - added LED functionality

## v0.0.3
Fixes:
 - changed probe ID

Features:
 - cleanup

## v0.0.2
Fixes:
 - Updated CTest command

Features:
 - none

## v0.0.1
Fixes:
 - None

Features:
 - Initial version of application
