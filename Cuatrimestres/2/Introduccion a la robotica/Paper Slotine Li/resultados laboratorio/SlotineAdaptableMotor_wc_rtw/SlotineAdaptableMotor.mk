# Copyright (C) 2005 Quanser, Inc.
# All Rights Reserved.          
#
# File    : nt_msvc.tmf $Revision: 1.1 $
# Abstract:
#       Real-Time Workshop template makefile for building a WindowsNT-based 
#       real-time version of the SIMULINK model for WinCon.
#
#       The following defines can be used to modify the behavior of the
#       build:
#         OPTS           - User specific options, such as OPTS=-DMULTITASKING
#                          to enable multitasking mode.
#         OPT_OPTS       - Optimization option. Default is -oaxt. To enable
#                          debugging specify as OPT_OPTS=-d2.
#         USER_OBJS      - Additional user objects, such as files needed by
#                          S-functions.
#         USER_PATH      - The directory path to the source (.c) files which 
#                          are used to create any .obj files specified in 
#                          USER_OBJS. Multiple paths must be seperated
#                          with a semicolon. For example:
#                          USER_PATH="path1;path2"
#         USER_INCLUDES  - Additional include paths 
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#       MAKE    - This is the command used to invoke the make utility
#       HOST    - What platform this template makefile is targeted for
#                 (i.e. PC or UNIX)
#       BUILD  - Invoke make from the Real-Time Workshop build procedure
#                (yes/no)?
#       TARGET - Type of target Real-Time (RT) or Nonreal-Tie (NRT)
#
MAKE            = nmake
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = wincon.tlc

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "|<" are expanded by the 
# Real-Time Workshop build procedure.
#   
#  MODEL_NAME          - Name of the SIMULINK block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile 
#                        <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed. 
#  MATLAB_BIN          - Path to MATLAB executable.
#  ALT_MATLAB_ROOT     - Alternate path to were MATLAB is installed. Used when MATLAB_ROOT contains spaces.
#  ALT_MATLAB_BIN      - Alternate path to MATLAB executable. Used when MATLAB_BIN contains spaces.
#  S_FUNCTIONS         - List of S-functions .c sources
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous 
#                        task (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  RELEASE             - Matlab release version

MODEL                = SlotineAdaptableMotor
MODULES              = SlotineAdaptableMotor_data.c rt_matrx.c rt_nonfinite.c rt_printf.c 
MAKEFILE             = SlotineAdaptableMotor.mk
MATLAB_ROOT          = C:\Archivos de programa\MATLAB\R2007a
ALT_MATLAB_ROOT      = C:\ARCHIV~1\MATLAB\R2007a
MATLAB_BIN           = C:\Archivos de programa\MATLAB\R2007a\bin
ALT_MATLAB_BIN       = C:\ARCHIV~1\MATLAB\R2007a\bin
S_FUNCTIONS          = stgenc.c stgad.c stgda.c
S_FUNCTIONS_LIB      = 
SOLVER               = ode1.c
NUMST                = 2
TID01EQ              = 1
NCSTATES             = 7
BUILDARGS            =  GENERATE_REPORT=0 ADD_MDL_NAME_TO_GLOBALS=1 TMW_EXTMODE_TESTING=0
EXT_MODE             = 1

RELEASE              = R2007a
USE_RTTCPIP          = 0
USE_RTSERIAL         = 0

# Matlab Release (multiplied by 10)
MATLAB_RELEASE = $(RELEASE:.=)
MATLAB_RELEASE = $(MATLAB_RELEASE:plus=)
MATLAB_RELEASE = $(MATLAB_RELEASE:Prerelease=)
MATLAB_RELEASE = $(MATLAB_RELEASE:R=)
MATLAB_RELEASE = $(MATLAB_RELEASE:SP=)
MATLAB_RELEASE = $(MATLAB_RELEASE:a=)
MATLAB_RELEASE = $(MATLAB_RELEASE:b=)
MATLAB_RELEASE = $(MATLAB_RELEASE:c=)

EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 

#--------------------------- Model and reference models -----------------------
MODELLIB                  = SlotineAdaptableMotorlib.lib
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# ..\..\..\..\..\..\.. or .. or even . if you want it
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

#--------------------------------- Tool Locations -----------------------------
#
# Modify the following macro to reflect where you have installed WinCon.
#
WINCON = C:\ARCHIV~1\Quanser\WINCON~1.2
WINCON_LIBS = $(WINCON)\lib6
WINCON_RTWLIBS = $(MATLAB_ROOT)\work\lib

#---------------------------- Tool Definitions --------------------------------

!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl
VC_DIR = C:\ARCHIV~1\MICROS~2\VC98

#----------------------- WinCon and RTX Definitions ---------------------------

