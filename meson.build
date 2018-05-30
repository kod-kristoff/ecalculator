project(
    'ecalculator',
    'cpp',
    version : '0.0.1',
    license : 'MIT'
)

add_global_arguments(
    '-std=c++17', language : 'cpp'
)

inc                   = include_directories('include')
kx_container_includes = include_directories(
  'externals/kx-container/include')
  
subdir('src')
subdir('test')
