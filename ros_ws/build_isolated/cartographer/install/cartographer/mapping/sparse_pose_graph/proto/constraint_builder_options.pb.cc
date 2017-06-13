// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cartographer/mapping/sparse_pose_graph/proto/constraint_builder_options.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "cartographer/mapping/sparse_pose_graph/proto/constraint_builder_options.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace cartographer {
namespace mapping {
namespace sparse_pose_graph {
namespace proto {

namespace {

const ::google::protobuf::Descriptor* ConstraintBuilderOptions_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ConstraintBuilderOptions_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto() {
  protobuf_AddDesc_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "cartographer/mapping/sparse_pose_graph/proto/constraint_builder_options.proto");
  GOOGLE_CHECK(file != NULL);
  ConstraintBuilderOptions_descriptor_ = file->message_type(0);
  static const int ConstraintBuilderOptions_offsets_[12] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, sampling_ratio_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, max_constraint_distance_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, adaptive_voxel_filter_options_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, min_score_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, global_localization_min_score_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, loop_closure_translation_weight_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, loop_closure_rotation_weight_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, log_matches_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, fast_correlative_scan_matcher_options_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, ceres_scan_matcher_options_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, fast_correlative_scan_matcher_options_3d_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, ceres_scan_matcher_options_3d_),
  };
  ConstraintBuilderOptions_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ConstraintBuilderOptions_descriptor_,
      ConstraintBuilderOptions::default_instance_,
      ConstraintBuilderOptions_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ConstraintBuilderOptions, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ConstraintBuilderOptions));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ConstraintBuilderOptions_descriptor_, &ConstraintBuilderOptions::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto() {
  delete ConstraintBuilderOptions::default_instance_;
  delete ConstraintBuilderOptions_reflection_;
}

