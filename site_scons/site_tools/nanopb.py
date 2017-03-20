#!python
"""
nanopb tool for scons, relies on protoc tool
"""

import SCons.Action
import SCons.Builder
import SCons.Defaults
import SCons.Node.FS
import SCons.Util

from SCons.Script import File, Dir, Action, Builder, Copy

import os.path

def generate(env):
    """Add Builders and construction variables for protoc to an Environment."""
    assert 'PROTOC' in env, "Must import protoc tool before nanopb tool"
    assert 'NANOPB_DIR' in env, "Must specify NANOPB_DIR before importing nanopb tool"
    assert 'NANOPB_TARGET' in env, "Must specify NANOPB_TARGET before importing nanopb tool"

    source_dir = Dir(env['NANOPB_DIR'])
    target_dir = Dir(env['NANOPB_TARGET'])
    env.ProtocPython(target_dir.Dir('generator/proto'), source_dir.File('generator/proto/nanopb.proto'))
    env.ProtocPython(target_dir.Dir('generator/proto'), source_dir.File('generator/proto/plugin.proto'))
    env.Command(target_dir.File('generator/nanopb_generator.py'), source_dir.File('generator/nanopb_generator.py'),
        Copy('$TARGET', '$SOURCE'))
    env.Command(target_dir.File('generator/proto/__init__.py'), source_dir.File('generator/proto/__init__.py'),
        Copy('$TARGET', '$SOURCE'))
    plugin_linux = env.Command(
        target_dir.File('generator/protoc-gen-nanopb'), source_dir.File('generator/protoc-gen-nanopb'),
        Copy('$TARGET', '$SOURCE'))
    plugin_windows = env.Command(
        target_dir.File('generator/protoc-gen-nanopb.bat'), source_dir.File('generator/protoc-gen-nanopb.bat'),
        Copy('$TARGET', '$SOURCE'))

    plugin = plugin_windows
    assert len(plugin) == 1, "Internal error, unexpected multiple plugin executables"
    env['NANOPB_PLUGIN'] = plugin[0]

    env.AddMethod(env['PROTOC_GENERATOR']('$NANOPBCOM', '$NANOPBCOMSTR', ['.pb.cc', '.pb.h']), 'Nanopb')
    env['NANOPBCOM'] = '$PROTOCCOM --plugin=protoc-gen-nanopb=${NANOPB_PLUGIN.abspath} --nanopb_out=${TARGET.dir.abspath}'

def exists(env):
    return env.Detect(protocs)
