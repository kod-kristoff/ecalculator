test_sources = [
  'test_main.cpp',
  'kx/container/stack_ff_test.cpp'
]

catch_dep = dependency('catch')

testexe = executable(
  'testexe',
  test_sources,
  include_directories : inc,
  dependencies        : catch_dep
)

test('ecalculator test', testexe)