void protobuf_AddDesc_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::cartographer::sensor::proto::protobuf_AddDesc_cartographer_2fsensor_2fproto_2fadaptive_5fvoxel_5ffilter_5foptions_2eproto();
  ::cartographer::mapping_2d::scan_matching::proto::protobuf_AddDesc_cartographer_2fmapping_5f2d_2fscan_5fmatching_2fproto_2fceres_5fscan_5fmatcher_5foptions_2eproto();
  ::cartographer::mapping_2d::scan_matching::proto::protobuf_AddDesc_cartographer_2fmapping_5f2d_2fscan_5fmatching_2fproto_2ffast_5fcorrelative_5fscan_5fmatcher_5foptions_2eproto();
  ::cartographer::mapping_3d::scan_matching::proto::protobuf_AddDesc_cartographer_2fmapping_5f3d_2fscan_5fmatching_2fproto_2fceres_5fscan_5fmatcher_5foptions_2eproto();
  ::cartographer::mapping_3d::scan_matching::proto::protobuf_AddDesc_cartographer_2fmapping_5f3d_2fscan_5fmatching_2fproto_2ffast_5fcorrelative_5fscan_5fmatcher_5foptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\nMcartographer/mapping/sparse_pose_graph"
    "/proto/constraint_builder_options.proto\022"
    ",cartographer.mapping.sparse_pose_graph."
    "proto\032=cartographer/sensor/proto/adaptiv"
    "e_voxel_filter_options.proto\032Lcartograph"
    "er/mapping_2d/scan_matching/proto/ceres_"
    "scan_matcher_options.proto\032Wcartographer"
    "/mapping_2d/scan_matching/proto/fast_cor"
    "relative_scan_matcher_options.proto\032Lcar"
    "tographer/mapping_3d/scan_matching/proto"
    "/ceres_scan_matcher_options.proto\032Wcarto"
    "grapher/mapping_3d/scan_matching/proto/f"
    "ast_correlative_scan_matcher_options.pro"
    "to\"\250\006\n\030ConstraintBuilderOptions\022\026\n\016sampl"
    "ing_ratio\030\001 \001(\001\022\037\n\027max_constraint_distan"
    "ce\030\002 \001(\001\022\\\n\035adaptive_voxel_filter_option"
    "s\030\003 \001(\01325.cartographer.sensor.proto.Adap"
    "tiveVoxelFilterOptions\022\021\n\tmin_score\030\004 \001("
    "\001\022%\n\035global_localization_min_score\030\005 \001(\001"
    "\022\'\n\037loop_closure_translation_weight\030\r \001("
    "\001\022$\n\034loop_closure_rotation_weight\030\016 \001(\001\022"
    "\023\n\013log_matches\030\010 \001(\010\022}\n%fast_correlative"
    "_scan_matcher_options\030\t \001(\0132N.cartograph"
    "er.mapping_2d.scan_matching.proto.FastCo"
    "rrelativeScanMatcherOptions\022h\n\032ceres_sca"
    "n_matcher_options\030\013 \001(\0132D.cartographer.m"
    "apping_2d.scan_matching.proto.CeresScanM"
    "atcherOptions\022\200\001\n(fast_correlative_scan_"
    "matcher_options_3d\030\n \001(\0132N.cartographer."
    "mapping_3d.scan_matching.proto.FastCorre"
    "lativeScanMatcherOptions\022k\n\035ceres_scan_m"
    "atcher_options_3d\030\014 \001(\0132D.cartographer.m"
    "apping_3d.scan_matching.proto.CeresScanM"
    "atcherOptions", 1333);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "cartographer/mapping/sparse_pose_graph/proto/constraint_builder_options.proto", &protobuf_RegisterTypes);
  ConstraintBuilderOptions::default_instance_ = new ConstraintBuilderOptions();
  ConstraintBuilderOptions::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto {
  StaticDescriptorInitializer_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto() {
    protobuf_AddDesc_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto();
  }
} static_descriptor_initializer_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ConstraintBuilderOptions::kSamplingRatioFieldNumber;
const int ConstraintBuilderOptions::kMaxConstraintDistanceFieldNumber;
const int ConstraintBuilderOptions::kAdaptiveVoxelFilterOptionsFieldNumber;
const int ConstraintBuilderOptions::kMinScoreFieldNumber;
const int ConstraintBuilderOptions::kGlobalLocalizationMinScoreFieldNumber;
const int ConstraintBuilderOptions::kLoopClosureTranslationWeightFieldNumber;
const int ConstraintBuilderOptions::kLoopClosureRotationWeightFieldNumber;
const int ConstraintBuilderOptions::kLogMatchesFieldNumber;
const int ConstraintBuilderOptions::kFastCorrelativeScanMatcherOptionsFieldNumber;
const int ConstraintBuilderOptions::kCeresScanMatcherOptionsFieldNumber;
const int ConstraintBuilderOptions::kFastCorrelativeScanMatcherOptions3DFieldNumber;
const int ConstraintBuilderOptions::kCeresScanMatcherOptions3DFieldNumber;
#endif  // !_MSC_VER

ConstraintBuilderOptions::ConstraintBuilderOptions()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
}

void ConstraintBuilderOptions::InitAsDefaultInstance() {
  adaptive_voxel_filter_options_ = const_cast< ::cartographer::sensor::proto::AdaptiveVoxelFilterOptions*>(&::cartographer::sensor::proto::AdaptiveVoxelFilterOptions::default_instance());
  fast_correlative_scan_matcher_options_ = const_cast< ::cartographer::mapping_2d::scan_matching::proto::FastCorrelativeScanMatcherOptions*>(&::cartographer::mapping_2d::scan_matching::proto::FastCorrelativeScanMatcherOptions::default_instance());
  ceres_scan_matcher_options_ = const_cast< ::cartographer::mapping_2d::scan_matching::proto::CeresScanMatcherOptions*>(&::cartographer::mapping_2d::scan_matching::proto::CeresScanMatcherOptions::default_instance());
  fast_correlative_scan_matcher_options_3d_ = const_cast< ::cartographer::mapping_3d::scan_matching::proto::FastCorrelativeScanMatcherOptions*>(&::cartographer::mapping_3d::scan_matching::proto::FastCorrelativeScanMatcherOptions::default_instance());
  ceres_scan_matcher_options_3d_ = const_cast< ::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions*>(&::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions::default_instance());
}

ConstraintBuilderOptions::ConstraintBuilderOptions(const ConstraintBuilderOptions& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
}

