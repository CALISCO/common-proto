// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: telemetry.proto

public final class TelemetryProto {
  private TelemetryProto() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  public interface TelemetryOrBuilder extends
      // @@protoc_insertion_point(interface_extends:Telemetry)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>optional int32 timestamp_ms = 1;</code>
     */
    boolean hasTimestampMs();
    /**
     * <code>optional int32 timestamp_ms = 1;</code>
     */
    int getTimestampMs();
  }
  /**
   * Protobuf type {@code Telemetry}
   */
  public  static final class Telemetry extends
      com.google.protobuf.GeneratedMessageV3 implements
      // @@protoc_insertion_point(message_implements:Telemetry)
      TelemetryOrBuilder {
    // Use Telemetry.newBuilder() to construct.
    private Telemetry(com.google.protobuf.GeneratedMessageV3.Builder<?> builder) {
      super(builder);
    }
    private Telemetry() {
      timestampMs_ = 0;
    }

    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
    getUnknownFields() {
      return this.unknownFields;
    }
    private Telemetry(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      this();
      int mutable_bitField0_ = 0;
      com.google.protobuf.UnknownFieldSet.Builder unknownFields =
          com.google.protobuf.UnknownFieldSet.newBuilder();
      try {
        boolean done = false;
        while (!done) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              done = true;
              break;
            default: {
              if (!parseUnknownField(input, unknownFields,
                                     extensionRegistry, tag)) {
                done = true;
              }
              break;
            }
            case 8: {
              bitField0_ |= 0x00000001;
              timestampMs_ = input.readInt32();
              break;
            }
          }
        }
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        throw e.setUnfinishedMessage(this);
      } catch (java.io.IOException e) {
        throw new com.google.protobuf.InvalidProtocolBufferException(
            e).setUnfinishedMessage(this);
      } finally {
        this.unknownFields = unknownFields.build();
        makeExtensionsImmutable();
      }
    }
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return TelemetryProto.internal_static_Telemetry_descriptor;
    }

    protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return TelemetryProto.internal_static_Telemetry_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              TelemetryProto.Telemetry.class, TelemetryProto.Telemetry.Builder.class);
    }

    private int bitField0_;
    public static final int TIMESTAMP_MS_FIELD_NUMBER = 1;
    private int timestampMs_;
    /**
     * <code>optional int32 timestamp_ms = 1;</code>
     */
    public boolean hasTimestampMs() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>optional int32 timestamp_ms = 1;</code>
     */
    public int getTimestampMs() {
      return timestampMs_;
    }

    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        output.writeInt32(1, timestampMs_);
      }
      unknownFields.writeTo(output);
    }

    public int getSerializedSize() {
      int size = memoizedSize;
      if (size != -1) return size;

      size = 0;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        size += com.google.protobuf.CodedOutputStream
          .computeInt32Size(1, timestampMs_);
      }
      size += unknownFields.getSerializedSize();
      memoizedSize = size;
      return size;
    }

    private static final long serialVersionUID = 0L;
    @java.lang.Override
    public boolean equals(final java.lang.Object obj) {
      if (obj == this) {
       return true;
      }
      if (!(obj instanceof TelemetryProto.Telemetry)) {
        return super.equals(obj);
      }
      TelemetryProto.Telemetry other = (TelemetryProto.Telemetry) obj;

      boolean result = true;
      result = result && (hasTimestampMs() == other.hasTimestampMs());
      if (hasTimestampMs()) {
        result = result && (getTimestampMs()
            == other.getTimestampMs());
      }
      result = result && unknownFields.equals(other.unknownFields);
      return result;
    }

    @java.lang.Override
    public int hashCode() {
      if (memoizedHashCode != 0) {
        return memoizedHashCode;
      }
      int hash = 41;
      hash = (19 * hash) + getDescriptor().hashCode();
      if (hasTimestampMs()) {
        hash = (37 * hash) + TIMESTAMP_MS_FIELD_NUMBER;
        hash = (53 * hash) + getTimestampMs();
      }
      hash = (29 * hash) + unknownFields.hashCode();
      memoizedHashCode = hash;
      return hash;
    }

    public static TelemetryProto.Telemetry parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static TelemetryProto.Telemetry parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static TelemetryProto.Telemetry parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static TelemetryProto.Telemetry parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static TelemetryProto.Telemetry parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static TelemetryProto.Telemetry parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }
    public static TelemetryProto.Telemetry parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input);
    }
    public static TelemetryProto.Telemetry parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseDelimitedWithIOException(PARSER, input, extensionRegistry);
    }
    public static TelemetryProto.Telemetry parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input);
    }
    public static TelemetryProto.Telemetry parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return com.google.protobuf.GeneratedMessageV3
          .parseWithIOException(PARSER, input, extensionRegistry);
    }

    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder() {
      return DEFAULT_INSTANCE.toBuilder();
    }
    public static Builder newBuilder(TelemetryProto.Telemetry prototype) {
      return DEFAULT_INSTANCE.toBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() {
      return this == DEFAULT_INSTANCE
          ? new Builder() : new Builder().mergeFrom(this);
    }

    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    /**
     * Protobuf type {@code Telemetry}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessageV3.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:Telemetry)
        TelemetryProto.TelemetryOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return TelemetryProto.internal_static_Telemetry_descriptor;
      }

      protected com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return TelemetryProto.internal_static_Telemetry_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                TelemetryProto.Telemetry.class, TelemetryProto.Telemetry.Builder.class);
      }

      // Construct using TelemetryProto.Telemetry.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }

      private Builder(
          com.google.protobuf.GeneratedMessageV3.BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessageV3
                .alwaysUseFieldBuilders) {
        }
      }
      public Builder clear() {
        super.clear();
        timestampMs_ = 0;
        bitField0_ = (bitField0_ & ~0x00000001);
        return this;
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return TelemetryProto.internal_static_Telemetry_descriptor;
      }

      public TelemetryProto.Telemetry getDefaultInstanceForType() {
        return TelemetryProto.Telemetry.getDefaultInstance();
      }

      public TelemetryProto.Telemetry build() {
        TelemetryProto.Telemetry result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public TelemetryProto.Telemetry buildPartial() {
        TelemetryProto.Telemetry result = new TelemetryProto.Telemetry(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.timestampMs_ = timestampMs_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder clone() {
        return (Builder) super.clone();
      }
      public Builder setField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          Object value) {
        return (Builder) super.setField(field, value);
      }
      public Builder clearField(
          com.google.protobuf.Descriptors.FieldDescriptor field) {
        return (Builder) super.clearField(field);
      }
      public Builder clearOneof(
          com.google.protobuf.Descriptors.OneofDescriptor oneof) {
        return (Builder) super.clearOneof(oneof);
      }
      public Builder setRepeatedField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          int index, Object value) {
        return (Builder) super.setRepeatedField(field, index, value);
      }
      public Builder addRepeatedField(
          com.google.protobuf.Descriptors.FieldDescriptor field,
          Object value) {
        return (Builder) super.addRepeatedField(field, value);
      }
      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof TelemetryProto.Telemetry) {
          return mergeFrom((TelemetryProto.Telemetry)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(TelemetryProto.Telemetry other) {
        if (other == TelemetryProto.Telemetry.getDefaultInstance()) return this;
        if (other.hasTimestampMs()) {
          setTimestampMs(other.getTimestampMs());
        }
        this.mergeUnknownFields(other.unknownFields);
        onChanged();
        return this;
      }

      public final boolean isInitialized() {
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        TelemetryProto.Telemetry parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (TelemetryProto.Telemetry) e.getUnfinishedMessage();
          throw e.unwrapIOException();
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private int timestampMs_ ;
      /**
       * <code>optional int32 timestamp_ms = 1;</code>
       */
      public boolean hasTimestampMs() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>optional int32 timestamp_ms = 1;</code>
       */
      public int getTimestampMs() {
        return timestampMs_;
      }
      /**
       * <code>optional int32 timestamp_ms = 1;</code>
       */
      public Builder setTimestampMs(int value) {
        bitField0_ |= 0x00000001;
        timestampMs_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional int32 timestamp_ms = 1;</code>
       */
      public Builder clearTimestampMs() {
        bitField0_ = (bitField0_ & ~0x00000001);
        timestampMs_ = 0;
        onChanged();
        return this;
      }
      public final Builder setUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return super.setUnknownFields(unknownFields);
      }

      public final Builder mergeUnknownFields(
          final com.google.protobuf.UnknownFieldSet unknownFields) {
        return super.mergeUnknownFields(unknownFields);
      }


      // @@protoc_insertion_point(builder_scope:Telemetry)
    }

    // @@protoc_insertion_point(class_scope:Telemetry)
    private static final TelemetryProto.Telemetry DEFAULT_INSTANCE;
    static {
      DEFAULT_INSTANCE = new TelemetryProto.Telemetry();
    }

    public static TelemetryProto.Telemetry getDefaultInstance() {
      return DEFAULT_INSTANCE;
    }

    @java.lang.Deprecated public static final com.google.protobuf.Parser<Telemetry>
        PARSER = new com.google.protobuf.AbstractParser<Telemetry>() {
      public Telemetry parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
          return new Telemetry(input, extensionRegistry);
      }
    };

    public static com.google.protobuf.Parser<Telemetry> parser() {
      return PARSER;
    }

    @java.lang.Override
    public com.google.protobuf.Parser<Telemetry> getParserForType() {
      return PARSER;
    }

    public TelemetryProto.Telemetry getDefaultInstanceForType() {
      return DEFAULT_INSTANCE;
    }

  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_Telemetry_descriptor;
  private static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_Telemetry_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\017telemetry.proto\032\014nanopb.proto\"!\n\tTelem" +
      "etry\022\024\n\014timestamp_ms\030\001 \001(\005B\020B\016TelemetryP" +
      "roto"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
          fi.kapsi.koti.jpa.nanopb.Nanopb.getDescriptor(),
        }, assigner);
    internal_static_Telemetry_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_Telemetry_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_Telemetry_descriptor,
        new java.lang.String[] { "TimestampMs", });
    fi.kapsi.koti.jpa.nanopb.Nanopb.getDescriptor();
  }

  // @@protoc_insertion_point(outer_class_scope)
}
