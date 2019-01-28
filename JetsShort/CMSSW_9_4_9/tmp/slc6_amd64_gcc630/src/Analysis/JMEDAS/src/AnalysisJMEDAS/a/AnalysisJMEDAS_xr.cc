// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME tmpdIslc6_amd64_gcc630dIsrcdIAnalysisdIJMEDASdIsrcdIAnalysisJMEDASdIadIAnalysisJMEDAS_xr

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "src/Analysis/JMEDAS/src/classes.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR_Dictionary();
   static void edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<vector<vector<pair<string,float> > > >*)
   {
      ::edm::Wrapper<vector<vector<pair<string,float> > > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<vector<vector<pair<string,float> > > >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<vector<vector<pair<string,float> > > >", ::edm::Wrapper<vector<vector<pair<string,float> > > >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<vector<vector<pair<string,float> > > >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(::edm::Wrapper<vector<vector<pair<string,float> > > >) );
      instance.SetNew(&new_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR);

      ::ROOT::AddClassAlternate("edm::Wrapper<vector<vector<pair<string,float> > > >","edm::Wrapper<std::vector<std::vector<std::pair<std::string,float> > > >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<vector<vector<pair<string,float> > > >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<vector<vector<pair<string,float> > > >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<vector<vector<pair<string,float> > > >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<vector<vector<pair<string,float> > > >*)0x0)->GetClass();
      edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::edm::Wrapper<vector<vector<pair<string,float> > > > : new ::edm::Wrapper<vector<vector<pair<string,float> > > >;
   }
   static void *newArray_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::edm::Wrapper<vector<vector<pair<string,float> > > >[nElements] : new ::edm::Wrapper<vector<vector<pair<string,float> > > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(void *p) {
      delete ((::edm::Wrapper<vector<vector<pair<string,float> > > >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(void *p) {
      delete [] ((::edm::Wrapper<vector<vector<pair<string,float> > > >*)p);
   }
   static void destruct_edmcLcLWrapperlEvectorlEvectorlEpairlEstringcOfloatgRsPgRsPgRsPgR(void *p) {
      typedef ::edm::Wrapper<vector<vector<pair<string,float> > > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<vector<vector<pair<string,float> > > >

namespace ROOT {
   static TClass *vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR_Dictionary();
   static void vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(void *p);
   static void destruct_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<pair<string,float> > >*)
   {
      vector<vector<pair<string,float> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<pair<string,float> > >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<pair<string,float> > >", -2, "vector", 214,
                  typeid(vector<vector<pair<string,float> > >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<pair<string,float> > >) );
      instance.SetNew(&new_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<pair<string,float> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<pair<string,float> > >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<pair<string,float> > >*)0x0)->GetClass();
      vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<pair<string,float> > > : new vector<vector<pair<string,float> > >;
   }
   static void *newArray_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<pair<string,float> > >[nElements] : new vector<vector<pair<string,float> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(void *p) {
      delete ((vector<vector<pair<string,float> > >*)p);
   }
   static void deleteArray_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(void *p) {
      delete [] ((vector<vector<pair<string,float> > >*)p);
   }
   static void destruct_vectorlEvectorlEpairlEstringcOfloatgRsPgRsPgR(void *p) {
      typedef vector<vector<pair<string,float> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<pair<string,float> > >

namespace ROOT {
   static TClass *vectorlEpairlEstringcOfloatgRsPgR_Dictionary();
   static void vectorlEpairlEstringcOfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlEstringcOfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEpairlEstringcOfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlEstringcOfloatgRsPgR(void *p);
   static void deleteArray_vectorlEpairlEstringcOfloatgRsPgR(void *p);
   static void destruct_vectorlEpairlEstringcOfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<string,float> >*)
   {
      vector<pair<string,float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<string,float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<string,float> >", -2, "vector", 214,
                  typeid(vector<pair<string,float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEpairlEstringcOfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<pair<string,float> >) );
      instance.SetNew(&new_vectorlEpairlEstringcOfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlEstringcOfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlEstringcOfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlEstringcOfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlEstringcOfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<string,float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<pair<string,float> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlEstringcOfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<pair<string,float> >*)0x0)->GetClass();
      vectorlEpairlEstringcOfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlEstringcOfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlEstringcOfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<string,float> > : new vector<pair<string,float> >;
   }
   static void *newArray_vectorlEpairlEstringcOfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<string,float> >[nElements] : new vector<pair<string,float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlEstringcOfloatgRsPgR(void *p) {
      delete ((vector<pair<string,float> >*)p);
   }
   static void deleteArray_vectorlEpairlEstringcOfloatgRsPgR(void *p) {
      delete [] ((vector<pair<string,float> >*)p);
   }
   static void destruct_vectorlEpairlEstringcOfloatgRsPgR(void *p) {
      typedef vector<pair<string,float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<pair<string,float> >

namespace {
  void TriggerDictionaryInitialization_AnalysisJMEDAS_xr_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/gpfs/ddn/users/dchasque/JetsShort/CMSSW_9_4_9/src",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/cmssw/CMSSW_9_4_9/src",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/coral/CORAL_2_3_21-fmblme4/include/LCG",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/lcg/root/6.10.08-elfike2/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/boost/1.63.0-fmblme/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/pcre/8.37-oenich/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/bz2lib/1.0.6/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/clhep/2.3.4.2-fmblme/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/fastjet/3.1.0/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/gsl/2.2.1/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/hepmc/2.06.07-oenich/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/libuuid/2.22.2/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/openssl/1.0.2d/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/python/2.7.11-fmblme/include/python2.7",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/sigcpp/2.6.2-oenich/include/sigc++-2.0",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tbb/2018/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/cms/vdt/0.3.9/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/xerces-c/3.1.3/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/xz/5.2.2-oenich/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/zlib-x86_64/1.2.11/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/md5/1.0.0/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/external/tinyxml/2.5.3-fmblme/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc630/lcg/root/6.10.08-elfike2/include",
"/gpfs/ddn/users/dchasque/JetsShort/CMSSW_9_4_9/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "AnalysisJMEDAS_xr dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace std{template <class _CharT> struct __attribute__((annotate("$clingAutoload$bits/char_traits.h")))  __attribute__((annotate("$clingAutoload$string")))  char_traits;
}
namespace std{template <typename > class __attribute__((annotate("$clingAutoload$bits/memoryfwd.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "AnalysisJMEDAS_xr dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef CMS_DICT_IMPL
  #define CMS_DICT_IMPL 1
#endif
#ifndef _REENTRANT
  #define _REENTRANT 1
#endif
#ifndef GNUSOURCE
  #define GNUSOURCE 1
#endif
#ifndef __STRICT_ANSI__
  #define __STRICT_ANSI__ 1
#endif
#ifndef GNU_GCC
  #define GNU_GCC 1
#endif
#ifndef _GNU_SOURCE
  #define _GNU_SOURCE 1
#endif
#ifndef CMSSW_GIT_HASH
  #define CMSSW_GIT_HASH "CMSSW_9_4_9"
#endif
#ifndef PROJECT_NAME
  #define PROJECT_NAME "CMSSW"
#endif
#ifndef PROJECT_VERSION
  #define PROJECT_VERSION "CMSSW_9_4_9"
#endif
#ifndef TBB_USE_GLIBCXX_VERSION
  #define TBB_USE_GLIBCXX_VERSION 60300
#endif
#ifndef BOOST_SPIRIT_THREADSAFE
  #define BOOST_SPIRIT_THREADSAFE 1
#endif
#ifndef PHOENIX_THREADSAFE
  #define PHOENIX_THREADSAFE 1
#endif
#ifndef CMSSW_REFLEX_DICT
  #define CMSSW_REFLEX_DICT 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include <string>
#include <vector>
#include <utility>
#include "DataFormats/Common/interface/Wrapper.h"

namespace {
  struct dictionary {
  	//std::pair<std::string,float> psf;
	//std::vector<std::pair<std::string,float> > vpsf;
	std::vector<std::vector<std::pair<std::string,float> > > vvpsf;
	//edm::Wrapper<std::vector<std::pair<std::string,float> > > wvpsf;
	edm::Wrapper<std::vector<std::vector<std::pair<std::string,float> > > > wvvpsf;
  };
}
#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"edm::Wrapper<std::vector<std::vector<std::pair<std::string,float> > > >", payloadCode, "@",
"edm::Wrapper<vector<vector<pair<string,float> > > >", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("AnalysisJMEDAS_xr",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_AnalysisJMEDAS_xr_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_AnalysisJMEDAS_xr_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_AnalysisJMEDAS_xr() {
  TriggerDictionaryInitialization_AnalysisJMEDAS_xr_Impl();
}