RTX = $(WINCON)\RTX\7.0
RTX_LIBS = "$(RTX)"
RTX_STDLIBS = "$(RTX_LIBS)\rtxlibcmt.lib"

#------------------------------ Include Path -----------------------------

MATLAB_INCLUDES = \
 "/I$(MATLAB_ROOT)\simulink\include" \
 "/I$(MATLAB_ROOT)\extern\include" \
 "/I$(MATLAB_ROOT)\rtw\c\src" \
 "/I$(MATLAB_ROOT)\rtw\c\src\ext_mode\common" \
 "/I$(MATLAB_ROOT)\rtw\c\libsrc" \
 "/I$(MATLAB_ROOT)\rtw\c\WinCon"

# Additional file include paths
ADD_INCLUDES = \
 /I "C:\DOCUME~1\usuario\ESCRIT~1\pSlotine\SLOTIN~1" \
 /I "C:\DOCUME~1\usuario\ESCRIT~1\pSlotine" \
 /I "$(MATLAB_ROOT)\rtw\c\libsrc" \


!if $(MATLAB_RELEASE) >= 140
ADD_INCLUDES = $(ADD_INCLUDES) /I $(RELATIVE_PATH_TO_ANCHOR) /I $(MODELREF_INC_PATH)
!endif

WINCON_INCLUDES   = /I. "/I$(WINCON)\include"
COMPILER_INCLUDES = "/I$(VC_DIR)\include"

INCLUDES = $(WINCON_INCLUDES) $(MATLAB_INCLUDES) $(ADD_INCLUDES) $(COMPILER_INCLUDES) $(USER_INCLUDES)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDES = $(INCLUDES) /I $(SHARED_SRC_DIR)
!endif

#------------------------ External mode ---------------------------------------
# uncomment -DVERBOSE to have information printed to stdout
!ifdef EXT_MODE
EXT_SRC     =
EXT_CC_OPTS = /D "EXT_MODE" #/D "VERBOSE"
!if $(EXTMODE_STATIC) == 1
EXT_SRC     = $(EXT_SRC) mem_mgr.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
!endif
!else
EXT_SRC     =
EXT_CC_OPTS =
!endif

#-------------------------------- C Flags --------------------------------

# Default options (do not change!)
DEFAULT_OPT_OPTS = /O2

# Required Options
#
# Add the /Zm<number> option to the end of the REQ_OPTS line if you get a C1076 error
#	"compiler limit : internal heap limit reached; use /Zm to specify a higher limit"
# while compiling. See the Visual Studio documentation for details. Be sure to run
# wc_clean or select WinCon/Clean from the diagram's menu to remove old object files
# after changing this option. A clean rebuild of the model is necessary.
#
REQ_OPTS = /nologo /W3 /GX /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c /D "UNDER_RTSS" /D "RELEASE" /Ox /EHsc /MT

# Optimization Options.
#   /O2   : maximum optimization
#   /d2   : debugging options
#
OPT_OPTS = /O2

# Listing Options
#   /Fa   : assembly listing (put in .COD file)
#   /FAcs : source code intermixed with assembler

LIST_OPTS =

CC_OPTS = $(REQ_OPTS) $(OPT_OPTS) $(LIST_OPTS) $(OPTS) $(EXT_CC_OPTS)

!if $(USE_RTTCPIP)
TCP_DEFINES = /D "USE_RTTCPIP"
!endif

!if $(USE_RTSERIAL)
SERIAL_DEFINES = /D "USE_RTSERIAL"
!endif

CPP_REQ_DEFINES = /D "MODEL=$(MODEL)" /D "RT" /D "USE_RTMODEL" /D "NUMST=$(NUMST)" \
                  /D "TID01EQ=$(TID01EQ)" /D "NCSTATES=$(NCSTATES)" \
				  /D "MATLAB_RELEASE=$(MATLAB_RELEASE)" /D "_WIN32_WINNT=0x0400" \
                  /D "WIN32_LEAN_AND_MEAN" $(TCP_DEFINES) $(SERIAL_DEFINES)

CFLAGS = $(CC_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES)

#-------------------------------- Linker Flags --------------------------------
#
# Remove /PDB:NONE for VC7
#
LD_OPTS = /NODEFAULTLIB /INCREMENTAL:NO /NOLOGO /driver /align:0x20 /subsystem:native,4.00 /RELEASE /entry:_RtapiProcessEntryCRT@8 /PDB:NONE /NODEFAULTLIB:"libc" /NODEFAULTLIB:"libcd" /NODEFAULTLIB:"libcmt" /NODEFAULTLIB:"libcmtd" /MACHINE:IX86 /STACK:0x0100000,0x0100000
LDFLAGS = $(LD_OPTS)

#------------------------------- Source Files ---------------------------------

