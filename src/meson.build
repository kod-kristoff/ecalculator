ecalculator_stack_sources = [
  'main_stack_based_calculator.cpp',
  'calculator.cpp',
  'input.cpp'
]

executable(
  'ecalculator-stack',
  ecalculator_stack_sources,
  include_directories : inc

)

ecalculator_expr_sources = [
  'main_expr_based_calculator.cpp',
  'scanner.cpp',
  'symbol_table.cpp',
  'parser.cpp'
]

executable(
  'expr-calculator',
  ecalculator_expr_sources,
  include_directories : inc
)
