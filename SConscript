Import('env')

# .srcnode is a hack that allows this SConstruct file to be invoked inside another
env.Append(PROTOCPROTOPATH=Dir('nanopb/generator/proto').srcnode())

env.Nanopb('telemetry', 'telemetry/telemetry.proto')
env.ProtocJava('telemetry', 'telemetry/telemetry.proto',
               genfiles=['telemetry/TelemetryProto.java'])

env.Nanopb('datalogger', 'datalogger/datalogger.proto')
env.ProtocPython('datalogger', 'datalogger/datalogger.proto')

env_libs = env.Clone()
env_libs['PROTOCCOM'] = '$PROTOC ${["-I%s"%x for x in PROTOCPROTOPATH]} -I. $PROTOCFLAGS ${SOURCES}'
env_libs.Nanopb('.', 'google/protobuf/timestamp.proto',
    genfiles=['google/protobuf/timestamp.pb.c'])
env_libs.Nanopb('.', 'google/protobuf/empty.proto',
    genfiles=['google/protobuf/empty.pb.c'])

env_libs.ProtocPython('.', 'google/protobuf/timestamp.proto',
                      genfiles=['google/protobuf/timestamp_pb2.py'])
env_libs.ProtocPython('.', 'google/protobuf/empty.proto',
                      genfiles=['google/protobuf/empty_pb2.py'])

env_libs.ProtocPython('.', 'nanopb/generator/proto/nanopb.proto')