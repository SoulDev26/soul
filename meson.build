project('soul', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])


libsoul_src = [
  'src/memory.cpp'
]

libfmt_dep = dependency('fmt')

static_library('soul', libsoul_src)
executable('tests', 'tests.cpp',
  dependencies : [libfmt_dep])
