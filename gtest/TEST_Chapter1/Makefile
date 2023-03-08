SRC_DIR = ../../src
INC_DIR = ../../inc
STUB_DIR = ../stubs
MOCK_DIR = ../mocks

OBJS_OUT = ../../obj
STUB_OBJS_DIR = $(STUB_DIR)/obj
MOCK_OBJS_DIR = $(MOCK_DIR)/objs


EXEC_NAME = utSolution
GTEST_JSON_OUTPUT = $(EXEC_NAME).json

# Unit test files (files containing test definitions)
UT_SRC = UT_Chapter1.cpp
UT_OBJ = $(UT_SRC:%.cpp=$(OBJS_OUT)/%.o)

# Stub files
STUB_SRC := 
STUB_OBJ = $(STUB_SRC:%.cpp=$(STUB_OBJS_DIR)/%.o)

MOCK_SRC = 
MOCK_OBJ = $(MOCK_SRC:%.cpp=$(MOCK_OBJS_DIR)/%.o)

# File(s) for which unit tests are written
SRC = Chapter1.cpp
OBJ = $(SRC:%.cpp=$(OBJS_OUT)/%.o)

# Additional include search directories
INCLUDES =	\
			-I$(INC_DIR)/ \
			-I/usr/include/

INCLUDES += $(shell pkg-config --cflags $(packages))

# Must have compiler flags
CXXFLAGS = -g --std=c++17 -O0 -DGTEST

# Repo-specific flags
CXXFLAGS += -Wall -Wextra

# Linker flags. Note how we specify that GTest / GMock libraries should be from release-host.
LDFLAGS  =  -lgcov -lgtest -lgtest_main -lgmock -lpthread -ldl

.PHONY: test

test: $(EXEC_NAME) run

$(EXEC_NAME): make_dirs $(OBJ) $(STUB_OBJ) $(MOCK_OBJ) $(UT_OBJ)
	$(info Linking UT executable...)
	$(CXX) -o $(EXEC_NAME) $(OBJ) $(UT_OBJ) $(STUB_OBJ) $(MOCK_OBJ) $(LDFLAGS)

$(OBJ): $(OBJS_OUT)/%.o: $(SRC_DIR)/%.cpp
	$(info Compiling file under test...)
# We add --coverage flag for source files we want to write unit tests for in order to enable code instrumentation
	$(CXX) $(INCLUDES) $(CXXFLAGS) --coverage -o $@ -c $<

$(STUB_OBJ): $(STUB_OBJS_DIR)/%.o: $(STUB_DIR)/src/%.cpp
	$(info Building stubs...)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o $@ -c $<

$(MOCK_OBJ): $(MOCK_OBJS_DIR)/%.o: $(MOCK_DIR)/src/%.cpp
	$(info Building mocks...)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o $@ -c $<

$(UT_OBJ): $(OBJS_OUT)/%.o: %.cpp
	$(info Building UT sources...)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o $@ -c $<

make_dirs:
# Create obj dirs if they do not exist
	mkdir -p $(STUB_OBJS_DIR)
	mkdir -p $(MOCK_OBJS_DIR)
	mkdir -p $(OBJS_OUT)

run: $(EXEC_NAME)
# Run test suite. After the run, *.gcda files will be generated in OBJ directory
	export LD_LIBRARY_PATH=$(CAS_HOSTFS)/usr/lib && ./$(EXEC_NAME) --gtest_output="json:$(GTEST_JSON_OUTPUT)"
# Copy suite summary to local report directory
	\cp -r *.json $(COVERAGE_LOCAL_REPORT_DIRECTORY)
# Copy all gcno and gcda files from OBJ directory to local report directory. They will be later processed by python script
	\cp -r $(OBJS_OUT)/*.gcda $(OBJS_OUT)/*.gcno $(COVERAGE_LOCAL_REPORT_DIRECTORY)


testclean:
	rm -rf $(OBJS_OUT)
	rm -f $(EXEC_NAME)
	rm -f $(EXEC_NAME).info
	rm -f $(GTEST_JSON_OUTPUT)