REQ_SRCS  = $(MODEL).c $(MODULES) rt_code.c rt_sim.c \
            $(SOLVER) $(EXT_SRC)
REQ_OBJS  = "$(RTX_LIBS)\startupCRT.obj"

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
SHARED_OBJS = $(SHARED_SRC:.c=.obj)

OBJS = $(REQ_OBJS) $(OBJS) $(SHARED_OBJS) "$(WINCON_LIBS)\rtx_main.obj"

# ------------------------- Additional Libraries ------------------------------

LIBS =


!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) "$(WINCON_RTWLIBS)\rtwlib.lib"
!else
LIBS = $(LIBS) "rtwlib.lib"
!endif



LIBS = $(LIBS) $(S_FUNCTIONS_LIB)

REQ_LIBS = "$(WINCON_LIBS)\RTXUtil.lib" "$(WINCON_LIBS)\RTXLibrary.lib" $(RTX_STDLIBS) \
		   "$(VC_DIR)\lib\oldnames.lib" "$(RTX_LIBS)\rtapi_rtss.lib" "$(RTX_LIBS)\rtx_rtss.lib"

!if $(USE_RTTCPIP)
REQ_LIBS = $(REQ_LIBS) "$(RTX_LIBS)\RtxTcpIp.lib"
!endif

#--------------------------------- Rules --------------------------------------

..\$(MODEL).wcl : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
        @rem @<<$(MODEL).lnk
        $(LDFLAGS) $(OBJS) $(REQ_LIBS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS) /out:$@
<<KEEP
		@$(LD) @$(MODEL).lnk
		@del $(MODEL).lnk
        @echo ### Created executable: $(MODEL).wcl

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\tcpip}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\serial}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\custom}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

# Additional sources

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\Stg}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\libsrc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\Stg}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\libsrc}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"



{$(MATLAB_ROOT)\rtw\c\src}.c{$(WINCON_RTWLIBS)}.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) /Fo$@ "$<"

{$(MATLAB_ROOT)\rtw\c\Stg}.c{$(WINCON_RTWLIBS)}.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) /Fo$@ "$<"

{$(MATLAB_ROOT)\rtw\c\libsrc}.c{$(WINCON_RTWLIBS)}.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) /Fo$@ "$<"



{$(MATLAB_ROOT)\rtw\c\src}.cpp{$(WINCON_RTWLIBS)}.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) /Fo$@ "$<"

{$(MATLAB_ROOT)\rtw\c\Stg}.cpp{$(WINCON_RTWLIBS)}.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) /Fo$@ "$<"

{$(MATLAB_ROOT)\rtw\c\libsrc}.cpp{$(WINCON_RTWLIBS)}.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) /Fo$@ "$<"



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

# Quanser devices

{$(MATLAB_ROOT)\rtw\c\WinCon}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\WinCon\devices}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\Quanser\devices}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\WinCon}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\WinCon\devices}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(MATLAB_ROOT)\rtw\c\Quanser\devices}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

# Put these rule last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) "$<"

{..}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

{..}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) "$<"

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@echo ### Creating $@
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ $?
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@echo ### $@ Created
!endif

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries:



!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"

MODULES_rtwlib = \
	"$(WINCON_RTWLIBS)\rt_backsubcc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_backsubcc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_backsubrc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_backsubrc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_backsubrr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_backsubrr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_enab.obj" \
	"$(WINCON_RTWLIBS)\rt_forwardsubcc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_forwardsubcc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_forwardsubcr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_forwardsubcr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_forwardsubrc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_forwardsubrc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_forwardsubrr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_forwardsubrr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_hypot.obj" \
	"$(WINCON_RTWLIBS)\rt_hypot32.obj" \
	"$(WINCON_RTWLIBS)\rt_i32zcfcn.obj" \
	"$(WINCON_RTWLIBS)\rt_look.obj" \
	"$(WINCON_RTWLIBS)\rt_look1d.obj" \
	"$(WINCON_RTWLIBS)\rt_look1d32.obj" \
	"$(WINCON_RTWLIBS)\rt_look2d32_general.obj" \
	"$(WINCON_RTWLIBS)\rt_look2d32_normal.obj" \
	"$(WINCON_RTWLIBS)\rt_look2d_general.obj" \
	"$(WINCON_RTWLIBS)\rt_look2d_normal.obj" \
	"$(WINCON_RTWLIBS)\rt_look32.obj" \
	"$(WINCON_RTWLIBS)\rt_lu_cplx.obj" \
	"$(WINCON_RTWLIBS)\rt_lu_cplx_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_lu_real.obj" \
	"$(WINCON_RTWLIBS)\rt_lu_real_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matdivcc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matdivcc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matdivcr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matdivcr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matdivrc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matdivrc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matdivrr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matdivrr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultandinccc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultandinccc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultandinccr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultandinccr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultandincrc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultandincrc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultandincrr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultandincrr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultcc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultcc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultcr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultcr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultrc_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultrc_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultrr_dbl.obj" \
	"$(WINCON_RTWLIBS)\rt_matmultrr_sgl.obj" \
	"$(WINCON_RTWLIBS)\rt_nrand.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_div_int16.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_div_int32.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_div_int8.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_div_uint16.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_div_uint32.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_div_uint8.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_prod_int16.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_prod_int32.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_prod_int8.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_prod_uint16.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_prod_uint32.obj" \
	"$(WINCON_RTWLIBS)\rt_sat_prod_uint8.obj" \
	"$(WINCON_RTWLIBS)\rt_urand.obj" \
	"$(WINCON_RTWLIBS)\rt_zcfcn.obj" \


