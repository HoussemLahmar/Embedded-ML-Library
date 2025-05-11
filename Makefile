# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS =
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BIN_DIR = bin
EXAMPLES_DIR = examples
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(wildcard $(SRC_DIR)/*.cpp))
TESTS = test_fixed_point test_linear_regression test_logistic_regression test_svm test_preprocess

# Cible par défaut
all: $(TESTS)

# Compilation des fichiers objets
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilation des tests
test_fixed_point: $(OBJECTS) $(TEST_DIR)/test_fixed_point.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_linear_regression: $(OBJECTS) $(TEST_DIR)/test_linear_regression.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_logistic_regression: $(OBJECTS) $(TEST_DIR)/test_logistic_regression.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_svm: $(OBJECTS) $(TEST_DIR)/test_svm.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_preprocess: $(OBJECTS) $(TEST_DIR)/test_preprocess.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation des exemples
examples: $(OBJECTS)
	@for example in $(wildcard $(EXAMPLES_DIR)/*/); do \
		$(CXX) $(CXXFLAGS) $$example/src/*.cpp $(OBJECTS) -o $$example/example; \
	done

# Nettoyage
clean:
	@rm -rf $(BIN_DIR) $(TESTS) $(wildcard $(EXAMPLES_DIR)/*/example)
	@echo "Nettoyage terminé."

# Phony targets
.PHONY: all clean examples