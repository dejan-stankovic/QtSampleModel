QT				= gui core widgets

CONFIG				= qt precompile_header c++11

SOURCES				= main.cpp \
				  SampleModel.cpp

HEADERS				= global.hpp \
				  SampleModel.hpp

PRECOMPILED_HEADER		= stdafx.hpp

include				  (kitemmodels/kitemmodels.pri)
