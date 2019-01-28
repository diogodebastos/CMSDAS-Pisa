ifeq ($(strip $(Analysis/JMEDAS)),)
ALL_COMMONRULES += src_Analysis_JMEDAS_src
src_Analysis_JMEDAS_src_parent := Analysis/JMEDAS
src_Analysis_JMEDAS_src_INIT_FUNC := $$(eval $$(call CommonProductRules,src_Analysis_JMEDAS_src,src/Analysis/JMEDAS/src,LIBRARY))
AnalysisJMEDAS := self/Analysis/JMEDAS
Analysis/JMEDAS := AnalysisJMEDAS
AnalysisJMEDAS_files := $(patsubst src/Analysis/JMEDAS/src/%,%,$(wildcard $(foreach dir,src/Analysis/JMEDAS/src ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
AnalysisJMEDAS_BuildFile    := $(WORKINGDIR)/cache/bf/src/Analysis/JMEDAS/BuildFile
AnalysisJMEDAS_LOC_USE := self  JetMETCorrections/Objects JetMETCorrections/Modules CondFormats/JetMETObjects FWCore/Framework FWCore/PluginManager FWCore/ParameterSet FWCore/MessageLogger FWCore/MessageService FWCore/ServiceRegistry FWCore/Utilities CommonTools/UtilAlgos DataFormats/JetReco DataFormats/MuonReco DataFormats/PatCandidates DataFormats/TauReco DataFormats/Math DataFormats/HepMCCandidate DataFormats/Common DataFormats/StdDictionaries SimDataFormats/GeneratorProducts SimDataFormats/JetMatching PhysicsTools/Utilities root rootmath rootcore rootminuit fastjet
AnalysisJMEDAS_LCGDICTS  := x 
AnalysisJMEDAS_PRE_INIT_FUNC += $$(eval $$(call LCGDict,AnalysisJMEDAS,src/Analysis/JMEDAS/src/classes.h,src/Analysis/JMEDAS/src/classes_def.xml,$(SCRAMSTORENAME_LIB),$(GENREFLEX_ARGS) --fail_on_warnings,))
AnalysisJMEDAS_EX_LIB   := AnalysisJMEDAS
AnalysisJMEDAS_EX_USE   := $(foreach d,$(AnalysisJMEDAS_LOC_USE),$(if $($(d)_EX_FLAGS_NO_RECURSIVE_EXPORT),,$d))
AnalysisJMEDAS_PACKAGE := self/src/Analysis/JMEDAS/src
ALL_PRODS += AnalysisJMEDAS
AnalysisJMEDAS_CLASS := LIBRARY
Analysis/JMEDAS_forbigobj+=AnalysisJMEDAS
AnalysisJMEDAS_INIT_FUNC        += $$(eval $$(call Library,AnalysisJMEDAS,src/Analysis/JMEDAS/src,src_Analysis_JMEDAS_src,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
endif
