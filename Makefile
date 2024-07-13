CXX = arm64-apple-darwin20.0.0-clang++
CXXFLAGS = -ftree-vectorize -fPIC -fPIE -fstack-protector-strong -O2 -pipe -stdlib=libc++ -fvisibility-inlines-hidden -fmessage-length=0 -isystem /Users/davidpavlicek03/anaconda3/include -D_FORTIFY_SOURCE=2

SRC_DIR = src
APP_DIR = $(SRC_DIR)/app
OBJ_DIR = obj

OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/card.o $(OBJ_DIR)/set.o
TARGET = output

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/card.o: $(APP_DIR)/card.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/set.o: $(APP_DIR)/set.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
