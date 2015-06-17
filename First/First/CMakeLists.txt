cmake_minimum_required (VERSION 2.6)
project (YSA)

add_definition(-DCOMPILE_NO_SF)
add_definition(-DCOMPILE_NO_VB)

file(GLOB YSA_SRC "*.h" "*.cpp")

add_executable(YSA YSA_SRC)
