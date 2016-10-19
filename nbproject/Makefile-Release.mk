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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/c59b28c3/StorageManagement.o \
	${OBJECTDIR}/ConfigFactory.o \
	${OBJECTDIR}/ModuleEntity.o \
	${OBJECTDIR}/ModuleServer.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/_ext/80c25dd5/newtestclass.o \
	${TESTDIR}/_ext/80c25dd5/newtestrunner.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utest

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utest: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/c59b28c3/StorageManagement.o: /home/nick/NetBeansProjects/utest/StorageManagement.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/c59b28c3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/c59b28c3/StorageManagement.o /home/nick/NetBeansProjects/utest/StorageManagement.cpp

${OBJECTDIR}/ConfigFactory.o: ConfigFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ConfigFactory.o ConfigFactory.cpp

${OBJECTDIR}/ModuleEntity.o: ModuleEntity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleEntity.o ModuleEntity.cpp

${OBJECTDIR}/ModuleServer.o: ModuleServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleServer.o ModuleServer.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/80c25dd5/newtestclass.o ${TESTDIR}/_ext/80c25dd5/newtestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/_ext/80c25dd5/newtestclass.o: /home/nick/NetBeansProjects/utest/tests/newtestclass.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/80c25dd5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/80c25dd5/newtestclass.o /home/nick/NetBeansProjects/utest/tests/newtestclass.cpp


${TESTDIR}/_ext/80c25dd5/newtestrunner.o: /home/nick/NetBeansProjects/utest/tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/80c25dd5
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/80c25dd5/newtestrunner.o /home/nick/NetBeansProjects/utest/tests/newtestrunner.cpp


${OBJECTDIR}/_ext/c59b28c3/StorageManagement_nomain.o: ${OBJECTDIR}/_ext/c59b28c3/StorageManagement.o /home/nick/NetBeansProjects/utest/StorageManagement.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/c59b28c3
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/c59b28c3/StorageManagement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/c59b28c3/StorageManagement_nomain.o /home/nick/NetBeansProjects/utest/StorageManagement.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/c59b28c3/StorageManagement.o ${OBJECTDIR}/_ext/c59b28c3/StorageManagement_nomain.o;\
	fi

${OBJECTDIR}/ConfigFactory_nomain.o: ${OBJECTDIR}/ConfigFactory.o ConfigFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ConfigFactory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ConfigFactory_nomain.o ConfigFactory.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ConfigFactory.o ${OBJECTDIR}/ConfigFactory_nomain.o;\
	fi

${OBJECTDIR}/ModuleEntity_nomain.o: ${OBJECTDIR}/ModuleEntity.o ModuleEntity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ModuleEntity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleEntity_nomain.o ModuleEntity.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ModuleEntity.o ${OBJECTDIR}/ModuleEntity_nomain.o;\
	fi

${OBJECTDIR}/ModuleServer_nomain.o: ${OBJECTDIR}/ModuleServer.o ModuleServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ModuleServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ModuleServer_nomain.o ModuleServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ModuleServer.o ${OBJECTDIR}/ModuleServer_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utest

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
