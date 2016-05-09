#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AllSelector.o \
	${OBJECTDIR}/AllTextSelector.o \
	${OBJECTDIR}/ExactTextSelector.o \
	${OBJECTDIR}/LocalSelector.o \
	${OBJECTDIR}/PenisHandler.o \
	${OBJECTDIR}/ScreamingJazzApp.o \
	${OBJECTDIR}/SelectorProduct.o \
	${OBJECTDIR}/SelectorRequestHandlerFactory.o \
	${OBJECTDIR}/SelectorSum.o \
	${OBJECTDIR}/TextOutputHandler.o \
	${OBJECTDIR}/URISelector.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/screaming_jazz

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/screaming_jazz: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/screaming_jazz ${OBJECTFILES} ${LDLIBSOPTIONS} -lPocoFoundation -lPocoUtil -lPocoNet

${OBJECTDIR}/AllSelector.o: AllSelector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AllSelector.o AllSelector.cpp

${OBJECTDIR}/AllTextSelector.o: AllTextSelector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AllTextSelector.o AllTextSelector.cpp

${OBJECTDIR}/ExactTextSelector.o: ExactTextSelector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExactTextSelector.o ExactTextSelector.cpp

${OBJECTDIR}/LocalSelector.o: LocalSelector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LocalSelector.o LocalSelector.cpp

${OBJECTDIR}/PenisHandler.o: PenisHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PenisHandler.o PenisHandler.cpp

${OBJECTDIR}/ScreamingJazzApp.o: ScreamingJazzApp.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScreamingJazzApp.o ScreamingJazzApp.cpp

${OBJECTDIR}/SelectorProduct.o: SelectorProduct.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SelectorProduct.o SelectorProduct.cpp

${OBJECTDIR}/SelectorRequestHandlerFactory.o: SelectorRequestHandlerFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SelectorRequestHandlerFactory.o SelectorRequestHandlerFactory.cpp

${OBJECTDIR}/SelectorSum.o: SelectorSum.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SelectorSum.o SelectorSum.cpp

${OBJECTDIR}/TextOutputHandler.o: TextOutputHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TextOutputHandler.o TextOutputHandler.cpp

${OBJECTDIR}/URISelector.o: URISelector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/URISelector.o URISelector.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/screaming_jazz

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
