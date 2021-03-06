#-------------------------------------------------------------------------------
# Copyright (c) 2010-2012, Jean-David Gadina <macmade@eosgarden.com>
# All rights reserved.
# 
# XEOS Software License - Version 1.0 - December 21, 2012
# 
# Permission is hereby granted, free of charge, to any person or organisation
# obtaining a copy of the software and accompanying documentation covered by
# this license (the "Software") to deal in the Software, with or without
# modification, without restriction, including without limitation the rights
# to use, execute, display, copy, reproduce, transmit, publish, distribute,
# modify, merge, prepare derivative works of the Software, and to permit
# third-parties to whom the Software is furnished to do so, all subject to the
# following conditions:
# 
#       1.  Redistributions of source code, in whole or in part, must retain the
#           above copyright notice and this entire statement, including the
#           above license grant, this restriction and the following disclaimer.
# 
#       2.  Redistributions in binary form must reproduce the above copyright
#           notice and this entire statement, including the above license grant,
#           this restriction and the following disclaimer in the documentation
#           and/or other materials provided with the distribution, unless the
#           Software is distributed by the copyright owner as a library.
#           A "library" means a collection of software functions and/or data
#           prepared so as to be conveniently linked with application programs
#           (which use some of those functions and data) to form executables.
# 
#       3.  The Software, or any substancial portion of the Software shall not
#           be combined, included, derived, or linked (statically or
#           dynamically) with software or libraries licensed under the terms
#           of any GNU software license, including, but not limited to, the GNU
#           General Public License (GNU/GPL) or the GNU Lesser General Public
#           License (GNU/LGPL).
# 
#       4.  All advertising materials mentioning features or use of this
#           software must display an acknowledgement stating that the product
#           includes software developed by the copyright owner.
# 
#       5.  Neither the name of the copyright owner nor the names of its
#           contributors may be used to endorse or promote products derived from
#           this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
# 
# IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
# THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.
#-------------------------------------------------------------------------------

# $Id$

#-------------------------------------------------------------------------------
# General
#-------------------------------------------------------------------------------

# Targets / Architectures

TARGET_32                       := i386
TARGET_64                       := x86_64
TARGET_ABI                      := elf

#-------------------------------------------------------------------------------
# Paths
#-------------------------------------------------------------------------------

# Toolchain

PATH_TOOLCHAIN                  := /usr/local/xeos-build/

# Toolchain software

PATH_TOOLCHAIN_YASM             := $(PATH_TOOLCHAIN)yasm/
PATH_TOOLCHAIN_BINUTILS         := $(PATH_TOOLCHAIN)binutils/
PATH_TOOLCHAIN_LLVM             := $(PATH_TOOLCHAIN)llvm/

# Project root directories

PATH_PROJECT                    := $(realpath $(dir $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))/
PATH_BUILD                      := $(PATH_PROJECT)build/
PATH_RELEASE                    := $(PATH_PROJECT)release/
PATH_SRC                        := $(PATH_PROJECT)source/
PATH_SW                         := $(PATH_PROJECT)software-deps/

# Build directories

PATH_BUILD_BOOT                 := $(PATH_BUILD)boot/
PATH_BUILD_TMP                  := $(PATH_BUILD)tmp/
PATH_BUILD_MOUNT                := $(PATH_BUILD)mount/
PATH_BUILD_32                   := $(PATH_BUILD)$(TARGET_32)/
PATH_BUILD_64                   := $(PATH_BUILD)$(TARGET_64)/
PATH_BUILD_32_CORE              := $(PATH_BUILD_32)core/
PATH_BUILD_64_CORE              := $(PATH_BUILD_64)core/
PATH_BUILD_32_CORE_BIN          := $(PATH_BUILD_32_CORE)bin/
PATH_BUILD_64_CORE_BIN          := $(PATH_BUILD_64_CORE)bin/
PATH_BUILD_32_CORE_OBJ          := $(PATH_BUILD_32_CORE)obj/
PATH_BUILD_64_CORE_OBJ          := $(PATH_BUILD_64_CORE)obj/
PATH_BUILD_32_CORE_OBJ_KERNEL   := $(PATH_BUILD_32_CORE_OBJ)xeos/
PATH_BUILD_64_CORE_OBJ_KERNEL   := $(PATH_BUILD_64_CORE_OBJ)xeos/
PATH_BUILD_32_CORE_OBJ_LIBC     := $(PATH_BUILD_32_CORE_OBJ)libc/
PATH_BUILD_64_CORE_OBJ_LIBC     := $(PATH_BUILD_64_CORE_OBJ)libc/
PATH_BUILD_32_CORE_OBJ_SYSTEM   := $(PATH_BUILD_32_CORE_OBJ)system/
PATH_BUILD_64_CORE_OBJ_SYSTEM   := $(PATH_BUILD_64_CORE_OBJ)system/

