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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/ConfigFactory.o \
	${OBJECTDIR}/src/ModuleEntity.o \
	${OBJECTDIR}/src/ScannerReader.o \
	${OBJECTDIR}/src/StorageManagement.o


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
LDLIBSOPTIONS=-L/home/nick/Desktop/stage/lib/mysql/lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utest

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utest: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utest ${OBJECTFILES} ${LDLIBSOPTIONS} -lmysqlcppconn -lhidapi-hidraw -lpthread

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -I/usr/local/lib -Ilib/hidapi -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/ConfigFactory.o: src/ConfigFactory.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -I/usr/local/lib -Ilib/hidapi -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ConfigFactory.o src/ConfigFactory.cxx

${OBJECTDIR}/src/ModuleEntity.o: src/ModuleEntity.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -I/usr/local/lib -Ilib/hidapi -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleEntity.o src/ModuleEntity.cxx

${OBJECTDIR}/src/ScannerReader.o: src/ScannerReader.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -I/usr/local/lib -Ilib/hidapi -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ScannerReader.o src/ScannerReader.cxx

${OBJECTDIR}/src/StorageManagement.o: src/StorageManagement.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -I/usr/local/lib -Ilib/hidapi -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/StorageManagement.o src/StorageManagement.cxx

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utest

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
