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
	${OBJECTDIR}/ExternalConnector.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/ConfigFactory.o \
	${OBJECTDIR}/src/DatabaseAdapter.o \
	${OBJECTDIR}/src/MatrixControl.o \
	${OBJECTDIR}/src/ModuleEntity.o \
	${OBJECTDIR}/src/ModuleServer.o \
	${OBJECTDIR}/src/SerialDriver.o \
	${OBJECTDIR}/src/StorageManagement.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f3

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/ConfigParserRunner.o \
	${TESTDIR}/tests/ConfigParserTest.o \
	${TESTDIR}/tests/EntityTest.o \
	${TESTDIR}/tests/EntityTestRunner.o \
	${TESTDIR}/tests/ExternalConnectorTest.o \
	${TESTDIR}/tests/ExternalTestRunner.o \
	${TESTDIR}/tests/IndexAllocRunner.o \
	${TESTDIR}/tests/IndexAllocationTest.o \
	${TESTDIR}/tests/MatrixControlTest.o \
	${TESTDIR}/tests/MatrixControlTestRunner.o \
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
LDLIBSOPTIONS=-Llib/cpputest-3.8/lib -L/usr/lib/mysql -L/usr/lib/x86_64-linux-gnu -L/usr/include/cppconn -L/usr/include/cppunit

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f6

${TESTDIR}/TestFiles/f6: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f6 ${OBJECTFILES} ${LDLIBSOPTIONS} -lCppUTest -lCppUTestExt -lwiringPi -lpthread -lmysqlclient -lmysqlcppconn

${OBJECTDIR}/ExternalConnector.o: ExternalConnector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExternalConnector.o ExternalConnector.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/ConfigFactory.o: src/ConfigFactory.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ConfigFactory.o src/ConfigFactory.cxx

${OBJECTDIR}/src/DatabaseAdapter.o: src/DatabaseAdapter.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DatabaseAdapter.o src/DatabaseAdapter.cxx

${OBJECTDIR}/src/MatrixControl.o: src/MatrixControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MatrixControl.o src/MatrixControl.cpp

${OBJECTDIR}/src/ModuleEntity.o: src/ModuleEntity.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleEntity.o src/ModuleEntity.cxx

${OBJECTDIR}/src/ModuleServer.o: src/ModuleServer.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleServer.o src/ModuleServer.cxx

${OBJECTDIR}/src/SerialDriver.o: src/SerialDriver.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SerialDriver.o src/SerialDriver.cpp

${OBJECTDIR}/src/StorageManagement.o: src/StorageManagement.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/StorageManagement.o src/StorageManagement.cxx

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

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/ExternalConnectorTest.o ${TESTDIR}/tests/ExternalTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/IndexAllocRunner.o ${TESTDIR}/tests/IndexAllocationTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/MatrixControlTest.o ${TESTDIR}/tests/MatrixControlTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/ModuleServerTest.o ${TESTDIR}/tests/ModuleServerTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/ConfigParserRunner.o: tests/ConfigParserRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ConfigParserRunner.o tests/ConfigParserRunner.cpp


${TESTDIR}/tests/ConfigParserTest.o: tests/ConfigParserTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ConfigParserTest.o tests/ConfigParserTest.cpp


${TESTDIR}/tests/EntityTest.o: tests/EntityTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/EntityTest.o tests/EntityTest.cpp


${TESTDIR}/tests/EntityTestRunner.o: tests/EntityTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/EntityTestRunner.o tests/EntityTestRunner.cpp


${TESTDIR}/tests/ExternalConnectorTest.o: tests/ExternalConnectorTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ExternalConnectorTest.o tests/ExternalConnectorTest.cpp


${TESTDIR}/tests/ExternalTestRunner.o: tests/ExternalTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ExternalTestRunner.o tests/ExternalTestRunner.cpp


${TESTDIR}/tests/IndexAllocRunner.o: tests/IndexAllocRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/IndexAllocRunner.o tests/IndexAllocRunner.cpp


${TESTDIR}/tests/IndexAllocationTest.o: tests/IndexAllocationTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/IndexAllocationTest.o tests/IndexAllocationTest.cpp


${TESTDIR}/tests/MatrixControlTest.o: tests/MatrixControlTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MatrixControlTest.o tests/MatrixControlTest.cpp


${TESTDIR}/tests/MatrixControlTestRunner.o: tests/MatrixControlTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MatrixControlTestRunner.o tests/MatrixControlTestRunner.cpp


${TESTDIR}/tests/ModuleServerTest.o: tests/ModuleServerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ModuleServerTest.o tests/ModuleServerTest.cpp


${TESTDIR}/tests/ModuleServerTestRunner.o: tests/ModuleServerTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ModuleServerTestRunner.o tests/ModuleServerTestRunner.cpp


${OBJECTDIR}/ExternalConnector_nomain.o: ${OBJECTDIR}/ExternalConnector.o ExternalConnector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ExternalConnector.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExternalConnector_nomain.o ExternalConnector.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ExternalConnector.o ${OBJECTDIR}/ExternalConnector_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
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
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ConfigFactory_nomain.o src/ConfigFactory.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ConfigFactory.o ${OBJECTDIR}/src/ConfigFactory_nomain.o;\
	fi

${OBJECTDIR}/src/DatabaseAdapter_nomain.o: ${OBJECTDIR}/src/DatabaseAdapter.o src/DatabaseAdapter.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/DatabaseAdapter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DatabaseAdapter_nomain.o src/DatabaseAdapter.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/DatabaseAdapter.o ${OBJECTDIR}/src/DatabaseAdapter_nomain.o;\
	fi

${OBJECTDIR}/src/MatrixControl_nomain.o: ${OBJECTDIR}/src/MatrixControl.o src/MatrixControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/MatrixControl.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MatrixControl_nomain.o src/MatrixControl.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/MatrixControl.o ${OBJECTDIR}/src/MatrixControl_nomain.o;\
	fi

${OBJECTDIR}/src/ModuleEntity_nomain.o: ${OBJECTDIR}/src/ModuleEntity.o src/ModuleEntity.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/ModuleEntity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleEntity_nomain.o src/ModuleEntity.cxx;\
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
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ModuleServer_nomain.o src/ModuleServer.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/ModuleServer.o ${OBJECTDIR}/src/ModuleServer_nomain.o;\
	fi

${OBJECTDIR}/src/SerialDriver_nomain.o: ${OBJECTDIR}/src/SerialDriver.o src/SerialDriver.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/SerialDriver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SerialDriver_nomain.o src/SerialDriver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/SerialDriver.o ${OBJECTDIR}/src/SerialDriver_nomain.o;\
	fi

${OBJECTDIR}/src/StorageManagement_nomain.o: ${OBJECTDIR}/src/StorageManagement.o src/StorageManagement.cxx 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/StorageManagement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/StorageManagement_nomain.o src/StorageManagement.cxx;\
	else  \
	    ${CP} ${OBJECTDIR}/src/StorageManagement.o ${OBJECTDIR}/src/StorageManagement_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f6

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
