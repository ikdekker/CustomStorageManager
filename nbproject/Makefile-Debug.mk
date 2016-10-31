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
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
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
	${OBJECTDIR}/src/ModuleServer.o \
	${OBJECTDIR}/src/StorageManagement.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f3

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/ConfigParserRunner.o \
	${TESTDIR}/tests/ConfigParserTest.o \
	${TESTDIR}/tests/EntityTest.o \
	${TESTDIR}/tests/EntityTestRunner.o \
	${TESTDIR}/tests/IndexAllocRunner.o \
	${TESTDIR}/tests/IndexAllocationTest.o \
	${TESTDIR}/tests/ModuleServerTest.o \
	${TESTDIR}/tests/ModuleServerTestRunner.o

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
LDLIBSOPTIONS=-L/home/nick/Desktop/stage/lib/mysql/lib -Llib/cpputest-3.8/lib -Llib/cpputest-3.8/src lib/cpputest-3.8/lib/libCppUTestExt.a lib/cpputest-3.8/lib/libCppUTest.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f6.exe

${TESTDIR}/TestFiles/f6.exe: lib/cpputest-3.8/lib/libCppUTestExt.a

${TESTDIR}/TestFiles/f6.exe: lib/cpputest-3.8/lib/libCppUTest.a

${TESTDIR}/TestFiles/f6.exe: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f6 ${OBJECTFILES} ${LDLIBSOPTIONS} -lcppUTestExt -lcppUTest -s

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/ConfigFactory.o: src/ConfigFactory.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ConfigFactory.o src/ConfigFactory.cxx

${OBJECTDIR}/src/ModuleEntity.o: src/ModuleEntity.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleEntity.o src/ModuleEntity.cxx

${OBJECTDIR}/src/ModuleServer.o: src/ModuleServer.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleServer.o src/ModuleServer.cxx

${OBJECTDIR}/src/StorageManagement.o: src/StorageManagement.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/StorageManagement.o src/StorageManagement.cxx

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/ConfigParserRunner.o ${TESTDIR}/tests/ConfigParserTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/EntityTest.o ${TESTDIR}/tests/EntityTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/IndexAllocRunner.o ${TESTDIR}/tests/IndexAllocationTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/ModuleServerTest.o ${TESTDIR}/tests/ModuleServerTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/ConfigParserRunner.o: tests/ConfigParserRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ConfigParserRunner.o tests/ConfigParserRunner.cpp


${TESTDIR}/tests/ConfigParserTest.o: tests/ConfigParserTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ConfigParserTest.o tests/ConfigParserTest.cpp


${TESTDIR}/tests/EntityTest.o: tests/EntityTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/EntityTest.o tests/EntityTest.cpp


${TESTDIR}/tests/EntityTestRunner.o: tests/EntityTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/EntityTestRunner.o tests/EntityTestRunner.cpp


${TESTDIR}/tests/IndexAllocRunner.o: tests/IndexAllocRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/IndexAllocRunner.o tests/IndexAllocRunner.cpp


${TESTDIR}/tests/IndexAllocationTest.o: tests/IndexAllocationTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/IndexAllocationTest.o tests/IndexAllocationTest.cpp


${TESTDIR}/tests/ModuleServerTest.o: tests/ModuleServerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ModuleServerTest.o tests/ModuleServerTest.cpp


${TESTDIR}/tests/ModuleServerTestRunner.o: tests/ModuleServerTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ModuleServerTestRunner.o tests/ModuleServerTestRunner.cpp


${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/src/ConfigFactory_nomain.o: ${OBJECTDIR}/src/ConfigFactory.o src/ConfigFactory.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ConfigFactory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ConfigFactory_nomain.o src/ConfigFactory.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ConfigFactory.o ${OBJECTDIR}/src/ConfigFactory_nomain.o;\
	fi

${OBJECTDIR}/src/ModuleEntity_nomain.o: ${OBJECTDIR}/src/ModuleEntity.o src/ModuleEntity.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ModuleEntity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleEntity_nomain.o src/ModuleEntity.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ModuleEntity.o ${OBJECTDIR}/src/ModuleEntity_nomain.o;\
	fi

${OBJECTDIR}/src/ModuleServer_nomain.o: ${OBJECTDIR}/src/ModuleServer.o src/ModuleServer.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ModuleServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleServer_nomain.o src/ModuleServer.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ModuleServer.o ${OBJECTDIR}/src/ModuleServer_nomain.o;\
	fi

${OBJECTDIR}/src/StorageManagement_nomain.o: ${OBJECTDIR}/src/StorageManagement.o src/StorageManagement.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/StorageManagement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -I/usr/lib -Ilib/gtest -I/usr/include/cppconn -Ilib/cpputest-3.8 -Ilib/cpputest-3.8/include -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/StorageManagement_nomain.o src/StorageManagement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/StorageManagement.o ${OBJECTDIR}/src/StorageManagement_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f6.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
