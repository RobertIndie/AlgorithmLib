PROJ_BASE := ../..
include $(PROJ_BASE)/makefile.libs

TARGET_TYPE := EXE
TARGET := AlibTest

INC += $(INC_ALIB) $(INC_GTEST)
LIB_DIR += $(LIB_DIR_GTEST)
LIB := $(LIB_ALIB) $(LIB_GTEST) $(LIB)

CXXFLAGS += -w
include $(PROJ_BASE)/makefile.build
