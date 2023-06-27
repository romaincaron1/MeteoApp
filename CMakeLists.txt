cmake_minimum_required(VERSION 3.25)
project(meteo)

set(CMAKE_CXX_STANDARD 20)

add_executable(meteo main.cpp Entities/User/User.cpp Entities/User/User.h Entities/Preference/Preference.cpp Entities/Preference/Preference.h Entities/Profile/Profile.cpp Entities/Profile/Profile.h Entities/Threshold/Threshold.cpp Entities/Threshold/Threshold.h Datatypes/Temperature.cpp Datatypes/WindSpeed.cpp Entities/Zone/Zone.cpp Entities/Zone/Zone.h Entities/Zone/City.cpp Entities/Zone/City.h Entities/Zone/Region.cpp Entities/Zone/Region.h Entities/Zone/Country.cpp Entities/Zone/Country.h)