"$(WINCON_RTWLIBS)\rtwlib.lib" : rtw_proj.tmw $(MAKEFILE) $(MODULES_rtwlib)
	@echo ### Creating $@
	$(LIBCMD) /nologo /out:$@ $(MODULES_rtwlib)
	@echo ### Created $@



!else

MODULES_rtwlib = \
	"rt_backsubcc_dbl.obj" \
	"rt_backsubcc_sgl.obj" \
	"rt_backsubrc_dbl.obj" \
	"rt_backsubrc_sgl.obj" \
	"rt_backsubrr_dbl.obj" \
	"rt_backsubrr_sgl.obj" \
	"rt_enab.obj" \
	"rt_forwardsubcc_dbl.obj" \
	"rt_forwardsubcc_sgl.obj" \
	"rt_forwardsubcr_dbl.obj" \
	"rt_forwardsubcr_sgl.obj" \
	"rt_forwardsubrc_dbl.obj" \
	"rt_forwardsubrc_sgl.obj" \
	"rt_forwardsubrr_dbl.obj" \
	"rt_forwardsubrr_sgl.obj" \
	"rt_hypot.obj" \
	"rt_hypot32.obj" \
	"rt_i32zcfcn.obj" \
	"rt_look.obj" \
	"rt_look1d.obj" \
	"rt_look1d32.obj" \
	"rt_look2d32_general.obj" \
	"rt_look2d32_normal.obj" \
	"rt_look2d_general.obj" \
	"rt_look2d_normal.obj" \
	"rt_look32.obj" \
	"rt_lu_cplx.obj" \
	"rt_lu_cplx_sgl.obj" \
	"rt_lu_real.obj" \
	"rt_lu_real_sgl.obj" \
	"rt_matdivcc_dbl.obj" \
	"rt_matdivcc_sgl.obj" \
	"rt_matdivcr_dbl.obj" \
	"rt_matdivcr_sgl.obj" \
	"rt_matdivrc_dbl.obj" \
	"rt_matdivrc_sgl.obj" \
	"rt_matdivrr_dbl.obj" \
	"rt_matdivrr_sgl.obj" \
	"rt_matmultandinccc_dbl.obj" \
	"rt_matmultandinccc_sgl.obj" \
	"rt_matmultandinccr_dbl.obj" \
	"rt_matmultandinccr_sgl.obj" \
	"rt_matmultandincrc_dbl.obj" \
	"rt_matmultandincrc_sgl.obj" \
	"rt_matmultandincrr_dbl.obj" \
	"rt_matmultandincrr_sgl.obj" \
	"rt_matmultcc_dbl.obj" \
	"rt_matmultcc_sgl.obj" \
	"rt_matmultcr_dbl.obj" \
	"rt_matmultcr_sgl.obj" \
	"rt_matmultrc_dbl.obj" \
	"rt_matmultrc_sgl.obj" \
	"rt_matmultrr_dbl.obj" \
	"rt_matmultrr_sgl.obj" \
	"rt_nrand.obj" \
	"rt_sat_div_int16.obj" \
	"rt_sat_div_int32.obj" \
	"rt_sat_div_int8.obj" \
	"rt_sat_div_uint16.obj" \
	"rt_sat_div_uint32.obj" \
	"rt_sat_div_uint8.obj" \
	"rt_sat_prod_int16.obj" \
	"rt_sat_prod_int32.obj" \
	"rt_sat_prod_int8.obj" \
	"rt_sat_prod_uint16.obj" \
	"rt_sat_prod_uint32.obj" \
	"rt_sat_prod_uint8.obj" \
	"rt_urand.obj" \
	"rt_zcfcn.obj" \


"rtwlib.lib" : rtw_proj.tmw $(MAKEFILE) $(MODULES_rtwlib)
	@echo ### Creating $@
	$(LIBCMD) /nologo /out:$@ $(MODULES_rtwlib)
	@echo ### Created $@



!endif

#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
