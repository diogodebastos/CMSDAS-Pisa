ifeq ($(strip $(PyAnalysisJMEDAS)),)
PyAnalysisJMEDAS := self/src/Analysis/JMEDAS/python
src_Analysis_JMEDAS_python_parent := 
ALL_PYTHON_DIRS += $(patsubst src/%,%,src/Analysis/JMEDAS/python)
PyAnalysisJMEDAS_files := $(patsubst src/Analysis/JMEDAS/python/%,%,$(wildcard $(foreach dir,src/Analysis/JMEDAS/python ,$(foreach ext,$(SRC_FILES_SUFFIXES),$(dir)/*.$(ext)))))
PyAnalysisJMEDAS_LOC_USE := self  
PyAnalysisJMEDAS_PACKAGE := self/src/Analysis/JMEDAS/python
ALL_PRODS += PyAnalysisJMEDAS
PyAnalysisJMEDAS_INIT_FUNC        += $$(eval $$(call PythonProduct,PyAnalysisJMEDAS,src/Analysis/JMEDAS/python,src_Analysis_JMEDAS_python,1,1,$(SCRAMSTORENAME_PYTHON),$(SCRAMSTORENAME_LIB),,))
else
$(eval $(call MultipleWarningMsg,PyAnalysisJMEDAS,src/Analysis/JMEDAS/python))
endif
ALL_COMMONRULES += src_Analysis_JMEDAS_python
src_Analysis_JMEDAS_python_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_JMEDAS_python,src/Analysis/JMEDAS/python,PYTHON))
