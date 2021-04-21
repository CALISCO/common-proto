#!python
"""
nanopb tool for scons, relies on protoc tool
"""

from SCons.Script import File, Dir

import os.path

def generate(env):
    """Add Builders and construction variables for protoc to an Environment."""
    assert 'NANOPB_DIR' in env, "Must specify NANOPB_DIR before importing nanopb tool"

    source_dir = Dir(env['NANOPB_DIR'])
    env['NANOPB_GENERATOR'] = source_dir.File('generator/nanopb_generator.py')

    env.AddMethod(env['PROTOC_GENERATOR']('$NANOPBCOM', '$NANOPBCOMSTR', ['.pb.c', '.pb.h'], []), 'Nanopb')
    env['NANOPBCOM'] = 'python $NANOPB_GENERATOR $SOURCES -q -D $PBTARGET'

def exists(env):
    return env.Detect(protocs)
