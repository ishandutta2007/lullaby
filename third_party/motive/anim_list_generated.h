/*
Copyright 2017 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS-IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ANIMLIST_MOTIVE_H_
#define FLATBUFFERS_GENERATED_ANIMLIST_MOTIVE_H_

#include "flatbuffers/flatbuffers.h"

#include "anim_generated.h"
#include "compact_spline_generated.h"

namespace motive {

struct AnimSourceFileName;

struct AnimSourceEmbedded;

struct AnimSource;

struct AnimListFb;

enum AnimSourceUnion {
  AnimSourceUnion_NONE = 0,
  AnimSourceUnion_AnimSourceFileName = 1,
  AnimSourceUnion_AnimSourceEmbedded = 2,
  AnimSourceUnion_MIN = AnimSourceUnion_NONE,
  AnimSourceUnion_MAX = AnimSourceUnion_AnimSourceEmbedded
};

inline AnimSourceUnion (&EnumValuesAnimSourceUnion())[3] {
  static AnimSourceUnion values[] = {
    AnimSourceUnion_NONE,
    AnimSourceUnion_AnimSourceFileName,
    AnimSourceUnion_AnimSourceEmbedded
  };
  return values;
}

inline const char **EnumNamesAnimSourceUnion() {
  static const char *names[] = {
    "NONE",
    "AnimSourceFileName",
    "AnimSourceEmbedded",
    nullptr
  };
  return names;
}

inline const char *EnumNameAnimSourceUnion(AnimSourceUnion e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesAnimSourceUnion()[index];
}

template<typename T> struct AnimSourceUnionTraits {
  static const AnimSourceUnion enum_value = AnimSourceUnion_NONE;
};

template<> struct AnimSourceUnionTraits<AnimSourceFileName> {
  static const AnimSourceUnion enum_value = AnimSourceUnion_AnimSourceFileName;
};

template<> struct AnimSourceUnionTraits<AnimSourceEmbedded> {
  static const AnimSourceUnion enum_value = AnimSourceUnion_AnimSourceEmbedded;
};

bool VerifyAnimSourceUnion(flatbuffers::Verifier &verifier, const void *obj, AnimSourceUnion type);
bool VerifyAnimSourceUnionVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct AnimSourceFileName FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_FILE_NAME = 4
  };
  const flatbuffers::String *file_name() const {
    return GetPointer<const flatbuffers::String *>(VT_FILE_NAME);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_FILE_NAME) &&
           verifier.Verify(file_name()) &&
           verifier.EndTable();
  }
};

struct AnimSourceFileNameBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_file_name(flatbuffers::Offset<flatbuffers::String> file_name) {
    fbb_.AddOffset(AnimSourceFileName::VT_FILE_NAME, file_name);
  }
  AnimSourceFileNameBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AnimSourceFileNameBuilder &operator=(const AnimSourceFileNameBuilder &);
  flatbuffers::Offset<AnimSourceFileName> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<AnimSourceFileName>(end);
    return o;
  }
};

inline flatbuffers::Offset<AnimSourceFileName> CreateAnimSourceFileName(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> file_name = 0) {
  AnimSourceFileNameBuilder builder_(_fbb);
  builder_.add_file_name(file_name);
  return builder_.Finish();
}

inline flatbuffers::Offset<AnimSourceFileName> CreateAnimSourceFileNameDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *file_name = nullptr) {
  return motive::CreateAnimSourceFileName(
      _fbb,
      file_name ? _fbb.CreateString(file_name) : 0);
}

struct AnimSourceEmbedded FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_EMBEDDED = 4
  };
  const motive::RigAnimFb *embedded() const {
    return GetPointer<const motive::RigAnimFb *>(VT_EMBEDDED);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_EMBEDDED) &&
           verifier.VerifyTable(embedded()) &&
           verifier.EndTable();
  }
};

struct AnimSourceEmbeddedBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_embedded(flatbuffers::Offset<motive::RigAnimFb> embedded) {
    fbb_.AddOffset(AnimSourceEmbedded::VT_EMBEDDED, embedded);
  }
  AnimSourceEmbeddedBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AnimSourceEmbeddedBuilder &operator=(const AnimSourceEmbeddedBuilder &);
  flatbuffers::Offset<AnimSourceEmbedded> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<AnimSourceEmbedded>(end);
    return o;
  }
};

inline flatbuffers::Offset<AnimSourceEmbedded> CreateAnimSourceEmbedded(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<motive::RigAnimFb> embedded = 0) {
  AnimSourceEmbeddedBuilder builder_(_fbb);
  builder_.add_embedded(embedded);
  return builder_.Finish();
}

struct AnimSource FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_U_TYPE = 4,
    VT_U = 6
  };
  AnimSourceUnion u_type() const {
    return static_cast<AnimSourceUnion>(GetField<uint8_t>(VT_U_TYPE, 0));
  }
  const void *u() const {
    return GetPointer<const void *>(VT_U);
  }
  template<typename T> const T *u_as() const;
  const AnimSourceFileName *u_as_AnimSourceFileName() const {
    return u_type() == AnimSourceUnion_AnimSourceFileName ? static_cast<const AnimSourceFileName *>(u()) : nullptr;
  }
  const AnimSourceEmbedded *u_as_AnimSourceEmbedded() const {
    return u_type() == AnimSourceUnion_AnimSourceEmbedded ? static_cast<const AnimSourceEmbedded *>(u()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_U_TYPE) &&
           VerifyOffset(verifier, VT_U) &&
           VerifyAnimSourceUnion(verifier, u(), u_type()) &&
           verifier.EndTable();
  }
};

template<> inline const AnimSourceFileName *AnimSource::u_as<AnimSourceFileName>() const {
  return u_as_AnimSourceFileName();
}

template<> inline const AnimSourceEmbedded *AnimSource::u_as<AnimSourceEmbedded>() const {
  return u_as_AnimSourceEmbedded();
}

struct AnimSourceBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_u_type(AnimSourceUnion u_type) {
    fbb_.AddElement<uint8_t>(AnimSource::VT_U_TYPE, static_cast<uint8_t>(u_type), 0);
  }
  void add_u(flatbuffers::Offset<void> u) {
    fbb_.AddOffset(AnimSource::VT_U, u);
  }
  AnimSourceBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AnimSourceBuilder &operator=(const AnimSourceBuilder &);
  flatbuffers::Offset<AnimSource> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<AnimSource>(end);
    return o;
  }
};

inline flatbuffers::Offset<AnimSource> CreateAnimSource(
    flatbuffers::FlatBufferBuilder &_fbb,
    AnimSourceUnion u_type = AnimSourceUnion_NONE,
    flatbuffers::Offset<void> u = 0) {
  AnimSourceBuilder builder_(_fbb);
  builder_.add_u(u);
  builder_.add_u_type(u_type);
  return builder_.Finish();
}

struct AnimListFb FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ANIM_FILES = 4,
    VT_ANIMS = 6
  };
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *anim_files() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_ANIM_FILES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<AnimSource>> *anims() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<AnimSource>> *>(VT_ANIMS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ANIM_FILES) &&
           verifier.Verify(anim_files()) &&
           verifier.VerifyVectorOfStrings(anim_files()) &&
           VerifyOffset(verifier, VT_ANIMS) &&
           verifier.Verify(anims()) &&
           verifier.VerifyVectorOfTables(anims()) &&
           verifier.EndTable();
  }
};

struct AnimListFbBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_anim_files(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> anim_files) {
    fbb_.AddOffset(AnimListFb::VT_ANIM_FILES, anim_files);
  }
  void add_anims(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<AnimSource>>> anims) {
    fbb_.AddOffset(AnimListFb::VT_ANIMS, anims);
  }
  AnimListFbBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AnimListFbBuilder &operator=(const AnimListFbBuilder &);
  flatbuffers::Offset<AnimListFb> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<AnimListFb>(end);
    return o;
  }
};

inline flatbuffers::Offset<AnimListFb> CreateAnimListFb(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> anim_files = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<AnimSource>>> anims = 0) {
  AnimListFbBuilder builder_(_fbb);
  builder_.add_anims(anims);
  builder_.add_anim_files(anim_files);
  return builder_.Finish();
}

inline flatbuffers::Offset<AnimListFb> CreateAnimListFbDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *anim_files = nullptr,
    const std::vector<flatbuffers::Offset<AnimSource>> *anims = nullptr) {
  return motive::CreateAnimListFb(
      _fbb,
      anim_files ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*anim_files) : 0,
      anims ? _fbb.CreateVector<flatbuffers::Offset<AnimSource>>(*anims) : 0);
}

inline bool VerifyAnimSourceUnion(flatbuffers::Verifier &verifier, const void *obj, AnimSourceUnion type) {
  switch (type) {
    case AnimSourceUnion_NONE: {
      return true;
    }
    case AnimSourceUnion_AnimSourceFileName: {
      auto ptr = reinterpret_cast<const AnimSourceFileName *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case AnimSourceUnion_AnimSourceEmbedded: {
      auto ptr = reinterpret_cast<const AnimSourceEmbedded *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyAnimSourceUnionVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyAnimSourceUnion(
        verifier,  values->Get(i), types->GetEnum<AnimSourceUnion>(i))) {
      return false;
    }
  }
  return true;
}

inline const motive::AnimListFb *GetAnimListFb(const void *buf) {
  return flatbuffers::GetRoot<motive::AnimListFb>(buf);
}

inline const char *AnimListFbIdentifier() {
  return "ALIS";
}

inline bool AnimListFbBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, AnimListFbIdentifier());
}

inline bool VerifyAnimListFbBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<motive::AnimListFb>(AnimListFbIdentifier());
}

inline const char *AnimListFbExtension() {
  return "motivelist";
}

inline void FinishAnimListFbBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<motive::AnimListFb> root) {
  fbb.Finish(root, AnimListFbIdentifier());
}

}  // namespace motive

#endif  // FLATBUFFERS_GENERATED_ANIMLIST_MOTIVE_H_