void ConstraintBuilderOptions::SharedCtor() {
  _cached_size_ = 0;
  sampling_ratio_ = 0;
  max_constraint_distance_ = 0;
  adaptive_voxel_filter_options_ = NULL;
  min_score_ = 0;
  global_localization_min_score_ = 0;
  loop_closure_translation_weight_ = 0;
  loop_closure_rotation_weight_ = 0;
  log_matches_ = false;
  fast_correlative_scan_matcher_options_ = NULL;
  ceres_scan_matcher_options_ = NULL;
  fast_correlative_scan_matcher_options_3d_ = NULL;
  ceres_scan_matcher_options_3d_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ConstraintBuilderOptions::~ConstraintBuilderOptions() {
  // @@protoc_insertion_point(destructor:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
  SharedDtor();
}

void ConstraintBuilderOptions::SharedDtor() {
  if (this != default_instance_) {
    delete adaptive_voxel_filter_options_;
    delete fast_correlative_scan_matcher_options_;
    delete ceres_scan_matcher_options_;
    delete fast_correlative_scan_matcher_options_3d_;
    delete ceres_scan_matcher_options_3d_;
  }
}

void ConstraintBuilderOptions::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ConstraintBuilderOptions::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ConstraintBuilderOptions_descriptor_;
}

const ConstraintBuilderOptions& ConstraintBuilderOptions::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_cartographer_2fmapping_2fsparse_5fpose_5fgraph_2fproto_2fconstraint_5fbuilder_5foptions_2eproto();
  return *default_instance_;
}

ConstraintBuilderOptions* ConstraintBuilderOptions::default_instance_ = NULL;

ConstraintBuilderOptions* ConstraintBuilderOptions::New() const {
  return new ConstraintBuilderOptions;
}

void ConstraintBuilderOptions::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<ConstraintBuilderOptions*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(sampling_ratio_, max_constraint_distance_);
    ZR_(min_score_, loop_closure_rotation_weight_);
    if (has_adaptive_voxel_filter_options()) {
      if (adaptive_voxel_filter_options_ != NULL) adaptive_voxel_filter_options_->::cartographer::sensor::proto::AdaptiveVoxelFilterOptions::Clear();
    }
    log_matches_ = false;
  }
  if (_has_bits_[8 / 32] & 3840) {
    if (has_fast_correlative_scan_matcher_options()) {
      if (fast_correlative_scan_matcher_options_ != NULL) fast_correlative_scan_matcher_options_->::cartographer::mapping_2d::scan_matching::proto::FastCorrelativeScanMatcherOptions::Clear();
    }
    if (has_ceres_scan_matcher_options()) {
      if (ceres_scan_matcher_options_ != NULL) ceres_scan_matcher_options_->::cartographer::mapping_2d::scan_matching::proto::CeresScanMatcherOptions::Clear();
    }
    if (has_fast_correlative_scan_matcher_options_3d()) {
      if (fast_correlative_scan_matcher_options_3d_ != NULL) fast_correlative_scan_matcher_options_3d_->::cartographer::mapping_3d::scan_matching::proto::FastCorrelativeScanMatcherOptions::Clear();
    }
    if (has_ceres_scan_matcher_options_3d()) {
      if (ceres_scan_matcher_options_3d_ != NULL) ceres_scan_matcher_options_3d_->::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ConstraintBuilderOptions::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional double sampling_ratio = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &sampling_ratio_)));
          set_has_sampling_ratio();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(17)) goto parse_max_constraint_distance;
        break;
      }

      // optional double max_constraint_distance = 2;
      case 2: {
        if (tag == 17) {
         parse_max_constraint_distance:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &max_constraint_distance_)));
          set_has_max_constraint_distance();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_adaptive_voxel_filter_options;
        break;
      }

      // optional .cartographer.sensor.proto.AdaptiveVoxelFilterOptions adaptive_voxel_filter_options = 3;
      case 3: {
        if (tag == 26) {
         parse_adaptive_voxel_filter_options:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_adaptive_voxel_filter_options()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(33)) goto parse_min_score;
        break;
      }

      // optional double min_score = 4;
      case 4: {
        if (tag == 33) {
         parse_min_score:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &min_score_)));
          set_has_min_score();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(41)) goto parse_global_localization_min_score;
        break;
      }

      // optional double global_localization_min_score = 5;
      case 5: {
        if (tag == 41) {
         parse_global_localization_min_score:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &global_localization_min_score_)));
          set_has_global_localization_min_score();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_log_matches;
        break;
      }

      // optional bool log_matches = 8;
      case 8: {
        if (tag == 64) {
         parse_log_matches:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &log_matches_)));
          set_has_log_matches();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(74)) goto parse_fast_correlative_scan_matcher_options;
        break;
      }

      // optional .cartographer.mapping_2d.scan_matching.proto.FastCorrelativeScanMatcherOptions fast_correlative_scan_matcher_options = 9;
      case 9: {
        if (tag == 74) {
         parse_fast_correlative_scan_matcher_options:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_fast_correlative_scan_matcher_options()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(82)) goto parse_fast_correlative_scan_matcher_options_3d;
        break;
      }

      // optional .cartographer.mapping_3d.scan_matching.proto.FastCorrelativeScanMatcherOptions fast_correlative_scan_matcher_options_3d = 10;
      case 10: {
        if (tag == 82) {
         parse_fast_correlative_scan_matcher_options_3d:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_fast_correlative_scan_matcher_options_3d()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_ceres_scan_matcher_options;
        break;
      }

      // optional .cartographer.mapping_2d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options = 11;
      case 11: {
        if (tag == 90) {
         parse_ceres_scan_matcher_options:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_ceres_scan_matcher_options()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_ceres_scan_matcher_options_3d;
        break;
      }

      // optional .cartographer.mapping_3d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options_3d = 12;
      case 12: {
        if (tag == 98) {
         parse_ceres_scan_matcher_options_3d:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_ceres_scan_matcher_options_3d()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(105)) goto parse_loop_closure_translation_weight;
        break;
      }

      // optional double loop_closure_translation_weight = 13;
      case 13: {
        if (tag == 105) {
         parse_loop_closure_translation_weight:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &loop_closure_translation_weight_)));
          set_has_loop_closure_translation_weight();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(113)) goto parse_loop_closure_rotation_weight;
        break;
      }

      // optional double loop_closure_rotation_weight = 14;
      case 14: {
        if (tag == 113) {
         parse_loop_closure_rotation_weight:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &loop_closure_rotation_weight_)));
          set_has_loop_closure_rotation_weight();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
  return false;
