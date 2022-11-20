file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_executable(${Formula} ${srcs} ${hdrs})

target_link_libraries(${Formula} ${FormulaLib})