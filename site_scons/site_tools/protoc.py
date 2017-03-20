#!python
"""
protoc.py: Protoc Builder for SCons

This Builder invokes protoc to generate C++ and Python
from a .proto file.

NOTE: Java is not currently supported.

Based off https://bitbucket.org/scons/scons/wiki/ProtocBuilder
"""

import SCons.Action
import SCons.Builder
import SCons.Defaults
import SCons.Node.FS
import SCons.Util

from SCons.Script import File, Dir, Action, Builder

import os.path

def ProtocGenerator(com, comstr, postfixes):
  _protoc_builder = Builder(
      action = Action(com, comstr),
      src_suffix='$PROTOCSRCSUFFIX',
      )
  def Protoc(env, target_dir, source):
    target_dir = Dir(target_dir)
    targets = []

    # TODO: multiple sources
    filename = os.path.basename(str(source))
    modulename = os.path.splitext(filename)[0]

    for postfix in postfixes:
      targets.append(target_dir.File(modulename + postfix))

    # must run in source dir, otherwise protoc creates source dir hierarchy in target dir
    _protoc_builder.__call__(env, target=targets, source=source)
  return Protoc

def generate(env):
    """Add Builders and construction variables for protoc to an Environment."""
    env['PROTOC_GENERATOR'] = ProtocGenerator  # allow other tools the use of this feature

    env['PROTOC']        = 'protoc'
    env['PROTOCFLAGS']   = SCons.Util.CLVar('')
    env['PROTOCPROTOPATH'] = SCons.Util.CLVar('')
    env['PROTOCSRCSUFFIX']  = '.proto'

    # protoc must run in source dir, otherwise protoc creates source dir hierarchy in target dir
    # Scons's native chdir=1 isn't used since that breaks parallel builds
    env['PROTOCCOM']     = 'cd ${SOURCES.dir} && $PROTOC ${["-I%s"%x for x in PROTOCPROTOPATH]} $PROTOCFLAGS ${SOURCES.name}'

    env.AddMethod(ProtocGenerator('$PROTOCPYTHONCOM', '$PROTOCPYTHONCOMSTR', ['_pb2.py']), 'ProtocPython')
    env['PROTOCPYTHONCOM'] = '$PROTOCCOM --python_out=${TARGET.dir.abspath}'

    env.AddMethod(ProtocGenerator('$PROTOCCPPCOM', '$PROTOCCPPCOMSTR', ['.pb.cc', '.pb.h']), 'ProtocCpp')
    env['PROTOCCPPCOM'] = '$PROTOCCOM --cpp_out=${TARGET.dir.abspath}'

def exists(env):
    return env.Detect(protocs)
