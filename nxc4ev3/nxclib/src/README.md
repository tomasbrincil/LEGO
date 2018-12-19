# NXClib - NXC2CC Library

## Build requirements
* GNU99 compiler for EV3
* make
* bash

## Tested build configuration
* Build system: Ubuntu 16.04.1
* EV3 compiler: arm-none-linux-gnueabi-gcc (Sourcery G++ Lite 2009q1-203) 4.3.3
* Make: GNU Make 4.1

## Building
* Set environment variable PREFIX to point to your cross-compiler for the EV3. Example:
```bash
export PREFIX=/home/kuba/sourcery/linux/arm-2009q1/bin/arm-none-linux-gnueabi-
```

* Run bash build script.
```bash
library/build.sh
```

## Copyright

```
NXClib - NXC2CC Library

Copyright (C) 2016-2017  Faculty of Electrical Engineering, CTU in Prague
```