# Source directories

PATH_SRC_BOOT                   := $(PATH_SRC)boot/
PATH_SRC_CORE                   := $(PATH_SRC)core/
PATH_SRC_CORE_KERNEL            := $(PATH_SRC_CORE)xeos/
PATH_SRC_CORE_LIBC              := $(PATH_SRC_CORE)libc/
PATH_SRC_CORE_SYSTEM            := $(PATH_SRC_CORE)system/
PATH_SRC_CORE_INC               := $(PATH_SRC_CORE)include/

# Release directories

PATH_RELEASE_CDROM              := $(PATH_RELEASE)cdrom/
PATH_RELEASE_FLOPPY             := $(PATH_RELEASE)floppy/

#-------------------------------------------------------------------------------
# File extensions
#-------------------------------------------------------------------------------

EXT_ASM                         := .s
EXT_C                           := .c
EXT_H                           := .h
EXT_OBJ                         := .o
EXT_BIN_RAW                     := .BIN
EXT_BIN                         := .$(TARGET_ABI)

#-------------------------------------------------------------------------------
# Software
#-------------------------------------------------------------------------------

# Assembler

AS                              := $(PATH_TOOLCHAIN_YASM)bin/yasm
AS_32                           := $(AS)
AS_64                           := $(AS)

# Linker

LD                              := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_32)-$(TARGET_ABI)/bin/ld
LD_32                           := $(LD)
LD_64                           := $(PATH_TOOLCHAIN_BINUTILS)$(TARGET_64)-$(TARGET_ABI)/bin/ld

# C compiler

CC                              := $(PATH_TOOLCHAIN_LLVM)bin/clang
CC_32                           := $(CC)
CC_64                           := $(CC)

# Utilities

MAKE                            := make
CD                              := cd
MV                              := mv
CP                              := cp
RM                              := rm
TAR                             := tar
SUDO                            := sudo
SVN                             := svn
DD                              := dd
EXEC                            := exec
PRINT                           := echo

#-------------------------------------------------------------------------------
# Software arguments
#-------------------------------------------------------------------------------

# C compiler warning flags

ARGS_CC_WARN                    := -Weverything -Werror
ARGS_CC_STD                     := -std=c99
ARGS_CC_32                      := -Os -I $(PATH_SRC_CORE_INC) -march=$(TARGET_32) -ccc-host-triple $(TARGET_32)-$(TARGET_ABI)-freebsd -nostdlib -fno-builtin $(ARGS_CC_STD) $(ARGS_CC_WARN)
ARGS_CC_64                      := -Os -I $(PATH_SRC_CORE_INC) -march=x86-64 -ccc-host-triple $(TARGET_64)-$(TARGET_ABI)-freebsd -nostdlib -fno-builtin $(ARGS_CC_STD) $(ARGS_CC_WARN)

# Linker flags

ARGS_LD_32                      := -z max-page-size=0x1000 -s
ARGS_LD_64                      := -z max-page-size=0x1000 -s

# Utilities

ARGS_MAKE_CLEAN                 := clean
ARGS_MAKE_BUILD                 := all
ARGS_MAKE_INSTALL               := install
ARGS_CP                         := 
ARGS_RM                         := -rf
ARGS_DD                         := conv=notrunc
ARGS_HDID                       := -nobrowse -nomount
ARGS_TAR_EXPAND                 := -xf
ARGS_SVN_CO                     := checkout

#-------------------------------------------------------------------------------
# Search paths
#-------------------------------------------------------------------------------

# Clear any existing search path
VPATH =
vpath

#-------------------------------------------------------------------------------
# File suffixes
#-------------------------------------------------------------------------------

# Clears any existing suffix
.SUFFIXES:

# Adds the suffixes used in this file
.SUFFIXES:

#-------------------------------------------------------------------------------
# DISPLAY
#-------------------------------------------------------------------------------

COLOR_NONE                      := "\x1b[0m"
COLOR_GRAY                      := "\x1b[30;01m"
COLOR_RED                       := "\x1b[31;01m"
COLOR_GREEN                     := "\x1b[32;01m"
COLOR_YELLOW                    := "\x1b[33;01m"
COLOR_BLUE                      := "\x1b[34;01m"
COLOR_PURPLE                    := "\x1b[35;01m"
COLOR_CYAN                      := "\x1b[36;01m"
