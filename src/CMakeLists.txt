SET(SRCS
    LandscapeMakerPluginInterface.cpp
    LandscapeMaker.cpp
    ui/LandscapeMakerConfigDialog.cpp
    Landscape.cpp
)

INCLUDE_DIRECTORIES(ui)

ADD_LIBRARY(LandscapeMaker MODULE ${SRCS})

TARGET_LINK_LIBRARIES(LandscapeMaker Qt5::Widgets)

SET_TARGET_PROPERTIES(LandscapeMaker PROPERTIES OUTPUT_NAME "LandscapeMaker")
SET_TARGET_PROPERTIES(LandscapeMaker PROPERTIES COMPILE_FLAGS "-DQT_DYNAMICPLUGIN")
SET_TARGET_PROPERTIES(LandscapeMaker PROPERTIES AUTOMOC TRUE)
SET_TARGET_PROPERTIES(LandscapeMaker PROPERTIES AUTOUIC TRUE)
SET_TARGET_PROPERTIES(LandscapeMaker PROPERTIES FOLDER "plugins/LandscapeMaker")

