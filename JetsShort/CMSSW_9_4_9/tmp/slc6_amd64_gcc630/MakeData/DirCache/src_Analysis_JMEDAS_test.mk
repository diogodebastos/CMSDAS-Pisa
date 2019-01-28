ALL_COMMONRULES += src_Analysis_JMEDAS_test
src_Analysis_JMEDAS_test_parent := Analysis/JMEDAS
src_Analysis_JMEDAS_test_INIT_FUNC += $$(eval $$(call CommonProductRules,src_Analysis_JMEDAS_test,src/Analysis/JMEDAS/test,TEST))
