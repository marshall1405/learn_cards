cmake_minimum_required(VERSION 3.10)

project(learn_cards)

set(wxWidgets_ROOT_DIR "/external/wxWidgets-3.2.5")

find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})

add_executable(learn_cards src/main.cpp src/app/card.cpp src/app/set.cpp src/app/menu.cpp src/app/set_window.cpp src/app/set_creator.cpp src/app/memory.cpp)

target_link_libraries(learn_cards ${wxWidgets_LIBRARIES})