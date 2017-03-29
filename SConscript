Import('env')

env.Append(PROTOCPROTOPATH='nanopb/generator/proto')

env.Nanopb('telemetry', 'telemetry/telemetry.proto')
env.ProtocJava('telemetry', 'telemetry/telemetry.proto',
               genfiles=['telemetry/TelemetryProto.java'])

env.Nanopb('datalogger', 'datalogger/datalogger.proto')
env.ProtocPython('datalogger', 'datalogger/datalogger.proto')
