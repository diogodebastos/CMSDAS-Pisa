ifeq ($(strip $(AnalysisJMEDASAuto)),)
AnalysisJMEDASAuto := self/src/Analysis/JMEDAS/plugins
PLUGINS:=yes
AnalysisJMEDASAuto_files := $(patsubst src/Analysis/JMEDAS/plugins/%,%,$(wildcard $(foreach dir,src/Analysis/JMEDAS/plugins ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
AnalysisJMEDASAuto_BuildFile    := $(WORKINGDIR)/cache/bf/src/Analysis/JMEDAS/plugins/BuildFile
AnalysisJMEDASAuto_LOC_USE := self  FWCore/Framework FWCore/ParameterSet root boost DataFormats/Candidate DataFormats/JetReco DataFormats/PatCandidates DataFormats/StdDictionaries DataFormats/WrappedStdDictionaries SimDataFormats/GeneratorProducts FWCore/ServiceRegistry CommonTools/Utils CommonTools/UtilAlgos CondFormats/JetMETObjects Analysis/JMEDAS
AnalysisJMEDASAuto_PRE_INIT_FUNC += $$(eval $$(call edmPlugin,AnalysisJMEDASAuto,AnalysisJMEDASAuto,$(SCRAMSTORENAME_LIB),src/Analysis/JMEDAS/plugins))
AnalysisJMEDASAuto_PACKAGE := self/src/Analysis/JMEDAS/plugins
ALL_PRODS += AnalysisJMEDASAuto
Analysis/JMEDAS_forbigobj+=AnalysisJMEDASAuto
AnalysisJMEDASAuto_INIT_FUNC        += $$(eval $$(call Library,AnalysisJMEDASAuto,src/Analysis/JMEDAS/plugins,src_Analysis_JMEDAS_plugins,$(SCRAMSTORENAME_BIN),,$(SCRAMSTORENAME_LIB),$(SCRAMSTORENAME_LOGS)))
AnalysisJMEDASAuto_CLASS := LIBRARY
else
$(eval $(call MultipleWarningMsg,AnalysisJMEDASAuto,src/Analysis/JMEDAS/plugins))
endif
ALL_COMMONRULES += src_Analysis_JMEDAS_plugins
src_Analysis_JMEDAS_plugins_parent := Analysis/JMEDAS
src_Analysis_JMEDAS_plugins_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_JMEDAS_plugins,src/Analysis/JMEDAS/plugins,PLUGINS))
