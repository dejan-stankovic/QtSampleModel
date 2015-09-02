QT				= gui core widgets
TARGET				= TreeModel

CONFIG				= qt precompile_header c++11

SOURCES				= main.cpp \
				  TreeModel.cpp \
				  TreeModelView.cpp

HEADERS				= TreeModel.hpp \
				  TreeModelView.hpp

PRECOMPILED_HEADER		= stdafx.hpp

include				  (kitemmodels/kitemmodels.pri)