#undef DO_
}

void ConstraintBuilderOptions::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
  // optional double sampling_ratio = 1;
  if (has_sampling_ratio()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->sampling_ratio(), output);
  }

  // optional double max_constraint_distance = 2;
  if (has_max_constraint_distance()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->max_constraint_distance(), output);
  }

  // optional .cartographer.sensor.proto.AdaptiveVoxelFilterOptions adaptive_voxel_filter_options = 3;
  if (has_adaptive_voxel_filter_options()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->adaptive_voxel_filter_options(), output);
  }

  // optional double min_score = 4;
  if (has_min_score()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->min_score(), output);
  }

  // optional double global_localization_min_score = 5;
  if (has_global_localization_min_score()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(5, this->global_localization_min_score(), output);
  }

  // optional bool log_matches = 8;
  if (has_log_matches()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->log_matches(), output);
  }

  // optional .cartographer.mapping_2d.scan_matching.proto.FastCorrelativeScanMatcherOptions fast_correlative_scan_matcher_options = 9;
  if (has_fast_correlative_scan_matcher_options()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      9, this->fast_correlative_scan_matcher_options(), output);
  }

  // optional .cartographer.mapping_3d.scan_matching.proto.FastCorrelativeScanMatcherOptions fast_correlative_scan_matcher_options_3d = 10;
  if (has_fast_correlative_scan_matcher_options_3d()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      10, this->fast_correlative_scan_matcher_options_3d(), output);
  }

  // optional .cartographer.mapping_2d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options = 11;
  if (has_ceres_scan_matcher_options()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->ceres_scan_matcher_options(), output);
  }

  // optional .cartographer.mapping_3d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options_3d = 12;
  if (has_ceres_scan_matcher_options_3d()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      12, this->ceres_scan_matcher_options_3d(), output);
  }

  // optional double loop_closure_translation_weight = 13;
  if (has_loop_closure_translation_weight()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(13, this->loop_closure_translation_weight(), output);
  }

  // optional double loop_closure_rotation_weight = 14;
  if (has_loop_closure_rotation_weight()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(14, this->loop_closure_rotation_weight(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
}

::google::protobuf::uint8* ConstraintBuilderOptions::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
  // optional double sampling_ratio = 1;
  if (has_sampling_ratio()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->sampling_ratio(), target);
  }

  // optional double max_constraint_distance = 2;
  if (has_max_constraint_distance()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->max_constraint_distance(), target);
  }

  // optional .cartographer.sensor.proto.AdaptiveVoxelFilterOptions adaptive_voxel_filter_options = 3;
  if (has_adaptive_voxel_filter_options()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->adaptive_voxel_filter_options(), target);
  }

  // optional double min_score = 4;
  if (has_min_score()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->min_score(), target);
  }

  // optional double global_localization_min_score = 5;
  if (has_global_localization_min_score()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, this->global_localization_min_score(), target);
  }

  // optional bool log_matches = 8;
  if (has_log_matches()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->log_matches(), target);
  }

  // optional .cartographer.mapping_2d.scan_matching.proto.FastCorrelativeScanMatcherOptions fast_correlative_scan_matcher_options = 9;
  if (has_fast_correlative_scan_matcher_options()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        9, this->fast_correlative_scan_matcher_options(), target);
  }

  // optional .cartographer.mapping_3d.scan_matching.proto.FastCorrelativeScanMatcherOptions fast_correlative_scan_matcher_options_3d = 10;
  if (has_fast_correlative_scan_matcher_options_3d()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        10, this->fast_correlative_scan_matcher_options_3d(), target);
  }

  // optional .cartographer.mapping_2d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options = 11;
  if (has_ceres_scan_matcher_options()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->ceres_scan_matcher_options(), target);
  }

  // optional .cartographer.mapping_3d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options_3d = 12;
  if (has_ceres_scan_matcher_options_3d()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        12, this->ceres_scan_matcher_options_3d(), target);
  }

  // optional double loop_closure_translation_weight = 13;
  if (has_loop_closure_translation_weight()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(13, this->loop_closure_translation_weight(), target);
  }

  // optional double loop_closure_rotation_weight = 14;
  if (has_loop_closure_rotation_weight()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(14, this->loop_closure_rotation_weight(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:cartographer.mapping.sparse_pose_graph.proto.ConstraintBuilderOptions)
  return target;
}

int ConstraintBuilderOptions::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional double sampling_ratio = 1;
    if (has_sampling_ratio()) {
      total_size += 1 + 8;
    }

    // optional double max_constraint_distance = 2;
    if (has_max_constraint_distance()) {
      total_size += 1 + 8;
    }

    // optional .cartographer.sensor.proto.AdaptiveVoxelFilterOptions adaptive_voxel_filter_options = 3;
    if (has_adaptive_voxel_filter_options()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->adaptive_voxel_filter_options());
    }

    // optional double min_score = 4;
    if (has_min_score()) {
      total_size += 1 + 8;
    }

    // optional double global_localization_min_score = 5;
    if (has_global_localization_min_score()) {
      total_size += 1 + 8;
    }

    // optional double loop_closure_translation_weight = 13;
    if (has_loop_closure_translation_weight()) {
      total_size += 1 + 8;
    }

    // optional double loop_closure_rotation_weight = 14;
    if (has_loop_closure_rotation_weight()) {
      total_size += 1 + 8;
    }

    // optional bool log_matches = 8;
    if (has_log_matches()) {
      total_size += 1 + 1;
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional .cartographer.mapping_2d.scan_matching.proto.FastCorrelativeScanMatcherOptions fast_correlative_scan_matcher_options = 9;
    if (has_fast_correlative_scan_matcher_options()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->fast_correlative_scan_matcher_options());
    }

    // optional .cartographer.mapping_2d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options = 11;
    if (has_ceres_scan_matcher_options()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->ceres_scan_matcher_options());
    }

    // optional .cartographer.mapping_3d.scan_matching.proto.FastCorrelativeScanMatcherOptions fast_correlative_scan_matcher_options_3d = 10;
    if (has_fast_correlative_scan_matcher_options_3d()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->fast_correlative_scan_matcher_options_3d());
    }

    // optional .cartographer.mapping_3d.scan_matching.proto.CeresScanMatcherOptions ceres_scan_matcher_options_3d = 12;
    if (has_ceres_scan_matcher_options_3d()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->ceres_scan_matcher_options_3d());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ConstraintBuilderOptions::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ConstraintBuilderOptions* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ConstraintBuilderOptions*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ConstraintBuilderOptions::MergeFrom(const ConstraintBuilderOptions& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_sampling_ratio()) {
      set_sampling_ratio(from.sampling_ratio());
    }
    if (from.has_max_constraint_distance()) {
      set_max_constraint_distance(from.max_constraint_distance());
    }
    if (from.has_adaptive_voxel_filter_options()) {
      mutable_adaptive_voxel_filter_options()->::cartographer::sensor::proto::AdaptiveVoxelFilterOptions::MergeFrom(from.adaptive_voxel_filter_options());
    }
    if (from.has_min_score()) {
      set_min_score(from.min_score());
    }
    if (from.has_global_localization_min_score()) {
      set_global_localization_min_score(from.global_localization_min_score());
    }
    if (from.has_loop_closure_translation_weight()) {
      set_loop_closure_translation_weight(from.loop_closure_translation_weight());
    }
    if (from.has_loop_closure_rotation_weight()) {
      set_loop_closure_rotation_weight(from.loop_closure_rotation_weight());
    }
    if (from.has_log_matches()) {
      set_log_matches(from.log_matches());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_fast_correlative_scan_matcher_options()) {
      mutable_fast_correlative_scan_matcher_options()->::cartographer::mapping_2d::scan_matching::proto::FastCorrelativeScanMatcherOptions::MergeFrom(from.fast_correlative_scan_matcher_options());
    }
    if (from.has_ceres_scan_matcher_options()) {
      mutable_ceres_scan_matcher_options()->::cartographer::mapping_2d::scan_matching::proto::CeresScanMatcherOptions::MergeFrom(from.ceres_scan_matcher_options());
    }
    if (from.has_fast_correlative_scan_matcher_options_3d()) {
      mutable_fast_correlative_scan_matcher_options_3d()->::cartographer::mapping_3d::scan_matching::proto::FastCorrelativeScanMatcherOptions::MergeFrom(from.fast_correlative_scan_matcher_options_3d());
    }
    if (from.has_ceres_scan_matcher_options_3d()) {
      mutable_ceres_scan_matcher_options_3d()->::cartographer::mapping_3d::scan_matching::proto::CeresScanMatcherOptions::MergeFrom(from.ceres_scan_matcher_options_3d());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ConstraintBuilderOptions::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConstraintBuilderOptions::CopyFrom(const ConstraintBuilderOptions& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConstraintBuilderOptions::IsInitialized() const {

  return true;
}

void ConstraintBuilderOptions::Swap(ConstraintBuilderOptions* other) {
  if (other != this) {
    std::swap(sampling_ratio_, other->sampling_ratio_);
    std::swap(max_constraint_distance_, other->max_constraint_distance_);
    std::swap(adaptive_voxel_filter_options_, other->adaptive_voxel_filter_options_);
    std::swap(min_score_, other->min_score_);
    std::swap(global_localization_min_score_, other->global_localization_min_score_);
    std::swap(loop_closure_translation_weight_, other->loop_closure_translation_weight_);
    std::swap(loop_closure_rotation_weight_, other->loop_closure_rotation_weight_);
    std::swap(log_matches_, other->log_matches_);
    std::swap(fast_correlative_scan_matcher_options_, other->fast_correlative_scan_matcher_options_);
    std::swap(ceres_scan_matcher_options_, other->ceres_scan_matcher_options_);
    std::swap(fast_correlative_scan_matcher_options_3d_, other->fast_correlative_scan_matcher_options_3d_);
    std::swap(ceres_scan_matcher_options_3d_, other->ceres_scan_matcher_options_3d_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ConstraintBuilderOptions::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ConstraintBuilderOptions_descriptor_;
  metadata.reflection = ConstraintBuilderOptions_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace sparse_pose_graph
}  // namespace mapping
}  // namespace cartographer

// @@protoc_insertion_point(global_scope)
