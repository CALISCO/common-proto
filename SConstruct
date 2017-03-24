# Top-level build wrapper so build outputs go in a separate directory.
import multiprocessing
import os
import os.path

SetOption('num_jobs', multiprocessing.cpu_count() + 1)

# On Windows platforms, force gcc-style (instead of MSVC-style) arguments.
env = Environment(ENV=os.environ,
    tools=['protoc', 'nanopb'],
    NANOPB_DIR='nanopb', NANOPB_TARGET='build/nanopb/')
Export('env')

def simplify_output(env, mappings):
  pad_len = max([len(val) for val in mappings.values()]) + 2
  for key, val in mappings.items():
    env[key] = val + (' ' * (pad_len - len(val))) + '$TARGET'

if ARGUMENTS.get('VERBOSE') != '1':
  simplify_output(env, {
    'PROTOCPYTHONCOMSTR': 'PYPROTO',
    'NANOPBCOMSTR': 'NANOPB',
    'PROTOCJAVACOMSTR': 'JAVAPROTO',
  })

###
### Actual build targets here
###
SConscript('SConscript', variant_dir='generated',
          exports=['env'],
          duplicate=0)
