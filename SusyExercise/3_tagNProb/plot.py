from ROOT import *
import tdrstyle
tdrstyle.setTDRStyle()


f1 = TFile("TnP_ele_Data.root")
f2 = TFile("TnP_ele_MC.root")
f3 = TFile("TnP_mu_Data.root")
f4 = TFile("TnP_mu_MC.root")

hist = {}

hn = ["invariantMass",
"LeptonProbePt",
"effLeptonPt",
"effLeptonEta",
"effNvert",]

for i in hn:
    hist[i+"_ele_data"] = f1.Get(i)
    hist[i+"_mu_data"] = f3.Get(i)
    hist[i+"_ele_MC"] = f2.Get(i)
    hist[i+"_mu_MC"] = f4.Get(i)
'''
c1 = TCanvas('c1')
leg = TLegend()
leg.AddEntry(hist["effLeptonPt_ele_data"], "Data")
leg.AddEntry(hist["effLeptonPt_ele_MC"], "MC")
hist["effLeptonPt_ele_data"].SetLineColor(kRed)
hist["effLeptonPt_ele_MC"].SetLineColor(kBlue)
hist["effLeptonPt_ele_data"].SetMarkerSize(1)
hist["effLeptonPt_ele_MC"].SetMarkerSize(1)
hist["effLeptonPt_ele_data"].SetTitle("Electron efficiency; P_{T}(e); Efficiency")
hist["effLeptonPt_ele_data"].Draw()
hist["effLeptonPt_ele_MC"].Draw("SAME")
leg.Draw()
c1.SaveAs("ele_pt_eff.png")

c2 = TCanvas('c2')
hist["effLeptonPt_mu_data"].SetLineColor(kRed)
hist["effLeptonPt_mu_MC"].SetLineColor(kBlue)
hist["effLeptonPt_mu_data"].SetMarkerSize(1)
hist["effLeptonPt_mu_MC"].SetMarkerSize(1)
hist["effLeptonPt_mu_data"].SetTitle("Muon efficiency; P_{T}(#mu); Efficiency")
hist["effLeptonPt_mu_data"].Draw()
hist["effLeptonPt_mu_MC"].Draw("SAME")
leg.Draw()
c2.SaveAs("mu_pt_eff.png")

c3 = TCanvas('c3')
hist["effLeptonEta_ele_data"].SetLineColor(kRed)
hist["effLeptonEta_ele_MC"].SetLineColor(kBlue)
hist["effLeptonEta_ele_data"].SetMarkerSize(1)
hist["effLeptonEta_ele_MC"].SetMarkerSize(1)
hist["effLeptonEta_ele_data"].SetTitle("Electron efficiency; #eta(e); Efficiency")
hist["effLeptonEta_ele_data"].Draw()
hist["effLeptonEta_ele_MC"].Draw("SAME")
leg.Draw()
c3.SaveAs("ele_eta_eff.png")

c4 = TCanvas('c4')
hist["effLeptonEta_mu_data"].SetLineColor(kRed)
hist["effLeptonEta_mu_MC"].SetLineColor(kBlue)
hist["effLeptonEta_mu_data"].SetMarkerSize(1)
hist["effLeptonEta_mu_MC"].SetMarkerSize(1)
hist["effLeptonEta_mu_data"].SetTitle("Muon efficiency; #eta(#mu); Efficiency")
hist["effLeptonEta_mu_data"].Draw()
hist["effLeptonEta_mu_MC"].Draw("SAME")
leg.Draw()
c4.SaveAs("mu_eta_eff.png")

c5 = TCanvas('c5')
hist["effNvert_ele_data"].SetLineColor(kRed)
hist["effNvert_ele_MC"].SetLineColor(kBlue)
hist["effNvert_ele_data"].SetMarkerSize(1)
hist["effNvert_ele_MC"].SetMarkerSize(1)
hist["effNvert_ele_data"].SetTitle("Electron efficiency; Number of vertices; Efficiency")
hist["effNvert_ele_data"].Draw()
hist["effNvert_ele_MC"].Draw("SAME")
leg.Draw()
c5.SaveAs("nVert_eff.png")
'''

c6 = TCanvas('c6')
hist["invariantMass_ele_data"].SetFillColor(30)
hist["invariantMass_ele_data"].GetXaxis().SetTitle("m(ee) [GeV]")
hist["invariantMass_ele_data"].GetYaxis().SetTitle("Entries")
hist["invariantMass_ele_data"].Draw("BAR")

c6.SaveAs("ee_invariantmass_data.png")

c7 = TCanvas('c7')
hist["invariantMass_ele_MC"].Scale(hist["invariantMass_ele_data"].Integral()/hist["invariantMass_ele_MC"].Integral())
hist["invariantMass_ele_MC"].SetFillColor(46)
hist["invariantMass_ele_MC"].GetXaxis().SetTitle("m(ee) [GeV]")
hist["invariantMass_ele_MC"].GetYaxis().SetTitle("Entries")
hist["invariantMass_ele_MC"].Draw("BAR")

c7.SaveAs("ee_invariantmass_MC.png")

c8 = TCanvas('c8')
hist["invariantMass_mu_data"].GetXaxis().SetTitle("m(#mu#mu) [GeV]")
hist["invariantMass_mu_data"].SetFillColor(30)
hist["invariantMass_mu_data"].GetYaxis().SetTitle("Entries")
hist["invariantMass_mu_data"].Draw("BAR")
c8.SaveAs("mu_invariantmass_data.png")

c9 = TCanvas('c9')
hist["invariantMass_mu_MC"].Scale(hist["invariantMass_mu_data"].Integral()/hist["invariantMass_mu_MC"].Integral())
hist["invariantMass_mu_MC"].SetFillColor(46)
hist["invariantMass_mu_MC"].GetXaxis().SetTitle("m(#mu#mu) [GeV]")
hist["invariantMass_mu_MC"].GetYaxis().SetTitle("Entries")
hist["invariantMass_mu_MC"].Draw("BAR")
c9.SaveAs("mu_invariantmass_MC.png")
