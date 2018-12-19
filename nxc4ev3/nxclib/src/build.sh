#!/bin/bash

##
## Configuration
##

# C4EV3
C4EV3_DIR="src/native"
C4EV3_LIB="libev3api.a"
C4EV3_HDR="$C4EV3_DIR/include"

# NXCLIB (C + NXC)
NXCLIB_DIR="src/lib_c"
NXCLIB_LIB="nxclib.a"
NXCLIB_CHDR="$NXCLIB_DIR/include"
NXCLIB_NXCHDR="src/lib_nxc"

# output
OUT_LIB="nxclib/lib.c"
OUT_HDR="nxclib"

##
## Functions
##


# build using make
# $1 -> source directory
# $2 -> make flags
function make_dir {
	# go to c4ev3 dir
	pushd "$1"
	# build
	make $2
	# go to root dir
	popd
}

# copy file from source directory
# $1 -> source directory
# $2 -> library name
function install_dir {
	# copy library
	mkdir -p "$OUT_LIB/"
	cp "$1/$2" "$OUT_LIB/$2"
}

# install headers
# $1 -> header directory
# $2 -> directory name for headers (nxclib/include.<this>)
function install_hdr {
	mkdir -p "$OUT_HDR/include.$2/"
	cp -r "$1/." "$OUT_HDR/include.$2/"
}


##
## Start
##

# cd to script dir
cd -P -- "$(dirname -- "$0")"

# print prefix (specifies build compiler)
echo -e "Build config: \n  * PREFIX=\"$PREFIX\"\n\n"


# clean
if [ "x$1" = "xclean" ]; then
	make_dir  "$C4EV3_DIR" "clean"
	make_dir "$NXCLIB_DIR" "clean"
	rm -r "$OUT_LIB/"
	rm -r "$OUT_HDR/"
	exit 0
fi

##
## Headers
##

install_hdr "$C4EV3_HDR"     "c"
install_hdr "$NXCLIB_CHDR"   "c"
install_hdr "$NXCLIB_NXCHDR" "nxc"

##
## Static libraries
##

# clean
#make_dir  "$C4EV3_DIR" "clean"
#make_dir "$NXCLIB_DIR" "clean"

# build
make_dir  "$C4EV3_DIR"
make_dir "$NXCLIB_DIR"

# install
install_dir  "$C4EV3_DIR"  "$C4EV3_LIB"
install_dir "$NXCLIB_DIR" "$NXCLIB_LIB"

